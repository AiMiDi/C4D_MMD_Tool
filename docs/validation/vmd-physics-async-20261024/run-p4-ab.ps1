# P4 真机 A/B/A：lag=1 严格等价 + seek 保持 + 性能
#
# 与 run-p3-ab.ps1 的差别（P4 契约）：
#   1) 判据从「找任意常数 lag」改为「必须 lag=1 且 lag_constant=True」；
#   2) 新增 seek 场景：B-async 段在采完 -SeekAfterFrame 后做一次时间跳变到 -SeekToFrame，
#      之后继续采样，由 analyze-p4-lag.py 分 seek 前/后两个窗口各自判定 lag=1；
#   3) 语义不过时性能数字一律在 summary 里标为 unavailable（不对外给结论）。
#
# 用法（无 -Execute 只打印计划，不启宿主）：
#   pwsh -NoProfile -File run-p4-ab.ps1 `
#     -SyncPluginsPath  S:\tmp\cmt_vmd_profile_20261019\p4\sync\plugins `
#     -AsyncPluginsPath S:\tmp\cmt_vmd_profile_20261019\p4\async\plugins `
#     -OutRoot S:\tmp\cmt_vmd_profile_20261019\p4\ab\main -Execute
param(
    [string]$SyncPluginsPath = 'S:\tmp\cmt_vmd_profile_20261019\p4\sync\plugins',
    [string]$AsyncPluginsPath = 'S:\tmp\cmt_vmd_profile_20261019\p4\async\plugins',
    [string]$OutRoot = '',
    [int]$Launches = 5,
    [int]$Reps = 5,
    [int]$Warmup = 15,
    [int]$Frames = 30,
    [int]$StartFrame = 560,
    [int]$MaxLoadPct = 30,
    [int]$QuietMaxLoadPct = 20,
    [string]$SemanticFrames = '539-620',
    [int]$SeekAfterFrame = 560,
    [int]$SeekToFrame = 600,
    [int]$ExpectRigid = 479,
    [int]$ExpectPoints = 70222,
    [string]$PmxPath = 'C:\pmx\白银之城—阿芙2.0\阿芙2.0.pmx',
    [string]$VmdPath = 'C:\vmd\Stay Tonight Heaven Lee Lee Ver. 动作.vmd',
    [string]$CinemaExe = 'C:\Program Files\Maxon Cinema 4D 2027\Cinema 4D.exe',
    [string]$PrefsPath = 'S:\tmp\cmt_vmd_profile_20261019\host_profile',
    [int]$Port = 5557,
    [int]$ReadyTimeoutSeconds = 240,
    [int]$StopTimeoutSeconds = 30,
    [double]$PromoteThresholdMs = 3.0,
    [double]$InvisibleThresholdMs = 1.5,
    [double]$DriftLimitPct = 5.0,
    [string]$AsyncPipeline = '',
    # 语义段与计时段分开跑时，计时段用它复用语义段已算好的 lag-p4.json，
    # 这样既能分开落盘，又能产出一份同时含语义与计时的 summary 供 check 判定。
    [string]$SemanticsRoot = '',
    # 只跑指定段（补跑单段用）：-OnlySegments A1-sync
    [string[]]$OnlySegments = @(),
    [switch]$SkipTiming,
    [switch]$SkipSemantics,
    [switch]$KeepRunning,
    [switch]$Execute
)
$ErrorActionPreference = 'Stop'
# 子进程（python 驱动）输出 UTF-8 JSON；不显式设解码会按 cp936 解出乱码，导致 ConvertFrom-Json 失败。
$env:PYTHONIOENCODING = 'utf-8'
try { [Console]::OutputEncoding = New-Object System.Text.UTF8Encoding($false) } catch { }
try { $OutputEncoding = [System.Text.Encoding]::UTF8 } catch { }

# 修正: $VmdPath 默认值（上面写错了一个 Lee）
if ($VmdPath -like '*Lee Lee*') { $VmdPath = 'C:\vmd\Stay Tonight Heaven Lee Ver. 动作.vmd' }

$RepoRoot = Split-Path -Parent (Split-Path -Parent (Split-Path -Parent $PSScriptRoot))
$HostTools = Join-Path $RepoRoot 'docs\validation\vmd-host-restore-20261024'
$StableMeasure = Join-Path $RepoRoot 'docs\validation\vmd-perf-stable-20261024\stable-measure.ps1'
$LaunchHost = Join-Path $HostTools 'launch-host.ps1'
$StopHost = Join-Path $HostTools 'stop-host.ps1'
$Driver = Join-Path $HostTools 'host-driver.py'
$Probe = Join-Path $PSScriptRoot 'probe-rigid.py'
$Analyzer = Join-Path $PSScriptRoot 'analyze-p4-lag.py'

if (-not $OutRoot) { $OutRoot = Join-Path 'S:\tmp\cmt_vmd_profile_20261019\p4\ab' ((Get-Date).ToUniversalTime().ToString('yyyyMMddTHHmmss')) }
$OutRoot = [IO.Path]::GetFullPath($OutRoot)

function Write-Step([string]$Text) { Write-Host ('[{0}] {1}' -f (Get-Date -Format 'HH:mm:ss'), $Text) }
function Get-FileSha([string]$Path) { (Get-FileHash -LiteralPath $Path -Algorithm SHA256).Hash.ToLower() }
function Get-ModulePath([string]$PluginsPath) { Join-Path $PluginsPath 'mmdtool\mmdtool.xdl64' }
function Get-Median([double[]]$Values) {
    if (-not $Values -or $Values.Count -eq 0) { return $null }
    $sorted = @($Values | Sort-Object)
    $mid = [int][math]::Floor($sorted.Count / 2)
    if ($sorted.Count % 2 -eq 1) { return [double]$sorted[$mid] }
    return ([double]$sorted[$mid - 1] + [double]$sorted[$mid]) / 2.0
}
function Get-CpuLoadPct {
    try {
        $sample = Get-CimInstance Win32_Processor -ErrorAction Stop | Measure-Object -Property LoadPercentage -Average
        if ($null -ne $sample.Average) { return [double]$sample.Average }
    } catch { }
    return $null
}
function Expand-Frames([string]$spec) {
    $frames = New-Object System.Collections.Generic.List[int]
    foreach ($chunk in ($spec -replace '\s', '').Split(',')) {
        if (-not $chunk) { continue }
        if ($chunk -match '^(\d+)-(\d+)$') {
            for ($i = [int]$Matches[1]; $i -le [int]$Matches[2]; $i++) { $frames.Add($i) }
        } else {
            $frames.Add([int]$chunk)
        }
    }
    return ($frames | Sort-Object -Unique)
}
function Get-OurHostProcesses {
    try {
        return @(Get-CimInstance Win32_Process -Filter "Name='Cinema 4D.exe'" -ErrorAction Stop | Where-Object { $_.CommandLine -and $_.CommandLine.Contains($PrefsPath) })
    } catch { return @() }
}
function Clear-OurHost {
    $ours = @(Get-OurHostProcesses)
    foreach ($proc in $ours) { & taskkill /F /T /PID $proc.ProcessId 2>&1 | Out-Null }
    if ($ours.Count -gt 0) { Start-Sleep -Seconds 2 }
    return $ours.Count
}
function Wait-MachineQuiet([int]$TimeoutSeconds = 900) {
    $deadline = (Get-Date).AddSeconds($TimeoutSeconds)
    $streak = 0
    while ((Get-Date) -lt $deadline) {
        $load = Get-CpuLoadPct
        if ($null -ne $load -and $load -lt $QuietMaxLoadPct) { $streak++ } else { $streak = 0 }
        if ($streak -ge 3) { return $true }
        Start-Sleep -Seconds 3
    }
    return $false
}
function Invoke-Driver([string[]]$DriverArgs) {
    $output = & python $Driver @DriverArgs 2>&1
    $code = $LASTEXITCODE
    $line = @($output | Where-Object { $_ -match '^DRIVER_RESULT:' } | Select-Object -Last 1)
    if ($code -ne 0) { throw ("driver_failed exit={0} args={1} out={2}" -f $code, ($DriverArgs -join ' '), (($output | Select-Object -Last 6) -join ' | ')) }
    if (-not $line) { return $null }
    return ($line -replace '^DRIVER_RESULT:', '') | ConvertFrom-Json
}
function Read-Json([string]$Path) { if (Test-Path -LiteralPath $Path) { return Get-Content -LiteralPath $Path -Raw | ConvertFrom-Json } return $null }

$checks = New-Object System.Collections.Generic.List[object]
$warnings = New-Object System.Collections.Generic.List[string]
function Add-Check([string]$Id, [string]$Status, [string]$Detail) {
    $checks.Add([pscustomobject]@{ id = $Id; status = $Status; detail = $Detail })
    Write-Host ('[check] {0,-40} {1,-8} {2}' -f $Id, $Status, $Detail)
}

$segments = @(
    # P8 之后产品默认开启异步：同步段显式 CMT_PHYSICS_ASYNC=0，异步段**不设环境变量**，
    # 这样 B 段验证的正是「用户什么都不配」时的默认行为。
    [pscustomobject]@{ name = 'A1-sync'; async = '0'; pipeline = '' },
    [pscustomobject]@{ name = 'B-async'; async = ''; pipeline = $AsyncPipeline },
    [pscustomobject]@{ name = 'A2-sync'; async = '0'; pipeline = '' }
)
if ($OnlySegments.Count -gt 0) {
    # 单段重跑（例如某段 probe 传输失败后补跑），不影响其它段已落盘的产物。
    $segments = @($segments | Where-Object { $OnlySegments -contains $_.name })
    if ($segments.Count -eq 0) { throw "only_segments_matched_nothing: $($OnlySegments -join ',')" }
}
$syncSha = if (Test-Path -LiteralPath (Get-ModulePath $SyncPluginsPath)) { Get-FileSha (Get-ModulePath $SyncPluginsPath) } else { $null }
$asyncSha = if (Test-Path -LiteralPath (Get-ModulePath $AsyncPluginsPath)) { Get-FileSha (Get-ModulePath $AsyncPluginsPath) } else { $null }
$semanticFramesSpec = $SemanticFrames
$semanticFrameNumbers = Expand-Frames $semanticFramesSpec
$semanticFrameList = ($semanticFrameNumbers -join ',')

if (-not $Execute) {
    $plan = [ordered]@{
        schema          = 'vmd-p4-ab-plan/1'
        out_root        = $OutRoot
        segments        = @($segments | ForEach-Object { [ordered]@{ name = $_.name; async = $_.async; pipeline = $_.pipeline } })
        launches        = $Launches
        reps            = $Reps
        warmup          = $Warmup
        frames          = $Frames
        start_frame     = $StartFrame
        max_load_pct    = $MaxLoadPct
        quiet_max_load  = $QuietMaxLoadPct
        semantic_frames = $semanticFramesSpec
        seek_after      = $SeekAfterFrame
        seek_to         = $SeekToFrame
        criteria        = 'lag1_strict'
        sync_sha        = $syncSha
        async_sha       = $asyncSha
        thresholds      = @{ promote_ms = $PromoteThresholdMs; invisible_ms = $InvisibleThresholdMs; drift_pct = $DriftLimitPct }
        actions         = @('timing A1/B/A2', 'semantics A1/B(+seek)/A2', 'analyze lag=1')
    }
    Write-Host ('P4_AB_PLAN:' + ($plan | ConvertTo-Json -Depth 6 -Compress))
    exit 0
}

New-Item -ItemType Directory -Force -Path $OutRoot | Out-Null
$runStart = Get-Date
$stray = Clear-OurHost
if ($stray -gt 0) { $warnings.Add("cleared $stray stale host(s) before start") }
Write-Step "P4 A/B/A 开始 out=$OutRoot sync=$syncSha async=$asyncSha"

# P8 之后产品内置异步物理并默认开启：两个段用**同一份二进制**，差异只在 CMT_PHYSICS_ASYNC。
# 因此同 sha 是预期形态（runtime_switch）；只有「两个段的插件目录不同却给出同一 sha」才是构建没切换。
$artifactMode = if ($syncSha -and $asyncSha -and $syncSha -eq $asyncSha) {
    if ([IO.Path]::GetFullPath($SyncPluginsPath) -ne [IO.Path]::GetFullPath($AsyncPluginsPath)) {
        throw 'sync/async plugin directories differ but artifacts share sha256; build is not switching variants'
    }
    'runtime_switch'
} else { 'distinct_artifacts' }
Add-Check 'artifact_variant_mode' 'info' "mode=$artifactMode sha=$($syncSha)"

$timing = @{}
$semantics = @{}

function Invoke-SegmentTiming([object]$Segment) {
    $segOut = Join-Path $OutRoot "segments\$($Segment.name)\timing"
    New-Item -ItemType Directory -Force -Path $segOut | Out-Null
    $plugins = if ($Segment.async -eq '1') { $AsyncPluginsPath } else { $SyncPluginsPath }
    $quiet = Wait-MachineQuiet
    if (-not $quiet) { $warnings.Add("$($Segment.name): machine not quiet (<$QuietMaxLoadPct%) within timeout") }

    $previousAsync = $env:CMT_PHYSICS_ASYNC
    $previousPipeline = $env:CMT_PHYSICS_PIPELINE
    if ([string]::IsNullOrEmpty($Segment.async)) {
        # 空值 = 不设环境变量，让产品用默认值（P8 之后默认开启异步）。
        Remove-Item Env:CMT_PHYSICS_ASYNC -ErrorAction SilentlyContinue
    } else {
        $env:CMT_PHYSICS_ASYNC = $Segment.async
    }
    if ($Segment.pipeline) { $env:CMT_PHYSICS_PIPELINE = $Segment.pipeline } else { Remove-Item Env:CMT_PHYSICS_PIPELINE -ErrorAction SilentlyContinue }
    try {
        Write-Step "计时 $($Segment.name)（ASYNC=$($Segment.async) PIPELINE=$($Segment.pipeline) launches=$Launches reps=$Reps）"
        $measureArgs = @($StableMeasure, '-Variant', $Segment.name, '-PluginsPath', $plugins, '-PhysicsBoth',
            '-Rounds', $Reps, '-Launches', $Launches, '-LaunchRetries', 2,
            '-Warmup', $Warmup, '-Frames', $Frames, '-StartFrame', $StartFrame,
            '-MaxLoadPct', $MaxLoadPct, '-OutDir', $segOut)
        & pwsh -NoProfile -File @measureArgs | Out-Host
        $exit = $LASTEXITCODE
    } finally {
        if ($null -eq $previousAsync) { Remove-Item Env:CMT_PHYSICS_ASYNC -ErrorAction SilentlyContinue } else { $env:CMT_PHYSICS_ASYNC = $previousAsync }
        if ($null -eq $previousPipeline) { Remove-Item Env:CMT_PHYSICS_PIPELINE -ErrorAction SilentlyContinue } else { $env:CMT_PHYSICS_PIPELINE = $previousPipeline }
    }
    $summary = Read-Json (Join-Path $segOut 'run-summary.json')
    $onMedians = @(); $offMedians = @(); $loads = @(); $moduleMatch = @()
    if ($summary) {
        $onMedians = @($summary.aggregate.on.per_launch_median_ms)
        $offMedians = @($summary.aggregate.off.per_launch_median_ms)
        foreach ($launch in @($summary.launches)) {
            if ($null -ne $launch.load_pct) { $loads += [double]$launch.load_pct }
            $moduleMatch += [bool]$launch.module_match
        }
    }
    $status = if ($exit -eq 0 -and $onMedians.Count -ge $Launches) { 'passed' } else { 'failed' }
    if ($status -eq 'failed' -and $exit -eq 0) { $warnings.Add("$($Segment.name): stable-measure exit 0 but only $($onMedians.Count)/$Launches usable launches") }
    Add-Check "timing_$($Segment.name)_exit" $status "exit=$exit launches=$($onMedians.Count)/$Launches module_match=$(@($moduleMatch | Where-Object { $_ }).Count)/$($moduleMatch.Count)"
    $timing[$Segment.name] = [ordered]@{
        exit           = $exit
        segment_dir    = $segOut
        on_medians     = $onMedians
        off_medians    = $offMedians
        on_median      = Get-Median $onMedians
        off_median     = Get-Median $offMedians
        load_pct_max   = if ($loads.Count) { ($loads | Measure-Object -Maximum).Maximum } else { $null }
        module_match   = [bool]($moduleMatch.Count -gt 0 -and (@($moduleMatch | Where-Object { -not $_ }).Count -eq 0))
    }
}

function Invoke-SegmentSemantics([object]$Segment) {
    $segOut = Join-Path $OutRoot "segments\$($Segment.name)\semantics"
    New-Item -ItemType Directory -Force -Path $segOut | Out-Null
    $plugins = if ($Segment.async -eq '1') { $AsyncPluginsPath } else { $SyncPluginsPath }
    $hostOut = Join-Path $segOut 'host'
    $probeOut = Join-Path $segOut 'probe.json'
    New-Item -ItemType Directory -Force -Path $hostOut | Out-Null
    $quiet = Wait-MachineQuiet
    if (-not $quiet) { $warnings.Add("$($Segment.name)/semantics: machine not quiet within timeout") }

    $previousAsync = $env:CMT_PHYSICS_ASYNC
    $previousPipeline = $env:CMT_PHYSICS_PIPELINE
    if ([string]::IsNullOrEmpty($Segment.async)) {
        # 空值 = 不设环境变量，让产品用默认值（P8 之后默认开启异步）。
        Remove-Item Env:CMT_PHYSICS_ASYNC -ErrorAction SilentlyContinue
    } else {
        $env:CMT_PHYSICS_ASYNC = $Segment.async
    }
    if ($Segment.pipeline) { $env:CMT_PHYSICS_PIPELINE = $Segment.pipeline } else { Remove-Item Env:CMT_PHYSICS_PIPELINE -ErrorAction SilentlyContinue }
    try {
        Write-Step "语义 $($Segment.name)（ASYNC=$($Segment.async) frames=$semanticFramesSpec seek=$SeekAfterFrame->$SeekToFrame）"
        & pwsh -NoProfile -File $LaunchHost -Execute -OutRoot $hostOut -ModulePath $plugins -Port $Port -PrefsPath $PrefsPath -CinemaExe $CinemaExe -ReadyTimeoutSeconds $ReadyTimeoutSeconds | Out-Host
        if ($LASTEXITCODE -ne 0) { throw "launch_host_failed exit=$LASTEXITCODE" }

        Invoke-Driver @('import', '--pmx', $PmxPath, '--vmd', $VmdPath) | Out-Null
        Invoke-Driver @('import-motion', '--vmd', $VmdPath) | Out-Null
        Invoke-Driver @('set-mode', '--mode', 'anim') | Out-Null
        Invoke-Driver @('physics', '--enabled', 'on') | Out-Null

        $probeArgs = @($Probe, '--frames', $semanticFrameList, '--out', $probeOut,
            '--expect-rigid', $ExpectRigid, '--expect-points', $ExpectPoints, '--enable-rigid-display',
            '--prefs-path', $PrefsPath, '--timeout', 600)
        # seek 必须对称施加到每个段：Bullet 世界状态路径相关（速度/接触 warm-start），
        # 只让 async 段 seek 会让它与「从未 reset 的热连续轨」比较，判据天生不可能全等。
        if ($SeekAfterFrame -ge 0 -and $SeekToFrame -ge 0) {
            $probeArgs += @('--seek-after-frame', $SeekAfterFrame, '--seek-to-frame', $SeekToFrame)
        }
        & python @probeArgs | Out-Host
        $probeExit = $LASTEXITCODE
        if ($probeExit -ne 0) { $warnings.Add("$($Segment.name)/semantics: probe exit=$probeExit") }
        $semantics[$Segment.name] = $probeOut
        Add-Check "semantics_$($Segment.name)_probe" ($(if ($probeExit -eq 0) { 'passed' } else { 'failed' })) "exit=$probeExit out=$probeOut"
    } finally {
        if ($null -eq $previousAsync) { Remove-Item Env:CMT_PHYSICS_ASYNC -ErrorAction SilentlyContinue } else { $env:CMT_PHYSICS_ASYNC = $previousAsync }
        if ($null -eq $previousPipeline) { Remove-Item Env:CMT_PHYSICS_PIPELINE -ErrorAction SilentlyContinue } else { $env:CMT_PHYSICS_PIPELINE = $previousPipeline }
        if (-not $KeepRunning) {
            $identityPath = Join-Path $hostOut 'host-identity.json'
            & pwsh -NoProfile -File $StopHost -Execute -IdentityPath $identityPath -OutRoot $hostOut -StopTimeoutSeconds $StopTimeoutSeconds | Out-Host
            if ($LASTEXITCODE -ne 0) {
                # stop-host 失败（identity 缺失/进程已崩）时兜底：只杀本任务私有 profile 的 C4D，
                # 结果如实记为 warning，绝不静默放过（否则下一个段会被 port_already_listening 卡住）。
                $warnings.Add("$($Segment.name)/semantics: stop-host exit=$LASTEXITCODE -> cleanup kill")
                Get-OurHostProcesses | ForEach-Object { taskkill /F /T /PID $_.ProcessId | Out-Null }
                Start-Sleep -Seconds 3
            }
        }
    }
}

if (-not $SkipTiming) { foreach ($segment in $segments) { Invoke-SegmentTiming $segment } }
if (-not $SkipSemantics) { foreach ($segment in $segments) { Invoke-SegmentSemantics $segment } }

# ---- 语义判定（lag=1 严格 + seek 窗口）----
$lag = $null
$tolerance = $null
$lagPath = Join-Path $OutRoot 'lag-p4.json'

# 计时段复用语义段结果（分开跑：先 -SkipTiming 跑语义，再 -SkipSemantics -SemanticsRoot 跑计时）
if ($SkipSemantics -and $SemanticsRoot) {
    $reuseLag = Join-Path ([IO.Path]::GetFullPath($SemanticsRoot)) 'lag-p4.json'
    if (Test-Path -LiteralPath $reuseLag) {
        $lag = Read-Json $reuseLag
        $lagPath = $reuseLag
        Copy-Item -LiteralPath $reuseLag -Destination (Join-Path $OutRoot 'lag-p4.json') -Force
        Add-Check 'semantics_reused' 'passed' "lag=$reuseLag"
        # 容差结论也必须一起复用，否则计时段会拿空的 $tolerance 去判 lag1_within_tolerance。
        $reuseTol = Join-Path ([IO.Path]::GetFullPath($SemanticsRoot)) 'lag-tolerance.json'
        if (Test-Path -LiteralPath $reuseTol) {
            Copy-Item -LiteralPath $reuseTol -Destination (Join-Path $OutRoot 'lag-tolerance.json') -Force
            $tolerance = Read-Json $reuseTol
            Add-Check 'tolerance_reused' 'passed' "tol=$reuseTol"
        } else {
            Add-Check 'tolerance_reused' 'warning' "missing=$reuseTol"
        }
    } else {
        Add-Check 'semantics_reused' 'failed' "missing=$reuseLag"
    }
}
if (-not $SkipSemantics -and $semantics.ContainsKey('A1-sync') -and $semantics.ContainsKey('B-async')) {
    $analyzerArgs = @($Analyzer,
        '--sync-a1', (Join-Path (Split-Path -Parent $semantics['A1-sync']) 'probe.host.json'),
        '--async-b', (Join-Path (Split-Path -Parent $semantics['B-async']) 'probe.host.json'),
        '--out', $lagPath)
    if ($semantics.ContainsKey('A2-sync')) {
        $analyzerArgs += @('--sync-a2', (Join-Path (Split-Path -Parent $semantics['A2-sync']) 'probe.host.json'))
    }
    if ($SeekAfterFrame -ge 0 -and $SeekToFrame -ge 0) { $analyzerArgs += @('--seek-after-frame', $SeekAfterFrame, '--seek-to-frame', $SeekToFrame) }
    & python @analyzerArgs | Out-Host
    $lag = Read-Json $lagPath

    # 分档 lag 的容差判据：参与求解的刚体比前一帧，骨骼跟随刚体比同帧（见 analyze-lag-tolerance.py 头注释）。
    $tolerancePath = Join-Path $OutRoot 'lag-tolerance.json'
    $toleranceArgs = @((Join-Path $PSScriptRoot 'analyze-lag-tolerance.py'),
        '--sync-a1', (Join-Path (Split-Path -Parent $semantics['A1-sync']) 'probe.host.json'),
        '--async-b', (Join-Path (Split-Path -Parent $semantics['B-async']) 'probe.host.json'),
        '--out', $tolerancePath)
    if ($semantics.ContainsKey('A2-sync')) {
        $toleranceArgs += @('--sync-a2', (Join-Path (Split-Path -Parent $semantics['A2-sync']) 'probe.host.json'))
    }
    if ($SeekAfterFrame -ge 0 -and $SeekToFrame -ge 0) {
        # seek 回来后重建世界的第一步必然是冷状态，Bullet 状态路径相关，不进判定；由 rebuild_transient 单独报告。
        $toleranceArgs += @('--seek-after-frame', $SeekAfterFrame, '--seek-to-frame', $SeekToFrame, '--seek-settle-frames', 1)
    }
    & python @toleranceArgs | Out-Host
    if (-not (Test-Path -LiteralPath $tolerancePath)) {
        throw "lag tolerance analysis produced no output: $tolerancePath"
    }
    $tolerance = Read-Json $tolerancePath
}

$semanticsOk = $false
$benefit = $null
$decision = 'unavailable'
if ($lag) {
    $displacement = $lag.displacement
    $asyncMoved = [bool]$displacement.'B-async'.all_rigids_moved
    $syncMoved = [bool]$displacement.'A1-sync'.all_rigids_moved
    Add-Check 'writeback_sync_all_rigids_moved' ($(if ($syncMoved) { 'passed' } else { 'failed' })) "moved=$($displacement.'A1-sync'.rigids_moved) frozen=$($displacement.'A1-sync'.rigids_frozen) frames=$($displacement.'A1-sync'.frames)"
    Add-Check 'writeback_async_all_rigids_moved' ($(if ($asyncMoved) { 'passed' } else { 'failed' })) "moved=$($displacement.'B-async'.rigids_moved) frozen=$($displacement.'B-async'.rigids_frozen)"

    # 逐位相等只作信息项：判据按刚体类型分档 lag（动力学 lag=1、骨骼跟随 lag=0），见 analyze-lag-tolerance.py。
    Add-Check 'lag1_bitwise_equal' 'info' "equal=$($lag.lag1.equal_frames)/$($lag.lag1.frames_compared) earliest=$($lag.lag1.earliest_mismatch_frame) verdict=$($lag.verdict)"
    # 旧分析器把 479 个刚体一律按 lag1 比，对骨骼跟随刚体天生不成立，只作信息项。
    Add-Check 'lag_constant_lag1' 'info' "lag_constant=$($lag.lag_constant) verdict=$($lag.verdict)（旧口径，骨骼跟随刚体应为 lag0）"
    $tolLag = if ($tolerance) { $tolerance.lag1 } else { $null }
    $tolOk = if ($tolLag) { [bool]$tolLag.all_within } else { $false }
    if ($null -eq $tolLag) {
        Add-Check 'lag1_within_tolerance' 'failed' '容差结论缺失（lag-tolerance.json 未生成也未复用）'
    }
    if ($tolerance -and $tolerance.rebuild_transient) {
        $transient = $tolerance.rebuild_transient
        Add-Check 'rebuild_transient_reported' 'info' ("跳过重建瞬态帧 {0}：{1}/{2} 帧在容差内 maxT={3}mm（不计入判定）" -f `
            ($transient.frames -join ','), $transient.frames_within_tolerance, $transient.frames_compared, $transient.max_translation_dev_mm)
    }
    if ($tolLag) {
        Add-Check 'lag1_within_tolerance' ($(if ($tolOk) { 'passed' } else { 'failed' })) ("within={0}/{1} maxT={2}mm maxR={3}rad over={4} dyn={5}bad/{6} kin={7}bad/{8}" -f `
            $tolLag.frames_within_tolerance, $tolLag.frames_compared, $tolLag.max_translation_dev_mm, $tolLag.max_rotation_dev_rad, `
            $tolLag.bodies_over_tolerance, $tolLag.per_class.dynamic.over_tolerance, $tolLag.per_class.dynamic.compared, `
            $tolLag.per_class.kinematic.over_tolerance, $tolLag.per_class.kinematic.compared)
    }

    $roster = $lag.roster
    $rosterOk = [bool]$roster.same_roster -and ($roster.'B-async'.count -eq $ExpectRigid) -and $roster.'B-async'.indices_contiguous -and ($roster.'B-async'.duplicates -eq 0) -and ($roster.'B-async'.unresolved_bones -eq 0)
    Add-Check 'roster_aligned' ($(if ($rosterOk) { 'passed' } else { 'failed' })) "count=$($roster.'B-async'.count) contiguous=$($roster.'B-async'.indices_contiguous) dup=$($roster.'B-async'.duplicates) unresolved=$($roster.'B-async'.unresolved_bones)"

    $anchorOk = @($lag.anchors.PSObject.Properties | Where-Object { $_.Value.local_matches -and $_.Value.world_matches }).Count -eq 3
    Add-Check 'anchor_mesh_540_560_619' ($(if ($anchorOk) { 'passed' } else { 'failed' })) '540/560/619 局部+世界锚点'
    if ($lag.sync_a1_vs_a2) {
        Add-Check 'sync_a1_vs_a2' ($(if ($lag.sync_a1_vs_a2.all_identical) { 'passed' } else { 'failed' })) "$($lag.sync_a1_vs_a2.identical)/$($lag.sync_a1_vs_a2.frames)"
    }

    $seekOk = $null
    if ($tolerance -and $tolerance.seek_pre -and $tolerance.seek_post) {
        $preTol = $tolerance.seek_pre
        $postTol = $tolerance.seek_post
        $preOk = [bool]$preTol.all_within
        $postOk = [bool]$postTol.all_within
        $events = if ($lag.seek) { @($lag.seek.events).Count } else { 0 }
        $seekOk = $preOk -and $postOk
        Add-Check 'seek_pre_window_lag1' ($(if ($preOk) { 'passed' } else { 'failed' })) ("within={0}/{1} over={2} maxT={3}mm" -f $preTol.frames_within_tolerance, $preTol.frames_compared, $preTol.bodies_over_tolerance, $preTol.max_translation_dev_mm)
        Add-Check 'seek_post_window_lag1' ($(if ($postOk) { 'passed' } else { 'failed' })) ("within={0}/{1} over={2} maxT={3}mm" -f $postTol.frames_within_tolerance, $postTol.frames_compared, $postTol.bodies_over_tolerance, $postTol.max_translation_dev_mm)
        Add-Check 'seek_rebuild_evidence' ($(if ($events -ge 1) { 'passed' } else { 'warning' })) "seek_events=$events after=$SeekAfterFrame to=$SeekToFrame"
    }
    $semanticsOk = $asyncMoved -and $syncMoved -and $tolOk -and $rosterOk -and $anchorOk -and ($null -ne $seekOk) -and $seekOk
}

# ---- 计时结论（语义不过则标 unavailable）----
if ($timing.ContainsKey('A1-sync') -and $timing.ContainsKey('B-async') -and $timing.ContainsKey('A2-sync')) {
    $on1 = $timing['A1-sync'].on_median; $on2 = $timing['A2-sync'].on_median
    $a1a2 = if ($on1 -and $on2) { [math]::Abs($on1 - $on2) / [math]::Max($on1, $on2) * 100.0 } else { $null }
    if ($null -ne $a1a2) {
        Add-Check 'a1_a2_drift' ($(if ($a1a2 -le $DriftLimitPct) { 'passed' } else { 'failed' })) ('{0:N2}% (limit {1}%)' -f $a1a2, $DriftLimitPct)
    }
    if ($on1 -and $on2) {
        $syncOn = ($on1 + $on2) / 2.0
        $benefit = $syncOn - $timing['B-async'].on_median
        if ($semanticsOk) {
            if ($benefit -ge $PromoteThresholdMs) { $decision = 'promote' }
            elseif ($benefit -lt $InvisibleThresholdMs) { $decision = 'archive_invisible' }
            else { $decision = 'gray_keep_off' }
        } else {
            $decision = 'unavailable'
            Add-Check 'timing_conclusion_gated' 'warning' "语义未过：收益 $([math]::Round($benefit,3)) ms 只作参考，不对外给结论"
        }
    }
}

Add-Check 'host_clean' ($(if (@(Get-OurHostProcesses).Count -eq 0 -and -not (Get-NetTCPConnection -State Listen -LocalPort $Port -ErrorAction SilentlyContinue)) { 'passed' } else { 'failed' })) 'C4D=0 & 5557 无监听'

$failures = @($checks | Where-Object { $_.status -eq 'failed' })
$summaryOut = [ordered]@{
    schema      = 'vmd-p4-ab/1'
    config      = [ordered]@{
        out_root = $OutRoot; launches = $Launches; reps = $Reps; warmup = $Warmup; frames = $Frames; start_frame = $StartFrame
        max_load_pct = $MaxLoadPct; quiet_max_load_pct = $QuietMaxLoadPct
        semantic_frames = $semanticFramesSpec; seek_after_frame = $SeekAfterFrame; seek_to_frame = $SeekToFrame
        criteria = 'lag1_strict'; async_pipeline = $AsyncPipeline
    }
    artifacts   = [ordered]@{ sync_sha256 = $syncSha; async_sha256 = $asyncSha; sync_path = (Get-ModulePath $SyncPluginsPath); async_path = (Get-ModulePath $AsyncPluginsPath) }
    timing      = $timing
    semantics   = [ordered]@{ probe_paths = $semantics; lag_path = $lagPath; reasoning = $lag }
    verdict     = [ordered]@{ semantics_ok = $semanticsOk; benefit_ms = $benefit; decision = $decision; promote_threshold_ms = $PromoteThresholdMs; invisible_threshold_ms = $InvisibleThresholdMs }
    checks      = $checks
    warnings    = $warnings
    elapsed_s   = [math]::Round(((Get-Date) - $runStart).TotalSeconds, 1)
}
$summaryPath = Join-Path $OutRoot 'run-summary.json'
if (Test-Path -LiteralPath $summaryPath) {
    $archive = "$OutRoot-archive-$(Get-Date -Format 'yyyyMMddTHHmmss')"
    Move-Item -LiteralPath $OutRoot -Destination $archive
    New-Item -ItemType Directory -Force -Path $OutRoot | Out-Null
    $summaryOut.config.out_root = $OutRoot
}
$summaryOut | ConvertTo-Json -Depth 12 | Set-Content -LiteralPath $summaryPath -Encoding UTF8

Write-Host ('P4_AB_RESULT:' + ([ordered]@{
    semantics_ok = $semanticsOk
    decision     = $decision
    benefit_ms   = $benefit
    lag_constant = if ($lag) { $lag.lag_constant } else { $null }
    verdict      = if ($lag) { $lag.verdict } else { $null }
    failures     = @($failures | ForEach-Object { $_.id })
    warnings     = @($warnings)
    summary      = $summaryPath
} | ConvertTo-Json -Depth 5 -Compress))

if ($failures.Count -gt 0) { Write-Host ("FAILURES: " + (@($failures | ForEach-Object { $_.id }) -join ', ')); exit 1 }
Write-Host 'P4_AB_OK'
exit 0

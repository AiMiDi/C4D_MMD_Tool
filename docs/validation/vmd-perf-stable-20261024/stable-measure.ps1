#Requires -Version 7.0
<#
.SYNOPSIS
    隔��宿主可重复测量：按固定配方重建场景，在**同一宿主会话内**交替物理开/关测多轮，
    并可跨多次启动（-Launches）验证跨启动散布。

.DESCRIPTION
    为什么要有这个脚本（t14 背景）：
      t8/t13 的同一 baseline 工件跨启动曾测出 34.0 / 45.1 / 65.6 ms（约 2×），说明
      "绝对毫秒"受宿主会话与机器负载影响极大。所以要：
        1) 同一会话内交替测量（-Rounds），只信同一时段内的相对差；
        2) 跨启动重复（-Launches），量化散布，并同时记录机器状态（电源计划/频率/负载/
           邻居进程/C4D 线程数）用于归因；
        3) 每次启动都核对宿主实际加载的模块 sha256，防止测错版本。

    默认（-Variant baseline）用 S:\tmp\...\ab\baseline\plugins 里冻结的基线工件，
    而不是可能被并行构建改写的 _build_msvc 产物；用 -Variant live 才用实时构建目录。

.EXAMPLE
    pwsh -NoProfile -File stable-measure.ps1 -Variant baseline -PhysicsBoth -Rounds 5 `
        -OutDir S:\tmp\cmt_vmd_profile_20261019\stable\baseline-verify

.EXAMPLE
    # 跨启动散布（验收用）：5 次启动 × 每次 5 轮交替
    pwsh -NoProfile -File stable-measure.ps1 -Variant profiling -PhysicsBoth -Rounds 5 -Launches 5
#>
[CmdletBinding()]
param(
    [string]$Variant = 'baseline',
    [string]$PluginsPath = '',
    [switch]$PhysicsBoth,
    [ValidateSet('on', 'off', 'both')]
    [string]$Physics = 'both',
    [int]$Rounds = 5,
    [int]$Launches = 1,
    # 单次启动内允许重试次数（宿主偶发 REENTRANT_DRAIN 卡死时用；0 = 不重试）
    [int]$LaunchRetries = 1,
    [string]$OutDir = '',
    # 计时口径：all = EXECUTIONFLAGS_PASS_ALL（t8/t13 历史口径，默认）；default = EXECUTIONFLAGS_0
    [ValidateSet('all','default')][string]$ExecFlags = 'all',
    [int]$Warmup = 20,
    [int]$Frames = 40,
    [int]$StartFrame = 560,
    [int]$StopTimeoutSeconds = 15,
    [string]$PmxPath = 'C:\pmx\白银之城—阿芙2.0\阿芙2.0.pmx',
    [string]$VmdPath = 'C:\vmd\Stay Tonight Heaven Lee Ver. 动作.vmd',
    [string]$CinemaExe = 'C:\Program Files\Maxon Cinema 4D 2027\Cinema 4D.exe',
    [string]$PrefsPath = 'S:\tmp\cmt_vmd_profile_20261019\host_profile',
    [int]$Port = 5557,
    [int]$ReadyTimeoutSeconds = 180,
    [switch]$KeepRunning,
    [switch]$RequireSpread,
    [double]$SpreadThresholdPct = 10.0,
    [string]$Label = '',
    # 负载对照：>0 时先起这么多 CPU 占用进程，再跑测量，用于复现"邻居抢 CPU"造成的漂移。
    [int]$LoadWorkers = 0,
    # 机器负载门禁：>0 时，若本次启动前后测到的 CPU 总占用超过该百分比，则丢弃本次启动并重试
    # （t14 实测：外部负载 82% 时 on median +21%，是跨启动散布的主因；clock 恒定 3200MHz 与散布无关）。
    [double]$MaxLoadPct = 0
)

Set-StrictMode -Version Latest
$ErrorActionPreference = 'Stop'

$here = $PSScriptRoot
$launchScript = Join-Path $here '..\vmd-host-restore-20261024\launch-host.ps1'
$stopScript = Join-Path $here '..\vmd-host-restore-20261024\stop-host.ps1'
$probePy = Join-Path $here 'stable-probe.py'
foreach ($needed in @($launchScript, $stopScript, $probePy)) {
    if (-not (Test-Path $needed)) { throw "missing_dependency: $needed" }
}

# --- 变体解析 ---------------------------------------------------------------
$frozenRoot = 'S:\tmp\cmt_vmd_profile_20261019\ab'
$livePlugins = 'C:\code\C4D_MMD_Tool\_build_msvc\sdk_2027_v143\bin\Release\plugins'
$profilingPlugins = 'S:\tmp\cmt_vmd_profile_20261019\profiling-build\bin\Release\plugins'
$variantMap = @{
    'baseline'  = if (Test-Path (Join-Path $frozenRoot 'baseline\plugins\mmdtool\mmdtool.xdl64')) { Join-Path $frozenRoot 'baseline\plugins' } else { $livePlugins }
    'candidate' = if (Test-Path (Join-Path $frozenRoot 'candidate\plugins\mmdtool\mmdtool.xdl64')) { Join-Path $frozenRoot 'candidate\plugins' } else { $livePlugins }
    'live'      = $livePlugins
    'profiling' = $profilingPlugins
}
$resolvedPlugins = if ($PluginsPath) { $PluginsPath } elseif ($variantMap.ContainsKey($Variant)) { $variantMap[$Variant] } else { $Variant }
if (-not (Test-Path $resolvedPlugins)) { throw "plugins_path_missing: $resolvedPlugins" }

$xdl64 = Join-Path $resolvedPlugins 'mmdtool\mmdtool.xdl64'
if (-not (Test-Path $xdl64)) { throw "plugin_artifact_missing: $xdl64" }
$artifact = Get-Item $xdl64
$artifactSha = (Get-FileHash $xdl64 -Algorithm SHA256).Hash
$bytes = [System.IO.File]::ReadAllBytes($xdl64)
$marker = [System.Text.Encoding]::ASCII.GetString($bytes).Contains('CMT_RUNTIME_PROFILING=1')

if (-not $OutDir) {
    $stamp = (Get-Date).ToUniversalTime().ToString('yyyyMMddTHHmmssZ')
    $OutDir = Join-Path 'S:\tmp\cmt_vmd_profile_20261019\stable' ("{0}-{1}" -f $stamp, $Variant)
}
if (Test-Path (Join-Path $OutDir 'run-summary.json')) {
    $archive = '{0}-archive-{1}' -f $OutDir, (Get-Date).ToUniversalTime().ToString('yyyyMMddTHHmmssZ')
    Write-Host "[archive] existing run-summary.json -> $archive"
    Move-Item -LiteralPath $OutDir -Destination $archive
}
New-Item -ItemType Directory -Force -Path $OutDir | Out-Null
$OutDir = (Resolve-Path $OutDir).Path

$modes = if ($PhysicsBoth) { @('on', 'off') } elseif ($Physics -eq 'both') { @('on', 'off') } else { @($Physics) }
$modeSpec = if ($modes.Count -eq 2) { 'both' } else { $modes[0] }

function Get-SystemState {
    param([string]$Tag)
    $cpu = Get-CimInstance Win32_Processor -ErrorAction SilentlyContinue | Select-Object -First 1
    $scheme = ''
    try { $scheme = (& powercfg /getactivescheme) -join ' ' } catch { $scheme = 'unavailable' }
    $sample = @()
    for ($i = 0; $i -lt 2; $i++) {
        try {
            $s = Get-Counter '\Processor(_Total)\% Processor Time' -SampleInterval 1 -MaxSamples 1 -ErrorAction Stop
            $sample += [double]$s.CounterSamples[0].CookedValue
        } catch { }
        Start-Sleep -Milliseconds 150
    }
    $top = @(Get-Process -ErrorAction SilentlyContinue |
        Sort-Object -Property CPU -Descending | Select-Object -First 5 |
        ForEach-Object { [ordered]@{ name = $_.ProcessName; pid = $_.Id; cpu_s = [math]::Round([double]$_.CPU, 1) } })
    $c4dProcs = @(Get-Process 'Cinema 4D' -ErrorAction SilentlyContinue)
    $c4dInfo = @($c4dProcs | ForEach-Object {
            [ordered]@{
                pid           = $_.Id
                threads       = $_.Threads.Count
                cpu_s         = [math]::Round([double]$_.CPU, 1)
                working_set   = $_.WorkingSet64
                priority      = $_.PriorityClass.ToString()
            }
        })
    return [ordered]@{
        schema            = 'vmd-system-state/1'
        tag               = $Tag
        captured_local    = (Get-Date).ToString('o')
        cpu_name          = $cpu.Name
        logical_cpus      = $cpu.NumberOfLogicalProcessors
        current_mhz       = $cpu.CurrentClockSpeed
        max_mhz           = $cpu.MaxClockSpeed
        load_pct_wmi      = $cpu.LoadPercentage
        cpu_total_samples = $sample
        power_scheme      = $scheme
        cinema4d          = $c4dInfo
        top_processes     = $top
    }
}

$launchResults = @()
$launchFailures = @()
$launchDiscards = @()
$sw = [System.Diagnostics.Stopwatch]::StartNew()

# 可选负载对照（默认 0 = 不干扰）：用独立 pwsh 进程跑算术死循环占 CPU。
$loadProcesses = @()
function Stop-LoadWorkers {
    foreach ($proc in $script:loadProcesses) {
        try { if (-not $proc.HasExited) { $proc.Kill($true) } } catch { }
    }
    $script:loadProcesses = @()
}
if ($LoadWorkers -gt 0) {
    $loopCode = '$end=(Get-Date).AddMinutes(45); while((Get-Date) -lt $end){ $a=0; for($i=0;$i -lt 400000;$i++){ $a=(($a+$i) % 1000003) } }'
    for ($w = 1; $w -le $LoadWorkers; $w++) {
        $loadProcesses += Start-Process -FilePath (Get-Process -Id $PID).Path -PassThru -WindowStyle Hidden `
            -ArgumentList '-NoProfile', '-Command', $loopCode
    }
    Write-Host ("[load] started {0} busy workers: {1}" -f $LoadWorkers, (($loadProcesses | ForEach-Object { $_.Id }) -join ','))
    Start-Sleep -Seconds 3
}

try {

for ($n = 1; $n -le $Launches; $n++) {
  for ($attempt = 1; $attempt -le ($LaunchRetries + 1); $attempt++) {
    $launchDir = Join-Path $OutDir $(if ($attempt -eq 1) { 'launch-{0}' -f $n } else { 'launch-{0}-retry{1}' -f $n, $attempt })
    New-Item -ItemType Directory -Force -Path $launchDir | Out-Null
    Write-Host ("[{0}] launch {1}/{2} plugins={3}" -f (Get-Date -Format 'HH:mm:ss'), $n, $Launches, $resolvedPlugins)

    $before = Get-SystemState -Tag ("launch{0}-before" -f $n)
    $before | ConvertTo-Json -Depth 8 | Set-Content -LiteralPath (Join-Path $launchDir 'system-before.json') -Encoding utf8

    $envSaved = @{ CMT_RUNTIME_PROFILE = $env:CMT_RUNTIME_PROFILE; CMT_PROFILE_LOG = $env:CMT_PROFILE_LOG }
    $profileLog = Join-Path $launchDir 'profile.log'
    if ($marker) {
        $env:CMT_RUNTIME_PROFILE = '1'
        $env:CMT_PROFILE_LOG = $profileLog
    }

    $launchStart = Get-Date
    try {
        & pwsh -NoProfile -File $launchScript -Execute -ModulePath $resolvedPlugins -OutRoot $launchDir `
            -CinemaExe $CinemaExe -PrefsPath $PrefsPath -Port $Port -ReadyTimeoutSeconds $ReadyTimeoutSeconds 2>&1 |
            Tee-Object -FilePath (Join-Path $launchDir 'launch.log') | Out-Null
        $launchExit = $LASTEXITCODE
    }
    finally {
        if ($marker) { $env:CMT_RUNTIME_PROFILE = $envSaved.CMT_RUNTIME_PROFILE; $env:CMT_PROFILE_LOG = $envSaved.CMT_PROFILE_LOG }
    }
    $launchSeconds = [math]::Round((New-TimeSpan -Start $launchStart).TotalSeconds, 1)
    $identityPath = Join-Path $launchDir 'host-identity.json'
    if ($launchExit -ne 0 -or -not (Test-Path $identityPath)) {
        Write-Host "[fail] launch $n exit=$launchExit (see $launchDir\launch.log)"
        $launchFailures += [ordered]@{ launch = $n; attempt = $attempt; dir = $launchDir; ok = $false; stage = 'launch'; exit_code = $launchExit; launch_seconds = $launchSeconds }
        if ($attempt -le $LaunchRetries) { Write-Host "    [retry] launch $n attempt $attempt launch_failed; retrying"; continue }
        break
    }
    $identity = Get-Content -LiteralPath $identityPath -Raw | ConvertFrom-Json
    $hostedModuleSha = ''
    if ($identity.PSObject.Properties['modules'] -and $identity.modules.PSObject.Properties['mmdtool_loaded']) {
        $hostedModuleSha = [string]$identity.modules.mmdtool_loaded.sha256
    }
    $moduleMatch = ($hostedModuleSha -and $hostedModuleSha.ToLower() -eq $artifactSha.ToLower())
    Write-Host ("    pid={0} ticks={1} module_match={2} startup={3}s" -f $identity.host.pid, $identity.host.start_ticks_utc, $moduleMatch, $launchSeconds)

    $afterLaunch = Get-SystemState -Tag ("launch{0}-running" -f $n)
    $launchLoadPct = if (@($afterLaunch.cpu_total_samples).Count -gt 0) {
        [math]::Round((($afterLaunch.cpu_total_samples | Measure-Object -Average).Average), 1)
    }
    else { $afterLaunch.load_pct_wmi }
    if ($MaxLoadPct -gt 0 -and $launchLoadPct -gt $MaxLoadPct) {
        Write-Host ("    [gate] load {0}% > {1}% ; discard this launch and retry" -f $launchLoadPct, $MaxLoadPct)
        if (-not $KeepRunning) {
            & pwsh -NoProfile -File $stopScript -Execute -IdentityPath $identityPath -OutRoot $launchDir -StopTimeoutSeconds $StopTimeoutSeconds 2>&1 | Out-Null
        }
        $launchDiscards += [ordered]@{ launch = $n; attempt = $attempt; dir = $launchDir; stage = 'load_gate'; load_pct = $launchLoadPct }
        if ($attempt -le $LaunchRetries) { continue }
        break
    }
    $afterLaunch | ConvertTo-Json -Depth 8 | Set-Content -LiteralPath (Join-Path $launchDir 'system-running.json') -Encoding utf8

    $probeJson = Join-Path $launchDir 'probe.json'
    $probeCsv = Join-Path $launchDir 'frames.csv'
    $probeArgs = @(
        $probePy, '--pmx', $PmxPath, '--vmd', $VmdPath,
        '--reps', $Rounds, '--mode', $modeSpec,
        '--warmup', $Warmup, '--frames', $Frames, '--start', $StartFrame,
        '--out', $probeJson, '--csv', $probeCsv,
        '--label', ("{0}-L{1}" -f ($(if ($Label) { $Label } else { $Variant })), $n),
        '--exec-flags', $ExecFlags
    )
    if ($marker) { $probeArgs += @('--profile-log', $profileLog) }
    $probeStart = Get-Date
    & python @probeArgs 2>&1 | Tee-Object -FilePath (Join-Path $launchDir 'probe.log') | ForEach-Object { Write-Host ('    ' + $_) }
    $probeExit = $LASTEXITCODE
    $probeSeconds = [math]::Round((New-TimeSpan -Start $probeStart).TotalSeconds, 1)

    $afterProbe = Get-SystemState -Tag ("launch{0}-after-probe" -f $n)
    $afterProbe | ConvertTo-Json -Depth 8 | Set-Content -LiteralPath (Join-Path $launchDir 'system-after-probe.json') -Encoding utf8

    $probe = $null
    if (Test-Path $probeJson) { $probe = Get-Content -LiteralPath $probeJson -Raw | ConvertFrom-Json }

    $cleanupPath = Join-Path $launchDir 'cleanup.json'
    $stopExit = 0
    if (-not $KeepRunning) {
        & pwsh -NoProfile -File $stopScript -Execute -IdentityPath $identityPath -OutRoot $launchDir -StopTimeoutSeconds $StopTimeoutSeconds 2>&1 |
            Tee-Object -FilePath (Join-Path $launchDir 'stop.log') | Out-Null
        $stopExit = $LASTEXITCODE
    }
    $cleanup = $null
    if (Test-Path $cleanupPath) {
        try { $cleanup = Get-Content -LiteralPath $cleanupPath -Raw | ConvertFrom-Json } catch { $cleanup = $null }
    }
    $cleanupState = 'ok'
    $cleanupReason = ''
    if ($stopExit -ne 0) {
        $cleanupState = 'unavailable'
        $cleanupReason = "stop_host_error: exit=$stopExit (宿主可能已崩或不可达)"
    }
    elseif (-not $cleanup) {
        $cleanupState = 'unavailable'
        $cleanupReason = 'stop_host_no_cleanup_json'
    }
    elseif ($cleanup.PSObject.Properties['exited'] -and $cleanup.exited -ne $true) {
        $cleanupState = 'incomplete'
        $cleanupReason = 'host_still_running_after_stop'
    }
    if ($cleanupState -ne 'ok') {
        # 清理问题只作为告警记录，绝不吞掉本次测量结果；也不覆盖 stop-host 自己写下的 cleanup.json。
        [pscustomobject][ordered]@{ schema = 'vmd-cleanup-state/1'; state = $cleanupState; reason = $cleanupReason; stop_exit = $stopExit } |
            ConvertTo-Json -Depth 5 | Set-Content -LiteralPath (Join-Path $launchDir 'cleanup-state.json') -Encoding utf8
        Write-Host "    [warn] cleanup_state=$cleanupState $cleanupReason"
    }

    $wallByMode = [ordered]@{}
    $stageByMode = [ordered]@{}
    if ($probe) {
        foreach ($rep in $probe.reps) {
            if (-not $wallByMode.Contains($rep.mode)) { $wallByMode[$rep.mode] = @(); $stageByMode[$rep.mode] = @() }
            $wallByMode[$rep.mode] += [double]$rep.wall.median_ms
            $stageByMode[$rep.mode] += $rep
        }
    }
    $modeSummary = [ordered]@{}
    foreach ($mode in $wallByMode.Keys) {
        $vals = @($wallByMode[$mode] | Sort-Object)
        $modeSummary[$mode] = [ordered]@{
            reps                   = $vals.Count
            medians_ms             = @($vals | ForEach-Object { [math]::Round($_, 4) })
            median_of_medians_ms   = [math]::Round(($vals | Measure-Object -Average).Average, 4)
            min_ms                 = [math]::Round($vals[0], 4)
            max_ms                 = [math]::Round($vals[-1], 4)
            intra_spread_pct       = if ($vals.Count -gt 1 -and $vals[0] -gt 0) { [math]::Round(($vals[-1] - $vals[0]) / $vals[0] * 100, 2) } else { 0 }
        }
    }

    $launchResults += [ordered]@{
        launch         = $n
        dir            = $launchDir
        ok             = ($launchExit -eq 0 -and $probeExit -eq 0)
        cleanup_state  = $cleanupState
        cleanup_reason = $cleanupReason
        stage          = 'complete'
        artifact_sha   = $artifactSha
        artifact_bytes = $artifact.Length
        marker         = $marker
        hosted_module_sha = $hostedModuleSha
        module_match   = $moduleMatch
        identity       = [ordered]@{
            pid             = $identity.host.pid
            start_ticks_utc = [string]$identity.host.start_ticks_utc
            start_time      = $identity.host.start_time_local
            exe_version     = $identity.host.exe_version
            endpoint        = $identity.mcp.endpoint
        }
        launch_seconds = $launchSeconds
        probe_seconds  = $probeSeconds
        probe_exit     = $probeExit
        stop_exit      = $stopExit
        stop_method    = if ($cleanup -and $cleanup.PSObject.Properties['stop_method']) { [string]$cleanup.stop_method } else { '' }
        stop_forced    = if ($cleanup -and $cleanup.PSObject.Properties['stop_forced']) { $cleanup.stop_forced } else { $null }
        remaining_cinema4d = if ($cleanup -and $cleanup.PSObject.Properties['remaining_cinema_processes']) { @($cleanup.remaining_cinema_processes).Count } else { $null }
        c4d_threads    = if ($afterLaunch.cinema4d.Count -gt 0) { $afterLaunch.cinema4d[0].threads } else { $null }
        load_pct       = $launchLoadPct
        max_load_pct   = $MaxLoadPct
        cpu_total_samples = $afterLaunch.cpu_total_samples
        top_processes  = $afterLaunch.top_processes
        modes          = $modeSummary
        probe          = $probeJson
        frames_csv     = $probeCsv
    }

    if (-not $launchResults[-1].ok) {
        $launchResults = @($launchResults | Select-Object -SkipLast 1)
        $launchFailures += [ordered]@{ launch = $n; attempt = $attempt; dir = $launchDir; ok = $false; stage = 'probe'; probe_exit = $probeExit; stop_exit = $stopExit }
        Write-Host "[fail] launch $n attempt $attempt probe_exit=$probeExit stop_exit=$stopExit"
        if (-not $KeepRunning) {
            & pwsh -NoProfile -File $stopScript -Execute -IdentityPath $identityPath -OutRoot $launchDir -StopTimeoutSeconds $StopTimeoutSeconds 2>&1 | Out-Null
        }
        if ($attempt -le $LaunchRetries) { Write-Host "    [retry] launch $n attempt $attempt probe_failed; restarting host"; continue }
        break
    }
    break
  }
}

}
finally {
    if ($LoadWorkers -gt 0) { Stop-LoadWorkers; Write-Host '[load] workers stopped' }
}

# --- 跨启动散布 -------------------------------------------------------------
$aggregate = [ordered]@{}
foreach ($mode in $modes) {
    $perLaunch = @($launchResults | Where-Object { $_.ok -and $_.modes -and $_.modes.Contains($mode) } | ForEach-Object { [double]$_.modes[$mode].median_of_medians_ms })
    if ($perLaunch.Count -eq 0) { continue }
    $sorted = @($perLaunch | Sort-Object)
    $agg = [ordered]@{
        launches           = $perLaunch.Count
        per_launch_median_ms = @($perLaunch | ForEach-Object { [math]::Round($_, 4) })
        min_ms             = [math]::Round($sorted[0], 4)
        max_ms             = [math]::Round($sorted[-1], 4)
        median_ms          = [math]::Round(($sorted | Measure-Object -Average).Average, 4)
        spread_pct         = if ($sorted[0] -gt 0) { [math]::Round(($sorted[-1] - $sorted[0]) / $sorted[0] * 100, 2) } else { 0 }
    }
    $aggregate[$mode] = $agg
}

$spreadValues = @($aggregate.Values | ForEach-Object { [double]$_.spread_pct })
$maxSpread = if ($spreadValues.Count -gt 0) { ($spreadValues | Measure-Object -Maximum).Maximum } else { 0 }
$allOk = ((@($launchResults | Where-Object { -not $_.ok }).Count -eq 0) -and ($launchFailures.Count -eq 0) -and ($launchResults.Count -eq $Launches))
$spreadOk = ($maxSpread -le $SpreadThresholdPct)

$stageTables = [ordered]@{}
if ($marker) {
    foreach ($mode in $modes) {
        $names = @{}
        foreach ($res in $launchResults) {
            if (-not $res.ok) { continue }
            $probe = Get-Content -LiteralPath $res.probe -Raw | ConvertFrom-Json
            foreach ($rep in $probe.reps) {
                if ($rep.mode -ne $mode) { continue }
                foreach ($prop in $rep.stages.PSObject.Properties) { $names[$prop.Name] = $true }
            }
        }
        $table = [ordered]@{}
        foreach ($name in ($names.Keys | Sort-Object)) {
            $inc = @(); $slf = @(); $calls = @()
            foreach ($res in $launchResults) {
                if (-not $res.ok) { continue }
                $probe = Get-Content -LiteralPath $res.probe -Raw | ConvertFrom-Json
                foreach ($rep in $probe.reps) {
                    if ($rep.mode -ne $mode) { continue }
                    if ($rep.stages.PSObject.Properties[$name]) {
                        $inc += [double]$rep.stages.$name.median_inclusive_ms
                        $slf += [double]$rep.stages.$name.median_self_ms
                        $calls += [int]$rep.stages.$name.calls_median
                    }
                }
            }
            if ($inc.Count -eq 0) { continue }
            $table[$name] = [ordered]@{
                median_inclusive_ms = [math]::Round(($inc | Sort-Object)[[int][math]::Floor($inc.Count / 2)], 4)
                median_self_ms      = [math]::Round(($slf | Sort-Object)[[int][math]::Floor($slf.Count / 2)], 4)
                calls_median        = ($calls | Sort-Object)[[int][math]::Floor($calls.Count / 2)]
                samples             = $inc.Count
            }
        }
        $stageTables[$mode] = $table
    }
}

$summary = [ordered]@{
    schema            = 'vmd-stable-measure/1'
    variant           = $Variant
    label             = $Label
    plugins_path      = $resolvedPlugins
    artifact          = [ordered]@{ path = $xdl64; bytes = $artifact.Length; sha256 = $artifactSha; profiling_marker = $marker }
    config            = [ordered]@{
        rounds = $Rounds; launches = $Launches; modes = @($modes)
        warmup = $Warmup; frames = $Frames; start_frame = $StartFrame
        pmx = $PmxPath; vmd = $VmdPath
        physics_setting = $modeSpec
        condition = if ($LoadWorkers -gt 0) { 'loaded:' + $LoadWorkers + '-busy-workers' } else { 'idle' }
        profile_log = if ($marker) { 'CMT_PROFILE_LOG per launch' } else { $null }
    }
    started_local     = $before.captured_local
    elapsed_s         = [math]::Round($sw.Elapsed.TotalSeconds, 1)
    launches          = $launchResults
    cleanup_all_ok    = (@($launchResults | Where-Object { $_.PSObject.Properties['cleanup_state'] -and $_.cleanup_state -ne 'ok' }).Count -eq 0)
    max_load_pct_gate = $MaxLoadPct
    launch_failures   = @($launchFailures)
    launch_discards   = @($launchDiscards)
    aggregate         = $aggregate
    stages            = $stageTables
    gate              = [ordered]@{
        all_launches_ok        = $allOk
        max_cross_launch_spread_pct = $maxSpread
        spread_threshold_pct   = $SpreadThresholdPct
        spread_ok              = $spreadOk
        module_identity_all_match = (@($launchResults | Where-Object { $_.module_match -ne $true }).Count -eq 0)
    }
}
$summaryText = $summary | ConvertTo-Json -Depth 12
Set-Content -LiteralPath (Join-Path $OutDir 'run-summary.json') -Value $summaryText -Encoding utf8

$lines = @()
$lines += "# stable-measure summary ($Variant)"
$lines += ''
$lines += ('- plugins: `{0}`' -f $resolvedPlugins)
$lines += ('- artifact: {0} B sha256 `{1}` profiling_marker={2}' -f $artifact.Length, $artifactSha, $marker)
$lines += ('- config: rounds={0} launches={1} modes={2} warmup={3} frames={4} start={5}' -f $Rounds, $Launches, ($modes -join '/'), $Warmup, $Frames, $StartFrame)
$lines += ('- elapsed: {0}s' -f $summary.elapsed_s)
$lines += ''
$lines += '| launch | pid | ticks | module_sha | on median | off median | threads | stop |'
$lines += '|---|---|---|---|---|---|---|---|'
foreach ($res in $launchResults) {
    $on = if ($res.modes -and $res.modes.Contains('on')) { $res.modes['on'].median_of_medians_ms } else { '' }
    $off = if ($res.modes -and $res.modes.Contains('off')) { $res.modes['off'].median_of_medians_ms } else { '' }
    $lines += ('| {0} | {1} | {2} | {3} | {4} | {5} | {6} | {7} |' -f $res.launch, $res.identity.pid, $res.identity.start_ticks_utc,
        ($res.hosted_module_sha.Substring(0, [Math]::Min(16, $res.hosted_module_sha.Length))), $on, $off, $res.c4d_threads,
        ('{0}{1}' -f $res.stop_method, $(if ($res.stop_forced) { ' (forced)' } else { '' })))
}
$lines += ''
foreach ($mode in $aggregate.Keys) {
    $agg = $aggregate[$mode]
    $lines += ('- {0}: median {1} ms, min {2}, max {3}, 跨启动散布 {4}%' -f $mode, $agg.median_ms, $agg.min_ms, $agg.max_ms, $agg.spread_pct)
}
$lines += ''
$lines += ('- gate: all_launches_ok={0} spread_ok={1} (阈 {2}%, 实测 {3}%) module_identity_all_match={4}' -f $allOk, $spreadOk, $SpreadThresholdPct, $maxSpread, $summary.gate.module_identity_all_match)
Set-Content -LiteralPath (Join-Path $OutDir 'summary.md') -Value ($lines -join "`n") -Encoding utf8

$lines | ForEach-Object { Write-Host $_ }
Write-Host ''
Write-Host ("STABLE_RESULT:" + (([ordered]@{
            variant         = $Variant
            out_dir         = $OutDir
            launches_ok     = @($launchResults | Where-Object { $_.ok }).Count
            launches_total  = $launchResults.Count
            aggregate       = $aggregate
            max_spread_pct  = $maxSpread
            spread_ok       = $spreadOk
            all_ok          = $allOk
            elapsed_s       = $summary.elapsed_s
        }) | ConvertTo-Json -Depth 8 -Compress))

$exit = if ($allOk -and ($spreadOk -or (-not $RequireSpread))) { 0 } else { 1 }
if (-not $allOk) { Write-Host 'FAILURES: see run-summary.json' } else { Write-Host 'FAILURES: none' }
exit $exit

#requires -Version 7.0
<#
.SYNOPSIS
  P2 异步物理的真实宿主 A/B/A 验证驱动（t31 交付物；本文件默认只做 dry-run 计划打印）。

.DESCRIPTION
  三段交替：A1 = sync（CMT_PHYSICS_ASYNC=0）→ B = async（=1）→ A2 = sync（=0）。
  每段做两件事（可用 -SkipTiming / -SkipSemantics 裁剪）：

    1) 计时：调用 docs/validation/vmd-perf-stable-20261024/stable-measure.ps1，
       沿用其安静门（-MaxLoadPct 30）、同会话交替、>=5 轮 rep、forced 清理。
    2) 语义：launch-host.ps1 起隔离宿主 → host-driver.py 建场景并导入资产 →
       probe-rigid.py 采样「ExecutePasses 之后」的刚体世界矩阵 + 网格 sha256 → stop-host.ps1 收尾。

  判定门槛（任务要求）：
    * 主线程每帧收益 >= 3.0 ms → 才值得考虑默认开；
    * < 1.5 ms → 判为不可见收益，归档结论、不默认开；
    * 1.5–3.0 ms 灰区 → 不默认开，要求延长轮次/换时段复测。

  语义断言（不能只看毫秒）：
    C0 锚点：sync 在 540/560/619 的网格局部 sha 前缀必须是 07757cb6 / 068d56c8 / c15545a9。
    C1 刚体位移一帧（精确）：async 帧 N 的 rigid_sha256 == sync 帧 N-1 的 rigid_sha256。
    C2 反证：async 帧 N 的刚体 != sync 帧 N（否则说明开关没生效，跑的还是同步路径）。
    C3 网格位移一帧（受限条件）：只有「动画静止窗口」（sync 的 N 与 N-1 网格相同）才要求
       async(N) == sync(N-1) 逐字节；其他帧动画本身在动，不要求相等，只记录差值来源。
    C4 稳定态：所有可比较的 async 帧都满足 C1/C3，即「晚且只晚一帧」是唯一差异。
    C5 刚体可见性（P2-002）：async(N) == sync(N-1) 且 != sync(N-2)（不是晚两帧、也不是没消费）。
    C6 关闭回退：A1 与 A2 两段 sync 的网格/刚体 sha 完全一致（开关关闭零差异、可复现）。

  失败处置：宿主不可达 / 确认弹窗卡住时按用户既有授权 Stop-Process，cleanup 里记 forced=true；
  崩溃包路径归档进报告（本脚本把 _bugreports 目录拷到 <OutRoot>/crash/ 再继续）。

.NOTES
  本任务（t31）不启动宿主：默认 -DryRun 只打印计划 JSON 并退出 0。
  真正开跑由复审 pass 后的执行任务调用 -Execute。
#>
[CmdletBinding()]
param(
    # 两版插件目录（都指向包含 mmdtool\mmdtool.xdl64 的 plugins 目录）
    [string]$SyncPluginsPath = '',
    [string]$AsyncPluginsPath = '',
    [string]$OutRoot = '',

    # 计量参数（透传给 stable-measure.ps1）
    [int]$Pairs = 5,
    [int]$Rounds = 5,
    [int]$Warmup = 15,
    [int]$Frames = 30,
    [int]$StartFrame = 560,
    [double]$MaxLoadPct = 30,
    [ValidateSet('all', 'default')][string]$ExecFlags = 'all',
    [int]$StopTimeoutSeconds = 15,

    # 语义采样帧：sync 需要覆盖 async 的 N-1 与 N-2，故多采 539/541/559/561/618
    [string]$SyncFrames = '539,540,541,559,560,561,618,619,620',
    # 两段必须按同一帧序列升序求值：物理是逐步推进的，帧序列不同会让 async(N) 与 sync(N-1) 不可比
    [string]$AsyncFrames = '539,540,541,559,560,561,618,619,620',
    [int]$ExpectRigid = 479,
    [int]$ExpectPoints = 70222,
    [switch]$SkipRigidDisplay,

    # 场景与宿主
    [string]$PmxPath = 'C:\pmx\白银之城—阿芙2.0\阿芙2.0.pmx',
    [string]$VmdPath = 'C:\vmd\Stay Tonight Heaven Lee Ver. 动作.vmd',
    [string]$CinemaExe = 'C:\Program Files\Maxon Cinema 4D 2027\Cinema 4D.exe',
    [string]$PrefsPath = 'S:\tmp\cmt_vmd_profile_20261019\host_profile',
    [int]$Port = 5557,
    [int]$ReadyTimeoutSeconds = 240,

    # 判定门槛
    [double]$PromoteThresholdMs = 3.0,
    [double]$InvisibleThresholdMs = 1.5,

    # 执行控制
    [switch]$SkipTiming,
    [switch]$SkipSemantics,
    [switch]$KeepRunning,
    [switch]$Execute,
    [switch]$DryRun
)

$ErrorActionPreference = 'Stop'
Set-StrictMode -Version Latest

$script:RepoRoot = Split-Path -Parent (Split-Path -Parent (Split-Path -Parent $PSScriptRoot))
$script:StableMeasure = Join-Path $script:RepoRoot 'docs\validation\vmd-perf-stable-20261024\stable-measure.ps1'
$script:LaunchHost = Join-Path $script:RepoRoot 'docs\validation\vmd-host-restore-20261024\launch-host.ps1'
$script:StopHost = Join-Path $script:RepoRoot 'docs\validation\vmd-host-restore-20261024\stop-host.ps1'
$script:HostDriver = Join-Path $script:RepoRoot 'docs\validation\vmd-host-restore-20261024\host-driver.py'
$script:ProbeRigid = Join-Path $PSScriptRoot 'probe-rigid.py'
$script:Failures = [System.Collections.Generic.List[string]]::new()
$script:Checks = [System.Collections.Generic.List[object]]::new()

if (-not $OutRoot) {
    $OutRoot = 'S:\tmp\cmt_vmd_profile_20261019\physics-async\runs\' + (Get-Date -Format 'yyyyMMddTHHmmss')
}

function Write-Step([string]$Text) { Write-Host ('[{0}] {1}' -f (Get-Date -Format 'HH:mm:ss'), $Text) }

function Add-Check([string]$Id, [string]$Status, [string]$Detail) {
    $script:Checks.Add([pscustomobject]@{ id = $Id; status = $Status; detail = $Detail })
    if ($Status -eq 'failed') { $script:Failures.Add("${Id}: $Detail") }
    Write-Host ("  {0,-34} {1,-7} {2}" -f $Id, $Status.ToUpperInvariant(), $Detail)
}

function Get-FileSha([string]$Path) {
    if (-not (Test-Path -LiteralPath $Path)) { return $null }
    return (Get-FileHash -LiteralPath $Path -Algorithm SHA256).Hash.ToLowerInvariant()
}

function Get-ModulePath([string]$PluginsPath) {
    if (-not $PluginsPath) { return $null }
    return (Join-Path $PluginsPath 'mmdtool\mmdtool.xdl64')
}

function Get-CpuLoadPct {
    try {
        $sample = Get-Counter '\Processor(_Total)\% Processor Time' -MaxSamples 1 -ErrorAction Stop
        return [math]::Round($sample.CounterSamples[0].CookedValue, 1)
    } catch {
        return $null
    }
}

function Get-Median([double[]]$Values) {
    # 自己算中位数：不依赖 Measure-Object 的可选开关（不同 PowerShell 版本支持不一致）
    $items = @($Values | Where-Object { $null -ne $_ } | Sort-Object)
    if ($items.Count -eq 0) { return $null }
    $middle = [int][math]::Floor($items.Count / 2)
    if ($items.Count % 2 -eq 1) { return [double]$items[$middle] }
    return ([double]$items[$middle - 1] + [double]$items[$middle]) / 2.0
}

function Get-OurHostProcesses {
    # 只认本任务私有 profile 的宿主（taskkill /T 连子进程一起收拾，避免单实例锁残留）
    $procs = Get-CimInstance Win32_Process -Filter "Name='Cinema 4D.exe'" -ErrorAction SilentlyContinue
    return @($procs | Where-Object { $_.CommandLine -and $_.CommandLine.Contains($PrefsPath) })
}

function Clear-OurHost {
    # 显式包成数组：Get-OurHostProcesses 可能返回 $null（没有残留宿主），StrictMode 下 $null.Count 会抛
    $ours = @(Get-OurHostProcesses)
    foreach ($proc in $ours) {
        & taskkill /F /T /PID $proc.ProcessId 2>&1 | Out-Null
    }
    if ($ours.Count -gt 0) { Start-Sleep -Seconds 3 }
    return $ours.Count
}

function Test-PortListening([int]$PortNumber) {
    return ((Get-NetTCPConnection -State Listen -LocalPort $PortNumber -ErrorAction SilentlyContinue | Measure-Object).Count -gt 0)
}

function Invoke-SegmentTiming {
    param([string]$Segment, [string]$PluginsPath, [string]$AsyncFlag)

    $outDir = Join-Path $OutRoot "segments\$Segment\timing"
    $previous = $env:CMT_PHYSICS_ASYNC
    try {
        $env:CMT_PHYSICS_ASYNC = $AsyncFlag
        Write-Step "segment $Segment 计时（CMT_PHYSICS_ASYNC=$AsyncFlag, load<$MaxLoadPct%）"
        & pwsh -NoProfile -File $script:StableMeasure `
            -Variant $Segment `
            -PluginsPath $PluginsPath `
            -PhysicsBoth `
            -Rounds $Rounds `
            -Launches $Pairs `
            -Warmup $Warmup `
            -Frames $Frames `
            -StartFrame $StartFrame `
            -MaxLoadPct $MaxLoadPct `
            -ExecFlags $ExecFlags `
            -Port $Port `
            -PrefsPath $PrefsPath `
            -CinemaExe $CinemaExe `
            -StopTimeoutSeconds $StopTimeoutSeconds `
            -OutDir $outDir 2>&1 | Tee-Object -FilePath (Join-Path $OutRoot "logs\segment-$Segment-timing.log") | Out-Host
        $exit = $LASTEXITCODE
    } finally {
        if ($null -eq $previous) { Remove-Item Env:CMT_PHYSICS_ASYNC -ErrorAction SilentlyContinue } else { $env:CMT_PHYSICS_ASYNC = $previous }
    }

    $summaryPath = Join-Path $outDir 'run-summary.json'
    if (-not (Test-Path -LiteralPath $summaryPath)) {
        Add-Check "timing_${Segment}_summary" 'failed' "缺 run-summary.json（stable-measure exit=$exit）"
        return $null
    }
    $summary = Get-Content -LiteralPath $summaryPath -Raw | ConvertFrom-Json
    $loads = @($summary.launches | ForEach-Object { $_.load_pct })
    # stable-measure 的 run-summary 把逐轮结果放在 aggregate.on/off（launches[] 内只有 probe/modes），
    # 早先按 $_.on.median_ms 取值会在 StrictMode 下抛「找不到属性 on」。
    $onMedian = if ($summary.aggregate -and $summary.aggregate.PSObject.Properties['on']) {
        @($summary.aggregate.on.per_launch_median_ms)
    } else { @() }
    $offMedian = if ($summary.aggregate -and $summary.aggregate.PSObject.Properties['off']) {
        @($summary.aggregate.off.per_launch_median_ms)
    } else { @() }
    Add-Check "timing_${Segment}_exit" ($(if ($exit -eq 0) { 'passed' } else { 'failed' })) "stable-measure exit=$exit，launches=$(@($summary.launches).Count)"

    return [pscustomobject]@{
        segment   = $Segment
        async     = ($AsyncFlag -eq '1')
        out_dir   = $outDir
        exit      = $exit
        launches  = @($summary.launches).Count
        on_median = (Get-Median $onMedian)
        off_median = (Get-Median $offMedian)
        on_values = $onMedian
        off_values = $offMedian
        loads     = $loads
    }
}

function Invoke-SegmentSemantics {
    param([string]$Segment, [string]$PluginsPath, [string]$AsyncFlag, [string]$FrameList)

    $segRoot = Join-Path $OutRoot "segments\$Segment\semantics"
    $hostOut = Join-Path $segRoot 'host'
    $probeOut = Join-Path $segRoot 'probe.json'
    New-Item -ItemType Directory -Force -Path $segRoot, $hostOut | Out-Null

    $module = Get-ModulePath $PluginsPath
    $previous = $env:CMT_PHYSICS_ASYNC
    try {
        $env:CMT_PHYSICS_ASYNC = $AsyncFlag
        Write-Step "segment $Segment 语义采样（CMT_PHYSICS_ASYNC=$AsyncFlag, frames=$FrameList）"

        & pwsh -NoProfile -File $script:LaunchHost -Execute -OutRoot $hostOut -ModulePath $PluginsPath `
            -Port $Port -PrefsPath $PrefsPath -CinemaExe $CinemaExe -ReadyTimeoutSeconds $ReadyTimeoutSeconds 2>&1 |
            Tee-Object -FilePath (Join-Path $OutRoot "logs\segment-$Segment-launch.log") | Out-Host
        if ($LASTEXITCODE -ne 0) {
            Add-Check "semantics_${Segment}_launch" 'failed' "launch-host.ps1 exit=$LASTEXITCODE"
            return $null
        }

        & python $script:HostDriver new-scene 2>&1 | Tee-Object -FilePath (Join-Path $OutRoot "logs\segment-$Segment-driver.log") | Out-Host
        & python $script:HostDriver import --pmx $PmxPath --vmd $VmdPath 2>&1 | Tee-Object -Append -FilePath (Join-Path $OutRoot "logs\segment-$Segment-driver.log") | Out-Host
        $motionLog = & python $script:HostDriver import-motion --vmd $VmdPath 2>&1
        $motionLog | Tee-Object -Append -FilePath (Join-Path $OutRoot "logs\segment-$Segment-driver.log") | Out-Host
        # 必须单独走 import-motion：`import --pmx --vmd` 只建模型不建动画槽（slot_count=0），
        # 场景会静止不动的假象，后续 C0/C1 全部无意义。
        $slotPresent = ($motionLog -join "`n") -match '"slot"\s*:\s*"'
        Add-Check "semantics_${Segment}_motion_slot" ($(if ($slotPresent) { 'passed' } else { 'failed' })) `
            $(if ($slotPresent) { 'import-motion 创建了动画槽' } else { 'import-motion 未返回 slot，场景不会求值' })
        if (-not $slotPresent) { return $null }

        & python $script:HostDriver set-mode --mode anim 2>&1 | Out-Null
        & python $script:HostDriver physics --enabled on 2>&1 | Out-Null

        $probeArgs = @($script:ProbeRigid, '--frames', $FrameList, '--out', $probeOut,
            '--expect-rigid', "$ExpectRigid", '--expect-points', "$ExpectPoints",
            '--prefs-path', $PrefsPath)
        # 刚体管理器 RIGID_DISPLAY_TYPE(1001) 出厂是 None(=OFF)：不开显示时 MMDRigidObject::Execute
# 根本不写 GetRelMl，刚体世界矩阵不会随物理更新（本任务实测）。默认必须打开。
if (-not $SkipRigidDisplay) { $probeArgs += '--enable-rigid-display' }
        & python @probeArgs 2>&1 | Tee-Object -FilePath (Join-Path $OutRoot "logs\segment-$Segment-probe.log") | Out-Host
        $probeExit = $LASTEXITCODE
        Add-Check "semantics_${Segment}_probe" ($(if ($probeExit -eq 0) { 'passed' } else { 'failed' })) "probe-rigid.py exit=$probeExit"
    } finally {
        if ($null -eq $previous) { Remove-Item Env:CMT_PHYSICS_ASYNC -ErrorAction SilentlyContinue } else { $env:CMT_PHYSICS_ASYNC = $previous }
        if (-not $KeepRunning) {
            $identity = Join-Path $hostOut 'host-identity.json'
            & pwsh -NoProfile -File $script:StopHost -Execute -IdentityPath $identity -OutRoot $hostOut -StopTimeoutSeconds $StopTimeoutSeconds 2>&1 |
                Tee-Object -FilePath (Join-Path $OutRoot "logs\segment-$Segment-stop.log") | Out-Host
        }
    }

    if (-not (Test-Path -LiteralPath $probeOut)) { return $null }
    return (Get-Content -LiteralPath $probeOut -Raw | ConvertFrom-Json)
}

function Get-FrameRecord($Probe, [int]$Frame) {
    if (-not $Probe) { return $null }
    return ($Probe.host.records | Where-Object { [int]$_.frame -eq $Frame } | Select-Object -First 1)
}

function Get-MeshLocalSha($Probe, [int]$Frame, [string]$ObjectFilter = 'Mesh') {
    $record = Get-FrameRecord $Probe $Frame
    if (-not $record) { return $null }
    $mesh = $record.meshes | Where-Object { $_.point_count -gt 0 -and $_.object -like "*$ObjectFilter*" } | Select-Object -First 1
    if (-not $mesh) { $mesh = $record.meshes | Where-Object { $_.point_count -gt 0 } | Select-Object -First 1 }
    if (-not $mesh) { return $null }
    return $mesh.local_sha256
}

function Get-RecordField($Probe, [int]$Frame, [string]$Field) {
    # StrictMode 下 (Get-FrameRecord ...).field 在缺记录时会抛「找不到属性」，这里统一返回 $null
    $record = Get-FrameRecord $Probe $Frame
    if (-not $record) { return $null }
    if (-not $record.PSObject.Properties[$Field]) { return $null }
    return $record.$Field
}

function Get-RosterKey($Probe) {
    # P2-004：把名册压成可逐项比较的键列表（RIGID_INDEX|name_local|bone_index|bone_name）
    if (-not $Probe) { return $null }
    if (-not $Probe.PSObject.Properties['roster']) { return $null }
    $rows = @($Probe.roster)
    if ($rows.Count -eq 0) { return $null }
    return @($rows | ForEach-Object {
            '{0}|{1}|{2}|{3}' -f $_.rigid_index, $_.name_local, $_.bone_index, $_.bone_name
        } | Sort-Object)
}

# ---------------------------------------------------------------- 计划（dry-run 也走这里）
New-Item -ItemType Directory -Force -Path $OutRoot, (Join-Path $OutRoot 'logs') | Out-Null
$syncModule = Get-ModulePath $SyncPluginsPath
$asyncModule = Get-ModulePath $AsyncPluginsPath

$plan = [pscustomobject]@{
    schema        = 'vmd-physics-async-plan/1'
    out_root      = $OutRoot
    segments      = @(
        [pscustomobject]@{ name = 'A1-sync'; env = 'CMT_PHYSICS_ASYNC=0'; plugins = $SyncPluginsPath }
        [pscustomobject]@{ name = 'B-async'; env = 'CMT_PHYSICS_ASYNC=1'; plugins = $AsyncPluginsPath }
        [pscustomobject]@{ name = 'A2-sync'; env = 'CMT_PHYSICS_ASYNC=0'; plugins = $SyncPluginsPath }
    )
    timing        = [pscustomobject]@{ tool = $script:StableMeasure; pairs = $Pairs; rounds = $Rounds; warmup = $Warmup; frames = $Frames; start_frame = $StartFrame; max_load_pct = $MaxLoadPct; exec_flags = $ExecFlags }
    semantics     = [pscustomobject]@{ sync_frames = $SyncFrames; async_frames = $AsyncFrames; expect_rigid = $ExpectRigid; expect_points = $ExpectPoints; rigid_display_disabled = [bool]$SkipRigidDisplay }
    thresholds    = [pscustomobject]@{ promote_ms = $PromoteThresholdMs; invisible_ms = $InvisibleThresholdMs }
    sync_artifact = [pscustomobject]@{ module = $syncModule; size = $(if ($syncModule -and (Test-Path -LiteralPath $syncModule)) { (Get-Item -LiteralPath $syncModule).Length } else { $null }); sha256 = (Get-FileSha $syncModule) }
    async_artifact = [pscustomobject]@{ module = $asyncModule; size = $(if ($asyncModule -and (Test-Path -LiteralPath $asyncModule)) { (Get-Item -LiteralPath $asyncModule).Length } else { $null }); sha256 = (Get-FileSha $asyncModule) }
}

if ($DryRun -or (-not $Execute)) {
    Write-Host 'DRY-RUN：只打印计划，不启动宿主、不测量（加 -Execute 才真正开跑）。'
    Write-Host ('AB_ASYNC_PLAN:' + ($plan | ConvertTo-Json -Depth 6 -Compress))
    exit 0
}

# ---------------------------------------------------------------- 正式执行
Write-Step '预检'
if (-not (Test-Path -LiteralPath $script:StableMeasure)) { throw "missing $script:StableMeasure" }
if (-not (Test-Path -LiteralPath $script:LaunchHost)) { throw "missing $script:LaunchHost" }
if (-not (Test-Path -LiteralPath $script:StopHost)) { throw "missing $script:StopHost" }
if (-not (Test-Path -LiteralPath $script:HostDriver)) { throw "missing $script:HostDriver" }
if (-not (Test-Path -LiteralPath $script:ProbeRigid)) { throw "missing $script:ProbeRigid" }
if (-not $syncModule -or -not (Test-Path -LiteralPath $syncModule)) { throw "sync plugin missing: $syncModule" }
if (-not $asyncModule -or -not (Test-Path -LiteralPath $asyncModule)) { throw "async plugin missing: $asyncModule" }
if ($plan.sync_artifact.sha256 -eq $plan.async_artifact.sha256) { throw 'sync/async 工件 sha 相同，说明 async 版没构建成功' }

$foreign = @(Get-CimInstance Win32_Process -Filter "Name='Cinema 4D.exe'" -ErrorAction SilentlyContinue | Where-Object { $_ })
if ($foreign.Count -gt 0) {
    Write-Step "清理上次残留的私有 profile 宿主：$(Clear-OurHost) 个"
}
if (Test-PortListening $Port) { throw "port $Port 已被占用，先清干净再跑" }
$load = Get-CpuLoadPct
Write-Step "初始 CPU 负载=$load%"

$timing = @{}
$semantics = @{}
$segments = @(
    @{ name = 'A1-sync'; flag = '0'; plugins = $SyncPluginsPath },
    @{ name = 'B-async'; flag = '1'; plugins = $AsyncPluginsPath },
    @{ name = 'A2-sync'; flag = '0'; plugins = $SyncPluginsPath }
)

foreach ($segment in $segments) {
    Write-Step "=== $($segment.name)"
    if (-not $SkipTiming) { $timing[$segment.name] = Invoke-SegmentTiming -Segment $segment.name -PluginsPath $segment.plugins -AsyncFlag $segment.flag }
    if (-not $SkipSemantics) {
        # 注意：变量名不能叫 $frames —— PowerShell 变量大小写不敏感，会撞上 [int]$Frames 参数
        $semanticFrames = if ($segment.name -eq 'B-async') { $AsyncFrames } else { $SyncFrames }
        $semantics[$segment.name] = Invoke-SegmentSemantics -Segment $segment.name -PluginsPath $segment.plugins -AsyncFlag $segment.flag -FrameList $semanticFrames
    }
    Clear-OurHost | Out-Null
}

# ---------------------------------------------------------------- 语义断言
$syncProbe = $semantics['A1-sync']
$asyncProbe = $semantics['B-async']
$sync2Probe = $semantics['A2-sync']

if (-not $SkipSemantics) {
    $anchorPrefixes = @{ 540 = '07757cb6'; 560 = '068d56c8'; 619 = 'c15545a9' }
    foreach ($frame in @(540, 560, 619)) {
        $sha = Get-MeshLocalSha $syncProbe $frame
        if (-not $sha) { Add-Check "C0_anchor_$frame" 'failed' 'sync 缺少该帧网格记录'; continue }
        $ok = $sha.StartsWith($anchorPrefixes[$frame])
        Add-Check "C0_anchor_$frame" ($(if ($ok) { 'passed' } else { 'failed' })) "sync 局部 sha=$($sha.Substring(0,16)) 期望前缀 $($anchorPrefixes[$frame])"
    }

    foreach ($frame in (($AsyncFrames -split ',') | ForEach-Object { [int]$_.Trim() } | Where-Object { $_ })) {
        $prev = $frame - 1
        $prev2 = $frame - 2
        $asyncRigid = Get-RecordField $asyncProbe $frame 'rigid_sha256'
        $syncPrevRigid = Get-RecordField $syncProbe $prev 'rigid_sha256'
        $syncRigid = Get-RecordField $syncProbe $frame 'rigid_sha256'
        $syncPrev2Rigid = Get-RecordField $syncProbe $prev2 'rigid_sha256'

        # C1：刚体晚一帧，逐字节
        Add-Check "C1_rigid_shift_$frame" ($(if ($asyncRigid -and $syncPrevRigid -and $asyncRigid -eq $syncPrevRigid) { 'passed' } else { 'failed' })) "async($frame)=$(if($asyncRigid){$asyncRigid.Substring(0,16)}) vs sync($prev)=$(if($syncPrevRigid){$syncPrevRigid.Substring(0,16)})"
        # C2：反证，必须与同帧 sync 不同（否则开关没生效）
        Add-Check "C2_rigid_not_sync_$frame" ($(if ($asyncRigid -and $syncRigid -and $asyncRigid -ne $syncRigid) { 'passed' } else { 'failed' })) "async($frame) 必须 != sync($frame)；相同说明 CMT_PHYSICS_ASYNC 未生效"
        # C5：不是晚两帧
        if ($syncPrev2Rigid) {
            Add-Check "C5_rigid_not_two_behind_$frame" ($(if ($asyncRigid -ne $syncPrev2Rigid) { 'passed' } else { 'failed' })) "async($frame) 必须 != sync($prev2)"
        }

        # C3：网格——只有动画静止窗口才要求逐字节
        $meshAsync = Get-MeshLocalSha $asyncProbe $frame
        $meshSyncPrev = Get-MeshLocalSha $syncProbe $prev
        $meshSync = Get-MeshLocalSha $syncProbe $frame
        if (-not ($meshAsync -and $meshSyncPrev -and $meshSync)) {
            Add-Check "C3_mesh_shift_$frame" 'failed' '缺少网格记录'
            continue
        }
        if ($meshSync -eq $meshSyncPrev) {
            Add-Check "C3_mesh_shift_$frame" ($(if ($meshAsync -eq $meshSyncPrev) { 'passed' } else { 'failed' })) "动画静止窗口：async($frame) 必须 == sync($prev)（逐字节）"
        } else {
            $relation = if ($meshAsync -eq $meshSyncPrev) { 'shift_exact' } elseif ($meshAsync -eq $meshSync) { 'no_shift_suspicious' } else { 'shift_plus_animation_delta' }
            $status = if ($relation -eq 'no_shift_suspicious') { 'failed' } else { 'passed' }
            Add-Check "C3_mesh_shift_$frame" $status "动画在动：async($frame) 与 sync($prev) 关系=$relation（此帧不要求逐字节，记录来源）"
        }
    }

    # C6：A1 与 A2 两段 sync 完全一致（关闭开关零差异、可复现）
    if ($sync2Probe) {
        $same = $true
        foreach ($frame in @(540, 560, 619)) {
            $a = Get-MeshLocalSha $syncProbe $frame
            $b = Get-MeshLocalSha $sync2Probe $frame
            if (-not ($a -and $b -and $a -eq $b)) { $same = $false }
            $ra = (Get-FrameRecord $syncProbe $frame).rigid_sha256
            $rb = (Get-FrameRecord $sync2Probe $frame).rigid_sha256
            if (-not ($ra -and $rb -and $ra -eq $rb)) { $same = $false }
        }
        Add-Check 'C6_sync_segments_identical' ($(if ($same) { 'passed' } else { 'failed' })) 'A1 与 A2 两段 sync 的网格+刚体 sha 必须完全相同'
    }

    # C7（P2-004）：刚体名册一一对应 —— 数量 / RIGID_INDEX / name / 关联骨骼
    $syncKeys = Get-RosterKey $syncProbe
    $asyncKeys = Get-RosterKey $asyncProbe
    if (-not ($syncKeys -and $asyncKeys)) {
        Add-Check 'C7_p2_004_roster' 'failed' 'probe 输出缺少 roster（probe-rigid.py 版本不对或宿主里读不到 RIGID_INDEX）'
    } else {
        $sameContent = (($syncKeys -join "`n") -eq ($asyncKeys -join "`n"))
        Add-Check 'C7_p2_004_roster' ($(if (($syncKeys.Count -eq $asyncKeys.Count) -and $sameContent) { 'passed' } else { 'failed' })) "sync=$($syncKeys.Count) async=$($asyncKeys.Count) 逐项一致=$sameContent（键=RIGID_INDEX|name_local|bone_index|bone_name）"

        $ids = @($syncProbe.roster | ForEach-Object { [int]$_.rigid_index } | Sort-Object)
        $contiguous = ($ids.Count -gt 0) -and ($ids[0] -eq 0) -and ($ids[$ids.Count - 1] -eq ($ids.Count - 1))
        Add-Check 'C7_roster_index_contiguous' ($(if ($contiguous) { 'passed' } else { 'failed' })) "RIGID_INDEX 范围 $($ids[0])..$($ids[$ids.Count - 1])，共 $($ids.Count) 个（必须 0..N-1 连续）"

        $shaSync = [string]$syncProbe.roster_sha256
        $shaAsync = [string]$asyncProbe.roster_sha256
        Add-Check 'C7_roster_sha256' ($(if ($shaSync -and $shaSync -eq $shaAsync) { 'passed' } else { 'failed' })) "sync=$($shaSync.Substring(0, [math]::Min(16, $shaSync.Length))) async=$($shaAsync.Substring(0, [math]::Min(16, $shaAsync.Length)))"

        $bonesSync = if ($syncProbe.PSObject.Properties['roster_bones_unresolved']) { [int]$syncProbe.roster_bones_unresolved } else { -1 }
        $bonesAsync = if ($asyncProbe.PSObject.Properties['roster_bones_unresolved']) { [int]$asyncProbe.roster_bones_unresolved } else { -1 }
        Add-Check 'C7_roster_bones_resolved' ($(if (($bonesSync -eq 0) -and ($bonesAsync -eq 0)) { 'passed' } else { 'failed' })) "未解析骨骼数 sync=$bonesSync async=$bonesAsync（>0 说明 RIGID_INDEX→骨骼映射断了）"

        if ($sync2Probe) {
            $sync2Keys = Get-RosterKey $sync2Probe
            $a2Same = if ($sync2Keys) { (($syncKeys -join "`n") -eq ($sync2Keys -join "`n")) } else { $false }
            Add-Check 'C7_roster_a2_identical' ($(if ($a2Same) { 'passed' } else { 'failed' })) 'A1 与 A2 的名册必须逐项相同（关掉开关时场景完全一致）'
        }
    }
}

# ---------------------------------------------------------------- 计时判定
$verdict = 'unknown'
$deltaOn = $null
$deltaOff = $null
if (-not $SkipTiming -and $timing['A1-sync'] -and $timing['B-async']) {
    $a1 = $timing['A1-sync']
    $b = $timing['B-async']
    $a2 = $timing['A2-sync']
    $syncOn = if ($a2) { ($a1.on_median + $a2.on_median) / 2 } else { $a1.on_median }
    $syncOff = if ($a2) { ($a1.off_median + $a2.off_median) / 2 } else { $a1.off_median }
    $deltaOn = [math]::Round($b.on_median - $syncOn, 3)
    $deltaOff = [math]::Round($b.off_median - $syncOff, 3)
    if ($a2) {
        $drift = if ($syncOn -gt 0) { [math]::Abs($a2.on_median - $a1.on_median) / $a1.on_median * 100 } else { 0 }
        Add-Check 'timing_sync_drift' ($(if ($drift -le 10) { 'passed' } else { 'failed' })) ("A1 vs A2 的 on median 漂移 {0:N2}%（>10% 说明本次不可用，需重跑）" -f $drift)
    }
    $verdict = if ($deltaOn -ge $PromoteThresholdMs) { 'promote_candidate' } elseif ($deltaOn -lt $InvisibleThresholdMs) { 'archive_invisible' } else { 'gray_keep_off' }
    Add-Check 'timing_main_thread_gain' 'passed' ("async 相对 sync：on {0:N3} ms / off {1:N3} ms → 判定 {2}" -f $deltaOn, $deltaOff, $verdict)
}

$summary = [pscustomobject]@{
    schema      = 'vmd-physics-async-summary/1'
    out_root    = $OutRoot
    started     = $true
    artifacts   = [pscustomobject]@{ sync = $plan.sync_artifact; async = $plan.async_artifact }
    timing      = [pscustomobject]@{ A1 = $timing['A1-sync']; B = $timing['B-async']; A2 = $timing['A2-sync']; sync_on_median = $(if ($deltaOn -ne $null) { ($timing['A1-sync'].on_median + $(if ($timing['A2-sync']) { $timing['A2-sync'].on_median } else { $timing['A1-sync'].on_median })) / 2 } else { $null }); delta_on_ms = $deltaOn; delta_off_ms = $deltaOff }
    checks      = $script:Checks
    failures    = $script:Failures
    verdict     = $verdict
    finished_at = (Get-Date).ToUniversalTime().ToString('o')
}

$summaryPath = Join-Path $OutRoot 'run-summary.json'
$summary | ConvertTo-Json -Depth 8 | Set-Content -LiteralPath $summaryPath -Encoding utf8

Write-Host ''
Write-Host "== summary: $summaryPath =="
Write-Host ("FAILURES: {0}" -f $(if ($script:Failures.Count -eq 0) { 'none' } else { $script:Failures -join ' | ' }))
Write-Host ('AB_ASYNC_RESULT:' + ($summary | ConvertTo-Json -Depth 8 -Compress))
if ($script:Failures.Count -gt 0) { exit 1 }
exit 0

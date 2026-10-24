<#
.SYNOPSIS
    基线逐帧计时一键跑：启动私有宿主 → 加载场景快照 → 物理开/关逐帧计时 →（可选）变形网格快照 → 干净收尾。

.DESCRIPTION
    固定流程（顺序不可打乱，任何一步失败即停并保留现场）：
      1. 校验参数与场景文件、记录插件目录与 mmdtool.xdl64 的 sha256；
      2. launch-host.ps1 -Execute 启动私有 profile 宿主（或接管已在运行的同一实例）；
      3. host-driver.py load 加载 .c4d 场景快照 → scene-report 采构成清单；
      4. 物理开：host-driver.py profile 逐帧计时（帧 0 求值 → 预热 → 计时区间）；
      5. 物理关：mmdtool_set_physics_enabled=false → 同样计时 → 恢复 true；
      6. 可选 -DumpMesh：导出检查点帧的变形网格（世界+局部坐标 CSV、float64 原始坐标、sha256）与末帧 PNG；
      7. stop-host.ps1 -Execute 关闭"本次启动的" pid，写 cleanup 与 run-summary.json。

    换插件目录即可跑另一版：-PluginsPath <另一个 plugins 目录>，其余参数不变。

.PARAMETER ScenePath
    场景快照 .c4d 路径（基线：S:\tmp\cmt_vmd_profile_20261019\scenes\perf-baseline.c4d）。

.PARAMETER OutDir
    本次运行输出目录；若其中已有 run-summary.json，整目录先归档为 <OutDir>-archive-<stamp> 再新建，绝不覆盖既有证据。

.PARAMETER PluginsPath
    承载 mmdtool.xdl64 的 plugins 目录。默认 sdk_2027_v143 Release。

.PARAMETER Warmup / Frames / StartFrame
    预热帧数（默认 40，从 540 开始）、计时帧数（默认 120）、计时起始帧（默认 560）。

.PARAMETER DumpMesh
    额外导出变形网格快照（默认开启；-DumpMesh 显式开启，-NoDumpMesh 关闭）。

.PARAMETER KeepRunning
    跑完不关闭宿主（调试用；默认必须关，避免残留）。

.EXAMPLE
    pwsh -NoProfile -File docs\validation\vmd-host-restore-20261024\baseline-run.ps1 `
        -ScenePath S:\tmp\cmt_vmd_profile_20261019\scenes\perf-baseline.c4d `
        -OutDir S:\tmp\cmt_vmd_profile_20261019\baseline-rerun

.EXAMPLE
    # A/B 对照：换插件目录跑 candidate 版
    pwsh -NoProfile -File docs\validation\vmd-host-restore-20261024\baseline-run.ps1 `
        -ScenePath S:\tmp\cmt_vmd_profile_20261019\scenes\perf-baseline.c4d `
        -OutDir S:\tmp\cmt_vmd_profile_20261019\baseline-candidate `
        -PluginsPath C:\code\C4D_MMD_Tool\_build_msvc\sdk_2027_v143\bin\Candidate\plugins
#>
[CmdletBinding()]
param(
    [Parameter(Mandatory = $true)][string]$ScenePath,
    [Parameter(Mandatory = $true)][string]$OutDir,
    [string]$PluginsPath = 'C:\code\C4D_MMD_Tool\_build_msvc\sdk_2027_v143\bin\Release\plugins',
    [string]$PmxPath = 'C:\pmx\白银之城—阿芙2.0\阿芙2.0.pmx',
    [string]$VmdPath = 'C:\vmd\Stay Tonight Heaven Lee Ver. 动作.vmd',
    [int]$Warmup = 40,
    [int]$Frames = 120,
    [int]$StartFrame = 560,
    [int[]]$DumpFrames = @(540, 560, 619),
    [int]$RenderFrame = 619,
    [switch]$DumpMesh,      # 显式开启（默认即开启；写明意图时用，与 -NoDumpMesh 冲突时本开关优先）
    [switch]$NoDumpMesh,
    [switch]$KeepRunning
)

Set-StrictMode -Version Latest
$ErrorActionPreference = 'Stop'
$env:PYTHONIOENCODING = 'utf-8'   # 与 host-driver.py 的 stdout 重配置互补，避免骨名/物件名编码崩
$root = $PSScriptRoot
$dumpMeshEnabled = ($DumpMesh.IsPresent -or (-not $NoDumpMesh.IsPresent))
$driver = Join-Path $root 'host-driver.py'
$launch = Join-Path $root 'launch-host.ps1'
$stop = Join-Path $root 'stop-host.ps1'
$steps = [System.Collections.Generic.List[object]]::new()
$failures = [System.Collections.Generic.List[string]]::new()

function Add-Step([string]$name, [string]$status, [string]$detail = '') {
    # warn = 已记录但不阻断（例如已知限制触发的回退路径），failed 才计入失败。
    $steps.Add([ordered]@{ name = $name; status = $status; detail = $detail })
    if ($status -eq 'failed') { $failures.Add($name) }
    Write-Host ('[{0}] {1} {2}' -f $status.ToUpperInvariant(), $name, $detail)
}

function Invoke-Driver {
    param([string[]]$Arguments, [string]$Name, [int]$TimeoutSeconds = 0)
    $output = & python $driver @Arguments 2>&1
    $code = $LASTEXITCODE
    $text = ($output | Out-String)
    $line = ($output | Where-Object { "$_" -like 'DRIVER_RESULT:*' } | Select-Object -Last 1)
    $payload = $null
    if ($line) {
        try { $payload = ("$line").Substring('DRIVER_RESULT:'.Length) | ConvertFrom-Json } catch { $payload = $null }
    }
    if ($code -ne 0 -or -not $payload) {
        Add-Step $Name 'failed' ("exit=$code " + $text.Trim().Substring(0, [Math]::Min(600, $text.Trim().Length)))
        return $null
    }
    Add-Step $Name 'passed'
    return $payload
}

function Get-TypeCount($counts, [string]$name) {
    # ConvertFrom-Json 出来的中文属性名在 StrictMode 下不能直接 .名称 取，必须走 PSObject.Properties。
    $property = $counts.PSObject.Properties[$name]
    if ($null -eq $property) { return 0 }
    return [int]$property.Value
}
function Get-CsvStats([string]$path) {
    if (-not (Test-Path -LiteralPath $path)) { return $null }
    $values = @(Get-Content -LiteralPath $path | Select-Object -Skip 1 | ForEach-Object {
            [double]($_ -split ',')[1]
        } | Sort-Object)
    if ($values.Count -eq 0) { return $null }
    $index = [int][Math]::Round(($values.Count - 1) * 0.95)
    [ordered]@{
        n = $values.Count
        mean_ms = [Math]::Round(($values | Measure-Object -Average).Average, 3)
        median_ms = [Math]::Round($values[[int][Math]::Floor(($values.Count - 1) / 2)], 3)
        p95_ms = [Math]::Round($values[$index], 3)
        min_ms = [Math]::Round($values[0], 3)
        max_ms = [Math]::Round($values[-1], 3)
    }
}

# --- 0. 预检 ---------------------------------------------------------------
if (-not (Test-Path -LiteralPath $ScenePath)) { throw "scene_not_found: $ScenePath" }
$ScenePath = (Resolve-Path -LiteralPath $ScenePath).Path
$moduleDll = Join-Path $PluginsPath 'mmdtool\mmdtool.xdl64'
if (-not (Test-Path -LiteralPath $moduleDll)) { throw "plugin_dll_not_found: $moduleDll" }
if (-not (Test-Path -LiteralPath $driver)) { throw "driver_not_found: $driver" }
New-Item -ItemType Directory -Force -Path $OutDir | Out-Null
$OutDir = (Resolve-Path -LiteralPath $OutDir).Path
$summaryPath = Join-Path $OutDir 'run-summary.json'
if (Test-Path -LiteralPath $summaryPath) {
    # 同一 OutDir 再次运行（例如复跑契约 Verify）：整目录归档，绝不覆盖既有证据
    $stamp = (Get-Date).ToString('yyyyMMddTHHmmss')
    $archive = "$OutDir-archive-$stamp"
    Move-Item -LiteralPath $OutDir -Destination $archive
    New-Item -ItemType Directory -Force -Path $OutDir | Out-Null
    $OutDir = (Resolve-Path -LiteralPath $OutDir).Path
    $summaryPath = Join-Path $OutDir 'run-summary.json'
    Write-Host ("archive : {0}" -f $archive)
}

$moduleInfo = Get-Item -LiteralPath $moduleDll
$moduleSha = (Get-FileHash -LiteralPath $moduleDll -Algorithm SHA256).Hash.ToLowerInvariant()
$sceneInfo = Get-Item -LiteralPath $ScenePath
$run = [ordered]@{
    schema = 'vmd-baseline-run/1'
    started_at = (Get-Date).ToString('o')
    scene = [ordered]@{ path = $ScenePath; size = $sceneInfo.Length
        sha256 = (Get-FileHash -LiteralPath $ScenePath -Algorithm SHA256).Hash.ToLowerInvariant() }
    plugins = [ordered]@{ path = $PluginsPath; module = $moduleInfo.FullName; module_size = $moduleInfo.Length
        module_sha256 = $moduleSha; module_version = $moduleInfo.LastWriteTime.ToString('o') }
    parameters = [ordered]@{ warmup = $Warmup; frames = $Frames; start_frame = $StartFrame; dump_mesh = $dumpMeshEnabled }
    host = $null
    timing = [ordered]@{}
    dumps = [ordered]@{}
    steps = $steps
    failures = $failures
    exit_code = 0
}
Write-Host "== baseline-run =="
Write-Host ("scene   : {0} ({1} B, sha {2})" -f $run.scene.path, $run.scene.size, $run.scene.sha256.Substring(0, 16))
Write-Host ("plugins : {0}" -f $moduleInfo.FullName)
Write-Host ("module  : {0} B sha {1}" -f $run.plugins.module_size, $run.plugins.module_sha256.Substring(0, 16))
Write-Host ("out     : {0}" -f $OutDir)

# --- 1. 启动宿主 -----------------------------------------------------------
$hostStarted = $false
try {
    $launchOut = & pwsh -NoProfile -File $launch -Execute -ModulePath $PluginsPath -OutRoot $OutDir 2>&1
    $launchCode = $LASTEXITCODE
    $launchText = ($launchOut | Out-String).Trim()
    if ($launchCode -ne 0) {
        Add-Step 'host_launch' 'failed' ("exit=$launchCode " + $launchText.Substring(0, [Math]::Min(800, $launchText.Length)))
        throw "host_launch_failed"
    }
    $hostStarted = $true
    $identityPath = Join-Path $OutDir 'host-identity.json'
    $identity = Get-Content -LiteralPath $identityPath -Raw | ConvertFrom-Json
    $run.host = [ordered]@{ pid = $identity.host.pid; start_ticks_utc = $identity.host.start_ticks_utc
        prefs_path = $identity.host.prefs_path; endpoint = $identity.mcp.endpoint
        loaded_module_sha256 = $identity.modules.mmdtool_loaded.sha256
        loaded_module_path = $identity.modules.mmdtool_loaded.path
        startup_seconds = $identity.startup_seconds }
    Add-Step 'host_launch' 'passed' ("pid={0} ticks={1} {2}s" -f $identity.host.pid, $identity.host.start_ticks_utc, $identity.startup_seconds)
    if ($identity.modules.mmdtool_loaded.sha256 -ne $moduleSha) {
        Add-Step 'module_identity' 'failed' ("期望 {0} 实际 {1}" -f $moduleSha.Substring(0, 16), $identity.modules.mmdtool_loaded.sha256)
        throw "module_sha_mismatch"
    }
    Add-Step 'module_identity' 'passed' ("加载模块 sha 与 -PluginsPath 一致")

    # --- 2. 加载场景 + 构成清单 -------------------------------------------
    $loadResult = Invoke-Driver -Name 'scene_load' -Arguments @('load', '--path', $ScenePath)
    if (-not $loadResult) { throw "scene_load_failed" }

    $reportPath = Join-Path $OutDir 'scene-report.json'
    $report = Invoke-Driver -Name 'scene_report' -Arguments @('scene-report', '--out', $reportPath)
    if (-not $report) { throw "scene_report_failed" }

    # --- 2b. 回退：.c4d 未能还原对象树时按固定配方重建 ---------------------
    # 实测（docs/validation/vmd-host-restore-20261024/README.md 已知限制）：C4D 2027 里
    # c4d.documents.LoadDocument(path, c4d.SCENEFILTER_0, None) 返回的文档对象数为 0，
    # 连只含一个立方体的 150 KB 探针场景也一样；所以快照 .c4d 只作留档，计时用同配方重建的场景。
    $rebuildUsed = $false
    if ([int]$report.total_objects -eq 0) {
        Add-Step 'scene_load_empty' 'warn' '加载 .c4d 后对象数为 0 → 回退为按资产重建（见 README 已知限制）'
        if (-not (Invoke-Driver -Name 'scene_rebuild_new' -Arguments @('new-scene'))) { throw 'scene_rebuild_failed' }
        if (-not (Invoke-Driver -Name 'scene_rebuild_pmx' -Arguments @('import', '--pmx', $PmxPath, '--vmd', $VmdPath))) { throw 'scene_rebuild_pmx_failed' }
        if (-not (Invoke-Driver -Name 'scene_rebuild_motion' -Arguments @('import-motion', '--vmd', $VmdPath))) { throw 'scene_rebuild_motion_failed' }
        $report = Invoke-Driver -Name 'scene_report' -Arguments @('scene-report', '--out', $reportPath)
        if (-not $report) { throw 'scene_report_after_rebuild_failed' }
        $rebuildUsed = $true
    }
    $run['scene_source'] = if ($rebuildUsed) { 'rebuild_from_assets' } else { 'loaded_from_snapshot' }

    $run['scene_composition'] = [ordered]@{ total_objects = $report.total_objects
        type_counts = $report.type_counts; meshes = $report.meshes
        fps = $report.fps; min_frame = $report.min_frame; max_frame = $report.max_frame }
    $boneCount = Get-TypeCount $report.type_counts '关节'
    $rigidCount = Get-TypeCount $report.type_counts 'MMD刚体'
    $jointCount = Get-TypeCount $report.type_counts 'MMDJoint'
    $pointCount = ($report.meshes | ForEach-Object { $_.points } | Measure-Object -Sum).Sum
    $run['scene_counts'] = [ordered]@{ bones = $boneCount; rigid_bodies = $rigidCount
        constraints = $jointCount; vertices = $pointCount; meshes = @($report.meshes).Count
        total_objects = $report.total_objects; fps = $report.fps
        min_frame = $report.min_frame; max_frame = $report.max_frame }
    Add-Step 'scene_composition' 'passed' ("objects={0} bones={1} rigid={2} joints={3} points={4}" -f `
            $report.total_objects, $boneCount, $rigidCount, $jointCount, $pointCount)
    if ([int]$report.total_objects -eq 0) { throw 'scene_empty_after_rebuild' }

    # 场景权威定义（资产 + 导入配方），A/B 对照时两版必须逐字相同
    $scopeManifest = [ordered]@{
        schema = 'vmd-scene-snapshot/1'
        created_at = (Get-Date).ToString('o')
        source = $run['scene_source']
        assets = @(
            [ordered]@{ role = 'pmx'; path = $PmxPath; size = (Get-Item -LiteralPath $PmxPath).Length
                sha256 = (Get-FileHash -LiteralPath $PmxPath -Algorithm SHA256).Hash.ToLowerInvariant() },
            [ordered]@{ role = 'vmd'; path = $VmdPath; size = (Get-Item -LiteralPath $VmdPath).Length
                sha256 = (Get-FileHash -LiteralPath $VmdPath -Algorithm SHA256).Hash.ToLowerInvariant() }
        )
        recipe = [ordered]@{ new_scene_fps = 30; pmx_import = 'mmdtool_import_pmx (默认网格合并)'
            motion = 'mmdtool_import_motion strategy=replace'; mode = 'anim' }
        c4d_version = '2027.0.0'
        module = [ordered]@{ path = $run.plugins.module; sha256 = $run.plugins.module_sha256; size = $run.plugins.module_size }
        snapshot_c4d = [ordered]@{ path = $ScenePath; size = $run.scene.size; sha256 = $run.scene.sha256
            reloadable = (-not $rebuildUsed) }
        composition = $run['scene_counts']
    }
    $scopeManifest | ConvertTo-Json -Depth 8 | Set-Content -LiteralPath (Join-Path $OutDir 'scene-manifest.json') -Encoding utf8
    $run['scene_manifest'] = Join-Path $OutDir 'scene-manifest.json'

    # --- 3. 物理开计时 -----------------------------------------------------
    $onCsv = Join-Path $OutDir 'timing-physics-on.csv'
    $on = Invoke-Driver -Name 'timing_physics_on' -Arguments @('profile', '--label', 'physics-on',
        '--warmup', "$Warmup", '--frames', "$Frames", '--start', "$StartFrame", '--csv', $onCsv)
    if (-not $on) { throw "timing_physics_on_failed" }
    $run.timing['physics_on'] = [ordered]@{ csv = $onCsv; stats = (Get-CsvStats $onCsv)
        cold_eval_ms = $on.cold_eval_ms; warmup_frames = $Warmup; measure_start = $StartFrame
        measure_count = $Frames; driver_stats = $on.stats }

    # --- 4. 物理关计时 -----------------------------------------------------
    if (-not (Invoke-Driver -Name 'physics_off' -Arguments @('physics', '--enabled', 'off'))) { throw "physics_toggle_failed" }
    $offCsv = Join-Path $OutDir 'timing-physics-off.csv'
    $off = Invoke-Driver -Name 'timing_physics_off' -Arguments @('profile', '--label', 'physics-off',
        '--warmup', "$Warmup", '--frames', "$Frames", '--start', "$StartFrame", '--csv', $offCsv)
    if (-not $off) { throw "timing_physics_off_failed" }
    $run.timing['physics_off'] = [ordered]@{ csv = $offCsv; stats = (Get-CsvStats $offCsv)
        cold_eval_ms = $off.cold_eval_ms; warmup_frames = $Warmup; measure_start = $StartFrame
        measure_count = $Frames; driver_stats = $off.stats }
    if (-not (Invoke-Driver -Name 'physics_restore' -Arguments @('physics', '--enabled', 'on'))) { throw "physics_restore_failed" }

    # --- 5. 变形网格快照（可选）-------------------------------------------
    if ($dumpMeshEnabled) {
        $meshDir = Join-Path $OutDir 'mesh'
        $dumpJson = Join-Path $OutDir 'mesh-dump.json'
        $dump = Invoke-Driver -Name 'mesh_dump' -Arguments @('dump', '--outdir', $meshDir,
            '--frames', ($DumpFrames -join ','), '--out', $dumpJson)
        if (-not $dump) { throw "mesh_dump_failed" }
        $run.dumps['mesh'] = [ordered]@{ dir = $meshDir; manifest = $dumpJson
            frames = $dump.frames
            records = @($dump.records | ForEach-Object { [ordered]@{
                        frame = $_.frame; object = $_.object; point_count = $_.point_count
                        local_sha256 = $_.local_sha256; world_sha256 = $_.world_sha256
                        csv = $_.csv; bin = $_.bin } }) }

        $png = Join-Path $OutDir ("frame-{0}.png" -f $RenderFrame)
        $render = Invoke-Driver -Name 'frame_render' -Arguments @('render', '--out', $png, '--frame', "$RenderFrame")
        if ($render) {
            $skip = if ($render.PSObject.Properties['skip_reason']) { $render.skip_reason } else { $null }
            $run.dumps['render'] = [ordered]@{ frame = $RenderFrame; path = $png
                saved = $render.saved; size = $render.size; skip_reason = $skip }
        } else {
            $run.dumps['render'] = [ordered]@{ frame = $RenderFrame; skipped = $true
                skip_reason = 'render step failed; 见 steps 里的 frame_render' }
        }
    }
}
catch {
    Add-Step 'aborted' 'failed' $_.Exception.Message
}
finally {
    # --- 6. 关闭宿主（只关本次启动的 pid）--------------------------------
    if ($hostStarted -and -not $KeepRunning) {
        $identityPath = Join-Path $OutDir 'host-identity.json'
        $stopOut = & pwsh -NoProfile -File $stop -Execute -IdentityPath $identityPath -OutRoot $OutDir 2>&1
        $stopCode = $LASTEXITCODE
        $stopText = ($stopOut | Out-String).Trim()
        if ($stopCode -ne 0) {
            Add-Step 'host_stop' 'failed' ("exit=$stopCode " + $stopText.Substring(0, [Math]::Min(600, $stopText.Length)))
        } else {
            $cleanupPath = Join-Path $OutDir 'cleanup.json'
            if (Test-Path -LiteralPath $cleanupPath) {
                $cleanup = Get-Content -LiteralPath $cleanupPath -Raw | ConvertFrom-Json
                $run['cleanup'] = [ordered]@{ stop_method = $cleanup.stop_method; stop_forced = $cleanup.stop_forced
                    stop_seconds = $cleanup.stop_seconds; port_released = $cleanup.port_released
                    remaining = @($cleanup.remaining_cinema_processes) }
                Add-Step 'host_stop' 'passed' ("{0} {1}s remaining={2}" -f $cleanup.stop_method, $cleanup.stop_seconds,
                    @($cleanup.remaining_cinema_processes).Count)
            } else {
                Add-Step 'host_stop' 'passed' 'exit=0'
            }
        }
    } elseif ($KeepRunning) {
        Add-Step 'host_stop' 'passed' 'skipped: -KeepRunning（宿主保留，需手工 stop-host.ps1）'
    }

    $run['finished_at'] = (Get-Date).ToString('o')
    $run['failure_count'] = $failures.Count
    $run['exit_code'] = if ($failures.Count -eq 0) { 0 } else { 1 }
    $run['steps'] = @($steps)
    $run['failures'] = @($failures)
    $run | ConvertTo-Json -Depth 12 | Set-Content -LiteralPath $summaryPath -Encoding utf8
    Write-Host "== summary: $summaryPath =="
    if ($run.timing.Contains('physics_on')) { Write-Host ("physics_on  mean={0} median={1} p95={2} n={3}" -f $run.timing['physics_on'].stats.mean_ms, $run.timing['physics_on'].stats.median_ms, $run.timing['physics_on'].stats.p95_ms, $run.timing['physics_on'].stats.n) }
    if ($run.timing.Contains('physics_off')) { Write-Host ("physics_off mean={0} median={1} p95={2} n={3}" -f $run.timing['physics_off'].stats.mean_ms, $run.timing['physics_off'].stats.median_ms, $run.timing['physics_off'].stats.p95_ms, $run.timing['physics_off'].stats.n) }
    Write-Host ("FAILURES: {0}" -f ($(if ($failures.Count) { $failures -join '; ' } else { 'none' })))
}

exit $run['exit_code']

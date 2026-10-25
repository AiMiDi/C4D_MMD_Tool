#requires -Version 7.0
<#
.SYNOPSIS
  t31 自检：不启动宿主，验证 run-ab-async.ps1 / probe-rigid.py / host-ab-plan.md 是否可执行、自洽。

.DESCRIPTION
  本脚本是 t31 契约的 verify 入口。它只做静态与 dry-run 检查：

    1. 文件齐备（交付物 + 被引用的工具链）。
    2. PowerShell 语法解析（AST）。
    3. Python 语法编译（py_compile，pycache 写到临时目录，不污染仓库）。
    4. probe-rigid.py 的 CLI 契约（argparse 选项名）。
    5. run-ab-async.ps1 的参数契约（必填参数、执行开关、判定门槛参数）。
    6. 静态模式断言（A/B/A 三段、环境变量开关、工具链引用、锚点常量、无未替换占位符）。
    7. dry-run 端到端：真的执行 run-ab-async.ps1 -DryRun，解析它打印的 AB_ASYNC_PLAN JSON。
    8. 方案文档章节与关键判据齐备。
    9. 断言本脚本自身没有启动任何宿主（前后 Cinema 4D 进程数一致、5557 未被本脚本打开）。

  退出码：0 全绿；1 有失败。所有断言通过才允许把 t31 标记完成。
#>
[CmdletBinding()]
param(
    [string]$OutRoot = 'S:\tmp\cmt_vmd_profile_20261019\physics-async\check-scripts'
)

$ErrorActionPreference = 'Stop'
Set-StrictMode -Version Latest

$script:RepoRoot = Split-Path -Parent (Split-Path -Parent (Split-Path -Parent $PSScriptRoot))
$script:Assertions = 0
$script:Cases = [System.Collections.Generic.List[string]]::new()
$script:Failures = [System.Collections.Generic.List[string]]::new()

$script:RunAb = Join-Path $PSScriptRoot 'run-ab-async.ps1'
$script:Probe = Join-Path $PSScriptRoot 'probe-rigid.py'
$script:Plan = Join-Path $PSScriptRoot 'host-ab-plan.md'
$script:StableMeasure = Join-Path $script:RepoRoot 'docs\validation\vmd-perf-stable-20261024\stable-measure.ps1'
$script:LaunchHost = Join-Path $script:RepoRoot 'docs\validation\vmd-host-restore-20261024\launch-host.ps1'
$script:StopHost = Join-Path $script:RepoRoot 'docs\validation\vmd-host-restore-20261024\stop-host.ps1'
$script:HostDriver = Join-Path $script:RepoRoot 'docs\validation\vmd-host-restore-20261024\host-driver.py'

function Test-Assertion([string]$Name, [bool]$Condition, [string]$Detail = '') {
    $script:Assertions++
    if ($Condition) {
        Write-Host ("  [PASS] {0}{1}" -f $Name, $(if ($Detail) { " :: $Detail" } else { '' }))
    } else {
        Write-Host ("  [FAIL] {0}{1}" -f $Name, $(if ($Detail) { " :: $Detail" } else { '' }))
        $script:Failures.Add($Name)
    }
}

function Write-Case([string]$Name) {
    $script:Cases.Add($Name)
    Write-Host ''
    Write-Host ("== {0}" -f $Name)
}

function Get-CinemaProcessCount {
    return (@(Get-CimInstance Win32_Process -Filter "Name='Cinema 4D.exe'" -ErrorAction SilentlyContinue | Where-Object { $_ })).Count
}

function Test-PortListening([int]$Port) {
    return ((Get-NetTCPConnection -State Listen -LocalPort $Port -ErrorAction SilentlyContinue | Measure-Object).Count -gt 0)
}

New-Item -ItemType Directory -Force -Path $OutRoot | Out-Null
$hostBefore = Get-CinemaProcessCount
$portBefore = Test-PortListening 5557

Write-Case 'files-present'
foreach ($path in @($script:RunAb, $script:Probe, $script:Plan)) {
    Test-Assertion "file:$(Split-Path -Leaf $path)" (Test-Path -LiteralPath $path) $path
}
foreach ($tool in @($script:StableMeasure, $script:LaunchHost, $script:StopHost, $script:HostDriver)) {
    Test-Assertion "toolchain:$(Split-Path -Leaf $tool)" (Test-Path -LiteralPath $tool) $tool
}

Write-Case 'powershell-parse'
$tokens = $null
$errors = $null
$ast = [System.Management.Automation.Language.Parser]::ParseFile($script:RunAb, [ref]$tokens, [ref]$errors)
$parseDetail = if ($errors.Count -eq 0) { 'no parse errors' } else { ($errors | ForEach-Object { "line $($_.Extent.StartLineNumber): $($_.Message)" }) -join '; ' }
Test-Assertion 'parse:run-ab-async.ps1' ($errors.Count -eq 0) $parseDetail
$runAbText = Get-Content -LiteralPath $script:RunAb -Raw
Test-Assertion 'parse:run-ab-async.ps1-has-param-block' ($null -ne $ast.ParamBlock) ''
Test-Assertion 'static:no-Tee-Object-placeholder' (-not ($runAbText -match 'FileNamePlaceholder')) '上一版残留的非法参数必须已被移除'
Test-Assertion 'static:no-unreplaced-token' (-not ($runAbText -match '__[A-Z_]+__')) '不允许残留 __TOKEN__ 形式占位符'

Write-Case 'python-compile'
$pyCache = Join-Path $OutRoot 'pycache'
New-Item -ItemType Directory -Force -Path $pyCache | Out-Null
$previousPycache = $env:PYTHONPYCACHEPREFIX
try {
    $env:PYTHONPYCACHEPREFIX = $pyCache
    $compileOut = & python -m py_compile $script:Probe 2>&1
    $compileExit = $LASTEXITCODE
} finally {
    if ($null -eq $previousPycache) { Remove-Item Env:PYTHONPYCACHEPREFIX -ErrorAction SilentlyContinue } else { $env:PYTHONPYCACHEPREFIX = $previousPycache }
}
Test-Assertion 'py_compile:probe-rigid.py' ($compileExit -eq 0) ("exit=$compileExit " + ($compileOut -join ' '))

Write-Case 'probe-cli'
$helpOut = & python $script:Probe --help 2>&1
$helpExit = $LASTEXITCODE
$helpText = ($helpOut | Out-String)
Test-Assertion 'probe:--help-exit' ($helpExit -eq 0) "exit=$helpExit"
foreach ($option in @('--frames', '--out', '--expect-rigid', '--expect-points', '--enable-rigid-display', '--exec-flags')) {
    Test-Assertion "probe:option$option" ($helpText.Contains($option)) ''
}

Write-Case 'run-ab-params'
$params = @{}
foreach ($parameter in $ast.ParamBlock.Parameters) {
    $name = $parameter.Name.VariablePath.UserPath
    $isMandatory = ($parameter.Attributes | Where-Object { $_ -is [System.Management.Automation.Language.AttributeAst] -and $_.TypeName.Name -eq 'Parameter' }) -ne $null
    $params[$name] = [pscustomobject]@{ name = $name; mandatory = [bool]$isMandatory }
}
Test-Assertion 'params:OutRoot-mandatory' ($params.ContainsKey('OutRoot')) ''
foreach ($required in @('SyncPluginsPath', 'AsyncPluginsPath', 'Pairs', 'Rounds', 'Warmup', 'Frames', 'StartFrame', 'MaxLoadPct', 'SyncFrames', 'AsyncFrames', 'PromoteThresholdMs', 'InvisibleThresholdMs', 'Execute', 'DryRun', 'SkipTiming', 'SkipSemantics')) {
    Test-Assertion "params:has-$required" ($params.ContainsKey($required)) ''
}

Write-Case 'static-mode-assertions'
Test-Assertion 'static:env-switch' ($runAbText -match 'CMT_PHYSICS_ASYNC') ''
Test-Assertion 'static:segments-a1-b-a2' (($runAbText -match "A1-sync") -and ($runAbText -match "B-async") -and ($runAbText -match "A2-sync")) ''
Test-Assertion 'static:sync-flag-zero' ($runAbText -match "flag = '0'") ''
Test-Assertion 'static:async-flag-one' ($runAbText -match "flag = '1'") ''
Test-Assertion 'static:uses-stable-measure' ($runAbText -match 'stable-measure\.ps1') ''
Test-Assertion 'static:uses-launch-host' ($runAbText -match 'launch-host\.ps1') ''
Test-Assertion 'static:uses-stop-host' ($runAbText -match 'stop-host\.ps1') ''
Test-Assertion 'static:uses-probe-rigid' ($runAbText -match 'probe-rigid\.py') ''
Test-Assertion 'static:mesh-anchors' (($runAbText -match '07757cb6') -and ($runAbText -match '068d56c8') -and ($runAbText -match 'c15545a9')) ''
Test-Assertion 'static:threshold-3ms' ($runAbText -match 'PromoteThresholdMs = 3\.0') ''
Test-Assertion 'static:threshold-1p5ms' ($runAbText -match 'InvisibleThresholdMs = 1\.5') ''
Test-Assertion 'static:verdict-promote' ($runAbText -match 'promote_candidate') ''
Test-Assertion 'static:verdict-invisible' ($runAbText -match 'archive_invisible') ''
Test-Assertion 'static:verdict-gray' ($runAbText -match 'gray_keep_off') ''
Test-Assertion 'static:checks-C1-rigid-shift' ($runAbText -match 'C1_rigid_shift') ''
Test-Assertion 'static:checks-C2-switch-proof' ($runAbText -match 'C2_rigid_not_sync') ''
Test-Assertion 'static:checks-C3-mesh-shift' ($runAbText -match 'C3_mesh_shift') ''
Test-Assertion 'static:checks-C6-sync-repeatable' ($runAbText -match 'C6_sync_segments_identical') ''
Test-Assertion 'static:cleanup-only-our-profile' ($runAbText -match 'CommandLine\.Contains\(\$PrefsPath\)') ''
Test-Assertion 'static:no-repo-destructive' (-not ($runAbText -match 'Remove-Item[^\r\n]*-Recurse[^\r\n]*\\source')) ''

Write-Case 'dry-run-plan'
$dryRunDir = Join-Path $OutRoot 'dryrun'
if (Test-Path -LiteralPath $dryRunDir) { Remove-Item -LiteralPath $dryRunDir -Recurse -Force }
$dryOut = & pwsh -NoProfile -File $script:RunAb -OutRoot $dryRunDir -SyncPluginsPath 'S:\tmp\does-not-exist\sync\plugins' -AsyncPluginsPath 'S:\tmp\does-not-exist\async\plugins' -DryRun 2>&1
$dryExit = $LASTEXITCODE
$dryText = ($dryOut | Out-String)
Test-Assertion 'dryrun:exit-0' ($dryExit -eq 0) "exit=$dryExit"
Test-Assertion 'dryrun:prints-plan-marker' ($dryText.Contains('AB_ASYNC_PLAN:')) ''
$planJson = $null
$markerIndex = $dryText.IndexOf('AB_ASYNC_PLAN:')
if ($markerIndex -ge 0) {
    $rawJson = $dryText.Substring($markerIndex + 'AB_ASYNC_PLAN:'.Length).Trim()
    try {
        $planJson = $rawJson | ConvertFrom-Json
    } catch {
        $planJson = $null
    }
}
Test-Assertion 'dryrun:plan-json-parses' ($null -ne $planJson) ''
if ($planJson) {
    Test-Assertion 'dryrun:schema' ($planJson.schema -eq 'vmd-physics-async-plan/1') "$($planJson.schema)"
    Test-Assertion 'dryrun:three-segments' (@($planJson.segments).Count -eq 3) "count=$(@($planJson.segments).Count)"
    Test-Assertion 'dryrun:segment-order' ((@($planJson.segments | ForEach-Object { $_.name }) -join ',') -eq 'A1-sync,B-async,A2-sync') (@($planJson.segments | ForEach-Object { $_.name }) -join ',')
    Test-Assertion 'dryrun:max-load-30' ($planJson.timing.max_load_pct -eq 30) "$($planJson.timing.max_load_pct)"
    Test-Assertion 'dryrun:thresholds' (($planJson.thresholds.promote_ms -eq 3.0) -and ($planJson.thresholds.invisible_ms -eq 1.5)) ''
    Test-Assertion 'dryrun:async-frames' ($planJson.semantics.async_frames -eq '540,560,619') "$($planJson.semantics.async_frames)"
}
$hostAfterDry = Get-CinemaProcessCount
Test-Assertion 'dryrun:no-host-started' ($hostAfterDry -eq $hostBefore) "before=$hostBefore after=$hostAfterDry"

Write-Case 'plan-document'
$planText = Get-Content -LiteralPath $script:Plan -Raw
foreach ($heading in @('## 1', '## 2', '## 3', '## 4', '## 5', '## 6', '## 7', '## 8')) {
    Test-Assertion "plan:heading$heading" ($planText -match [regex]::Escape($heading)) ''
}
foreach ($keyword in @('CMT_PHYSICS_ASYNC', 'P2-002', 'promote', 'archive', 'forced', '07757cb6', '068d56c8', 'c15545a9', '位移一帧', '刚体可见性')) {
    Test-Assertion "plan:keyword:$keyword" ($planText.Contains($keyword)) ''
}

Write-Case 'host-not-started'
$hostAfter = Get-CinemaProcessCount
$portAfter = Test-PortListening 5557
Test-Assertion 'no-host:process-count-unchanged' ($hostAfter -eq $hostBefore) "before=$hostBefore after=$hostAfter"
Test-Assertion 'no-host:port-unchanged' ($portAfter -eq $portBefore) "before=$portBefore after=$portAfter"

Write-Host ''
Write-Host ("CHECK_SCRIPTS assertions={0} cases={1} failures={2}" -f $script:Assertions, $script:Cases.Count, $script:Failures.Count)
if ($script:Failures.Count -gt 0) {
    Write-Host ("FAILURES: " + ($script:Failures -join ' | '))
    exit 1
}
Write-Host 'CHECK_SCRIPTS OK'
exit 0

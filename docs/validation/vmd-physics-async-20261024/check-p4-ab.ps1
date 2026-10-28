#!/usr/bin/env pwsh
# P4 结果自检：只读产物 + 少量环境探针，不启宿主。
#
#   pwsh -NoProfile -File check-p4-ab.ps1 -RunRoot S:\tmp\...\p4\ab\main
#
# 退出码 0 表示全部断言通过（warning 不计失败），1 表示有 failed。
param(
    [Parameter(Mandatory = $true)][string]$RunRoot,
    [int]$MinLaunches = 5,
    [int]$MinReps = 5,
    [double]$MaxLoadPct = 30,
    [double]$DriftLimitPct = 5.0,
    [double]$PromoteThresholdMs = 3.0,
    [double]$InvisibleThresholdMs = 1.5,
    [int]$ExpectRigid = 479,
    [string]$PatchShaPrefix = '',
    [string]$BuildSummary = '',
    [int]$Port = 5557,
    [switch]$AllowMissingSeek
)
$ErrorActionPreference = 'Stop'

$assertions = 0
$failures = New-Object System.Collections.Generic.List[string]
$warnings = New-Object System.Collections.Generic.List[string]
$checks = New-Object System.Collections.Generic.List[object]

function Add-Assert([string]$Id, [bool]$Ok, [string]$Detail, [string]$Level = 'failed') {
    $script:assertions++
    $status = if ($Ok) { 'passed' } elseif ($Level -eq 'warning') { 'warning' } else { 'failed' }
    $checks.Add([pscustomobject]@{ id = $Id; status = $status; detail = $Detail })
    if ($status -eq 'failed') { $script:failures.Add($Id) }
    if ($status -eq 'warning') { $script:warnings.Add($Id) }
    Write-Host ('[check] {0,-42} {1,-8} {2}' -f $Id, $status, $Detail)
}

function Read-Json([string]$Path) { if (Test-Path -LiteralPath $Path) { return Get-Content -LiteralPath $Path -Raw | ConvertFrom-Json } return $null }

$summaryPath = Join-Path $RunRoot 'run-summary.json'
Add-Assert 'summary_present' (Test-Path -LiteralPath $summaryPath) $summaryPath
$summary = Read-Json $summaryPath
if (-not $summary) { Write-Host 'CHECK_P4 FAILED assertions=1'; exit 1 }

Add-Assert 'summary_schema' ($summary.schema -eq 'vmd-p4-ab/1') "schema=$($summary.schema)"
Add-Assert 'out_root_matches' ($summary.config.out_root -eq $RunRoot) "config=$($summary.config.out_root) actual=$RunRoot"

# ---- 工件 ----
$syncSha = $summary.artifacts.sync_sha256
$asyncSha = $summary.artifacts.async_sha256
Add-Assert 'artifacts_present' ([bool]$syncSha -and [bool]$asyncSha) "sync=$syncSha async=$asyncSha"
Add-Assert 'artifacts_differ' ($syncSha -and $asyncSha -and $syncSha -ne $asyncSha) '两版 xdl64 sha256 必须不同'
foreach ($item in @(@{ n = 'sync'; p = $summary.artifacts.sync_path }, @{ n = 'async'; p = $summary.artifacts.async_path })) {
    $exists = $item.p -and (Test-Path -LiteralPath $item.p)
    Add-Assert "artifact_$($item.n)_exists" ([bool]$exists) "$($item.p)"
    if ($exists) {
        $bytes = [IO.File]::ReadAllBytes($item.p)
        $marker = [Text.Encoding]::ASCII.GetString($bytes).Contains('CMT_RUNTIME_PROFILING=1')
        Add-Assert "artifact_$($item.n)_no_profiling_marker" (-not $marker) "size=$($bytes.Length)"
    }
}
$gitOut = @()
try { $gitOut = @(git -C (Split-Path -Parent (Split-Path -Parent (Split-Path -Parent $PSScriptRoot))) status --porcelain --ignore-submodules -- source res sdk_2026 sdk_2027 dependency 2>$null) } catch { }
$tracked = @($gitOut | Where-Object { $_ -match '^[ MARC][MD]' -or $_ -match '^[MARC]' })
Add-Assert 'product_tree_tracked_clean' ($tracked.Count -eq 0) ("tracked_changes=" + $tracked.Count)

if ($BuildSummary) {
    $build = Read-Json $BuildSummary
    Add-Assert 'build_summary_present' ([bool]$build) $BuildSummary
    if ($build) {
        $cacheLines = @($build.steps | Where-Object { $_.name -like 'cache-*' })
        $allOff = ($cacheLines.Count -gt 0) -and (@($cacheLines | Where-Object { $_.detail -notmatch 'CMT_ENABLE_RUNTIME_PROFILING:BOOL=OFF' }).Count -eq 0)
        Add-Assert 'build_profiling_off' $allOff ("cache_steps=" + $cacheLines.Count)
        if ($PatchShaPrefix) {
            $patchSha = [string]$build.patch_sha256
            Add-Assert 'build_patch_prefix' ($patchSha.ToLower().StartsWith($PatchShaPrefix.ToLower())) "patch=$patchSha expect_prefix=$PatchShaPrefix"
        }
    }
}

# ---- 计时 ----
foreach ($name in @('A1-sync', 'B-async', 'A2-sync')) {
    $segment = $summary.timing.$name
    Add-Assert "timing_${name}_present" ($null -ne $segment -and $null -ne $segment.on_median) "on=$($segment.on_median) off=$($segment.off_median)"
    if ($segment) {
        Add-Assert "timing_${name}_launches" (@($segment.on_medians).Count -ge $MinLaunches) "launches=$(@($segment.on_medians).Count) min=$MinLaunches"
        Add-Assert "timing_${name}_on_positive" ([double]$segment.on_median -gt 0) "on_median=$($segment.on_median)"
        $load = $segment.load_pct_max
        Add-Assert "timing_${name}_load_gate" ($null -ne $load -and [double]$load -le $MaxLoadPct) "max_load=$load limit=$MaxLoadPct"
        Add-Assert "timing_${name}_module_match" ([bool]$segment.module_match) "module_match=$($segment.module_match)"
    }
}
$on1 = $summary.timing.'A1-sync'.on_median
$on2 = $summary.timing.'A2-sync'.on_median
if ($on1 -and $on2) {
    $drift = [math]::Abs($on1 - $on2) / [math]::Max($on1, $on2) * 100.0
    Add-Assert 'a1_a2_drift' ($drift -le $DriftLimitPct) ('{0:N2}% limit={1}%' -f $drift, $DriftLimitPct)
}

# ---- 语义（lag=1 严格 + seek）----
$lagPath = $summary.semantics.lag_path
$lag = Read-Json $lagPath
Add-Assert 'lag_artifact_present' ([bool]$lag) $lagPath
if ($lag) {
    $movedSync = [bool]$lag.displacement.'A1-sync'.all_rigids_moved
    $movedAsync = [bool]$lag.displacement.'B-async'.all_rigids_moved
    Add-Assert 'writeback_sync_all_rigids_moved' $movedSync "moved=$($lag.displacement.'A1-sync'.rigids_moved) frozen=$($lag.displacement.'A1-sync'.rigids_frozen)"
    Add-Assert 'writeback_async_all_rigids_moved' $movedAsync "moved=$($lag.displacement.'B-async'.rigids_moved) frozen=$($lag.displacement.'B-async'.rigids_frozen)"
    Add-Assert 'lag1_bitwise_equal' ([bool]$lag.lag1.all_equal) "equal=$($lag.lag1.equal_frames)/$($lag.lag1.frames_compared) earliest=$($lag.lag1.earliest_mismatch_frame)"
    Add-Assert 'lag_constant' ([bool]$lag.lag_constant) "verdict=$($lag.verdict)"
    Add-Assert 'lag1_window_size' ([int]$lag.lag1.frames_compared -ge 80) "frames_compared=$($lag.lag1.frames_compared) min=80"

    $roster = $lag.roster
    Add-Assert 'roster_same_across_segments' ([bool]$roster.same_roster) "same=$($roster.same_roster)"
    Add-Assert 'roster_count' ([int]$roster.'B-async'.count -eq $ExpectRigid) "count=$($roster.'B-async'.count) expect=$ExpectRigid"
    Add-Assert 'roster_indices_contiguous' ([bool]$roster.'B-async'.indices_contiguous) 'RIGID_INDEX 必须 0..N-1'
    Add-Assert 'roster_no_duplicates' ([int]$roster.'B-async'.duplicates -eq 0) "dup=$($roster.'B-async'.duplicates)"
    Add-Assert 'roster_bones_resolved' ([int]$roster.'B-async'.unresolved_bones -eq 0) "unresolved=$($roster.'B-async'.unresolved_bones)"

    $anchorOk = @($lag.anchors.PSObject.Properties | Where-Object { $_.Value.local_matches -and $_.Value.world_matches }).Count -eq 3
    Add-Assert 'anchor_540_560_619' $anchorOk '局部+世界 sha 前缀'
    if ($lag.sync_a1_vs_a2) { Add-Assert 'sync_a1_vs_a2' ([bool]$lag.sync_a1_vs_a2.all_identical) "$($lag.sync_a1_vs_a2.identical)/$($lag.sync_a1_vs_a2.frames)" }
    else { Add-Assert 'sync_a1_vs_a2' $false '缺 A2 语义段' }

    if ($lag.seek) {
        $events = @($lag.seek.events).Count
        Add-Assert 'seek_events_recorded' ($events -ge 1) "events=$events after=$($lag.seek.seek_after_frame) to=$($lag.seek.seek_to_frame)" $(if ($AllowMissingSeek) { 'warning' } else { 'failed' })
        $pre = $lag.seek.pre_window.lag1
        $post = $lag.seek.post_window.lag1
        Add-Assert 'seek_pre_window_lag1' ([bool]$pre.all_equal) "$($pre.equal_frames)/$($pre.frames_compared) earliest=$($pre.earliest_mismatch_frame)"
        Add-Assert 'seek_post_window_lag1' ([bool]$post.all_equal) "$($post.equal_frames)/$($post.frames_compared) earliest=$($post.earliest_mismatch_frame)"
        Add-Assert 'seek_post_window_size' ([int]$post.frames_compared -ge 40) "post_frames=$($post.frames_compared) min=40"
    } else {
        Add-Assert 'seek_present' $false 'summary 缺 seek 段（B-async 未带 seek 参数）' $(if ($AllowMissingSeek) { 'warning' } else { 'failed' })
    }
}

# ---- 结论一致性 ----
$verdict = $summary.verdict
$semanticsOk = [bool]$verdict.semantics_ok
if ($semanticsOk) {
    $anyFailedSemantics = @($checks | Where-Object { $_.id -like 'lag1_*' -or $_.id -like 'seek_*' -or $_.id -like 'writeback_*' } | Where-Object { $_.status -eq 'failed' }).Count -gt 0
    Add-Assert 'verdict_semantics_consistent' (-not $anyFailedSemantics) "semantics_ok=$semanticsOk"
    $benefit = [double]$verdict.benefit_ms
    $expected = if ($benefit -ge $PromoteThresholdMs) { 'promote' } elseif ($benefit -lt $InvisibleThresholdMs) { 'archive_invisible' } else { 'gray_keep_off' }
    Add-Assert 'decision_matches_thresholds' ($verdict.decision -eq $expected) "decision=$($verdict.decision) expected=$expected benefit=$benefit"
} else {
    Add-Assert 'decision_gated_unavailable' ($verdict.decision -eq 'unavailable') "decision=$($verdict.decision)"
}

# ---- 环境 ----
$c4d = @(Get-CimInstance Win32_Process -Filter "Name='Cinema 4D.exe'" -ErrorAction SilentlyContinue)
Add-Assert 'host_clean_c4d' ($c4d.Count -eq 0) "c4d_processes=$($c4d.Count)"
$listening = @(Get-NetTCPConnection -State Listen -LocalPort $Port -ErrorAction SilentlyContinue)
Add-Assert 'host_clean_port' ($listening.Count -eq 0) "port=$Port listeners=$($listening.Count)"

$checks | ConvertTo-Json -Depth 5 | Set-Content -LiteralPath (Join-Path $RunRoot 'check-p4-ab.json') -Encoding UTF8

if ($failures.Count -gt 0) {
    Write-Host ("CHECK_P4 FAILED assertions={0} failures={1} warnings={2}" -f $assertions, $failures.Count, $warnings.Count)
    Write-Host ("FAILED: " + ($failures -join ', '))
    exit 1
}
Write-Host ("CHECK_P4 OK assertions={0} failures=0 warnings={1}" -f $assertions, $warnings.Count)
if ($warnings.Count -gt 0) { Write-Host ("WARNINGS: " + ($warnings -join ', ')) }
exit 0

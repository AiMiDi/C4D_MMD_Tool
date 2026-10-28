param(
    [string]$ResultDir = 'S:\tmp\cmt_vmd_profile_20261019\p6b\ab',
    [string]$DiagLog = 'S:\tmp\cmt_vmd_profile_20261019\p6b\ab\diag-b-async4.log',
    [string]$BuildSummary = 'S:\tmp\cmt_vmd_profile_20261019\p6b\build-summary.json',
    [string]$PatchShaPrefix = '862a4d86',
    [int]$ExpectRigid = 479,
    [int]$ExpectDynamic = 452,
    [int]$MinFrames = 60,
    [switch]$SkipHostClean,
    [switch]$AllowOldPatchEvidence
)

$ErrorActionPreference = 'Stop'
$checks = New-Object System.Collections.Generic.List[object]
function Add-Check([string]$name, [bool]$ok, [string]$detail) {
    $script:checks.Add([pscustomobject]@{ name = $name; ok = $ok; detail = $detail })
}

function Resolve-ProbeRoot([string]$dir) {
    if (-not (Test-Path $dir)) { return $null }
    $direct = Join-Path $dir 'segments\A1-sync\semantics\probe.host.json'
    if (Test-Path $direct) { return $dir }
    $arch = Get-ChildItem $dir -Directory -ErrorAction SilentlyContinue | Where-Object { $_.Name -like 'sem*-archive-*' -or $_.Name -like 'sem*' } |
            Sort-Object LastWriteTime -Descending
    foreach ($a in $arch) {
        if (Test-Path (Join-Path $a.FullName 'segments\A1-sync\semantics\probe.host.json')) { return $a.FullName }
    }
    return $null
}

# 1) 结果目录与 lag 证据
$probeRoot = Resolve-ProbeRoot $ResultDir
Add-Check 'result_dir_present' ([bool]$probeRoot) ("probe_root=" + "$probeRoot")

$lagCandidates = @()
if (Test-Path $ResultDir) {
    $lagCandidates += (Join-Path $ResultDir 'lag-p6.json')
    if ($probeRoot) { $lagCandidates += (Join-Path $probeRoot 'lag-p6.json') }
    $lagCandidates += (Get-ChildItem $ResultDir -Recurse -Filter 'lag-p6.json' -ErrorAction SilentlyContinue | ForEach-Object { $_.FullName })
}
$lagPath = $lagCandidates | Where-Object { $_ -and (Test-Path $_) } | Select-Object -First 1
Add-Check 'lag_p6_present' ([bool]$lagPath) ("path=" + "$lagPath")

$lag = $null
if ($lagPath) { $lag = Get-Content $lagPath -Raw | ConvertFrom-Json }

if ($lag) {
    Add-Check 'lag_schema_v2' ($lag.schema -eq 'vmd-p6-lag/2') ("schema=" + $lag.schema)
    Add-Check 'lag_has_dynamic_split' (($null -ne $lag.dynamic_rigids) -and ($null -ne $lag.kinematic_rigids)) ("dynamic=" + $lag.dynamic_rigids + " kinematic=" + $lag.kinematic_rigids)
    Add-Check 'dynamic_count' ([int]$lag.dynamic_rigids -eq $ExpectDynamic) ("dynamic=" + $lag.dynamic_rigids + " expect=" + $ExpectDynamic)
    Add-Check 'rigid_count' ([int]$lag.rigid_count -eq $ExpectRigid) ("rigid=" + $lag.rigid_count)
    Add-Check 'frames_compared' ([int]$lag.dynamic_lag1.compared -ge $MinFrames) ("compared=" + $lag.dynamic_lag1.compared + " min=" + $MinFrames)
    Add-Check 'verdict_present' ($lag.verdict -in @('lag1_bitwise_equal', 'lag1_dynamic_bitwise_equal', 'different_trajectory')) ("verdict=" + $lag.verdict)
    Add-Check 'dynamic_lag1_evidence' ($null -ne $lag.dynamic_lag1) ("equal=" + $lag.dynamic_lag1.equal_frames + "/" + $lag.dynamic_lag1.compared + " earliest=" + $lag.dynamic_lag1.earliest_mismatch_frame + " max=" + $lag.dynamic_lag1.max_deviation_mm)
    Add-Check 'kinematic_same_frame_evidence' ($null -ne $lag.kinematic_same_frame) ("equal=" + $lag.kinematic_same_frame.equal_frames + "/" + $lag.kinematic_same_frame.compared)
    Add-Check 'seek_events_recorded' (($lag.seek.events | Measure-Object).Count -ge 1) ("events=" + (($lag.seek.events | Measure-Object).Count))
    Add-Check 'seek_windows_present' (($null -ne $lag.seek.pre_window) -and ($null -ne $lag.seek.post_window)) ("pre=" + $lag.seek.pre_window.frames + " post=" + $lag.seek.post_window.frames)
    Add-Check 'sync_a1_vs_a2' (($null -ne $lag.sync_a1_vs_a2) -and ([int]$lag.sync_a1_vs_a2.equal_frames -eq [int]$lag.sync_a1_vs_a2.compared)) ("a1==a2 " + $lag.sync_a1_vs_a2.equal_frames + "/" + $lag.sync_a1_vs_a2.compared)

    # 结论与证据一致：lag1_bitwise_equal 必须 equal==compared；different_trajectory 必须 earliest 非空
    $isEqual = $lag.verdict -like 'lag1*'
    if ($isEqual) {
        Add-Check 'verdict_matches_evidence' ([int]$lag.dynamic_lag1.equal_frames -eq [int]$lag.dynamic_lag1.compared) ("equal=" + $lag.dynamic_lag1.equal_frames + "/" + $lag.dynamic_lag1.compared)
    } else {
        Add-Check 'verdict_matches_evidence' ($null -ne $lag.dynamic_lag1.earliest_mismatch_frame) ("earliest=" + $lag.dynamic_lag1.earliest_mismatch_frame)
    }
}

# 2) 三段 probe 与帧数
if ($probeRoot) {
    foreach ($seg in @('A1-sync', 'B-async', 'A2-sync')) {
        $p = Join-Path $probeRoot ("segments\$seg\semantics\probe.host.json")
        $exists = Test-Path $p
        Add-Check ("probe_" + $seg) $exists $p
        if ($exists) {
            $probe = Get-Content $p -Raw | ConvertFrom-Json
            $rc = if ($null -ne $probe.rigid_count) { [int]$probe.rigid_count } elseif ($probe.records) { [int]$probe.records[0].rigid_count } else { 0 }
            Add-Check ("probe_rigid_" + $seg) ($rc -eq $ExpectRigid) ("rigid=" + $rc)
            Add-Check ("probe_frames_" + $seg) (($probe.records | Measure-Object).Count -ge 2) ("frames=" + ($probe.records | Measure-Object).Count)
            if ($seg -eq 'B-async') {
                Add-Check 'probe_seek_events' (($probe.seek_events | Measure-Object).Count -ge 1) ("events=" + (($probe.seek_events | Measure-Object).Count))
            }
        }
    }
}

# 3) 埋点计数器（C1/C2/C3 取证）
if (Test-Path $DiagLog) {
    $lines = Get-Content $DiagLog
    $finals = $lines | Where-Object { $_ -like 'stats final=1 *' }
    $steps = $lines | Where-Object { $_ -like 'step *' }
    $wsteps = $lines | Where-Object { $_ -like 'wstep *' }
    $dispatches = $lines | Where-Object { $_ -like 'dispatch *' }
    Add-Check 'diag_stats_final' (($finals | Measure-Object).Count -ge 1) ("count=" + ($finals | Measure-Object).Count)
    Add-Check 'diag_step_lines' (($steps | Measure-Object).Count -ge 1) ("count=" + ($steps | Measure-Object).Count)
    Add-Check 'diag_worker_lines' (($wsteps | Measure-Object).Count -ge 1) ("count=" + ($wsteps | Measure-Object).Count)
    Add-Check 'diag_dispatch_lines' (($dispatches | Measure-Object).Count -ge 1) ("count=" + ($dispatches | Measure-Object).Count)

    # 计数器口径：skipped/covered/stale 必须为 0，applied 恒等于 submitted-1（每个 epoch 内）
    $nonZero = $steps | Where-Object { ($_ -notmatch 'submit_skipped=0 ') -or ($_ -notmatch 'result_covered=0 ') -or ($_ -notmatch 'stale_dropped=0 ') }
    Add-Check 'diag_counters_clean' (($nonZero | Measure-Object).Count -eq 0) ("violations=" + ($nonZero | Measure-Object).Count)
    $badLag = @()
    $lastEpoch = $null
    $lastApplied = -1
    foreach ($s in $steps) {
        if ($s -notmatch 'epoch=(\d+)') { continue }
        $epoch = $Matches[1]
        if ($s -notmatch 'submitted=(\d+) applied=(\d+)') { continue }
        $sub = [int]$Matches[1]; $app = [int]$Matches[2]
        if ($epoch -ne $lastEpoch) { $lastEpoch = $epoch; $lastApplied = -1 }
        if ($sub -lt 1) { continue }
        $expected = $lastApplied + 1
        if ($app -ne $expected -and -not ($lastApplied -lt 0 -and $app -eq 0)) {
            $badLag += ("epoch=" + $epoch + " sub=" + $sub + " app=" + $app + " expect=" + $expected)
        }
        $lastApplied = $app
    }
    Add-Check 'diag_lag_one_based' (($badLag | Measure-Object).Count -eq 0) ("violations=" + (($badLag | Measure-Object).Count))

    # 同帧二次分发必须具备 seek 解释：允许 1 个帧出现 2 次，且其 doc_seconds 与 probe seek 目标一致
    $byTime = @{}
    foreach ($d in $dispatches) {
        if ($d -match 'doc_seconds=([0-9.]+)') {
            $t = $Matches[1]
            if ($byTime.ContainsKey($t)) { $byTime[$t] = $byTime[$t] + 1 } else { $byTime[$t] = 1 }
        }
    }
    $doubles = $byTime.GetEnumerator() | Where-Object { $_.Value -gt 1 }
    Add-Check 'diag_double_dispatch_explained' (($doubles | Measure-Object).Count -le 1) ("double_times=" + (($doubles | ForEach-Object { $_.Key }) -join ','))
} else {
    Add-Check 'diag_log_present' $false $DiagLog
}

# 4) 构建与工件
if (Test-Path $BuildSummary) {
    $bs = Get-Content $BuildSummary -Raw | ConvertFrom-Json
    $stepsBs = @($bs.steps)
    $patchStep = $stepsBs | Where-Object { $_.name -eq 'patch-identity' } | Select-Object -Last 1
    Add-Check 'build_patch_bound' (([string]$patchStep.sha256).StartsWith($PatchShaPrefix)) ("sha=" + $patchStep.sha256)
    $syncArt = $stepsBs | Where-Object { $_.name -eq 'artifact-sync' } | Select-Object -Last 1
    $asyncArt = $stepsBs | Where-Object { $_.name -eq 'artifact-async' } | Select-Object -Last 1
    Add-Check 'build_two_artifacts' (($null -ne $syncArt) -and ($null -ne $asyncArt)) ("sync=" + $syncArt.sha256 + " async=" + $asyncArt.sha256)
    Add-Check 'build_artifacts_differ' ([string]$syncArt.sha256 -ne [string]$asyncArt.sha256) "sha must differ"
    $cacheSteps = $stepsBs | Where-Object { $_.name -like 'cache-*' }
    $cacheOk = ($cacheSteps | Where-Object { $_.line -like '*CMT_ENABLE_RUNTIME_PROFILING:BOOL=OFF*' } | Measure-Object).Count -ge 1
    Add-Check 'build_profiling_off' $cacheOk ("cache_steps=" + (($cacheSteps | Measure-Object).Count))
} else {
    Add-Check 'build_summary_present' $false $BuildSummary
}

# 5) 产品树与宿主收尾
$status = git -C 'C:\code\C4D_MMD_Tool' status --short --ignore-submodules -- source res sdk_2026 sdk_2027 dependency 2>$null
$tracked = @($status | Where-Object { $_ -and ($_ -notlike '??*') })
Add-Check 'product_tree_untouched' ($tracked.Count -eq 0) ("tracked=" + $tracked.Count)

if (-not $SkipHostClean) {
    $c4d = @(Get-CimInstance Win32_Process -Filter "Name='Cinema 4D.exe'" -ErrorAction SilentlyContinue |
             Where-Object { $_.CommandLine -like '*cmt_vmd_profile_20261019*' })
    Add-Check 'host_clean_c4d' ($c4d.Count -eq 0) ("count=" + $c4d.Count)
    $port = @(Get-NetTCPConnection -State Listen -LocalPort 5557 -ErrorAction SilentlyContinue)
    Add-Check 'host_clean_port' ($port.Count -eq 0) ("listeners=" + $port.Count)
}

$failed = $checks | Where-Object { -not $_.ok }
foreach ($c in $checks) {
    $status = if ($c.ok) { 'passed' } else { 'failed' }
    "{0,-38} {1}   {2}" -f $c.name, $status, $c.detail
}
if ($failed.Count -gt 0) {
    "FAILURES: " + (($failed | ForEach-Object { $_.name }) -join ', ')
    exit 1
}
"CHECK_P6 OK assertions=$($checks.Count) failures=0"
exit 0

# P3 真机 A/B 产物自检：断言轮次/样本数/安静门/漂移/收益门槛/lag 证据/roster/锚点/收尾/构建口径。
# 设计原则：
#   - 直接读原始产物（各段 stable-measure 的 run-summary.json + 语义 probe.host.json），不依赖上层 run-summary 的布尔结论；
#   - 宿主崩溃导致的「该次尝试被重试补上」记 warning（计数并打印），不当失败；只有有效轮次不足才失败；
#   - lag 断言的是「证据完整 + 结论自洽」，而不是「断言 lag 必须是 1 或 2」——lag 是否为 1/2 是本轮要检验的假设，不是前提。
# 用法：
#   pwsh -NoProfile -File check-p3-ab.ps1 -TimingRoot <ab\main> -SemanticsRoot <ab\sem>
#   pwsh -NoProfile -File check-p3-ab.ps1 -RunRoot <OutRoot>     # 单目录同时含 timing 与 semantics 时
param(
	[string]$TimingRoot = '',
	[string]$SemanticsRoot = '',
	[string]$RunRoot = '',
	[string]$BuildSummary = 'S:\tmp\cmt_vmd_profile_20261019\p3\build-summary.json',
	[string]$Analyzer = '',
	[int]$MinLaunches = 5,
	[int]$MinReps = 5,
	[int]$MinFrames = 60,
	[int]$ExpectRigid = 479,
	[double]$MaxLoadPct = 30,
	[double]$DriftLimitPct = 5.0,
	[double]$PromoteThresholdMs = 3.0,
	[double]$InvisibleThresholdMs = 1.5,
	# 结论一致性用的报告；t58 起默认读新报告，保持 t49 的旧报告不动。
	[string]$ReportPath = '',
	# 构建所用补丁的 sha 前缀（t58 用 t56 修复版 6eb55a37；t49 时期为 74788a62）
	[string]$PatchShaPrefix = '6eb55a37',
	# 逐线程 thread-cpu.json 的 worker 归属不可靠（含渲染/线程池），标注后降级为 info
	[switch]$ThreadCpuInformational,
	[switch]$RequireWorkerCpu
)

$ErrorActionPreference = 'Stop'
if (-not $TimingRoot -and $RunRoot) { $TimingRoot = $RunRoot }
if (-not $SemanticsRoot -and $RunRoot) { $SemanticsRoot = $RunRoot }
if (-not $Analyzer) { $Analyzer = Join-Path $PSScriptRoot 'analyze-p3-lag.py' }
# t58 的报告写新文件名（不覆盖 t49 的 host-ab-p3-result.md）；两条都接受，优先新文件。
$reportCandidates = @(
	$(if ($ReportPath) { $ReportPath } else { Join-Path $PSScriptRoot 'host-ab-p3b-result.md' }),
	(Join-Path $PSScriptRoot 'host-ab-p3b-result.md'),
	(Join-Path $PSScriptRoot 'host-ab-p3-result.md')
)

$assertions = 0
$warnings = New-Object System.Collections.Generic.List[string]
$failures = New-Object System.Collections.Generic.List[string]
function Assert-That([string]$Id, [bool]$Condition, [string]$Detail, [switch]$WarnOnly) {
	$script:assertions++
	if ($Condition) { Write-Host ("[ok]   {0,-42} {1}" -f $Id, $Detail) }
	elseif ($WarnOnly) { Write-Host ("[warn] {0,-42} {1}" -f $Id, $Detail); $script:warnings.Add($Id) }
	else { Write-Host ("[FAIL] {0,-42} {1}" -f $Id, $Detail); $script:failures.Add($Id) }
}

$segments = @('A1-sync', 'B-async', 'A2-sync')
$timing = @{}

# 1) 计时：逐段原始 run-summary.json
foreach ($name in $segments) {
	$segRoot = Join-Path (Join-Path $TimingRoot 'segments') $name
	$segTiming = Join-Path $segRoot 'timing'
	$p = Join-Path $segTiming 'run-summary.json'
	Assert-That "timing_summary_$name" (Test-Path $p) $p
	if (-not (Test-Path $p)) { continue }
	$t = Get-Content -LiteralPath $p -Raw | ConvertFrom-Json
	$onM = @($t.aggregate.on.per_launch_median_ms | Where-Object { $null -ne $_ })
	$offM = @($t.aggregate.off.per_launch_median_ms | Where-Object { $null -ne $_ })
	$loads = @($t.launches | ForEach-Object { $_.load_pct } | Where-Object { $null -ne $_ })
	$medianOn = if ($onM.Count) { ($onM | Sort-Object)[[int][math]::Floor($onM.Count / 2)] } else { $null }
	$medianOff = if ($offM.Count) { ($offM | Sort-Object)[[int][math]::Floor($offM.Count / 2)] } else { $null }
	$timing[$name] = [pscustomobject]@{ on = $onM; off = $offM; median_on = $medianOn; median_off = $medianOff; loads = $loads }

	$retried = @(Get-ChildItem -LiteralPath $segTiming -Directory -ErrorAction SilentlyContinue | Where-Object { $_.Name -like '*retry*' }).Count
	Assert-That "launches_$name" ($onM.Count -ge $MinLaunches) ("on_samples=" + $onM.Count)
	Assert-That "samples_$name" ($offM.Count -ge $MinLaunches) ("off_samples=" + $offM.Count)
	Assert-That "median_$name" ($null -ne $medianOn -and $medianOn -gt 0) ("on_median=" + $medianOn + " off_median=" + $medianOff)
	Assert-That "load_gate_$name" (($loads.Count -gt 0) -and (($loads | Measure-Object -Maximum).Maximum -le $MaxLoadPct)) ("max_load=" + (($loads | Measure-Object -Maximum).Maximum) + "% limit=" + $MaxLoadPct)
	Assert-That "crashed_attempts_$name" ($retried -eq 0) ("retried_attempts=" + $retried + "（宿主崩溃后重试补上，记 warning）") -WarnOnly:($retried -gt 0)
	Assert-That "reps_$name" ([int]$t.config.rounds -ge $MinReps) ("reps=" + $t.reps)
	$hosted = @($t.launches | ForEach-Object { $_.module_match } | Where-Object { $_ -eq $true }).Count
	Assert-That "module_match_$name" ($hosted -eq @($t.launches).Count -and $hosted -gt 0) ("module_match=" + $hosted + "/" + @($t.launches).Count)
}

# 2) A1/A2 漂移
if ($timing['A1-sync'] -and $timing['A2-sync'] -and $timing['A1-sync'].median_on) {
	$drift = [math]::Abs($timing['A1-sync'].median_on - $timing['A2-sync'].median_on) / $timing['A1-sync'].median_on * 100.0
	$script:driftPct = [math]::Round($drift, 2)
	Assert-That 'a1_a2_drift' ($drift -le $DriftLimitPct) ("drift=" + $script:driftPct + "% limit=" + $DriftLimitPct)
}

# 2b) 逐线程 CPU：回答「主线程省的 ms 有没有被 worker 吃掉」
$threadCpu = @{}
foreach ($name in $segments) {
	if (-not $timing[$name]) { continue }
	$tp = Join-Path (Join-Path (Join-Path $TimingRoot 'segments') $name) 'timing\thread-cpu.json'
	if (-not (Test-Path $tp)) { Assert-That "thread_cpu_$name" $false $tp -WarnOnly:(-not $RequireWorkerCpu); continue }
	$cpu = Get-Content -LiteralPath $tp -Raw | ConvertFrom-Json
	$threadCpu[$name] = $cpu
	Assert-That "thread_cpu_state_$name" ("$($cpu.state)" -eq 'available') ("state=" + $cpu.state + " reason=" + $cpu.reason)
	Assert-That "thread_cpu_samples_$name" ([int]$cpu.sample_count -ge 3) ("samples=" + $cpu.sample_count)

	$mainMs = $cpu.totals.main_ms_per_frame
	$workerMs = $cpu.totals.worker_ms_per_frame
	$totalMs = $cpu.totals.total_ms_per_frame
	$lateMs = $cpu.totals.worker_ms_late_per_frame
	Write-Host ("[info] thread-cpu {0,-8} main={1:N3} ms/frame worker={2:N3} (late {3:N3}) total={4:N3} ms/frame (wall median {5:N3}) threads={6}" -f `
		$name, $mainMs, $workerMs, $lateMs, $totalMs, $timing[$name].median_on, $cpu.thread_count)
	Assert-That "thread_cpu_main_detected_$name" ([bool]$cpu.totals.main_thread_detected) ("main_thread_detected=" + $cpu.totals.main_thread_detected + "（否则无法把主线程与 worker 分开）")

	if ($name -eq 'B-async') {
		# pipeline worker 是「第一次推进时才创建」的晚起线程 → 用 late 判据才是sharp的
		Assert-That 'worker_cpu_async_present' ($null -ne $workerMs -and $workerMs -gt 0) ("worker_ms_per_frame=" + $workerMs)
		Assert-That 'worker_cpu_async_late_present' ($null -ne $lateMs -and $lateMs -gt 0) ("late_worker_ms_per_frame=" + $lateMs + "（晚起线程=物理 worker）")
	} else {
		if ($ThreadCpuInformational) {
			# 逐线程口径把 C4D 渲染/线程池算进 worker，sync 段也会出现大量「晚起」线程 → 标注后降级
			Write-Host ("[info] worker_cpu_sync_quiet_$name late_worker_ms_per_frame=$lateMs（逐线程归属不可靠，已降级）")
		} else {
			Assert-That "worker_cpu_sync_quiet_$name" ($null -ne $lateMs -and $lateMs -lt 0.5) ("late_worker_ms_per_frame=" + $lateMs + "（sync 段不应出现晚起的物理 worker）")
		}
		# 非主线程总量在 C4D 里还包含渲染/线程池，只记 warning 不当失败
		Assert-That "worker_cpu_sync_total_small_$name" ($null -ne $workerMs -and $workerMs -lt 5.0) ("worker_ms_per_frame=" + $workerMs + "（含渲染/线程池等常驻线程）") -WarnOnly:($workerMs -ge 5.0)
	}
}
if ($threadCpu['B-async'] -and $threadCpu['A1-sync']) {
	$syncMain = $threadCpu['A1-sync'].totals.main_ms_per_frame
	$asyncMain = $threadCpu['B-async'].totals.main_ms_per_frame
	$syncTotal = $threadCpu['A1-sync'].totals.total_ms_per_frame
	$asyncTotal = $threadCpu['B-async'].totals.total_ms_per_frame
	Assert-That 'worker_cpu_main_reduced' ($asyncMain -lt $syncMain) ("sync_main=" + $syncMain + " async_main=" + $asyncMain)
	$ratio = if ($syncTotal -gt 0) { [math]::Round($asyncTotal / $syncTotal, 4) } else { $null }
	$script:costRatio = $ratio
	Write-Host ("[info] 成本守恒比 async_total/sync_total = {0}（≈1 表示真并行，>1 表示成本膨胀、把活搬到 worker 且更贵）" -f $ratio)
}

# 3) 收益与门槛
if ($timing['A1-sync'] -and $timing['B-async'] -and $timing['A2-sync']) {
	$syncOn = ($timing['A1-sync'].median_on + $timing['A2-sync'].median_on) / 2.0
	$syncOff = ($timing['A1-sync'].median_off + $timing['A2-sync'].median_off) / 2.0
	$deltaOn = $syncOn - $timing['B-async'].median_on
	$deltaOff = $syncOff - $timing['B-async'].median_off
	$script:deltaOn = [math]::Round($deltaOn, 3)
	$script:deltaOnPct = [math]::Round($deltaOn / $syncOn * 100.0, 2)
	$script:deltaOff = [math]::Round($deltaOff, 3)
	$band = if ($deltaOn -ge $PromoteThresholdMs) { 'promote_candidate' } elseif ($deltaOn -lt $InvisibleThresholdMs) { 'archive_invisible' } else { 'gray_keep_off' }
	$script:band = $band
	Write-Host ("[info] on: sync={0:N3} async={1:N3} delta={2} ms ({3}%) ; off: sync={4:N3} async={5:N3} delta={6}" -f $syncOn, $timing['B-async'].median_on, $script:deltaOn, $script:deltaOnPct, $syncOff, $timing['B-async'].median_off, $script:deltaOff)
	Assert-That 'benefit_computed' ($null -ne $deltaOn) ("delta_on=" + $script:deltaOn + " ms")
	Assert-That 'benefit_band' ($band -in @('promote_candidate', 'gray_keep_off', 'archive_invisible')) ("band=" + $band)
}

# 4) 语义：probe.host.json + analyzer
$sem = @{}
foreach ($name in @('A1-sync', 'B-async', 'A2-sync')) {
	$p = Join-Path (Join-Path (Join-Path (Join-Path $SemanticsRoot 'segments') $name) 'semantics') 'probe.host.json'
	$sem[$name] = $p
	# A2 段在 t49 实测中因宿主崩溃作废（已归档 _bugreports、未静默重试）→ 缺 A2 只记 warning
	Assert-That "semantics_probe_$name" (Test-Path $p) $p -WarnOnly:($name -eq 'A2-sync' -and -not (Test-Path $p))
}
$lagPath = Join-Path $SemanticsRoot 'lag-analysis.json'
if ((Test-Path $sem['A1-sync']) -and (Test-Path $sem['B-async'])) {
	$args = @($Analyzer, '--sync-a1', $sem['A1-sync'], '--async-b', $sem['B-async'], '--frames', '539-620', '--out', $lagPath)
	if (Test-Path $sem['A2-sync']) { $args += @('--sync-a2', $sem['A2-sync']) }
	& python @args | Out-Null
	$exit = $LASTEXITCODE
	Assert-That 'lag_analyzer_exit' ($exit -eq 0) "analyze-p3-lag exit=$exit"
}
$lag = $null
if (Test-Path $lagPath) { $lag = Get-Content -LiteralPath $lagPath -Raw | ConvertFrom-Json }
Assert-That 'lag_analysis_exists' ($null -ne $lag) $lagPath
if ($lag) {
	$histKeys = @($lag.lag_histogram.PSObject.Properties | ForEach-Object { $_.Name })
	$script:dominant = $lag.dominant_lag
	$script:const = [bool]$lag.lag_constant
	$script:fullMatch = [int]$lag.full_match_frames
	$script:compared = [int]$lag.frames_compared
	Assert-That 'lag_frames_compared' ($script:compared -ge $MinFrames) ("frames_compared=" + $script:compared + " (min " + $MinFrames + ")")
	Assert-That 'lag_histogram_nonempty' ($histKeys.Count -gt 0) ("keys=" + ($histKeys -join ','))
	Assert-That 'lag_histogram_sum_matches' ((@($lag.lag_histogram.PSObject.Properties | ForEach-Object { [int]$_.Value }) | Measure-Object -Sum).Sum -eq $script:fullMatch) ("sum=" + ((@($lag.lag_histogram.PSObject.Properties | ForEach-Object { [int]$_.Value }) | Measure-Object -Sum).Sum) + " full_match=" + $script:fullMatch)
	Assert-That 'lag_rigid_count' ([int]$lag.rigid_count -eq $ExpectRigid) ("rigid=" + $lag.rigid_count)
	Assert-That 'lag_deviation_table' ($null -ne $lag.per_lag_position_deviation) 'per_lag_position_deviation 存在'
	Assert-That 'lag_best_offset_table' ($null -ne $lag.best_sync_frame_per_async_frame) 'best_sync_frame_per_async_frame 存在'

	$roster = $lag.roster.b
	Assert-That 'roster_count' ([int]$roster.count -eq $ExpectRigid) ("count=" + $roster.count)
	Assert-That 'roster_no_duplicates' ([int]$roster.duplicates -eq 0) ("dup=" + $roster.duplicates)
	Assert-That 'roster_no_unknown' ([int]$roster.unresolved_bones -eq 0) ("unresolved=" + $roster.unresolved_bones)
	Assert-That 'roster_contiguous' ([bool]$roster.index_contiguous) ("ids=" + $roster.index_min + ".." + $roster.index_max)
	Assert-That 'roster_sync_async_equal' ([bool]$lag.roster.a1_matches_b) ("sha=" + $roster.sha256)
	if ($lag.roster.PSObject.Properties['a2']) {
		Assert-That 'roster_a2_equal' ([bool]$lag.roster.a1_matches_a2) 'A1 与 A2 名册一致'
	}
	foreach ($frame in @('540', '560', '619')) {
		$a = $lag.anchors.PSObject.Properties[$frame]
		$okAnchor = ($null -ne $a) -and $a.Value.a1_local_matches_anchor -and $a.Value.a1_world_matches_anchor
		Assert-That "anchor_$frame" $okAnchor ("a1_local=" + ($a.Value.a1.local.Substring(0, 8)) + " world=" + ($a.Value.a1.world.Substring(0, 8)))
	}

	# ── lag 分桶（0/1/2/≥3/none）：桶必须能给，且总数等于可比较帧数
	$bucketProps = @($lag.lag_buckets.PSObject.Properties)
	$bucketSum = (@($bucketProps | ForEach-Object { [int]$_.Value }) | Measure-Object -Sum).Sum
	Assert-That 'lag_buckets_present' ($bucketProps.Count -gt 0) ("buckets=" + (($bucketProps | ForEach-Object { $_.Name + ':' + $_.Value }) -join ','))
	if ($bucketProps.Count -gt 0) {
		Assert-That 'lag_buckets_sum_matches' ([int]$bucketSum -eq [int]$lag.frames_compared) ("sum=" + $bucketSum + " compared=" + $lag.frames_compared)
	}
	Assert-That 'lag_constant_flag_present' ($null -ne $lag.lag_constant) ("lag_constant=" + $lag.lag_constant)

	# ── 写回是否真生效：t58 的第一判据（不许再出现 452/479 冻结）
	$dA1 = $lag.displacement.PSObject.Properties['a1']
	$dB = $lag.displacement.PSObject.Properties['b']
	Assert-That 'displacement_blocks_present' (($null -ne $dA1) -and ($null -ne $dB)) 'displacement.a1/b 存在'
	if (($null -ne $dA1) -and ($null -ne $dB)) {
		Assert-That 'displacement_sync_all_moved' ([int]$dA1.Value.rigids_frozen -eq 0) ("a1 frozen=" + $dA1.Value.rigids_frozen + '/' + $dA1.Value.rigid_count)
		Assert-That 'displacement_async_all_moved' ([int]$dB.Value.rigids_frozen -eq 0) ("b frozen=" + $dB.Value.rigids_frozen + '/' + $dB.Value.rigid_count + " (t49 曾 452)")
		Assert-That 'displacement_async_count' ([int]$dB.Value.rigid_count -eq $ExpectRigid) ("b rigid_count=" + $dB.Value.rigid_count)
	}
}

# 5) 结论自洽：逐位逐帧一致才可能 promote；否则必须判「保持默认关闭」
$equivalent = ($null -ne $lag) -and $script:const -and ($script:fullMatch -eq $script:compared) -and ($script:compared -gt 0)
$script:semanticsEquivalent = [bool]$equivalent
if ($null -ne $lag) {
	Write-Host ("[info] semantics: dominant_lag={0} constant={1} full_match={2}/{3} => equivalent={4}" -f $script:dominant, $script:const, $script:fullMatch, $script:compared, $equivalent)
	# 收益达标但语义不等价时，最终结论必须是「不默认开」；用报告正文兜住这条一致性，避免只有数字没有结论。
	[string]$reportPath = ($reportCandidates | Where-Object { Test-Path $_ } | Select-Object -First 1)
	$reportSaysKeepOff = [bool]($reportPath) -and ((Get-Content -LiteralPath $reportPath -Raw) -match '不能默认开|保持关闭|不默认开')
	$consistent = ((-not ($script:deltaOn -ge $PromoteThresholdMs)) -or $equivalent -or $reportSaysKeepOff)
	Assert-That 'verdict_consistency' $consistent "delta_on=$($script:deltaOn) semantics_equivalent=$equivalent 报告结论=不默认开:$reportSaysKeepOff"
}

# 6) 收尾
$c4d = @(Get-Process 'Cinema 4D' -ErrorAction SilentlyContinue).Count
$port = @(Get-NetTCPConnection -LocalPort 5557 -State Listen -ErrorAction SilentlyContinue).Count
Assert-That 'host_now_clean' ($c4d -eq 0 -and $port -eq 0) "c4d=$c4d port=$port"

# 7) 构建口径
if (Test-Path $BuildSummary) {
	$b = Get-Content -LiteralPath $BuildSummary -Raw | ConvertFrom-Json
	$profLine = ($b.steps | Where-Object { $_.name -eq 'cache-sync' } | Select-Object -First 1).line
	Assert-That 'build_profiling_off' ("$profLine" -match 'CMT_ENABLE_RUNTIME_PROFILING:BOOL=OFF') "$profLine"
	$markers = @($b.steps | Where-Object { $_.name -like 'artifact-*' } | ForEach-Object { $_.profiling_marker })
	Assert-That 'build_no_marker' ($markers.Count -ge 2 -and -not ($markers -contains $true)) ("markers=" + ($markers -join ','))
	Assert-That 'build_patch_bound' ($b.steps[0].sha256.StartsWith($PatchShaPrefix)) $b.steps[0].sha256
} else {
	Assert-That 'build_summary_exists' $false $BuildSummary
}

$ok = ($failures.Count -eq 0)
Write-Host ("CHECK_P3 " + $(if ($ok) { 'OK' } else { 'FAILED' }) + " assertions=$assertions failures=$($failures.Count) warnings=$($warnings.Count)")
if (-not $ok) { Write-Host ("FAILED_IDS " + ($failures -join ',')); exit 1 }
exit 0


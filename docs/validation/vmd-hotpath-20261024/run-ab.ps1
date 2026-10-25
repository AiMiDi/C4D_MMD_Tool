# t19：baseline ↔ 候选 交替 A/B 测量驱动（不重新发明测量逻辑，只编排 stable-measure.ps1）。
#
# 为什么要交替：t14 已证明绝对毫秒跨会话不可比（同工件 20 分钟后 3.2×），只能信同一时段内的
# 相对差。因此这里按 B,C,B,C,... 严格交替，每个 variant 各自 5 次独立启动，每次启动内
# 再交替物理开/关 5 轮（stable-measure 的 -Rounds）。
#
# 负载门禁：-MaxLoadPct 30（t14 结论：外部 CPU 争用是 2× 漂移主因；被门禁丢弃的启动自动
# 重试，不算失败，但会在 summary 里留下 launch_discards）。
param(
	[string]$RepoRoot = 'C:\code\C4D_MMD_Tool',
	[string]$BaselinePlugins = 'S:\tmp\cmt_vmd_profile_20261019\ab\baseline\plugins',
	[string]$CandidatePlugins = 'S:\tmp\cmt_vmd_profile_20261019\hotpath\candidate\plugins',
	[string]$OutRoot = '',
	[int]$Pairs = 5,
	[int]$Rounds = 5,
	[int]$MaxLoadPct = 30,
	[int]$QuietMaxLoadPct = 20,
	[int]$QuietTimeoutSeconds = 900,
	[int]$QuietConsecutiveSamples = 3,
	[int]$LaunchRetries = 3,
	[int]$Warmup = 20,
	[int]$Frames = 40,
	[int]$StartFrame = 560
)

$ErrorActionPreference = 'Stop'
Set-StrictMode -Version Latest
# 本次运行的起始时刻：用于只清理「自己这次运行」留下的残留宿主。
$script:runStart = Get-Date
Set-StrictMode -Version Latest

$measure = Join-Path $RepoRoot 'docs\validation\vmd-perf-stable-20261024\stable-measure.ps1'
if (-not (Test-Path $measure)) { throw "stable-measure.ps1 不存在：$measure" }
if (-not $OutRoot) {
	$stamp = (Get-Date).ToUniversalTime().ToString('yyyyMMddTHHmmssZ')
	$OutRoot = "S:\tmp\cmt_vmd_profile_20261019\hotpath\ab\$stamp"
}
New-Item -ItemType Directory -Path $OutRoot -Force | Out-Null
Write-Host "AB_OUT_ROOT $OutRoot"

$variants = @(
	[pscustomobject]@{ name = 'baseline'; plugins = $BaselinePlugins },
	[pscustomobject]@{ name = 'candidate'; plugins = $CandidatePlugins }
)

$launchRecords = New-Object System.Collections.Generic.List[object]
$order = 0

# 机器安静门（比 stable-measure 的 -MaxLoadPct 更严格、且覆盖「跑之前」这个时刻）：
# 团队里其他人在并行 cmake/MSBuild 时，同一会话内的 5 轮会单调恶化（实测 on 38.6→47.9 ms），
# 这会系统性冤枉后跑的那个 variant。所以在每次启动前等到：无 cl/MSBuild/cmake/vctip 进程，
# 且 CPU 总占用 < $QuietMaxLoadPct 连续 $QuietConsecutiveSamples 次。等不到就记 quiet_ok=false
# 并照跑（数据仍保留，但在报告里标注该轮受干扰）。
function Wait-MachineQuiet([int]$maxLoadPct, [int]$timeoutSeconds, [int]$consecutive) {
	$deadline = (Get-Date).AddSeconds($timeoutSeconds)
	$streak = 0
	$waitedStart = Get-Date
	while ((Get-Date) -lt $deadline) {
		$builders = @(Get-Process -Name cl,MSBuild,cmake,vctip -ErrorAction SilentlyContinue)
		$load = (Get-CimInstance Win32_Processor | Measure-Object -Property LoadPercentage -Average).Average
		# MSBuild 的 /m 节点会长时间挂着（37+ 个）但多数空闲；真正影响计时的是 CPU 占用，故只看 load。
		if ($load -lt $maxLoadPct) { $streak++ } else { $streak = 0 }
		if ($streak -ge $consecutive) {
			return [pscustomobject]@{ quiet = $true; waited_s = [math]::Round(((Get-Date) - $waitedStart).TotalSeconds, 1); builders = $builders.Count; load_pct = $load }
		}
		if ($streak -eq 0) {
			Write-Host ("    [quiet] waiting: builders={0} load={1}% streak={2}" -f $builders.Count, $load, $streak)
		}
		Start-Sleep -Seconds 10
	}
	return [pscustomobject]@{ quiet = $false; waited_s = [math]::Round(((Get-Date) - $waitedStart).TotalSeconds, 1); builders = -1; load_pct = -1 }
}

foreach ($pair in 1..$Pairs) {
	foreach ($variant in $variants) {
		$order++
		$tag = 'p{0}-{1}' -f $pair, $variant.name
		$outDir = Join-Path $OutRoot $tag
		Write-Host ("== [{0}] {1}  (order {2}, pair {3})" -f (Get-Date -Format 'HH:mm:ss'), $tag, $order, $pair)
		$quiet = Wait-MachineQuiet -maxLoadPct $QuietMaxLoadPct -timeoutSeconds $QuietTimeoutSeconds -consecutive $QuietConsecutiveSamples
		Write-Host ("    [quiet] quiet={0} waited={1}s load={2}% builders={3}" -f $quiet.quiet, $quiet.waited_s, $quiet.load_pct, $quiet.builders)
		$started = Get-Date
		# 每次启动前清掉「本次运行留下的」残留宿主：宿主偶发在 startup 阶段崩到
		# "Cinema 4D: Application Error" 模态对话框（audit.log 记 REENTRANT_DRAIN，崩溃栈全在
		# python311.dll），它仍占着 5557，后续 launch-host 会以 port_already_listening 拒绝。
		# 只清理本次运行之后启动的进程，绝不碰别人/用户已有的宿主。
		# 用 CIM 枚举 + taskkill /F /T（树杀）。Get-Process 'Cinema 4D' 会漏掉部分实例
		# （2026-10-25 实测：进程存在且持有 2027 的「同一安装单实例」锁，但 Get-Process 看不到），
		# 而单实例锁会让后续每一次 Start-Process 只打印
		# "Detected another instance of the same installation running. Forwarding command line
		#  parameters..." 然后以 exit_code=-1 退出——这正是 13:17–13:28 连败的真因。
		function Clear-OurHost([string]$why) {
			$targets = @(Get-CimInstance Win32_Process -Filter "Name='Cinema 4D.exe'" -ErrorAction SilentlyContinue | Where-Object { $_.CommandLine -and $_.CommandLine.Contains($script:prefsPath) })
			foreach ($proc in $targets) {
				Write-Host ("    [cleanup:{0}] 树杀残留宿主 pid={1}（created {2}）" -f $why, $proc.ProcessId, $proc.CreationDate)
				& taskkill /F /T /PID $proc.ProcessId 2>&1 | Out-Null
			}
			if ($targets.Count -gt 0) {
				for ($w = 0; $w -lt 20; $w++) {
					if (@(Get-CimInstance Win32_Process -Filter "Name='Cinema 4D.exe'" -ErrorAction SilentlyContinue).Count -eq 0 -and
					    @(Get-NetTCPConnection -State Listen -LocalPort 5557 -ErrorAction SilentlyContinue).Count -eq 0) { break }
					Start-Sleep -Seconds 1
				}
				Start-Sleep -Seconds 3
			}
		}
		Clear-OurHost 'pre'
		$attempt = 0
		$usable = $false
		$summary = $null
		$exit = -1
		$elapsed = 0
		while (-not $usable -and $attempt -lt 3) {
			$attempt++
			$attemptDir = if ($attempt -eq 1) { $outDir } else { "$outDir-try$attempt" }
			$measureArgs = @(
				'-NoProfile', '-File', $measure,
				'-Variant', $variant.name,
				'-PluginsPath', $variant.plugins,
				'-PhysicsBoth',
				'-Rounds', "$Rounds",
				'-Launches', '1',
				'-LaunchRetries', '1',
				'-MaxLoadPct', "$MaxLoadPct",
				'-Warmup', "$Warmup",
				'-Frames', "$Frames",
				'-StartFrame', "$StartFrame",
				'-OutDir', $attemptDir
			)
			Write-Host ("    [attempt {0}] out={1}" -f $attempt, $attemptDir)
			& pwsh @measureArgs
			$exit = $LASTEXITCODE
			$elapsed = [math]::Round(((Get-Date) - $started).TotalSeconds, 1)
			$summaryPath = Join-Path $attemptDir 'run-summary.json'
			if (Test-Path $summaryPath) {
				$cand = Get-Content -LiteralPath $summaryPath -Raw | ConvertFrom-Json
				if (@($cand.launches).Count -gt 0) { $summary = $cand; $usable = $true; $outDir = $attemptDir }
			}
			if (-not $usable) {
				Write-Warning "$tag attempt $attempt 无可用的 run-summary.json 或 launches 为空（exit=$exit）"
				Clear-OurHost "attempt$attempt"
			}
		}
		if (-not $usable) {
			$launchRecords.Add([pscustomobject]@{
				order = $order; pair = $pair; variant = $variant.name; dir = $outDir
				measure_exit = $exit; elapsed_s = $elapsed; quiet_ok = $quiet.quiet; quiet_waited_s = $quiet.waited_s
				ok = $false; error = 'no usable launch after 3 attempts'
			})
			continue
		}
		$launch = $summary.launches[0]
		$onMedians = @(if ($launch.modes -and $launch.modes.on) { $launch.modes.on.medians_ms } else { @() })
		$offMedians = @(if ($launch.modes -and $launch.modes.off) { $launch.modes.off.medians_ms } else { @() })
		$launchRecords.Add([pscustomobject]@{
			order = $order
			pair = $pair
			variant = $variant.name
			dir = $outDir
			measure_exit = $exit
			elapsed_s = $elapsed
			quiet_ok = $quiet.quiet
			quiet_waited_s = $quiet.waited_s
			ok = [bool]$launch.ok
			artifact_sha = $summary.artifact.sha256
			artifact_bytes = $summary.artifact.bytes
			hosted_module_sha = $launch.hosted_module_sha
			module_match = [bool]$launch.module_match
			pid = $(if ($launch.identity) { $launch.identity.pid } else { $null })
			start_ticks_utc = $(if ($launch.identity) { $launch.identity.start_ticks_utc } else { $null })
			on_medians_ms = $onMedians
			off_medians_ms = $offMedians
			on_median_ms = $(if ($launch.modes -and $launch.modes.on) { [double]$launch.modes.on.median_of_medians_ms } else { $null })
			off_median_ms = $(if ($launch.modes -and $launch.modes.off) { [double]$launch.modes.off.median_of_medians_ms } else { $null })
			on_cv_pct = if ($onMedians.Count -ge 2) { [math]::Round((([double[]]$onMedians | Measure-Object -StandardDeviation).StandardDeviation / ([double[]]$onMedians | Measure-Object -Average).Average) * 100, 2) } else { 0 }
			off_cv_pct = if ($offMedians.Count -ge 2) { [math]::Round((([double[]]$offMedians | Measure-Object -StandardDeviation).StandardDeviation / ([double[]]$offMedians | Measure-Object -Average).Average) * 100, 2) } else { 0 }
			load_pct = $launch.load_pct
			launch_discards = $summary.launch_discards
			stop_method = $launch.stop_method
			stop_forced = [bool]$launch.stop_forced
			remaining_cinema4d = $launch.remaining_cinema4d
		})
		Write-Host ("   -> on {0:N3} ms  off {1:N3} ms  load {2}%  module {3}  exit {4}" -f `
			$launch.modes.on.median_of_medians_ms, $launch.modes.off.median_of_medians_ms, $launch.load_pct,
			([string]$launch.hosted_module_sha).Substring(0, 12), $exit)
	}
}

function Get-Stats([double[]]$values) {
	$sorted = $values | Sort-Object
	$mean = ($values | Measure-Object -Average).Average
	$sd = if ($values.Count -ge 2) { ($values | Measure-Object -StandardDeviation).StandardDeviation } else { 0 }
	[pscustomobject]@{
		n = $values.Count
		median = [math]::Round(($sorted[[int][math]::Floor(($sorted.Count - 1) / 2)] + $sorted[[int][math]::Ceiling(($sorted.Count - 1) / 2)]) / 2, 3)
		mean = [math]::Round($mean, 3)
		min = [math]::Round($sorted[0], 3)
		max = [math]::Round($sorted[$sorted.Count - 1], 3)
		cv_pct = if ($mean -gt 0) { [math]::Round(($sd / $mean) * 100, 2) } else { 0 }
	}
}

$agg = [ordered]@{}
foreach ($name in @('baseline', 'candidate')) {
	$records = @($launchRecords | Where-Object { $_.variant -eq $name -and $_.PSObject.Properties['on_median_ms'] })
	$on = @($records | ForEach-Object { [double]$_.on_median_ms })
	$off = @($records | ForEach-Object { [double]$_.off_median_ms })
	$agg[$name] = [pscustomobject]@{
		launches = $records.Count
		on = Get-Stats $on
		off = Get-Stats $off
		artifacts = @($records | ForEach-Object { [pscustomobject]@{ sha256 = $_.artifact_sha; bytes = $_.artifact_bytes } } | Sort-Object sha256 -Unique)
	}
}

$pairsOut = @()
foreach ($pair in 1..$Pairs) {
	$b = $launchRecords | Where-Object { $_.pair -eq $pair -and $_.variant -eq 'baseline' } | Select-Object -First 1
	$c = $launchRecords | Where-Object { $_.pair -eq $pair -and $_.variant -eq 'candidate' } | Select-Object -First 1
	if (-not ($b -and $c -and $b.PSObject.Properties['on_median_ms'] -and $c.PSObject.Properties['on_median_ms'])) { continue }
	$pairsOut += [pscustomobject]@{
		pair = $pair
		baseline_on_ms = $b.on_median_ms
		candidate_on_ms = $c.on_median_ms
		delta_on_ms = [math]::Round($c.on_median_ms - $b.on_median_ms, 3)
		delta_on_pct = [math]::Round((($c.on_median_ms - $b.on_median_ms) / $b.on_median_ms) * 100, 2)
		baseline_off_ms = $b.off_median_ms
		candidate_off_ms = $c.off_median_ms
		delta_off_ms = [math]::Round($c.off_median_ms - $b.off_median_ms, 3)
		delta_off_pct = [math]::Round((($c.off_median_ms - $b.off_median_ms) / $b.off_median_ms) * 100, 2)
	}
}

$result = [pscustomobject]@{
	schema = 'vmd-hotpath-ab/1'
	out_root = $OutRoot
	config = [pscustomobject]@{
		pairs = $Pairs; rounds = $Rounds; max_load_pct_gate = $MaxLoadPct; launch_retries = $LaunchRetries
		warmup = $Warmup; frames = $Frames; start_frame = $StartFrame
		baseline_plugins = $BaselinePlugins; candidate_plugins = $CandidatePlugins
	}
	launches = $launchRecords
	aggregate = $agg
	pairs_table = $pairsOut
	cleanup = [pscustomobject]@{
		stop_forced_any = [bool](@($launchRecords | Where-Object { $_.PSObject.Properties['stop_forced'] -and $_.stop_forced }).Count)
		remaining_any = [bool](@($launchRecords | Where-Object { $_.PSObject.Properties['remaining_cinema4d'] -and @($_.remaining_cinema4d).Count -gt 0 }).Count)
	}
}

$jsonPath = Join-Path $OutRoot 'ab-summary.json'
$result | ConvertTo-Json -Depth 8 | Set-Content -LiteralPath $jsonPath -Encoding utf8
Write-Host "AB_SUMMARY $jsonPath"
Write-Host ('AB_RESULT:' + ($result | ConvertTo-Json -Depth 6 -Compress))

$bad = @($launchRecords | Where-Object { -not $_.ok })
if ($bad.Count -gt 0) {
	Write-Warning ("有 {0} 次启动未成功：{1}" -f $bad.Count, (($bad | ForEach-Object { $_.dir }) -join '; '))
	exit 1
}
foreach ($name in @('baseline', 'candidate')) {
	$shas = @($agg[$name].artifacts | ForEach-Object { $_.sha256 })
	if ($shas.Count -ne 1) { Write-Warning "$name 出现了多个工件 sha：$($shas -join ', ')"; exit 1 }
}
Write-Host 'AB_OK'
exit 0

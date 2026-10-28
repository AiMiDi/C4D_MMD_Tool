# P3 异步物理：真机 A/B/A 验证（计时 + 宿主实测 lag + 逐位对齐 + 刚体名册 + 变形锚点）。
#
# 三段：A1-sync（默认 seam 路径）→ B-async（CMT_PHYSICS_ASYNC=1 + CMT_PHYSICS_PIPELINE=0）→ A2-sync。
# 计时沿用 docs/validation/vmd-perf-stable-20261024/stable-measure.ps1（安静门 -MaxLoadPct）。
# 语义采样用 launch-host.ps1 + host-driver.py + probe-rigid.py，逐帧记录刚体世界矩阵。
#
# 用法（不带 -Execute 只打印计划，供 check 脚本无宿主自检）：
#   pwsh -NoProfile -File run-p3-ab.ps1 -OutRoot S:\tmp\...\p3\ab\run1 -Execute
param(
	[string]$SyncPluginsPath = 'S:\tmp\cmt_vmd_profile_20261019\p3\sync\plugins',
	[string]$AsyncPluginsPath = 'S:\tmp\cmt_vmd_profile_20261019\p3\async\plugins',
	[string]$OutRoot = '',
	[int]$Launches = 5,
	[int]$Reps = 5,
	[int]$Warmup = 15,
	[int]$Frames = 30,
	[int]$StartFrame = 560,
	[int]$MaxLoadPct = 30,
	[int]$QuietMaxLoadPct = 20,
	[int]$QuietTimeoutSeconds = 900,
	[string]$SemanticFrames = '539-620',
	[string]$PmxPath = 'C:\pmx\白银之城—阿芙2.0\阿芙2.0.pmx',
	[string]$VmdPath = 'C:\vmd\Stay Tonight Heaven Lee Ver. 动作.vmd',
	[string]$PrefsPath = 'S:\tmp\cmt_vmd_profile_20261019\host_profile',
	[string]$CinemaExe = 'C:\Program Files\Maxon Cinema 4D 2027\Cinema 4D.exe',
	[int]$Port = 5557,
	[int]$ReadyTimeoutSeconds = 180,
	[int]$StopTimeoutSeconds = 30,
	[int]$ExpectRigid = 479,
	[int]$ExpectPoints = 70222,
	[double]$PromoteThresholdMs = 3.0,
	[double]$InvisibleThresholdMs = 1.5,
	[double]$DriftLimitPct = 5.0,
	# 默认留空 = 不设 CMT_PHYSICS_PIPELINE，让 P3 走自身的默认 seam 主路径（t35 修复的默认可达性）。
	# 若默认路径到不了异步档，可显式传 -AsyncPipeline 0 复现 t34 的强制绕法，并在报告里当作“可达性缺口”记录。
	[string]$AsyncPipeline = '',
	# 逐线程 CPU 采样（t58 新增）：回答「主线程省的 ms 有没有被 worker 吃掉」。
	[int]$ThreadCpuIntervalMs = 500,
	[switch]$SkipThreadCpu,
	[switch]$SkipRigidDisplay,
	[switch]$SkipTiming,
	[switch]$SkipSemantics,
	[switch]$Execute
)

$ErrorActionPreference = 'Stop'
$RepoRoot = Split-Path -Parent (Split-Path -Parent (Split-Path -Parent $PSScriptRoot))
$StableMeasure = Join-Path $RepoRoot 'docs\validation\vmd-perf-stable-20261024\stable-measure.ps1'
$LaunchHost = Join-Path $RepoRoot 'docs\validation\vmd-host-restore-20261024\launch-host.ps1'
$StopHost = Join-Path $RepoRoot 'docs\validation\vmd-host-restore-20261024\stop-host.ps1'
$HostDriver = Join-Path $RepoRoot 'docs\validation\vmd-host-restore-20261024\host-driver.py'
$Probe = Join-Path $PSScriptRoot 'probe-rigid.py'
$Analyzer = Join-Path $PSScriptRoot 'analyze-p3-lag.py'

# probe-rigid.py 只接受逗号分隔的帧号（parse_frames 里逐段 int()），这里把 '539-620' 展开。
function Expand-Frames([string]$spec) {
	$list = New-Object System.Collections.Generic.List[int]
	foreach ($chunk in $spec.Split(',')) {
		$c = $chunk.Trim()
		if (-not $c) { continue }
		if ($c -match '^(\d+)\s*-\s*(\d+)$') {
			$from = [int]$Matches[1]; $to = [int]$Matches[2]
			for ($i = $from; $i -le $to; $i++) { $list.Add($i) }
		} else { $list.Add([int]$c) }
	}
	return ($list -join ',')
}

$segments = @(
	[pscustomobject]@{ name = 'A1-sync'; async = '0'; pipeline = $null; plugins = $SyncPluginsPath },
	[pscustomobject]@{ name = 'B-async'; async = '1'; pipeline = $(if ($AsyncPipeline) { $AsyncPipeline } else { $null }); plugins = $AsyncPluginsPath },
	[pscustomobject]@{ name = 'A2-sync'; async = '0'; pipeline = $null; plugins = $SyncPluginsPath }
)

$plan = [ordered]@{
	schema = 'vmd-p3-ab/1'
	segments = @($segments | ForEach-Object { [ordered]@{ name = $_.name; env = "CMT_PHYSICS_ASYNC=$($_.async)"; pipeline = $_.pipeline; plugins = $_.plugins } })
	launches = $Launches; reps = $Reps; warmup = $Warmup; frames = $Frames; start_frame = $StartFrame
	max_load_pct = $MaxLoadPct; quiet_max_load_pct = $QuietMaxLoadPct
	semantic_frames = $SemanticFrames
	thresholds = [ordered]@{ promote_ms = $PromoteThresholdMs; invisible_ms = $InvisibleThresholdMs; drift_limit_pct = $DriftLimitPct }
	out_root = $OutRoot
}

if (-not $Execute) {
	Write-Host ('P3_AB_PLAN:' + ($plan | ConvertTo-Json -Depth 6 -Compress))
	exit 0
}

if (-not $OutRoot) { $OutRoot = 'S:\tmp\cmt_vmd_profile_20261019\p3\ab\' + (Get-Date -Format 'yyyyMMddTHHmmss') }
New-Item -ItemType Directory -Force -Path $OutRoot, (Join-Path $OutRoot 'logs'), (Join-Path $OutRoot 'segments') | Out-Null
if (Test-Path (Join-Path $OutRoot 'run-summary.json')) { throw "OutRoot already has run-summary.json: $OutRoot" }

$checks = New-Object System.Collections.Generic.List[object]
function Add-Check([string]$Id, [string]$Status, [string]$Detail) {
	$checks.Add([pscustomobject]@{ id = $Id; status = $Status; detail = $Detail })
	Write-Host ("[check] {0,-6} {1,-46} {2}" -f $Status.ToUpper(), $Id, $Detail)
}
function Write-Step([string]$Text) { Write-Host ('[{0}] {1}' -f (Get-Date -Format 'HH:mm:ss'), $Text) }
function Get-FileSha([string]$Path) { (Get-FileHash -LiteralPath $Path -Algorithm SHA256).Hash.ToLower() }
function Get-ModulePath([string]$PluginsPath) { Join-Path $PluginsPath 'mmdtool\mmdtool.xdl64' }
function Get-Median([double[]]$Values) {
	$arr = @($Values | Where-Object { $null -ne $_ } | Sort-Object)
	if ($arr.Count -eq 0) { return $null }
	$mid = [int][math]::Floor($arr.Count / 2)
	if ($arr.Count % 2 -eq 1) { return [double]$arr[$mid] }
	return [double](($arr[$mid - 1] + $arr[$mid]) / 2.0)
}
function Get-CpuLoadPct {
	try { return [double](Get-CimInstance Win32_Processor | Measure-Object -Property LoadPercentage -Average).Average } catch { return 0.0 }
}
function Get-OurHostProcesses {
	@(Get-CimInstance Win32_Process -Filter "Name='Cinema 4D.exe'" -ErrorAction SilentlyContinue |
		Where-Object { $_.CommandLine -and $_.CommandLine.Contains($PrefsPath) })
}
function Clear-OurHost {
	$ours = @(Get-OurHostProcesses)
	foreach ($p in $ours) { & taskkill /F /T /PID $p.ProcessId 2>&1 | Out-Null }
	if ($ours.Count -gt 0) { Start-Sleep -Seconds 3 }
}
function Wait-MachineQuiet {
	$deadline = (Get-Date).AddSeconds($QuietTimeoutSeconds)
	$hits = 0
	while ((Get-Date) -lt $deadline) {
		$load = Get-CpuLoadPct
		if ($load -lt $QuietMaxLoadPct) { $hits++ } else { $hits = 0 }
		if ($hits -ge 3) { return $true }
		Start-Sleep -Seconds 5
	}
	return $false
}

# ── 逐线程 CPU 采样（t58）───────────────────────────────────────────────
# 目的：把「主线程每帧省的 ms」与「worker 每帧吃的 ms」放在同一窗口内对比，
#       从而判断 async 是真并行（总 CPU 守恒）还是把成本搬到 worker（总 CPU 膨胀）。
# 手段：Toolhelp32 枚举本进程线程 + GetThreadTimes 取 kernel+user 累计（100 ns）。
#       主线程 TID 用 GetWindowThreadProcessId 从主窗口认定，比「CPU 最高」稳。
# 失败降级：任何 P/Invoke/句柄失败 → state=unavailable + reason，绝不让整轮崩。
$ThreadCpuSource = @'
using System;
using System.Collections.Generic;
using System.Runtime.InteropServices;

public static class CmtThreadCpu
{
    [StructLayout(LayoutKind.Sequential)]
    struct FILETIME { public uint Low; public uint High; }

    [StructLayout(LayoutKind.Sequential)]
    struct THREADENTRY32 {
        public uint dwSize; public uint cntUsage; public uint th32ThreadID; public uint th32OwnerProcessID;
        public int tpBasePri; public int tpDeltaPri; public uint dwFlags;
    }

    [StructLayout(LayoutKind.Sequential)]
    public struct ThreadStat { public uint tid; public long creation100ns; public long cpu100ns; }

    [DllImport("kernel32.dll", SetLastError = true)]
    static extern IntPtr CreateToolhelp32Snapshot(uint dwFlags, uint th32ProcessID);
    [DllImport("kernel32.dll", SetLastError = true)]
    static extern bool Thread32First(IntPtr hSnapshot, ref THREADENTRY32 lpte);
    [DllImport("kernel32.dll", SetLastError = true)]
    static extern bool Thread32Next(IntPtr hSnapshot, ref THREADENTRY32 lpte);
    [DllImport("kernel32.dll", SetLastError = true)]
    static extern IntPtr OpenThread(uint dwDesiredAccess, bool bInheritHandle, uint dwThreadId);
    [DllImport("kernel32.dll", SetLastError = true)]
    static extern bool GetThreadTimes(IntPtr hThread, out FILETIME lpCreationTime, out FILETIME lpExitTime, out FILETIME lpKernelTime, out FILETIME lpUserTime);
    [DllImport("kernel32.dll", SetLastError = true)]
    static extern bool CloseHandle(IntPtr hObject);
    [DllImport("user32.dll", SetLastError = true)]
    static extern uint GetWindowThreadProcessId(IntPtr hWnd, out uint lpdwProcessId);

    const uint TH32CS_SNAPTHREAD = 0x00000004;
    const uint THREAD_QUERY_INFORMATION = 0x0040;
    const uint THREAD_QUERY_LIMITED_INFORMATION = 0x0800;

    static long ToLong(FILETIME ft) { return ((long)ft.High << 32) | (long)ft.Low; }

    public static ThreadStat[] Sample(uint processId)
    {
        var list = new List<ThreadStat>();
        IntPtr snap = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, 0);
        if (snap == new IntPtr(-1)) return list.ToArray();
        try
        {
            var te = new THREADENTRY32();
            te.dwSize = (uint)Marshal.SizeOf(typeof(THREADENTRY32));
            if (Thread32First(snap, ref te))
            {
                do
                {
                    if (te.th32OwnerProcessID != processId) continue;
                    IntPtr h = OpenThread(THREAD_QUERY_LIMITED_INFORMATION, false, te.th32ThreadID);
                    if (h == IntPtr.Zero) h = OpenThread(THREAD_QUERY_INFORMATION, false, te.th32ThreadID);
                    if (h == IntPtr.Zero) continue;
                    try
                    {
                        FILETIME c, e, k, u;
                        if (GetThreadTimes(h, out c, out e, out k, out u))
                        {
                            var s = new ThreadStat();
                            s.tid = te.th32ThreadID;
                            s.creation100ns = ToLong(c);
                            s.cpu100ns = ToLong(k) + ToLong(u);
                            list.Add(s);
                        }
                    }
                    finally { CloseHandle(h); }
                }
                while (Thread32Next(snap, ref te));
            }
        }
        finally { CloseHandle(snap); }
        return list.ToArray();
    }

    public static uint ThreadOfWindow(long hwnd)
    {
        uint pid;
        return GetWindowThreadProcessId(new IntPtr(hwnd), out pid);
    }
}
'@

$script:threadCpuType = $null
$script:threadCpuState = $null
$script:threadCpuReason = ''

function Initialize-ThreadCpu {
	if ($SkipThreadCpu) { return 'skipped' }
	if ($script:threadCpuState) { return $script:threadCpuState }
	try {
		if (-not $script:threadCpuType) {
			Add-Type -TypeDefinition $ThreadCpuSource -Language CSharp -ErrorAction Stop
			$script:threadCpuType = [CmtThreadCpu]
		}
		$script:threadCpuState = 'available'
	} catch {
		$script:threadCpuState = 'unavailable'
		$script:threadCpuReason = $_.Exception.Message
	}
	return $script:threadCpuState
}

function New-ThreadCpuSession {
	return [pscustomobject]@{
		state      = (Initialize-ThreadCpu)
		reason     = $script:threadCpuReason
		pids       = @{}
		samples    = 0
		tick       = 0
		refreshEvery = 10   # 每 10 次采样（≈5 s）刷新一次宿主 pid 集合，避免 CIM 查询本身干扰计时
		started    = (Get-Date)
	}
}

function Update-ThreadCpuSession {
	param($Session)
	if ($Session.state -ne 'available') { return }
	$Session.samples++
	$Session.tick++
	$now = Get-Date
	if (($Session.tick % $Session.refreshEvery) -eq 1 -or $Session.pids.Count -eq 0) {
		foreach ($p in Get-OurHostProcesses) {
			$key = [string]$p.ProcessId
			if ($Session.pids.ContainsKey($key)) { continue }
			$startFt = 0L
			try { $startFt = ([long](Get-Process -Id $p.ProcessId -ErrorAction Stop).StartTime.ToUniversalTime().ToFileTime()) } catch { }
			$Session.pids[$key] = [pscustomobject]@{
				process    = [int]$p.ProcessId
				start_ft   = $startFt
				main_tid   = 0
				first_seen = $now
				last_seen  = $now
				threads    = @{}
			}
		}
	}
	foreach ($key in @($Session.pids.Keys)) {
		$entry = $Session.pids[$key]
		$alive = $true
		try { $null = Get-Process -Id $entry.process -ErrorAction Stop } catch { $alive = $false }
		if (-not $alive) { continue }
		$entry.last_seen = $now
		try { $stats = @([CmtThreadCpu]::Sample([uint32]$entry.process)) } catch { continue }
		foreach ($st in $stats) {
			$tk = [string]$st.tid
			if (-not $entry.threads.ContainsKey($tk)) {
				$entry.threads[$tk] = [pscustomobject]@{
					tid        = [int]$st.tid
					creation   = [long]$st.creation100ns
					last_cpu   = [double]$st.cpu100ns
					cpu        = 0.0
				}
			}
			$th = $entry.threads[$tk]
			$delta = [double]$st.cpu100ns - $th.last_cpu
			if ($delta -gt 0) { $th.cpu += $delta }
			$th.last_cpu = [double]$st.cpu100ns
		}
		if ($entry.main_tid -eq 0) {
			try {
				$hwnd = (Get-Process -Id $entry.process -ErrorAction Stop).MainWindowHandle
				if ($hwnd -ne [IntPtr]::Zero) { $entry.main_tid = [int][CmtThreadCpu]::ThreadOfWindow([long]$hwnd) }
			} catch { }
		}
	}
}

function Complete-ThreadCpuSession {
	param($Session, [string]$OutPath, [int]$FramesMeasured, [string]$SegmentName)

	$result = [ordered]@{
		schema          = 'vmd-p3-thread-cpu/1'
		segment         = $SegmentName
		state           = $Session.state
		reason          = $Session.reason
		interval_ms     = $ThreadCpuIntervalMs
		sample_count    = $Session.samples
		frames_measured = $FramesMeasured
		launches        = @()
		thread_count    = 0
		totals          = [ordered]@{
			main_ms            = 0.0
			worker_ms          = 0.0
			total_ms           = 0.0
			# 「晚起线程」= 进程启动 2 s 之后才创建的线程：async 的物理 worker 只会在第一次推进时才创建，
			# 用它把 pipeline worker 与 Redshift/渲染等常驻线程分开。
			worker_ms_late     = 0.0
			main_thread_detected = $false
			main_ms_per_frame  = $null
			worker_ms_per_frame = $null
			total_ms_per_frame = $null
			worker_ms_late_per_frame = $null
		}
	}

	if ($Session.state -eq 'available') {
		$mainMs = 0.0; $workerMs = 0.0; $threadCount = 0; $lateMs = 0.0; $mainDetected = $false
		foreach ($key in @($Session.pids.Keys)) {
			$entry = $Session.pids[$key]
			if ($entry.main_tid -ne 0) { $mainDetected = $true }
			$launchMain = 0.0; $launchWorker = 0.0
			$rows = New-Object System.Collections.Generic.List[object]
			foreach ($tk in @($entry.threads.Keys)) {
				$th = $entry.threads[$tk]
				$ms = $th.cpu / 10000.0
				$isMain = ($th.tid -eq $entry.main_tid)
				if ($isMain) { $launchMain += $ms } else { $launchWorker += $ms }
				$createdAfterS = $null
				if ($entry.start_ft -gt 0 -and $th.creation -gt 0) {
					$createdAfterS = [math]::Round((($th.creation - $entry.start_ft) / 10000000.0), 2)
				}
				if ($createdAfterS -ne $null -and $createdAfterS -ge 2.0 -and -not $isMain) { $lateMs += $ms }
				$rows.Add([pscustomobject]@{
					tid              = $th.tid
					cpu_ms           = [math]::Round($ms, 3)
					is_main          = $isMain
					created_after_s  = $createdAfterS
					creation_ticks   = $th.creation
				})
			}
			$threadCount += $rows.Count
			$mainMs += $launchMain
			$workerMs += $launchWorker
			$result.launches += [pscustomobject]@{
				pid             = [int]$entry.process
				main_thread_tid = [int]$entry.main_tid
				wall_s          = [math]::Round(($entry.last_seen - $entry.first_seen).TotalSeconds, 3)
				main_ms         = [math]::Round($launchMain, 3)
				worker_ms       = [math]::Round($launchWorker, 3)
				top_threads     = @($rows | Sort-Object -Property cpu_ms -Descending | Select-Object -First 12)
			}
		}
		$result.thread_count = $threadCount
		$result.totals.main_ms = [math]::Round($mainMs, 3)
		$result.totals.worker_ms = [math]::Round($workerMs, 3)
		$result.totals.total_ms = [math]::Round($mainMs + $workerMs, 3)
		$result.totals.worker_ms_late = [math]::Round($lateMs, 3)
		$result.totals.main_thread_detected = $mainDetected
		if ($FramesMeasured -gt 0) {
			$result.totals.main_ms_per_frame = [math]::Round($mainMs / $FramesMeasured, 4)
			$result.totals.worker_ms_per_frame = [math]::Round($workerMs / $FramesMeasured, 4)
			$result.totals.total_ms_per_frame = [math]::Round(($mainMs + $workerMs) / $FramesMeasured, 4)
			$result.totals.worker_ms_late_per_frame = [math]::Round($lateMs / $FramesMeasured, 4)
		}
	}

	$result | ConvertTo-Json -Depth 8 | Set-Content -LiteralPath $OutPath -Encoding UTF8
	return $result
}

# 预检
foreach ($p in @($SyncPluginsPath, $AsyncPluginsPath)) {
	$module = Get-ModulePath $p
	if (-not (Test-Path $module)) { throw "missing module: $module" }
}
$syncSha = Get-FileSha (Get-ModulePath $SyncPluginsPath)
$asyncSha = Get-FileSha (Get-ModulePath $AsyncPluginsPath)
Add-Check 'artifacts_present' ($(if ($syncSha -ne $asyncSha) { 'passed' } else { 'failed' })) "sync=$($syncSha.Substring(0,16)) async=$($asyncSha.Substring(0,16))"
$productStatus = @(& git -C $RepoRoot status --porcelain --ignore-submodules -- source res sdk_2026 sdk_2027 dependency | Where-Object { $_ -notmatch '^\?\?' })
Add-Check 'product_tree_untouched' ($(if ($productStatus.Count -eq 0) { 'passed' } else { 'failed' })) "tracked_changes=$($productStatus.Count)"

function Invoke-SegmentTiming {
	param($Segment)
	$segRoot = Join-Path $OutRoot "segments\$($Segment.name)\timing"
	New-Item -ItemType Directory -Force -Path $segRoot | Out-Null

	$prevAsync = $env:CMT_PHYSICS_ASYNC
	$prevPipeline = $env:CMT_PHYSICS_PIPELINE
	try {
		$env:CMT_PHYSICS_ASYNC = $Segment.async
		if ($Segment.pipeline) { $env:CMT_PHYSICS_PIPELINE = $Segment.pipeline } else { Remove-Item Env:CMT_PHYSICS_PIPELINE -ErrorAction SilentlyContinue }

		if (-not (Wait-MachineQuiet)) { Add-Check "quiet_$($Segment.name)" 'failed' "CPU 未在 $QuietTimeoutSeconds s 内降到 $QuietMaxLoadPct% 以下" }
		else { Add-Check "quiet_$($Segment.name)" 'passed' ("load=" + [math]::Round((Get-CpuLoadPct),1) + '%') }

		Write-Step "计时 $($Segment.name)（ASYNC=$($Segment.async) PIPELINE=$($Segment.pipeline) launches=$Launches reps=$Reps）"
		$measureArgs = @('-NoProfile', '-File', $StableMeasure, '-Variant', $Segment.name, '-PluginsPath', $Segment.plugins,
			'-PhysicsBoth', '-Rounds', "$Reps", '-Launches', "$Launches", '-LaunchRetries', '2',
			'-Warmup', "$Warmup", '-Frames', "$Frames", '-StartFrame', "$StartFrame",
			'-MaxLoadPct', "$MaxLoadPct", '-OutDir', $segRoot,
			'-PrefsPath', $PrefsPath, '-CinemaExe', $CinemaExe, '-Port', "$Port", '-ReadyTimeoutSeconds', "$ReadyTimeoutSeconds")

		# 用 Start-Process + 轮询来跑 stable-measure：这样父进程能在整个测量窗口内采逐线程 CPU。
		$logPath = Join-Path $OutRoot "logs\timing-$($Segment.name).log"
		$logErrPath = Join-Path $OutRoot "logs\timing-$($Segment.name).err.log"
		New-Item -ItemType Directory -Force -Path (Join-Path $OutRoot 'logs') | Out-Null
		$quoted = @($measureArgs | ForEach-Object { if ("$_" -match '\s') { '"' + $_ + '"' } else { "$_" } })
		$cpuSession = New-ThreadCpuSession
		$proc = Start-Process -FilePath (Get-Command pwsh).Source -ArgumentList $quoted -RedirectStandardOutput $logPath -RedirectStandardError $logErrPath -PassThru -NoNewWindow
		while (-not $proc.HasExited) {
			Update-ThreadCpuSession $cpuSession
			Start-Sleep -Milliseconds $ThreadCpuIntervalMs
		}
		Update-ThreadCpuSession $cpuSession
		$proc.WaitForExit()
		$exit = $proc.ExitCode
		if (Test-Path $logPath) { Get-Content -LiteralPath $logPath | Out-Host }
		$framesMeasured = $Launches * $Reps * 2 * $Frames
		$cpu = Complete-ThreadCpuSession -Session $cpuSession -OutPath (Join-Path $segRoot 'thread-cpu.json') `
			-FramesMeasured $framesMeasured -SegmentName $Segment.name
		if ($cpu.state -eq 'available') {
			Write-Step ("thread-cpu {0}: main={1} ms/frame worker={2} ms/frame total={3} threads={4} samples={5}" -f `
				$Segment.name, $cpu.totals.main_ms_per_frame, $cpu.totals.worker_ms_per_frame, $cpu.totals.total_ms_per_frame, $cpu.thread_count, $cpu.sample_count)
		} else {
			Write-Step ("thread-cpu {0}: state={1} reason={2}" -f $Segment.name, $cpu.state, $cpu.reason)
		}
		$summaryPath = Join-Path $segRoot 'run-summary.json'
		if (-not (Test-Path $summaryPath)) { Add-Check "timing_$($Segment.name)_exit" 'failed' "stable-measure exit=$exit 且缺 run-summary.json"; Add-Check "timing_$($Segment.name)_summary" 'failed' '缺 run-summary.json'; return $null }
		$summary = Get-Content -LiteralPath $summaryPath -Raw | ConvertFrom-Json
		# 宿主崩溃会让 stable-measure 返回非 0（该次尝试被 -LaunchRetries 重试后补上）：
		# 只要该段最终有效 launch 数达标且确有重试目录，就记 warning 而不是 failed（崩溃事实仍写进 detail）。
		$launchDirs = @(Get-ChildItem -LiteralPath $segRoot -Directory -ErrorAction SilentlyContinue | Where-Object { $_.Name -like 'launch-*' })
		$retried = @($launchDirs | Where-Object { $_.Name -like '*retry*' }).Count
		$validLaunches = @($summary.launches).Count
		$exitStatus = if ($exit -eq 0) { 'passed' }
			elseif ($validLaunches -ge $Launches -and $retried -gt 0) { 'warning' }
			else { 'failed' }
		Add-Check "timing_$($Segment.name)_exit" $exitStatus "stable-measure exit=$exit launches=$validLaunches retried_attempts=$retried"
		return $summary
	} finally {
		if ($null -eq $prevAsync) { Remove-Item Env:CMT_PHYSICS_ASYNC -ErrorAction SilentlyContinue } else { $env:CMT_PHYSICS_ASYNC = $prevAsync }
		if ($null -eq $prevPipeline) { Remove-Item Env:CMT_PHYSICS_PIPELINE -ErrorAction SilentlyContinue } else { $env:CMT_PHYSICS_PIPELINE = $prevPipeline }
	}
}

function Invoke-SegmentSemantics {
	param($Segment)
	$segRoot = Join-Path $OutRoot "segments\$($Segment.name)\semantics"
	$hostOut = Join-Path $segRoot 'host'
	$probeOut = Join-Path $segRoot 'probe.json'
	New-Item -ItemType Directory -Force -Path $segRoot, $hostOut | Out-Null

	$prevAsync = $env:CMT_PHYSICS_ASYNC
	$prevPipeline = $env:CMT_PHYSICS_PIPELINE
	try {
		$env:CMT_PHYSICS_ASYNC = $Segment.async
		if ($Segment.pipeline) { $env:CMT_PHYSICS_PIPELINE = $Segment.pipeline } else { Remove-Item Env:CMT_PHYSICS_PIPELINE -ErrorAction SilentlyContinue }
		Write-Step "语义采样 $($Segment.name)（ASYNC=$($Segment.async) PIPELINE=$($Segment.pipeline) frames=$SemanticFrames）"

		& pwsh -NoProfile -File $LaunchHost -Execute -OutRoot $hostOut -ModulePath ($Segment.plugins) -Port $Port -PrefsPath $PrefsPath -CinemaExe $CinemaExe -ReadyTimeoutSeconds $ReadyTimeoutSeconds 2>&1 |
			Tee-Object -FilePath (Join-Path $OutRoot "logs\sem-$($Segment.name)-launch.log") | Out-Host
		if ($LASTEXITCODE -ne 0) { Add-Check "sem_$($Segment.name)_launch" 'failed' "launch-host exit=$LASTEXITCODE"; return $null }

		& python $HostDriver new-scene 2>&1 | Tee-Object -FilePath (Join-Path $OutRoot "logs\sem-$($Segment.name)-driver.log") | Out-Host
		& python $HostDriver import --pmx $PmxPath --vmd $VmdPath 2>&1 | Tee-Object -Append -FilePath (Join-Path $OutRoot "logs\sem-$($Segment.name)-driver.log") | Out-Host
		$motionLog = & python $HostDriver import-motion --vmd $VmdPath 2>&1
		$motionLog | Tee-Object -Append -FilePath (Join-Path $OutRoot "logs\sem-$($Segment.name)-driver.log") | Out-Host
		$slotPresent = ($motionLog -join "`n") -match '"slot"\s*:\s*"'
		Add-Check "sem_$($Segment.name)_slot" ($(if ($slotPresent) { 'passed' } else { 'failed' })) 'import-motion 是否创建动画槽'
		if (-not $slotPresent) { return $null }

		& python $HostDriver set-mode --mode anim 2>&1 | Out-Null
		& python $HostDriver physics --enabled on 2>&1 | Out-Null

		$probeArgs = @($Probe, '--frames', (Expand-Frames $SemanticFrames), '--out', $probeOut,
			'--expect-rigid', "$ExpectRigid", '--expect-points', "$ExpectPoints", '--prefs-path', $PrefsPath)
		if (-not $SkipRigidDisplay) { $probeArgs += '--enable-rigid-display' }
		& python @probeArgs 2>&1 | Tee-Object -FilePath (Join-Path $OutRoot "logs\sem-$($Segment.name)-probe.log") | Out-Host
		if ($LASTEXITCODE -ne 0) { Add-Check "sem_$($Segment.name)_probe" 'failed' "probe exit=$LASTEXITCODE" } else { Add-Check "sem_$($Segment.name)_probe" 'passed' 'probe exit=0' }
	} finally {
		if ($null -eq $prevAsync) { Remove-Item Env:CMT_PHYSICS_ASYNC -ErrorAction SilentlyContinue } else { $env:CMT_PHYSICS_ASYNC = $prevAsync }
		if ($null -eq $prevPipeline) { Remove-Item Env:CMT_PHYSICS_PIPELINE -ErrorAction SilentlyContinue } else { $env:CMT_PHYSICS_PIPELINE = $prevPipeline }
		$identity = Join-Path $hostOut 'host-identity.json'
		if (Test-Path $identity) {
			& pwsh -NoProfile -File $StopHost -Execute -IdentityPath $identity -OutRoot $hostOut -StopTimeoutSeconds $StopTimeoutSeconds 2>&1 |
				Tee-Object -FilePath (Join-Path $OutRoot "logs\sem-$($Segment.name)-stop.log") | Out-Host
			$cleanup = Join-Path $hostOut 'cleanup.json'
			if (Test-Path $cleanup) {
				$c = Get-Content $cleanup -Raw | ConvertFrom-Json
				$method = $c.PSObject.Properties['stop_method'] ? $c.stop_method : 'unknown'
				$forced = $c.PSObject.Properties['stop_forced'] ? $c.stop_forced : $null
				Add-Check "cleanup_$($Segment.name)" 'passed' "method=$method forced=$forced remaining=$(@($c.remaining_cinema_processes).Count)"
			}
		}
	}
	return $null
}

# ── 计时
$timing = @{}
if (-not $SkipTiming) {
	foreach ($seg in $segments) {
		$timing[$seg.name] = Invoke-SegmentTiming -Segment $seg
		Clear-OurHost
	}
}

# ── 语义
$semantics = @{}
if (-not $SkipSemantics) {
	foreach ($seg in $segments) {
		$null = Invoke-SegmentSemantics -Segment $seg
		$semantics[$seg.name] = Join-Path $OutRoot "segments\$($seg.name)\semantics\probe.host.json"
		Clear-OurHost
	}
}

# ── 计时聚合：每段取所有 launch 的 on/off median 的 median
$timingSummary = [ordered]@{}
foreach ($name in @('A1-sync', 'B-async', 'A2-sync')) {
	$s = $timing[$name]
	if (-not $s) { continue }
	$agg = $s.aggregate
	if (-not $agg) { continue }
	$onPerLaunch = @($agg.on.per_launch_median_ms | Where-Object { $null -ne $_ })
	$offPerLaunch = @($agg.off.per_launch_median_ms | Where-Object { $null -ne $_ })
	$timingSummary[$name] = [ordered]@{
		launches = @($s.launches).Count
		on_per_launch_ms = $onPerLaunch
		off_per_launch_ms = $offPerLaunch
		on_median_ms = Get-Median $onPerLaunch
		off_median_ms = Get-Median $offPerLaunch
		on_mean_ms = if ($onPerLaunch.Count) { [math]::Round(($onPerLaunch | Measure-Object -Average).Average, 3) } else { $null }
		load_pct = @($s.launches | ForEach-Object { $_.load_pct })
	}
}
$benefit = $null
if ($timingSummary['A1-sync'] -and $timingSummary['B-async'] -and $timingSummary['A1-sync'].on_median_ms -and $timingSummary['B-async'].on_median_ms) {
	$benefit = [ordered]@{
		sync_on_ms = $timingSummary['A1-sync'].on_median_ms
		async_on_ms = $timingSummary['B-async'].on_median_ms
		delta_on_ms = [math]::Round($timingSummary['A1-sync'].on_median_ms - $timingSummary['B-async'].on_median_ms, 3)
		delta_on_pct = [math]::Round(100.0 * ($timingSummary['A1-sync'].on_median_ms - $timingSummary['B-async'].on_median_ms) / $timingSummary['A1-sync'].on_median_ms, 2)
		sync_off_ms = if ($timingSummary['A1-sync'].off_median_ms) { $timingSummary['A1-sync'].off_median_ms } else { $null }
		async_off_ms = if ($timingSummary['B-async'].off_median_ms) { $timingSummary['B-async'].off_median_ms } else { $null }
	}
	$delta = $benefit.delta_on_ms
	$benefit['decision'] = if ($delta -ge $PromoteThresholdMs) { 'promote_candidate' } elseif ($delta -lt $InvisibleThresholdMs) { 'archive_invisible' } else { 'gray_keep_off' }
}
$driftPct = $null
if ($timingSummary['A1-sync'] -and $timingSummary['A2-sync'] -and $timingSummary['A1-sync'].on_median_ms) {
	$driftPct = [math]::Round(100.0 * [math]::Abs($timingSummary['A2-sync'].on_median_ms - $timingSummary['A1-sync'].on_median_ms) / $timingSummary['A1-sync'].on_median_ms, 2)
	Add-Check 'a1_a2_drift' ($(if ($driftPct -le $DriftLimitPct) { 'passed' } else { 'failed' })) "drift=$driftPct% (limit $DriftLimitPct%)"
} else { Add-Check 'a1_a2_drift' 'failed' '缺 A1/A2 计时' }

# ── lag 分析
$lagAnalysis = $null
$lagPath = Join-Path $OutRoot 'lag-analysis.json'
if ($semantics['A1-sync'] -and $semantics['B-async'] -and (Test-Path $semantics['A1-sync']) -and (Test-Path $semantics['B-async'])) {
	$argList = @($Analyzer, '--sync-a1', $semantics['A1-sync'], '--async-b', $semantics['B-async'], '--frames', $SemanticFrames, '--out', $lagPath)
	if ($semantics['A2-sync'] -and (Test-Path $semantics['A2-sync'])) { $argList += @('--sync-a2', $semantics['A2-sync']) }
	& python @argList 2>&1 | Tee-Object -FilePath (Join-Path $OutRoot 'logs\lag-analysis.log') | Out-Host
	if (Test-Path $lagPath) {
		$lagAnalysis = Get-Content $lagPath -Raw | ConvertFrom-Json
		Add-Check 'lag_histogram_nonempty' ($(if (@($lagAnalysis.lag_histogram.PSObject.Properties).Count -gt 0) { 'passed' } else { 'failed' })) ("hist=" + (($lagAnalysis.lag_histogram | ConvertTo-Json -Compress)))
		Add-Check 'lag_constant' ($(if ($lagAnalysis.lag_constant) { 'passed' } else { 'failed' })) "dominant=$($lagAnalysis.dominant_lag) constant=$($lagAnalysis.lag_constant)"
		Add-Check 'lag_bitwise_align' ($(if ($lagAnalysis.full_match_frames -eq $lagAnalysis.frames_compared -and $lagAnalysis.frames_compared -gt 0) { 'passed' } else { 'failed' })) "$($lagAnalysis.full_match_frames)/$($lagAnalysis.frames_compared) 帧逐位相等"
		$roster = $lagAnalysis.roster
		Add-Check 'roster_aligned' ($(if ($roster.b.count -eq $ExpectRigid -and $roster.b.duplicates -eq 0 -and $roster.b.unresolved_bones -eq 0 -and $roster.a1_matches_b) { 'passed' } else { 'failed' })) "count=$($roster.b.count) dup=$($roster.b.duplicates) unresolved=$($roster.b.unresolved_bones) sha=$($roster.b.sha256.Substring(0,16))"
		Add-Check 'anchor_mesh' ($(if (@($lagAnalysis.anchors.PSObject.Properties | Where-Object { $_.Value.a1_local_matches_anchor -and $_.Value.a1_world_matches_anchor }).Count -eq 3) { 'passed' } else { 'failed' })) '帧 540/560/619 局部+世界锚点'
		if ($lagAnalysis.sync_a1_vs_a2) {
			Add-Check 'sync_a1_vs_a2' ($(if ($lagAnalysis.sync_a1_vs_a2.all_identical) { 'passed' } else { 'failed' })) "$($lagAnalysis.sync_a1_vs_a2.identical)/$($lagAnalysis.sync_a1_vs_a2.frames) 帧逐位一致"
		}
		# t58 第一判据：写回必须让 479 个刚体全部动过（t49 曾是 452 冻结 / 27 移动）
		$dispB = $lagAnalysis.displacement.b
		$dispA1 = $lagAnalysis.displacement.a1
		if ($dispB) {
			Add-Check 'writeback_async_all_rigids_moved' ($(if ([int]$dispB.rigids_frozen -eq 0) { 'passed' } else { 'failed' })) `
				"async moved=$($dispB.rigids_moved)/$($dispB.rigid_count) frozen=$($dispB.rigids_frozen) max_mm=$($dispB.max_displacement_mm)"
		}
		if ($dispA1) {
			Add-Check 'writeback_sync_all_rigids_moved' ($(if ([int]$dispA1.rigids_frozen -eq 0) { 'passed' } else { 'failed' })) `
				"sync moved=$($dispA1.rigids_moved)/$($dispA1.rigid_count) frozen=$($dispA1.rigids_frozen)"
		}
		$buckets = $lagAnalysis.lag_buckets
		Add-Check 'lag_buckets_present' ($(if ($buckets -and @($buckets.PSObject.Properties).Count -gt 0) { 'passed' } else { 'failed' })) `
			("buckets=" + (($buckets.PSObject.Properties | ForEach-Object { $_.Name + ':' + $_.Value }) -join ','))
	}
} else { Add-Check 'lag_analysis' 'failed' '缺语义采样输出' }

# ── 逐线程 CPU 汇总（t58）：主线程省下的 ms 是否被 worker 吃掉
$threadCpu = [ordered]@{}
foreach ($seg in $segments) {
	$tp = Join-Path $OutRoot ("segments\{0}\timing\thread-cpu.json" -f $seg.name)
	if (-not (Test-Path $tp)) { Add-Check "worker_cpu_$($seg.name)" 'failed' "缺 $tp"; continue }
	$c = Get-Content -LiteralPath $tp -Raw | ConvertFrom-Json
	$threadCpu[$seg.name] = $c
	$stateOk = ("$($c.state)" -eq 'available')
	Add-Check "worker_cpu_$($seg.name)" ($(if ($stateOk) { 'passed' } else { 'failed' })) `
		("state=" + $c.state + " main=" + $c.totals.main_ms_per_frame + " worker=" + $c.totals.worker_ms_per_frame + " total=" + $c.totals.total_ms_per_frame + " samples=" + $c.sample_count)
	if ($stateOk -and $seg.name -eq 'B-async') {
		Add-Check 'worker_cpu_async_nonzero' ($(if ([double]$c.totals.worker_ms_per_frame -gt 0) { 'passed' } else { 'failed' })) `
			("worker_ms_per_frame=" + $c.totals.worker_ms_per_frame)
	}
}

Clear-OurHost
$c4dLeft = @(Get-Process 'Cinema 4D' -ErrorAction SilentlyContinue).Count
$portLeft = @(Get-NetTCPConnection -LocalPort $Port -State Listen -ErrorAction SilentlyContinue).Count
Add-Check 'host_clean' ($(if ($c4dLeft -eq 0 -and $portLeft -eq 0) { 'passed' } else { 'failed' })) "c4d=$c4dLeft port=$portLeft"

$warnings = @($checks | Where-Object { $_.status -eq 'warning' })
$failures = @($checks | Where-Object { $_.status -notin @('passed', 'warning') })
$summary = [ordered]@{
	schema = 'vmd-p3-ab-result/1'
	generated_at = (Get-Date).ToString('o')
	artifacts = [ordered]@{ sync = $syncSha; async = $asyncSha; sync_path = (Get-ModulePath $SyncPluginsPath); async_path = (Get-ModulePath $AsyncPluginsPath) }
	config = $plan
	timing = $timingSummary
	benefit = $benefit
	a1_a2_drift_pct = $driftPct
	lag = $lagAnalysis
	thread_cpu = $threadCpu
	checks = $checks
	failures = $failures
	warnings = $warnings
	verdict = $(if ($failures.Count -eq 0) { 'pass' } else { 'fail' })
}
$summary | ConvertTo-Json -Depth 12 | Set-Content -Path (Join-Path $OutRoot 'run-summary.json') -Encoding utf8

Write-Host ("P3_AB " + $summary.verdict.ToUpper() + " checks=" + $checks.Count + " failures=" + $failures.Count)
if ($benefit) { Write-Host ("BENEFIT on: sync={0} async={1} delta={2} ms ({3}%) decision={4}" -f $benefit.sync_on_ms, $benefit.async_on_ms, $benefit.delta_on_ms, $benefit.delta_on_pct, $benefit.decision) }
if ($lagAnalysis) { Write-Host ("LAG dominant={0} constant={1} match={2}/{3}" -f $lagAnalysis.dominant_lag, $lagAnalysis.lag_constant, $lagAnalysis.full_match_frames, $lagAnalysis.frames_compared) }
Write-Host ("HOST c4d={0} port={1}" -f $c4dLeft, $portLeft)
if ($failures.Count -ne 0) { exit 1 }
exit 0

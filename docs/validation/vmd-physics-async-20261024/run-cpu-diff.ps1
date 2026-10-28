# 变体级 CPU 差分：sync vs async 各起一台宿主，跑固定「物理开」帧序列，采进程总 CPU 与墙钟。
# 用途：判断「主线程省下的时间是否被 worker 吃掉」——进程总 CPU 若与 sync 持平，说明只是把工作搬到了别的线程。
param(
	[string]$SyncPlugins = 'S:\tmp\cmt_vmd_profile_20261019\p3b\sync\plugins',
	[string]$AsyncPlugins = 'S:\tmp\cmt_vmd_profile_20261019\p3b\async\plugins',
	[string]$OutRoot = 'S:\tmp\cmt_vmd_profile_20261019\p3b\cpu-diff',
	[int]$StartFrame = 560,
	[int]$Frames = 60,
	[int]$Warmup = 10,
	[int]$MaxLoadPct = 30,
	[int]$QuietMaxLoadPct = 20,
	[string]$PrefsPath = 'S:\tmp\cmt_vmd_profile_20261019\host_profile',
	[int]$Port = 5557,
	[string]$CinemaExe = 'C:\Program Files\Maxon Cinema 4D 2027\Cinema 4D.exe',
	[string]$PmxPath = 'C:\pmx\白银之城—阿芙2.0\阿芙2.0.pmx',
	[string]$VmdPath = 'C:\vmd\Stay Tonight Heaven Lee Ver. 动作.vmd',
	[ValidateSet('sync', 'async')]
	[string[]]$Variants = @('sync', 'async'),
	[switch]$Execute
)

$ErrorActionPreference = 'Stop'
$repo = Split-Path -Parent (Split-Path -Parent (Split-Path -Parent $PSScriptRoot))
$hostDir = Join-Path $repo 'docs\validation\vmd-host-restore-20261024'
$driver = Join-Path $hostDir 'host-driver.py'

New-Item -ItemType Directory -Path $OutRoot -Force | Out-Null

function Get-LoadPct {
	$s = (Get-Counter '\Processor(_Total)\% Processor Time' -SampleInterval 1 -MaxSamples 2 -ErrorAction SilentlyContinue).CounterSamples
	if (-not $s) { return 0.0 }
	return [math]::Round((($s | Measure-Object -Property CookedValue -Average).Average), 1)
}
function Wait-Quiet {
	$ok = 0
	$deadline = (Get-Date).AddMinutes(10)
	while ((Get-Date) -lt $deadline) {
		if ((Get-LoadPct) -lt $QuietMaxLoadPct) { $ok++ } else { $ok = 0 }
		if ($ok -ge 3) { return $true }
		Start-Sleep -Seconds 3
	}
	return $false
}

$selected = @(
	@{ name = 'sync'; plugins = $SyncPlugins; async = '0' },
	@{ name = 'async'; plugins = $AsyncPlugins; async = '1' }
) | Where-Object { $Variants -contains $_.name }

$plan = [ordered]@{ schema = 'vmd-cpu-diff-run/1'; variants = $selected.name; out = $OutRoot; start = $StartFrame; frames = $Frames; warmup = $Warmup }
if (-not $Execute) {
	Write-Host ('CPU_DIFF_PLAN:' + ($plan | ConvertTo-Json -Depth 4 -Compress))
	exit 0
}

$rows = @()
foreach ($v in $selected) {
	if (-not (Wait-Quiet)) { Write-Warning "quiet gate not reached for $($v.name)" }
	$dir = Join-Path $OutRoot $v.name
	New-Item -ItemType Directory -Path $dir -Force | Out-Null
	$env:CMT_PHYSICS_ASYNC = $v.async
	& pwsh -NoProfile -File (Join-Path $hostDir 'launch-host.ps1') -Execute -OutRoot $dir -ModulePath $v.plugins -Port $Port -PrefsPath $PrefsPath -CinemaExe $CinemaExe | Out-Host
	if ($LASTEXITCODE -ne 0) { throw "launch failed for $($v.name)" }
	$identity = Join-Path $dir 'host-identity.json'
	try {
		# 不调 new-scene：t58 观察到该步偶发 transport_timeout（宿主启动后弹窗/恢复对话框类）。
		# 启动自带的空文档足以承载导入，且与计时轮的做法一致。
		& python $driver import --pmx $PmxPath --vmd $VmdPath | Out-Host
		if ($LASTEXITCODE -ne 0) { throw "import failed for $($v.name)" }
		& python $driver import-motion --vmd $VmdPath | Out-Host
		if ($LASTEXITCODE -ne 0) { throw "import-motion failed for $($v.name)" }
		& python $driver set-mode --mode anim | Out-Host
		if ($LASTEXITCODE -ne 0) { throw "set-mode failed for $($v.name)" }
		& python $driver physics --enabled on | Out-Host
		if ($LASTEXITCODE -ne 0) { throw "physics failed for $($v.name)" }
		$out = Join-Path $dir 'cpu-diff.json'
		& python (Join-Path $PSScriptRoot 'worker-cpu-diff.py') --label $v.name --start $StartFrame --frames $Frames --warmup $Warmup --out $out | Out-Host
		if ($LASTEXITCODE -ne 0) { throw "cpu diff failed for $($v.name)" }
		$rows += (Get-Content $out -Raw | ConvertFrom-Json)
	}
	finally {
		& pwsh -NoProfile -File (Join-Path $hostDir 'stop-host.ps1') -Execute -IdentityPath $identity -OutRoot $dir -StopTimeoutSeconds 20 | Out-Host
		$env:CMT_PHYSICS_ASYNC = $null
	}
}

$summary = [ordered]@{ schema = 'vmd-cpu-diff/1'; generated_at = (Get-Date).ToString('o'); results = $rows }
$summary | ConvertTo-Json -Depth 6 | Set-Content (Join-Path $OutRoot 'cpu-diff-summary.json') -Encoding utf8

$sync = $rows | Where-Object label -EQ 'sync' | Select-Object -First 1
$async = $rows | Where-Object label -EQ 'async' | Select-Object -First 1
if ($sync -and $async) {
	Write-Host ('CPU_DIFF_RESULT:' + ([ordered]@{
		sync_wall_ms_per_frame = $sync.wall_ms_per_frame
		async_wall_ms_per_frame = $async.wall_ms_per_frame
		sync_cpu_ms_per_frame = $sync.process_cpu_ms_per_frame
		async_cpu_ms_per_frame = $async.process_cpu_ms_per_frame
		cpu_ratio_async_over_sync = [math]::Round($async.process_cpu_ms_per_frame / $sync.process_cpu_ms_per_frame, 4)
		wall_ratio_async_over_sync = [math]::Round($async.wall_ms_per_frame / $sync.wall_ms_per_frame, 4)
	} | ConvertTo-Json -Compress))
}
exit 0



# 同步模式子步档位（substeps = 3 / 2 / 1）计时：单次宿主会话内改 MODEL_PHYSICS_SUBSTEPS 后测 on-median。
# 用途：回答「B（精度档位）单独够不够把 34 ms 压到 16.7 ms 内」，供默认开关决策。
# 只读产品树：宿主用隔离工件目录，参数只改内存里的场景对象。
param(
	[string]$PluginsPath = 'S:\tmp\cmt_vmd_profile_20261019\p3b\sync\plugins',
	[string]$OutRoot = 'S:\tmp\cmt_vmd_profile_20261019\p3b\substeps',
	[string]$Steps = '3,2,1',
	[int]$StartFrame = 560,
	[int]$Frames = 30,
	[int]$Warmup = 15,
	[int]$MaxLoadPct = 30,
	[int]$QuietMaxLoadPct = 20,
	[string]$CinemaExe = 'C:\Program Files\Maxon Cinema 4D 2027\Cinema 4D.exe',
	[string]$PrefsPath = 'S:\tmp\cmt_vmd_profile_20261019\host_profile',
	[int]$Port = 5557,
	[string]$PmxPath = 'C:\pmx\白银之城—阿芙2.0\阿芙2.0.pmx',
	[string]$VmdPath = 'C:\vmd\Stay Tonight Heaven Lee Ver. 动作.vmd',
	[switch]$Execute
)

$ErrorActionPreference = 'Stop'
$repo = Split-Path -Parent (Split-Path -Parent (Split-Path -Parent $PSScriptRoot))
$hostDir = Join-Path $repo 'docs\validation\vmd-host-restore-20261024'
$driver = Join-Path $hostDir 'host-driver.py'
$launch = Join-Path $hostDir 'launch-host.ps1'
$stop = Join-Path $hostDir 'stop-host.ps1'

New-Item -ItemType Directory -Path $OutRoot -Force | Out-Null

function Get-LoadPct {
	$sample = (Get-Counter '\Processor(_Total)\% Processor Time' -SampleInterval 1 -MaxSamples 2 -ErrorAction SilentlyContinue).CounterSamples
	if (-not $sample) { return 0.0 }
	return [math]::Round((($sample | Measure-Object -Property CookedValue -Average).Average), 1)
}

function Wait-Quiet {
	$ok = 0
	$deadline = (Get-Date).AddMinutes(10)
	while ((Get-Date) -lt $deadline) {
		$load = Get-LoadPct
		if ($load -lt $QuietMaxLoadPct) { $ok++ } else { $ok = 0 }
		if ($ok -ge 3) { return $true }
		Start-Sleep -Seconds 3
	}
	return $false
}

$plan = [ordered]@{
	schema = 'vmd-substeps-ab-run/1'
	plugins = $PluginsPath
	plugin_sha256 = (Get-FileHash (Join-Path $PluginsPath 'mmdtool\mmdtool.xdl64') -Algorithm SHA256).Hash.ToLower()
	steps = $Steps
	start = $StartFrame; frames = $Frames; warmup = $Warmup
	out = $OutRoot
}
if (-not $Execute) {
	Write-Host ('SUBSTEPS_PLAN:' + ($plan | ConvertTo-Json -Depth 4 -Compress))
	exit 0
}

if (-not (Wait-Quiet)) { Write-Warning 'quiet gate not reached; continuing' }

$row = Join-Path $OutRoot 'host'
New-Item -ItemType Directory -Path $row -Force | Out-Null
& pwsh -NoProfile -File $launch -Execute -OutRoot $row -ModulePath $PluginsPath -Port $Port -PrefsPath $PrefsPath -CinemaExe $CinemaExe | Out-Host
if ($LASTEXITCODE -ne 0) { throw "launch failed exit=$LASTEXITCODE" }
$identity = Join-Path $row 'host-identity.json'

try {
	& python $driver new-scene 2>&1 | Select-String 'DRIVER_RESULT' | ForEach-Object { $_.Line }
	& python $driver import --pmx $PmxPath --vmd $VmdPath 2>&1 | Select-String 'DRIVER_RESULT' | ForEach-Object { $_.Line }
	& python $driver import-motion --vmd $VmdPath 2>&1 | Select-String 'DRIVER_RESULT' | ForEach-Object { $_.Line }
	& python $driver set-mode --mode anim 2>&1 | Select-String 'DRIVER_RESULT' | ForEach-Object { $_.Line }
	& python $driver physics --enabled on 2>&1 | Select-String 'DRIVER_RESULT' | ForEach-Object { $_.Line }

	$outJson = Join-Path $OutRoot 'substeps.json'
	& python (Join-Path $PSScriptRoot 'substeps-probe.py') --steps $Steps --start $StartFrame --frames $Frames --warmup $Warmup --out $outJson | Out-Host
	if ($LASTEXITCODE -ne 0) { throw "substeps probe failed exit=$LASTEXITCODE" }
}
finally {
	& pwsh -NoProfile -File $stop -Execute -IdentityPath $identity -OutRoot $row -StopTimeoutSeconds 20 | Out-Host
}

$data = Get-Content (Join-Path $OutRoot 'substeps.json') -Raw | ConvertFrom-Json
$summary = [ordered]@{ schema = 'vmd-substeps-ab/1'; plan = $plan; results = $data.results; finished_at = (Get-Date).ToString('o') }
$summary | ConvertTo-Json -Depth 6 | Set-Content (Join-Path $OutRoot 'run-summary.json') -Encoding utf8

$best = $data.results | Sort-Object median_ms | Select-Object -First 1
Write-Host ('SUBSTEPS_AB_RESULT:' + ([ordered]@{
	best_substeps = $best.requested_substeps
	best_median_ms = [math]::Round($best.median_ms, 3)
	rows = @($data.results | ForEach-Object { [ordered]@{ substeps = $_.requested_substeps; median_ms = [math]::Round($_.median_ms, 3); p95_ms = [math]::Round($_.p95_ms, 3) } })
} | ConvertTo-Json -Depth 4 -Compress))
exit 0

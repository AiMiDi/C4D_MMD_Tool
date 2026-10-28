# t52 诊断采样：单次 launch、短窗口，抓 P3 async 写回链路（flush/consume/apply/mismatch/applied_frame）
# 不修改产品树；插件来自隔离构建 S:\tmp\cmt_vmd_profile_20261019\p3diag-build。
param(
	[string]$OutRoot = 'S:\tmp\cmt_vmd_profile_20261019\p3diag-run',
	[string]$PluginsPath = 'S:\tmp\cmt_vmd_profile_20261019\p3diag-build\bin\Release\plugins',
	[string]$PmxPath = 'C:\pmx\白银之城—阿芙2.0\阿芙2.0.pmx',
	[string]$VmdPath = 'C:\vmd\Stay Tonight Heaven Lee Ver. 动作.vmd',
	[int]$StartFrame = 539,
	[int]$EndFrame = 560,
	[switch]$Execute
)
$ErrorActionPreference = 'Stop'
$repo = Split-Path -Parent (Split-Path -Parent (Split-Path -Parent $PSScriptRoot))
$restore = Join-Path $repo 'docs\validation\vmd-host-restore-20261024'
$driver = Join-Path $restore 'host-driver.py'
$launch = Join-Path $restore 'launch-host.ps1'
$stop = Join-Path $restore 'stop-host.ps1'
$probe = Join-Path $PSScriptRoot 'probe-rigid.py'
$python = (Get-Command python).Source

$plan = [ordered]@{
	schema = 'vmd-diag-p3-sample/1'
	out_root = $OutRoot
	plugins_path = $PluginsPath
	frames = "$StartFrame-$EndFrame"
	async = 'CMT_PHYSICS_ASYNC=1'
	pipeline = 'CMT_PHYSICS_PIPELINE=(unset, P3 default seam path)'
	diag_log_env = 'CMT_ASYNC_DIAG_LOG'
	execute = [bool]$Execute
}
if (-not $Execute) { 'DIAG_SAMPLE_PLAN:' + ($plan | ConvertTo-Json -Compress); exit 0 }

if (Test-Path $OutRoot) { throw "out_root_exists: $OutRoot" }
New-Item -ItemType Directory -Path $OutRoot -Force | Out-Null
$logs = Join-Path $OutRoot 'logs'
New-Item -ItemType Directory -Path $logs -Force | Out-Null
$plan | ConvertTo-Json -Depth 5 | Set-Content -Path (Join-Path $OutRoot 'plan.json') -Encoding utf8

$diagLog = Join-Path $OutRoot 'async-diag.log'
$env:CMT_PHYSICS_ASYNC = '1'
Remove-Item Env:CMT_PHYSICS_PIPELINE -ErrorAction SilentlyContinue
$env:CMT_ASYNC_DIAG_LOG = $diagLog

function Step([string]$name, [scriptblock]$body) {
	$sw = [Diagnostics.Stopwatch]::StartNew()
	try { & $body; $sw.Stop(); 'STEP OK   {0} {1:n1}s' -f $name, $sw.Elapsed.TotalSeconds }
	catch { $sw.Stop(); 'STEP FAIL {0} {1:n1}s :: {2}' -f $name, $sw.Elapsed.TotalSeconds, $_.Exception.Message; throw }
}

$identity = $null
$sw = [Diagnostics.Stopwatch]::StartNew()
try {
	Step 'launch' { & pwsh -NoProfile -File $launch -Execute -OutRoot (Join-Path $OutRoot 'host') -ModulePath $PluginsPath | Out-Null }
	$identity = Get-Content (Join-Path $OutRoot 'host\host-identity.json') -Raw | ConvertFrom-Json
	'IDENTITY pid={0} ticks={1} module={2}' -f $identity.host.pid, $identity.host.start_ticks_utc, $identity.modules.mmdtool_loaded.sha256

	Step 'scene' {
		& $python $driver new-scene 2>&1 | Tee-Object -FilePath (Join-Path $logs 'driver-new-scene.log') | Out-Null
		& $python $driver import --pmx $PmxPath --vmd $VmdPath 2>&1 | Tee-Object -FilePath (Join-Path $logs 'driver-import-pmx.log') | Out-Null
		& $python $driver import-motion --vmd $VmdPath 2>&1 | Tee-Object -FilePath (Join-Path $logs 'driver-import-motion.log') | Out-Null
		& $python $driver set-mode --mode anim 2>&1 | Tee-Object -FilePath (Join-Path $logs 'driver-set-mode.log') | Out-Null
		& $python $driver physics --enabled on 2>&1 | Tee-Object -FilePath (Join-Path $logs 'driver-physics-on.log') | Out-Null
	}

	Step 'probe' {
		& $python $probe --frames '540,560' --out (Join-Path $OutRoot 'probe.json') --enable-rigid-display 2>&1 |
			Tee-Object -FilePath (Join-Path $logs 'probe.log') | Out-Null
		if ($LASTEXITCODE -ne 0) { Write-Warning "probe_exit=$LASTEXITCODE (non-fatal: diag 采集不依赖 probe)" }
	}

	# 关键：短窗口逐帧求值，让 Step/Consume/Apply 链路跑起来
	Step 'step-frames' {
		$code = @"
import c4d, json
doc = c4d.documents.GetActiveDocument()
out = []
for frame in range($StartFrame, $EndFrame + 1):
    doc.SetTime(c4d.BaseTime(float(frame), 30.0))
    doc.ExecutePasses(None, True, True, True, c4d.EXECUTIONFLAGS_PASS_ALL)
print(json.dumps({"stepped": [$StartFrame, $EndFrame]}), flush=True)
"@
		$tmp = Join-Path $OutRoot 'step-frames.py'
		Set-Content -Path $tmp -Value $code -Encoding utf8
		& $python (Join-Path $PSScriptRoot 'diag-exec.py') --file $tmp 2>&1 | Tee-Object -FilePath (Join-Path $logs 'driver-step.log') | Out-Null
	}

	# 触发 ResetStandalonePhysics → ShutdownStandaloneAsyncPhysics → stats final
	# 交互边界触发 FlushStandaloneAsyncPhysics（模式来回切换 = 动画读路径的 flush 点）
	Step 'flush-bounce' {
		& $python $driver set-mode --mode edit 2>&1 | Tee-Object -FilePath (Join-Path $logs 'driver-mode-edit.log') | Out-Null
		& $python $driver set-mode --mode anim 2>&1 | Tee-Object -FilePath (Join-Path $logs 'driver-mode-anim.log') | Out-Null
	}

	Step 'force-reset' {
		& $python $driver physics --enabled off 2>&1 | Tee-Object -FilePath (Join-Path $logs 'driver-physics-off.log') | Out-Null
	}
}
finally {
	$sw.Stop()
	try {
		Step 'stop' { & pwsh -NoProfile -File $stop -Execute -IdentityPath (Join-Path $OutRoot 'host\host-identity.json') -OutRoot (Join-Path $OutRoot 'host') | Out-Null }
	}
	catch { 'STEP FAIL stop :: ' + $_.Exception.Message }
	'ELAPSED {0:n1}s' -f $sw.Elapsed.TotalSeconds
}

# 汇总
$lines = if (Test-Path $diagLog) { Get-Content $diagLog } else { @() }
$summary = [ordered]@{
	schema = 'vmd-diag-p3-summary/1'
	diag_lines = $lines.Count
	events = @{}
	flush_reason = @{}
}
foreach ($line in $lines) {
	if ($line -notmatch '^DIAG (\S+) (.*)$') { continue }
	$tag = $Matches[1]
	$summary.events[$tag] = 1 + [int]($summary.events[$tag])
	if ($tag -eq 'flush_reason') {
		$reason = switch ([int](($Matches[2] -split ' ')[0])) { 1 { 'not_active' } 2 { 'already_current' } 3 { 'ok' } 4 { 'timeout' } default { 'unknown' } }
		$summary.flush_reason[$reason] = 1 + [int]($summary.flush_reason[$reason])
	}
}
$summary | ConvertTo-Json -Depth 5 | Set-Content -Path (Join-Path $OutRoot 'summary.json') -Encoding utf8
'DIAG_SAMPLE_RESULT:' + ($summary | ConvertTo-Json -Compress)

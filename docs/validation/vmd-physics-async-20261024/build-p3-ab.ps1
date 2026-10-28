# P3 异步物理：隔离 worktree 构建（sync 基线 + async 候选），产品树零写入。
# 用法：pwsh -NoProfile -File docs\validation\vmd-physics-async-20261024\build-p3-ab.ps1
param(
	[string]$Src = 'S:\tmp\cmt_vmd_profile_20261019\p3-src',
	[string]$WorkRoot = 'S:\tmp\cmt_vmd_profile_20261019\p3',
	[string]$Patch = 'C:\code\C4D_MMD_Tool\.dsh-switchman\vmd-perf-20261024\candidate-async-p3\candidate-async-p3.patch',
	[string]$PatchShaPrefix = '74788a62',
	[string]$Repo = 'C:\code\C4D_MMD_Tool',
	[int]$Parallel = 0,          # >0 时给 cmake --build 传 --parallel N（C1001 内部编译器错误多由并行吃满内存触发）
	[int]$BuildRetries = 1,      # 构建失败后的重试次数（C1001 属瞬时资源问题，重试通常可过）
	[switch]$SkipBaseline,
	[switch]$SkipAsync
)

$ErrorActionPreference = 'Stop'
$results = [ordered]@{ schema = 'vmd-p3-build/1'; started_at = (Get-Date).ToString('o'); steps = @() }

function Add-Step {
	param([string]$Name, [string]$Status, [hashtable]$Data = @{})
	$entry = [ordered]@{ name = $Name; status = $Status; at = (Get-Date).ToString('o') }
	foreach ($k in $Data.Keys) { $entry[$k] = $Data[$k] }
	$script:results.steps += $entry
	$line = "STEP {0} {1}" -f $Status.ToUpper(), $Name
	foreach ($k in $Data.Keys) { $line += " | $k=$($Data[$k])" }
	Write-Host $line
}

function Get-Sha256([string]$Path) { (Get-FileHash -LiteralPath $Path -Algorithm SHA256).Hash.ToLower() }

function Test-ProfilingMarker([string]$Path) {
	# 与 cmake/check_profiling_disabled.cmake 一致：二进制里出现 ASCII "CMT_RUNTIME_PROFILING=1" 即视为插桩版
	$bytes = [IO.File]::ReadAllBytes($Path)
	$needle = [Text.Encoding]::ASCII.GetBytes('CMT_RUNTIME_PROFILING=1')
	$last = $bytes.Length - $needle.Length
	for ($i = 0; $i -le $last; $i++) {
		if ($bytes[$i] -ne $needle[0]) { continue }
		$ok = $true
		for ($j = 1; $j -lt $needle.Length; $j++) { if ($bytes[$i + $j] -ne $needle[$j]) { $ok = $false; break } }
		if ($ok) { return $true }
	}
	return $false
}

function Invoke-Build([string]$BuildDir, [string]$Tag) {
	$cfgArgs = @('-S', (Join-Path $Src 'sdk_2027'), '-B', $BuildDir, '-G', 'Visual Studio 18 2026', '-A', 'x64', '-T', 'v143', '-DCMT_ENABLE_RUNTIME_PROFILING:BOOL=OFF')
	$sw = [Diagnostics.Stopwatch]::StartNew()
	& cmake @cfgArgs 2>&1 | Out-File -Encoding utf8 (Join-Path $WorkRoot "configure-$Tag.log")
	$cfgExit = $LASTEXITCODE
	$cfgElapsed = [math]::Round($sw.Elapsed.TotalSeconds, 1)
	Add-Step "configure-$Tag" 'ok' @{ exit = $cfgExit; seconds = $cfgElapsed; cmd = ('cmake ' + ($cfgArgs -join ' ')) }
	if ($cfgExit -ne 0) { throw "configure failed for $Tag" }

	$cache = Join-Path $BuildDir 'CMakeCache.txt'
	$profLine = (Select-String -Path $cache -Pattern '^CMT_ENABLE_RUNTIME_PROFILING:' | Select-Object -First 1).Line
	Add-Step "cache-$Tag" 'ok' @{ line = $profLine }

	$buildArgs = @('--build', $BuildDir, '--config', 'Release', '--target', 'mmdtool')
	if ($Parallel -gt 0) { $buildArgs += @('--parallel', "$Parallel") }
	$bExit = 1
	$bElapsed = 0
	$attempt = 0
	while ($attempt -le $BuildRetries) {
		$attempt++
		$sw.Restart()
		& cmake @buildArgs 2>&1 | Out-File -Encoding utf8 (Join-Path $WorkRoot "build-$Tag.log")
		$bExit = $LASTEXITCODE
		$bElapsed = [math]::Round($sw.Elapsed.TotalSeconds, 1)
		Add-Step "build-$Tag" $(if ($bExit -eq 0) { 'ok' } else { 'failed' }) @{ exit = $bExit; seconds = $bElapsed; attempt = $attempt; parallel = $Parallel }
		if ($bExit -eq 0) { break }
	}
	if ($bExit -ne 0) { throw "build failed for $Tag" }

	$artifact = Join-Path $BuildDir 'bin\Release\plugins\mmdtool\mmdtool.xdl64'
	if (-not (Test-Path $artifact)) { throw "artifact missing for $Tag" }
	$size = (Get-Item $artifact).Length
	$sha = Get-Sha256 $artifact
	$marker = Test-ProfilingMarker $artifact
	$dest = Join-Path $WorkRoot "$Tag\plugins"
	if (Test-Path (Join-Path $WorkRoot $Tag)) { Remove-Item (Join-Path $WorkRoot $Tag) -Recurse -Force }
	New-Item -ItemType Directory -Path $dest -Force | Out-Null
	& robocopy (Join-Path $BuildDir 'bin\Release\plugins') $dest /MIR /NFL /NDL /NJH /NJS /R:1 /W:1 | Out-Null
	$copied = Join-Path $dest 'mmdtool\mmdtool.xdl64'
	Add-Step "artifact-$Tag" 'ok' @{
		path = $copied; size_bytes = $size; sha256 = $sha; profiling_marker = $marker
		plugins_root = $dest; build_dir = $BuildDir
	}
	if ($marker) { throw "profiling marker present in $Tag artifact" }
	return [ordered]@{ path = $copied; size_bytes = $size; sha256 = $sha; plugins_root = $dest }
}

New-Item -ItemType Directory -Path $WorkRoot -Force | Out-Null

# 1) patch 身份
$patchSha = Get-Sha256 $Patch
Add-Step 'patch-identity' 'ok' @{ sha256 = $patchSha; size_bytes = (Get-Item $Patch).Length }
if (-not $patchSha.StartsWith($PatchShaPrefix)) { throw "patch sha mismatch: $patchSha" }

# 2) 产品树基线（零写入判据）
$productStatus = @(& git -C $Repo status --porcelain --ignore-submodules -- source res sdk_2026 sdk_2027 dependency | Where-Object { $_ -notmatch '^\?\?' })
Add-Step 'product-tree-baseline' 'ok' @{ tracked_changes = $productStatus.Count }
$headBefore = (& git -C $Repo rev-parse HEAD).Trim()
$srcHead = (& git -C $Src rev-parse HEAD).Trim()
Add-Step 'worktree-head' $(if ($srcHead -eq $headBefore) { 'ok' } else { 'fail' }) @{ head = $srcHead; product_head = $headBefore }
if ($srcHead -ne $headBefore) { throw "worktree HEAD mismatch" }

# 3) sync 基线（未打补丁）
$sync = $null
if (-not $SkipBaseline) {
	$sync = Invoke-Build (Join-Path $WorkRoot 'build-sync') 'sync'
}

# 4) 应用补丁（仅 worktree）
& git -C $Src apply --check $Patch 2>&1 | Out-Null
$checkExit = $LASTEXITCODE
Add-Step 'patch-apply-check' 'ok' @{ exit = $checkExit }
if ($checkExit -ne 0) { throw "git apply --check failed" }
& git -C $Src apply $Patch 2>&1 | Out-Null
$applyExit = $LASTEXITCODE
Add-Step 'patch-apply' 'ok' @{ exit = $applyExit }
if ($applyExit -ne 0) { throw "git apply failed" }
$diffStat = (& git -C $Src diff --stat | Select-Object -Last 1)
Add-Step 'patch-diffstat' 'ok' @{ line = $diffStat }

# 5) async 候选（必须 re-configure：patch 新增 .cpp 需被 CMake 收录）
$async = $null
if (-not $SkipAsync) {
	$async = Invoke-Build (Join-Path $WorkRoot 'build-async') 'async'
}

# 6) 两版必须不同
if ($sync -and $async) {
	$same = ($sync.sha256 -eq $async.sha256)
	Add-Step 'artifacts-differ' $(if ($same) { 'fail' } else { 'ok' }) @{ sync_sha = $sync.sha256; async_sha = $async.sha256 }
	if ($same) { throw "sync and async artifacts are identical" }
}

# 7) 产品树零写入
$afterStatus = @(& git -C $Repo status --porcelain --ignore-submodules -- source res sdk_2026 sdk_2027 dependency | Where-Object { $_ -notmatch '^\?\?' })
$headAfter = (& git -C $Repo rev-parse HEAD).Trim()
Add-Step 'product-tree-untouched' $(if ($afterStatus.Count -eq 0 -and $headAfter -eq $headBefore) { 'ok' } else { 'fail' }) @{
	tracked_changes = $afterStatus.Count; head = $headAfter
}

$results.sync = $sync
$results.async = $async
$results.finished_at = (Get-Date).ToString('o')
$results | ConvertTo-Json -Depth 8 | Set-Content -Path (Join-Path $WorkRoot 'build-summary.json') -Encoding utf8
# 同名步骤可能因重试出现多次（build-<Tag> failed → ok）：只按最后一次状态判失败
$lastByName = [ordered]@{}
foreach ($s in $results.steps) { $lastByName[$s.name] = $s.status }
$failures = @($lastByName.Keys | Where-Object { $lastByName[$_] -ne 'ok' })
Write-Host ("BUILD_P3 " + $(if ($failures.Count -eq 0) { 'OK' } else { 'FAILED' }))
if ($sync) { Write-Host ("SYNC  " + $sync.sha256 + " " + $sync.size_bytes + " B " + $sync.path) }
if ($async) { Write-Host ("ASYNC " + $async.sha256 + " " + $async.size_bytes + " B " + $async.path) }
if ($failures.Count -ne 0) { exit 1 }
exit 0

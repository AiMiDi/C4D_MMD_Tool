# t58 构建产物核验：两版 xdl64 存在、sha/大小符合本轮构建、无 profiling 标记、产品树零 tracked 改动。
param(
	[string]$SyncXdl = 'S:\tmp\cmt_vmd_profile_20261019\p3b\sync\plugins\mmdtool\mmdtool.xdl64',
	[string]$AsyncXdl = 'S:\tmp\cmt_vmd_profile_20261019\p3b\async\plugins\mmdtool\mmdtool.xdl64',
	[string]$SyncSha = '096ca542832120a8c95ed6f0e8f687c0a11195420fd80913988b608da22d9008',
	[string]$AsyncSha = 'bf8afb06c6142b1e1750a63e2c694b061a7ae17290297727b8086e526e234b02',
	[string]$BuildSummary = 'S:\tmp\cmt_vmd_profile_20261019\p3b\build-summary.json'
)

$ErrorActionPreference = 'Stop'
$repo = Split-Path -Parent (Split-Path -Parent (Split-Path -Parent $PSScriptRoot))
$failures = 0
function Check($name, $ok, $detail) {
	if ($ok) { Write-Host ("[ok]   {0}  {1}" -f $name, $detail) }
	else { Write-Host ("[FAIL] {0}  {1}" -f $name, $detail); $script:failures++ }
}

foreach ($pair in @(@{ n = 'sync'; p = $SyncXdl; sha = $SyncSha }, @{ n = 'async'; p = $AsyncXdl; sha = $AsyncSha })) {
	$exists = Test-Path $pair.p
	Check "artifact_$($pair.n)_exists" $exists $pair.p
	if (-not $exists) { continue }
	$sha = (Get-FileHash $pair.p -Algorithm SHA256).Hash.ToLower()
	$size = (Get-Item $pair.p).Length
	Check "artifact_$($pair.n)_sha" ($sha -eq $pair.sha) "$sha size=$size"
	$bytes = [System.IO.File]::ReadAllBytes($pair.p)
	$text = [System.Text.Encoding]::ASCII.GetString($bytes)
	Check "artifact_$($pair.n)_no_profiling_marker" (-not $text.Contains('CMT_RUNTIME_PROFILING=1')) 'marker=absent'
}

Check 'artifacts_differ' ($SyncSha -ne $AsyncSha) "sync=$($SyncSha.Substring(0,8)) async=$($AsyncSha.Substring(0,8))"

if (Test-Path $BuildSummary) {
	$b = Get-Content $BuildSummary -Raw | ConvertFrom-Json
	$cacheOff = @($b.steps | Where-Object { $_.name -like 'cache-*' -and $_.line -like '*CMT_ENABLE_RUNTIME_PROFILING:BOOL=OFF*' }).Count -ge 2
	Check 'build_cache_profiling_off' $cacheOff 'cache-sync/cache-async 均为 OFF'
	$patched = $b.steps[0].sha256
	Check 'build_patch_bound' ($patched.StartsWith('6eb55a37')) $patched
} else {
	Check 'build_summary_present' $false $BuildSummary
}

$status = @(& git -C $repo status --porcelain --ignore-submodules -- source res sdk_2026 sdk_2027 dependency | Where-Object { $_ -notmatch '^\?\?' })
Check 'product_tree_tracked_zero' ($status.Count -eq 0) "tracked_changes=$($status.Count)"

$c4d = @(Get-CimInstance Win32_Process -Filter "Name='Cinema 4D.exe'" -ErrorAction SilentlyContinue).Count
$port = @(Get-NetTCPConnection -State Listen -LocalPort 5557 -ErrorAction SilentlyContinue).Count
Check 'host_clean' ($c4d -eq 0 -and $port -eq 0) "c4d=$c4d port5557=$port"

if ($failures -eq 0) { Write-Host 'ARTIFACTS_OK'; exit 0 }
Write-Host "ARTIFACTS_FAILED failures=$failures"
exit 1

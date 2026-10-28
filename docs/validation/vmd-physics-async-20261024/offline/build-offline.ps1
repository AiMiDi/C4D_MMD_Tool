param(
	[string]$Source = 'C:\code\C4D_MMD_Tool\docs\validation\vmd-physics-async-20261024\offline\async-world-divergence.cpp',
	[string]$OutDir = 'S:\tmp\cmt_vmd_profile_20261019\physics-async\offline'
)

$ErrorActionPreference = 'Stop'
$repo = 'C:\code\C4D_MMD_Tool'
New-Item -ItemType Directory -Force -Path $OutDir | Out-Null

$vcvars = 'C:\Program Files\Microsoft Visual Studio\18\Community\VC\Auxiliary\Build\vcvars64.bat'
$envBat = Join-Path $OutDir 'env.bat'
@"
@call "$vcvars" >nul 2>&1
@set
"@ | Set-Content -Path $envBat -Encoding ASCII

$lines = & cmd /c "`"$envBat`""
$found = 0
foreach ($line in $lines) {
	if ($line -match '^([A-Za-z_][A-Za-z0-9_]*)=(.*)$') {
		$name = $Matches[1]
		if ($name -in @('PATH','INCLUDE','LIB','LIBPATH')) {
			Set-Item -Path ("Env:" + $name) -Value $Matches[2]
			$found++
		}
	}
}
if ($found -lt 2) { throw "vcvars import failed (found=$found)" }

$includes = @(
	(Join-Path $repo 'dependency\libMMD\src'),
	(Join-Path $repo 'dependency\libMMD\external\eigen'),
	(Join-Path $repo 'dependency\bullet3\src')
)
$libs = @(
	(Join-Path $repo '_build_msvc\cmt_deps_prebuilt\lib\libMMD.lib'),
	(Join-Path $repo '_build_msvc\cmt_deps_prebuilt\lib\BulletDynamics.lib'),
	(Join-Path $repo '_build_msvc\cmt_deps_prebuilt\lib\BulletCollision.lib'),
	(Join-Path $repo '_build_msvc\cmt_deps_prebuilt\lib\LinearMath.lib'),
	(Join-Path $repo '_build_msvc\cmt_deps_prebuilt\lib\Bullet3Common.lib')
)
foreach ($lib in $libs) { if (-not (Test-Path $lib)) { throw "missing lib: $lib" } }

$exe = Join-Path $OutDir 'async-world-divergence.exe'
$args = @('/nologo', '/std:c++20', '/O2', '/MD', '/EHsc', '/bigobj', '/utf-8', '/W3')
foreach ($inc in $includes) { $args += "/I$inc" }
$args += $Source
$args += '/Fe:' + $exe
$args += '/link'
foreach ($lib in $libs) { $args += $lib }

Write-Host "cl $($args -join ' ')"
& cl @args
$code = $LASTEXITCODE
Write-Host "CL_EXIT=$code"
if ($code -ne 0) { exit $code }
if (-not (Test-Path $exe)) { throw "no exe produced" }
Write-Host ("EXE {0} {1} B" -f $exe, (Get-Item $exe).Length)
exit 0

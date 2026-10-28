# 编译并运行 P4 等价性夹具（真实 libMMD + 真实 PMX 刚体 + 真实反射路径）
param(
    [switch]$Run,
    [string]$Pmx = "C:\pmx\白银之城—阿芙2.0\阿芙2.0.pmx"
)

$ErrorActionPreference = 'Stop'

$Here = Split-Path -Parent $MyInvocation.MyCommand.Path
$Repo = (Resolve-Path (Join-Path $Here '..\..\..\..')).Path
$Build = Join-Path $Here 'build'
New-Item -ItemType Directory -Force -Path $Build | Out-Null

$VcVars = 'C:\Program Files\Microsoft Visual Studio\18\Community\VC\Auxiliary\Build\vcvars64.bat'
if (-not (Test-Path $VcVars)) { throw "vcvars64.bat 不存在：$VcVars" }

$LibDir = Join-Path $Repo '_build_msvc\cmt_deps_prebuilt\lib'
$Obj = Join-Path $Build 'p4-equivalence-v2.obj'
$Exe = Join-Path $Build 'p4-equivalence-v2.exe'
$Src = Join-Path $Here 'p4-equivalence-v2.cpp'

$cl = @(
    '/nologo', '/c', '/std:c++20', '/EHsc', '/MD', '/O2', '/W4', '/utf-8', '/DBT_THREADSAFE=1', '/DLIBMMD_STATIC=1', '/DNDEBUG',
    ('"/I' + (Join-Path $Repo 'dependency\libMMD\src') + '"'),
    ('"/I' + (Join-Path $Repo 'dependency\libMMD\external\eigen') + '"'),
    ('"/I' + (Join-Path $Repo 'dependency\bullet3\src') + '"'),
    ('"' + $Src + '"'),
    ('"/Fo' + $Obj + '"')
) -join ' '

$libs = @(
    (Join-Path $LibDir 'libMMD.lib'),
    (Join-Path $LibDir 'BulletDynamics.lib'),
    (Join-Path $LibDir 'BulletCollision.lib'),
    (Join-Path $LibDir 'BulletSoftBody.lib'),
    (Join-Path $LibDir 'BulletInverseDynamics.lib'),
    (Join-Path $LibDir 'Bullet3Common.lib'),
    (Join-Path $LibDir 'LinearMath.lib')
) | ForEach-Object { '"' + $_ + '"' }

$link = @('/nologo', ('"' + $Obj + '"'), ('"/Fe' + $Exe + '"'), ('"/link' )) + $libs
$link += @('"/LIBPATH:' + $LibDir + '"')
$link = $link -join ' '

$Cmd = Join-Path $Build 'build-p4.cmd'
$Lines = @(
    '@echo off',
    ('call "' + $VcVars + '" >nul 2>&1'),
    ('cl ' + $cl),
    'if errorlevel 1 exit /b 11',
    ('cl ' + $link),
    'if errorlevel 1 exit /b 12',
    'exit /b 0'
)
Set-Content -Path $Cmd -Value $Lines -Encoding ascii

$CompileInput = Get-Content $Cmd -Raw
Write-Host ("[build] cmd=" + $Cmd)
& cmd.exe /d /c "`"$Cmd`"" 2>&1 | Tee-Object -FilePath (Join-Path $Build 'build.log') | Out-Null
$code = $LASTEXITCODE
Write-Host ("BUILD_EXIT=" + $code)
Get-Content (Join-Path $Build 'build.log') -ErrorAction SilentlyContinue |
    Where-Object { $_ -match 'error|warning' } | Select-Object -First 30

if ($code -ne 0) { exit $code }

if ($Run) {
    if (-not (Test-Path $Pmx)) { throw "PMX 不存在：$Pmx" }
    & $Exe $Pmx 2>&1 | Tee-Object -FilePath (Join-Path $Build 'run.log')
    $runCode = $LASTEXITCODE
    Write-Host ("RUN_EXIT=" + $runCode)
    exit $runCode
}

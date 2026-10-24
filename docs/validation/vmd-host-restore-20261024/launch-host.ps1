<#
.SYNOPSIS
    以私有 profile 启动 Cinema 4D（或接管一个已在运行的实例），并写 host-identity.json。

.DESCRIPTION
    默认（不加 -Execute）只打印计划，不启动任何进程，便于审阅。
    -Execute 时：
      1. 记录启动前的 Cinema 4D 进程与 5557 监听者（processes-before.json）；
      2. Start-Process 带 g_prefsPath / g_additionalModulePath 启动（或 -AdoptPid 接管既有实例）；
      3. 轮询 5557 是否由「本次 pid」监听，超时则明确失败并写失败记录；
      4. 采集 pid、UTC start ticks（十进制字符串）、exe 路径/版本、prefs 路径、命令行 hash、
         已加载 mmdtool 模块路径与 sha256，写 host-identity.json。

    只操作自己启动/接管的 pid，绝不触碰其他 Cinema 4D 进程。
#>
[CmdletBinding()]
param(
    [string]$CinemaExe = 'C:\Program Files\Maxon Cinema 4D 2027\Cinema 4D.exe',
    [string]$PrefsPath = 'S:\tmp\cmt_vmd_profile_20261019\host_profile',
    [string]$ModulePath = 'C:\code\C4D_MMD_Tool\_build_msvc\sdk_2027_v143\bin\Release\plugins',
    [int]$Port = 5557,
    [int]$ReadyTimeoutSeconds = 180,
    [string]$OutRoot = $PSScriptRoot,
    [int]$AdoptPid = 0,
    [switch]$Execute
)

Set-StrictMode -Version Latest
$ErrorActionPreference = 'Stop'

$identityPath = Join-Path $OutRoot 'host-identity.json'
$beforePath = Join-Path $OutRoot 'processes-before.json'
$logDir = Join-Path $OutRoot 'logs'
$stamp = (Get-Date).ToUniversalTime().ToString('yyyyMMddTHHmmssZ')

$prefsArg = 'g_prefsPath="' + $PrefsPath + '"'
$moduleArg = 'g_additionalModulePath="' + $ModulePath + '"'
$argumentString = $prefsArg + ' ' + $moduleArg

function Write-Log {
    param([string]$Line)
    Write-Host $Line
}

function Get-ProcessStartTicksDecimal {
    param([System.Diagnostics.Process]$Process)
    # .NET 的 Process.StartTime 与 Win32 FILETIME 同源，UTC ticks 为 100ns 计数（18 位十进制）
    return $Process.StartTime.ToUniversalTime().Ticks.ToString()
}

function Get-CimCommandLine {
    param([int]$ProcessId)
    $cim = Get-CimInstance -ClassName Win32_Process -Filter "ProcessId = $ProcessId" -ErrorAction SilentlyContinue
    if ($null -eq $cim) { return $null }
    return [string]$cim.CommandLine
}

function Get-Sha256Hex {
    param([string]$Path)
    return (Get-FileHash -LiteralPath $Path -Algorithm SHA256).Hash.ToLowerInvariant()
}

function Get-PortOwner {
    param([int]$LocalPort)
    $conn = Get-NetTCPConnection -State Listen -LocalPort $LocalPort -ErrorAction SilentlyContinue
    if ($null -eq $conn) { return @() }
    return @($conn | ForEach-Object { [int]$_.OwningProcess })
}

$plan = [ordered]@{
    mode            = if ($AdoptPid -gt 0) { 'adopt' } else { 'launch' }
    cinema_exe      = $CinemaExe
    prefs_path      = $PrefsPath
    module_path     = $ModulePath
    arguments       = $argumentString
    port            = $Port
    endpoint        = 'http://127.0.0.1:' + $Port + '/mcp'
    token_path      = Join-Path $PrefsPath 'prefs\mcp\token'
    identity_path   = $identityPath
    ready_timeout_s = $ReadyTimeoutSeconds
}

if (-not $Execute) {
    Write-Log 'PLAN_ONLY（未启动任何进程；加 -Execute 才会真正启动）'
    $plan | ConvertTo-Json -Depth 5
    exit 0
}

if (Test-Path -LiteralPath $identityPath) {
    Write-Log ('FAIL launch_identity_exists: ' + $identityPath + '（不覆盖既有身份记录，请先人工归档）')
    exit 1
}
if (-not (Test-Path -LiteralPath $CinemaExe)) {
    Write-Log ('FAIL cinema_exe_missing: ' + $CinemaExe)
    exit 1
}
if (-not (Test-Path -LiteralPath $ModulePath)) {
    Write-Log ('FAIL module_path_missing: ' + $ModulePath)
    exit 1
}
New-Item -ItemType Directory -Force -Path $logDir | Out-Null
$logPath = Join-Path $logDir ('launch-' + $stamp + '.log')
$log = [System.Collections.Generic.List[string]]::new()

function Add-Log {
    param([string]$Line)
    Write-Host $Line
    $log.Add(('[' + (Get-Date).ToString('HH:mm:ss') + '] ' + $Line))
}

# 1. 启动前快照：只用于「未触碰其他宿主进程」的证据
$otherProcesses = @(Get-Process -Name 'Cinema 4D' -ErrorAction SilentlyContinue | ForEach-Object {
    [ordered]@{ pid = $_.Id; start_local = $_.StartTime.ToString('o'); path = $_.Path }
})
$before = [ordered]@{
    schema          = 'vmd-host-processes-before/1'
    recorded_at     = (Get-Date).ToString('o')
    cinema_processes = $otherProcesses
    port            = $Port
    port_owners     = (Get-PortOwner -LocalPort $Port)
}
$before | ConvertTo-Json -Depth 5 | Set-Content -LiteralPath $beforePath -Encoding utf8
Add-Log ('processes_before=' + $beforePath + ' count=' + $otherProcesses.Count)

if ($AdoptPid -gt 0) {
    $target = Get-Process -Id $AdoptPid -ErrorAction SilentlyContinue
    if ($null -eq $target) {
        Add-Log ('FAIL adopt_pid_missing: ' + $AdoptPid)
        exit 1
    }
    if ($target.ProcessName -ne 'Cinema 4D') {
        Add-Log ('FAIL adopt_pid_not_cinema4d: ' + $target.ProcessName)
        exit 1
    }
    Add-Log ('adopting pid=' + $AdoptPid)
} else {
    $existing = @(Get-PortOwner -LocalPort $Port)
    if ($existing.Count -gt 0) {
        Add-Log ('FAIL port_already_listening: ' + $Port + ' owners=' + ($existing -join ','))
        exit 1
    }
    Add-Log ('starting ' + $CinemaExe)
    Add-Log ('arguments ' + $argumentString)
    $target = Start-Process -FilePath $CinemaExe -ArgumentList $argumentString -PassThru
    Add-Log ('started pid=' + $target.Id)
}

$sw = [Diagnostics.Stopwatch]::StartNew()
$ready = $false
while ($sw.Elapsed.TotalSeconds -lt $ReadyTimeoutSeconds) {
    if ($target.HasExited) {
        Add-Log ('FAIL host_exited_before_ready: exit_code=' + $target.ExitCode)
        break
    }
    $owners = @(Get-PortOwner -LocalPort $Port)
    if ($owners -contains $target.Id) { $ready = $true; break }
    Start-Sleep -Milliseconds 750
}
if (-not $ready) {
    if (-not $target.HasExited) {
        Add-Log ('FAIL host_ready_timeout: ' + $ReadyTimeoutSeconds + 's（端口 ' + $Port + ' 未由 pid ' + $target.Id + ' 监听）')
    }
    $failure = [ordered]@{
        schema   = 'vmd-host-launch-failure/1'
        pid      = $target.Id
        port     = $Port
        reason   = if ($target.HasExited) { 'host_exited_before_ready' } else { 'host_ready_timeout' }
        elapsed  = [math]::Round($sw.Elapsed.TotalSeconds, 3)
        log      = $logPath
    }
    $failure | ConvertTo-Json -Depth 5 | Set-Content -LiteralPath (Join-Path $OutRoot 'launch-failure.json') -Encoding utf8
    $log | Set-Content -LiteralPath $logPath -Encoding utf8
    exit 1
}
Add-Log ('ready: port=' + $Port + ' pid=' + $target.Id + ' in ' + [math]::Round($sw.Elapsed.TotalSeconds, 2) + 's')

# 2. 采集身份：tick 用十进制字符串，命令行用 Win32_Process 的原始 argv 再算 hash
$ticks = Get-ProcessStartTicksDecimal -Process $target
$commandLine = Get-CimCommandLine -ProcessId $target.Id
if ([string]::IsNullOrWhiteSpace($commandLine)) {
    Add-Log 'WARN command_line_unavailable（进程可能已退出）'
    $commandLine = ''
}
$commandLineHash = ''
if ($commandLine) {
    $bytes = [Text.Encoding]::UTF8.GetBytes($commandLine)
    $commandLineHash = [Convert]::ToHexString([Security.Cryptography.SHA256]::HashData($bytes)).ToLowerInvariant()
}

$loadedModule = $null
try {
    $target.Refresh()
    $module = $target.Modules | Where-Object { $_.ModuleName -like 'mmdtool*' } | Select-Object -First 1
    if ($module) {
        $loadedModule = [ordered]@{
            name       = $module.ModuleName
            path       = $module.FileName
            size_bytes = (Get-Item -LiteralPath $module.FileName).Length
            sha256     = Get-Sha256Hex -Path $module.FileName
        }
    }
} catch {
    Add-Log ('WARN module_enumeration_failed: ' + $_.Exception.Message)
}

$listeners = @(Get-NetTCPConnection -State Listen -OwningProcess $target.Id -ErrorAction SilentlyContinue | ForEach-Object {
    [ordered]@{ address = $_.LocalAddress; port = [int]$_.LocalPort }
})

$identity = [ordered]@{
    schema          = 'vmd-host-identity/1'
    generated_at    = (Get-Date).ToString('o')
    mode            = if ($AdoptPid -gt 0) { 'adopt' } else { 'launch' }
    host            = [ordered]@{
        pid                 = $target.Id
        start_ticks_utc     = $ticks
        start_time_local    = $target.StartTime.ToString('o')
        exe_path            = $target.Path
        exe_version         = (Get-Item -LiteralPath $target.Path).VersionInfo.FileVersion
        prefs_path          = (Join-Path $PrefsPath 'prefs')
        prefs_arg           = $prefsArg
        module_path_arg     = $moduleArg
        command_line        = $commandLine
        command_line_sha256 = $commandLineHash
        working_set_bytes   = $target.WorkingSet64
    }
    mcp             = [ordered]@{
        endpoint   = 'http://127.0.0.1:' + $Port + '/mcp'
        host       = '127.0.0.1'
        port       = $Port
        token_path = (Join-Path $PrefsPath 'prefs\mcp\token')
    }
    modules         = [ordered]@{
        mmdtool_loaded = $loadedModule
        module_path    = $ModulePath
    }
    listeners       = $listeners
    startup_seconds = [math]::Round($sw.Elapsed.TotalSeconds, 3)
    processes_before = $beforePath
    log             = $logPath
}

if (Test-Path -LiteralPath $identityPath) {
    Add-Log ('FAIL launch_identity_exists_race: ' + $identityPath)
    exit 1
}
$identity | ConvertTo-Json -Depth 6 | Set-Content -LiteralPath $identityPath -Encoding utf8
Add-Log ('identity_written=' + $identityPath)
$log | Set-Content -LiteralPath $logPath -Encoding utf8

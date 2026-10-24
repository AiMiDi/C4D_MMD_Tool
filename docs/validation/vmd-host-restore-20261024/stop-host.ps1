<#
.SYNOPSIS
    按 host-identity.json 干净关闭本次启动的 Cinema 4D，并写 cleanup.json。

.DESCRIPTION
    默认只打印计划；-Execute 时：
      1. 读 host-identity.json，校验 pid 仍存活且 UTC start ticks 与记录一致（不一致立即失败且不杀）；
      2. 优先 CloseMainWindow()，在 -StopTimeoutSeconds 内等待退出；
      3. 超时才 Stop-Process，并把 stop_forced=true 记录在案；
      4. 校验：该 pid 已退出、5557 释放、无其他 Cinema 4D 进程被牵连；
      5. 写 cleanup.json（含关闭方式、耗时、残存进程清单）。

    绝不关闭 host-identity.json 之外的任何进程。
#>
[CmdletBinding()]
param(
    [string]$IdentityPath = (Join-Path $PSScriptRoot 'host-identity.json'),
    [string]$OutRoot = $PSScriptRoot,
    [int]$StopTimeoutSeconds = 90,
    [switch]$Execute
)

Set-StrictMode -Version Latest
$ErrorActionPreference = 'Stop'

$cleanupPath = Join-Path $OutRoot 'cleanup.json'

if (-not (Test-Path -LiteralPath $IdentityPath)) {
    Write-Host ('FAIL identity_missing: ' + $IdentityPath)
    exit 1
}
$identity = Get-Content -LiteralPath $IdentityPath -Raw | ConvertFrom-Json
$pidValue = [int]$identity.host.pid
$recordedTicks = [string]$identity.host.start_ticks_utc
$port = [int]$identity.mcp.port

if (-not $Execute) {
    Write-Host 'PLAN_ONLY（未关闭任何进程；加 -Execute 才会执行）'
    [ordered]@{
        pid            = $pidValue
        start_ticks_utc = $recordedTicks
        port           = $port
        strategy       = 'CloseMainWindow 优先，超时才 Stop-Process'
        cleanup_path   = $cleanupPath
    } | ConvertTo-Json -Depth 4
    exit 0
}

if (Test-Path -LiteralPath $cleanupPath) {
    Write-Host ('FAIL cleanup_artifact_exists: ' + $cleanupPath)
    exit 1
}

$target = Get-Process -Id $pidValue -ErrorAction SilentlyContinue
if ($null -eq $target) {
    Write-Host ('INFO already_exited pid=' + $pidValue)
    [ordered]@{
        schema         = 'vmd-host-cleanup/1'
        recorded_at    = (Get-Date).ToString('o')
        pid            = $pidValue
        already_exited = $true
        port_released  = ((Get-NetTCPConnection -State Listen -LocalPort $port -ErrorAction SilentlyContinue | Measure-Object).Count -eq 0)
    } | ConvertTo-Json -Depth 5 | Set-Content -LiteralPath $cleanupPath -Encoding utf8
    exit 0
}

$liveTicks = $target.StartTime.ToUniversalTime().Ticks.ToString()
if ($liveTicks -ne $recordedTicks) {
    Write-Host ('FAIL identity_ticks_mismatch: recorded=' + $recordedTicks + ' live=' + $liveTicks + '（拒绝关闭）')
    [ordered]@{
        schema          = 'vmd-host-cleanup/1'
        recorded_at     = (Get-Date).ToString('o')
        pid             = $pidValue
        reason          = 'identity_ticks_mismatch'
        ticks_recorded  = $recordedTicks
        ticks_live      = $liveTicks
        stop_attempted  = $false
    } | ConvertTo-Json -Depth 5 | Set-Content -LiteralPath $cleanupPath -Encoding utf8
    exit 3
}

$sw = [Diagnostics.Stopwatch]::StartNew()
$method = 'CloseMainWindow'
$requested = $target.CloseMainWindow()
if (-not $requested) { $method = 'CloseMainWindow_not_requested' }

$deadline = (Get-Date).AddSeconds($StopTimeoutSeconds)
while (-not $target.HasExited -and (Get-Date) -lt $deadline) {
    Start-Sleep -Milliseconds 500
    $target.Refresh()
}
$forced = $false
if (-not $target.HasExited) {
    Write-Host ('WARN close_main_window_timeout: ' + $StopTimeoutSeconds + 's，改 Stop-Process（仅本 pid）')
    $target.Kill()
    $target.WaitForExit(15000) | Out-Null
    $forced = $true
    $method = 'Stop-Process'
}
$sw.Stop()

Start-Sleep -Milliseconds 500
$remaining = @(Get-Process -Name 'Cinema 4D' -ErrorAction SilentlyContinue | ForEach-Object {
    [ordered]@{ pid = $_.Id; start_local = $_.StartTime.ToString('o') }
})
$portStillListening = @(Get-NetTCPConnection -State Listen -LocalPort $port -ErrorAction SilentlyContinue | ForEach-Object { [int]$_.OwningProcess })

$cleanup = [ordered]@{
    schema            = 'vmd-host-cleanup/1'
    recorded_at       = (Get-Date).ToString('o')
    pid               = $pidValue
    ticks_recorded    = $recordedTicks
    ticks_live        = $liveTicks
    identity_ok       = ($liveTicks -eq $recordedTicks)
    stop_method       = $method
    stop_forced       = $forced
    stop_seconds      = [math]::Round($sw.Elapsed.TotalSeconds, 3)
    exited            = [bool]$target.HasExited
    exit_code         = if ($target.HasExited) { $target.ExitCode } else { $null }
    port              = $port
    port_released     = ($portStillListening.Count -eq 0)
    remaining_cinema_processes = $remaining
    other_processes_untouched  = ($remaining.Count -eq 0)
    identity_path     = $IdentityPath
}
$cleanup | ConvertTo-Json -Depth 6 | Set-Content -LiteralPath $cleanupPath -Encoding utf8

Write-Host ('cleanup_written=' + $cleanupPath + ' method=' + $method + ' forced=' + $forced + ' remaining=' + $remaining.Count)
if (-not $target.HasExited) { exit 1 }
if ($remaining.Count -ne 0) { exit 1 }
exit 0

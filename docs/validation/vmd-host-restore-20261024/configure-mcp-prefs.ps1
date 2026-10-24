<#
.SYNOPSIS
    把 MCP 适配器偏好（端口等）写进私有 profile 并落盘 —— 通过运行中宿主的 exec_python 执行 configure-mcp-prefs.py。

.DESCRIPTION
    Cinema 4D 的 MCP 适配器内置默认端口是 5556；历史上那套实验环境用的是 5557。
    端口存在「偏好设置 → MCP」的世界插件偏好里（profile 内的 Cinema 4D.prf），
    只改 prf 字节不可行（值不是裸 int32），所以用适配器自己的偏好容器 API 写：

        c4d.plugins.SetWorldPluginData(1070225, bc)   # 1070225 = PLUGIN_ID_PREFERENCES
        c4d.SaveWorldPreferences()

    偏好写完后必须重启 Cinema 4D 才生效（适配器在启动时绑定端口）。

    默认只打印计划；-Execute 才真正写。写前要求宿主已在跑（默认探测 5556 与 5557 两个端点）。
#>
[CmdletBinding()]
param(
    [ValidateSet('auto', '5556', '5557')]
    [string]$EndpointPort = 'auto',
    [int]$TargetPort = 5557,
    [string]$TokenPath = 'S:\tmp\cmt_vmd_profile_20261019\host_profile\prefs\mcp\token',
    [string]$OutRoot = $PSScriptRoot,
    [switch]$Execute
)

Set-StrictMode -Version Latest
$ErrorActionPreference = 'Stop'

$codePath = Join-Path $OutRoot 'configure-mcp-prefs.py'
if (-not (Test-Path -LiteralPath $codePath)) {
    Write-Host ('FAIL configure_code_missing: ' + $codePath)
    exit 1
}
if (-not (Test-Path -LiteralPath $TokenPath)) {
    Write-Host ('FAIL token_missing: ' + $TokenPath)
    exit 1
}

$candidates = if ($EndpointPort -eq 'auto') { @(5556, 5557) } else { @([int]$EndpointPort) }

if (-not $Execute) {
    Write-Host 'PLAN_ONLY（未写入任何偏好；加 -Execute 才会写）'
    [ordered]@{
        target_port = $TargetPort
        endpoint_candidates = $candidates
        token_path  = $TokenPath
        code_path   = $codePath
        note        = '写入后需重启 Cinema 4D 才生效'
    } | ConvertTo-Json -Depth 4
    exit 0
}

$token = (Get-Content -LiteralPath $TokenPath -Raw).Trim()
$code = (Get-Content -LiteralPath $codePath -Raw).Replace('__PORT__', [string]$TargetPort)

$body = @{
    jsonrpc = '2.0'
    id      = 1
    method  = 'tools/call'
    params  = @{
        name      = 'exec_python'
        arguments = @{ code = $code; timeout_seconds = 60; max_iterations = 5000000 }
    }
} | ConvertTo-Json -Depth 8

foreach ($port in $candidates) {
    $endpoint = 'http://127.0.0.1:' + $port + '/mcp'
    try {
        $response = Invoke-WebRequest -Uri $endpoint -Method Post -Body $body -TimeoutSec 60 -Proxy $null `
            -Headers @{ 'Content-Type' = 'application/json'; 'Accept' = 'application/json, text/event-stream'; 'Authorization' = 'Bearer ' + $token } -ErrorAction Stop
    } catch {
        Write-Host ('INFO endpoint_unreachable: ' + $endpoint + ' — ' + $_.Exception.Message)
        continue
    }
    $text = [string]$response.Content
    $payload = $null
    if ($text.TrimStart().StartsWith('{')) {
        $payload = $text | ConvertFrom-Json
    } else {
        foreach ($line in ($text -split "`n")) {
            if ($line.TrimStart().StartsWith('data:')) {
                $payload = ($line.TrimStart().Substring(5).Trim() | ConvertFrom-Json)
                break
            }
        }
    }
    if ($null -eq $payload) {
        Write-Host ('FAIL response_unparseable: ' + $endpoint)
        exit 1
    }
    $result = $payload.result
    # exec_python 只有在有输出时才带 stdout/stderr 字段；StrictMode 下直接取属性会抛错，必须先探测。
    $structured = if ($null -ne $result -and $result.PSObject.Properties['structuredContent']) { $result.structuredContent } else { $null }
    $stdout = if ($null -ne $structured -and $structured.PSObject.Properties['stdout']) { [string]$structured.stdout } else { '' }
    $stderr = if ($null -ne $structured -and $structured.PSObject.Properties['stderr']) { [string]$structured.stderr } else { '' }
    Write-Host ('INFO endpoint=' + $endpoint + ' isError=' + $result.isError)
    if ($stdout) { $stdout.TrimEnd().Split("`n") | ForEach-Object { Write-Host ('  ' + $_) } }
    if ($stderr) { $stderr.TrimEnd().Split("`n") | ForEach-Object { Write-Host ('  stderr | ' + $_) } }
    if ($result.isError -eq $true) { exit 1 }
    if ($stdout -match 'PREF_RESOLVED_PORT\s+(\d+)') {
        $resolved = [int]$Matches[1]
        Write-Host ('INFO resolved_port=' + $resolved + ' target=' + $TargetPort)
        if ($resolved -ne $TargetPort) { exit 1 }
    }
    exit 0
}

Write-Host 'FAIL no_reachable_endpoint（宿主未运行？先跑 launch-host.ps1 -Execute）'
exit 1

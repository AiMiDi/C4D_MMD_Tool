[CmdletBinding()]
param(
    [Parameter(Mandatory)][string]$ProjectRoot,
    [string]$InstallerPath = '',
    [switch]$CheckOnly
)

$ErrorActionPreference = 'Stop'
Set-StrictMode -Version Latest
$projectPath = [IO.Path]::GetFullPath($ProjectRoot)
$expectedPath = [IO.Path]::GetFullPath((Join-Path $projectPath 'setup/Common/installer_script.iss'))
if ([string]::IsNullOrEmpty($InstallerPath)) { $InstallerPath = $expectedPath }
$installerPathResolved = [IO.Path]::GetFullPath($InstallerPath)
if (-not $installerPathResolved.Equals($expectedPath, [StringComparison]::OrdinalIgnoreCase)) {
    throw 'Installer resource adaptation only supports setup/Common/installer_script.iss. Custom installers manage their own resource sources.'
}

$encoding = [Text.UTF8Encoding]::new($false, $true)
$content = $encoding.GetString([IO.File]::ReadAllBytes($installerPathResolved))
$oldResourcePath = '..\..\res\{#ResFolderName}\*'
$builtResourcePath = '..\..\{#SdkBuildDir}\{#SdkRootName}\bin\{#SdkBinConfig}\plugins\mmdtool\res\*'
$oldPattern = '(?m)^Source:\s*"' + [regex]::Escape($oldResourcePath) + '";'
$builtPattern = '(?m)^Source:\s*"' + [regex]::Escape($builtResourcePath) + '";'
$oldMatches = [regex]::Matches($content, $oldPattern)
$builtMatches = [regex]::Matches($content, $builtPattern)
if ($oldMatches.Count + $builtMatches.Count -ne 1) {
    throw "Expected exactly one recognized installer resource Source; found $($oldMatches.Count) old and $($builtMatches.Count) built sources. No changes made."
}
$adapted = $content
if ($oldMatches.Count -eq 1) {
    $match = $oldMatches[0]
    $replacement = $match.Value.Replace($oldResourcePath, $builtResourcePath)
    $adapted = $content.Substring(0, $match.Index) + $replacement + $content.Substring($match.Index + $match.Length)
}
$adapterPath = '..\..\{#SdkBuildDir}\{#SdkRootName}\bin\{#SdkBinConfig}\plugins\mmdtool\mcp\*'
$adapterPattern = '(?m)^Source:\s*"' + [regex]::Escape($adapterPath) + '";'
$adapterMatches = [regex]::Matches($adapted, $adapterPattern)
if ($adapterMatches.Count -gt 1) { throw 'Ambiguous MCP runtime Source entries. No changes made.' }
if ($adapterMatches.Count -eq 0) {
    # Derive destination and component guards from the recognized resource row.
    # This keeps each SDK package paired with its own built adapter files.
    $rowPattern = '(?m)^Source:\s*"' + [regex]::Escape($builtResourcePath) + '";[^\r\n]*'
    $row = [regex]::Match($adapted, $rowPattern)
    $adapterRow = $row.Value.Replace($builtResourcePath, $adapterPath).Replace('\res";', '\mcp";')
    $newline = if ($content.Contains("`r`n")) { "`r`n" } else { "`n" }
    $adapted = $adapted.Insert($row.Index + $row.Length, $newline + $adapterRow)
}
if ($adapted -ceq $content) {
    Write-Host "Installer already consumes built resources and MCP runtime: $installerPathResolved"
    return
}
if ($CheckOnly) {
    Write-Host "Installer would consume built runtime resources: $installerPathResolved"
    return
}
# Adapt the recognized resource row and add its paired MCP row. Preserve
# includes, component guards, other user edits and original line endings.
[IO.File]::WriteAllText($installerPathResolved, $adapted, $encoding)
Write-Host "Installer resource Source adapted to built output: $installerPathResolved"

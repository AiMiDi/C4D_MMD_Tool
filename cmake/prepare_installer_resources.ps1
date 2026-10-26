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
# The setup submodule is shared with older releases. Extend its recognized
# version tables here so a clean submodule checkout also packages the 2027 SDK.
$versionTables = @(
    @{ Name = 'VerArray'; Value = '2027' },
    @{ Name = 'XdlSdkRel'; Value = 'sdk_2027' },
    @{ Name = 'ResFolder'; Value = 'S24_up' }
)
$versionPattern = '(?m)^#dim VerArray\[VerCount\] \{([^}\r\n]+)\}'
$versionMatch = [regex]::Match($adapted, $versionPattern)
if (-not $versionMatch.Success) { throw 'Unrecognized installer version table. No changes made.' }
$has2027 = $versionMatch.Groups[1].Value -match "'2027'"
$expectedCount = if ($has2027) { 12 } else { 11 }
foreach ($table in $versionTables) {
    $pattern = '(?m)^#dim ' + $table.Name + '\[VerCount\] \{([^}\r\n]+)\}'
    $matches = [regex]::Matches($adapted, $pattern)
    if ($matches.Count -ne 1) { throw "Ambiguous installer table $($table.Name). No changes made." }
    $match = $matches[0]
    $entries = [regex]::Matches($match.Groups[1].Value, "'([^']+)'")
    if ($entries.Count -ne $expectedCount) { throw "Unexpected size of installer table $($table.Name). No changes made." }
    if ($has2027) {
        if ($entries[-1].Groups[1].Value -ne $table.Value) { throw 'Inconsistent 2027 installer mapping. No changes made.' }
    } else {
        $replacement = $match.Value.TrimEnd('}') + ",'$($table.Value)'}"
        $adapted = $adapted.Remove($match.Index, $match.Length).Insert($match.Index, $replacement)
    }
}
$countPattern = '(?m)^#define VerCount = ' + $expectedCount + '(?=\r?$)'
if ([regex]::Matches($adapted, $countPattern).Count -ne 1) { throw 'Unrecognized installer version count. No changes made.' }
$adapted = [regex]::Replace($adapted, $countPattern, '#define VerCount = 12')
foreach ($prefix in @('', 'C_')) {
    $index = if ($has2027) { 11 } else { 10 }
    $lastEntry = "'$prefix{#VerArray[$index]}'"
    $pattern = [regex]::Escape($lastEntry) + ' \];'
    if ([regex]::Matches($adapted, $pattern).Count -ne 1) { throw 'Unrecognized installer Pascal version mapping. No changes made.' }
    if (-not $has2027) {
        $newline = if ($content.Contains("`r`n")) { "`r`n" } else { "`n" }
        $replacement = $lastEntry + ',' + $newline + "            '$prefix{#VerArray[11]}' ];"
        $adapted = [regex]::Replace($adapted, $pattern, $replacement)
    }
}
# The year tables also need the matching registry-discovery path. Newer C4D
# installers use hashed Maxon subkeys, not a literal "Maxon Cinema 4D 2027" key.
# Keep 2023 and the R/S versions on their existing lookup paths.
$oldYearCondition = "else if (ver = '2024') or (ver = '2025') or (ver = '2026') then"
$yearCondition = 'else if StrToIntDef(ver, 0) >= 2024 then'
$oldYearMatches = [regex]::Matches($adapted, [regex]::Escape($oldYearCondition))
$yearMatches = [regex]::Matches($adapted, [regex]::Escape($yearCondition))
if ($oldYearMatches.Count + $yearMatches.Count -ne 1) {
    throw 'Unrecognized installer year-based registry lookup. No changes made.'
}
if ($oldYearMatches.Count -eq 1) {
    $adapted = $adapted.Replace($oldYearCondition, $yearCondition)
}
if ($adapted -ceq $content) {
    Write-Host "Installer already includes 2027 detection and consumes built runtime files: $installerPathResolved"
    return
}
if ($CheckOnly) {
    Write-Host "Installer would include 2027 detection and consume built runtime files: $installerPathResolved"
    return
}
# Adapt the version tables and paired runtime rows. Preserve includes,
# component guards, other user edits and original line endings.
[IO.File]::WriteAllText($installerPathResolved, $adapted, $encoding)
Write-Host "Installer adapted for 2027 detection and built runtime files: $installerPathResolved"

[CmdletBinding()]
param(
    [string]$FixtureRoot = 'S:\tmp\cmt-installer-resource-checks',
    [string]$PinnedInstallerPath = ''
)

$ErrorActionPreference = 'Stop'
Set-StrictMode -Version Latest
$repoRoot = Split-Path -Parent $PSScriptRoot
$prepare = Join-Path $repoRoot 'cmake/prepare_installer_resources.ps1'
$fixture = Join-Path ([IO.Path]::GetFullPath($FixtureRoot)) ([Guid]::NewGuid().ToString('N'))
$installer = Join-Path $fixture 'setup/Common/installer_script.iss'
New-Item -ItemType Directory -Path (Split-Path -Parent $installer) -Force | Out-Null
$oldSource = 'Source: "..\..\res\{#ResFolderName}\*"; DestDir: "{app}\res"; Flags: recursesubdirs;'
$newSource = $oldSource.Replace('..\..\res\{#ResFolderName}\*', '..\..\{#SdkBuildDir}\{#SdkRootName}\bin\{#SdkBinConfig}\plugins\mmdtool\res\*')
$encoding = [Text.UTF8Encoding]::new($false)
if ($PinnedInstallerPath) {
    $original = [IO.File]::ReadAllText([IO.Path]::GetFullPath($PinnedInstallerPath), $encoding)
} else {
    # The exact pinned submodule Source form; CI can exercise the root-only
    # adapter without initializing setup just for this fixture.
    $original = '#include "common_setup.iss"' + "`r`n" + $oldSource + "`r`n; preserve this comment`r`n"
}
[IO.File]::WriteAllText($installer, $original, $encoding)
$passed = [Collections.Generic.List[string]]::new()

function Assert-True([bool]$Condition, [string]$Message) {
    if (-not $Condition) { throw $Message }
}
function Assert-Rejected([scriptblock]$Action, [string]$Name) {
    $rejected = $false
    try { & $Action } catch { $rejected = $true }
    Assert-True $rejected "Expected rejection: $Name"
    $passed.Add($Name)
}

& $prepare -ProjectRoot $fixture -CheckOnly
Assert-True ([IO.File]::ReadAllText($installer, $encoding) -eq $original) 'Preview changed installer source'
$passed.Add('preview does not write')
& $prepare -ProjectRoot $fixture
$expected = $original.Replace('..\..\res\{#ResFolderName}\*', '..\..\{#SdkBuildDir}\{#SdkRootName}\bin\{#SdkBinConfig}\plugins\mmdtool\res\*')
$builtResourcePath = '..\..\{#SdkBuildDir}\{#SdkRootName}\bin\{#SdkBinConfig}\plugins\mmdtool\res\*'
$resourceRowPattern = '(?m)^Source:\s*"' + [regex]::Escape($builtResourcePath) + '";[^\r\n]*'
$resourceRow = [regex]::Match($expected, $resourceRowPattern).Value
Assert-True (-not [string]::IsNullOrEmpty($resourceRow)) 'Expected fixture resource Source row was not found'
$adapterRow = $resourceRow.Replace('\res\*', '\mcp\*').Replace('\res";', '\mcp";')
# The pinned installer may already contain the paired runtime row. In that
# case adaptation must preserve it rather than inventing a duplicate in the
# expected output. Keep the input's newline convention for older templates.
if (-not $expected.Contains($adapterRow)) {
    $newline = if ($expected.Contains("`r`n")) { "`r`n" } else { "`n" }
    $expected = $expected.Replace($resourceRow, $resourceRow + $newline + $adapterRow)
}
Assert-True ([IO.File]::ReadAllText($installer, $encoding) -ceq $expected) 'Adaptation changed unrelated installer content'
$passed.Add('resource Source and paired MCP runtime adapt with other bytes preserved')
$before = (Get-FileHash -LiteralPath $installer).Hash
& $prepare -ProjectRoot $fixture
Assert-True ((Get-FileHash -LiteralPath $installer).Hash -eq $before) 'Repeated adaptation is not idempotent'
$passed.Add('already adapted Source is idempotent')

[IO.File]::WriteAllText($installer, $oldSource + "`r`n" + $newSource, $encoding)
$before = (Get-FileHash -LiteralPath $installer).Hash
Assert-Rejected { & $prepare -ProjectRoot $fixture } 'ambiguous old and built resource sources rejected'
Assert-True ((Get-FileHash -LiteralPath $installer).Hash -eq $before) 'Ambiguous installer was changed'
[IO.File]::WriteAllText($installer, 'Source: "custom\resources\*";', $encoding)
Assert-Rejected { & $prepare -ProjectRoot $fixture } 'unknown Source schema rejected'
Assert-Rejected { & $prepare -ProjectRoot $fixture -InstallerPath (Join-Path $fixture 'custom.iss') } 'custom installer path rejected before reading or writing'

$receipt = [ordered]@{ count = $passed.Count; passed = $passed.ToArray(); pinnedSourceProvided = [bool]$PinnedInstallerPath; fixture = $fixture }
$receipt | ConvertTo-Json -Depth 3 | Set-Content -LiteralPath (Join-Path $fixture 'receipt.json')
$receipt | ConvertTo-Json -Depth 3

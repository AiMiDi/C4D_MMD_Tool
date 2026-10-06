[CmdletBinding()]
param([string]$FixtureRoot = 'S:\tmp\cmt-runtime-resource-checks')

$ErrorActionPreference = 'Stop'
Set-StrictMode -Version Latest
$repoRoot = Split-Path -Parent $PSScriptRoot
$syncScript = Join-Path $repoRoot 'cmake/sync_runtime_resources.ps1'
$fixture = Join-Path ([IO.Path]::GetFullPath($FixtureRoot)) ([Guid]::NewGuid().ToString('N'))
$source = Join-Path $fixture 'source'
$build = Join-Path $fixture 'build'
$destination = Join-Path $build 'plugin/res'
$defaultConfig = Join-Path $repoRoot 'res/S24_up/cmt_config.json'
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

function Sync-Resources([string]$Policy = 'reset') {
    & $syncScript -Source $source -Destination $destination -BuildRoot $build -DefaultConfig $defaultConfig -ConfigPolicy $Policy
}

New-Item -ItemType Directory -Path $source -Force | Out-Null
foreach ($child in Get-ChildItem -LiteralPath (Join-Path $repoRoot 'res/S24_up') -Force) {
    Copy-Item -LiteralPath $child.FullName -Destination $source -Recurse
}
Sync-Resources
Assert-True (Test-Path -LiteralPath (Join-Path $destination 'description/OMMDBoneManager.res')) 'Missing description in fresh output'
Assert-True (-not ((Get-Item -LiteralPath $destination).Attributes -band [IO.FileAttributes]::ReparsePoint)) 'Output must be a real directory'
$passed.Add('fresh output contains complete real resources')

$stale = Join-Path $destination 'obsolete.txt'
Set-Content -LiteralPath $stale -Value 'obsolete'
Sync-Resources
Assert-True (-not (Test-Path -LiteralPath $stale)) 'Stale output was retained'
$passed.Add('repeat sync removes stale resources')

$outputConfig = Join-Path $destination 'cmt_config.json'
Set-Content -LiteralPath $outputConfig -Value '{"fixture_setting":42}'
Sync-Resources preserve
Assert-True ((Get-Content -LiteralPath $outputConfig -Raw | ConvertFrom-Json).fixture_setting -eq 42) 'Preserve lost output preferences'
Sync-Resources reset
Assert-True ((Get-Content -LiteralPath $outputConfig -Raw).Trim() -eq (Get-Content -LiteralPath $defaultConfig -Raw).Trim()) 'Reset did not restore repository defaults'
$passed.Add('preserve and reset config policies')

$sourceConfig = Join-Path $source 'cmt_config.json'
$savedConfig = Get-Content -LiteralPath $sourceConfig -Raw
$before = (Get-FileHash -LiteralPath $outputConfig).Hash
Set-Content -LiteralPath $sourceConfig -Value '{invalid'
Assert-Rejected { Sync-Resources } 'invalid source config rejected before output replacement'
Assert-True ((Get-FileHash -LiteralPath $outputConfig).Hash -eq $before) 'Invalid config changed existing output'
Set-Content -LiteralPath $sourceConfig -Value $savedConfig

# Simulate the old SDK runtime junction. Its target is a source fixture; hashing
# every file detects accidental recursive removal or modification of that tree.
Assert-True ($destination.StartsWith($fixture + [IO.Path]::DirectorySeparatorChar, [StringComparison]::OrdinalIgnoreCase)) 'Fixture removal escaped its isolated root'
Remove-Item -LiteralPath $destination -Recurse -Force
New-Item -ItemType Junction -Path $destination -Target $source | Out-Null
$sourceHashes = @(Get-ChildItem -LiteralPath $source -Recurse -File | Get-FileHash | Sort-Object Path | Select-Object Path,Hash)
Sync-Resources
$afterHashes = @(Get-ChildItem -LiteralPath $source -Recurse -File | Get-FileHash | Sort-Object Path | Select-Object Path,Hash)
Assert-True (($sourceHashes | ConvertTo-Json -Compress) -eq ($afterHashes | ConvertTo-Json -Compress)) 'Junction replacement modified its source target'
Assert-True (-not ((Get-Item -LiteralPath $destination).Attributes -band [IO.FileAttributes]::ReparsePoint)) 'Old junction was not replaced'
$passed.Add('old junction unlinked without touching source')

$linkedParent = Join-Path $build 'linked-parent'
New-Item -ItemType Junction -Path $linkedParent -Target $source | Out-Null
Assert-Rejected {
    & $syncScript -Source $source -Destination (Join-Path $linkedParent 'res') -BuildRoot $build -DefaultConfig $defaultConfig
} 'linked output ancestor rejected'
Assert-Rejected {
    & $syncScript -Source $source -Destination (Join-Path $fixture 'outside/res') -BuildRoot $build -DefaultConfig $defaultConfig
} 'output outside build root rejected'

Remove-Item -LiteralPath $sourceConfig
Sync-Resources
Assert-True (Test-Path -LiteralPath $outputConfig) 'Legacy resources did not receive fallback config'
$passed.Add('legacy resource layout receives default config')

$linkedSource = Join-Path $source 'linked-directory'
New-Item -ItemType Junction -Path $linkedSource -Target (Join-Path $source 'description') | Out-Null
Assert-Rejected { Sync-Resources } 'linked resource source rejected'
([IO.DirectoryInfo]::new($linkedSource)).Delete()
Assert-True (@(Get-ChildItem -LiteralPath (Split-Path -Parent $destination) -Filter '.res-stage-*').Count -eq 0) 'Resource staging directory leaked'

$receipt = [ordered]@{ passed = $passed.ToArray(); count = $passed.Count; fixture = $fixture }
$receipt | ConvertTo-Json -Depth 3 | Set-Content -LiteralPath (Join-Path $fixture 'receipt.json')
$receipt | ConvertTo-Json -Depth 3

[CmdletBinding()]
param(
    [Parameter(Mandatory)][string]$Source,
    [Parameter(Mandatory)][string]$Destination,
    [Parameter(Mandatory)][string]$BuildRoot,
    [Parameter(Mandatory)][string]$DefaultConfig,
    [ValidateSet('reset', 'preserve')][string]$ConfigPolicy = 'reset'
)

$ErrorActionPreference = 'Stop'
Set-StrictMode -Version Latest

function Get-NormalPath([string]$Path) {
    return [IO.Path]::GetFullPath($Path).TrimEnd([IO.Path]::DirectorySeparatorChar)
}

$sourcePath = Get-NormalPath $Source
$destinationPath = Get-NormalPath $Destination
$buildPath = Get-NormalPath $BuildRoot
$buildPrefix = $buildPath + [IO.Path]::DirectorySeparatorChar

function Assert-BuildPath([string]$Path) {
    if (-not $Path.StartsWith($buildPrefix, [StringComparison]::OrdinalIgnoreCase)) {
        throw "Resource output must be inside BuildRoot: $Path"
    }
}

Assert-BuildPath $destinationPath
if ([IO.Path]::GetFileName($destinationPath) -ne 'res') {
    throw 'Resource destination must be a res directory.'
}
if ($sourcePath -eq $destinationPath -or $sourcePath.StartsWith($buildPrefix, [StringComparison]::OrdinalIgnoreCase) -or
    $destinationPath.StartsWith($sourcePath + [IO.Path]::DirectorySeparatorChar, [StringComparison]::OrdinalIgnoreCase)) {
    throw 'Resource source and build output must be separate trees.'
}

# A link at the res leaf is an old SDK output and can be unlinked. No ancestor
# may be a junction: otherwise a lexically valid output could escape BuildRoot.
$ancestor = [IO.DirectoryInfo]::new([IO.Path]::GetDirectoryName($destinationPath))
while ($null -ne $ancestor) {
    if ($ancestor.Exists -and ($ancestor.Attributes -band [IO.FileAttributes]::ReparsePoint)) {
        throw "Linked output ancestor is not allowed: $($ancestor.FullName)"
    }
    $ancestor = $ancestor.Parent
}

function Get-SourceFiles([string]$Path) {
    $entry = Get-Item -LiteralPath $Path -Force
    if ($entry.Attributes -band [IO.FileAttributes]::ReparsePoint) {
        throw "Linked source resources are not allowed: $Path"
    }
    foreach ($child in Get-ChildItem -LiteralPath $Path -Force) {
        if ($child.Attributes -band [IO.FileAttributes]::ReparsePoint) {
            throw "Linked source resources are not allowed: $($child.FullName)"
        }
        if ($child.PSIsContainer) {
            Get-SourceFiles $child.FullName
        } else {
            $child
        }
    }
}

function Remove-BuildTree([string]$Path) {
    Assert-BuildPath (Get-NormalPath $Path)
    $entry = Get-Item -LiteralPath $Path -Force -ErrorAction SilentlyContinue
    if ($null -eq $entry) { return }
    if ($entry.Attributes -band [IO.FileAttributes]::ReparsePoint) {
        # DirectoryInfo.Delete() removes the junction itself; never recurse into
        # its target, which can be the maintained resource tree.
        $entry.Delete()
    } elseif ($entry.PSIsContainer) {
        foreach ($child in Get-ChildItem -LiteralPath $Path -Force) {
            Remove-BuildTree $child.FullName
        }
        [IO.Directory]::Delete($Path)
    } else {
        Remove-Item -LiteralPath $Path -Force
    }
}

function Assert-Config([string]$Content) {
    $config = ConvertFrom-Json -InputObject $Content
    if ($null -eq $config -or $config -isnot [PSCustomObject]) {
        throw 'cmt_config.json must contain a JSON object.'
    }
}

$sourceFiles = @(Get-SourceFiles $sourcePath)
foreach ($required in 'c4d_symbols.h', 'description', 'dialogs', 'strings_en-US', 'strings_zh-CN') {
    if (-not (Test-Path -LiteralPath (Join-Path $sourcePath $required))) {
        throw "Missing required resource: $required"
    }
}
$configSource = Join-Path $sourcePath 'cmt_config.json'
if (-not (Test-Path -LiteralPath $configSource)) { $configSource = Get-NormalPath $DefaultConfig }
$configContent = Get-Content -LiteralPath $configSource -Raw
Assert-Config $configContent

$existing = Get-Item -LiteralPath $destinationPath -Force -ErrorAction SilentlyContinue
if ($ConfigPolicy -eq 'preserve' -and $null -ne $existing -and
    -not ($existing.Attributes -band [IO.FileAttributes]::ReparsePoint)) {
    $existingConfig = Join-Path $destinationPath 'cmt_config.json'
    if (Test-Path -LiteralPath $existingConfig) {
        $configEntry = Get-Item -LiteralPath $existingConfig -Force
        if ($configEntry.Attributes -band [IO.FileAttributes]::ReparsePoint) {
            throw 'Cannot preserve a linked cmt_config.json.'
        }
        $configContent = Get-Content -LiteralPath $existingConfig -Raw
        Assert-Config $configContent
    }
}

$stagePath = Join-Path ([IO.Path]::GetDirectoryName($destinationPath)) ('.res-stage-' + [Guid]::NewGuid())
Assert-BuildPath $stagePath
try {
    New-Item -ItemType Directory -Path $stagePath -Force | Out-Null
    foreach ($child in Get-ChildItem -LiteralPath $sourcePath -Force) {
        Copy-Item -LiteralPath $child.FullName -Destination $stagePath -Recurse -Force
    }
    [IO.File]::WriteAllText((Join-Path $stagePath 'cmt_config.json'), $configContent, [Text.UTF8Encoding]::new($false))
    foreach ($file in $sourceFiles) {
        $relative = [IO.Path]::GetRelativePath($sourcePath, $file.FullName)
        if ($relative -eq 'cmt_config.json') { continue }
        $copied = Join-Path $stagePath $relative
        if ((Get-FileHash -LiteralPath $file.FullName).Hash -ne (Get-FileHash -LiteralPath $copied).Hash) {
            throw "Resource copy verification failed: $relative"
        }
    }
    Remove-BuildTree $destinationPath
    Move-Item -LiteralPath $stagePath -Destination $destinationPath
    Write-Host "Runtime resources copied: $destinationPath (config: $ConfigPolicy)"
} finally {
    Remove-BuildTree $stagePath
}

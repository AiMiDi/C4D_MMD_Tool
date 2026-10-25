# t19：两版插件的变形一致性（mesh sha256）验证。
#
# 用 baseline-run.ps1 各自跑一遍完整轮（含 -DumpMesh），然后把 mesh-dump.json 里
# 帧 540/560/619 的 local/world sha256 与基线锚点、以及两版之间逐字节比较。
# 结果保持型候选的判据是：三帧的局部与世界 sha256 必须与基线完全相同（逐点偏差 0）。
param(
	[string]$RepoRoot = 'C:\code\C4D_MMD_Tool',
	[string]$BaselinePlugins = 'S:\tmp\cmt_vmd_profile_20261019\ab\baseline\plugins',
	[string]$CandidatePlugins = 'S:\tmp\cmt_vmd_profile_20261019\hotpath\candidate\plugins',
	[string]$ScenePath = 'S:\tmp\cmt_vmd_profile_20261019\scenes\perf-baseline.c4d',
	[string]$OutRoot = '',
	[int]$Warmup = 20,
	[int]$Frames = 40,
	[int]$StartFrame = 560
)

$ErrorActionPreference = 'Stop'
Set-StrictMode -Version Latest

$runner = Join-Path $RepoRoot 'docs\validation\vmd-host-restore-20261024\baseline-run.ps1'
if (-not (Test-Path $runner)) { throw "baseline-run.ps1 不存在：$runner" }
if (-not $OutRoot) {
	$stamp = (Get-Date).ToUniversalTime().ToString('yyyyMMddTHHmmssZ')
	$OutRoot = "S:\tmp\cmt_vmd_profile_20261019\hotpath\mesh\$stamp"
}
New-Item -ItemType Directory -Path $OutRoot -Force | Out-Null
Write-Host "MESH_OUT_ROOT $OutRoot"

# 历史锚点：从 t13 已经冻结的 A/B 轮（六轮逐字节相同）读取，避免手抄 sha 出错。
# 若该目录不存在，则退化为「只比较两版之间」，并在 summary 里记录 anchor_source=none。
$anchorPath = 'S:\tmp\cmt_vmd_profile_20261019\ab\round1-baseline\mesh-dump.json'
$anchors = @{}
$anchorSource = 'none'
if (Test-Path -LiteralPath $anchorPath) {
	$anchorSource = $anchorPath
	$anchorJson = Get-Content -LiteralPath $anchorPath -Raw | ConvertFrom-Json
	foreach ($rec in $anchorJson.records) {
		$anchors[[int]$rec.frame] = [pscustomobject]@{ local = $rec.local_sha256; world = $rec.world_sha256; point_count = [int]$rec.point_count }
	}
	Write-Host ("MESH_ANCHORS {0} frames {1}" -f $anchorPath, (($anchors.Keys | Sort-Object) -join ','))
}
else {
	Write-Warning "历史锚点缺失：$anchorPath（只做两版互比）"
}

$variants = @(
	[pscustomobject]@{ name = 'baseline'; plugins = $BaselinePlugins },
	[pscustomobject]@{ name = 'candidate'; plugins = $CandidatePlugins }
)

$runRecords = @{}
foreach ($variant in $variants) {
	$outDir = Join-Path $OutRoot $variant.name
	Write-Host ("== [{0}] mesh run {1}" -f (Get-Date -Format 'HH:mm:ss'), $variant.name)
	$measureArgs = @(
		'-NoProfile', '-File', $runner,
		'-ScenePath', $ScenePath,
		'-OutDir', $outDir,
		'-PluginsPath', $variant.plugins,
		'-DumpMesh',
		'-Warmup', "$Warmup",
		'-Frames', "$Frames",
		'-StartFrame', "$StartFrame"
	)
	& pwsh @measureArgs
	$exit = $LASTEXITCODE
	$summaryPath = Join-Path $outDir 'run-summary.json'
	$meshPath = Join-Path $outDir 'mesh-dump.json'
	if (-not (Test-Path $meshPath)) {
		Write-Warning "$($variant.name) 未产出 mesh-dump.json（exit=$exit）"
		$runRecords[$variant.name] = [pscustomobject]@{ name = $variant.name; exit = $exit; ok = $false }
		continue
	}
	$summary = if (Test-Path $summaryPath) { Get-Content -LiteralPath $summaryPath -Raw | ConvertFrom-Json } else { $null }
	$mesh = Get-Content -LiteralPath $meshPath -Raw | ConvertFrom-Json
	$runRecords[$variant.name] = [pscustomobject]@{
		name = $variant.name
		exit = $exit
		ok = ($exit -eq 0)
		# baseline-run.ps1 的 run-summary.json 把工件信息放在 plugins / host 块里，
		# 没有顶层 artifact_sha；这里取插件模块 sha（本地）与宿主实际加载 sha 对比。
		artifact_sha = if ($summary -and $summary.PSObject.Properties['plugins']) { $summary.plugins.module_sha256 } else { $null }
		hosted_module_sha = if ($summary -and $summary.PSObject.Properties['host']) { $summary.host.loaded_module_sha256 } else { $null }
		frames = @($mesh.frames)
		records = @($mesh.records | ForEach-Object {
			[pscustomobject]@{
				frame = [int]$_.frame
				object = $_.object
				point_count = [int]$_.point_count
				local_sha256 = $_.local_sha256
				world_sha256 = $_.world_sha256
			}
		})
	}
	Write-Host ("   -> frames {0} exit {1}" -f (($mesh.frames) -join ','), $exit)
}

$comparison = @()
$failures = @()
foreach ($frame in @(540, 560, 619)) {
	$b = ($runRecords['baseline'].records | Where-Object { $_.frame -eq $frame })
	$c = ($runRecords['candidate'].records | Where-Object { $_.frame -eq $frame })
	if (-not ($b -and $c)) { $failures += "frame $frame 缺少记录（baseline=$([bool]$b) candidate=$([bool]$c)）"; continue }
	$anchor = if ($anchors.ContainsKey([int]$frame)) { $anchors[[int]$frame] } else { $null }
	$row = [pscustomobject]@{
		frame = $frame
		baseline_local = $b.local_sha256
		candidate_local = $c.local_sha256
		local_equal = ($b.local_sha256 -eq $c.local_sha256)
		baseline_world = $b.world_sha256
		candidate_world = $c.world_sha256
		world_equal = ($b.world_sha256 -eq $c.world_sha256)
		point_count_equal = ($b.point_count -eq $c.point_count)
		anchor_local = if ($anchor) { $anchor.local } else { $null }
		anchor_world = if ($anchor) { $anchor.world } else { $null }
		candidate_matches_anchor_local = if ($anchor) { $c.local_sha256 -eq $anchor.local } else { $null }
		candidate_matches_anchor_world = if ($anchor) { $c.world_sha256 -eq $anchor.world } else { $null }
		baseline_matches_anchor_local = if ($anchor) { $b.local_sha256 -eq $anchor.local } else { $null }
	}
	if (-not $row.local_equal) { $failures += "frame $frame local sha 不同" }
	if (-not $row.world_equal) { $failures += "frame $frame world sha 不同" }
	if (-not $row.point_count_equal) { $failures += "frame $frame point_count 不同" }
	if ($anchor -and (-not $row.candidate_matches_anchor_local)) { $failures += "frame $frame 候选 local sha 与历史锚点不同" }
	if ($anchor -and (-not $row.candidate_matches_anchor_world)) { $failures += "frame $frame 候选 world sha 与历史锚点不同" }
	if ($anchor -and (-not $row.baseline_matches_anchor_local)) { $failures += "frame $frame 基线 local sha 与历史锚点不同（说明环境/配方变了）" }
	$comparison += $row
}

$result = [pscustomobject]@{
	schema = 'vmd-hotpath-mesh/1'
	out_root = $OutRoot
	scene = $ScenePath
	anchor_source = $anchorSource
	runs = $runRecords
	comparison = $comparison
	failures = $failures
}
$jsonPath = Join-Path $OutRoot 'mesh-summary.json'
$result | ConvertTo-Json -Depth 8 | Set-Content -LiteralPath $jsonPath -Encoding utf8
Write-Host "MESH_SUMMARY $jsonPath"
Write-Host ('MESH_RESULT:' + ($result | ConvertTo-Json -Depth 6 -Compress))
foreach ($row in $comparison) {
	Write-Host ("  frame {0}: local {1} world {2} points {3}" -f $row.frame,
		$(if ($row.local_equal) { 'EQUAL' } else { 'DIFF' }),
		$(if ($row.world_equal) { 'EQUAL' } else { 'DIFF' }),
		$(if ($row.point_count_equal) { 'EQUAL' } else { 'DIFF' }))
}
if ($failures.Count -gt 0) {
	Write-Warning ($failures -join '; ')
	exit 1
}
if (-not ($runRecords['baseline'].ok -and $runRecords['candidate'].ok)) { exit 1 }
Write-Host 'MESH_OK'
exit 0

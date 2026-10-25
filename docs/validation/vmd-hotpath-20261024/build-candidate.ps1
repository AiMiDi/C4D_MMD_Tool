# 构建 C1/C3 候选工件的隔离脚本（t19）。
#
# 设计要点：
# - 产品树只在「apply → 构建 → 反向 apply」这个窗口内被临时改写，结束时必须与开工前
#   `git status --short` 完全一致（否则脚本以非零退出）。
# - 构建目录完全在 S:\tmp 下，绝不复用/污染 _build_msvc\sdk_2027_v143（那是 baseline 工件来源）。
# - Release 口径与出包一致：CMT_ENABLE_RUNTIME_PROFILING=OFF。
# - 用法：
#   pwsh -NoProfile -File docs\validation\vmd-hotpath-20261024\build-candidate.ps1 `
#     -Patch <patch> -BuildDir S:\tmp\...\hotpath-build -OutDir S:\tmp\...\hotpath\candidate
param(
	[string]$RepoRoot = 'C:\code\C4D_MMD_Tool',
	[string]$Patch = 'C:\code\C4D_MMD_Tool\.dsh-switchman\vmd-perf-20261024\candidate-hotpath-v1\candidate-hotpath-v1.patch',
	[string]$BuildDir = 'S:\tmp\cmt_vmd_profile_20261019\hotpath-build',
	[string]$OutDir = 'S:\tmp\cmt_vmd_profile_20261019\hotpath\candidate\plugins',
	[string]$Generator = 'Visual Studio 18 2026',
	[string]$Toolset = 'v143',
	[ValidateSet('all','c1','c3')][string]$Only = 'all'
)

$ErrorActionPreference = 'Stop'
Set-StrictMode -Version Latest

function Assert-True([bool]$condition, [string]$what) {
	if (-not $condition) { throw "ASSERT FAILED: $what" }
	Write-Host "  PASS $what"
}

function Invoke-Native([string]$file, [string[]]$arguments, [string]$workDir) {
	$psi = New-Object System.Diagnostics.ProcessStartInfo
	$psi.FileName = $file
	$psi.Arguments = ($arguments | ForEach-Object { if ($_ -match '\s') { '"' + $_ + '"' } else { $_ } }) -join ' '
	$psi.WorkingDirectory = $workDir
	$psi.RedirectStandardOutput = $true
	$psi.RedirectStandardError = $true
	$psi.UseShellExecute = $false
	$psi.CreateNoWindow = $true
	$proc = [System.Diagnostics.Process]::Start($psi)
	$stdout = $proc.StandardOutput.ReadToEnd()
	$stderr = $proc.StandardError.ReadToEnd()
	$proc.WaitForExit()
	return [pscustomobject]@{ ExitCode = $proc.ExitCode; Stdout = $stdout; Stderr = $stderr }
}

Write-Host '== 1. 前置状态'
$statusBefore = (Invoke-Native 'git' @('-C', $RepoRoot, 'status', '--short') $RepoRoot).Stdout.Trim()
Write-Host ("  git status 行数 = {0}" -f (($statusBefore -split "`n" | Where-Object { $_.Trim() }).Count))
$statusBefore | Set-Content -LiteralPath 'S:\tmp\hotpath-t19-status-before.txt' -Encoding utf8
Assert-True (Test-Path $Patch) "补丁存在：$Patch"
$patchSha = (Get-FileHash -LiteralPath $Patch -Algorithm SHA256).Hash
Write-Host "  patch sha256 = $patchSha"
Assert-True ($patchSha -eq 'CCF7EB014CB67E61B0F8371A240CCDB985DF745141F89EB3D247506FAC78FE74') '补丁 sha256 与 t17 交付一致'

# 记录补丁涉及的每个文件在「应用前」的字节 sha256：还原时按这些目标值校验，
# 避免 core.autocrlf=true 造成的假 M 或字节漂移（t13 教训）。
$hashesBefore = @{}
$numstat = Invoke-Native 'git' @('-C', $RepoRoot, 'apply', '--numstat', $Patch) $RepoRoot
foreach ($line in @($numstat.Stdout -split "`n" | Where-Object { $_.Trim() })) {
	$rel = ($line -split "`t")[2].Trim()
	$full = Join-Path $RepoRoot ($rel -replace '/', '\')
	if (Test-Path -LiteralPath $full) {
		$hashesBefore[$rel] = (Get-FileHash -LiteralPath $full -Algorithm SHA256).Hash
		Write-Host ("  baseline {0} {1}" -f $hashesBefore[$rel].Substring(0, 16), $rel)
	}
	else {
		# 补丁新增的文件（mmd_keyframe_search.h）：开工前不存在，还原后必须重新消失。
		$hashesBefore[$rel] = $null
		Write-Host ("  baseline <absent>          {0}" -f $rel)
	}
}
Assert-True ($hashesBefore.Count -eq 6) '补丁涉及 6 个文件'
$hashesBefore | ConvertTo-Json | Set-Content -LiteralPath 'S:\tmp\hotpath-t19-hashes-before.json' -Encoding utf8

Write-Host '== 2. 应用补丁'
$applyCheck = Invoke-Native 'git' @('-C', $RepoRoot, 'apply', '--check', $Patch) $RepoRoot
Assert-True ($applyCheck.ExitCode -eq 0) 'git apply --check exit 0'
$apply = Invoke-Native 'git' @('-C', $RepoRoot, 'apply', $Patch) $RepoRoot
Assert-True ($apply.ExitCode -eq 0) 'git apply exit 0'
$patched = Invoke-Native 'git' @('-C', $RepoRoot, 'status', '--short', '--', 'source') $RepoRoot
Write-Host "  临时改动：`n$($patched.Stdout.Trim())"
Assert-True (($patched.Stdout.Trim() -split "`n" | Where-Object { $_.Trim() }).Count -eq 6) '临时改动恰好 6 个文件'

# 归因用：只留 C1 或只留 C3 的变体（用于把合并收益拆成两半）。
# C1 组 = mmd_model_manager.cpp + mmd_bone_control_util.{cpp,hpp} + mmd_bone_manager.h
# C3 组 = mmd_bone.cpp + 新增 mmd_keyframe_search.h
$c1Files = @(
	'source/module/tools/object/mmd_model_manager.cpp',
	'source/utils/mmd_bone_control_util.cpp',
	'source/utils/mmd_bone_control_util.hpp',
	'source/module/tools/object/mmd_bone_manager.h'
)
$c3Files = @('source/module/tools/tag/mmd_bone.cpp')
$c3NewFiles = @('source/module/tools/tag/mmd_keyframe_search.h')

function Restore-PathsFromHead([string[]]$paths) {
	foreach ($rel in $paths) {
		$full = Join-Path $RepoRoot ($rel -replace '/', '\')
		$blob = (Invoke-Native 'git' @('-C', $RepoRoot, 'rev-parse', "HEAD:$rel") $RepoRoot).Stdout.Trim()
		$blobFile = Join-Path $env:TEMP 't19-restore.bin'
		& cmd /c "git -C `"$RepoRoot`" cat-file blob $blob > `"$blobFile`"" | Out-Null
		[System.IO.File]::WriteAllBytes($full, [System.IO.File]::ReadAllBytes($blobFile))
		$target = $hashesBefore[$rel]
		if ($target -and ((Get-FileHash -LiteralPath $full -Algorithm SHA256).Hash -ne $target)) {
			$text = [System.Text.Encoding]::UTF8.GetString([System.IO.File]::ReadAllBytes($blobFile)) -replace "`r`n", "`n"
			[System.IO.File]::WriteAllBytes($full, [System.Text.Encoding]::UTF8.GetBytes(($text -replace "`n", "`r`n")))
		}
		Invoke-Native 'git' @('-C', $RepoRoot, 'update-index', '--refresh', '--', $rel) $RepoRoot | Out-Null
	}
}

switch ($Only) {
	'c1' {
		Restore-PathsFromHead $c3Files
		foreach ($rel in $c3NewFiles) {
			$full = Join-Path $RepoRoot ($rel -replace '/', '\')
			if (Test-Path -LiteralPath $full) { Remove-Item -LiteralPath $full -Force }
		}
		Write-Host '  变体裁剪：只保留 C1（已回滚 C3 的 mmd_bone.cpp 与新增头）'
	}
	'c3' {
		Restore-PathsFromHead $c1Files
		Write-Host '  变体裁剪：只保留 C3（已回滚 C1 的 4 个文件）'
	}
	'all' { Write-Host '  变体：完整补丁（C1+C3）' }
	default { throw "未知 -Only 值：$Only（允许 all|c1|c3）" }
}

try {
	Write-Host '== 3. 配置 Release（隔离构建目录）'
	if (Test-Path $BuildDir) { Remove-Item -LiteralPath $BuildDir -Recurse -Force }
	$configureArgs = @(
		'-S', (Join-Path $RepoRoot 'sdk_2027'),
		'-B', $BuildDir,
		'-G', $Generator,
		'-A', 'x64',
		'-T', $Toolset,
		'-DCMT_ENABLE_RUNTIME_PROFILING:BOOL=OFF'
	)
	$configureStart = Get-Date
	$configure = Invoke-Native 'cmake' $configureArgs $RepoRoot
	$configureSeconds = [math]::Round(((Get-Date) - $configureStart).TotalSeconds, 1)
	Write-Host $configure.Stdout
	Write-Host $configure.Stderr
	Assert-True ($configure.ExitCode -eq 0) "cmake configure exit 0（$configureSeconds s）"
	$cache = Join-Path $BuildDir 'CMakeCache.txt'
	$cacheText = Get-Content -LiteralPath $cache -Raw
	Assert-True ($cacheText -match 'CMT_ENABLE_RUNTIME_PROFILING:BOOL=OFF') 'CMakeCache 记录 CMT_ENABLE_RUNTIME_PROFILING=OFF（出包口径）'

	Write-Host '== 4. 构建 mmdtool（Release）'
	$buildStart = Get-Date
	$build = Invoke-Native 'cmake' @('--build', $BuildDir, '--config', 'Release', '--target', 'mmdtool') $RepoRoot
	$buildSeconds = [math]::Round(((Get-Date) - $buildStart).TotalSeconds, 1)
	$tail = ($build.Stdout -split "`n" | Select-Object -Last 12) -join "`n"
	Write-Host $tail
	Write-Host $build.Stderr
	Assert-True ($build.ExitCode -eq 0) "cmake build exit 0（$buildSeconds s）"

	Write-Host '== 5. 收集工件'
	$artifact = Join-Path $BuildDir 'bin\Release\plugins\mmdtool\mmdtool.xdl64'
	Assert-True (Test-Path $artifact) "构建产物存在：$artifact"
	$artifactItem = Get-Item -LiteralPath $artifact
	$artifactSha = (Get-FileHash -LiteralPath $artifact -Algorithm SHA256).Hash
	Write-Host ("  artifact = {0} B  sha256 {1}" -f $artifactItem.Length, $artifactSha)
	# 插桩口径自检：出包口径不应带 profiling 标记
	$markerHit = Select-String -LiteralPath $artifact -Pattern 'CMT_RUNTIME_PROFILING=1' -SimpleMatch -Quiet -ErrorAction SilentlyContinue
	Assert-True (-not $markerHit) '候选工件不含 CMT_RUNTIME_PROFILING=1 标记（未插桩）'

	if (Test-Path $OutDir) { Remove-Item -LiteralPath $OutDir -Recurse -Force }
	New-Item -ItemType Directory -Path (Split-Path -Parent $OutDir) -Force | Out-Null
	Copy-Item -LiteralPath (Join-Path $BuildDir 'bin\Release\plugins') -Destination $OutDir -Recurse -Force
	$copied = Join-Path $OutDir 'mmdtool\mmdtool.xdl64'
	Assert-True (Test-Path $copied) "候选插件目录已落盘：$copied"
	$copiedSha = (Get-FileHash -LiteralPath $copied -Algorithm SHA256).Hash
	Assert-True ($copiedSha -eq $artifactSha) '落盘副本与构建产物 sha256 一致'

	[pscustomobject]@{
		patch_sha256 = $patchSha
		artifact = $artifact
		artifact_bytes = $artifactItem.Length
		artifact_sha256 = $artifactSha
		plugins_dir = Split-Path -Parent $OutDir
		configure_seconds = $configureSeconds
		build_seconds = $buildSeconds
	} | ConvertTo-Json -Depth 4 | Set-Content -LiteralPath 'S:\tmp\hotpath-t19-build.json' -Encoding utf8
}
finally {
	Write-Host '== 6. 还原产品树（无论构建成败）'
	# 教训：`git apply -R` 若中途失败，`git checkout --` 会因 core.autocrlf=true 把 LF 文件转成
	# CRLF，导致 git status 出现假 M（内容规范化后其实为空）。所以这里改为「按 HEAD blob 写字节」，
	# 并对原始为 CRLF 的文件再做一次 LF→CRLF 归一，最后用记录的目标 sha256 校验。
	$reverse = Invoke-Native 'git' @('-C', $RepoRoot, 'apply', '-R', $Patch) $RepoRoot
	if ($reverse.ExitCode -ne 0) { Write-Warning "git apply -R exit $($reverse.ExitCode)；改用 HEAD blob 字节还原" }
	# 教训（两次实测）：即使 apply -R 成功，core.autocrlf=true 也会让 LF 文件回写成 CRLF，字节
	# 与开工前不同（git status 仍是干净的，但 sha256 变了）。所以逐文件以「开工前 sha256」为准，
	# 不一致就用 HEAD blob 字节覆盖，再按原换行风格归一。
	foreach ($rel in @($hashesBefore.Keys)) {
		$full = Join-Path $RepoRoot ($rel -replace '/', '\')
		$target = $hashesBefore[$rel]
		if ($null -eq $target) { continue }
		if (Test-Path -LiteralPath $full) {
			$now = (Get-FileHash -LiteralPath $full -Algorithm SHA256).Hash
			if ($now -eq $target) { continue }
		}
		$blob = (Invoke-Native 'git' @('-C', $RepoRoot, 'rev-parse', "HEAD:$rel") $RepoRoot).Stdout.Trim()
		$blobFile = Join-Path $env:TEMP 't19-restore.bin'
		& cmd /c "git -C `"$RepoRoot`" cat-file blob $blob > `"$blobFile`"" | Out-Null
		$lfBytes = [System.IO.File]::ReadAllBytes($blobFile)
		[System.IO.File]::WriteAllBytes($full, $lfBytes)
		if ((Get-FileHash -LiteralPath $full -Algorithm SHA256).Hash -ne $target) {
			$text = [System.Text.Encoding]::UTF8.GetString($lfBytes) -replace "`r`n", "`n"
			[System.IO.File]::WriteAllBytes($full, [System.Text.Encoding]::UTF8.GetBytes(($text -replace "`n", "`r`n")))
		}
		Invoke-Native 'git' @('-C', $RepoRoot, 'update-index', '--refresh', '--', $rel) $RepoRoot | Out-Null
	}
	# 反向 apply 失败时新增文件可能残留（它出现在 git status 的 untracked 里，不在 diff HEAD 里）
	foreach ($rel in @($hashesBefore.Keys | Where-Object { $null -eq $hashesBefore[$_] })) {
		$full = Join-Path $RepoRoot ($rel -replace '/', '\')
		if (Test-Path -LiteralPath $full) {
			Write-Warning "清理补丁新增的残留文件：$rel"
			Remove-Item -LiteralPath $full -Force
		}
	}
}

Write-Host '== 7. 断言产品树已还原'
# 只比 source/：其他 teammate 可能同时新增 docs/ 或 res/ 下的未跟踪文件，那不属于本任务的残留。
$statusBeforeSource = (Invoke-Native 'git' @('-C', $RepoRoot, 'status', '--short', '--', 'source') $RepoRoot).Stdout.Trim()
$statusAfterSource = (Invoke-Native 'git' @('-C', $RepoRoot, 'status', '--short', '--', 'source') $RepoRoot).Stdout.Trim()
if ($statusAfterSource -ne $statusBeforeSource) {
	Write-Host '--- before(source) ---'
	Write-Host $statusBeforeSource
	Write-Host '--- after(source) ---'
	Write-Host $statusAfterSource
	throw 'ASSERT FAILED: source/ 的 git status 与开工前不一致'
}
Write-Host '  PASS source/ git status 与开工前完全一致'
foreach ($rel in $hashesBefore.Keys) {
	$full = Join-Path $RepoRoot ($rel -replace '/', '\')
	if ($null -eq $hashesBefore[$rel]) {
		Assert-True (-not (Test-Path -LiteralPath $full)) "新增文件已清除：$rel"
		continue
	}
	$now = (Get-FileHash -LiteralPath $full -Algorithm SHA256).Hash
	Assert-True ($now -eq $hashesBefore[$rel]) "字节级还原：$rel"
}
Write-Host 'BUILD_CANDIDATE OK'

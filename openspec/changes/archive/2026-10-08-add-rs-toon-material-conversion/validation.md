> 2026-10-08：本记录保留早期模块的验证历史。当前 25/25 收尾与最终模块证据见 [completion-validation.md](completion-validation.md)，严格校验按用户要求跳过。

# RS Toon implementation and validation — 2026-10-07

The RS Toon (MMD style) implementation is present in the working tree. Full
acceptance is **pending**. Additional UV is not required by the default profile.
This record separates native image evidence from the subsequent import crash fix.

## Module identities

| Scope | SDK 2026 Release SHA-256 | Evidence directory |
| --- | --- | --- |
| Profile v1 / graph recipe revision 2; native images and conversion | `b86b5bab86ecc2375f272f68a0e5ae913203de0cc7dfbd8e683709c008ce9c2e` | `_build_msvc/validation/rs-toon-material/profile-v1-b86b5bab86ec/` |
| Current module; disabled-material import crash fix | `3a27a16d171e5498c7556e3da8441feca9b06552285d6d4ffffa7541a67b548c` | `_build_msvc/validation/rs-toon-material/crash-fix-3a27a16d171e/` |

Both modules are normal Release builds with `CMT_ENABLE_RUNTIME_REGRESSION=OFF`.
Native tests use the maintained production import protocol. Host: Cinema 4D
2026.4; renderer: Redshift 2026.7.0, Jun 2 build `3bed0ed5`. GPU: RTX 4060,
driver 581.80. CPU: i9-14900KF. SDK 2024 and R20 have compile evidence only.
The shared worktree contains other changes; no commit or public release is made.

Subsequent user-requested actual-model checking on the current module is recorded
in [actual-pmx-outline.md](actual-pmx-outline.md). It confirms visible contour
contributions on the supplied 35-material PMX; it does not complete the full
GPU/CPU matrix or MMD parity acceptance.

## Completed native checks

On `b86b5bab86ec`, saved receipts cover:

- 29 owned graph roles and 13 per-material attributes, recipe revision 2;
  missing attribute metadata repairs without a fourteenth orphan attribute.
- Standard entry conversion, source retention and scoped TextureTag switching;
  three Undo/Redo cycles with immediate save/reopen, plus reader repair.
- Missing selections, nested foreign model meshes, multipart meshes and copied
  model ownership; independent materials have separate bindings.
- Main RGB/RGBA, individual/common/empty Toon path edits, bad-image rejection,
  retained sampler settings and same-image bright-end fallback.
- Material/Group/Flip numerical values for Toon and edge. GPU and CPU render
  sequences `0/15/30/0/30/15/0`: stable node counts, repeated PNG identity within
  each backend, equal sampled RGB/Alpha between backends. This is sampled
  agreement, not whole-image GPU/CPU equivalence or MMD parity.
- Ordinary-UV generated PMX character, alpha fringe and nine appearance
  variants: common Toon, default ramp, RGB main texture, specular zero,
  powers 8/80, edge off/zero and changed light direction.
- Native per-material Contour on merged and split geometry. Global Contour
  override was absent; scale 1 was recorded. An active custom global override
  remains untested. Merged/split images differ at 305 pixels (max delta 43),
  illustrating geometry-sensitive native contour behavior.

Render settings used for the controlled matrix: primary/secondary Brute Force,
64-pixel buckets and hardware ray tracing disabled. Earlier resource-limited
render attempts are excluded. The converter does not change scene lighting or
renderer settings. Edge-off versus zero-width differs at two RGB pixels by one
8-bit level, with identical Alpha; the strict PNG hash comparison failed and
this bounded difference is recorded instead of claiming exact equivalence.
At a fixed highlight threshold, power 80 affects fewer pixels than power 8.

The generated character has no original MMD render reference. A final-module
RS Standard/RS Toon side-by-side comparison has not been completed.

## Crash, fix and focused recheck

At 14:29:19, the owned test process (PID 22644) exited during the first
`materials=false` production import. The new crash report identifies
`ACCESS_VIOLATION`, with `ResolvePMXMaterialData` → `AddMaterial` → mesh/model
`LoadPMX` on the faulting thread. The report, minidump, exact module/PDB and MCP
audit were saved under the first evidence directory's `crash/`. The existing
October 6 ZIP was not treated as this crash's evidence.

Cause: the material path manager was only created when renderer material
import was enabled, but model entry registration unconditionally accessed its
path array. The current source constructs a local path resolver independently
of the renderer creation gate and propagates failed entry registration.

On `3a27a16d171e`, native production import passed all four combinations of
Standard/RS Toon × merged/split meshes with `materials=false`, zero materials
and zero texture assignments; each case saved and reopened successfully.
Normal Toon import retained the 29-role/13-attribute structure. ANIM and preview
conversion gates, artist-connection preservation and explicit Additional UV
Morph/SubTexture diagnostics also passed; ordinary fixtures have no Additional
UV warning. No rendering was started during this crash-fix verification.

Some `exec_python` wrappers reported a final `ReferenceError` because the
callback replaced/closed its starting test document. Their saved JSON and
stdout confirm the native assertions finished. This harness error is recorded
separately from the actual access violation; transport success is not claimed.

## Builds and automated checks

- Current SDK 2026, 2024 and R20 Release builds passed, with copied runtime
  resources. Logs are retained in the crash-fix evidence directory.
- Focused CTest in **Release**: `material_morph_runtime_test`,
  `morph_evaluation_test`, `cmt_material_fixture_matrix`: 3/3 passed.
- Maintained MCP unit tests: 35/35 passed. Python syntax checks passed.
- `git diff --check` passed. Strict OpenSpec validation is recorded after
  updating this record and the task checklist.
- An accidental broad Debug CTest invocation found unbuilt Debug executables;
  it is not acceptance evidence. The correct focused Release run above passed.

## Historical remaining acceptance work (before 2026-10-08)

2026-10-07 Specular follow-up: [revision 3 mask candidate](specular-mask.md)
adds the missing native reflection mask, with three SDK builds and focused
logic regressions. Host initialization blocked native candidate/image checks;
task 1.4 is reopened for the changed highlight recipe.

2026-10-07 follow-up: [base-parameter auto-sync and stocking investigation](authoring-sync.md)
records three-renderer native core-binding checks, the separately compiled
authoring-default/name fix, and the unsuccessful Sphere Add preview. Candidate
runtime checks and full visual parity are not inferred from those results.

Unchecked task boxes retain their full original acceptance requirements:
injected mid-transaction failures with complete rollback receipts; ambiguous
native asset/port and multiple-surface rejection cases; unsupported-host
half-import prevention; old selection persistence; mixed-preview image
coverage; active global Contour override; current crash-fixed module GPU/CPU
image matrix and representative Standard/Toon comparison.

Sphere SubTexture and Additional UV contribution, per-vertex edge magnitude,
complete PMX shadow flags, separate Ambient shading and MME remain outside
profile v1. These are approximate MMD-style materials, not native MMD parity.

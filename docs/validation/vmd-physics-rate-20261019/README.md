> 本文只保留结论。逐次测量日志、原始记录与脚本已从版本库移出，归档在 `S:\tmp\cmt_vmd_profile_20261019\repo-evidence-archive-20261024\` 下同名目录。

# VMD physics rate experiment — 2026-10-19

## Decision

**60 Hz is a useful, lossy preview candidate; 30 Hz is unsuitable for this model. Keep the production default at 120 Hz.** The 60 Hz result preserves the overall silhouette, but changes skirt ornaments, hanging accessories, and hair positions. At 30 Hz the skirt visibly stretches downward, accessories sag substantially, and hair shape changes. This is not a lossless optimization.

The experiment is isolated under `S:/tmp/cmt_vmd_profile_20261019/optimization_round5`. Production source and dependencies are unchanged. No setting was added to the shipped UI, no installer was produced, and no commit was made. Three comparison scenes remain in the task's private Cinema 4D instance; the active scene is `CMT Physics 60 Hz - Preview`.

![Native viewport comparison at frame 619](comparison-frame619.png)

The figure uses the same crop of three native viewport captures. No pose or geometry was edited for the figure. The uncropped captures are `frame619-120Hz.png`, `frame619-60Hz.png`, and `frame619-30Hz.png`.

## Controlled change

Scene: the saved current-scene copy, 阿芙2.0.pmx, 30 project FPS, 625 bones, 479 rigid bodies, 748 constraints, 35 meshes, and 70,222 vertices.

The sole experimental production-code difference is the four-line addition in `experimental-rate.patch`, calling `MMDPhysics::SetFPS()` from `ApplyPhysicsConfigToRuntime()`. A private model BaseContainer field selects 120, 60, or 30 Hz. This field has no production resource/API contract. The 30 Hz test matches **this project's** FPS; an automatic arbitrary-project-FPS mode was not implemented.

Animation still advances by `1 / project_fps` per evaluated frame. The maximum substep count stays 10. Gravity, rigid bodies, constraints, solver parameters, collision settings, animation/IK, and skinning remain unchanged. At 30 project FPS, the profiler confirms 4, 2, and 1 Bullet substeps per frame respectively. This does not skip animation frames or change VMD duration.

Both profiling ON and OFF Release builds succeeded. Timing and quality results below use OFF; stage attribution uses ON. The OFF binary passes `cmake/check_profiling_disabled.cmake`. Starting it with the profiling environment enabled produced no profile log. Packaging defaults and profiling guards remain OFF.

The final host uses the isolated experimental OFF binary at `S:/tmp/cmt_vmd_profile_20261019/profiler-build/bin/Release/plugins/mmdtool/mmdtool.xdl64`, also preserved in `optimization_round5/candidate_off/plugins`. The frozen source file was restored to production after preserving the experimental source and binary. Therefore the currently loaded binary intentionally differs from that restored source. The ordinary installed/shared plugin was not overwritten.

## Timing

Each run loads a fresh snapshot, warms frame 0 and frames 540–559, and measures `ExecutePasses(None, True, True, True, BUILDFLAGS_NONE)` for frames 560–619. Capture and file I/O are outside the timer. Run order is 120 → 60 → 30 → 30 → 60 → 120. Each rate has 120 timed samples across two runs.

| Rate | OFF wall mean, run 1 / run 2 | OFF pooled wall mean | OFF caller CPU mean | ON Bullet mean | Bullet substeps/frame |
|---|---:|---:|---:|---:|---:|
| 120 Hz | 60.392 / 64.793 ms | 62.593 ms | 61.328 ms | 28.609 ms | 4 |
| 60 Hz | 49.114 / 51.212 ms | 50.163 ms | 49.740 ms | 16.318 ms | 2 |
| 30 Hz | 43.796 / 41.503 ms | 42.650 ms | 42.448 ms | 8.659 ms | 1 |

In this interleaved sample, 60 Hz reduces total evaluation wall time by about 19.9% and Bullet time by about 43.0%. At 30 Hz the corresponding reductions are about 31.9% and 69.7%, with unacceptable visible deformation for this scene.

Other MSBuild/compiler processes remained active and were not disturbed. These are local measurements, not a universal speedup guarantee. `ExecutePasses` includes scene evaluation and deformation caches but excludes viewport drawing: these numbers are **not measured viewport FPS** and do not establish 60 FPS playback. Windows caller CPU counters are quantized; only aggregate means are used.

The ON profile uses two complete 60-frame groups per rate, excluding capture runs. The selection script, three stage summaries, and all OFF frame timing arrays are preserved with the receipt. Nested inclusive stages must not be added together.

## Physics quality and repeatability

All three rates completed a lighter native replay of frames 0–619, covering about 20.7 seconds at 30 FPS. Bone positions were recorded on all 620 frames; actual deformation-cache vertices were exported at frames 0, 59, 119, 179, 239, 299, 359, 419, 479, 539, 599, and 619. All sampled values were finite. Captures at frame 619 use the same closer camera, with no reset between frames 0 and 619.

Against the 120 Hz reference, pooling all 70,222 vertices over those 12 mesh samples:

| Rate | Mean vertex displacement | P95 displacement | P95 / reference height | Maximum displacement |
|---|---:|---:|---:|---:|
| 60 Hz | 0.1959 | 0.8268 | 4.43% | 3.5503, frame 599 |
| 30 Hz | 0.6779 | 2.8738 | 15.39% | 9.0283, frame 619 |

Displacements are in mesh-local coordinates; reference height is the baseline frame-0 mesh Y extent, about 18.67 in the same coordinates. These are pose differences, not direct collision-penetration measurements. Bone positions and temporal differences in `quality-summary.json` use world coordinates and must not be directly compared to mesh-local units. Pooled statistics can hide larger errors on small accessories; per-mesh statistics are retained in that file.

The 60 Hz silhouette remains recognizable and substantially closer to the reference than 30 Hz, but the lower skirt and accessories visibly move downward. It is reasonable to inspect it as a faster preview, not to silently replace the original physical result. The 30 Hz stretch and sag fail this scene's quality requirement. Finite values alone are not a quality pass, and sampled views do not certify every collision or every model.

Repeat checks:

- The isolated 120 Hz ON short-window run matches the preceding production baseline's 60 bone/mesh samples exactly.
- The lighter 120 Hz replay matches the first complete 620-frame bone capture exactly; all 12 mesh checkpoints match after the earlier float32 storage conversion.
- Completed portions of both interrupted 60 Hz captures match the lighter replay at all comparable checkpoints (7 and 8 checkpoints respectively).
- With physics disabled, all three rate settings produce identical bones and deformed vertices over the existing 13-frame seek/same-time test sequence.
- All completed runs report the original document unchanged. Native host operations used MCP only.

## Unresolved sampling crashes

Two heavy full-mesh capture runs crashed the private C4D instance: PID 28092 after 360 completed frames at 60 Hz, and PID 67996 after 460 frames during a single-request retry. Their top stacks are in C4D's embedded Python. This is **not sufficient to identify the root cause or exclude native memory corruption**; neither a Bullet frequency fault nor a Python sampler fault has been proven.

The reports and minidumps were saved under `optimization_round5/crash-28092` and `crash-67996`; compact stack excerpts and full-file hashes are retained here. Only the verified task-owned crashed processes were stopped. No user document or other compiler/host process was terminated.

Reducing full-mesh exports to 12 checkpoints allowed all three 620-frame replays to finish without another crash. This is additional evidence, not a fix or a broad stability certification. The two failures remain a release limitation and are not discarded from the results.

## Artifacts and reproduction

- `receipt.json`: source/binary/build-log hashes, timing arrays, profile means, quality results, repeat checks, crash evidence hashes, and final host state.
- `quality-summary.json`: mesh-part differences and all-frame bone motion statistics.
- `experimental-rate.patch`: exact isolated frequency change.
- `compare_rates.py`: fresh-scene timing and short-window sampling harness.
- `light_native.py` / `light_batch.py`: lighter long replay and native viewport capture.
- `analyze_light.py` / `summarize_profiles.py` / `collect_receipt.py`: analysis and consistency assertions.

Harnesses reference the existing task root and helper scripts there; they require the private MCP host and saved scene assets. Full model assets, raw vertex arrays, native profile JSONL, and minidumps remain outside the repository. No authentication token is included.

The three saved preview scenes are `S:/tmp/cmt_vmd_profile_20261019/optimization_round5/physics-{120,60,30}Hz-preview.c4d`. Their experimental frequency field is honored only by the isolated experimental plugin. Loading them with the production plugin uses its ordinary 120 Hz behavior. The current task-owned host already has all three open, with 60 Hz active.

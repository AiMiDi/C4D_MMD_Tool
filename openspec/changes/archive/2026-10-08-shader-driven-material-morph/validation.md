# Implementation evidence

## Remaining-task closure — 2026-10-08

The user explicitly requested skipping the native MMD comparison and marking
task 1.5 complete. This is an acceptance waiver: the renderer uses the preserved
Mul/Add state and Saba reference operation; native MMD fidelity remains
unverified. Opening the official portable MMD distribution produced no native
reference image, and its prepared fixture is not counted as acceptance.

### Complete managed lighting paths

Standard and Redshift each produced six real lit-sphere images on module
`e5c0501cebb1af35ecb2320fede99eebb80261152461694bb58add078eeb2b34`.
The imported bound mesh, material shaders/nodes and User Data remain in the
render path. Only private fixture geometry is replaced by a sphere; this test
does not bypass managed outputs through emission or constant surface inputs.
Material Morph preview drives Power 2/510, red specular and zero specular.

- Standard half-peak highlight area decreases from 6171 to 1229 pixels;
  Redshift decreases from 7135 to 71. Red highlights contain no green/blue
  response; the zero case peaks at 1/255 for Standard and 0 for Redshift.
- Repeat and save/reopen images are byte-identical in each renderer.
  Ordinary reopening disables preview; the test explicitly restores its weight
  before the comparison render.
- Managed structure is unchanged through all cases. The private host restores
  the original document and renderer device settings on exit.
- These are native Standard and RS lighting-response checks. They establish
  no native-MMD BRDF equivalence or cross-renderer lighting parity.

### Authoring completion

The full-material delete command passed three Undo/Redo cycles. Every step
saved immediately and reopened with the expected polygon count (4 before
deletion, 2 afterward), then exported PMX with the corresponding material and
Morph definitions. Its original scene materials remain available for Undo.

Inspection also found that Material Morph lacked a whole-definition delete
entry. The material Morph editor now has an EDIT-only "Delete entire Morph"
button, separate from offset deletion. It uses the existing confirmation,
full-model Undo, reference remapping and preview restoration path. SDK 2026,
2024 and R20 compile.

After the user clicked the confirmation, the native deletion command completed
on module `5aba607728cb07d972d3a941555fab2dad5e85571233be25bd9a607d57ce65f0`.
The deleted state and three Undo/Redo cycles pass immediate save/reopen, PMX
export and native Standard preview sampling. The deleted state exports exactly
Multiply/Group/Flip, with Group targeting Multiply at index 0 with weight .25,
and Flip targeting Group at index 1 with weight 1. Undo restores Tint and its
preview response; Redo removes it and restores base output. Tests re-resolve
the live model after Undo/Redo because C4D can replace the model object.

The earlier MCP timeout represented a pending dialog, not a completed deletion.
Its outcome is now reconciled and no second deletion was queued. Cleanup closes
the exact private document, reports no remaining owned documents or errors,
and restores the original document. The host wrapper reports the known stale
document ReferenceError after that callback; the cleanup receipt is persisted
before it and confirms completion.

Task progress is now 15/15, including the user's explicit native-MMD waiver.
The archive is `_build_msvc/validation/shader-driven-material-morph/completion-20261008/`;
`completion-receipt.json`, `morph-delete.json`, saved C4D/PMX files, lighting
images/analysis and cleanup receipts retain the distinct evidence identities.

## Texture semantics correction — 2026-10-07

The earlier statement that implementation is complete with only acceptance left
is withdrawn for texture Morph semantics. Source inspection confirms a visible
reference divergence, not merely missing rendering evidence:

- Before this repair, `source/utils/cmt_material_morph_accumulator.hpp` merged texture Mul/Add
  into one runtime factor. The Standard wrapper and Redshift texture multiplier
  then scale the sample with that factor; factor Alpha also scales opacity.
- Local libMMD revision `ecbbaed832377582a3e0f7296febc5186f9d82dd`,
  `src/libMMD/Model/MMD/PMXModel.cpp:889-894`, retains separate texture, sphere
  and toon Mul/Add RGBA factors.
- [Saba shader at revision 29b8efa8](https://github.com/benikabocha/saba/blob/29b8efa8b31c8e746f9a88020fb0ad9dcdcf3332/viewer/Saba/Viewer/resource/shader/mmd.frag#L40-L50)
  applies multiplication and addition after sampling. For sample RGB T and
  factors M/A, its intermediate RGB is `U = (1-M.a) + T*M.rgb*M.a`, followed by
  `clamp(U + (U-1)*A.a, 0, 1) + A.rgb`. Its main texture branch applies sampled
  image Alpha separately when texture mode is 2. Saba is a comparison reference,
  not an authoritative native-MMD oracle.

For example, with T=.25, neutral multiplication and additive RGB=.2/Alpha=0,
the old texture contribution was .30 whereas the Saba formula gives .45.
This algebraic counterexample is source analysis, not a native render result.
The final fidelity claim must be settled by native MMD output.

Existing render receipts remain evidence for lifecycle, determinism and the
implemented provisional formula, not proof of MMD texture fidelity. Their
expected pixel values must not be used as the independent oracle.

### Reference repair implementation

- Runtime state and dirty checksums now retain separate Mul/Add RGBA for main,
  sphere and toon textures. PMX offset serialization is unchanged.
- Standard captures the operands in InitRender and applies the reference
  operation to the child sample. Texture-factor Alpha no longer scales opacity.
- Redshift uses seven native User Data readers and four fixed texture math
  nodes. Its equivalent affine scale/bias are applied before Saturate, then Add
  RGB and Diffuse multiplication. Image Alpha is split independently.
- Binding version 2 uses explicit undoable migration from version 1. Legacy
  unbound shader parameters keep their old interpretation. Wiring validation
  protects foreign inputs and edited math operations.
- Focused material tests and all 15 SDK-independent CTest groups pass, including
  .25 + .2 = .45, black-texel addition, factor Alpha behavior, clamp placement,
  and 450 direct/affine channel comparisons.
- SDK 2026 Release build passed. Native preflight caught that RS math_op values
  have type Int64, not Int32; the corrected build reads the exact native type.
  Corrected module SHA-256:
  `5d699ce5130efa88d3930af47531da01ac908b5848d590a588d2c4b50111d13b`.
- The user subsequently authorized another GPU attempt. On this module, six
  Standard native sampling cases pass, including separate/mixed Mul/Add and
  factor Alpha. Both Redshift fixture materials install version-2 bindings.
  GPU render results are recorded below.

Saba-reference repair and native MMD fidelity remain distinct. No native MMD
reference image has been supplied or produced by this repair.

### GPU and migration receipts for 5d699ce5

- RTX 4060, GPU enabled and CPU/hybrid rendering disabled during the run.
  Renderer device preferences were restored afterward.
- Seven renders at `0,15,30,0,30,15,0` pass. Repeated frames have identical
  RGB/Alpha samples and PNG SHA-256 values.
- All 31 frames `0..30` pass without crash or out-of-memory failure. Frames
  0/15/30 match the corresponding seek results, including their PNG hashes.
- The fixture animates both additive RGB/Alpha and non-neutral multiplicative
  RGB/Alpha. At frames 0/15/30, textured RGB samples are `[6,21,73]`,
  `[17,41,80]`, `[31,65,94]`; textured Alpha is 48/53/58. Plain Alpha is
  128/141/153. Alpha is checked against `96*(.5+.1*weight)` for the RGBA image.
- RGB uses an isolated emission pass on a render-document clone. The decoded
  color-managed texel is calibrated from frame 0, then checked against the Saba
  operation with a three-code-value tolerance. This is a renderer-operation
  regression, not an independent native-MMD or full BRDF/lighting oracle.
- After rendering, the plain material has 9 nodes and the textured material
  15, each with exactly 7 managed readers and no duplicate math nodes.
- Actual version-1 Standard and Redshift scenes from the preceding 5a8929a8
  checkpoint upgrade to version 2. One Undo restores both materials to v1; one
  Redo restores both to v2. Each step saves immediately and reopens with the same
  structure. Standard sampling also passes after migration.
- SDK 2026, SDK 2024 and R20 Release builds pass. Compatibility builds include
  the concurrent Toon work available in the shared workspace; they are compile
  evidence, not native Toon acceptance. The GPU host loaded the exact 5d699ce5
  module archived with its PDB, not a later shared-workspace rebuild.
- Private documents were cleaned and the task-owned C4D host was stopped.
  Some `exec_python` wrappers report a stale active-document ReferenceError
  after a callback intentionally closes its entry document; the callback's
  completed assertions and persisted migration/cleanup receipts are retained.

Archive: `_build_msvc/validation/shader-driven-material-morph/texture-factors-5d699ce5/`.
`repair-receipt.json` is the consolidated result; `gpu-seek.json`,
`gpu-continuous.json`, `standard-sampling.json`, `version1-upgrade.json`, actual
PNGs and build logs provide the corresponding evidence. The preparer's generic
`receipt.json` describes its separate full regression suite and is not this
repair's acceptance record.

## Minimal rendering checkpoint — 2026-10-06

- SDK 2026 Debug built successfully. Loaded native module SHA-256:
  `26f84838f7171521381330fea72fe801b25a48cf6883ab466f27dc935d40b0c2`.
- Seven SDK-independent logic tests passed, including material accumulation,
  Group/Flip expansion, cycle detection, and the roughness approximation.
- `tests/material/shader_binding_test.py` generates one model with two materials
  (plain and RGBA image), two material Morphs, a Group, and a Flip.
- Standard native InitRender/Sample checks passed for six weight combinations:
  base, additive, additive plus multiplicative, Group, Flip, and reset. All four
  fields were asserted against the evaluator formula. Frame 15 on a linear
  strength track also passed.
- Asynchronous RenderDocument on private AliasTrans document clones produced
  Standard frames 0 and 30 with interior Alpha `[128, 48]` and `[153, 72]`.
- Redshift native User Data contained the expected evaluated parameters.
  Default-material frame 30 produced Alpha `[153, 72]`. Isolating the existing
  color output into emission on render clones produced the same Alpha and plain
  RGB `[50, 101, 153]` at frame 0, `[76, 101, 153]` at frame 30. Thus the native
  reader consumed the animated value instead of its unchanged default.
- Evidence: `_build_msvc/validation/shader-driven-material-morph/minimum-26f84838/`.
  `minimum-receipt.json` records loaded module identity and five actual RGBA
  image hashes/pixels; `standard-sampling.json` records native shader samples.
- Stable test project: `_build_msvc/validation/material-morph-debug-test.c4d`.
  SetDocumentName/SetDocumentPath followed by SaveDocument with
  SAVEDOCUMENTFLAGS_DONTADDTORECENTLIST left GetChanged() false.

This is a minimum implementation checkpoint, not full feature acceptance.
Default BRDF RGB lighting, complete image matrix, preview authoring, migration,
Undo/Redo, save/reopen, copy isolation, and compatibility builds remain pending.
The generic MCP start_render PNG output had no alpha plane; it was not used as
Alpha evidence. The retained native C4DThread/MultipassBitmap runs explicitly
allocated and saved Alpha.

## Authoring checkpoint — 2026-10-06

Native module `3a632577e3a79929a565cb23d124fe820555d13294d1af0db1308c5c6df35209`
was loaded and checked in Cinema 4D 2026.4.0. Evidence is retained in
`_build_msvc/validation/shader-driven-material-morph/authoring-3a632577/`.

- Standard mixed preview, translated render-document copy, disabling preview,
  saving/reopening with preview off, and clearing preview on entering ANIM passed.
- PMX export while preview was active preserved all base-material fields and all
  Morph definitions exactly in the fixture parser.
- Material reordering preserved single-material targets. Removing the last
  additive offset restored its base contribution. New multiplicative offsets
  were neutral; changing operation preserved values; explicit reset zeroed an
  additive offset.
- A real older saved Standard scene upgraded only on the explicit button.
  Upgrade Undo and Redo passed. An artist noise shader was preserved. Creating
  an independent material and its Undo/Redo restored both model links and tags.
- Reconnecting a broken Standard output preserved the original child bitmap;
  repeated repair retained four outputs. Redshift recreated a removed reader;
  repeated repair retained eight hidden attributes for two materials. Redshift
  preview was off after save/reopen.
- Standard background document-clone renders at frames 0, 30, 15, then 0 produced
  Alpha `[128,48]`, `[153,72]`, `[141,60]`, `[128,48]`. Returning to frame 0
  reproduced both recorded RGB and Alpha samples. These images isolate color
  through luminance and do not establish highlight appearance under lighting.
- Same-frame formal strength values 0, .25, .75, 1, 0 were sampled successfully
  on preceding module `dfdfcf4b27cd4dc88d048332ad91c0f8057160476a7587089dd63e7c2c0a42ec`.
  An isolated-color Standard viewport visibly changed with the preview slider.
  The default fixture's lighting did not produce a useful BRDF comparison.
- SDK 2026, SDK 2024, and R20 Debug builds passed. The standalone test target
  passed 13 CTest groups (7 C++ groups and 6 Python fixture groups).

### Remaining acceptance limits

The new Redshift render attempt returned `RENDERRESULT_OUTOFMEMORY` twice, including
after a fresh host restart. A contemporaneous GPU inventory reported 6260 MiB used
and 1698 MiB free on an 8188 MiB RTX 4060; this is context, not proof of the exact
allocation which failed. Other user processes were preserved. The earlier minimum
Redshift images remain valid for their recorded binary, but do not certify this
new binary. The complete default-lighting/highlight and image-variant matrix,
continuous-versus-jump Redshift rendering, and object-copy conflict/repair matrix
remain unaccepted. No full-feature or release-ready claim is made.

## Alpha boundary and Redshift CPU — 2026-10-06

Module `37b51970afe39b21a75404717b670f77964a49edae90077ee2d4446454c753fa`
adds the pre-sample Alpha correction and rejects a missing required texture child.
Native sampling verified `96/255 * 1.8 = 0.677647...` instead of prematurely
clamping the factor to 1. An opaque PNG produced effective Alpha .75, and explicit
repair restored a removed bitmap child. Preview persistence was rechecked.
The two-quad fixture's normals were corrected to agree with its winding; a
Standard default-material render then produced nonblack RGB and expected Alpha.

Redshift **CPU-only** passed on this module, with core version 2026.7.0 and plugin
9da76b0d. The native preference description identified the RTX 4060 at parameter
2500 and Intel Core i9-14900KF at 2501. GPU was temporarily disabled, CPU enabled,
and Hybrid disabled. The renderer log explicitly reports CPU devices using Embree.
The original GPU=1 / CPU=1 / Hybrid=0 settings were restored and read back afterward.

- Preview frame: Alpha `[153,72]`, RGB `[[76,101,153],[11,23,73]]`.
- Timeline frames 0,30,15,0: Alpha `[128,48]`, `[153,72]`, `[141,60]`, `[128,48]`.
- First and returned frame-0 RGB/Alpha samples match exactly.
- A copied model sharing source materials reported a conflict. Creating independent
  materials for the copy gave separate mesh bindings; changing only its preview
  resulted in source/copy Alpha `.5` / `.575`, demonstrating isolation.

These CPU results supersede the earlier CPU-unattempted limitation. They do not
certify the GPU backend or constitute a performance comparison. Evidence, raw
native log, device restoration, and RGBA images are retained under
`_build_msvc/validation/shader-driven-material-morph/alpha-cpu-37b51970/`.

## Deletion, roughness and integration — 2026-10-06

Module `07a14041153af459a322e019a38e7ebff87b50b383d7a636b0cf09b0370ac2ca`
sets the owned Standard reflectance layer's roughness multiplier to 1.0, so
the scalar shader's mapped value is not scaled by the layer's 0.1 default.
Required texture children and the multiplier are included in binding validation.

- Native Standard preview persistence and referenced-Morph deletion passed.
  Group/Flip references now contract when a Morph is removed. The preceding
  `858a4845` deletion checkpoint additionally records Undo and Redo; those receipts
  retain their own identity rather than being attributed to the later module.
- Three actual lit Standard renders cover the base, increased specular power,
  and red specular offset. Power changes RGB; the color offset increases red;
  both preserve Alpha `[128,48]`. Comparisons use consistently decoded PNG samples
  in `highlight-image-comparison.json`. Lit BRDF comparisons do not require the
  other RGB components to remain identical, and saved-image color conversion is
  not mixed with the original render-buffer samples.
- All nine maintained native integration cases passed on this exact loaded
  module, including material strength 0/1/0, restoration after deletion, PMX
  remapping, artist emission preservation, save/reopen, motion and camera export.
  Per-case cleanup confirmed restoration of the original document.
- SDK 2026, SDK 2024 and R20 Debug builds passed. All 13 standalone CTest groups
  passed again after the native sampling helper was updated for internal shaders.

Evidence and file hashes are archived under
`_build_msvc/validation/shader-driven-material-morph/final-07a14041/`.
Redshift CPU image evidence remains attached to the earlier `37b51970` module;
the new Standard highlight images do not extend it to Redshift or GPU acceptance.

## Undo/save crash and texture authoring — 2026-10-06

The test host crashed while saving immediately after a Redshift binding repair
was undone. The original module was
`4af4a2214de34e955b6035131e717d5bdadabda90eca02c1e42e051e1666d1ff`.
Its binary, PDB, minidump, C4D bug report and LLDB transcript are archived in
`_build_msvc/validation/shader-driven-material-morph/crash-rs-undo-4af4a221/`.
Rider debugger requests did not return, so the matching dump was inspected with
the locally installed LLDB without launching or attaching another C4D process.

The dump shows exception `0xc0000005` through
`MMDMeshManagerObject::Write` → `WriteHashMap<BaseTag*, Int32>` →
`WriteBaseList2D<BaseTag>` → `BaseLink::SetLink`, with cached tag address
`0x00000005054e5100`. The derived mesh-tag cache can outlive tags replaced by Undo.
Saving now writes empty legacy cache slots while retaining authoritative Pose
Morph tags. Read and CopyTo rebuild runtime mappings; MorphUIData uses BaseLink
instead of raw tag addresses. Redshift graph transactions join the authoring
undo block with ADD; metadata and mesh User Data use CHANGE_SMALL, while Standard
shader hierarchies retain recursive undo.

An initial Python assertion incorrectly suggested a broken Redshift graph.
The complete traceback instead points to `GraphNode.IsValid()` on a null
`FindChild` result. Enumerating actual graph children confirms the graph survives
and the removed reader is absent after Undo, as expected. No graph-corruption
root-cause claim is made from that assertion.

Corrected module:
`7208de31d49dbf79a584077bd2ac3522bdb3c7d3d64e05f3878251f72a3884bd`.
Evidence is archived under
`_build_msvc/validation/shader-driven-material-morph/crash-fix-7208de31/`.

- Redshift repair: three Undo/Redo cycles, saving immediately before an evaluation
  pass and reopening at each step; all six live and reopened graphs match.
- Deep mesh Undo: three Undo/Redo cycles replace the mesh/tag substructure; all
  six immediate saves and reopens preserve point data, tag inventory and Pose
  Morph count. This exercises cache lifetime independently of material undo.
  The same cycles also passed with authored Vertex and UV Morphs. After reopening,
  model strengths 0/1/.5/0 reached both Pose Morph tag sliders. A control export
  made immediately after fresh import matched the Undo/reopen export. Both have
  an empty UV offset list, so this does **not** certify UV PMX round-trip; that
  separate export limitation is retained in `mesh-morph-export-control.json`.
- All nine maintained native integration cases passed on this exact module,
  with the original private baseline document restored and cleanup complete.
  An earlier run had no surviving initial blank document and is retained as
  `receipt-missing-initial-document.json`, not an acceptance receipt.
- Standard and Redshift each passed ten texture-path transitions across two
  materials, including an opaque image, cleared path and RGBA image. Undo/Redo
  restored both the authored field and the render binding. Retained inactive
  texture branches are reused; Redshift node counts remain at ten.
- Standard mixed-preview persistence, render cloning, last-offset deletion,
  material reordering, neutral reset and PMX round-trip passed again.
- The Standard preview image has Alpha `[153,72]`. Redshift CPU preview and frame
  30 have Alpha `[153,72]`, frame 15 `[141,60]`, and the base `[128,48]`.
  Returning to frame 0 exactly matches the initial RGB and Alpha samples. The
  original GPU=1 / CPU=1 / Hybrid=0 settings were restored and read back.
- SDK 2026, 2024 and R20 Debug builds passed, as did all fourteen standalone
  CTest groups. These results do not certify a Release installer or GPU rendering.

The previous `4af4a221` CPU lit/highlight images remain evidence for that exact
module only; it is not accepted overall because it exhibited the save crash.
Full release acceptance remains open, including the complete renderer/image
matrix and the remaining authoring/upgrade combinations.

## Batch upgrade Undo and Release acceptance — 2026-10-07

The production Release module `c7ad243ee135a7135f2e58ff6c99585b4d9ae95b2562b3a1501faac281700478`
exposed a separate two-material upgrade defect: one Undo/Redo did not restore
both Redshift materials together. A native transaction matrix reproduced the
split with automatic graph ADD undo, including when no material snapshot was
recorded. Full material CHANGE snapshots with graph UndoMode NONE restored both
graphs in one step. This supersedes the earlier ADD/CHANGE_SMALL strategy above;
it does not change the previously diagnosed dangling mesh-tag cache crash.

Corrected Release module:
`5a8929a829deb8e517b91add05022284b9bbf1eefb19eee7201dd78c53174159`.
The regression bridge is disabled. Fixture import and material PMX export use
the maintained production MCP operations, while binding edits use the actual
model parameters and authoring buttons. Evidence, binary/PDB, failure/control
receipts, scripts, images and hashes are archived under
`_build_msvc/validation/shader-driven-material-morph/batch-undo-5a8929a8/`.

- Standard and Redshift two-material legacy upgrades each pass three Undo/Redo
  cycles. Every step saves immediately and reopens with matching structure;
  unrelated artist nodes/shaders and retained bitmap paths survive.
- Redshift missing-reader repair passes three Undo/Redo cycles with immediate
  save/reopen. Deep mesh/tag Undo passes the same six checks on a fixture with
  authored Vertex and UV Morphs, without another save crash.
- Independent material creation passes two Undo/Redo cycles per material for
  each renderer. The copied model reports a shared-owner conflict before
  isolation. The live source/copy opacity is `.5` / `.575`; Redshift save/reopen
  clears preview and restores both to `.5`, preserving remapped ownership.
- Standard mixed preview, render-clone preservation, ordinary reopen, ANIM
  reset, neutral initialization/reset, operation switching, material reordering
  and material PMX round-trip pass. Last-offset deletion passes three Undo/Redo
  cycles with actual shader samples. Redshift texture edits pass twelve
  Undo/Redo checks across the two materials after the transaction change.
- Each renderer survives 100 repeated preview evaluations with unchanged
  shader/node counts. Reverse-sync attempts preserve the stored base Alpha
  during preview, in ANIM and for managed bindings in EDIT.
- Actual Standard and Redshift GPU preview images have Alpha `[153,72]`.
  GPU RGB samples are `[[76,101,153],[11,23,73]]`. The next GPU timeline render
  fails with `RENDERRESULT_OUTOFMEMORY`; the RTX 4060 reports 7371/8188 MiB used
  (587 MiB free). The single successful GPU image is not sequence acceptance.
- On this same module, Redshift CPU frames 0/30/15/0 have Alpha
  `[128,48]`, `[153,72]`, `[141,60]`, `[128,48]`. The first and final RGB/Alpha
  samples are identical. Original GPU/CPU/hybrid preferences are restored and
  read back. Private documents are cleaned up and the original private baseline
  is restored before the task-owned C4D process is closed.
- SDK 2026, SDK 2024 and R20 Release builds pass. All fifteen standalone tests
  pass in their built Debug configuration; an initial invocation specifying
  Release could not find the eight native test executables and is not counted
  as a test failure of the implementation. Python helper compilation and
  `git diff --check` also pass.

Remaining acceptance includes full material/Morph deletion confirmation flows,
the complete lighting/highlight matrix and successful GPU sequence rendering.
The independent UV PMX export limitation recorded above remains out of this
material-only acceptance. The installer archived by the separate release task
on 2026-10-06 predates this fix and has **not** been repackaged with this module.

## GPU retry — 2026-10-07

Retested the identical `5a8929a8` Release module in a fresh task-owned Cinema 4D
process, GPU enabled with CPU and hybrid rendering disabled. The first retry
returned OUTOFMEMORY at frame 0. After available GPU memory increased from about
843 MiB to 2142 MiB, a second attempt successfully rendered
`0 → 15 → 30 → 0 → 30 → 15 → 0`. Every repeated frame has identical sampled
RGB and Alpha. Alpha at frames 0/15/30 is `[128,48]` / `[141,60]` / `[153,72]`.
This closes the short GPU seek-sequence evidence gap on the current Release.

An additional 0-through-30 every-frame sequence passed frames 0, 1, 2 and 3,
then returned OUTOFMEMORY at frame 4. Available GPU memory was about 582 MiB.
The full consecutive-frame sequence remains unaccepted; no pixel assertion or
native crash occurred in this attempt. Memory snapshots alone do not establish
which allocation or process caused the renderer failure. Original device
preferences were restored and read back, private test documents were closed,
and the task-owned C4D process was stopped. No other process was stopped.

Separate success/failure receipts, all completed PNGs, memory snapshots, scripts,
loaded-module identity and cleanup evidence are archived under
`_build_msvc/validation/shader-driven-material-morph/gpu-retry-5a8929a8/`.

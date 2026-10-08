# Focused native material matrix

`material_fixture_matrix.prepare(directory)` creates nine deterministic PMX
cases and their textures using the Python standard library. The native runs add
a tenth case using Cinema 4D's JPEG codec. The inputs distinguish these paths:

| Input | What it detects |
| --- | --- |
| RGBA with A=0 / A=255 | Transparent and opaque endpoints |
| Fixed gray RGB, A=0/64/128/255 | RGB or luminance incorrectly used as alpha |
| Varying RGB, fixed A=128 | Texture color loading independently from alpha |
| RGB PNG, TGA24, JPEG | Images without an embedded alpha channel |
| RGBA TIFF | Embedded alpha incorrectly rejected by an extension whitelist |
| No texture | Texture factors incorrectly applied without image sampling |
| Texture alpha factor 1/.5/0, then reset | Missing, accumulated or stale factors |

Every textured case uses a relative path under `纹理/阿芙_*.png`, `.tga`, `.tif`
or `.jpg`. PMX geometry is a UV-mapped quad, not an arbitrary real asset. Fixture
paths, lengths and SHA-256 values are recorded. PMX inputs include a real material
morph and are independently parsed by the existing PMX fixture reader.

## Run without Cinema 4D

```powershell
python -m unittest discover -s tests/material -p test_fixture_matrix.py -v
```

These tests check input formats, independent channels, the image oracle and
asynchronous worker ownership. They do not assert that a renderer has executed.

## Native shader and graph checks

Run coordination on Cinema 4D's main thread with an existing
`c4d_runtime_regression.Suite`. The Suite must belong exclusively to this run.
The caller supplies the normal production import callback, selecting the
appropriate renderer and targeting `suite.doc`; the callback returns the imported
model or `None`. A strength callback can use the normal production morph API or
the actual public strength description resolved from the imported model:

```python
import sys
sys.path.insert(0, "C:/code/C4D_MMD_Tool/tests/material")
import native_diffuse_test
import native_redshift_test

def set_strength(suite, value):
    identifier = suite.morph_strength_id(suite.model, "tint")
    suite.model[identifier] = value

# import_standard(suite, path) and import_redshift(suite, path) are the caller's
# production import callbacks; they must import into this exact owned document.
standard = native_diffuse_test.run_matrix(suite, import_standard, set_strength)
redshift = native_redshift_test.run_matrix(suite, import_redshift, set_strength)
```

Each case evaluates strengths 0, 1, .5, 0, .5 on one model, saves/reopens it,
evaluates again and resets to zero. Standard samples the actual plugin shader
and original bitmap child at four UV positions, with color conversion disabled
and with document conversion enabled. RGB is compared against the decoded child
sample, never against an assumed sRGB code value in a linear rendering space.
Opacity is checked against the actual input A independently from RGB.

Redshift checks its actual graph, including coefficient values, exact file URL,
the sampler A splitter connection and absence of duplicate nodes. A graph check
does not establish GPU rendering or final appearance.

The routines write `standard_matrix_receipt.json` /
`redshift_matrix_receipt.json` after each successful step. On failure they save
the private failing scene and the partial receipt before closing their exact
registered documents. The original failure remains an exception. Successful
and failing runs restore the Suite's original live user document.

## Asynchronous actual image checks

Store the session in a persistent host module, so its worker remains strongly
referenced between calls. Each of the following operations is a separate main
thread callback; never call `Wait()` or poll in a blocking loop:

```python
import native_render_matrix

session = native_render_matrix.RenderMatrixSession(
    suite, import_redshift, set_strength, renderer="redshift")
session.start("alpha_full")              # starts, returns immediately
session.status()                         # a subsequent callback
session.collect()                        # only after status.state == "ready"

session.start("gray_varied_alpha", .5, reopen=True)
session.status()                         # repeat in separate callbacks as needed
session.collect()
session.close()
```

Use `renderer="standard"` with the Standard import callback for the matching
Standard run. Always render/collect `alpha_full` first: it establishes the quad's
actual image bounds and U orientation from its four gray stripes. Other cases
reuse these four interior regions even when the model is fully transparent.
The oracle compares the actual rendered alpha values against
`imageAlpha * effectiveDiffuseAlpha * effectiveTextureAlphaFactor`, allowing
8-bit quantization and sampling tolerance. It rejects a white fallback image
for the varying RGB case. No third-party image package is required.

The default `shading="isolated_channels"` pass copies the imported color shader
to Standard luminance, or connects the imported Redshift sampler to emission.
Only the private AliasTrans clone is changed, and the imported alpha branch is
preserved. This verifies actual image loading and opacity independently from
BRDF, lights and exposure. Before isolation, the original imported shader/graph
is sampled and recorded. Redshift ports are checked for existence; an absent
renderer or port is an error and cannot trigger a Standard fallback.

To record unchanged material behavior, after the isolated calibration run:

```python
session.start("alpha_full", shading="default")
# status -> collect
session.start("varied_rgb_fixed_alpha", .5, shading="default", reopen=True)
# status -> collect
```

Default images assert opacity and record RGB for visual inspection. They do not
claim equivalent Standard/Redshift lighting or final RGB appearance. The receipts
explicitly keep `default_rgb_visual_acceptance=false`. Renderer, pass, image
SHA-256, coefficient snapshots, alpha measurements and whether the OCIO view
transform was baked in the render are recorded. Save the caller's loaded module
identity separately; a source fingerprint is not a loaded DLL hash.

Each render uses one private, detached document clone and one owned native
`C4DThread`. `collect()` persists the actual PNG before numeric assertions, then
releases the finished worker and closes the exact Suite documents. A running
`close()` requests asynchronous cancellation and returns `cleanup_pending=true`.
Keep that session alive, poll its status in another callback, then call `close()`
again once stopped. Do not free its document, create another Suite render or
discard the worker while cleanup is pending. A host timeout also requires status
reconciliation; it does not prove that rendering stopped.

## Ordinary RS highlight rendering

`native_rs_highlight_test.py` prepares a black-diffuse sphere with one fixed
Redshift light. It imports through the production interface, removes only the
fixture's binding, and drives ordinary synchronization through the MMD UI fields.
Broad/narrow white, red and zero-specular cases record native PNGs separately.
Rendered images remain `rendered_pending_analysis`; a successful render alone
does not prove the expected highlight response or MMD fidelity.

Reserve the C4D host before running this helper: preferences and renderer state
are shared with other scripts. The module registry protects its own sessions,
not unrelated helpers. Use the retained factory across separate MCP callbacks:

```python
import native_rs_highlight_test as highlight
highlight.create_session(c4d, r"S:\tmp\rs-highlight-fresh")
highlight.active_session().start("white_broad", "cpu")
# In a later callback; repeat collect while running is true.
highlight.active_session().collect()
# After collecting each image, start the next case/device, then finally:
highlight.active_session().close()
```

`close()` requests asynchronous cancellation if its own worker is running.
Keep the session and poll/close later; never discover or cancel workers by class
name or GC scanning. The host-free `test_highlight_lifecycle.py` verifies retained
references, duplicate rejection, deferred cleanup and device restoration. These
fixtures are not native rendering acceptance.

`analyze_rs_highlights.py` performs offline response checks. For **each** requested
device, collect `white_broad`, `white_narrow`, `red`, `zero`, a second
`white_narrow`, and `white_narrow` with `reopen=True` (6 renders per device).
One complete device matrix is sufficient for material response acceptance.
To additionally require both matrices and their pixel comparison, pass
`--compare-devices` to the analyzer (12 renders total).
Then close the session and run with a Python installation containing Pillow:

```powershell
python tests/material/analyze_rs_highlights.py S:\tmp\rs-highlight-fresh --output S:\tmp\rs-highlight-analysis.json
```

The output must be a new file; original receipts are never overwritten. The
analyzer resolves PNGs beside `renders.json`, so archived runs remain readable.
It requires the profile, module hash, exact case inputs, successful render
results, image hashes, consistent device selections and successful cleanup.
Blank/transparent images, unchanged broad/narrow highlights, wrong hue,
nonzero disabled specular, incomplete repetition/reopen coverage and excessive
pixel differences fail. Every metric and tolerance is recorded in the report.

Profile v1 uses the central 60%-diameter disk and half-peak area for width;
narrow/broad area must be at most .75, and red must dominate green/blue by 3x.
Other byte-scale image thresholds are listed in the report's `limits`. These
thresholds are **provisional until checked against native diagnostic renders**.
`response_checks_passed` means those bounded response checks passed. It does not
certify native MMD fidelity or actual GPU execution: device selections are
recorded preferences, and backend execution still requires renderer evidence.
The 18 synthetic analyzer tests and PNG decode smoke check verify the validator
itself. Separately, the six-image ordinary RS native response run is archived at
`_build_msvc/validation/remaining/rs-standard-highlight-native-20261007/`:
Power width, red/zero specular, exact repeat and save/reopen pass on d6ca05c6
with C4D 2026.4.0 / RS 2026.9.0. This fixed-scene response evidence is not native
MMD BRDF equivalence or a full managed-binding lighting matrix.

## Shader-driven authoring regression

Version-2 bindings preserve texture Mul/Add independently and use the Saba
reference sampling operation. `shader_binding_test.prepare(...,
texture_multiply=(.5, 1.25, .8, .5))` also exercises non-neutral multiplication
RGB and Alpha; pass the same tuple to `standard_snapshot`. The older matrix
oracle above describes the legacy combined-factor path and must not be used as
the expected output for version-2 bindings. Image opacity is now image Alpha
times Diffuse Alpha; texture-factor Alpha participates in the RGB operation.
Saba agreement is not native MMD fidelity acceptance.

For GPU checks, `start_render(..., isolated=True)` connects the complete managed
texture math output to emission on a private clone. It does not bypass the new
math branch by connecting the raw sampler. Record the actual loaded module,
GPU/CPU preferences, RGBA images, and repeated-frame results separately from
the pure algorithm checks.

`shader_binding_test.production_suite(c4d, manifest)` adapts fixture import/export
to the maintained production MCP operations. This permits native tests against a
normal Release module with the regression bridge disabled. Call it with the same
private-document ownership and cleanup discipline as the regression Suite.

The binding helper covers mixed preview, shader sampling, last-offset editing,
material PMX export, Redshift repair, two-material legacy upgrade, independent
copy ownership and deep mesh-cache Undo. In particular,
`redshift_upgrade_undo_roundtrip` checks both materials after a **single** Undo
or Redo, then saves immediately and verifies the reopened graph. Checking only
one material misses the split transaction defect. `independent_binding_undo_roundtrip`
checks shared-owner diagnostics and owner remapping through Undo/Redo.

Render helpers return a retained asynchronous worker. Collect it in a later
callback and restore any temporary renderer device preferences on success or
failure. A passing CPU image must not be reported as GPU acceptance.

`native_toon_test.py` covers the separate RS Toon profile. Its generated fixtures
use ordinary UV and contain explicit Toon RGBA and edge offsets, plus a small
PMX character with an alpha-cutout fringe. Use
`production_suite(c4d, manifest, material_type="redshift_toon")` for import;
`binding_snapshot` reads all sixteen attributes and checks the fixed graph,
and `conversion_roundtrip` checks actual TextureTag assignment plus three
Undo/Redo cycles, saving immediately after each action. `start_render` and
`collect_render` retain a private render clone between callbacks. The character
is a generated fixture, not an original MMD image reference. Record renderer
device logs and reject failed or resource-limited renders even if a bitmap exists.

`material_disabled_import_roundtrip(c4d, manifest)` exercises Standard and
RS Toon with renderer materials disabled, for merged and split meshes, through
the production interface and immediate save/reopen. It guards the PMX path
resolver crash while confirming no material or TextureTag is created.

`shader_binding_test.base_parameter_binding(suite)` edits base parameters through
the MMD UI parameter interface without a sync button or explicit evaluation.
Run it on a fresh binding fixture for Standard, RS Standard and RS Toon. It
checks native Standard shader samples / RS object attributes, Morph preview
addition and reset, material naming, RS preview defaults and stable node IDs.

`native_toon_specular_test.run(c4d, output)` runs a blocking six-sphere comparison
in a task-owned c4dpy process, never through the interactive main-thread bridge.
It imports the production Toon recipe, compares the invalid `linear` gradient
knot ID with the correct `linearknot`, and renders zero Specular / Power 8 /
Power 64 after saving and reopening on GPU and CPU. Reader defaults isolate
the shading recipe; this is not the mesh-attribute Morph image matrix.

All render fixtures use `native_render_matrix.ensure_redshift_post` to reuse
the document's existing Redshift VideoPost. Multiple Redshift posts fail
preflight: adding a duplicate can leave the renderer waiting on its own context.

`native_material_page_test.run(c4d, scene_path)` reads the actual saved model's
material description and parameters in a fresh c4dpy process before production
import can warm the RS capability cache. It verifies that status reads stay
cache-only, walks first / stockings / last / no selection, and preserves the
document's material count. This callback check does not replace GUI tab-switch
or renderer-preview crash reproduction.

`native_sphere_test.prepare/run` exercises the production revision 5 Sphere
Multiply/Add recipe, sixteen mesh attributes, independent factor RGBA, preview
reset, path/mode edits, dormant artist connection protection, and immediate
save/reopen after Undo/Redo. `native_sphere_visual_test.run` imports the actual
PMX, renders the previous stockings recipe and revision 5 under the same light,
checks CPU/GPU and repeated GPU rendering after reopening, and records a separate
frontal directional-light study. It has no native-MMD equivalence claim.

`native_standard_sphere_test.run(suite, renderer)` validates new Standard and
RS Standard Matcap bindings. It checks independent RGBA Morph formulas, ten
RS mesh attributes with preserved field IDs, sampling and artist input
protection, opacity isolation, mode/path edits and immediate Undo/Redo reopen.
`native_standard_sphere_visual_test.run` renders an unlit directional-gradient
sphere from two camera directions and the actual PMX stockings under one
distant light. Standard uses its CPU renderer; RS is tested on GPU and CPU.
The unlit probe verifies projection independently of Standard/PBR lighting.

`native_toon_acceptance_test.run_contracts` checks persisted type choices,
UI mode/preview gates, importer/entry recipe equality, document-preserving
capability queries and native graphs with multiple surfaces, multiple outputs,
a removed required input port, a missing role or the wrong asset. `run_faults`
requires an explicit regression build and checks allocated-attribute, bound,
assigned and linked failure stages, ambiguous selections, unavailable renderer
imports and immediate conversion Undo/Redo reopen. Shipping builds compile out
all private fault controls.

`native_toon_visual_acceptance_test.run` renders managed Toon attributes on
saved/reopened documents while an unrelated document is active. Run each
`groups` slice and each `compute_devices` choice in a separate private c4dpy
process to release renderer resources between batches. Its matrix includes
0/15/30/0/reset, Material/Group/Flip tracks, mixed preview, edge-off/zero/wide,
zero Specular, an active default Contour with an unmanaged positive control,
both mesh layouts and a same-light actual-PMX Standard/Toon comparison.
`analyze_toon_acceptance.py` checks native attribute values and image results;
failed resource attempts remain separate from passing receipts.
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

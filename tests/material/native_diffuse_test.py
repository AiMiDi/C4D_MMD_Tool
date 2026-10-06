"""Native texture sampling regressions for Standard PMX diffuse RGBA.

Call ``prepare(directory)`` outside C4D or inside its Python process, then call
``run(suite)`` with a c4d_runtime_regression.Suite. Sampling uses the real loaded
plugin shader; no render preview, synthetic pass flag, or private model is used.
The caller owns document restoration and the final receipt/build identity.
"""

from pathlib import Path
import hashlib
import json
import math
import struct
import zlib


def _pack(format_, *values):
    return struct.pack("<" + format_, *values)


def _text(value):
    encoded = value.encode("utf-8")
    return _pack("i", len(encoded)) + encoded


def _png():
    # A colored semi-transparent image makes RGB-as-alpha observable. Alpha 96
    # differs from every RGB component, so a green-as-alpha bug cannot pass.
    def chunk(name, data):
        return struct.pack(">I", len(data)) + name + data + struct.pack(">I", zlib.crc32(name + data))

    row = b"\0" + bytes((64, 128, 192, 96)) * 2
    header = struct.pack(">IIBBBBB", 2, 2, 8, 6, 0, 0, 0)
    return b"\x89PNG\r\n\x1a\n" + chunk(b"IHDR", header) + chunk(b"IDAT", zlib.compress(row * 2)) + chunk(b"IEND", b"")


def _pmx(with_morph, texture_factor_morph=(0., 0., 0., 0.), *,
         texture_path="colored-alpha.png", diffuse=(.2, .4, .6, .5), quad=False):
    result = bytearray(b"PMX " + _pack("fB", 2., 8) + bytes((1, 0, 4, 4, 4, 4, 4, 4)))
    for value in ("diffuse RGBA", "diffuse RGBA", "generated material fixture", "generated material fixture"):
        result.extend(_text(value))
    vertices = (((-1., -1., 0.), (0., 0.)), ((1., -1., 0.), (1., 0.)),
                ((1., 1., 0.), (1., 1.)), ((-1., 1., 0.), (0., 1.))) if quad else (
        ((0., 0., 0.), (0., 0.)), ((1., 0., 0.), (1., 0.)), ((0., 1., 0.), (0., 1.)))
    faces = (0, 1, 2, 0, 2, 3) if quad else (0, 1, 2)
    result.extend(_pack("i", len(vertices)))
    for position, uv in vertices:
        result.extend(_pack("3f3f2fBif", *position, 0., 0., 1., *uv, 0, 0, 1.))
    result.extend(_pack("i", len(faces)) + _pack(str(len(faces)) + "I", *faces))
    result.extend(_pack("i", int(texture_path is not None)))
    if texture_path is not None:
        result.extend(_text(texture_path))
    result.extend(_pack("i", 1) + _text("tinted alpha") + _text("tinted alpha"))
    result.extend(_pack("4f3ff3fB4ffiiBBi", *diffuse, 0., 0., 0., 10.,
                        0., 0., 0., 1, 0., 0., 0., 1., 0., 0 if texture_path else -1, -1, 0, 0, -1))
    result.extend(_text("") + _pack("i", len(faces)))
    result.extend(_pack("i", 1) + _text("root") + _text("root"))
    result.extend(_pack("3fiiH3f", 0., 0., 0., -1, 0, 0x1e, 0., .1, 0.))
    result.extend(_pack("i", int(with_morph)))
    if with_morph:
        result.extend(_text("tint") + _text("tint") + _pack("BBiiB", 4, 8, 1, 0, 1))
        result.extend(_pack("28f", .1, 0., 0., .1, *([0.] * 12), *texture_factor_morph, *([0.] * 8)))
    result.extend(_pack("iii", 0, 0, 0))  # Display frames, rigid bodies, joints.
    return bytes(result)


def prepare(directory):
    directory = Path(directory).resolve()
    directory.mkdir(parents=True, exist_ok=True)
    result = {}
    for name, data in (("colored-alpha.png", _png()), ("diffuse_no_morph.pmx", _pmx(False)),
                       ("diffuse_with_morph.pmx", _pmx(True))):
        path = directory / name
        path.write_bytes(data)
        result[name] = {"path": str(path), "sha256": hashlib.sha256(data).hexdigest(), "bytes": len(data)}
    return result


def _vector(value):
    return [float(value.x), float(value.y), float(value.z)]


def _assert_near(actual, expected, message):
    if len(actual) != len(expected) or any(not math.isfinite(a) or abs(a - e) > 1e-5 for a, e in zip(actual, expected)):
        raise AssertionError(f"{message}: actual={actual}, expected={expected}")


def _sample(suite, shader, alpha, channel):
    c4d = suite.c4d
    child = shader.GetDown()
    if shader.GetType() != 1068715 or child is None or child.GetType() != c4d.Xbitmap:
        raise AssertionError("Expected one MMD coefficient wrapper around the original bitmap")
    if child.GetDown() is not None or child.GetNext() is not None:
        raise AssertionError("Diffuse or morph synchronization nested or duplicated a wrapper")

    irs = c4d.modules.render.InitRenderStruct(suite.doc)
    irs.linear_workflow = False
    irs.document_colorprofile = c4d.DOCUMENT_COLORPROFILE_DISABLED
    result = shader.InitRender(irs)
    if result != c4d.INITRENDERRESULT_OK:
        raise AssertionError("Native material shader failed InitRender: " + str(result))
    try:
        if not (shader.GetRenderInfo() & c4d.SHADERINFO_ALPHA_SUPPORT):
            raise AssertionError("Wrapper lost the bitmap's alpha sampling capability")
        data = c4d.modules.render.ChannelData()
        data.p = c4d.Vector(.5, .5, 0.)
        data.n = c4d.Vector(0., 0., 1.)
        data.d = c4d.Vector(0.)
        data.t = data.off = data.scale = 0.
        # Match the actual material channel as well as the alpha request. A
        # bare TEX_ALPHA leaves GET_TEX_CHANNEL at COLOR; color management then
        # interprets even the opacity sample in the document's rendering space.
        flags = c4d.TEX_ALPHA if alpha else 0
        data.texflag = (flags & ~0x3f0) | (channel << 6)  # SDK CALC_TEXINFO.
        # The child is already initialized by the wrapper. Sampling it here
        # gives a color-space-independent baseline without double InitRender.
        return {"sample": _vector(shader.Sample(data)), "bitmap": _vector(child.Sample(data)),
                "texflag": data.texflag, "channel": channel}
    finally:
        shader.FreeRender()


def _snapshot(suite, strength):
    c4d = suite.c4d
    material = suite.doc.GetFirstMaterial()
    if material[c4d.MATERIAL_USE_ENVIRONMENT]:
        raise AssertionError("A sphere-mode None material acquired an Environment contribution")
    color = _sample(suite, material[c4d.MATERIAL_COLOR_SHADER], False, c4d.CHANNEL_COLOR)
    color_alpha = _sample(suite, material[c4d.MATERIAL_COLOR_SHADER], True, c4d.CHANNEL_COLOR)
    opacity = _sample(suite, material[c4d.MATERIAL_ALPHA_SHADER], True, c4d.CHANNEL_ALPHA)
    diffuse = [.2 + .1 * strength, .4, .6]
    alpha = .5 + .1 * strength
    _assert_near(color["sample"], [a * b for a, b in zip(color["bitmap"], diffuse)], "Diffuse RGB applied incorrectly")
    _assert_near(color_alpha["sample"], color_alpha["bitmap"], "Diffuse RGB contaminated bitmap alpha")
    _assert_near(opacity["sample"], [a * alpha for a in opacity["bitmap"]], "Diffuse alpha applied incorrectly")
    _assert_near(opacity["bitmap"], [96. / 255.] * 3, "Bitmap RGB/color-profile sample was used instead of raw channel alpha")
    return {"strength": strength, "color": color, "color_alpha": color_alpha, "opacity": opacity}


def run(suite):
    try:
        return _run_original(suite)
    finally:
        suite.close()


def _run_original(suite):
    fixtures = prepare(suite.output / "material-inputs")
    suite.manifest["fixtures"].update(fixtures)
    evidence = {"fixtures": fixtures, "no_material_morph": [], "with_material_morph": []}
    suite.new_model("diffuse_no_morph.pmx")
    evidence["no_material_morph"].append(_snapshot(suite, 0.))
    suite.reopen("diffuse_no_morph_reopen")
    evidence["no_material_morph"].append(_snapshot(suite, 0.))

    suite.new_model("diffuse_with_morph.pmx")
    suite.model[suite.ids["MODEL_MODE"]] = suite.ids["MODEL_MODE_ANIM"]
    for strength in (0., 1., .5, 0., .5):
        suite.call("set_strength", morph_index=0, strength=strength)
        suite.evaluate(0)
        evidence["with_material_morph"].append(_snapshot(suite, strength))
    suite.reopen("diffuse_with_morph_reopen")
    evidence["with_material_morph"].append(_snapshot(suite, .5))
    suite.call("set_strength", morph_index=0, strength=0.)
    suite.evaluate(0)
    evidence["with_material_morph"].append(_snapshot(suite, 0.))
    evidence["native_shader_sampling"] = True
    evidence["full_image_render"] = False
    return evidence


def sample_matrix_shader(suite, shader, alpha, channel, uv, profile):
    c4d = suite.c4d
    wrapper = shader.GetType() == 1068715
    child = shader.GetDown() if wrapper else None
    if wrapper and (child is None or child.GetDown() is not None or child.GetNext() is not None):
        raise AssertionError("Repeated synchronization nested or duplicated a material wrapper")
    irs = c4d.modules.render.InitRenderStruct(suite.doc)
    if profile == "raw":
        irs.linear_workflow = False
        irs.document_colorprofile = c4d.DOCUMENT_COLORPROFILE_DISABLED
    if shader.InitRender(irs) != c4d.INITRENDERRESULT_OK:
        raise AssertionError("Native fixture shader could not load its texture")
    try:
        data = c4d.modules.render.ChannelData()
        data.p, data.n, data.d = c4d.Vector(*uv, 0.), c4d.Vector(0., 0., 1.), c4d.Vector(0.)
        data.t = data.off = data.scale = 0.
        data.texflag = ((c4d.TEX_ALPHA if alpha else 0) & ~0x3f0) | (channel << 6)
        return {"sample": _vector(shader.Sample(data)), "child": _vector(child.Sample(data)) if child else None,
                "shader_type": shader.GetType(), "child_type": child.GetType() if child else None,
                "profile": profile, "texflag": data.texflag}
    finally:
        shader.FreeRender()


def snapshot_matrix(suite, case, strength, profile="raw"):
    import material_fixture_matrix as matrix
    c4d, material = suite.c4d, suite.doc.GetFirstMaterial()
    if material is None:
        raise AssertionError("Standard matrix import created no material")
    rgb_factor, alpha_factor = matrix.expected_coefficients(case, strength)
    samples = []
    for index, u in enumerate(matrix.SAMPLE_U):
        color = sample_matrix_shader(suite, material[c4d.MATERIAL_COLOR_SHADER], False,
                                     c4d.CHANNEL_COLOR, (u, .5), profile)
        opacity = sample_matrix_shader(suite, material[c4d.MATERIAL_ALPHA_SHADER], True,
                                       c4d.CHANNEL_ALPHA, (u, .5), profile)
        if case["stripes"] is not None:
            if color["child"] is None:
                raise AssertionError("A texture color lost its coefficient wrapper")
            _assert_near(color["sample"], [value * factor for value, factor in zip(color["child"], rgb_factor)],
                         "Texture color coefficient was applied more than once or lost")
        elif profile == "raw":
            _assert_near(color["sample"], rgb_factor, "Plain diffuse color did not match its material coefficient")
        expected_alpha = (case["stripes"][index][3] / 255. if case["alpha"] else 1.) * alpha_factor
        _assert_near(opacity["sample"], [expected_alpha] * 3,
                     "Alpha was color-managed, extracted from RGB, or missed the texture factor")
        if case["alpha"]:
            requested = sample_matrix_shader(suite, material[c4d.MATERIAL_COLOR_SHADER], True,
                                             c4d.CHANNEL_COLOR, (u, .5), profile)
            _assert_near(requested["sample"], requested["child"], "Diffuse RGB contaminated image alpha")
        samples.append({"u": u, "color": color, "opacity": opacity, "expected_alpha": expected_alpha})
    return {"case": case["name"], "strength": strength, "profile": profile, "samples": samples}


def load_matrix_model(suite, case, import_model=None):
    """Create a private scene and resolve exactly one imported model."""
    if import_model is None:
        suite.new_model(case["pmx"])
    else:
        cleanup = suite.close()
        if cleanup["errors"]:
            raise RuntimeError("Previous owned material document could not be closed")
        suite.new_document("Material matrix " + case["name"])
        suite.model = import_model(suite, suite.fixture(case["pmx"]))
        models = [node for node in suite.walk(suite.doc.GetFirstObject()) if node.GetType() == 1056724]
        if len(models) != 1 or (suite.model is not None and suite.model != models[0]):
            raise AssertionError("Matrix import must create exactly one model in its owned document")
        suite.model = models[0]
    suite.model[suite.ids["MODEL_PHYSICS_ENABLED"]] = False
    suite.model[suite.ids["MODEL_MODE"]] = suite.ids["MODEL_MODE_ANIM"]
    suite.evaluate(0)
    return suite.model


def apply_matrix_strength(suite, strength, set_strength=None):
    if set_strength is None:
        suite.call("set_strength", morph_index=0, strength=strength)
    else:
        set_strength(suite, strength)
    suite.evaluate(0)


def run_matrix(suite, import_model=None, set_strength=None, *, snapshot=None):
    """Focused native sampling. Callbacks also support a normal production build."""
    import material_fixture_matrix as matrix
    evidence = {"fixtures": {}, "cases": [], "status": "running",
                "native_shader_sampling": snapshot is None, "native_graph_inspection": snapshot is not None,
                "full_image_render": False}
    sample = snapshot or snapshot_matrix
    renderer = "standard" if snapshot is None else "redshift"
    receipt = suite.output / (renderer + "_matrix_receipt.json")
    current_name = "prepare"

    def persist():
        receipt.write_text(json.dumps(evidence, indent=2, ensure_ascii=False), encoding="utf-8")

    try:
        prepared = matrix.prepare(suite.output / (renderer + "-matrix-inputs"))
        matrix.add_native_jpeg(suite, prepared)
        suite.manifest["fixtures"].update(prepared["fixtures"])
        evidence["fixtures"] = prepared["fixtures"]
        persist()
        for case in prepared["cases"]:
            current_name = case["name"]
            load_matrix_model(suite, case, import_model)
            steps = (0., 1., .5, 0., .5) if case["morph"] else (0.,)
            snapshots = []
            evidence["cases"].append({"case": case["name"], "snapshots": snapshots, "status": "running"})
            for strength in steps:
                if case["morph"]:
                    apply_matrix_strength(suite, strength, set_strength)
                suite.evaluate(0)
                profiles = ("raw", "document") if snapshot is None else ("graph",)
                snapshots.extend(sample(suite, case, strength, profile) for profile in profiles)
                persist()
            suite.reopen("matrix_" + case["name"] + "_reopened")
            suite.evaluate(0)
            snapshots.append(sample(suite, case, steps[-1]))
            if case["morph"]:
                apply_matrix_strength(suite, 0., set_strength)
                snapshots.append(sample(suite, case, 0.))
            evidence["cases"][-1]["status"] = "passed"
            persist()
        evidence["status"] = "passed"
        return evidence
    except Exception as error:
        evidence.update(status="failed", failed_case=current_name,
                        error={"type": type(error).__name__, "message": str(error)})
        try:
            evidence["failure_scenes"] = suite.save_failure_scenes(renderer + "_matrix_" + current_name)
        except Exception as snapshot_error:
            evidence["failure_capture_error"] = str(snapshot_error)
        try:
            persist()
        except Exception as write_error:
            evidence["receipt_write_error"] = str(write_error)
        raise
    finally:
        evidence["cleanup"] = suite.close()
        try:
            persist()
        except Exception:
            if evidence["status"] != "failed":
                raise

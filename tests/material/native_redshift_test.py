"""Native Redshift graph regressions using the actual PMX material adapter.

``run(suite, import_model)`` accepts a caller-owned import callback with signature
``import_model(suite, pmx_path)``. It must import into ``suite.doc`` with the
RedShift material option. Keeping this callback explicit avoids changing global
import preferences or assuming that the regression bridge supports a renderer.
It may return the imported BaseObject; otherwise it must select that object.
The caller records loaded binary identity and restores the prior document.
"""

from pathlib import Path
import hashlib
import math

import native_diffuse_test as diffuse

SPACE = "com.redshift3d.redshift4c4d.class.nodespace"
PREFIX = "com.redshift3d.redshift4c4d.nodes.core."


def prepare(directory):
    fixtures = diffuse.prepare(directory)
    path = Path(directory).resolve() / "redshift_with_texture_morph.pmx"
    data = diffuse._pmx(True, texture_factor_morph=(.2, .1, 0., .25))
    path.write_bytes(data)
    fixtures[path.name] = {"path": str(path), "sha256": hashlib.sha256(data).hexdigest(), "bytes": len(data)}
    return fixtures


def _near(actual, expected, message):
    if len(actual) != len(expected) or any(not math.isfinite(a) or abs(a - e) > 1e-5 for a, e in zip(actual, expected)):
        raise AssertionError(f"{message}: actual={actual}, expected={expected}")


def _port(node, direction, identifier):
    ports = node.GetInputs() if direction == "input" else node.GetOutputs()
    port = ports.FindChild(identifier)
    if not port.IsValid():
        raise AssertionError("Missing native Redshift port: " + identifier)
    return port


def _wire(maxon, source, destination):
    predecessors = maxon.GraphModelHelper.GetDirectPredecessors(destination, maxon.NODE_KIND.OUTPORT)
    paths = [str(node.GetPath()) for node in predecessors]
    expected = str(source.GetPath())
    if paths != [expected]:
        raise AssertionError(f"Wrong opacity/color graph connection: {paths}, expected {[expected]}")
    return {"source": expected, "destination": str(destination.GetPath())}


def snapshot(suite, strength=0., texture_factor_morph=False):
    import maxon

    material = suite.doc.GetFirstMaterial()
    if material is None:
        raise AssertionError("Redshift PMX import created no material")
    node_material = material.GetNodeMaterialReference()
    if node_material is None or not node_material.HasSpace(maxon.Id(SPACE)):
        raise AssertionError("Material import did not use the Redshift adapter")
    graph = node_material.GetGraph(maxon.Id(SPACE))
    root = graph.GetNode(maxon.NodePath())
    texture = root.FindChild("cmt_diffuse_texture")
    splitter = root.FindChild("cmt_opacity_splitter")
    if not texture.IsValid() or not splitter.IsValid():
        raise AssertionError("Importer-owned diffuse/opacity nodes are absent")
    standard_nodes = maxon.GraphModelHelper.FindNodesByAssetId(graph, maxon.Id(PREFIX + "standardmaterial"), True)
    if len(standard_nodes) != 1:
        raise AssertionError("Expected one Standard Material node in the imported graph")
    standard = standard_nodes[0]

    wires = [
        _wire(maxon, _port(texture, "output", PREFIX + "texturesampler.outcolor"),
              _port(standard, "input", PREFIX + "standardmaterial.base_color")),
        _wire(maxon, _port(texture, "output", PREFIX + "texturesampler.outcolor"),
              _port(splitter, "input", PREFIX + "rscolorsplitter.input")),
        _wire(maxon, _port(splitter, "output", PREFIX + "rscolorsplitter.outa"),
              _port(standard, "input", PREFIX + "standardmaterial.opacity_color")),
    ]
    color = _port(texture, "input", PREFIX + "texturesampler.color_multiplier").GetPortValue()
    rgb = [float(color.r), float(color.g), float(color.b)]
    alpha = float(_port(texture, "input", PREFIX + "texturesampler.alpha_multiplier").GetPortValue())
    # maxon.interface.Bool is a nonempty Python wrapper even when its payload
    # is false; bool(wrapper) therefore does not reflect the native boolean.
    if int(_port(texture, "input", PREFIX + "texturesampler.alpha_is_luminance").GetPortValue()) != 0:
        raise AssertionError("Texture RGB luminance was selected as opacity instead of image alpha")

    factors = [1. + .2 * strength, 1. + .1 * strength, 1.] if texture_factor_morph else [1.] * 3
    factor_alpha = 1. + .25 * strength if texture_factor_morph else 1.
    expected_rgb = [a * b for a, b in zip([.2 + .1 * strength, .4, .6], factors)]
    expected_alpha = (.5 + .1 * strength) * factor_alpha
    _near(rgb, expected_rgb, "Redshift diffuse/texture RGB coefficient")
    _near([alpha], [expected_alpha], "Redshift diffuse/texture alpha coefficient")

    texture_nodes = maxon.GraphModelHelper.FindNodesByAssetId(graph, maxon.Id(PREFIX + "texturesampler"), True)
    splitters = maxon.GraphModelHelper.FindNodesByAssetId(graph, maxon.Id(PREFIX + "rscolorsplitter"), True)
    if len(texture_nodes) != 1 or len(splitters) != 1:
        raise AssertionError("Repeated material synchronization duplicated graph nodes")
    return {"strength": strength, "color_multiplier": rgb, "alpha_multiplier": alpha,
            "alpha_is_luminance": False, "wires": wires, "texture_nodes": 1, "splitter_nodes": 1}


def _new_model(suite, name, import_model):
    cleanup = suite.close()
    if cleanup["errors"]:
        raise RuntimeError("Previous owned Redshift document could not be closed")
    suite.new_document("Redshift " + name)
    imported = import_model(suite, suite.fixture(name))
    suite.model = imported if imported is not None else suite.doc.GetActiveObject()
    if suite.model is None or suite.model.GetType() != 1056724:
        raise AssertionError("Redshift PMX import did not select its MMD model")
    suite.model[suite.ids["MODEL_PHYSICS_ENABLED"]] = False
    suite.evaluate(0)


def run(suite, import_model):
    try:
        return _run_original(suite, import_model)
    finally:
        suite.close()


def _run_original(suite, import_model):
    fixtures = prepare(suite.output / "redshift-inputs")
    suite.manifest["fixtures"].update(fixtures)
    result = {"fixtures": fixtures, "no_material_morph": [], "material_and_texture_morph": []}
    _new_model(suite, "diffuse_no_morph.pmx", import_model)
    result["no_material_morph"].append(snapshot(suite))
    suite.reopen("redshift_no_morph_reopen")
    result["no_material_morph"].append(snapshot(suite))

    _new_model(suite, "redshift_with_texture_morph.pmx", import_model)
    suite.model[suite.ids["MODEL_MODE"]] = suite.ids["MODEL_MODE_ANIM"]
    for strength in (0., 1., .5, 0., .5):
        suite.call("set_strength", morph_index=0, strength=strength)
        suite.evaluate(0)
        result["material_and_texture_morph"].append(snapshot(suite, strength, True))
    suite.reopen("redshift_texture_morph_reopen")
    result["material_and_texture_morph"].append(snapshot(suite, .5, True))
    suite.call("set_strength", morph_index=0, strength=0.)
    suite.evaluate(0)
    result["material_and_texture_morph"].append(snapshot(suite, 0., True))
    result["native_graph_inspection"] = True
    result["full_image_render"] = False
    return result


def snapshot_matrix(suite, case, strength, profile="graph"):
    import maxon
    import material_fixture_matrix as matrix
    material = suite.doc.GetFirstMaterial()
    node_material = material.GetNodeMaterialReference() if material else None
    if node_material is None or not node_material.HasSpace(maxon.Id(SPACE)):
        raise AssertionError("Matrix import did not create a Redshift material")
    graph = node_material.GetGraph(maxon.Id(SPACE))
    root = graph.GetNode(maxon.NodePath())
    standards = maxon.GraphModelHelper.FindNodesByAssetId(graph, maxon.Id(PREFIX + "standardmaterial"), True)
    textures = maxon.GraphModelHelper.FindNodesByAssetId(graph, maxon.Id(PREFIX + "texturesampler"), True)
    splitters = maxon.GraphModelHelper.FindNodesByAssetId(graph, maxon.Id(PREFIX + "rscolorsplitter"), True)
    if len(standards) != 1:
        raise AssertionError("Exactly one Redshift Standard Material is required")
    standard = standards[0]
    expected_rgb, expected_alpha = matrix.expected_coefficients(case, strength)
    wires = []
    if case["stripes"] is None:
        if textures or splitters:
            raise AssertionError("An untextured material acquired image/opacity nodes")
        color = _port(standard, "input", PREFIX + "standardmaterial.base_color").GetPortValue()
        opacity = _port(standard, "input", PREFIX + "standardmaterial.opacity_color").GetPortValue()
        rgb = [float(color.r), float(color.g), float(color.b)]
        _near([float(opacity.r), float(opacity.g), float(opacity.b)], [expected_alpha] * 3,
              "No-image texture factor incorrectly affected plain opacity")
        alpha, texture_path = float(opacity.r), None
    else:
        if len(textures) != 1 or len(splitters) != 1:
            raise AssertionError("Repeated morph/reopen duplicated texture or opacity nodes")
        texture, splitter = root.FindChild("cmt_diffuse_texture"), root.FindChild("cmt_opacity_splitter")
        if not texture.IsValid() or not splitter.IsValid():
            raise AssertionError("Importer-owned Redshift texture nodes are missing")
        for source, destination in (
            (_port(texture, "output", PREFIX + "texturesampler.outcolor"),
             _port(standard, "input", PREFIX + "standardmaterial.base_color")),
            (_port(texture, "output", PREFIX + "texturesampler.outcolor"),
             _port(splitter, "input", PREFIX + "rscolorsplitter.input")),
            (_port(splitter, "output", PREFIX + "rscolorsplitter.outa"),
             _port(standard, "input", PREFIX + "standardmaterial.opacity_color")),
        ):
            wires.append(_wire(maxon, source, destination))
        color = _port(texture, "input", PREFIX + "texturesampler.color_multiplier").GetPortValue()
        rgb = [float(color.r), float(color.g), float(color.b)]
        alpha = float(_port(texture, "input", PREFIX + "texturesampler.alpha_multiplier").GetPortValue())
        if int(_port(texture, "input", PREFIX + "texturesampler.alpha_is_luminance").GetPortValue()) != 0:
            raise AssertionError("Redshift converted RGB to opacity instead of extracting image alpha")
        bundle = _port(texture, "input", PREFIX + "texturesampler.tex0")
        path = bundle.FindChild("path")
        if not path.IsValid():
            raise AssertionError("Redshift texture URL is missing")
        texture_path = str(path.GetPortValue())
        # Maxon Url may use a file scheme or escaped path. Verify decoded file
        # identity; never accept only a coincidentally matching basename.
        from urllib.parse import unquote, urlparse
        parsed = urlparse(texture_path)
        decoded = unquote(parsed.path) if parsed.scheme == "file" else unquote(texture_path)
        if decoded.startswith("/") and len(decoded) > 2 and decoded[2] == ":":
            decoded = decoded[1:]
        if Path(decoded).resolve() != Path(case["texture_path"]).resolve():
            raise AssertionError("Chinese relative texture path resolved to a different file: " + texture_path)
    _near(rgb, expected_rgb, "Redshift matrix effective RGB coefficient")
    _near([alpha], [expected_alpha], "Redshift matrix effective alpha coefficient")
    return {"case": case["name"], "strength": strength, "profile": profile,
            "color_multiplier": rgb, "alpha_multiplier": alpha, "texture_path": texture_path,
            "texture_nodes": len(textures), "splitter_nodes": len(splitters), "wires": wires}


def run_matrix(suite, import_model, set_strength=None):
    return diffuse.run_matrix(suite, import_model, set_strength, snapshot=snapshot_matrix)

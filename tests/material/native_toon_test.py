"""Native RS Toon probes and small image fixtures; execute inside Cinema 4D."""

from pathlib import Path
import json
import math
import hashlib
import struct
import zlib

SPACE = "com.redshift3d.redshift4c4d.class.nodespace"
PREFIX = "com.redshift3d.redshift4c4d.nodes.core."
OUTPUT = "com.redshift3d.redshift4c4d.node.output"


def prepare(directory):
    """Ordinary-UV fixture with distinctive Toon and edge RGBA offsets."""
    import shader_binding_test as binding
    from native_diffuse_test import _pack, _text
    directory = Path(directory)
    fixtures = binding.prepare(directory, texture_multiply=(.5, 1.25, .8, .5))
    data = bytearray((directory / "binding.pmx").read_bytes())
    table = _pack("i", 1) + _text("colored-alpha.png") + _pack("i", 2)
    replacement = _pack("i", 2) + _text("colored-alpha.png") + _text("toon-steps.png") + _pack("i", 2)
    data = bytearray(data.replace(table, replacement, 1))
    for name in ("plain", "textured"):
        offset = data.index(_text(name) + _text(name)) + len(_text(name)) * 2
        data[offset + 44] = 17  # two-sided and edge enabled
        struct.pack_into("4ff", data, offset + 45, .015, .025, .04, .8, 1.5)
        struct.pack_into("i", data, offset + struct.calcsize("<4f3ff3fB4ffiiBBi") - 4, 1)
    for name, header, updates in (
        ("Tint", _pack("BBiiB", 4, 8, 1, -1, 1), {11: .05, 12: .1, 13: .2, 14: -.25, 15: .75,
                                                      24: .2, 25: -.1, 26: .1, 27: .25}),
        ("Multiply", _pack("BBiiB", 4, 8, 1, 1, 0), {24: .5, 25: 1.2, 26: .8, 27: .6}),
    ):
        prefix = _text(name) * 2 + header
        offset = data.index(prefix) + len(prefix)
        for field, value in updates.items():
            struct.pack_into("f", data, offset + field * 4, value)
    path = directory / "toon-binding.pmx"
    path.write_bytes(data)

    def chunk(kind, content):
        return struct.pack(">I", len(content)) + kind + content + struct.pack(">I", zlib.crc32(kind + content))

    # Top is white, bottom dark blue: orientation errors are visible on a sphere.
    rows = b"".join(b"\0" + bytes((255, 255, 255) if y < 16 else (40, 65, 100)) * 4
                    for y in range(32))
    png = b"\x89PNG\r\n\x1a\n" + chunk(b"IHDR", struct.pack(">IIBBBBB", 4, 32, 8, 2, 0, 0, 0))
    png += chunk(b"IDAT", zlib.compress(rows)) + chunk(b"IEND", b"")
    (directory / "toon-steps.png").write_bytes(png)
    for name in ("toon-binding.pmx", "toon-steps.png"):
        path = directory / name
        fixtures[name] = {"path": str(path), "sha256": hashlib.sha256(path.read_bytes()).hexdigest()}
    return fixtures


def prepare_character(directory):
    """Small generated PMX character, with no third-party model dependency."""
    from native_diffuse_test import _pack, _text
    directory = Path(directory)
    fixtures = prepare(directory)
    vertices, surfaces = [], []

    def ellipsoid(center, radii, end=math.pi):
        start = len(vertices)
        longitude, latitude = 32, 20
        for row in range(latitude + 1):
            theta = end * row / latitude
            for column in range(longitude + 1):
                phi = 2 * math.pi * column / longitude
                direction = (math.sin(theta) * math.cos(phi), math.cos(theta), math.sin(theta) * math.sin(phi))
                position = [c + r * n for c, r, n in zip(center, radii, direction)]
                normal = [n / r for n, r in zip(direction, radii)]
                length = math.sqrt(sum(n * n for n in normal))
                vertices.append((*position, *(n / length for n in normal), column / longitude, row / latitude))
        indices = []
        for row in range(latitude):
            for column in range(longitude):
                a = start + row * (longitude + 1) + column
                b = a + longitude + 1
                indices.extend((a, a + 1, b, a + 1, b + 1, b))
        return indices

    surfaces.append(ellipsoid((0., 1.15, 0.), (.82, 1.02, .68)))
    surfaces.append(ellipsoid((0., 1.22, -.03), (.88, 1.04, .73), math.pi * .35))
    surfaces.append(ellipsoid((-.27, 1.35, -.64), (.13, .22, .07)) +
                    ellipsoid((.27, 1.35, -.64), (.13, .22, .07)))
    surfaces.append(ellipsoid((0., -.1, -.05), (.8, .85, .5)))
    # A thin front hair strip carries an RGBA cutout using ordinary UV.
    start = len(vertices)
    for x, y, u, v in ((-.72, 1.58, 0., 1.), (.72, 1.58, 1., 1.),
                        (.72, 1.9, 1., 0.), (-.72, 1.9, 0., 0.)):
        vertices.append((x, y, -.70, 0., 0., -1., u, v))
    surfaces.append([start, start + 2, start + 1, start, start + 3, start + 2])
    data = bytearray(b"PMX " + _pack("fB", 2., 8) + bytes((1, 0, 4, 4, 4, 4, 4, 4)))
    for text in ("Generated Toon character", "Generated Toon character", "Ordinary UV; no MMD native reference", ""):
        data.extend(_text(text))
    data.extend(_pack("i", len(vertices)))
    for vertex in vertices:
        data.extend(_pack("3f3f2fBif", *vertex, 0, 0, 1.))
    indices = [i for surface in surfaces for i in surface]
    data.extend(_pack("i", len(indices)) + _pack(str(len(indices)) + "I", *indices))
    data.extend(_pack("i", 2) + _text("toon-steps.png") + _text("hair-cutout.png"))
    data.extend(_pack("i", len(surfaces)))
    colors = ((.85, .56, .42), (.14, .09, .22), (.025, .04, .07), (.12, .28, .50), (.18, .10, .25))
    for index, (name, color, faces) in enumerate(zip(("skin", "hair", "eyes", "clothes", "transparent fringe"), colors, surfaces)):
        data.extend(_text(name) * 2)
        data.extend(_pack("4f3ff3fB4ffiiBBi", *color, 1., .15, .15, .15, 40.,
                          0., 0., 0., 17, .01, .01, .025, 1., 1.,
                          1 if index == 4 else -1, -1, 0, 0, 0))
        data.extend(_text("") + _pack("i", len(faces)))
    data.extend(_pack("i", 1) + _text("root") * 2 + _pack("3fiiH3f", 0., 0., 0., -1, 0, 0x1e, 0., .1, 0.))
    data.extend(_pack("iiii", 0, 0, 0, 0))
    path = directory / "toon-character.pmx"
    path.write_bytes(data)

    def chunk(kind, content):
        return struct.pack(">I", len(content)) + kind + content + struct.pack(">I", zlib.crc32(kind + content))

    rows = b"".join(b"\0" + b"".join(bytes((255, 255, 255, 255 if (x % 8 < 5 or y < 4) else 0))
                      for x in range(32)) for y in range(16))
    png = b"\x89PNG\r\n\x1a\n" + chunk(b"IHDR", struct.pack(">IIBBBBB", 32, 16, 8, 6, 0, 0, 0))
    png += chunk(b"IDAT", zlib.compress(rows)) + chunk(b"IEND", b"")
    (directory / "hair-cutout.png").write_bytes(png)
    for name in ("toon-character.pmx", "hair-cutout.png"):
        path = directory / name
        fixtures[name] = {"path": str(path), "sha256": hashlib.sha256(path.read_bytes()).hexdigest()}
    return fixtures


def prepare_additional_uv(directory):
    """Explicit AddUV1 usage is diagnosed; ordinary extra-channel absence isn't."""
    from native_diffuse_test import _pack, _text
    directory = Path(directory)
    fixtures = prepare(directory)
    data = bytearray((directory / "toon-binding.pmx").read_bytes())
    offset = 17
    for _ in range(4):
        size = struct.unpack_from("<i", data, offset)[0]
        offset += 4 + size
    count = struct.unpack_from("<i", data, offset)[0]
    start = offset + 4
    stride = struct.calcsize("<3f3f2fBif")
    vertices = b"".join(data[start + i * stride:start + i * stride + 32] + _pack("4f", 0., 0., 0., 0.) +
                         data[start + i * stride + 32:start + (i + 1) * stride] for i in range(count))
    data[start:start + count * stride] = vertices
    data[10] = 1
    first = data.index(_text("Tint") * 2)
    struct.pack_into("i", data, first - 4, 5)
    morph = _text("Extra UV") * 2 + _pack("BBii4f", 4, 4, 1, 0, .1, 0., 0., 0.)
    data[-12:-12] = morph
    # Use an existing image as a SubTexture input. Its visual contribution is
    # intentionally unsupported but does not block the ordinary-UV branches.
    offset = data.index(_text("plain") * 2) + len(_text("plain")) * 2
    struct.pack_into("i", data, offset + 69, 0)
    data[offset + 73] = 3
    path = directory / "toon-additional-uv.pmx"
    path.write_bytes(data)
    fixtures[path.name] = {"path": str(path), "sha256": hashlib.sha256(data).hexdigest()}
    return fixtures


def binding_snapshot(suite):
    """Read the installed revision 5 graph and all sixteen mesh attributes."""
    import maxon
    c4d = suite.c4d
    rows = []
    for material in suite.doc.GetMaterials():
        metadata = material.GetDataInstance().GetContainer(1068715)
        if metadata.GetInt32(170) != 1:
            continue
        graph = material.GetNodeMaterialReference().GetGraph(maxon.Id(SPACE))
        token = metadata.GetString(102)
        meshes = [mesh for mesh in suite.nodes(c4d.Opolygon)
                  if any(token in entry.GetString(c4d.DESC_NAME)
                         for _, entry in mesh.GetUserDataContainer())]
        if len(meshes) != 1:
            raise AssertionError("Toon attributes do not identify one mesh")
        values = []
        for field in range(16):
            identifier = metadata.GetInt32(300 + field)
            value = meshes[0][c4d.DescID(c4d.DescLevel(c4d.ID_USERDATA),
                                        c4d.DescLevel(identifier))]
            values.append([value.x, value.y, value.z] if isinstance(value, c4d.Vector) else float(value))
        nodes = sorted(str(node.GetId()) for node in graph.GetViewRoot().GetChildren()
                       if str(node.GetId()).startswith("cmt_"))
        if metadata.GetInt32(100) != 2 or metadata.GetInt32(171) != 5 or len(nodes) != 40:
            raise AssertionError((metadata.GetInt32(100), nodes))
        root = graph.GetViewRoot()
        neutral = metadata.GetBool(178)
        tone_input = root.FindChild("cmt_toon_surface").GetInputs().FindChild(PREFIX + "toonmaterial.base_tone_map")
        expected = root.FindChild("cmt_toon_ramp" if neutral else "cmt_toon_add").GetOutputs().FindChild(
            PREFIX + ("rsramp.outcolor" if neutral else "rsmathaddvector.out"))
        predecessors = maxon.GraphModelHelper.GetDirectPredecessors(tone_input, maxon.NODE_KIND.OUTPORT)
        if [str(port.GetPath()) for port in predecessors] != [str(expected.GetPath())]:
            raise AssertionError("Unassigned Toon must bypass texture-factor multiplication")
        fallback_knots = root.FindChild("cmt_toon_ramp").GetInputs().FindChild(PREFIX + "rsramp.ramp")
        for index in (0, 1):
            color = fallback_knots.FindChild("_" + str(index)).FindChild("color").GetPortValue()
            expected_color = .3 if index == 0 and not neutral else 1.
            if any(abs(value - expected_color) > 1e-6 for value in (color.r, color.g, color.b)):
                raise AssertionError("Unassigned and missing assigned Toon fallbacks differ")
        mask = graph.GetViewRoot().FindChild("cmt_specular_mask")
        knots = mask.GetInputs().FindChild(PREFIX + "rsramp.ramp")
        for index in (0, 1):
            knot = knots.FindChild("_" + str(index))
            color = knot.FindChild("color").GetPortValue()
            if (float(knot.FindChild("position").GetPortValue()) != float(index)
                    or any(abs(component - index) > 1e-6 for component in (color.r, color.g, color.b))
                    or str(knot.FindChild("interpolation").GetPortValue()) != "linearknot"):
                raise AssertionError("Fresh Toon graph must have a smooth black-to-white specular mask")
        rows.append({"material": material.GetName(), "values": values, "neutral_toon_fallback": neutral,
                     "nodes": nodes, "diagnostic": metadata.GetString(175)})
    return rows


def conversion_roundtrip(suite, cycles=3):
    """Exercise assignment, source preservation and immediate save after Undo."""
    c4d, ids = suite.c4d, suite.ids
    suite.model[ids["MODEL_MODE"]] = ids["MODEL_MODE_EDIT"]
    suite.model[ids["MODEL_MATMORPH_PREVIEW_ENABLED"]] = False
    suite.model[ids["MODEL_MATERIAL_LIST"]] = 0
    source = suite.model[ids["MODEL_MATERIAL_LINK"]]
    source_name = source.GetName()
    count = len(suite.doc.GetMaterials())
    suite.doc.FlushUndoBuffer()
    c4d.CallButton(suite.model, ids["MODEL_MATERIAL_CONVERT_TOON"])
    target = suite.model[ids["MODEL_MATERIAL_LINK"]]
    if target == source or len(suite.doc.GetMaterials()) != count + 1:
        raise AssertionError("Conversion did not create an independent material: " +
                             str(suite.model[ids["MODEL_MATMORPH_STATUS"]]))

    def signature(document):
        model = next(node for node in suite.walk(document.GetFirstObject()) if node.GetType() == suite.model.GetType())
        model[ids["MODEL_MATERIAL_LIST"]] = 0
        material = model[ids["MODEL_MATERIAL_LINK"]]
        assignments = [tag for node in suite.walk(model.GetDown()) for tag in node.GetTags()
                       if tag.CheckType(c4d.Ttexture) and tag.GetMaterial() == material]
        return {"profile": material.GetDataInstance().GetContainer(1068715).GetInt32(170),
                "materials": len(document.GetMaterials()), "assignments": len(assignments),
                "source_preserved": any(m.GetName() == source_name for m in document.GetMaterials())}

    converted = signature(suite.doc)
    if converted["assignments"] < 1 or not converted["source_preserved"]:
        raise AssertionError(converted)
    rows = []
    for cycle in range(cycles):
        for action, expected_count in (("undo", count), ("redo", count + 1)):
            if not (suite.doc.DoUndo() if action == "undo" else suite.doc.DoRedo()):
                raise AssertionError("Missing conversion " + action)
            path = suite.output / f"toon-conversion-{cycle}-{action}.c4d"
            # Save before evaluating or refreshing the scene.
            if not c4d.documents.SaveDocument(suite.doc, str(path),
                    c4d.SAVEDOCUMENTFLAGS_DONTADDTORECENTLIST, c4d.FORMAT_C4DEXPORT):
                raise AssertionError("Immediate conversion save failed")
            actual = signature(suite.doc)
            loaded = c4d.documents.LoadDocument(str(path),
                    c4d.SCENEFILTER_OBJECTS | c4d.SCENEFILTER_MATERIALS, None)
            if loaded is None or actual != signature(loaded) or actual["materials"] != expected_count:
                raise AssertionError((action, actual))
            rows.append({"cycle": cycle, "action": action, "live_and_reopen": actual})
    return rows


def start_render(suite, frame=0, width=640, height=400):
    """Render the actual managed scene in a retained asynchronous clone."""
    import native_render_matrix as render
    c4d = suite.c4d
    suite.evaluate(frame)
    translator = c4d.AliasTrans()
    if not translator.Init(suite.doc):
        raise RuntimeError("Toon render clone translation failed")
    clone = suite.doc.GetClone(c4d.COPYFLAGS_NONE, translator)
    translator.Translate(True)
    # A non-active document can otherwise fall back to the editor camera after
    # a callback changes the active document. Pin the private scene camera in
    # each render clone so contour comparisons use identical framing.
    source_camera = suite.doc.GetRenderBaseDraw().GetSceneCamera(suite.doc)
    if source_camera is not None:
        cameras = [node for node in suite.walk(clone.GetFirstObject())
                   if node.CheckType(c4d.Ocamera) and node.GetName() == source_camera.GetName()]
        if len(cameras) != 1:
            raise AssertionError("Toon render camera must identify one cloned camera")
        clone.GetRenderBaseDraw().SetSceneCamera(cameras[0])
    clone.SetTime(c4d.BaseTime(frame, 30))
    clone.ExecutePasses(None, True, True, True, c4d.BUILDFLAGS_NONE)
    bitmap = c4d.bitmaps.MultipassBitmap(width, height, c4d.COLORMODE_RGB)
    if bitmap is None or bitmap.AddChannel(True, True) is None:
        raise MemoryError("Toon RGBA bitmap allocation failed")
    worker = render._worker(c4d, clone, bitmap)
    if not worker.Start(c4d.THREADMODE_ASYNC):
        raise RuntimeError("Toon render thread did not start")
    return worker


def collect_render(worker, path):
    import c4d
    if worker.IsRunning():
        return {"running": True, "progress": worker.progress}
    worker.End(True)
    if worker.result != c4d.RENDERRESULT_OK or worker.error:
        raise AssertionError((worker.result, worker.error))
    bitmap = worker.bitmap
    if bitmap.Save(str(path), c4d.FILTER_PNG, savebits=c4d.SAVEBIT_ALPHA) != c4d.IMAGERESULT_OK:
        raise AssertionError("Toon RGBA image save failed")
    width, height = bitmap.GetBw(), bitmap.GetBh()
    alpha = bitmap.GetInternalChannel()
    rows = [{"xy": [x, y], "rgb": list(bitmap.GetPixel(x, y)),
             "alpha": bitmap.GetAlphaPixel(alpha, x, y)}
            for x, y in ((width // 2, height // 3), (width // 2, height // 2),
                         (width // 3, height // 2), (2 * width // 3, height // 2))]
    result = {"running": False, "result": worker.result, "image": str(path), "samples": rows}
    worker.document = worker.bitmap = None
    return result


def port(node, role, name):
    """Find a required native port, without silently accepting a missing input."""
    parent = node.GetInputs() if role == "input" else node.GetOutputs()
    result = parent.FindChild(name)
    if result.IsNullValue():
        raise RuntimeError("Required RS Toon port is missing: " + name)
    return result


def make_prototype(c4d, maxon, *, texture_path="", toon_path="", edge=True):
    material = c4d.BaseMaterial(c4d.Mmaterial)
    node_material = material.GetNodeMaterialReference()
    graph = node_material.CreateEmptyGraph(maxon.Id(SPACE))
    with graph.BeginTransaction() as transaction:
        surface = graph.AddChild(maxon.Id("cmt_toon_surface"), maxon.Id(PREFIX + "toonmaterial"))
        output = graph.AddChild(maxon.Id("cmt_toon_output"), maxon.Id(OUTPUT))
        contour = graph.AddChild(maxon.Id("cmt_toon_contour"), maxon.Id(PREFIX + "contour"))
        ramp = graph.AddChild(maxon.Id("cmt_toon_ramp"), maxon.Id(PREFIX + "rsramp"))
        port(surface, "output", PREFIX + "toonmaterial.outcolor").Connect(port(output, "input", OUTPUT + ".surface"))
        port(contour, "output", PREFIX + "contour.outcolor").Connect(port(output, "input", OUTPUT + ".contour"))
        for name, value in (("base_color", maxon.Color(.65, .3, .16)), ("refl_color", maxon.Color(.15)),
                            ("refl_roughness", .25), ("refl_use_fresnel", False)):
            port(surface, "input", PREFIX + "toonmaterial." + name).SetPortValue(value)
        for name, value in (("externalenable", edge), ("internalenable", False), ("backfacingenable", False),
                            ("externalcolor", maxon.Color(0.)), ("externalthickness", 3.)):
            port(contour, "input", PREFIX + "contour." + name).SetPortValue(value)
        knots = port(ramp, "input", PREFIX + "rsramp.ramp")
        for index, position, color in ((0, 0., .3), (1, .5, 1.)):
            knot = knots.FindChild("_" + str(index))
            knot.FindChild("position").SetPortValue(position)
            knot.FindChild("color").SetPortValue(maxon.Color(color))
        port(ramp, "input", PREFIX + "rsramp.ramp_interp").SetPortValue(0)
        tonemap = ramp
        tonemap_output = "rsramp.outcolor"
        if toon_path:
            tonemap = graph.AddChild(maxon.Id("cmt_toon_texture"), maxon.Id(PREFIX + "texturesampler"))
            port(tonemap, "input", PREFIX + "texturesampler.tex0").FindChild("path").SetPortValue(maxon.Url(toon_path))
            port(tonemap, "input", PREFIX + "texturesampler.tone_map_enable").SetPortValue(True)
            tonemap_output = "texturesampler.outcolor"
        port(tonemap, "output", PREFIX + tonemap_output).Connect(port(surface, "input", PREFIX + "toonmaterial.base_tone_map"))
        if texture_path:
            texture = graph.AddChild(maxon.Id("cmt_diffuse_texture"), maxon.Id(PREFIX + "texturesampler"))
            splitter = graph.AddChild(maxon.Id("cmt_opacity_splitter"), maxon.Id(PREFIX + "rscolorsplitter"))
            port(texture, "input", PREFIX + "texturesampler.tex0").FindChild("path").SetPortValue(maxon.Url(texture_path))
            port(texture, "input", PREFIX + "texturesampler.alpha_is_luminance").SetPortValue(False)
            port(texture, "output", PREFIX + "texturesampler.outcolor").Connect(port(surface, "input", PREFIX + "toonmaterial.base_color"))
            port(texture, "output", PREFIX + "texturesampler.outcolor").Connect(port(splitter, "input", PREFIX + "rscolorsplitter.input"))
            port(splitter, "output", PREFIX + "rscolorsplitter.outa").Connect(port(surface, "input", PREFIX + "toonmaterial.opacity_color"))
        transaction.Commit()
    return material


def start_prototype(output_directory):
    """Build an owned document and return an asynchronous native render worker."""
    import c4d
    import maxon
    import native_render_matrix as render
    import c4d_runtime_regression as regression

    original = c4d.documents.GetActiveDocument()
    if original is not None and not original.GetDocumentPath().GetString():
        original.SetDocumentName("CMT Toon private baseline")
    document = c4d.documents.BaseDocument()
    document.SetDocumentName("CMT RS Toon prototype")
    c4d.documents.InsertBaseDocument(document)
    c4d.documents.SetActiveDocument(document)
    material = make_prototype(c4d, maxon)
    document.InsertMaterial(material)
    sphere = c4d.BaseObject(c4d.Osphere)
    sphere[c4d.PRIM_SPHERE_RAD] = 60.
    document.InsertObject(sphere)
    tag = c4d.TextureTag()
    tag.SetMaterial(material)
    sphere.InsertTag(tag)
    camera = c4d.BaseObject(c4d.Ocamera)
    camera.SetAbsPos(c4d.Vector(0., 0., -300.))
    document.InsertObject(camera)
    document.GetRenderBaseDraw().SetSceneCamera(camera)
    light = c4d.BaseObject(c4d.Olight)
    light.SetAbsPos(c4d.Vector(-130., 150., -180.))
    document.InsertObject(light)
    render_data = document.GetActiveRenderData()
    for identifier, value in ((c4d.RDATA_RENDERENGINE, 1036219), (c4d.RDATA_XRES, 256),
                              (c4d.RDATA_YRES, 256), (c4d.RDATA_ALPHACHANNEL, True),
                              (c4d.RDATA_STRAIGHTALPHA, True), (c4d.RDATA_SAVEIMAGE, False)):
        render_data[identifier] = value
    render.ensure_redshift_post(c4d, render_data)
    document.ExecutePasses(None, True, True, True, c4d.BUILDFLAGS_NONE)
    c4d.EventAdd()
    c4d.documents.SetActiveDocument(original)
    translator = c4d.AliasTrans()
    if not translator.Init(document):
        raise RuntimeError("Prototype render clone translation failed")
    render_document = document.GetClone(c4d.COPYFLAGS_NONE, translator)
    translator.Translate(True)
    bitmap = c4d.bitmaps.MultipassBitmap(256, 256, c4d.COLORMODE_RGB)
    bitmap.AddChannel(True, True)
    worker = render._worker(c4d, render_document, bitmap)
    worker.source_document = document
    worker.original_document = original
    if not worker.Start(c4d.THREADMODE_ASYNC):
        raise RuntimeError("Toon prototype render did not start")
    directory = Path(output_directory)
    directory.mkdir(parents=True, exist_ok=True)
    identity = {"host": c4d.GetC4DVersion(), "module": regression.loaded_plugin_binary(),
                "resolution": [256, 256], "additional_uv_used": False,
                "camera": [0, 0, -300], "light": [-130, 150, -180]}
    (directory / "prototype-identity.json").write_text(json.dumps(identity, indent=2), encoding="utf-8")
    return worker


def material_disabled_import_roundtrip(c4d, manifest):
    """Regression for PMX path resolution without creating renderer materials.

    Exercise both mesh layouts and both material selections through the formal
    production interface. A disabled material gate still imports model metadata.
    """
    import shader_binding_test as binding
    rows = []
    for material_type in ("standard", "redshift_toon"):
        for multipart in (False, True):
            suite = binding.production_suite(c4d, manifest, material_type=material_type,
                import_options={"materials": False, "multipart": multipart})
            try:
                suite.new_model("binding.pmx")
                suite.assert_true(not suite.doc.GetMaterials(), "Disabled import created materials")
                texture_tags = [tag for mesh in suite.nodes(c4d.Opolygon)
                                for tag in mesh.GetTags() if tag.CheckType(c4d.Ttexture)]
                suite.assert_true(not texture_tags, "Disabled import created material assignments")
                suite.reopen("materials-disabled-" + material_type + "-" + str(multipart))
                suite.assert_true(not suite.doc.GetMaterials(), "Reopen created disabled materials")
                rows.append({"material_type": material_type, "multipart": multipart,
                             "materials": 0, "model_imported": True, "save_reopen": True})
            finally:
                cleanup = suite.close()
                suite.assert_true(not cleanup["errors"], str(cleanup))
    return rows


def collect_prototype(worker, output_directory):
    import c4d
    if worker.IsRunning():
        return {"running": True, "progress": worker.progress}
    worker.End(True)
    result = {"running": False, "result": worker.result, "error": worker.error}
    if worker.result == c4d.RENDERRESULT_OK and not worker.error:
        path = Path(output_directory) / "prototype.png"
        worker.bitmap.Save(str(path), c4d.FILTER_PNG, savebits=c4d.SAVEBIT_ALPHA)
        result["image"] = str(path)
        result["center_rgb"] = list(worker.bitmap.GetPixel(128, 128))
        result["center_alpha"] = worker.bitmap.GetAlphaPixel(worker.bitmap.GetInternalChannel(), 128, 128)
    (Path(output_directory) / "prototype-receipt.json").write_text(json.dumps(result, indent=2), encoding="utf-8")
    return result

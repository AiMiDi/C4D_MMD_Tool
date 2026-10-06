"""Deterministic RGB/alpha inputs and image oracles; only the stdlib is used."""

from pathlib import Path
import hashlib
import json
import math
import struct
import zlib

SIZE = 16
SAMPLE_U = (.125, .375, .625, .875)
TEXTURE_MORPH = (.2, .1, 0., .25)
CASES = (
    {"name": "alpha_zero", "stripes": [(64, 128, 192, 0)] * 4, "alpha": True,
     "diffuse": (.2, .4, .6, 1.), "morph": False},
    {"name": "alpha_full", "stripes": [(gray, gray, gray, 255) for gray in (32, 96, 160, 224)], "alpha": True,
     "diffuse": (.2, .4, .6, 1.), "morph": False},
    {"name": "gray_varied_alpha", "stripes": [(128, 128, 128, alpha) for alpha in (0, 64, 128, 255)],
     "alpha": True, "diffuse": (.2, .4, .6, .5), "morph": True},
    {"name": "varied_rgb_fixed_alpha", "stripes": [(gray, gray, gray, 128) for gray in (32, 96, 160, 224)],
     "alpha": True, "diffuse": (.2, .4, .6, .5), "morph": True},
    {"name": "rgb_without_alpha", "stripes": [(32, 32, 32), (96, 96, 96), (160, 160, 160), (224, 224, 224)],
     "alpha": False, "diffuse": (.2, .4, .6, .5), "morph": True},
    {"name": "rgb_factor_zero", "stripes": [(32, 32, 32), (96, 96, 96), (160, 160, 160), (224, 224, 224)],
     "alpha": False, "diffuse": (.2, .4, .6, .5), "morph": True,
     "texture_morph": (.2, .1, 0., -1.)},
    {"name": "no_texture", "stripes": None, "alpha": False,
     "diffuse": (.2, .4, .6, .5), "morph": True,
     "texture_morph": (.2, .1, 0., -1.)},
)


def png_bytes(stripes, alpha):
    channels = 4 if alpha else 3
    if len(stripes) != 4 or any(len(pixel) != channels for pixel in stripes):
        raise ValueError("Four RGB or RGBA stripes are required")
    def chunk(kind, data):
        return struct.pack(">I", len(data)) + kind + data + struct.pack(">I", zlib.crc32(kind + data))
    row = b"\0" + b"".join(bytes(pixel) * (SIZE // 4) for pixel in stripes)
    header = struct.pack(">IIBBBBB", SIZE, SIZE, 8, 6 if alpha else 2, 0, 0, 0)
    return b"\x89PNG\r\n\x1a\n" + chunk(b"IHDR", header) + chunk(b"IDAT", zlib.compress(row * SIZE)) + chunk(b"IEND", b"")


def tga_bytes(stripes):
    """Uncompressed top-left-origin RGB24; it contains no alpha channel."""
    header = struct.pack("<BBBHHBHHHHBB", 0, 0, 2, 0, 0, 0, 0, 0, SIZE, SIZE, 24, 0x20)
    row = b"".join(bytes((pixel[2], pixel[1], pixel[0])) * (SIZE // 4) for pixel in stripes)
    return header + row * SIZE


def tiff_bytes(stripes):
    """Baseline little-endian TIFF with one uncompressed RGBA strip.

    ExtraSamples=2 explicitly declares unassociated embedded alpha. This tests
    decoding the channel rather than inferring it from a PNG/TGA extension.
    """
    tags = [(256, 4, 1, SIZE), (257, 4, 1, SIZE), (258, 3, 4, 0),
            (259, 3, 1, 1), (262, 3, 1, 2), (273, 4, 1, 0),
            (277, 3, 1, 4), (278, 4, 1, SIZE), (279, 4, 1, SIZE * SIZE * 4),
            (284, 3, 1, 1), (338, 3, 1, 2)]
    bits_offset = 8 + 2 + 12 * len(tags) + 4
    pixels_offset = bits_offset + 8
    entries = b"".join(struct.pack("<HHII", tag, kind, count,
        bits_offset if tag == 258 else pixels_offset if tag == 273 else value)
        for tag, kind, count, value in tags)
    row = b"".join(bytes(pixel) * (SIZE // 4) for pixel in stripes)
    return (b"II" + struct.pack("<HIH", 42, 8, len(tags)) + entries + b"\0" * 4
            + struct.pack("<4H", 8, 8, 8, 8) + row * SIZE)


def expected_coefficients(case, strength):
    rgb = [case["diffuse"][0] + .1 * strength, *case["diffuse"][1:3]]
    alpha = case["diffuse"][3] + .1 * strength
    if case["morph"] and case["stripes"] is not None:
        factors = case.get("texture_morph", TEXTURE_MORPH)
        rgb = [value * (1. + factor * strength) for value, factor in zip(rgb, factors[:3])]
        alpha *= 1. + factors[3] * strength
    return rgb, alpha


def expected_opacity(case, strength=0.):
    _, coefficient = expected_coefficients(case, strength)
    samples = [pixel[3] / 255. if case["alpha"] else 1. for pixel in case["stripes"]] if case["stripes"] else [1.] * 4
    return [min(1., max(0., alpha * coefficient)) for alpha in samples]


def verify_render_samples(case, strength, samples, *, alpha_tolerance=.025, check_rgb=True):
    """Verify rendered alpha independently from BRDF, exposure and OCIO RGB."""
    if len(samples) != 4:
        raise AssertionError("The four stripe regions must all be measured")
    expected = expected_opacity(case, strength)
    actual = [float(sample["alpha"]) for sample in samples]
    if any(not math.isfinite(value) or abs(value - target) > alpha_tolerance for value, target in zip(actual, expected)):
        raise AssertionError(f"Rendered alpha does not match image A times the effective coefficient: {actual} versus {expected}")
    for sample in samples:
        if len(sample["rgb"]) != 3 or not all(math.isfinite(float(value)) for value in sample["rgb"]):
            raise AssertionError("Rendered RGB must contain three finite values")
    if check_rgb and case["name"] in ("alpha_full", "varied_rgb_fixed_alpha", "rgb_without_alpha"):
        luminances = [sum(float(value) for value in sample["rgb"]) for sample in samples]
        if any(right <= left for left, right in zip(luminances, luminances[1:])):
            raise AssertionError("Changing texture RGB did not produce increasing rendered color")
    return {"expected_alpha": expected, "actual_alpha": actual, "alpha_tolerance": alpha_tolerance}


def prepare(directory):
    import native_diffuse_test as diffuse
    directory = Path(directory).resolve()
    directory.mkdir(parents=True, exist_ok=True)
    manifest, cases = {}, []
    for definition in CASES:
        case = dict(definition)
        relative = "纹理/阿芙_" + case["name"] + ".png" if case["stripes"] else None
        pmx_name = "matrix_" + case["name"] + ".pmx"
        files = {pmx_name: diffuse._pmx(case["morph"], case.get("texture_morph", TEXTURE_MORPH),
                 texture_path=relative, diffuse=case["diffuse"], quad=True)}
        if relative is not None:
            files[relative] = png_bytes(case["stripes"], case["alpha"])
        for name, content in files.items():
            path = directory / name
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_bytes(content)
            manifest[name] = {"path": str(path), "bytes": len(content), "sha256": hashlib.sha256(content).hexdigest()}
        case.update(pmx=pmx_name, texture_relative=relative, texture_path=str(directory / relative) if relative else None)
        cases.append(case)
    for source_name, name, extension, encoder in (
        ("rgb_factor_zero", "tga_rgb_factor_zero", "tga", tga_bytes),
        ("gray_varied_alpha", "tiff_varied_alpha", "tif", tiff_bytes),
    ):
        source = next(case for case in cases if case["name"] == source_name)
        relative = "纹理/阿芙_" + name + "." + extension
        case = {**source, "name": name, "pmx": "matrix_" + name + ".pmx",
                "texture_relative": relative, "texture_path": str(directory / relative)}
        files = {relative: encoder(case["stripes"]), case["pmx"]: diffuse._pmx(
            True, case.get("texture_morph", TEXTURE_MORPH), texture_path=relative,
            diffuse=case["diffuse"], quad=True)}
        for filename, content in files.items():
            path = directory / filename
            path.write_bytes(content)
            manifest[filename] = {"path": str(path), "bytes": len(content),
                                  "sha256": hashlib.sha256(content).hexdigest()}
        cases.append(case)
    metadata = directory / "matrix.json"
    metadata.write_text(json.dumps(cases, indent=2, ensure_ascii=False), encoding="utf-8")
    return {"fixtures": manifest, "cases": cases, "metadata": str(metadata)}


def add_native_jpeg(suite, prepared):
    """Use the host's codec to create an opaque JPEG, without a Python package."""
    import native_diffuse_test as diffuse
    source = next(case for case in prepared["cases"] if case["name"] == "rgb_factor_zero")
    c4d = suite.c4d
    bitmap = c4d.bitmaps.BaseBitmap()
    result, _ = bitmap.InitWith(source["texture_path"])
    if result != c4d.IMAGERESULT_OK:
        raise AssertionError("Could not decode the native JPEG source fixture")
    directory = Path(source["texture_path"]).parent.parent
    relative = "纹理/阿芙_opaque_factor.jpg"
    path = directory / relative
    if bitmap.Save(str(path), c4d.FILTER_JPG, None, c4d.SAVEBIT_0) != c4d.IMAGERESULT_OK:
        raise AssertionError("Could not encode the native JPEG material fixture")
    case = {**source, "name": "jpeg_factor_zero", "texture_relative": relative,
            "texture_path": str(path), "pmx": "matrix_jpeg_factor_zero.pmx"}
    pmx = diffuse._pmx(True, case["texture_morph"], texture_path=relative, diffuse=case["diffuse"], quad=True)
    (directory / case["pmx"]).write_bytes(pmx)
    for name in (relative, case["pmx"]):
        content = (directory / name).read_bytes()
        prepared["fixtures"][name] = {"path": str(directory / name), "bytes": len(content),
                                      "sha256": hashlib.sha256(content).hexdigest()}
    prepared["cases"].append(case)
    return case

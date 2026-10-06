"""Deterministic, redistributable PMX/VMD inputs for C4D runtime regressions.

Only Python's standard library is required. No third-party model assets are used.
The small readers inspect exported data independently of Cinema 4D's scene state;
the C++ fixture test additionally validates generated inputs through libMMD.
"""

from pathlib import Path
import hashlib
import math
import struct


def pack(fmt, *values):
    return struct.pack("<" + fmt, *values)


def text(value):
    encoded = value.encode("utf-8")
    return pack("i", len(encoded)) + encoded


def fixed(value, width):
    encoded = value.encode("shift_jis")
    if len(encoded) > width:
        raise ValueError("VMD name exceeds its encoded field width")
    return encoded.ljust(width, b"\0")


def make_pmx(toon_texture=None):
    """Build the base model, optionally with a separate PMX toon texture.

    The toon variant also animates the toon texture factor. This exposes both
    import-time emission and a later material-morph sync which installs a toon
    shader in an artist-owned Luminance channel.
    """
    result = bytearray(b"PMX " + pack("fB", 2.0, 8) + bytes([1, 0, 4, 4, 4, 4, 4, 4]))
    for value in ("CMT regression", "CMT regression", "Generated test fixture", "Generated test fixture"):
        result.extend(text(value))
    result.extend(pack("i", 3))
    for position, uv in (((0., 0., 0.), (0., 0.)), ((1., 0., 0.), (1., 0.)), ((0., 1., 0.), (0., 1.))):
        result.extend(pack("3f3f2fBif", *position, 0., 0., 1., *uv, 0, 0, 1.))
    result.extend(pack("i3I", 3, 0, 1, 2))
    result.extend(pack("i", 1 if toon_texture is not None else 0))
    if toon_texture is not None:
        result.extend(text(toon_texture))
    result.extend(pack("i", 1) + text("base") + text("base"))
    result.extend(pack("4f3ff3fB4ffiiBBi", .2, .4, .6, 1., 0., 0., 0., 10.,
                       0., 0., 0., 1, 0., 0., 0., 1., 1., -1, -1, 0, 0,
                       0 if toon_texture is not None else -1))
    result.extend(text("") + pack("i", 3))
    bones = [("root", (0., 0., 0.), -1, 1), ("hinge", (0., 1., 0.), 0, 0),
             ("tip", (0., 2., 0.), 1, 0), ("goal", (1., 1., 0.), 0, 0x20)]
    result.extend(pack("i", len(bones)))
    for name, position, parent, extra in bones:
        result.extend(text(name) + text(name) + pack("3fiiH", *position, parent, 0, 0x1e | extra))
        result.extend(pack("i", 1) if extra & 1 else pack("3f", 0., .25, 0.))
        if extra & 0x20:
            result.extend(pack("iifiiB", 2, 16, .5, 1, 1, 0))
    result.extend(pack("i", 1) + text("tint") + text("tint") + pack("BBi", 4, 8, 1))
    toon_factor = [.2, .3, .4, .1] if toon_texture is not None else [0.] * 4
    result.extend(pack("iB", 0, 1) + pack("28f", .25, 0., 0., 0., *([0.] * 20), *toon_factor))
    result.extend(pack("i", 1) + text("bones") + text("bones") + pack("Bi", 0, 2))
    result.extend(pack("BiBi", 0, 0, 0, 1))
    result.extend(pack("i", 2))
    for index, position, operation in ((0, (0., 0., 0.), 0), (1, (0., 1., 0.), 1)):
        name = "rigid" + str(index)
        result.extend(text(name) + text(name))
        result.extend(pack("iBHB3f3f3f5fB", index, 0, 0xffff, 0, .1, .1, .1,
                      *position, 0., 0., 0., 1., 0., 0., 0., .5, operation))
    result.extend(pack("i", 1) + text("joint") + text("joint"))
    result.extend(pack("Bii24f", 0, 0, 1, 0., 1., 0., 0., 0., 0.,
                      -10., -10., -10., 10., 10., 10., -3.14, -3.14, -3.14,
                      3.14, 3.14, 3.14, 0., 0., 0., 0., 0., 0.))
    return bytes(result)


def make_white_toon_bitmap():
    """Generate a tiny flat white toon ramp without external image libraries.

    A 2 x 4, 24-bit BMP has white samples at every UV position. Connecting this
    shadow-lookup texture to emission therefore gives a deterministic white
    result, independently of texture filtering or the current camera.
    """
    width, height = 2, 4
    row = b"\xff" * (width * 3) + b"\0\0"  # BMP rows are aligned to four bytes.
    pixels = row * height
    file_header = b"BM" + pack("IHHI", 14 + 40 + len(pixels), 0, 0, 14 + 40)
    bitmap_header = pack("IiiHHIIiiII", 40, width, height, 1, 24, 0, len(pixels), 0, 0, 0, 0)
    return file_header + bitmap_header + pixels


def make_vmd(translation=1., morph_weight=1., visibility=True, ik_enabled=False):
    result = bytearray(fixed("Vocaloid Motion Data 0002", 30) + fixed("CMT regression", 20))
    result.extend(pack("I", 2))
    interpolation = bytes([20] * 8 + [107] * 8) * 4
    for frame, x in ((0, 0.), (2, translation)):
        result.extend(fixed("root", 15) + pack("I3f4f", frame, x, 0., 0., 0., 0., 0., 1.) + interpolation)
    result.extend(pack("I", 2))
    for frame, weight in ((0, 0.), (2, morph_weight)):
        result.extend(fixed("tint", 15) + pack("If", frame, weight))
    result.extend(pack("III", 0, 0, 0))  # cameras, lights, shadows
    result.extend(pack("IIBI", 1, 0, int(visibility), 1))
    result.extend(fixed("goal", 20) + pack("B", int(ik_enabled)))
    return bytes(result)


def make_mixed_morph_pmx():
    """A translating/rotating bone, then a group and a material morph.

    Runtime morph collection puts derived bone morphs after the root-owned group
    and material morphs. Input [bone_pose, group, tint] therefore forces index
    remapping to output [group, tint, bone_pose], exposing stale file indices.
    The root bone's 30-degree rotation and translation also make same-frame
    weight changes observable in both its world matrix and the skinned triangle.
    """
    base = make_pmx()
    material = text("tint") + text("tint") + pack("BBi", 4, 8, 1)
    material += pack("iB", 0, 1) + pack("28f", .25, 0., 0., 0., *([0.] * 24))
    old_morphs = pack("i", 1) + material
    old_frame = pack("i", 1) + text("bones") + text("bones") + pack("Bi", 0, 2)
    old_frame += pack("BiBi", 0, 0, 0, 1)
    old_segment = old_morphs + old_frame
    if base.count(old_segment) != 1:
        raise ValueError("Base PMX fixture morph/frame segment changed")
    bone = text("bone_pose") + text("bone_pose") + pack("BBi", 4, 2, 1)
    half_angle = math.radians(30.) / 2.
    bone += pack("i3f4f", 0, .3, 0., 0., 0., 0., math.sin(half_angle), math.cos(half_angle))
    group = text("group") + text("group") + pack("BBi", 4, 0, 1) + pack("if", 2, 1.)
    new_morphs = pack("i", 3) + bone + group + material
    new_frame = pack("i", 1) + text("bones") + text("bones") + pack("Bi", 0, 3)
    new_frame += pack("BiBiBi", 0, 0, 0, 1, 1, 2)
    return base.replace(old_segment, new_morphs + new_frame, 1)


def make_camera_vmd():
    result = bytearray(fixed("Vocaloid Motion Data 0002", 30) + fixed("カメラ・照明", 20))
    result.extend(pack("III", 0, 0, 2))
    for frame, x in ((0, 0.), (2, 2.)):
        result.extend(pack("If3f3f", frame, -4., x, 1., 2., 0., 0., 0.))
        result.extend(bytes([20, 107, 20, 107] * 6) + pack("IB", 45, 0))
    result.extend(pack("III", 0, 0, 0))
    return bytes(result)


def generate(directory):
    directory = Path(directory)
    directory.mkdir(parents=True, exist_ok=True)
    files = {"model.pmx": make_pmx(), "mixed_morphs.pmx": make_mixed_morph_pmx(),
             "toon_material.pmx": make_pmx("toon_white.bmp"), "toon_white.bmp": make_white_toon_bitmap(),
             "motion_a.vmd": make_vmd(),
             "motion_b.vmd": make_vmd(3., .5, False, True), "camera.vmd": make_camera_vmd()}
    receipt = {}
    for name, data in files.items():
        path = directory / name
        path.write_bytes(data)
        receipt[name] = {"path": str(path.resolve()), "sha256": hashlib.sha256(data).hexdigest(), "bytes": len(data)}
    return receipt


class Reader:
    def __init__(self, data):
        self.data, self.offset = data, 0

    def take(self, count):
        end = self.offset + count
        if count < 0 or end > len(self.data):
            raise ValueError("Truncated or invalid MMD file at byte " + str(self.offset))
        result = self.data[self.offset:end]
        self.offset = end
        return result

    def unpack(self, fmt):
        return struct.unpack("<" + fmt, self.take(struct.calcsize("<" + fmt)))

    def number(self, fmt="i"):
        return self.unpack(fmt)[0]

    def name(self, encoding="utf-8"):
        return self.take(self.number()).decode(encoding)

    def index(self, width, unsigned=False):
        return self.number({1: "B" if unsigned else "b", 2: "H" if unsigned else "h", 4: "I" if unsigned else "i"}[width])


def read_vmd(path):
    reader = Reader(Path(path).read_bytes())
    header = reader.take(30).rstrip(b"\0").decode("ascii")
    if header != "Vocaloid Motion Data 0002":
        raise ValueError("Unexpected VMD header: " + repr(header))
    result = {"model_name": reader.take(20).rstrip(b"\0").decode("shift_jis"),
              "motions": [], "morphs": [], "cameras": [], "iks": []}
    for _ in range(reader.number("I")):
        name = reader.take(15).rstrip(b"\0").decode("shift_jis")
        values = reader.unpack("I3f4f")
        reader.take(64)
        result["motions"].append({"name": name, "frame": values[0], "translation": values[1:4], "quaternion": values[4:8]})
    for _ in range(reader.number("I")):
        name = reader.take(15).rstrip(b"\0").decode("shift_jis")
        frame, weight = reader.unpack("If")
        result["morphs"].append({"name": name, "frame": frame, "weight": weight})
    for _ in range(reader.number("I")):
        values = reader.unpack("If3f3f")
        reader.take(24)
        angle, perspective = reader.unpack("IB")
        result["cameras"].append({"frame": values[0], "distance": values[1], "position": values[2:5],
                                  "rotation": values[5:8], "angle": angle, "perspective": perspective})
    reader.take(reader.number("I") * 28)  # lights
    reader.take(reader.number("I") * 9)   # shadows
    if reader.offset < len(reader.data):
        for _ in range(reader.number("I")):
            frame, show, count = reader.unpack("IBI")
            states = {}
            for _ in range(count):
                name = reader.take(20).rstrip(b"\0").decode("shift_jis")
                states[name] = bool(reader.number("B"))
            result["iks"].append({"frame": frame, "show": bool(show), "states": states})
    if reader.offset != len(reader.data):
        raise ValueError("Unexpected trailing VMD data")
    return result


def _read_pmx_prefix(reader, capture_geometry=False):
    """Consume the PMX header through bones and return their data/index widths."""
    if reader.take(4) != b"PMX ":
        raise ValueError("Not a PMX file")
    version = reader.number("f")
    header = reader.take(reader.number("B"))
    encoding = "utf-8" if header[0] else "utf-16-le"
    additional_uv, vertex_width, texture_width, material_width, bone_width, morph_width, rigid_width = header[1:8]
    names = [reader.name(encoding) for _ in range(4)]
    vertex_count = reader.number()
    vertices = []
    for _ in range(vertex_count):
        if capture_geometry:
            position, normal, uv = reader.unpack("3f"), reader.unpack("3f"), reader.unpack("2f")
            additional = [reader.unpack("4f") for _ in range(additional_uv)]
            weight_type = reader.number("B")
            bone_count = {0: 1, 1: 2, 2: 4, 3: 2, 4: 4}[weight_type]
            indices = [reader.index(bone_width) for _ in range(bone_count)]
            weights = reader.unpack("f" if weight_type in (1, 3) else "4f") if weight_type else ()
            vertex = {"position": position, "normal": normal, "uv": uv, "additional_uv": additional,
                      "weight_type": weight_type, "bone_indices": indices, "bone_weights": weights}
            if weight_type == 3:
                vertex["sdef"] = [reader.unpack("3f") for _ in range(3)]
            vertex["edge_magnitude"] = reader.number("f")
            vertices.append(vertex)
            continue
        reader.take(32 + additional_uv * 16)
        weight_type = reader.number("B")
        sizes = {0: bone_width, 1: 2 * bone_width + 4, 2: 4 * bone_width + 16,
                 3: 2 * bone_width + 40, 4: 4 * bone_width + 16}
        reader.take(sizes[weight_type] + 4)
    reader.take(reader.number() * vertex_width)
    textures = [reader.name(encoding) for _ in range(reader.number())]
    material_count = reader.number()
    materials = []
    for _ in range(material_count):
        name, english = reader.name(encoding), reader.name(encoding)
        diffuse = reader.unpack("4f")
        specular = reader.unpack("3f")
        specular_power = reader.number("f")
        ambient = reader.unpack("3f")
        flags = reader.number("B")
        edge_color = reader.unpack("4f")
        edge_size = reader.number("f")
        texture_index = reader.index(texture_width)
        sphere_index = reader.index(texture_width)
        sphere_mode, toon_mode = reader.unpack("BB")
        toon_index = reader.index(texture_width) if toon_mode == 0 else reader.number("B")
        memo, face_vertices = reader.name(encoding), reader.number()
        materials.append({"name": name, "english": english, "diffuse": diffuse, "specular": specular,
                          "specular_power": specular_power, "ambient": ambient, "flags": flags,
                          "edge_color": edge_color, "edge_size": edge_size, "texture_index": texture_index,
                          "sphere_index": sphere_index, "sphere_mode": sphere_mode, "toon_mode": toon_mode,
                          "toon_index": toon_index, "memo": memo, "face_vertices": face_vertices})
    bones = []
    for _ in range(reader.number()):
        name, english = reader.name(encoding), reader.name(encoding)
        position = reader.unpack("3f")
        parent = reader.index(bone_width)
        layer, flags = reader.unpack("iH")
        tail = reader.index(bone_width) if flags & 1 else reader.unpack("3f")
        if flags & 0x300:
            reader.take(bone_width + 4)
        if flags & 0x400:
            reader.take(12)
        if flags & 0x800:
            reader.take(24)
        if flags & 0x2000:
            reader.take(4)
        if flags & 0x20:
            reader.take(bone_width + 8)
            for _ in range(reader.number()):
                reader.take(bone_width)
                if reader.number("B"):
                    reader.take(24)
        bones.append({"name": name, "english": english, "position": position, "parent": parent,
                      "layer": layer, "flags": flags, "tail": tail})
    result = {"version": version, "model_name": names[0], "vertices": vertex_count,
              "materials": material_count, "material_data": materials, "textures": textures, "bones": bones}
    if capture_geometry:
        result["vertex_data"] = vertices
    widths = {"encoding": encoding, "vertex": vertex_width, "material": material_width,
              "bone": bone_width, "morph": morph_width, "rigid": rigid_width}
    return result, widths


def read_pmx_bones(path):
    """Read PMX bone names/parents and counts; supports exported index widths."""
    result, _ = _read_pmx_prefix(Reader(Path(path).read_bytes()))
    return result


def read_pmx_morphs_and_frames(path, *, include_physics=False):
    """Inspect morph references and display-frame targets using PMX index widths."""
    reader = Reader(Path(path).read_bytes())
    prefix, widths = _read_pmx_prefix(reader, capture_geometry=include_physics)
    encoding = widths["encoding"]
    morphs = []
    for index in range(reader.number()):
        name, english = reader.name(encoding), reader.name(encoding)
        panel, kind, count = reader.unpack("BBi")
        offsets = []
        for _ in range(count):
            if kind in (0, 9):
                offsets.append({"morph_index": reader.index(widths["morph"]), "weight": reader.number("f")})
            elif kind == 1:
                offsets.append({"vertex_index": reader.index(widths["vertex"], True), "position": reader.unpack("3f")})
            elif kind == 2:
                offsets.append({"bone_index": reader.index(widths["bone"]), "position": reader.unpack("3f"),
                                "quaternion": reader.unpack("4f")})
            elif 3 <= kind <= 7:
                offsets.append({"vertex_index": reader.index(widths["vertex"], True), "uv": reader.unpack("4f")})
            elif kind == 8:
                offsets.append({"material_index": reader.index(widths["material"]), "operation": reader.number("B"),
                                "values": reader.unpack("28f")})
            elif kind == 10:
                offsets.append({"rigid_index": reader.index(widths["rigid"]), "local": reader.number("B"),
                                "translate": reader.unpack("3f"), "rotate": reader.unpack("3f")})
            else:
                raise ValueError("Unsupported PMX morph kind " + str(kind))
        morphs.append({"index": index, "name": name, "english": english, "panel": panel,
                       "kind": kind, "offsets": offsets})
    frames = []
    for _ in range(reader.number()):
        name, english = reader.name(encoding), reader.name(encoding)
        special, count = reader.unpack("Bi")
        targets = []
        for _ in range(count):
            kind = reader.number("B")
            if kind not in (0, 1):
                raise ValueError("Unsupported PMX display-frame target kind " + str(kind))
            targets.append({"kind": kind, "index": reader.index(widths["bone"] if kind == 0 else widths["morph"])})
        frames.append({"name": name, "english": english, "special": special, "targets": targets})
    result = {"version": prefix["version"], "morphs": morphs, "display_frames": frames}
    if not include_physics:
        return result
    rigidbodies = []
    for _ in range(reader.number()):
        name, english = reader.name(encoding), reader.name(encoding)
        bone_index = reader.index(widths["bone"])
        group, mask, shape = reader.unpack("BHB")
        size, position, rotation = reader.unpack("3f"), reader.unpack("3f"), reader.unpack("3f")
        coefficients, operation = reader.unpack("5f"), reader.number("B")
        rigidbodies.append({"name": name, "english": english, "bone_index": bone_index,
                            "group": group, "mask": mask, "shape": shape, "size": size,
                            "position": position, "rotation": rotation,
                            "coefficients": coefficients, "operation": operation})
    joints = []
    for _ in range(reader.number()):
        name, english, kind = reader.name(encoding), reader.name(encoding), reader.number("B")
        indices = [reader.index(widths["rigid"]) for _ in range(2)]
        fields = ("position", "rotation", "translate_lower", "translate_upper",
                  "rotate_lower", "rotate_upper", "spring_translate", "spring_rotate")
        joint = {"name": name, "english": english, "kind": kind, "rigid_indices": indices}
        joint.update({field: reader.unpack("3f") for field in fields})
        joints.append(joint)
    if prefix["version"] > 2.05:
        if reader.number() != 0:
            raise ValueError("Scale snapshot supports the exporter's empty softbody section")
    if reader.offset != len(reader.data):
        raise ValueError("Unexpected trailing PMX data in scale snapshot")
    return {**prefix, **result, "rigidbodies": rigidbodies, "joints": joints}


if __name__ == "__main__":
    import argparse
    import json
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("directory", type=Path)
    print(json.dumps(generate(parser.parse_args().directory), indent=2))

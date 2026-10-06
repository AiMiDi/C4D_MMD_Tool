"""Inventory canonical Windows Release package inputs without building or installing.

An input pass verifies files/configuration, not the source-to-binary relationship
or native acceptance. Those require separate frozen build and runtime receipts.
"""
from pathlib import Path
import argparse
import hashlib
import json
import os
import stat
import struct

REPO = Path(__file__).resolve().parents[1]
SDKS = ("sdk_r20", "sdk_r21", "sdk_r23", "sdk_r25", "sdk_2023", "sdk_2024", "sdk_2025", "sdk_2026")
MCP_FILES = ("run_mmdtool_mcp.py", "mmdtool_mcp/__init__.py", "mmdtool_mcp/schema.py",
             "mmdtool_mcp/host.py", "mmdtool_mcp/server.py")


def identity(path):
    return {"path": str(path), "bytes": path.stat().st_size,
            "sha256": hashlib.sha256(path.read_bytes()).hexdigest()}


def linked(path):
    if path.is_symlink(): return True
    flags = getattr(path.lstat(), "st_file_attributes", 0)
    return bool(flags & getattr(stat, "FILE_ATTRIBUTE_REPARSE_POINT", 0x400))


def real_files(directory):
    if linked(directory): raise ValueError("Linked runtime directory")
    files = []
    with os.scandir(directory) as entries:
        for entry in entries:
            path = Path(entry.path)
            if linked(path): raise ValueError("Linked runtime entry: " + str(path))
            if entry.is_dir(follow_symlinks=False): files.extend(real_files(path))
            elif entry.is_file(follow_symlinks=False): files.append(identity(path))
            else: raise ValueError("Unexpected runtime entry: " + str(path))
    return sorted(files, key=lambda item: item["path"])


def pe_is_x64_dll(path):
    with path.open("rb") as stream:
        dos = stream.read(64)
        if len(dos) != 64 or dos[:2] != b"MZ": return False
        offset = struct.unpack_from("<I", dos, 60)[0]
        if offset > path.stat().st_size - 26: return False
        stream.seek(offset)
        header = stream.read(26)
        return (header[:4] == b"PE\0\0" and struct.unpack_from("<H", header, 4)[0] == 0x8664
                and struct.unpack_from("<H", header, 22)[0] & 0x2000 != 0
                and struct.unpack_from("<H", header, 24)[0] == 0x20B)


def inspect(build_root):
    records = []
    for sdk in SDKS:
        graph = build_root / sdk
        plugin = graph / "bin/Release/plugins/mmdtool"
        record = {"sdk": sdk, "path": str(plugin), "status": "incomplete", "issues": []}
        cache = graph / "CMakeCache.txt"
        if cache.is_file():
            record["cache"] = identity(cache)
            values = {}
            for line in cache.read_text(encoding="utf-8", errors="replace").splitlines():
                if not line.startswith(("#", "//")) and ":" in line and "=" in line:
                    key, value = line.split("=", 1)
                    values[key.split(":", 1)[0]] = value
            record["runtime_regression"] = values.get("CMT_ENABLE_RUNTIME_REGRESSION", "unknown")
            if record["runtime_regression"].upper() not in ("OFF", "FALSE", "0", "NO"):
                record["issues"].append("Regression bridge is enabled or not explicitly known OFF")
        else: record["issues"].append("SDK build cache missing")
        binary = plugin / "mmdtool.xdl64"
        if not binary.is_file(): record["issues"].append("Canonical Release module missing")
        elif linked(binary) or not pe_is_x64_dll(binary): record["issues"].append("Module is not a real x64 PE DLL")
        else: record["binary"] = identity(binary)
        try:
            if not plugin.is_dir(): raise ValueError("Canonical Release plugin directory missing")
            if any(linked(parent) for parent in (graph, graph / "bin", graph / "bin/Release", plugin.parent, plugin)):
                raise ValueError("Linked plugin output ancestor")
            resource = plugin / "res"
            record["resources"] = real_files(resource)
            for required in ("c4d_symbols.h", "cmt_config.json"):
                if not (resource / required).is_file(): raise ValueError("Required resource missing: " + required)
            if not (resource / "description").is_dir(): raise ValueError("Description resources missing")
            if not isinstance(json.loads((resource / "cmt_config.json").read_text(encoding="utf-8-sig")), dict):
                raise ValueError("Runtime configuration is not an object")
            adapter = plugin / "mcp"
            record["adapter"] = real_files(adapter)
            actual = {Path(item["path"]).relative_to(adapter).as_posix() for item in record["adapter"]}
            if actual != set(MCP_FILES): raise ValueError("Adapter runtime file inventory differs")
            for relative in MCP_FILES:
                if identity(adapter / relative)["sha256"] != identity(REPO / "mcp" / relative)["sha256"]:
                    raise ValueError("Stale adapter runtime: " + relative)
        except (OSError, ValueError) as error:
            record["issues"].append(str(error))
        if not record["issues"]: record["status"] = "inputs_present"
        records.append(record)
    return {"schema_version": 1, "build_root": str(build_root), "sdks": records,
            "package_inputs_ready": all(item["status"] == "inputs_present" for item in records),
            "source_build_relationship_verified": False, "native_executed": False,
            "release_accepted": False}


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--build-root", type=Path, default=REPO / "_build_msvc")
    parser.add_argument("--output", type=Path, required=True)
    args = parser.parse_args()
    result = inspect(args.build_root.resolve())
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(result, indent=2, ensure_ascii=False), encoding="utf-8")
    print(json.dumps({"ready": result["package_inputs_ready"], "output": str(args.output),
                      "sdks": [{"sdk": item["sdk"], "issues": item["issues"]} for item in result["sdks"]]},
                     ensure_ascii=False, indent=2))
    raise SystemExit(0 if result["package_inputs_ready"] else 1)

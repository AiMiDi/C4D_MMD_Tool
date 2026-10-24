#!/usr/bin/env python3
"""mmdtool 宿主驱动（只走 MCP production API + exec_python），用于建场景与基线计时。

用法（由 baseline-run.ps1 调用，也可单独跑）：
    python host-driver.py capabilities            # 查文档/插件能力
    python host-driver.py new-scene               # 新建 30FPS 场景（不动用户已有文档）
    python host-driver.py import --pmx <path> --vmd <path>
    python host-driver.py inspect                 # 构成清单 JSON
    python host-driver.py save --path <c4d>
    python host-driver.py dump --outdir <dir> --frames 0,559,619   # 变形网格快照
    python host-driver.py profile --out <csv> --physics on --warmup 20 --frames 60
    python host-driver.py render --out <png> --frame 619

所有输出都是单行 `DRIVER_RESULT:{json}`，便于 PowerShell 解析；失败时退出码非零。
"""
from __future__ import annotations

import argparse
import sys

# Windows 控制台/管道默认代码页常是 cp936，直接 print 日文/中文骨名会抛
# UnicodeEncodeError（表现为 emit 处 exit=1，且栈被截断后看不出原因）。
for _stream in (sys.stdout, sys.stderr):
    try:
        _stream.reconfigure(encoding="utf-8", errors="backslashreplace")
    except Exception:
        pass
import json
import os
import sys
import time
import uuid

REPO = r"C:\code\C4D_MMD_Tool"
sys.path.insert(0, os.path.join(REPO, "mcp"))

from mmdtool_mcp.host import HostConnection, HostError  # noqa: E402

ENDPOINT = "http://127.0.0.1:5557/mcp"
TOKEN = r"S:\tmp\cmt_vmd_profile_20261019\host_profile\prefs\mcp\token"


def connect(timeout: float = 300.0) -> HostConnection:
    host = HostConnection(ENDPOINT, TOKEN, timeout)
    host.initialize()
    return host


def op(host: HostConnection, name: str, arguments: dict, *, may_mutate: bool = True) -> dict:
    result = host.call_production(name, arguments, str(uuid.uuid4()), may_mutate=may_mutate)
    if not result.get("success"):
        raise SystemExit("operation_failed: %s %s" % (name, json.dumps(result, ensure_ascii=False)[:2000]))
    return result


def emit(payload: dict) -> None:
    print("DRIVER_RESULT:" + json.dumps(payload, ensure_ascii=False, allow_nan=True, default=str))


def run_host_code(code: str, timeout: int = 300, tolerate_error_with_stdout: bool = False) -> dict:
    """在本机宿主里执行任意只读/受控 Python；返回 stdout 与耗时。"""
    host = connect()
    started = time.perf_counter()
    result = host.request("tools/call", {"name": "exec_python", "arguments": {
        "code": code, "timeout_seconds": timeout, "max_iterations": 50000000}})
    elapsed = time.perf_counter() - started
    structured = result.get("structuredContent") or {}
    stdout = structured.get("stdout", "") if isinstance(structured, dict) else ""
    note = None
    if result.get("isError"):
        # 已知无害形态：脚本已 print 出 JSON，收尾时 Python 包装器析构抛
        # "ReferenceError: the object 'c4d.documents.BaseDocument' is not alive"。
        # 这种失败里 stdout 嵌在 content[].text 的 "--- stdout before the error (N line) ---" 之后。
        text = json.dumps(result, ensure_ascii=False)
        blobs = [item.get("text", "") for item in (result.get("content") or []) if isinstance(item, dict)]
        marker = "--- stdout before the error"
        embedded = ""
        for blob in blobs:
            index = blob.find(marker)
            if index >= 0:
                tail = blob[index:]
                newline = tail.find("\n")
                embedded = tail[newline + 1:] if newline >= 0 else ""
                break
        if tolerate_error_with_stdout and embedded.strip() and "is not alive" in text:
            stdout = embedded
            note = "teardown_referenceerror: " + text[:600]
        else:
            raise SystemExit("host_execution_failed: " + text[:4000])
    return {"stdout": stdout, "elapsed_s": round(elapsed, 3), "teardown_error": note}


# --- 场景构建 ---------------------------------------------------------------

NEW_SCENE_CODE = r'''
import json, c4d
doc = c4d.documents.BaseDocument()
doc.SetFps(30)
doc.SetMinTime(c4d.BaseTime(0, 30))
doc.SetMaxTime(c4d.BaseTime(619, 30))
doc.SetLoopMinTime(c4d.BaseTime(0, 30))
doc.SetLoopMaxTime(c4d.BaseTime(619, 30))
doc.SetTime(c4d.BaseTime(0, 30))
c4d.documents.InsertBaseDocument(doc)
c4d.documents.SetActiveDocument(doc)
_saved = doc.GetDocumentPath()
print(json.dumps({"ok": True, "fps": doc.GetFps(),
                  "min_frame": doc.GetMinTime().GetFrame(30),
                  "max_frame": doc.GetMaxTime().GetFrame(30),
                  "name": doc.GetDocumentName()}, ensure_ascii=False))
'''


def cmd_capabilities(_args) -> int:
    host = connect()
    caps = op(host, "mmdtool_capabilities", {}, may_mutate=False)
    emit(caps["data"])
    return 0


def cmd_new_scene(_args) -> int:
    out = run_host_code(NEW_SCENE_CODE, tolerate_error_with_stdout=True)
    emit({"step": "new_scene", "host": out["stdout"].strip()[-2000:], "elapsed_s": out["elapsed_s"]})
    return 0


def cmd_import(args) -> int:
    host = connect()
    caps = op(host, "mmdtool_capabilities", {}, may_mutate=False)["data"]
    documents = caps.get("documents") or []
    if not documents:
        raise SystemExit("no_document")
    document = documents[-1]["handle"]          # 最后一个 = 我们刚建的活动文档
    imported = op(host, "mmdtool_import_pmx", {"document": document, "path": args.pmx})
    model = imported["data"].get("model") or {}
    model_handle = model.get("handle") if isinstance(model, dict) else None
    if not model_handle:
        raise SystemExit("import_pmx_returned_no_model: " + json.dumps(imported, ensure_ascii=False)[:1500])
    emit({"document": document, "model": model_handle, "import_pmx": imported["data"]})
    return 0


def cmd_import_motion(args) -> int:
    host = connect()
    caps = op(host, "mmdtool_capabilities", {}, may_mutate=False)["data"]
    document = (caps.get("documents") or [])[-1]["handle"]
    models = op(host, "mmdtool_list_models", {"document": document}, may_mutate=False)["data"]["models"]
    if not models:
        raise SystemExit("no_model_to_attach_motion")
    model_handle = models[0]["handle"]
    motion = op(host, "mmdtool_import_motion", {"document": document, "model": model_handle,
                                                "path": args.vmd, "strategy": "replace"})
    emit({"document": document, "model": model_handle, "import_motion": motion["data"]})
    return 0


def cmd_inspect(_args) -> int:
    host = connect()
    caps = op(host, "mmdtool_capabilities", {}, may_mutate=False)["data"]
    document = (caps.get("documents") or [])[-1]["handle"]
    models = op(host, "mmdtool_list_models", {"document": document}, may_mutate=False)["data"]
    inspections = []
    for item in models.get("models", []):
        detail = op(host, "mmdtool_inspect_model",
                    {"document": document, "model": item["handle"], "section": "summary"},
                    may_mutate=False)["data"]
        inspections.append(detail)
    emit({"document": document, "list_models": models, "inspections": inspections})
    return 0


def cmd_save(args) -> int:
    code = r'''
import json, c4d, hashlib, os
doc = c4d.documents.GetActiveDocument()
path = %r
os.makedirs(os.path.dirname(path), exist_ok=True)
ok = c4d.documents.SaveDocument(doc, path, c4d.SAVEDOCUMENTFLAGS_0, c4d.FORMAT_C4DEXPORT)
info = {"saved": bool(ok), "path": path}
if ok and os.path.exists(path):
    info["size"] = os.path.getsize(path)
    h = hashlib.sha256()
    with open(path, "rb") as f:
        for chunk in iter(lambda: f.read(1 << 20), b""):
            h.update(chunk)
    info["sha256"] = h.hexdigest()
print(json.dumps(info, ensure_ascii=False))
''' % args.path
    out = run_host_code(code)
    emit({"step": "save", "host": out["stdout"].strip()[-2000:], "elapsed_s": out["elapsed_s"]})
    return 0



PICK_ACTIVE_PREAMBLE = r"""
# 统一入口：C4D 有多个文档时（例如快照 .c4d 残留一个空文档），
# GetActiveDocument() 未必是含场景的那个；这里选"顶层对象最多"的文档并激活。
import c4d as _c4d


def _count_top(doc):
    n = 0
    cur = doc.GetFirstObject() if doc is not None else None
    while cur is not None:
        n += 1
        cur = cur.GetNext()
    return n


_best = None
_bestn = -1
_d = _c4d.documents.GetFirstDocument()
while _d is not None:
    _n = _count_top(_d)
    if _n > _bestn:
        _best, _bestn = _d, _n
    _d = _d.GetNext()
if _best is not None:
    _c4d.documents.SetActiveDocument(_best)
    print("ACTIVE_DOC:%s objects=%d" % (_best.GetDocumentName(), _bestn))
"""

SCENE_REPORT_CODE = r'''
import json, c4d
from collections import Counter
doc = c4d.documents.GetActiveDocument()
counts = Counter(); total = 0; meshes = []; path_stack = []
def path_of(obj):
    names = []
    cur = obj
    while cur is not None:
        names.append(cur.GetName())
        cur = cur.GetUp()
    return "/".join(reversed(names))
def walk(obj):
    global total
    while obj is not None:
        total += 1
        counts[obj.GetTypeName()] += 1
        try:
            if obj.GetType() == c4d.Opolygon:
                meshes.append({"path": path_of(obj), "points": obj.GetPointCount(),
                               "polygons": obj.GetPolygonCount()})
        except Exception:
            pass
        if obj.GetDown(): walk(obj.GetDown())
        obj = obj.GetNext()
walk(doc.GetFirstObject())
names = {}
def collect_bone_names(obj):
    while obj is not None:
        if obj.GetTypeName() == "关节" and len(names) < 12:
            names[obj.GetName()] = 1
        if obj.GetDown(): collect_bone_names(obj.GetDown())
        obj = obj.GetNext()
collect_bone_names(doc.GetFirstObject())
print(json.dumps({
    "document": doc.GetDocumentName(), "path": doc.GetDocumentPath(), "fps": doc.GetFps(),
    "min_frame": doc.GetMinTime().GetFrame(doc.GetFps()),
    "max_frame": doc.GetMaxTime().GetFrame(doc.GetFps()),
    "time_frame": doc.GetTime().GetFrame(doc.GetFps()),
    "total_objects": total, "type_counts": dict(counts), "meshes": meshes,
    "sample_bone_names": list(names)[:12],
    "physics_settings": {"substeps": doc[c4d.DOCUMENT_DYNAMICSUBDIVISION] if hasattr(c4d, "DOCUMENT_DYNAMICSUBDIVISION") else None},
}, ensure_ascii=False))
'''

PROFILE_CODE = r'''
import json, time, c4d
label = __LABEL__
warmup = __WARMUP__
measure = __MEASURE__
start_frame = __START__
doc = c4d.documents.GetActiveDocument()
fps = doc.GetFps()
def evaluate(frame):
    doc.SetTime(c4d.BaseTime(frame, fps))
    t0 = time.perf_counter()
    doc.ExecutePasses(None, True, True, True, c4d.EXECUTIONFLAGS_PASS_ALL)
    return (time.perf_counter() - t0) * 1000.0
cold = evaluate(0)
warm = []
for i in range(warmup):
    warm.append(evaluate(540 + i))
frames = []
for i in range(measure):
    f = start_frame + i
    frames.append([f, round(evaluate(f), 4)])
values = sorted(item[1] for item in frames)
def pct(p):
    if not values:
        return None
    idx = min(len(values) - 1, max(0, int(round((len(values) - 1) * p))))
    return values[idx]
result = {
    "label": label, "fps": fps, "cold_eval_ms": round(cold, 4),
    "warmup_frames": [540 + i for i in range(warmup)],
    "warmup_ms": [round(v, 4) for v in warm],
    "measure_start": start_frame, "measure_count": measure,
    "frames": frames,
    "stats": {"mean_ms": round(sum(values) / len(values), 4) if values else None,
              "median_ms": pct(0.5), "p95_ms": pct(0.95), "min_ms": values[0] if values else None,
              "max_ms": values[-1] if values else None, "n": len(values)},
    "scene": {"document": doc.GetDocumentName(), "objects": None},
}
print(json.dumps(result, ensure_ascii=False))
'''

DUMP_CODE = r'''
import json, os, c4d, hashlib, struct
outdir = __OUTDIR__
frames = __FRAMES__
doc = c4d.documents.GetActiveDocument()
fps = doc.GetFps()
os.makedirs(outdir, exist_ok=True)
def evaluate(frame):
    doc.SetTime(c4d.BaseTime(frame, fps))
    doc.ExecutePasses(None, True, True, True, c4d.EXECUTIONFLAGS_PASS_ALL)
def path_of(obj):
    names = []
    cur = obj
    while cur is not None:
        names.append(cur.GetName())
        cur = cur.GetUp()
    return "/".join(reversed(names))
def gather(obj, acc):
    while obj is not None:
        try:
            if obj.GetType() == c4d.Opolygon:
                acc.append(obj)
        except Exception:
            pass
        if obj.GetDown(): gather(obj.GetDown(), acc)
        obj = obj.GetNext()
records = []
for frame in frames:
    evaluate(frame)
    meshes = []
    gather(doc.GetFirstObject(), meshes)
    for mesh in meshes:
        points = mesh.GetAllPoints()                      # 局部坐标（对象空间）
        matrix = mesh.GetMg()                             # 世界矩阵
        world = [matrix.Mul(p) for p in points]
        local_bytes = b"".join(struct.pack("<3d", p.x, p.y, p.z) for p in points)
        world_bytes = b"".join(struct.pack("<3d", p.x, p.y, p.z) for p in world)
        tag = "%s@%d" % (path_of(mesh).replace("/", "_").replace(" ", "_"), frame)
        csv_path = os.path.join(outdir, tag + ".csv")
        with open(csv_path, "w", encoding="utf-8") as handle:
            handle.write("index,x_world,y_world,z_world,x_local,y_local,z_local\n")
            for i, (pw, pl) in enumerate(zip(world, points)):
                handle.write("%d,%.9f,%.9f,%.9f,%.9f,%.9f,%.9f\n" % (i, pw.x, pw.y, pw.z, pl.x, pl.y, pl.z))
        bin_path = os.path.join(outdir, tag + ".f64")
        with open(bin_path, "wb") as handle:
            handle.write(world_bytes)
        records.append({
            "frame": frame, "object": path_of(mesh), "point_count": len(points),
            "coordinate_system": "csv: world (x_world..) + local object space (x_local..); f64: world xyz float64 little-endian",
            "local_sha256": hashlib.sha256(local_bytes).hexdigest(),
            "world_sha256": hashlib.sha256(world_bytes).hexdigest(),
            "prefix32_local": [[round(p.x, 6), round(p.y, 6), round(p.z, 6)] for p in points[:32]],
            "world_bbox": {"min": [min(p.x for p in world), min(p.y for p in world), min(p.z for p in world)],
                           "max": [max(p.x for p in world), max(p.y for p in world), max(p.z for p in world)]},
            "csv": csv_path, "bin": bin_path,
        })
print(json.dumps({"frames": frames, "records": records}, ensure_ascii=False))
'''

RENDER_CODE = r'''
import json, os, c4d
out = __OUT__
frame = __FRAME__
doc = c4d.documents.GetActiveDocument()
fps = doc.GetFps()
doc.SetTime(c4d.BaseTime(frame, fps))
doc.ExecutePasses(None, True, True, True, c4d.EXECUTIONFLAGS_PASS_ALL)
info = {"out": out, "frame": frame}
try:
    bmp = c4d.bitmaps.BaseBitmap()
    bmp.Init(640, 360, 24)
    info["bitmap"] = True
except Exception as error:
    info["bitmap_error"] = repr(error)
    print(json.dumps(info, ensure_ascii=False)); raise SystemExit(0)
try:
    rdata = doc.GetActiveRenderData()
    if rdata is not None:
        rdata[c4d.RDATA_XRES] = 640
        rdata[c4d.RDATA_YRES] = 360
        rdata[c4d.RDATA_FRAMESEQUENCE] = c4d.RDATA_FRAMESEQUENCE_MANUAL
        try:
            rdata[c4d.RDATA_RENDERENGINE] = 0  # standard renderer, avoid Redshift startup cost
        except Exception:
            pass
    info["render_data"] = bool(rdata)
    result = c4d.documents.RenderDocument(doc, rdata.GetData() if rdata is not None else None, bmp,
                                          c4d.RENDERFLAGS_EXTERNAL | c4d.RENDERFLAGS_OPEN_PICTUREVIEWER)
    info["render_result"] = int(result)
    if result == c4d.RENDERRESULT_OK:
        os.makedirs(os.path.dirname(out), exist_ok=True)
        bmp.Save(out, c4d.FILTER_PNG)
        info["saved"] = os.path.exists(out)
        if os.path.exists(out):
            info["size"] = os.path.getsize(out)
    else:
        info["skip_reason"] = "RenderDocument returned %d" % int(result)
except Exception as error:
    info["error"] = repr(error)
    info["skip_reason"] = "render failed: %r" % (error,)
print(json.dumps(info, ensure_ascii=False))
'''


def cmd_set_mode(args) -> int:
    host = connect()
    caps = op(host, "mmdtool_capabilities", {}, may_mutate=False)["data"]
    document = (caps.get("documents") or [])[-1]["handle"]
    models = op(host, "mmdtool_list_models", {"document": document}, may_mutate=False)["data"]["models"]
    result = op(host, "mmdtool_set_mode",
                {"document": document, "model": models[0]["handle"], "mode": args.mode})
    emit({"set_mode": args.mode, "data": result["data"]})
    return 0


def cmd_physics(args) -> int:
    host = connect()
    caps = op(host, "mmdtool_capabilities", {}, may_mutate=False)["data"]
    document = (caps.get("documents") or [])[-1]["handle"]
    models = op(host, "mmdtool_list_models", {"document": document}, may_mutate=False)["data"]["models"]
    result = op(host, "mmdtool_set_physics_enabled",
                {"document": document, "model": models[0]["handle"], "enabled": args.enabled == "on"})
    emit({"physics": args.enabled, "data": result["data"]})
    return 0


def cmd_scene_report(args) -> int:
    out = run_host_code(PICK_ACTIVE_PREAMBLE + SCENE_REPORT_CODE)
    payload = json.loads(out["stdout"].strip().splitlines()[-1])
    payload["exec_elapsed_s"] = out["elapsed_s"]
    if args.out:
        os.makedirs(os.path.dirname(os.path.abspath(args.out)), exist_ok=True)
        with open(args.out, "w", encoding="utf-8") as handle:
            json.dump(payload, handle, ensure_ascii=False, indent=2)
    emit(payload)
    return 0


def cmd_profile(args) -> int:
    code = (PICK_ACTIVE_PREAMBLE + PROFILE_CODE)
    code = (code.replace("__LABEL__", json.dumps(args.label))
                .replace("__WARMUP__", str(args.warmup))
                .replace("__MEASURE__", str(args.frames))
                .replace("__START__", str(args.start)))
    out = run_host_code(code, timeout=600)
    payload = json.loads(out["stdout"].strip().splitlines()[-1])
    payload["exec_elapsed_s"] = out["elapsed_s"]
    if args.csv:
        with open(args.csv, "w", encoding="utf-8", newline="") as handle:
            handle.write("frame,ms\n")
            for frame, ms in payload["frames"]:
                handle.write("%d,%.4f\n" % (frame, ms))
        payload["csv"] = args.csv
    emit(payload)
    return 0


def cmd_dump(args) -> int:
    frames = [int(item) for item in args.frames.split(",") if item.strip()]
    code = (PICK_ACTIVE_PREAMBLE + DUMP_CODE)
    code = (code.replace("__OUTDIR__", json.dumps(args.outdir))
                .replace("__FRAMES__", json.dumps(frames)))
    out = run_host_code(code, timeout=900)
    payload = json.loads(out["stdout"].strip().splitlines()[-1])
    payload["exec_elapsed_s"] = out["elapsed_s"]
    if args.out:
        os.makedirs(os.path.dirname(os.path.abspath(args.out)), exist_ok=True)
        with open(args.out, "w", encoding="utf-8") as handle:
            json.dump(payload, handle, ensure_ascii=False, indent=2)
    emit(payload)
    return 0


def cmd_render(args) -> int:
    code = (PICK_ACTIVE_PREAMBLE + RENDER_CODE)
    code = (code.replace("__OUT__", json.dumps(args.out))
                .replace("__FRAME__", str(args.frame)))
    out = run_host_code(code, timeout=900)
    payload = json.loads(out["stdout"].strip().splitlines()[-1])
    payload["exec_elapsed_s"] = out["elapsed_s"]
    emit(payload)
    return 0


LOAD_CODE = r"""
import json, c4d, os
path = __PATH__
info = {"path": path, "exists": os.path.exists(path)}
doc = c4d.documents.LoadDocument(path, c4d.SCENEFILTER_0, None)
info["loaded"] = bool(doc)
if doc is not None:
    # LoadDocument 返回的是未被文档列表持有的对象：必须 InsertBaseDocument 接管，
    # 否则脚本结束后 Python 包装器析构会把文档带走（表面现象：下一个调用报 no active document）。
    inserted = c4d.documents.InsertBaseDocument(doc)
    info["inserted"] = bool(inserted)
    c4d.documents.SetActiveDocument(doc)
    active = c4d.documents.GetActiveDocument()
    info["active_name"] = active.GetDocumentName() if active is not None else None
    info["name"] = doc.GetDocumentName()
    info["path"] = doc.GetDocumentPath()
    info["fps"] = doc.GetFps()
    info["min_frame"] = doc.GetMinTime().GetFrame(doc.GetFps())
    info["max_frame"] = doc.GetMaxTime().GetFrame(doc.GetFps())
    info["animation_frames"] = doc[c4d.DOCUMENT_TIME] if False else None
print(json.dumps(info, ensure_ascii=False))
"""


def cmd_load(args) -> int:
    code = LOAD_CODE.replace("__PATH__", json.dumps(args.path))
    out = run_host_code(code, timeout=600, tolerate_error_with_stdout=True)
    payload = json.loads(out["stdout"].strip().splitlines()[-1])
    payload["exec_elapsed_s"] = out["elapsed_s"]
    payload["host_teardown_error"] = out.get("teardown_error")
    if not payload.get("loaded"):
        raise SystemExit("scene_load_failed: " + json.dumps(payload, ensure_ascii=False)[:800])
    emit(payload)
    return 0

def main(argv: list[str]) -> int:
    parser = argparse.ArgumentParser()
    sub = parser.add_subparsers(dest="command", required=True)

    sub.add_parser("capabilities").set_defaults(func=cmd_capabilities)
    sub.add_parser("new-scene").set_defaults(func=cmd_new_scene)

    p_import = sub.add_parser("import")
    p_import.add_argument("--pmx", required=True)
    p_import.add_argument("--vmd", required=True)
    p_import.set_defaults(func=cmd_import)

    p_motion = sub.add_parser("import-motion")
    p_motion.add_argument("--vmd", required=True)
    p_motion.set_defaults(func=cmd_import_motion)

    sub.add_parser("inspect").set_defaults(func=cmd_inspect)

    p_save = sub.add_parser("save")
    p_save.add_argument("--path", required=True)
    p_save.set_defaults(func=cmd_save)

    p_mode = sub.add_parser("set-mode")
    p_mode.add_argument("--mode", choices=("edit", "anim"), default="anim")
    p_mode.set_defaults(func=cmd_set_mode)

    p_phys = sub.add_parser("physics")
    p_phys.add_argument("--enabled", choices=("on", "off"), required=True)
    p_phys.set_defaults(func=cmd_physics)

    p_report = sub.add_parser("scene-report")
    p_report.add_argument("--out")
    p_report.set_defaults(func=cmd_scene_report)

    p_profile = sub.add_parser("profile")
    p_profile.add_argument("--label", required=True)
    p_profile.add_argument("--warmup", type=int, default=20)
    p_profile.add_argument("--frames", type=int, default=60)
    p_profile.add_argument("--start", type=int, default=560)
    p_profile.add_argument("--csv")
    p_profile.set_defaults(func=cmd_profile)

    p_dump = sub.add_parser("dump")
    p_dump.add_argument("--outdir", required=True)
    p_dump.add_argument("--frames", default="540,560,619")
    p_dump.add_argument("--out")
    p_dump.set_defaults(func=cmd_dump)

    p_load = sub.add_parser("load")
    p_load.add_argument("--path", required=True)
    p_load.set_defaults(func=cmd_load)

    p_render = sub.add_parser("render")
    p_render.add_argument("--out", required=True)
    p_render.add_argument("--frame", type=int, default=619)
    p_render.set_defaults(func=cmd_render)

    args = parser.parse_args(argv)
    try:
        return args.func(args)
    except HostError as error:
        emit({"error": error.code, "message": str(error)})
        return 2


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))

#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""P2 异步物理验证：刚体世界变换 + 网格锚点采样探针。

用途（t31 方案的一部分，本文件只写不跑）：
  在**已经启动好**的隔离宿主里，对若干帧依次执行
  ``SetTime(frame) -> ExecutePasses(PASS_ALL)`` 之后立刻采样：
    1) 每个 MMDRigidObject 的世界矩阵（12 个 float32，逐字节可比）；
    2) 每个多边网格对象的局部/世界顶点 sha256 与点数。

为什么不复用 host-driver.py：
  host-driver.py（docs/validation/vmd-host-restore-20261024/）只有 mesh dump，
  没有刚体采样；本任务 inScope 只有 docs/validation/vmd-physics-async-20261024，
  不能改它，因此这里自带一份最小实现（网格取样逻辑与 host-driver.py 的 DUMP_CODE
  保持一致：局部坐标走 GetAllPoints()，世界坐标走 GetMg().Mul(p)）。

刚体可见性的前提（P2-002 要验证的正是这一点）：
  ``MMDRigidObject::Execute``（source/module/tools/object/mmd_rigid.cpp:685）只在
  ``m_display_type != RIGID_DISPLAY_TYPE_OFF`` 时把 ``mmd_rigidbody_->GetTransform()``
  写进对象相对矩阵。刚体管理器上 RIGID_DISPLAY_TYPE 的 id 是 1001
  （res/S24_up/description/OMMDRigidManager.h: RIGID_MANAGER_GRP=1000, RIGID_DISPLAY_TYPE=1001,
  取值 OFF=0 / ON=1 / WIRE=2）。所以采样前必须 ``--enable-rigid-display`` 打开显示，
  否则刚体矩阵恒为初始值，测到的「一致」是假象。

自校验（fail-closed）：
  * 打开显示后，如果样例刚体矩阵在两帧之间完全没有变化，说明显示没生效或物理没跑，
    直接报 ``rigid_display_not_enabled`` 并退出码 2，绝不把「恒等」当结论；
  * 采样到的刚体数必须等于 ``--expect-rigid``（默认 479），否则退出码 3 并打印类型分布，
    防止选择器抓错对象。

退出码：0 成功；2 前提不成立（显示/物理未生效）；3 计数不符；4 宿主/连接错误。
"""

from __future__ import annotations

import argparse
import hashlib
import json
import os
import struct
import sys
import time
from pathlib import Path

REPO_ROOT = Path(r"C:\code\C4D_MMD_Tool")
DEFAULT_PREFS = Path(r"S:\tmp\cmt_vmd_profile_20261019\host_profile")
DEFAULT_ENDPOINT = "http://127.0.0.1:5557/mcp"
TOKEN_RELATIVE = Path("prefs") / "mcp" / "token"


def import_host_module():
    """导入仓库自带的 MCP 客户端。

    坑：仓库里有个顶层包叫 ``mcp``，直接把仓库根加进 sys.path 会命中 PyPI 的 mcp 包
    并报 ModuleNotFoundError，所以要把 ``<repo>/mcp`` 加进 sys.path 再导 ``mmdtool_mcp``。
    """
    repo_mcp = REPO_ROOT / "mcp"
    if not repo_mcp.is_dir():
        raise SystemExit(f"repo mcp directory not found: {repo_mcp}")
    sys.path.insert(0, str(repo_mcp))
    from mmdtool_mcp.host import HostConnection  # noqa: WPS433 (deliberate late import)

    return HostConnection


# ----------------------------------------------------------------------------------
# 宿主内执行的代码模板
# ----------------------------------------------------------------------------------
HOST_CODE = r'''
import c4d
import hashlib
import json
import struct

FRAMES = __FRAMES__
ENABLE_RIGID_DISPLAY = __ENABLE_RIGID_DISPLAY__
EXEC_FLAGS = __EXEC_FLAGS__
RIGID_MANAGER_DISPLAY_ID = 1001   # res/S24_up/description/OMMDRigidManager.h
RIGID_DISPLAY_ON = 1

doc = c4d.documents.GetActiveDocument()
if doc is None:
    print(json.dumps({"error": "no_active_document"}))
    raise SystemExit(0)

# 多文档时 GetActiveDocument() 不一定是场景文档：选顶层对象最多的那个。
best = doc
best_count = -1
first = c4d.documents.GetFirstDocument()
cur = first
while cur is not None:
    count = 0
    top = cur.GetFirstObject()
    while top is not None:
        count += 1
        top = top.GetNext()
    if count > best_count:
        best_count = count
        best = cur
    cur = cur.GetNext()
if best is not doc:
    c4d.documents.SetActiveDocument(best)
    doc = best


def walk(obj, acc):
    while obj is not None:
        acc.append(obj)
        if obj.GetDown():
            walk(obj.GetDown(), acc)
        obj = obj.GetNext()


def type_name(obj):
    try:
        return obj.GetTypeName()
    except Exception:
        return ""


def is_rigid(obj):
    name = type_name(obj)
    if name and "rigid" in name.lower():
        return True
    try:
        return obj.GetName().startswith("MMD刚体")
    except Exception:
        return False


def path_of(obj):
    names = []
    cur = obj
    while cur is not None:
        names.append(cur.GetName())
        cur = cur.GetUp()
    return "/".join(reversed(names))


def matrix_bytes(mg):
    """把 4x4 世界矩阵压成 12 个 float32（v1, v2, v3, off），用于逐字节比较。"""
    values = []
    for v in (mg.v1, mg.v2, mg.v3, mg.off):
        values.extend([float(v.x), float(v.y), float(v.z)])
    return b"".join(struct.pack("<f", value) for value in values), values


def evaluate(frame):
    doc.SetTime(c4d.BaseTime(frame, doc.GetFps()))
    doc.ExecutePasses(None, True, True, True, EXEC_FLAGS)


rigid_display = {"requested": ENABLE_RIGID_DISPLAY, "managers": [], "applied": False}
if ENABLE_RIGID_DISPLAY:
    objects = []
    walk(doc.GetFirstObject(), objects)
    for obj in objects:
        name = type_name(obj)
        if name and "rigidmanagers" in name.lower() or (name and name.startswith("MMDRigidManager")):
            before = None
            try:
                before = obj[RIGID_MANAGER_DISPLAY_ID]
            except Exception:
                before = "<unreadable>"
            try:
                obj[RIGID_MANAGER_DISPLAY_ID] = RIGID_DISPLAY_ON
                rigid_display["managers"].append({"name": obj.GetName(), "before": str(before), "after": str(obj[RIGID_MANAGER_DISPLAY_ID])})
                rigid_display["applied"] = True
            except Exception as error:
                rigid_display["managers"].append({"name": obj.GetName(), "error": repr(error)})
    try:
        c4d.EventAdd()
    except Exception:
        pass

records = []
for frame in FRAMES:
    evaluate(frame)
    objects = []
    walk(doc.GetFirstObject(), objects)

    rigids = []
    for obj in objects:
        if not is_rigid(obj):
            continue
        raw, values = matrix_bytes(obj.GetMg())
        rigids.append({
            "path": path_of(obj),
            "name": obj.GetName(),
            "matrix_hex": raw.hex(),
            "matrix": [round(value, 9) for value in values],
        })
    rigids.sort(key=lambda item: item["path"])

    meshes = []
    for obj in objects:
        try:
            if obj.GetType() != c4d.Opolygon:
                continue
        except Exception:
            continue
        points = obj.GetAllPoints()
        mg = obj.GetMg()
        world = [mg.Mul(p) for p in points]
        local_bytes = b"".join(struct.pack("<3d", p.x, p.y, p.z) for p in points)
        world_bytes = b"".join(struct.pack("<3d", p.x, p.y, p.z) for p in world)
        meshes.append({
            "object": path_of(obj),
            "point_count": len(points),
            "local_sha256": hashlib.sha256(local_bytes).hexdigest(),
            "world_sha256": hashlib.sha256(world_bytes).hexdigest(),
        })
    meshes.sort(key=lambda item: item["object"])

    rigid_blob = b"".join(bytes.fromhex(item["matrix_hex"]) for item in rigids)
    records.append({
        "frame": frame,
        "rigid_count": len(rigids),
        "rigid_sha256": hashlib.sha256(rigid_blob).hexdigest(),
        "rigids": rigids,
        "meshes": meshes,
    })

print(json.dumps({
    "schema": "vmd-async-probe/1",
    "document": doc.GetDocumentName(),
    "fps": doc.GetFps(),
    "frames": FRAMES,
    "rigid_display": rigid_display,
    "records": records,
}, ensure_ascii=False))
'''


def parse_frames(raw: str) -> list:
    frames = []
    for chunk in str(raw).replace(" ", ",").split(","):
        chunk = chunk.strip()
        if not chunk:
            continue
        frames.append(int(chunk))
    if not frames:
        raise SystemExit("no frames given")
    return frames


def run_host_code(connection, code: str, timeout: float) -> dict:
    """通过 exec_python 跑一段宿主内代码，取回 JSON。

    exec_python 抛异常时 isError=True，且 structuredContent 里没有 stdout/stderr，
    所以模板自己保证「正常路径 print(json)」，异常由这里显式报错。
    """
    import uuid

    result = connection.call_production(
        "exec_python",
        {"code": code, "timeout_seconds": int(timeout)},
        str(uuid.uuid4()),
        may_mutate=True,
    )
    data = result.get("data") or {}
    if result.get("is_error") or data.get("is_error"):
        raise RuntimeError(f"exec_python failed: {json.dumps(result.get('raw', data))[:2000]}")
    stdout = ""
    structured = data.get("structuredContent") or data.get("structured_content") or {}
    if isinstance(structured, dict):
        stdout = structured.get("stdout") or ""
    if not stdout:
        stdout = data.get("stdout") or ""
    text = stdout.strip()
    start = text.find("{")
    if start < 0:
        raise RuntimeError(f"no JSON in host stdout: {text[:800]}")
    return json.loads(text[start:])


def main(argv=None) -> int:
    parser = argparse.ArgumentParser(description="Sample MMDRigidObject world matrices and mesh anchors from a running isolated host")
    parser.add_argument("--frames", default="539,540,541,559,560,561,618,619,620", help="comma separated frame numbers")
    parser.add_argument("--out", required=True, help="output JSON path")
    parser.add_argument("--endpoint", default=None, help=f"default: {DEFAULT_ENDPOINT}")
    parser.add_argument("--token-file", default=None, help="default: <prefs>/mcp/token")
    parser.add_argument("--prefs-path", default=str(DEFAULT_PREFS), help="host private profile root")
    parser.add_argument("--timeout", type=float, default=300.0)
    parser.add_argument("--expect-rigid", type=int, default=479)
    parser.add_argument("--expect-points", type=int, default=70222)
    parser.add_argument("--enable-rigid-display", action="store_true", help="打开刚体显示，否则刚体矩阵不随物理更新")
    parser.add_argument("--exec-flags", choices=["all", "default"], default="all")
    args = parser.parse_args(argv)

    frames = parse_frames(args.frames)
    prefs = Path(args.prefs_path)
    token_file = Path(args.token_file) if args.token_file else prefs / TOKEN_RELATIVE
    endpoint = args.endpoint or DEFAULT_ENDPOINT

    if not token_file.is_file():
        print(f"PROBE_ERROR token file missing: {token_file}", file=sys.stderr)
        return 4

    flags_expr = "c4d.EXECUTIONFLAGS_PASS_ALL" if args.exec_flags == "all" else "c4d.EXECUTIONFLAGS_0"
    code = (
        HOST_CODE.replace("__FRAMES__", repr(frames))
        .replace("__ENABLE_RIGID_DISPLAY__", "True" if args.enable_rigid_display else "False")
        .replace("__EXEC_FLAGS__", flags_expr)
    )

    HostConnection = import_host_module()
    started = time.time()
    try:
        connection = HostConnection(endpoint, str(token_file), int(args.timeout))
    except Exception as error:  # noqa: BLE001 - host may be down, report as data
        print(f"PROBE_ERROR connect failed: {error!r}", file=sys.stderr)
        return 4

    try:
        payload = run_host_code(connection, code, args.timeout)
    except Exception as error:  # noqa: BLE001
        print(f"PROBE_ERROR exec failed: {error!r}", file=sys.stderr)
        return 4

    records = payload.get("records") or []
    if not records:
        print("PROBE_ERROR no records", file=sys.stderr)
        return 4

    rigid_counts = sorted({item["rigid_count"] for item in records})
    if rigid_counts != [args.expect_rigid]:
        print(f"PROBE_ERROR rigid count mismatch: {rigid_counts} != [{args.expect_rigid}]", file=sys.stderr)
        return 3

    point_counts = sorted({mesh["point_count"] for item in records for mesh in item["meshes"] if mesh["point_count"] > 0})
    if args.expect_points and point_counts and point_counts != [args.expect_points]:
        print(f"PROBE_WARN mesh point counts {point_counts} != [{args.expect_points}]", file=sys.stderr)

    # fail-closed：刚体显示/物理没生效时，所有帧的刚体 sha 会完全相同。
    rigid_shas = [item["rigid_sha256"] for item in records]
    distinct_rigid = len(set(rigid_shas))
    if args.enable_rigid_display and distinct_rigid == 1:
        print("PROBE_ERROR rigid_display_not_enabled: all frames share one rigid_sha256", file=sys.stderr)
        return 2

    result = {
        "schema": "vmd-async-probe-result/1",
        "endpoint": endpoint,
        "token_file": str(token_file),
        "prefs_path": str(prefs),
        "exec_flags": args.exec_flags,
        "enable_rigid_display": bool(args.enable_rigid_display),
        "frames": frames,
        "rigid_count": rigid_counts,
        "distinct_rigid_sha256": distinct_rigid,
        "point_counts": point_counts,
        "elapsed_s": round(time.time() - started, 3),
        "host": payload,
    }

    out_path = Path(args.out)
    out_path.parent.mkdir(parents=True, exist_ok=True)
    out_path.write_text(json.dumps(result, ensure_ascii=False, indent=2), encoding="utf-8")
    print("PROBE_RESULT:" + json.dumps({
        "out": str(out_path),
        "frames": frames,
        "rigid_count": rigid_counts,
        "distinct_rigid_sha256": distinct_rigid,
        "mesh_shas": {item["frame"]: [mesh["local_sha256"] for mesh in item["meshes"]] for item in records},
    }, ensure_ascii=False))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())

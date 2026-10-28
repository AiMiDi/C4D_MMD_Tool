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
# seek 场景（P4）：在采完 SEEK_AFTER 帧后，一次性跳到 SEEK_TO 帧求值一次，
# 目的是让宿主走「时间跳变 → 物理重建」路径；之后继续按 FRAMES 采样。
SEEK_AFTER = __SEEK_AFTER__
SEEK_TO = __SEEK_TO__
MESH_FRAMES = __MESH_FRAMES__
ENABLE_RIGID_DISPLAY = __ENABLE_RIGID_DISPLAY__
EXEC_FLAGS = __EXEC_FLAGS__
RIGID_MANAGER_DISPLAY_ID = 1001   # res/S24_up/description/OMMDRigidManager.h
RIGID_DISPLAY_ON = 1

# res/S24_up/description/OMMDRigid.h: PMX_RIGID_OBJ_GRP=10000 起
RIGID_INDEX_ID = 10001            # 字符串参数（String::IntToString 存储）
RIGID_NAME_LOCAL_ID = 10003
RIGID_NAME_UNIVERSAL_ID = 10004
RIGID_RELATED_BONE_ID = 10006     # Int32，-1 表示不关联骨骼
# 0 = 跟随骨骼（libMMD Kinematic）、1 = 物理（Dynamic）、2 = 物理+骨骼对齐（DynamicAndBoneMerge / libMMD Aligned）
# 注意：单独放在 rigid_modes 里，不进 roster，避免改变 roster_sha256 这个跨轮锚点。
RIGID_PHYSICS_MODE_ID = 10007     # res/S24_up/description/OMMDRigid.h: PMX_RIGID_OBJ_GRP=10000 起第 8 个
# 0 = 跟随骨骼（不参与求解，异步下无 lag），1 = 物理演算，2 = 物理演算 + 骨骼位置对齐。
# 注意 10013 是 RIGID_SHAPE_SIZE_Z（浮点尺寸），早先误当成类型读，导致 477 个刚体都读成 0。
# res/S24_up/description/TMMDBone.h: PMX_BONE_INFO_GRP=10000 起
BONE_INDEX_ID = 10001

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
    # 首选按描述参数判定（RIGID_INDEX 只有刚体对象才有），名称前缀只作为兜底
    if read_int_param(obj, RIGID_INDEX_ID) is not None:
        return True
    name = type_name(obj)
    if name and "rigid" in name.lower() and "manager" not in name.lower():
        return True
    try:
        # 兜底必须排除「MMD刚体管理器」——它的名字也以 MMD刚体 开头，会把 479 数成 480
        object_name = obj.GetName()
        return object_name.startswith("MMD刚体") and "管理器" not in object_name
    except Exception:
        return False


def read_param(obj, param_id):
    try:
        return obj[param_id]
    except Exception:
        return None


def read_int_param(obj, param_id):
    """RIGID_INDEX 是字符串参数，RIGID_RELATED_BONE_INDEX / BONE_INDEX 是 Int32，统一读成 int。"""
    value = read_param(obj, param_id)
    if value is None:
        return None
    if isinstance(value, str):
        try:
            return int(value.strip())
        except Exception:
            return None
    try:
        return int(value)
    except Exception:
        return None


def read_str_param(obj, param_id):
    value = read_param(obj, param_id)
    return None if value is None else str(value)


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
        # 修正运算符优先级：原写法 `A and B or (A and C)` 在中文类型名（MMD刚体管理器）下永不命中
        if name and ("rigidmanagers" in name.lower() or name.startswith("MMDRigidManager") or "刚体管理器" in name):
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

# --- P2-004：刚体名册（与帧无关，只取一次）----------------------------------
objects_all = []
walk(doc.GetFirstObject(), objects_all)

bone_map = {}
for obj in objects_all:
    try:
        tags = obj.GetTags() or []   # 2027 的 GetTags() 返回 list，不是链表
    except Exception:
        tags = []
    for tag in tags:
        bone_index_in_tag = read_int_param(tag, BONE_INDEX_ID)
        if bone_index_in_tag is not None and bone_index_in_tag not in bone_map:
            bone_map[bone_index_in_tag] = {"object": path_of(obj), "name": obj.GetName()}

roster = []
rigid_modes = {}
for obj in objects_all:
    rigid_index = read_int_param(obj, RIGID_INDEX_ID)
    if rigid_index is None:
        continue
    bone_index = read_int_param(obj, RIGID_RELATED_BONE_ID)
    bone_name = None
    bone_path = None
    if bone_index is not None and bone_index >= 0:
        entry = bone_map.get(bone_index)
        if entry is not None:
            bone_name = entry["name"]
            bone_path = entry["object"]
    mode = read_int_param(obj, RIGID_PHYSICS_MODE_ID)
    if mode is not None:
        rigid_modes[str(rigid_index)] = mode
    roster.append({
        "rigid_index": rigid_index,
        "name_local": read_str_param(obj, RIGID_NAME_LOCAL_ID),
        "name_universal": read_str_param(obj, RIGID_NAME_UNIVERSAL_ID),
        "bone_index": bone_index,
        "bone_name": bone_name,
        "bone_path": bone_path,
        "path": path_of(obj),
    })
roster.sort(key=lambda item: item["rigid_index"])
roster_sha256 = hashlib.sha256(json.dumps(roster, sort_keys=True, ensure_ascii=False).encode("utf-8")).hexdigest()

records = []
seek_events = []
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
    mesh_objects = objects if frame in MESH_FRAMES else []
    for obj in mesh_objects:
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

    if SEEK_AFTER >= 0 and SEEK_TO >= 0 and frame == SEEK_AFTER:
        # 时间跳变求值：宿主会走物理重建路径（P4 是 RebuildStandaloneAsyncShadow）。
        # 这里只记录跳变前后的刚体状态指纹与文档时间，等价判定留给客户端脚本。
        evaluate(SEEK_TO)
        seek_objects = []
        walk(doc.GetFirstObject(), seek_objects)
        seek_rigids = [obj for obj in seek_objects if is_rigid(obj)]
        seek_blob = b"".join(matrix_bytes(obj.GetMg())[0] for obj in seek_rigids)
        seek_events.append({
            "after_frame": frame,
            "target_frame": SEEK_TO,
            "rigid_count": len(seek_rigids),
            "rigid_sha256_before": records[-1]["rigid_sha256"],
            "rigid_sha256_after": hashlib.sha256(seek_blob).hexdigest(),
            "doc_time_seconds_after": doc.GetTime().Get(),
        })

payload = {
    "schema": "vmd-async-probe/2",
    "document": doc.GetDocumentName(),
    "fps": doc.GetFps(),
    "frames": FRAMES,
    "rigid_display": rigid_display,
    "roster_count": len(roster),
    "roster_sha256": roster_sha256,
    "bone_map_count": len(bone_map),
    "roster": roster,
    # 刚体类型（10013）：0=骨骼跟随（不参与求解，无 lag），1/2=动力学（参与求解，异步下 lag=1）。
    # 判据必须按类型分档比较：把骨骼跟随刚体也按 lag=1 比，等于拿两帧不同的骨骼姿态相减，
    # 天生差几毫米到几十毫米，会把「语义正确」误判成发散。
    "rigid_modes": rigid_modes,
    "records": records,
    "seek_events": seek_events,
}

# 结果落盘而不是从 stdout 回传：9 帧 × 479 刚体的矩阵清单有几百 KB，
# exec_python 的 stdout 通道会把它截断（实测 "no JSON in host stdout"）。
try:
    with open(__OUT_PATH__, "w", encoding="utf-8") as handle:
        json.dump(payload, handle, ensure_ascii=False)
    print(json.dumps({
        "schema": "vmd-async-probe/2",
        "written": __OUT_PATH__,
        "records": len(records),
        "roster_count": len(roster),
        "roster_sha256": roster_sha256,
    }, ensure_ascii=False), flush=True)
except Exception as exc:  # noqa: BLE001 - 用 stdout 把失败原因带回客户端
    print(json.dumps({"error": "write_failed", "detail": repr(exc)}, ensure_ascii=False), flush=True)
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

    传输层与 host-driver.py 一致：直接 `tools/call`，读 structuredContent.stdout；
    isError 时从 content[].text 的 "--- stdout before the error" 之后取回已打印的 stdout。
    """
    started = time.perf_counter()
    result = connection.request("tools/call", {"name": "exec_python", "arguments": {
        "code": code, "timeout_seconds": int(timeout), "max_iterations": 50000000}})
    elapsed = time.perf_counter() - started
    structured = result.get("structuredContent") or {}
    stdout = structured.get("stdout", "") if isinstance(structured, dict) else ""
    teardown_note = None
    if result.get("isError"):
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
        if embedded.strip():
            # 已有输出就算成功：C4D 的 exec 包装器常在收尾时抛 ReferenceError("... is not alive")
            stdout = embedded
            teardown_note = "teardown_error: " + text[:600]
        else:
            raise RuntimeError("host_execution_failed: " + text[:2000])
    text = stdout.strip()
    start = text.find("{")
    if start < 0:
        raise RuntimeError(f"no JSON in host stdout: {text[:800]}")
    payload = json.loads(text[start:])
    if isinstance(payload, dict):
        payload.setdefault("exec_elapsed_s", round(elapsed, 3))
        if teardown_note:
            payload.setdefault("teardown_note", teardown_note)
    return payload


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
    parser.add_argument("--strict-roster", action="store_true", help="关联骨骼名解析不出来时直接失败（P2-004 严格模式）")
    parser.add_argument("--seek-after-frame", type=int, default=-1, help="P4 seek 场景：采完该帧后做一次时间跳变（需配 --seek-to-frame）")
    parser.add_argument("--seek-to-frame", type=int, default=-1, help="P4 seek 场景：跳变目标帧（跳变后继续按 --frames 采样）")
    parser.add_argument("--mesh-frames", default="540,560,619", help="只在这些帧计算网格 sha（锚点旁证）；其余帧 meshes=[]")
    args = parser.parse_args(argv)

    frames = parse_frames(args.frames)
    if (args.seek_after_frame >= 0) != (args.seek_to_frame >= 0):
        print("PROBE_ERROR seek_after_frame and seek_to_frame must be given together", file=sys.stderr)
        return 3
    if args.seek_after_frame >= 0 and args.seek_after_frame not in frames:
        print(f"PROBE_ERROR seek_after_frame {args.seek_after_frame} not in --frames", file=sys.stderr)
        return 3
    prefs = Path(args.prefs_path)
    token_file = Path(args.token_file) if args.token_file else prefs / TOKEN_RELATIVE
    endpoint = args.endpoint or DEFAULT_ENDPOINT

    if not token_file.is_file():
        print(f"PROBE_ERROR token file missing: {token_file}", file=sys.stderr)
        return 4

    flags_expr = "c4d.EXECUTIONFLAGS_PASS_ALL" if args.exec_flags == "all" else "c4d.EXECUTIONFLAGS_0"
    host_json_path = Path(args.out).with_suffix(".host.json")
    host_json_path.parent.mkdir(parents=True, exist_ok=True)
    if host_json_path.exists():
        host_json_path.unlink()
    code = (
        HOST_CODE.replace("__FRAMES__", repr(frames))
        .replace("__ENABLE_RIGID_DISPLAY__", "True" if args.enable_rigid_display else "False")
        .replace("__EXEC_FLAGS__", flags_expr)
        .replace("__SEEK_AFTER__", repr(int(args.seek_after_frame)))
        .replace("__SEEK_TO__", repr(int(args.seek_to_frame)))
        .replace("__OUT_PATH__", repr(str(host_json_path)))
    .replace("__MESH_FRAMES__", repr(sorted(int(x) for x in str(args.mesh_frames).split(",") if x.strip())))
    )

    HostConnection = import_host_module()
    started = time.time()
    try:
        connection = HostConnection(endpoint, str(token_file), int(args.timeout))
        connection.initialize()
    except Exception as error:  # noqa: BLE001 - host may be down, report as data
        print(f"PROBE_ERROR connect failed: {error!r}", file=sys.stderr)
        return 4

    try:
        ack = run_host_code(connection, code, args.timeout)
    except Exception as error:  # noqa: BLE001
        print(f"PROBE_ERROR exec failed: {error!r}", file=sys.stderr)
        return 4

    # 宿主把完整结果写在 host_json_path，stdout 只回一行 ack（避免大 payload 被截断）
    if isinstance(ack, dict) and ack.get("written"):
        try:
            payload = json.loads(Path(ack["written"]).read_text(encoding="utf-8"))
        except Exception as error:  # noqa: BLE001
            print(f"PROBE_ERROR read host payload failed: {error!r}", file=sys.stderr)
            return 4
    elif isinstance(ack, dict) and ack.get("error"):
        print(f"PROBE_ERROR host write failed: {ack.get('detail')}", file=sys.stderr)
        return 4
    else:
        payload = ack

    records = payload.get("records") or []
    if not records:
        print("PROBE_ERROR no records", file=sys.stderr)
        return 4

    rigid_counts = sorted({item["rigid_count"] for item in records})
    if rigid_counts != [args.expect_rigid]:
        print(f"PROBE_ERROR rigid count mismatch: {rigid_counts} != [{args.expect_rigid}]", file=sys.stderr)
        return 3

    # P2-004：名册必须与 --expect-rigid 一致，否则说明选择器抓错对象或场景不对
    roster = payload.get("roster") or []
    roster_count = len(roster)
    if roster_count != args.expect_rigid:
        print(f"PROBE_ERROR rigid roster count mismatch: {roster_count} != {args.expect_rigid}", file=sys.stderr)
        return 3
    roster_ids = [entry.get("rigid_index") for entry in roster]
    missing_bones = [entry for entry in roster if entry.get("bone_index") is not None and entry.get("bone_index") >= 0 and not entry.get("bone_name")]
    if args.strict_roster and missing_bones:
        print(f"PROBE_ERROR roster bones unresolved: {len(missing_bones)} (first: {missing_bones[0].get('path')})", file=sys.stderr)
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
        "schema": "vmd-async-probe-result/2",
        "endpoint": endpoint,
        "token_file": str(token_file),
        "prefs_path": str(prefs),
        "exec_flags": args.exec_flags,
        "enable_rigid_display": bool(args.enable_rigid_display),
        "frames": frames,
        "rigid_count": rigid_counts,
        "distinct_rigid_sha256": distinct_rigid,
        "point_counts": point_counts,
        "roster_count": roster_count,
        "roster_sha256": payload.get("roster_sha256"),
        "bone_map_count": payload.get("bone_map_count"),
        "roster_ids_first_last": [roster_ids[0], roster_ids[-1]] if roster_ids else [],
        "roster_bones_unresolved": len(missing_bones),
        "elapsed_s": round(time.time() - started, 3),
        "host": payload,
        "roster": roster,
    }

    out_path = Path(args.out)
    out_path.parent.mkdir(parents=True, exist_ok=True)
    out_path.write_text(json.dumps(result, ensure_ascii=False, indent=2), encoding="utf-8")
    print("PROBE_RESULT:" + json.dumps({
        "out": str(out_path),
        "frames": frames,
        "rigid_count": rigid_counts,
        "distinct_rigid_sha256": distinct_rigid,
        "roster_count": roster_count,
        "roster_sha256": payload.get("roster_sha256"),
        "roster_bones_unresolved": len(missing_bones),
        "mesh_shas": {item["frame"]: [mesh["local_sha256"] for mesh in item["meshes"]] for item in records},
    }, ensure_ascii=False))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())

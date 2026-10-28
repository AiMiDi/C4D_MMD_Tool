#!/usr/bin/env python3
"""P4 语义判定：lag=1 严格等价（async(N) == sync(N-1)）+ seek 前后窗口。

与 analyze-p3-lag.py 的差别（P4 契约要求）：
- 判据从「找任意常数 lag」改为「必须 lag=1 且 lag_constant」；
- 不等时区分「晚一帧但不全等」与「另走一条轨迹」，并给最早不等帧与偏差量级；
- 支持 seek 场景：按 seek 前后切窗口分别判定，并读取 probe 的 seek_events 作为「重建是否发生」的行为证据。

输入是 probe-rigid.py 写出的 `<probe>.host.json`（含 records[].rigids[].matrix_hex）。

用法：
  python analyze-p4-lag.py --sync-a1 A1.host.json --async-b B.host.json [--sync-a2 A2.host.json] \
      --seek-after-frame 560 --seek-to-frame 600 --out lag-p4.json
"""
from __future__ import annotations

import argparse
import json
import math
import statistics
import struct
import sys
from pathlib import Path

ANCHOR_LOCAL = {
    540: "07757cb6",
    560: "068d56c8",
    619: "15545a9",
}
ANCHOR_WORLD = {
    540: "5361f419",
    560: "e07de0ca",
    619: "fba9fd24",
}
# 修正：619 的局部前缀常量在 t8/t19 记录里是 c15545a9
ANCHOR_LOCAL[619] = "c15545a9"

POSITION_TOLERANCE_MM = 5.0      # lag=1 但未逐位相等时，用偏差量级区分「差一点」与「另一条轨迹」
TRAJECTORY_THRESHOLD_MM = 50.0

# ---- 容差判据（P8b 增补）----
# 背景：异步写回与同步写回的矩阵合成顺序不同，个别轴分量会差恰好 1 ULP（见 tolerance-rationale.md）。
# 逐位相等保留为信息项（lag1_bitwise_equal / lag_constant 字段不变），决定性判据改用下面的容差。
# 单位：矩阵分量原值是 C4D 文档单位（cm）。历史上所有报告里的 *_mm 都直接取分量原值、未做 ×10，
# 本文件的阈值沿用同一标度（"名义 mm"），见 tolerance-rationale.md「单位口径」一节。
TRANSLATION_TOLERANCE_MM = 1e-4
ROTATION_TOLERANCE_RAD = 1e-5
# 动态/运动学分类阈值：运动学刚体由骨骼姿态直接驱动，同帧 async/sync 只差写回末位（实测 ≤3.5e-5）；
# 动态刚体滞后一帧，同帧偏差中位 1~4。阈值落在两者之间 5 个数量级的空隙里。
KINEMATIC_SAME_FRAME_MAX_DEVIATION = 1e-2
# 世界重建边界帧的豁免上限。重建点两侧都回到重建态，LAG1 的参照帧（N-1）属于上一个世界，
# 故该帧改按 lag0 判；若这类帧多于 3 个，说明不是「重建边界」而是系统性发散，判据拒绝豁免。
MAX_RESET_BOUNDARY_FRAMES = 3



def load_probe(path: Path) -> dict:
    data = json.loads(path.read_text(encoding="utf-8"))
    records = data.get("records") or []
    by_frame = {}
    for record in records:
        rigids = {item["path"]: item["matrix_hex"] for item in record.get("rigids") or []}
        by_frame[int(record["frame"])] = {
            "rigid_sha256": record.get("rigid_sha256"),
            "rigids": rigids,
            "meshes": record.get("meshes") or [],
        }
    return {
        "path": str(path),
        "schema": data.get("schema"),
        "fps": data.get("fps"),
        "roster": data.get("roster") or [],
        "roster_count": data.get("roster_count"),
        "roster_sha256": data.get("roster_sha256"),
        "records": by_frame,
        "seek_events": data.get("seek_events") or [],
        "rigid_display": data.get("rigid_display"),
    }


def positions(hex_value: str) -> tuple:
    """matrix_hex 是 12 个 float32：v1/v2/v3 各 3 个，最后 3 个是平移（与 probe-rigid.py 的 matrix_bytes 一致）。"""
    raw = bytes.fromhex(hex_value)
    values = struct.unpack("<12f", raw)
    return values[9], values[10], values[11]


def matrix_components(hex_value: str) -> tuple:
    """matrix_hex → 12 个 float32（v1/v2/v3/off 顺序与 positions 一致）。"""
    return struct.unpack("<12f", bytes.fromhex(hex_value)[:48])


def translation_deviation_mm(left: tuple, right: tuple) -> float:
    """两个 12 分量矩阵的平移差（欧氏距离，沿用既有 *_mm 标度）。"""
    return ((left[9] - right[9]) ** 2 + (left[10] - right[10]) ** 2 + (left[11] - right[11]) ** 2) ** 0.5


def _unit_axes(values: tuple) -> list:
    axes = []
    for base in (0, 3, 6):
        x, y, z = values[base], values[base + 1], values[base + 2]
        norm = math.sqrt(x * x + y * y + z * z)
        axes.append((x / norm, y / norm, z / norm) if norm > 0.0 else (1.0, 0.0, 0.0))
    return axes


def rotation_deviation_rad(left: tuple, right: tuple) -> float:
    """两个 3x3 基的夹角（基先归一化，避免缩放参与）：acos((tr(AᵀB)-1)/2)。"""
    a = _unit_axes(left)
    b = _unit_axes(right)
    trace = sum(a[i][k] * b[i][k] for i in range(3) for k in range(3))
    return math.acos(max(-1.0, min(1.0, (trace - 1.0) / 2.0)))


def _frame_deviation(async_rigids: dict, sync_dynamic: dict, sync_kinematic: dict,
                     dynamic: set, kinematic: set, thresholds: tuple) -> dict:
    """单帧偏差：动态刚体对 sync_dynamic（lag 侧帧），运动学刚体对 sync_kinematic（同帧）。"""
    trans_tol, rot_tol = thresholds
    max_trans = 0.0
    max_rot = 0.0
    max_trans_dynamic = 0.0
    max_rot_dynamic = 0.0
    max_trans_kinematic = 0.0
    max_rot_kinematic = 0.0
    compared = 0
    over = []
    for path, kind, source in ([(p, "dynamic", sync_dynamic) for p in dynamic]
                               + [(p, "kinematic", sync_kinematic) for p in kinematic]):
        left = async_rigids.get(path)
        right = source.get(path)
        if left is None or right is None:
            continue
        compared += 1
        a = matrix_components(left)
        b = matrix_components(right)
        trans = translation_deviation_mm(a, b)
        rot = rotation_deviation_rad(a, b)
        max_trans = max(max_trans, trans)
        max_rot = max(max_rot, rot)
        if kind == "dynamic":
            max_trans_dynamic = max(max_trans_dynamic, trans)
            max_rot_dynamic = max(max_rot_dynamic, rot)
        else:
            max_trans_kinematic = max(max_trans_kinematic, trans)
            max_rot_kinematic = max(max_rot_kinematic, rot)
        if trans > trans_tol or rot > rot_tol:
            over.append({"path": path, "kind": kind, "translation_mm": round(trans, 9), "rotation_rad": round(rot, 12)})
    return {
        "compared": compared,
        "max_translation_mm": max_trans,
        "max_rotation_rad": max_rot,
        "max_translation_mm_dynamic": max_trans_dynamic,
        "max_rotation_rad_dynamic": max_rot_dynamic,
        "max_translation_mm_kinematic": max_trans_kinematic,
        "max_rotation_rad_kinematic": max_rot_kinematic,
        "over": over,
    }


def derive_rigid_classes(async_records: dict, sync_records: dict) -> tuple:
    """动态/运动学分类。

    主口径（与 analyze-p6-lag.py 一致）：异步段前两帧之间**没动**的刚体是动态刚体——重建后
    第一帧动态刚体还没有结果，只有被骨骼直接驱动的运动学刚体会跟到新姿态。
    交叉校验口径：同帧 async vs sync 的中位平移偏差（运动学只差写回末位，动态滞后一帧）。
    两口径都给出集合；不一致时以主口径为准，并把不一致写进输出（不静默）。
    """
    frames = sorted(async_records)
    if not frames:
        return set(), set(), {}
    all_paths = sorted(async_records[frames[0]]["rigids"])
    motion_kinematic = set()
    if len(frames) >= 2:
        first = async_records[frames[0]]["rigids"]
        second = async_records[frames[1]]["rigids"]
        motion_kinematic = {path for path in first if path in second and first[path] != second[path]}
    deviation_kinematic = set()
    for path in all_paths:
        deviations = []
        for frame in frames:
            left = async_records[frame]["rigids"].get(path)
            right = sync_records.get(frame, {}).get("rigids", {}).get(path)
            if left is None or right is None:
                continue
            deviations.append(translation_deviation_mm(matrix_components(left), matrix_components(right)))
        if deviations and statistics.median(deviations) <= KINEMATIC_SAME_FRAME_MAX_DEVIATION:
            deviation_kinematic.add(path)
    kinematic = motion_kinematic or deviation_kinematic
    dynamic = set(all_paths) - kinematic
    details = {
        "dynamic": len(dynamic),
        "kinematic": len(kinematic),
        "motion_derived_kinematic": len(motion_kinematic),
        "deviation_derived_kinematic": len(deviation_kinematic),
        "consistent": motion_kinematic == deviation_kinematic,
        "kinematic_threshold_mm": KINEMATIC_SAME_FRAME_MAX_DEVIATION,
        "derivation": "async 前两帧之间未移动 = 动态；同帧 async-vs-sync 中位平移偏差 <= 阈值 亦判运动学",
    }
    return dynamic, kinematic, details


def tolerance_analysis(async_records: dict, sync_records: dict, frames: list,
                       dynamic: set, kinematic: set, thresholds: tuple) -> dict:
    """容差判据：动态刚体 async(f) vs sync(f-1)、运动学刚体 async(f) vs sync(f)，逐帧汇总。"""
    per_frame = []
    over_entries = []
    distinct_over = set()
    max_trans = max_rot = 0.0
    max_trans_dynamic = max_rot_dynamic = 0.0
    max_trans_kinematic = max_rot_kinematic = 0.0
    for frame in sorted(frames):
        if frame not in async_records or (frame - 1) not in sync_records:
            continue
        result = _frame_deviation(
            async_records[frame]["rigids"],
            sync_records[frame - 1]["rigids"],
            sync_records[frame]["rigids"] if frame in sync_records else {},
            dynamic, kinematic, thresholds)
        max_trans = max(max_trans, result["max_translation_mm"])
        max_rot = max(max_rot, result["max_rotation_rad"])
        max_trans_dynamic = max(max_trans_dynamic, result["max_translation_mm_dynamic"])
        max_rot_dynamic = max(max_rot_dynamic, result["max_rotation_rad_dynamic"])
        max_trans_kinematic = max(max_trans_kinematic, result["max_translation_mm_kinematic"])
        max_rot_kinematic = max(max_rot_kinematic, result["max_rotation_rad_kinematic"])
        for item in result["over"]:
            distinct_over.add((item["kind"], item["path"]))
            over_entries.append(dict(item, frame=frame, sync_frame=frame - 1))
        per_frame.append({
            "frame": frame,
            "sync_frame": frame - 1,
            "compared": result["compared"],
            "bodies_over_tolerance": len(result["over"]),
            "max_translation_mm": round(result["max_translation_mm"], 9),
            "max_rotation_rad": round(result["max_rotation_rad"], 12),
        })
    frames_over = [item["frame"] for item in per_frame if item["bodies_over_tolerance"] > 0]
    worst = max(over_entries, key=lambda item: item["translation_mm"]) if over_entries else None
    return {
        "frames_compared": len(per_frame),
        "frames_within_tolerance": len(per_frame) - len(frames_over),
        "all_within": bool(per_frame) and not frames_over,
        "max_translation_dev_mm": round(max_trans, 9),
        "max_rotation_dev_rad": round(max_rot, 12),
        "max_translation_dev_mm_dynamic": round(max_trans_dynamic, 9),
        "max_rotation_dev_rad_dynamic": round(max_rot_dynamic, 12),
        "max_translation_dev_mm_kinematic": round(max_trans_kinematic, 9),
        "max_rotation_dev_rad_kinematic": round(max_rot_kinematic, 12),
        "bodies_over_tolerance": len(distinct_over),
        "bodies_over_tolerance_pairs": len(over_entries),
        "frames_over_tolerance": frames_over,
        "worst": worst,
        "over_tolerance": over_entries[:20],
        "per_frame": per_frame,
    }


def bitwise_split(async_records: dict, sync_records: dict, frames: list,
                  dynamic: set, kinematic: set) -> dict:
    """逐位判据的「谁在差」信息项：动态按 lag=1、运动学按同帧分别统计。"""
    dynamic_diffs = {}
    kinematic_diffs = {}
    for frame in sorted(frames):
        if frame not in async_records:
            continue
        async_rigids = async_records[frame]["rigids"]
        if (frame - 1) in sync_records:
            previous = sync_records[frame - 1]["rigids"]
            for path in dynamic:
                left = async_rigids.get(path)
                right = previous.get(path)
                if left is not None and right is not None and left != right:
                    dynamic_diffs.setdefault(path, []).append(frame)
        current = sync_records[frame]["rigids"] if frame in sync_records else {}
        for path in kinematic:
            left = async_rigids.get(path)
            right = current.get(path)
            if left is not None and right is not None and left != right:
                kinematic_diffs.setdefault(path, []).append(frame)
    return {
        "dynamic_bodies_differing": len(dynamic_diffs),
        "kinematic_bodies_differing": len(kinematic_diffs),
        "dynamic_frames": sorted({frame for hits in dynamic_diffs.values() for frame in hits}),
        "dynamic_examples": [{"path": path, "frames": sorted(hits)} for path, hits in sorted(dynamic_diffs.items())[:20]],
        "kinematic_examples": [{"path": path, "frames": sorted(hits)} for path, hits in sorted(kinematic_diffs.items())[:5]],
    }


def reset_boundaries(async_records: dict, sync_records: dict, frames: list,
                     dynamic: set, kinematic: set, thresholds: tuple) -> dict:
    """识别世界重建边界帧：同帧（lag0）在容差内、但与上一帧（lag1）不在容差内。

    重建点两侧都会回到重建态，LAG1 的参照帧（N-1）属于上一个世界，故该帧改按 lag0 判。
    这类帧必须显式列出并受 MAX_RESET_BOUNDARY_FRAMES 限制——系统性发散时 lag0 也会超出容差，
    因此不会被误判成边界。
    """
    boundary_frames = []
    details = []
    for frame in sorted(frames):
        if frame not in sync_records:
            continue
        sync_rigids = sync_records[frame]["rigids"]
        lag0 = _frame_deviation(async_records[frame]["rigids"], sync_rigids, sync_rigids, dynamic, kinematic, thresholds)
        lag1 = _frame_deviation(async_records[frame]["rigids"], sync_records[frame - 1]["rigids"], sync_rigids, dynamic, kinematic, thresholds)
        if not lag0["over"] and lag1["over"]:
            boundary_frames.append(frame)
            details.append({
                "frame": frame,
                "lag0_within_tolerance": True,
                "lag1_max_translation_mm": round(lag1["max_translation_mm"], 9),
                "lag1_max_rotation_rad": round(lag1["max_rotation_rad"], 12),
                "lag1_bodies_over_tolerance": len(lag1["over"]),
            })
    return {
        "frames": boundary_frames,
        "details": details,
        "count": len(boundary_frames),
        "limit": MAX_RESET_BOUNDARY_FRAMES,
        "within_limit": len(boundary_frames) <= MAX_RESET_BOUNDARY_FRAMES,
        "rule": "同帧(lag0)在容差内且 lag1 不在容差内 = 世界重建边界帧，改按 lag0 判；超过 limit 即拒绝豁免",
    }



def compare_frames(a: dict, b: dict) -> dict:
    """逐刚体比较两帧的 matrix_hex。"""
    paths = sorted(set(a["rigids"]) | set(b["rigids"]))
    equal = 0
    mismatched = []
    max_dev = 0.0
    deviations = []
    for path in paths:
        left = a["rigids"].get(path)
        right = b["rigids"].get(path)
        if left is not None and left == right:
            equal += 1
            deviations.append(0.0)
            continue
        mismatched.append(path)
        if left is None or right is None:
            continue
        ax, ay, az = positions(left)
        bx, by, bz = positions(right)
        dev = ((ax - bx) ** 2 + (ay - by) ** 2 + (az - bz) ** 2) ** 0.5
        deviations.append(dev)
        max_dev = max(max_dev, dev)
    return {
        "total": len(paths),
        "equal": equal,
        "mismatched": len(mismatched),
        "mismatched_paths": mismatched[:10],
        "max_deviation_mm": round(max_dev, 4),
        "median_deviation_mm": round(statistics.median(deviations), 4) if deviations else 0.0,
    }


def displacement(records: dict) -> dict:
    """每个刚体在记录帧序列上的最大位移（mm）；frozen = 全程 0。"""
    frames = sorted(records)
    if len(frames) < 2:
        return {"frames": len(frames), "rigids_moved": 0, "rigids_frozen": 0, "all_rigids_moved": False}
    positions_by_rigid: dict = {}
    for frame in frames:
        for path, hex_value in records[frame]["rigids"].items():
            positions_by_rigid.setdefault(path, []).append((frame, positions(hex_value)))
    moved = 0
    frozen = 0
    max_disp = 0.0
    for path, series in positions_by_rigid.items():
        base = series[0][1]
        peak = 0.0
        for _, current in series[1:]:
            dev = ((current[0] - base[0]) ** 2 + (current[1] - base[1]) ** 2 + (current[2] - base[2]) ** 2) ** 0.5
            peak = max(peak, dev)
        max_disp = max(max_disp, peak)
        if peak > 1e-9:
            moved += 1
        else:
            frozen += 1
    return {
        "frames": len(frames),
        "rigids_moved": moved,
        "rigids_frozen": frozen,
        "all_rigids_moved": frozen == 0,
        "max_displacement_mm": round(max_disp, 4),
    }


def lag_table(async_records: dict, sync_records: dict, max_lag: int = 3) -> dict:
    """参考表：每帧在 lag 0..max_lag 上能否整帧逐位相等（P4 只认 lag=1，其余仅作诊断）。"""
    frames = sorted(async_records)
    histogram = {}
    per_frame = {}
    for frame in frames:
        matches = []
        for lag in range(0, max_lag + 1):
            sync_frame = frame - lag
            if sync_frame not in sync_records:
                continue
            result = compare_frames(async_records[frame], sync_records[sync_frame])
            if result["equal"] == result["total"] and result["total"] > 0:
                matches.append(lag)
        per_frame[frame] = matches
        if matches:
            for lag in matches:
                histogram[str(lag)] = histogram.get(str(lag), 0) + 1
        else:
            histogram["none"] = histogram.get("none", 0) + 1
    return {"frames": len(frames), "histogram": histogram, "per_frame": per_frame}


def lag1_analysis(async_records: dict, sync_records: dict, window_frames: list) -> dict:
    """严格 lag=1：逐帧 async(f) vs sync(f-1)。"""
    compared = 0
    equal = 0
    earliest = None
    details = []
    worst = {"frame": None, "max_deviation_mm": 0.0}
    for frame in sorted(window_frames):
        if frame not in async_records or (frame - 1) not in sync_records:
            continue
        result = compare_frames(async_records[frame], sync_records[frame - 1])
        compared += 1
        if result["equal"] == result["total"] and result["total"] > 0:
            equal += 1
        elif earliest is None:
            earliest = frame
        if result["max_deviation_mm"] > worst["max_deviation_mm"]:
            worst = {"frame": frame, "max_deviation_mm": result["max_deviation_mm"]}
        details.append({
            "frame": frame,
            "sync_frame": frame - 1,
            "equal": result["equal"],
            "total": result["total"],
            "mismatched": result["mismatched"],
            "max_deviation_mm": result["max_deviation_mm"],
            "median_deviation_mm": result["median_deviation_mm"],
        })
    return {
        "frames_compared": compared,
        "equal_frames": equal,
        "all_equal": compared > 0 and equal == compared,
        "earliest_mismatch_frame": earliest,
        "worst": worst,
        "per_frame": details,
    }


def classify(lag1: dict, per_frame: list) -> str:
    if lag1["all_equal"]:
        return "lag1_bitwise_equal"
    if not per_frame:
        return "no_data"
    medians = [item["median_deviation_mm"] for item in per_frame]
    med = statistics.median(medians) if medians else 0.0
    if med <= POSITION_TOLERANCE_MM:
        return "lag1_close_but_not_equal"
    if med >= TRAJECTORY_THRESHOLD_MM:
        return "different_trajectory"
    return "lag1_partial"


def roster_summary(probes: dict) -> dict:
    """名册摘要：数量、相对索引连续性、重复、未解析骨骼，以及跨段一致性。"""
    summary = {}
    for name, probe in probes.items():
        roster = probe["roster"]
        indices = [int(item.get("rigid_index", -1)) for item in roster]
        duplicates = len(indices) - len(set(indices))
        unresolved = sum(1 for item in roster if int(item.get("bone_index") or -1) >= 0 and not item.get("bone_name"))
        contiguous = indices == list(range(len(indices)))
        summary[name] = {
            "count": len(roster),
            "sha256": probe["roster_sha256"],
            "indices_contiguous": contiguous,
            "duplicates": duplicates,
            "unresolved_bones": unresolved,
        }
    shas = {value["sha256"] for value in summary.values() if value["sha256"]}
    summary["same_roster"] = len(shas) <= 1
    return summary


def anchor_summary(probe: dict) -> dict:
    """网格锚点（局部/世界 sha 前缀）；网格对物理不敏感，这里只作旁证。"""
    out = {}
    for frame, local_prefix in ANCHOR_LOCAL.items():
        record = probe["records"].get(frame)
        if not record or not record["meshes"]:
            out[str(frame)] = {"present": False}
            continue
        mesh = record["meshes"][0]
        out[str(frame)] = {
            "present": True,
            "local_prefix": mesh["local_sha256"][:8],
            "world_prefix": mesh["world_sha256"][:8],
            "local_matches": mesh["local_sha256"].startswith(local_prefix),
            "world_matches": mesh["world_sha256"].startswith(ANCHOR_WORLD[frame]),
        }
    return out


def seek_summary(async_probe: dict, sync_probe: dict, seek_after: int, seek_to: int) -> dict:
    """seek 证据：probe 记录的跳变指纹 + seek 前后窗口各自的 lag=1 结果。"""
    frames = sorted(async_probe["records"])
    pre = [frame for frame in frames if frame <= seek_after]
    post = [frame for frame in frames if frame > seek_after]
    return {
        "seek_after_frame": seek_after,
        "seek_to_frame": seek_to,
        "events": async_probe["seek_events"],
        "pre_window": {
            "frames": len(pre),
            "lag1": lag1_analysis(async_probe["records"], sync_probe["records"], pre),
        },
        "post_window": {
            "frames": len(post),
            "lag1": lag1_analysis(async_probe["records"], sync_probe["records"], post),
        },
        "post_first_frame": post[0] if post else None,
    }


def main(argv=None) -> int:
    parser = argparse.ArgumentParser(description="P4 lag=1 strict equivalence analysis")
    parser.add_argument("--sync-a1", required=True)
    parser.add_argument("--async-b", required=True)
    parser.add_argument("--sync-a2", default=None)
    parser.add_argument("--seek-after-frame", type=int, default=-1)
    parser.add_argument("--seek-to-frame", type=int, default=-1)
    parser.add_argument("--out", default=None)
    args = parser.parse_args(argv)

    probes = {"A1-sync": load_probe(Path(args.sync_a1)), "B-async": load_probe(Path(args.async_b))}
    if args.sync_a2:
        probes["A2-sync"] = load_probe(Path(args.sync_a2))

    sync = probes["A1-sync"]
    async_probe = probes["B-async"]

    async_disp = displacement(async_probe["records"])
    sync_disp = displacement(sync["records"])
    lag1 = lag1_analysis(async_probe["records"], sync["records"], list(async_probe["records"]))
    table = lag_table(async_probe["records"], sync["records"])
    verdict = classify(lag1, lag1["per_frame"])

    result = {
        "schema": "vmd-p4-lag/1",
        "inputs": {name: probe["path"] for name, probe in probes.items()},
        "frames": {
            "async": len(async_probe["records"]),
            "sync": len(sync["records"]),
        },
        "roster": roster_summary(probes),
        "displacement": {"A1-sync": sync_disp, "B-async": async_disp},
        "lag1": {key: value for key, value in lag1.items() if key != "per_frame"},
        "lag1_per_frame": lag1["per_frame"],
        "lag_reference_table": table,
        "verdict": verdict,
        "lag_constant": verdict == "lag1_bitwise_equal",
        "anchors": anchor_summary(sync),
        "anchors_async": anchor_summary(async_probe),
        "sync_a1_vs_a2": None,
    }
    if "A2-sync" in probes:
        a2 = probes["A2-sync"]
        common = sorted(set(sync["records"]) & set(a2["records"]))
        identical = 0
        for frame in common:
            item = compare_frames(sync["records"][frame], a2["records"][frame])
            if item["equal"] == item["total"] and item["total"] > 0:
                identical += 1
        result["sync_a1_vs_a2"] = {"frames": len(common), "identical": identical, "all_identical": identical == len(common) and bool(common)}

    if args.seek_after_frame >= 0 and args.seek_to_frame >= 0:
        result["seek"] = seek_summary(async_probe, sync, args.seek_after_frame, args.seek_to_frame)

    if args.out:
        Path(args.out).parent.mkdir(parents=True, exist_ok=True)
        Path(args.out).write_text(json.dumps(result, ensure_ascii=False, indent=2), encoding="utf-8")

    print("LAG1_ANALYSIS " + json.dumps({
        "frames_compared": lag1["frames_compared"],
        "equal_frames": lag1["equal_frames"],
        "all_equal": lag1["all_equal"],
        "verdict": verdict,
        "earliest_mismatch_frame": lag1["earliest_mismatch_frame"],
        "worst": lag1["worst"],
    }, ensure_ascii=False))
    print("LAG_REFERENCE " + json.dumps({"histogram": table["histogram"], "frames": table["frames"]}, ensure_ascii=False))
    print("DISPLACEMENT " + json.dumps({"a1": sync_disp, "b": async_disp}, ensure_ascii=False))
    print("ROSTER " + json.dumps(result["roster"], ensure_ascii=False))
    if "seek" in result:
        seek = result["seek"]
        print("SEEK " + json.dumps({
            "after_frame": seek["seek_after_frame"],
            "to_frame": seek["seek_to_frame"],
            "events": len(seek["events"]),
            "pre_equal": f"{seek['pre_window']['lag1']['equal_frames']}/{seek['pre_window']['lag1']['frames_compared']}",
            "post_equal": f"{seek['post_window']['lag1']['equal_frames']}/{seek['post_window']['lag1']['frames_compared']}",
            "post_all_equal": seek["post_window"]["lag1"]["all_equal"],
            "post_earliest_mismatch": seek["post_window"]["lag1"]["earliest_mismatch_frame"],
        }, ensure_ascii=False))
    return 0


if __name__ == "__main__":
    sys.exit(main())

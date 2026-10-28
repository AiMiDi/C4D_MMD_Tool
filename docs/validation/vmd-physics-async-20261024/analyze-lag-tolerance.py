#!/usr/bin/env python3
"""按「刚体类型分档 lag」比较同步段与异步段的刚体轨迹。

为什么必须分档：异步物理让**参与求解**的刚体滞后一帧（async(N) == sync(N-1)），
而**骨骼跟随**刚体（PMX 类型 0）不参与求解、由当帧骨骼直接驱动，没有滞后
（async(N) == sync(N)）。旧判据把 479 个刚体一律按 lag=1 比较，等于拿两帧不同的
骨骼姿态相减，27 个跟随骨骼的刚体会差几毫米到几十毫米，把「语义正确」误判成发散。

判据：
  - 平移偏差 ≤ --translation-mm（默认 1e-4 mm）
  - 旋转偏差 ≤ --rotation-rad（默认 1e-5 rad）
逐位相等（matrix_hex）另作信息项报告，不作为通过条件。

用法：
  python analyze-lag-tolerance.py --sync-a1 <probe.host.json> --async-b <probe.host.json> \
      --out <json> [--sync-a2 ...] [--seek-after-frame 560] [--seek-to-frame 600]
"""

from __future__ import annotations

import argparse
import json
import math
from pathlib import Path

AXIS_SLICES = ((0, 3), (3, 6), (6, 9))
OFFSET_SLICE = (9, 12)

# PMX 刚体类型：0 = 骨骼跟随（不参与求解），1 = 物理演算，2 = 物理演算 + 骨骼位置对齐。
KINEMATIC_MODE = 0


class Probe:
    def __init__(self, path: Path):
        payload = json.loads(path.read_text(encoding="utf-8"))
        self.payload = payload
        modes = payload.get("rigid_modes") or {}
        index_of = {}
        for entry in payload.get("roster", []):
            if "path" in entry and "rigid_index" in entry:
                index_of[entry["path"]] = str(entry["rigid_index"])
        self.lag_of = {}
        for record in payload.get("records", []):
            for rigid in record.get("rigids", []):
                path_key = rigid.get("path")
                rigid_index = index_of.get(path_key)
                mode = modes.get(rigid_index) if rigid_index is not None else None
                self.lag_of[path_key] = 0 if mode == KINEMATIC_MODE else 1
        self.records = {}
        for record in payload.get("records", []):
            rigids = sorted(record.get("rigids", []), key=lambda item: item.get("path", ""))
            self.records[int(record["frame"])] = rigids

    def lag(self, path_key: str) -> int:
        return self.lag_of.get(path_key, 1)

    def missing_modes(self) -> int:
        return sum(1 for value in self.lag_of.values() if value is None)

    def kinematic_count(self) -> int:
        return sum(1 for value in self.lag_of.values() if value == 0)


def axis_angle_rad(a: list[float], b: list[float]) -> float:
    dot = sum(x * y for x, y in zip(a, b))
    na = math.sqrt(sum(x * x for x in a)) or 1.0
    nb = math.sqrt(sum(y * y for y in b)) or 1.0
    return math.acos(max(-1.0, min(1.0, dot / (na * nb))))


def compare_body(a: dict, b: dict) -> tuple[float, float, bool]:
    ma, mb = a.get("matrix") or [], b.get("matrix") or []
    if len(ma) < 12 or len(mb) < 12:
        return float("inf"), float("inf"), a.get("matrix_hex") == b.get("matrix_hex")
    translation = math.sqrt(sum((ma[i] - mb[i]) ** 2 for i in range(*OFFSET_SLICE)))
    rotation = max(axis_angle_rad(ma[start:end], mb[start:end]) for start, end in AXIS_SLICES)
    return translation, rotation, a.get("matrix_hex") == b.get("matrix_hex")


def compare_frames(
    sync: Probe,
    async_: Probe,
    frames: list[int],
    translation_tol: float,
    rotation_tol: float,
    skip_frames: set[int] | None = None,
) -> dict:
    """按每个刚体自己的 lag 比较；lag=0 的刚体比同帧，lag=1 的比前一帧。

    skip_frames 里的帧不参与判定（seek 后重建的瞬态帧），由 rebuild_transient 单独报告。
    """
    skip_frames = skip_frames or set()
    frames_compared = 0
    frames_within = 0
    bitwise_frames = 0
    bodies_over = 0
    bodies_dynamic = 0
    bodies_kinematic = 0
    max_t = 0.0
    max_r = 0.0
    worst = {"frame": None, "body": None, "translation_mm": 0.0, "rotation_rad": 0.0}
    per_class = {
        "dynamic": {"compared": 0, "over": 0, "max_translation_mm": 0.0, "max_rotation_rad": 0.0},
        "kinematic": {"compared": 0, "over": 0, "max_translation_mm": 0.0, "max_rotation_rad": 0.0},
    }
    for frame in frames:
        if frame in skip_frames:
            continue
        if frame not in async_.records:
            continue
        by_path = {rigid.get("path"): rigid for rigid in async_.records[frame]}
        frame_ok = True
        frame_bitwise = True
        counted = 0
        for path_key, current in by_path.items():
            lag = async_.lag(path_key)
            base_frame = frame - lag
            if base_frame not in sync.records:
                continue
            reference = next(
                (item for item in sync.records[base_frame] if item.get("path") == path_key), None
            )
            if reference is None:
                continue
            counted += 1
            translation, rotation, same = compare_body(reference, current)
            bucket = "dynamic" if lag == 1 else "kinematic"
            stats = per_class[bucket]
            stats["compared"] += 1
            stats["max_translation_mm"] = max(stats["max_translation_mm"], round(translation, 9))
            stats["max_rotation_rad"] = max(stats["max_rotation_rad"], round(rotation, 12))
            if bucket == "dynamic":
                bodies_dynamic += 1
            else:
                bodies_kinematic += 1
            if not same:
                frame_bitwise = False
            if translation > translation_tol or rotation > rotation_tol:
                frame_ok = False
                stats["over"] += 1
                bodies_over += 1
                if translation > max_t or rotation > max_r:
                    worst = {
                        "frame": frame,
                        "body": current.get("name"),
                        "translation_mm": round(translation, 6),
                        "rotation_rad": round(rotation, 9),
                    }
                    max_t = max(max_t, translation)
                    max_r = max(max_r, rotation)
        if counted == 0:
            continue
        frames_compared += 1
        if frame_ok:
            frames_within += 1
        if frame_bitwise:
            bitwise_frames += 1
    return {
        "frames_compared": frames_compared,
        "frames_within_tolerance": frames_within,
        "all_within": frames_compared > 0 and frames_within == frames_compared,
        "bodies_over_tolerance": bodies_over,
        "max_translation_dev_mm": round(max_t, 9),
        "max_rotation_dev_rad": round(max_r, 12),
        "worst": worst,
        "bitwise_equal_frames": bitwise_frames,
        "per_class": {
            name: {
                "compared": stats["compared"],
                "over_tolerance": stats["over"],
                "max_translation_mm": round(stats["max_translation_mm"], 9),
                "max_rotation_rad": round(stats["max_rotation_rad"], 12),
            }
            for name, stats in per_class.items()
        },
        "bodies_dynamic": bodies_dynamic,
        "bodies_kinematic": bodies_kinematic,
    }


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--sync-a1", required=True)
    parser.add_argument("--async-b", required=True)
    parser.add_argument("--sync-a2", default=None)
    parser.add_argument("--out", required=True)
    parser.add_argument("--seek-after-frame", type=int, default=-1)
    parser.add_argument("--seek-to-frame", type=int, default=-1)
    parser.add_argument(
        "--seek-settle-frames",
        type=int,
        default=1,
        help="seek 之后重建的瞬态帧数：这些帧不参与判定，单独记进 rebuild_transient。",
    )
    parser.add_argument("--translation-mm", type=float, default=1e-4)
    parser.add_argument("--rotation-rad", type=float, default=1e-5)
    args = parser.parse_args()

    sync_a1 = Probe(Path(args.sync_a1))
    async_b = Probe(Path(args.async_b))

    all_frames = sorted(f for f in async_b.records if f >= 0)
    pre_frames = [f for f in all_frames if args.seek_after_frame < 0 or f <= args.seek_after_frame]
    post_frames = [f for f in all_frames if args.seek_after_frame >= 0 and f > args.seek_after_frame]
    # seek 回来后第一次推进必然是「重建世界」的第一步，Bullet 状态路径相关、不可能与热连续轨逐位相同；
    # 只跳过这一段（默认 1 帧），并把它的偏差单独打出来，绝不静默隐藏。
    transient_frames = (
        set(range(args.seek_after_frame + 1, args.seek_after_frame + 1 + max(0, args.seek_settle_frames)))
        if args.seek_after_frame >= 0 and args.seek_settle_frames > 0
        else set()
    )

    result = {
        "tolerance": {"translation_mm": args.translation_mm, "rotation_rad": args.rotation_rad},
        "lag_model": {
            "dynamic": 1,
            "kinematic": 0,
            "bodies_dynamic": len(async_b.lag_of) - async_b.kinematic_count(),
            "bodies_kinematic": async_b.kinematic_count(),
        },
        "rebuild_transient": {
            "frames": sorted(transient_frames),
            **compare_frames(
                sync_a1, async_b, sorted(transient_frames), args.translation_mm, args.rotation_rad
            ),
        }
        if transient_frames
        else None,
        "lag1": compare_frames(
            sync_a1, async_b, all_frames, args.translation_mm, args.rotation_rad, transient_frames
        ),
        "seek_pre": compare_frames(sync_a1, async_b, pre_frames, args.translation_mm, args.rotation_rad)
        if args.seek_after_frame >= 0
        else None,
        "seek_post": compare_frames(
            sync_a1, async_b, post_frames, args.translation_mm, args.rotation_rad, transient_frames
        )
        if args.seek_after_frame >= 0
        else None,
    }
    if args.sync_a2:
        sync_a2 = Probe(Path(args.sync_a2))
        result["a1_vs_a2"] = compare_frames(sync_a2, sync_a1, sorted(sync_a1.records), args.translation_mm, args.rotation_rad)

    Path(args.out).write_text(json.dumps(result, ensure_ascii=False, indent=2), encoding="utf-8")
    summary = {
        "lag1_within": f"{result['lag1']['frames_within_tolerance']}/{result['lag1']['frames_compared']}",
        "max_translation_dev_mm": result["lag1"]["max_translation_dev_mm"],
        "max_rotation_dev_rad": result["lag1"]["max_rotation_dev_rad"],
        "bodies_over": result["lag1"]["bodies_over_tolerance"],
        "bitwise_equal_frames": result["lag1"]["bitwise_equal_frames"],
        "dynamic": result["lag1"]["per_class"]["dynamic"],
        "kinematic": result["lag1"]["per_class"]["kinematic"],
        "seek_post_within": (
            f"{result['seek_post']['frames_within_tolerance']}/{result['seek_post']['frames_compared']}"
            if result["seek_post"]
            else None
        ),
    }
    print("TOLERANCE_ANALYSIS " + json.dumps(summary, ensure_ascii=False))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())

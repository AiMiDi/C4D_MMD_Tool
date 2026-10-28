#!/usr/bin/env python3
"""P3 异步物理：宿主实测 lag 分布与逐位对齐分析。

输入：probe-rigid.py 产出的 `<out>.host.json`（A1-sync / B-async / A2-sync 各一份）。
判据：刚体世界矩阵逐位比对（matrix_hex），**不用网格 sha 当等价证明**（t34 已证该场景网格对物理不敏感）。
输出：JSON 摘要 + 人类可读摘要行。

用法：
  python analyze-p3-lag.py --sync-a1 <host.json> --async-b <host.json> [--sync-a2 <host.json>]
                           --frames 500-620 --max-lag 4 --out out.json
"""
import argparse
import json
from collections import Counter
from pathlib import Path

SCHEMA = "vmd-p3-lag-analysis/1"
ANCHORS = (540, 560, 619)
ANCHOR_LOCAL = {540: "07757cb6", 560: "068d56c8", 619: "c15545a9"}
ANCHOR_WORLD = {540: "5361f419", 560: "e07de0ca", 619: "fba9fd24"}


def load_probe(path):
    data = json.loads(Path(path).read_text(encoding="utf-8"))
    records = {}
    for rec in data.get("records") or []:
        frame = int(rec["frame"])
        rigids = rec.get("rigids") or []
        meshes = rec.get("meshes") or rec.get("mesh") or []
        records[frame] = {
            "matrix_hex": [r.get("matrix_hex") for r in rigids],
            "positions": [(r.get("matrix") or [0.0] * 12)[9:12] for r in rigids],
            "paths": [r.get("path") for r in rigids],
            "mesh": {m.get("object"): m for m in meshes},
            "rigid_sha256": rec.get("rigid_sha256"),
        }
    roster = data.get("roster") or []
    return {
        "records": records,
        "roster": roster,
        "roster_sha256": data.get("roster_sha256"),
        "roster_count": data.get("roster_count"),
        "bone_map_count": data.get("bone_map_count"),
        "rigid_display": data.get("rigid_display"),
        "frames": sorted(records),
    }


def frames_equal(a, b):
    """逐字节比较两个快照的全部刚体世界矩阵。"""
    ma, mb = a["matrix_hex"], b["matrix_hex"]
    if len(ma) != len(mb) or not ma:
        return False, len(ma)
    diff = sum(1 for x, y in zip(ma, mb) if x != y)
    return diff == 0, diff


def max_position_deviation(a, b):
    """两个快照里逐刚体世界位置的最大欧氏距离（mm）。"""
    pa, pb = a.get("positions") or [], b.get("positions") or []
    if not pa or not pb or len(pa) != len(pb):
        return float("inf")
    worst = 0.0
    for x, y in zip(pa, pb):
        d = ((x[0] - y[0]) ** 2 + (x[1] - y[1]) ** 2 + (x[2] - y[2]) ** 2) ** 0.5
        if d > worst:
            worst = d
    return worst


def displacement_summary(probe, frames):
    """统计「有多少刚体在世界里真的动过」。

    t49 的现场指纹是 452/479 恒为 0（写回被整帧拒绝），只有 27 个 kinematic 随骨骼动。
    这里用「首帧 vs 每一帧」的累计位移判断每个刚体是否动过，作为「写回是否生效」的独立判据。
    """
    if not frames:
        return {}
    base = probe["records"][frames[0]]["positions"]
    moved = [0] * len(base)
    max_move = [0.0] * len(base)
    for frame in frames:
        pos = probe["records"][frame]["positions"]
        if len(pos) != len(base):
            continue
        for j, (x, y) in enumerate(zip(base, pos)):
            d = ((x[0] - y[0]) ** 2 + (x[1] - y[1]) ** 2 + (x[2] - y[2]) ** 2) ** 0.5
            if d > 1e-9:
                moved[j] += 1
            if d > max_move[j]:
                max_move[j] = d
    frozen = [j for j, n in enumerate(moved) if n == 0]
    max_sorted = sorted(max_move)
    return {
        "rigid_count": len(base),
        "frames": len(frames),
        "rigids_moved": len(base) - len(frozen),
        "rigids_frozen": len(frozen),
        "frozen_ratio": round(len(frozen) / len(base), 4) if base else None,
        "all_rigids_moved": len(frozen) == 0,
        "max_displacement_mm": round(max_sorted[-1], 3) if max_sorted else None,
        "median_max_displacement_mm": round(max_sorted[len(max_sorted) // 2], 3) if max_sorted else None,
        "frozen_first_indices": frozen[:20],
    }


def parse_frames(text):
    out = []
    for chunk in str(text).split(","):
        chunk = chunk.strip()
        if not chunk:
            continue
        if "-" in chunk:
            lo, hi = chunk.split("-", 1)
            out.extend(range(int(lo), int(hi) + 1))
        else:
            out.append(int(chunk))
    return sorted(set(out))


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--sync-a1", required=True)
    ap.add_argument("--async-b", required=True)
    ap.add_argument("--sync-a2")
    ap.add_argument("--frames", default="")
    ap.add_argument("--max-lag", type=int, default=4)
    ap.add_argument("--out", required=True)
    args = ap.parse_args()

    a1 = load_probe(args.sync_a1)
    b = load_probe(args.async_b)
    a2 = load_probe(args.sync_a2) if args.sync_a2 else None

    listed = parse_frames(args.frames) if args.frames else []
    common = sorted(set(a1["records"]) & set(b["records"]))
    if listed:
        common = [f for f in common if f in set(listed)]

    result = {
        "schema": SCHEMA,
        "frames_requested": len(listed) or len(common),
        "frames_compared": 0,
        "max_lag": args.max_lag,
        "lag_histogram": {},
        "lag_buckets": {},
        "displacement": {},
        "lag_per_frame": {},
        "dominant_lag": None,
        "lag_constant": False,
        "full_match_frames": 0,
        "first_frame": common[0] if common else None,
        "last_frame": common[-1] if common else None,
        "rigid_count": len(b["records"][common[0]]["matrix_hex"]) if common else 0,
        "roster": {},
        "anchors": {},
        "sync_a1_vs_a2": {},
        "notes": [],
    }

    # ── 名册：A1 / B / A2 必须一致（479、无重复无未知）
    def roster_summary(p, label):
        ids = [r.get("rigid_index") for r in p["roster"]]
        # 没有骨骼关联的刚体（bone_index < 0）本身就没有骨骼名，不算「未解析」。
        unresolved = [r for r in p["roster"] if (r.get("bone_index") or -1) >= 0 and not r.get("bone_name")]
        return {
            "label": label,
            "count": p["roster_count"] or len(p["roster"]),
            "sha256": p["roster_sha256"],
            "index_min": min(ids) if ids else None,
            "index_max": max(ids) if ids else None,
            "index_contiguous": (ids == list(range(len(ids)))) if ids else False,
            "duplicates": len(ids) - len(set(ids)),
            "unresolved_bones": len(unresolved),
            "rigid_display": p.get("rigid_display"),
        }

    result["roster"] = {
        "a1": roster_summary(a1, "A1-sync"),
        "b": roster_summary(b, "B-async"),
        "a1_matches_b": a1["roster_sha256"] == b["roster_sha256"],
    }
    if a2:
        result["roster"]["a2"] = roster_summary(a2, "A2-sync")
        result["roster"]["a1_matches_a2"] = a1["roster_sha256"] == a2["roster_sha256"]

    # ── lag 直方图：async(N) 是否逐位等于 sync(N−L)
    hist = Counter()
    per_frame = {}
    body_diff_at_one = []
    for frame in common:
        matched_lags = []
        for lag in range(0, args.max_lag + 1):
            src = frame - lag
            if src not in a1["records"]:
                continue
            eq, diff = frames_equal(b["records"][frame], a1["records"][src])
            if eq:
                matched_lags.append(lag)
                hist[lag] += 1
        per_frame[frame] = matched_lags
        eq1, diff1 = frames_equal(b["records"][frame], a1["records"][frame - 1]) if (frame - 1) in a1["records"] else (False, -1)
        if not eq1:
            body_diff_at_one.append({"frame": frame, "bodies_differing_at_lag1": diff1})

    result["lag_histogram"] = {str(k): v for k, v in sorted(hist.items())}
    result["lag_per_frame"] = {str(k): v for k, v in per_frame.items()}
    result["frames_compared"] = len(common)
    if hist:
        dominant, count = hist.most_common(1)[0]
        result["dominant_lag"] = dominant
        result["dominant_lag_frames"] = count
        result["full_match_frames"] = count
        result["lag_constant"] = all(len(v) == 1 and v[0] == dominant for v in per_frame.values())
    if body_diff_at_one:
        result["mismatch_at_lag1_first"] = body_diff_at_one[0]
        result["mismatch_at_lag1_frames"] = len(body_diff_at_one)

    # ── lag 分桶（0 / 1 / 2 / ≥3 / 无匹配）：captain 要求 ≥3 的桶也要显式给出
    buckets = Counter()
    for frame, lags in per_frame.items():
        if not lags:
            buckets["none"] += 1
        else:
            smallest = min(lags)
            buckets[str(smallest) if smallest < 3 else "ge3"] += 1
    result["lag_buckets"] = {k: buckets[k] for k in ("0", "1", "2", "ge3", "none") if buckets[k]}
    result["lag_buckets_total"] = sum(buckets.values())

    # ── 位移分布：写回是否真的生效（t49 的 452 冻结指纹）
    result["displacement"] = {
        "a1": displacement_summary(a1, common),
        "b": displacement_summary(b, common),
    }
    if a2:
        shared_a2 = [f for f in common if f in a2["records"]]
        result["displacement"]["a2"] = displacement_summary(a2, shared_a2)

    # ── 每 lag 的位置偏差统计：即便不逐位相等，也能看出「最像哪一帧」
    lag_dev = {}
    for lag in range(0, args.max_lag + 1):
        vals = []
        for frame in common:
            src = frame - lag
            if src not in a1["records"]:
                continue
            vals.append(max_position_deviation(a1["records"][src], b["records"][frame]))
        if vals:
            vals_sorted = sorted(vals)
            lag_dev[str(lag)] = {
                "frames": len(vals),
                "median_mm": round(vals_sorted[len(vals_sorted) // 2], 3),
                "max_mm": round(vals_sorted[-1], 3),
            }
    result["per_lag_position_deviation"] = lag_dev

    # ── 逐帧找「最像的 sync 帧」：偏移乱跳即证明不存在恒定 lag
    best_offsets = {}
    for frame in (common[0], common[len(common) // 4], common[len(common) // 2], common[-2], common[-1]):
        candidates = [g for g in sorted(a1["records"]) if g <= frame]
        if not candidates:
            continue
        best = min(candidates, key=lambda g: max_position_deviation(a1["records"][g], b["records"][frame]))
        best_offsets[str(frame)] = {
            "best_sync_frame": best,
            "offset": frame - best,
            "max_mm": round(max_position_deviation(a1["records"][best], b["records"][frame]), 3),
        }
    result["best_sync_frame_per_async_frame"] = best_offsets

    # ── A1 vs A2（同配置两次独立启动）：逐位一致才说明逐位比较可跨进程
    if a2:
        shared = sorted(set(a1["records"]) & set(a2["records"]))
        ok = sum(1 for f in shared if frames_equal(a1["records"][f], a2["records"][f])[0])
        result["sync_a1_vs_a2"] = {"frames": len(shared), "identical": ok, "all_identical": ok == len(shared)}

    # ── 变形锚点：同帧 + lag 对齐后
    for frame in ANCHORS:
        entry = {"frame": frame}
        for label, probe in (("a1", a1), ("b", b)):
            rec = probe["records"].get(frame)
            if rec:
                mesh = rec["mesh"].get("Mesh") or next(iter(rec["mesh"].values()), None)
                if mesh:
                    entry[label] = {
                        "local": (mesh.get("local_sha256") or "")[:64],
                        "world": (mesh.get("world_sha256") or "")[:64],
                        "points": mesh.get("point_count"),
                    }
        lag = result["dominant_lag"]
        if lag is not None and (frame - lag) in a1["records"]:
            rec = a1["records"][frame - lag]
            mesh = rec["mesh"].get("Mesh") or next(iter(rec["mesh"].values()), None)
            if mesh:
                entry["a1_at_lag"] = {
                    "lag": lag,
                    "source_frame": frame - lag,
                    "local": (mesh.get("local_sha256") or "")[:64],
                    "world": (mesh.get("world_sha256") or "")[:64],
                }
        entry["anchor_local_prefix_expected"] = ANCHOR_LOCAL[frame]
        entry["anchor_world_prefix_expected"] = ANCHOR_WORLD[frame]
        if "a1" in entry:
            entry["a1_local_matches_anchor"] = entry["a1"]["local"].startswith(ANCHOR_LOCAL[frame])
            entry["a1_world_matches_anchor"] = entry["a1"]["world"].startswith(ANCHOR_WORLD[frame])
        result["anchors"][str(frame)] = entry

    Path(args.out).write_text(json.dumps(result, ensure_ascii=False, indent=1), encoding="utf-8")

    print("LAG_ANALYSIS frames=%d rigid=%d dominant_lag=%s constant=%s full_match=%d/%d"
          % (result["frames_compared"], result["rigid_count"], result["dominant_lag"],
             result["lag_constant"], result["full_match_frames"], result["frames_compared"]))
    print("LAG_HISTOGRAM " + json.dumps(result["lag_histogram"], sort_keys=True))
    print("LAG_BUCKETS " + json.dumps(result["lag_buckets"], sort_keys=True))
    for label in ("a1", "b", "a2"):
        d = result["displacement"].get(label)
        if not d:
            continue
        print("DISPLACEMENT %s moved=%d/%d frozen=%d max_mm=%s all_moved=%s"
              % (label, d["rigids_moved"], d["rigid_count"], d["rigids_frozen"],
                 d["max_displacement_mm"], d["all_rigids_moved"]))
    print("ROSTER count=%s sha=%s contiguous=%s dup=%s unresolved=%s a1==b:%s"
          % (result["roster"]["b"]["count"], result["roster"]["b"]["sha256"],
             result["roster"]["b"]["index_contiguous"], result["roster"]["b"]["duplicates"],
             result["roster"]["b"]["unresolved_bones"], result["roster"]["a1_matches_b"]))
    for frame in ANCHORS:
        e = result["anchors"][str(frame)]
        if "a1" in e:
            print("ANCHOR %d a1_local=%s a1_world=%s anchor_ok=%s/%s"
                  % (frame, e["a1"]["local"][:8], e["a1"]["world"][:8],
                     e["a1_local_matches_anchor"], e["a1_world_matches_anchor"]))
    if result.get("sync_a1_vs_a2"):
        s = result["sync_a1_vs_a2"]
        print("SYNC_A1_VS_A2 frames=%d identical=%d all=%s" % (s["frames"], s["identical"], s["all_identical"]))


if __name__ == "__main__":
    main()

#!/usr/bin/env python3
"""P6 语义分析（t76 修订版判据）。

判据（captain amend）：
  - 动态刚体（dynamic + dynamicAndBoneMerge，452 个）：async(N) 与 sync(N-1) 逐位相等；
  - 运动学刚体（kinematic，27 个）：async(N) 与 sync(N) 同帧逐位相等（跟当前帧骨骼）。
不做网格 sha、不做「最像帧」、不做误差阈值替代。

动态/运动学分类的推导：不依赖额外宿主调用——在 async 段里，帧 539→540 发生了位移的刚体就是
骨骼层级驱动的运动学刚体（此时动态刚体尚无结果）。用该集合作分类，并在输出里给出集合大小。
"""
import argparse
import json
import statistics
import struct
from pathlib import Path


def load(path):
    with open(path, "r", encoding="utf-8") as f:
        return json.load(f)


def frames_of(probe):
    return {int(r["frame"]): r for r in probe["records"]}


def matrices(record):
    return [rig.get("matrix_hex") or "" for rig in record["rigids"]]


def pos_of(hexstr):
    raw = bytes.fromhex(hexstr)
    vals = struct.unpack("<12f", raw[:48])
    return vals[9], vals[10], vals[11]


def dist_mm(a, b):
    dx, dy, dz = a[0] - b[0], a[1] - b[1], a[2] - b[2]
    return (dx * dx + dy * dy + dz * dz) ** 0.5


def pct(values, q):
    if not values:
        return 0.0
    s = sorted(values)
    k = (len(s) - 1) * q
    lo = int(k)
    hi = min(lo + 1, len(s) - 1)
    return s[lo] + (s[hi] - s[lo]) * (k - lo)


def derive_kinematic(b_probe):
    fs = frames_of(b_probe)
    order = sorted(fs)
    if len(order) < 2:
        return set()
    a = matrices(fs[order[0]])
    b = matrices(fs[order[1]])
    return {i for i, (x, y) in enumerate(zip(a, b)) if x != y}


def compare_subset(ref_probe, test_probe, lag, indices):
    """ref 用 frame-lag，test 用 frame；只在 indices 上比。返回逐帧结果。"""
    fr = frames_of(ref_probe)
    ft = frames_of(test_probe)
    out = {}
    for frame in sorted(ft):
        src = frame - lag
        if src not in fr:
            continue
        ma = matrices(fr[src])
        mb = matrices(ft[frame])
        if len(ma) != len(mb) or not indices:
            continue
        eq = all(ma[i] == mb[i] for i in indices)
        d = [dist_mm(pos_of(ma[i]), pos_of(mb[i])) for i in indices]
        out[frame] = {
            "bitwise_equal": eq,
            "equal_count": sum(1 for i in indices if ma[i] == mb[i]),
            "count": len(indices),
            "mean_mm": statistics.fmean(d) if d else 0.0,
            "max_mm": max(d) if d else 0.0,
            "p50_mm": pct(d, 0.5),
            "p90_mm": pct(d, 0.9),
        }
    return out


def displacement(probe, indices=None):
    fs = frames_of(probe)
    order = sorted(fs)
    if len(order) < 2:
        return {"frames": len(order), "rigids_moved": 0, "frozen": 0, "total_max_mm": 0.0}
    first = matrices(fs[order[0]])
    last = matrices(fs[order[-1]])
    idx = indices if indices is not None else range(len(first))
    total = [dist_mm(pos_of(first[i]), pos_of(last[i])) for i in idx]
    moved = sum(1 for t in total if t > 0.0)
    return {
        "frames": len(order),
        "rigids": len(total),
        "rigids_moved": moved,
        "frozen": len(total) - moved,
        "total_max_mm": max(total) if total else 0.0,
        "travel_max_mm": 0.0,
    }


def travel(probe, indices=None):
    fs = frames_of(probe)
    order = sorted(fs)
    if len(order) < 2:
        return 0.0
    idx = list(indices if indices is not None else range(len(matrices(fs[order[0]]))))
    prev = matrices(fs[order[0]])
    acc = [0.0] * len(idx)
    for frame in order[1:]:
        cur = matrices(fs[frame])
        for k, i in enumerate(idx):
            acc[k] += dist_mm(pos_of(prev[i]), pos_of(cur[i]))
        prev = cur
    return max(acc) if acc else 0.0


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--root", required=True)
    ap.add_argument("--out", required=True)
    ap.add_argument("--max-lag", type=int, default=4)
    ap.add_argument("--detail-from", type=int, default=539)
    ap.add_argument("--detail-count", type=int, default=8)
    ap.add_argument("--seek-after", type=int, default=560)
    args = ap.parse_args()

    root = Path(args.root)
    segs = {}
    for name in ("A1-sync", "B-async", "A2-sync"):
        p = root / "segments" / name / "semantics" / "probe.host.json"
        if p.exists():
            segs[name] = load(p)
    if "A1-sync" not in segs or "B-async" not in segs:
        raise SystemExit("missing probe.host.json: %s" % sorted(segs))

    a1, b, a2 = segs["A1-sync"], segs["B-async"], segs.get("A2-sync")

    kin = derive_kinematic(b)
    total_rigids = len(b["records"][0]["rigids"])
    dyn = set(range(total_rigids)) - kin

    # 主判据：动态 lag=1，运动学 lag=0
    dyn_lag1 = compare_subset(a1, b, 1, dyn)
    kin_lag0 = compare_subset(a1, b, 0, kin)

    dyn_frames = sorted(dyn_lag1)
    kin_frames = sorted(kin_lag0)
    dyn_equal = [f for f in dyn_frames if dyn_lag1[f]["bitwise_equal"]]
    kin_equal = [f for f in kin_frames if kin_lag0[f]["bitwise_equal"]]
    dyn_mismatch = [f for f in dyn_frames if not dyn_lag1[f]["bitwise_equal"]]
    kin_mismatch = [f for f in kin_frames if not kin_lag0[f]["bitwise_equal"]]

    verdict = ("lag1_dynamic_bitwise_equal" if (dyn_frames and not dyn_mismatch and not kin_mismatch)
               else "different_trajectory")

    detail = {}
    for frame in range(args.detail_from, args.detail_from + args.detail_count):
        if frame not in frames_of(b):
            continue
        row = {"frame": frame}
        for label, lag in (("vs_sync_N", 0), ("vs_sync_Nm1", 1)):
            src = frame - lag
            if src not in frames_of(a1):
                continue
            ma = matrices(frames_of(a1)[src])
            mb = matrices(frames_of(b)[frame])
            dd = [dist_mm(pos_of(ma[i]), pos_of(mb[i])) for i in dyn]
            kk = [dist_mm(pos_of(ma[i]), pos_of(mb[i])) for i in kin]
            row[label] = {
                "sync_frame": src,
                "dynamic_equal": sum(1 for i in dyn if ma[i] == mb[i]),
                "dynamic_count": len(dyn),
                "dynamic_mean_mm": statistics.fmean(dd) if dd else 0.0,
                "dynamic_max_mm": max(dd) if dd else 0.0,
                "kinematic_equal": sum(1 for i in kin if ma[i] == mb[i]),
                "kinematic_count": len(kin),
                "kinematic_mean_mm": statistics.fmean(kk) if kk else 0.0,
                "kinematic_max_mm": max(kk) if kk else 0.0,
            }
        detail[str(frame)] = row

    # 其它 lag（供参考，不参与判定）
    lag_table = {}
    for lag in range(0, args.max_lag + 1):
        d = compare_subset(a1, b, lag, dyn)
        lag_table[str(lag)] = {
            "frames": len(d),
            "equal_frames": sum(1 for f in d if d[f]["bitwise_equal"]),
            "max_mm": max((v["max_mm"] for v in d.values()), default=0.0),
        }

    seek_events = b.get("seek_events") or []
    pre = [f for f in dyn_frames if f < args.seek_after]
    post = [f for f in dyn_frames if f > args.seek_after]

    payload = {
        "schema": "vmd-p6-lag/2",
        "criteria": "dynamic_lag1_and_kinematic_same_frame",
        "segments": sorted(segs),
        "rigid_count": total_rigids,
        "kinematic_rigids": len(kin),
        "dynamic_rigids": len(dyn),
        "kinematic_rule": "derived from async frame %d->%d motion" % (args.detail_from, args.detail_from + 1),
        "verdict": verdict,
        "dynamic_lag1": {
            "compared": len(dyn_frames),
            "equal_frames": len(dyn_equal),
            "earliest_mismatch_frame": min(dyn_mismatch) if dyn_mismatch else None,
            "max_deviation_mm": max((v["max_mm"] for v in dyn_lag1.values()), default=0.0),
            "worst_frame": max(dyn_lag1, key=lambda f: dyn_lag1[f]["max_mm"]) if dyn_lag1 else None,
            "first_mismatch_detail": dyn_lag1.get(min(dyn_mismatch)) if dyn_mismatch else None,
        },
        "kinematic_same_frame": {
            "compared": len(kin_frames),
            "equal_frames": len(kin_equal),
            "earliest_mismatch_frame": min(kin_mismatch) if kin_mismatch else None,
            "max_deviation_mm": max((v["max_mm"] for v in kin_lag0.values()), default=0.0),
        },
        "detail_frames": detail,
        "lag_table_dynamic": lag_table,
        "displacement": {name: displacement(s) for name, s in segs.items()},
        "displacement_dynamic": {name: displacement(s, dyn) for name, s in segs.items()},
        "travel_max_mm": {name: travel(s, dyn) for name, s in segs.items()},
        "seek": {
            "events": seek_events,
            "pre_window": {"frames": len(pre), "equal_frames": sum(1 for f in pre if dyn_lag1[f]["bitwise_equal"])},
            "post_window": {"frames": len(post), "equal_frames": sum(1 for f in post if dyn_lag1[f]["bitwise_equal"])},
        },
        "sync_a1_vs_a2": None,
    }
    if a2 is not None:
        cmp2 = compare_subset(a1, a2, 0, set(range(total_rigids)))
        payload["sync_a1_vs_a2"] = {
            "compared": len(cmp2),
            "equal_frames": sum(1 for f in cmp2 if cmp2[f]["bitwise_equal"]),
        }

    out = Path(args.out)
    out.parent.mkdir(parents=True, exist_ok=True)
    with open(out, "w", encoding="utf-8") as f:
        json.dump(payload, f, ensure_ascii=False, indent=2)

    print("P6_VERDICT=%s" % verdict)
    print("P6_RIGIDS total=%d dynamic=%d kinematic=%d" % (total_rigids, len(dyn), len(kin)))
    print("P6_DYNAMIC_LAG1 compared=%d equal=%d earliest=%s max=%.4fmm@%s"
          % (len(dyn_frames), len(dyn_equal), payload["dynamic_lag1"]["earliest_mismatch_frame"],
             payload["dynamic_lag1"]["max_deviation_mm"], payload["dynamic_lag1"]["worst_frame"]))
    print("P6_KINEMATIC_SAME compared=%d equal=%d earliest=%s max=%.4fmm"
          % (len(kin_frames), len(kin_equal), payload["kinematic_same_frame"]["earliest_mismatch_frame"],
             payload["kinematic_same_frame"]["max_deviation_mm"]))
    print("P6_LAG_TABLE %s" % json.dumps(lag_table, ensure_ascii=False))
    for frame, row in list(detail.items())[:8]:
        a = row.get("vs_sync_N", {})
        b_ = row.get("vs_sync_Nm1", {})
        print("P6_DETAIL f=%s | vsN dyn_eq=%s/%s mean=%.3f max=%.3f | vsNm1 dyn_eq=%s/%s mean=%.3f max=%.3f"
              % (frame,
                 a.get("dynamic_equal", 0), a.get("dynamic_count", 0),
                 a.get("dynamic_mean_mm", 0.0), a.get("dynamic_max_mm", 0.0),
                 b_.get("dynamic_equal", 0), b_.get("dynamic_count", 0),
                 b_.get("dynamic_mean_mm", 0.0), b_.get("dynamic_max_mm", 0.0)))
    print("P6_DISPLACEMENT_DYN %s" % json.dumps(payload["displacement_dynamic"], ensure_ascii=False))
    print("P6_OUT %s" % out)


if __name__ == "__main__":
    main()

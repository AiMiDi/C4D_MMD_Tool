#!/usr/bin/env python3
"""把 stable-measure 的 probe.json 汇总成 stage 分解与自洽校验（t14）。

用法：
    python analyze-stable.py --run <OutDir> [--run <OutDir2> ...] [--json <out.json>]

自洽口径（写进报告，避免含糊）：
  * wall：客户端墙钟，`SetTime + doc.ExecutePasses(...)` 一次调用的耗时；
  * root_ms：插桩帧根的 inclusive 之和（父级包含子级，会重复计）；
  * self_sum：所有 stage 的 self_ms 之和（互不重叠，等价于插桩覆盖到的实际工作量）；
  * 自洽判据：|self_sum - wall| / wall ≤ 10% 且 |root_ms - wall| / wall ≤ 10%。
"""
from __future__ import annotations

import argparse
import json
import os
import statistics

LEAF_HINT = {
    "runtime.rebuild", "animation.layer", "ik.solve", "physics.total", "physics.bullet",
    "physics.inputs", "physics.writeback", "mesh.manager.execute", "mesh.invalidate",
    "mesh.weight_update", "material.sync", "material.ownership", "morph.total",
    "bone.plan", "bone.tag.execute", "bone.manager.execute", "bone.animation",
    "bone.scene_sync", "bone.hierarchy", "bone.append_order", "control.presentation",
    "control.solve", "control.chains", "control.sync", "model.execute", "model.managers",
}


def load(path: str) -> dict:
    with open(path, "r", encoding="utf-8") as handle:
        return json.load(handle)


def median(values: list) -> float:
    return round(statistics.median(values), 4) if values else 0.0


def collect(probe: dict) -> tuple:
    """返回 (per_mode_stage_table, per_mode_wall, per_mode_self_sum, per_mode_root)。"""
    stages = {}
    wall = {}
    self_sum = {}
    root = {}
    for rep in probe.get("reps", []):
        mode = rep["mode"]
        wall.setdefault(mode, []).append(float(rep["wall"]["median_ms"]))
        total_self = 0.0
        for name, info in (rep.get("stages") or {}).items():
            stages.setdefault(mode, {}).setdefault(name, []).append(float(info["median_inclusive_ms"]))
            total_self += float(info["median_self_ms"])
        self_sum.setdefault(mode, []).append(round(total_self, 4))
        # root 由 CSV 侧没有；用 model.execute 的 inclusive 作为帧根近似（若存在）
        model_exec = (rep.get("stages") or {}).get("model.execute")
        if model_exec:
            root.setdefault(mode, []).append(float(model_exec["median_inclusive_ms"]))
    table = {}
    for mode, names in stages.items():
        table[mode] = {name: median(vals) for name, vals in names.items()}
    return table, {k: median(v) for k, v in wall.items()}, {k: median(v) for k, v in self_sum.items()}, {k: median(v) for k, v in root.items()}


def main(argv=None) -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--run", action="append", required=True)
    parser.add_argument("--json", default="")
    args = parser.parse_args(argv)

    report = {"schema": "vmd-stable-analysis/1", "runs": []}
    for run_dir in args.run:
        summary = load(os.path.join(run_dir, "run-summary.json"))
        entry = {
            "run_dir": run_dir,
            "variant": summary.get("variant"),
            "artifact_sha": summary.get("artifact", {}).get("sha256"),
            "marker": summary.get("artifact", {}).get("profiling_marker"),
            "condition": (summary.get("config") or {}).get("condition"),
            "launches": [],
            "modes": {},
        }
        merged = {}
        for launch in summary.get("launches", []):
            if not launch.get("ok"):
                continue
            probe_path = launch.get("probe")
            if not probe_path or not os.path.exists(probe_path):
                continue
            probe = load(probe_path)
            table, wall, self_sum, root = collect(probe)
            per_mode = {}
            for mode in wall:
                stage_map = table.get(mode, {})
                ordered = sorted(stage_map.items(), key=lambda kv: -kv[1])
                per_mode[mode] = {
                    "wall_median_ms": wall[mode],
                    "stage_median_inclusive_ms": dict(ordered),
                    "self_sum_ms": self_sum.get(mode),
                    "root_ms": root.get(mode),
                    "self_sum_vs_wall_pct": round((self_sum.get(mode, 0) - wall[mode]) / wall[mode] * 100, 2) if wall[mode] else None,
                    "root_vs_wall_pct": round((root.get(mode, 0) - wall[mode]) / wall[mode] * 100, 2) if wall[mode] else None,
                }
                merged.setdefault(mode, {}).setdefault("wall", []).append(wall[mode])
            entry["launches"].append({
                "launch": launch.get("launch"),
                "pid": (launch.get("identity") or {}).get("pid"),
                "ticks": (launch.get("identity") or {}).get("start_ticks_utc"),
                "hosted_module_sha": launch.get("hosted_module_sha"),
                "modes": per_mode,
                "c4d_threads": launch.get("c4d_threads"),
                "cpu_total_samples": launch.get("cpu_total_samples"),
            })
        for mode, data in merged.items():
            values = data["wall"]
            entry["modes"][mode] = {
                "wall_medians": [round(v, 4) for v in values],
                "median_ms": median(values),
                "spread_pct": round((max(values) - min(values)) / min(values) * 100, 2) if len(values) > 1 and min(values) > 0 else 0.0,
            }
        report["runs"].append(entry)

    text = json.dumps(report, ensure_ascii=False, indent=2)
    if args.json:
        os.makedirs(os.path.dirname(args.json) or ".", exist_ok=True)
        with open(args.json, "w", encoding="utf-8") as handle:
            handle.write(text)
    print(text)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())

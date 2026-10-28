#!/usr/bin/env python3
"""把「主线程物理开销」从绝对帧时里剥离出来。

机器负载会同时抬高 on/off 两种模式的绝对帧时，跨启动比较 on 的中位数因此不可靠
（实测同一异步段三次启动 on 中位数 24.93/22.15/19.10 ms）。而**同一次启动内**
(physics-on 中位数 − physics-off 中位数) 抵消了整机负载这个共模项，留下的是
「物理在主线程上花掉多少毫秒」，这才是异步物理要消掉的目标量。

输出每个段每次启动的 on/off/开销，以及段的汇总（中位数、最小、最大、散布）。
"最小开销"代表该段最接近无争用时的表现，是最能反映机制上限的数字。
"""

from __future__ import annotations

import argparse
import json
import statistics
from pathlib import Path


def launch_cost(probe_path: Path) -> dict:
    payload = json.loads(probe_path.read_text(encoding="utf-8"))
    on = [rep["wall"]["median_ms"] for rep in payload.get("reps", []) if rep.get("mode") == "on"]
    off = [rep["wall"]["median_ms"] for rep in payload.get("reps", []) if rep.get("mode") == "off"]
    if not on or not off:
        return {}
    on_median = statistics.median(on)
    off_median = statistics.median(off)
    return {
        "launch": probe_path.parent.name,
        "label": payload.get("label"),
        "started_local": payload.get("started_local"),
        "on_median_ms": round(on_median, 4),
        "off_median_ms": round(off_median, 4),
        "main_thread_physics_ms": round(on_median - off_median, 4),
        "on_min_ms": round(min(on), 4),
        "off_min_ms": round(min(off), 4),
        "best_case_physics_ms": round(min(on) - min(off), 4),
        "reps_on": len(on),
        "reps_off": len(off),
    }


def summarize(rows: list[dict]) -> dict:
    if not rows:
        return {}
    costs = [row["main_thread_physics_ms"] for row in rows]
    best = [row["best_case_physics_ms"] for row in rows]
    return {
        "launches": len(rows),
        "main_thread_physics_ms": {
            "median": round(statistics.median(costs), 4),
            "min": round(min(costs), 4),
            "max": round(max(costs), 4),
            "spread_pct": round(
                (max(costs) - min(costs)) / statistics.median(costs) * 100.0, 2
            )
            if statistics.median(costs)
            else None,
        },
        "best_case_physics_ms": {
            "median": round(statistics.median(best), 4),
            "min": round(min(best), 4),
            "max": round(max(best), 4),
        },
        "on_median_ms": round(statistics.median([row["on_median_ms"] for row in rows]), 4),
        "off_median_ms": round(statistics.median([row["off_median_ms"] for row in rows]), 4),
    }


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--root", required=True, help="run-p4-ab 的 -OutRoot")
    parser.add_argument("--out", required=True)
    args = parser.parse_args()

    root = Path(args.root)
    result = {"root": str(root), "segments": {}}
    for segment_dir in sorted(root.glob("segments/*/timing")):
        rows = []
        for probe in sorted(segment_dir.glob("launch-*/probe.json")):
            row = launch_cost(probe)
            if row:
                rows.append(row)
        if rows:
            result["segments"][segment_dir.parent.name] = {
                "launches": rows,
                "summary": summarize(rows),
            }

    sync = result["segments"].get("A1-sync", {}).get("summary")
    async_ = result["segments"].get("B-async", {}).get("summary")
    if sync and async_:
        result["conclusion"] = {
            "sync_main_thread_physics_ms": sync["main_thread_physics_ms"]["min"],
            "async_main_thread_physics_ms": async_["main_thread_physics_ms"]["min"],
            "saved_ms": round(
                sync["main_thread_physics_ms"]["min"] - async_["main_thread_physics_ms"]["min"], 4
            ),
            "residual_async_ms": async_["main_thread_physics_ms"]["min"],
            "note": "两侧都取最接近无争用的一次启动；异步残差 = 提交/取回/写回的固定开销。",
        }

    Path(args.out).write_text(json.dumps(result, ensure_ascii=False, indent=2), encoding="utf-8")
    print("MAIN_THREAD_COST " + json.dumps(result.get("conclusion", {}), ensure_ascii=False))
    for name, block in result["segments"].items():
        summary = block["summary"]
        print(
            "  %-8s launches=%d median=%.2fms min=%.2fms max=%.2fms" % (
                name,
                summary["launches"],
                summary["main_thread_physics_ms"]["median"],
                summary["main_thread_physics_ms"]["min"],
                summary["main_thread_physics_ms"]["max"],
            )
        )
    return 0


if __name__ == "__main__":
    raise SystemExit(main())

#!/usr/bin/env python3
"""汇总跨启动漂移实验（stable-measure.ps1 -Launches N）的 md 表与归因数字。

用法：
    python analyze-drift.py <run-summary.json> [--json-out out.json]

输出（stdout）：
    1) 每次启动的机器状态（时钟/负载/线程/CPU 采样）与 on/off median；
    2) 跨启动散布（max-min）/min，与验收阈值 10% 对照；
    3) 与负载/时钟的皮尔逊相关系数（样本很少，只作方向性提示，不作因果）。
"""

from __future__ import annotations

import argparse
import json
import math
from pathlib import Path


def pearson(xs: list[float], ys: list[float]) -> float | None:
    n = len(xs)
    if n < 3 or len(ys) != n:
        return None
    mx = sum(xs) / n
    my = sum(ys) / n
    num = sum((x - mx) * (y - my) for x, y in zip(xs, ys))
    dx = math.sqrt(sum((x - mx) ** 2 for x in xs))
    dy = math.sqrt(sum((y - my) ** 2 for y in ys))
    if dx == 0 or dy == 0:
        return None
    return num / (dx * dy)


def spread_pct(values: list[float]) -> float:
    if len(values) < 2:
        return 0.0
    lo, hi = min(values), max(values)
    if lo <= 0:
        return 0.0
    return (hi - lo) / lo * 100.0


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("summary")
    ap.add_argument("--json-out", default="")
    args = ap.parse_args()

    summary = json.loads(Path(args.summary).read_text(encoding="utf-8"))
    launches = summary.get("launches", []) or []

    rows = []
    on_medians, off_medians, loads, clocks = [], [], [], []
    for item in launches:
        if not item.get("ok"):
            continue
        running = {}
        running_path = Path(item["dir"]) / "system-running.json"
        if running_path.exists():
            running = json.loads(running_path.read_text(encoding="utf-8"))
        modes = item.get("modes", {}) or {}
        on_ms = (modes.get("on") or {}).get("median_of_medians_ms")
        off_ms = (modes.get("off") or {}).get("median_of_medians_ms")
        on_spread = (modes.get("on") or {}).get("intra_spread_pct")
        off_spread = (modes.get("off") or {}).get("intra_spread_pct")
        samples = running.get("cpu_total_samples") or []
        load = sum(samples) / len(samples) if samples else running.get("load_pct_wmi")
        clock = running.get("current_mhz")
        threads = None
        c4d = running.get("cinema4d") or []
        if c4d:
            threads = c4d[0].get("threads")
        rows.append(
            {
                "launch": item.get("launch"),
                "pid": (item.get("identity") or {}).get("pid"),
                "startup_s": item.get("launch_seconds"),
                "clock_mhz": clock,
                "max_mhz": running.get("max_mhz"),
                "load_pct": load,
                "power_scheme": running.get("power_scheme"),
                "threads": threads,
                "on_ms": on_ms,
                "off_ms": off_ms,
                "on_intra_pct": on_spread,
                "off_intra_pct": off_spread,
            }
        )
        if on_ms is not None:
            on_medians.append(float(on_ms))
        if off_ms is not None:
            off_medians.append(float(off_ms))
        if load is not None:
            loads.append(float(load))
        if clock:
            clocks.append(float(clock))

    print("| 启动 | pid | 启动耗时 s | 时钟 MHz | 负载 % | 线程 | 物理开 median ms | 物理关 median ms | on 内散布 % | off 内散布 % |")
    print("| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |")
    for r in rows:
        print(
            "| L{launch} | {pid} | {startup_s} | {clock_mhz} | {load} | {threads} | {on_ms} | {off_ms} | {on_intra_pct} | {off_intra_pct} |".format(
                launch=r["launch"],
                pid=r["pid"],
                startup_s=r["startup_s"],
                clock_mhz=r["clock_mhz"],
                load=None if r["load_pct"] is None else round(float(r["load_pct"]), 1),
                threads=r["threads"],
                on_ms=r["on_ms"],
                off_ms=r["off_ms"],
                on_intra_pct=r["on_intra_pct"],
                off_intra_pct=r["off_intra_pct"],
            )
        )

    result = {"launches": rows, "spread": {}, "correlation": {}}
    for mode, values in (("on", on_medians), ("off", off_medians)):
        if not values:
            continue
        result["spread"][mode] = {
            "n": len(values),
            "values": [round(v, 4) for v in values],
            "min": round(min(values), 4),
            "max": round(max(values), 4),
            "median": round(sorted(values)[len(values) // 2], 4),
            "spread_pct": round(spread_pct(values), 2),
        }
    if len(loads) == len(on_medians) and len(on_medians) >= 3:
        result["correlation"]["on_vs_load"] = round(pearson(loads, on_medians) or 0.0, 3)
    if len(clocks) == len(on_medians) and len(on_medians) >= 3:
        result["correlation"]["on_vs_clock"] = round(pearson(clocks, on_medians) or 0.0, 3)

    print()
    for mode, info in result["spread"].items():
        print(
            f"- {mode}: n={info['n']} min={info['min']} max={info['max']} median={info['median']} spread={info['spread_pct']}%"
        )
    for key, value in result["correlation"].items():
        print(f"- r({key})={value}")
    if summary.get("launch_failures"):
        print(f"- launch_failures={len(summary['launch_failures'])}")
    print(f"- wall_gate: {json.dumps((summary.get('gate') or {}), ensure_ascii=False)}")

    if args.json_out:
        Path(args.json_out).write_text(json.dumps(result, ensure_ascii=False, indent=2), encoding="utf-8")
        print(f"- json_out={args.json_out}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())

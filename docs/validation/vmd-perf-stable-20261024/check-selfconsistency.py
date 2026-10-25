# -*- coding: utf-8 -*-
"""把某次 profiling 运行的 stage 口径与墙钟口径放在同一会话内对比。

用法: python check_selfconsistency.py <launch-dir>
输出: 每个 rep 的 wall median、Σself、root_ms、以及两者比值/缺口。
"""
import json
import statistics
import sys
from pathlib import Path


def main() -> int:
    launch = Path(sys.argv[1])
    probe = json.loads((launch / "probe.json").read_text(encoding="utf-8"))
    print(f"launch       = {launch}")
    print(f"exec_flags   = {probe.get('exec_flags')}")
    print(f"profile_rows = {probe.get('profile', {}).get('rows_total')} "
          f"threads={probe.get('profile', {}).get('threads')} "
          f"main={probe.get('profile', {}).get('main_thread')}")
    rows = []
    for rep in probe["reps"]:
        wall = rep["wall"]
        stages = rep.get("stages") or {}
        if isinstance(stages, list):
            stages = {s.get("name", str(i)): s for i, s in enumerate(stages)}
        self_sum = sum(
            (v.get("median_self_ms") if "median_self_ms" in v else v.get("self_ms", 0.0)) for v in stages.values()
        )
        incl_sum = sum(
            (v.get("median_inclusive_ms") if "median_inclusive_ms" in v else v.get("inclusive_ms", 0.0))
            for v in stages.values()
        )
        # root_ms 由 panel 的顶层 scope 决定；用 model.execute 的 inclusive 近似不可靠，
        # 这里只报 self 口径与 inclusive 口径两个数。
        rows.append({
            "rep": rep["rep"],
            "mode": rep["mode"],
            "wall_median": wall.get("median_ms"),
            "wall_mean": wall.get("mean_ms"),
            "self_sum": round(self_sum, 3),
            "incl_sum": round(incl_sum, 3),
        })
    print(f"{'rep':>4} {'mode':>4} {'wall_med':>9} {'Σself':>9} {'Σself/wall':>10} {'Σincl':>9}")
    for r in rows:
        if r["wall_median"]:
            ratio = r["self_sum"] / r["wall_median"]
            print(f"{r['rep']:>4} {r['mode']:>4} {r['wall_median']:>9.3f} {r['self_sum']:>9.3f} "
                  f"{ratio:>10.3f} {r['incl_sum']:>9.3f}")
    for mode in ("on", "off"):
        sel = [r for r in rows if r["mode"] == mode and r["wall_median"]]
        if not sel:
            continue
        w = statistics.median([r["wall_median"] for r in sel])
        s = statistics.median([r["self_sum"] for r in sel])
        print(f"[{mode}] wall={w:.3f} Σself={s:.3f} ratio={s / w:.3f} gap={w - s:+.3f} ms ({(s / w - 1) * 100:+.1f}%)")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())

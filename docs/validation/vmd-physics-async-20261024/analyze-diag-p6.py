import collections
import io
import json
import re
import sys

LOG = r"S:\tmp\cmt_vmd_profile_20261019\p6b\ab\diag-b-async3.log"
OUT = r"S:\tmp\cmt_vmd_profile_20261019\p6b\ab\diag-summary.json"


def kv(line):
    body = line.split(" ", 1)[1] if " " in line else ""
    out = {}
    for token in body.split():
        if "=" in token:
            k, v = token.split("=", 1)
            out[k] = v
    return out


def main():
    lines = [l.strip() for l in io.open(LOG, encoding="utf-8", errors="replace") if l.strip()]
    steps, wsteps, dispatches, seeds, stats = [], [], [], [], []
    for line in lines:
        if line.startswith("step "):
            steps.append(kv(line))
        elif line.startswith("wstep "):
            wsteps.append(kv(line))
        elif line.startswith("dispatch "):
            dispatches.append(kv(line))
        elif line.startswith("seed "):
            seeds.append(kv(line))
        elif line.startswith("stats "):
            stats.append(kv(line))

    # 每个 epoch 的 step 序列（step 行含 epoch）
    by_epoch = collections.OrderedDict()
    for s in steps:
        by_epoch.setdefault(s.get("epoch"), []).append(s)

    # 每帧 dispatch 计数（按 doc_seconds）
    disp_by_time = collections.OrderedDict()
    for d in dispatches:
        disp_by_time.setdefault(d.get("doc_seconds"), []).append(d)

    # 最终 stats（最后一个 final=1）
    final = stats[-1] if stats else {}

    summary = {
        "lines": len(lines),
        "counts": {"step": len(steps), "wstep": len(wsteps), "dispatch": len(dispatches), "seed": len(seeds), "stats": len(stats)},
        "epochs": {},
        "dispatch_times": {t: len(v) for t, v in disp_by_time.items()},
        "double_dispatch_times": {t: len(v) for t, v in disp_by_time.items() if len(v) > 1},
        "final_stats": final,
        "seeds": seeds,
    }
    for epoch, seq in by_epoch.items():
        summary["epochs"][epoch] = {
            "steps": len(seq),
            "first": seq[0],
            "last": seq[-1],
            "seq": seq,
        }
    json.dump(summary, io.open(OUT, "w", encoding="utf-8"), ensure_ascii=False, indent=2)

    print("LINES %d step=%d wstep=%d dispatch=%d seed=%d stats=%d"
          % (len(lines), len(steps), len(wsteps), len(dispatches), len(seeds), len(stats)))
    print("EPOCHS %s" % json.dumps({k: v["steps"] for k, v in summary["epochs"].items()}, ensure_ascii=False))
    print("DOUBLE_DISPATCH %s" % json.dumps(summary["double_dispatch_times"], ensure_ascii=False))
    print("FINAL_STATS %s" % json.dumps(final, ensure_ascii=False))
    for epoch, seq in by_epoch.items():
        if len(seq) < 2:
            continue
        print("--- epoch %s ---" % epoch)
        for s in seq[:10]:
            print("  step submitted=%s applied=%s payload_hash=%s worker=%s produced=%s consumed=%s skipped=%s covered=%s stale=%s"
                  % (s.get("submitted"), s.get("applied"), s.get("payload_hash"), s.get("worker_steps"),
                     s.get("produced"), s.get("consumed"), s.get("submit_skipped"), s.get("result_covered"),
                     s.get("stale_dropped")))
    print("--- wstep ---")
    for w in wsteps[:12]:
        print("  k=%s job_frame=%s bones=%s" % (w.get("k"), w.get("job_frame"), w.get("bones")))
    print("OUT %s" % OUT)


if __name__ == "__main__":
    sys.exit(main())

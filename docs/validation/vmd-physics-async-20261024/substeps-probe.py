#!/usr/bin/env python3
"""调度子步档位测量（同步模式）：substeps = 3 / 2 / 1 各跑一轮 on 计时。

只读场景 + 改模型管理器参数（MODEL_PHYSICS_SUBSTEPS = 3200），不写产品树。
用法：
  python substeps-probe.py --steps 3,2,1 --start 560 --frames 30 --out <path>.json
"""

from __future__ import annotations

import argparse
import json
import sys
import time
from pathlib import Path

REPO = Path(r"C:\code\C4D_MMD_Tool")
sys.path.insert(0, str(REPO / "mcp"))

import importlib.util  # noqa: E402

_spec = importlib.util.spec_from_file_location(
    "host_driver", str(REPO / "docs" / "validation" / "vmd-host-restore-20261024" / "host-driver.py")
)
driver = importlib.util.module_from_spec(_spec)
_spec.loader.exec_module(driver)  # type: ignore[union-attr]

TOKEN = Path(r"S:\tmp\cmt_vmd_profile_20261019\host_profile\prefs\mcp\token")
ENDPOINT = "http://127.0.0.1:5557/mcp"

MEASURE_CODE = r"""
import json, time, c4d
doc = None
candidates = []
d = c4d.documents.GetFirstDocument()
while d:
    roots = list(d.GetObjects())
    candidates.append((len(roots), d))
    d = d.GetNext()
if candidates:
    candidates.sort(key=lambda t: t[0])
    doc = candidates[-1][1]
    c4d.documents.SetActiveDocument(doc)
if doc is None:
    raise RuntimeError("no document")

manager = None
stack = list(doc.GetObjects())
while stack:
    o = stack.pop()
    if o is None:
        continue
    if o.GetTypeName() == "MMD模型管理器":
        manager = o
        break
    stack.extend(list(o.GetChildren()))

substeps_before = None
substeps_after = None
if manager is not None:
    bc = manager.GetDataInstance()
    substeps_before = bc.GetInt32(3200)
    if SUBSTEPS_SET > 0:
        manager.SetParameter(c4d.DescID(c4d.DescLevel(3200)), SUBSTEPS_SET, c4d.DESCFLAGS_SET_NONE)
    substeps_after = manager.GetDataInstance().GetInt32(3200)

fps = doc.GetFps()
frames = []
for f in range(START - WARMUP, START + FRAMES):
    doc.SetTime(c4d.BaseTime(f, fps))
    t0 = time.perf_counter()
    doc.ExecutePasses(None, True, True, True, c4d.EXECUTIONFLAGS_PASS_ALL)
    frames.append((f, (time.perf_counter() - t0) * 1000.0))

tail = [ms for f, ms in frames if f >= START]
tail_sorted = sorted(tail)
n = len(tail_sorted)
result = {
    "schema": "vmd-substeps-probe/1",
    "manager_found": manager is not None,
    "substeps_before": substeps_before,
    "substeps_after": substeps_after,
    "fps": fps,
    "warmup": WARMUP,
    "frames": FRAMES,
    "start": START,
    "samples": n,
    "median_ms": tail_sorted[n // 2] if n else None,
    "mean_ms": (sum(tail) / n) if n else None,
    "p95_ms": tail_sorted[min(n - 1, int(n * 0.95))] if n else None,
    "min_ms": tail_sorted[0] if n else None,
    "max_ms": tail_sorted[-1] if n else None,
    "per_frame": [{"frame": f, "ms": ms} for f, ms in frames],
}
print("SUBSTEPS_RESULT:" + json.dumps(result, allow_nan=True, default=str))
"""


def one_step(conn, substeps: int, warmup: int, frames: int, start: int) -> dict:
    code = (
        MEASURE_CODE.replace("SUBSTEPS_SET", str(substeps))
        .replace("WARMUP", str(warmup))
        .replace("FRAMES", str(frames))
        .replace("START", str(start))
    )
    out = driver.run_host_code(code, timeout=300, tolerate_error_with_stdout=True)
    text = out.get("stdout") or ""
    for line in text.splitlines():
        if line.startswith("SUBSTEPS_RESULT:"):
            return json.loads(line[len("SUBSTEPS_RESULT:") :])
    raise RuntimeError(f"no SUBSTEPS_RESULT in host stdout: {text[-400:]}")


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--steps", default="3,2,1")
    ap.add_argument("--start", type=int, default=560)
    ap.add_argument("--frames", type=int, default=30)
    ap.add_argument("--warmup", type=int, default=15)
    ap.add_argument("--out", required=True)
    args = ap.parse_args()

    steps = [int(s) for s in args.steps.split(",") if s.strip()]
    conn = driver.connect(timeout=120.0)
    results = []
    for step in steps:
        r = one_step(conn, step, args.warmup, args.frames, args.start)
        r["requested_substeps"] = step
        results.append(r)
        print(f"SUBSTEPS {step}: median={r['median_ms']:.3f} ms mean={r['mean_ms']:.3f} p95={r['p95_ms']:.3f} (applied={r['substeps_after']})")

    payload = {"schema": "vmd-substeps-ab/1", "results": results, "generated_at": time.strftime("%Y-%m-%dT%H:%M:%S")}
    Path(args.out).write_text(json.dumps(payload, ensure_ascii=False, indent=2), encoding="utf-8")
    print("SUBSTEPS_OK " + args.out)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())


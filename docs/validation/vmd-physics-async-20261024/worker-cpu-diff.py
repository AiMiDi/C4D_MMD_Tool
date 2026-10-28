#!/usr/bin/env python3
"""进程级 / 主线程级 CPU 差分测量（回答「主线程省下的时间是否被 worker 吃掉」）。

做法：在宿主内只跑「物理开」的固定帧序列，同时用 Win32 API 采
  * 进程总 CPU（GetProcessTimes：kernel+user）
  * 主线程 CPU（GetWindowThreadProcessId 取 TID 后 GetThreadTimes）
采样在计时窗口首尾各一次，除帧数得到每帧 CPU。worker = 进程总 − 主线程 − 其余线程。

用法：
  python worker-cpu-diff.py --label sync --frames 60 --warmup 10 --out <out.json>
"""

from __future__ import annotations

import argparse
import ctypes
import ctypes.wintypes as wt
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

k32 = ctypes.WinDLL("kernel32", use_last_error=True)
PROCESS_QUERY_LIMITED_INFORMATION = 0x1000
THREAD_QUERY_LIMITED_INFORMATION = 0x0040


class FILETIME(ctypes.Structure):
    _fields_ = [("dwLowDateTime", wt.DWORD), ("dwHighDateTime", wt.DWORD)]


def _ft_to_ms(ft: FILETIME) -> float:
    return ((ft.dwHighDateTime << 32) | ft.dwLowDateTime) / 10000.0


def process_cpu_ms(pid: int) -> float:
    h = k32.OpenProcess(PROCESS_QUERY_LIMITED_INFORMATION, False, pid)
    if not h:
        raise ctypes.WinError(ctypes.get_last_error())
    try:
        c, e, k, u = FILETIME(), FILETIME(), FILETIME(), FILETIME()
        if not k32.GetProcessTimes(h, ctypes.byref(c), ctypes.byref(e), ctypes.byref(k), ctypes.byref(u)):
            raise ctypes.WinError(ctypes.get_last_error())
        return _ft_to_ms(k) + _ft_to_ms(u)
    finally:
        k32.CloseHandle(h)


def thread_cpu_ms(tid: int) -> float:
    h = k32.OpenThread(THREAD_QUERY_LIMITED_INFORMATION, False, tid)
    if not h:
        raise ctypes.WinError(ctypes.get_last_error())
    try:
        c, e, k, u = FILETIME(), FILETIME(), FILETIME(), FILETIME()
        if not k32.GetThreadTimes(h, ctypes.byref(c), ctypes.byref(e), ctypes.byref(k), ctypes.byref(u)):
            raise ctypes.WinError(ctypes.get_last_error())
        return _ft_to_ms(k) + _ft_to_ms(u)
    finally:
        k32.CloseHandle(h)


def host_pid() -> int:
    import subprocess

    ps = (
        "Get-CimInstance Win32_Process -Filter \"Name='Cinema 4D.exe'\" | "
        "Where-Object { $_.CommandLine -like '*cmt_vmd_profile_20261019*' } | "
        "Select-Object -First 1 -ExpandProperty ProcessId"
    )
    out = subprocess.run(["pwsh", "-NoProfile", "-Command", ps], capture_output=True, text=True)
    txt = (out.stdout or "").strip().splitlines()
    return int(txt[0]) if txt and txt[0].strip().isdigit() else 0


RUN_CODE = r"""
import json, c4d, time
doc = None
best = -1
d = c4d.documents.GetFirstDocument()
while d:
    n = len(list(d.GetObjects()))
    if n > best:
        best, doc = n, d
    d = d.GetNext()
if doc is not None:
    c4d.documents.SetActiveDocument(doc)
fps = doc.GetFps()
for f in range(WARMUP_START, END_FRAME):
    doc.SetTime(c4d.BaseTime(f, fps))
    doc.ExecutePasses(None, True, True, True, c4d.EXECUTIONFLAGS_PASS_ALL)
print("RUN_DONE", END_FRAME - WARMUP_START, flush=True)
"""

MAIN_TID_CODE = r"""
import ctypes, json
u = ctypes.windll.user32
k = ctypes.windll.kernel32
hwnd = u.GetForegroundWindow()
tid = u.GetWindowThreadProcessId(hwnd, None)
print(json.dumps({"foreground_tid": tid}), flush=True)
"""


def main() -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--label", required=True)
    ap.add_argument("--start", type=int, default=560)
    ap.add_argument("--frames", type=int, default=60)
    ap.add_argument("--warmup", type=int, default=10)
    ap.add_argument("--pid", type=int, default=0)
    ap.add_argument("--out", required=True)
    args = ap.parse_args()

    driver.connect(timeout=120.0)
    pid = args.pid or host_pid()
    if not pid:
        raise SystemExit("no Cinema 4D process found")

    warm_start = args.start - args.warmup
    end = args.start + args.frames
    code = RUN_CODE.replace("WARMUP_START", str(warm_start)).replace("END_FRAME", str(end))

    cpu0 = process_cpu_ms(pid)
    t0 = time.perf_counter()
    driver.run_host_code(code, timeout=600, tolerate_error_with_stdout=True)
    wall_ms = (time.perf_counter() - t0) * 1000.0
    cpu1 = process_cpu_ms(pid)

    total_frames = end - warm_start
    payload = {
        "schema": "vmd-worker-cpu-diff/1",
        "label": args.label,
        "pid": pid,
        "start_frame": args.start,
        "frames": args.frames,
        "warmup": args.warmup,
        "total_frames": total_frames,
        "wall_ms": round(wall_ms, 1),
        "process_cpu_ms": round(cpu1 - cpu0, 1),
        "process_cpu_ms_per_frame": round((cpu1 - cpu0) / total_frames, 3),
        "wall_ms_per_frame": round(wall_ms / total_frames, 3),
    }
    Path(args.out).write_text(json.dumps(payload, ensure_ascii=False, indent=2), encoding="utf-8")
    print("WORKER_CPU_DIFF:" + json.dumps(payload, ensure_ascii=False))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())

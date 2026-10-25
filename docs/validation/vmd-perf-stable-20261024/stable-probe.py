#!/usr/bin/env python3
"""单会话内交替测量：同一宿主进程里重复多轮物理开/关，采墙钟 + 插桩 stage。

设计要点（t14 契约）：
  * 一轮宿主会话内交替 ≥5 次，避免跨启动漂移污染对照；
  * 每个 rep 都重设物理开关，并记录设置结果，防止"以为切了其实没切"；
  * 墙钟口径与 t8/t13 一致：SetTime + doc.ExecutePasses(None, True, True, True, PASS_ALL)；
  * 若宿主是 profiling 构建（CMT_PROFILE_LOG 生效），同一 rep 的 stage 行按帧号对齐；
  * 输出原始逐帧 CSV（墙钟 + 各 stage inclusive/self），供后续自洽校验与归因。

用法：
    python stable-probe.py --pmx <pmx> --vmd <vmd> --reps 5 --mode both \
        --warmup 20 --frames 40 --start 560 --out <json> --csv <csv> \
        --profile-log <path> --label baseline
"""
from __future__ import annotations

import argparse
import importlib.util
import json
import os
import statistics
import sys
import time

for _stream in (sys.stdout, sys.stderr):
    try:
        _stream.reconfigure(encoding="utf-8", errors="backslashreplace")
    except Exception:
        pass

REPO = r"C:\code\C4D_MMD_Tool"
DRIVER = os.path.join(REPO, "docs", "validation", "vmd-host-restore-20261024", "host-driver.py")


def load_driver():
    spec = importlib.util.spec_from_file_location("vmd_host_driver", DRIVER)
    if spec is None or spec.loader is None:
        raise SystemExit("driver_not_loadable: %s" % DRIVER)
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    return module


# --- 宿主内执行：固定 30FPS 时间轴上的逐帧墙钟 ---------------------------------
TIMING_CODE = r'''
import json, time, c4d

label = %(label)r
warmup = %(warmup)d
frames = %(frames)d
start = %(start)d

# 多文档时（快照残留空文档）选择顶层对象最多的那个，与 host-driver 的 PICK_ACTIVE_PREAMBLE 一致
docs = c4d.documents.GetFirstDocument()
best = None
best_count = -1
while docs is not None:
    top = docs.GetFirstObject()
    count = 0
    while top is not None:
        count += 1
        top = top.GetNext()
    if count > best_count:
        best, best_count = docs, count
    docs = docs.GetNext()
if best is not None:
    c4d.documents.SetActiveDocument(best)

doc = c4d.documents.GetActiveDocument()
if doc is None:
    raise RuntimeError("no_active_document")
fps = doc.GetFps() or 30
flags = %(flags_expr)s

# 预热段：与 t8/t13 配方对齐（540-559 预热，560-619 计时）
for i in range(warmup):
    doc.SetTime(c4d.BaseTime(start - warmup + i, fps))
    doc.ExecutePasses(None, True, True, True, flags)

samples = []
for k in range(frames):
    doc.SetTime(c4d.BaseTime(start + k, fps))
    t0 = time.perf_counter()
    doc.ExecutePasses(None, True, True, True, flags)
    samples.append(round((time.perf_counter() - t0) * 1000.0, 4))

print(json.dumps({"label": label, "fps": fps, "warmup": warmup, "frames": frames,
                  "start": start, "ms": samples}, ensure_ascii=False))
'''


SCENE_INFO_CODE = r'''
import json, c4d

docs = c4d.documents.GetFirstDocument()
best = None
best_count = -1
while docs is not None:
    top = docs.GetFirstObject()
    count = 0
    while top is not None:
        count += 1
        top = top.GetNext()
    if count > best_count:
        best, best_count = docs, count
    docs = docs.GetNext()
doc = best
info = {"object_count_top_level": best_count if best is not None else 0}
if doc is not None:
    info["fps"] = doc.GetFps()
    info["min_frame"] = doc.GetMinTime().GetFrame(30)
    info["max_frame"] = doc.GetMaxTime().GetFrame(30)
    info["document_name"] = doc.GetDocumentName()
    try:
        info["dynamics_substeps"] = doc[c4d.DOCUMENT_DYNAMICSUBDIVISION]
    except Exception as exc:
        info["dynamics_substeps_error"] = repr(exc)
    try:
        info["dynamics_auto_time_steps"] = bool(doc[c4d.DOCUMENT_DYNAMICAUTOTIMESTEPS])
    except Exception as exc:
        info["dynamics_auto_time_steps_error"] = repr(exc)
    counts = {}
    stack = [doc.GetFirstObject()]
    total = 0
    while stack:
        obj = stack.pop()
        if obj is None:
            continue
        total += 1
        name = ""
        try:
            name = obj.GetTypeName()
        except Exception:
            name = "?"
        counts[name] = counts.get(name, 0) + 1
        stack.append(obj.GetDown())
        stack.append(obj.GetNext())
    info["object_total"] = total
    info["type_counts"] = dict(sorted(counts.items(), key=lambda kv: -kv[1]))
print(json.dumps(info, ensure_ascii=False))
'''


def read_profile_lines(path: str, offset: int) -> tuple:
    """从 offset 起读新增的插桩行；返回 (parsed_rows, new_offset)。"""
    if not path or not os.path.exists(path):
        return [], offset
    with open(path, "rb") as handle:
        handle.seek(0, os.SEEK_END)
        size = handle.tell()
        if size <= offset:
            return [], size
        handle.seek(offset)
        blob = handle.read()
    rows = []
    for line in blob.splitlines():
        line = line.strip()
        if not line:
            continue
        try:
            rows.append(json.loads(line))
        except Exception:
            continue
    return rows, offset + len(blob)


def stage_table(rows: list) -> dict:
    """把插桩行聚合成 {stage: {median_inclusive, median_self, calls}}。"""
    buckets = {}
    for row in rows:
        for stage in row.get("stages") or []:
            name = stage.get("name")
            if not name:
                continue
            slot = buckets.setdefault(name, {"inclusive": [], "self": [], "calls": []})
            slot["inclusive"].append(float(stage.get("inclusive_ms") or 0.0))
            slot["self"].append(float(stage.get("self_ms") or 0.0))
            slot["calls"].append(int(stage.get("calls") or 0))
    table = {}
    for name, slot in buckets.items():
        table[name] = {
            "median_inclusive_ms": round(statistics.median(slot["inclusive"]), 4),
            "median_self_ms": round(statistics.median(slot["self"]), 4),
            "calls_median": int(statistics.median(slot["calls"])) if slot["calls"] else 0,
            "frames": len(slot["inclusive"]),
        }
    return table


SCENE_PREPARE_CODE = r"""
import json, c4d

# 禁止在 exec_python 内新建文档（c4d.documents.BaseDocument() + InsertBaseDocument +
# SetActiveDocument）。在 MCP dispatcher 的 drain 内这条路会触发 CoreMessage 重入
# （audit.log 的 REENTRANT_DRAIN），2026-10-24 19:07:37 的宿主崩溃即由此触发：
# _bugreports/_BugReport.txt 的调用栈全是 python311 帧，mmdtool 只出现在 Loaded_Modules。
# 因此这里只复用启动时已经加载的文档：改 fps / 帧范围，再走 mmdtool_import_*。
doc = c4d.documents.GetActiveDocument()
if doc is None:
    raise RuntimeError("no_active_document")
doc.SetFps(30)
doc.SetMinTime(c4d.BaseTime(0, 30))
doc.SetMaxTime(c4d.BaseTime(619, 30))
doc.SetLoopMinTime(c4d.BaseTime(0, 30))
doc.SetLoopMaxTime(c4d.BaseTime(619, 30))
doc.SetTime(c4d.BaseTime(0, 30))
print(json.dumps({"ok": True, "name": doc.GetDocumentName(), "fps": doc.GetFps(),
                  "min_frame": doc.GetMinTime().GetFrame(30),
                  "max_frame": doc.GetMaxTime().GetFrame(30),
                  "objects_before": len(doc.GetObjects())}, ensure_ascii=False))
"""


def set_physics(driver, enabled: bool) -> dict:
    host = driver.connect(timeout=120.0)  # 卡死宿主最多等 2 分钟，避免占住整轮
    caps = driver.op(host, "mmdtool_capabilities", {}, may_mutate=False)["data"]
    document = (caps.get("documents") or [])[-1]["handle"]
    models = driver.op(host, "mmdtool_list_models", {"document": document}, may_mutate=False)["data"]["models"]
    if not models:
        raise SystemExit("no_model_handle")
    result = driver.op(host, "mmdtool_set_physics_enabled",
                       {"document": document, "model": models[0]["handle"], "enabled": enabled})
    return {"requested": enabled, "data": result.get("data")}


def build_scene(driver, pmx: str, vmd: str) -> dict:
    """资产 + 固定配方重建场景（.c4d 不能回放，见 README §8）。

    复用宿主启动时的文档，不新建文档（见 SCENE_PREPARE_CODE 注释里的崩溃证据）。
    """
    info = {}
    driver.run_host_code(SCENE_PREPARE_CODE, tolerate_error_with_stdout=True)
    host = driver.connect(timeout=120.0)  # 卡死宿主最多等 2 分钟，避免占住整轮
    caps = driver.op(host, "mmdtool_capabilities", {}, may_mutate=False)["data"]
    document = (caps.get("documents") or [])[-1]["handle"]
    imported = driver.op(host, "mmdtool_import_pmx", {"document": document, "path": pmx})["data"]
    model = (imported.get("model") or {}).get("handle")
    if not model:
        raise SystemExit("import_pmx_no_model: " + json.dumps(imported, ensure_ascii=False)[:1500])
    motion = driver.op(host, "mmdtool_import_motion",
                       {"document": document, "model": model, "path": vmd, "strategy": "replace"})["data"]
    info["document"] = document
    info["model"] = model
    info["import_pmx"] = {k: imported.get(k) for k in ("bone_count", "morph_count", "slot_count")}
    info["import_motion"] = {k: motion.get(k) for k in ("bone_count", "morph_count", "slot")}
    return info


def summarise(values: list) -> dict:
    if not values:
        return {"n": 0}
    ordered = sorted(values)
    def pct(p):
        index = max(0, min(len(ordered) - 1, int(round((len(ordered) - 1) * p))))
        return round(ordered[index], 4)
    return {
        "n": len(ordered),
        "mean_ms": round(statistics.fmean(ordered), 4),
        "median_ms": round(statistics.median(ordered), 4),
        "min_ms": round(ordered[0], 4),
        "max_ms": round(ordered[-1], 4),
        "p95_ms": pct(0.95),
        "stdev_ms": round(statistics.pstdev(ordered), 4) if len(ordered) > 1 else 0.0,
    }


def main(argv=None) -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--pmx", required=True)
    parser.add_argument("--vmd", required=True)
    parser.add_argument("--reps", type=int, default=5)
    parser.add_argument("--mode", choices=["both", "on", "off"], default="both")
    parser.add_argument("--warmup", type=int, default=20)
    parser.add_argument("--frames", type=int, default=40)
    parser.add_argument("--start", type=int, default=560)
    parser.add_argument("--out", required=True)
    parser.add_argument("--csv", required=True)
    parser.add_argument("--profile-log", default="")
    parser.add_argument("--label", default="")
    parser.add_argument("--expect-physics", default="")
    parser.add_argument("--skip-scene", action="store_true")
    parser.add_argument("--exec-flags", choices=["all", "default"], default="all",
                        help="all=PASS_ALL(t8/t13 口径); default=EXECUTIONFLAGS_0(只跑动画/表达式)")
    args = parser.parse_args(argv)

    driver = load_driver()
    started = time.time()
    payload = {
        "schema": "vmd-stable-probe/1",
        "label": args.label,
        "started_local": time.strftime("%Y-%m-%dT%H:%M:%S"),
        "profile_log": args.profile_log or None,
        "expect_physics": args.expect_physics or None,
        "exec_flags": args.exec_flags,
        "reps": [],
        "scene": None,
    }

    if not args.skip_scene:
        payload["scene"] = build_scene(driver, args.pmx, args.vmd)
        try:
            info = driver.run_host_code(SCENE_INFO_CODE, tolerate_error_with_stdout=True)
            payload["scene_info"] = json.loads(info["stdout"].strip().splitlines()[-1])
        except Exception as exc:
            payload["scene_info_error"] = repr(exc)
        print("scene_info:" + json.dumps({
            "fps": (payload.get("scene_info") or {}).get("fps"),
            "dynamics_substeps": (payload.get("scene_info") or {}).get("dynamics_substeps"),
            "object_total": (payload.get("scene_info") or {}).get("object_total"),
        }, ensure_ascii=False), flush=True)

    modes = ["on", "off"] if args.mode == "both" else [args.mode]
    csv_rows = []
    stage_names = []
    log_offset = 0
    if args.profile_log and os.path.exists(args.profile_log):
        log_offset = os.path.getsize(args.profile_log)

    for rep in range(1, args.reps + 1):
        for mode in modes:
            enabled = mode == "on"
            switch = set_physics(driver, enabled)
            label = "%s-rep%d-%s" % (args.label or "run", rep, mode)
            flags_expr = "c4d.EXECUTIONFLAGS_PASS_ALL" if args.exec_flags == "all" else "c4d.EXECUTIONFLAGS_0"
            out = driver.run_host_code(TIMING_CODE % {
                "label": label, "warmup": args.warmup, "frames": args.frames, "start": args.start,
                "flags_expr": flags_expr,
            }, tolerate_error_with_stdout=True)
            try:
                measured = json.loads(out["stdout"].strip().splitlines()[-1])
            except Exception:
                raise SystemExit("timing_output_unparsable: " + out["stdout"][-2000:])
            wall = [float(x) for x in measured["ms"]]

            payload["reps"].append({
                "rep": rep,
                "mode": mode,
                "label": label,
                "physics_switch": switch,
                "wall": summarise(wall),
                "profile_frames": 0,
                "stages": {},
            })
            for index, value in enumerate(wall):
                csv_rows.append({
                    "rep": rep, "mode": mode, "frame": args.start + index,
                    "wall_ms": value, "root_ms": "", "stages": {},
                })
            print("[%s] %s wall median=%.3f mean=%.3f p95=%.3f" % (
                time.strftime("%H:%M:%S"), label,
                payload["reps"][-1]["wall"].get("median_ms", -1),
                payload["reps"][-1]["wall"].get("mean_ms", -1),
                payload["reps"][-1]["wall"].get("p95_ms", -1)), flush=True)

    # --- 插桩 stage 归属 ------------------------------------------------------
    # 不能按"读日志的时间窗"分 rep：ProfileBatchCollector 是懒 flush（下一帧到来
    # 才写出上一帧），末尾几行会落到下一个读窗里，导致 off 段混进 on 段的 stage
    # （t14 首次运行就踩到：物理已关但 physics.total 仍显示 14 ms）。
    # 改为：所有 rep 跑完后一次性读全量增量，按帧号过滤，按线程取主测量线程，
    # 再按"每 frames 行一组"的顺序切片，与执行顺序一一对应。
    if args.profile_log and os.path.exists(args.profile_log):
        time.sleep(0.4)
        rows, _ = read_profile_lines(args.profile_log, log_offset)
    else:
        rows = []
    expected = set(range(args.start, args.start + args.frames))
    rows = [row for row in rows if int(row.get("frame", -1)) in expected]
    per_thread = {}
    for row in rows:
        per_thread[str(row.get("thread"))] = per_thread.get(str(row.get("thread")), 0) + 1
    main_thread = max(per_thread.items(), key=lambda kv: kv[1])[0] if per_thread else None
    rows = [row for row in rows if str(row.get("thread")) == main_thread]
    payload["profile"] = {
        "rows_total": len(rows),
        "threads": per_thread,
        "main_thread": main_thread,
        "expected_rows": len(payload["reps"]) * args.frames,
    }
    chunks = [rows[i:i + args.frames] for i in range(0, len(rows), args.frames)]
    payload["profile"]["chunks"] = len(chunks)
    for index, rep_payload in enumerate(payload["reps"]):
        if index >= len(chunks):
            rep_payload["profile_frames"] = 0
            rep_payload["profile_note"] = "no_rows_for_this_rep"
            continue
        chunk = chunks[index]
        for row in chunk:
            for stage in row.get("stages") or []:
                if stage.get("name") not in stage_names:
                    stage_names.append(stage.get("name"))
        rep_payload["profile_frames"] = len(chunk)
        rep_payload["stages"] = stage_table(chunk)
        rep_payload["profile_frames_seen"] = [int(row.get("frame", -1)) for row in chunk[:3]]
        for row in chunk:
            csv_rows.append({
                "rep": rep_payload["rep"],
                "mode": rep_payload["mode"],
                "frame": int(row.get("frame", -1)),
                "wall_ms": "",
                "root_ms": row.get("root_ms"),
                "stages": {s.get("name"): s for s in (row.get("stages") or [])},
            })

    # 逐帧 CSV（宽表：wall + 每个 stage 的 inclusive/self）
    header = ["rep", "mode", "frame", "wall_ms", "root_ms"]
    for name in stage_names:
        header += ["%s.inclusive_ms" % name, "%s.self_ms" % name]
    lines = [",".join(header)]
    for row in csv_rows:
        if row["stages"]:
            values = [str(row["rep"]), row["mode"], str(row["frame"]), "", "" if row["root_ms"] is None else "%.4f" % float(row["root_ms"])]
            for name in stage_names:
                stage = row["stages"].get(name) or {}
                values.append("%.4f" % float(stage.get("inclusive_ms") or 0.0))
                values.append("%.4f" % float(stage.get("self_ms") or 0.0))
            lines.append(",".join(values))
        else:
            values = [str(row["rep"]), row["mode"], str(row["frame"]), "%.4f" % float(row["wall_ms"]), ""]
            for _name in stage_names:
                values += ["", ""]
            lines.append(",".join(values))
    os.makedirs(os.path.dirname(args.csv) or ".", exist_ok=True)
    with open(args.csv, "w", encoding="utf-8", newline="") as handle:
        handle.write("\n".join(lines) + "\n")

    payload["csv"] = args.csv
    payload["elapsed_s"] = round(time.time() - started, 1)
    os.makedirs(os.path.dirname(args.out) or ".", exist_ok=True)
    with open(args.out, "w", encoding="utf-8") as handle:
        json.dump(payload, handle, ensure_ascii=False, indent=2)
    print("PROBE_RESULT:" + json.dumps({
        "reps": len(payload["reps"]),
        "modes": modes,
        "wall_medians": [r["wall"].get("median_ms") for r in payload["reps"]],
        "stage_count": len(stage_names),
        "csv": args.csv,
        "out": args.out,
        "elapsed_s": payload["elapsed_s"],
    }, ensure_ascii=False), flush=True)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())

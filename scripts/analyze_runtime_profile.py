"""Summarize CMT schema-1 JSONL without adding nested inclusive durations.

Frame buckets are (session, thread, document, marker, time, frame, fps).
Repeated evaluation at the same time accumulates in the same bucket. These
counts describe instrumented calls, not viewport FPS or rendered frames.
"""
from __future__ import annotations

import argparse
import json
import math
from collections import defaultdict
from pathlib import Path


def summarize(lines, *, frame_min=None, frame_max=None, document=None):
    buckets = {}
    stages = defaultdict(lambda: {"calls": 0, "inclusive_ms": 0.0, "self_ms": 0.0, "max_ms": 0.0})
    documents = defaultdict(set)
    for number, line in enumerate(lines, 1):
        line = line.strip()
        if not line:
            continue
        # Console output can be saved together with other diagnostic lines.
        if "[CMT][Profile] " in line:
            line = line.split("[CMT][Profile] ", 1)[1]
        elif not line.startswith("{"):
            continue
        try:
            record = json.loads(line)
            if not isinstance(record, dict):
                raise ValueError("record must be an object")
            if record.get("schema") != 1:
                raise ValueError("unsupported schema")
            frame = int(record["frame"])
            seconds = float(record["time_seconds"])
            if not math.isfinite(seconds) or int(record["fps"]) < 0 or int(record["root_calls"]) < 0:
                raise ValueError("invalid context or root count")
            if frame_min is not None and frame < frame_min:
                continue
            if frame_max is not None and frame > frame_max:
                continue
            if document is not None and str(record["document"]) != document:
                continue
            key = tuple(record[name] for name in ("session", "thread", "document", "marker", "time_seconds", "frame", "fps"))
            bucket = buckets.setdefault(key, {"root_ms": 0.0, "root_calls": 0, "stages": defaultdict(float)})
            root_ms = float(record["root_ms"])
            if not math.isfinite(root_ms) or root_ms < 0:
                raise ValueError("invalid root duration")
            bucket["root_ms"] += root_ms
            bucket["root_calls"] += int(record["root_calls"])
            documents[(record["session"], record["thread"], record["document"], record["marker"])].add(key)
            for stage in record["stages"]:
                result = stages[stage["name"]]
                calls = int(stage["calls"])
                values = [float(stage[name]) for name in ("inclusive_ms", "self_ms", "max_ms")]
                if not isinstance(stage["name"], str) or calls < 0 or any(not math.isfinite(value) or value < 0 for value in values):
                    raise ValueError("invalid stage statistics")
                result["calls"] += calls
                result["inclusive_ms"] += values[0]
                result["self_ms"] += values[1]
                result["max_ms"] = max(result["max_ms"], values[2])
                bucket["stages"][stage["name"]] += values[1]
        except (ValueError, KeyError, TypeError) as error:
            raise ValueError(f"profile line {number}: {error}") from error
    count = len(buckets)
    ranked = []
    for name, values in stages.items():
        samples = sorted(bucket["stages"].get(name, 0.0) for bucket in buckets.values())
        ranked.append({"name": name, **values,
                       "mean_self_ms_per_bucket": values["self_ms"] / count,
                       "p95_self_ms_per_bucket": samples[math.ceil(count * .95) - 1]})
    ranked.sort(key=lambda stage: stage["self_ms"], reverse=True)
    return {"schema": 1, "buckets": count,
            "root_ms": sum(bucket["root_ms"] for bucket in buckets.values()),
            "root_calls": sum(bucket["root_calls"] for bucket in buckets.values()),
            "contexts": [{"session": key[0], "thread": key[1], "document": key[2], "marker": key[3], "buckets": len(value)}
                         for key, value in documents.items()],
            "stages": ranked}


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("log", type=Path)
    parser.add_argument("--frame-min", type=int)
    parser.add_argument("--frame-max", type=int)
    parser.add_argument("--document")
    parser.add_argument("--json", type=Path, dest="output")
    args = parser.parse_args()
    try:
        with args.log.open(encoding="utf-8-sig") as stream:
            report = summarize(stream, frame_min=args.frame_min, frame_max=args.frame_max, document=args.document)
    except (OSError, ValueError) as error:
        parser.exit(2, f"{error}\n")
    if args.output:
        args.output.write_text(json.dumps(report, indent=2, ensure_ascii=False) + "\n", encoding="utf-8")
    print(f"{report['buckets']} document/time/thread buckets, {report['root_calls']} instrumented roots")
    print("Stage                            Calls     Self ms  Mean/bucket  P95/bucket   Max call")
    for stage in report["stages"]:
        print(f"{stage['name']:32} {stage['calls']:6} {stage['self_ms']:11.3f} "
              f"{stage['mean_self_ms_per_bucket']:12.3f} {stage['p95_self_ms_per_bucket']:11.3f} {stage['max_ms']:10.3f}")


if __name__ == "__main__":
    main()

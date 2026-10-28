#!/usr/bin/env python3
"""P6 诊断埋点（只在隔离 worktree S:\\tmp\\...\\p6-src 内改；产品树零写入）。

加三类日志（env `CMT_ASYNC_STATS_LOG` 门控，未设则完全静默）：
  seed bodies=.. copied=.. skipped=.. ok=.. epoch=..
  step epoch=.. submitted=.. applied=.. produced=.. consumed=.. worker_steps=..
       submit_skipped=.. result_covered=.. stale_dropped=.. in_flight_dropped=.. mismatch=..
  stats final=1 ...（Shutdown 时，含 submit_waited/cancelled）
"""
import sys
from pathlib import Path

TARGET = Path(r"S:\tmp\cmt_vmd_profile_20261019\p6-src\source\module\tools\object\mmd_model_runtime.cpp")

HELPER = '''
#include <cstdio>

namespace {
// t76 诊断：仅当 CMT_ASYNC_STATS_LOG 指向文件时写一行（每次 fopen/append，量级=每帧一行）。
void CmtP6Stats(const char* const line)
{
	const char* const path = std::getenv("CMT_ASYNC_STATS_LOG");
	if (!path || !*path)
		return;
	std::FILE* const file = std::fopen(path, "ab");
	if (!file)
		return;
	std::fputs(line, file);
	std::fputc('\\n', file);
	std::fclose(file);
}
}  // namespace
'''

SEED_BLOCK = '''\t{
\t\tchar buffer[256];
\t\tstd::snprintf(buffer, sizeof(buffer),
\t\t\t"seed bodies=%d copied=%d skipped=%d ok=%d epoch=%lld",
\t\t\tstatic_cast<int>(stats.bodies), static_cast<int>(stats.copied),
\t\t\tstatic_cast<int>(stats.skipped), stats.ok ? 1 : 0,
\t\t\tstatic_cast<long long>(async_physics_epoch_));
\t\tCmtP6Stats(buffer);
\t}
'''

STEP_BLOCK = '''\t{
\t\tconst cmt::physics::PhysicsAsyncPipeline::Counters c = async_physics_pipeline_.GetCounters();
\t\tchar buffer[640];
\t\tstd::snprintf(buffer, sizeof(buffer),
\t\t\t"step epoch=%lld submitted=%llu applied=%llu produced=%llu consumed=%llu worker_steps=%llu"
\t\t\t" submit_skipped=%llu result_covered=%llu stale_dropped=%llu in_flight_dropped=%llu mismatch=%lld",
\t\t\tstatic_cast<long long>(async_physics_epoch_),
\t\t\tstatic_cast<unsigned long long>(c.submitted),
\t\t\tstatic_cast<unsigned long long>(async_applied_frame_),
\t\t\tstatic_cast<unsigned long long>(c.produced),
\t\t\tstatic_cast<unsigned long long>(c.consumed),
\t\t\tstatic_cast<unsigned long long>(c.worker_steps),
\t\t\tstatic_cast<unsigned long long>(c.submit_skipped),
\t\t\tstatic_cast<unsigned long long>(c.result_covered),
\t\t\tstatic_cast<unsigned long long>(c.stale_dropped),
\t\t\tstatic_cast<unsigned long long>(c.in_flight_dropped),
\t\t\tstatic_cast<long long>(async_rigid_identity_mismatch_));
\t\tCmtP6Stats(buffer);
\t}
'''

STATS_BLOCK = '''\t{
\t\tconst cmt::physics::PhysicsAsyncPipeline::Counters c = async_physics_pipeline_.GetCounters();
\t\tchar buffer[640];
\t\tstd::snprintf(buffer, sizeof(buffer),
\t\t\t"stats final=1 epoch=%lld submitted=%llu applied=%llu produced=%llu consumed=%llu worker_steps=%llu"
\t\t\t" submit_skipped=%llu submit_waited=%llu result_covered=%llu stale_dropped=%llu in_flight_dropped=%llu"
\t\t\t" cancelled=%llu mismatch=%lld",
\t\t\tstatic_cast<long long>(async_physics_epoch_),
\t\t\tstatic_cast<unsigned long long>(c.submitted),
\t\t\tstatic_cast<unsigned long long>(async_applied_frame_),
\t\t\tstatic_cast<unsigned long long>(c.produced),
\t\t\tstatic_cast<unsigned long long>(c.consumed),
\t\t\tstatic_cast<unsigned long long>(c.worker_steps),
\t\t\tstatic_cast<unsigned long long>(c.submit_skipped),
\t\t\tstatic_cast<unsigned long long>(c.submit_waited),
\t\t\tstatic_cast<unsigned long long>(c.result_covered),
\t\t\tstatic_cast<unsigned long long>(c.stale_dropped),
\t\t\tstatic_cast<unsigned long long>(c.in_flight_dropped),
\t\t\tstatic_cast<unsigned long long>(c.cancelled),
\t\t\tstatic_cast<long long>(async_rigid_identity_mismatch_));
\t\tCmtP6Stats(buffer);
\t}
'''


def to_nl(block, nl):
    return block.replace("\n", nl) if nl != "\n" else block


def replace_once(text, anchor, insert_after, name):
    count = text.count(anchor)
    if count != 1:
        raise SystemExit("anchor %s count=%d (expected 1)" % (name, count))
    return text.replace(anchor, anchor + insert_after, 1)


def main():
    if not TARGET.exists():
        raise SystemExit("target missing: %s" % TARGET)
    text = TARGET.read_text(encoding="utf-8", newline="")
    nl = "\r\n" if "\r\n" in text else "\n"
    if "CmtP6Stats" in text:
        raise SystemExit("already instrumented")

    text = replace_once(text, '#include "utils/cmt_runtime_profile_c4d.hpp"' + nl,
                        to_nl(HELPER, nl), "include-tail")
    text = replace_once(text, "\tasync_seed_stats_ = stats;" + nl,
                        to_nl(SEED_BLOCK, nl), "seed")

    step_anchor = ("\t// 拒绝（job 在途 / 结果未消费）时不推进帧号：显示值保持上一份结果，滞后增大而不跳帧。" + nl
                   + "}" + nl)
    if text.count(step_anchor) != 1:
        raise SystemExit("step anchor count=%d" % text.count(step_anchor))
    text = text.replace(step_anchor,
                        "\t// 拒绝（job 在途 / 结果未消费）时不推进帧号：显示值保持上一份结果，滞后增大而不跳帧。" + nl
                        + to_nl(STEP_BLOCK, nl) + "}" + nl, 1)

    text = replace_once(text,
                        "void MMDModelManagerObject::ShutdownStandaloneAsyncPhysics()" + nl + "{" + nl,
                        to_nl(STATS_BLOCK, nl), "shutdown")

    TARGET.write_text(text, encoding="utf-8", newline="")
    print("PATCHED %s (%d bytes, nl=%s)" % (TARGET, len(text.encode("utf-8")), "crlf" if nl != "\n" else "lf"))
    for token in ("CmtP6Stats", "step epoch=", "stats final=1", "seed bodies="):
        print("contains %-16s %s" % (token, token in text))


if __name__ == "__main__":
    sys.exit(main())

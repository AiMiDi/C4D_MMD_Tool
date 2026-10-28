#!/usr/bin/env python3
"""P6 诊断埋点（只改隔离 worktree；产品树零写入）。

覆盖 t80 §5 清单：payload_hash / bone_hash / applied / submitted / consumed /
stale_dropped / result_covered / control_state_changed / 每帧主世界物理分发是否二次进入。

env 门控：`CMT_ASYNC_STATS_LOG`（未设则完全静默）。
"""
import sys
from pathlib import Path

ROOT = Path(r"S:\tmp\cmt_vmd_profile_20261019\p6b-src\source\module\tools\object")
RUNTIME = ROOT / "mmd_model_runtime.cpp"
ASYNC = ROOT / "cmt_physics_async.cpp"
MANAGER = ROOT / "mmd_model_manager.cpp"

HELPER = '''
#include <cstdio>
#include <cstdlib>

namespace {
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

FNV_HELPER = '''
namespace {
std::uint64_t CmtP6HashBytes(const void* const data, const std::size_t bytes)
{
	const unsigned char* const p = static_cast<const unsigned char*>(data);
	std::uint64_t h = 1469598103934665603ull;
	for (std::size_t i = 0; i < bytes; ++i)
	{
		h ^= static_cast<std::uint64_t>(p[i]);
		h *= 1099511628211ull;
	}
	return h;
}
}  // namespace
'''


def read(p):
    return p.read_text(encoding="utf-8", newline="")


def nl_of(text):
    return "\r\n" if "\r\n" in text else "\n"


def once(text, anchor, insert, name, after=True):
    n = text.count(anchor)
    if n != 1:
        raise SystemExit("anchor %-22s count=%d" % (name, n))
    return text.replace(anchor, anchor + insert if after else insert + anchor, 1)


def patch_runtime():
    text = read(RUNTIME)
    nl = nl_of(text)
    if "CmtP6Stats" in text:
        print("runtime already instrumented; skip")
        return
    block = (HELPER + FNV_HELPER).replace("\n", nl)

    text = once(text, '#include "utils/cmt_runtime_profile_c4d.hpp"' + nl, block, "runtime:include")

    seed_log = ('''\t{
\t\tchar buffer[256];
\t\tstd::snprintf(buffer, sizeof(buffer), "seed bodies=%d copied=%d skipped=%d ok=%d epoch=%lld",
\t\t\tstatic_cast<int>(stats.bodies), static_cast<int>(stats.copied), static_cast<int>(stats.skipped),
\t\t\tstats.ok ? 1 : 0, static_cast<long long>(async_physics_epoch_));
\t\tCmtP6Stats(buffer);
\t}
''').replace("\n", nl)
    text = once(text, "\tasync_seed_stats_ = stats;" + nl, seed_log, "runtime:seed")

    # 载荷哈希 + 计数（step 尾部）
    step_log = ('''\t{
\t\tstd::uint64_t bone_hash = 0;
\t\tif (!bone_world.empty())
\t\t\tbone_hash = CmtP6HashBytes(bone_world.data(), bone_world.size() * sizeof(bone_world[0]));
\t\tconst cmt::physics::PhysicsAsyncPipeline::Counters c = async_physics_pipeline_.GetCounters();
\t\tchar buffer[768];
\t\tstd::snprintf(buffer, sizeof(buffer),
\t\t\t"step epoch=%lld payload_bones=%zu payload_hash=%016llx submitted=%llu applied=%llu produced=%llu"
\t\t\t" consumed=%llu worker_steps=%llu submit_skipped=%llu result_covered=%llu stale_dropped=%llu"
\t\t\t" in_flight_dropped=%llu mismatch=%lld",
\t\t\tstatic_cast<long long>(async_physics_epoch_), bone_world.size(),
\t\t\tstatic_cast<unsigned long long>(bone_hash),
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
''').replace("\n", nl)
    text = once(text, "\t// 拒绝（job 在途 / 结果未消费）时不推进帧号：显示值保持上一份结果，滞后增大而不跳帧。" + nl,
                step_log + "}", "runtime:step")

    consume_log = ('''\t{
\t\tchar buffer[256];
\t\tstd::snprintf(buffer, sizeof(buffer), "consume result_frame=%llu applied_before=%llu submitted=%llu",
\t\t\tstatic_cast<unsigned long long>(result.frame),
\t\t\tstatic_cast<unsigned long long>(async_applied_frame_),
\t\t\tstatic_cast<unsigned long long>(async_submitted_frame_));
\t\tCmtP6Stats(buffer);
\t}
''').replace("\n", nl)
    anchor_try = "\tif (async_physics_pipeline_.TryConsume(async_physics_epoch_, 0, result))" + nl + "\t\tApplyStandaloneAsyncResult(result);" + nl
    replacement = ("\tif (async_physics_pipeline_.TryConsume(async_physics_epoch_, 0, result))" + nl
                   + "\t{" + nl + consume_log + "\t\tApplyStandaloneAsyncResult(result);" + nl + "\t}" + nl)
    if text.count(anchor_try) != 1:
        raise SystemExit("anchor runtime:consume count=%d" % text.count(anchor_try))
    text = text.replace(anchor_try, replacement, 1)

    stats_log = ('''\t{
\t\tconst cmt::physics::PhysicsAsyncPipeline::Counters c = async_physics_pipeline_.GetCounters();
\t\tchar buffer[768];
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
''').replace("\n", nl)
    text = once(text, "void MMDModelManagerObject::ShutdownStandaloneAsyncPhysics()" + nl + "{" + nl,
                stats_log, "runtime:shutdown")

    RUNTIME.write_text(text, encoding="utf-8", newline="")
    print("patched runtime", len(text.encode("utf-8")))


def patch_async():
    text = read(ASYNC)
    nl = nl_of(text)
    if "CmtP6Stats" in text:
        print("async already instrumented; skip")
        return
    text = once(text, '#include "cmt_physics_async.h"' + nl, HELPER.replace("\n", nl), "async:include")
    wlog = ('''\t\t\t{
\t\t\t\tchar buffer[256];
\t\t\t\tstd::snprintf(buffer, sizeof(buffer), "wstep k=%llu job_frame=%llu epoch=%llu bones=%zu",
\t\t\t\t\tstatic_cast<unsigned long long>(worker_steps_.load(std::memory_order_acquire)),
\t\t\t\t\tstatic_cast<unsigned long long>(job.frame),
\t\t\t\t\tstatic_cast<unsigned long long>(job.epoch),
\t\t\t\t\tjob.bone_world.size());
\t\t\t\tCmtP6Stats(buffer);
\t\t\t}
''').replace("\n", nl)
    text = once(text, "\t\t\t\t++worker_steps_;" + nl, wlog, "async:wstep")
    ASYNC.write_text(text, encoding="utf-8", newline="")
    print("patched async", len(text.encode("utf-8")))


def patch_manager():
    text = read(MANAGER)
    nl = nl_of(text)
    if "CmtP6Stats" in text:
        print("manager already instrumented; skip")
        return
    lines = text.split(nl)
    idx = next(i for i, line in enumerate(lines) if line.startswith("#include "))
    lines.insert(idx + 1, HELPER.replace("\n", nl))
    text = nl.join(lines)

    dispatch_log = ('''\t\t\t{
\t\t\t\tchar buffer[320];
\t\t\t\tconst Float64 doc_seconds = now_time.Get();
\t\t\t\tstd::snprintf(buffer, sizeof(buffer),
\t\t\t\t\t"dispatch doc_seconds=%.6f time_changed=%d reset=%d anim_init=%d phys=%d control_changed=%d morph_changed=%d",
\t\t\t\t\tdoc_seconds, time_changed ? 1 : 0, needs_physics_reset ? 1 : 0,
\t\t\t\t\tis_animation_initialized_ ? 1 : 0, physics_enabled ? 1 : 0,
\t\t\t\t\tcontrol_state_changed ? 1 : 0, bone_morph_state_changed ? 1 : 0);
\t\t\t\tCmtP6Stats(buffer);
\t\t\t}
''').replace("\n", nl)
    text = once(text, "\t\t\tconst Bool physics_enabled = IsPhysicsEnabled(op);" + nl, dispatch_log, "manager:dispatch")
    # 把 log 放在 physics_enabled 之前会引用未定义变量，这里改为紧随其后声明块内使用：
    MANAGER.write_text(text, encoding="utf-8", newline="")
    print("patched manager", len(text.encode("utf-8")))


def main():
    for p in (RUNTIME, ASYNC, MANAGER):
        if not p.exists():
            raise SystemExit("missing %s" % p)
    patch_runtime()
    patch_async()
    patch_manager()
    return 0


if __name__ == "__main__":
    sys.exit(main())


#include "module/core/cmt_old_sdk_stl_preload.h"
#include "cmt_runtime_profile_c4d.hpp"
#if CMT_ENABLE_RUNTIME_PROFILING
#include <atomic>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <mutex>
#include <thread>
#include <vector>
#include "cmt_runtime_profile_bullet.hpp"
#include <LinearMath/btQuickprof.h>

// A retained export lets packaging inspect the actual binary, including reused
// CI artifacts. Runtime environment settings cannot hide an instrumented build.
#if defined(_WIN32)
#define CMT_PROFILE_BUILD_EXPORT __declspec(dllexport)
#else
#define CMT_PROFILE_BUILD_EXPORT __attribute__((visibility("default"), used))
#endif
extern "C" CMT_PROFILE_BUILD_EXPORT const char* CmtRuntimeProfilingBuildMarker()
{
	return "CMT_RUNTIME_PROFILING=1";
}
#undef CMT_PROFILE_BUILD_EXPORT

namespace cmt_runtime
{
namespace
{
	thread_local BulletProfileBridge<> bullet_bridge;
	btEnterProfileZoneFunc* previous_bullet_enter = nullptr;
	btLeaveProfileZoneFunc* previous_bullet_leave = nullptr;
	void EnterBulletZone(const char* name)
	{
		if (previous_bullet_enter) previous_bullet_enter(name);
		bullet_bridge.Enter(name);
	}
	void LeaveBulletZone()
	{
		bullet_bridge.Leave();
		if (previous_bullet_leave) previous_bullet_leave();
	}
	thread_local ProfileContext active_context;
	thread_local bool emitting = false;
	struct PendingBatch { ProfileContext context; FrameMetrics metrics; };
	thread_local std::vector<PendingBatch> deferred_batches;
	bool Enabled()
	{
		static const bool enabled = [] {
			const char* value = std::getenv("CMT_RUNTIME_PROFILE");
			return value && *value && std::strcmp(value, "0") && std::strcmp(value, "false") && std::strcmp(value, "FALSE");
		}();
		return enabled && !emitting;
	}
	void WriteBatch(const ProfileContext& context, const FrameMetrics& metrics)
	{
		// Logging stays out of the measured scopes and cannot recursively profile.
		struct EmissionGuard
		{
			EmissionGuard() { emitting = true; }
			~EmissionGuard() { emitting = false; }
		} guard;
		static const std::uint64_t session = static_cast<std::uint64_t>(std::chrono::steady_clock::now().time_since_epoch().count());
		static std::atomic<std::uint64_t> sequence{0};
		const auto thread = static_cast<std::uint64_t>(std::hash<std::thread::id>{}(std::this_thread::get_id()));
		const auto line = FormatProfileBatch(context, metrics, session, thread, ++sequence);
		static std::mutex output_mutex;
		std::lock_guard<std::mutex> lock(output_mutex);
		static const std::string path = [] {
			const char* value = std::getenv("CMT_PROFILE_LOG");
			return value ? std::string(value) : std::string();
		}();
		bool written = false;
		if (!path.empty())
		{
			std::ofstream file(path, std::ios::app | std::ios::binary);
			if (file) { file << line << '\n'; written = file.good(); }
		}
		if (!written)
			ApplicationOutput("[CMT][Profile] @", String(line.c_str()));
	}
	void Emit(const ProfileContext& context, const FrameMetrics& metrics)
	{
		// A nested document can finish while its caller is still being timed.
		// Defer formatting, locking and I/O until that outermost scope finishes.
		if (detail::active_scope)
			deferred_batches.push_back({context, metrics});
		else
			WriteBatch(context, metrics);
	}
	void DrainDeferred()
	{
		if (detail::active_scope) return;
		for (const auto& batch : deferred_batches) WriteBatch(batch.context, batch.metrics);
		deferred_batches.clear();
	}
	using Collector = ProfileBatchCollector<void (*)(const ProfileContext&, const FrameMetrics&)>;
	Collector& ThreadCollector()
	{
		thread_local Collector collector(&Emit);
		return collector;
	}
}

void InitializeBulletProfiling()
{
	// Register once at plugin startup, before scene evaluation/workers begin.
	// Never swap Bullet's process-global callbacks around individual steps.
	if (!Enabled() || btGetCurrentEnterProfileZoneFunc() == &EnterBulletZone) return;
	previous_bullet_enter = btGetCurrentEnterProfileZoneFunc();
	previous_bullet_leave = btGetCurrentLeaveProfileZoneFunc();
	btSetCustomEnterProfileZoneFunc(&EnterBulletZone);
	btSetCustomLeaveProfileZoneFunc(&LeaveBulletZone);
}

void ShutdownBulletProfiling()
{
	// PluginEnd is after runtime work. Leave another owner's hooks untouched.
	if (btGetCurrentEnterProfileZoneFunc() != &EnterBulletZone ||
		btGetCurrentLeaveProfileZoneFunc() != &LeaveBulletZone) return;
	btSetCustomEnterProfileZoneFunc(previous_bullet_enter);
	btSetCustomLeaveProfileZoneFunc(previous_bullet_leave);
}

ProfileEntry::ProfileEntry(const RuntimeStage stage, const BaseDocument* document)
{
	if (!Enabled()) return;
	context_.document = reinterpret_cast<std::uintptr_t>(document);
	context_.seconds = document ? document->GetTime().Get() : 0.0;
	if (!detail::active_frame_metrics || active_context.document != context_.document || active_context.seconds != context_.seconds)
	{
		if (document)
		{
			UInt32 high = 0, low = 0;
			const_cast<BaseDocument*>(document)->GetMarkerStampEx(&high, &low);
			context_.marker = (static_cast<std::uint64_t>(high) << 32) | low;
			context_.fps = document->GetFps();
			context_.frame = document->GetTime().GetFrame(context_.fps);
		}
		owns_frame_ = true;
		previous_context_ = active_context;
		active_context = context_;
		metrics_.emplace(true);
		frame_.emplace(*metrics_);
	}
	stage_.emplace(stage);
}

ProfileEntry::~ProfileEntry() noexcept
{
	stage_.reset();
	frame_.reset();
	if (!owns_frame_) return;
	active_context = previous_context_;
	// Diagnostics must not let an allocation or stream failure escape into C4D.
	try
	{
		ThreadCollector().Add(context_, *metrics_);
		DrainDeferred();
	}
	catch (...) {}
}

void FlushRuntimeProfile() noexcept
{
	if (!Enabled()) return;
	try { ThreadCollector().Flush(); DrainDeferred(); }
	catch (...) {}
}
} // namespace cmt_runtime
#endif

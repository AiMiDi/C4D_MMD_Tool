#pragma once
#include "cmt_runtime_profile.hpp"
#if CMT_ENABLE_RUNTIME_PROFILING
#include <optional>
#include <c4d.h>
#include "module/core/cmt_marco.h"
#include "cmt_runtime_profile_report.hpp"

namespace cmt_runtime
{
// Function entries include animation parameter callbacks outside ModelExecute.
class ProfileEntry
{
public:
	ProfileEntry(RuntimeStage stage, const BaseDocument* document);
	~ProfileEntry() noexcept;
	ProfileEntry(const ProfileEntry&) = delete;
	ProfileEntry& operator=(const ProfileEntry&) = delete;
private:
	std::optional<FrameMetrics> metrics_;
	ProfileContext context_, previous_context_;
	std::optional<ScopedFrameMetrics> frame_;
	std::optional<ScopedRuntimeStage> stage_;
	bool owns_frame_ = false;
};
void FlushRuntimeProfile() noexcept;
void InitializeBulletProfiling();
void ShutdownBulletProfiling();
}
#define CMT_PROFILE_FUNCTION(stage, document) \
	::cmt_runtime::ProfileEntry CMT_PROFILE_JOIN(cmt_profile_entry_, __COUNTER__)(stage, document)
#define CMT_PROFILE_FLUSH() ::cmt_runtime::FlushRuntimeProfile()
#define CMT_PROFILE_BULLET_INIT() ::cmt_runtime::InitializeBulletProfiling()
#define CMT_PROFILE_BULLET_SHUTDOWN() ::cmt_runtime::ShutdownBulletProfiling()
#else
#define CMT_PROFILE_FUNCTION(stage, document) ((void)0)
#define CMT_PROFILE_FLUSH() ((void)0)
#define CMT_PROFILE_BULLET_INIT() ((void)0)
#define CMT_PROFILE_BULLET_SHUTDOWN() ((void)0)
#endif

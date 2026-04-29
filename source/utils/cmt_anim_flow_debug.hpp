/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & CMT contributors.
Author:			Aimidi
Date:			2026/4/29
File:			cmt_anim_flow_debug.hpp
Description:	Animation/IK/physics flow diagnostic switch.

	Default: disabled (zero overhead beyond a single relaxed atomic load).

	Enable via environment variable:
		CMT_ANIM_FLOW_DEBUG=1     (also accepts non-empty value other than 0/false/FALSE)
		CMT_ANIM_FLOW_BONE=<int>  (optional; if set, only that bone_index logs)

	Output is routed through DebugOutput(maxon::OUTPUT::DIAGNOSTIC, ...) so it
	flows into the same Cinema 4D console pipe as the existing [CMT][Frame N]
	logs and can be redirected with g_consoleSwitch / g_console=true at startup.

**************************************************************************/

#pragma once

#include <atomic>
#include <cstdlib>
#include <cstring>

#include <c4d.h>
#include "module/core/cmt_marco.h"

namespace cmt::debug
{
	namespace detail
	{
		inline bool ParseTruthyEnv(const char* name)
		{
			const char* const value = std::getenv(name);
			if (!value || !*value)
				return false;
			return std::strcmp(value, "0") != 0
				&& std::strcmp(value, "false") != 0
				&& std::strcmp(value, "FALSE") != 0;
		}

		inline Int32 ParseInt32Env(const char* name, const Int32 fallback)
		{
			const char* const value = std::getenv(name);
			if (!value || !*value)
				return fallback;
			return static_cast<Int32>(std::strtol(value, nullptr, 10));
		}
	}

	/**
	 * @brief True iff CMT_ANIM_FLOW_DEBUG is set to a truthy value at process start.
	 *
	 * Cached on first call; subsequent calls are a single relaxed atomic load on most
	 * platforms thanks to the magic-static guard. Safe to call from any thread.
	 */
	inline bool IsAnimationFlowDebugEnabled()
	{
		static const bool kEnabled = detail::ParseTruthyEnv("CMT_ANIM_FLOW_DEBUG");
		return kEnabled;
	}

	/**
	 * @brief Optional bone-index filter; -1 means "log every bone".
	 *
	 * Set via CMT_ANIM_FLOW_BONE=<int>. Useful when zooming in on a single IK chain
	 * end-effector to keep the diagnostic log readable during playback.
	 */
	inline Int32 GetAnimationFlowDebugBoneFilter()
	{
		static const Int32 kFilter = detail::ParseInt32Env("CMT_ANIM_FLOW_BONE", -1);
		return kFilter;
	}

	inline bool ShouldLogAnimationFlow()
	{
		return IsAnimationFlowDebugEnabled();
	}

	inline bool ShouldLogAnimationFlowForBone(const Int32 bone_index)
	{
		if (!IsAnimationFlowDebugEnabled())
			return false;
		const Int32 filter = GetAnimationFlowDebugBoneFilter();
		return filter < 0 || filter == bone_index;
	}
}

// Lightweight macros so the diagnostic call sites stay readable. The argument
// expressions are still evaluated when the switch is off because DebugOutput
// uses the maxon @-placeholder format and we want behavior parity with existing
// [CMT][Frame N] logs; if a hot-path call site needs zero-evaluation guards,
// wrap it in `if (cmt::debug::ShouldLogAnimationFlow()) { ... }` explicitly.
#define CMT_ANIM_FLOW_LOG(fmt, ...)                                            \
	do {                                                                       \
		if (::cmt::debug::ShouldLogAnimationFlow())                            \
			DebugOutput(maxon::OUTPUT::DIAGNOSTIC, fmt, __VA_ARGS__);          \
	} while (0)

#define CMT_ANIM_FLOW_LOG_BONE(bone_index, fmt, ...)                           \
	do {                                                                       \
		if (::cmt::debug::ShouldLogAnimationFlowForBone(bone_index))           \
			DebugOutput(maxon::OUTPUT::DIAGNOSTIC, fmt, __VA_ARGS__);          \
	} while (0)

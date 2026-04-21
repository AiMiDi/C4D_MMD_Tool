#pragma once

#include <string>

namespace cmt_dbg
{
	inline void Log(const char*, const char*, const char*, const std::string&)
	{
		// Intentionally a no-op in normal builds. The call still keeps
		// debug-only values "used" so strict CI builds don't fail on warnings.
	}
}

#pragma once

#include <atomic>
#include <cstdint>

namespace cmt_runtime_identity
{
	// Session-local identities are deliberately absent from HyperFile data. Undo
	// copies retain them, while newly created and reopened definitions get new IDs.
	inline std::uint64_t Next()
	{
		static std::atomic<std::uint64_t> sequence{1};
		return sequence.fetch_add(1, std::memory_order_relaxed);
	}
}

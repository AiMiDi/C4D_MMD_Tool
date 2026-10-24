// Explicit microbenchmark, not a CTest pass/fail threshold or viewport estimate.
#include "utils/cmt_runtime_profile.hpp"
#include <chrono>
#include <cstdint>
#include <iostream>

int main()
{
	using namespace cmt_runtime;
	constexpr std::uint64_t iterations = 1000000;
	volatile std::uint64_t work = 0;
	for (const bool enabled : {false, true})
	{
		FrameMetrics metrics(enabled);
		const auto start = std::chrono::steady_clock::now();
		{
			ScopedFrameMetrics frame(metrics);
			for (std::uint64_t i = 0; i < iterations; ++i)
			{
				CMT_PROFILE_SCOPE(RuntimeStage::ModelExecute);
				{
					CMT_PROFILE_SCOPE(RuntimeStage::BoneAnimation);
					work = work + (i & 1);
				}
			}
		}
		const auto ns = std::chrono::duration<double, std::nano>(std::chrono::steady_clock::now() - start).count();
		std::cout << "macro=" << CMT_ENABLE_RUNTIME_PROFILING << " runtime=" << enabled
			<< " nested_pair_ns=" << ns / iterations << " roots=" << metrics.root_calls << '\n';
	}
	return work == iterations ? 0 : 1;
}

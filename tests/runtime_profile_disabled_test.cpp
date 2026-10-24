#include "utils/cmt_runtime_profile_c4d.hpp"
#include <cstdlib>
#include <iostream>

int main()
{
	// Deliberately undefined symbols: the disabled macros must erase arguments.
	CMT_PROFILE_SCOPE(nonexistent_stage());
	CMT_PROFILE_FUNCTION(nonexistent_stage(), nonexistent_sdk_document());
	CMT_PROFILE_FLUSH();
	cmt_runtime::FrameMetrics metrics(true);
	{
		cmt_runtime::ScopedFrameMetrics frame(metrics);
		cmt_runtime::ScopedRuntimeStage stage(cmt_runtime::RuntimeStage::IK);
	}
	if (metrics.enabled || metrics.root_calls || metrics.Milliseconds(cmt_runtime::RuntimeStage::IK))
		return EXIT_FAILURE;
	std::cout << "compiled-out scopes do not reference arguments or the SDK\n";
}

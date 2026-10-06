#include "utils/cmt_motion_validation.hpp"

#include <cstdlib>
#include <iostream>
#include <limits>

namespace
{
	void Require(const bool condition, const char* message)
	{
		if (!condition)
		{
			std::cerr << message << '\n';
			std::exit(EXIT_FAILURE);
		}
	}
}

int main()
{
	using namespace cmt_motion_validation;
	const double nan = std::numeric_limits<double>::quiet_NaN();
	const double infinity = std::numeric_limits<double>::infinity();
	const auto max_frame = std::numeric_limits<std::int32_t>::max();
	std::int32_t frame = 91;
	Require(!TryAnimationFrame(30, 2.75, frame), "fractional positive VMD offsets must reject for every channel");
	Require(!TryAnimationFrame(30, -0.75, frame), "fractional negative VMD offsets must reject for every channel");
	Require(TryAnimationFrame(30, 2, frame) && frame == 32, "integral offset must translate the exact frame");
	Require(TryAnimationFrame(5, -10, frame) && frame == 0, "negative result must clamp to valid first frame");
	Require(TryAnimationFrame(static_cast<std::uint32_t>(max_frame), 0, frame) && frame == max_frame, "largest representable frame is valid");
	Require(!TryAnimationFrame(static_cast<std::uint32_t>(max_frame), 1, frame), "positive offset overflow must reject");
	Require(!TryAnimationFrame(std::numeric_limits<std::uint32_t>::max(), 0, frame), "unsigned source overflow must reject before narrowing");
	Require(TryAnimationFrame(std::numeric_limits<std::uint32_t>::max(), -2147483648.0, frame) && frame == max_frame, "wide source plus valid negative offset must be combined without premature narrowing");
	Require(!TryAnimationFrame(0, -2147483649.0, frame), "negative offset overflow must reject");
	Require(!TryAnimationFrame(0, nan, frame), "NaN offset must reject");
	Require(!TryAnimationFrame(0, infinity, frame), "infinite offset must reject");
	Require(!IsFrameOffsetValid(1e100), "unrepresentable offset must reject even for empty enabled sections");
	std::uint32_t exported = 91;
	Require(TryExportFrame(max_frame, 0, exported) && exported == static_cast<std::uint32_t>(max_frame), "largest stored frame must export without overflow");
	Require(!TryExportFrame(max_frame, 1, exported), "export positive offset overflow must reject before addition narrows");
	Require(!TryExportFrame(std::numeric_limits<std::int32_t>::min(), -1, exported), "export negative offset overflow must reject");
	Require(TryExportFrame(-5, 10, exported) && exported == 5, "legacy negative track frame plus positive offset must combine safely");
	Require(TryExportFrame(5, -10, exported) && exported == 0, "export negative output must clamp consistently with import");
	Require(!TryExportFrame(30, -0.75, exported), "fractional export offset must reject");
	Require(!TryExportFrame(30, nan, exported), "NaN export offset must reject");
	Require(TryDocumentFrame(1, 24, 30, frame) && frame == 1, "C4D rational time must preserve GetFrame truncation");
	Require(TryDocumentFrame(max_frame, 30, 30, frame) && frame == max_frame, "document max frame boundary must validate before casting");
	Require(!TryDocumentFrame(static_cast<double>(max_frame) + 1, 30, 30, frame), "baked document max above Int32 must reject");
	Require(!TryDocumentFrame(nan, 30, 30, frame), "NaN document time must reject");
	Require(!TryDocumentFrame(1, 0, 30, frame), "invalid rational time denominator must reject");

	Require(IsPositionValid({1.0, -2.0, 3.0}, 8.5), "ordinary scaled vector is valid");
	Require(!IsPositionValid({nan, 0.0, 0.0}, 1.0), "NaN translation must reject");
	Require(!IsPositionValid({0.0, infinity, 0.0}, 1.0), "infinite translation must reject");
	Require(!IsPositionValid({1.0, 2.0, 3.0}, 0.0), "zero scale ratio must reject");
	Require(!IsPositionValid({1.0, 2.0, 3.0}, infinity), "infinite scale ratio must reject");
	Require(!IsPositionValid({static_cast<double>(std::numeric_limits<float>::max()), 0.0, 0.0}, 2.0), "finite translation overflowing stored Float32 after scaling must reject");

	Require(IsQuaternionValid({0.0, 0.0, 0.0, 1.0}), "identity quaternion is valid");
	Require(IsQuaternionValid({1.0, 2.0, 3.0, 4.0}), "nonunit quaternion can be normalized safely");
	Require(IsQuaternionValid({0.0, 0.0, 0.0, static_cast<double>(std::numeric_limits<float>::denorm_min())}), "nonzero float denormal can be normalized in double precision");
	Require(!IsQuaternionValid({0.0, 0.0, 0.0, 0.0}), "zero-norm quaternion must reject");
	Require(!IsQuaternionValid({0.0, nan, 0.0, 1.0}), "NaN quaternion coefficient must reject");
	Require(!IsQuaternionValid({0.0, 0.0, infinity, 1.0}), "infinite quaternion coefficient must reject");
	std::cout << "motion numeric preflight validation regression passed\n";
	return EXIT_SUCCESS;
}

#include "utils/cmt_control_hit_test.hpp"
#include <iostream>
#include <limits>

int main()
{
	using cmt::controls::SegmentDistanceSquared;
	// Real edge proximity is different from testing a spline's bounding box:
	// hovering an empty ring center must not claim the controller.
	const bool passed = SegmentDistanceSquared(50, 3, 0, 0, 100, 0) == 9 &&
		SegmentDistanceSquared(-4, 3, 0, 0, 100, 0) == 25 &&
		SegmentDistanceSquared(104, 3, 0, 0, 100, 0) == 25 &&
		SegmentDistanceSquared(3, 4, 0, 0, 0, 0) == 25 &&
		SegmentDistanceSquared(50, 50, 0, 0, 100, 0) > 36 &&
		SegmentDistanceSquared(50, 50, 0, 100, 100, 0) == 0 &&
		std::isinf(SegmentDistanceSquared(0, 0, 0, 0, std::numeric_limits<double>::quiet_NaN(), 1));
	if (!passed) { std::cerr << "Controller hover geometry failed\n"; return 1; }
	return 0;
}

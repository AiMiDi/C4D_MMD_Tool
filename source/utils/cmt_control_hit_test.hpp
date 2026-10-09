#pragma once

#include <algorithm>
#include <cmath>
#include <limits>

namespace cmt::controls
{
	// Pixels, rather than model units, keep hover tolerance stable while zooming.
	inline double SegmentDistanceSquared(double x, double y, double ax, double ay, double bx, double by)
	{
		if (!std::isfinite(x) || !std::isfinite(y) || !std::isfinite(ax) || !std::isfinite(ay) ||
			!std::isfinite(bx) || !std::isfinite(by))
			return std::numeric_limits<double>::infinity();
		const double dx = bx - ax, dy = by - ay;
		const double length_squared = dx * dx + dy * dy;
		const double t = length_squared > 0.0 ? std::clamp(((x - ax) * dx + (y - ay) * dy) / length_squared, 0.0, 1.0) : 0.0;
		const double offset_x = x - (ax + t * dx), offset_y = y - (ay + t * dy);
		return offset_x * offset_x + offset_y * offset_y;
	}
}

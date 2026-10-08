#pragma once

#include <algorithm>
#include <cmath>
#include <limits>

namespace cmt_material
{
// The same approximation is used by ordinary materials and Morph bindings.
inline double RoughnessFromSpecularPower(const double power)
{
	if (!std::isfinite(power)) return 1.0;
	return std::clamp(std::pow(2.0 / (std::max(power, 0.0) + 2.0), 0.25), 0.0, 1.0);
}

inline bool TrySpecularPowerFromRoughness(const double roughness, double& power)
{
	// Invalid port data must not overwrite the stored MMD base value.
	if (!std::isfinite(roughness) || roughness < 0.0 || roughness > 1.0)
		return false;

	// A perfect mirror has infinite power. PMX stores a Float32, so saturate
	// to its largest finite value before taking a reciprocal or overflowing.
	constexpr double maximum_power = std::numeric_limits<float>::max();
	if (roughness <= RoughnessFromSpecularPower(maximum_power))
	{
		power = maximum_power;
		return true;
	}
	const double squared = roughness * roughness;
	power = std::clamp(2.0 / (squared * squared) - 2.0, 0.0, maximum_power);
	return true;
}
}

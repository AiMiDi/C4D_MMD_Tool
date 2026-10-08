#pragma once

#include <algorithm>

namespace cmt_runtime
{
// Preserve PMX Mul/Add RGBA independently. The sampling operation follows Saba
// 29b8efa8 mmd.frag; native MMD equivalence is still an external acceptance item.
template <class VectorType, class ScalarType>
struct TextureMorphFactors
{
	VectorType multiply_rgb = VectorType(1);
	ScalarType multiply_alpha = ScalarType(1);
	VectorType add_rgb = VectorType(0);
	ScalarType add_alpha = ScalarType(0);

	// Equivalent affine part before saturation, suitable for native node graphs.
	VectorType SampleScale() const { return multiply_rgb * (multiply_alpha * (ScalarType(1) + add_alpha)); }
	VectorType SampleBias() const { return VectorType(ScalarType(1) - multiply_alpha * (ScalarType(1) + add_alpha)); }

	VectorType Apply(const VectorType& sample) const
	{
		const auto channel = [&](const ScalarType value, const ScalarType multiplier, const ScalarType addition)
		{
			const ScalarType multiplied = ScalarType(1) - multiply_alpha + value * multiplier * multiply_alpha;
			const ScalarType adjusted = multiplied + (multiplied - ScalarType(1)) * add_alpha;
			return std::max(ScalarType(0), std::min(ScalarType(1), adjusted)) + addition;
		};
		return VectorType(channel(sample.x, multiply_rgb.x, add_rgb.x),
			channel(sample.y, multiply_rgb.y, add_rgb.y), channel(sample.z, multiply_rgb.z, add_rgb.z));
	}

	// Only pre-binding scene compatibility uses the old, combined coefficient.
	VectorType LegacyColor() const { return multiply_rgb + add_rgb; }
	ScalarType LegacyAlpha() const { return multiply_alpha + add_alpha; }
};
}

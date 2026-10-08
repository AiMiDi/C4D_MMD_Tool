#include "utils/cmt_material_morph_accumulator.hpp"
#include "utils/cmt_texture_morph.hpp"

#include <cmath>
#include <cstdlib>
#include <iostream>

namespace
{
	struct Vector3
	{
		double x, y, z;
		explicit Vector3(const double value) : x(value), y(value), z(value) {}
		Vector3(const double x_, const double y_, const double z_) : x(x_), y(y_), z(z_) {}
		Vector3 operator+(const Vector3& other) const { return {x + other.x, y + other.y, z + other.z}; }
		Vector3 operator*(const double weight) const { return {x * weight, y * weight, z * weight}; }
	};
	using Values = cmt_runtime::MaterialMorphValues<Vector3, double>;
	using TextureFactors = cmt_runtime::TextureMorphFactors<Vector3, double>;
	struct State : Values
	{
		State() : Values(1.0) {}
		TextureFactors texture, sphere_texture, toon_texture;
	};
	struct Offset : Values
	{
		explicit Offset(const bool additive) : Values(additive ? 0.0 : 1.0), op_type(additive ? 1 : 0) {}
		int op_type;
	};
	void Near(const double actual, const double expected, const char* message)
	{
		if (std::abs(actual - expected) > 1e-12)
		{
			std::cerr << message << ": got " << actual << ", expected " << expected << '\n';
			std::exit(EXIT_FAILURE);
		}
	}
}

int main()
{
	State base;
	base.diffuse_rgb = Vector3(0.2, 0.4, 0.6);
	base.diffuse_alpha = 0.8;
	base.specular_power = 20.0;
	Offset multiply(false);
	multiply.diffuse_rgb = Vector3(2.0, 0.5, 1.0);
	multiply.diffuse_alpha = 0.5;
	multiply.specular_power = 0.5;
	multiply.texture_factor_rgb = Vector3(0.5, 2.0, 1.0);
	Offset add(true);
	add.diffuse_rgb = Vector3(0.1, 0.2, 0.3);
	add.diffuse_alpha = 0.1;
	add.specular_power = 8.0;
	add.toon_texture_factor_alpha = 0.4;

	cmt_runtime::MaterialMorphAccumulator<Vector3, double> accumulator;
	accumulator.Apply(multiply, 0.5);
	accumulator.Apply(add, 0.25);
	const auto result = accumulator.Compose(base);
	Near(result.diffuse_rgb.x, 0.325, "multiply plus additive diffuse red");
	Near(result.diffuse_rgb.y, 0.35, "partial multiplier diffuse green");
	Near(result.diffuse_alpha, 0.625, "alpha composition");
	Near(result.specular_power, 17.0, "specular power composition");
	Near(result.texture.multiply_rgb.x, 0.75, "texture multiplication has identity base");
	Near(result.texture.multiply_rgb.y, 1.5, "texture multiply channels independent");
	Near(result.toon_texture.multiply_alpha, 1.0, "toon multiply alpha stays separate");
	Near(result.toon_texture.add_alpha, 0.1, "toon additive alpha stays separate");
	for (int sample = 0; sample < 1000; ++sample)
		Near(accumulator.Compose(base).diffuse_alpha, 0.625, "repeated evaluation must not drift");
	Near(base.diffuse_alpha, 0.8, "base data is immutable");

	cmt_runtime::MaterialMorphAccumulator<Vector3, double> reset;
	reset.Apply(multiply, 0.0);
	reset.Apply(add, 0.0);
	Near(reset.Compose(base).diffuse_alpha, 0.8, "zero strength restores base");
	Near(reset.Compose(base).texture.multiply_rgb.x, 1.0, "zero strength restores texture identity");
	Near(reset.Compose(base).texture.add_alpha, 0.0, "zero strength restores additive identity");

	cmt_runtime::MaterialMorphAccumulator<Vector3, double> reversed;
	reversed.Apply(add, 0.25);
	reversed.Apply(multiply, 0.5);
	Near(reversed.Compose(base).diffuse_alpha, result.diffuse_alpha, "add/multiply bucket order is stable");

	// Reference-operation counterexamples. These are Saba regression cases, not
	// a claim of independently verified native MMD output.
	TextureFactors texture;
	texture.add_rgb = Vector3(.2);
	Near(texture.Apply(Vector3(.25)).x, .45, "add happens after texture sampling, not .25 * 1.2");
	Near(texture.Apply(Vector3(0)).x, .2, "additive morph can brighten a black texel");
	texture.multiply_alpha = 0.;
	Near(texture.Apply(Vector3(.25)).x, 1.2, "multiply alpha zero mixes to white, not transparent");
	texture = TextureFactors{};
	texture.add_alpha = 1.;
	Near(texture.Apply(Vector3(.8)).x, .6, "additive alpha adjusts sampled RGB");
	Near(texture.Apply(Vector3(.2)).x, 0., "additive alpha clamps RGB below zero");
	texture.add_rgb = Vector3(.3);
	Near(texture.Apply(Vector3(2.)).x, 1.3, "saturate before adding RGB, no final clamp");

	// Same old combined factor, different correct sampling: the runtime must
	// not discard the Mul/Add distinction, including sphere and toon channels.
	Offset texture_add(true), texture_mul(false);
	texture_add.texture_factor_rgb = texture_add.sphere_texture_factor_rgb = texture_add.toon_texture_factor_rgb = Vector3(.2);
	texture_mul.texture_factor_rgb = Vector3(1.2);
	cmt_runtime::MaterialMorphAccumulator<Vector3, double> add_only, mul_only;
	add_only.Apply(texture_add, 1.); mul_only.Apply(texture_mul, 1.);
	const auto added = add_only.Compose(base);
	Near(added.texture.Apply(Vector3(.25)).x, .45, "additive state is not folded into multiplication");
	Near(mul_only.Compose(base).texture.Apply(Vector3(.25)).x, .3, "multiplicative state remains distinct");
	Near(added.sphere_texture.Apply(Vector3(.25)).x, .45, "sphere preserves separate operations");
	Near(added.toon_texture.Apply(Vector3(.25)).x, .45, "toon preserves separate operations");
	texture_add.texture_factor_alpha = 2.;
	add_only.Apply(texture_add, .5);
	Near(add_only.Compose(base).diffuse_alpha, base.diffuse_alpha, "texture alpha does not change diffuse opacity");

	// The RS fixed graph uses affine coefficients before its saturation node.
	// Compare that representation with the direct two-stage sampling operation
	// across HDR samples, extrapolated alphas, negative additions and RGB channels.
	for (double ma : {-0.5, 0., .25, 1., 2.})
		for (double aa : {-1.5, -1., 0., .5, 2.})
			for (double sample : {-.2, 0., .25, .8, 1., 2.})
			{
				texture.multiply_rgb = Vector3(.5, 1.5, -.25);
				texture.multiply_alpha = ma; texture.add_alpha = aa;
				texture.add_rgb = Vector3(.2, -.1, .4);
				const auto scale = texture.SampleScale(); const auto bias = texture.SampleBias();
				const auto output = texture.Apply(Vector3(sample));
				const auto node = [&](double m, double b, double a) { return std::max(0., std::min(1., sample * m + b)) + a; };
				Near(output.x, node(scale.x, bias.x, texture.add_rgb.x), "RS graph/direct red equivalence");
				Near(output.y, node(scale.y, bias.y, texture.add_rgb.y), "RS graph/direct green equivalence");
				Near(output.z, node(scale.z, bias.z, texture.add_rgb.z), "RS graph/direct blue equivalence");
			}

	std::cout << "material morph composition regression passed\n";
	return EXIT_SUCCESS;
}

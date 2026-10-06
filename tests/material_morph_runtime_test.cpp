#include "utils/cmt_material_morph_accumulator.hpp"

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
	Values base(1.0);
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
	Near(result.texture_factor_rgb.x, 0.75, "texture factor has identity base");
	Near(result.texture_factor_rgb.y, 1.5, "texture factor channels independent");
	Near(result.toon_texture_factor_alpha, 1.1, "toon alpha factor independent");
	for (int sample = 0; sample < 1000; ++sample)
		Near(accumulator.Compose(base).diffuse_alpha, 0.625, "repeated evaluation must not drift");
	Near(base.diffuse_alpha, 0.8, "base data is immutable");

	cmt_runtime::MaterialMorphAccumulator<Vector3, double> reset;
	reset.Apply(multiply, 0.0);
	reset.Apply(add, 0.0);
	Near(reset.Compose(base).diffuse_alpha, 0.8, "zero strength restores base");
	Near(reset.Compose(base).texture_factor_rgb.x, 1.0, "zero strength restores texture identity");

	cmt_runtime::MaterialMorphAccumulator<Vector3, double> reversed;
	reversed.Apply(add, 0.25);
	reversed.Apply(multiply, 0.5);
	Near(reversed.Compose(base).diffuse_alpha, result.diffuse_alpha, "add/multiply bucket order is stable");

	std::cout << "material morph composition regression passed\n";
	return EXIT_SUCCESS;
}

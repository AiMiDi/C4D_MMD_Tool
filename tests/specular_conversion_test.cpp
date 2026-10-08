#include "utils/cmt_specular_conversion.hpp"
#include <cstdlib>
#include <iostream>

namespace
{
void Check(const bool condition, const char* message)
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
	using namespace cmt_material;
	for (const double original : {0.0, 0.25, 1.0, 10.0, 30.0, 128.0, 10000.0,
		static_cast<double>(std::numeric_limits<float>::max())})
	{
		double restored = -1.0;
		Check(TrySpecularPowerFromRoughness(RoughnessFromSpecularPower(original), restored),
			"Finite nonnegative power must round-trip");
		Check(std::abs(restored - original) <= 1e-12 * std::max(1.0, original),
			"Power changed across material creation and reverse synchronization");
	}
	double power = 123.0;
	Check(TrySpecularPowerFromRoughness(0.5, power) && power == 30.0, "Half roughness must mean power 30");
	Check(TrySpecularPowerFromRoughness(0.25, power) && power == 510.0, "Quarter roughness must mean power 510");
	Check(TrySpecularPowerFromRoughness(1.0, power) && power == 0.0, "Full roughness must mean power zero");
	for (const double roughness : {0.0, 1e-200})
		Check(TrySpecularPowerFromRoughness(roughness, power)
			&& power == std::numeric_limits<float>::max(), "Mirror power must remain finite in PMX");
	for (const double invalid : {-0.1, 1.1, std::numeric_limits<double>::infinity(),
		std::numeric_limits<double>::quiet_NaN()})
	{
		power = 123.0;
		Check(!TrySpecularPowerFromRoughness(invalid, power) && power == 123.0,
			"Invalid roughness must preserve the previous power");
	}
	Check(RoughnessFromSpecularPower(-1.0) == 1.0, "Negative power must use neutral roughness");
	Check(RoughnessFromSpecularPower(std::numeric_limits<double>::infinity()) == 1.0,
		"Invalid power must use neutral roughness");
	std::cout << "Specular conversion round-trip and boundary tests passed\n";
}

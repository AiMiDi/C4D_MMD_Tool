#include "utils/cmt_morph_evaluation.hpp"
#include <cstdlib>
#include <iostream>

namespace
{
void Check(bool condition, const char* message)
{
	if (!condition) { std::cerr << message << '\n'; std::exit(EXIT_FAILURE); }
}
void Near(double actual, double expected)
{
	Check(std::abs(actual - expected) < 1e-12, "Unexpected effective weight");
}
}

int main()
{
	using namespace cmt_runtime;
	std::vector<MorphNode> nodes(4);
	nodes[0] = {MorphKind::Group, {{1, .5}, {2, 1.0}}};
	nodes[1] = {MorphKind::Group, {{3, 2.0}}};
	nodes[2] = {MorphKind::Flip, {{3, .25}}};
	const std::vector<double> input{.8, .2, 0.0, .1};
	auto result = ExpandMorphWeights(nodes, input);
	Near(result.values[3], 1.55);
	Check(!result.cyclic && !result.invalid, "Valid diamond rejected");
	nodes[1].children.push_back({0, .5});
	result = ExpandMorphWeights(nodes, {.8, 0.0, 0.0, .1});
	Check(result.cyclic, "Cycle not detected");
	Near(result.values[3], 1.15);
	nodes[1].children.push_back({99, 1.0});
	Check(ExpandMorphWeights(nodes, input).invalid, "Invalid reference not detected");
	for (int i = 0; i < 1000; ++i)
		Near(ExpandMorphWeights(nodes, {0.0, 0.0, 0.0, .3}).values[3], .3);
	Near(MaterialRoughness(0), 1.0);
	Near(MaterialRoughness(30), .5);
	Check(MaterialRoughness(128) < MaterialRoughness(30), "Higher power must narrow highlights");
	std::cout << "Morph graph and roughness tests passed\n";
}

#pragma once

#include "cmt_specular_conversion.hpp"

#include <algorithm>
#include <cmath>
#include <cstddef>
#include <utility>
#include <vector>

namespace cmt_runtime
{
enum class MorphKind { Leaf, Group, Flip };

struct MorphNode
{
	MorphKind kind = MorphKind::Leaf;
	std::vector<std::pair<std::size_t, double>> children;
};

struct MorphWeights
{
	std::vector<double> values;
	bool cyclic = false;
	bool invalid = false;
};

// Expand each input independently. A path-local cycle guard preserves shared
// descendants and contributions from multiple parents without infinite walks.
inline MorphWeights ExpandMorphWeights(const std::vector<MorphNode>& nodes, const std::vector<double>& input)
{
	MorphWeights result;
	result.values.resize(nodes.size(), 0.0);
	std::vector<bool> path(nodes.size(), false);
	struct Visit { std::size_t index; double weight; bool leave; };
	std::vector<Visit> stack;
	for (std::size_t root = 0; root < input.size() && root < nodes.size(); ++root)
	{
		stack.push_back({root, input[root], false});
		while (!stack.empty())
		{
			const Visit visit = stack.back();
			stack.pop_back();
			if (visit.index >= nodes.size() || !std::isfinite(visit.weight))
			{
				result.invalid = true;
				continue;
			}
			if (visit.leave) { path[visit.index] = false; continue; }
			if (visit.weight == 0.0) continue;
			if (path[visit.index]) { result.cyclic = true; continue; }
			const auto& node = nodes[visit.index];
			if (node.kind == MorphKind::Leaf)
			{
				const double total = result.values[visit.index] + visit.weight;
				if (std::isfinite(total)) result.values[visit.index] = total;
				else result.invalid = true;
				continue;
			}
			const double weight = node.kind == MorphKind::Flip ? (visit.weight >= 0.5 ? 1.0 : 0.0) : visit.weight;
			if (weight == 0.0) continue;
			path[visit.index] = true;
			stack.push_back({visit.index, 0.0, true});
			for (auto child = node.children.rbegin(); child != node.children.rend(); ++child)
				stack.push_back({child->first, weight * child->second, false});
		}
	}
	return result;
}

inline double MaterialRoughness(const double power)
{
	return cmt_material::RoughnessFromSpecularPower(power);
}
}

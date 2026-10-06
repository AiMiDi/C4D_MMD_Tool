#pragma once

#include <cstdint>
#include <iterator>
#include <map>
#include <string>

// Names, rather than transient C4D DescIDs or runtime solver indices, identify
// IK channels. Keeping sparse channels also retains unknown IK names on export.
namespace mmd_model_info
{

using StepKeys = std::map<std::int32_t, bool>;

struct AnimationSlot
{
	StepKeys visibility;
	std::map<std::string, StepKeys> ik_channels;
	std::map<std::string, bool> ik_defaults;
};

inline bool Evaluate(const StepKeys& keys, const std::int32_t frame, const bool fallback)
{
	const auto next = keys.upper_bound(frame);
	return next == keys.begin() ? fallback : std::prev(next)->second;
}

inline bool EvaluateIK(const AnimationSlot& slot, const std::string& name, const std::int32_t frame, const bool fallback)
{
	const auto default_it = slot.ik_defaults.find(name);
	const bool initial = default_it == slot.ik_defaults.end() ? fallback : default_it->second;
	const auto channel = slot.ik_channels.find(name);
	return channel == slot.ik_channels.end() ? initial : Evaluate(channel->second, frame, initial);
}

}

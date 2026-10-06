#pragma once

#include <algorithm>
#include <array>
#include <cstdint>
#include <map>
#include <tuple>
#include <vector>

namespace cmt_runtime
{

// Contains only parameters that affect playback ordering or phase membership.
// Scene pointers and per-frame transforms deliberately stay outside this cache.
struct BoneExecutionEntry
{
	std::int32_t index = -1;
	std::int32_t layer = 0;
	std::int32_t append_depth = 0;
	bool after_physics = false;
	bool is_ik = false;

	bool operator==(const BoneExecutionEntry& other) const
	{
		return std::tie(index, layer, append_depth, after_physics, is_ik)
			== std::tie(other.index, other.layer, other.append_depth, other.after_physics, other.is_ik);
	}
};

class BoneExecutionPlan
{
public:
	void Invalidate() { dirty_ = true; }
	bool IsDirty() const { return dirty_; }

	// The caller reuses a scratch snapshot. An unchanged scene performs no sort
	// or allocation here; direct parameter writes are detected by the comparison.
	bool Update(const std::vector<BoneExecutionEntry>& entries)
	{
		if (!dirty_ && entries == snapshot_)
			return false;

		snapshot_ = entries;
		std::vector<BoneExecutionEntry> ordered = entries;
		for (auto& entry : ordered)
			entry.layer = std::max<std::int32_t>(0, entry.layer);
		std::sort(ordered.begin(), ordered.end(), [](const BoneExecutionEntry& lhs, const BoneExecutionEntry& rhs)
		{
			return std::tie(lhs.layer, lhs.append_depth, lhs.index)
				< std::tie(rhs.layer, rhs.append_depth, rhs.index);
		});

		bone_indices_.clear();
		layers_.clear();
		groups_.clear();
		bone_indices_.reserve(ordered.size());
		for (const auto& entry : ordered)
		{
			if (entry.index < 0)
				continue;
			const std::int32_t layer = std::max<std::int32_t>(0, entry.layer);
			bone_indices_.push_back(entry.index);
			auto& group = groups_[layer];
			const std::size_t phase = entry.after_physics ? 1 : 0;
			group.bones[phase].push_back(entry.index);
			if (entry.is_ik)
				group.ik_bones[phase].push_back(entry.index);
		}

		for (auto& pair : groups_)
		{
			layers_.push_back(pair.first);
			// The existing IK contract orders solver controllers by PMX index,
			// independently of append depth used by the animation bone pass.
			for (auto& indices : pair.second.ik_bones)
				std::sort(indices.begin(), indices.end());
		}
		dirty_ = false;
		++rebuild_count_;
		return true;
	}

	const std::vector<std::int32_t>& BoneIndices() const { return bone_indices_; }
	const std::vector<std::int32_t>& Layers() const { return layers_; }
	std::uint64_t RebuildCount() const { return rebuild_count_; }

	const std::vector<std::int32_t>& BonesForLayer(const std::int32_t layer, const bool after_physics) const
	{
		const auto found = groups_.find(layer);
		return found == groups_.end() ? empty_ : found->second.bones[after_physics ? 1 : 0];
	}

	const std::vector<std::int32_t>& IKBonesForLayer(const std::int32_t layer, const bool after_physics) const
	{
		const auto found = groups_.find(layer);
		return found == groups_.end() ? empty_ : found->second.ik_bones[after_physics ? 1 : 0];
	}

private:
	struct LayerGroup
	{
		std::array<std::vector<std::int32_t>, 2> bones;
		std::array<std::vector<std::int32_t>, 2> ik_bones;
	};

	bool dirty_ = true;
	std::uint64_t rebuild_count_ = 0;
	std::vector<BoneExecutionEntry> snapshot_;
	std::vector<std::int32_t> bone_indices_;
	std::vector<std::int32_t> layers_;
	std::map<std::int32_t, LayerGroup> groups_;
	std::vector<std::int32_t> empty_;
};

} // namespace cmt_runtime

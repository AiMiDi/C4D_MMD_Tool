#ifndef CMT_PHYSICS_SHADOW_H
#define CMT_PHYSICS_SHADOW_H

//! P2 影子骨骼节点：Bullet 世界只面对这一套纯 Eigen 的 libmmd::IMMDNode 实现。
//!
//! 并发正确性的前提是**物理线程不触碰任何 C4D 对象**：
//! 主线程在 pre-physics 相位把骨骼世界矩阵拷进来，worker 只读写这里的 Eigen 矩阵；
//! 结果槽里再拷出去，主线程下一帧消费时写回 C4D。
//!
//! 这里刻意不引用 c4d_baselist.h / C4DIKChainNodeAdapter：本文件可以被无头夹具直编。

#include <cstddef>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include <Eigen/Geometry>

#include "libMMD/Model/MMD/IMMDNode.h"

namespace cmt
{
	namespace physics
	{
		//! 单根骨骼的影子节点。语义等价于 MMDNode 的「全局/局部/初始」三套矩阵，
		//! 但不含任何父子链更新逻辑：世界矩阵完全由主线程拷入、由物理线程读改写。
		class ShadowBoneNode final : public libmmd::IMMDNode
		{
		public:
			explicit ShadowBoneNode(std::int32_t bone_index)
				: name_("shadow#" + std::to_string(bone_index))
			{
				global_.setIdentity();
				initial_.setIdentity();
				local_.setIdentity();
				ik_rotate_.setIdentity();
			}

			const std::string& GetName() const override { return name_; }

			void SetGlobalTransform(const Eigen::Matrix4f& m) override { global_ = m; }
			const Eigen::Matrix4f& GetGlobalTransform() const override { return global_; }
			const Eigen::Matrix4f& GetInitialGlobalTransform() const override { return initial_; }

			const Eigen::Matrix4f& GetLocalTransform() const override { return local_; }

			void SetIKRotate(const Eigen::Quaternionf& ikr) override { ik_rotate_ = ikr; }
			const Eigen::Quaternionf& GetIKRotate() const override { return ik_rotate_; }
			Eigen::Quaternionf AnimateRotate() const override { return ik_rotate_; }

			//! 影子节点不做父子链推导：主线程每次都会整套覆盖世界矩阵。
			void UpdateLocalTransform() override {}
			void UpdateGlobalTransform() override {}

			libmmd::IMMDNode* GetParent() const override { return nullptr; }

			void SetInitialGlobalTransform(const Eigen::Matrix4f& m) { initial_ = m; }
			void SetLocalTransform(const Eigen::Matrix4f& m) { local_ = m; }

		private:
			std::string name_;
			Eigen::Matrix4f global_;
			Eigen::Matrix4f initial_;
			Eigen::Matrix4f local_;
			Eigen::Quaternionf ik_rotate_;
		};

		//! 625 根骨骼的影子集合：索引即骨骼下标（与 C4D bone_list_ 顺序一致）。
		class ShadowBoneSet
		{
		public:
			void Resize(const std::size_t count)
			{
				nodes_.clear();
				nodes_.reserve(count);
				for (std::size_t i = 0; i < count; ++i)
					nodes_.push_back(std::make_unique<ShadowBoneNode>(static_cast<std::int32_t>(i)));
			}

			std::size_t Count() const { return nodes_.size(); }

			ShadowBoneNode* Node(const std::int32_t bone_index) const
			{
				if (bone_index < 0 || static_cast<std::size_t>(bone_index) >= nodes_.size())
					return nullptr;
				return nodes_[static_cast<std::size_t>(bone_index)].get();
			}

			libmmd::IMMDNode* MmdNode(const std::int32_t bone_index) const
			{
				return Node(bone_index);
			}

			//! 主线程 → 影子：整套覆盖世界矩阵。越界下标直接忽略（保持旧值）。
			void CaptureWorldMatrices(const std::vector<Eigen::Matrix4f>& world)
			{
				const std::size_t n = world.size() < nodes_.size() ? world.size() : nodes_.size();
				for (std::size_t i = 0; i < n; ++i)
					nodes_[i]->SetGlobalTransform(world[i]);
			}

			//! 影子 → 结果槽：整套拷出世界矩阵。
			void SnapshotWorldMatrices(std::vector<Eigen::Matrix4f>& out) const
			{
				out.resize(nodes_.size());
				for (std::size_t i = 0; i < nodes_.size(); ++i)
					out[i] = nodes_[i]->GetGlobalTransform();
			}

		private:
			std::vector<std::unique_ptr<ShadowBoneNode>> nodes_;
		};
	}
}

#endif // CMT_PHYSICS_SHADOW_H

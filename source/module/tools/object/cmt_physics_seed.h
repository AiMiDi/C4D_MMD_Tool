#pragma once
// P6：影子世界种子化。
//
// 问题（真机 t73/t74 实测）：`StartStandaloneAsyncPhysics()` 里影子刚体是刚按 PMX 定义
// 新建的，随后只做了 `ResetTransform()`（读到的是影子骨骼节点当时的状态）。而主世界此刻
// 可能已经被 `ResetStandalonePhysics()` 复位到**当前帧真实姿态**（mmd_model_runtime.cpp
// 的 1339–1346：ResetTransform/Reset/SetActivation 三连）。两者起点不同：
//   - 主世界：第 539 帧真实姿态 → 第一步 1.8 mm
//   - 影子：PMX 绑定姿态 → 第一次 SyncBonePositionToPhysics 把刚体拽去真实姿态，
//     速度 = (目标 - 当前位置)/dt ≈ 2.9 m/s → 第一步 97.168 mm（54×）
// 之后每帧 1.4–1.7×、总位移比 2.751×，永不收敛。
//
// 修法：影子世界在**首次 Start** 与**每次世界重建**时，从主世界当前真实刚体状态逐项
// 种子化，而不是从绑定变换冷启动。状态清单（缺一不可，夹具逐项证伪）：
//   1. 世界变换 btTransform（同时写 world/centerOfMass/interpolation）
//   2. 线速度 btVector3（同时写 interpolation 线速度）
//   3. 角速度 btVector3（同时写 interpolation 角速度）
//   4. 激活态（activation state + deactivation time）
// 另清空累加外力，避免把主世界上一帧的残余力带进影子第一步。

#include <cstddef>

#include "libMMD/Model/MMD/MMDPhysics.h"
#include <btBulletDynamicsCommon.h>

// R20 的 Maxon Source Processor 不认识 C++17 嵌套命名空间简写，必须用经典嵌套写法。
namespace cmt
{
	namespace physics
	{

struct RigidSeedStats
{
	std::size_t bodies = 0;   // 两侧刚体表大小（应当相等）
	std::size_t copied = 0;   // 实际复制成功的刚体数
	std::size_t skipped = 0;  // 因缺少 btRigidBody 而跳过的数量
	bool ok = false;          // 数量一致且没有跳过才算成功（fail-closed）
};

// 字段掩码：每个字段都能被单独关掉，用于「逐项证伪」——缺任何一项都必须让等价性变红。
struct SeedFieldMask
{
	bool transform = true;     // worldTransform / centerOfMassTransform / interpolationWorldTransform
	bool velocities = true;    // 线速度 / 角速度 / 插值速度
	bool activation = true;    // 激活态 / 去激活时间
	bool aux = true;           // 命中比例（摩擦/回弹/阻尼来自 PMX Config，两侧 Configure 同源，不在此复制）
	bool motion_state = true;  // motion state 缓存（Bullet 用它回写骨骼）
};

// 单个刚体：把 source 的当前物理状态逐项写到 target（mask 决定哪些字段参与）。
inline void SeedOneRigidBodyState(btRigidBody& target, const btRigidBody& source,
	const SeedFieldMask& mask = SeedFieldMask{})
{
	if (mask.transform)
	{
		target.setWorldTransform(source.getWorldTransform());
		target.setCenterOfMassTransform(source.getCenterOfMassTransform());
		target.setInterpolationWorldTransform(source.getInterpolationWorldTransform());
	}

	if (mask.velocities)
	{
		const btVector3 linear = source.getLinearVelocity();
		const btVector3 angular = source.getAngularVelocity();
		target.setLinearVelocity(linear);
		target.setAngularVelocity(angular);
		target.setInterpolationLinearVelocity(linear);
		target.setInterpolationAngularVelocity(angular);
	}

	target.clearForces();

	if (mask.activation)
	{
		target.setActivationState(source.getActivationState());
		target.setDeactivationTime(source.getDeactivationTime());
	}
	if (mask.aux)
	{
		target.setHitFraction(source.getHitFraction());
	}
	if (mask.motion_state)
	{
		if (btMotionState* const motion = target.getMotionState())
			motion->setWorldTransform(source.getWorldTransform());
	}
}

// 全量种子化：shadow_bodies[i] <- main_bodies[i]。
// 两侧数量不一致直接判失败（不允许按下标错写；调用方必须据此拒绝启动异步档）。
template <typename BodyPtrContainer>
inline RigidSeedStats SeedWorldFromMain(const BodyPtrContainer& shadow_bodies,
	const BodyPtrContainer& main_bodies, const SeedFieldMask& mask = SeedFieldMask{})
{
	RigidSeedStats stats;
	stats.bodies = shadow_bodies.size();
	if (shadow_bodies.size() != main_bodies.size())
	{
		stats.skipped = shadow_bodies.size();
		return stats;
	}

	for (std::size_t index = 0; index < shadow_bodies.size(); ++index)
	{
		const auto& shadow = shadow_bodies[index];
		const auto& main = main_bodies[index];
		if (!shadow || !main)
		{
			++stats.skipped;
			continue;
		}
		btRigidBody* const target = shadow->GetRigidBody();
		const btRigidBody* const source = main->GetRigidBody();
		if (!target || !source)
		{
			++stats.skipped;
			continue;
		}
		SeedOneRigidBodyState(*target, *source, mask);
		++stats.copied;
	}

	stats.ok = (stats.skipped == 0 && stats.copied == stats.bodies);
	return stats;
}

	}
} // namespace cmt::physics

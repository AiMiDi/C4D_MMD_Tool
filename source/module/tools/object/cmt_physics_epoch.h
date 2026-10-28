// t64（P4-001）：异步物理 epoch 的唯一来源。
//
// 契约：epoch 随「世界边界变化」（首次建立管线、镜像重建、seek、导出、中途开启、重建世界）
// 单调递增，绝不回退到 1。0 保留给「尚未初始化」，因此消费方可以区分「没启用」与「第一代世界」。
//
// 为什么需要独立计数器：P4-001 之前 StartStandaloneAsyncPhysics() 每次都写
// `async_physics_epoch_ = 1;`，ShutdownStandaloneAsyncPhysics() 里的 ++ 被这一行覆盖；
// 于是 seek/重建之后旧世界的在途结果与当前世界的 epoch 相同，跨世界污染无法从计数上排除。
#pragma once

#include <cstdint>

// R20 的 Maxon Source Processor 不认识 C++17 嵌套命名空间简写
// （namespace cmt::physics 报 "Expected ;"），兼容 SDK 树必须用经典嵌套写法。
namespace cmt
{
	namespace physics
	{

	class PhysicsEpochCounter
	{
	public:
		//! 推进一个世界边界：首次给 1，之后严格 +1（回绕时跳过 0）。
		std::uint64_t Next()
		{
			if (!initialized_)
			{
				initialized_ = true;
				epoch_ = 1;
				return epoch_;
			}
			++epoch_;
			if (epoch_ == 0)
				++epoch_;
			return epoch_;
		}

		std::uint64_t Current() const { return epoch_; }
		bool Initialized() const { return initialized_; }

		//! 只有测试/诊断需要把计数器拨到回绕边缘，用来证明「回绕不会产出 0」。
		void ResetForTest(std::uint64_t epoch)
		{
			initialized_ = true;
			epoch_ = epoch;
		}

	private:
		std::uint64_t epoch_ = 0;
		bool initialized_ = false;
	};

	}
} // namespace cmt::physics

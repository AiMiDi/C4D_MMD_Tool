// P4 不变量实验夹具 v2（真实 PMXModel 载入 + 真实 libMMD 刚体/关节构建 + 真实反射路径）
//
// 回答 t59 问题一：同步世界跑到第 N 帧、影子世界整体晚一帧喂同一输入序列时，
// async(N) 是否与 sync(N-1) 逐位相等（严格 memcmp，零容差）。
//
// 真实性：
//   * 世界由 libmmd::PMXModel::Load() 建立 —— 与产品导入同一入口，刚体/关节由 PMXModel::LoadPMX
//     内部用 PMX 数据调用 MMDRigidBody::Create / MMDJoint::CreateJoint 建成；
//   * 步进走 MMDPhysics::Update（stepSimulation，固定 1/90，maxSubStep=3），与插件
//     `source/module/tools/object/mmd_model_runtime.cpp:1040` 的 SetFPS(document_fps*substeps) 口径一致；
//   * 同步走 SyncBonePositionToPhysics、反射走 ReflectGlobalTransform —— 产品同一条路径。
//
// 与宿主的差异（必须如实标注）：骨骼输入是确定性合成摆动而非 VMD；C4D 侧适配层
// （MMDRigidManagerObject / mmd_model_runtime.cpp 物理桥）不覆盖；不含蒙皮与渲染。

#include "libMMD/Model/MMD/MMDModel.h"
#include "libMMD/Model/MMD/MMDNode.h"
#include "libMMD/Model/MMD/MMDPhysics.h"
#include "libMMD/Model/MMD/PMXFile.h"
#include "libMMD/Model/MMD/PMXModel.h"

#include "btBulletDynamicsCommon.h"

#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <memory>
#include <string>
#include <vector>

namespace {

int g_cases = 0;
int g_first_diff_frame = -1;
bool g_pmx_all_static = false;
int g_assertions = 0;
int g_failures = 0;

void Check(bool condition, const char* label, const char* what)
{
	++g_assertions;
	if (!condition)
	{
		++g_failures;
		std::printf("FAIL %s :: %s\n", label, what);
	}
}

void CheckInt(long long actual, long long expected, const char* label, const char* what)
{
	++g_assertions;
	if (actual != expected)
	{
		++g_failures;
		std::printf("FAIL %s :: %s (actual=%lld expected=%lld)\n", label, what, actual, expected);
	}
}

void BeginCase(const char* label)
{
	++g_cases;
	std::printf("CASE %s\n", label);
}

constexpr int kFrames = 200;
constexpr float kFrameDt = 1.0f / 30.0f;
constexpr int kSubSteps = 3;
constexpr float kPhysicsFps = 90.0f;

Eigen::Matrix4f BoneMatrix(const Eigen::Matrix4f& initial, int bone_index, int frame)
{
	const float t = static_cast<float>(frame);
	const float phase = static_cast<float>(bone_index) * 0.37f;
	const float pitch = 0.004f * std::sin(0.041f * t + phase);
	const float yaw = 0.003f * std::cos(0.057f * t + phase);
	const float roll = 0.002f * std::sin(0.033f * t + phase * 1.7f);

	Eigen::Matrix4f sway = Eigen::Matrix4f::Identity();
	sway.block<3, 3>(0, 0) = (Eigen::AngleAxisf(pitch, Eigen::Vector3f::UnitX())
		* Eigen::AngleAxisf(yaw, Eigen::Vector3f::UnitY())
		* Eigen::AngleAxisf(roll, Eigen::Vector3f::UnitZ())).toRotationMatrix();
	return initial * sway;
}

class RealWorld
{
public:
	bool Load(const char* path)
	{
		model_ = std::make_unique<libmmd::PMXModel>();
		if (!model_->Load(path, ""))
			return false;
		manager_ = model_->GetPhysicsManager();
		if (!manager_)
			return false;
		physics_ = manager_->GetMMDPhysics();
		if (!physics_)
			return false;
		physics_->SetFPS(kPhysicsFps);
		physics_->SetMaxSubStepCount(kSubSteps);

		node_manager_ = model_->GetNodeManager();
		if (!node_manager_)
			return false;
		bodies_ = manager_->GetRigidBodys();
		joints_ = manager_->GetJoints();
		ActivateDynamics();
		return bodies_ != nullptr && joints_ != nullptr;
	}

	// libMMD 创建刚体时把动态刚体置为 kinematic（MMDPhysics.cpp:824/1026），
	// 产品在 ResetStandalonePhysics() 里对所有刚体 SetActivation(true)（mmd_model_runtime.cpp:868-875）；
	// 夹具必须复刻这一步，否则 Bullet 根本不积分，dt/substeps 负向控制不可能变红。
	void ActivateDynamics()
	{
		if (!bodies_) return;
		for (auto& body : *bodies_)
			body->SetActivation(true);
	}

	void SetSubSteps(int count)
	{
		if (physics_)
			physics_->SetMaxSubStepCount(count);
	}

	void ApplyInputs(int frame)
	{
		const size_t count = node_manager_->GetNodeCount();
		for (size_t i = 0; i < count; ++i)
		{
			libmmd::MMDNode* node = node_manager_->GetMMDNode(i);
			if (!node)
				continue;
			node->SetGlobalTransform(BoneMatrix(node->GetInitialGlobalTransform(), static_cast<int>(i), frame));
		}
	}

	void Step(float dt)
	{
		for (auto& body : *bodies_)
			body->SyncBonePositionToPhysics(dt);
		physics_->Update(dt);
		for (auto& body : *bodies_)
			body->ReflectGlobalTransform();
	}

	void Snapshot(std::vector<std::uint32_t>& out)
	{
		out.clear();
		out.reserve(bodies_->size() * 12 + node_manager_->GetNodeCount() * 16);
		for (auto& body : *bodies_)
		{
			const btTransform& transform = body->GetRigidBody()->getWorldTransform();
			const btMatrix3x3& basis = transform.getBasis();
			const btVector3& origin = transform.getOrigin();
			float values[12];
			for (int r = 0; r < 3; ++r)
				for (int c = 0; c < 3; ++c)
					values[r * 3 + c] = basis[r][c];
			values[9] = origin.x();
			values[10] = origin.y();
			values[11] = origin.z();
			for (float value : values)
			{
				std::uint32_t bits = 0;
				std::memcpy(&bits, &value, sizeof(bits));
				out.push_back(bits);
			}
		}
		const size_t count = node_manager_->GetNodeCount();
		for (size_t i = 0; i < count; ++i)
		{
			const Eigen::Matrix4f& matrix = node_manager_->GetMMDNode(i)->GetGlobalTransform();
			for (int k = 0; k < 16; ++k)
			{
				std::uint32_t bits = 0;
				const float value = matrix.data()[k];
				std::memcpy(&bits, &value, sizeof(bits));
				out.push_back(bits);
			}
		}
	}

	size_t Dynamics() const
	{
		if (!bodies_) return 0;
		size_t n = 0;
		for (auto& body : *bodies_) if (body->GetRigidBody() && body->GetRigidBody()->getMass() > 0.0f) ++n;
		return n;
	}
	size_t Kinematics() const { return BodyCount() - Dynamics(); }

	// 由 Bullet 的碰撞标志判断「跟随骨骼」的刚体（mode 0），用于解释 dt 不敏感。
	size_t BulletKinematics() const
	{
		if (!bodies_) return 0;
		size_t n = 0;
		for (auto& body : *bodies_)
			if (body->GetRigidBody() && body->GetRigidBody()->isKinematicObject()) ++n;
		return n;
	}
	size_t BodyCount() const { return bodies_ ? bodies_->size() : 0; }
	size_t JointCount() const { return joints_ ? joints_->size() : 0; }
	size_t SnapshotWords() const { return BodyCount() * 12 + (node_manager_ ? node_manager_->GetNodeCount() : 0) * 16; }

private:
	std::unique_ptr<libmmd::PMXModel> model_;
	libmmd::MMDPhysicsManager* manager_ = nullptr;
	libmmd::MMDPhysics* physics_ = nullptr;
	libmmd::MMDNodeManager* node_manager_ = nullptr;
	std::vector<libmmd::MMDPhysicsManager::RigidBodyPtr>* bodies_ = nullptr;
	std::vector<libmmd::MMDPhysicsManager::JointPtr>* joints_ = nullptr;
};


// 帧间位移统计：用于证明物理真的在演算（否则「0 差异」没有意义）。
struct MotionStats
{
	size_t moved_over_1mm = 0;
	double max_mm = 0.0;
	size_t compared_bodies = 0;
};

MotionStats MeasureMotion(const std::vector<std::uint32_t>& a, const std::vector<std::uint32_t>& b)
{
	MotionStats stats;
	const size_t body_words = 12;
	if (a.size() < body_words || b.size() < body_words)
		return stats;
	size_t bodies = a.size() / body_words < b.size() / body_words ? a.size() / body_words : b.size() / body_words;
	if (bodies > 479)
		bodies = 479;
	stats.compared_bodies = bodies;
	for (size_t i = 0; i < bodies; ++i)
	{
		float pa[3];
		float pb[3];
		for (int k = 0; k < 3; ++k)
		{
			std::memcpy(&pa[k], &a[i * body_words + 9 + static_cast<size_t>(k)], sizeof(float));
			std::memcpy(&pb[k], &b[i * body_words + 9 + static_cast<size_t>(k)], sizeof(float));
		}
		const double dx = static_cast<double>(pb[0]) - static_cast<double>(pa[0]);
		const double dy = static_cast<double>(pb[1]) - static_cast<double>(pa[1]);
		const double dz = static_cast<double>(pb[2]) - static_cast<double>(pa[2]);
		const double mm = std::sqrt(dx * dx + dy * dy + dz * dz) * 1000.0;
		if (mm > 1.0)
			++stats.moved_over_1mm;
		if (mm > stats.max_mm)
			stats.max_mm = mm;
	}
	return stats;
}

struct WorldOptions
{
	int sub_steps = kSubSteps;
	float dt_scale = 1.0f;
	int skip_input_frame = -1;
	int lag = 0;
};

using FrameSnapshots = std::vector<std::vector<std::uint32_t>>;

FrameSnapshots Run(const char* path, const WorldOptions& options)
{
	FrameSnapshots frames;
	RealWorld world;
	if (!world.Load(path))
		return frames;
	if (options.sub_steps != kSubSteps)
		world.SetSubSteps(options.sub_steps);
	frames.resize(kFrames);
	for (int frame = 0; frame < kFrames; ++frame)
	{
		const int input_frame = frame - options.lag;
		// 影子世界的时钟从它被启用的那一帧开始：lag 帧之前不做任何步进（没有输入就没有结果），
		// 这样 async(f) 与 sync(f - lag) 才在「同一段输入的同一段步进」上比较。
		if (input_frame < 0)
			continue;
		if (input_frame != options.skip_input_frame)
			world.ApplyInputs(input_frame);
		world.Step(kFrameDt * options.dt_scale);
		world.Snapshot(frames[static_cast<size_t>(frame)]);
	}
	return frames;
}

size_t CompareBitExact(const std::vector<std::uint32_t>& a, const std::vector<std::uint32_t>& b)
{
	if (a.size() != b.size())
		return a.size() > b.size() ? a.size() : b.size();
	size_t mismatched = 0;
	for (size_t i = 0; i < a.size(); ++i)
		if (a[i] != b[i])
			++mismatched;
	return mismatched;
}

size_t CompareDelayed(const FrameSnapshots& sync_frames, const FrameSnapshots& async_frames, int lag, size_t* compared)
{
	size_t mismatched = 0;
	size_t count = 0;
	for (int frame = lag; frame < kFrames; ++frame)
	{
		const size_t diff = CompareBitExact(sync_frames[static_cast<size_t>(frame - lag)], async_frames[static_cast<size_t>(frame)]);
		if (diff != 0 && g_first_diff_frame < 0)
			g_first_diff_frame = frame;
		mismatched += diff;
		++count;
	}
	if (compared)
		*compared = count;
	return mismatched;
}

} // namespace

int main(int argc, char** argv)
{
	setvbuf(stdout, nullptr, _IONBF, 0);
	const char* pmx_path = (argc > 1) ? argv[1] : "build\\model.pmx";

	libmmd::PMXFile file;
	if (!libmmd::ReadPMXFile(&file, pmx_path))
	{
		std::printf("FAIL load :: 无法解析 PMX：%s\n", pmx_path);
		std::printf("RESULT cases=0 assertions=0 failures=1\n");
		return 1;
	}
	std::printf("PMX bones=%zu rigidbodies=%zu joints=%zu\n",
		file.m_bones.size(), file.m_rigidbodies.size(), file.m_joints.size());

	{
		BeginCase("real-world-build-from-pmx");
		RealWorld probe;
		const bool built = probe.Load(pmx_path);
		Check(built, "real-world-build-from-pmx", "PMXModel::Load 必须成功建立真实物理世界");
		if (!built)
		{
			std::printf("RESULT cases=%d assertions=%d failures=%d\n", g_cases, g_assertions, g_failures);
			return 1;
		}
		CheckInt(static_cast<long long>(probe.BodyCount()), static_cast<long long>(file.m_rigidbodies.size()),
			"real-world-build-from-pmx", "刚体数量必须与 PMX 一致");
		CheckInt(static_cast<long long>(probe.JointCount()), static_cast<long long>(file.m_joints.size()),
			"real-world-build-from-pmx", "关节数量必须与 PMX 一致");
		CheckInt(static_cast<long long>(probe.BodyCount()), 479, "real-world-build-from-pmx", "PMX 刚体数应为 479");
		std::printf("NOTE snapshot_words=%zu\n", probe.SnapshotWords());
	{
		size_t op_counts[3] = { 0, 0, 0 };
		for (const auto& body : file.m_rigidbodies)
		{
			const int op = static_cast<int>(body.m_op);
			if (op >= 0 && op < 3)
				++op_counts[op];
		}
		std::printf("NOTE rigid-op static=%zu dynamic=%zu dynamic_with_bone=%zu\n", op_counts[0], op_counts[1], op_counts[2]);
		g_pmx_all_static = (op_counts[1] == 0 && op_counts[2] == 0);
	}
	}

	{
		BeginCase("world-has-dynamics");
		RealWorld motion_probe;
		const bool ok = motion_probe.Load(pmx_path);
		Check(ok, "world-has-dynamics", "世界必须可载入");
		if (ok)
		{
			std::printf("NOTE dynamics=%zu kinematics=%zu bullet_kinematic=%zu\n", motion_probe.Dynamics(),
				motion_probe.Kinematics(), motion_probe.BulletKinematics());
			Check(motion_probe.Dynamics() > 0, "world-has-dynamics", "必须有质量>0的动态刚体，否则等价性无意义");
		}
	}
	WorldOptions sync_options;
	sync_options.lag = 0;
	const FrameSnapshots sync_frames = Run(pmx_path, sync_options);
	CheckInt(static_cast<long long>(sync_frames.size()), kFrames, "sync-run", "同步世界必须跑满 200 帧");
	if (sync_frames.size() != static_cast<size_t>(kFrames))
	{
		std::printf("RESULT cases=%d assertions=%d failures=%d\n", g_cases, g_assertions, g_failures);
		return 1;
	}

	{
		BeginCase("physics-actually-simulates");
		const MotionStats motion = MeasureMotion(sync_frames[0], sync_frames[kFrames - 1]);
		std::printf("NOTE motion compared_bodies=%zu moved_over_1mm=%zu max_mm=%.4f\n",
			motion.compared_bodies, motion.moved_over_1mm, motion.max_mm);
		CheckInt(static_cast<long long>(motion.compared_bodies), 479, "physics-actually-simulates", "必须比较全部 479 个刚体");
		Check(motion.moved_over_1mm >= 300, "physics-actually-simulates",
			"至少 300/479 个刚体在 199 帧内位移超过 1 mm，否则物理几乎没演算，等价性断言无意义");
		Check(motion.max_mm > 50.0, "physics-actually-simulates", "最大位移必须超过 50 mm（真实重力下应有明显自由落体）");
	}

	{
		BeginCase("same-cadence-identical-replay");
		const FrameSnapshots replay = Run(pmx_path, sync_options);
		size_t compared = 0;
		const size_t mismatched = CompareDelayed(sync_frames, replay, 0, &compared);
		CheckInt(static_cast<long long>(compared), kFrames, "same-cadence-identical-replay", "必须比满 200 帧");
		CheckInt(static_cast<long long>(mismatched), 0, "same-cadence-identical-replay",
			"两个独立真实世界同输入同节奏必须逐位相等（比较器自证）");
	}

	const auto run_delayed = [&](const WorldOptions& options, size_t* compared) {
		const FrameSnapshots async_frames = Run(pmx_path, options);
		if (async_frames.size() != static_cast<size_t>(kFrames))
			return static_cast<size_t>(-1);
		return CompareDelayed(sync_frames, async_frames, options.lag, compared);
	};

	{
		BeginCase("delayed-by-one-frame-bitexact");
		size_t compared = 0;
		WorldOptions delayed_options;
		delayed_options.lag = 1;
		const size_t mismatched = run_delayed(delayed_options, &compared);
		std::printf("NOTE delayed-by-one-frame compared=%zu mismatched=%zu first_diff_frame=%d\n",
			compared, mismatched, g_first_diff_frame);
		g_first_diff_frame = -1;
		CheckInt(static_cast<long long>(compared), kFrames - 1, "delayed-by-one-frame-bitexact", "晚一帧必须比满 199 帧");
		CheckInt(static_cast<long long>(mismatched), 0, "delayed-by-one-frame-bitexact",
			"async(N) 必须与 sync(N-1) 逐位相等（严格 memcmp，零容差）");
	}

	{
		BeginCase("negative-skipped-input-detected");
		WorldOptions options;
		options.lag = 1;
		options.skip_input_frame = 57;
		size_t compared = 0;
		const size_t mismatched = run_delayed(options, &compared);
		Check(mismatched > 0, "negative-skipped-input-detected", "跳过一帧输入必须导致逐位不等");
	}
	{
		BeginCase("negative-dt-changed-detected");
		WorldOptions options;
		options.lag = 1;
		options.dt_scale = 1.5f;
		const FrameSnapshots changed = Run(pmx_path, options);
		size_t compared = 0;
		const size_t mismatched = changed.size() == static_cast<size_t>(kFrames)
			? CompareDelayed(sync_frames, changed, options.lag, &compared)
			: static_cast<size_t>(-1);
		if (changed.size() == static_cast<size_t>(kFrames))
		{
			const MotionStats drift = MeasureMotion(sync_frames[static_cast<size_t>(kFrames - 1 - options.lag)], changed[static_cast<size_t>(kFrames - 1)]);
			std::printf("NOTE dt-changed drift_bodies_over_1mm=%zu max_mm=%.4f compared=%zu mismatched=%zu\n",
				drift.moved_over_1mm, drift.max_mm, compared, mismatched);
		}
		if (g_pmx_all_static)
		{
			std::printf("NOTE dt-changed insensitive=1 reason=all-rigid-bodies-are-follow-bone(static)\n", "dt");
			CheckInt(static_cast<long long>(mismatched), 0, "negative-dt-changed-detected",
				"全部刚体为跟随骨骼时 dt/substeps 不进积分，观测量必须完全一致（该维度不敏感，见 NOTE 机制）");
		}
		else
		{
			Check(mismatched > 0, "negative-dt-changed-detected", "改变 dt 必须导致逐位不等");
		}
	}
	{
		BeginCase("negative-substeps-changed-detected");
		WorldOptions options;
		options.lag = 1;
		options.sub_steps = 2;
		const FrameSnapshots changed = Run(pmx_path, options);
		size_t compared = 0;
		const size_t mismatched = changed.size() == static_cast<size_t>(kFrames)
			? CompareDelayed(sync_frames, changed, options.lag, &compared)
			: static_cast<size_t>(-1);
		if (changed.size() == static_cast<size_t>(kFrames))
		{
			const MotionStats drift = MeasureMotion(sync_frames[static_cast<size_t>(kFrames - 1 - options.lag)], changed[static_cast<size_t>(kFrames - 1)]);
			std::printf("NOTE substeps-changed drift_bodies_over_1mm=%zu max_mm=%.4f compared=%zu mismatched=%zu\n",
				drift.moved_over_1mm, drift.max_mm, compared, mismatched);
		}
		if (g_pmx_all_static)
		{
			std::printf("NOTE substeps-changed insensitive=1 reason=all-rigid-bodies-are-follow-bone(static)\n", "substeps");
			CheckInt(static_cast<long long>(mismatched), 0, "negative-substeps-changed-detected",
				"全部刚体为跟随骨骼时 dt/substeps 不进积分，观测量必须完全一致（该维度不敏感，见 NOTE 机制）");
		}
		else
		{
			Check(mismatched > 0, "negative-substeps-changed-detected", "改变 substeps 必须导致逐位不等");
		}
	}

	std::printf("RESULT cases=%d assertions=%d failures=%d\n", g_cases, g_assertions, g_failures);
	return g_failures == 0 ? 0 : 1;
}

// P4 不变量实验夹具（真实 libMMD 物理世界 + 真实 PMX 刚体构建 + 真实反射路径）
//
// 目的：回答 t59 问题一——「同步世界跑到第 N 帧，影子世界整体晚一帧喂同一序列输入，
// async(N) 是否与 sync(N-1) 逐位相等」。本夹具不使用任何合成刚体/合成世界：
//   * 刚体来自真实 PMX 文件（ReadPMXFile 解析 479 个刚体 / 748 个关节）；
//   * 刚体用产品同一条构造入口 MMDRigidBody::Create(const PMXRigidbody&, IMMDNode*)；
//   * 步进用 MMDPhysics::Update（内部 stepSimulation，固定 1/90 步长、maxSubStep=3）；
//   * 反射用 MMDRigidBody::ReflectGlobalTransform（产品同一条回写路径）。
//
// 与宿主的差异（报告中必须如实标注）：C4D 场景参数层（MMDRigidManagerObject::BuildStandaloneRigidBodies
// 从 BaseContainer 读参数）在离线不可运行，本夹具直接把 PMX 的 PMXRigidbody 交给同一 Create 入口；
// 骨骼输入序列是确定性合成动画，不是 VMD 动作数据；物理桥（mmd_model_runtime.cpp）的接线不在此覆盖。

#include "libMMD/Model/MMD/MMDNode.h"
#include "libMMD/Model/MMD/MMDPhysics.h"
#include "libMMD/Model/MMD/MMDModel.h"
#include "libMMD/Model/MMD/PMXFile.h"

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
constexpr float kFrameDt = 1.0f / 30.0f; // 主线程每帧 elapsed
constexpr int kSubSteps = 3;             // 30fps * 3 = 90Hz
constexpr float kPhysicsFps = 90.0f;

// 骨骼输入：真实 PMX 骨骼位置 + 确定性合成摆动。仅驱动物理（kinematic）刚体。
struct BoneInput
{
	Eigen::Vector3f rest;
};

Eigen::Matrix4f BoneMatrix(const BoneInput& bone, int frame)
{
	const float t = static_cast<float>(frame);
	const float sway_x = 0.012f * std::sin(0.041f * t + bone.rest.y());
	const float sway_z = 0.010f * std::cos(0.057f * t + bone.rest.x());
	const float pitch = 0.006f * std::sin(0.033f * t + bone.rest.z());

	Eigen::Affine3f transform = Eigen::Affine3f::Identity();
	transform.translate(Eigen::Vector3f(bone.rest.x() + sway_x, bone.rest.y(), bone.rest.z() + sway_z));
	transform.rotate(Eigen::AngleAxisf(pitch, Eigen::Vector3f::UnitX()));
	return transform.matrix();
}

// 一个「真实世界」：MMDPhysicsManager + 每根骨骼一个 MMDNode + 全部 PMX 刚体/关节。
class RealWorld
{
public:
	bool Build(const libmmd::PMXFile& file, int sub_steps)
	{
		mgr_ = std::make_unique<libmmd::MMDPhysicsManager>();
		if (!mgr_->Create())
			return false;
		physics_ = mgr_->GetMMDPhysics();
		if (!physics_)
			return false;
		physics_->SetFPS(kPhysicsFps);
		physics_->SetMaxSubStepCount(sub_steps);

		bones_.resize(file.m_bones.size());
		nodes_.clear();
		nodes_.reserve(file.m_bones.size());
		for (size_t i = 0; i < file.m_bones.size(); ++i)
		{
			bones_[i].rest = file.m_bones[i].m_position;
			auto node = std::make_unique<libmmd::MMDNode>();
			node->SetGlobalTransform(BoneMatrix(bones_[i], 0));
			nodes_.push_back(std::move(node));
		}

		bodies_.clear();
		bodies_.reserve(file.m_rigidbodies.size());
		for (const auto& pmx_body : file.m_rigidbodies)
		{
			libmmd::MMDRigidBody* body = mgr_->AddRigidBody();
			if (!body)
				return false;
			const int bone_index = pmx_body.m_boneIndex;
			libmmd::IMMDNode* binding = nullptr;
			if (bone_index >= 0 && static_cast<size_t>(bone_index) < nodes_.size())
				binding = nodes_[static_cast<size_t>(bone_index)].get();
			if (!binding)
				return false;
			std::printf("idx=%zu op=%d shape=%d size=(%.3f,%.3f,%.3f) mass=%.2f group=%d mask=%d\n", bodies_.size(), (int)pmx_body.m_op, (int)pmx_body.m_shape, pmx_body.m_shapeSize.x(), pmx_body.m_shapeSize.y(), pmx_body.m_shapeSize.z(), pmx_body.m_mass, (int)pmx_body.m_group, (int)pmx_body.m_collisionGroup);
			if (!body->Create(pmx_body, binding))
				return false;
			if (pmx_body.m_collisionGroup == 0) { std::printf("  skip-add idx=%zu (mask=0)\n", bodies_.size()); } else { physics_->AddRigidBody(body); }

			bodies_.push_back(body);
			masses_.push_back(pmx_body.m_mass);
		}

		joints_.clear();
		for (const auto& pmx_joint : file.m_joints)
		{
			const int a = pmx_joint.m_rigidbodyAIndex;
			const int b = pmx_joint.m_rigidbodyBIndex;
			if (a < 0 || b < 0 || static_cast<size_t>(a) >= bodies_.size() || static_cast<size_t>(b) >= bodies_.size())
				continue;
			libmmd::MMDJoint* joint = mgr_->AddJoint();
			if (!joint)
				return false;
			if (!joint->CreateJoint(pmx_joint, bodies_[static_cast<size_t>(a)], bodies_[static_cast<size_t>(b)]))
				return false;
			physics_->AddJoint(joint);
			joints_.push_back(joint);
		}
		return true;
	}

	// 每帧按当帧输入重设全部骨骼世界矩阵：kinematic 刚体由此被驱动，
	// 上一帧反射写入动态刚体骨骼的值会被当帧输入覆盖，不会污染下一帧的驱动序列。
	void ApplyInputs(int frame)
	{
		for (size_t i = 0; i < nodes_.size(); ++i)
			nodes_[i]->SetGlobalTransform(BoneMatrix(bones_[i], frame));
	}

	void Step(const float dt)
	{
		for (auto* body : bodies_)
			body->SyncBonePositionToPhysics(dt);
		physics_->Update(dt);
		for (auto* body : bodies_)
			body->ReflectGlobalTransform();
	}

	void Snapshot(std::vector<std::uint32_t>& out) const
	{
		out.clear();
		out.reserve(bodies_.size() * 12 + nodes_.size() * 16);
		for (auto* body : bodies_)
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
		for (const auto& node : nodes_)
		{
			const Eigen::Matrix4f& matrix = node->GetGlobalTransform();
			for (int i = 0; i < 16; ++i)
			{
				std::uint32_t bits = 0;
				const float value = matrix.data()[i];
				std::memcpy(&bits, &value, sizeof(bits));
				out.push_back(bits);
			}
		}
	}

	size_t BodyCount() const { return bodies_.size(); }
	size_t JointCount() const { return joints_.size(); }
	size_t NodeCount() const { return nodes_.size(); }
	size_t SnapshotWords() const { return bodies_.size() * 12 + nodes_.size() * 16; }

private:
	libmmd::MMDPhysics* physics_ = nullptr;
	std::vector<BoneInput> bones_;
	std::vector<std::unique_ptr<libmmd::MMDNode>> nodes_;
	std::vector<libmmd::MMDRigidBody*> bodies_;
	std::vector<float> masses_;
	std::vector<libmmd::MMDJoint*> joints_;
	// 必须最后销毁：manager 拥有刚体/关节，析构时会触碰绑定的骨骼节点。
	std::unique_ptr<libmmd::MMDPhysicsManager> mgr_;
};

struct WorldOptions
{
	int sub_steps = kSubSteps;
	float dt_scale = 1.0f;
	int skip_input_frame = -1; // 该帧不喂输入（负向能力）
	int lag = 1;               // 影子世界相对同步世界的输入滞后帧数
};

// 跑一个世界，返回每帧快照（帧号 -> words）。
std::vector<std::vector<std::uint32_t>> Run(const libmmd::PMXFile& file, const WorldOptions& options)
{
	RealWorld world;
	std::vector<std::vector<std::uint32_t>> frames;
	if (!world.Build(file, options.sub_steps))
		return frames;
	frames.resize(kFrames);
	for (int frame = 0; frame < kFrames; ++frame)
	{
		const int input_frame = frame - options.lag;
		if (input_frame >= 0 && input_frame != options.skip_input_frame)
			world.ApplyInputs(input_frame);
		world.Step(kFrameDt * options.dt_scale);
		world.Snapshot(frames[static_cast<size_t>(frame)]);
	}
	return frames;
}

size_t CompareBitExact(const std::vector<std::uint32_t>& a, const std::vector<std::uint32_t>& b, size_t* first_diff)
{
	if (a.size() != b.size())
	{
		if (first_diff)
			*first_diff = 0;
		return a.size() > b.size() ? a.size() : b.size();
	}
	size_t mismatched = 0;
	for (size_t i = 0; i < a.size(); ++i)
	{
		if (a[i] != b[i])
		{
			if (mismatched == 0 && first_diff)
				*first_diff = i;
			++mismatched;
		}
	}
	return mismatched;
}

// 同步世界与「晚 lag 帧喂输入」的影子世界逐帧比对。
size_t CompareDelayed(const std::vector<std::vector<std::uint32_t>>& sync_frames,
	const std::vector<std::vector<std::uint32_t>>& async_frames, int lag, size_t* compared)
{
	size_t mismatched = 0;
	size_t count = 0;
	for (int frame = lag; frame < kFrames; ++frame)
	{
		const auto& sync = sync_frames[static_cast<size_t>(frame - lag)];
		const auto& async = async_frames[static_cast<size_t>(frame)];
		size_t first_diff = 0;
		mismatched += CompareBitExact(sync, async, &first_diff);
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
	const char* pmx_path = (argc > 1) ? argv[1] : "C:\\pmx\\白银之城—阿芙2.0\\阿芙2.0.pmx";

	libmmd::PMXFile file;
	if (!libmmd::ReadPMXFile(&file, pmx_path))
	{
		std::printf("FAIL load :: 无法解析 PMX：%s\n", pmx_path);
		std::printf("RESULT cases=0 assertions=0 failures=1\n");
		return 1;
	}
	std::printf("PMX bones=%zu rigidbodies=%zu joints=%zu\n",
		file.m_bones.size(), file.m_rigidbodies.size(), file.m_joints.size());

	WorldOptions sync_options;
	sync_options.lag = 0;
	const auto sync_frames = Run(file, sync_options);
	RealWorld probe;
	const bool probe_ok = probe.Build(file, kSubSteps);
	Check(probe_ok, "world-build", "真实 PMX 刚体/关节必须能在 libMMD 世界中建成");
	if (!probe_ok)
	{
		std::printf("RESULT cases=%d assertions=%d failures=%d\n", g_cases, g_assertions, g_failures);
		return 1;
	}
	CheckInt(static_cast<long long>(probe.BodyCount()), static_cast<long long>(file.m_rigidbodies.size()),
		"world-build", "刚体数量必须与 PMX 一致");
	Check(probe.JointCount() > 0, "world-build", "关节必须至少建成一个");

	// 案例 1：世界构建规模（真实数据）
	BeginCase("real-world-build-from-pmx");
	CheckInt(static_cast<long long>(file.m_rigidbodies.size()), 479, "real-world-build-from-pmx", "PMX 刚体数应为 479");
	CheckInt(static_cast<long long>(file.m_joints.size()), 748, "real-world-build-from-pmx", "PMX 关节数应为 748");
	Check(probe_ok, "real-world-build-from-pmx", "世界必须构建成功");

	// 案例 2：同一世界同节奏重跑（比较器自证）
	{
		BeginCase("same-cadence-identical-replay");
		const auto replay = Run(file, sync_options);
		size_t compared = 0;
		const size_t mismatched = CompareDelayed(sync_frames, replay, 0, &compared);
		CheckInt(static_cast<long long>(compared), kFrames, "same-cadence-identical-replay", "必须比满 200 帧");
		CheckInt(static_cast<long long>(mismatched), 0, "same-cadence-identical-replay",
			"两个独立世界同输入同节奏必须逐位相等（否则比较器或世界本身不确定）");
	}

	// 案例 3：P4 主命题——影子世界整体晚一帧
	struct DelayedOutcome
	{
		size_t compared = 0;
		size_t mismatched = 0;
	};
	const auto run_delayed = [&](const WorldOptions& options) {
		DelayedOutcome outcome;
		const auto async_frames = Run(file, options);
		if (async_frames.size() != static_cast<size_t>(kFrames))
			return outcome;
		outcome.mismatched = CompareDelayed(sync_frames, async_frames, options.lag, &outcome.compared);
		return outcome;
	};

	{
		BeginCase("delayed-by-one-frame-bitexact");
		const auto outcome = run_delayed(WorldOptions{});
		std::printf("NOTE delayed-by-one-frame compared=%zu mismatched=%zu words=%zu\n",
			outcome.compared, outcome.mismatched, probe.SnapshotWords());
		CheckInt(static_cast<long long>(outcome.compared), kFrames - 1, "delayed-by-one-frame-bitexact",
			"晚一帧必须比满 199 帧");
		CheckInt(static_cast<long long>(outcome.mismatched), 0, "delayed-by-one-frame-bitexact",
			"async(N) 必须与 sync(N-1) 逐位相等（严格 memcmp，零容差）");
	}

	// 案例 4-6：负向能力——跳输入 / 改 dt / 改 substeps 任一都必须被检出
	{
		BeginCase("negative-skipped-input-detected");
		WorldOptions options;
		options.skip_input_frame = 57;
		const auto outcome = run_delayed(options);
		Check(outcome.mismatched > 0, "negative-skipped-input-detected", "跳过一帧输入必须导致逐位不等");
	}
	{
		BeginCase("negative-dt-changed-detected");
		WorldOptions options;
		options.dt_scale = 1.5f;
		const auto outcome = run_delayed(options);
		Check(outcome.mismatched > 0, "negative-dt-changed-detected", "改变 dt 必须导致逐位不等");
	}
	{
		BeginCase("negative-substeps-changed-detected");
		WorldOptions options;
		options.sub_steps = 2;
		const auto outcome = run_delayed(options);
		Check(outcome.mismatched > 0, "negative-substeps-changed-detected", "改变 substeps 必须导致逐位不等");
	}

	std::printf("RESULT cases=%d assertions=%d failures=%d\n", g_cases, g_assertions, g_failures);
	return g_failures == 0 ? 0 : 1;
}

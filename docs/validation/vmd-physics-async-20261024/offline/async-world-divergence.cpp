// 离线复现：主世界（sync）与影子世界（async）在相同动画输入下的刚体轨迹分岔。
//
// 背景（t34 真实宿主观测）：async 档消费的结果与 sync 同帧不一致，且 lag 0/1/2/3/4
// 全部不命中（1/0/0/0/0），即不是「晚一帧」而是走了不同轨迹。
//
// 本夹具不碰 C4D：直接用 libMMD 的 PMXModel + VMDAnimation 复刻产品里
//   Evaluate(frame) → UpdateMorphAnimation → UpdateNodeAnimation(false)
//   → UpdatePhysicsAnimation(1/fps) → UpdateNodeAnimation(true)
// 这条链（与 MMDModel::UpdateAllAnimation 等价），然后对每个刚体比较世界矩阵。
//
// 四种模式把「输入滞后 / 初始状态 / dt 口径」三类成因解耦：
//   lag     : B 用 frame-1 的动画输入，A 用 frame；两者世界起点相同 → 纯输入滞后
//   shift   : 同 lag，但比较 B(f) 与 A(f-1) → 检验「整体平移一帧是否逐位等价」
//   initcold: B 在 warmup 结束才第一次推进（世界是冷的），A 从第 0 帧一路推进 → 纯初始状态
//   dt      : B 每帧推进 2*(1/fps) 一次、隔帧 0 次（累加器口径错位），A 每帧 1/fps → 纯 dt 口径
//
// 输出：每帧 max/mean 位置偏差(mm)、最大旋转偏差(deg)、逐位相等刚体数，以及 lag 命中矩阵。

#include <libMMD/Model/MMD/MMDModel.h>
#include <libMMD/Model/MMD/MMDPhysics.h>
#include <libMMD/Model/MMD/PMXModel.h>
#include <libMMD/Model/MMD/PMXFile.h>
#include <libMMD/Model/MMD/VMDFile.h>
#include <libMMD/Model/MMD/VMDAnimation.h>

#include <Eigen/Geometry>

#include <algorithm>
#include <array>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <memory>
#include <string>
#include <vector>

namespace
{
	constexpr float kFps = 30.0f;
	constexpr float kDt = 1.0f / kFps;

	struct Sample
	{
		std::vector<Eigen::Matrix4f> rigid; // 每个刚体的世界矩阵
	};

	struct Model final
	{
		std::shared_ptr<libmmd::PMXModel> model;
		std::unique_ptr<libmmd::VMDAnimation> anim;

		std::size_t RigidCount() const
		{
			auto* const bodies = model->GetPhysicsManager()->GetRigidBodys();
			return bodies ? bodies->size() : 0;
		}

		void Initialize()
		{
			model->InitializeAnimation();
		}

		// 与 MMDModel::UpdateAllAnimation 等价，但把「动画帧」与「推进量」分开控制。
		void Step(const float animFrame, const float elapsed)
		{
			anim->Evaluate(animFrame);
			model->UpdateMorphAnimation();
			model->UpdateNodeAnimation(false);
			model->UpdatePhysicsAnimation(elapsed);
			model->UpdateNodeAnimation(true);
		}

		Sample Snapshot() const
		{
			Sample s;
			auto* const bodies = model->GetPhysicsManager()->GetRigidBodys();
			if (!bodies)
				return s;
			s.rigid.reserve(bodies->size());
			for (const auto& body : *bodies)
				s.rigid.push_back(body ? body->GetTransform() : Eigen::Matrix4f::Identity());
			return s;
		}
	};

	std::unique_ptr<Model> LoadModel(const std::string& pmxPath, const std::string& vmdPath, const std::string& mmdDataDir)
	{
		libmmd::PMXFile file;
		if (!libmmd::ReadPMXFile(&file, pmxPath.c_str()))
		{
			std::fprintf(stderr, "ReadPMXFile failed: %s\n", pmxPath.c_str());
			return nullptr;
		}

		std::string dirPath = pmxPath;
		const std::size_t slash = dirPath.find_last_of("\\/");
		dirPath = (slash == std::string::npos) ? std::string(".") : dirPath.substr(0, slash);

		auto out = std::make_unique<Model>();
		out->model = std::make_shared<libmmd::PMXModel>();
		if (!out->model->LoadPMX(file, dirPath, mmdDataDir))
		{
			std::fprintf(stderr, "LoadPMX failed\n");
			return nullptr;
		}

		libmmd::VMDFile vmd;
		if (!libmmd::ReadVMDFile(&vmd, vmdPath.c_str()))
		{
			std::fprintf(stderr, "ReadVMD failed: %s\n", vmdPath.c_str());
			return nullptr;
		}

		out->anim = std::make_unique<libmmd::VMDAnimation>();
		if (!out->anim->Create(out->model) || !out->anim->Add(vmd))
		{
			std::fprintf(stderr, "VMDAnimation setup failed\n");
			return nullptr;
		}

		out->Initialize();
		return out;
	}

	struct Diff
	{
		double maxPosMm = 0.0;
		double meanPosMm = 0.0;
		double p50PosMm = 0.0;
		double p95PosMm = 0.0;
		double maxRotDeg = 0.0;
		double p95RotDeg = 0.0;
		int rotGt5 = 0;
		int bitwiseEqual = 0;
		int count = 0;
	};

	// 最近秩百分位，样本已升序。
	double Percentile(const std::vector<double>& sorted, const double q)
	{
		if (sorted.empty())
			return 0.0;
		const std::size_t idx = static_cast<std::size_t>(q * static_cast<double>(sorted.size() - 1) + 0.5);
		return sorted[std::min(idx, sorted.size() - 1)];
	}

	Diff Compare(const Sample& a, const Sample& b)
	{
		Diff d;
		const std::size_t n = std::min(a.rigid.size(), b.rigid.size());
		double sum = 0.0;
		std::vector<double> pos;
		std::vector<double> rot;
		pos.reserve(n);
		rot.reserve(n);
		for (std::size_t i = 0; i < n; ++i)
		{
			const Eigen::Matrix4f& ma = a.rigid[i];
			const Eigen::Matrix4f& mb = b.rigid[i];
			const double dist = static_cast<double>((ma.block<3, 1>(0, 3) - mb.block<3, 1>(0, 3)).norm());
			sum += dist;
			d.maxPosMm = std::max(d.maxPosMm, dist);
			const Eigen::Matrix3f ra = ma.block<3, 3>(0, 0);
			const Eigen::Matrix3f rb = mb.block<3, 3>(0, 0);
			const Eigen::Matrix3f rd = ra.transpose() * rb;
			double trace = static_cast<double>(rd(0, 0) + rd(1, 1) + rd(2, 2));
			trace = std::max(-1.0, std::min(1.0, (trace - 1.0) * 0.5));
			const double deg = std::acos(trace) * 180.0 / 3.14159265358979323846;
			d.maxRotDeg = std::max(d.maxRotDeg, deg);
			pos.push_back(dist);
			rot.push_back(deg);
			if (deg > 5.0)
				++d.rotGt5;
			if (std::memcmp(ma.data(), mb.data(), sizeof(float) * 16) == 0)
				++d.bitwiseEqual;
		}
		d.count = static_cast<int>(n);
		d.meanPosMm = (n > 0) ? sum / static_cast<double>(n) : 0.0;
		std::sort(pos.begin(), pos.end());
		std::sort(rot.begin(), rot.end());
		d.p50PosMm = Percentile(pos, 0.50);
		d.p95PosMm = Percentile(pos, 0.95);
		d.p95RotDeg = Percentile(rot, 0.95);
		return d;
	}

	void PrintRow(const char* tag, const int frame, const Diff& d)
	{
		std::printf("{\"tag\":\"%s\",\"frame\":%d,\"count\":%d,\"max_pos_mm\":%.4f,\"mean_pos_mm\":%.4f,"
			"\"p50_pos_mm\":%.4f,\"p95_pos_mm\":%.4f,\"max_rot_deg\":%.4f,\"p95_rot_deg\":%.4f,"
			"\"rot_gt_5deg\":%d,\"bitwise_equal\":%d}\n",
			tag, frame, d.count, d.maxPosMm, d.meanPosMm, d.p50PosMm, d.p95PosMm, d.maxRotDeg, d.p95RotDeg,
			d.rotGt5, d.bitwiseEqual);
	}
}

int main(int argc, char** argv)
{
	std::string pmx = "C:\\pmx\\白银之城—阿芙2.0\\阿芙2.0.pmx";
	std::string vmd = "C:\\vmd\\Stay Tonight Heaven Lee Ver. 动作.vmd";
	std::string mode = "shift";
	std::string mmdDataDir;
	int warmup = 200;
	int measure = 60;
	int startFrame = 200;
	int skipEvery = 7;

	for (int i = 1; i < argc; ++i)
	{
		const std::string arg = argv[i];
		auto next = [&](const char* name) -> std::string
		{
			if (i + 1 >= argc)
			{
				std::fprintf(stderr, "missing value for %s\n", name);
				std::exit(2);
			}
			return argv[++i];
		};
		if (arg == "--pmx") pmx = next("--pmx");
		else if (arg == "--vmd") vmd = next("--vmd");
		else if (arg == "--mode") mode = next("--mode");
		else if (arg == "--mmd-data-dir") mmdDataDir = next("--mmd-data-dir");
		else if (arg == "--warmup") warmup = std::atoi(next("--warmup").c_str());
		else if (arg == "--measure") measure = std::atoi(next("--measure").c_str());
		else if (arg == "--start-frame") startFrame = std::atoi(next("--start-frame").c_str());
		else if (arg == "--skip-every") skipEvery = std::atoi(next("--skip-every").c_str());
	}

	std::printf("{\"event\":\"config\",\"mode\":\"%s\",\"warmup\":%d,\"measure\":%d,\"start_frame\":%d,\"fps\":%.1f}\n",
		mode.c_str(), warmup, measure, startFrame, static_cast<double>(kFps));

	auto a = LoadModel(pmx, vmd, mmdDataDir);
	auto b = LoadModel(pmx, vmd, mmdDataDir);
	if (!a || !b)
	{
		std::fprintf(stderr, "model load failed\n");
		return 1;
	}
	std::printf("{\"event\":\"loaded\",\"rigid_a\":%zu,\"rigid_b\":%zu}\n", a->RigidCount(), b->RigidCount());
	if (a->RigidCount() == 0 || a->RigidCount() != b->RigidCount())
		return 3;

	// 把物理世界重新拉回冷起步：A 从第 0 帧一路推进；B 按模式决定何时开始推进。
	const int firstFrame = 0;
	std::vector<Sample> ref;   // A 的历史，索引 = frame - firstFrame
	ref.reserve(static_cast<std::size_t>(warmup + measure + 8));

	// 命中矩阵：lag 0..4 的逐位相等刚体数（只对 shift 模式有意义）
	std::vector<std::array<int, 5>> lagHits;
	lagHits.reserve(static_cast<std::size_t>(measure));

	for (int frame = firstFrame; frame < warmup + measure; ++frame)
	{
		a->Step(static_cast<float>(frame), kDt);
		ref.push_back(a->Snapshot());

		const bool measuring = frame >= warmup;
		const int outFrame = frame;

		Diff d;
		const char* tag = mode.c_str();

		if (mode == "lag" || mode == "shift")
		{
			b->Step(std::max(0.0f, static_cast<float>(frame) - 1.0f), kDt);
			const Sample s = b->Snapshot();
			if (mode == "lag")
				d = Compare(ref.back(), s);
			else
			{
				const int idx = frame - 1 - firstFrame;
				d = (idx >= 0) ? Compare(ref[static_cast<std::size_t>(idx)], s) : Compare(ref.back(), s);
			}

			if (measuring)
			{
				std::array<int, 5> hits{};
				for (int lag = 0; lag <= 4; ++lag)
				{
					const int idx = frame - lag - firstFrame;
					if (idx >= 0)
						hits[static_cast<std::size_t>(lag)] = Compare(ref[static_cast<std::size_t>(idx)], s).bitwiseEqual;
				}
				lagHits.push_back(hits);
			}
		}
		else if (mode == "initcold")
		{
			if (frame >= warmup)
				b->Step(static_cast<float>(frame), kDt);
			const Sample s = b->Snapshot();
			if (measuring)
				d = Compare(ref.back(), s);
		}
		else if (mode == "delay")
		{
			// 与 A 完全相同的步数与输入序列，仅整体延后一帧：帧 f 用 pose(f-1)，f=0 不步进。
			if (frame >= 1)
				b->Step(static_cast<float>(frame - 1), kDt);
			const Sample s = b->Snapshot();
			if (measuring)
			{
				const int idx = frame - 1 - firstFrame;
				d = (idx >= 0) ? Compare(ref[static_cast<std::size_t>(idx)], s) : Compare(ref.back(), s);
			}
		}
		else if (mode == "skip")
		{
			// 模拟 async 背压丢帧：每 skipEvery 帧漏一次步且不补（no catch-up）。
			const float elapsed = ((skipEvery > 0) && ((frame % skipEvery) == 0)) ? 0.0f : kDt;
			b->Step(static_cast<float>(frame), elapsed);
			const Sample s = b->Snapshot();
			if (measuring)
				d = Compare(ref.back(), s);
		}
		else if (mode == "dt")
		{
			// 每帧 1/30 的双倍与零交替：累加器总时间相同，但离散步进相位不同。
			const float elapsed = ((frame % 2) == 0) ? (2.0f * kDt) : 0.0f;
			b->Step(static_cast<float>(frame), elapsed);
			const Sample s = b->Snapshot();
			if (measuring)
				d = Compare(ref.back(), s);
		}
		else
		{
			std::fprintf(stderr, "unknown mode: %s\n", mode.c_str());
			return 2;
		}

		if (measuring)
			PrintRow(tag, outFrame, d);
	}

	if (!lagHits.empty())
	{
		for (int lag = 0; lag <= 4; ++lag)
		{
			int exactFrames = 0;
			int totalEqual = 0;
			for (const auto& hits : lagHits)
			{
				if (hits[static_cast<std::size_t>(lag)] == a->RigidCount())
					++exactFrames;
				totalEqual += hits[static_cast<std::size_t>(lag)];
			}
			std::printf("{\"event\":\"lag_summary\",\"lag\":%d,\"exact_frames\":%d,\"frames\":%zu,"
				"\"mean_equal_bodies\":%.2f}\n",
				lag, exactFrames, lagHits.size(),
				static_cast<double>(totalEqual) / static_cast<double>(lagHits.size()));
		}
	}

	return 0;
}


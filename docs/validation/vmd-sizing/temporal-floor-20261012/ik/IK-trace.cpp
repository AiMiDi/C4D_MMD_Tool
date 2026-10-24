#include <iostream>
#include <iomanip>
extern bool floorIKTrace;
//
// Copyright(c) 2016-2017 benikabocha.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)
//

#include "MMDIkSolver.h"

#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <unordered_set>
#include <Eigen/Core>
#include <Eigen/Geometry>

namespace libmmd
{
	namespace
	{
		constexpr size_t kInvalidPathIndex = static_cast<size_t>(-1);

		/** Match reze-engine: max rotation step scales with the IK link index. */
		inline float IkChainAngleLimit(float unitAngle, size_t chainIndex)
		{
			const float scaled = unitAngle * static_cast<float>(chainIndex + 1);
			constexpr float pi = static_cast<float>(EIGEN_PI);
			return std::min(pi, scaled);
		}

		Eigen::Vector3f StablePerpendicularAxis(const Eigen::Vector3f& v)
		{
			const Eigen::Vector3f basis = std::abs(v.x()) < 0.75f
				? Eigen::Vector3f::UnitX()
				: Eigen::Vector3f::UnitY();
			Eigen::Vector3f axis = v.cross(basis);
			if (axis.squaredNorm() < 1.0e-12f)
				axis = v.cross(Eigen::Vector3f::UnitZ());
			return axis.normalized();
		}

		float StableAngleBetween(const Eigen::Vector3f& first, const Eigen::Vector3f& second)
		{
			// acos of a normalized float dot loses small angles near parallel links.
			// Use the original vectors and double products to preserve those angles
			// without making the result depend on the model's uniform scale.
			const Eigen::Vector3d a = first.cast<double>();
			const Eigen::Vector3d b = second.cast<double>();
			return static_cast<float>(std::atan2(a.cross(b).norm(), a.dot(b)));
		}

		bool BuildPathFromAncestor(IMMDNode* ancestor, IMMDNode* node, std::vector<IMMDNode*>& outPath)
		{
			outPath.clear();
			if (ancestor == nullptr || node == nullptr)
			{
				return false;
			}

			std::vector<IMMDNode*> reversePath;
			for (IMMDNode* current = node; current != nullptr; current = current->GetParent())
			{
				reversePath.push_back(current);
				if (current == ancestor)
				{
					outPath.assign(reversePath.rbegin(), reversePath.rend());
					return true;
				}
			}

			return false;
		}
	}

	MMDIkSolver::MMDIkSolver()
		: m_ikNode(nullptr)
		, m_ikTarget(nullptr)
		, m_iterateCount(1)
		, m_limitAngle(2.0f * static_cast<float>(EIGEN_PI))
		, m_enable(true)
		, m_baseAnimEnable(true)
		, m_updateRoot(nullptr)
	{
	}

	void MMDIkSolver::AddIKChain(IMMDNode * node, const bool isKnee)
	{
		InvalidateChainPathCache();
		// Matches benikabocha/saba knee IK limits (radians): min ≈ 0.5°, max = 180°.
		constexpr float pi = static_cast<float>(EIGEN_PI);
		const float knee_min_x = (0.5f * pi) / 180.0f;
		const float knee_max_x = pi;
		m_chains.emplace_back(node,
			isKnee,
			isKnee ? Eigen::Vector3f(knee_min_x, 0.0f, 0.0f) : Eigen::Vector3f::Zero(),
			isKnee ? Eigen::Vector3f(knee_max_x, 0.0f, 0.0f) : Eigen::Vector3f::Zero(),
			Eigen::Quaternionf::Identity());
	}

	void MMDIkSolver::AddIKChain(
		IMMDNode * node,
		const bool axisLimit,
		const Eigen::Vector3f & limitMin,
		const Eigen::Vector3f & limitMax
	)
	{
		InvalidateChainPathCache();
		m_chains.emplace_back(node, axisLimit, limitMin, limitMax, Eigen::Quaternionf::Identity());
	}

	void MMDIkSolver::BuildChainPath()
	{
		InvalidateChainPathCache();

		if (!m_ikNode || !m_ikTarget || m_chains.empty())
			return;

		std::unordered_set<IMMDNode*> chainNodeSet;
		for (const auto& chain : m_chains)
		{
			chainNodeSet.insert(chain.m_node);
		}

		// Find the highest chain node by walking upward from both endpoints.
		// In PMX convention m_ikNode is the external control bone and
		// m_ikTarget is the effector (descendant of the chain), so the walk
		// from m_ikTarget is the one that typically discovers the chain nodes.
		auto findRoot = [&](IMMDNode* start)
		{
			for (IMMDNode* cur = start; cur != nullptr; cur = cur->GetParent())
			{
				if (chainNodeSet.count(cur))
					m_updateRoot = cur;
			}
		};
		findRoot(m_ikTarget);
		if (!m_updateRoot)
			findRoot(m_ikNode);

		if (m_updateRoot == nullptr)
			return;

		// Build paths from the update root to each node.  Either path may
		// fail when the node is not a descendant of m_updateRoot (e.g. the
		// external IK control bone lives in a different branch).
		BuildPathFromAncestor(m_updateRoot, m_ikNode, m_ikPath);
		BuildPathFromAncestor(m_updateRoot, m_ikTarget, m_targetPath);

		if (m_ikPath.empty() && m_targetPath.empty())
		{
			InvalidateChainPathCache();
			return;
		}

		m_targetPathIndices.assign(m_chains.size(), kInvalidPathIndex);
		m_ikPathIndices.assign(m_chains.size(), kInvalidPathIndex);
		for (size_t ci = 0; ci < m_chains.size(); ci++)
		{
			for (size_t pi = 0; pi < m_targetPath.size(); pi++)
			{
				if (m_targetPath[pi] == m_chains[ci].m_node)
				{
					m_targetPathIndices[ci] = pi;
					break;
				}
			}

			for (size_t pi = 0; pi < m_ikPath.size(); pi++)
			{
				if (m_ikPath[pi] == m_chains[ci].m_node)
				{
					m_ikPathIndices[ci] = pi;
					break;
				}
			}
		}
	}

	void MMDIkSolver::UpdatePathGlobalTransform(const std::vector<IMMDNode*>& path, size_t fromPathIdx)
	{
		for (size_t i = fromPathIdx; i < path.size(); i++)
		{
			IMMDNode* node = path[i];
			IMMDNode* parent = node->GetParent();
			if (parent)
				node->SetGlobalTransform(parent->GetGlobalTransform() * node->GetLocalTransform());
			else
				node->SetGlobalTransform(node->GetLocalTransform());
		}
	}

	void MMDIkSolver::UpdateTrackedGlobalTransforms()
	{
		if (!m_ikPath.empty())
		{
			UpdatePathGlobalTransform(m_ikPath, 0);
		}

		if (!m_targetPath.empty())
		{
			UpdatePathGlobalTransform(m_targetPath, 0);
		}

		for (size_t chainIdx = 0; chainIdx < m_chains.size(); chainIdx++)
		{
			if (m_targetPathIndices[chainIdx] == kInvalidPathIndex &&
				m_ikPathIndices[chainIdx] == kInvalidPathIndex)
			{
				m_chains[chainIdx].m_node->UpdateGlobalTransform();
			}
		}
	}

	void MMDIkSolver::UpdateTrackedGlobalTransforms(size_t chainIdx)
	{
		bool updatedTrackedPath = false;

		if (m_ikPathIndices[chainIdx] != kInvalidPathIndex)
		{
			UpdatePathGlobalTransform(m_ikPath, m_ikPathIndices[chainIdx]);
			updatedTrackedPath = true;
		}

		if (m_targetPathIndices[chainIdx] != kInvalidPathIndex)
		{
			UpdatePathGlobalTransform(m_targetPath, m_targetPathIndices[chainIdx]);
			updatedTrackedPath = true;
		}

		if (!updatedTrackedPath)
		{
			m_chains[chainIdx].m_node->UpdateGlobalTransform();
		}
	}

	void MMDIkSolver::Solve()
	{
		if (!m_enable)
		{
			return;
		}

		if (m_ikNode == nullptr || m_ikTarget == nullptr)
		{
			return;
		}

		const bool useTrackedPaths = !m_ikPath.empty() || !m_targetPath.empty();

		for (auto& chain : m_chains)
		{
			chain.m_prevAngle = Eigen::Vector3f::Zero();
			chain.m_node->SetIKRotate(Eigen::Quaternionf::Identity());
			chain.m_planeModeAngle = 0;
			chain.m_node->UpdateLocalTransform();
		}

		if (useTrackedPaths)
			UpdateTrackedGlobalTransforms();
		else
			for (auto& chain : m_chains)
				chain.m_node->UpdateGlobalTransform();

		constexpr float kSolveDistanceEpsilon = 1.0e-5f;
		for (uint32_t i = 0; i < m_iterateCount; i++)
		{
			SolveCore(i);

			const Eigen::Vector3f targetPos = m_ikTarget->GetGlobalTransform().col(3).head<3>();
			const Eigen::Vector3f ikPos = m_ikNode->GetGlobalTransform().col(3).head<3>();
			const float dist = (targetPos - ikPos).norm();
            if (floorIKTrace && m_ikNode->GetName() == "左足ＩＫ") {
                std::cerr << std::setprecision(12) << "iter," << ikPos.y() << ',' << i << ',' << dist << ',' << targetPos.x() << ',' << targetPos.y() << ',' << targetPos.z();
                for (const auto& chain : m_chains) { const auto p=chain.m_node->GetGlobalTransform().col(3).head<3>(); const auto q=chain.m_node->GetIKRotate(); std::cerr << ',' << p.y() << ',' << p.z() << ',' << q.x() << ',' << q.y() << ',' << q.z() << ',' << q.w(); }
                std::cerr << '\n';
            }

			if (!std::isfinite(dist))
				break;
			if (dist < kSolveDistanceEpsilon)
				break;
		}

		if (useTrackedPaths)
			m_updateRoot->UpdateGlobalTransform();
	}

	namespace
	{
		float NormalizeAngle(const float angle)
		{
			constexpr float two_pi = 2.0f * static_cast<float>(EIGEN_PI);
			float ret = angle;
			while (ret >= two_pi)
			{
				ret -= two_pi;
			}
			while (ret < 0)
			{
				ret += two_pi;
			}

			return ret;
		}

		float DiffAngle(const float a, const float b)
		{
			constexpr float pi_f = static_cast<float>(EIGEN_PI);
			constexpr float two_pi = 2.0f * static_cast<float>(EIGEN_PI);
			const float diff = NormalizeAngle(a) - NormalizeAngle(b);
			if (diff > pi_f)
			{
				return diff - two_pi;
			}
			if (diff < -pi_f)
			{
				return diff + two_pi;
			}
			return diff;
		}

		Eigen::Vector3f Decompose(const Eigen::Matrix3f& m, const Eigen::Vector3f& before)
		{
			constexpr float pi_f = static_cast<float>(EIGEN_PI);
			Eigen::Vector3f r;
			float sy = -m(2, 0);
			constexpr float e = 1.0e-6f;
			if (1.0f - std::abs(sy) < e)
			{
				r.y() = std::asin(sy);
				// 180°に近いほうを探す
				float sx = std::sin(before.x());
				float sz = std::sin(before.z());
				if (std::abs(sx) < std::abs(sz))
				{
					// Xのほうが0または180
					float cx = std::cos(before.x());
					if (cx > 0)
					{
						r.x() = 0;
						r.z() = std::asin(-m(0, 1));
					}
					else
					{
						r.x() = pi_f;
						r.z() = std::asin(m(0, 1));
					}
				}
				else
				{
					float cz = std::cos(before.z());
					if (cz > 0)
					{
						r.z() = 0;
						r.x() = std::asin(-m(1, 2));
					}
					else
					{
						r.z() = pi_f;
						r.x() = std::asin(m(1, 2));
					}
				}
			}
			else
			{
				r.x() = std::atan2(m(2, 1), m(2, 2));
				r.y() = std::asin(-m(2, 0));
				r.z() = std::atan2(m(1, 0), m(0, 0));
			}

			Eigen::Vector3f tests[] =
			{
				Eigen::Vector3f(r.x() + pi_f, pi_f - r.y(), r.z() + pi_f),
				Eigen::Vector3f(r.x() + pi_f, pi_f - r.y(), r.z() - pi_f),
				Eigen::Vector3f(r.x() + pi_f, -pi_f - r.y(), r.z() + pi_f),
				Eigen::Vector3f(r.x() + pi_f, -pi_f - r.y(), r.z() - pi_f),
				Eigen::Vector3f(r.x() - pi_f, pi_f - r.y(), r.z() + pi_f),
				Eigen::Vector3f(r.x() - pi_f, pi_f - r.y(), r.z() - pi_f),
				Eigen::Vector3f(r.x() - pi_f, -pi_f - r.y(), r.z() + pi_f),
				Eigen::Vector3f(r.x() - pi_f, -pi_f - r.y(), r.z() - pi_f),
			};

			float errX = std::abs(DiffAngle(r.x(), before.x()));
			float errY = std::abs(DiffAngle(r.y(), before.y()));
			float errZ = std::abs(DiffAngle(r.z(), before.z()));
			float minErr = errX + errY + errZ;
			for (const auto test : tests)
			{
				float err = std::abs(DiffAngle(test.x(), before.x()))
					+ std::abs(DiffAngle(test.y(), before.y()))
					+ std::abs(DiffAngle(test.z(), before.z()));
				if (err < minErr)
				{
					minErr = err;
					r = test;
				}
			}
			return r;
		}
	}

	void MMDIkSolver::SolveCore(uint32_t iteration)
	{
		for (size_t chainIdx = m_chains.size(); chainIdx > 0; --chainIdx)
		{
			auto& chain = m_chains[chainIdx - 1];
			const size_t chainListIdx = chainIdx - 1;
			const float angleLimitThisChain = IkChainAngleLimit(m_limitAngle, chainListIdx);
			IMMDNode* chainNode = chain.m_node;
			if (chainNode == m_ikTarget || chainNode == m_ikNode)
			{
				continue;
			}

			if (chain.m_enableAxisLimit)
			{
				if ((chain.m_limitMin.x() != 0 || chain.m_limitMax.x() != 0) &&
					(chain.m_limitMin.y() == 0 || chain.m_limitMax.y() == 0) &&
					(chain.m_limitMin.z() == 0 || chain.m_limitMax.z() == 0)
					)
				{
					SolvePlane(iteration, chainListIdx, SolveAxis::X);
					continue;
				}
				if ((chain.m_limitMin.y() != 0 || chain.m_limitMax.y() != 0) &&
					(chain.m_limitMin.x() == 0 || chain.m_limitMax.x() == 0) &&
					(chain.m_limitMin.z() == 0 || chain.m_limitMax.z() == 0)
					)
				{
					SolvePlane(iteration, chainListIdx, SolveAxis::Y);
					continue;
				}
				if ((chain.m_limitMin.z() != 0 || chain.m_limitMax.z() != 0) &&
					(chain.m_limitMin.x() == 0 || chain.m_limitMax.x() == 0) &&
					(chain.m_limitMin.y() == 0 || chain.m_limitMax.y() == 0)
				)
				{
					SolvePlane(iteration, chainListIdx, SolveAxis::Z);
					continue;
				}
			}

			Eigen::Vector3f ikPos = m_ikNode->GetGlobalTransform().col(3).head<3>();
			Eigen::Vector3f targetPos = m_ikTarget->GetGlobalTransform().col(3).head<3>();

			const Eigen::Matrix4f& chainGlobal = chain.m_node->GetGlobalTransform();
			Eigen::Matrix3f Rt = chainGlobal.block<3,3>(0,0).transpose();
			Eigen::Vector3f tVec = chainGlobal.block<3,1>(0,3);
			Eigen::Vector3f chainIkPos = Rt * (ikPos - tVec);
			Eigen::Vector3f chainTargetPos = Rt * (targetPos - tVec);
			if (chainIkPos.squaredNorm() < 1.0e-12f || chainTargetPos.squaredNorm() < 1.0e-12f)
				continue;

			Eigen::Vector3f chainIkVec = chainIkPos.normalized();
			Eigen::Vector3f chainTargetVec = chainTargetPos.normalized();

			float angle = StableAngleBetween(chainTargetPos, chainIkPos);
            if (floorIKTrace && m_ikNode->GetName() == "左足ＩＫ" && iteration >= 90)
                std::cerr << "angle," << ikPos.y() << ',' << iteration << ',' << chainListIdx << ',' << angle << ',' << (angle < 1.75e-5f) << '\n';

			if (angle < 1.75e-5f)
			{
				continue;
			}
			angle = std::clamp(angle, -angleLimitThisChain, angleLimitThisChain);

			// CCD cross product: the descendant of this chain node moves with
			// rotation; the external node stays fixed.  We need to rotate the
			// descendant direction toward the external direction.
			// cross = descendant_dir x external_dir
			const bool ikIsDescendant = !m_ikPathIndices.empty() &&
				m_ikPathIndices[chainListIdx] != kInvalidPathIndex;
			const bool targetIsDescendant = !m_targetPathIndices.empty() &&
				m_targetPathIndices[chainListIdx] != kInvalidPathIndex;
			const Eigen::Vector3f& descendantVec = (targetIsDescendant && !ikIsDescendant) ? chainTargetVec : chainIkVec;
			Eigen::Vector3f cross;
			if (targetIsDescendant && !ikIsDescendant)
				cross = chainTargetVec.cross(chainIkVec);
			else
				cross = chainIkVec.cross(chainTargetVec);
			if (cross.squaredNorm() < 1.0e-12f)
				cross = StablePerpendicularAxis(descendantVec);
			else
				cross.normalize();
			Eigen::Quaternionf rot = Eigen::Quaternionf(Eigen::AngleAxisf(angle, cross));

			Eigen::Quaternionf chainRot = chainNode->GetIKRotate() * chainNode->AnimateRotate() * rot;
			if (chain.m_enableAxisLimit)
			{
				Eigen::Matrix3f chainRotM = chainRot.toRotationMatrix();
				auto rotXYZ = Decompose(chainRotM, chain.m_prevAngle);
				Eigen::Vector3f clampXYZ;
				clampXYZ = rotXYZ.cwiseMax(chain.m_limitMin).cwiseMin(chain.m_limitMax);

				clampXYZ = (clampXYZ - chain.m_prevAngle).cwiseMax(-angleLimitThisChain).cwiseMin(angleLimitThisChain) + chain.m_prevAngle;
				Eigen::Quaternionf r = Eigen::Quaternionf(Eigen::AngleAxisf(clampXYZ.x(), Eigen::Vector3f(1, 0, 0)));
				r = r * Eigen::Quaternionf(Eigen::AngleAxisf(clampXYZ.y(), Eigen::Vector3f(0, 1, 0)));
				r = r * Eigen::Quaternionf(Eigen::AngleAxisf(clampXYZ.z(), Eigen::Vector3f(0, 0, 1)));
				chainRotM = r.toRotationMatrix();
				chain.m_prevAngle = clampXYZ;

				chainRot = Eigen::Quaternionf(chainRotM);
			}

			Eigen::Quaternionf ikRot = chainRot * chainNode->AnimateRotate().inverse();
			chainNode->SetIKRotate(ikRot);
			chainNode->UpdateLocalTransform();
			if (m_updateRoot)
				UpdateTrackedGlobalTransforms(chainListIdx);
			else
				chainNode->UpdateGlobalTransform();
		}
	}

	void MMDIkSolver::SolvePlane(uint32_t iteration, size_t chainIdx, SolveAxis solveAxis)
	{
		const float planeAngleLimit = IkChainAngleLimit(m_limitAngle, chainIdx);

		int RotateAxisIndex = 0;
		Eigen::Vector3f RotateAxis = Eigen::Vector3f(1, 0, 0);
		switch (solveAxis)
		{
		case SolveAxis::X:
			RotateAxisIndex = 0;
			RotateAxis = Eigen::Vector3f(1, 0, 0);
			break;
		case SolveAxis::Y:
			RotateAxisIndex = 1;
			RotateAxis = Eigen::Vector3f(0, 1, 0);
			break;
		case SolveAxis::Z:
			RotateAxisIndex = 2;
			RotateAxis = Eigen::Vector3f(0, 0, 1);
			break;
		default:
			break;
		}

		auto& chain = m_chains[chainIdx];
		Eigen::Vector3f ikPos = m_ikNode->GetGlobalTransform().col(3).head<3>();
		Eigen::Vector3f targetPos = m_ikTarget->GetGlobalTransform().col(3).head<3>();

		const Eigen::Matrix4f& chainGlobal = chain.m_node->GetGlobalTransform();
		Eigen::Matrix3f Rt = chainGlobal.block<3,3>(0,0).transpose();
		Eigen::Vector3f tVec = chainGlobal.block<3,1>(0,3);
		Eigen::Vector3f chainIkPos = Rt * (ikPos - tVec);
		Eigen::Vector3f chainTargetPos = Rt * (targetPos - tVec);
		if (chainIkPos.squaredNorm() < 1.0e-12f || chainTargetPos.squaredNorm() < 1.0e-12f)
			return;

		Eigen::Vector3f chainIkVec = chainIkPos.normalized();
		Eigen::Vector3f chainTargetVec = chainTargetPos.normalized();

		float angle = StableAngleBetween(chainTargetPos, chainIkPos);
            if (floorIKTrace && m_ikNode->GetName() == "左足ＩＫ" && iteration >= 90)
                std::cerr << "angle," << ikPos.y() << ',' << iteration << ',' << chainIdx << ',' << angle << ',' << (angle < 1.75e-5f) << '\n';
		angle = std::clamp(angle, -planeAngleLimit, planeAngleLimit);

		// The descendant moves with chain rotation; the external stays fixed.
		// Test both rotation directions by checking alignment of the rotated
		// descendant direction with the external direction.
		const bool ikIsDescendant = !m_ikPathIndices.empty() &&
			m_ikPathIndices[chainIdx] != kInvalidPathIndex;
		const bool targetIsDescendant = !m_targetPathIndices.empty() &&
			m_targetPathIndices[chainIdx] != kInvalidPathIndex;
		const Eigen::Vector3f& descendantVec = (targetIsDescendant && !ikIsDescendant) ? chainTargetVec : chainIkVec;
		const Eigen::Vector3f& externalVec = (targetIsDescendant && !ikIsDescendant) ? chainIkVec : chainTargetVec;

		Eigen::Quaternionf rot1 = Eigen::Quaternionf(Eigen::AngleAxisf(angle, RotateAxis));
		float dot1 = (rot1 * descendantVec).dot(externalVec);

		Eigen::Quaternionf rot2 = Eigen::Quaternionf(Eigen::AngleAxisf(-angle, RotateAxis));
		float dot2 = (rot2 * descendantVec).dot(externalVec);

		float newAngle = chain.m_planeModeAngle;
		if (dot1 > dot2)
		{
			newAngle += angle;
		}
		else
		{
			newAngle -= angle;
		}

		if (iteration == 0)
		{
			if (newAngle < chain.m_limitMin[RotateAxisIndex] || newAngle > chain.m_limitMax[RotateAxisIndex])
			{
				if (-newAngle > chain.m_limitMin[RotateAxisIndex] && -newAngle < chain.m_limitMax[RotateAxisIndex])
				{
					newAngle *= -1;
				}
				else
				{
					auto halfRad = (chain.m_limitMin[RotateAxisIndex] + chain.m_limitMax[RotateAxisIndex]) * 0.5f;
					if (std::abs(halfRad - newAngle) > std::abs(halfRad + newAngle))
					{
						newAngle *= -1;
					}
				}
			}
		}

		newAngle = std::clamp(newAngle, chain.m_limitMin[RotateAxisIndex], chain.m_limitMax[RotateAxisIndex]);
		chain.m_planeModeAngle = newAngle;

		Eigen::Quaternionf ikRotM = Eigen::Quaternionf(Eigen::AngleAxisf(newAngle, RotateAxis)) * chain.m_node->AnimateRotate().inverse();
		chain.m_node->SetIKRotate(ikRotM);

		chain.m_node->UpdateLocalTransform();
		if (m_updateRoot)
			UpdateTrackedGlobalTransforms(chainIdx);
		else
			chain.m_node->UpdateGlobalTransform();
	}
}

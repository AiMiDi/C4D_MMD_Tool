#include "MMDMotionLegs.h"
#include <algorithm>
#include <cmath>
#include <Eigen/Cholesky>

namespace libmmd::sizing::detail
{
namespace
{
struct Capsule { Vector start, end; double radius; };
std::vector<double> FootIKErrors(const Pose& pose, const std::vector<int>& controls)
{
    std::vector<double> errors;
    for (int control : controls)
        errors.push_back((pose.positions[pose.rig.model.m_bones[control].m_ikTargetBoneIndex] - pose.positions[control]).norm());
    return errors;
}

bool PreservesFootIK(const Pose& pose, const std::vector<int>& controls, const std::vector<double>& before, double tolerance)
{
    const auto after = FootIKErrors(pose, controls);
    for (size_t i = 0; i < controls.size(); ++i)
        if (pose.ikEnabled[controls[i]] && after[i] > before[i] + tolerance) return false;
    return true;
}

Capsule WorldCapsule(const Pose& pose, size_t index)
{
    const auto& body = pose.rig.model.m_rigidbodies[index];
    Rotation rotation(Eigen::AngleAxisd(body.m_rotate.z(), Vector::UnitZ()) *
        Eigen::AngleAxisd(body.m_rotate.y(), Vector::UnitY()) * Eigen::AngleAxisd(body.m_rotate.x(), Vector::UnitX()));
    Vector center = body.m_translate.cast<double>();
    if (body.m_boneIndex >= 0)
    {
        center = pose.positions[body.m_boneIndex] + pose.rotations[body.m_boneIndex] *
            (center - pose.rig.model.m_bones[body.m_boneIndex].m_position.cast<double>());
        rotation = pose.rotations[body.m_boneIndex] * rotation;
    }
    const double halfLength = body.m_shape == libmmd::PMXRigidbody::Shape::Capsule ? body.m_shapeSize.y() * .5 : 0.;
    const Vector axis = rotation * (Vector::UnitY() * halfLength);
    return {center - axis, center + axis, body.m_shapeSize.x()};
}

std::pair<Vector, Vector> ClosestPoints(const Capsule& first, const Capsule& second)
{
    const Vector u = first.end - first.start, v = second.end - second.start, w = first.start - second.start;
    const double a = u.squaredNorm(), b = u.dot(v), c = v.squaredNorm(), d = u.dot(w), e = v.dot(w);
    double s = 0., t = 0.;
    if (a <= 1.e-16) t = c > 1.e-16 ? std::clamp(e / c, 0., 1.) : 0.;
    else if (c <= 1.e-16) s = std::clamp(-d / a, 0., 1.);
    else
    {
        const double denominator = a * c - b * b;
        if (denominator > 1.e-16) s = std::clamp((b * e - c * d) / denominator, 0., 1.);
        t = (b * s + e) / c;
        if (t < 0.) { t = 0.; s = std::clamp(-d / a, 0., 1.); }
        else if (t > 1.) { t = 1.; s = std::clamp((b - d) / a, 0., 1.); }
    }
    return {first.start + s * u, second.start + t * v};
}
}

std::vector<LegPair> LegCollisionPairs(const Rig& rig)
{
    std::vector<size_t> sides[2];
    for (int side = 0; side < 2; ++side)
        for (const auto* part : {"足", "ひざ"})
        {
            const std::string name = std::string(side == 0 ? "左" : "右") + part;
            const int bone = rig.Find(name);
            if (bone < 0 || !rig.SupportedChain(bone)) continue;
            // Canonical limb colliders only: duplicate hip/skirt accessory
            // bodies can intentionally overlap at the crotch even in bind pose.
            for (size_t i = 0; i < rig.model.m_rigidbodies.size(); ++i)
            {
                const auto& body = rig.model.m_rigidbodies[i];
                if (body.m_name != name || body.m_boneIndex != bone || body.m_op != libmmd::PMXRigidbody::Operation::Static ||
                    (body.m_shape != libmmd::PMXRigidbody::Shape::Capsule && body.m_shape != libmmd::PMXRigidbody::Shape::Sphere)) continue;
                Require(body.m_shapeSize.allFinite() && (body.m_shapeSize.array() >= 0).all() &&
                    body.m_translate.allFinite() && body.m_rotate.allFinite(), "Invalid leg collider: " + name);
                sides[side].push_back(i); break;
            }
        }
    std::vector<LegPair> pairs;
    for (size_t left : sides[0]) for (size_t right : sides[1]) pairs.push_back({left, right});
    return pairs;
}

std::vector<double> LegPenetrations(const Pose& pose, const std::vector<LegPair>& pairs, double margin)
{
    std::vector<double> depths;
    for (const auto& pair : pairs)
    {
        const auto left = WorldCapsule(pose, pair.left), right = WorldCapsule(pose, pair.right);
        const auto points = ClosestPoints(left, right);
        depths.push_back(std::max(0., left.radius + right.radius + margin - (points.first - points.second).norm()));
    }
    return depths;
}

void ApplyLegAvoidance(const Rig& rig, libmmd::VMDFile& motion, const Options& options, Analysis& analysis,
                       const std::atomic_bool* cancel, const ProgressCallback& progress)
{
    const auto pairs = LegCollisionPairs(rig);
    std::vector<int> controls;
    double length = 0.;
    for (const std::string side : {"左", "右"})
    {
        const int control = rig.Find(side + "足ＩＫ"), hip = rig.Find(side + "足"), knee = rig.Find(side + "ひざ"), ankle = rig.Find(side + "足首");
        if (control < 0 || hip < 0 || knee < 0 || ankle < 0 || !rig.SupportedChain(control)) continue;
        const auto& bone = rig.model.m_bones[control];
        if ((static_cast<uint16_t>(bone.m_boneFlag) & 0x324u) != 0x24u || bone.m_ikTargetBoneIndex != ankle ||
            rig.ikAffected[control]) continue;
        const auto hasLink = [&](int index) {
            return std::any_of(bone.m_ikLinks.begin(), bone.m_ikLinks.end(),
                [&](const auto& link) { return link.m_ikBoneIndex == index; });
        };
        if (!hasLink(hip) || !hasLink(knee) || !rig.SupportedChain(ankle)) continue;
        controls.push_back(control);
        length += (rig.model.m_bones[hip].m_position - rig.model.m_bones[knee].m_position).norm() +
                  (rig.model.m_bones[knee].m_position - rig.model.m_bones[ankle].m_position).norm();
    }
    if (controls.size() != 2 || pairs.empty())
    {
        analysis.warnings.push_back("Leg avoidance skipped: requires two standard foot IK chains and canonical static leg capsules/spheres");
        return;
    }
    const double budget = length * .04; // Eight percent of mean leg length per foot.
    const double epsilon = std::max(1.e-4, budget * .005);
    const Motion input(motion);
    const uint32_t last = BakeLimit(input, options, controls.size());
    std::vector<Eigen::Vector4d> corrections;
    corrections.reserve(size_t(last) + 1);
    Baker baker;
    for (uint32_t frame = 0; frame <= last; ++frame)
    {
        CheckCancel(cancel);
        ReportProgress(progress, ProgressPhase::LegAvoidance, frame, 2 * (uint64_t(last) + 1));
        Pose pose(rig, input, frame);
        const auto original = pose.local;
        const auto footErrors = FootIKErrors(pose, controls);
        std::vector<Rotation> parentRotations;
        for (int control : controls)
        {
            const int parent = rig.model.m_bones[control].m_parentBoneIndex;
            parentRotations.push_back(parent < 0 ? Rotation::Identity() : pose.rotations[parent]);
        }
        Eigen::Vector4d offset = Eigen::Vector4d::Zero();
        const auto evaluate = [&](const Eigen::Vector4d& value) {
            pose.local = original;
            for (size_t i = 0; i < controls.size(); ++i)
                if (pose.ikEnabled[controls[i]])
                    pose.local[controls[i]].translation += parentRotations[i].conjugate() * Vector(value[i * 2], 0., value[i * 2 + 1]);
            pose.Update();
            const auto depths = LegPenetrations(pose, pairs, options.collisionMargin);
            Eigen::VectorXd residual(static_cast<Eigen::Index>(depths.size()));
            for (size_t i = 0; i < depths.size(); ++i) residual[i] = depths[i];
            return residual;
        };
        Eigen::VectorXd residual = evaluate(offset);
        const Eigen::Vector4d previous = corrections.empty() ? Eigen::Vector4d::Zero().eval() : corrections.back();
        const auto objective = [&](const Eigen::VectorXd& depths, const Eigen::Vector4d& correction) {
            return depths.squaredNorm() + .05 * correction.squaredNorm() + .15 * (correction - previous).squaredNorm();
        };
        // Release a completed contact gradually. Carrying the previous value
        // unchanged would leave a permanent foot offset after the crossing.
        Eigen::Vector4d warm = .75 * previous;
        for (size_t i = 0; i < controls.size(); ++i)
            if (!pose.ikEnabled[controls[i]]) warm.segment<2>(i * 2).setZero();
        const auto warmResidual = evaluate(warm);
        if (warmResidual.maxCoeff() <= residual.maxCoeff() + 1.e-6 && objective(warmResidual, warm) < objective(residual, offset) &&
            PreservesFootIK(pose, controls, footErrors, options.tolerance))
        { offset = warm; residual = warmResidual; }
        for (unsigned iteration = 0; iteration < std::min(options.iterations, 16u) && residual.maxCoeff() > options.tolerance; ++iteration)
        {
            CheckCancel(cancel);
            Eigen::MatrixXd jacobian(residual.size(), 4);
            for (int axis = 0; axis < 4; ++axis)
            {
                auto positive = offset, negative = offset;
                positive[axis] += epsilon; negative[axis] -= epsilon;
                jacobian.col(axis) = (evaluate(positive) - evaluate(negative)) / (2. * epsilon);
            }
            // Pose regularization prefers the smallest planar foot displacement.
            Eigen::Matrix4d normal = jacobian.transpose() * jacobian;
            normal.diagonal().array() += .2;
            Eigen::Vector4d step = normal.ldlt().solve(-jacobian.transpose() * residual - .05 * offset - .15 * (offset - previous));
            Require(step.allFinite(), "Non-finite leg avoidance step");
            if (step.norm() > budget * .25) step *= budget * .25 / step.norm();
            bool accepted = false;
            for (int search = 0; search < 8; ++search)
            {
                Eigen::Vector4d candidate = offset + std::ldexp(1., -search) * step;
                for (int foot = 0; foot < 2; ++foot)
                {
                    const double distance = candidate.segment<2>(foot * 2).norm();
                    if (distance > budget) candidate.segment<2>(foot * 2) *= budget / distance;
                }
                const auto next = evaluate(candidate);
                if (objective(next, candidate) < objective(residual, offset) - 1.e-10 &&
                    next.maxCoeff() <= residual.maxCoeff() + 1.e-6 && PreservesFootIK(pose, controls, footErrors, options.tolerance))
                { offset = candidate; residual = next; accepted = true; break; }
            }
            if (!accepted) break;
        }
        corrections.push_back(offset);
    }
    // Independent frame solutions can choose opposite sides of a crossing.
    // Smooth only the correction, never the authored foot trajectory, then
    // re-evaluate IK and reject smoothing that makes the original collision worse.
    for (uint32_t frame = 0; frame <= last; ++frame)
    {
        CheckCancel(cancel);
        ReportProgress(progress, ProgressPhase::LegAvoidance, uint64_t(last) + 1 + frame, 2 * (uint64_t(last) + 1));
        Eigen::Vector4d offset = Eigen::Vector4d::Zero();
        double weightSum = 0.;
        for (int delta = -4; delta <= 4; ++delta)
        {
            const auto sample = std::clamp<int64_t>(int64_t(frame) + delta, 0, last);
            const double weight = 5 - std::abs(delta);
            offset += weight * corrections[size_t(sample)]; weightSum += weight;
        }
        offset /= weightSum;
        Pose pose(rig, input, frame);
        const auto original = pose.local;
        const auto footErrors = FootIKErrors(pose, controls);
        const auto originalDepths = LegPenetrations(pose, pairs, options.collisionMargin);
        const double originalMaximum = *std::max_element(originalDepths.begin(), originalDepths.end());
        std::vector<Rotation> parentRotations;
        for (int control : controls)
        {
            const int parent = rig.model.m_bones[control].m_parentBoneIndex;
            parentRotations.push_back(parent < 0 ? Rotation::Identity() : pose.rotations[parent]);
        }
        std::vector<double> residual;
        for (int search = 0; search <= 8; ++search)
        {
            pose.local = original;
            const double strength = search == 8 ? 0. : std::ldexp(1., -search);
            for (size_t i = 0; i < controls.size(); ++i)
                if (pose.ikEnabled[controls[i]])
                    pose.local[controls[i]].translation += parentRotations[i].conjugate() *
                        Vector(strength * offset[i * 2], 0., strength * offset[i * 2 + 1]);
            pose.Update();
            residual = LegPenetrations(pose, pairs, options.collisionMargin);
            if (*std::max_element(residual.begin(), residual.end()) <= originalMaximum + 1.e-6 &&
                PreservesFootIK(pose, controls, footErrors, options.tolerance)) break;
        }
        for (size_t i = 0; i < pairs.size(); ++i)
        {
            const auto& body = rig.model.m_rigidbodies[pairs[i].left];
            const auto left = WorldCapsule(pose, pairs[i].left), right = WorldCapsule(pose, pairs[i].right);
            const auto points = ClosestPoints(left, right);
            const Vector radial = points.first - points.second;
            const Vector normal = radial.squaredNorm() > 1.e-16 ? radial.normalized().eval() : Vector::UnitX().eval();
            const Vector actual = points.first - normal * left.radius;
            Record(analysis, options, Stage::Avoidance, frame, "Leg capsules: " + body.m_name + "/" +
                rig.model.m_rigidbodies[pairs[i].right].m_name, actual + normal * residual[i], actual);
        }
        for (int control : controls) baker.Store(pose, control, frame);
    }
    baker.Finish(motion);
    ReportProgress(progress, ProgressPhase::LegAvoidance, 2 * (uint64_t(last) + 1), 2 * (uint64_t(last) + 1));
}
}

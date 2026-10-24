#include "MMDMotionFloor.h"
#include "MMDMotionLegs.h"
#include <algorithm>
#include <cmath>
#include <map>
#include <memory>
#include <limits>

namespace libmmd::sizing::detail
{
namespace
{
constexpr uint32_t releaseFrames = 4;

double LegLength(const Rig& rig, const std::string& side)
{
    const int hip = rig.Find(side + "足"), knee = rig.Find(side + "ひざ"), ankle = rig.Find(side + "足首");
    if (hip < 0 || knee < 0 || ankle < 0) return 0.;
    return (rig.model.m_bones[hip].m_position - rig.model.m_bones[knee].m_position).norm() +
           (rig.model.m_bones[knee].m_position - rig.model.m_bones[ankle].m_position).norm();
}

double MoveTowards(double value, double target, double step)
{
    return value + std::clamp(target - value, -step, step);
}

struct FloorFrame
{
    Pose pose;
    std::vector<Rotation> parents;
    std::vector<LocalPose> feet;
    std::vector<double> depths;
    std::vector<double> ikErrors;

    FloorFrame(const Rig& rig, const Motion& raw, const Motion& incoming,
               const std::vector<std::pair<int, int>>& controls,
               const std::vector<LegPair>& pairs, double margin, uint32_t frame) : pose(rig, raw, frame)
    {
        // Keep the completed hand-contact channels, restoring just the foot
        // input channels before evaluating any temporal foot correction.
        for (const auto& control : controls)
            pose.local[control.second] = incoming.Sample(rig.model.m_bones[control.second].m_name, frame);
        pose.Update();
        depths = LegPenetrations(pose, pairs, margin);
        for (const auto& control : controls)
        {
            const int bone = control.second, parent = rig.model.m_bones[bone].m_parentBoneIndex;
            parents.push_back(parent < 0 ? Rotation::Identity() : pose.rotations[parent]);
            feet.push_back(pose.local[bone]);
            const int ankle = rig.model.m_bones[bone].m_ikTargetBoneIndex;
            const bool hasIK = (static_cast<uint16_t>(rig.model.m_bones[bone].m_boneFlag) & 0x20u) != 0;
            ikErrors.push_back(hasIK ? (pose.positions[ankle] - pose.positions[bone]).norm() : 0.);
        }
    }
};
}

void ApplyFloorContinuity(const Rig& source, const Rig& target, const Motion& incoming,
    libmmd::VMDFile& output, const std::vector<std::pair<int, int>>& feet,
    const std::vector<std::vector<FootFloorTarget>>& targets,
    double maximumWithoutFeet, const Options& options, Analysis& analysis, const std::atomic_bool* cancel,
    const ProgressCallback& progress)
{
    if (feet.empty()) return;
    analysis.maxResidual = maximumWithoutFeet;
    const Motion raw(output);
    const uint32_t last = incoming.LastFrame();
    const auto pairs = options.legAvoidance ? LegCollisionPairs(target) : std::vector<LegPair>();
    std::vector<double> steps, previous(feet.size(), 0.);
    std::vector<bool> warned(feet.size(), false);
    for (const auto& foot : feet)
    {
        const std::string side = target.model.m_bones[foot.second].m_name.substr(0, 3);
        const double fromLength = LegLength(source, side), toLength = LegLength(target, side);
        double step = 0.;
        if (fromLength > 1.e-8 && toLength > 1.e-8)
            step = options.contactDistance > 0. ?
                std::min(.02 * toLength, options.contactDistance * toLength / fromLength / releaseFrames) : .02 * toLength;
        steps.push_back(step);
    }
    std::vector<std::vector<double>> chosen(size_t(last) + 1, std::vector<double>(feet.size(), 0.));
    for (uint32_t frame = 0; frame <= last; ++frame)
        for (size_t foot = 0; foot < feet.size(); ++foot) chosen[frame][foot] = targets[frame][foot].correction;

    // At most the current frame and four future frames are retained. A large
    // motion must not allocate a full array of skeletal poses per character.
    std::map<uint32_t, std::unique_ptr<FloorFrame>> cache;
    const auto prepare = [&](uint32_t frame) -> FloorFrame& {
        auto found = cache.find(frame);
        if (found == cache.end())
            found = cache.emplace(frame, std::make_unique<FloorFrame>(target, raw, incoming, feet,
                pairs, options.collisionMargin, frame)).first;
        return *found->second;
    };
    const auto evaluate = [&](FloorFrame& base, const std::vector<double>& corrections, Pose& pose) {
        pose.local = base.pose.local;
        for (size_t foot = 0; foot < feet.size(); ++foot)
        {
            const int control = feet[foot].second;
            pose.local[control] = base.feet[foot];
            // Evaluate the actual float channel that the VMD baker writes.
            pose.local[control].translation = (base.feet[foot].translation +
                base.parents[foot].conjugate() * Vector(0., corrections[foot], 0.)).cast<float>().cast<double>();
        }
        pose.Update();
        const auto depths = LegPenetrations(pose, pairs, options.collisionMargin);
        for (size_t pair = 0; pair < depths.size(); ++pair)
            if (depths[pair] > std::max(base.depths[pair], options.tolerance) + 1.e-8) return false;
        for (size_t foot = 0; foot < feet.size(); ++foot)
        {
            const int control = feet[foot].second;
            const auto& bone = target.model.m_bones[control];
            if ((static_cast<uint16_t>(bone.m_boneFlag) & 0x20u) != 0 && pose.ikEnabled[control] &&
                (pose.positions[bone.m_ikTargetBoneIndex] - pose.positions[control]).norm() > base.ikErrors[foot] + options.tolerance)
                return false;
        }
        return true;
    };
    Baker baker;
    for (uint32_t frame = 0; frame <= last; ++frame)
    {
        CheckCancel(cancel);
        ReportProgress(progress, ProgressPhase::Contact, uint64_t(last) + 1 + frame, 2 * (uint64_t(last) + 1));
        while (!cache.empty() && cache.begin()->first < frame) cache.erase(cache.begin());
        auto& base = prepare(frame);
        Pose pose = base.pose;
        for (size_t foot = 0; foot < feet.size(); ++foot)
        {
            const double rawCorrection = targets[frame][foot].correction, step = steps[foot];
            if (step <= 0. || rawCorrection == 0.) continue;
            double magnitude = std::abs(rawCorrection);
            for (uint32_t ahead = 1; ahead <= releaseFrames && ahead <= last - frame; ++ahead)
            {
                const double future = targets[frame + ahead][foot].correction;
                const double futureMagnitude = rawCorrection * future > 0. ? std::abs(future) : 0.;
                magnitude = std::min(magnitude, futureMagnitude + ahead * step);
            }
            double lower = std::min(0., rawCorrection), upper = std::max(0., rawCorrection);
            if (rawCorrection < 0.) lower = std::max(lower, -magnitude);
            else upper = std::min(upper, magnitude);
            // The previous actual correction came from float VMD channels.
            // A few ulps must not turn a shared interval endpoint into an
            // empty interval and restore a large raw correction. This only
            // accounts for channel rounding in the temporal bound; spatial
            // collision and IK tolerances remain unchanged.
            const Vector vertical = base.parents[foot].conjugate() * Vector::UnitY();
            const Vector channelMagnitude = base.feet[foot].translation.cwiseAbs() +
                vertical.cwiseAbs() * std::abs(rawCorrection);
            const double rounding = 2. * std::numeric_limits<float>::epsilon() *
                (1. + vertical.cwiseAbs().dot(channelMagnitude));
            if (frame > 0)
            {
                lower = std::max(lower, previous[foot] - step - rounding);
                upper = std::min(upper, previous[foot] + step + rounding);
            }
            bool accepted = false;
            if (lower <= upper)
            {
                const double desired = std::clamp(rawCorrection, lower, upper), anchor = std::clamp(0., lower, upper);
                for (int search = 0; search <= 8; ++search)
                {
                    CheckCancel(cancel);
                    const double strength = search == 8 ? 0. : std::ldexp(1., -search);
                    const double candidate = anchor + strength * (desired - anchor);
                    auto corrections = chosen[frame]; corrections[foot] = candidate;
                    if (!evaluate(base, corrections, pose)) continue;
                    // The predicted continuation only releases toward zero;
                    // it never follows yesterday's absolute foot position.
                    double release = candidate;
                    bool releasable = true;
                    for (uint32_t ahead = 1; ahead <= releaseFrames && ahead <= last - frame; ++ahead)
                    {
                        CheckCancel(cancel);
                        release = MoveTowards(release, 0., step);
                        const auto& futureTarget = targets[frame + ahead][foot];
                        if (!futureTarget.active) release = 0.;
                        auto futureCorrections = chosen[frame + ahead]; futureCorrections[foot] = release;
                        auto& futureBase = prepare(frame + ahead); Pose futurePose = futureBase.pose;
                        if (!evaluate(futureBase, futureCorrections, futurePose)) { releasable = false; break; }
                    }
                    if (!releasable) continue;
                    chosen[frame][foot] = candidate; accepted = true; break;
                }
            }
            if (!accepted && !warned[foot])
            {
                // A disconnected IK safety interval cannot be repaired by
                // blending. Keep the guarded spatial solve, not all-zero
                // motion, and expose the unresolved temporal limitation.
                warned[foot] = true;
                analysis.warnings.push_back("Floor continuity limited by IK/collision safety: " + target.model.m_bones[feet[foot].second].m_name);
            }
        }
        if (!evaluate(base, chosen[frame], pose))
        {
            // Independent foot reductions can conflict. Restore the original
            // jointly solved combination before considering the zero pose.
            for (size_t foot = 0; foot < feet.size(); ++foot) chosen[frame][foot] = targets[frame][foot].correction;
            if (!evaluate(base, chosen[frame], pose))
            {
                std::fill(chosen[frame].begin(), chosen[frame].end(), 0.);
                evaluate(base, chosen[frame], pose);
            }
        }
        for (size_t foot = 0; foot < feet.size(); ++foot)
        {
            const int control = feet[foot].second;
            previous[foot] = pose.positions[control].y() - base.pose.positions[control].y();
            if (targets[frame][foot].active)
            {
                const auto& bone = target.model.m_bones[control];
                const int point = (static_cast<uint16_t>(bone.m_boneFlag) & 0x20u) != 0 ? bone.m_ikTargetBoneIndex : control;
                const auto& recorded = targets[frame][foot];
                const double error = (recorded.goal - pose.positions[point]).norm();
                Require(std::isfinite(error), "Non-finite floor continuity residual");
                if (recorded.initialError > options.tolerance) --analysis.unresolved;
                if (error > options.tolerance) ++analysis.unresolved;
                analysis.maxResidual = std::max(analysis.maxResidual, error);
                if (recorded.diagnosticIndex < analysis.samples.size())
                {
                    auto& sample = analysis.samples[recorded.diagnosticIndex];
                    sample.actual = pose.positions[point]; sample.error = error;
                }
            }
            baker.Store(pose, control, frame);
        }
    }
    baker.Finish(output);
    ReportProgress(progress, ProgressPhase::Contact, 2 * (uint64_t(last) + 1), 2 * (uint64_t(last) + 1));
}
}

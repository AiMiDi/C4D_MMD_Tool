#include "libMMD/Model/MMD/MMDMotionSizing.h"
#include "MMDMotionPose.h"
#include "MMDMotionConstraints.h"
#include <algorithm>
#include <filesystem>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>

using namespace libmmd::sizing;
using namespace libmmd::sizing::detail;
namespace fs = std::filesystem;

std::vector<uint8_t> Read(const std::string& path)
{
    std::ifstream stream(fs::u8path(path), std::ios::binary);
    Require(stream.good(), "Asset not found: " + path);
    return {std::istreambuf_iterator<char>(stream), std::istreambuf_iterator<char>()};
}

int main(int argc, char** argv)
{
    try
    {
        Require(argc == 3, "Expected manifest and output directory");
        std::ifstream manifest(argv[1]);
        std::vector<std::string> paths;
        for (std::string line; std::getline(manifest, line); )
        {
            if (!line.empty() && line.back() == '\r') line.pop_back();
            paths.push_back(line);
        }
        Require(paths.size() >= 3, "Manifest requires source, target and VMD");
        libmmd::PMXFile source, target;
        libmmd::VMDFile input;
        auto bytes = Read(paths[0]); Require(libmmd::ReadPMXFile(&source, bytes.data(), bytes.size()), "Source parse");
        bytes = Read(paths[1]); Require(libmmd::ReadPMXFile(&target, bytes.data(), bytes.size()), "Target parse");
        bytes = Read(paths[2]); Require(libmmd::ReadVMDFile(&input, bytes.data(), bytes.size()), "Motion parse");
        const fs::path output(argv[2]); fs::create_directories(output);
        const Rig sourceRig(source), targetRig(target);
        const Motion sourceMotion(input);
        const int sourceLeft = sourceRig.Find("左手首"), sourceRight = sourceRig.Find("右手首");
        const int targetLeft = targetRig.Find("左手首"), targetRight = targetRig.Find("右手首");
        Require(sourceLeft >= 0 && sourceRight >= 0 && targetLeft >= 0 && targetRight >= 0, "Missing wrists");
        std::ofstream bodies(output / "bodies.tsv");
        bodies << "index\tname\tbone\top\tshape\tsupported\tsize\tposition\n";
        for (size_t i = 0; i < target.m_rigidbodies.size(); ++i)
        {
            const auto& body = target.m_rigidbodies[i];
            bodies << i << '\t' << body.m_name << '\t' << body.m_boneIndex << '\t' << int(body.m_op)
                   << '\t' << int(body.m_shape) << '\t' << (body.m_boneIndex < 0 || targetRig.SupportedChain(body.m_boneIndex))
                   << '\t' << body.m_shapeSize.transpose() << '\t' << body.m_translate.transpose() << '\n';
        }
        Options base; base.stance = base.twist = true; base.maxDiagnostics = 1000000;
        std::vector<std::pair<std::string, Options>> variants;
        variants.emplace_back("base", base);
        auto avoidance = base; avoidance.avoidance = true; variants.emplace_back("avoidance", avoidance);
        auto wrist = base; wrist.wristContact = true; variants.emplace_back("wrist", wrist);
        auto combined = avoidance; combined.wristContact = true; variants.emplace_back("avoidance-wrist", combined);
        auto all = combined; all.fingerContact = all.floorContact = true; variants.emplace_back("all", all);
        auto iterations = combined; iterations.iterations = 160; variants.emplace_back("iterations160", iterations);
        auto distance = combined; distance.contactDistance = .6; variants.emplace_back("distance06", distance);
        std::ofstream summary(output / "summary.tsv");
        summary << "variant\tstage\tconstraints\tunresolved\tmax_residual\telapsed_ms\n";
        for (const auto& variant : variants)
        {
            const auto& name = variant.first; const auto& options = variant.second;
            const auto result = Run(source, target, input, options);
            Require(result.success, name + ": " + result.error);
            fs::create_directories(output / name);
            std::ofstream diagnostics(output / name / "diagnostics.tsv");
            diagnostics << std::setprecision(12) << "stage\tframe\tbone\terror\ttarget_x\ttarget_y\ttarget_z\tactual_x\tactual_y\tactual_z\n";
            for (const auto& sample : result.analysis.samples)
                if (sample.error > options.tolerance || (sample.stage == Stage::Contact && sample.bone.find("手首") != std::string::npos))
                    diagnostics << size_t(sample.stage) << '\t' << sample.frame << '\t' << sample.bone << '\t' << sample.error
                                << '\t' << sample.target.x() << '\t' << sample.target.y() << '\t' << sample.target.z()
                                << '\t' << sample.actual.x() << '\t' << sample.actual.y() << '\t' << sample.actual.z() << '\n';
            std::ofstream frames(output / name / "frames.tsv");
            frames << std::setprecision(12) << "stage\tframe\tpoint_hits\tpoint_max\tsegment_hits\tsegment_max\tsource_wrists\ttarget_wrists\twrist_active\n";
            std::ofstream hits(output / name / "hits.tsv");
            hits << std::setprecision(12) << "stage\tframe\tside\tpoint\tbody\tdepth\n";
            std::ofstream positions(output / name / "positions.tsv");
            positions << std::setprecision(12) << "stage\tframe\tbone\tx\ty\tz\n";
            for (size_t stage : {4u, 5u, 6u})
            {
                const auto& motion = result.stages[stage];
                Require(libmmd::WriteVMDFile(&motion, (output / name / ("stage-" + std::to_string(stage) + ".vmd")).string().c_str()), "VMD export");
                size_t constraints = 0, unresolved = 0; double maximum = 0;
                for (const auto& sample : result.analysis.samples) if (size_t(sample.stage) == stage)
                { ++constraints; unresolved += sample.error > options.tolerance; maximum = std::max(maximum, sample.error); }
                summary << name << '\t' << stage << '\t' << constraints << '\t' << unresolved << '\t' << maximum << '\t' << result.elapsedMilliseconds << '\n';
                const Motion sampled(motion);
                for (uint32_t frame = 0; frame <= sourceMotion.LastFrame(); ++frame)
                {
                    const Pose original(sourceRig, sourceMotion, frame), pose(targetRig, sampled, frame);
                    if (frame == 258 || frame == 313 || frame == 776 || frame == 854)
                        for (const char* boneName : {"左腕", "左ひじ", "左手首", "右腕", "右ひじ", "右手首"})
                        {
                            const auto& position = pose.positions[targetRig.Find(boneName)];
                            positions << stage << '\t' << frame << '\t' << boneName << '\t' << position.x() << '\t' << position.y() << '\t' << position.z() << '\n';
                        }
                    size_t pointHits = 0, segmentHits = 0; double pointMax = 0, segmentMax = 0;
                    for (const std::string side : {"左", "右"})
                    {
                        const int arm = targetRig.Find(side + "腕"), elbow = targetRig.Find(side + "ひじ"), hand = targetRig.Find(side + "手首");
                        Require(arm >= 0 && elbow >= 0 && hand >= 0, "Missing arm");
                        std::vector<std::pair<std::string, Vector>> points{{"elbow", pose.positions[elbow]}, {"wrist", pose.positions[hand]}};
                        for (int sample = 1; sample <= 3; ++sample)
                        {
                            const double alpha = sample / 4.;
                            points.emplace_back("forearm" + std::to_string(sample), (1. - alpha) * pose.positions[elbow] + alpha * pose.positions[hand]);
                            points.emplace_back("upperarm" + std::to_string(sample), (1. - alpha) * pose.positions[arm] + alpha * pose.positions[elbow]);
                        }
                        for (size_t b = 0; b < target.m_rigidbodies.size(); ++b)
                        {
                            const auto& body = target.m_rigidbodies[b];
                            if (body.m_op != libmmd::PMXRigidbody::Operation::Static ||
                                (body.m_boneIndex >= 0 && (!targetRig.SupportedChain(body.m_boneIndex) || targetRig.Ancestor(arm, body.m_boneIndex)))) continue;
                            for (size_t p = 0; p < points.size(); ++p)
                            {
                                const double depth = (ProjectOutside(body, pose, points[p].second, options.collisionMargin) - points[p].second).norm();
                                if (depth > options.tolerance)
                                {
                                    if (p < 2) { ++pointHits; pointMax = std::max(pointMax, depth); }
                                    else { ++segmentHits; segmentMax = std::max(segmentMax, depth); }
                                    hits << stage << '\t' << frame << '\t' << side << '\t' << points[p].first << '\t' << body.m_name << '\t' << depth << '\n';
                                }
                            }
                        }
                    }
                    const double sourceDistance = (original.positions[sourceLeft] - original.positions[sourceRight]).norm();
                    frames << stage << '\t' << frame << '\t' << pointHits << '\t' << pointMax << '\t' << segmentHits << '\t' << segmentMax
                           << '\t' << sourceDistance << '\t' << (pose.positions[targetLeft] - pose.positions[targetRight]).norm()
                           << '\t' << (sourceDistance <= options.contactDistance) << '\n';
                }
            }
            std::cout << name << ": solve " << result.elapsedMilliseconds << " ms, unresolved " << result.analysis.unresolved << '\n';
        }
        return 0;
    }
    catch (const std::exception& error) { std::cerr << error.what() << '\n'; return 1; }
}

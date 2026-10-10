#pragma once

#include <algorithm>
#include <array>
#include <cmath>
#include <string>
#include <string_view>

#include "utils/cmt_control_role.hpp"

namespace cmt::controls
{
enum class Part
{
    Other,
    Root,
    Torso,
    Face,
    LeftArm,
    RightArm,
    LeftLeg,
    RightLeg,
    Fingers
};
enum class LimbMode
{
    Auto = 0,
    FK = 1,
    IK = 2
};
struct ControlClass
{
    Part part = Part::Other;
    Side side = Side::Center;
    bool secondary = false;
    bool finger = false;
    bool limb_fk = false;
    bool limb_ik = false;
};

inline std::string NormalizeControlAlias(std::string_view name, Side &side)
{
    std::string key;
    for (const unsigned char ch : name)
    {
        if (ch == ' ' || ch == '_' || ch == '-' || ch == '.')
            continue;
        key += static_cast<char>(ch >= 'A' && ch <= 'Z' ? ch + ('a' - 'A') : ch);
    }
    side = Side::Center;
    if (!key.empty() && key.front() == '+')
        key.erase(0, 1);
    if (key.compare(0, 3, "左") == 0)
    {
        side = Side::Left;
        key.erase(0, 3);
    }
    else if (key.compare(0, 3, "右") == 0)
    {
        side = Side::Right;
        key.erase(0, 3);
    }
    else if (key.compare(0, 4, "left") == 0)
    {
        side = Side::Left;
        key.erase(0, 4);
    }
    else if (key.compare(0, 5, "right") == 0)
    {
        side = Side::Right;
        key.erase(0, 5);
    }
    else if (!key.empty() && (key.back() == 'l' || key.back() == 'r'))
    {
        side = key.back() == 'l' ? Side::Left : Side::Right;
        key.pop_back();
    }
    return key;
}

inline bool IsFingerAlias(std::string_view name)
{
    Side side;
    const auto key = NormalizeControlAlias(name, side);
    if (side == Side::Center)
        return false;
    constexpr std::string_view fingers[] = {"親指",  "人指",  "人差指", "中指", "薬指",   "小指",
                                            "thumb", "index", "middle", "ring", "little", "pinky"};
    for (const auto finger : fingers)
    {
        if (key.compare(0, finger.size(), finger) != 0)
            continue;
        const auto number = std::string_view(key).substr(finger.size());
        if (number == "0" || number == "1" || number == "2" || number == "3" || number == "０" || number == "１" ||
            number == "２" || number == "３")
            return true;
    }
    return false;
}

inline ControlClass ClassifyControl(std::string_view name, bool is_ik = false)
{
    ControlClass result;
    NormalizeControlAlias(name, result.side);
    const auto role = ClassifyName(name).role;
    const auto purpose = ClassifyPurpose(name);
    result.secondary = IsSecondaryPurpose(purpose);
    result.finger = IsFingerAlias(name);
    if (result.finger)
    {
        result.part = Part::Fingers;
        return result;
    }
    if (role == Role::Root || role == Role::Center || role == Role::Groove)
        result.part = Part::Root;
    else if (role == Role::Spine || role == Role::Pelvis || role == Role::Waist || role == Role::Neck)
        result.part = Part::Torso;
    else if (role == Role::Head || purpose == Purpose::Eye || purpose == Purpose::Eyes || purpose == Purpose::Accessory)
        result.part = Part::Face;
    else if (role == Role::Leg || role == Role::Knee || role == Role::Ankle || role == Role::Toe ||
             role == Role::IkParent || role == Role::IkGoal || role == Role::ToeIk)
    {
        result.part = result.side == Side::Right ? Part::RightLeg : Part::LeftLeg;
        result.limb_ik = role == Role::IkParent || role == Role::IkGoal || role == Role::ToeIk || is_ik;
        result.limb_fk = !result.limb_ik;
    }
    else if (purpose == Purpose::Shoulder || purpose == Purpose::Arm || purpose == Purpose::Elbow ||
             purpose == Purpose::Wrist || (result.secondary && result.side != Side::Center))
    {
        result.part = result.side == Side::Right ? Part::RightArm : Part::LeftArm;
        result.limb_fk = purpose == Purpose::Arm || purpose == Purpose::Elbow || purpose == Purpose::Wrist;
    }
    return result;
}

inline bool ModeShowsControl(LimbMode mode, bool fk, bool ik)
{
    return mode == LimbMode::Auto || (!fk && !ik) || (mode == LimbMode::FK ? !ik : !fk);
}

struct Point3
{
    double x = 0, y = 0, z = 0;
    Point3 operator+(Point3 b) const { return {x + b.x, y + b.y, z + b.z}; }
    Point3 operator-(Point3 b) const { return {x - b.x, y - b.y, z - b.z}; }
    Point3 operator*(double s) const { return {x * s, y * s, z * s}; }
    double Dot(Point3 b) const { return x * b.x + y * b.y + z * b.z; }
    double Length() const { return std::sqrt(Dot(*this)); }
};

struct TwoBoneSolution
{
    Point3 joint, end;
    bool reachable = false;
};

inline bool SolveTwoBone(Point3 root, Point3 target, Point3 pole, double upper, double lower, TwoBoneSolution &result)
{
    if (!std::isfinite(upper) || !std::isfinite(lower) || upper <= 1e-8 || lower <= 1e-8)
        return false;
    for (const auto point : {root, target, pole})
        if (!std::isfinite(point.x) || !std::isfinite(point.y) || !std::isfinite(point.z))
            return false;
    Point3 direction = target - root;
    const double requested = direction.Length();
    if (!std::isfinite(requested))
        return false;
    direction = requested > 1e-8 ? direction * (1.0 / requested) : Point3{0, -1, 0};
    const double minimum = std::max(1e-8, std::abs(upper - lower));
    const double distance = std::clamp(requested, minimum, upper + lower);
    Point3 bend = pole - root;
    bend = bend - direction * bend.Dot(direction);
    if (bend.Length() <= 1e-8)
    {
        bend = std::abs(direction.z) < 0.9 ? Point3{0, 0, 1} : Point3{0, 1, 0};
        bend = bend - direction * bend.Dot(direction);
    }
    bend = bend * (1.0 / bend.Length());
    const double along = (upper * upper - lower * lower + distance * distance) / (2.0 * distance);
    const double height = std::sqrt(std::max(0.0, upper * upper - along * along));
    result.joint = root + direction * along + bend * height;
    result.end = root + direction * distance;
    result.reachable = requested >= minimum && requested <= upper + lower;
    return true;
}
} // namespace cmt::controls

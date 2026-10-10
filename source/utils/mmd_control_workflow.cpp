#include "module/core/cmt_old_sdk_stl_preload.h"
#include "utils/mmd_control_workflow.hpp"

#include <algorithm>
#include <cmath>
#include <Eigen/Geometry>
#include "module/tools/object/mmd_bone_manager.h"
#include "module/tools/tag/mmd_bone.h"
#include "utils/mmd_bone_control_util.hpp"
#include "utils/string_util.hpp"
#include "description/OMMDModelManager.h"
#include "description/TMMDBone.h"
#include "plugin_resource.h"
#include "ospline.h"

namespace
{
using namespace cmt::controls;
// Private, persistent links. These are deliberately absent from the user UI.
constexpr Int32 kArmTargetLink = 4900;
constexpr Int32 kArmPoleLink = 4901;
constexpr Int32 kEffectorOrientation = 4902;
constexpr Int32 kGoalBoneOrientation = 4903;
constexpr Int32 kUpperTwist = 4904;
constexpr Int32 kLowerTwist = 4905;
constexpr Int32 kPartParameters[] = {0,
                                     MODEL_CONTROLS_ROOT,
                                     MODEL_CONTROLS_TORSO,
                                     MODEL_CONTROLS_FACE,
                                     MODEL_CONTROLS_ARM_L,
                                     MODEL_CONTROLS_ARM_R,
                                     MODEL_CONTROLS_LEG_L,
                                     MODEL_CONTROLS_LEG_R,
                                     MODEL_CONTROLS_FINGERS};

Matrix Normalized(Matrix matrix)
{
    matrix.sqmat = matrix.sqmat.GetNormalized();
    return matrix;
}
Eigen::Vector3d ToEigen(Vector v) { return {v.x, v.y, v.z}; }
Eigen::Quaterniond Quaternion(const Matrix &matrix)
{
    Eigen::Matrix3d basis;
    basis.col(0) = ToEigen(matrix.sqmat.v1.GetNormalized());
    basis.col(1) = ToEigen(matrix.sqmat.v2.GetNormalized());
    basis.col(2) = ToEigen(matrix.sqmat.v3.GetNormalized());
    return Eigen::Quaterniond(basis).normalized();
}
Eigen::Quaterniond Swing(Vector from, Vector to)
{
    const auto a = ToEigen(from).normalized();
    const auto b = ToEigen(to).normalized();
    const double dot = std::clamp(a.dot(b), -1.0, 1.0);
    if (dot < -1.0 + 1e-8)
        return Eigen::Quaterniond(Eigen::AngleAxisd(PI, a.unitOrthogonal()));
    const Eigen::Vector3d cross = a.cross(b);
    return Eigen::Quaterniond(1.0 + dot, cross.x(), cross.y(), cross.z()).normalized();
}
Matrix RotationMatrix(const Eigen::Quaterniond &rotation)
{
    const auto m = rotation.normalized().toRotationMatrix();
    return Matrix(Vector(), Vector(m(0, 0), m(1, 0), m(2, 0)), Vector(m(0, 1), m(1, 1), m(2, 1)),
                  Vector(m(0, 2), m(1, 2), m(2, 2)));
}
BaseObject *Model(BaseObject *object)
{
    for (; object; object = object->GetUp())
        if (object->IsInstanceOf(g_mmd_model_manager_object_id))
            return object;
    return nullptr;
}
BaseObject *Link(BaseTag *tag, Int32 parameter)
{
    if (!tag)
        return nullptr;
    GeData value;
    if (!tag->GetParameter(CreateDescID(DescLevel(parameter)), value, DESCFLAGS_GET::NONE))
        return nullptr;
    const BaseLink *link = value.GetBaseLink();
    BaseList2D *node = link ? link->GetLink(tag->GetDocument()) : nullptr;
    return node && node->IsInstanceOf(Obase) ? static_cast<BaseObject *>(node) : nullptr;
}
void SetLink(BaseTag *tag, Int32 parameter, BaseObject *object)
{
    BaseLink *link = BaseLink::Alloc();
    if (!link)
        return;
    link->SetLink(object);
    tag->SetParameter(CreateDescID(DescLevel(parameter)), GeData(link), DESCFLAGS_SET::NONE);
    BaseLink::Free(link); // GeData copies the link value.
}
Int32 ModeParameter(Part part)
{
    switch (part)
    {
    case Part::LeftArm:
        return MODEL_CONTROLS_ARM_L_MODE;
    case Part::RightArm:
        return MODEL_CONTROLS_ARM_R_MODE;
    case Part::LeftLeg:
        return MODEL_CONTROLS_LEG_L_MODE;
    case Part::RightLeg:
        return MODEL_CONTROLS_LEG_R_MODE;
    default:
        return 0;
    }
}
Bool GroupVisible(const ControlClass &control, BaseObject *model)
{
    if (!model)
        return true;
    const BaseContainer *data = model->GetDataInstance();
    const Int32 part = static_cast<Int32>(control.part);
    const Int32 solo = data->GetInt32(MODEL_CONTROLS_SOLO);
    if (solo && solo != part)
    {
        const Bool arm_fingers =
            control.finger && ((solo == static_cast<Int32>(Part::LeftArm) && control.side == Side::Left) ||
                               (solo == static_cast<Int32>(Part::RightArm) && control.side == Side::Right));
        if (!arm_fingers)
            return false;
    }
    if (control.finger &&
        !data->GetBool(control.side == Side::Right ? MODEL_CONTROLS_ARM_R : MODEL_CONTROLS_ARM_L, true))
        return false;
    if (control.secondary && !data->GetBool(MODEL_CONTROLS_HELPERS, true))
        return false;
    return !part || data->GetBool(kPartParameters[part], true);
}
struct ArmChain
{
    BaseObject *upper = nullptr;
    BaseObject *elbow = nullptr;
    BaseObject *wrist = nullptr;
};
Bool CanSolveChain(const ArmChain &chain)
{
    if (!chain.upper || !chain.elbow || !chain.wrist)
        return false;
    Bool has_elbow = false;
    for (BaseObject *bone = chain.wrist; bone; bone = bone->GetUp())
    {
        BaseTag *tag = bone->GetTag(g_mmd_bone_tag_id);
        if (!tag || tag->GetDataInstance()->GetBool(PMX_BONE_PHYSICS_AFTER_DEFORM))
            return false;
        if ((bone == chain.upper || bone == chain.elbow || bone == chain.wrist) &&
            (tag->GetDataInstance()->GetBool(PMX_BONE_IS_FIXED_AXIS) ||
             !tag->GetDataInstance()->GetBool(PMX_BONE_ROTATABLE)))
            return false;
        has_elbow = has_elbow || bone == chain.elbow;
        if (bone == chain.upper)
            return has_elbow && (chain.elbow->GetMg().off - chain.upper->GetMg().off).GetLength() > 1e-5 &&
                   (chain.wrist->GetMg().off - chain.elbow->GetMg().off).GetLength() > 1e-5;
    }
    return false;
}
ArmChain FindArm(MMDBoneManagerObject &manager, Side side)
{
    ArmChain chain;
    maxon::BaseArray<BaseObject *> bones;
    manager.BuildOrderedBoneObjectList(bones);
    for (BaseObject *bone : bones)
    {
        BaseTag *tag = bone->GetTag(g_mmd_bone_tag_id);
        const auto kind = mmd_control_workflow::ClassifyBone(tag ? tag->GetDataInstance() : nullptr);
        if (kind.side != side || kind.secondary)
            continue;
        const auto *data = tag->GetDataInstance();
        auto purpose = ClassifyPurpose(string_util::GetStdString(data->GetString(PMX_BONE_NAME_LOCAL)));
        if (purpose == Purpose::Unknown)
            purpose = ClassifyPurpose(string_util::GetStdString(data->GetString(PMX_BONE_NAME_UNIVERSAL)));
        if (purpose == Purpose::Arm)
            chain.upper = bone;
        if (purpose == Purpose::Elbow)
            chain.elbow = bone;
        if (purpose == Purpose::Wrist)
            chain.wrist = bone;
    }
    return chain;
}
ArmChain FindLeg(MMDBoneManagerObject &manager, Side side)
{
    ArmChain chain;
    maxon::BaseArray<BaseObject *> bones;
    manager.BuildOrderedBoneObjectList(bones);
    for (BaseObject *bone : bones)
    {
        BaseTag *tag = bone->GetTag(g_mmd_bone_tag_id);
        if (!tag || mmd_control_workflow::ClassifyBone(tag->GetDataInstance()).side != side)
            continue;
        const auto *data = tag->GetDataInstance();
        auto role = ClassifyName(string_util::GetStdString(data->GetString(PMX_BONE_NAME_LOCAL))).role;
        if (role == Role::None)
            role = ClassifyName(string_util::GetStdString(data->GetString(PMX_BONE_NAME_UNIVERSAL))).role;
        if (role == Role::Leg)
            chain.upper = bone;
        if (role == Role::Knee)
            chain.elbow = bone;
        if (role == Role::Ankle)
            chain.wrist = bone;
    }
    return chain;
}
BaseObject *FindLegGoal(MMDBoneManagerObject &manager, Side side)
{
    maxon::BaseArray<BaseObject *> bones;
    manager.BuildOrderedBoneObjectList(bones);
    for (BaseObject *bone : bones)
    {
        BaseTag *tag = bone->GetTag(g_mmd_bone_tag_id);
        const auto kind = mmd_control_workflow::ClassifyBone(tag ? tag->GetDataInstance() : nullptr);
        if (kind.side != side || !kind.limb_ik || !tag->GetDataInstance()->GetBool(PMX_BONE_IS_IK))
            continue;
        const auto local =
            ClassifyName(string_util::GetStdString(tag->GetDataInstance()->GetString(PMX_BONE_NAME_LOCAL))).role;
        const auto universal =
            ClassifyName(string_util::GetStdString(tag->GetDataInstance()->GetString(PMX_BONE_NAME_UNIVERSAL))).role;
        if (local == Role::ToeIk || universal == Role::ToeIk)
            continue;
        return bone;
    }
    return nullptr;
}
BaseObject *Effector(MMDBoneManagerObject &manager, BaseTag *goal)
{
    // Imported indices can be reassigned by the manager. The persistent
    // PMX target link is authoritative after import and after scene reload.
    if (BaseObject *target = Link(goal, PMX_BONE_IK_TARGET_BONE_LINK))
        return target;
    BaseTag *target = manager.FindBone(goal->GetDataInstance()->GetInt32(PMX_BONE_IK_TARGET_BONE_INDEX));
    return target ? target->GetObject() : nullptr;
}
Matrix FrozenBone(BaseObject *bone)
{
    std::vector<BaseObject *> chain;
    BaseObject *parent = bone;
    for (; parent && parent->GetTag(g_mmd_bone_tag_id); parent = parent->GetUp())
        chain.push_back(parent);
    Matrix result = parent ? Normalized(parent->GetMg()) : Matrix();
    for (auto i = chain.rbegin(); i != chain.rend(); ++i)
        result = Normalized(result * (*i)->GetFrozenMln());
    return result;
}
Matrix ControlBase(BaseObject *control)
{
    BaseObject *parent = control->GetUp();
    return Normalized((parent ? parent->GetMg() : Matrix()) * control->GetFrozenMln());
}
SplineObject *NewHandle(Bool pole, Float radius)
{
    std::vector<Vector> points;
    std::vector<Int32> counts;
    if (pole)
    {
        points = {Vector(-radius, -radius, 0), Vector(radius, -radius, 0), Vector(0, radius, 0),
                  Vector(-radius, -radius, 0)};
        counts = {4};
    }
    else
    {
        points = {Vector(-radius, -radius * 0.25, 0), Vector(radius, -radius * 0.25, 0),
                  Vector(radius, radius * 1.5, 0), Vector(-radius, radius * 1.5, 0),
                  Vector(-radius, -radius * 0.25, 0)};
        counts = {5};
    }
    SplineObject *spline = SplineObject::Alloc(static_cast<Int32>(points.size()), SPLINETYPE::LINEAR);
    if (!spline || !spline->ResizeObject(static_cast<Int32>(points.size()), static_cast<Int32>(counts.size())))
        return nullptr;
    for (Int32 i = 0; i < static_cast<Int32>(points.size()); ++i)
        spline->GetPointW()[i] = points[i];
    for (Int32 i = 0; i < static_cast<Int32>(counts.size()); ++i)
    {
        spline->GetSegmentW()[i].cnt = counts[i];
        spline->GetSegmentW()[i].closed = false;
    }
    spline->SetParameter(ConstDescID(DescLevel(SPLINEOBJECT_CLOSED)), false, DESCFLAGS_SET::NONE);
    spline->SetDefaultCoeff();
    spline->Message(MSG_UPDATE);
    return spline;
}
Vector DefaultPole(const ArmChain &chain)
{
    const Vector shoulder = chain.upper->GetMg().off, elbow = chain.elbow->GetMg().off,
                 wrist = chain.wrist->GetMg().off;
    Vector direction = wrist - shoulder;
    if (direction.GetLength() > 1e-8)
        direction.Normalize();
    Vector bend = elbow - shoulder - direction * Dot(elbow - shoulder, direction);
    if (bend.GetLength() <= 1e-5)
        bend = Model(chain.upper) ? -Model(chain.upper)->GetMg().sqmat.v3.GetNormalized() : Vector(0, 0, -1);
    bend.Normalize();
    return elbow + bend * std::max((wrist - shoulder).GetLength() * 0.5, 1.0);
}
Bool OwnedControl(BaseObject *control, MMDBoneManagerObject &manager)
{
    BaseObject *owner = reinterpret_cast<BaseObject *>(manager.Get());
    for (BaseObject *parent = control; parent; parent = parent->GetUp())
        if (parent == owner)
            return true;
    return false;
}
void MarkInput(BaseObject *control)
{
    control->SetDirty(DIRTYFLAGS::DATA | DIRTYFLAGS::MATRIX | DIRTYFLAGS::CACHE);
    control->Message(MSG_UPDATE);
}
void RecordMatchedInput(BaseDocument *doc, BaseObject *control)
{
    doc->AddUndo(UNDOTYPE::CHANGE, control);
    for (CTrack *track = control->GetFirstCTrack(); track; track = track->GetNext())
        doc->AddUndo(UNDOTYPE::CHANGE, track);
}
void CommitMatchedInput(BaseDocument *doc, BaseObject *control)
{
    // Existing animation would overwrite the snapped transform on the next
    // pass. Match at the current time, preserving every other authored key.
    for (CTrack *track = control->GetFirstCTrack(); track; track = track->GetNext())
    {
        const DescID id = track->GetDescriptionID();
        if (id.GetDepth() != 2 || (id[0].id != ID_BASEOBJECT_REL_POSITION && id[0].id != ID_BASEOBJECT_REL_ROTATION))
            continue;
        const Int32 component = id[1].id - VECTOR_X;
        if (component < 0 || component > 2)
            continue;
        CCurve *curve = track->GetCurve();
        CKey *key = curve ? curve->AddKey(doc->GetTime()) : nullptr;
        if (!key)
            continue;
        const Vector value = id[0].id == ID_BASEOBJECT_REL_POSITION ? control->GetRelPos() : control->GetRelRot();
        key->SetValue(curve, component == 0 ? value.x : component == 1 ? value.y : value.z);
    }
    MarkInput(control);
}
} // namespace

cmt::controls::ControlClass mmd_control_workflow::ClassifyBone(const BaseContainer *data)
{
    if (!data)
        return {};
    const auto local =
        ClassifyControl(string_util::GetStdString(data->GetString(PMX_BONE_NAME_LOCAL)), data->GetBool(PMX_BONE_IS_IK));
    const auto universal = ClassifyControl(string_util::GetStdString(data->GetString(PMX_BONE_NAME_UNIVERSAL)),
                                           data->GetBool(PMX_BONE_IS_IK));
    auto result = local.part != Part::Other ? local : universal;
    result.secondary = local.secondary || universal.secondary;
    return result;
}

cmt::controls::LimbMode mmd_control_workflow::GetLimbMode(BaseTag *bone)
{
    BaseObject *model = bone ? Model(bone->GetObject()) : nullptr;
    const Int32 parameter = ModeParameter(ClassifyBone(bone ? bone->GetDataInstance() : nullptr).part);
    return model && parameter ? static_cast<LimbMode>(std::clamp(model->GetDataInstance()->GetInt32(parameter), 0, 2))
                              : LimbMode::Auto;
}

Bool mmd_control_workflow::IsInputEnabled(BaseTag *bone)
{
    const auto kind = ClassifyBone(bone ? bone->GetDataInstance() : nullptr);
    const auto mode = GetLimbMode(bone);
    return mode == LimbMode::Auto || (mode == LimbMode::IK ? !kind.limb_fk : !kind.limb_ik);
}
Bool mmd_control_workflow::IsForcedFK(BaseTag *bone)
{
    return bone && ClassifyBone(bone->GetDataInstance()).limb_fk && GetLimbMode(bone) == LimbMode::FK;
}
Bool mmd_control_workflow::IsForcedIK(BaseTag *bone) { return bone && GetLimbMode(bone) == LimbMode::IK; }
Bool mmd_control_workflow::OwnsLegSolver(BaseTag *goal)
{
    if (!goal || !IsForcedIK(goal))
        return false;
    const auto kind = ClassifyBone(goal->GetDataInstance());
    if (kind.part != Part::LeftLeg && kind.part != Part::RightLeg)
        return false;
    BaseObject *object = goal->GetObject();
    while (object && !object->IsInstanceOf(g_mmd_bone_manager_object_id))
        object = object->GetUp();
    auto *manager = object ? object->GetNodeData<MMDBoneManagerObject>() : nullptr;
    if (!manager || FindLegGoal(*manager, kind.side) != goal->GetObject())
        return false;
    const auto chain = FindLeg(*manager, kind.side);
    return CanSolveChain(chain) && Link(goal, PMX_BONE_CONTROL_LINK) &&
           Link(chain.upper->GetTag(g_mmd_bone_tag_id), kArmPoleLink);
}
Bool mmd_control_workflow::IsVisible(BaseTag *bone, BaseObject *manager)
{
    if (!bone)
        return false;
    const auto kind = ClassifyBone(bone->GetDataInstance());
    BaseObject *model = Model(manager);
    if (GetLimbMode(bone) == LimbMode::Auto && kind.limb_fk &&
        (kind.part == Part::LeftLeg || kind.part == Part::RightLeg) && model &&
        model->GetDataInstance()->GetInt32(MODEL_CONTROLS_DISPLAY) == MODEL_CONTROLS_DISPLAY_PRIMARY)
        return false;
    return GroupVisible(kind, Model(manager)) && ModeShowsControl(GetLimbMode(bone), kind.limb_fk, kind.limb_ik);
}
UInt32 mmd_control_workflow::PresentationChecksum(BaseObject *model)
{
    UInt32 hash = 2166136261u;
    if (!model)
        return hash;
    hash = (hash ^ static_cast<UInt32>(model->GetDataInstance()->GetInt32(MODEL_CONTROLS_SOLO))) * 16777619u;
    for (Int32 parameter = MODEL_CONTROLS_ROOT; parameter <= MODEL_CONTROLS_HELPERS; ++parameter)
        hash = (hash ^ static_cast<UInt32>(model->GetDataInstance()->GetBool(parameter, true))) * 16777619u;
    hash = (hash ^ RuntimeChecksum(model)) * 16777619u;
    return hash;
}
UInt32 mmd_control_workflow::RuntimeChecksum(BaseObject *model)
{
    UInt32 hash = 2166136261u;
    if (model)
        for (Int32 parameter = MODEL_CONTROLS_ARM_L_MODE; parameter <= MODEL_CONTROLS_LEG_R_MODE; ++parameter)
            hash = (hash ^ static_cast<UInt32>(model->GetDataInstance()->GetInt32(parameter))) * 16777619u;
    return hash;
}
void mmd_control_workflow::CollectExtraControls(MMDBoneManagerObject &manager, std::vector<ExtraControl> &controls)
{
    for (const auto side : {Side::Left, Side::Right})
    {
        const auto chain = FindArm(manager, side);
        BaseTag *owner = chain.upper ? chain.upper->GetTag(g_mmd_bone_tag_id) : nullptr;
        for (const auto parameter : {kArmTargetLink, kArmPoleLink})
            if (BaseObject *control = Link(owner, parameter))
                controls.push_back(
                    {control, owner, side == Side::Left ? Part::LeftArm : Part::RightArm, parameter == kArmPoleLink});
    }
    for (const auto side : {Side::Left, Side::Right})
    {
        const auto chain = FindLeg(manager, side);
        BaseTag *owner = chain.upper ? chain.upper->GetTag(g_mmd_bone_tag_id) : nullptr;
        if (BaseObject *pole = Link(owner, kArmPoleLink))
            controls.push_back({pole, owner, side == Side::Left ? Part::LeftLeg : Part::RightLeg, true});
    }
}
void mmd_control_workflow::CreateArmControls(MMDBoneManagerObject &manager, BaseObject *root)
{
    for (const auto side : {Side::Left, Side::Right})
    {
        const auto chain = FindArm(manager, side);
        if (!CanSolveChain(chain))
            continue;
        const Float length = (chain.elbow->GetMg().off - chain.upper->GetMg().off).GetLength() +
                             (chain.wrist->GetMg().off - chain.elbow->GetMg().off).GetLength();
        if (length <= 1e-5)
            continue;
        BaseTag *owner = chain.upper->GetTag(g_mmd_bone_tag_id);
        BaseObject *model = Model(root);
        const Float size = model ? model->GetDataInstance()->GetFloat(MODEL_CONTROLS_SIZE, 1.0) : 1.0;
        const Float model_scale = model ? model->GetMg().sqmat.v1.GetLength() : 1.0;
        const Float radius = ((FrozenBone(chain.elbow).off - FrozenBone(chain.upper).off).GetLength() +
                              (FrozenBone(chain.wrist).off - FrozenBone(chain.elbow).off).GetLength()) *
                             model_scale * 0.045 * std::clamp(size, 0.25, 3.0);
        for (const auto parameter : {kArmTargetLink, kArmPoleLink})
        {
            const Bool pole = parameter == kArmPoleLink;
            if (BaseObject *existing = Link(owner, parameter))
            {
                const Float existing_scale=std::max(existing->GetMg().sqmat.v1.GetLength(),Float(1e-8));
                SplineObject *style = NewHandle(pole, (pole ? radius * 0.55 : radius)/existing_scale);
                if (style && existing->IsInstanceOf(Ospline))
                {
                    SplineObject *spline = ToSpline(existing);
                    if (spline->ResizeObject(style->GetPointCount(), style->GetSegmentCount()))
                    {
                        for (Int32 i = 0; i < style->GetPointCount(); ++i)
                            spline->GetPointW()[i] = style->GetPointR()[i];
                        for (Int32 i = 0; i < style->GetSegmentCount(); ++i)
                            spline->GetSegmentW()[i] = style->GetSegmentR()[i];
                        spline->SetDefaultCoeff();
                        spline->Message(MSG_UPDATE);
                    }
                }
                SplineObject::Free(style);
                continue;
            }
            SplineObject *control = NewHandle(pole, pole ? radius * 0.55 : radius);
            if (!control)
                continue;
            control->SetName(String(side == Side::Left ? (pole ? "左腕方向_ctrl" : "左手IK_ctrl")
                                                       : (pole ? "右腕方向_ctrl" : "右手IK_ctrl")));
            control->InsertUnderLast(root);
            Matrix pose = Normalized(chain.wrist->GetMg());
            if (pole)
                pose.off = DefaultPole(chain);
            control->SetMg(pose);
            const Matrix local = control->GetMl();
            control->SetFrozenPos(local.off);
            control->SetFrozenRot(MatrixToHPB(Normalized(local), ROTATIONORDER::DEFAULT));
            control->SetFrozenScale(local.sqmat.v1.GetLength() * Vector(1));
            control->SetRelMl(Matrix());
            control->SetRenderMode(MODE_OFF);
            control->SetParameter(ConstDescID(DescLevel(ID_BASEOBJECT_USECOLOR)), ID_BASEOBJECT_USECOLOR_ALWAYS,
                                  DESCFLAGS_SET::NONE);
            control->SetParameter(ConstDescID(DescLevel(ID_BASEOBJECT_COLOR)),
                                  side == Side::Left ? Vector(0.2, 0.48, 1) : Vector(1, 0.28, 0.24),
                                  DESCFLAGS_SET::NONE);
            SetLink(owner, parameter, control);
        }
    }
    for (const auto side : {Side::Left, Side::Right})
    {
        const auto chain = FindLeg(manager, side);
        if (!CanSolveChain(chain) || !FindLegGoal(manager, side))
            continue;
        BaseTag *owner = chain.upper->GetTag(g_mmd_bone_tag_id);
        BaseObject *model = Model(root);
        const Float size = model ? model->GetDataInstance()->GetFloat(MODEL_CONTROLS_SIZE, 1.0) : 1.0;
        const Float model_scale = model ? model->GetMg().sqmat.v1.GetLength() : 1.0;
        const Float radius = (FrozenBone(chain.wrist).off - FrozenBone(chain.upper).off).GetLength() * model_scale *
                             0.025 * std::clamp(size, 0.25, 3.0);
        if (BaseObject *existing = Link(owner, kArmPoleLink))
        {
            if (existing->IsInstanceOf(Ospline))
            {
                const Float existing_scale=std::max(existing->GetMg().sqmat.v1.GetLength(),Float(1e-8));
                SplineObject *style = NewHandle(true, radius/existing_scale);
                SplineObject *spline = ToSpline(existing);
                if (style && spline->ResizeObject(style->GetPointCount(), style->GetSegmentCount()))
                {
                    for (Int32 i = 0; i < style->GetPointCount(); ++i)
                        spline->GetPointW()[i] = style->GetPointR()[i];
                    for (Int32 i = 0; i < style->GetSegmentCount(); ++i)
                        spline->GetSegmentW()[i] = style->GetSegmentR()[i];
                    spline->SetDefaultCoeff();
                    spline->Message(MSG_UPDATE);
                }
                SplineObject::Free(style);
            }
            continue;
        }
        SplineObject *pole = NewHandle(true, radius);
        if (!pole)
            continue;
        pole->InsertUnderLast(root);
        pole->SetName(String(side == Side::Left ? "左膝方向_ctrl" : "右膝方向_ctrl"));
        Matrix pose = Normalized(chain.wrist->GetMg());
        pose.off = DefaultPole(chain);
        pole->SetMg(pose);
        const Matrix local = pole->GetMl();
        pole->SetFrozenPos(local.off);
        pole->SetFrozenRot(MatrixToHPB(Normalized(local), ROTATIONORDER::DEFAULT));
        pole->SetFrozenScale(local.sqmat.v1.GetLength() * Vector(1));
        pole->SetRelMl(Matrix());
        pole->SetRenderMode(MODE_OFF);
        pole->SetParameter(ConstDescID(DescLevel(ID_BASEOBJECT_USECOLOR)), ID_BASEOBJECT_USECOLOR_ALWAYS,
                           DESCFLAGS_SET::NONE);
        pole->SetParameter(ConstDescID(DescLevel(ID_BASEOBJECT_COLOR)),
                           side == Side::Left ? Vector(0.2, 0.48, 1) : Vector(1, 0.28, 0.24), DESCFLAGS_SET::NONE);
        SetLink(owner, kArmPoleLink, pole);
    }
}
void mmd_control_workflow::RefreshExtraVisibility(MMDBoneManagerObject &manager, BaseObject *object, Int32 display)
{
    std::vector<ExtraControl> controls;
    CollectExtraControls(manager, controls);
    for (const auto &control : controls)
    {
        auto kind = ClassifyBone(control.owner->GetDataInstance());
        kind.limb_fk = false;
        kind.limb_ik = true;
        const Bool visible = display != BONE_DISPLAY_TYPE_OFF && display != BONE_DISPLAY_TYPE_ON &&
                             GetLimbMode(control.owner) == LimbMode::IK && GroupVisible(kind, Model(object));
        control.object->SetEditorMode(visible ? MODE_ON : MODE_OFF);
        if (!visible)
            control.object->DelBit(BIT_ACTIVE);
    }
}
namespace
{
Int32 ChainLayer(const ArmChain &chain)
{
    Int32 layer = 0;
    for (BaseObject *bone = chain.wrist; bone; bone = bone->GetUp())
    {
        if (BaseTag *tag = bone->GetTag(g_mmd_bone_tag_id))
            layer = std::max(layer, tag->GetDataInstance()->GetInt32(PMX_BONE_LAYER));
        if (bone == chain.upper)
            return layer;
    }
    return NOTOK;
}

void SetWorldRotation(BaseObject *object, const Eigen::Quaterniond &rotation)
{
    const Matrix original = object->GetMg();
    Matrix matrix = RotationMatrix(rotation);
    matrix.off = original.off;
    matrix.sqmat.v1 *= original.sqmat.v1.GetLength();
    matrix.sqmat.v2 *= original.sqmat.v2.GetLength();
    matrix.sqmat.v3 *= original.sqmat.v3.GetLength();
    object->SetMg(matrix);
    MarkInput(object);
}

Bool SolveEvaluatedChain(MMDBoneManagerObject &manager, BaseDocument *doc, const ArmChain &chain, BaseObject *goal,
                         BaseObject *pole)
{
    // Solve after this layer's animation and append transforms. Using the
    // evaluated segment vectors preserves intermediary twist bones and VMD
    // translations, instead of assuming a direct parent/child bind chain.
    const Vector root = chain.upper->GetMg().off;
    const Vector joint = chain.elbow->GetMg().off;
    const Vector end = chain.wrist->GetMg().off;
    const auto point = [](Vector v) { return Point3{v.x, v.y, v.z}; };
    TwoBoneSolution solution;
    if (!SolveTwoBone(point(root), point(goal->GetMg().off), point(pole->GetMg().off), (joint - root).GetLength(),
                      (end - joint).GetLength(), solution))
        return false;
    const Vector solved_joint(solution.joint.x, solution.joint.y, solution.joint.z);
    const Vector solved_end(solution.end.x, solution.end.y, solution.end.z);
    const auto upper_twist = Eigen::Quaterniond(
        Eigen::AngleAxisd(goal->GetDataInstance()->GetFloat(kUpperTwist), ToEigen(solved_joint - root).normalized()));
    SetWorldRotation(chain.upper,
                     upper_twist * Swing(joint - root, solved_joint - root) * Quaternion(chain.upper->GetMg()));
    const Vector current_joint = chain.elbow->GetMg().off;
    const Vector current_end = chain.wrist->GetMg().off;
    const auto lower_twist = Eigen::Quaterniond(Eigen::AngleAxisd(goal->GetDataInstance()->GetFloat(kLowerTwist),
                                                                  ToEigen(solved_end - current_joint).normalized()));
    SetWorldRotation(chain.elbow, lower_twist * Swing(current_end - current_joint, solved_end - current_joint) *
                                      Quaternion(chain.elbow->GetMg()));
    SetWorldRotation(chain.wrist,
                     Quaternion(goal->GetMg()) * Quaternion(goal->GetDataInstance()->GetMatrix(kEffectorOrientation)));

    // Publish through the same override path as native PMX IK. The later
    // bone-tag and manager passes must not overwrite this solved layer.
    for (BaseObject *bone = chain.wrist; bone; bone = bone->GetUp())
    {
        if (BaseTag *tag = bone->GetTag(g_mmd_bone_tag_id))
        {
            const auto q = Quaternion(bone->GetRelMl());
            manager.SetPhysicsOverride(manager.FindBoneIndex(tag), doc, bone->GetRelPos(),
                                       {static_cast<Float32>(q.x()), static_cast<Float32>(q.y()),
                                        static_cast<Float32>(q.z()), static_cast<Float32>(q.w())});
        }
        if (bone == chain.upper)
            break;
    }
    return true;
}
} // namespace

Int32 mmd_control_workflow::SolveLayer(MMDBoneManagerObject &manager, BaseDocument *doc, const Int32 layer,
                                       const Bool after_physics)
{
    if (after_physics)
        return 0;
    Int32 solved = 0;
    for (const auto side : {Side::Left, Side::Right})
    {
        for (const Bool leg : {false, true})
        {
            const auto chain = leg ? FindLeg(manager, side) : FindArm(manager, side);
            if (!CanSolveChain(chain))
                continue;
            BaseTag *owner = chain.upper->GetTag(g_mmd_bone_tag_id);
            if (!IsForcedIK(owner))
                continue;
            BaseObject *goal_bone = leg ? FindLegGoal(manager, side) : nullptr;
            BaseObject *goal =
                leg ? (goal_bone ? Link(goal_bone->GetTag(g_mmd_bone_tag_id), PMX_BONE_CONTROL_LINK) : nullptr)
                    : Link(owner, kArmTargetLink);
            BaseObject *pole = Link(owner, kArmPoleLink);
            Int32 solve_layer = ChainLayer(chain);
            if (solve_layer == NOTOK || !goal || !pole)
                continue;
            if (goal_bone)
                solve_layer = std::max(
                    solve_layer, goal_bone->GetTag(g_mmd_bone_tag_id)->GetDataInstance()->GetInt32(PMX_BONE_LAYER));
            if (solve_layer == layer && SolveEvaluatedChain(manager, doc, chain, goal, pole))
                ++solved;
        }
    }
    return solved;
}

Bool mmd_control_workflow::GetDirectGoalDelta(BaseTag *bone, BaseObject *object, const Vector &animation_translation,
                                              const std::array<Float32, 4> &animation_rotation, Vector &translation,
                                              std::array<Float32, 4> &rotation)
{
    if (!bone || !object || !bone->GetDataInstance()->GetBool(PMX_BONE_IS_IK) || !IsForcedIK(bone))
        return false;
    BaseObject *control = Link(bone, PMX_BONE_CONTROL_LINK);
    if (!control)
        return false;
    const Matrix base = (object->GetUp() ? object->GetUp()->GetMg() : Matrix()) * object->GetFrozenMln();
    translation = (~base) * control->GetMg().off - animation_translation;
    const auto desired =
        Quaternion(control->GetMg()) * Quaternion(control->GetDataInstance()->GetMatrix(kGoalBoneOrientation));
    const Eigen::Quaterniond animation(animation_rotation[3], animation_rotation[0], animation_rotation[1],
                                       animation_rotation[2]);
    const auto q = (animation.normalized().conjugate() * Quaternion(base).conjugate() * desired).normalized();
    rotation = {static_cast<Float32>(q.x()), static_cast<Float32>(q.y()), static_cast<Float32>(q.z()),
                static_cast<Float32>(q.w())};
    return true;
}

Bool mmd_control_workflow::SetLimbMode(MMDBoneManagerObject &manager, BaseObject *model, Int32 parameter, Int32 value,
                                       const Bool undo_transaction)
{
    value = std::clamp(value, 0, 2);
    BaseContainer *data = model->GetDataInstance();
    if (data->GetInt32(parameter) == value)
        return true;
    BaseDocument *doc = model->GetDocument();
    if (!doc)
    {
        data->SetInt32(parameter, value);
        return true;
    }
    const Part part = parameter == MODEL_CONTROLS_ARM_L_MODE   ? Part::LeftArm
                      : parameter == MODEL_CONTROLS_ARM_R_MODE ? Part::RightArm
                      : parameter == MODEL_CONTROLS_LEG_L_MODE ? Part::LeftLeg
                                                               : Part::RightLeg;
    if (value == static_cast<Int32>(LimbMode::IK))
    {
        const Side side = part == Part::LeftArm || part == Part::LeftLeg ? Side::Left : Side::Right;
        const Bool leg = part == Part::LeftLeg || part == Part::RightLeg;
        if (!CanSolveChain(leg ? FindLeg(manager, side) : FindArm(manager, side)))
            return false;
    }
    struct Pose
    {
        BaseObject *bone;
        BaseObject *control;
        Matrix target;
    };
    std::vector<Pose> poses;
    maxon::BaseArray<BaseObject *> bones;
    manager.BuildOrderedBoneObjectList(bones);
    for (BaseObject *bone : bones)
    {
        BaseTag *tag = bone->GetTag(g_mmd_bone_tag_id);
        const auto kind = ClassifyBone(tag ? tag->GetDataInstance() : nullptr);
        if (kind.part == part && kind.limb_fk && !kind.secondary)
            if (BaseObject *control = Link(tag, PMX_BONE_CONTROL_LINK))
                poses.push_back({bone, control, Normalized(bone->GetMg())});
    }
    if (undo_transaction)
        doc->StartUndo();
    doc->AddUndo(UNDOTYPE::CHANGE_SMALL, model);
    for (const auto &pose : poses)
        RecordMatchedInput(doc, pose.control);
    if (value == static_cast<Int32>(LimbMode::IK) && (part == Part::LeftArm || part == Part::RightArm))
    {
        const auto chain = FindArm(manager, part == Part::LeftArm ? Side::Left : Side::Right);
        BaseTag *owner = chain.upper ? chain.upper->GetTag(g_mmd_bone_tag_id) : nullptr;
        BaseObject *goal = Link(owner, kArmTargetLink);
        BaseObject *pole = Link(owner, kArmPoleLink);
        if (!goal || !pole || !chain.wrist)
        {
            if (undo_transaction)
                doc->EndUndo();
            return false;
        }
        RecordMatchedInput(doc, goal);
        RecordMatchedInput(doc, pole);
        goal->GetDataInstance()->SetFloat(kUpperTwist, 0);
        goal->GetDataInstance()->SetFloat(kLowerTwist, 0);
        goal->SetMg(chain.wrist->GetMg());
        Matrix matrix = pole->GetMg();
        matrix.off = DefaultPole(chain);
        pole->SetMg(matrix);
        CommitMatchedInput(doc, goal);
        CommitMatchedInput(doc, pole);
    }
    else if (value == static_cast<Int32>(LimbMode::IK))
    {
        const Side side = part == Part::LeftLeg ? Side::Left : Side::Right;
        const auto chain = FindLeg(manager, side);
        BaseObject *foot_goal = FindLegGoal(manager, side);
        for (BaseObject *bone : bones)
        {
            BaseTag *tag = bone->GetTag(g_mmd_bone_tag_id);
            const auto kind = ClassifyBone(tag ? tag->GetDataInstance() : nullptr);
            if (kind.part != part || !tag->GetDataInstance()->GetBool(PMX_BONE_IS_IK))
                continue;
            BaseObject *control = Link(tag, PMX_BONE_CONTROL_LINK);
            BaseObject *target = Effector(manager, tag);
            if (!control || !target)
                continue;
            RecordMatchedInput(doc, control);
            control->GetDataInstance()->SetMatrix(
                kGoalBoneOrientation,
                RotationMatrix(Quaternion(control->GetMg()).conjugate() * Quaternion(bone->GetMg())));
            Matrix matrix = control->GetMg();
            matrix.off = target->GetMg().off;
            control->SetMg(matrix);
            if (bone == foot_goal && chain.wrist)
            {
                control->GetDataInstance()->SetMatrix(
                    kEffectorOrientation,
                    RotationMatrix(Quaternion(control->GetMg()).conjugate() * Quaternion(chain.wrist->GetMg())));
                control->GetDataInstance()->SetFloat(kUpperTwist, 0);
                control->GetDataInstance()->SetFloat(kLowerTwist, 0);
            }
            CommitMatchedInput(doc, control);
        }
        BaseObject *pole = chain.upper ? Link(chain.upper->GetTag(g_mmd_bone_tag_id), kArmPoleLink) : nullptr;
        if (pole && chain.elbow && chain.wrist)
        {
            RecordMatchedInput(doc, pole);
            Matrix matrix = pole->GetMg();
            matrix.off = DefaultPole(chain);
            pole->SetMg(matrix);
            CommitMatchedInput(doc, pole);
        }
    }
    data->SetInt32(parameter, value);
    if (value == static_cast<Int32>(LimbMode::IK))
    {
        const Bool leg = part == Part::LeftLeg || part == Part::RightLeg;
        const Side side = part == Part::LeftLeg || part == Part::LeftArm ? Side::Left : Side::Right;
        const auto chain = leg ? FindLeg(manager, side) : FindArm(manager, side);
        BaseObject *goal_bone = leg ? FindLegGoal(manager, side) : nullptr;
        BaseObject *goal =
            leg ? (goal_bone ? Link(goal_bone->GetTag(g_mmd_bone_tag_id), PMX_BONE_CONTROL_LINK) : nullptr)
                : Link(chain.upper ? chain.upper->GetTag(g_mmd_bone_tag_id) : nullptr, kArmTargetLink);
        if (goal && chain.upper && chain.elbow && chain.wrist)
        {
            // Target and pole preserve joint locations. Preserve roll as well:
            // PMX IK and intermediary append/twist bones can have a different
            // roll from the shortest swing used by an animator's two-bone IK.
            for (Int32 iteration = 0; iteration < 3; ++iteration)
            {
                for (const auto joint :
                     {std::make_pair(chain.upper, kUpperTwist), std::make_pair(chain.elbow, kLowerTwist)})
                {
                    doc->ExecutePasses(nullptr, true, true, true, BUILDFLAGS::NONE);
                    for (const auto &pose : poses)
                        if (pose.bone == joint.first)
                        {
                            const auto correction =
                                (Quaternion(pose.target) * Quaternion(joint.first->GetMg()).conjugate()).normalized();
                            const Vector axis =
                                (joint.first == chain.upper ? chain.elbow->GetMg().off - chain.upper->GetMg().off
                                                            : chain.wrist->GetMg().off - chain.elbow->GetMg().off)
                                    .GetNormalized();
                            const Float angle = 2.0 * std::atan2(correction.vec().dot(ToEigen(axis)), correction.w());
                            goal->GetDataInstance()->SetFloat(joint.second,
                                                              goal->GetDataInstance()->GetFloat(joint.second) + angle);
                            MarkInput(goal);
                        }
                }
            }
        }
    }
    if (value == static_cast<Int32>(LimbMode::IK) && (part == Part::LeftLeg || part == Part::RightLeg))
    {
        for (Int32 iteration = 0; iteration < 3; ++iteration)
        {
            doc->ExecutePasses(nullptr, true, true, true, BUILDFLAGS::NONE);
            for (BaseObject *bone : bones)
            {
                BaseTag *tag = bone->GetTag(g_mmd_bone_tag_id);
                const auto kind = ClassifyBone(tag ? tag->GetDataInstance() : nullptr);
                if (kind.part != part || !tag->GetDataInstance()->GetBool(PMX_BONE_IS_IK))
                    continue;
                BaseObject *control = Link(tag, PMX_BONE_CONTROL_LINK);
                BaseObject *target = Effector(manager, tag);
                if (!control || !target)
                    continue;
                for (const auto &pose : poses)
                    if (pose.bone == target)
                    {
                        Matrix matrix = control->GetMg();
                        matrix.off = pose.target.off;
                        control->SetMg(matrix);
                        CommitMatchedInput(doc, control);
                    }
            }
        }
    }
    if (value == static_cast<Int32>(LimbMode::FK))
    {
        // Match in evaluated space, so append transformations are accounted for.
        for (Int32 iteration = 0; iteration < 8; ++iteration)
        {
            doc->ExecutePasses(nullptr, true, true, true, BUILDFLAGS::NONE);
            Float error = 0;
            for (const auto &pose : poses)
            {
                const Eigen::Quaterniond correction =
                    Quaternion(pose.target) * Quaternion(pose.bone->GetMg()).conjugate();
                error = std::max(error, Float(correction.vec().norm()));
                const auto basis = Quaternion(ControlBase(pose.control));
                const auto input =
                    (basis.conjugate() * correction * basis * Quaternion(pose.control->GetRelMl())).normalized();
                Matrix matrix = RotationMatrix(input);
                matrix.off = pose.control->GetRelPos();
                pose.control->SetRelMl(matrix);
                CommitMatchedInput(doc, pose.control);
            }
            if (error < 1e-6)
                break;
        }
    }
    if (undo_transaction)
        doc->EndUndo();
    return true;
}
void mmd_control_workflow::ApplyPreset(MMDBoneManagerObject &manager, BaseObject *model, Int32 preset)
{
    const Int32 mode = preset == MODEL_CONTROLS_WORKFLOW_IK   ? MODEL_CONTROLS_LIMB_IK
                       : preset == MODEL_CONTROLS_WORKFLOW_FK ? MODEL_CONTROLS_LIMB_FK
                                                              : MODEL_CONTROLS_LIMB_AUTO;
    BaseDocument *doc = model->GetDocument();
    if (doc)
    {
        doc->StartUndo();
        doc->AddUndo(UNDOTYPE::CHANGE_SMALL, model);
    }
    for (Int32 parameter = MODEL_CONTROLS_ARM_L_MODE; parameter <= MODEL_CONTROLS_LEG_R_MODE; ++parameter)
        SetLimbMode(manager, model, parameter, mode, false);
    model->GetDataInstance()->SetInt32(MODEL_CONTROLS_SOLO, 0);
    for (Int32 parameter = MODEL_CONTROLS_ROOT; parameter <= MODEL_CONTROLS_FINGERS; ++parameter)
        model->GetDataInstance()->SetBool(parameter, true);
    model->GetDataInstance()->SetBool(MODEL_CONTROLS_HELPERS, false);
    if (doc)
        doc->EndUndo();
}
void mmd_control_workflow::ResetSelected(MMDBoneManagerObject &manager, BaseObject *model)
{
    BaseDocument *doc = model->GetDocument();
    if (!doc)
        return;
    doc->StartUndo();
    maxon::BaseArray<BaseObject *> bones;
    manager.BuildOrderedBoneObjectList(bones);
    for (BaseObject *bone : bones)
    {
        BaseTag *tag = bone->GetTag(g_mmd_bone_tag_id);
        BaseObject *control = Link(tag, PMX_BONE_CONTROL_LINK);
        if (!control || !OwnedControl(control, manager) || !control->GetBit(BIT_ACTIVE) ||
            control->GetEditorMode() == MODE_OFF)
            continue;
        doc->AddUndo(UNDOTYPE::CHANGE, control);
        mmd_bone_control_util::ResetControlRelativeTransform(tag);
    }
    std::vector<ExtraControl> extras;
    CollectExtraControls(manager, extras);
    for (const auto &extra : extras)
        if (extra.object->GetBit(BIT_ACTIVE) && extra.object->GetEditorMode() != MODE_OFF)
        {
            doc->AddUndo(UNDOTYPE::CHANGE, extra.object);
            extra.object->SetRelMl(Matrix());
            MarkInput(extra.object);
        }
    doc->EndUndo();
}
void mmd_control_workflow::KeySelected(MMDBoneManagerObject &manager, BaseObject *model)
{
    BaseDocument *doc = model->GetDocument();
    if (!doc)
        return;
    doc->StartUndo();
    std::vector<ExtraControl> handles;
    CollectExtraControls(manager, handles);
    maxon::BaseArray<BaseObject *> bones;
    manager.BuildOrderedBoneObjectList(bones);
    for (BaseObject *bone : bones)
    {
        BaseTag *tag = bone->GetTag(g_mmd_bone_tag_id);
        BaseObject *control = Link(tag, PMX_BONE_CONTROL_LINK);
        if (control && OwnedControl(control, manager))
            handles.push_back({control, tag, Part::Other, false});
    }
    for (const auto &extra : handles)
    {
        BaseObject *control = extra.object;
        if (!control->GetBit(BIT_ACTIVE) || control->GetEditorMode() == MODE_OFF)
            continue;
        for (Int32 channel = 0; channel < (extra.pole ? 3 : 6); ++channel)
        {
            const Bool position = channel < 3;
            const Int32 component = channel % 3;
            const DescID id = CreateDescID(
                DescLevel(position ? ID_BASEOBJECT_REL_POSITION : ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0),
                DescLevel(VECTOR_X + component, DTYPE_REAL, 0));
            CTrack *track = control->FindCTrack(id);
            if (!track)
            {
                track = CTrack::Alloc(control, id);
                if (!track)
                    continue;
                control->InsertTrackSorted(track);
                doc->AddUndo(UNDOTYPE::NEWOBJ, track);
            }
            else
                doc->AddUndo(UNDOTYPE::CHANGE, track);
            CCurve *curve = track->GetCurve();
            if (CKey *key = curve ? curve->AddKey(doc->GetTime()) : nullptr)
            {
                const Vector value = position ? control->GetRelPos() : control->GetRelRot();
                key->SetValue(curve, component == 0 ? value.x : component == 1 ? value.y : value.z);
            }
        }
    }
    doc->EndUndo();
}

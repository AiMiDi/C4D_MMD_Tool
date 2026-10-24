#pragma once

#include <array>
#include <vector>
#include <c4d.h>
#include "module/core/cmt_marco.h"
#include "utils/cmt_control_workflow.hpp"

class MMDBoneManagerObject;

namespace mmd_control_workflow
{
struct LimbChain
{
    BaseObject *upper = nullptr;
    BaseObject *elbow = nullptr;
    BaseObject *wrist = nullptr;
};
struct LimbChains
{
    LimbChain arms[2];
    LimbChain legs[2];
    BaseObject *leg_goals[2] = {nullptr, nullptr};
};
// Stack-owned by one model evaluation. Only bone identity/classification is
// reused: links, modes, layers and matrices are still read at each use.
class EvaluationContext
{
public:
    const LimbChains& GetChains(MMDBoneManagerObject& manager);
private:
    MMDBoneManagerObject* manager_ = nullptr;
    LimbChains chains_;
};
struct ExtraControl
{
    BaseObject *object = nullptr;
    BaseTag *owner = nullptr;
    cmt::controls::Part part = cmt::controls::Part::Other;
    Bool pole = false;
};

cmt::controls::ControlClass ClassifyBone(const BaseContainer *data);
cmt::controls::LimbMode GetLimbMode(BaseTag *bone);
Bool IsInputEnabled(BaseTag *bone);
Bool IsForcedFK(BaseTag *bone);
Bool IsForcedIK(BaseTag *bone);
Bool OwnsLegSolver(BaseTag *goal);
Bool IsVisible(BaseTag *bone, BaseObject *manager);
UInt32 PresentationChecksum(BaseObject *model);
UInt32 RuntimeChecksum(BaseObject *model);
void CollectExtraControls(MMDBoneManagerObject &manager, std::vector<ExtraControl> &controls,
                          EvaluationContext* context = nullptr);
void CreateArmControls(MMDBoneManagerObject &manager, BaseObject *root);
void RefreshExtraVisibility(MMDBoneManagerObject &manager, BaseObject *object, Int32 display);
Int32 SolveLayer(MMDBoneManagerObject &manager, BaseDocument *doc, Int32 layer, Bool after_physics,
                 EvaluationContext* context = nullptr);
Bool GetDirectGoalDelta(BaseTag *bone, BaseObject *object, const Vector &animation_translation,
                        const std::array<Float32, 4> &animation_rotation, Vector &translation,
                        std::array<Float32, 4> &rotation);
Bool SetLimbMode(MMDBoneManagerObject &manager, BaseObject *model, Int32 parameter, Int32 value,
                 Bool undo_transaction = true);
void ApplyPreset(MMDBoneManagerObject &manager, BaseObject *model, Int32 preset);
void ResetSelected(MMDBoneManagerObject &manager, BaseObject *model);
void KeySelected(MMDBoneManagerObject &manager, BaseObject *model);
} // namespace mmd_control_workflow

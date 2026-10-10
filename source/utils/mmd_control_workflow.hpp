#pragma once

#include <array>
#include <vector>
#include <c4d.h>
#include "module/core/cmt_marco.h"
#include "utils/cmt_control_workflow.hpp"

class MMDBoneManagerObject;

namespace mmd_control_workflow
{
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
void CollectExtraControls(MMDBoneManagerObject &manager, std::vector<ExtraControl> &controls);
void CreateArmControls(MMDBoneManagerObject &manager, BaseObject *root);
void RefreshExtraVisibility(MMDBoneManagerObject &manager, BaseObject *object, Int32 display);
Int32 SolveLayer(MMDBoneManagerObject &manager, BaseDocument *doc, Int32 layer, Bool after_physics);
Bool GetDirectGoalDelta(BaseTag *bone, BaseObject *object, const Vector &animation_translation,
                        const std::array<Float32, 4> &animation_rotation, Vector &translation,
                        std::array<Float32, 4> &rotation);
Bool SetLimbMode(MMDBoneManagerObject &manager, BaseObject *model, Int32 parameter, Int32 value,
                 Bool undo_transaction = true);
void ApplyPreset(MMDBoneManagerObject &manager, BaseObject *model, Int32 preset);
void ResetSelected(MMDBoneManagerObject &manager, BaseObject *model);
void KeySelected(MMDBoneManagerObject &manager, BaseObject *model);
} // namespace mmd_control_workflow

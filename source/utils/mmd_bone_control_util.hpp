/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & CMT contributors.
Author:			Aimidi
Date:			2026/5/15
File:			mmd_bone_control_util.hpp
Description:	MMD bone control utilities

**************************************************************************/

#pragma once

#include <array>

#include <c4d.h>
#include "module/core/cmt_marco.h"

class MMDBoneManagerObject;

namespace mmd_bone_control_util
{
	Bool CreateOrRefreshControls(MMDBoneManagerObject& bone_manager, BaseObject* bone_manager_object);
	Bool HasActiveControlDelta(MMDBoneManagerObject& bone_manager);
	UInt32 GetControlStateChecksum(MMDBoneManagerObject& bone_manager);
	void SyncControlsToCurrentPose(MMDBoneManagerObject& bone_manager);
	Bool GetControlDeltaInBoneSpace(BaseTag* bone_tag, BaseObject* bone_object, Vector& translation, std::array<Float32, 4>& rotation);
	void ResetControlRelativeTransform(BaseTag* bone_tag);
}

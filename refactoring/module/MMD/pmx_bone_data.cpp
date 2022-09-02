/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & Walter White & CMT contributors.
Author:			Aimidi
Date:			2022/8/24
File:			pmx_bone_data.cpp
Description:	pmx bone data

**************************************************************************/

#include "pch.h"
#include "pmx_bone_data.h"

PMXBoneFlags::PMXBoneFlags()
{
	indexed_tail_position = false;
	rotatable = true;
	translatable = false;
	is_visible = true;
	enabled = true;
	is_IK = false;
	inherit_rotation = false;
	inherit_translation = false;
	fixed_axis = false;
	local_coordinate = false;
	physics_after_deform = false;
	external_parent_deform = false;
}

Bool PMXBoneData::ReadFromFile(BaseFile* file)
{

	return true;
}

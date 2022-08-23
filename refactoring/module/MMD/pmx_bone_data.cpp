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
	Rotatable = true;
	Translatable = false;
	Is_visible = true;
	Enabled = true;
	IK = false;
	Inherit_rotation = false;
	Inherit_translation = false;
	Fixed_axis = false;
	Local_coordinate = false;
	Physics_after_deform = false;
	External_parent_deform = false;
}

Bool PMXBoneData::ReadFromFile(BaseFile* file)
{

	return true;
}

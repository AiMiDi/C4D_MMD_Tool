/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & CMT contributors.
Author:			Aimidi
Date:			2023/9/12
File:			mmd_bone_root.cpp
Description:	DESC

**************************************************************************/

#pragma once
#include "description/OMMDBoneRoot.h"
/*
type 0: update BoneRoot;
type 1: set bone display type;
type 2: bone index change;
type 3: bone morph change;
*/
enum class MMDBoneRootObjectMSGType : int8_t
{
	DEFAULT = -1,
	SET_BONE_DISPLAY_TYPE,
	BONE_ROOT_UPDATE,
	BONE_MORPH_CHANGE
};
struct MMDBoneRootObjectMSG
{

	MMDBoneRootObjectMSGType type;
	Int32	display_type;
	BaseObject* bond_root_object;

	explicit MMDBoneRootObjectMSG(
		const MMDBoneRootObjectMSGType type_ = MMDBoneRootObjectMSGType::DEFAULT,
		const Int32 display_type_ = BONE_DISPLAY_TYPE_ON,
		BaseObject* BoneRoot_ = nullptr) :
		type(type_),
		display_type(display_type_),
		bond_root_object(BoneRoot_) {}
};
class MMDBoneRootObject final : public ObjectData
{
public:
	BaseLink* GetBoneLink(Int32 index);
	Int32 GetBoneIndex(BaseLink* bone);
};

/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & CMT contributors.
Author:			Aimidi
Date:			2023/9/12
File:			mmd_bone_root.cpp
Description:	DESC

**************************************************************************/

#pragma once

class MMDBoneRootObject final : public ObjectData
{
public:
	BaseLink* GetBoneLink(Int32 index);
	Int32 GetBoneIndex(BaseLink* bone);
};

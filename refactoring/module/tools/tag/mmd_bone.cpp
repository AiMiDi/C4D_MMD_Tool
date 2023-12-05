/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & CMT contributors.
Author:			Aimidi
Date:			2023/9/12
File:			mmd_bone_root.h
Description:	DESC

**************************************************************************/

#include "pch.h"
#include "mmd_bone.h"

#include "customgui_priority.h"

Bool MMDBoneTag::RefreshColor(GeListNode* node, BaseObject* op)
{
	if (!op)
	{
		op = m_bone_object;
	}
	if (!node)
	{
		node = Get();
	}
	const BaseContainer* bc = reinterpret_cast<BaseList2D*>(node)->GetDataInstance();
	if (!bc)
	{
		return(false);
	}
	static constexpr Vector colors[6]
	{
		Vector(0.56640625, 0.78125, 1),       /* Is_rotatable == 1 */
		Vector(0.703125, 1, 0.546875),        /* Is_translatable == 1 */
		Vector(0.984375, 0.375, 0),           /* Is_IK == 1 */
		Vector(0.4, 0.4, 0.4),                /* Is_visible == 0 */
		Vector(0.7265625, 0.328125, 1),       /* Fixed_axis == 1 */
		Vector(0.682353, 0.64453125, 1),      /* Inherit_rotation == 1||Inherit_translation == 1 */
	};
	Int32 color = 0;

	if (bc->GetBool(PMX_BONE_ROTATABLE) == 1)
		color = 0;
	if (bc->GetBool(PMX_BONE_TRANSLATABLE) == 1)
		color = 1;
	if (bc->GetBool(PMX_BONE_IS_IK) == 1)
		color = 2;
	if (bc->GetBool(PMX_BONE_VISIBLE) == 0)
		color = 3;
	if (bc->GetBool(PMX_BONE_IS_FIXED_AXIS) == 1)
		color = 4;
	if (bc->GetBool(PMX_BONE_INHERIT_ROTATION) == 1 || bc->GetBool(PMX_BONE_INHERIT_TRANSLATION))
		color = 5;
	if (node != nullptr)
	{
#if API_VERSION >= 21000
		node->SetParameter(ConstDescID(DescLevel(ID_BASELIST_ICON_COLORIZE_MODE)), ID_BASELIST_ICON_COLORIZE_MODE_CUSTOM, DESCFLAGS_SET::NONE);
		node->SetParameter(ConstDescID(DescLevel(ID_BASELIST_ICON_COLOR)), colors[color], DESCFLAGS_SET::NONE);
#endif
	}
	if (op != nullptr)
	{
#if API_VERSION >= 21000
		op->SetParameter(ConstDescID(DescLevel(ID_BASELIST_ICON_COLORIZE_MODE)), ID_BASELIST_ICON_COLORIZE_MODE_CUSTOM, DESCFLAGS_SET::NONE);
		op->SetParameter(ConstDescID(DescLevel(ID_BASELIST_ICON_COLOR)), colors[color], DESCFLAGS_SET::NONE);
#endif
		auto objColor = MakeObjectColorProperties(colors[color], ID_BASEOBJECT_USECOLOR_ALWAYS, true);
		op->SetColorProperties(&objColor);
	}
	return(true);
}

MMDBoneTag::TrackDescIDArray MMDBoneTag::GetTrackDescIDsImpl()
{
	static const TrackDescIDArray track_desc_IDs
	{
		ConstDescID(DescLevel(ID_BASEOBJECT_REL_POSITION), DescLevel(VECTOR_X)),
		ConstDescID(DescLevel(ID_BASEOBJECT_REL_POSITION), DescLevel(VECTOR_Y)),
		ConstDescID(DescLevel(ID_BASEOBJECT_REL_POSITION), DescLevel(VECTOR_Z)),
		ConstDescID(DescLevel(ID_BASEOBJECT_REL_ROTATION), DescLevel(VECTOR_X)),
		ConstDescID(DescLevel(ID_BASEOBJECT_REL_ROTATION), DescLevel(VECTOR_Y)),
		ConstDescID(DescLevel(ID_BASEOBJECT_REL_ROTATION), DescLevel(VECTOR_Z))
	};
	return track_desc_IDs;
}

Bool MMDBoneTag::Init(GeListNode* node, Bool isCloneInit)
{
	if (!node)
		return(false);
	
	BaseContainer* bc = reinterpret_cast<BaseList2D*>(node)->GetDataInstance();
	if (!bc)
		return false;

	bc->SetString(ID_BASELIST_NAME, GeLoadString(IDS_T_MMD_BONE));
	bc->SetString(PMX_BONE_NAME_LOCAL, "bone"_s);
	bc->SetInt32(PMX_BONE_NAME_IS_LOCAL, 2);
	bc->SetString(PMX_BONE_NAME_UNIVERSAL, "bone"_s);
	bc->SetString(PMX_BONE_PARENT_BONE_INDEX, "-1"_s);
	bc->SetString(PMX_BONE_PARENT_BONE_NAME, ""_s);
	bc->SetInt32(PMX_BONE_ROTATABLE, 1);
	bc->SetInt32(PMX_BONE_VISIBLE, 1);
	bc->SetInt32(PMX_BONE_ENABLED, 1);
	bc->SetInt32(PMX_BONE_TAIL_INDEX, 0);
	bc->SetInt32(PMX_BONE_INHERIT_BONE_PARENT_INDEX, -1);
	bc->SetFloat(PMX_BONE_INHERIT_BONE_PARENT_INFLUENCE, 1.0);
	bc->SetVector(PMX_BONE_LOCAL_X, Vector(1, 0, 0));
	bc->SetVector(PMX_BONE_LOCAL_Z, Vector(0, 0, 1));
	if (GeData priority; node->GetParameter(ConstDescID(DescLevel(EXPRESSION_PRIORITY)), priority, DESCFLAGS_GET::NONE))
	{
		if (auto* pd = DataGetCustomDataType(priority, PriorityData, CUSTOMGUI_PRIORITY_DATA))
		{
			pd->SetPriorityValue(PRIORITYVALUE_PRIORITY, 1);
			bc->SetData(EXPRESSION_PRIORITY, priority);
		}
	}
	if (!InitInterpolator(node))
		return false;

	return SUPER::Init(node, isCloneInit);
}

Bool MMDBoneTag::Message(GeListNode* node, Int32 type, void* data)
{

	return SUPER::Message(node, type, data);
}

MMDBoneTag::TrackDescIDArray MMDBoneTag::GetTrackDescIDs()
{
	return GetTrackDescIDsImpl();
}

MMDBoneTag::TrackObjectArray MMDBoneTag::GetTrackObjects(
	GeListNode* node)
{
	return TrackObjectArray
	{
		m_bone_object,		// POSITION_X
		m_bone_object,		// POSITION_Y
		m_bone_object,		// POSITION_Z
		m_bone_object,		// ROTATION_X
		m_bone_object,		// ROTATION_Y
		m_bone_object		// ROTATION_Z
	};
}

MMDBoneTag::InterpolatorTrackTableArray MMDBoneTag::
GetTrackInterpolatorMap()
{
	static constexpr InterpolatorTrackTableArray track_interpolator_map
	{
		PMX_BONE_TAG_INTERPOLATOR_POSITION_X,
		PMX_BONE_TAG_INTERPOLATOR_POSITION_Y,
		PMX_BONE_TAG_INTERPOLATOR_POSITION_Z,
		PMX_BONE_TAG_INTERPOLATOR_ROTATION,
		PMX_BONE_TAG_INTERPOLATOR_ROTATION,
		PMX_BONE_TAG_INTERPOLATOR_ROTATION,
	};
	return track_interpolator_map;
}

MMDBoneTag::CurrentValuesArray MMDBoneTag::GetCurrentValues(
	GeListNode* node)
{
	if (!m_bone_object)
	{
		return CurrentValuesArray{};
	}

	const Vector RelPos = m_bone_object->GetRelPos();
	const Vector RelRot = m_bone_object->GetRelRot();

	const CurrentValuesArray current_values
	{
		RelPos.x,													// POSITION_X
		RelPos.y,													// POSITION_Y
		RelPos.z,													// POSITION_Z
		RelRot.x,													// ROTATION_X
		RelRot.y,													// ROTATION_Y
		RelRot.z,													// ROTATION_Z
	};

	return current_values;
}

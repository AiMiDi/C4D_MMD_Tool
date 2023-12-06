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
#include "ocajoint.h"
#include "module/tools/object/mmd_bone_root.h"

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
		return false;
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
	return true;
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
		return false;
	
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

Bool MMDBoneTag::SetDParameter(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_SET& flags)
{
	BaseContainer* bc = reinterpret_cast<BaseList2D*>(node)->GetDataInstance();
	if (bc == nullptr)
	{
		return false;
	}
	switch (id[0].id)
	{
	case PMX_BONE_ROTATABLE:
	{
		if (m_bone_object == nullptr)
			return true;
		if (BaseTag* protection_tag = m_bone_object->GetTag(Tprotection); protection_tag != nullptr)
		{
			if (t_data.GetBool() == true)
			{
				protection_tag->SetParameter(ConstDescID(DescLevel(PROTECTION_R_X)), false, DESCFLAGS_SET::NONE);
				protection_tag->SetParameter(ConstDescID(DescLevel(PROTECTION_R_Y)), false, DESCFLAGS_SET::NONE);
				protection_tag->SetParameter(ConstDescID(DescLevel(PROTECTION_R_Z)), false, DESCFLAGS_SET::NONE);
			}
			else
			{
				protection_tag->SetParameter(ConstDescID(DescLevel(PROTECTION_R_X)), true, DESCFLAGS_SET::NONE);
				protection_tag->SetParameter(ConstDescID(DescLevel(PROTECTION_R_Y)), true, DESCFLAGS_SET::NONE);
				protection_tag->SetParameter(ConstDescID(DescLevel(PROTECTION_R_Z)), true, DESCFLAGS_SET::NONE);
			}
		}
		RefreshColor(node);
		break;
	}
	case PMX_BONE_TRANSLATABLE:
	{
		if (m_bone_object == nullptr)
			return true;
		if (BaseTag* protection_tag = m_bone_object->GetTag(Tprotection); protection_tag != nullptr)
		{
			if (t_data.GetBool() == true)
			{
				protection_tag->SetParameter(ConstDescID(DescLevel(PROTECTION_P_X)), false, DESCFLAGS_SET::NONE);
				protection_tag->SetParameter(ConstDescID(DescLevel(PROTECTION_P_Y)), false, DESCFLAGS_SET::NONE);
				protection_tag->SetParameter(ConstDescID(DescLevel(PROTECTION_P_Z)), false, DESCFLAGS_SET::NONE);
			}
			else
			{
				protection_tag->SetParameter(ConstDescID(DescLevel(PROTECTION_P_X)), true, DESCFLAGS_SET::NONE);
				protection_tag->SetParameter(ConstDescID(DescLevel(PROTECTION_P_Y)), true, DESCFLAGS_SET::NONE);
				protection_tag->SetParameter(ConstDescID(DescLevel(PROTECTION_P_Z)), true, DESCFLAGS_SET::NONE);
			}
		}
		this->RefreshColor(node);
		break;
	}
	case PMX_BONE_VISIBLE:
	{
		if (m_bone_object == nullptr)
			return true;
		if (t_data.GetBool() == false)
		{
			m_bone_object->SetParameter(ConstDescID(DescLevel(ID_CA_JOINT_OBJECT_JOINT_DISPLAY)), ID_CA_JOINT_OBJECT_JOINT_DISPLAY_NONE, DESCFLAGS_SET::NONE);
			m_bone_object->SetParameter(ConstDescID(DescLevel(ID_CA_JOINT_OBJECT_BONE_DISPLAY)), ID_CA_JOINT_OBJECT_BONE_DISPLAY_NONE, DESCFLAGS_SET::NONE);
		}
		else
		{
			m_bone_object->SetParameter(ConstDescID(DescLevel(ID_CA_JOINT_OBJECT_JOINT_DISPLAY)), ID_CA_JOINT_OBJECT_JOINT_DISPLAY_AXIS, DESCFLAGS_SET::NONE);
			m_bone_object->SetParameter(ConstDescID(DescLevel(ID_CA_JOINT_OBJECT_BONE_DISPLAY)), ID_CA_JOINT_OBJECT_BONE_DISPLAY_STANDARD, DESCFLAGS_SET::NONE);
		}
		this->RefreshColor(node);
		break;
	}
	case PMX_BONE_INDEXED_TAIL_POSITION:
	{
		if (m_bone_object == nullptr)
			return true;
		switch (t_data.GetInt32())
		{
		case PMX_BONE_TAIL_IS_INDEX:
		{
			if (bc->GetInt32(PMX_BONE_TAIL_INDEX) == -1)
			{
				m_bone_object->SetParameter(ConstDescID(DescLevel(ID_CA_JOINT_OBJECT_BONE_ALIGN)), ID_CA_JOINT_OBJECT_BONE_ALIGN_NULL, DESCFLAGS_SET::NONE);
			}
			else
			{
				m_bone_object->SetParameter(ConstDescID(DescLevel(ID_CA_JOINT_OBJECT_BONE_ALIGN)), ID_CA_JOINT_OBJECT_BONE_ALIGN_TOCHILD, DESCFLAGS_SET::NONE);
			}
			break;
		}
		case PMX_BONE_TAIL_POSITION:
		{
			if (bc->GetVector(PMX_BONE_TAIL_POSITION) == Vector())
			{
				m_bone_object->SetParameter(ConstDescID(DescLevel(ID_CA_JOINT_OBJECT_BONE_ALIGN)), ID_CA_JOINT_OBJECT_BONE_ALIGN_NULL, DESCFLAGS_SET::NONE);
			}
			else
			{
				m_bone_object->SetParameter(ConstDescID(DescLevel(ID_CA_JOINT_OBJECT_BONE_ALIGN)), ID_CA_JOINT_OBJECT_BONE_ALIGN_TOCHILD, DESCFLAGS_SET::NONE);
			}
			break;
		}
		default:
			break;
		}
		break;
	}
	case PMX_BONE_TAIL_INDEX:
	{
		if (m_bone_object == nullptr)
			return true;
		if (bc->GetInt32(PMX_BONE_INDEXED_TAIL_POSITION) == PMX_BONE_TAIL_IS_INDEX)
		{
			if (t_data.GetInt32() == -1)
			{
				m_bone_object->SetParameter(ConstDescID(DescLevel(ID_CA_JOINT_OBJECT_BONE_ALIGN)), ID_CA_JOINT_OBJECT_BONE_ALIGN_NULL, DESCFLAGS_SET::NONE);
			}
			else {
				m_bone_object->SetParameter(ConstDescID(DescLevel(ID_CA_JOINT_OBJECT_BONE_ALIGN)), ID_CA_JOINT_OBJECT_BONE_ALIGN_TOCHILD, DESCFLAGS_SET::NONE);
			}
		}
		break;
	}
	case PMX_BONE_TAIL_POSITION:
	{
		if (m_bone_object == nullptr)
			return true;
		if (bc->GetInt32(PMX_BONE_INDEXED_TAIL_POSITION) == PMX_BONE_TAIL_POSITION)
		{
			if (t_data.GetVector().IsZero())
			{
				m_bone_object->SetParameter(ConstDescID(DescLevel(ID_CA_JOINT_OBJECT_BONE_ALIGN)), ID_CA_JOINT_OBJECT_BONE_ALIGN_NULL, DESCFLAGS_SET::NONE);
			}
			else {
				m_bone_object->SetParameter(ConstDescID(DescLevel(ID_CA_JOINT_OBJECT_BONE_ALIGN)), ID_CA_JOINT_OBJECT_BONE_ALIGN_TOCHILD, DESCFLAGS_SET::NONE);
			}
		}
		break;
	}
	case PMX_BONE_NAME_IS:
	{
		if (m_bone_object == nullptr)
			return true;
		if (t_data.GetInt32() == true)
		{
			m_bone_object->SetName(bc->GetString(PMX_BONE_NAME_UNIVERSAL));
		}
		else {
			m_bone_object->SetName(bc->GetString(PMX_BONE_NAME_LOCAL));
		}
		break;
	}
	case PMX_BONE_NAME_UNIVERSAL:
	case PMX_BONE_NAME_LOCAL:
	{
		if (m_bone_object == nullptr)
			return true;
		if (bc->GetInt32(PMX_BONE_NAME_IS) == 1)
		{
			m_bone_object->SetName(bc->GetString(PMX_BONE_NAME_UNIVERSAL));
		}
		else {
			m_bone_object->SetName(bc->GetString(PMX_BONE_NAME_LOCAL));
		}
		break;
	}
	case PMX_BONE_INHERIT_BONE_PARENT_LINK:
	{
		if (node->GetEnabling(ConstDescID(DescLevel(PMX_BONE_INHERIT_BONE_PARENT_LINK)), GeData(), DESCFLAGS_ENABLE::NONE, nullptr)) {
			if (m_bone_root == nullptr)
				return true;
			if (SDK2024_Const auto inherit_bone_parent_link = t_data.GetBaseLink(); inherit_bone_parent_link != nullptr) {
				inherit_bone_parent_link->CopyTo(inherit_bone_parent, COPYFLAGS::NONE, nullptr);
				if (const auto inherit_bone_parent_index = m_bone_root->GetNodeData<MMDBoneRootObject>()->GetBoneIndex(inherit_bone_parent);
					inherit_bone_parent_index != -1)
				{
					bc->SetInt32(PMX_BONE_INHERIT_BONE_PARENT_INDEX, inherit_bone_parent_index);
				}
			}
		}
		break;
	}
	case PMX_BONE_INHERIT_BONE_PARENT_INDEX:
	{
		if (node->GetEnabling(ConstDescID(DescLevel(PMX_BONE_INHERIT_BONE_PARENT_INDEX)), GeData(), DESCFLAGS_ENABLE::NONE, nullptr)) {
			if (m_bone_root == nullptr)
				return true;
			if (SDK2024_Const auto inherit_bone_parent_link_ptr = m_bone_root->GetNodeData<MMDBoneRootObject>()->GetBoneLink(t_data.GetInt32());
				inherit_bone_parent_link_ptr != nullptr)
			{
				if (SDK2024_Const auto inherit_bone_parent_link = bc->GetBaseLink(PMX_BONE_INHERIT_BONE_PARENT_LINK);
					inherit_bone_parent_link == nullptr)
				{
					node->SetParameter(ConstDescID(DescLevel(PMX_BONE_INHERIT_BONE_PARENT_LINK)), BaseLink::Alloc(), DESCFLAGS_SET::NONE);
				}
				inherit_bone_parent_link_ptr->CopyTo(inherit_bone_parent, COPYFLAGS::NONE, nullptr);
			}
		}
		break;
	}
	case PMX_BONE_IS_IK:
	case PMX_BONE_IS_FIXED_AXIS:
	case PMX_BONE_INHERIT_ROTATION:
	case PMX_BONE_INHERIT_TRANSLATION:
	{
		this->RefreshColor(node);
		break;
	}
	default:
		break;
	}
	return SUPER::SetDParameter(node, id, t_data, flags);
}

Bool MMDBoneTag::GetDEnabling(const GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_ENABLE flags,
	const BaseContainer* itemdesc) const
{
	switch (id[0].id)
	{
	case PMX_BONE_TAIL_INDEX:
		if (const Bool indexed_tail_position = itemdesc->GetBool(PMX_BONE_INDEXED_TAIL_POSITION);
			indexed_tail_position == PMX_BONE_TAIL_IS_POSITION)
		{
			return false;
		}
		break;
	case PMX_BONE_TAIL_POSITION:
		if (const Bool indexed_tail_position = itemdesc->GetBool(PMX_BONE_INDEXED_TAIL_POSITION);
			indexed_tail_position == PMX_BONE_TAIL_IS_INDEX)
		{
			return false;
		}
		break;
	[[fallthrough]] case PMX_BONE_INHERIT_BONE_PARENT_INDEX:
	[[fallthrough]] case PMX_BONE_INHERIT_BONE_PARENT_INFLUENCE:
	case PMX_BONE_INHERIT_BONE_PARENT_LINK:
		const Bool inherit_rotation = itemdesc->GetBool(PMX_BONE_INHERIT_ROTATION);
		const Bool inherit_translation = itemdesc->GetBool(PMX_BONE_INHERIT_TRANSLATION);
		if (inherit_rotation == 0 && inherit_translation == 0)
		{
			return false;
		}
		break;
	case PMX_BONE_FIXED_AXIS:
		if (const Bool fixed_axis = itemdesc->GetBool(PMX_BONE_IS_FIXED_AXIS); fixed_axis == 0)
		{
			return false;
		}
		break;
	[[fallthrough]] case PMX_BONE_LOCAL_X:
	case PMX_BONE_LOCAL_Z:
		if (const Bool local_coordinate = itemdesc->GetBool(PMX_BONE_LOCAL_IS_COORDINATE); local_coordinate == 0)
		{
			return false;
		}
		break;
	default:;
	}
	return SUPER::GetDEnabling(node, id, t_data, flags, itemdesc);
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

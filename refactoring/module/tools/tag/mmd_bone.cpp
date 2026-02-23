/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & CMT contributors.
Author:			Aimidi
Date:			2023/9/12
File:			mmd_bone_root.h
Description:	DESC

**************************************************************************/

#include <c4d.h>
#include <c4d_symbols.h>
#include "plugin_resource.h"
#include "module/core/cmt_marco.h"
#include "mmd_bone.h"

#include "customgui_priority.h"
#include "ocajoint.h"
#include "tprotection.h"
#include "maxon/quaternion.h"
#include "description/TMMDBone.h"
#include "module/tools/object/mmd_bone_manager.h"

Bool MMDBoneTag::RefreshColor(GeListNode* node, BaseObject* op)
{
	if (!op)
	{
		op = bone_object_;
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

NodeData* MMDBoneTag::Alloc()
{
	return NewObj(MMDBoneTag).GetValue();
}
SDK2024_Init(MMDBoneTag)
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
	bc->SetFloat(PMX_BONE_INHERIT_BONE_PARENT_INFLUENCE, 0.0);
	bc->SetVector(PMX_BONE_LOCAL_X, Vector(1, 0, 0));
	bc->SetVector(PMX_BONE_LOCAL_Z, Vector(0, 0, 1));

	if (GeData priority; node->GetParameter(ConstDescID(DescLevel(EXPRESSION_PRIORITY)), priority, DESCFLAGS_GET::NONE))
	{
		if (auto* pd = GetCustomDataTypeWritable<PriorityData>(priority, CUSTOMGUI_PRIORITY_DATA))
		{
			pd->SetPriorityValue(PRIORITYVALUE_MODE, CYCLE_ANIMATION);
			pd->SetPriorityValue(PRIORITYVALUE_PRIORITY, 2);
			bc->SetData(EXPRESSION_PRIORITY, priority);
		}
	}

	return SDK2024_SuperInit;
}

void MMDBoneTag::HandleDescriptionUpdate(GeListNode* node, BaseContainer* const bc, const Int32 id)
{
	switch (id)
	{
	case PMX_BONE_ROTATABLE:
	{
		if (!bone_object_)
			return;
		if (!protection_tag_)
		{
			if (!CreateBoneLockTag())
				break;
		}
		SetRotationLock(!bc->GetBool(id));
		RefreshColor(node);
		break;
	}
	case PMX_BONE_TRANSLATABLE:
	{
		if (!bone_object_)
			return;
		if (!protection_tag_)
		{
			if (!CreateBoneLockTag())
				break;
		}
		SetPositionLock(!bc->GetBool(id));
		RefreshColor(node);
		break;
	}
	case PMX_BONE_VISIBLE:
	{
		if (!bone_object_)
			return;
		if (!bc->GetBool(id))
		{
			bone_object_->SetParameter(ConstDescID(DescLevel(ID_CA_JOINT_OBJECT_JOINT_DISPLAY)), ID_CA_JOINT_OBJECT_JOINT_DISPLAY_NONE, DESCFLAGS_SET::NONE);
			bone_object_->SetParameter(ConstDescID(DescLevel(ID_CA_JOINT_OBJECT_BONE_DISPLAY)), ID_CA_JOINT_OBJECT_BONE_DISPLAY_NONE, DESCFLAGS_SET::NONE);
		}
		else
		{
			bone_object_->SetParameter(ConstDescID(DescLevel(ID_CA_JOINT_OBJECT_JOINT_DISPLAY)), ID_CA_JOINT_OBJECT_JOINT_DISPLAY_AXIS, DESCFLAGS_SET::NONE);
			bone_object_->SetParameter(ConstDescID(DescLevel(ID_CA_JOINT_OBJECT_BONE_DISPLAY)), ID_CA_JOINT_OBJECT_BONE_DISPLAY_STANDARD, DESCFLAGS_SET::NONE);
		}
		this->RefreshColor(node);
		break;
	}
	case PMX_BONE_INDEXED_TAIL_POSITION:
	{
		if (!bone_object_)
			return;
		switch (bc->GetInt32(id))
		{
		case PMX_BONE_TAIL_IS_INDEX:
			{
				if (bc->GetInt32(PMX_BONE_TAIL_INDEX) == -1)
				{
					bone_object_->SetParameter(ConstDescID(DescLevel(ID_CA_JOINT_OBJECT_BONE_ALIGN)), ID_CA_JOINT_OBJECT_BONE_ALIGN_NULL, DESCFLAGS_SET::NONE);
				}
				else
				{
					bone_object_->SetParameter(ConstDescID(DescLevel(ID_CA_JOINT_OBJECT_BONE_ALIGN)), ID_CA_JOINT_OBJECT_BONE_ALIGN_TOCHILD, DESCFLAGS_SET::NONE);
				}
				break;
			}
		case PMX_BONE_TAIL_POSITION:
			{
				if (bc->GetVector(PMX_BONE_TAIL_POSITION) == Vector())
				{
					bone_object_->SetParameter(ConstDescID(DescLevel(ID_CA_JOINT_OBJECT_BONE_ALIGN)), ID_CA_JOINT_OBJECT_BONE_ALIGN_NULL, DESCFLAGS_SET::NONE);
				}
				else
				{
					bone_object_->SetParameter(ConstDescID(DescLevel(ID_CA_JOINT_OBJECT_BONE_ALIGN)), ID_CA_JOINT_OBJECT_BONE_ALIGN_TOCHILD, DESCFLAGS_SET::NONE);
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
		if (!bone_object_)
			return;
		if (bc->GetInt32(PMX_BONE_INDEXED_TAIL_POSITION) == PMX_BONE_TAIL_IS_INDEX)
		{
			if (bc->GetInt32(id) == -1)
			{
				bone_object_->SetParameter(ConstDescID(DescLevel(ID_CA_JOINT_OBJECT_BONE_ALIGN)), ID_CA_JOINT_OBJECT_BONE_ALIGN_NULL, DESCFLAGS_SET::NONE);
			}
			else {
				bone_object_->SetParameter(ConstDescID(DescLevel(ID_CA_JOINT_OBJECT_BONE_ALIGN)), ID_CA_JOINT_OBJECT_BONE_ALIGN_TOCHILD, DESCFLAGS_SET::NONE);
			}
		}
		break;
	}
	case PMX_BONE_TAIL_POSITION:
	{
		if (!bone_object_)
			return;
		if (bc->GetInt32(PMX_BONE_INDEXED_TAIL_POSITION) == PMX_BONE_TAIL_POSITION)
		{
			if (bc->GetVector(id).IsZero())
			{
				bone_object_->SetParameter(ConstDescID(DescLevel(ID_CA_JOINT_OBJECT_BONE_ALIGN)), ID_CA_JOINT_OBJECT_BONE_ALIGN_NULL, DESCFLAGS_SET::NONE);
			}
			else {
				bone_object_->SetParameter(ConstDescID(DescLevel(ID_CA_JOINT_OBJECT_BONE_ALIGN)), ID_CA_JOINT_OBJECT_BONE_ALIGN_TOCHILD, DESCFLAGS_SET::NONE);
			}
		}
		break;
	}
	case PMX_BONE_NAME_IS:
	{
		if (!bone_object_)
			return;
		if (bc->GetInt32(id))
		{
			bone_object_->SetName(bc->GetString(PMX_BONE_NAME_UNIVERSAL));
		}
		else {
			bone_object_->SetName(bc->GetString(PMX_BONE_NAME_LOCAL));
		}
		break;
	}
	case PMX_BONE_NAME_UNIVERSAL:
	case PMX_BONE_NAME_LOCAL:
	{
		if (!bone_object_)
			return;
		if (bc->GetInt32(PMX_BONE_NAME_IS) == 1)
		{
			bone_object_->SetName(bc->GetString(PMX_BONE_NAME_UNIVERSAL));
		}
		else {
			bone_object_->SetName(bc->GetString(PMX_BONE_NAME_LOCAL));
		}
		break;
	}
	case PMX_BONE_IS_IK:
	case PMX_BONE_IS_FIXED_AXIS:
	case PMX_BONE_INHERIT_ROTATION:
	case PMX_BONE_INHERIT_TRANSLATION:
		{
			RefreshColor(node);
			break;
		}
	default:
		break;
	}
}

void MMDBoneTag::HandleBoneModeChange(const Int32 bone_mode)
{
	if (bone_mode_ == bone_mode)
		return;

	if (bone_mode == BONE_MODE_EDIT)
	{
		// TODO: Save to mmd_node_
		if (bone_object_)
			bone_object_->ChangeNBit(NBIT::NO_DD, NBITCONTROL::CLEAR);
	}
	else
	{
		if (bone_object_)
			bone_object_->ChangeNBit(NBIT::NO_DD, NBITCONTROL::SET);
	}

	bone_mode_ = bone_mode;
}

void MMDBoneTag::SetBoneDisplay(const BaseContainer* const data_instance_bc, const MMDBoneManagerObjectMsg* msg) const
{
	switch (msg->display_type)
	{
	case BONE_DISPLAY_TYPE_MOVABLE:
		{
			if (data_instance_bc->GetBool(PMX_BONE_TRANSLATABLE))
			{
				bone_object_->SetEditorMode(MODE_ON);
				bone_object_->SetRenderMode(MODE_ON);
			}
			else {
				bone_object_->SetEditorMode(MODE_OFF);
				bone_object_->SetRenderMode(MODE_OFF);
			}
			break;
		}
	case BONE_DISPLAY_TYPE_ROTATABLE:
		{
			if (data_instance_bc->GetBool(PMX_BONE_ROTATABLE))
			{
				bone_object_->SetEditorMode(MODE_ON);
				bone_object_->SetRenderMode(MODE_ON);
			}
			else {
				bone_object_->SetEditorMode(MODE_OFF);
				bone_object_->SetRenderMode(MODE_OFF);
			}
			break;
		}
	case BONE_DISPLAY_TYPE_VISIBLE:
		{
			if (data_instance_bc->GetBool(PMX_BONE_VISIBLE))
			{
				bone_object_->SetEditorMode(MODE_ON);
				bone_object_->SetRenderMode(MODE_ON);
			}
			else {
				bone_object_->SetEditorMode(MODE_OFF);
				bone_object_->SetRenderMode(MODE_OFF);
			}
			break;
		}
	case BONE_DISPLAY_TYPE_ENABLED:
		{
			if (data_instance_bc->GetBool(PMX_BONE_ENABLED))
			{
				bone_object_->SetEditorMode(MODE_ON);
				bone_object_->SetRenderMode(MODE_ON);
			}
			else {
				bone_object_->SetEditorMode(MODE_OFF);
				bone_object_->SetRenderMode(MODE_OFF);
			}
			break;
		}
	case BONE_DISPLAY_TYPE_IK:
		{
			if (data_instance_bc->GetBool(PMX_BONE_IS_IK))
			{
				bone_object_->SetEditorMode(MODE_ON);
				bone_object_->SetRenderMode(MODE_ON);
			}
			else {
				bone_object_->SetEditorMode(MODE_OFF);
				bone_object_->SetRenderMode(MODE_OFF);
			}
			break;
		}
	default:
		bone_object_->SetEditorMode(MODE_UNDEF);
		bone_object_->SetRenderMode(MODE_UNDEF);
		break;
	}
}

static Int32 GetTagBoneIndex(const BaseTag* tag)
{
	GeData data;
	tag->GetParameter(ConstDescID(DescLevel(PMX_BONE_INDEX)), data, DESCFLAGS_GET::NONE);
	return data.GetString().ToInt32(nullptr);
}

void MMDBoneTag::HandleBoneIndexUpdate(BaseContainer* const bc, BaseObject* bone_manager_object) const
{
	if (!bone_object_)
		return;

	BaseObject* up_obj = bone_object_->GetUp();
	BaseObject* prev_obj = bone_object_->GetPred();
	const Int32 prev_index = bc->GetString(PMX_BONE_INDEX).ToInt32(nullptr);

	if (!up_obj)
	{
		bc->SetString(PMX_BONE_INDEX, "0"_s);
		if (prev_index != 0 && bone_manager_object != nullptr)
		{
			MMDBoneTagMsg msg(MMDBoneTagMsgType::BONE_INDEX_CHANGE);
			bone_manager_object->Message(g_mmd_bone_tag_id, &msg);
		}
		return;
	}

	Int32 new_bone_index = -1;

	if (up_obj->IsInstanceOf(g_mmd_bone_manager_object_id))
	{
		if (prev_obj)
		{
			if (SDK2024_Const BaseTag* prev_tag = prev_obj->GetTag(g_mmd_bone_tag_id); prev_tag)
				new_bone_index = GetTagBoneIndex(prev_tag) + 1;
		}
		else
		{
			new_bone_index = 0;
			bc->SetString(PMX_BONE_PARENT_BONE_INDEX, "-1"_s);
		}
	}
	else
	{
		SDK2024_Const BaseTag* up_tag = up_obj->GetTag(g_mmd_bone_tag_id);
		if (up_tag)
		{
			GeData data;
			up_tag->GetParameter(ConstDescID(DescLevel(PMX_BONE_INDEX)), data, DESCFLAGS_GET::NONE);
			bc->SetData(PMX_BONE_PARENT_BONE_INDEX, data);
		}

		if (prev_obj)
		{
			BaseObject* last_obj = prev_obj;
			while (last_obj->GetDownLast())
				last_obj = last_obj->GetDownLast();

			if (SDK2024_Const BaseTag* last_tag = last_obj->GetTag(g_mmd_bone_tag_id); last_tag)
				new_bone_index = GetTagBoneIndex(last_tag) + 1;
		}
		else if (up_tag)
		{
			new_bone_index = GetTagBoneIndex(up_tag) + 1;
		}
	}

	if (prev_index != new_bone_index)
	{
		bc->SetString(PMX_BONE_INDEX, String::IntToString(new_bone_index));
		if (bone_manager_object != nullptr)
		{
			MMDBoneTagMsg msg(MMDBoneTagMsgType::BONE_INDEX_CHANGE);
			bone_manager_object->Message(g_mmd_bone_tag_id, &msg);
		}
	}
}

Bool MMDBoneTag::Message(GeListNode* node, Int32 type, void* data)
{
	iferr_scope_handler{
		return true;
	};
	const auto bc = reinterpret_cast<BaseList2D*>(node)->GetDataInstance();
	if (!bc)
	{
		return true;
	}
	switch (type)
	{
	case MSG_DESCRIPTION_CHECKUPDATE:
		HandleDescriptionUpdate(node, bc, static_cast<DescriptionCheckUpdate*>(data)->descid->operator[](0).id);
		break;
	case MSG_MENUPREPARE:
		if (const auto doc = static_cast<BaseDocument*>(data); doc)
		{
			if (BaseObject* op = doc->GetActiveObject(); op)
			{
				const String name = op->GetName();
				node->SetParameter(ConstDescID(DescLevel(PMX_BONE_NAME_LOCAL)), name, DESCFLAGS_SET::NONE);
				RefreshColor(node, op);
			}
		}
		break;
	case  g_mmd_bone_manager_object_id:
		if (const auto* msg = static_cast<MMDBoneManagerObjectMsg*>(data); msg)
		{
			switch (msg->type)
			{
			case MMDBoneManagerObjectMsgType::SET_BONE_DISPLAY_UPDATE:
				SetBoneDisplay(bc, msg);
				break;
			case MMDBoneManagerObjectMsgType::BONE_HIERARCHY_UPDATE:
				HandleBoneIndexUpdate(bc, msg->bone_manager_object);
				break;
			case MMDBoneManagerObjectMsgType::BONE_MODE_CHANGE:
				HandleBoneModeChange(msg->bone_mode);
				break;
			case MMDBoneManagerObjectMsgType::DEFAULT:
			case MMDBoneManagerObjectMsgType::BONE_MORPH_CHANGE:
				break;
			}
		}
		break;
	default: ;
	}

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
		if (!bone_object_)
			break;
		if (!protection_tag_)
		{
			if (!CreateBoneLockTag())
				break;
		}
		SetRotationLock(!t_data.GetBool());
		RefreshColor(node);
		break;
	}
	case PMX_BONE_TRANSLATABLE:
	{
		if (!bone_object_)
			break;
		if (!protection_tag_)
		{
			if (!CreateBoneLockTag())
				break;
		}
		SetPositionLock(!t_data.GetBool());
		RefreshColor(node);
		break;
	}
	case PMX_BONE_VISIBLE:
	{
		if (!bone_object_)
			break;
		if (!t_data.GetBool())
		{
			bone_object_->SetParameter(ConstDescID(DescLevel(ID_CA_JOINT_OBJECT_JOINT_DISPLAY)), ID_CA_JOINT_OBJECT_JOINT_DISPLAY_NONE, DESCFLAGS_SET::NONE);
			bone_object_->SetParameter(ConstDescID(DescLevel(ID_CA_JOINT_OBJECT_BONE_DISPLAY)), ID_CA_JOINT_OBJECT_BONE_DISPLAY_NONE, DESCFLAGS_SET::NONE);
		}
		else
		{
			bone_object_->SetParameter(ConstDescID(DescLevel(ID_CA_JOINT_OBJECT_JOINT_DISPLAY)), ID_CA_JOINT_OBJECT_JOINT_DISPLAY_AXIS, DESCFLAGS_SET::NONE);
			bone_object_->SetParameter(ConstDescID(DescLevel(ID_CA_JOINT_OBJECT_BONE_DISPLAY)), ID_CA_JOINT_OBJECT_BONE_DISPLAY_STANDARD, DESCFLAGS_SET::NONE);
		}
		this->RefreshColor(node);
		break;
	}
	case PMX_BONE_INDEXED_TAIL_POSITION:
	{
		if (!bone_object_)
			break;
		switch (t_data.GetInt32())
		{
		case PMX_BONE_TAIL_IS_INDEX:
		{
			if (bc->GetInt32(PMX_BONE_TAIL_INDEX) == -1)
			{
				bone_object_->SetParameter(ConstDescID(DescLevel(ID_CA_JOINT_OBJECT_BONE_ALIGN)), ID_CA_JOINT_OBJECT_BONE_ALIGN_NULL, DESCFLAGS_SET::NONE);
			}
			else
			{
				bone_object_->SetParameter(ConstDescID(DescLevel(ID_CA_JOINT_OBJECT_BONE_ALIGN)), ID_CA_JOINT_OBJECT_BONE_ALIGN_TOCHILD, DESCFLAGS_SET::NONE);
			}
			break;
		}
		case PMX_BONE_TAIL_POSITION:
		{
			if (bc->GetVector(PMX_BONE_TAIL_POSITION) == Vector())
			{
				bone_object_->SetParameter(ConstDescID(DescLevel(ID_CA_JOINT_OBJECT_BONE_ALIGN)), ID_CA_JOINT_OBJECT_BONE_ALIGN_NULL, DESCFLAGS_SET::NONE);
			}
			else
			{
				bone_object_->SetParameter(ConstDescID(DescLevel(ID_CA_JOINT_OBJECT_BONE_ALIGN)), ID_CA_JOINT_OBJECT_BONE_ALIGN_TOCHILD, DESCFLAGS_SET::NONE);
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
		if (!bone_object_)
			break;
		if (bc->GetInt32(PMX_BONE_INDEXED_TAIL_POSITION) == PMX_BONE_TAIL_IS_INDEX)
		{
			if (t_data.GetInt32() == -1)
			{
				bone_object_->SetParameter(ConstDescID(DescLevel(ID_CA_JOINT_OBJECT_BONE_ALIGN)), ID_CA_JOINT_OBJECT_BONE_ALIGN_NULL, DESCFLAGS_SET::NONE);
			}
			else {
				bone_object_->SetParameter(ConstDescID(DescLevel(ID_CA_JOINT_OBJECT_BONE_ALIGN)), ID_CA_JOINT_OBJECT_BONE_ALIGN_TOCHILD, DESCFLAGS_SET::NONE);
			}
		}
		break;
	}
	case PMX_BONE_TAIL_POSITION:
	{
		if (!bone_object_)
			break;
		if (bc->GetInt32(PMX_BONE_INDEXED_TAIL_POSITION) == PMX_BONE_TAIL_POSITION)
		{
			if (t_data.GetVector().IsZero())
			{
				bone_object_->SetParameter(ConstDescID(DescLevel(ID_CA_JOINT_OBJECT_BONE_ALIGN)), ID_CA_JOINT_OBJECT_BONE_ALIGN_NULL, DESCFLAGS_SET::NONE);
			}
			else {
				bone_object_->SetParameter(ConstDescID(DescLevel(ID_CA_JOINT_OBJECT_BONE_ALIGN)), ID_CA_JOINT_OBJECT_BONE_ALIGN_TOCHILD, DESCFLAGS_SET::NONE);
			}
		}
		break;
	}
	case PMX_BONE_NAME_IS:
	{
		if (!bone_object_)
			break;
		if (t_data.GetInt32())
		{
			bone_object_->SetName(bc->GetString(PMX_BONE_NAME_UNIVERSAL));
		}
		else {
			bone_object_->SetName(bc->GetString(PMX_BONE_NAME_LOCAL));
		}
		break;
	}
	case PMX_BONE_NAME_UNIVERSAL:
	case PMX_BONE_NAME_LOCAL:
	{
		if (!bone_object_)
			break;
		if (bc->GetInt32(PMX_BONE_NAME_IS) == 1)
		{
			bone_object_->SetName(bc->GetString(PMX_BONE_NAME_UNIVERSAL));
		}
		else {
			bone_object_->SetName(bc->GetString(PMX_BONE_NAME_LOCAL));
		}
		break;
	}
case PMX_BONE_LAYER:
	{
		if (GeData priority; node->GetParameter(ConstDescID(DescLevel(EXPRESSION_PRIORITY)), priority, DESCFLAGS_GET::NONE))
		{
		if (auto* pd = GetCustomDataTypeWritable<PriorityData>(priority, CUSTOMGUI_PRIORITY_DATA))
		{
			pd->SetPriorityValue(PRIORITYVALUE_PRIORITY, t_data);
			pd->SetPriorityValue(PRIORITYVALUE_MODE, CYCLE_EXPRESSION);
			bc->SetData(EXPRESSION_PRIORITY, priority);
		}
		}
		break;
	}
	case PMX_BONE_IS_IK:
	{
		is_IK = bc->GetBool(PMX_BONE_IS_IK);
		const auto state = reinterpret_cast<BaseList2D*>(Get())->GetDescIDState(ConstDescID(DescLevel(PMX_BONE_IK_GRP)), true);
		if (is_IK)
			reinterpret_cast<BaseList2D*>(Get())->SetDescIDState(ConstDescID(DescLevel(PMX_BONE_IK_GRP)), ~DESCIDSTATE::HIDDEN & state);
		else
			reinterpret_cast<BaseList2D*>(Get())->SetDescIDState(ConstDescID(DescLevel(PMX_BONE_IK_GRP)), DESCIDSTATE::HIDDEN | state);
		[[fallthrough]];
	}
	case PMX_BONE_IS_FIXED_AXIS: [[fallthrough]];
	case PMX_BONE_INHERIT_ROTATION: [[fallthrough]];
	case PMX_BONE_INHERIT_TRANSLATION:
	{
		RefreshColor(node);
		break;
	}
	default:
		break;
	}
	return SUPER::SetDParameter(node, id, t_data, flags);
}

SDK2024_GetDEnabling(MMDBoneTag)
{
	if (bone_mode_ != BONE_MODE_EDIT)
		return false;

	GeData ge_data;
	switch (id[0].id)
	{
	case PMX_BONE_TAIL_INDEX:
		node->GetParameter(ConstDescID(DescLevel(PMX_BONE_INDEXED_TAIL_POSITION)), ge_data, DESCFLAGS_GET::NONE);
		if (const auto indexed_tail_position = ge_data.GetInt32();
			indexed_tail_position == PMX_BONE_TAIL_IS_POSITION)
		{
			return false;
		}
		return true;
	case PMX_BONE_TAIL_POSITION:
		node->GetParameter(ConstDescID(DescLevel(PMX_BONE_INDEXED_TAIL_POSITION)), ge_data, DESCFLAGS_GET::NONE);
		if (const auto indexed_tail_position = ge_data.GetInt32();
			indexed_tail_position == PMX_BONE_TAIL_IS_INDEX)
		{
			return false;
		}
		return true;
	case PMX_BONE_INHERIT_BONE_PARENT_INDEX:
	case PMX_BONE_INHERIT_BONE_PARENT_INFLUENCE:
	case PMX_BONE_INHERIT_BONE_PARENT_LINK:
	{
		node->GetParameter(ConstDescID(DescLevel(PMX_BONE_INHERIT_ROTATION)), ge_data, DESCFLAGS_GET::NONE);
		const auto inherit_rotation = ge_data.GetBool();
		node->GetParameter(ConstDescID(DescLevel(PMX_BONE_INHERIT_TRANSLATION)), ge_data, DESCFLAGS_GET::NONE);
		const auto inherit_translation = ge_data.GetBool();
		if (inherit_rotation || inherit_translation)
		{
			return true;
		}
		return false;
	}
	case PMX_BONE_FIXED_AXIS:
		node->GetParameter(ConstDescID(DescLevel(PMX_BONE_IS_FIXED_AXIS)), ge_data, DESCFLAGS_GET::NONE);
		if (const Bool fixed_axis = ge_data.GetBool(); !fixed_axis)
		{
			return false;
		}
		return true;
	case PMX_BONE_LOCAL_X:
	case PMX_BONE_LOCAL_Z:
		node->GetParameter(ConstDescID(DescLevel(PMX_BONE_LOCAL_IS_COORDINATE)), ge_data, DESCFLAGS_GET::NONE);
		if (const Bool local_coordinate = ge_data.GetBool(); !local_coordinate)
		{
			return false;
		}
		return true;
	default:;
	}
	return true;
}

bool MMDBoneTag::CreateBoneLockTag()
{
	if(!bone_object_)
		return false;
	protection_tag_ = bone_object_->MakeTag(Tprotection);
	if (!protection_tag_)
	{
		// TODO: Log
		// GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
		// MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
		return false;
	}
	protection_tag_->ChangeNBit(NBIT::OHIDE, NBITCONTROL::SET);
	protection_tag_->ChangeNBit(NBIT::AHIDE_FOR_HOST, NBITCONTROL::SET);
	protection_tag_->SetParameter(ConstDescID(DescLevel(PROTECTION_ALLOW_EXPRESSIONS)), true, DESCFLAGS_SET::NONE);
	return true;
}

void MMDBoneTag::SetRotationLock(const bool flag) const
{
	protection_tag_->SetParameter(ConstDescID(DescLevel(PROTECTION_R_X)), flag, DESCFLAGS_SET::NONE);
	protection_tag_->SetParameter(ConstDescID(DescLevel(PROTECTION_R_Y)), flag, DESCFLAGS_SET::NONE);
	protection_tag_->SetParameter(ConstDescID(DescLevel(PROTECTION_R_Z)), flag, DESCFLAGS_SET::NONE);
}

void MMDBoneTag::SetPositionLock(const bool flag) const
{
	protection_tag_->SetParameter(ConstDescID(DescLevel(PROTECTION_P_X)), flag, DESCFLAGS_SET::NONE);
	protection_tag_->SetParameter(ConstDescID(DescLevel(PROTECTION_P_Y)), flag, DESCFLAGS_SET::NONE);
	protection_tag_->SetParameter(ConstDescID(DescLevel(PROTECTION_P_Z)), flag, DESCFLAGS_SET::NONE);
}

EXECUTIONRESULT MMDBoneTag::Execute(BaseTag* tag, BaseDocument* doc, BaseObject* op, BaseThread* bt, Int32 priority, EXECUTIONFLAGS flags)
{
	if (!op)
		return EXECUTIONRESULT::OK;

	if(!bone_object_)
		bone_object_ = op;

	if (bone_mode_ == BONE_MODE_EDIT)
	{
		const auto bc = tag->GetDataInstance();
		if (!bc)
			return EXECUTIONRESULT::OK;

		HandleBoneIndexUpdate(bc, reinterpret_cast<BaseObject*>(bone_manager_data_->Get()));
	}
	else if (bone_mode_ == BONE_MODE_VMD && mmd_node_)
	{
		const auto& local = mmd_node_->GetLocalTransform();
		const Eigen::Vector3f translate = local.col(3).head<3>() - mmd_node_->GetInitialTranslate();
		const auto pm = bone_manager_data_->GetPositionMultiple();

		bone_object_->SetRelMl(Matrix{Vector(translate.x(), translate.y(), translate.z()) * pm,
		   Vector(local(0,0), local(1,0), local(2,0)),
		   Vector(local(0,1), local(1,1), local(2,1)),
		   Vector(local(0,2), local(1,2), local(2,2)) });
	}

	return EXECUTIONRESULT::OK;
}

Bool MMDBoneTag::Read(GeListNode* node, HyperFile* hf, Int32 level)
{
	IOReadField(bone_manager_data_);
	return SUPER::Read(node, hf, level);
}

SDK2024_Write(MMDBoneTag)
{
	IOWriteField(bone_manager_data_);
	return SUPER::Write(node, hf);
}

Int32 MMDBoneTag::GetBoneIndex() const
{
	return !mmd_node_ ? -1 : static_cast<Int32>(mmd_node_->GetIndex());
}

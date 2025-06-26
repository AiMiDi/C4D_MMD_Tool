/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & CMT contributors.
Author:			Aimidi
Date:			2023/9/12
File:			mmd_bone_root.h
Description:	DESC

**************************************************************************/

#include "pch.h"
#include "mmd_bone.h"

#include "maxon/quaternion.h"
#include "description/TMMDBone.h"
#include "module/tools/object/mmd_bone_manager.h"

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

MMDBoneTagMsg::MMDBoneTagMsg(const MMDBoneTagMsgType type): type(type)
{}

void MMDBoneTag::SetBoneManager(BaseObject* bone_manager)
{
	m_bone_manager = bone_manager;
}

void MMDBoneTag::SetBoneObject(BaseObject* bone_object)
{
	if(!bone_object && m_bone_tag)
		m_bone_object = m_bone_tag->GetObject();
	else
		m_bone_object = bone_object;
}

void MMDBoneTag::SetBoneTag(BaseTag* bone_tag)
{
	if(bone_tag)
		m_bone_tag = bone_tag;
	else
		m_bone_tag = reinterpret_cast<BaseTag*>(Get());
}

void MMDBoneTag::SetMMDNode(saba::MMDNode* mmd_node)
{
	m_mmd_node = mmd_node;
}

NodeData* MMDBoneTag::Alloc()
{
	return NewObj(MMDBoneTag).GetValue();
}

Bool MMDBoneTag::Init(GeListNode* node SDK2024_InitParaName)
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

	return SUPER::Init(node SDK2024_InitPara);
}

void MMDBoneTag::HandleDescriptionUpdate(GeListNode* node, BaseContainer* const bc, const Int32 id)
{
	switch (id)
	{
	case PMX_BONE_ROTATABLE:
		{
			if (!m_bone_object)
				return;
			if (!protection_tag)
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
			if (!m_bone_object)
				return;
			if (!protection_tag)
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
			if (!m_bone_object)
				return;
			if (!bc->GetBool(id))
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
			if (!m_bone_object)
				return;
			switch (bc->GetInt32(id))
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
			if (!m_bone_object)
				return;
			if (bc->GetInt32(PMX_BONE_INDEXED_TAIL_POSITION) == PMX_BONE_TAIL_IS_INDEX)
			{
				if (bc->GetInt32(id) == -1)
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
			if (!m_bone_object)
				return;
			if (bc->GetInt32(PMX_BONE_INDEXED_TAIL_POSITION) == PMX_BONE_TAIL_POSITION)
			{
				if (bc->GetVector(id).IsZero())
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
			if (!m_bone_object)
				return;
			if (bc->GetInt32(id))
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
			if (!m_bone_object)
				return;
			if (bc->GetInt32(PMX_BONE_NAME_IS) == 1)
			{
				m_bone_object->SetName(bc->GetString(PMX_BONE_NAME_UNIVERSAL));
			}
			else {
				m_bone_object->SetName(bc->GetString(PMX_BONE_NAME_LOCAL));
			}
			break;
		}
	case PMX_BONE_LAYER:
	{
		if (GeData priority; node->GetParameter(ConstDescID(DescLevel(EXPRESSION_PRIORITY)), priority, DESCFLAGS_GET::NONE))
		{
			if (auto* pd = DataGetCustomDataType(priority, PriorityData, CUSTOMGUI_PRIORITY_DATA))
			{
				pd->SetPriorityValue(PRIORITYVALUE_PRIORITY, bc->GetData(PMX_BONE_LAYER));
				bc->SetData(EXPRESSION_PRIORITY, priority);
			}
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

void MMDBoneTag::SetBoneDisplay(const BaseContainer* const data_instance_bc, const MMDBoneManagerObjectMsg* msg) const
{
	switch (msg->display_type)
	{
	case BONE_DISPLAY_TYPE_MOVABLE:
		{
			if (data_instance_bc->GetBool(PMX_BONE_TRANSLATABLE))
			{
				m_bone_object->SetEditorMode(MODE_ON);
				m_bone_object->SetRenderMode(MODE_ON);
			}
			else {
				m_bone_object->SetEditorMode(MODE_OFF);
				m_bone_object->SetRenderMode(MODE_OFF);
			}
			break;
		}
	case BONE_DISPLAY_TYPE_ROTATABLE:
		{
			if (data_instance_bc->GetBool(PMX_BONE_ROTATABLE))
			{
				m_bone_object->SetEditorMode(MODE_ON);
				m_bone_object->SetRenderMode(MODE_ON);
			}
			else {
				m_bone_object->SetEditorMode(MODE_OFF);
				m_bone_object->SetRenderMode(MODE_OFF);
			}
			break;
		}
	case BONE_DISPLAY_TYPE_VISIBLE:
		{
			if (data_instance_bc->GetBool(PMX_BONE_VISIBLE))
			{
				m_bone_object->SetEditorMode(MODE_ON);
				m_bone_object->SetRenderMode(MODE_ON);
			}
			else {
				m_bone_object->SetEditorMode(MODE_OFF);
				m_bone_object->SetRenderMode(MODE_OFF);
			}
			break;
		}
	case BONE_DISPLAY_TYPE_ENABLED:
		{
			if (data_instance_bc->GetBool(PMX_BONE_ENABLED))
			{
				m_bone_object->SetEditorMode(MODE_ON);
				m_bone_object->SetRenderMode(MODE_ON);
			}
			else {
				m_bone_object->SetEditorMode(MODE_OFF);
				m_bone_object->SetRenderMode(MODE_OFF);
			}
			break;
		}
	case BONE_DISPLAY_TYPE_IK:
		{
			if (data_instance_bc->GetBool(PMX_BONE_IS_IK))
			{
				m_bone_object->SetEditorMode(MODE_ON);
				m_bone_object->SetRenderMode(MODE_ON);
			}
			else {
				m_bone_object->SetEditorMode(MODE_OFF);
				m_bone_object->SetRenderMode(MODE_OFF);
			}
			break;
		}
	default:
		m_bone_object->SetEditorMode(MODE_UNDEF);
		m_bone_object->SetRenderMode(MODE_UNDEF);
		break;
	}
}

void MMDBoneTag::HandleBoneHierarchyUpdate(BaseContainer* const data_instance_bc, const MMDBoneManagerObjectMsg* msg)
{
	m_bone_manager = msg->bond_root_object;
	if (m_bone_object) {
		BaseObject* up_obj = m_bone_object->GetUp();
		BaseObject* prev_obj = m_bone_object->GetPred();
		const Int32	prev_index = data_instance_bc->GetString(PMX_BONE_INDEX).ToInt32(nullptr);
		if (up_obj)
		{
			GeData Ge_data;
			if (!up_obj->IsInstanceOf(ID_O_MMD_BONE_ROOT))
			{
				SDK2024_Const BaseTag* up_tag = up_obj->GetTag(ID_T_MMD_BONE);
				if (up_tag)
				{
					up_tag->GetParameter(ConstDescID(DescLevel(PMX_BONE_INDEX)), Ge_data, DESCFLAGS_GET::NONE);
					data_instance_bc->SetData(PMX_BONE_PARENT_BONE_INDEX, Ge_data);
				}
				if (prev_obj == nullptr)
				{
					if (up_tag != nullptr)
					{
						up_tag->GetParameter(ConstDescID(DescLevel(PMX_BONE_INDEX)), Ge_data, DESCFLAGS_GET::NONE);
						data_instance_bc->SetString(PMX_BONE_INDEX, String::IntToString(Ge_data.GetString().ToInt32(nullptr) + 1));
					}
				}
				else {
					BaseObject* lase_obj = prev_obj;
					while (lase_obj->GetDownLast() != nullptr)
					{
						lase_obj = lase_obj->GetDownLast();
					}

					if (SDK2024_Const BaseTag* last_tag = lase_obj->GetTag(ID_T_MMD_BONE); last_tag != nullptr)
					{
						last_tag->GetParameter(ConstDescID(DescLevel(PMX_BONE_INDEX)), Ge_data, DESCFLAGS_GET::NONE);
						data_instance_bc->SetString(PMX_BONE_INDEX, String::IntToString(Ge_data.GetString().ToInt32(nullptr) + 1));
					}
				}
			}
			else {
				if (prev_obj == nullptr)
				{
					data_instance_bc->SetString(PMX_BONE_INDEX, "0"_s);
				}
				else {
					if (SDK2024_Const BaseTag* prev_tag = prev_obj->GetTag(ID_T_MMD_BONE); prev_tag != nullptr)
					{
						prev_tag->GetParameter(ConstDescID(DescLevel(PMX_BONE_INDEX)), Ge_data, DESCFLAGS_GET::NONE);
						data_instance_bc->SetString(PMX_BONE_INDEX, String::IntToString(Ge_data.GetString().ToInt32(nullptr) + 1));
					}
				}
			}
		}
		else {
			data_instance_bc->SetString(PMX_BONE_INDEX, "0"_s);
		}
		bool error = false;
		if (const Int32 now_index = data_instance_bc->GetString(PMX_BONE_INDEX).ToInt32(&error);
			!error && now_index != prev_index && m_bone_manager != nullptr)
			m_bone_manager->Message(ID_T_MMD_BONE, nullptr);
	}
}

Bool MMDBoneTag::Message(GeListNode* node, Int32 type, void* data)
{
	iferr_scope_handler{
		return true;
	};
	const auto data_instance_bc = reinterpret_cast<BaseList2D*>(node)->GetDataInstance();
	if (!data_instance_bc)
	{
		return true;
	}
	switch (type)
	{
	case MSG_DESCRIPTION_CHECKUPDATE:
		HandleDescriptionUpdate(node, data_instance_bc, static_cast<DescriptionCheckUpdate*>(data)->descid->operator[](0).id);
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
	case  ID_O_MMD_BONE_ROOT:
		if (const auto* msg = static_cast<MMDBoneManagerObjectMsg*>(data); msg)
		{
			switch (msg->type)
			{
			case MMDBoneManagerObjectMsgType::SET_BONE_DISPLAY_UPDATE:
				SetBoneDisplay(data_instance_bc, msg);
				break;
			case MMDBoneManagerObjectMsgType::BONE_HIERARCHY_UPDATE:
				HandleBoneHierarchyUpdate(data_instance_bc, msg);
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
		if (!m_bone_object)
			break;
		if (!protection_tag)
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
		if (!m_bone_object)
			break;
		if (!protection_tag)
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
		if (!m_bone_object)
			break;
		if (!t_data.GetBool())
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
		if (!m_bone_object)
			break;
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
		if (!m_bone_object)
			break;
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
		if (!m_bone_object)
			break;
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
		if (!m_bone_object)
			break;
		if (t_data.GetInt32())
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
		if (!m_bone_object)
			break;
		if (bc->GetInt32(PMX_BONE_NAME_IS) == 1)
		{
			m_bone_object->SetName(bc->GetString(PMX_BONE_NAME_UNIVERSAL));
		}
		else {
			m_bone_object->SetName(bc->GetString(PMX_BONE_NAME_LOCAL));
		}
		break;
	}
	case PMX_BONE_LAYER:
	{
		if (GeData priority; node->GetParameter(ConstDescID(DescLevel(EXPRESSION_PRIORITY)), priority, DESCFLAGS_GET::NONE))
		{
			if (auto* pd = DataGetCustomDataType(priority, PriorityData, CUSTOMGUI_PRIORITY_DATA))
			{
				pd->SetPriorityValue(PRIORITYVALUE_PRIORITY, t_data);
				bc->SetData(EXPRESSION_PRIORITY, priority);
			}
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
	return SUPER::SetDParameter(node, id, t_data, flags);
}

Bool MMDBoneTag::GetDEnabling(SDK2024_Const GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_ENABLE flags,
	const BaseContainer* itemdesc) SDK2024_Const
{
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
	if(!m_bone_object)
		return false;
	protection_tag = m_bone_object->MakeTag(Tprotection);
	if (!protection_tag)
	{
		// TODO: Log
		// GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
		// MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
		return false;
	}
	protection_tag->ChangeNBit(NBIT::OHIDE, NBITCONTROL::SET);
	protection_tag->ChangeNBit(NBIT::AHIDE_FOR_HOST, NBITCONTROL::SET);
	protection_tag->SetParameter(ConstDescID(DescLevel(PROTECTION_ALLOW_EXPRESSIONS)), true, DESCFLAGS_SET::NONE);
	return true;
}

void MMDBoneTag::HandleBoneLockUpdate(const BaseContainer* bc)
{
	if (!protection_tag)
		if (!CreateBoneLockTag())
			return;
	SetRotationLock(!bc->GetBool(PMX_BONE_ROTATABLE));
	SetPositionLock(!bc->GetBool(PMX_BONE_TRANSLATABLE));
}

void MMDBoneTag::SetRotationLock(const bool flag) const
{
	protection_tag->SetParameter(ConstDescID(DescLevel(PROTECTION_R_X)), flag, DESCFLAGS_SET::NONE);
	protection_tag->SetParameter(ConstDescID(DescLevel(PROTECTION_R_Y)), flag, DESCFLAGS_SET::NONE);
	protection_tag->SetParameter(ConstDescID(DescLevel(PROTECTION_R_Z)), flag, DESCFLAGS_SET::NONE);
}

void MMDBoneTag::SetPositionLock(const bool flag) const
{
	protection_tag->SetParameter(ConstDescID(DescLevel(PROTECTION_P_X)), flag, DESCFLAGS_SET::NONE);
	protection_tag->SetParameter(ConstDescID(DescLevel(PROTECTION_P_Y)), flag, DESCFLAGS_SET::NONE);
	protection_tag->SetParameter(ConstDescID(DescLevel(PROTECTION_P_Z)), flag, DESCFLAGS_SET::NONE);
}

EXECUTIONRESULT MMDBoneTag::Execute(BaseTag* tag, BaseDocument* doc, BaseObject* op, BaseThread* bt, Int32 priority,
                                    EXECUTIONFLAGS flags)
{
	if (!tag || !op)
		return EXECUTIONRESULT::OK;

	BaseContainer* bc = tag->GetDataInstance();
	if (!bc)
		return EXECUTIONRESULT::OK;

	if(!m_bone_object)
		m_bone_object = op;

	if(!m_bone_tag)
		m_bone_tag = tag;

	HandleBoneLockUpdate(bc);

	if (m_mmd_node)
	{
		const auto& animation_translate = m_mmd_node->GetAnimationTranslate();
		const auto& animation_rotate = m_mmd_node->GetAnimationRotate();

		const auto local_matrix = maxon::Matrix{Vector{animation_translate.x, animation_translate.y, animation_rotate.z},
			maxon::Quaternion64(animation_rotate.x, animation_rotate.y, animation_rotate.z, animation_rotate.w).GetMatrix()};

		m_bone_object->SetMl(local_matrix);
	}

	return EXECUTIONRESULT::OK;
}

Bool MMDBoneTag::Read(GeListNode* node, HyperFile* hf, Int32 level)
{
	iferr_scope_handler{
		return false;
	};
	{
		AutoAlloc<BaseLink> bone_manager_link;
		if (!bone_manager_link)
			return false;
		if (!bone_manager_link->Read(hf))
			return false;
		m_bone_manager = reinterpret_cast<BaseObject*>(bone_manager_link->ForceGetLink());
	}

	return SUPER::Read(node, hf, level);
}

Bool MMDBoneTag::Write(SDK2024_Const GeListNode* node, HyperFile* hf) SDK2024_Const
{
	iferr_scope_handler{
		return false;
	};
	AutoAlloc<BaseLink> bone_manager_link;
	if (!bone_manager_link)
		return false;
	bone_manager_link->SetLink(m_bone_manager);
	if (!bone_manager_link->Write(hf))
		return false;
	return SUPER::Write(node, hf);
}

Int32 MMDBoneTag::GetBoneIndex() const
{
	return !m_mmd_node ? -1 : static_cast<Int32>(m_mmd_node->GetIndex());
}

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

Bool BoneMorphData::Write(HyperFile* hf) const
{
	if (!grp_id.Write(hf))
		return false;
	if (!strength_id.Write(hf))
		return false;
	if (!translation_id.Write(hf))
		return false;
	if (!rotation_id.Write(hf))
		return false;
	if (!button_grp_id.Write(hf))
		return false;
	if (!button_delete_id.Write(hf))
		return false;
	if (!button_rename_id.Write(hf))
		return false;
	if (!hf->WriteString(name))
		return false;
	return true;
}

Bool BoneMorphData::Read(HyperFile* hf)
{
	if (!grp_id.Read(hf))
		return false;
	if (!strength_id.Read(hf))
		return false;
	if (!translation_id.Read(hf))
		return false;
	if (!rotation_id.Read(hf))
		return false;
	if (!button_grp_id.Read(hf))
		return false;
	if (!button_delete_id.Read(hf))
		return false;
	if (!button_rename_id.Read(hf))
		return false;
	if (!hf->ReadString(&name))
		return false;
	return true;
}

NodeData* MMDBoneTag::Alloc()
{
	iferr_scope_handler
	{
		return nullptr;
	};
	return NewObj(MMDBoneTag, nullptr, nullptr) iferr_return;
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
		if (!m_bone_object)
			return true;
		if (!protection_tag)
		{
			if (!CreateBoneLockTag())
				break;
		}
		auto SetRotationProtectionFunc = [this](const bool flag)
			{
				protection_tag->SetParameter(ConstDescID(DescLevel(PROTECTION_R_X)), flag, DESCFLAGS_SET::NONE);
				protection_tag->SetParameter(ConstDescID(DescLevel(PROTECTION_R_Y)), flag, DESCFLAGS_SET::NONE);
				protection_tag->SetParameter(ConstDescID(DescLevel(PROTECTION_R_Z)), flag, DESCFLAGS_SET::NONE);
			};
		SetRotationProtectionFunc(!t_data.GetBool());
		RefreshColor(node);
		break;
	}
	case PMX_BONE_TRANSLATABLE:
	{
		if (!m_bone_object)
			return true;
		if (!protection_tag)
		{
			if (!CreateBoneLockTag())
				break;
		}
		auto SetPositionProtectionFunc = [this](const bool flag)
			{
				protection_tag->SetParameter(ConstDescID(DescLevel(PROTECTION_P_X)), flag, DESCFLAGS_SET::NONE);
				protection_tag->SetParameter(ConstDescID(DescLevel(PROTECTION_P_Y)), flag, DESCFLAGS_SET::NONE);
				protection_tag->SetParameter(ConstDescID(DescLevel(PROTECTION_P_Z)), flag, DESCFLAGS_SET::NONE);
			};
		SetPositionProtectionFunc(!t_data.GetBool());
		RefreshColor(node);
		break;
	}
	case PMX_BONE_VISIBLE:
	{
		if (!m_bone_object)
			return true;
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
		if (!m_bone_object)
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
		if (!m_bone_object)
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
		if (!m_bone_object)
			return true;
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
		if (m_bone_root == nullptr)
			return true;
		if (node->GetEnabling(ConstDescID(DescLevel(PMX_BONE_INHERIT_BONE_PARENT_LINK)), GeData(), DESCFLAGS_ENABLE::NONE, nullptr)) {
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
		if (!m_bone_root)
			return true;
		if (node->GetEnabling(ConstDescID(DescLevel(PMX_BONE_INHERIT_BONE_PARENT_INDEX)), GeData(), DESCFLAGS_ENABLE::NONE, nullptr)) {
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
		RefreshColor(node);
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

void MMDBoneTag::CheckInheritBoneParent(const BaseDocument* doc, BaseObject* op, const BaseContainer* bc)
{
	auto CheckInheritBoneParentFunc = [this, &bc, &doc](const std::function<void(const BaseObject*)>& UpdateFunc)
	{
		if (!inherit_bone_parent->IsCacheLink())
		{
			if (SDK2024_Const BaseLink* inherit_bone_parent_link = bc->GetBaseLink(PMX_BONE_INHERIT_BONE_PARENT_LINK);
				!inherit_bone_parent_link)
				inherit_bone_parent_link->CopyTo(inherit_bone_parent, COPYFLAGS::NONE, nullptr);
		}
		else if (const auto inherit_bone_parent_object = reinterpret_cast<const BaseObject*>(inherit_bone_parent->GetLink(doc, Ojoint));
			inherit_bone_parent_object) {
			UpdateFunc(inherit_bone_parent_object);
		}
	};

	if (bc->GetBool(PMX_BONE_INHERIT_ROTATION))
	{
		CheckInheritBoneParentFunc([&op, &bc](const BaseObject* inherit_bone_parent_object)
		{
			op->SetRelRot(inherit_bone_parent_object->GetRelRot() * bc->GetFloat(PMX_BONE_INHERIT_BONE_PARENT_INFLUENCE));
		});
	}
	if (bc->GetBool(PMX_BONE_INHERIT_TRANSLATION))
	{
		CheckInheritBoneParentFunc([&op, &bc](const BaseObject* inherit_bone_parent_object)
		{
			op->SetRelPos(inherit_bone_parent_object->GetRelPos()* bc->GetFloat(PMX_BONE_INHERIT_BONE_PARENT_INFLUENCE));
		});
	}
}

void MMDBoneTag::UpdateBoneMorph(const BaseTag* tag, BaseObject* op)
{
	GeData Ge_data;
	op->GetParameter(ConstDescID(DescLevel(ID_BASEOBJECT_FROZEN_POSITION)), Ge_data, DESCFLAGS_GET::NONE);
	const Vector op_position = Ge_data.GetVector() - prev_position;
	prev_position = Vector(0);
	op->GetParameter(ConstDescID(DescLevel(ID_BASEOBJECT_FROZEN_ROTATION)), Ge_data, DESCFLAGS_GET::NONE);
	const Vector op_rotation = Ge_data.GetVector() - prev_rotation;
	prev_rotation = Vector(0);

	for (const auto& id : bone_morph_data_arr)
	{
		Float strength = 0;
		if (tag->GetParameter(id.strength_id, Ge_data, DESCFLAGS_GET::NONE))
		{
			strength = Ge_data.GetFloat();
		}
		if (tag->GetParameter(id.translation_id, Ge_data, DESCFLAGS_GET::NONE))
		{
			prev_position += Ge_data.GetVector() * strength;
		}
		if (tag->GetParameter(id.rotation_id, Ge_data, DESCFLAGS_GET::NONE))
		{
			prev_rotation += Ge_data.GetVector() * strength;
		}
	}
	op->SetParameter(ConstDescID(DescLevel(ID_BASEOBJECT_FROZEN_POSITION)), op_position + prev_position, DESCFLAGS_SET::NONE);
	op->SetParameter(ConstDescID(DescLevel(ID_BASEOBJECT_FROZEN_ROTATION)), op_rotation + prev_rotation, DESCFLAGS_SET::NONE);
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

void MMDBoneTag::UpdateBoneLock(BaseObject* op, const BaseContainer* bc)
{
	if (!protection_tag)
	{
		if (!CreateBoneLockTag())
			return;
	}
	if (bc->GetBool(PMX_BONE_ROTATABLE) == true)
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
	if (bc->GetBool(PMX_BONE_TRANSLATABLE) == true)
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

void MMDBoneTag::UpdateBoneIndex(BaseTag* tag, BaseObject* op, BaseContainer* bc)
{
	BaseObject* up_obj = op->GetUp();
	BaseObject* prev_obj = op->GetPred();
	const Int32	prev_index = bc->GetString(PMX_BONE_INDEX).ToInt32(nullptr);
	if (up_obj)
	{
		GeData Ge_data;
		BaseObject* tmp_lase_obj;
		BaseObject* lase_obj;
		BaseTag* lase_tag;
		if (!up_obj->IsInstanceOf(ID_O_MMD_BONE_ROOT))
		{
			tag->SetParameter(ConstDescID(DescLevel(PMX_BONE_PARENT_BONE_NAME)), up_obj->GetName(), DESCFLAGS_SET::NONE);
			if (const BaseTag* up_tag = up_obj->GetTag(ID_T_MMD_BONE); !up_tag)
			{
				up_tag->GetParameter(ConstDescID(DescLevel(PMX_BONE_INDEX)), Ge_data, DESCFLAGS_GET::NONE);
				bc->SetData(PMX_BONE_PARENT_BONE_INDEX, Ge_data);
				if (!prev_obj)
				{
					up_tag->GetParameter(ConstDescID(DescLevel(PMX_BONE_INDEX)), Ge_data, DESCFLAGS_GET::NONE);
					bc->SetString(PMX_BONE_INDEX, String::IntToString(Ge_data.GetString().ToInt32(nullptr) + 1));
				}
			}
			else {
				lase_obj = prev_obj;
				// Get the previous bone
				while (prev_obj != nullptr && !prev_obj->IsInstanceOf(Ojoint)) {
					lase_obj = prev_obj;
					prev_obj = prev_obj->GetPred();
				}
				// Get the last bone
				tmp_lase_obj = lase_obj->GetDownLast();
				while (tmp_lase_obj != nullptr)
				{
					if (tmp_lase_obj->IsInstanceOf(Ojoint)) {
						lase_obj = tmp_lase_obj;
						tmp_lase_obj = tmp_lase_obj->GetDownLast();
					}
					else {
						tmp_lase_obj = tmp_lase_obj->GetPred();
					}
				}
				lase_tag = lase_obj->GetTag(ID_T_MMD_BONE);
				if (lase_tag != nullptr)
				{
					lase_tag->GetParameter(ConstDescID(DescLevel(PMX_BONE_INDEX)), Ge_data, DESCFLAGS_GET::NONE);
					bc->SetString(PMX_BONE_INDEX, String::IntToString(Ge_data.GetString().ToInt32(nullptr) + 1));
				}
			}
		}
		else {
			if (!prev_obj)
			{
				if (!m_bone_root)
				{
					m_bone_root = up_obj;
					// TODO: const maxon::StrongRef<OMMDBoneRoot_MSG> BoneRoot_msg(NewObj(OMMDBoneRoot_MSG, OMMDBoneRoot_MSG_Type::BONEROOT_UPDATA, 0, up_obj).GetValue());
					// op->MultiMessage(MULTIMSG_ROUTE::BROADCAST, ID_O_MMD_BONE_ROOT, BoneRoot_msg);
				}
				bc->SetString(PMX_BONE_INDEX, "0"_s);
			}
			else {
				lase_obj = prev_obj;
				// Get the previous bone
				while (prev_obj != nullptr && !prev_obj->IsInstanceOf(Ojoint)) {
					lase_obj = prev_obj;
					prev_obj = prev_obj->GetPred();
				}
				// Get the last bone
				tmp_lase_obj = lase_obj->GetDownLast();
				while (tmp_lase_obj != nullptr)
				{
					if (tmp_lase_obj->IsInstanceOf(Ojoint)) {
						lase_obj = tmp_lase_obj;
						tmp_lase_obj = tmp_lase_obj->GetDownLast();
					}
					else {
						tmp_lase_obj = tmp_lase_obj->GetPred();
					}
				}
				lase_tag = lase_obj->GetTag(ID_T_MMD_BONE);
				if (lase_tag != nullptr)
				{
					lase_tag->GetParameter(ConstDescID(DescLevel(PMX_BONE_INDEX)), Ge_data, DESCFLAGS_GET::NONE);
					bc->SetString(PMX_BONE_INDEX, String::IntToString(Ge_data.GetString().ToInt32(nullptr) + 1));
				}
			}
		}
	}
	else {
		m_bone_root = nullptr;
		// TODO: const maxon::StrongRef<OMMDBoneRoot_MSG> BoneRoot_msg(NewObj(OMMDBoneRoot_MSG, OMMDBoneRoot_MSG_Type::BONEROOT_UPDATA, 0, nullptr).GetValue());
		// op->MultiMessage(MULTIMSG_ROUTE::BROADCAST, ID_O_MMD_BONE_ROOT, BoneRoot_msg);
		bc->SetString(PMX_BONE_INDEX, "0"_s);
	}
	if (const Int32 now_index = bc->GetString(PMX_BONE_INDEX).ToInt32(nullptr); now_index != prev_index && m_bone_root) {
		// BONE_INDEX_CHANGE
		// TODO: const maxon::StrongRef<TMMDBone_MSG> msg(NewObj(TMMDBone_MSG, TMMDBone_MSG_Type::BONE_INDEX_CHANGE).GetValue());
		// m_bone_root->Message(ID_T_MMD_BONE, msg);
	}
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

	UpdateBoneLock(op, bc);
	UpdateBoneIndex(tag, op, bc);
	CheckInheritBoneParent(doc, op, bc);
	UpdateBoneMorph(tag, op);

	return SUPER::Execute(op, doc, bt, priority, flags);
}

Bool MMDBoneTag::AddToExecution(BaseTag* tag, PriorityList* list)
{
	if (list == nullptr || tag == nullptr)
	{
		return true;
	}
	list->Add(tag, EXECUTIONPRIORITY_EXPRESSION, EXECUTIONFLAGS::NONE);
	return true;
}

Bool MMDBoneTag::Read(GeListNode* node, HyperFile* hf, Int32 level)
{
	iferr_scope_handler{
		return false;
	};
	{
		AutoAlloc<BaseLink> bone_root_link;
		if (!bone_root_link)
			return false;
		if (!bone_root_link->Read(hf))
			return false;
		m_bone_root = reinterpret_cast<BaseObject*>(bone_root_link->ForceGetLink());
	}
	if (!hf->ReadInt32(&this->m_bone_morph_name_index))
		return false;
	if (!hf->ReadInt32(&this->prev_frame))
		return false;
	if (!hf->ReadInt32(&this->prev_interpolator_type))
		return false;
	if (!hf->ReadVector64(&this->prev_position))
		return false;
	if (!hf->ReadVector64(&this->prev_rotation))
		return false;
	Int button_id_num = 0;
	if (!hf->ReadInt64(&button_id_num))
		return false;
	for (Int button_index = 0; button_index < button_id_num; button_index++)
	{
		DescID button_id;
		if (!button_id.Read(hf))
			return false;
		Int morph_index = 0;
		if (!hf->ReadInt64(&morph_index))
			return false;
		this->button_id_map.Insert(std::move(button_id), morph_index) iferr_return;
	}
	Int morph_num = 0;
	if (!hf->ReadInt64(&morph_num))
		return false;
	bone_morph_data_arr.EnsureCapacity(morph_num)iferr_return;
	for (Int morph_index = 0; morph_index < morph_num; morph_index++)
	{
		auto& bone_morph = bone_morph_data_arr.Append()iferr_return;
		if (!bone_morph.Read(hf))
			return false;
	}
	return SUPER::Read(node, hf, level);
}

Bool MMDBoneTag::Write(const GeListNode* node, HyperFile* hf) const
{
	iferr_scope_handler{
		return false;
	};
	AutoAlloc<BaseLink> bone_root_link;
	if (!bone_root_link)
		return false;
	bone_root_link->SetLink(m_bone_root);
	if (!bone_root_link->Write(hf))
		return false;
	if (!hf->WriteInt32(this->m_bone_morph_name_index))
		return false;
	if (!hf->WriteInt32(this->prev_frame))
		return false;
	if (!hf->WriteInt32(this->prev_interpolator_type))
		return false;
	if (!hf->WriteVector64(this->prev_position))
		return false;
	if (!hf->WriteVector64(this->prev_rotation))
		return false;
	if (!hf->WriteInt64(button_id_map.GetCount()))
		return false;
	for (const auto& button_id : button_id_map)
	{
		if (!button_id.GetKey().Write(hf))
			return false;
		if (!hf->WriteInt64(button_id.GetValue()))
			return false;
	}
	if (!hf->WriteInt64(bone_morph_data_arr.GetCount()))
		return false;
	for (const auto& bone_morph : bone_morph_data_arr)
	{
		if (!bone_morph.Write(hf))
			return false;
	}
	return SUPER::Write(node, hf);
}

Bool MMDBoneTag::IsPhysicalBone() const
{
	return m_is_physical_bone;
}

void MMDBoneTag::SetPhysical(const Bool is_physical_bone)
{
	m_is_physical_bone = is_physical_bone;
}

Int MMDBoneTag::AddBondMorph(String morph_name)
{
	iferr_scope_handler
	{
		return -1;
	};
	if (!m_bone_tag)
		return -1;
	if (morph_name.IsEmpty())
	{
		morph_name = "morph_" + String::IntToString(m_bone_morph_name_index);
		m_bone_morph_name_index++;
	}
	DynamicDescription* const ddesc = m_bone_tag->GetDynamicDescriptionWritable();
	if (ddesc == nullptr)
		return-1;
	auto& data = bone_morph_data_arr.Append()iferr_return;
	BaseContainer bc = GetCustomDataTypeDefault(DTYPE_GROUP);
	bc.SetString(DESC_NAME, morph_name);
	bc.SetData(DESC_PARENTGROUP, DescIDGeData(PMX_BONE_MORPH_GRP));
	data.grp_id = ddesc->Alloc(bc);
	bc = GetCustomDataTypeDefault(DTYPE_REAL);
	bc.SetString(DESC_NAME, morph_name);
	bc.SetFloat(DESC_MAX, 1.);
	bc.SetFloat(DESC_MIN, 0.);
	bc.SetInt32(DESC_CUSTOMGUI, CUSTOMGUI_REALSLIDER);
	bc.SetFloat(DESC_MAXSLIDER, 1.);
	bc.SetFloat(DESC_MINSLIDER, 0.);
	bc.SetFloat(DESC_STEP, 0.01);
	bc.SetInt32(DESC_UNIT, DESC_UNIT_PERCENT);
	bc.SetData(DESC_PARENTGROUP, DescIDGeData(data.grp_id));
	data.strength_id = ddesc->Alloc(bc);
	bc = GetCustomDataTypeDefault(DTYPE_VECTOR);
	bc.SetString(DESC_NAME, GeLoadString(IDS_MORPH_BONE_TRANSLATION));
	bc.SetInt32(DESC_ANIMATE, DESC_ANIMATE_OFF);
	bc.SetData(DESC_PARENTGROUP, DescIDGeData(data.grp_id));
	data.translation_id = ddesc->Alloc(bc);
	bc = GetCustomDataTypeDefault(DTYPE_VECTOR);
	bc.SetString(DESC_NAME, GeLoadString(IDS_MORPH_BONE_ROTATION));
	bc.SetInt32(DESC_ANIMATE, DESC_ANIMATE_OFF);
	bc.SetData(DESC_PARENTGROUP, DescIDGeData(data.grp_id));
	data.rotation_id = ddesc->Alloc(bc);
	bc = GetCustomDataTypeDefault(DTYPE_GROUP);
	bc.SetInt32(DESC_COLUMNS, 2);
	bc.SetData(DESC_PARENTGROUP, DescIDGeData(data.grp_id));
	data.button_grp_id = ddesc->Alloc(bc);
	bc = GetCustomDataTypeDefault(DTYPE_BUTTON);
	bc.SetString(DESC_NAME, GeLoadString(IDS_MORPH_DELETE));
	bc.SetInt32(DESC_CUSTOMGUI, CUSTOMGUI_BUTTON);
	bc.SetData(DESC_PARENTGROUP, DescIDGeData(data.button_grp_id));
	data.button_delete_id = ddesc->Alloc(bc);
	bc = GetCustomDataTypeDefault(DTYPE_BUTTON);
	bc.SetString(DESC_NAME, GeLoadString(IDS_MORPH_RENAME));
	bc.SetInt32(DESC_CUSTOMGUI, CUSTOMGUI_BUTTON);
	bc.SetData(DESC_PARENTGROUP, DescIDGeData(data.button_grp_id));
	data.button_rename_id = ddesc->Alloc(bc);
	const Int index = bone_morph_data_arr.GetIndex(*data);
	iferr(button_id_map.Insert(data.button_delete_id, index))
		return -1;
	iferr(button_id_map.Insert(data.button_rename_id, index))
		return -1;
	// BONE_MORPH_ADD
	// TODO: const maxon::StrongRef<TMMDBone_MSG> msg(NewObj(TMMDBone_MSG, TMMDBone_MSG_Type::BONE_MORPH_ADD, morph_name, data.strength_id, static_cast<BaseTag*>(Get())).GetValue());
	// m_bone_root->Message(ID_T_MMD_BONE, msg);
	data.name = std::move(morph_name);
	if (GeIsMainThread())
	{
		SendCoreMessage(COREMSG_CINEMA, BaseContainer(COREMSG_CINEMA_FORCE_AM_UPDATE)); 
		EventAdd();
	}
	return index;
}

bool MMDBoneTag::CheckBoneMorphIndex(const Int index) const
{
	if (index < 0 || index >= GetMorphCount())
	{
		return false;
	}
	return true;
}

Bool MMDBoneTag::SetBondMorphTranslation(const Int index, const Vector& translation)
{
	if (!CheckBoneMorphIndex(index))
		return nullptr;
	return Get()->SetParameter(bone_morph_data_arr[index].translation_id, translation, DESCFLAGS_SET::NONE);
}

Bool MMDBoneTag::SetBondMorphRotation(const Int index, const Vector& rotation)
{
	if (!CheckBoneMorphIndex(index))
		return nullptr;
	return Get()->SetParameter(bone_morph_data_arr[index].rotation_id, rotation, DESCFLAGS_SET::NONE);
}

Int MMDBoneTag::GetMorphCount() const
{
	return bone_morph_data_arr.GetCount();
}

BoneMorphData* MMDBoneTag::GetMorph(const Int index)
{
	if (!CheckBoneMorphIndex(index))
		return nullptr;
	return &bone_morph_data_arr[index];
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

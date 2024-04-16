/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & CMT contributors.
Author:			Aimidi
Date:			2023/9/12
File:			mmd_bone_root.h
Description:	DESC

**************************************************************************/

#include "pch.h"
#include "mmd_bone.h"
#include "module/tools/object/mmd_bone_root.h"
#include "cmt_tools_setting.h"
#include "utils/math_util.hpp"

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

BoneMorphData::BoneMorphData(String name, DescID grp_id, DescID strength_id, DescID translation_id, DescID rotation_id,
	DescID button_grp_id, DescID button_delete_id, DescID button_rename_id):
	name(std::move(name)),
	grp_id(std::move(grp_id)),
	strength_id(std::move(strength_id)),
	translation_id(std::move(translation_id)),
	rotation_id(std::move(rotation_id)),
	button_grp_id(std::move(button_grp_id)),
	button_delete_id(std::move(button_delete_id)),
	button_rename_id(std::move(button_rename_id))
{
}

Bool BoneMorphData::Write(HyperFile* hf) SDK2024_Const
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

MMDBoneTagMsg::MMDBoneTagMsg(const MMDBoneTagMsgType type): type(type)
{}

MMDBoneTagBoneIndexChangeMsg::MMDBoneTagBoneIndexChangeMsg(): MMDBoneTagMsg(MMDBoneTagMsgType::BONE_INDEX_CHANGE)
{}

MMDBoneTagBoneMorphAddMsg::MMDBoneTagBoneMorphAddMsg(String name, SDK2024_Const BaseTag* bone_tag, const DescID& strength_id):
	MMDBoneTagMsg(MMDBoneTagMsgType::BONE_MORPH_ADD), name(std::move(name)), bone_morph_UI_data(bone_tag, strength_id)
{}

MMDBoneTagBoneMorphDeleteMsg::MMDBoneTagBoneMorphDeleteMsg(String name, SDK2024_Const BaseTag* bone_tag,
	const DescID& strength_id):
	MMDBoneTagMsg(MMDBoneTagMsgType::BONE_MORPH_DELETE), name(std::move(name)), bone_morph_UI_data(bone_tag, strength_id)
{}

MMDBoneTagBoneMorphRenameMsg::MMDBoneTagBoneMorphRenameMsg(String old_name, String new_name, SDK2024_Const BaseTag* bone_tag,
	const DescID& strength_id):
	MMDBoneTagMsg(MMDBoneTagMsgType::BONE_MORPH_RENAME), old_name(std::move(old_name)), new_name(std::move(new_name)), bone_morph_UI_data(bone_tag, strength_id)
{}

void MMDBoneTag::SetBoneRoot(BaseObject* bone_root)
{
	m_bone_root = bone_root;
}

void MMDBoneTag::SetBoneObject(BaseObject* bone_object)
{
	m_bone_object = bone_object;
}

Bool MMDBoneTag::LoadVMD(const libmmd::vmd_bone_key_frame& data, const CMTToolsSetting::MotionImport& setting)
{
	const auto frame_at = static_cast<int32_t>(data.get_frame_at() + setting.time_offset);
	const auto frame_at_time = BaseTime{ data.get_frame_at() + setting.time_offset, 30.0 };

	std::array<CCurve*, m_track_count> curves{ nullptr };

	const auto track_desc_ids = GetTrackDescIDs();

	for (auto track_index = size_t{}; track_index < m_track_count; ++track_index)
	{
		auto& track_id = track_desc_ids[track_index];
		CTrack* track = m_bone_object->FindCTrack(track_id);
		if (!track)
		{
			track = CTrack::Alloc(m_bone_object, track_id);
			if (!track)
			{
				return false;
			}
			m_bone_object->InsertTrackSorted(track);
		}

		auto& curve = curves[track_index];
		curve = track->GetCurve();
		if (!curve)
		{
			return false;
		}
	}
	CTrack* frame_at_track = m_bone_tag->FindCTrack(m_frame_at_desc);
	if (!frame_at_track)
	{
		frame_at_track = CTrack::Alloc(m_bone_tag, m_frame_at_desc);
		if (!frame_at_track)
		{
			return false;
		}
		m_bone_tag->InsertTrackSorted(frame_at_track);
	}
	CCurve* frame_at_curve = frame_at_track->GetCurve();
	if (!frame_at_curve)
	{
		return false;
	}
	CKey* frame_key = frame_at_curve->AddKey(frame_at_time);
	if (!frame_key)
	{
		return false;
	}
	frame_key->SetValue(frame_at_curve, frame_at);

	auto set_curve_value = [&frame_at_time, &curves](const uint8_t& curve_index, const Float& value)
		{
			CCurve* curve = curves[curve_index];
			CKey* key = curve->AddKey(frame_at_time);
			if (!key)
			{
				return false;
			}
			key->SetValue(curve, value);
			return true;
		};

	const auto& position = data.get_position();
	if (!set_curve_value(POSITION_X, maxon::SafeConvert<Float>(position[0]) * setting.position_multiple))
	{
		return false;
	}
	if (!set_curve_value(POSITION_Y, maxon::SafeConvert<Float>(position[1]) * setting.position_multiple))
	{
		return false;
	}
	if (!set_curve_value(POSITION_Z, maxon::SafeConvert<Float>(position[2]) * setting.position_multiple))
	{
		return false;
	}
	if (!LoadVMDInterpolator(PMX_BONE_TAG_INTERPOLATOR_POSITION_X, frame_at, data.get_position_x_interpolator()))
	{
		return false;
	}
	if (!LoadVMDInterpolator(PMX_BONE_TAG_INTERPOLATOR_POSITION_Y, frame_at, data.get_position_y_interpolator()))
	{
		return false;
	}
	if (!LoadVMDInterpolator(PMX_BONE_TAG_INTERPOLATOR_POSITION_Z, frame_at, data.get_position_z_interpolator()))
	{
		return false;
	}

	const auto rotation_euler = math_util::QuaternionToEuler(data.get_rotation());
	if (!set_curve_value(ROTATION_X, maxon::SafeConvert<Float>(rotation_euler.x)))
	{
		return false;
	}
	if (!set_curve_value(ROTATION_Y, maxon::SafeConvert<Float>(rotation_euler.y)))
	{
		return false;
	}
	if (!set_curve_value(ROTATION_Z, maxon::SafeConvert<Float>(rotation_euler.z)))
	{
		return false;
	}
	if (!LoadVMDInterpolator(PMX_BONE_TAG_INTERPOLATOR_ROTATION, frame_at, data.get_rotation_interpolator()))
	{
		return false;
	}
	if (!LoadVMDInterpolator(PMX_BONE_TAG_INTERPOLATOR_ROTATION, frame_at, data.get_rotation_interpolator()))
	{
		return false;
	}
	if (!LoadVMDInterpolator(PMX_BONE_TAG_INTERPOLATOR_ROTATION, frame_at, data.get_rotation_interpolator()))
	{
		return false;
	}

	return true;
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
	bc->SetInt32(PMX_BONE_INHERIT_BONE_PARENT_INDEX, -1);
	bc->SetFloat(PMX_BONE_INHERIT_BONE_PARENT_INFLUENCE, 1.0);
	bc->SetVector(PMX_BONE_LOCAL_X, Vector(1, 0, 0));
	bc->SetVector(PMX_BONE_LOCAL_Z, Vector(0, 0, 1));

	if (!InitInterpolator(node))
		return false;

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
	case PMX_BONE_INHERIT_BONE_PARENT_LINK:
		{
			if (m_bone_root == nullptr)
				return;
			if (node->GetEnabling(ConstDescID(DescLevel(PMX_BONE_INHERIT_BONE_PARENT_LINK)), GeData(), DESCFLAGS_ENABLE::NONE, nullptr))
			{
				if (SDK2024_Const auto inherit_bone_parent_link = bc->GetBaseLink(id); inherit_bone_parent_link != nullptr)
				{
					const auto doc = node->GetDocument();
					if (!doc)
						break;
					inherit_bone_parent_link->CopyTo(inherit_bone_parent, COPYFLAGS::NONE, nullptr);
					if (const auto inherit_bone_parent_index = m_bone_root->GetNodeData<MMDBoneRootObject>()->FindBoneIndex(reinterpret_cast<BaseTag*>(inherit_bone_parent->GetLink(doc)));
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
			return;
		if (node->GetEnabling(ConstDescID(DescLevel(PMX_BONE_INHERIT_BONE_PARENT_INDEX)), GeData(), DESCFLAGS_ENABLE::NONE, nullptr))
		{
			if (SDK2024_Const auto inherit_bone_parent_tag = m_bone_root->GetNodeData<MMDBoneRootObject>()->FindBone(bc->GetInt32(id));
				inherit_bone_parent_tag != nullptr)
			{
				if (!bc->GetBaseLink(PMX_BONE_INHERIT_BONE_PARENT_LINK))
				{
					const auto inherit_bone_parent_link = BaseLink::Alloc();
					inherit_bone_parent_link->SetLink(inherit_bone_parent_tag);
					node->SetParameter(ConstDescID(DescLevel(PMX_BONE_INHERIT_BONE_PARENT_LINK)), inherit_bone_parent_link, DESCFLAGS_SET::NONE);
				}
				inherit_bone_parent->SetLink(inherit_bone_parent_tag);
			}
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

void MMDBoneTag::CheckUserDataButton(GeListNode* node, const DescriptionCommand* description_command)
{
	if (const auto button_id_ptr = button_id_map.Find(description_command->_descId); button_id_ptr != nullptr)
	{
		DynamicDescription* const dynamic_description = node->GetDynamicDescriptionWritable();
		if (dynamic_description == nullptr)
			return;
		const auto button_id = button_id_ptr->GetValue();
		if (button_id == -1)
			return;
		BoneMorphData& morph_data = bone_morph_data_arr[button_id];
		if (description_command->_descId == morph_data.button_delete_id)
		{
			if (QuestionDialog(IDS_MES_BONE_MORPH_DELETE, morph_data.name))
			{
				dynamic_description->Remove(morph_data.button_delete_id);
				dynamic_description->Remove(morph_data.button_rename_id);
				dynamic_description->Remove(morph_data.button_grp_id);
				dynamic_description->Remove(morph_data.rotation_id);
				dynamic_description->Remove(morph_data.translation_id);
				dynamic_description->Remove(morph_data.strength_id);
				dynamic_description->Remove(morph_data.grp_id);
				iferr(button_id_map.Erase(morph_data.button_delete_id))
					return;
				iferr(button_id_map.Erase(morph_data.button_rename_id))
					return;
				for (auto& desc_id : button_id_map.GetKeys())
				{
					if (auto index = button_id_map.FindValue(desc_id); *index > button_id)
					{
						(*index)--;
					}
				}
				// BONE_MORPH_DELETE
				MMDBoneTagBoneMorphDeleteMsg msg{ morph_data.name, reinterpret_cast<BaseTag*>(Get()), morph_data.strength_id };
				m_bone_root->Message(ID_T_MMD_BONE, &msg);
				iferr(bone_morph_data_arr.Erase(button_id))
					return;
				::SendCoreMessage(COREMSG_CINEMA, BaseContainer(COREMSG_CINEMA_FORCE_AM_UPDATE)); 
				if (::GeIsMainThread())
				{
					::EventAdd();
				}
			}
			return;
		}
		if (description_command->_descId == morph_data.button_rename_id)
		{
			auto new_name = morph_data.name;
			if (!RenameDialog(&new_name))
			{
				BaseContainer description_bc = *dynamic_description->Find(morph_data.grp_id);
				description_bc.SetString(DESC_NAME, new_name);
				dynamic_description->Set(morph_data.grp_id, description_bc, nullptr);
				description_bc = *dynamic_description->Find(morph_data.strength_id);
				description_bc.SetString(DESC_NAME, new_name);
				dynamic_description->Set(morph_data.strength_id, description_bc, nullptr);
				// BONE_MORPH_RENAME
				MMDBoneTagBoneMorphRenameMsg msg{ morph_data.name, new_name, reinterpret_cast<BaseTag*>(Get()), morph_data.strength_id };
				m_bone_root->Message(ID_T_MMD_BONE, &msg);
				morph_data.name = std::move(new_name);
				::SendCoreMessage(COREMSG_CINEMA, BaseContainer(COREMSG_CINEMA_FORCE_AM_UPDATE)); 
				if (::GeIsMainThread())
				{
					::EventAdd();
				}
			}
			return;
		}
	}
}

void MMDBoneTag::SetBoneDisplay(const BaseContainer* const data_instance_bc, const MMDBoneRootObjectMsg* msg) const
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

void MMDBoneTag::BoneRootUpdate(BaseContainer* const data_instance_bc, const MMDBoneRootObjectMsg* msg)
{
	m_bone_root = msg->bond_root_object;
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
			!error && now_index != prev_index && m_bone_root != nullptr)
			m_bone_root->Message(ID_T_MMD_BONE, nullptr);
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
	case MSG_DESCRIPTION_COMMAND:
		{
			const auto* description_command = static_cast<DescriptionCommand*>(data);
			if (!description_command)
				return false;
			// check if it is a user data button 
			if (description_command->_descId.GetDepth() == 2 && description_command->_descId[0].id == ID_USERDATA)
			{
				CheckUserDataButton(node, description_command);
			}
			else {
				if(description_command->_descId[0].id == PMX_BONE_MORPH_ADD_BUTTON)
					AddBoneMorph(data_instance_bc->GetString(PMX_BONE_MORPH_ADD_NAME));
			}
			break;
		}
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
		if (const auto* msg = static_cast<MMDBoneRootObjectMsg*>(data); msg)
		{
			switch (msg->type)
			{
			case MMDBoneRootObjectMsgType::SET_BONE_DISPLAY_TYPE:
				SetBoneDisplay(data_instance_bc, msg);
				break;
			case MMDBoneRootObjectMsgType::BONE_ROOT_UPDATE:
				BoneRootUpdate(data_instance_bc, msg);
				break;
			case MMDBoneRootObjectMsgType::DEFAULT:
			case MMDBoneRootObjectMsgType::BONE_MORPH_CHANGE:
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
	case PMX_BONE_INHERIT_BONE_PARENT_LINK:
	{
		if (!m_bone_root)
			break;
		if (node->GetEnabling(ConstDescID(DescLevel(PMX_BONE_INHERIT_BONE_PARENT_LINK)), GeData(), DESCFLAGS_ENABLE::NONE, nullptr))
		{
			const auto doc = node->GetDocument();
			if (!doc)
				break;
			if (SDK2024_Const auto inherit_bone_parent_link = t_data.GetBaseLink(); inherit_bone_parent_link)
			{
				inherit_bone_parent_link->CopyTo(inherit_bone_parent, COPYFLAGS::NONE, nullptr);
				if (const auto inherit_bone_parent_index = m_bone_root->GetNodeData<MMDBoneRootObject>()->FindBoneIndex(reinterpret_cast<BaseTag*>(inherit_bone_parent->GetLink(doc)));
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
			break;
		if (node->GetEnabling(ConstDescID(DescLevel(PMX_BONE_INHERIT_BONE_PARENT_INDEX)), GeData(), DESCFLAGS_ENABLE::NONE, nullptr)) {
			if (SDK2024_Const auto inherit_bone_parent_tag = m_bone_root->GetNodeData<MMDBoneRootObject>()->FindBone(t_data.GetInt32());
				inherit_bone_parent_tag != nullptr)
			{
				if (!bc->GetBaseLink(PMX_BONE_INHERIT_BONE_PARENT_LINK))
				{
					const auto inherit_bone_parent_link = BaseLink::Alloc();
					inherit_bone_parent_link->SetLink(inherit_bone_parent_tag);
					node->SetParameter(ConstDescID(DescLevel(PMX_BONE_INHERIT_BONE_PARENT_LINK)), inherit_bone_parent_link, DESCFLAGS_SET::NONE);
				}
				inherit_bone_parent->SetLink(inherit_bone_parent_tag);
			}
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
	if(!itemdesc)
		return SUPER::GetDEnabling(node, id, t_data, flags, itemdesc);
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
	case PMX_BONE_INHERIT_BONE_PARENT_INDEX:
	case PMX_BONE_INHERIT_BONE_PARENT_INFLUENCE:
	case PMX_BONE_INHERIT_BONE_PARENT_LINK:
		{
			const Bool inherit_rotation = itemdesc->GetBool(PMX_BONE_INHERIT_ROTATION);
			const Bool inherit_translation = itemdesc->GetBool(PMX_BONE_INHERIT_TRANSLATION);
			if (inherit_rotation == 0 && inherit_translation == 0)
			{
				return false;
			}
			break;
		}
	case PMX_BONE_FIXED_AXIS:
		if (const Bool fixed_axis = itemdesc->GetBool(PMX_BONE_IS_FIXED_AXIS); fixed_axis == 0)
		{
			return false;
		}
		break;
	case PMX_BONE_LOCAL_X:
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

void MMDBoneTag::HandleInheritParentBone(const BaseDocument* doc, BaseObject* op, const BaseContainer* bc)
{
	auto CheckInheritBoneParentFunc = [this, &doc](const std::function<void(const BaseObject*)>& UpdateFunc)
	{
		if (const auto inherit_bone_parent_object = reinterpret_cast<const BaseObject*>(inherit_bone_parent->GetLink(doc, Ojoint));
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

void MMDBoneTag::HandleBoneMorphUpdate(SDK2024_Const BaseTag* tag, BaseObject* op)
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

void MMDBoneTag::HandleBoneIndexUpdate(BaseTag* tag, BaseObject* op, BaseContainer* bc)
{
	BaseObject* up_obj = op->GetUp();
	BaseObject* prev_obj = op->GetPred();
	const Int32	prev_index = m_bone_index;
	if (up_obj)
	{
		GeData Ge_data;
		BaseObject* tmp_lase_obj;
		BaseObject* lase_obj;
		BaseTag* lase_tag;
		if (!up_obj->IsInstanceOf(ID_O_MMD_BONE_ROOT))
		{
			tag->SetParameter(ConstDescID(DescLevel(PMX_BONE_PARENT_BONE_NAME)), up_obj->GetName(), DESCFLAGS_SET::NONE);
			if (SDK2024_Const BaseTag* up_tag = up_obj->GetTag(ID_T_MMD_BONE); up_tag)
			{
				up_tag->GetParameter(ConstDescID(DescLevel(PMX_BONE_INDEX)), Ge_data, DESCFLAGS_GET::NONE);
				bc->SetData(PMX_BONE_PARENT_BONE_INDEX, Ge_data);
				if (!prev_obj)
				{
					up_tag->GetParameter(ConstDescID(DescLevel(PMX_BONE_INDEX)), Ge_data, DESCFLAGS_GET::NONE);
					m_bone_index = Ge_data.GetString().ToInt32(nullptr) + 1;
				}
				else
				{
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
						m_bone_index = Ge_data.GetString().ToInt32(nullptr) + 1;
					}
				}
			}
		}
		else
		{
			if (!prev_obj)
			{
				if (!m_bone_root)
				{
					m_bone_root = up_obj;
					const maxon::StrongRef<MMDBoneRootObjectMsg> BoneRoot_msg(NewObj(MMDBoneRootObjectMsg, MMDBoneRootObjectMsgType::BONE_ROOT_UPDATE, 0, up_obj).GetValue());
					op->MultiMessage(MULTIMSG_ROUTE::BROADCAST, ID_O_MMD_BONE_ROOT, BoneRoot_msg);
				}
				m_bone_index = 0;
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
					m_bone_index = Ge_data.GetString().ToInt32(nullptr) + 1;
				}
			}
		}
	}
	else {
		m_bone_root = nullptr;
		const maxon::StrongRef<MMDBoneRootObjectMsg> BoneRoot_msg(NewObj(MMDBoneRootObjectMsg, MMDBoneRootObjectMsgType::BONE_ROOT_UPDATE, 0, nullptr).GetValue());
		op->MultiMessage(MULTIMSG_ROUTE::BROADCAST, ID_O_MMD_BONE_ROOT, BoneRoot_msg);
		m_bone_index = 0;
	}
	if (m_bone_root && m_bone_index != prev_index) {
		bc->SetString(PMX_BONE_INDEX, String::IntToString(m_bone_index));
		// BONE_INDEX_CHANGE
		MMDBoneTagBoneIndexChangeMsg msg{};
		m_bone_root->Message(ID_T_MMD_BONE, &msg);
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

	HandleBoneLockUpdate(bc);
	HandleBoneIndexUpdate(tag, op, bc);
	HandleInheritParentBone(doc, op, bc);
	HandleBoneMorphUpdate(tag, op);

	return ExecuteImpl(op, doc, bt, priority, flags);
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

Bool MMDBoneTag::Write(SDK2024_Const GeListNode* node, HyperFile* hf) SDK2024_Const
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
	for (SDK2024_Const auto& button_id : button_id_map)
	{
		if (!const_cast<DescID&>(button_id.GetKey()).Write(hf))
			return false;
		if (!hf->WriteInt64(button_id.GetValue()))
			return false;
	}
	if (!hf->WriteInt64(bone_morph_data_arr.GetCount()))
		return false;
	for (SDK2024_Const auto& bone_morph : bone_morph_data_arr)
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

Int MMDBoneTag::AddBoneMorph(String morph_name)
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
	DynamicDescription* const dynamic_description = m_bone_tag->GetDynamicDescriptionWritable();
	if (!dynamic_description)
		return-1;
	BaseContainer grp_bc = GetCustomDataTypeDefault(DTYPE_GROUP);
	grp_bc.SetString(DESC_NAME, morph_name);
	grp_bc.SetData(DESC_PARENTGROUP, DescIDGeData(ConstDescID(DescLevel(PMX_BONE_MORPH_GRP))));
	auto grp_id = dynamic_description->Alloc(grp_bc);
	BaseContainer strength_bc = GetCustomDataTypeDefault(DTYPE_REAL);
	strength_bc.SetString(DESC_NAME, morph_name);
	strength_bc.SetFloat(DESC_MAX, 1.);
	strength_bc.SetFloat(DESC_MIN, 0.);
	strength_bc.SetInt32(DESC_CUSTOMGUI, CUSTOMGUI_REALSLIDER);
	strength_bc.SetFloat(DESC_MAXSLIDER, 1.);
	strength_bc.SetFloat(DESC_MINSLIDER, 0.);
	strength_bc.SetFloat(DESC_STEP, 0.01);
	strength_bc.SetInt32(DESC_UNIT, DESC_UNIT_PERCENT);
	strength_bc.SetData(DESC_PARENTGROUP, DescIDGeData(grp_id));
	BaseContainer translation_bc = GetCustomDataTypeDefault(DTYPE_VECTOR);
	translation_bc.SetString(DESC_NAME, GeLoadString(IDS_MORPH_BONE_TRANSLATION));
	translation_bc.SetInt32(DESC_ANIMATE, DESC_ANIMATE_OFF);
	translation_bc.SetData(DESC_PARENTGROUP, DescIDGeData(grp_id));
	BaseContainer rotation_bc = GetCustomDataTypeDefault(DTYPE_VECTOR);
	rotation_bc.SetString(DESC_NAME, GeLoadString(IDS_MORPH_BONE_ROTATION));
	rotation_bc.SetInt32(DESC_ANIMATE, DESC_ANIMATE_OFF);
	rotation_bc.SetData(DESC_PARENTGROUP, DescIDGeData(grp_id));
	BaseContainer button_grp_bc = GetCustomDataTypeDefault(DTYPE_GROUP);
	button_grp_bc.SetInt32(DESC_COLUMNS, 2);
	button_grp_bc.SetData(DESC_PARENTGROUP, DescIDGeData(grp_id));
	auto button_grp_id = dynamic_description->Alloc(button_grp_bc);
	BaseContainer button_delete_bc = GetCustomDataTypeDefault(DTYPE_BUTTON);
	button_delete_bc.SetString(DESC_NAME, GeLoadString(IDS_MORPH_DELETE));
	button_delete_bc.SetInt32(DESC_CUSTOMGUI, CUSTOMGUI_BUTTON);
	button_delete_bc.SetData(DESC_PARENTGROUP, DescIDGeData(button_grp_id));
	BaseContainer button_rename_bc = GetCustomDataTypeDefault(DTYPE_BUTTON);
	button_rename_bc.SetString(DESC_NAME, GeLoadString(IDS_MORPH_RENAME));
	button_rename_bc.SetInt32(DESC_CUSTOMGUI, CUSTOMGUI_BUTTON);
	button_rename_bc.SetData(DESC_PARENTGROUP, DescIDGeData(button_grp_id));
	const auto& morph_data = bone_morph_data_arr.SDK2024_Append(
		morph_name,
		SDK2024_Move(grp_id),
		dynamic_description->Alloc(strength_bc),
		dynamic_description->Alloc(translation_bc),
		dynamic_description->Alloc(rotation_bc),
		SDK2024_Move(button_grp_id),
		dynamic_description->Alloc(button_delete_bc),
		dynamic_description->Alloc(button_rename_bc))iferr_return;
	const Int index = bone_morph_data_arr.GetIndex(morph_data);
	iferr(button_id_map.Insert(morph_data.button_delete_id, index))
		return -1;
	iferr(button_id_map.Insert(morph_data.button_rename_id, index))
		return -1;
	// BONE_MORPH_ADD
	MMDBoneTagBoneMorphAddMsg msg{ std::move(morph_name), reinterpret_cast<BaseTag*>(Get()), morph_data.strength_id };
	m_bone_root->Message(ID_T_MMD_BONE, &msg);
	if (GeIsMainThread())
	{
		SendCoreMessage(COREMSG_CINEMA, BaseContainer(COREMSG_CINEMA_FORCE_AM_UPDATE)); 
		EventAdd();
	}
	return index;
}

bool MMDBoneTag::CheckBoneMorphIndex(const Int index) const
{
	if (index < 0 || index >= GetBoneMorphCount())
	{
		return false;
	}
	return true;
}

Int32 MMDBoneTag::GetBoneIndex() const
{
	return m_bone_index;
}

Bool MMDBoneTag::SetBoneMorphTranslation(const Int index, const Vector& translation)
{
	if (!CheckBoneMorphIndex(index))
		return nullptr;
	return Get()->SetParameter(bone_morph_data_arr[index].translation_id, translation, DESCFLAGS_SET::NONE);
}

Bool MMDBoneTag::SetBoneMorphRotation(const Int index, const Vector& rotation)
{
	if (!CheckBoneMorphIndex(index))
		return nullptr;
	return Get()->SetParameter(bone_morph_data_arr[index].rotation_id, rotation, DESCFLAGS_SET::NONE);
}

Bool MMDBoneTag::SetBoneMorphTranslationNoCheck(Int index, const Vector& translation)
{
	return Get()->SetParameter(bone_morph_data_arr[index].translation_id, translation, DESCFLAGS_SET::NONE);
}

Bool MMDBoneTag::SetBoneMorphRotationNoCheck(Int index, const Vector& rotation)
{
	return Get()->SetParameter(bone_morph_data_arr[index].rotation_id, rotation, DESCFLAGS_SET::NONE);
}

Int MMDBoneTag::GetBoneMorphCount() const
{
	return bone_morph_data_arr.GetCount();
}

BoneMorphData* MMDBoneTag::GetBoneMorph(const Int index)
{
	if (!CheckBoneMorphIndex(index))
		return nullptr;
	return &bone_morph_data_arr[index];
}

BoneMorphData* MMDBoneTag::GetBoneMorphNoCheck(const Int index)
{
	return &bone_morph_data_arr[index];
}

MMDBoneTag::TrackDescIDArray MMDBoneTag::GetTrackDescIDs()
{
	return GetTrackDescIDsImpl();
}

MMDBoneTag::TrackObjectArray MMDBoneTag::GetTrackObjects(
	GeListNode* node)
{
	const auto TrackArray = TrackObjectArray
	{
		m_bone_object,		// POSITION_X
		m_bone_object,		// POSITION_Y
		m_bone_object,		// POSITION_Z
		m_bone_object,		// ROTATION_X
		m_bone_object,		// ROTATION_Y
		m_bone_object		// ROTATION_Z
	};
	return TrackArray;
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
		constexpr CurrentValuesArray current_values{};
		return current_values;
	}

	const Vector RelPos = m_bone_object->GetRelPos();
	const Vector RelRot = m_bone_object->GetRelRot();

	const CurrentValuesArray current_values
	{
		RelPos.x,	// POSITION_X
		RelPos.y,	// POSITION_Y
		RelPos.z,	// POSITION_Z
		RelRot.x,	// ROTATION_X
		RelRot.y,	// ROTATION_Y
		RelRot.z,	// ROTATION_Z
	};

	return current_values;
}

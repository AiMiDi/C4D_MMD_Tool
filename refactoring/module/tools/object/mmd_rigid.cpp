/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & CMT contributors.
Author:			Luc
Date:			2024/2/5
File:			mmd_rigid.cpp
Description:	C4D MMD rigid object

**************************************************************************/

#include "pch.h"
#include "mmd_rigid.h"
#include "mmd_bone_root.h"
#include "mmd_rigid_root.h"

constexpr Vector g_pmx_rigid_colors[16] =
{
		Vector(255, 212, 127) / 255,
		Vector(212, 255, 127) / 255,
		Vector(127, 255, 127) / 255,
		Vector(127, 212, 255) / 255,
		Vector(127, 212, 255) / 255,
		Vector(127, 127, 255) / 255,
		Vector(212, 127, 255) / 255,
		Vector(255, 84,  0) / 255,
		Vector(255, 255, 0) / 255,
		Vector(0,   255, 85) / 255,
		Vector(0,   255, 255) / 255,
		Vector(0,   85,  255) / 255,
		Vector(84,  0,   255) / 255,
		Vector(255, 0,   255) / 255,
		Vector(255, 0,   84) / 255,
		Vector(127, 127, 0) / 255
};

constexpr Vector g_pmx_rigid_wire_colors[3] =
{
	Vector(200, 255, 150) / 255,
	Vector(255, 200, 150) / 255,
	Vector(255, 255, 150) / 255,
};

MMDRigidObject::MMDRigidObject() : m_draw_color(MakeObjectColorProperties(g_pmx_rigid_colors[0], ID_BASEOBJECT_USECOLOR_ALWAYS, true))
{}

Bool MMDRigidObject::Init(GeListNode* node SDK2024_InitParaName)
{
	if (!node)
	{
		return false;
	}
	
	BaseContainer* bc = reinterpret_cast<BaseList2D*>(node)->GetDataInstance();
	if (!bc)
	{
		return false;
	}

	node->ChangeNBit(NBIT::NO_DD, NBITCONTROL::SET);

	bc->SetInt32(RIGID_RELATED_BONE_INDEX, -1);
	bc->SetFloat(RIGID_SHAPE_SIZE_X, 17.);
	bc->SetFloat(RIGID_SHAPE_SIZE_Y, 17.);
	bc->SetFloat(RIGID_SHAPE_SIZE_Z, 17.);
	bc->SetFloat(RIGID_MASS, 1.);
	bc->SetFloat(RIGID_FRICTION_FORCE, 0.5);
	bc->SetFloat(RIGID_MOVE_ATTENUATION, 0.5);
	bc->SetFloat(RIGID_ROTATION_DAMPING, 0.5);

#if API_VERSION >= 21000
	bc->SetInt32(ID_BASELIST_ICON_COLORIZE_MODE, ID_BASELIST_ICON_COLORIZE_MODE_CUSTOM);
#endif
	return true;
}

Bool MMDRigidObject::GetDDescription(SDK2024_Const GeListNode* node, Description* description, DESCFLAGS_DESC& flags) SDK2024_Const
{
	if (!(node && description))
	{
		return false;
	}

	if (!description->LoadDescription(node->GetType()))
	{
		return false;
	}

	BaseContainer* settings;
	if (const BaseContainer* data_container = reinterpret_cast<SDK2024_Const BaseList2D*>(node)->GetDataInstance(); data_container)
	{
		switch (m_rigid_shape_type)
		{
		case SPHERICAL:

			settings = description->GetParameterI(ConstDescID(DescLevel(RIGID_SHAPE_SIZE_X)), nullptr);
			if (settings != nullptr)
			{
				settings->SetString(DESC_SHORT_NAME, GeLoadString(IDS_RIGID_SHAPE_SIZE_R));
			}
				
			settings = description->GetParameterI(ConstDescID(DescLevel(RIGID_SHAPE_SIZE_Y)), nullptr);
			if (settings != nullptr)
			{
				settings->SetBool(DESC_HIDE, true);
			}
				
			settings = description->GetParameterI(ConstDescID(DescLevel(RIGID_SHAPE_SIZE_Z)), nullptr);
			if (settings != nullptr)
			{
				settings->SetBool(DESC_HIDE, true);
			}
			break;

		case BOX:

			settings = description->GetParameterI(ConstDescID(DescLevel(RIGID_SHAPE_SIZE_X)), nullptr);
			if (settings != nullptr)
			{
				settings->SetString(DESC_SHORT_NAME, GeLoadString(IDS_RIGID_SHAPE_SIZE_L));
			}
				
			settings = description->GetParameterI(ConstDescID(DescLevel(RIGID_SHAPE_SIZE_Y)), nullptr);
			if (settings != nullptr)
			{
				settings->SetString(DESC_SHORT_NAME, GeLoadString(IDS_RIGID_SHAPE_SIZE_H));
			}
				
			settings = description->GetParameterI(ConstDescID(DescLevel(RIGID_SHAPE_SIZE_Z)), nullptr);
			if (settings != nullptr)
			{
				settings->SetString(DESC_SHORT_NAME, GeLoadString(IDS_RIGID_SHAPE_SIZE_W));
			}
			break;

		case CAPLETS:
			settings = description->GetParameterI(ConstDescID(DescLevel(RIGID_SHAPE_SIZE_X)), nullptr);
			if (settings != nullptr)
			{
				settings->SetString(DESC_SHORT_NAME, GeLoadString(IDS_RIGID_SHAPE_SIZE_R));
			}
				
			settings = description->GetParameterI(ConstDescID(DescLevel(RIGID_SHAPE_SIZE_Y)), nullptr);
			if (settings != nullptr)
			{
				settings->SetString(DESC_SHORT_NAME, GeLoadString(IDS_RIGID_SHAPE_SIZE_H));
			}
				
			settings = description->GetParameterI(ConstDescID(DescLevel(RIGID_SHAPE_SIZE_Z)), nullptr);
			if (settings != nullptr)
			{
				settings->SetBool(DESC_HIDE, true);
			}
			break;

		default:
			break;
		}
	}

	settings = description->GetParameterI(ConstDescID(DescLevel(RIGID_RELATED_BONE_INDEX)), nullptr);
	if (settings != nullptr)
	{
		settings->SetContainer(DESC_CYCLE, m_rigid_root->GetNodeData<MMDRigidRootObject>()->GetBoneRoot()->GetNodeData<MMDBoneRootObject>()->GetBoneItems());
	}

	flags |= DESCFLAGS_DESC::LOADED;
	return SUPER::GetDDescription(node, description, flags);
}

void ResetAutoFreeObject(AutoFree<BaseObject>& object, BaseObject* new_object)
{
	object.Free();
	object.Assign(new_object);
}

void SetBoxSize(const BaseContainer* bc, BaseObject* object)
{
	object->SetParameter(ConstDescID(DescLevel(PRIM_CUBE_LEN)), Vector(bc->GetFloat(RIGID_SHAPE_SIZE_X) * 2, bc->GetFloat(RIGID_SHAPE_SIZE_Z) * 2, bc->GetFloat(RIGID_SHAPE_SIZE_Y) * 2), DESCFLAGS_SET::NONE);
}

void SetSphericalSize(const BaseContainer* bc, BaseObject* object)
{
	object->SetParameter(ConstDescID(DescLevel(PRIM_SPHERE_RAD)), bc->GetData(RIGID_SHAPE_SIZE_X), DESCFLAGS_SET::NONE);
}

void SetCaplsuleSize(const BaseContainer* bc, BaseObject* object)
{
	object->SetParameter(ConstDescID(DescLevel(PRIM_CAPSULE_RADIUS)), bc->GetData(RIGID_SHAPE_SIZE_X), DESCFLAGS_SET::NONE);
	object->SetParameter(ConstDescID(DescLevel(PRIM_CAPSULE_HEIGHT)), bc->GetFloat(RIGID_SHAPE_SIZE_Y) + bc->GetFloat(RIGID_SHAPE_SIZE_X) * 2, DESCFLAGS_SET::NONE);
}

void MMDRigidObject::ResetRigidType(const Int32 type, const std::function<void(BaseObject*)>& func)
{
	ModelingCommandData cd;
	cd.doc = GetActiveDocument();
	const AutoFree draw_parameter_object(BaseObject::Alloc(type));
	func(draw_parameter_object);
	cd.op = draw_parameter_object;
	SendModelingCommand(MCOMMAND_CURRENTSTATETOOBJECT, cd);
	ResetAutoFreeObject(m_draw_mesh_object, reinterpret_cast<BaseObject*>(cd.result->GetIndex(0)));
	m_draw_mesh_object->SetPhong(true, true, 0.7853982);
}

void MMDRigidObject::SetBoxRigid(const BaseContainer* bc)
{
	ResetRigidType(Ocube, [this, bc](auto&& PH1) { ::SetBoxSize(bc, std::forward<decltype(PH1)>(PH1)); });
}

void MMDRigidObject::SetSphericalRigid(const BaseContainer* bc)
{
	ResetRigidType(Osphere, [this, bc](auto&& PH1) { ::SetSphericalSize(bc, std::forward<decltype(PH1)>(PH1)); });
}

void MMDRigidObject::SetCaplsuleRigid(const BaseContainer* bc)
{
	ResetRigidType(Ocapsule, [this, bc](auto&& PH1) { ::SetCaplsuleSize(bc, std::forward<decltype(PH1)>(PH1)); });
}

void MMDRigidObject::SetRigidSize(const Int32 type, const std::function<void(BaseObject*)>& func)
{
	ModelingCommandData cd;
	cd.doc = GetActiveDocument();
	const AutoFree draw_parameter_object(BaseObject::Alloc(type));
	func(draw_parameter_object);
	cd.op = draw_parameter_object;
	SendModelingCommand(MCOMMAND_CURRENTSTATETOOBJECT, cd);
	ResetAutoFreeObject(m_draw_mesh_object, reinterpret_cast<BaseObject*>(cd.result->GetIndex(0)));
	m_draw_mesh_object->SetPhong(true, true, 0.7853982);
}

void MMDRigidObject::SetBoxSize(const BaseContainer* bc)
{
	SetRigidSize(Ocube, [this, bc](auto&& PH1) { ::SetBoxSize(bc, std::forward<decltype(PH1)>(PH1)); });
}

void MMDRigidObject::SetSphericalSize(const BaseContainer* bc)
{
	SetRigidSize(Osphere, [this, bc](auto&& PH1) { ::SetSphericalSize(bc, std::forward<decltype(PH1)>(PH1)); });
}

void MMDRigidObject::SetCaplsuleSize(const BaseContainer* bc)
{
	SetRigidSize(Ocapsule, [this, bc](auto&& PH1) { ::SetCaplsuleSize(bc, std::forward<decltype(PH1)>(PH1)); });
}

Bool MMDRigidObject::SetDParameter(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_SET& flags)
{
	const BaseContainer* bc = reinterpret_cast<BaseList2D*>(node)->GetDataInstance();
	if(!bc)
		return false;
	switch (id[0].id)
	{
	case RIGID_SHAPE_TYPE:
	{
		UpdateRigidShape(bc, t_data.GetInt32());
		break;
	}
	case RIGID_SHAPE_SIZE_X:
	case RIGID_SHAPE_SIZE_Y:
	case RIGID_SHAPE_SIZE_Z:
	{
		UpdateRigidSize(bc);
		break;
	}
	case RIGID_RELATED_BONE_INDEX:
	{
		related_bone = m_rigid_root->GetNodeData<MMDRigidRootObject>()->GetBoneRoot()->GetNodeData<MMDBoneRootObject>()->
		                                                   FindBone(t_data.GetInt32())->GetObject();
		break;
	}
	case RIGID_PHYSICS_MODE:
	{
		m_physics_mode = t_data.GetInt32();
		break;
	}
	case RIGID_GROUP_ID:
	{
		UpdateRigidGroup(t_data.GetInt32());
		break;
	}
	default:
		break;
	}
	return SUPER::SetDParameter(node, id, t_data, flags);
}

Bool MMDRigidObject::GetDEnabling(SDK2024_Const GeListNode* node, const DescID& id, const GeData& t_data,
                                  const DESCFLAGS_ENABLE flags, const BaseContainer* itemdesc) SDK2024_Const
{
	switch (id[0].id)
	{
	case ID_BASEOBJECT_REL_POSITION:
	case ID_BASEOBJECT_REL_ROTATION:
	case ID_BASEOBJECT_FROZEN_POSITION:
	case ID_BASEOBJECT_FROZEN_ROTATION:
	case RIGID_RELATED_BONE_INDEX:
	case RIGID_PHYSICS_MODE:
	case RIGID_GROUP_ID:
	case RIGID_SHAPE_TYPE:
	case RIGID_SHAPE_SIZE_X:
	case RIGID_SHAPE_SIZE_Y:
	case RIGID_SHAPE_SIZE_Z:
	case RIGID_SHAPE_POSITION_X:
	case RIGID_SHAPE_POSITION_Y:
	case RIGID_SHAPE_POSITION_Z:
	case RIGID_SHAPE_ROTATION_X:
	case RIGID_SHAPE_ROTATION_Y:
	case RIGID_SHAPE_ROTATION_Z:
	case RIGID_MASS:
	case RIGID_REPULSION:
	case RIGID_FRICTION_FORCE:
	case RIGID_MOVE_ATTENUATION:
	case RIGID_ROTATION_DAMPING:
	case RIGID_NON_COLLISION_GROUP_0:
	case RIGID_NON_COLLISION_GROUP_1:
	case RIGID_NON_COLLISION_GROUP_2:
	case RIGID_NON_COLLISION_GROUP_3:
	case RIGID_NON_COLLISION_GROUP_4:
	case RIGID_NON_COLLISION_GROUP_5:
	case RIGID_NON_COLLISION_GROUP_6:
	case RIGID_NON_COLLISION_GROUP_7:
	case RIGID_NON_COLLISION_GROUP_8:
	case RIGID_NON_COLLISION_GROUP_9:
	case RIGID_NON_COLLISION_GROUP_10:
	case RIGID_NON_COLLISION_GROUP_11:
	case RIGID_NON_COLLISION_GROUP_12:
	case RIGID_NON_COLLISION_GROUP_13:
	case RIGID_NON_COLLISION_GROUP_14:
	case RIGID_NON_COLLISION_GROUP_15:
	{
		if (m_rigid_mode == RIGID_MODE_ANIM)
		{
			return false;
		}
		return true;
	}
	case ID_BASEOBJECT_REL_SCALE:
	case ID_BASEOBJECT_FROZEN_SCALE:
		return false;
	default:
		break;
	}
	return SUPER::GetDEnabling(node, id, t_data, flags, itemdesc);
}

void MMDRigidObject::UpdateRigidShape(const BaseContainer* bc, const Int32 rigid_shape_type)
{
	m_rigid_shape_type = rigid_shape_type;
	switch (m_rigid_shape_type)
	{
	case SPHERICAL:
		{
			SetSphericalRigid(bc);
			break;
		}
	case BOX:
		{
			SetBoxRigid(bc);
			break;
		}
	case CAPLETS:
		{
			SetCaplsuleRigid(bc);
			break;
		}
	default:
		break;
	}
	if (m_display_type == RIGID_DISPLAY_TYPE_WIRE)
	{
		m_draw_color.color = g_pmx_rigid_wire_colors[m_rigid_group_id];
	}
}

void MMDRigidObject::UpdateRigidSize(const BaseContainer* bc)
{
	switch (m_rigid_shape_type)
	{
	case SPHERICAL:
		{
			SetSphericalSize(bc);
			break;
		}
	case BOX:
		{
			SetBoxSize(bc);
			break;
		}
	case CAPLETS:
		{
			SetCaplsuleSize(bc);
			break;
		}
	default:
		break;
	}
}

void MMDRigidObject::UpdateRigidGroup(const Int32 rigid_group)
{
	m_rigid_group_id = rigid_group;
	if (m_display_type != RIGID_DISPLAY_TYPE_WIRE)
	{
		m_draw_color.color = g_pmx_rigid_colors[m_rigid_group_id];
	}
}

Bool MMDRigidObject::Message(GeListNode* node, Int32 type, void* data)
{
	switch (type)
	{
#if API_VERSION >= 21000
	case MSG_GETCUSTOMICON:
	{
		const auto cid = static_cast<GetCustomIconData*>(data);
		if (!cid)
		{
			break;
		}

		CustomIconSettings settings;
		FillCustomIconSettingsFromBaseList2D(settings, reinterpret_cast<BaseObject*>(node)->GetDataInstanceRef(), node->GetType(), true);
		settings._colorMode = 1;
		settings._customColor = maxon::Color(g_pmx_rigid_colors[m_rigid_group_id]);

		CustomIconGetIdDelegate getIdCallback = [this]()->Int32
			{
				switch (m_rigid_shape_type)
				{
				case SPHERICAL:
					return Osphere;
				case BOX:
					return Ocube;
				case CAPLETS:
					return Ocapsule;
				default:
					break;
				}
				return Osphere;
			};
		GetCustomIcon(*cid, settings, false, &getIdCallback);
		break;
	}
#endif
	case MSG_DESCRIPTION_CHECKUPDATE:
	{
		const Int32	id = static_cast<DescriptionCheckUpdate*>(data)->descid->operator[](0).id;
		const BaseContainer* bc = reinterpret_cast<BaseList2D*>(node)->GetDataInstance();
		if(!bc)
			return false;
		switch (id)
		{
		case RIGID_SHAPE_TYPE:
		{
			UpdateRigidShape(bc, bc->GetInt32(RIGID_SHAPE_TYPE));
			break;
		}
		case RIGID_SHAPE_SIZE_X:
		case RIGID_SHAPE_SIZE_Y:
		case RIGID_SHAPE_SIZE_Z:
		{
			UpdateRigidSize(bc);
			break;
		}
		case RIGID_RELATED_BONE_INDEX:
		{
			related_bone = m_rigid_root->GetNodeData<MMDRigidRootObject>()->GetBoneRoot()->GetNodeData<MMDBoneRootObject>()->
			                             FindBone(bc->GetInt32(RIGID_RELATED_BONE_INDEX))->GetObject();
			break;
		}
		case RIGID_PHYSICS_MODE:
		{
			m_physics_mode = bc->GetInt32(RIGID_PHYSICS_MODE);
			break;
		}
		case RIGID_GROUP_ID:
		{
			UpdateRigidGroup(bc->GetInt32(RIGID_GROUP_ID));
			break;
		}
		default:
			break;
		}
		break;
	}
	case  ID_O_MMD_RIGID_ROOT:
	{
		if (const auto* msg = static_cast<MMDRigidRootObjectMsg*>(data); msg)
		{
			switch (msg->type)
			{
			case MMDRigidRootObjectMsgType::RIGID_DISPLAY_CHANGE:
			{
				m_display_type = msg->display_type;
				break;
			}
			case MMDRigidRootObjectMsgType::RIGID_MODE_CHANGE:
			{
				const auto op = reinterpret_cast<BaseObject*>(node);
				if (m_rigid_mode == RIGID_MODE_EDIT && msg->rigid_mode == RIGID_MODE_ANIM)
				{
					m_original_position = op->GetAbsPos();
					m_original_rotation = op->GetAbsRot();
					if (related_bone != nullptr)
					{
						m_relative_bone_position = op->GetAbsPos() - related_bone->GetAbsPos();
						m_relative_bone_rotation = op->GetAbsRot() - related_bone->GetAbsRot();
					}
				}
				else if (m_rigid_mode == RIGID_MODE_ANIM && msg->rigid_mode == RIGID_MODE_EDIT)
				{
					op->SetAbsPos(m_original_position);
					op->SetAbsRot(m_original_rotation);
				}

				m_rigid_mode = msg->rigid_mode;
				if (m_protection_tag)
				{
					if (m_rigid_mode == RIGID_MODE_ANIM)
					{
						m_protection_tag->SetParameter(ConstDescID(DescLevel(PROTECTION_P_X)), true, DESCFLAGS_SET::NONE);
						m_protection_tag->SetParameter(ConstDescID(DescLevel(PROTECTION_P_Y)), true, DESCFLAGS_SET::NONE);
						m_protection_tag->SetParameter(ConstDescID(DescLevel(PROTECTION_P_Z)), true, DESCFLAGS_SET::NONE);
						m_protection_tag->SetParameter(ConstDescID(DescLevel(PROTECTION_R_X)), true, DESCFLAGS_SET::NONE);
						m_protection_tag->SetParameter(ConstDescID(DescLevel(PROTECTION_R_Y)), true, DESCFLAGS_SET::NONE);
						m_protection_tag->SetParameter(ConstDescID(DescLevel(PROTECTION_R_Z)), true, DESCFLAGS_SET::NONE);
					}
					else
					{
						m_protection_tag->SetParameter(ConstDescID(DescLevel(PROTECTION_P_X)), false, DESCFLAGS_SET::NONE);
						m_protection_tag->SetParameter(ConstDescID(DescLevel(PROTECTION_P_Y)), false, DESCFLAGS_SET::NONE);
						m_protection_tag->SetParameter(ConstDescID(DescLevel(PROTECTION_P_Z)), false, DESCFLAGS_SET::NONE);
						m_protection_tag->SetParameter(ConstDescID(DescLevel(PROTECTION_R_X)), false, DESCFLAGS_SET::NONE);
						m_protection_tag->SetParameter(ConstDescID(DescLevel(PROTECTION_R_Y)), false, DESCFLAGS_SET::NONE);
						m_protection_tag->SetParameter(ConstDescID(DescLevel(PROTECTION_R_Z)), false, DESCFLAGS_SET::NONE);
					}
				}
				break;
			}
			case MMDRigidRootObjectMsgType::DEFAULT: [[fallthrough]];
			default:
				break;
			}
		}
		break;
	}
	default:
		break;
	}
	return SUPER::Message(node, type, data);
}

DRAWRESULT MMDRigidObject::Draw(BaseObject* op, const DRAWPASS drawpass, BaseDraw* bd, BaseDrawHelp* bh)
{
	if (drawpass == DRAWPASS::OBJECT)
	{
		if (op == nullptr || bd == nullptr || bh == nullptr)
		{
			return DRAWRESULT::FAILURE;
		}
		const BaseContainer* bc = op->GetDataInstance();
		bd->SetMatrix_Matrix(nullptr, op->GetMg());
		if (!bc)
		{
			return DRAWRESULT::FAILURE;
		}
		switch (m_display_type)
		{
		case RIGID_DISPLAY_TYPE_ON:
		{
			if (m_draw_mesh_object)
			{
					if (op == GetActiveDocument()->GetActiveObject())
					{
						m_draw_color.xray = false;
						m_draw_mesh_object->SetColorProperties(&m_draw_color);
						bd->DrawObject(bh, m_draw_mesh_object, DRAWOBJECT::USE_OBJECT_COLOR, drawpass);
					}
					else
					{
						m_draw_color.xray = true;
						m_draw_mesh_object->SetColorProperties(&m_draw_color);
						bd->DrawObject(bh, m_draw_mesh_object, DRAWOBJECT::USE_OBJECT_COLOR | DRAWOBJECT::XRAY_ON, drawpass);
					}
			}
			else
			{
				UpdateRigidShape(bc, bc->GetInt32(RIGID_SHAPE_TYPE));
			}
			break;
		}
		case RIGID_DISPLAY_TYPE_WIRE:
		{
			if (m_draw_mesh_object)
			{
				if (op == GetActiveDocument()->GetActiveObject())
				{
					ObjectColorProperties objColor = MakeObjectColorProperties(Vector(1, 0.21, 0.21), ID_BASEOBJECT_USECOLOR_ALWAYS, false);
					m_draw_mesh_object->SetColorProperties(&objColor);
					bd->DrawObject(bh, m_draw_mesh_object, DRAWOBJECT::USE_OBJECT_COLOR, drawpass);
				}
				else
				{
					m_draw_color.xray = false;
					m_draw_mesh_object->SetColorProperties(&m_draw_color);
					bd->DrawObject(bh, m_draw_mesh_object, DRAWOBJECT::USE_OBJECT_COLOR, drawpass);
				}
			}
			else
			{
				UpdateRigidShape(bc, bc->GetInt32(RIGID_SHAPE_TYPE));
			}
			break;
		}
		default:
			break;
		}
	}
	return SUPER::Draw(op, drawpass, bd, bh);
}

EXECUTIONRESULT MMDRigidObject::Execute(BaseObject* op, BaseDocument* doc, BaseThread* bt, Int32 priority,
	EXECUTIONFLAGS flags)
{
	if (op == nullptr || doc == nullptr)
	{
		return EXECUTIONRESULT::OK;
	}

	const BaseContainer* bc = static_cast<BaseList2D*>(op)->GetDataInstance();
	if (bc == nullptr)
	{
		return EXECUTIONRESULT::OK;
	}

	BaseObject* pred_object = op->GetPred();
	BaseObject* UpObject = op->GetUp();
	BaseObject* rigid_root_object = m_rigid_root;

	if (UpObject == nullptr && rigid_root_object != nullptr)
	{
		op->Remove();
		op->InsertUnderLast(rigid_root_object);
	}

	Int32 pred_index = bc->GetString(RIGID_INDEX).ToInt32(nullptr);
	if (UpObject != nullptr && UpObject->IsInstanceOf(ID_O_MMD_RIGID_ROOT))
	{
		if (pred_object == nullptr)
		{
			op->SetParameter(ConstDescID(DescLevel(RIGID_INDEX)), "0"_s, DESCFLAGS_SET::NONE);
		}
		else
		{
			while (pred_object != nullptr && !pred_object->IsInstanceOf(ID_O_MMD_RIGID))
			{
				pred_object = pred_object->GetPred();
			}
			GeData data;
			pred_object->GetParameter(ConstDescID(DescLevel(RIGID_INDEX)), data, DESCFLAGS_GET::NONE);
			const String RigidIndex = data.GetString();
			op->SetParameter(ConstDescID(DescLevel(RIGID_INDEX)), String::IntToString(RigidIndex.ToInt32(nullptr) + 1), DESCFLAGS_SET::NONE);
		}

		if (rigid_root_object == nullptr)
		{
			m_rigid_root = UpObject;
		}
	}

	if (Int32 now_index = bc->GetString(RIGID_INDEX).ToInt32(nullptr); now_index != pred_index && m_rigid_root != nullptr)
	{
		m_rigid_root->Message(ID_O_MMD_RIGID, NewObj(MMDRigidObjectMsg, pred_index, now_index, op).GetValue());
	}
		
	if (m_protection_tag == nullptr)
	{
		m_protection_tag = op->MakeTag(Tprotection);
		m_protection_tag->ChangeNBit(NBIT::OHIDE, NBITCONTROL::SET);
		m_protection_tag->ChangeNBit(NBIT::AHIDE_FOR_HOST, NBITCONTROL::SET);
		m_protection_tag->SetParameter(ConstDescID(DescLevel(PROTECTION_ALLOW_EXPRESSIONS)), true, DESCFLAGS_SET::NONE);
	}

	if (m_rigid_mode == RIGID_MODE_ANIM)
	{
		switch (m_physics_mode)
		{
		case TRACK_BONES:
		{
			if (related_bone != nullptr)
			{
				op->SetAbsPos(related_bone->GetAbsPos() + m_relative_bone_position);
				op->SetAbsRot(related_bone->GetAbsRot() + m_relative_bone_rotation);
			}
			break;
		}
		case PHYSICAL_CALCULUS:
		{
			if (related_bone != nullptr)
			{
				related_bone->SetAbsPos(op->GetAbsPos() - m_relative_bone_position);
				related_bone->SetAbsRot(op->GetAbsRot() - m_relative_bone_rotation);
			}
			break;
		}
		case PHYSICS_AND_BONES:
		{
			break;
		}
		default:
			break;
		}
	}
	return EXECUTIONRESULT::OK;
}

Bool MMDRigidObject::AddToExecution(BaseObject* op, PriorityList* list)
{
	if (list == nullptr || op == nullptr)
	{
		return true;
	}
	list->Add(op, EXECUTIONPRIORITY_EXPRESSION, EXECUTIONFLAGS::NONE);
	return true;
}

Bool MMDRigidObject::Read(GeListNode* node, HyperFile* hf, Int32 level)
{
	const BaseContainer* bc = reinterpret_cast<BaseList2D*>(node)->GetDataInstance();
	if (!bc)
	{
		return false;
	}

	hf->ReadInt32(&m_display_type);
	hf->ReadInt32(&m_rigid_mode);
	hf->ReadInt32(&m_physics_mode);

	hf->ReadInt32(&m_rigid_shape_type);
	UpdateRigidShape(bc, m_rigid_shape_type);

	hf->ReadInt32(&m_rigid_group_id);
	UpdateRigidGroup(m_rigid_group_id);

	hf->ReadVector(&m_original_position);
	hf->ReadVector(&m_original_rotation);
	hf->ReadVector(&m_relative_bone_position);
	hf->ReadVector(&m_relative_bone_rotation);
	AutoAlloc<BaseLink> link;

	if (link == nullptr)
	{
		return false;
	}

	if (!link->Read(hf))
	{
		return false;
	}
	m_rigid_root = reinterpret_cast<BaseObject*>(link->GetLink(GetActiveDocument()));

	if (!link->Read(hf))
	{
		return false;
	}
	related_bone = reinterpret_cast<BaseObject*>(link->GetLink(GetActiveDocument()));

	if (!link->Read(hf))
	{
		return false;
	}
	m_protection_tag = reinterpret_cast<BaseTag*>(link->GetLink(GetActiveDocument()));

	return true;
}

Bool MMDRigidObject::Write(SDK2024_Const GeListNode* node, HyperFile* hf) SDK2024_Const
{
	hf->WriteInt32(m_display_type);
	hf->WriteInt32(m_rigid_mode);
	hf->WriteInt32(m_physics_mode);
	hf->WriteInt32(m_rigid_shape_type);
	hf->WriteInt32(m_rigid_group_id);
	hf->WriteVector(m_original_position);
	hf->WriteVector(m_original_rotation);
	hf->WriteVector(m_relative_bone_position);
	hf->WriteVector(m_relative_bone_rotation);

	AutoAlloc<BaseLink> link;
	if (link == nullptr)
	{
		return false;
	}

	link->SetLink(m_rigid_root);
	if (!link->Write(hf))
	{
		return false;
	}

	link->SetLink(related_bone);
	if (!link->Write(hf))
	{
		return false;
	}

	link->SetLink(m_protection_tag);
	if (!link->Write(hf))
	{
		return false;
	}

	return true;
}

Bool MMDRigidObject::CopyTo(NodeData* dest, SDK2024_Const GeListNode* snode, GeListNode* dnode, COPYFLAGS flags,
	AliasTrans* trn) SDK2024_Const
{
	auto* const destObject = reinterpret_cast<MMDRigidObject*>(dest);
	if (destObject == nullptr)
	{
		return false;
	}

	destObject->m_rigid_mode = m_rigid_mode;
	destObject->m_display_type = m_display_type;
	destObject->m_physics_mode = m_physics_mode;
	destObject->m_rigid_shape_type = m_rigid_shape_type;
	destObject->m_rigid_group_id = m_rigid_group_id;
	destObject->m_rigid_root = m_rigid_root;
	destObject->related_bone = related_bone;
	destObject->m_original_position = m_original_position;
	destObject->m_original_rotation = m_original_rotation;
	destObject->m_relative_bone_position = m_relative_bone_position;
	destObject->m_relative_bone_rotation = m_relative_bone_rotation;

	return true;
}

NodeData* MMDRigidObject::Alloc()
{
	return NewObjClear(MMDRigidObject);
}

BaseObject* MMDRigidObject::GetRootObject() const
{
	return m_rigid_root;
}

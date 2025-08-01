/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & CMT contributors.
Author:			Luc
Date:			2024/2/5
File:			mmd_rigid.cpp
Description:	C4D MMD rigid object

**************************************************************************/

#include "pch.h"
#include "mmd_rigid.h"
#include "mmd_bone_manager.h"
#include "mmd_rigid_manager.h"

SDK2024_ConstExpr Vector g_pmx_rigid_colors[16] =
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

SDK2024_ConstExpr Vector g_pmx_rigid_wire_colors[3] =
{
	Vector(200, 255, 150) / 255,
	Vector(255, 200, 150) / 255,
	Vector(255, 255, 150) / 255,
};

MMDRigidObject::MMDRigidObject() : draw_color_(MakeObjectColorProperties(g_pmx_rigid_colors[0], ID_BASEOBJECT_USECOLOR_ALWAYS, true))
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

	const DescID* const single_id = description->GetSingleDescID();
	if (const auto cid = ConstDescID(DescLevel(RIGID_RELATED_BONE_INDEX)); single_id == nullptr || cid.IsPartOf(*single_id, nullptr))
    {
		settings = description->GetParameterI(cid, nullptr);
		if (settings != nullptr && rigid_manager_)
		{
			settings->SetContainer(DESC_CYCLE, rigid_manager_data_->GetBoneItems());
		}
    }

	flags |= DESCFLAGS_DESC::LOADED;
	return SUPER::GetDDescription(node, description, flags);
}

struct BoxType
{
	constexpr static Int32 type =  Ocube;

	static void InitParameter(const BaseContainer* bc, BaseObject* object)
	{
		object->SetParameter(ConstDescID(DescLevel(PRIM_CUBE_LEN)), Vector(bc->GetFloat(RIGID_SHAPE_SIZE_X) * 2, bc->GetFloat(RIGID_SHAPE_SIZE_Z) * 2, bc->GetFloat(RIGID_SHAPE_SIZE_Y) * 2), DESCFLAGS_SET::NONE);
	}
};

struct SphericalType
{
	constexpr static Int32 type = Osphere;

	static void InitParameter(const BaseContainer* bc, BaseObject* object)
	{
		object->SetParameter(ConstDescID(DescLevel(PRIM_SPHERE_RAD)), bc->GetData(RIGID_SHAPE_SIZE_X), DESCFLAGS_SET::NONE);
	}
};

struct CaplsuleType
{
	constexpr static Int32 type =  Ocapsule;

	static void InitParameter(const BaseContainer* bc, BaseObject* object)
	{
		object->SetParameter(ConstDescID(DescLevel(PRIM_CAPSULE_RADIUS)), bc->GetData(RIGID_SHAPE_SIZE_X), DESCFLAGS_SET::NONE);
		object->SetParameter(ConstDescID(DescLevel(PRIM_CAPSULE_HEIGHT)), bc->GetFloat(RIGID_SHAPE_SIZE_Y) + bc->GetFloat(RIGID_SHAPE_SIZE_X) * 2, DESCFLAGS_SET::NONE);
	}
};

template <typename Type>
void MMDRigidObject::ResetRigidType(const BaseContainer* bc)
{
	ModelingCommandData cd;
	cd.doc = GetActiveDocument();
	const AutoFree draw_parameter_object(BaseObject::Alloc(Type::type));
	Type::InitParameter(bc, draw_parameter_object);
	cd.op = draw_parameter_object;
	SendModelingCommand(MCOMMAND_CURRENTSTATETOOBJECT, cd);
	draw_mesh_object_.Free();
	draw_mesh_object_.Assign(reinterpret_cast<BaseObject*>(cd.result->GetIndex(0)));
	draw_mesh_object_->SetPhong(true, true, 0.7853982);
}

template <typename Type>
void MMDRigidObject::SetRigidSize(const BaseContainer* bc)
{
	ModelingCommandData cd;
	cd.doc = GetActiveDocument();
	const AutoFree draw_parameter_object(BaseObject::Alloc(Type::type));
	Type::InitParameter(bc, draw_parameter_object);
	cd.op = draw_parameter_object;
	SendModelingCommand(MCOMMAND_CURRENTSTATETOOBJECT, cd);
	draw_mesh_object_.Free();
	draw_mesh_object_.Assign(reinterpret_cast<BaseObject*>(cd.result->GetIndex(0)));
	draw_mesh_object_->SetPhong(true, true, 0.7853982);
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
		break;
	}
	case RIGID_PHYSICS_MODE:
	{
		UpdateRigidPhysics(t_data.GetInt32());
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
	if (m_rigid_mode == RIGID_MODE_ANIM || id[0].id == ID_BASEOBJECT_REL_SCALE || id[0].id == ID_BASEOBJECT_FROZEN_SCALE)
		return false;

	return SUPER::GetDEnabling(node, id, t_data, flags, itemdesc);
}

void MMDRigidObject::UpdateRigidShape(const BaseContainer* bc, const Int32 rigid_shape_type)
{
	m_rigid_shape_type = rigid_shape_type;
	switch (m_rigid_shape_type)
	{
	case SPHERICAL:
		ResetRigidType<SphericalType>(bc);
		break;
	case BOX:
		ResetRigidType<BoxType>(bc);
		break;
	case CAPLETS:
		ResetRigidType<CaplsuleType>(bc);
		break;
	default:
		break;
	}
}

void MMDRigidObject::UpdateRigidSize(const BaseContainer* bc)
{
	switch (m_rigid_shape_type)
	{
	case SPHERICAL:
		SetRigidSize<SphericalType>(bc);
		break;
	case BOX:
		SetRigidSize<BoxType>(bc);
		break;
	case CAPLETS:
		SetRigidSize<CaplsuleType>(bc);
		break;
	default:
		break;
	}
}

void MMDRigidObject::UpdateRigidPhysics(Int32 physics_mode)
{
	m_physics_mode = physics_mode;
	if (m_display_type == RIGID_DISPLAY_TYPE_WIRE)
	{
		draw_color_.color = g_pmx_rigid_wire_colors[m_physics_mode];
	}
}

void MMDRigidObject::UpdateRigidGroup(const Int32 rigid_group)
{
	m_rigid_group_id = rigid_group;
	if (m_display_type != RIGID_DISPLAY_TYPE_WIRE)
	{
		draw_color_.color = g_pmx_rigid_colors[m_rigid_group_id];
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

		CustomIconGetIdDelegate get_id_callback = [this]()->Int32
			{
				static Int32 rigid_shape_type_to_object_type[3] = {Osphere, Ocube, Ocapsule};
				return rigid_shape_type_to_object_type[m_rigid_shape_type];
			};
		GetCustomIcon(*cid, settings, false, &get_id_callback);
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
				UpdateRigidShape(bc, bc->GetInt32(RIGID_SHAPE_TYPE));
				break;
			case RIGID_SHAPE_SIZE_X: [[fallthrough]];
			case RIGID_SHAPE_SIZE_Y: [[fallthrough]];
			case RIGID_SHAPE_SIZE_Z:
				UpdateRigidSize(bc);
				break;
			case RIGID_PHYSICS_MODE:
				UpdateRigidPhysics(bc->GetInt32(RIGID_PHYSICS_MODE));
				break;
			case RIGID_GROUP_ID:
				UpdateRigidGroup(bc->GetInt32(RIGID_GROUP_ID));
				break;
			default:
				break;
		}
		break;
	}
	case  ID_O_MMD_RIGID_MANAGER:
	{
		if (const auto* msg = static_cast<MMDRigidRootObjectMsg*>(data); msg)
		{
			switch (msg->type)
			{
			case MMDRigidRootObjectMsgType::RIGID_DISPLAY_CHANGE:
				m_display_type = msg->display_type;
				break;
			case MMDRigidRootObjectMsgType::RIGID_MODE_CHANGE:
				HandleRigidModeChange(msg->rigid_mode);
				break;
			case MMDRigidRootObjectMsgType::DEFAULT:
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
			if (draw_mesh_object_)
			{
					if (op == GetActiveDocument()->GetActiveObject())
					{
						draw_color_.xray = false;
						draw_mesh_object_->SetColorProperties(&draw_color_);
						bd->DrawObject(bh, draw_mesh_object_, DRAWOBJECT::USE_OBJECT_COLOR, drawpass);
					}
					else
					{
						draw_color_.xray = true;
						draw_mesh_object_->SetColorProperties(&draw_color_);
						bd->DrawObject(bh, draw_mesh_object_, DRAWOBJECT::USE_OBJECT_COLOR | DRAWOBJECT::XRAY_ON, drawpass);
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
			if (draw_mesh_object_)
			{
				if (op == GetActiveDocument()->GetActiveObject())
				{
					ObjectColorProperties objColor = MakeObjectColorProperties(Vector(1, 0.21, 0.21), ID_BASEOBJECT_USECOLOR_ALWAYS, false);
					draw_mesh_object_->SetColorProperties(&objColor);
					bd->DrawObject(bh, draw_mesh_object_, DRAWOBJECT::USE_OBJECT_COLOR, drawpass);
				}
				else
				{
					draw_color_.xray = false;
					draw_mesh_object_->SetColorProperties(&draw_color_);
					bd->DrawObject(bh, draw_mesh_object_, DRAWOBJECT::USE_OBJECT_COLOR, drawpass);
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

	const BaseContainer* bc = op->GetDataInstance();
	if (bc == nullptr)
	{
		return EXECUTIONRESULT::OK;
	}

	BaseObject* prev_object = op->GetPred();
	BaseObject* up_object = op->GetUp();
	BaseObject* rigid_manager = rigid_manager_;

	if (up_object == nullptr && rigid_manager != nullptr)
	{
		op->Remove();
		op->InsertUnderLast(rigid_manager);
	}

	const Int32 prev_object_index = bc->GetString(RIGID_INDEX).ToInt32(nullptr);
	if (up_object != nullptr && up_object->IsInstanceOf(ID_O_MMD_RIGID_MANAGER))
	{
		if (prev_object == nullptr)
		{
			op->SetParameter(ConstDescID(DescLevel(RIGID_INDEX)), "0"_s, DESCFLAGS_SET::NONE);
		}
		else
		{
			while (prev_object != nullptr && !prev_object->IsInstanceOf(ID_O_MMD_RIGID))
			{
				prev_object = prev_object->GetPred();
			}
			GeData data;
			prev_object->GetParameter(ConstDescID(DescLevel(RIGID_INDEX)), data, DESCFLAGS_GET::NONE);
			const String RigidIndex = data.GetString();
			op->SetParameter(ConstDescID(DescLevel(RIGID_INDEX)), String::IntToString(RigidIndex.ToInt32(nullptr) + 1), DESCFLAGS_SET::NONE);
		}

		if (rigid_manager == nullptr)
		{
			rigid_manager_ = up_object;
			rigid_manager_data_ = rigid_manager_->GetNodeData<MMDRigidManagerObject>();
		}
	}

	if (const Int32 now_index = bc->GetString(RIGID_INDEX).ToInt32(nullptr); now_index != prev_object_index && rigid_manager_ != nullptr)
	{
		rigid_manager_->Message(ID_O_MMD_RIGID, nullptr);
	}

	if (!m_protection_tag)
	{
		m_protection_tag = op->MakeTag(Tprotection);
		m_protection_tag->ChangeNBit(NBIT::OHIDE, NBITCONTROL::SET);
		m_protection_tag->ChangeNBit(NBIT::AHIDE_FOR_HOST, NBITCONTROL::SET);
		m_protection_tag->SetParameter(ConstDescID(DescLevel(PROTECTION_ALLOW_EXPRESSIONS)), true, DESCFLAGS_SET::NONE);
	}

	if (m_rigid_mode == RIGID_MODE_ANIM && m_display_type != RIGID_DISPLAY_TYPE_OFF && mmd_rigidbody_)
	{
		const auto transform = mmd_rigidbody_->GetTransform();
		op->SetMl(Matrix{
		   Vector(transform[3][0],transform[3][1],-transform[3][2]) * rigid_manager_data_->GetPositionMultiple(),
		   Vector(transform[0][0],transform[0][1],-transform[0][2]),
		   Vector(transform[1][0],transform[1][1],-transform[1][2]),
		   Vector(transform[2][0],transform[2][1],-transform[2][2]) });
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
	UpdateRigidPhysics(m_physics_mode);

	hf->ReadInt32(&m_rigid_shape_type);
	UpdateRigidShape(bc, m_rigid_shape_type);

	hf->ReadInt32(&m_rigid_group_id);
	UpdateRigidGroup(m_rigid_group_id);

	AutoAlloc<BaseLink> link;

	if (link == nullptr)
	{
		return false;
	}

	if (!link->Read(hf))
	{
		return false;
	}
	rigid_manager_ = reinterpret_cast<BaseObject*>(link->GetLink(GetActiveDocument()));
	rigid_manager_data_ = rigid_manager_->GetNodeData<MMDRigidManagerObject>();

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

	AutoAlloc<BaseLink> link;
	if (link == nullptr)
	{
		return false;
	}

	link->SetLink(rigid_manager_);
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
	destObject->rigid_manager_ = rigid_manager_;
	destObject->rigid_manager_data_ = rigid_manager_data_;

	return true;
}

NodeData* MMDRigidObject::Alloc()
{
	return NewObjClear(MMDRigidObject);
}

void MMDRigidObject::HandleRigidModeChange(Int32 mode)
{
	if (m_rigid_mode == mode)
		return;

	if (mode == RIGID_MODE_ANIM)
	{
		// TODO: Save to mmd_rigid_body

		if (m_protection_tag)
		{
			m_protection_tag->SetParameter(ConstDescID(DescLevel(PROTECTION_P_X)), true, DESCFLAGS_SET::NONE);
			m_protection_tag->SetParameter(ConstDescID(DescLevel(PROTECTION_P_Y)), true, DESCFLAGS_SET::NONE);
			m_protection_tag->SetParameter(ConstDescID(DescLevel(PROTECTION_P_Z)), true, DESCFLAGS_SET::NONE);
			m_protection_tag->SetParameter(ConstDescID(DescLevel(PROTECTION_R_X)), true, DESCFLAGS_SET::NONE);
			m_protection_tag->SetParameter(ConstDescID(DescLevel(PROTECTION_R_Y)), true, DESCFLAGS_SET::NONE);
			m_protection_tag->SetParameter(ConstDescID(DescLevel(PROTECTION_R_Z)), true, DESCFLAGS_SET::NONE);
		}
	}
	else
	{
		if (m_protection_tag)
		{
			m_protection_tag->SetParameter(ConstDescID(DescLevel(PROTECTION_P_X)), false, DESCFLAGS_SET::NONE);
			m_protection_tag->SetParameter(ConstDescID(DescLevel(PROTECTION_P_Y)), false, DESCFLAGS_SET::NONE);
			m_protection_tag->SetParameter(ConstDescID(DescLevel(PROTECTION_P_Z)), false, DESCFLAGS_SET::NONE);
			m_protection_tag->SetParameter(ConstDescID(DescLevel(PROTECTION_R_X)), false, DESCFLAGS_SET::NONE);
			m_protection_tag->SetParameter(ConstDescID(DescLevel(PROTECTION_R_Y)), false, DESCFLAGS_SET::NONE);
			m_protection_tag->SetParameter(ConstDescID(DescLevel(PROTECTION_R_Z)), false, DESCFLAGS_SET::NONE);
		}
	}

	m_rigid_mode = mode;
}

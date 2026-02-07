/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & CMT contributors.
Author:			Luc
Date:			2024/2/5
File:			mmd_rigid.cpp
Description:	C4D MMD rigid object

**************************************************************************/

#include <c4d.h>
#include <c4d_symbols.h>
#include "plugin_resource.h"
#include "module/core/cmt_marco.h"
#include "customgui_iconchooser.h"
#include "mmd_rigid.h"
#include "mmd_rigid_manager.h"
#include "libMMD/Model/MMD/MMDPhysics.h"

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

SDK2024_Init(MMDRigidObject)
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

SDK2024_GetDDescription(MMDRigidObject)
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
		if (settings && rigid_manager_data_)
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

SDK2024_GetDEnabling(MMDRigidObject)
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
	case  g_mmd_rigid_manager_object_id:
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

void MMDRigidObject::HandleRigidIndexUpdate(BaseObject* op) const
{
	if (const BaseObject* up_object = op->GetUp(); !up_object || !up_object->IsInstanceOf(g_mmd_rigid_manager_object_id))
		return;

	if (BaseObject* prev_object = op->GetPred(); !prev_object)
	{
		op->SetParameter(ConstDescID(DescLevel(RIGID_INDEX)), "0"_s, DESCFLAGS_SET::NONE);
	}
	else
	{
		while (prev_object != nullptr && !prev_object->IsInstanceOf(g_mmd_rigid_object_id))
			prev_object = prev_object->GetPred();

		GeData data;
		if (!prev_object->GetParameter(ConstDescID(DescLevel(RIGID_INDEX)), data, DESCFLAGS_GET::NONE))
			return;

		const auto rigid_index = data.GetString().ToInt32(nullptr) + 1;
		if (!op->GetParameter(ConstDescID(DescLevel(RIGID_INDEX)), data, DESCFLAGS_GET::NONE))
			return;

		if (rigid_index == data.GetString().ToInt32(nullptr))
			return;

		if (!op->SetParameter(ConstDescID(DescLevel(RIGID_INDEX)), String::IntToString(rigid_index), DESCFLAGS_SET::NONE))
			return;

		if (!rigid_manager_data_)
			return;

		rigid_manager_data_->UpdateRigidList();
	}
}

EXECUTIONRESULT MMDRigidObject::Execute(BaseObject* op, BaseDocument* doc, BaseThread* bt, Int32 priority,
                                        EXECUTIONFLAGS flags)
{
	if (op == nullptr)
	{
		return EXECUTIONRESULT::OK;
	}

	if (m_rigid_mode == RIGID_MODE_EDIT)
	{
		HandleRigidIndexUpdate(op);
	}
	else if (m_display_type != RIGID_DISPLAY_TYPE_OFF && mmd_rigidbody_)
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
	list->Add(op, EXECUTIONPRIORITY_EXPRESSION, EXECUTIONFLAGS::EXPRESSION);
	return true;
}

Bool MMDRigidObject::Read(GeListNode* node, HyperFile* hf, Int32 level)
{
	const BaseContainer* bc = reinterpret_cast<BaseList2D*>(node)->GetDataInstance();
	if (!bc)
	{
		return false;
	}

	IOReadField(m_display_type);
	IOReadField(m_rigid_mode);
	IOReadField(m_physics_mode);
	IOReadField(m_rigid_shape_type);
	IOReadField(m_rigid_group_id);
	IOReadField(rigid_manager_data_);

	UpdateRigidPhysics(m_physics_mode);
	UpdateRigidShape(bc, m_rigid_shape_type);
	UpdateRigidGroup(m_rigid_group_id);
	return true;
}

SDK2024_Write(MMDRigidObject)
{
	IOWriteField(m_display_type);
	IOWriteField(m_rigid_mode);
	IOWriteField(m_physics_mode);
	IOWriteField(m_rigid_shape_type);
	IOWriteField(m_rigid_group_id);
	IOWriteField(rigid_manager_data_);

	return true;
}

SDK2024_CopyTo(MMDRigidObject)
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

	if (mode == RIGID_MODE_EDIT)
	{
		Get()->ChangeNBit(NBIT::NO_DD, NBITCONTROL::CLEAR);

	}
	else
	{
		// TODO: Save to mmd_rigid_body
		Get()->ChangeNBit(NBIT::NO_DD, NBITCONTROL::SET);

	}

	m_rigid_mode = mode;
}

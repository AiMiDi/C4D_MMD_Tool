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

constexpr Vector PMX_Rigid_Color[16] =
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
		Vector(84,  0,	  255) / 255,
		Vector(255, 0,	  255) / 255,
		Vector(255, 0,	  84) / 255,
		Vector(127, 127, 0) / 255
};
constexpr Vector PMX_Rigid_Wire_Color[3] =
{
	Vector(200, 255, 150) / 255,
	Vector(255, 200, 150) / 255,
	Vector(255, 255, 150) / 255,
};

Bool MMDRigidObject::Init(GeListNode* node, Bool isCloneInit)
{
	if (node == nullptr)
	{
		return false;
	}

	BaseContainer* bc = static_cast<BaseList2D*>(node)->GetDataInstance();

	if (bc == nullptr)
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

Bool MMDRigidObject::GetDDescription(SDK2024_Const GeListNode* node, Description* description, DESCFLAGS_DESC& flags) const
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
	SDK2024_Const BaseContainer* bc = static_cast<SDK2024_Const BaseList2D*>(node)->GetDataInstance();

	if (bc != nullptr)
	{
		switch (bc->GetInt32(RIGID_SHAPE_TYPE))
		{
		case SPHERICAL:
			settings = description->GetParameterI(ConstDescID(DescLevel(RIGID_SHAPE_SIZE_X)), nullptr);
			if (settings != nullptr)
				settings->SetString(DESC_SHORT_NAME, GeLoadString(IDS_RIGID_SHAPE_SIZE_R));
			settings = description->GetParameterI(ConstDescID(DescLevel(RIGID_SHAPE_SIZE_Y)), nullptr);
			if (settings != nullptr)
				settings->SetBool(DESC_HIDE, true);
			settings = description->GetParameterI(ConstDescID(DescLevel(RIGID_SHAPE_SIZE_Z)), nullptr);
			if (settings != nullptr)
				settings->SetBool(DESC_HIDE, true);
			break;
		case BOX:
			settings = description->GetParameterI(ConstDescID(DescLevel(RIGID_SHAPE_SIZE_X)), nullptr);
			if (settings != nullptr)
				settings->SetString(DESC_SHORT_NAME, GeLoadString(IDS_RIGID_SHAPE_SIZE_L));
			settings = description->GetParameterI(ConstDescID(DescLevel(RIGID_SHAPE_SIZE_Y)), nullptr);
			if (settings != nullptr)
				settings->SetString(DESC_SHORT_NAME, GeLoadString(IDS_RIGID_SHAPE_SIZE_H));
			settings = description->GetParameterI(ConstDescID(DescLevel(RIGID_SHAPE_SIZE_Z)), nullptr);
			if (settings != nullptr)
				settings->SetString(DESC_SHORT_NAME, GeLoadString(IDS_RIGID_SHAPE_SIZE_W));
			break;
		case CAPLETS:
			settings = description->GetParameterI(ConstDescID(DescLevel(RIGID_SHAPE_SIZE_X)), nullptr);
			if (settings != nullptr)
				settings->SetString(DESC_SHORT_NAME, GeLoadString(IDS_RIGID_SHAPE_SIZE_R));
			settings = description->GetParameterI(ConstDescID(DescLevel(RIGID_SHAPE_SIZE_Y)), nullptr);
			if (settings != nullptr)
				settings->SetString(DESC_SHORT_NAME, GeLoadString(IDS_RIGID_SHAPE_SIZE_H));
			settings = description->GetParameterI(ConstDescID(DescLevel(RIGID_SHAPE_SIZE_Z)), nullptr);
			if (settings != nullptr)
				settings->SetBool(DESC_HIDE, true);
			break;
		default:
			break;
		}
	}
	settings = description->GetParameterI(ConstDescID(DescLevel(RIGID_RELATED_BONE_INDEX)), nullptr);
	if (settings != nullptr) {
		settings->SetContainer(DESC_CYCLE, m_rigid_root->GetNodeData<MMDRigidRootObject>()->GetBoneRoot()->GetNodeData<MMDBoneRootObject>()->GetBoneItems());
	}
	flags |= DESCFLAGS_DESC::LOADED;
	return SUPER::GetDDescription(node, description, flags);
}

Bool MMDRigidObject::SetDParameter(GeListNode* node, const DescID& id, const GeData& t_data,
	DESCFLAGS_SET& flags)
{
	BaseContainer* bc = static_cast<BaseList2D*>(node)->GetDataInstance();
	switch (id[0].id)
	{
	case RIGID_SHAPE_TYPE:
	{
		if (bc != nullptr)
		{
			switch (t_data.GetInt32())
			{
			case SPHERICAL:
			{
				if (pdraw_obj != nullptr)
				{
					BaseObject::Free(draw_obj);
					BaseObject::Free(pdraw_obj);
					ModelingCommandData cd;
					cd.doc = GetActiveDocument();
					pdraw_obj = BaseObject::Alloc(Osphere);
					pdraw_obj->SetParameter(ConstDescID(DescLevel(PRIM_SPHERE_RAD)), bc->GetData(RIGID_SHAPE_SIZE_X), DESCFLAGS_SET::NONE);
					cd.op = pdraw_obj;
					SendModelingCommand(MCOMMAND_CURRENTSTATETOOBJECT, cd);
					draw_obj = (BaseObject*)cd.result->GetIndex(0);
					draw_obj->SetPhong(true, true, 0.7853982);
				}
				break;
			}
			case BOX:
			{
				if (pdraw_obj != nullptr)
				{
					BaseObject::Free(draw_obj);
					BaseObject::Free(pdraw_obj);
					ModelingCommandData cd;
					cd.doc = GetActiveDocument();
					pdraw_obj = BaseObject::Alloc(Ocube);
					pdraw_obj->SetParameter(ConstDescID(DescLevel(PRIM_CUBE_LEN)), Vector(bc->GetFloat(RIGID_SHAPE_SIZE_X) * 2, bc->GetFloat(RIGID_SHAPE_SIZE_Z) * 2, bc->GetFloat(RIGID_SHAPE_SIZE_Y) * 2), DESCFLAGS_SET::NONE);
					cd.op = pdraw_obj;
					SendModelingCommand(MCOMMAND_CURRENTSTATETOOBJECT, cd);
					draw_obj = (BaseObject*)cd.result->GetIndex(0);
					draw_obj->SetPhong(true, true, 0.7853982);
				}
				break;
			}
			case CAPLETS:
			{
				if (pdraw_obj != nullptr)
				{
					BaseObject::Free(draw_obj);
					BaseObject::Free(pdraw_obj);
					ModelingCommandData cd;
					cd.doc = GetActiveDocument();
					pdraw_obj = BaseObject::Alloc(Ocapsule);
					pdraw_obj->SetParameter(ConstDescID(DescLevel(PRIM_CAPSULE_RADIUS)), bc->GetData(RIGID_SHAPE_SIZE_X), DESCFLAGS_SET::NONE);
					pdraw_obj->SetParameter(ConstDescID(DescLevel(PRIM_CAPSULE_HEIGHT)), bc->GetFloat(RIGID_SHAPE_SIZE_Y) + bc->GetFloat(RIGID_SHAPE_SIZE_X) * 2, DESCFLAGS_SET::NONE);
					cd.op = pdraw_obj;
					SendModelingCommand(MCOMMAND_CURRENTSTATETOOBJECT, cd);
					draw_obj = (BaseObject*)cd.result->GetIndex(0);
					draw_obj->SetPhong(true, true, 0.7853982);
				}
				break;
			}
			default:
				break;
			}
		}
		break;
	}
	case RIGID_SHAPE_SIZE_X:
	{
		if (bc != nullptr)
		{
			switch (bc->GetInt32(RIGID_SHAPE_TYPE))
			{
			case SPHERICAL:
			{
				if (pdraw_obj != nullptr)
				{
					BaseObject::Free(draw_obj);
					ModelingCommandData cd;
					cd.doc = GetActiveDocument();
					pdraw_obj->SetParameter(ConstDescID(DescLevel(PRIM_SPHERE_RAD)), bc->GetData(RIGID_SHAPE_SIZE_X), DESCFLAGS_SET::NONE);
					cd.op = pdraw_obj;
					SendModelingCommand(MCOMMAND_CURRENTSTATETOOBJECT, cd);
					draw_obj = (BaseObject*)cd.result->GetIndex(0);
					draw_obj->SetPhong(true, true, 0.7853982);
				}
				break;
			}
			case BOX:
			{
				if (pdraw_obj != nullptr)
				{
					BaseObject::Free(draw_obj);
					ModelingCommandData cd;
					cd.doc = GetActiveDocument();
					pdraw_obj->SetParameter(ConstDescID(DescLevel(PRIM_CUBE_LEN)), Vector(bc->GetFloat(RIGID_SHAPE_SIZE_X) * 2, bc->GetFloat(RIGID_SHAPE_SIZE_Z) * 2, bc->GetFloat(RIGID_SHAPE_SIZE_Y) * 2), DESCFLAGS_SET::NONE);
					cd.op = pdraw_obj;
					SendModelingCommand(MCOMMAND_CURRENTSTATETOOBJECT, cd);
					draw_obj = (BaseObject*)cd.result->GetIndex(0);
					draw_obj->SetPhong(true, true, 0.7853982);
				}
				break;
			}
			case CAPLETS:
			{
				if (pdraw_obj != nullptr)
				{
					BaseObject::Free(draw_obj);
					ModelingCommandData cd;
					cd.doc = GetActiveDocument();
					pdraw_obj->SetParameter(ConstDescID(DescLevel(PRIM_CAPSULE_RADIUS)), bc->GetData(RIGID_SHAPE_SIZE_X), DESCFLAGS_SET::NONE);
					pdraw_obj->SetParameter(ConstDescID(DescLevel(PRIM_CAPSULE_HEIGHT)), bc->GetFloat(RIGID_SHAPE_SIZE_Y) + bc->GetFloat(RIGID_SHAPE_SIZE_X) * 2, DESCFLAGS_SET::NONE);
					cd.op = pdraw_obj;
					SendModelingCommand(MCOMMAND_CURRENTSTATETOOBJECT, cd);
					draw_obj = (BaseObject*)cd.result->GetIndex(0);
					draw_obj->SetPhong(true, true, 0.7853982);
				}
				break;
			}
			default:
				break;
			}
		}
		break;
	}
	case RIGID_SHAPE_SIZE_Y:
	{
		if (bc != nullptr)
		{
			switch (bc->GetInt32(RIGID_SHAPE_TYPE))
			{
			case SPHERICAL:
			{
				if (pdraw_obj != nullptr)
				{
					BaseObject::Free(draw_obj);
					ModelingCommandData cd;
					cd.doc = GetActiveDocument();
					pdraw_obj->SetParameter(ConstDescID(DescLevel(PRIM_SPHERE_RAD)), bc->GetData(RIGID_SHAPE_SIZE_X), DESCFLAGS_SET::NONE);
					cd.op = pdraw_obj;
					SendModelingCommand(MCOMMAND_CURRENTSTATETOOBJECT, cd);
					draw_obj = (BaseObject*)cd.result->GetIndex(0);
					draw_obj->SetPhong(true, true, 0.7853982);
				}
				break;
			}
			case BOX:
			{
				if (pdraw_obj != nullptr)
				{
					BaseObject::Free(draw_obj);
					ModelingCommandData cd;
					cd.doc = GetActiveDocument();
					pdraw_obj->SetParameter(ConstDescID(DescLevel(PRIM_CUBE_LEN)), Vector(bc->GetFloat(RIGID_SHAPE_SIZE_X) * 2, bc->GetFloat(RIGID_SHAPE_SIZE_Z) * 2, bc->GetFloat(RIGID_SHAPE_SIZE_Y) * 2), DESCFLAGS_SET::NONE);
					cd.op = pdraw_obj;
					SendModelingCommand(MCOMMAND_CURRENTSTATETOOBJECT, cd);
					draw_obj = (BaseObject*)cd.result->GetIndex(0);
					draw_obj->SetPhong(true, true, 0.7853982);
				}
				break;
			}
			case CAPLETS:
			{
				if (pdraw_obj != nullptr)
				{
					BaseObject::Free(draw_obj);
					ModelingCommandData cd;
					cd.doc = GetActiveDocument();
					pdraw_obj->SetParameter(ConstDescID(DescLevel(PRIM_CAPSULE_RADIUS)), bc->GetData(RIGID_SHAPE_SIZE_X), DESCFLAGS_SET::NONE);
					pdraw_obj->SetParameter(ConstDescID(DescLevel(PRIM_CAPSULE_HEIGHT)), bc->GetFloat(RIGID_SHAPE_SIZE_Y) + bc->GetFloat(RIGID_SHAPE_SIZE_X) * 2, DESCFLAGS_SET::NONE);
					cd.op = pdraw_obj;
					SendModelingCommand(MCOMMAND_CURRENTSTATETOOBJECT, cd);
					draw_obj = (BaseObject*)cd.result->GetIndex(0);
					draw_obj->SetPhong(true, true, 0.7853982);
				}
				break;
			}
			default:
				break;
			}
		}
		break;
	}
	case RIGID_SHAPE_SIZE_Z:
	{
		if (bc != nullptr)
		{
			switch (bc->GetInt32(RIGID_SHAPE_TYPE))
			{
			case SPHERICAL:
			{
				if (pdraw_obj != nullptr)
				{
					BaseObject::Free(draw_obj);
					ModelingCommandData cd;
					cd.doc = GetActiveDocument();
					pdraw_obj->SetParameter(ConstDescID(DescLevel(PRIM_SPHERE_RAD)), bc->GetData(RIGID_SHAPE_SIZE_X), DESCFLAGS_SET::NONE);
					cd.op = pdraw_obj;
					SendModelingCommand(MCOMMAND_CURRENTSTATETOOBJECT, cd);
					draw_obj = (BaseObject*)cd.result->GetIndex(0);
					draw_obj->SetPhong(true, true, 0.7853982);
				}
				break;
			}
			case BOX:
			{
				if (pdraw_obj != nullptr)
				{
					BaseObject::Free(draw_obj);
					ModelingCommandData cd;
					cd.doc = GetActiveDocument();
					pdraw_obj->SetParameter(ConstDescID(DescLevel(PRIM_CUBE_LEN)), Vector(bc->GetFloat(RIGID_SHAPE_SIZE_X) * 2, bc->GetFloat(RIGID_SHAPE_SIZE_Z) * 2, bc->GetFloat(RIGID_SHAPE_SIZE_Y) * 2), DESCFLAGS_SET::NONE);
					cd.op = pdraw_obj;
					SendModelingCommand(MCOMMAND_CURRENTSTATETOOBJECT, cd);
					draw_obj = (BaseObject*)cd.result->GetIndex(0);
					draw_obj->SetPhong(true, true, 0.7853982);
				}
				break;
			}
			case CAPLETS:
			{
				if (pdraw_obj != nullptr)
				{
					BaseObject::Free(draw_obj);
					ModelingCommandData cd;
					cd.doc = GetActiveDocument();
					pdraw_obj->SetParameter(ConstDescID(DescLevel(PRIM_CAPSULE_RADIUS)), bc->GetData(RIGID_SHAPE_SIZE_X), DESCFLAGS_SET::NONE);
					pdraw_obj->SetParameter(ConstDescID(DescLevel(PRIM_CAPSULE_HEIGHT)), bc->GetFloat(RIGID_SHAPE_SIZE_Y) + bc->GetFloat(RIGID_SHAPE_SIZE_X) * 2, DESCFLAGS_SET::NONE);
					cd.op = pdraw_obj;
					SendModelingCommand(MCOMMAND_CURRENTSTATETOOBJECT, cd);
					draw_obj = (BaseObject*)cd.result->GetIndex(0);
					draw_obj->SetPhong(true, true, 0.7853982);
				}
				break;
			}
			default:
				break;
			}
		}
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
		physics_mode = t_data.GetInt32();
		break;
	}
	default:
		break;
	}
	return SUPER::SetDParameter(node, id, t_data, flags);
}

Bool MMDRigidObject::GetDEnabling(const GeListNode* node, const DescID& id, const GeData& t_data,
	DESCFLAGS_ENABLE flags, const BaseContainer* itemdesc) const
{
	switch (id[0].id)
	{
	case ID_BASEOBJECT_REL_POSITION:
	{
		if (m_rigid_mode == RIGID_MODE_ANIM)
		{
			return false;
		}
		else {
			return true;
		}
	}
	case ID_BASEOBJECT_REL_ROTATION:
	{
		if (m_rigid_mode == RIGID_MODE_ANIM)
		{
			return false;
		}
		else {
			return true;
		}
	}
	case ID_BASEOBJECT_FROZEN_POSITION:
	{
		if (m_rigid_mode == RIGID_MODE_ANIM)
		{
			return false;
		}
		else {
			return true;
		}
	}
	case ID_BASEOBJECT_FROZEN_ROTATION:
	{
		if (m_rigid_mode == RIGID_MODE_ANIM)
		{
			return false;
		}
		else {
			return true;
		}
	}
	case RIGID_RELATED_BONE_INDEX:
	{
		if (m_rigid_mode == RIGID_MODE_ANIM)
		{
			return false;
		}
		else {
			return true;
		}
	}
	case RIGID_PHYSICS_MODE:
	{
		if (m_rigid_mode == RIGID_MODE_ANIM)
		{
			return false;
		}
		else {
			return true;
		}
	}
	case RIGID_GROUP_ID:
	{
		if (m_rigid_mode == RIGID_MODE_ANIM)
		{
			return false;
		}
		else {
			return true;
		}
	}
	case RIGID_SHAPE_TYPE:
	{
		if (m_rigid_mode == RIGID_MODE_ANIM)
		{
			return false;
		}
		else {
			return true;
		}
	}
	case RIGID_SHAPE_SIZE_X:
	{
		if (m_rigid_mode == RIGID_MODE_ANIM)
		{
			return false;
		}
		else {
			return true;
		}
	}
	case RIGID_SHAPE_SIZE_Y:
	{
		if (m_rigid_mode == RIGID_MODE_ANIM)
		{
			return false;
		}
		else {
			return true;
		}
	}
	case RIGID_SHAPE_SIZE_Z:
	{
		if (m_rigid_mode == RIGID_MODE_ANIM)
		{
			return false;
		}
		else {
			return true;
		}
	}
	case RIGID_SHAPE_POSITION_X:
	{
		if (m_rigid_mode == RIGID_MODE_ANIM)
		{
			return false;
		}
		else {
			return true;
		}
	}
	case RIGID_SHAPE_POSITION_Y:
	{
		if (m_rigid_mode == RIGID_MODE_ANIM)
		{
			return false;
		}
		else {
			return true;
		}
	}
	case RIGID_SHAPE_POSITION_Z:
	{
		if (m_rigid_mode == RIGID_MODE_ANIM)
		{
			return false;
		}
		else {
			return true;
		}
	}
	case RIGID_SHAPE_ROTATION_X:
	{
		if (m_rigid_mode == RIGID_MODE_ANIM)
		{
			return false;
		}
		else {
			return true;
		}
	}
	case RIGID_SHAPE_ROTATION_Y:
	{
		if (m_rigid_mode == RIGID_MODE_ANIM)
		{
			return false;
		}
		else {
			return true;
		}
	}
	case RIGID_SHAPE_ROTATION_Z:
	{
		if (m_rigid_mode == RIGID_MODE_ANIM)
		{
			return false;
		}
		else {
			return true;
		}
	}
	case RIGID_MASS:
	{
		if (m_rigid_mode == RIGID_MODE_ANIM)
		{
			return false;
		}
		else {
			return true;
		}
	}
	case RIGID_REPULSION:
	{
		if (m_rigid_mode == RIGID_MODE_ANIM)
		{
			return false;
		}
		else {
			return true;
		}
	}
	case RIGID_FRICTION_FORCE:
	{
		if (m_rigid_mode == RIGID_MODE_ANIM)
		{
			return false;
		}
		else {
			return true;
		}
	}
	case RIGID_MOVE_ATTENUATION:
	{
		if (m_rigid_mode == RIGID_MODE_ANIM)
		{
			return false;
		}
		else {
			return true;
		}
	}
	case RIGID_ROTATION_DAMPING:
	{
		if (m_rigid_mode == RIGID_MODE_ANIM)
		{
			return false;
		}
		else {
			return true;
		}
	}
	case RIGID_NON_COLLISION_GROUP_0:
	{
		if (m_rigid_mode == RIGID_MODE_ANIM)
		{
			return false;
		}
		else {
			return true;
		}
	}
	case RIGID_NON_COLLISION_GROUP_1:
	{
		if (m_rigid_mode == RIGID_MODE_ANIM)
		{
			return false;
		}
		else {
			return true;
		}
	}
	case RIGID_NON_COLLISION_GROUP_2:
	{
		if (m_rigid_mode == RIGID_MODE_ANIM)
		{
			return false;
		}
		else {
			return true;
		}
	}
	case RIGID_NON_COLLISION_GROUP_3:
	{
		if (m_rigid_mode == RIGID_MODE_ANIM)
		{
			return false;
		}
		else {
			return true;
		}
	}
	case RIGID_NON_COLLISION_GROUP_4:
	{
		if (m_rigid_mode == RIGID_MODE_ANIM)
		{
			return false;
		}
		else {
			return true;
		}
	}
	case RIGID_NON_COLLISION_GROUP_5:
	{
		if (m_rigid_mode == RIGID_MODE_ANIM)
		{
			return false;
		}
		else {
			return true;
		}
	}
	case RIGID_NON_COLLISION_GROUP_6:
	{
		if (m_rigid_mode == RIGID_MODE_ANIM)
		{
			return false;
		}
		else {
			return true;
		}
	}
	case RIGID_NON_COLLISION_GROUP_7:
	{
		if (m_rigid_mode == RIGID_MODE_ANIM)
		{
			return false;
		}
		else {
			return true;
		}
	}
	case RIGID_NON_COLLISION_GROUP_8:
	{
		if (m_rigid_mode == RIGID_MODE_ANIM)
		{
			return false;
		}
		else {
			return true;
		}
	}
	case RIGID_NON_COLLISION_GROUP_9:
	{
		if (m_rigid_mode == RIGID_MODE_ANIM)
		{
			return false;
		}
		else {
			return true;
		}
	}
	case RIGID_NON_COLLISION_GROUP_10:
	{
		if (m_rigid_mode == RIGID_MODE_ANIM)
		{
			return false;
		}
		else {
			return true;
		}
	}
	case RIGID_NON_COLLISION_GROUP_11:
	{
		if (m_rigid_mode == RIGID_MODE_ANIM)
		{
			return false;
		}
		else {
			return true;
		}
	}
	case RIGID_NON_COLLISION_GROUP_12:
	{
		if (m_rigid_mode == RIGID_MODE_ANIM)
		{
			return false;
		}
		else {
			return true;
		}
	}
	case RIGID_NON_COLLISION_GROUP_13:
	{
		if (m_rigid_mode == RIGID_MODE_ANIM)
		{
			return false;
		}
		else {
			return true;
		}
	}
	case RIGID_NON_COLLISION_GROUP_14:
	{
		if (m_rigid_mode == RIGID_MODE_ANIM)
		{
			return false;
		}
		else {
			return true;
		}
	}
	case RIGID_NON_COLLISION_GROUP_15:
	{
		if (m_rigid_mode == RIGID_MODE_ANIM)
		{
			return false;
		}
		else {
			return true;
		}
	}
	case ID_BASEOBJECT_REL_SCALE:
		return false;
	case ID_BASEOBJECT_FROZEN_SCALE:
		return false;
	default:
		break;
	}
	return SUPER::GetDEnabling(node, id, t_data, flags, itemdesc);
}

Bool MMDRigidObject::Message(GeListNode* node, Int32 type, void* data)
{
	switch (type)
	{
#if API_VERSION >= 21000
	case MSG_GETCUSTOMICON:
	{
		GetCustomIconData* const cid = static_cast<GetCustomIconData*>(data);
		if (cid == nullptr)
			break;
		CustomIconSettings	settings;
		BaseContainer* bc = static_cast<BaseList2D*>(node)->GetDataInstance();
		if (bc == nullptr)
		{
			break;
		}
		BaseContainer& bcr = static_cast<BaseObject*>(node)->GetDataInstanceRef();
		FillCustomIconSettingsFromBaseList2D(settings, bcr, node->GetType(), true);
		settings._colorMode = 1;
		settings._customColor = maxon::Color(PMX_Rigid_Color[bc->GetInt32(RIGID_GROUP_ID)]);
		CustomIconGetIdDelegate getIdCallback = [bc]()->Int32
			{
				switch (bc->GetInt32(RIGID_SHAPE_TYPE))
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
		BaseContainer* bc = static_cast<BaseList2D*>(node)->GetDataInstance();
		switch (id)
		{
		case RIGID_SHAPE_TYPE:
		{
			if (bc != nullptr)
			{
				switch (bc->GetInt32(RIGID_SHAPE_TYPE))
				{
				case SPHERICAL:
				{
					if (pdraw_obj != nullptr)
					{
						BaseObject::Free(draw_obj);
						BaseObject::Free(pdraw_obj);
						ModelingCommandData cd;
						cd.doc = GetActiveDocument();
						pdraw_obj = BaseObject::Alloc(Osphere);
						pdraw_obj->SetParameter(ConstDescID(DescLevel(PRIM_SPHERE_RAD)), bc->GetData(RIGID_SHAPE_SIZE_X), DESCFLAGS_SET::NONE);
						cd.op = pdraw_obj;
						SendModelingCommand(MCOMMAND_CURRENTSTATETOOBJECT, cd);
						draw_obj = (BaseObject*)cd.result->GetIndex(0);
						draw_obj->SetPhong(true, true, 0.7853982);
					}
					break;
				}
				case BOX:
				{
					if (pdraw_obj != nullptr)
					{
						BaseObject::Free(draw_obj);
						BaseObject::Free(pdraw_obj);
						ModelingCommandData cd;
						cd.doc = GetActiveDocument();
						pdraw_obj = BaseObject::Alloc(Ocube);
						pdraw_obj->SetParameter(ConstDescID(DescLevel(PRIM_CUBE_LEN)), Vector(bc->GetFloat(RIGID_SHAPE_SIZE_X) * 2, bc->GetFloat(RIGID_SHAPE_SIZE_Z) * 2, bc->GetFloat(RIGID_SHAPE_SIZE_Y) * 2), DESCFLAGS_SET::NONE);
						cd.op = pdraw_obj;
						SendModelingCommand(MCOMMAND_CURRENTSTATETOOBJECT, cd);
						draw_obj = (BaseObject*)cd.result->GetIndex(0);
						draw_obj->SetPhong(true, true, 0.7853982);
					}
					break;
				}
				case CAPLETS:
				{
					if (pdraw_obj != nullptr)
					{
						BaseObject::Free(draw_obj);
						BaseObject::Free(pdraw_obj);
						ModelingCommandData cd;
						cd.doc = GetActiveDocument();
						pdraw_obj = BaseObject::Alloc(Ocapsule);
						pdraw_obj->SetParameter(ConstDescID(DescLevel(PRIM_CAPSULE_RADIUS)), bc->GetData(RIGID_SHAPE_SIZE_X), DESCFLAGS_SET::NONE);
						pdraw_obj->SetParameter(ConstDescID(DescLevel(PRIM_CAPSULE_HEIGHT)), bc->GetFloat(RIGID_SHAPE_SIZE_Y) + bc->GetFloat(RIGID_SHAPE_SIZE_X) * 2, DESCFLAGS_SET::NONE);
						cd.op = pdraw_obj;
						SendModelingCommand(MCOMMAND_CURRENTSTATETOOBJECT, cd);
						draw_obj = (BaseObject*)cd.result->GetIndex(0);
						draw_obj->SetPhong(true, true, 0.7853982);
					}
					break;
				}
				default:
					break;
				}
			}
			break;
		}
		case RIGID_SHAPE_SIZE_X:
		{
			if (bc != nullptr)
			{
				switch (bc->GetInt32(RIGID_SHAPE_TYPE))
				{
				case SPHERICAL:
				{
					if (pdraw_obj != nullptr)
					{
						BaseObject::Free(draw_obj);
						ModelingCommandData cd;
						cd.doc = GetActiveDocument();
						pdraw_obj->SetParameter(ConstDescID(DescLevel(PRIM_SPHERE_RAD)), bc->GetData(RIGID_SHAPE_SIZE_X), DESCFLAGS_SET::NONE);
						cd.op = pdraw_obj;
						SendModelingCommand(MCOMMAND_CURRENTSTATETOOBJECT, cd);
						draw_obj = (BaseObject*)cd.result->GetIndex(0);
						draw_obj->SetPhong(true, true, 0.7853982);
					}
					break;
				}
				case BOX:
				{
					if (pdraw_obj != nullptr)
					{
						BaseObject::Free(draw_obj);
						ModelingCommandData cd;
						cd.doc = GetActiveDocument();
						pdraw_obj->SetParameter(ConstDescID(DescLevel(PRIM_CUBE_LEN)), Vector(bc->GetFloat(RIGID_SHAPE_SIZE_X) * 2, bc->GetFloat(RIGID_SHAPE_SIZE_Z) * 2, bc->GetFloat(RIGID_SHAPE_SIZE_Y) * 2), DESCFLAGS_SET::NONE);
						cd.op = pdraw_obj;
						SendModelingCommand(MCOMMAND_CURRENTSTATETOOBJECT, cd);
						draw_obj = (BaseObject*)cd.result->GetIndex(0);
						draw_obj->SetPhong(true, true, 0.7853982);
					}
					break;
				}
				case CAPLETS:
				{
					if (pdraw_obj != nullptr)
					{
						BaseObject::Free(draw_obj);
						ModelingCommandData cd;
						cd.doc = GetActiveDocument();
						pdraw_obj->SetParameter(ConstDescID(DescLevel(PRIM_CAPSULE_RADIUS)), bc->GetData(RIGID_SHAPE_SIZE_X), DESCFLAGS_SET::NONE);
						pdraw_obj->SetParameter(ConstDescID(DescLevel(PRIM_CAPSULE_HEIGHT)), bc->GetFloat(RIGID_SHAPE_SIZE_Y) + bc->GetFloat(RIGID_SHAPE_SIZE_X) * 2, DESCFLAGS_SET::NONE);
						cd.op = pdraw_obj;
						SendModelingCommand(MCOMMAND_CURRENTSTATETOOBJECT, cd);
						draw_obj = (BaseObject*)cd.result->GetIndex(0);
						draw_obj->SetPhong(true, true, 0.7853982);
					}
					break;
				}
				default:
					break;
				}
			}
			break;
		}
		case RIGID_SHAPE_SIZE_Y:
		{
			if (bc != nullptr)
			{
				switch (bc->GetInt32(RIGID_SHAPE_TYPE))
				{
				case SPHERICAL:
				{
					if (pdraw_obj != nullptr)
					{
						BaseObject::Free(draw_obj);
						ModelingCommandData cd;
						cd.doc = GetActiveDocument();
						pdraw_obj->SetParameter(ConstDescID(DescLevel(PRIM_SPHERE_RAD)), bc->GetData(RIGID_SHAPE_SIZE_X), DESCFLAGS_SET::NONE);
						cd.op = pdraw_obj;
						SendModelingCommand(MCOMMAND_CURRENTSTATETOOBJECT, cd);
						draw_obj = (BaseObject*)cd.result->GetIndex(0);
						draw_obj->SetPhong(true, true, 0.7853982);
					}
					break;
				}
				case BOX:
				{
					if (pdraw_obj != nullptr)
					{
						BaseObject::Free(draw_obj);
						ModelingCommandData cd;
						cd.doc = GetActiveDocument();
						pdraw_obj->SetParameter(ConstDescID(DescLevel(PRIM_CUBE_LEN)), Vector(bc->GetFloat(RIGID_SHAPE_SIZE_X) * 2, bc->GetFloat(RIGID_SHAPE_SIZE_Z) * 2, bc->GetFloat(RIGID_SHAPE_SIZE_Y) * 2), DESCFLAGS_SET::NONE);
						cd.op = pdraw_obj;
						SendModelingCommand(MCOMMAND_CURRENTSTATETOOBJECT, cd);
						draw_obj = (BaseObject*)cd.result->GetIndex(0);
						draw_obj->SetPhong(true, true, 0.7853982);
					}
					break;
				}
				case CAPLETS:
				{
					if (pdraw_obj != nullptr)
					{
						BaseObject::Free(draw_obj);
						ModelingCommandData cd;
						cd.doc = GetActiveDocument();
						pdraw_obj->SetParameter(ConstDescID(DescLevel(PRIM_CAPSULE_RADIUS)), bc->GetData(RIGID_SHAPE_SIZE_X), DESCFLAGS_SET::NONE);
						pdraw_obj->SetParameter(ConstDescID(DescLevel(PRIM_CAPSULE_HEIGHT)), bc->GetFloat(RIGID_SHAPE_SIZE_Y) + bc->GetFloat(RIGID_SHAPE_SIZE_X) * 2, DESCFLAGS_SET::NONE);
						cd.op = pdraw_obj;
						SendModelingCommand(MCOMMAND_CURRENTSTATETOOBJECT, cd);
						draw_obj = (BaseObject*)cd.result->GetIndex(0);
						draw_obj->SetPhong(true, true, 0.7853982);
					}
					break;
				}
				default:
					break;
				}
			}
			break;
		}
		case RIGID_SHAPE_SIZE_Z:
		{
			if (bc != nullptr)
			{
				switch (bc->GetInt32(RIGID_SHAPE_TYPE))
				{
				case SPHERICAL:
				{
					if (pdraw_obj != nullptr)
					{
						BaseObject::Free(draw_obj);
						ModelingCommandData cd;
						cd.doc = GetActiveDocument();
						pdraw_obj->SetParameter(ConstDescID(DescLevel(PRIM_SPHERE_RAD)), bc->GetData(RIGID_SHAPE_SIZE_X), DESCFLAGS_SET::NONE);
						cd.op = pdraw_obj;
						SendModelingCommand(MCOMMAND_CURRENTSTATETOOBJECT, cd);
						draw_obj = (BaseObject*)cd.result->GetIndex(0);
						draw_obj->SetPhong(true, true, 0.7853982);
					}
					break;
				}
				case BOX:
				{
					if (pdraw_obj != nullptr)
					{
						BaseObject::Free(draw_obj);
						ModelingCommandData cd;
						cd.doc = GetActiveDocument();
						pdraw_obj->SetParameter(ConstDescID(DescLevel(PRIM_CUBE_LEN)), Vector(bc->GetFloat(RIGID_SHAPE_SIZE_X) * 2, bc->GetFloat(RIGID_SHAPE_SIZE_Z) * 2, bc->GetFloat(RIGID_SHAPE_SIZE_Y) * 2), DESCFLAGS_SET::NONE);
						cd.op = pdraw_obj;
						SendModelingCommand(MCOMMAND_CURRENTSTATETOOBJECT, cd);
						draw_obj = (BaseObject*)cd.result->GetIndex(0);
						draw_obj->SetPhong(true, true, 0.7853982);
					}
					break;
				}
				case CAPLETS:
				{
					if (pdraw_obj != nullptr)
					{
						BaseObject::Free(draw_obj);
						ModelingCommandData cd;
						cd.doc = GetActiveDocument();
						pdraw_obj->SetParameter(ConstDescID(DescLevel(PRIM_CAPSULE_RADIUS)), bc->GetData(RIGID_SHAPE_SIZE_X), DESCFLAGS_SET::NONE);
						pdraw_obj->SetParameter(ConstDescID(DescLevel(PRIM_CAPSULE_HEIGHT)), bc->GetFloat(RIGID_SHAPE_SIZE_Y) + bc->GetFloat(RIGID_SHAPE_SIZE_X) * 2, DESCFLAGS_SET::NONE);
						cd.op = pdraw_obj;
						SendModelingCommand(MCOMMAND_CURRENTSTATETOOBJECT, cd);
						draw_obj = (BaseObject*)cd.result->GetIndex(0);
						draw_obj->SetPhong(true, true, 0.7853982);
					}
					break;
				}
				default:
					break;
				}
			}
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
			physics_mode = bc->GetInt32(RIGID_PHYSICS_MODE);
			break;
		}
		default:
			break;
		}
		break;
	}
	case  ID_O_MMD_RIGID_ROOT:
	{
		auto* msg = static_cast<MMDRigidRootObjectMsg*>(data);
		if (msg != nullptr)
		{
			switch (msg->type) {
			case 0:
			{
				m_display_type = msg->display_type;
				if (draw_obj == nullptr)
				{
					if (m_display_type != RIGID_DISPLAY_TYPE_OFF)
					{
						BaseContainer* bc = static_cast<BaseList2D*>(node)->GetDataInstance();
						if (bc != nullptr)
						{
							BaseObject::Free(draw_obj);
							BaseObject::Free(pdraw_obj);
							ModelingCommandData cd;
							switch (bc->GetInt32(RIGID_SHAPE_TYPE))
							{
							case SPHERICAL:
							{
								cd.doc = GetActiveDocument();
								pdraw_obj = BaseObject::Alloc(Osphere);
								pdraw_obj->SetParameter(ConstDescID(DescLevel(PRIM_SPHERE_RAD)), bc->GetData(RIGID_SHAPE_SIZE_X), DESCFLAGS_SET::NONE);
								cd.op = pdraw_obj;
								SendModelingCommand(MCOMMAND_CURRENTSTATETOOBJECT, cd);
								draw_obj = (BaseObject*)cd.result->GetIndex(0);
								draw_obj->SetPhong(true, true, 0.7853982);
								break;
							}
							case BOX:
							{
								cd.doc = GetActiveDocument();
								pdraw_obj = BaseObject::Alloc(Ocube);
								pdraw_obj->SetParameter(ConstDescID(DescLevel(PRIM_CUBE_LEN)), Vector(bc->GetFloat(RIGID_SHAPE_SIZE_X) * 2, bc->GetFloat(RIGID_SHAPE_SIZE_Z) * 2, bc->GetFloat(RIGID_SHAPE_SIZE_Y) * 2), DESCFLAGS_SET::NONE);
								cd.op = pdraw_obj;
								SendModelingCommand(MCOMMAND_CURRENTSTATETOOBJECT, cd);
								draw_obj = (BaseObject*)cd.result->GetIndex(0);
								draw_obj->SetPhong(true, true, 0.7853982);
								break;
							}
							case CAPLETS:
							{
								cd.doc = GetActiveDocument();
								pdraw_obj = BaseObject::Alloc(Ocapsule);
								pdraw_obj->SetParameter(ConstDescID(DescLevel(PRIM_CAPSULE_RADIUS)), bc->GetData(RIGID_SHAPE_SIZE_X), DESCFLAGS_SET::NONE);
								pdraw_obj->SetParameter(ConstDescID(DescLevel(PRIM_CAPSULE_HEIGHT)), bc->GetFloat(RIGID_SHAPE_SIZE_Y) + bc->GetFloat(RIGID_SHAPE_SIZE_X) * 2, DESCFLAGS_SET::NONE);
								cd.op = pdraw_obj;
								SendModelingCommand(MCOMMAND_CURRENTSTATETOOBJECT, cd);
								draw_obj = (BaseObject*)cd.result->GetIndex(0);
								draw_obj->SetPhong(true, true, 0.7853982);
								break;
							}
							default:
								break;
							}
						}
					}
				}
				else if (m_display_type == RIGID_DISPLAY_TYPE_OFF)
				{
					BaseObject::Free(draw_obj);
					BaseObject::Free(pdraw_obj);
				}
				break;
			}
			case 1:
			{
				BaseObject* op = static_cast<BaseObject*>(node);
				if (m_rigid_mode == RIGID_MODE_EDIT && msg->rigid_mode == RIGID_MODE_ANIM) {
					no_anim_pos = op->GetAbsPos();
					no_anim_rot = op->GetAbsRot();
					if (related_bone != nullptr) {
						relative_bone_position = op->GetAbsPos() - related_bone->GetAbsPos();
						relative_bone_rotation = op->GetAbsRot() - related_bone->GetAbsRot();
					}
				}
				else if (m_rigid_mode == RIGID_MODE_ANIM && msg->rigid_mode == RIGID_MODE_EDIT) {
					op->SetAbsPos(no_anim_pos);
					op->SetAbsRot(no_anim_rot);
				}
				m_rigid_mode = msg->rigid_mode;
				if (protection_tag != nullptr) {
					if (m_rigid_mode == RIGID_MODE_ANIM) {
						protection_tag->SetParameter(ConstDescID(DescLevel(PROTECTION_P_X)), true, DESCFLAGS_SET::NONE);
						protection_tag->SetParameter(ConstDescID(DescLevel(PROTECTION_P_Y)), true, DESCFLAGS_SET::NONE);
						protection_tag->SetParameter(ConstDescID(DescLevel(PROTECTION_P_Z)), true, DESCFLAGS_SET::NONE);
						protection_tag->SetParameter(ConstDescID(DescLevel(PROTECTION_R_X)), true, DESCFLAGS_SET::NONE);
						protection_tag->SetParameter(ConstDescID(DescLevel(PROTECTION_R_Y)), true, DESCFLAGS_SET::NONE);
						protection_tag->SetParameter(ConstDescID(DescLevel(PROTECTION_R_Z)), true, DESCFLAGS_SET::NONE);
					}
					else {
						protection_tag->SetParameter(ConstDescID(DescLevel(PROTECTION_P_X)), false, DESCFLAGS_SET::NONE);
						protection_tag->SetParameter(ConstDescID(DescLevel(PROTECTION_P_Y)), false, DESCFLAGS_SET::NONE);
						protection_tag->SetParameter(ConstDescID(DescLevel(PROTECTION_P_Z)), false, DESCFLAGS_SET::NONE);
						protection_tag->SetParameter(ConstDescID(DescLevel(PROTECTION_R_X)), false, DESCFLAGS_SET::NONE);
						protection_tag->SetParameter(ConstDescID(DescLevel(PROTECTION_R_Y)), false, DESCFLAGS_SET::NONE);
						protection_tag->SetParameter(ConstDescID(DescLevel(PROTECTION_R_Z)), false, DESCFLAGS_SET::NONE);
					}
				}
				break;
			}
			}
		}
		break;
	}
	default:
		break;
	}
	return SUPER::Message(node, type, data);
}

DRAWRESULT MMDRigidObject::Draw(BaseObject* op, DRAWPASS drawpass, BaseDraw* bd, BaseDrawHelp* bh)
{
	if (drawpass == DRAWPASS::OBJECT)
	{
		if (op == nullptr || bd == nullptr || bh == nullptr)
		{
			return DRAWRESULT::FAILURE;
		}
		BaseContainer* bc = static_cast<BaseList2D*>(op)->GetDataInstance();
		bd->SetMatrix_Matrix(nullptr, op->GetMg());
		if (bc != nullptr)
		{
			switch (m_display_type)
			{
			case RIGID_DISPLAY_TYPE_ON:
			{
				if (draw_obj != nullptr)
				{
					if (op == GetActiveDocument()->GetActiveObject())
					{
						ObjectColorProperties objColor{ PMX_Rigid_Color[bc->GetInt32(RIGID_GROUP_ID)], ID_BASEOBJECT_USECOLOR_ALWAYS, false };
						draw_obj->SetColorProperties(&objColor);
						bd->DrawObject(bh, draw_obj, DRAWOBJECT::USE_OBJECT_COLOR, drawpass);
					}
					else {
						ObjectColorProperties objColor{ PMX_Rigid_Color[bc->GetInt32(RIGID_GROUP_ID)], ID_BASEOBJECT_USECOLOR_ALWAYS, true };
						draw_obj->SetColorProperties(&objColor);
						bd->DrawObject(bh, draw_obj, DRAWOBJECT::USE_OBJECT_COLOR | DRAWOBJECT::XRAY_ON, drawpass);
					}
				}
				else {
					if (bc != nullptr)
					{
						BaseObject::Free(draw_obj);
						BaseObject::Free(pdraw_obj);
						ModelingCommandData cd;
						switch (bc->GetInt32(RIGID_SHAPE_TYPE))
						{
						case SPHERICAL:
						{
							cd.doc = GetActiveDocument();
							pdraw_obj = BaseObject::Alloc(Osphere);
							pdraw_obj->SetParameter(ConstDescID(DescLevel(PRIM_SPHERE_RAD)), bc->GetData(RIGID_SHAPE_SIZE_X), DESCFLAGS_SET::NONE);
							cd.op = pdraw_obj;
							SendModelingCommand(MCOMMAND_CURRENTSTATETOOBJECT, cd);
							draw_obj = (BaseObject*)cd.result->GetIndex(0);
							draw_obj->SetPhong(true, true, 0.7853982);
							break;
						}
						case BOX:
						{
							cd.doc = GetActiveDocument();
							pdraw_obj = BaseObject::Alloc(Ocube);
							pdraw_obj->SetParameter(ConstDescID(DescLevel(PRIM_CUBE_LEN)), Vector(bc->GetFloat(RIGID_SHAPE_SIZE_X) * 2, bc->GetFloat(RIGID_SHAPE_SIZE_Z) * 2, bc->GetFloat(RIGID_SHAPE_SIZE_Y) * 2), DESCFLAGS_SET::NONE);
							cd.op = pdraw_obj;
							SendModelingCommand(MCOMMAND_CURRENTSTATETOOBJECT, cd);
							draw_obj = (BaseObject*)cd.result->GetIndex(0);
							draw_obj->SetPhong(true, true, 0.7853982);
							break;
						}
						case CAPLETS:
						{
							cd.doc = GetActiveDocument();
							pdraw_obj = BaseObject::Alloc(Ocapsule);
							pdraw_obj->SetParameter(ConstDescID(DescLevel(PRIM_CAPSULE_RADIUS)), bc->GetData(RIGID_SHAPE_SIZE_X), DESCFLAGS_SET::NONE);
							pdraw_obj->SetParameter(ConstDescID(DescLevel(PRIM_CAPSULE_HEIGHT)), bc->GetFloat(RIGID_SHAPE_SIZE_Y) + bc->GetFloat(RIGID_SHAPE_SIZE_X) * 2, DESCFLAGS_SET::NONE);
							cd.op = pdraw_obj;
							SendModelingCommand(MCOMMAND_CURRENTSTATETOOBJECT, cd);
							draw_obj = (BaseObject*)cd.result->GetIndex(0);
							draw_obj->SetPhong(true, true, 0.7853982);
							break;
						}
						default:
							break;
						}
					}
				}
				break;
			}
			case RIGID_DISPLAY_TYPE_WIRE:
			{
				if (draw_obj != nullptr)
				{
					if (op == GetActiveDocument()->GetActiveObject())
					{
						ObjectColorProperties objColor{ PMX_Rigid_Color[bc->GetInt32(RIGID_GROUP_ID)], ID_BASEOBJECT_USECOLOR_ALWAYS, false };
						draw_obj->SetColorProperties(&objColor);
						bd->DrawObject(bh, draw_obj, DRAWOBJECT::USE_OBJECT_COLOR, drawpass);
					}
					else {
						ObjectColorProperties objColor{ PMX_Rigid_Color[bc->GetInt32(RIGID_GROUP_ID)], ID_BASEOBJECT_USECOLOR_ALWAYS, true};
						draw_obj->SetColorProperties(&objColor);
						bd->DrawObject(bh, draw_obj, DRAWOBJECT::USE_OBJECT_COLOR, drawpass);
					}
				}
				else {
					if (bc != nullptr)
					{
						BaseObject::Free(draw_obj);
						BaseObject::Free(pdraw_obj);
						ModelingCommandData cd;
						switch (bc->GetInt32(RIGID_SHAPE_TYPE))
						{
						case SPHERICAL:
						{
							cd.doc = GetActiveDocument();
							pdraw_obj = BaseObject::Alloc(Osphere);
							pdraw_obj->SetParameter(ConstDescID(DescLevel(PRIM_SPHERE_RAD)), bc->GetData(RIGID_SHAPE_SIZE_X), DESCFLAGS_SET::NONE);
							cd.op = pdraw_obj;
							SendModelingCommand(MCOMMAND_CURRENTSTATETOOBJECT, cd);
							draw_obj = (BaseObject*)cd.result->GetIndex(0);
							draw_obj->SetPhong(true, true, 0.7853982);
							break;
						}
						case BOX:
						{
							cd.doc = GetActiveDocument();
							pdraw_obj = BaseObject::Alloc(Ocube);
							pdraw_obj->SetParameter(ConstDescID(DescLevel(PRIM_CUBE_LEN)), Vector(bc->GetFloat(RIGID_SHAPE_SIZE_X) * 2, bc->GetFloat(RIGID_SHAPE_SIZE_Z) * 2, bc->GetFloat(RIGID_SHAPE_SIZE_Y) * 2), DESCFLAGS_SET::NONE);
							cd.op = pdraw_obj;
							SendModelingCommand(MCOMMAND_CURRENTSTATETOOBJECT, cd);
							draw_obj = (BaseObject*)cd.result->GetIndex(0);
							draw_obj->SetPhong(true, true, 0.7853982);
							break;
						}
						case CAPLETS:
						{
							cd.doc = GetActiveDocument();
							pdraw_obj = BaseObject::Alloc(Ocapsule);
							pdraw_obj->SetParameter(ConstDescID(DescLevel(PRIM_CAPSULE_RADIUS)), bc->GetData(RIGID_SHAPE_SIZE_X), DESCFLAGS_SET::NONE);
							pdraw_obj->SetParameter(ConstDescID(DescLevel(PRIM_CAPSULE_HEIGHT)), bc->GetFloat(RIGID_SHAPE_SIZE_Y) + bc->GetFloat(RIGID_SHAPE_SIZE_X) * 2, DESCFLAGS_SET::NONE);
							cd.op = pdraw_obj;
							SendModelingCommand(MCOMMAND_CURRENTSTATETOOBJECT, cd);
							draw_obj = (BaseObject*)cd.result->GetIndex(0);
							draw_obj->SetPhong(true, true, 0.7853982);
							break;
						}
						default:
							break;
						}
					}
				}
				break;
			}
			default:
				break;
			}
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
	BaseContainer* bc = static_cast<BaseList2D*>(op)->GetDataInstance();
	if (bc == nullptr)
	{
		return EXECUTIONRESULT::OK;
	}
	BaseObject* PredObject = op->GetPred();
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
		if (PredObject == nullptr)
		{
			op->SetParameter(ConstDescID(DescLevel(RIGID_INDEX)), "0"_s, DESCFLAGS_SET::NONE);
		}
		else {
			while (PredObject != nullptr && !PredObject->IsInstanceOf(ID_O_MMD_RIGID))
			{
				PredObject = PredObject->GetPred();
			}
			GeData data;
			PredObject->GetParameter(ConstDescID(DescLevel(RIGID_INDEX)), data, DESCFLAGS_GET::NONE);
			String RigidIndex = data.GetString();
			op->SetParameter(ConstDescID(DescLevel(RIGID_INDEX)), String::IntToString(RigidIndex.ToInt32(nullptr) + 1), DESCFLAGS_SET::NONE);
		}
		if (rigid_root_object == nullptr)
		{
			m_rigid_root = UpObject;
		}
	}
	Int32 now_index = bc->GetString(RIGID_INDEX).ToInt32(nullptr);
	if (now_index != pred_index && m_rigid_root != nullptr)
		m_rigid_root->Message(ID_O_MMD_RIGID, NewObj(OMMDRigid_MSG, pred_index, now_index, op).GetValue());
	if (protection_tag == nullptr) {
		protection_tag = op->MakeTag(Tprotection);
		protection_tag->ChangeNBit(NBIT::OHIDE, NBITCONTROL::SET);
		protection_tag->ChangeNBit(NBIT::AHIDE_FOR_HOST, NBITCONTROL::SET);
		protection_tag->SetParameter(ConstDescID(DescLevel(PROTECTION_ALLOW_EXPRESSIONS)), true, DESCFLAGS_SET::NONE);
	}
	if (m_rigid_mode == RIGID_MODE_ANIM) {
		switch (physics_mode)
		{
		case TRACK_BONES:
		{
			if (related_bone != nullptr) {
				op->SetAbsPos(related_bone->GetAbsPos() + relative_bone_position);
				op->SetAbsRot(related_bone->GetAbsRot() + relative_bone_rotation);
			}
			break;
		}
		case PHYSICAL_CALCULUS:
		{
			if (related_bone != nullptr) {
				related_bone->SetAbsPos(op->GetAbsPos() - relative_bone_position);
				related_bone->SetAbsRot(op->GetAbsRot() - relative_bone_rotation);
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
	hf->ReadInt32(&m_display_type);
	hf->ReadInt32(&m_rigid_mode);
	hf->ReadInt32(&physics_mode);
	hf->ReadVector(&no_anim_pos);
	hf->ReadVector(&no_anim_rot);
	hf->ReadVector(&relative_bone_position);
	hf->ReadVector(&relative_bone_rotation);
	AutoAlloc<BaseLink> rigid_root_link;
	if (rigid_root_link == nullptr)
		return false;
	if (!rigid_root_link->Read(hf))
		return false;
	m_rigid_root = static_cast<BaseObject*>(rigid_root_link->GetLink(GetActiveDocument()));
	AutoAlloc<BaseLink> related_bone_link;
	if (related_bone_link == nullptr)
		return false;
	if (!related_bone_link->Read(hf))
		return false;
	related_bone = static_cast<BaseObject*>(related_bone_link->GetLink(GetActiveDocument()));
	return true;
}

Bool MMDRigidObject::Write(const GeListNode* node, HyperFile* hf) const
{
	hf->WriteInt32(m_display_type);
	hf->WriteInt32(m_rigid_mode);
	hf->WriteInt32(physics_mode);
	hf->WriteVector(no_anim_pos);
	hf->WriteVector(no_anim_rot);
	hf->WriteVector(relative_bone_position);
	hf->WriteVector(relative_bone_rotation);
	AutoAlloc<BaseLink> rigid_root_link;
	if (rigid_root_link == nullptr)
		return false;
	rigid_root_link->SetLink(m_rigid_root);
	if (!rigid_root_link->Write(hf))
		return false;
	AutoAlloc<BaseLink> related_bone_link;
	if (related_bone_link == nullptr)
		return false;
	related_bone_link->SetLink(related_bone);
	if (!related_bone_link->Write(hf))
		return false;
	return true;
}

Bool MMDRigidObject::CopyTo(NodeData* dest, const GeListNode* snode, GeListNode* dnode, COPYFLAGS flags,
	AliasTrans* trn) const
{
	auto* const destObject = static_cast<MMDRigidObject*>(dest);
	if (destObject == nullptr)
		return false;
	destObject->m_rigid_root = m_rigid_root;
	destObject->related_bone = related_bone;
	destObject->m_rigid_mode = m_rigid_mode;
	destObject->m_display_type = m_display_type;
	destObject->no_anim_pos = no_anim_pos;
	destObject->no_anim_rot = no_anim_rot;
	destObject->relative_bone_position = relative_bone_position;
	destObject->relative_bone_rotation = relative_bone_rotation;
	return true;
}

void MMDRigidObject::Free(GeListNode* node)
{
	BaseObject::Free(pdraw_obj);
	BaseObject::Free(draw_obj);
}

NodeData* MMDRigidObject::Alloc()
{
	return NewObjClear(MMDRigidObject);
}

BaseObject* MMDRigidObject::GetRootObject() const
{
	return m_rigid_root;
}



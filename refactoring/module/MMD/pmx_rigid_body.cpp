/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & Walter White & CMT contributors.
Author:			Aimidi
Date:			2022/9/24
File:			pmx_rigid_body.cpp
Description:	pmx rigid body data

**************************************************************************/

#include "pch.h"
#include "pmx_rigid_body.h"

Bool PMXRigidBody::ReadFromFile(BaseFile* file)
{
	if (!m_model_info->m_text_reader(file, m_data->rigid_body_name_local))
		return FALSE;
	if (!m_model_info->m_text_reader(file, m_data->rigid_body_name_universal))
		return FALSE;
	if (!m_model_info->m_bone_index_reader(file, m_data->related_bone_index))
		return FALSE;
	if (!file->ReadChar(&m_data->group_id))
		return FALSE;
	if (!file->ReadBytes(&m_data->non_collision_group, sizeof m_data->non_collision_group))
		return FALSE;
	if (!file->ReadChar(&m_data->shape_type))
		return FALSE;
	if (!file->ReadVector32(&m_data->shape_size))
		return FALSE;
	if (!file->ReadVector32(&m_data->shape_position))
		return FALSE;
	if (!file->ReadVector32(&m_data->shape_rotation))
		return FALSE;
	if (!file->ReadFloat32(&m_data->mass))
		return FALSE;
	if (!file->ReadFloat32(&m_data->move_attenuation))
		return FALSE;
	if (!file->ReadFloat32(&m_data->rotation_damping))
		return FALSE;
	if (!file->ReadFloat32(&m_data->repulsion_force))
		return FALSE;
	if (!file->ReadFloat32(&m_data->friction_force))
		return FALSE;
	if (!file->ReadChar(&m_data->physics_mode))
		return FALSE;
	return TRUE;
}

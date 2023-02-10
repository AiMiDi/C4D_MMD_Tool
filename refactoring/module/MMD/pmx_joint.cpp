/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & Walter White & CMT contributors.
Author:			Aimidi
Date:			2022/9/24
File:			pmx_joint.cpp
Description:	pmx joint data

**************************************************************************/

#include "pch.h"
#include "pmx_joint.h"

Bool PMXJoint::ReadFromFile(BaseFile* file)
{
	if (!m_model_info->m_text_reader(file, m_data->joint_name_local))
		return FALSE;
	if (!m_model_info->m_text_reader(file, m_data->joint_name_universal))
		return FALSE;
	if (!file->ReadChar(&m_data->joint_type))
		return FALSE;
	if (!m_model_info->m_rigidbody_index_reader(file, m_data->rigid_body_index_A))
		return FALSE;
	if (!m_model_info->m_rigidbody_index_reader(file, m_data->rigid_body_index_B))
		return FALSE;
	if (!file->ReadVector32(&m_data->position))
		return FALSE;
	if (!file->ReadVector32(&m_data->rotation))
		return FALSE;
	if (!file->ReadVector32(&m_data->position_minimum))
		return FALSE;
	if (!file->ReadVector32(&m_data->position_maximum))
		return FALSE;
	if (!file->ReadVector32(&m_data->rotation_minimum))
		return FALSE;
	if (!file->ReadVector32(&m_data->rotation_maximum))
		return FALSE;
	if (!file->ReadVector32(&m_data->position_spring))
		return FALSE;
	if (!file->ReadVector32(&m_data->rotation_spring))
		return FALSE;
	return TRUE;
}

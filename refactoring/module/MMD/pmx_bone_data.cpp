/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & Walter White & CMT contributors.
Author:			Aimidi
Date:			2022/8/24
File:			pmx_bone_data.cpp
Description:	pmx bone data

**************************************************************************/

#include "pch.h"
#include "pmx_bone_data.h"

Bool PMXBone::ReadFromFile(BaseFile* file)
{
	iferr_scope_handler
	{
		return FALSE;
	};
	if (!m_model_info.m_text_reader(file, m_data->bone_name_local))
		return FALSE;
	if (!m_model_info.m_text_reader(file, m_data->bone_name_universal))
		return FALSE;
	if (!file->ReadVector32(&m_data->position))
		return FALSE;
	if (!m_model_info.m_bone_index_reader(file,m_data->parent_bone_index))
		return FALSE;
	if (!file->ReadInt32(& m_data->layer))
		return FALSE;
	if (!file->ReadBytes(& m_data->bone_flags, sizeof PMXBoneFlags))
		return FALSE;
	if ( m_data->bone_flags.indexed_tail_position == 0)
	{
		if (!file->ReadVector32(& m_data->tail_position))
			return FALSE;
	}
	else if ( m_data->bone_flags.indexed_tail_position == 1)
	{
		if (!m_model_info.m_bone_index_reader(file, m_data->tail_index))
			return FALSE;
	}
	if ( m_data->bone_flags.inherit_rotation || m_data->bone_flags.inherit_translation)
	{
		if (!m_model_info.m_bone_index_reader(file, m_data->inherit_bone_parent_index))
			return FALSE;
		if (!file->ReadFloat32(& m_data->inherit_bone_parent_influence))
			return FALSE;
	}
	if ( m_data->bone_flags.fixed_axis)
	{
		if (!file->ReadVector32(& m_data->bone_fixed_axis))
			return FALSE;
	}
	if ( m_data->bone_flags.local_coordinate)
	{
		if (!file->ReadVector32(& m_data->bone_local_X))
			return FALSE;
		if (!file->ReadVector32(& m_data->bone_local_Z))
			return FALSE;
	}
	if ( m_data->bone_flags.external_parent_deform)
	{
		file->Seek(4);
	}
	if ( m_data->bone_flags.is_IK)
	{
		if (!m_model_info.m_bone_index_reader(file, m_data->IK_target_index))
			return FALSE;
		if (!file->ReadInt32(& m_data->IK_loop_count))
			return FALSE;
		if (!file->ReadFloat32(& m_data->IK_limit_radian))
			return FALSE;
		if (!file->ReadInt32(& m_data->IK_link_count))
			return FALSE;
		m_data->IK_links.Resize(m_data->IK_link_count)iferr_return;
		for (Int32 j = 0; j < m_data->IK_link_count; j++)
		{
			auto& [bone_index, has_limits, limit_min, limit_max] = m_data->IK_links[j];
			if (!m_model_info.m_bone_index_reader(file, bone_index))
				return FALSE;
			if (!file->ReadBool(&has_limits))
				return FALSE;
			if (has_limits)
			{
				if (!file->ReadVector32(&limit_min))
					return FALSE;
				if (!file->ReadVector32(&limit_max))
					return FALSE;
			}
		}
	}
	return true;
}

/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & Walter White & CMT contributors.
Author:			Aimidi
Date:			2022/9/19
File:			pmx_display.cpp
Description:	pmx display data

**************************************************************************/

#include "pch.h"
#include "pmx_display.h"

Bool PMXDisplay::ReadFromFile(BaseFile* file)
{
	if (!m_model_info->m_text_reader(file, m_data->display_name_local))
		return FALSE;
	if (!m_model_info->m_text_reader(file, m_data->display_name_universal))
		return FALSE;
	if (!file->ReadChar(&m_data->special_flag))
		return FALSE;
	if (!file->ReadInt32(&m_data->frame_count))
		return FALSE;

	for (Int32 frame_index = 0; frame_index < m_data->frame_count; frame_index++)
	{
		auto& [frame_type, frame_data] = m_data->frame_datas[frame_index];
		if (!file->ReadChar(&frame_type))
			return FALSE;
		switch (frame_type)
		{
		case PMXFrameData::BONE:
		{
			m_model_info->m_bone_index_reader(file, frame_data);
			break;
		}
		case PMXFrameData::MORPH:
		{
			m_model_info->m_morph_index_reader(file, frame_data);
			break;
		}
		default:
			return FALSE;
		}
	}
	return TRUE;
}

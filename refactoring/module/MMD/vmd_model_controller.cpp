/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & Walter White & CMT contributors.
Author:			Aimidi
Date:			2022/7/14
File:			vmd_model_controller_animation.cpp
Description:	MMD style model information animation

**************************************************************************/

#include "pch.h"
#include "vmd_model_controller.h"

Bool VMDModelControllerAnimation::ReadFromFile(BaseFile* file)
{
	iferr_scope_handler
	{
		return FALSE;
	};
	assert(file != nullptr);
	if (!file->ReadUInt32(&m_frame_num))
		return FALSE;
	if (!file->ReadBool(&m_data->show))
		return FALSE;
	UInt32 ik_info_number = 0;
	if (!file->ReadUInt32(&ik_info_number))
		return FALSE;
	m_data->IK_Info_array.Resize(ik_info_number)iferr_return;
	for (UInt32 ik_info_index = 0; ik_info_index < ik_info_number; ++ik_info_index)
	{
		if (!m_data->IK_Info_array[ik_info_index].ReadFromFile(file))
			return FALSE;
	}
	return TRUE;
}

Bool VMDModelControllerAnimation::WriteToFile(BaseFile* file) const
{
	iferr_scope_handler
	{
		return FALSE;
	};
	assert(file != nullptr);
	if (!file->WriteUInt32(m_frame_num))
		return FALSE;
	if (!file->WriteBool(m_data->show))
		return FALSE;
	auto ikInfoCount = static_cast<UInt32>(m_data->IK_Info_array.GetCount());
	if (!file->WriteUInt32(ikInfoCount))
		return FALSE;
	while (ikInfoCount--)
	{
		if (!m_data->IK_Info_array[ikInfoCount].WriteToFile(file))
			return FALSE;
	}
	return TRUE;
}

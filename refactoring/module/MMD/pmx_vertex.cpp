/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & Walter White & CMT contributors.
Author:			Aimidi
Date:			2022/8/13
File:			pmx_vertex.cpp
Description:	pmx vertex data

**************************************************************************/

#include "pch.h"
#include "pmx_vertex.h"

Bool PMXVertex::ReadFromFile(BaseFile* file)
{
	if (!file->ReadVector32(&m_data->position))
		return FALSE;
	if (!file->ReadVector32(&m_data->normal))
		return FALSE;
	if (!file->ReadBytes(&m_data->UV, sizeof m_data->UV))
		return FALSE;
	if (!file->Seek(16LL * m_model_info->GetData()->additional_vec4_count))
		return FALSE;
	if (!file->ReadChar(&m_data->weight_deform_type))
		return FALSE;
	m_data->weight_deform.reset(PMXWeight::Alloc(m_data->weight_deform_type, m_model_info));
	m_data->weight_deform->ReadFromFile(file);
	if (!file->ReadFloat32(&m_data->edge_scale))
		return FALSE;
	return TRUE;
}

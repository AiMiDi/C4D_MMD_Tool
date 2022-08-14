/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & Walter White & CMT contributors.
Author:			Aimidi
Date:			2022/8/13
File:			pmx_vertex_data.cpp
Description:	pmx vertex data

**************************************************************************/

#include "pch.h"
#include "pmx_vertex_data.h"

Bool PMXVertexData::ReadFromFile(BaseFile* file)
{
	if (!file->ReadVector32(&m_position))
		return FALSE;
	if (!file->ReadVector32(&m_normal))
		return FALSE;
	if (!file->ReadBytes(&m_UV, sizeof(maxon::Vector2d32)))
		return FALSE;
	if (!file->Seek(16LL * m_model_info.additional_Vector4d32_count))
		return FALSE;
	if (!file->ReadChar(&m_weight_deform_type))
		return FALSE;
	m_weight_deform.reset(PMXWeight::Alloc(m_weight_deform_type, m_model_info.m_bone_index_reader));
	m_weight_deform->ReadFromFile(file);
	if (!file->ReadFloat32(&m_edge_scale))
		return FALSE;
	return TRUE;
}

/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & Walter White & CMT contributors.
Author:			Aimidi
Date:			2022/9/18
File:			pmx_morph.cpp
Description:	pmx morph data

**************************************************************************/

#include "pch.h"
#include "pmx_morph.h"
#include "utils/math_util.hpp"

Bool PMXGroupMorphOffset::ReadFromFile(BaseFile* file)
{
	if (!m_model_info->m_morph_index_reader(file, m_data->morph_index))
		return FALSE;
	if (!file->ReadFloat32(&m_data->influence))
		return FALSE;
	return TRUE;
}

Bool PMXVertexMorpOffset::ReadFromFile(BaseFile* file)
{
	if (!m_model_info->m_vertex_index_reader(file, m_data->vertex_index))
		return FALSE;
	if (!file->ReadVector32(&m_data->position_offset))
		return FALSE;
	return TRUE;
}

Bool PMXBoneMorphOffset::ReadFromFile(BaseFile* file)
{
	if (!m_model_info->m_bone_index_reader(file, m_data->bone_index))
		return FALSE;
	if (!file->ReadVector32(&m_data->translation))
		return FALSE;
	Vector4d32 quaternion_rotation;
	if (!file->ReadBytes(&quaternion_rotation, sizeof quaternion_rotation))
		return FALSE;
	m_data->rotation = math_util::QuaternionToEuler(quaternion_rotation);
	return TRUE;
}

Bool PMXUVMorphOffset::ReadFromFile(BaseFile* file)
{
	if (!m_model_info->m_vertex_index_reader(file, m_data->vertex_index))
		return FALSE;
	if (!file->ReadBytes(&m_data->UV_offset, sizeof m_data->UV_offset))
		return FALSE;
	return TRUE;
}

Bool PMXMaterialMorphOffset::ReadFromFile(BaseFile* file)
{
	if (!m_model_info->m_material_index_reader(file, m_data->material_index))
		return FALSE;
	if (!file->ReadChar(&m_data->blend_mode))
		return FALSE;
	if (!file->ReadBytes(&m_data->diffuse, sizeof m_data->diffuse))
		return FALSE;
	if (!file->ReadVector32(&m_data->specular))
		return FALSE;
	if (!file->ReadFloat32(&m_data->specularity))
		return FALSE;
	if (!file->ReadVector32(&m_data->ambient))
		return FALSE;
	if (!file->ReadBytes(&m_data->edge_colour, sizeof m_data->edge_colour))
		return FALSE;
	if (!file->ReadFloat32(&m_data->edge_size))
		return FALSE;
	if (!file->ReadBytes(&m_data->texture_tint, sizeof m_data->texture_tint))
		return FALSE;
	if (!file->ReadBytes(&m_data->environment_tint, sizeof m_data->environment_tint))
		return FALSE;
	if (!file->ReadBytes(&m_data->toon_tint, sizeof m_data->toon_tint))
		return FALSE;
	return TRUE;
}

Bool PMXFlipMorphOffset::ReadFromFile(BaseFile* file)
{
	if (!m_model_info->m_morph_index_reader(file, m_data->morph_index))
		return FALSE;
	if (!file->ReadFloat32(&m_data->influence))
		return FALSE;
	return TRUE;
}

Bool PMXImpulseMorphOffset::ReadFromFile(BaseFile* file)
{
	if (!m_model_info->m_rigidbody_index_reader(file, m_data->rigid_body_index))
		return FALSE;
	if (!file->ReadChar(&m_data->local_flag))
		return FALSE;
	if (!file->ReadVector32(&m_data->movement_speed))
		return FALSE;
	if (!file->ReadVector32(&m_data->rotation_torque))
		return FALSE;
	return TRUE;
}

Bool PMXMorph::ReadFromFile(BaseFile* file)
{
	iferr_scope_handler
	{
		return FALSE;
	};
	if (!m_model_info->m_text_reader(file, m_data->morph_name_local))
		return FALSE;
	if (!m_model_info->m_text_reader(file, m_data->morph_name_universal))
		return FALSE;
	if (!file->ReadChar(&m_data->panel_type))
		return FALSE;
	if (!file->ReadChar(&m_data->morph_type))
		return FALSE;
	if (!file->ReadInt32(&m_data->offset_count))
		return FALSE;
	m_data->offset_data.Resize(m_data->offset_count)iferr_return;
	for (Int32 offset_index = 0; offset_index < m_data->offset_count; offset_index++)
	{
		auto& offset = m_data->offset_data[offset_index];
		switch (m_data->morph_type)
		{
		case PMXMorphData::GROUP:
		{
			offset = std::make_unique<PMXGroupMorphOffset>(m_model_info);
			break;
		}
		case PMXMorphData::VERTEX:
		{
			offset = std::make_unique<PMXVertexMorpOffset>(m_model_info);
			break;
		}
		case PMXMorphData::BONE:
		{
			offset = std::make_unique<PMXBoneMorphOffset>(m_model_info);
			break;
		}
		case PMXMorphData::UV:
		case PMXMorphData::UV1:
		case PMXMorphData::UV2:
		case PMXMorphData::UV3:
		case PMXMorphData::UV4:
		{
			offset = std::make_unique<PMXUVMorphOffset>(m_model_info, m_data->morph_type - 3);
			break;
		}
		case PMXMorphData::MATERIAL:
		{
			offset = std::make_unique<PMXMaterialMorphOffset>(m_model_info);
			break;
		}
		case PMXMorphData::FLIP:
		{
			offset = std::make_unique<PMXFlipMorphOffset>(m_model_info);
			break;
		}
		case PMXMorphData::IMPULSE:
		{
			offset = std::make_unique<PMXImpulseMorphOffset>(m_model_info);
			break;
		}
		default: 
			return FALSE;
		}
		if (!offset->ReadFromFile(file))
			return FALSE;
	}
	return TRUE;
}

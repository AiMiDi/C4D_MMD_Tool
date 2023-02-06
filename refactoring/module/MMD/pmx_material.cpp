/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & Walter White & CMT contributors.
Author:			Aimidi
Date:			2022/9/14
File:			pmx_material.cpp
Description:	pmx material data

**************************************************************************/

#include "pch.h"
#include "pmx_material.h"

Bool PMXMaterial::ReadFromFile(BaseFile* file)
{
	if (!m_model_info->m_text_reader(file, m_data->material_name_local))
		return FALSE;
	if (!m_model_info->m_text_reader(file, m_data->material_name_universal))
		return FALSE;
	static_assert(sizeof Vector4d32 == 16);
	if (!file->ReadBytes(&m_data->diffuse_colour, sizeof Vector4d32))
		return FALSE;
	if (!file->ReadVector32(&m_data->specular_colour))
		return FALSE;
	if (!file->ReadFloat32(&m_data->specular_strength))
		return FALSE;
	if (!file->ReadVector32(&m_data->ambient_colour))
		return FALSE;
	static_assert(sizeof PMXMaterialFlags == 1);
	if (!file->ReadBytes(&m_data->drawing_flags, sizeof PMXMaterialFlags))
		return FALSE;
	if (!file->ReadBytes(&m_data->edge_colour, sizeof(Vector4d32)))
		return FALSE;
	if (!file->ReadFloat32(&m_data->edge_scale))
		return FALSE;
	if (!m_model_info->m_texture_index_reader(file,m_data->texture_index))
		return FALSE;
	if (!m_model_info->m_texture_index_reader(file,m_data->environment_index))
		 return FALSE;
	if (!file->ReadChar(&m_data->environment_blend_mode))
		return FALSE;
	if (!file->ReadChar(&m_data->toon_reference))
		return FALSE;
	if (m_data->toon_reference == 0)
	{
		if (!m_model_info->m_texture_index_reader(file, m_data->toon_part))
		return FALSE;
	}
	else if (m_data->toon_reference == 1)
	{
		if (!file->ReadChar(&m_data->toon_internal))
			return FALSE;
	}
	if (!m_model_info->m_text_reader(file, m_data->meta_data))
		return FALSE;
	if (!file->ReadInt32(&m_data->surface_count))
		return FALSE;
	m_data->surface_count /= 3;
	return TRUE;
}

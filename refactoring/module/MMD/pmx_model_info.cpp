/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & Walter White & CMT contributors.
Author:			Aimidi
Date:			2022/8/14
File:			pmx_model_info.cpp
Description:	pmx model information data

**************************************************************************/

#include "pch.h"
#include "module/MMD/pmx_model_info.h"

void PMXModelInfo::ResetReader()
{
	m_text_reader.SetTextEncoding(m_data->text_encoding);
	m_vertex_index_reader.SetIndexSize(m_data->vertex_index_size);
	m_texture_index_reader.SetIndexSize(m_data->texture_index_size);
	m_material_index_reader.SetIndexSize(m_data->material_index_size);
	m_bone_index_reader.SetIndexSize(m_data->bone_index_size);
	m_morph_index_reader.SetIndexSize(m_data->morph_index_size);
	m_rigidbody_index_reader.SetIndexSize(m_data->rigidbody_index_size);
}

Bool PMXModelInfo::ReadFromFile(BaseFile* file)
{
	if (!file->ReadFloat32(&m_data->version))
		return FALSE;
	Char globals_count;                            
	if (!file->ReadChar(&globals_count))
		return FALSE;      
	if (globals_count != 8)
	{
		ApplicationOutput("PMXModelInfo::LoadFromFile() error at read global info count"_s);
		return FALSE;
	}
	if (!file->ReadChar(&m_data->text_encoding))
		return FALSE;
	if (!file->ReadChar(&m_data->additional_vec4_count))
		return FALSE;
	if (!file->ReadChar(&m_data->vertex_index_size))
		return FALSE;
	if (!file->ReadChar(&m_data->texture_index_size))
		return FALSE;
	if (!file->ReadChar(&m_data->material_index_size))
		return FALSE;
	if (!file->ReadChar(&m_data->bone_index_size))
		return FALSE;
	if (!file->ReadChar(&m_data->morph_index_size))
		return FALSE;
	if (!file->ReadChar(&m_data->rigidbody_index_size))
		return FALSE;
	ResetReader();
	if (!m_text_reader(file, m_data->model_name_local))
		return FALSE;
	if (!m_text_reader(file, m_data->model_name_universal))
		return FALSE;
	if (!m_text_reader(file, m_data->comments_local))
		return FALSE;
	if (!m_text_reader(file, m_data->comments_universal))
		return FALSE;
	return TRUE;
}

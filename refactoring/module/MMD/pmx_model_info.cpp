/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & Walter White & CMT contributors.
Author:			Aimidi
Date:			2022/8/14
File:			pmx_model_info.cpp
Description:	pmx model information data

**************************************************************************/

#include "pch.h"
#include "module/MMD/pmx_model_info.h"

void PMXModelInfoData::InitReader()
{
	m_text_reader.SetTextEncoding(m_text_encoding);
	m_vertex_index_reader.SetIndexSize(m_vertex_index_size);
	m_texture_index_reader.SetIndexSize(m_texture_index_size);
	m_material_index_reader.SetIndexSize(m_material_index_size);
	m_bone_index_reader.SetIndexSize(m_bone_index_size);
	m_morph_index_reader.SetIndexSize(m_morph_index_size);
	m_rigidbody_index_reader.SetIndexSize(m_rigidbody_index_size);
}

Bool PMXModelInfoData::ReadFromFile(BaseFile* file)
{
	if (!file->ReadFloat32(&version))
		return FALSE;
	Char globals_count;                            
	if (!file->ReadChar(&globals_count))
		return FALSE;      
	if (globals_count != 8)
	{
		DebugStop("PMX file corruption!"_s);
		return FALSE;
	}
	if (!file->ReadChar(&m_text_encoding))
		return FALSE;
	if (!file->ReadChar(&additional_Vector4d32_count))
		return FALSE;
	if (!file->ReadChar(&m_vertex_index_size))
		return FALSE;
	if (!file->ReadChar(&m_texture_index_size))
		return FALSE;
	if (!file->ReadChar(&m_material_index_size))
		return FALSE;
	if (!file->ReadChar(&m_bone_index_size))
		return FALSE;
	if (!file->ReadChar(&m_morph_index_size))
		return FALSE;
	if (!file->ReadChar(&m_rigidbody_index_size))
		return FALSE;
	InitReader();
	if (!m_text_reader(file, model_name_local))
		return FALSE;
	if (!m_text_reader(file, model_name_universal))
		return FALSE;
	if (!m_text_reader(file, comments_local))
		return FALSE;
	if (!m_text_reader(file, comments_universal))
		return FALSE;
	return TRUE;
}

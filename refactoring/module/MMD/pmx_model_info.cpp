/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & Walter White & CMT contributors.
Author:			Aimidi
Date:			2022/8/14
File:			pmx_model_info.cpp
Description:	pmx model information data

**************************************************************************/

#include "pch.h"
#include "module/MMD/pmx_model_info.h"

void PMXModelInfo::InitReader()
{
	m_text_reader.SetTextEncoding(m_text_encoding);
	m_vertex_index_reader.SetIndexSize(m_vertex_index_size);
	m_texture_index_reader.SetIndexSize(m_texture_index_size);
	m_material_index_reader.SetIndexSize(m_material_index_size);
	m_bone_index_reader.SetIndexSize(m_bone_index_size);
	m_morph_index_reader.SetIndexSize(m_morph_index_size);
	m_rigidbody_index_reader.SetIndexSize(m_rigidbody_index_size);
}

void PMXModelInfo::Init(const Char& text_encoding,
	const Char& vertex_index_size,
	const Char& texture_index_size,
	const Char& material_index_size,
	const Char& bone_index_size,
	const Char& morph_index_size,
	const Char& rigidbody_index_size)
{
	m_text_encoding = text_encoding;
	m_vertex_index_size = vertex_index_size;
	m_texture_index_size = texture_index_size;
	m_material_index_size = material_index_size;
	m_bone_index_size = bone_index_size;
	m_morph_index_size = morph_index_size;
	m_rigidbody_index_size = rigidbody_index_size;
	InitReader();
}

Bool PMXModelInfo::ReadFromFile(BaseFile* file)
{
	if (!file->ReadFloat32(&version))
		return FALSE;
	Char globals_count;                            
	if (!file->ReadChar(&globals_count))
		return FALSE;      
	if (globals_count != 8)
	{
		ApplicationOutput("PMXModelInfo::LoadFromFile() error at read global info count"_s);
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

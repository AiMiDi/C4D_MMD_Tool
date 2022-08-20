/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & Walter White & CMT contributors.
Author:			Aimidi
Date:			2022/8/14
File:			pmx_model_info_data.h
Description:	pmx model information data

**************************************************************************/

#ifndef _PMX_MODEL_INFO_DATA_H_
#define _PMX_MODEL_INFO_DATA_H_

#include "pch.h"
#include "mmd_base.hpp"
#include "utils/pmx_util.hpp"

/**
 * \brief PMX model global information struct
 */
class PMXModelInfoData final : public MMDDataBase
{
	// String encoding. 0 is UTF16LE encoding and 1 is UTF8 encoding
	Char	m_text_encoding = 0;
	// Vertex index size
	Char	m_vertex_index_size = 4;
	// Texture index size
	Char	m_texture_index_size = 2;
	// Material index size 
	Char	m_material_index_size = 2;
	// Bone index size
	Char	m_bone_index_size = 2;
	// Morph index size 
	Char	m_morph_index_size = 2;
	// Rigid-body index size 
	Char	m_rigidbody_index_size = 2;
public:
	PMXTextReader	m_text_reader{};
	PMXUIndexReader	m_vertex_index_reader{};
	PMXIndexReader	m_texture_index_reader{};
	PMXIndexReader	m_material_index_reader{};
	PMXIndexReader	m_bone_index_reader{};
	PMXIndexReader	m_morph_index_reader{};
	PMXIndexReader	m_rigidbody_index_reader{};

	// version
	Float32 version = 2.0f;
	// Additional Vector4d32 numbers
	Char	additional_Vector4d32_count = 0;
	// Local model name 
	String	model_name_local;
	// Generic model name 
	String	model_name_universal;
	// Local language model description 
	String	comments_local;
	// Common language model description
	String	comments_universal;
	// Is there a UV morph  
	Bool	have_UV_morph = false;
	// Is there a vertex morph 
	Bool	have_vertex_morph = false;

	explicit PMXModelInfoData(
		const Char text_encoding = 0,
		const Char vertex_index_size = 4,
		const Char texture_index_size = 2,
		const Char material_index_size = 2,
		const Char bone_index_size = 2,
		const Char morph_index_size = 2,
		const Char rigidbody_index_size = 2) :
	m_text_encoding(text_encoding),
	m_vertex_index_size(vertex_index_size),
	m_texture_index_size(texture_index_size),
	m_material_index_size(material_index_size),
	m_bone_index_size(bone_index_size),
	m_morph_index_size(morph_index_size),
	m_rigidbody_index_size(rigidbody_index_size)
	{
		InitReader();
	}
	void InitReader();
	Bool ReadFromFile(BaseFile* file) override;
};

#endif // !_PMX_MODEL_INFO_DATA_H_

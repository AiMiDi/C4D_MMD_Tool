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
#include "pmx_reader.hpp"

/**
 * \brief PMX model global information struct
 */
class PMXModelInfoData final : public MMDDataBase
{
	// String encoding. 0 is UTF16LE encoding and 1 is UTF8 encoding
	Char	text_encoding = 0;
	// Vertex index size
	Char	vertex_index_size = 0;
	//  Texture index size
	Char	texture_index_size = 0;
	// Material index size 
	Char	material_index_size = 0;
	// Bone index size 
	Char	bone_index_size = 0;
	// Morph index size 
	Char	morph_index_size = 0;
	// Rigid-body index size 
	Char	rigidbody_index_size = 0;
public:
	PMXTextReader m_text_reader;
	PMXUIndexReader m_vertex_index_reader;
	PMXIndexReader m_texture_index_reader;
	PMXIndexReader m_material_index_reader;
	PMXIndexReader m_bone_index_reader;
	PMXIndexReader m_morph_index_reader;
	PMXIndexReader m_rigidbody_index_reader;

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

	void InitReader();

	Bool ReadFromFile(BaseFile* file) override;
};

#endif // !_PMX_MODEL_INFO_DATA_H_

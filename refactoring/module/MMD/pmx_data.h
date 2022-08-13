/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & Walter White & CMT contributors.
Author:			Aimidi
Date:			2022/7/2
File:			pmx_data.h
Description:	pmx file data

**************************************************************************/

#ifndef _PMX_DATA_H_
#define _PMX_DATA_H_

#include "pch.h"

/* PMX model global information struct. */
struct PMXModelInformation
{
	// version
	Float32 version = 2.0f;
	// String encoding. 0 is UTF16LE encoding and 1 is UTF8 encoding
	Char	text_encoding = 0;
	// Additional Vector4d32 numbers
	Char	additional_Vector4d32_count = 0;
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
};

struct PMXDataCount
{
	Int32 vertex_data_count = 0;
	Int32 surface_data_count = 0;
	Int32 texture_data_count = 0;
	Int32 material_data_count = 0;
	Int32 bone_data_count = 0;
	Int32 morph_data_count = 0;
	Int32 display_data_count = 0;
	Int32 rigid_body_data_count = 0;
	Int32 joint_data_count = 0;
};


#endif // !_PMX_DATA_H_

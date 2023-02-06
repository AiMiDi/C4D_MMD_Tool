/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & Walter White & CMT contributors.
Author:			Aimidi
Date:			2022/8/14
File:			pmx_model_info.h
Description:	pmx model information data

**************************************************************************/

#ifndef _PMX_MODEL_INFO_H_
#define _PMX_MODEL_INFO_H_

#include "pch.h"
#include "mmd_element.hpp"
#include "utils/pmx_util.hpp"

struct PMXModelInfoData
{
	// String encoding. 0 is UTF16LE encoding and 1 is UTF8 encoding
	Char	text_encoding = 0;
	// Vertex index size
	Char	vertex_index_size = 4;
	// Texture index size
	Char	texture_index_size = 2;
	// Material index size 
	Char	material_index_size = 2;
	// Bone index size
	Char	bone_index_size = 2;
	// Morph index size 
	Char	morph_index_size = 2;
	// Rigid-body index size 
	Char	rigidbody_index_size = 2;

	// version
	Float32 version = 2.0f;
	// Additional Vector4d32 numbers
	Char	additional_vec4_count = 1;
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

	PMXModelInfoData(String model_name_local = {}, String model_name_universal = {}, String	comments_local = {}, String	comments_universal = {}):
		model_name_local(std::move(model_name_local)), model_name_universal(std::move(model_name_universal)), comments_local(std::move(comments_local)), comments_universal(std::move(comments_universal)) {}
};

/**
 * \brief PMX model global information struct
 */
class PMXModelInfo final : public MMDElement
{
	GENERATE_MMD_CLASS_BODY(PMXModelInfo, PMXModelInfoData)
public:
	PMXTextReader	m_text_reader{};
	PMXUIndexReader	m_vertex_index_reader{};
	PMXIndexReader	m_texture_index_reader{};
	PMXIndexReader	m_material_index_reader{};
	PMXIndexReader	m_bone_index_reader{};
	PMXIndexReader	m_morph_index_reader{};
	PMXIndexReader	m_rigidbody_index_reader{};

	/**
	 * \brief Default constructor function
	 */
	explicit PMXModelInfo(std::unique_ptr<PMXModelInfoData> data = std::make_unique<PMXModelInfoData>()) : m_data(std::move(data)){}
	/**
	 * \brief Constructor function
	 */
	explicit PMXModelInfo(String model_name_local, String model_name_universal, String comments_local, String comments_universal) :
		m_data(std::make_unique<PMXModelInfoData>(std::move(model_name_local), std::move(model_name_universal), std::move(comments_local), std::move(comments_universal))) {}
	/**
	* \brief Destructor function
	*/
	~PMXModelInfo() override = default;

	void ResetReader();
	/**
	 * \brief Read PMX model info data from a pmx file
	 * \param file file pmx file
	 * \return Successful TRUE, other FALSE.
	 */
	Bool ReadFromFile(BaseFile* file) override;
};

#endif // !_PMX_MODEL_INFO_H_

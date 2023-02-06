/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & Walter White & CMT contributors.
Author:			Aimidi
Date:			2022/10/2
File:			pmx_texture.h
Description:	pmx texture data

**************************************************************************/

#ifndef _PMX_TEXTURE_H_
#define _PMX_TEXTURE_H_

#include "pmx_element.hpp"

struct PMXTextureData
{
	String path;

	explicit PMXTextureData(String path_ = {}) : path(std::move(path_)) {}
};

class PMXTexture final : public PMXElement
{
	GENERATE_MMD_CLASS_BODY(PMXTexture, PMXTextureData)
public:
	/**
	 * \brief Default constructor function
	 */
	explicit PMXTexture(const PMXModelInfo* model_info) : PMXElement(model_info), m_data(std::make_unique<data_type>()) {}
	/**
	 * \brief Destructor function
	 */
	~PMXTexture() override = default;
	/**
	 * \brief Read PMX texture data from a pmx file
	 * \param file file pmx file
	 * \return Successful TRUE, other FALSE.
	 */
	Bool ReadFromFile(BaseFile* file) override;
};

#endif // !PMX_TEXTURE_H

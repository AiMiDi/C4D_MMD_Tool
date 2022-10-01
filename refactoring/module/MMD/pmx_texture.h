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
	 * \brief Move constructor
	 */
	PMXTexture(PMXTexture&& src) noexcept = default;
	/**
	 * \brief Move operator=
	 * \return Result reference
	 */
	PMXTexture& operator =(PMXTexture&& src) noexcept = default;
	MAXON_DISALLOW_COPY_AND_ASSIGN(PMXTexture)
public:
	Bool ReadFromFile(BaseFile* file) override;
private:
	using data_type = PMXTextureData;
	std::unique_ptr<data_type> m_data;
};

#endif // !PMX_TEXTURE_H

/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & Walter White & CMT contributors.
Author:			Aimidi
Date:			2022/8/13
File:			pmx_vertex.h
Description:	pmx vertex data

**************************************************************************/

#ifndef _PMX_VERTEX_H_
#define _PMX_VERTEX_H_

#include "pmx_element.hpp"
#include "pmx_model_info.h"
#include "pmx_weight.h"

struct PMXVertexData
{
	// The position
	Vector32 position{};
	// The normal vector
	Vector32 normal{};
	// The UV coordinates. 
	maxon::Vector2d32 UV{};          
	// Skip the extra Vector4d32[N]  16*N
	enum
	{
		DEFAULT = -1,
		BDEF1,
		BDEF2,
		BDEF4,
		SDEF,
		QDEF
	};
	// Variant weight type, 0=BDEF1, 1=BDEF2, 2=BDEF4, 3=SDEF, 4=QDEF
	Char weight_deform_type = DEFAULT;
	// Variant weight 
	std::unique_ptr<PMXWeight> weight_deform{nullptr};
	// Edge magnification 
	Float32 edge_scale = 0.f;
};

class PMXVertex final : public PMXElement
{
	GENERATE_MMD_CLASS_BODY(PMXVertex, PMXVertexData)
public:
	/**
	 * \brief Default constructor function
	 */
	explicit PMXVertex(const PMXModelInfo* model_info) : PMXElement(model_info), m_data(std::make_unique<data_type>())  {}
	/**
	 * \brief Destructor function
	 */
	~PMXVertex() override = default;
	/**
	 * \brief Read PMX vertex data from a pmx file
	 * \param file file pmx file
	 * \return Successful TRUE, other FALSE.
	 */
	Bool ReadFromFile(BaseFile* file) override;
};

#endif // !PMX_VERTEX


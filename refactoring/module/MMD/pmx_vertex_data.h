/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & Walter White & CMT contributors.
Author:			Aimidi
Date:			2022/8/13
File:			pmx_vertex_data.h
Description:	pmx vertex data

**************************************************************************/
#ifndef _PMX_VERTEX_DATA_H_
#define _PMX_VERTEX_DATA_H_

#include "mmd_base.hpp"
#include "pmx_model_info_data.h"
#include "pmx_weight.h"

class PMXVertexData final : public MMDDataBase
{
	// The position
	Vector32 m_position{};
	// The normal vector
	Vector32 m_normal{};
	// The UV coordinates. 
	maxon::Vector2d32 m_UV{};          
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
	Char m_weight_deform_type = DEFAULT;
	// Variant weight 
	std::unique_ptr<PMXWeight> m_weight_deform{nullptr};
	// Edge magnification 
	Float32 m_edge_scale = 0.f;
	const PMXModelInfoData& m_model_info;
public:
	explicit PMXVertexData(const PMXModelInfoData& model_info) :m_model_info(model_info) {}
	~PMXVertexData() override = default;
	Bool ReadFromFile(BaseFile* file) override;
};
#endif // !PMX_VERTEX_DATA


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

class PMXVertex final : public MMDDataBase
{
public:
	explicit PMXVertex(const PMXModelInfoData& model_info) :m_model_info(model_info) {}
	~PMXVertex() override = default;
	MAXON_DISALLOW_COPY_AND_ASSIGN(PMXVertex)
public:
	Bool ReadFromFile(BaseFile* file) override;
private:
	using data_type = PMXVertexData;
	std::unique_ptr<data_type> m_data;
	const PMXModelInfoData& m_model_info;
};
#endif // !PMX_VERTEX_DATA


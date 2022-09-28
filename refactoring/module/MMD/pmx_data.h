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

#include "pmx_bone.h"
#include "pmx_display.h"
#include "pmx_joint.h"
#include "pmx_material.h"
#include "pmx_model_info.h"
#include "pmx_morph.h"
#include "pmx_rigid_body.h"
#include "pmx_vertex.h"

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

struct PMXData
{
	// 模型信息 
	PMXModelInfo model_info;
	// 顶点数据 
	MMDElementArray<PMXVertex>		vertex_data;
	// 面数据  
	maxon::BaseArray<CPolygon>		surface_data;
	// 贴图数据 
	maxon::BaseArray<String>		texture_data;
	// 材质数据 
	MMDElementArray<PMXMaterial>	material_data;
	// 骨骼数据 
	MMDElementArray<PMXBone>		bone_data;
	// 变形数据 
	MMDElementArray<PMXMorph>		morph_data;
	// 表示枠数据
	MMDElementArray<PMXDisplay>	display_data;
	// 刚体数据 
	MMDElementArray<PMXRigidBody>	rigid_body_data;
	// J点数据  
	MMDElementArray<PMXJoint>		joint_data;
};

#endif // !_PMX_DATA_H_

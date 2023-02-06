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
#include "pmx_polygon.h"
#include "pmx_rigid_body.h"
#include "pmx_texture.h"
#include "pmx_vertex.h"

struct PMXData
{
	// 模型信息 
	PMXModelInfo model_info;
	// 顶点数据 
	PMXElementArray<PMXVertex>			vertex_data{ &model_info };
	// 面数据  
	PMXElementArray<PMXPolygon>			surface_data{ &model_info };
	// 贴图数据 
	PMXElementArray<PMXTexture>			texture_data{ &model_info };
	// 材质数据 
	PMXElementArray<PMXMaterial>		material_data{ &model_info };
	// 骨骼数据 
	PMXElementArray<PMXBone>			bone_data{ &model_info };
	// 变形数据 
	PMXElementArray<PMXMorph>			morph_data{ &model_info };
	// 表示枠数据
	PMXElementArray<PMXDisplay>			display_data{ &model_info };
	// 刚体数据 
	PMXElementArray<PMXRigidBody>		rigid_body_data{ &model_info };
	// J点数据  
	PMXElementArray<PMXJoint>			joint_data{ &model_info };

	explicit PMXData(String model_name_local = {}, String model_name_universal = {}, String	comments_local = {}, String	comments_universal = {}) :
	model_info(std::move(model_name_local), std::move(model_name_universal), std::move(comments_local), std::move(comments_universal)){}
};

class PMX
{
	GENERATE_MMD_CLASS_BODY(PMX, PMXData)
public:
	/**
	 * \brief  Constructor function
	 */
	explicit PMX(String model_name_local = {}, String model_name_universal = {});
	/**
	 * \brief Destructor function
	 */
	~PMX() = default;
	/**
	 * \brief Read from a vmd file
	 * \param fn Optionally, passing in an empty file name allows the user to choose otherwise use the passed file name.
	 * \return Successful TRUE, other FALSE.
	 */
	Bool LoadFromFile(Filename& fn);
	/**
	 * \brief Write to vmd file
	 * \param fn Optionally, passing in an empty file name allows the user to choose otherwise use the passed file name.
	 * \return Successful TRUE, other FALSE.
	 */
	// TODO: Bool SaveToFile(Filename& fn) const;
};

#endif // !_PMX_DATA_H_

/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & Walter White & CMT contributors.
Author:			Aimidi
Date:			2022/9/14
File:			pmx_material.h
Description:	pmx material data

**************************************************************************/

#ifndef _PMX_MATERIAL_H_
#define _PMX_MATERIAL_H_

#include "pmx_element.hpp"
#include "pmx_model_info.h"

/* Material symbol(1 byte) */
struct PMXMaterialFlags
{
	// Double sided depiction 
	Bool	no_cull : 1;
	// Cast shadows on geometry 
	Bool	ground_shadow : 1;
	// Render to shadow map（本影标示）
	Bool	draw_shadow : 1;
	// Accept shadows from shadow maps（本影）
	Bool	Receive_shadow : 1;
	// Edge depiction（轮廓线有效） 
	Bool	has_edge : 1;
	// Use additional vector4d32 as the color of the vertices 
	Bool	vertex_colour : 1;
	// All three vertices are drawn 
	Bool	point_drawing : 1;
	// Three sides are drawn 
	Bool	line_drawing : 1;

	PMXMaterialFlags()
	{
		no_cull = false;
		ground_shadow = false;
		draw_shadow = false;
		Receive_shadow = false;
		has_edge = false;
		vertex_colour = false;
		point_drawing = false;
		line_drawing = false;
	}
};

struct PMXMaterialData
{
	// Local material name, Japanese, Chinese, etc 
	String				material_name_local{};
	// General material name, usually in English 
	String				material_name_universal{};
	// diffuse color RGBA 
	Vector4d32			diffuse_colour = Vector4d32(1);
	// Specular (specular) color RGB 
	Vector32			specular_colour{};
	// Specular light intensity 
	Float32				specular_strength = 5.0f;
	// Environment color, the shadow color when the light is insufficient (i.e. the base color, which makes the shadow less black) 
	Vector32			ambient_colour = Vector32(1);
	// Draw marker 
	PMXMaterialFlags	drawing_flags{};
	// Edge color RGBA 
	Vector4d32			edge_colour{ 0, 0, 0, 1 };
	// Edge scale[0, 1] 
	Float32				edge_scale = 1.f;
	// Texture index 
	Int32				texture_index = -1;
	// Environment (specular map) index for environment mapping 
	Int32				environment_index = 0;
	// Environment (specular map) blend mode, 0 = off, 1 = multiply, 2 = add, 3 = extra vector4d32 */
	Char				environment_blend_mode = 0;
	// Map reference 0 = reference texture, 1 = internal reference 
	Char				toon_reference = 0;
	// toon texture part 
	Int32				toon_part = 0;
	// toon internal index 
	Char				toon_internal = 0;
	// Metadata, used for scripts and other data. 
	String				meta_data{};
	// Number of faces, which indicates how many faces are affected by the current material. 
	Int32				surface_count = 0;


};

class PMXMaterial final : public PMXElement
{
	GENERATE_MMD_CLASS_BODY(PMXMaterial, PMXMaterialData)
public:
	/**
	 * \brief Default constructor function
	 */
	explicit PMXMaterial(const PMXModelInfo* model_info) : m_data(std::make_unique<data_type>()), PMXElement(model_info) {}
	/**
	 * \brief Destructor function
	 */
	~PMXMaterial() override = default;
	/**
	 * \brief Read PMX material data from a pmx file
	 * \param file file pmx file
	 * \return Successful TRUE, other FALSE.
	 */
	Bool ReadFromFile(BaseFile* file) override;
};

#endif // !_PMX_MATERIAL_H_

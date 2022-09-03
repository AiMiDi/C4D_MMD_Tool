#pragma once
#include "mmd_base.hpp"
#include "pmx_model_info_data.h"

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

class PMXMaterialData : public MMDDataBase
{
	const PMXModelInfoData& m_model_info;

	// Local material name, Japanese, Chinese, etc 
	String				m_material_name_local{};
	// General material name, usually in English 
	String				m_material_name_universal{};
	// diffuse color RGBA 
	Vector4d32			m_diffuse_colour = Vector4d32(1);
	// Specular (specular) color RGB 
	Vector32			m_specular_colour{};
	// Specular light intensity 
	Float32				m_specular_strength = 5.0f;
	// Environment color, the shadow color when the light is insufficient (i.e. the base color, which makes the shadow less black) 
	Vector32			m_ambient_colour = Vector32(1);
	// Draw marker 
	PMXMaterialFlags	m_drawing_flags{};
	// Edge color RGBA 
	Vector4d32			m_edge_colour{ 0, 0, 0, 1 };
	// Edge scale[0, 1] 
	Float32				m_edge_scale = 1.f;
	// Texture index 
	Int32				m_texture_index = -1;
	// Environment (specular map) index for environment mapping 
	Int32				m_environment_index = 0;
	// Environment (specular map) blend mode, 0 = off, 1 = multiply, 2 = add, 3 = extra vector4d32 */
	Char				m_environment_blend_mode = 0;
	// Map reference 0 = reference texture, 1 = internal reference 
	Char				m_toon_reference = 0;
	// toon texture part 
	Int32				m_toon_part = 0;
	// toon internal index 
	Char				m_toon_internal = 0;
	// Metadata, used for scripts and other data. 
	String				m_meta_data{};
	// Number of faces, which indicates how many faces are affected by the current material. 
	Int32				m_surface_count = 0;
public:
	explicit PMXMaterialData(const PMXModelInfoData& model_info) : m_model_info(model_info) {}

	~PMXMaterialData() override = default;

	Bool ReadFromFile(BaseFile* file) override;
};
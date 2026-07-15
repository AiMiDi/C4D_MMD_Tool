/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & CMT contributors.
Author:			Aimidi
Description:	通用 MMD 材质表情贴图系数 ShaderData 实现。

**************************************************************************/

#include "module/core/cmt_old_sdk_stl_preload.h"
#include "mmd_material_morph_shader.h"
#include "plugin_resource.h"
#include "description/Xmmdmaterialmorphshader.h"

SDK2024_Init(MMDMaterialTextureMorphShader)
{
	if (BaseContainer* const bc = static_cast<BaseList2D*>(node)->GetDataInstance())
	{
		bc->SetVector(MMDMATERIALMORPHSHADER_FACTOR_COLOR, Vector(1.0));
		bc->SetFloat(MMDMATERIALMORPHSHADER_FACTOR_ALPHA, 1.0);
	}
	m_factor_rgb = Vector(1.0);
	m_factor_alpha = 1.0;
	return true;
}

INITRENDERRESULT MMDMaterialTextureMorphShader::InitRender(BaseShader* sh, const InitRenderStruct& irs)
{
	if (sh)
	{
		if (const BaseContainer* const bc = sh->GetDataInstance())
		{
			m_factor_rgb = bc->GetVector(MMDMATERIALMORPHSHADER_FACTOR_COLOR, Vector(1.0));
			m_factor_alpha = bc->GetFloat(MMDMATERIALMORPHSHADER_FACTOR_ALPHA, 1.0);
		}
		// 初始化被包装的 child shader（render-time 快照，不修改场景状态）。
		if (BaseShader* const child = sh->GetDown())
			child->InitRender(irs);
	}
	return INITRENDERRESULT::OK;
}

void MMDMaterialTextureMorphShader::FreeRender(BaseShader* sh)
{
	if (sh)
	{
		if (BaseShader* const child = sh->GetDown())
			child->FreeRender();
	}
}

Vector MMDMaterialTextureMorphShader::Output(BaseShader* sh, ChannelData* cd)
{
	Vector sampled(1.0);
	if (sh)
	{
		if (BaseShader* const child = sh->GetDown())
			sampled = child->Sample(cd);
	}
	// 将有效贴图系数应用到采样结果（系数已由运行时 evaluator 预计算并写入参数）。
	return Vector(
		sampled.x * m_factor_rgb.x * m_factor_alpha,
		sampled.y * m_factor_rgb.y * m_factor_alpha,
		sampled.z * m_factor_rgb.z * m_factor_alpha);
}

Bool cmt_register::RegisterMMDMaterialTextureMorphShader()
{
	return RegisterShaderPlugin(g_mmd_material_texture_morph_shader_id,
		"MMD Material Texture Morph"_s, PLUGINFLAG_HIDEPLUGINMENU,
		MMDMaterialTextureMorphShader::Alloc, "Xmmdmaterialmorphshader"_s, 0);
}

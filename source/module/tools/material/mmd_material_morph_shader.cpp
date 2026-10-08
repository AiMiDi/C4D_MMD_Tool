/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & CMT contributors.
Author:			Aimidi
Description:	通用 MMD 材质表情贴图系数 ShaderData 实现。

**************************************************************************/

#include "module/core/cmt_old_sdk_stl_preload.h"
#include "mmd_material_morph_shader.h"
#include "plugin_resource.h"
#include "description/Xmmdmaterialmorphshader.h"
#include "mmd_material_morph_binding.h"
#include "module/tools/object/mmd_model_manager.h"
#include "xbitmap.h"

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
	m_child_initialized = false;
	m_output = 0;
	m_sphere_shader = nullptr;
	m_sphere_mode = 0;
	m_sphere = {};
	m_camera_inverse = Matrix();
	if (irs.vd)
	{
		if (const RayCamera* camera = irs.vd->GetRayCamera()) m_camera_inverse = camera->m_inverse;
	}
	if (sh)
	{
		if (const BaseContainer* const bc = sh->GetDataInstance())
		{
			m_factor_rgb = bc->GetVector(MMDMATERIALMORPHSHADER_FACTOR_COLOR, Vector(1.0));
			m_factor_alpha = bc->GetFloat(MMDMATERIALMORPHSHADER_FACTOR_ALPHA, 1.0);
			m_output = bc->GetInt32(MMDMATERIALMORPHSHADER_OUTPUT);
			m_sphere_mode = bc->GetInt32(MMDMATERIALMORPHSHADER_SPHERE_MODE);
			if (m_output != 0)
			{
				// Links are translated with the shader into the render document.
				BaseDocument* const doc = const_cast<BaseDocument*>(irs.doc);
				auto* model_object = static_cast<BaseObject*>(bc->GetLink(MMDMATERIALMORPHSHADER_MODEL, doc, g_mmd_model_manager_object_id));
				auto* material = static_cast<BaseMaterial*>(bc->GetLink(MMDMATERIALMORPHSHADER_MATERIAL, doc));
				auto* model = model_object ? model_object->GetNodeData<MMDModelManagerObject>() : nullptr;
				MMDMaterialRuntimeState state;
				if (!model || !model->GetMaterialRenderState(material, irs.time, state))
					return INITRENDERRESULT::UNKNOWNERROR;
				const auto field = static_cast<mmd_material_binding::Field>(bc->GetInt32(MMDMATERIALMORPHSHADER_FIELD));
				const Bool textured = bc->GetBool(MMDMATERIALMORPHSHADER_TEXTURED);
				m_color = mmd_material_binding::Color(state, field, textured);
				m_scalar = mmd_material_binding::Scalar(state, field, textured);
				m_texture = state.texture;
				m_sphere = state.sphere_texture;
			}
			if (m_sphere_mode == 1 || m_sphere_mode == 2)
			{
				auto* sphere = static_cast<BaseShader*>(bc->GetLink(MMDMATERIALMORPHSHADER_SPHERE_SHADER,
					const_cast<BaseDocument*>(irs.doc), Xbitmap));
				if (!sphere || sphere->GetUp() != sh) return INITRENDERRESULT::UNKNOWNERROR;
				const auto result = sphere->InitRender(irs);
				if (result != INITRENDERRESULT::OK) return result;
				m_sphere_shader = sphere;
			}
		}
		// 初始化被包装的 child shader（render-time 快照，不修改场景状态）。
		if (BaseShader* const child = sh->GetDown())
		{
			const INITRENDERRESULT result = child->InitRender(irs);
			m_child_initialized = result == INITRENDERRESULT::OK;
			if (!m_child_initialized && m_sphere_shader)
			{
				m_sphere_shader->FreeRender();
				m_sphere_shader = nullptr;
			}
			return result;
		}
	}
	return INITRENDERRESULT::OK;
}

void MMDMaterialTextureMorphShader::FreeRender(BaseShader* sh)
{
	if (m_sphere_shader) m_sphere_shader->FreeRender();
	m_sphere_shader = nullptr;
	if (sh && m_child_initialized)
	{
		if (BaseShader* const child = sh->GetDown())
			child->FreeRender();
	}
	m_child_initialized = false;
}

SHADERINFO MMDMaterialTextureMorphShader::GetRenderInfo(BaseShader* sh)
{
	// In particular, ALPHA_SUPPORT lets the material request the bitmap's alpha
	// sample through TEX_ALPHA. Without it, RGB becomes an unintended opacity mask.
	BaseShader* const child = sh ? sh->GetDown() : nullptr;
	auto info = child ? child->GetRenderInfo() : SHADERINFO::NONE;
	if (sh)
	{
		auto* sphere = static_cast<BaseShader*>(sh->GetDataInstance()->GetLink(
			MMDMATERIALMORPHSHADER_SPHERE_SHADER, sh->GetDocument(), Xbitmap));
		if (sphere && sphere->GetUp() == sh) info |= sphere->GetRenderInfo();
	}
	if (sh && sh->GetDataInstance()->GetInt32(MMDMATERIALMORPHSHADER_OUTPUT) != 0)
	{
#if API_VERSION >= 2024000
		return info | SHADERINFO::TIMEDEPENDENT | SHADERINFO::ALPHA_SUPPORT;
#else
		return info | SHADERINFO::ALPHA_SUPPORT;
#endif
	}
	return info;
}

BaseShader* MMDMaterialTextureMorphShader::GetSubsurfaceShader(BaseShader* sh, Float& bestmpl)
{
	BaseShader* const child = sh ? sh->GetDown() : nullptr;
	return child ? child->GetSubsurfaceShader(bestmpl) : nullptr;
}

Vector MMDMaterialTextureMorphShader::ApplySphere(const Vector& color, ChannelData* cd) const
{
	if (!m_sphere_shader || !cd || (cd->texflag & TEX_ALPHA)) return color;
	// PMX sphere mapping uses the view-space Phong normal, independently of
	// mesh UV, light direction and reflected view ray. Transform directions only.
	const Vector normal = (m_camera_inverse.sqmat * cd->n).GetNormalized();
	ChannelData sample = *cd;
	// Bitmap V follows image rows; a positive camera-space Y samples the top.
	sample.p = Vector(0.5 + 0.5 * normal.x, 0.5 - 0.5 * normal.y, 0.0);
	// Mesh UV derivatives have no meaning in this projection. Native bitmap
	// filtering still applies; a constant footprint avoids unrelated UV seams.
	sample.d = Vector(0.0);
	sample.texflag &= ~TEX_ALPHA;
	const Vector sphere = m_sphere.Apply(m_sphere_shader->Sample(&sample));
	return m_sphere_mode == 1 ? Vector(color.x * sphere.x, color.y * sphere.y, color.z * sphere.z)
		: color + sphere;
}

Vector MMDMaterialTextureMorphShader::Output(BaseShader* sh, ChannelData* cd)
{
	if (m_output == 1) return ApplySphere(m_color, cd);
	if (m_output == 2) return Vector(m_scalar);
	if (m_output == 4)
	{
		BaseShader* child = sh ? sh->GetDown() : nullptr;
		if (!child || !cd || !(child->GetRenderInfo() & SHADERINFO::ALPHA_SUPPORT)) return Vector(m_scalar);
		ChannelData alpha = *cd;
		alpha.texflag |= TEX_ALPHA;
		return child->Sample(&alpha) * m_scalar;
	}
	Vector sampled(1.0);
	if (sh)
	{
		if (BaseShader* const child = sh->GetDown())
			sampled = child->Sample(cd);
	}
	if (m_output == 3)
	{
		if (cd && (cd->texflag & TEX_ALPHA)) return sampled;
		sampled = m_texture.Apply(sampled);
		return ApplySphere(Vector(sampled.x * m_color.x, sampled.y * m_color.y, sampled.z * m_color.z), cd);
	}
	// Alpha-capable children are sampled separately by the host. RGB tint must
	// never tint that opacity sample (e.g. a red diffuse tint is still opaque).
	if (cd && (cd->texflag & TEX_ALPHA))
		return sampled * m_factor_alpha;
	// 将有效贴图系数应用到采样结果（系数已由运行时 evaluator 预计算并写入参数）。
	return ApplySphere(Vector(
		sampled.x * m_factor_rgb.x * m_factor_alpha,
		sampled.y * m_factor_rgb.y * m_factor_alpha,
		sampled.z * m_factor_rgb.z * m_factor_alpha), cd);
}

Bool cmt_register::RegisterMMDMaterialTextureMorphShader()
{
	return RegisterShaderPlugin(g_mmd_material_texture_morph_shader_id,
		"MMD Material Texture Morph"_s, PLUGINFLAG_HIDEPLUGINMENU,
		MMDMaterialTextureMorphShader::Alloc, "Xmmdmaterialmorphshader"_s, 0);
}

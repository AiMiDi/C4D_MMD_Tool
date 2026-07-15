#include "module/core/cmt_old_sdk_stl_preload.h"
#include "mmd_standard_material.h"
#include "mmd_material.h"
#include "mmd_material_morph_shader.h"
#include "plugin_resource.h"
#include "description/Xmmdmaterialmorphshader.h"
#include "xcolor.h"
#include "xbitmap.h"

#include <cstdio>

namespace
{
Bool IsIdentityFactor(const Vector& factor, const Float factor_alpha)
{
	return factor.x == 1.0 && factor.y == 1.0 && factor.z == 1.0 && factor_alpha == 1.0;
}

Vector ComponentMultiply(const Vector& lhs, const Vector& rhs)
{
	return Vector(lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z);
}

String ResolveToonTexturePath(const libmmd::PMXMaterial& material,
	const maxon::BaseArray<Filename>& texture_paths)
{
	const Int32 toon_index = material.m_toonTextureIndex;
	if (toon_index < 0)
		return {};

	if (material.m_toonMode == libmmd::PMXToonMode::Separate)
	{
		return toon_index < texture_paths.GetCount() ? texture_paths[toon_index].GetString() : String();
	}

	if (toon_index > 9)
		return {};
	Char filename[16];
	std::snprintf(filename, sizeof(filename), "toon%02d.bmp", static_cast<int>(toon_index + 1));
	return (GeGetPluginResourcePath() + Filename("mikumikudance_data") + Filename(filename)).GetString();
}

void SetChannelTexture(Material* const material, const Int32 channel_id, const String& texture_path)
{
	if (!material || texture_path.IsEmpty())
		return;
	material->SetChannelState(channel_id, true);
	if (BaseChannel* const channel = material->GetChannel(channel_id))
	{
		BaseContainer data = channel->GetData();
		data.SetString(BASECHANNEL_TEXTURE, texture_path);
		channel->SetData(data);
	}
}

BaseShader* GetMaterialShader(Material* const material, BaseDocument* const doc, const Int32 shader_param_id)
{
	if (!material)
		return nullptr;
	GeData gd;
	if (!GetAtomParameter(material, CreateDescID(DescLevel(shader_param_id)), gd, DESCFLAGS_GET::NONE))
		return nullptr;
	return static_cast<BaseShader*>(gd.GetLink(doc));
}

void SetChannelTextureIfUnwrapped(Material* const material, BaseDocument* const doc,
	const Int32 channel_id, const Int32 shader_param_id, const String& texture_path)
{
	BaseShader* const shader = GetMaterialShader(material, doc, shader_param_id);
	if (shader && shader->IsInstanceOf(g_mmd_material_texture_morph_shader_id))
		return;
	SetChannelTexture(material, channel_id, texture_path);
}

void SetTextureMorphShaderFactor(BaseShader* const shader, const Vector& factor, const Float factor_alpha)
{
	if (!shader)
		return;
	shader->SetParameter(ConstDescID(DescLevel(MMDMATERIALMORPHSHADER_FACTOR_COLOR)), factor, DESCFLAGS_SET::NONE);
	shader->SetParameter(ConstDescID(DescLevel(MMDMATERIALMORPHSHADER_FACTOR_ALPHA)), factor_alpha, DESCFLAGS_SET::NONE);
}

void SyncTextureMorphChannel(Material* const material, BaseDocument* const doc, const Int32 channel_id,
	const Int32 shader_param_id, const Vector& factor, const Float factor_alpha)
{
	if (!material)
		return;
	BaseChannel* const channel = material->GetChannel(channel_id);
	if (!channel)
		return;

	BaseShader* current_shader = GetMaterialShader(material, doc, shader_param_id);
	if (current_shader && current_shader->IsInstanceOf(g_mmd_material_texture_morph_shader_id))
	{
		SetTextureMorphShaderFactor(current_shader, factor, factor_alpha);
		return;
	}
	// Pure-color channels are updated directly by SyncTo(). Wrapping Xcolor would
	// apply diffuse/alpha twice and would incorrectly make texture factors affect
	// a material that has no texture sample.
	if (current_shader && current_shader->IsInstanceOf(Xcolor))
		return;

	if (IsIdentityFactor(factor, factor_alpha))
		return;

	BaseContainer channel_data = channel->GetData();
	const String tex_path = channel_data.GetString(BASECHANNEL_TEXTURE);

	BaseShader* child = current_shader;
	Bool child_is_new = false;
	if (!child)
	{
		if (tex_path.IsEmpty())
			return;
		child = BaseShader::Alloc(Xbitmap);
		if (!child)
			return;
		child->SetParameter(ConstDescID(DescLevel(BITMAPSHADER_FILENAME)), Filename(tex_path), DESCFLAGS_SET::NONE);
		child_is_new = true;
	}

	BaseShader* const wrapper = BaseShader::Alloc(g_mmd_material_texture_morph_shader_id);
	if (!wrapper)
	{
		if (child_is_new)
			BaseShader::Free(child);
		return;
	}
	SetTextureMorphShaderFactor(wrapper, factor, factor_alpha);

	if (!child_is_new)
		child->Remove();

	material->InsertShader(wrapper);
	child->InsertUnder(wrapper);
	material->SetParameter(CreateDescID(DescLevel(shader_param_id)), wrapper, DESCFLAGS_SET::NONE);
	material->SetChannelState(channel_id, true);

	if (child_is_new && tex_path.IsPopulated())
	{
		channel_data.SetString(BASECHANNEL_TEXTURE, ""_s);
		channel->SetData(channel_data);
	}
}

}

BaseMaterial* MMDStandardMaterialAdapter::CreateFromPMX(const libmmd::PMXMaterial& pmx_material,
	const maxon::BaseArray<Filename>& texture_paths, const maxon::String& material_name)
{
	const auto tex_info = MMDMaterialAdapter::DetectTextureFromPMX(pmx_material, texture_paths);
	const bool has_texture = tex_info.has_texture;
	const bool has_alpha_channel = tex_info.has_alpha;
	const auto texture_index = pmx_material.m_textureIndex;

	Material* material = Material::Alloc();
	if (!material)
		return nullptr;
	BaseMaterial* base_material = material;

	const auto& color = pmx_material.m_diffuse;
	if (has_texture)
	{
		BaseChannel* base_color_channel = material->GetChannel(CHANNEL_COLOR);
		if (base_color_channel)
		{
			BaseContainer base_color_container = base_color_channel->GetData();
			base_color_container.SetString(BASECHANNEL_TEXTURE, texture_paths[texture_index].GetString());
			base_color_channel->SetData(base_color_container);
		}
	}
	else
	{
		BaseShader* base_color_shader = BaseShader::Alloc(Xcolor);
		if (base_color_shader)
		{
			base_color_shader->SetParameter(ConstDescID(DescLevel(COLORSHADER_COLOR)), Vector(color[0], color[1], color[2]), DESCFLAGS_SET::NONE);
			material->SetParameter(ConstDescID(DescLevel(MATERIAL_COLOR_SHADER)), base_color_shader, DESCFLAGS_SET::NONE);
			material->InsertShader(base_color_shader);
		}
	}

	material->SetChannelState(CHANNEL_ALPHA, true);
	BaseChannel* alpha_channel = material->GetChannel(CHANNEL_ALPHA);
	if (alpha_channel)
	{
		if (has_alpha_channel)
		{
			BaseContainer alpha_container = alpha_channel->GetData();
			alpha_container.SetString(BASECHANNEL_TEXTURE, texture_paths[texture_index].GetString());
			alpha_channel->SetData(alpha_container);
		}
		else
		{
			BaseShader* alpha_shader = BaseShader::Alloc(Xcolor);
			if (alpha_shader)
			{
				alpha_shader->SetParameter(ConstDescID(DescLevel(COLORSHADER_COLOR)), Vector(1, 1, 1), DESCFLAGS_SET::NONE);
				alpha_shader->SetParameter(ConstDescID(DescLevel(COLORSHADER_BRIGHTNESS)), color[3], DESCFLAGS_SET::NONE);
				material->SetParameter(ConstDescID(DescLevel(MATERIAL_ALPHA_SHADER)), alpha_shader, DESCFLAGS_SET::NONE);
				material->InsertShader(alpha_shader);
			}
		}
	}

	const auto sphere_index = pmx_material.m_sphereTextureIndex;
	if (pmx_material.m_sphereMode != libmmd::PMXSphereMode::None
		&& sphere_index >= 0 && sphere_index < texture_paths.GetCount())
	{
		SetChannelTexture(material, CHANNEL_ENVIRONMENT, texture_paths[sphere_index].GetString());
	}
	SetChannelTexture(material, CHANNEL_LUMINANCE, ResolveToonTexturePath(pmx_material, texture_paths));

	base_material->SetName(material_name);
	return base_material;
}

BaseMaterial* MMDStandardMaterialAdapter::CreateFromData(const MMDMaterialData& data)
{
	Material* material = Material::Alloc();
	if (!material)
		return nullptr;

	const auto tex_info = MMDMaterialAdapter::DetectTextureFromData(data);
	const bool has_texture = tex_info.has_texture;
	const bool has_alpha_channel = tex_info.has_alpha;
	const Filename texture_path(data.texture_path);

	if (has_texture)
	{
		BaseChannel* base_color_channel = material->GetChannel(CHANNEL_COLOR);
		if (base_color_channel)
		{
			BaseContainer base_color_container = base_color_channel->GetData();
			base_color_container.SetString(BASECHANNEL_TEXTURE, texture_path.GetString());
			base_color_channel->SetData(base_color_container);
		}
	}
	else
	{
		BaseShader* color_shader = BaseShader::Alloc(Xcolor);
		if (color_shader)
		{
			color_shader->SetParameter(ConstDescID(DescLevel(COLORSHADER_COLOR)), data.diffuse_rgb, DESCFLAGS_SET::NONE);
			material->SetParameter(ConstDescID(DescLevel(MATERIAL_COLOR_SHADER)), color_shader, DESCFLAGS_SET::NONE);
			material->InsertShader(color_shader);
		}
	}

	material->SetChannelState(CHANNEL_ALPHA, true);
	BaseChannel* alpha_channel = material->GetChannel(CHANNEL_ALPHA);
	if (alpha_channel)
	{
		if (has_alpha_channel)
		{
			BaseContainer alpha_container = alpha_channel->GetData();
			alpha_container.SetString(BASECHANNEL_TEXTURE, texture_path.GetString());
			alpha_channel->SetData(alpha_container);
		}
		else
		{
			BaseShader* alpha_shader = BaseShader::Alloc(Xcolor);
			if (alpha_shader)
			{
				alpha_shader->SetParameter(ConstDescID(DescLevel(COLORSHADER_COLOR)), Vector(1, 1, 1), DESCFLAGS_SET::NONE);
				alpha_shader->SetParameter(ConstDescID(DescLevel(COLORSHADER_BRIGHTNESS)), data.diffuse_alpha, DESCFLAGS_SET::NONE);
				material->SetParameter(ConstDescID(DescLevel(MATERIAL_ALPHA_SHADER)), alpha_shader, DESCFLAGS_SET::NONE);
				material->InsertShader(alpha_shader);
			}
		}
	}

	material->SetChannelState(CHANNEL_SPECULAR, true);
	material->SetParameter(ConstDescID(DescLevel(MATERIAL_SPECULAR_COLOR)), data.specular, DESCFLAGS_SET::NONE);
	Float specular_width = maxon::Clamp01(data.specular_power / 100.0);
	material->SetParameter(ConstDescID(DescLevel(MATERIAL_SPECULAR_WIDTH)), specular_width, DESCFLAGS_SET::NONE);

	material->SetChannelState(CHANNEL_ENVIRONMENT, true);
	material->SetParameter(ConstDescID(DescLevel(MATERIAL_ENVIRONMENT_COLOR)), data.ambient, DESCFLAGS_SET::NONE);
	SetChannelTexture(material, CHANNEL_ENVIRONMENT, data.sphere_texture_path);
	SetChannelTexture(material, CHANNEL_LUMINANCE, data.toon_texture_path);

	material->SetName(data.name_local);
	return material;
}

void MMDStandardMaterialAdapter::SyncTo(const MMDMaterialData& data, BaseMaterial* material)
{
	if (!material || !material->IsInstanceOf(Mmaterial))
		return;
	Material* mat = static_cast<Material*>(material);
	mat->SetName(data.name_local);
	BaseDocument* doc = mat->GetDocument();
	BaseChannel* color_ch = mat->GetChannel(CHANNEL_COLOR);
	if (color_ch)
	{
		BaseContainer bc = color_ch->GetData();
		if (bc.GetString(BASECHANNEL_TEXTURE).IsEmpty())
		{
			GeData gd;
			if (GetAtomParameter(mat, ConstDescID(DescLevel(MATERIAL_COLOR_SHADER)), gd, DESCFLAGS_GET::NONE))
			{
				BaseShader* sh = static_cast<BaseShader*>(gd.GetLink(doc));
				if (sh && sh->IsInstanceOf(Xcolor))
					sh->SetParameter(ConstDescID(DescLevel(COLORSHADER_COLOR)), data.diffuse_rgb, DESCFLAGS_SET::NONE);
			}
		}
	}
	BaseChannel* alpha_ch = mat->GetChannel(CHANNEL_ALPHA);
	if (alpha_ch)
	{
		BaseContainer ac = alpha_ch->GetData();
		if (ac.GetString(BASECHANNEL_TEXTURE).IsEmpty())
		{
			GeData gd;
			if (GetAtomParameter(mat, ConstDescID(DescLevel(MATERIAL_ALPHA_SHADER)), gd, DESCFLAGS_GET::NONE))
			{
				BaseShader* ash = static_cast<BaseShader*>(gd.GetLink(doc));
				if (ash && ash->IsInstanceOf(Xcolor))
					ash->SetParameter(ConstDescID(DescLevel(COLORSHADER_BRIGHTNESS)), data.diffuse_alpha, DESCFLAGS_SET::NONE);
			}
		}
	}
	mat->SetChannelState(CHANNEL_SPECULAR, true);
	mat->SetParameter(ConstDescID(DescLevel(MATERIAL_SPECULAR_COLOR)), data.specular, DESCFLAGS_SET::NONE);
	Float specular_width = maxon::Clamp01(data.specular_power / 100.0);
	mat->SetParameter(ConstDescID(DescLevel(MATERIAL_SPECULAR_WIDTH)), specular_width, DESCFLAGS_SET::NONE);

	mat->SetChannelState(CHANNEL_ENVIRONMENT, true);
	mat->SetParameter(ConstDescID(DescLevel(MATERIAL_ENVIRONMENT_COLOR)), data.ambient, DESCFLAGS_SET::NONE);
	SetChannelTextureIfUnwrapped(mat, doc, CHANNEL_ENVIRONMENT, MATERIAL_ENVIRONMENT_SHADER, data.sphere_texture_path);
	SetChannelTextureIfUnwrapped(mat, doc, CHANNEL_LUMINANCE, MATERIAL_LUMINANCE_SHADER, data.toon_texture_path);
}

void MMDStandardMaterialAdapter::ReadFrom(const BaseMaterial* material, MMDMaterialData& data)
{
	if (!material || !material->IsInstanceOf(Mmaterial))
		return;
	Material* mat = const_cast<Material*>(static_cast<const Material*>(material));
	data.name_local = mat->GetName();
	BaseDocument* doc = mat->GetDocument();
	BaseChannel* color_ch = mat->GetChannel(CHANNEL_COLOR);
	if (color_ch)
	{
		BaseContainer bc = color_ch->GetData();
		String tex_path = bc.GetString(BASECHANNEL_TEXTURE);
		if (tex_path.IsPopulated())
		{
			data.texture_path = tex_path;
		}
		else
		{
			GeData gd;
			if (GetAtomParameter(mat, ConstDescID(DescLevel(MATERIAL_COLOR_SHADER)), gd, DESCFLAGS_GET::NONE))
			{
				BaseShader* sh = static_cast<BaseShader*>(gd.GetLink(doc));
				if (sh && sh->IsInstanceOf(Xcolor))
				{
					GeData color_data;
					if (GetAtomParameter(sh, ConstDescID(DescLevel(COLORSHADER_COLOR)), color_data, DESCFLAGS_GET::NONE))
						data.diffuse_rgb = color_data.GetVector();
				}
			}
		}
	}
	BaseChannel* alpha_ch = mat->GetChannel(CHANNEL_ALPHA);
	if (alpha_ch)
	{
		BaseContainer ac = alpha_ch->GetData();
		if (ac.GetString(BASECHANNEL_TEXTURE).IsEmpty())
		{
			GeData gd;
			if (GetAtomParameter(mat, ConstDescID(DescLevel(MATERIAL_ALPHA_SHADER)), gd, DESCFLAGS_GET::NONE))
			{
				BaseShader* ash = static_cast<BaseShader*>(gd.GetLink(doc));
				if (ash && ash->IsInstanceOf(Xcolor))
				{
					GeData brightness_data;
					if (GetAtomParameter(ash, ConstDescID(DescLevel(COLORSHADER_BRIGHTNESS)), brightness_data, DESCFLAGS_GET::NONE))
						data.diffuse_alpha = brightness_data.GetFloat();
				}
			}
		}
	}
	GeData spec_color;
	if (GetAtomParameter(mat, ConstDescID(DescLevel(MATERIAL_SPECULAR_COLOR)), spec_color, DESCFLAGS_GET::NONE))
		data.specular = spec_color.GetVector();
	GeData spec_width;
	if (GetAtomParameter(mat, ConstDescID(DescLevel(MATERIAL_SPECULAR_WIDTH)), spec_width, DESCFLAGS_GET::NONE))
		data.specular_power = spec_width.GetFloat() * 100.0;
	GeData amb_color;
	if (GetAtomParameter(mat, ConstDescID(DescLevel(MATERIAL_ENVIRONMENT_COLOR)), amb_color, DESCFLAGS_GET::NONE))
		data.ambient = amb_color.GetVector();
}

void MMDStandardMaterialAdapter::SyncRuntimeState(const MMDMaterialRuntimeState& state, BaseMaterial* material)
{
	if (!material || !material->IsInstanceOf(Mmaterial))
		return;
	Material* const mat = static_cast<Material*>(material);
	BaseDocument* const doc = mat->GetDocument();

	// PMX textured materials are shaded by both the effective diffuse value and
	// the effective texture factor. Pure Xcolor channels are handled by SyncTo().
	SyncTextureMorphChannel(mat, doc, CHANNEL_COLOR, MATERIAL_COLOR_SHADER,
		ComponentMultiply(state.diffuse_rgb, state.texture_factor_rgb), 1.0);
	SyncTextureMorphChannel(mat, doc, CHANNEL_ALPHA, MATERIAL_ALPHA_SHADER,
		Vector(1.0), state.diffuse_alpha * state.texture_factor_alpha);
	SyncTextureMorphChannel(mat, doc, CHANNEL_ENVIRONMENT, MATERIAL_ENVIRONMENT_SHADER,
		state.sphere_texture_factor_rgb, state.sphere_texture_factor_alpha);
	SyncTextureMorphChannel(mat, doc, CHANNEL_LUMINANCE, MATERIAL_LUMINANCE_SHADER,
		state.toon_texture_factor_rgb, state.toon_texture_factor_alpha);
}

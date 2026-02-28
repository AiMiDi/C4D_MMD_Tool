#include "mmd_standard_material.h"
#include "mmd_material.h"
#include "xcolor.h"

BaseMaterial* CreateStandardMaterialFromPMX(const libmmd::PMXMaterial& pmx_material,
	const maxon::BaseArray<Filename>& texture_paths, const maxon::String& material_name)
{
	BaseMaterial* base_material = nullptr;
	bool has_texture = false;
	bool has_alpha_channel = false;
	const auto texture_index = pmx_material.m_textureIndex;
	if (texture_index != -1 && texture_index < texture_paths.GetCount())
	{
		const auto& texture_path = texture_paths[texture_index];
		if (GeFExist(texture_path))
		{
			has_texture = true;
			AutoAlloc<BaseBitmap> bitmap;
			if (bitmap && bitmap->Init(texture_path) == IMAGERESULT::OK)
			{
				if (bitmap->GetChannelCount() &&
					(texture_path.GetSuffix().ToLower().Compare("png"_s) == maxon::COMPARERESULT::EQUAL ||
					 texture_path.GetSuffix().ToLower().Compare("tga"_s) == maxon::COMPARERESULT::EQUAL))
					has_alpha_channel = true;
			}
		}
	}

	Material* material = Material::Alloc();
	if (!material)
		return nullptr;
	base_material = material;

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

	base_material->SetName(material_name);
	return base_material;
}

BaseMaterial* CreateStandardMaterialFromData(const MMDMaterialData& data)
{
	Material* material = Material::Alloc();
	if (!material)
		return nullptr;

	BaseShader* color_shader = BaseShader::Alloc(Xcolor);
	if (color_shader)
	{
		color_shader->SetParameter(ConstDescID(DescLevel(COLORSHADER_COLOR)), data.diffuse_rgb, DESCFLAGS_SET::NONE);
		material->SetParameter(ConstDescID(DescLevel(MATERIAL_COLOR_SHADER)), color_shader, DESCFLAGS_SET::NONE);
		material->InsertShader(color_shader);
	}

	material->SetChannelState(CHANNEL_ALPHA, true);
	BaseShader* alpha_shader = BaseShader::Alloc(Xcolor);
	if (alpha_shader)
	{
		alpha_shader->SetParameter(ConstDescID(DescLevel(COLORSHADER_COLOR)), Vector(1, 1, 1), DESCFLAGS_SET::NONE);
		alpha_shader->SetParameter(ConstDescID(DescLevel(COLORSHADER_BRIGHTNESS)), data.diffuse_alpha, DESCFLAGS_SET::NONE);
		material->SetParameter(ConstDescID(DescLevel(MATERIAL_ALPHA_SHADER)), alpha_shader, DESCFLAGS_SET::NONE);
		material->InsertShader(alpha_shader);
	}

	material->SetChannelState(CHANNEL_SPECULAR, true);
	material->SetParameter(ConstDescID(DescLevel(MATERIAL_SPECULAR_COLOR)), data.specular, DESCFLAGS_SET::NONE);
	Float specular_width = maxon::Clamp01(data.specular_power / 100.0);
	material->SetParameter(ConstDescID(DescLevel(MATERIAL_SPECULAR_WIDTH)), specular_width, DESCFLAGS_SET::NONE);

	material->SetName(data.name_local);
	return material;
}

void SyncToStandardMaterial(const MMDMaterialData& data, BaseMaterial* material)
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
			if (mat->GetParameter(ConstDescID(DescLevel(MATERIAL_COLOR_SHADER)), gd, DESCFLAGS_GET::NONE))
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
			if (mat->GetParameter(ConstDescID(DescLevel(MATERIAL_ALPHA_SHADER)), gd, DESCFLAGS_GET::NONE))
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
}

void ReadFromStandardMaterial(const BaseMaterial* material, MMDMaterialData& data)
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
		if (bc.GetString(BASECHANNEL_TEXTURE).IsEmpty())
		{
			GeData gd;
			if (mat->GetParameter(ConstDescID(DescLevel(MATERIAL_COLOR_SHADER)), gd, DESCFLAGS_GET::NONE))
			{
				BaseShader* sh = static_cast<BaseShader*>(gd.GetLink(doc));
				if (sh && sh->IsInstanceOf(Xcolor))
				{
					GeData color_data;
					if (sh->GetParameter(ConstDescID(DescLevel(COLORSHADER_COLOR)), color_data, DESCFLAGS_GET::NONE))
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
			if (mat->GetParameter(ConstDescID(DescLevel(MATERIAL_ALPHA_SHADER)), gd, DESCFLAGS_GET::NONE))
			{
				BaseShader* ash = static_cast<BaseShader*>(gd.GetLink(doc));
				if (ash && ash->IsInstanceOf(Xcolor))
				{
					GeData brightness_data;
					if (ash->GetParameter(ConstDescID(DescLevel(COLORSHADER_BRIGHTNESS)), brightness_data, DESCFLAGS_GET::NONE))
						data.diffuse_alpha = brightness_data.GetFloat();
				}
			}
		}
	}
}

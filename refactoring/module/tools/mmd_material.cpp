#include "mmd_material.h"
#include "cmt_tools_setting.h"
#include "xcolor.h"


void MMDMaterialManager::SetTextureRelativePath(const Filename& texture_relative_path)
{
	m_texture_relative_path = texture_relative_path;
}

Bool MMDMaterialManager::LoadPMXTextures(const std::vector<libmmd::PMXTexture>& pmx_textures)
{
	m_texture_path_array.Reset();
	const auto texture_count = pmx_textures.size();
	iferr(m_texture_path_array.SetCapacityHint(static_cast<Int>(texture_count)))
	{
		return false;
	}
	for (auto texture_index = decltype(texture_count){}; texture_index < texture_count; ++texture_index)
	{
		const auto& [m_textureName] = pmx_textures[texture_index];
		String texture_path_str(m_textureName.c_str());
		Filename texture_path(texture_path_str);
		if(texture_path.IsPopulated() && !GeFExist(texture_path))
		{
			// relative path to abs path
			texture_path = FormatString("@\\@", m_texture_relative_path.GetString(), texture_path_str);
		}
		iferr(m_texture_path_array.SDK2024_Append(std::move(texture_path)))
			return false;
	}
	return true;
}

BaseMaterial* MMDMaterialManager::LoadPMXMaterial(const libmmd::PMXMaterial& pmx_material, const uint64_t material_index, const maxon::String& material_name, const CMTToolsSetting::ModelImport& setting)
{
	BaseMaterial* base_material = nullptr;

	// base color texture
	bool has_texture = false;
	bool has_alpha_channel = false;
	const auto texture_index = pmx_material.m_textureIndex;
	if (texture_index != -1 && texture_index < m_texture_path_array.GetCount())
	{
		const auto& texture_path = m_texture_path_array[texture_index];
		if (GeFExist(texture_path))
		{
			has_texture = true;

			AutoAlloc<BaseBitmap> bitmap;
			if(!bitmap)
				return base_material;

			if(bitmap->Init(texture_path) != IMAGERESULT::OK)
				return base_material;

			// has alpha channel
			if (bitmap->GetChannelCount() &&
				(texture_path.GetSuffix().ToLower().Compare("png"_s) != maxon::COMPARERESULT::EQUAL||
				 texture_path.GetSuffix().ToLower().Compare("tga"_s) != maxon::COMPARERESULT::EQUAL))
			{
				has_alpha_channel = true;
			}
		}
	}

	switch (setting.import_material_type)
	{
	case CMTToolsSetting::ModelImport::material_type::Standard:
	{
		const auto material = Material::Alloc();
		if (!material)
			return material;
		base_material = material;

		const auto& color = pmx_material.m_diffuse;
		if (has_texture)
		{
			BaseChannel* base_color_channel = material->GetChannel(CHANNEL_COLOR);
			if (!base_color_channel)
				return base_material;

			BaseContainer base_color_container = base_color_channel->GetData();
			base_color_container.SetString(BASECHANNEL_TEXTURE, m_texture_path_array[texture_index].GetString());
			base_color_channel->SetData(base_color_container);
		}
		else
		{
			BaseShader* base_color_shader = BaseShader::Alloc(Xcolor);
			if (!base_color_shader)
				return base_material;
			base_color_shader->SetParameter(ConstDescID(DescLevel(COLORSHADER_COLOR)), Vector(color[0], color[1], color[2]), DESCFLAGS_SET::NONE);
			material->SetParameter(ConstDescID(DescLevel(MATERIAL_COLOR_SHADER)), base_color_shader, DESCFLAGS_SET::NONE);
			material->InsertShader(base_color_shader);
		}

		material->SetChannelState(CHANNEL_ALPHA, true);
		BaseChannel* alpha_channel = material->GetChannel(CHANNEL_ALPHA);
		if (!alpha_channel)
			return base_material;
		if(has_alpha_channel)
		{
			BaseContainer alpha_container = alpha_channel->GetData();
			alpha_container.SetString(BASECHANNEL_TEXTURE, m_texture_path_array[texture_index].GetString());
			alpha_channel->SetData(alpha_container);
		}
		else
		{
			BaseShader* alpha_shader = BaseShader::Alloc(Xcolor);
			alpha_shader->SetParameter(ConstDescID(DescLevel(COLORSHADER_COLOR)), Vector(1, 1, 1), DESCFLAGS_SET::NONE);
			alpha_shader->SetParameter(ConstDescID(DescLevel(COLORSHADER_BRIGHTNESS)), color[3], DESCFLAGS_SET::NONE);
			material->SetParameter(ConstDescID(DescLevel(MATERIAL_ALPHA_SHADER)), alpha_shader, DESCFLAGS_SET::NONE);
			material->InsertShader(alpha_shader);
		}

		break;
	}
	case CMTToolsSetting::ModelImport::material_type::RedShift:
		{
			NodeMaterial* material = reinterpret_cast<NodeMaterial*>(BaseMaterial::Alloc(Mmaterial));
			break;
		}
	case CMTToolsSetting::ModelImport::material_type::Octane:
		break;
	}

	// set material name
	base_material->SetName(material_name);

	return base_material;
}

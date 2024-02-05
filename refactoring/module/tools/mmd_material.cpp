#include "pch.h"

#include "mmd_material.h"
#include "cmt_tools_setting.h"
#include "xcolor.h"


void MMDMaterialManager::SetTextureRelativePath(const Filename& texture_relative_path)
{
	m_texture_relative_path = texture_relative_path;
}

Bool MMDMaterialManager::LoadPMXTexture(const libmmd::pmx_model::pmx_texture_array& pmx_texture_array)
{
	m_texture_path_array.Reset();
	const auto texture_count = pmx_texture_array.size();
	iferr(m_texture_path_array.SetCapacityHint(static_cast<Int>(texture_count)))
	{
		return false;
	}
	for (auto texture_index = decltype(texture_count){}; texture_index < texture_count; ++texture_index)
	{
		const auto& texture = pmx_texture_array[texture_index];
		Filename texture_path(maxon::String(texture.get_texture_path().c_str()));
		if(texture_path.IsPopulated() && !GeFExist(texture_path))
		{
			texture_path = m_texture_relative_path + texture_path;
		}
		iferr(m_texture_path_array.SDK2024_Append(std::move(texture_path)))
			return false;
	}
	return true;
}

BaseMaterial* MMDMaterialManager::LoadPMXMaterial(const libmmd::pmx_material& pmx_material, const libmmd::pmx_model::pmx_texture_array& pmx_texture_array, const uint64_t material_index, const CMTToolsSetting::ModelImport& setting)
{
	BaseMaterial* base_material = nullptr;

	// base color texture
	bool has_texture = false;
	bool has_alpha_channel = false;
	const auto texture_index = pmx_material.get_texture_index();
	if (texture_index == -1)
	{
		has_texture = true;
	}
	else if (texture_index < m_texture_path_array.GetCount())
	{
		const auto& texture_path = m_texture_path_array[texture_index];

		if (!GeFExist(texture_path))
			return base_material;

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


	switch (setting.import_material_type)
	{
	case CMTToolsSetting::ModelImport::material_type::Standard:
	{
		const auto material = Material::Alloc();
		if (!material)
			return material;
		base_material = material;

		if (has_texture)
		{
			BaseShader* base_color_shader = BaseShader::Alloc(Xcolor);
			if(!base_color_shader)
				return base_material;
			const auto& diffuse_colour = pmx_material.get_diffuse_color();
			base_color_shader->SetParameter(ConstDescID(DescLevel(COLORSHADER_COLOR)), Vector(diffuse_colour[0], diffuse_colour[1], diffuse_colour[2]), DESCFLAGS_SET::NONE);
			base_color_shader->SetParameter(ConstDescID(DescLevel(COLORSHADER_BRIGHTNESS)), diffuse_colour[3], DESCFLAGS_SET::NONE);
			material->SetParameter(ConstDescID(DescLevel(MATERIAL_COLOR_SHADER)), base_color_shader, DESCFLAGS_SET::NONE);
			material->InsertShader(base_color_shader);
		}
		else
		{
			
		}

		if(has_alpha_channel)
		{
			BaseChannel* base_color_channel = material->GetChannel(CHANNEL_COLOR);
			if (!base_color_channel)
				return base_material;

			material->SetChannelState(CHANNEL_ALPHA, true);
			BaseChannel* alpha_channel = material->GetChannel(CHANNEL_ALPHA);
			if (!alpha_channel)
				return base_material;


		}

		break;
	}
	case CMTToolsSetting::ModelImport::material_type::RedShift:
		break;
	case CMTToolsSetting::ModelImport::material_type::Octane:
		break;
	}

	// set material name
	if (setting.import_english)
	{
		if (const maxon::String material_name_universal(pmx_material.get_material_name_universal().c_str()); material_name_universal.IsEmpty())
		{
			base_material->SetName("Material_" + String::UIntToString(material_index));
		}
		else
		{
			base_material->SetName(material_name_universal);
		}
	}
	else
	{
		base_material->SetName(maxon::String(pmx_material.get_material_name_local().c_str()));
	}

	return base_material;
}

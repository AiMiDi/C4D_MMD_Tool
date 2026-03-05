#include "mmd_corona_material.h"
#include <c4d_symbols.h>

namespace
{
	constexpr auto ID_CORONA_MATERIAL = 1032100;
	constexpr auto ID_CORONA_BITMAP = 1036473;
	constexpr auto CORONA_BITMAP_FILENAME = 11520;
	constexpr auto CORONA_MATERIAL_DIFFUSE = 4101;
	constexpr auto CORONA_MATERIAL_ALPHA = 4109;
	constexpr auto CORONA_DIFFUSE_COLOR = 4300;
	constexpr auto CORONA_DIFFUSE_TEXTURE = 4301;
	constexpr auto CORONA_DIFFUSE_COLOR_LEVEL = 4302;
	constexpr auto CORONA_ALPHA_COLOR = 4750;
	constexpr auto CORONA_ALPHA_TEXTURE = 4751;
	constexpr auto CORONA_ALPHA_COLOR_LEVEL = 4752;
}

BaseMaterial* CreateCoronaMaterialFromPMX(const libmmd::PMXMaterial& pmx_material,
	const maxon::BaseArray<Filename>& texture_paths, const maxon::String& material_name)
{
	BaseMaterial* material = BaseMaterial::Alloc(ID_CORONA_MATERIAL);
	if (!material)
		return nullptr;

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

	const auto& color = pmx_material.m_diffuse;
	const Vector diffuse_rgb(color.x(), color.y(), color.z());
	const Float diffuse_alpha = color.w();

	material->SetParameter(ConstDescID(DescLevel(CORONA_MATERIAL_DIFFUSE)), true, DESCFLAGS_SET::NONE);
	material->SetParameter(ConstDescID(DescLevel(CORONA_MATERIAL_ALPHA)), true, DESCFLAGS_SET::NONE);

	if (has_texture)
	{
		BaseShader* tex_shader = BaseShader::Alloc(ID_CORONA_BITMAP);
		if (tex_shader)
		{
			tex_shader->SetParameter(ConstDescID(DescLevel(CORONA_BITMAP_FILENAME)),
				texture_paths[texture_index].GetString(), DESCFLAGS_SET::NONE);
			material->InsertShader(tex_shader);
			material->SetParameter(ConstDescID(DescLevel(CORONA_DIFFUSE_TEXTURE)), tex_shader, DESCFLAGS_SET::NONE);
		}
		else
		{
			material->SetParameter(ConstDescID(DescLevel(CORONA_DIFFUSE_COLOR)), diffuse_rgb, DESCFLAGS_SET::NONE);
			material->SetParameter(ConstDescID(DescLevel(CORONA_DIFFUSE_COLOR_LEVEL)), 1.0, DESCFLAGS_SET::NONE);
		}
	}
	else
	{
		material->SetParameter(ConstDescID(DescLevel(CORONA_DIFFUSE_COLOR)), diffuse_rgb, DESCFLAGS_SET::NONE);
		material->SetParameter(ConstDescID(DescLevel(CORONA_DIFFUSE_COLOR_LEVEL)), 1.0, DESCFLAGS_SET::NONE);
	}

	if (has_alpha_channel && has_texture)
	{
		BaseShader* alpha_shader = BaseShader::Alloc(ID_CORONA_BITMAP);
		if (alpha_shader)
		{
			alpha_shader->SetParameter(ConstDescID(DescLevel(CORONA_BITMAP_FILENAME)),
				texture_paths[texture_index].GetString(), DESCFLAGS_SET::NONE);
			material->InsertShader(alpha_shader);
			material->SetParameter(ConstDescID(DescLevel(CORONA_ALPHA_TEXTURE)), alpha_shader, DESCFLAGS_SET::NONE);
		}
		else
		{
			material->SetParameter(ConstDescID(DescLevel(CORONA_ALPHA_COLOR)), Vector(1, 1, 1), DESCFLAGS_SET::NONE);
			material->SetParameter(ConstDescID(DescLevel(CORONA_ALPHA_COLOR_LEVEL)), diffuse_alpha, DESCFLAGS_SET::NONE);
		}
	}
	else
	{
		material->SetParameter(ConstDescID(DescLevel(CORONA_ALPHA_COLOR)), Vector(1, 1, 1), DESCFLAGS_SET::NONE);
		material->SetParameter(ConstDescID(DescLevel(CORONA_ALPHA_COLOR_LEVEL)), diffuse_alpha, DESCFLAGS_SET::NONE);
	}

	material->SetName(material_name);
	return material;
}

BaseMaterial* CreateCoronaMaterialFromData(const MMDMaterialData& data)
{
	BaseMaterial* material = BaseMaterial::Alloc(ID_CORONA_MATERIAL);
	if (!material)
		return nullptr;

	material->SetParameter(ConstDescID(DescLevel(CORONA_MATERIAL_DIFFUSE)), true, DESCFLAGS_SET::NONE);
	material->SetParameter(ConstDescID(DescLevel(CORONA_MATERIAL_ALPHA)), true, DESCFLAGS_SET::NONE);
	material->SetParameter(ConstDescID(DescLevel(CORONA_DIFFUSE_COLOR)), data.diffuse_rgb, DESCFLAGS_SET::NONE);
	material->SetParameter(ConstDescID(DescLevel(CORONA_ALPHA_COLOR)), Vector(1, 1, 1), DESCFLAGS_SET::NONE);
	material->SetParameter(ConstDescID(DescLevel(CORONA_ALPHA_COLOR_LEVEL)), data.diffuse_alpha, DESCFLAGS_SET::NONE);
	material->SetName(data.name_local);
	return material;
}

void SyncToCoronaMaterial(const MMDMaterialData& data, BaseMaterial* material)
{
	if (!material || material->GetType() != ID_CORONA_MATERIAL)
		return;
	material->SetName(data.name_local);
	material->SetParameter(ConstDescID(DescLevel(CORONA_DIFFUSE_COLOR)), data.diffuse_rgb, DESCFLAGS_SET::NONE);
	material->SetParameter(ConstDescID(DescLevel(CORONA_ALPHA_COLOR_LEVEL)), data.diffuse_alpha, DESCFLAGS_SET::NONE);
}

void ReadFromCoronaMaterial(const BaseMaterial* material, MMDMaterialData& data)
{
	if (!material || material->GetType() != ID_CORONA_MATERIAL)
		return;
	data.name_local = material->GetName();
	GeData ge_data;
	if (material->GetParameter(ConstDescID(DescLevel(CORONA_DIFFUSE_COLOR)), ge_data, DESCFLAGS_GET::NONE))
		data.diffuse_rgb = ge_data.GetVector();
	if (material->GetParameter(ConstDescID(DescLevel(CORONA_ALPHA_COLOR_LEVEL)), ge_data, DESCFLAGS_GET::NONE))
		data.diffuse_alpha = ge_data.GetFloat();
}

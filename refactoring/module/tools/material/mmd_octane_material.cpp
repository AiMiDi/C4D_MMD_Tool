#include "mmd_octane_material.h"
#include <c4d_symbols.h>

namespace
{
	constexpr auto ID_OCTANE_DIFFUSE_MATERIAL = 1029501;
	constexpr auto ID_OCTANE_IMAGE_TEXTURE = 1029508;
	constexpr auto ID_OCTANE_RGBSPECTRUM = 1029504;
	constexpr auto ID_OCTANE_FLOAT_TEXTURE = 1029506;

	constexpr auto OCT_MAT_USE_COLOR = 1160;
	constexpr auto OCT_MAT_USE_OPACITY = 1261;
	constexpr auto OCT_MATERIAL_DIFFUSE_LINK = 1110;
	constexpr auto OCT_MATERIAL_DIFFUSE_COLOR = 1111;
	constexpr auto OCT_MATERIAL_DIFFUSE_FLOAT = 1112;
	constexpr auto OCT_MATERIAL_OPACITY_LINK = 1260;
	constexpr auto OCT_MATERIAL_OPACITY_COLOR = 1261;
	constexpr auto OCT_MATERIAL_OPACITY_FLOAT = 1262;

	constexpr auto RGBSPECTRUMSHADER_COLOR = 1000;
	constexpr auto FLOATTEXTURE_VALUE = 1000;
	constexpr auto IMAGETEXTURE_FILE = 1000;
}

BaseMaterial* CreateOctaneMaterialFromPMX(const libmmd::PMXMaterial& pmx_material,
	const maxon::BaseArray<Filename>& texture_paths, const maxon::String& material_name)
{
	BaseMaterial* material = BaseMaterial::Alloc(ID_OCTANE_DIFFUSE_MATERIAL);
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

	material->SetParameter(ConstDescID(DescLevel(OCT_MAT_USE_COLOR)), true, DESCFLAGS_SET::NONE);
	material->SetParameter(ConstDescID(DescLevel(OCT_MAT_USE_OPACITY)), true, DESCFLAGS_SET::NONE);

	if (has_texture)
	{
		BaseShader* tex_shader = BaseShader::Alloc(ID_OCTANE_IMAGE_TEXTURE);
		if (tex_shader)
		{
			tex_shader->SetParameter(ConstDescID(DescLevel(IMAGETEXTURE_FILE)),
				texture_paths[texture_index].GetString(), DESCFLAGS_SET::NONE);
			material->InsertShader(tex_shader);
			material->SetParameter(ConstDescID(DescLevel(OCT_MATERIAL_DIFFUSE_LINK)), tex_shader, DESCFLAGS_SET::NONE);
		}
		else
		{
			BaseShader* color_shader = BaseShader::Alloc(ID_OCTANE_RGBSPECTRUM);
			if (color_shader)
			{
				color_shader->SetParameter(ConstDescID(DescLevel(RGBSPECTRUMSHADER_COLOR)), diffuse_rgb, DESCFLAGS_SET::NONE);
				material->InsertShader(color_shader);
				material->SetParameter(ConstDescID(DescLevel(OCT_MATERIAL_DIFFUSE_LINK)), color_shader, DESCFLAGS_SET::NONE);
			}
		}
	}
	else
	{
		BaseShader* color_shader = BaseShader::Alloc(ID_OCTANE_RGBSPECTRUM);
		if (color_shader)
		{
			color_shader->SetParameter(ConstDescID(DescLevel(RGBSPECTRUMSHADER_COLOR)), diffuse_rgb, DESCFLAGS_SET::NONE);
			material->InsertShader(color_shader);
			material->SetParameter(ConstDescID(DescLevel(OCT_MATERIAL_DIFFUSE_LINK)), color_shader, DESCFLAGS_SET::NONE);
		}
	}

	if (has_alpha_channel && has_texture)
	{
		BaseShader* alpha_shader = BaseShader::Alloc(ID_OCTANE_IMAGE_TEXTURE);
		if (alpha_shader)
		{
			alpha_shader->SetParameter(ConstDescID(DescLevel(IMAGETEXTURE_FILE)),
				texture_paths[texture_index].GetString(), DESCFLAGS_SET::NONE);
			material->InsertShader(alpha_shader);
			material->SetParameter(ConstDescID(DescLevel(OCT_MATERIAL_OPACITY_LINK)), alpha_shader, DESCFLAGS_SET::NONE);
		}
		else
		{
			BaseShader* float_shader = BaseShader::Alloc(ID_OCTANE_FLOAT_TEXTURE);
			if (float_shader)
			{
				float_shader->SetParameter(ConstDescID(DescLevel(FLOATTEXTURE_VALUE)), diffuse_alpha, DESCFLAGS_SET::NONE);
				material->InsertShader(float_shader);
				material->SetParameter(ConstDescID(DescLevel(OCT_MATERIAL_OPACITY_LINK)), float_shader, DESCFLAGS_SET::NONE);
			}
		}
	}
	else
	{
		BaseShader* float_shader = BaseShader::Alloc(ID_OCTANE_FLOAT_TEXTURE);
		if (float_shader)
		{
			float_shader->SetParameter(ConstDescID(DescLevel(FLOATTEXTURE_VALUE)), diffuse_alpha, DESCFLAGS_SET::NONE);
			material->InsertShader(float_shader);
			material->SetParameter(ConstDescID(DescLevel(OCT_MATERIAL_OPACITY_LINK)), float_shader, DESCFLAGS_SET::NONE);
		}
	}

	material->SetName(material_name);
	return material;
}

BaseMaterial* CreateOctaneMaterialFromData(const MMDMaterialData& data)
{
	BaseMaterial* material = BaseMaterial::Alloc(ID_OCTANE_DIFFUSE_MATERIAL);
	if (!material)
		return nullptr;

	material->SetParameter(ConstDescID(DescLevel(OCT_MAT_USE_COLOR)), true, DESCFLAGS_SET::NONE);
	material->SetParameter(ConstDescID(DescLevel(OCT_MAT_USE_OPACITY)), true, DESCFLAGS_SET::NONE);

	BaseShader* color_shader = BaseShader::Alloc(ID_OCTANE_RGBSPECTRUM);
	if (color_shader)
	{
		color_shader->SetParameter(ConstDescID(DescLevel(RGBSPECTRUMSHADER_COLOR)), data.diffuse_rgb, DESCFLAGS_SET::NONE);
		material->InsertShader(color_shader);
		material->SetParameter(ConstDescID(DescLevel(OCT_MATERIAL_DIFFUSE_LINK)), color_shader, DESCFLAGS_SET::NONE);
	}

	BaseShader* float_shader = BaseShader::Alloc(ID_OCTANE_FLOAT_TEXTURE);
	if (float_shader)
	{
		float_shader->SetParameter(ConstDescID(DescLevel(FLOATTEXTURE_VALUE)), data.diffuse_alpha, DESCFLAGS_SET::NONE);
		material->InsertShader(float_shader);
		material->SetParameter(ConstDescID(DescLevel(OCT_MATERIAL_OPACITY_LINK)), float_shader, DESCFLAGS_SET::NONE);
	}

	material->SetName(data.name_local);
	return material;
}

void SyncToOctaneMaterial(const MMDMaterialData& data, BaseMaterial* material)
{
	if (!material || material->GetType() != ID_OCTANE_DIFFUSE_MATERIAL)
		return;
	material->SetName(data.name_local);
	GeData ge_data;
	if (material->GetParameter(ConstDescID(DescLevel(OCT_MATERIAL_DIFFUSE_LINK)), ge_data, DESCFLAGS_GET::NONE))
	{
		if (const auto* link = ge_data.GetBaseLink(); link)
		{
			if (auto* shader = reinterpret_cast<BaseShader*>(link->ForceGetLink()); shader)
			{
				if (shader->GetType() == ID_OCTANE_RGBSPECTRUM)
					shader->SetParameter(ConstDescID(DescLevel(RGBSPECTRUMSHADER_COLOR)), data.diffuse_rgb, DESCFLAGS_SET::NONE);
			}
		}
	}
	if (material->GetParameter(ConstDescID(DescLevel(OCT_MATERIAL_OPACITY_LINK)), ge_data, DESCFLAGS_GET::NONE))
	{
		if (const auto* link = ge_data.GetBaseLink(); link)
		{
			if (auto* shader = reinterpret_cast<BaseShader*>(link->ForceGetLink()); shader)
			{
				if (shader->GetType() == ID_OCTANE_FLOAT_TEXTURE)
					shader->SetParameter(ConstDescID(DescLevel(FLOATTEXTURE_VALUE)), data.diffuse_alpha, DESCFLAGS_SET::NONE);
			}
		}
	}
}

void ReadFromOctaneMaterial(const BaseMaterial* material, MMDMaterialData& data)
{
	if (!material || material->GetType() != ID_OCTANE_DIFFUSE_MATERIAL)
		return;
	data.name_local = material->GetName();
	GeData ge_data;
	bool got_diffuse = false;
	if (material->GetParameter(ConstDescID(DescLevel(OCT_MATERIAL_DIFFUSE_LINK)), ge_data, DESCFLAGS_GET::NONE))
	{
		if (const auto* link = ge_data.GetBaseLink(); link)
		{
			if (auto* shader = reinterpret_cast<BaseShader*>(link->ForceGetLink()); shader)
			{
				if (shader->GetType() == ID_OCTANE_RGBSPECTRUM)
				{
					GeData color_data;
					if (shader->GetParameter(ConstDescID(DescLevel(RGBSPECTRUMSHADER_COLOR)), color_data, DESCFLAGS_GET::NONE))
					{
						data.diffuse_rgb = color_data.GetVector();
						got_diffuse = true;
					}
				}
			}
		}
	}
	if (!got_diffuse)
	{
		if (material->GetParameter(ConstDescID(DescLevel(OCT_MATERIAL_DIFFUSE_COLOR)), ge_data, DESCFLAGS_GET::NONE))
			data.diffuse_rgb = ge_data.GetVector();
	}
	if (material->GetParameter(ConstDescID(DescLevel(OCT_MATERIAL_OPACITY_LINK)), ge_data, DESCFLAGS_GET::NONE))
	{
		if (const auto* link = ge_data.GetBaseLink(); link)
		{
			if (auto* shader = reinterpret_cast<BaseShader*>(link->ForceGetLink()); shader)
			{
				if (shader->GetType() == ID_OCTANE_FLOAT_TEXTURE)
				{
					GeData val_data;
					if (shader->GetParameter(ConstDescID(DescLevel(FLOATTEXTURE_VALUE)), val_data, DESCFLAGS_GET::NONE))
						data.diffuse_alpha = val_data.GetFloat();
				}
			}
		}
	}
}

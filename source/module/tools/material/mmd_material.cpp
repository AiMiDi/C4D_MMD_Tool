#include "mmd_material.h"
#include "mmd_standard_material.h"
#include "mmd_redshift_material.h"
#include "mmd_octane_material.h"
#include "mmd_corona_material.h"
#include "cmt_tools_setting.h"
#include "utils/io_util.hpp"
#include "utils/string_util.hpp"

using namespace io_util;

namespace
{
	constexpr auto ID_REDSHIFT_MATERIAL = 1036224;
	constexpr auto ID_OCTANE_DIFFUSE_MATERIAL = 1029501;
	constexpr auto ID_CORONA_MATERIAL = 1032100;
#if API_VERSION >= 2024000
	constexpr maxon::LiteralId k_redshiftSpaceId("com.redshift3d.redshift4c4d.class.nodespace");
#endif
}

MMDRendererMaterialType MMDMaterialAdapter::DetectType(const BaseMaterial* material)
{
	if (!material)
		return MMDRendererMaterialType::Unknown;
	switch (material->GetType())
	{
	case Mmaterial:
	{
#if API_VERSION >= 2024000
		if (material->IsNodeBased())
		{
			auto* node_mat = static_cast<NodeMaterial*>(const_cast<BaseMaterial*>(material));
			if (node_mat && node_mat->HasSpace(k_redshiftSpaceId))
				return MMDRendererMaterialType::RedShift;
		}
#endif
		return MMDRendererMaterialType::Standard;
	}
	case ID_REDSHIFT_MATERIAL:
		return MMDRendererMaterialType::RedShift;
	case ID_OCTANE_DIFFUSE_MATERIAL:
		return MMDRendererMaterialType::Octane;
	case ID_CORONA_MATERIAL:
		return MMDRendererMaterialType::Corona;
	default:
		return MMDRendererMaterialType::Unknown;
	}
}

MMDMaterialAdapter::TextureInfo MMDMaterialAdapter::DetectTextureFromPMX(
	const libmmd::PMXMaterial& pmx_material, const maxon::BaseArray<Filename>& texture_paths)
{
	TextureInfo info{};
	const auto texture_index = pmx_material.m_textureIndex;
	if (texture_index == -1 || texture_index >= texture_paths.GetCount())
		return info;
	const auto& texture_path = texture_paths[texture_index];
	if (!GeFExist(texture_path))
		return info;
	info.has_texture = true;
	AutoAlloc<BaseBitmap> bitmap;
	if (bitmap && bitmap->Init(texture_path) == IMAGERESULT::OK)
	{
		if (bitmap->GetChannelCount() &&
			(texture_path.GetSuffix().ToLower().Compare("png"_s) == maxon::COMPARERESULT::EQUAL ||
			 texture_path.GetSuffix().ToLower().Compare("tga"_s) == maxon::COMPARERESULT::EQUAL))
			info.has_alpha = true;
	}
	return info;
}

MMDMaterialAdapter::TextureInfo MMDMaterialAdapter::DetectTextureFromData(const MMDMaterialData& data)
{
	TextureInfo info{};
	const Filename texture_path(data.texture_path);
	if (!texture_path.IsPopulated() || !GeFExist(texture_path))
		return info;
	info.has_texture = true;
	AutoAlloc<BaseBitmap> bitmap;
	if (bitmap && bitmap->Init(texture_path) == IMAGERESULT::OK)
	{
		if (bitmap->GetChannelCount() &&
			(texture_path.GetSuffix().ToLower().Compare("png"_s) == maxon::COMPARERESULT::EQUAL ||
			 texture_path.GetSuffix().ToLower().Compare("tga"_s) == maxon::COMPARERESULT::EQUAL))
			info.has_alpha = true;
	}
	return info;
}

std::unique_ptr<MMDMaterialAdapter> MMDMaterialAdapter::Create(MMDRendererMaterialType type)
{
	switch (type)
	{
	case MMDRendererMaterialType::Standard: return std::make_unique<MMDStandardMaterialAdapter>();
	case MMDRendererMaterialType::RedShift: return std::make_unique<MMDRedShiftMaterialAdapter>();
	case MMDRendererMaterialType::Octane:   return std::make_unique<MMDOctaneMaterialAdapter>();
	case MMDRendererMaterialType::Corona:   return std::make_unique<MMDCoronaMaterialAdapter>();
	default:                                return nullptr;
	}
}

std::unique_ptr<MMDMaterialAdapter> MMDMaterialAdapter::CreateFor(const BaseMaterial* material)
{
	const auto type = DetectType(material);
	return type != MMDRendererMaterialType::Unknown ? Create(type) : nullptr;
}

void SyncToMaterial(const MMDMaterialData& data, BaseMaterial* material)
{
	auto adapter = MMDMaterialAdapter::CreateFor(material);
	if (adapter)
		adapter->SyncTo(data, material);
}

void ReadFromMaterial(const BaseMaterial* material, MMDMaterialData& data)
{
	auto adapter = MMDMaterialAdapter::CreateFor(material);
	if (adapter)
		adapter->ReadFrom(material, data);
}

BaseMaterial* CreateMaterialFromData(const MMDMaterialData& data, MMDRendererMaterialType type)
{
	auto adapter = MMDMaterialAdapter::Create(type);
	return adapter ? adapter->CreateFromData(data) : nullptr;
}

void MMDMaterialData::FromPMX(const libmmd::PMXMaterial& pmx_material)
{
	name_local = String(pmx_material.m_name.c_str());
	name_universal = String(pmx_material.m_englishName.c_str());
	diffuse_rgb.x = pmx_material.m_diffuse[0];
	diffuse_rgb.y = pmx_material.m_diffuse[1];
	diffuse_rgb.z = pmx_material.m_diffuse[2];
	diffuse_alpha = pmx_material.m_diffuse[3];
	specular.x = pmx_material.m_specular[0];
	specular.y = pmx_material.m_specular[1];
	specular.z = pmx_material.m_specular[2];
	specular_power = pmx_material.m_specularPower;
	ambient.x = pmx_material.m_ambient[0];
	ambient.y = pmx_material.m_ambient[1];
	ambient.z = pmx_material.m_ambient[2];
	const auto flags = static_cast<uint8_t>(pmx_material.m_drawMode);
	draw_both_face = (flags & static_cast<uint8_t>(libmmd::PMXDrawModeFlags::BothFace)) != 0;
	draw_ground_shadow = (flags & static_cast<uint8_t>(libmmd::PMXDrawModeFlags::GroundShadow)) != 0;
	draw_cast_self_shadow = (flags & static_cast<uint8_t>(libmmd::PMXDrawModeFlags::CastSelfShadow)) != 0;
	draw_receive_self_shadow = (flags & static_cast<uint8_t>(libmmd::PMXDrawModeFlags::RecieveSelfShadow)) != 0;
	draw_vertex_color = (flags & static_cast<uint8_t>(libmmd::PMXDrawModeFlags::VertexColor)) != 0;
	edge_enabled = (flags & static_cast<uint8_t>(libmmd::PMXDrawModeFlags::DrawEdge)) != 0;
	edge_color_rgb.x = pmx_material.m_edgeColor[0];
	edge_color_rgb.y = pmx_material.m_edgeColor[1];
	edge_color_rgb.z = pmx_material.m_edgeColor[2];
	edge_color_alpha = pmx_material.m_edgeColor[3];
	edge_size = pmx_material.m_edgeSize;
	sphere_mode = static_cast<Int32>(pmx_material.m_sphereMode);
	toon_mode = static_cast<Int32>(pmx_material.m_toonMode);
	toon_texture_index = pmx_material.m_toonTextureIndex;
	memo = String(pmx_material.m_memo.c_str());
	num_face_vertices = pmx_material.m_numFaceVertices;
	material_link = maxon::StrongRef<AutoAlloc<BaseLink>>();
}

void MMDMaterialData::ToPMX(libmmd::PMXMaterial& pmx_material) const
{
	pmx_material.m_name = string_util::GetStdString(name_local);
	pmx_material.m_englishName = string_util::GetStdString(name_universal);
	pmx_material.m_diffuse[0] = diffuse_rgb.x;
	pmx_material.m_diffuse[1] = diffuse_rgb.y;
	pmx_material.m_diffuse[2] = diffuse_rgb.z;
	pmx_material.m_diffuse[3] = diffuse_alpha;
	pmx_material.m_specular[0] = specular.x;
	pmx_material.m_specular[1] = specular.y;
	pmx_material.m_specular[2] = specular.z;
	pmx_material.m_specularPower = specular_power;
	pmx_material.m_ambient[0] = ambient.x;
	pmx_material.m_ambient[1] = ambient.y;
	pmx_material.m_ambient[2] = ambient.z;
	uint8_t flags = 0;
	if (draw_both_face) flags |= static_cast<uint8_t>(libmmd::PMXDrawModeFlags::BothFace);
	if (draw_ground_shadow) flags |= static_cast<uint8_t>(libmmd::PMXDrawModeFlags::GroundShadow);
	if (draw_cast_self_shadow) flags |= static_cast<uint8_t>(libmmd::PMXDrawModeFlags::CastSelfShadow);
	if (draw_receive_self_shadow) flags |= static_cast<uint8_t>(libmmd::PMXDrawModeFlags::RecieveSelfShadow);
	if (draw_vertex_color) flags |= static_cast<uint8_t>(libmmd::PMXDrawModeFlags::VertexColor);
	if (edge_enabled) flags |= static_cast<uint8_t>(libmmd::PMXDrawModeFlags::DrawEdge);
	pmx_material.m_drawMode = static_cast<libmmd::PMXDrawModeFlags>(flags);
	pmx_material.m_edgeColor[0] = edge_color_rgb.x;
	pmx_material.m_edgeColor[1] = edge_color_rgb.y;
	pmx_material.m_edgeColor[2] = edge_color_rgb.z;
	pmx_material.m_edgeColor[3] = edge_color_alpha;
	pmx_material.m_edgeSize = edge_size;
	pmx_material.m_textureIndex = -1; // TODO: path to index conversion
	pmx_material.m_sphereTextureIndex = -1; // TODO: path to index conversion
	pmx_material.m_sphereMode = static_cast<libmmd::PMXSphereMode>(sphere_mode);
	pmx_material.m_toonMode = static_cast<libmmd::PMXToonMode>(toon_mode);
	pmx_material.m_toonTextureIndex = toon_texture_index;
	pmx_material.m_memo = string_util::GetStdString(memo);
	pmx_material.m_numFaceVertices = num_face_vertices;
}

Bool MMDMaterialData::Read(HyperFile* hf)
{
	if (!ReadData(hf, name_local) || !ReadData(hf, name_universal))
		return false;
	if (!ReadData(hf, diffuse_rgb) || !ReadData(hf, diffuse_alpha))
		return false;
	if (!ReadData(hf, specular) || !ReadData(hf, specular_power) || !ReadData(hf, ambient))
		return false;
	Bool draw_flags[5];
	if (!ReadData(hf, draw_flags[0]) || !ReadData(hf, draw_flags[1]) || !ReadData(hf, draw_flags[2]) || !ReadData(hf, draw_flags[3]) || !ReadData(hf, draw_flags[4]))
		return false;
	draw_both_face = draw_flags[0];
	draw_ground_shadow = draw_flags[1];
	draw_cast_self_shadow = draw_flags[2];
	draw_receive_self_shadow = draw_flags[3];
	draw_vertex_color = draw_flags[4];
	if (!ReadData(hf, edge_enabled) || !ReadData(hf, edge_color_rgb) || !ReadData(hf, edge_color_alpha) || !ReadData(hf, edge_size))
		return false;
	if (!ReadData(hf, texture_path) || !ReadData(hf, sphere_texture_path) || !ReadData(hf, sphere_mode) || !ReadData(hf, toon_mode) || !ReadData(hf, toon_texture_index))
		return false;
	if (!ReadData(hf, toon_texture_path))
		return false;
	if (!ReadData(hf, memo) || !ReadData(hf, num_face_vertices))
		return false;
	Bool has_link = false;
	if (!hf->ReadBool(&has_link))
		return false;
	if (has_link)
	{
		if (!ReadData(hf, material_link))
			return false;
	}
	else
		material_link = maxon::StrongRef<AutoAlloc<BaseLink>>();
	Bool has_mesh_link = false;
	if (!hf->ReadBool(&has_mesh_link))
		return false;
	if (has_mesh_link)
	{
		if (!ReadData(hf, mesh_link))
			return false;
	}
	else
		mesh_link = maxon::StrongRef<AutoAlloc<BaseLink>>();
	if (!ReadData(hf, selection_name))
		return false;
	return true;
}

Bool MMDMaterialData::Write(HyperFile* hf) const
{
	if (!WriteData(hf, name_local) || !WriteData(hf, name_universal))
		return false;
	if (!WriteData(hf, diffuse_rgb) || !WriteData(hf, diffuse_alpha))
		return false;
	if (!WriteData(hf, specular) || !WriteData(hf, specular_power) || !WriteData(hf, ambient))
		return false;
	if (!WriteData(hf, draw_both_face) || !WriteData(hf, draw_ground_shadow) || !WriteData(hf, draw_cast_self_shadow) || !WriteData(hf, draw_receive_self_shadow) || !WriteData(hf, draw_vertex_color))
		return false;
	if (!WriteData(hf, edge_enabled) || !WriteData(hf, edge_color_rgb) || !WriteData(hf, edge_color_alpha) || !WriteData(hf, edge_size))
		return false;
	if (!WriteData(hf, texture_path) || !WriteData(hf, sphere_texture_path) || !WriteData(hf, sphere_mode) || !WriteData(hf, toon_mode) || !WriteData(hf, toon_texture_index))
		return false;
	if (!WriteData(hf, toon_texture_path))
		return false;
	if (!WriteData(hf, memo) || !WriteData(hf, num_face_vertices))
		return false;
	const Bool has_link = material_link && *material_link;
	if (!hf->WriteBool(has_link))
		return false;
	if (has_link)
	{
		if (!WriteData(hf, material_link))
			return false;
	}
	const Bool has_mesh_link = mesh_link && *mesh_link;
	if (!hf->WriteBool(has_mesh_link))
		return false;
	if (has_mesh_link)
	{
		if (!WriteData(hf, mesh_link))
			return false;
	}
	if (!WriteData(hf, selection_name))
		return false;
	return true;
}

Bool MMDMaterialData::CopyTo(MMDMaterialData& dest) const
{
	iferr_scope_handler { return false; };
	dest.name_local = name_local;
	dest.name_universal = name_universal;
	dest.diffuse_rgb = diffuse_rgb;
	dest.diffuse_alpha = diffuse_alpha;
	dest.specular = specular;
	dest.specular_power = specular_power;
	dest.ambient = ambient;
	dest.draw_both_face = draw_both_face;
	dest.draw_ground_shadow = draw_ground_shadow;
	dest.draw_cast_self_shadow = draw_cast_self_shadow;
	dest.draw_receive_self_shadow = draw_receive_self_shadow;
	dest.draw_vertex_color = draw_vertex_color;
	dest.edge_enabled = edge_enabled;
	dest.edge_color_rgb = edge_color_rgb;
	dest.edge_color_alpha = edge_color_alpha;
	dest.edge_size = edge_size;
	dest.texture_path = texture_path;
	dest.sphere_texture_path = sphere_texture_path;
	dest.sphere_mode = sphere_mode;
	dest.toon_mode = toon_mode;
	dest.toon_texture_index = toon_texture_index;
	dest.toon_texture_path = toon_texture_path;
	dest.memo = memo;
	dest.num_face_vertices = num_face_vertices;
	if (material_link && *material_link)
	{
		dest.material_link = maxon::StrongRef<AutoAlloc<BaseLink>>::Create() iferr_return;
		if (!dest.material_link || !*dest.material_link)
			return false;
		(*dest.material_link)->SetLink((*material_link)->ForceGetLink());
	}
	else
		dest.material_link = maxon::StrongRef<AutoAlloc<BaseLink>>();
	if (mesh_link && *mesh_link)
	{
		dest.mesh_link = maxon::StrongRef<AutoAlloc<BaseLink>>::Create() iferr_return;
		if (!dest.mesh_link || !*dest.mesh_link)
			return false;
		(*dest.mesh_link)->SetLink((*mesh_link)->ForceGetLink());
	}
	else
		dest.mesh_link = maxon::StrongRef<AutoAlloc<BaseLink>>();
	dest.selection_name = selection_name;
	return true;
}

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
			texture_path = FormatString("@\\@", m_texture_relative_path.GetString(), texture_path_str);
		}
		iferr(m_texture_path_array.SDK2024_Append(std::move(texture_path)))
			return false;
	}
	return true;
}

BaseMaterial* MMDMaterialManager::LoadPMXMaterial(const libmmd::PMXMaterial& pmx_material, const uint64_t material_index, const maxon::String& material_name, const CMTToolsSetting::ModelImport& setting)
{
	MMDRendererMaterialType create_type = MMDRendererMaterialType::Standard;
	switch (setting.import_material_type)
	{
	case CMTToolsSetting::ModelImport::material_type::Standard: create_type = MMDRendererMaterialType::Standard; break;
	case CMTToolsSetting::ModelImport::material_type::RedShift: create_type = MMDRendererMaterialType::RedShift; break;
	case CMTToolsSetting::ModelImport::material_type::Octane:   create_type = MMDRendererMaterialType::Octane;   break;
	case CMTToolsSetting::ModelImport::material_type::Corona:   create_type = MMDRendererMaterialType::Corona;   break;
	}
	auto adapter = MMDMaterialAdapter::Create(create_type);
	return adapter ? adapter->CreateFromPMX(pmx_material, m_texture_path_array, material_name) : nullptr;
}

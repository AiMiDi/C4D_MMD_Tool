#include "pch.h"
#include "pmx_material_data.h"

Bool PMXMaterialData::ReadFromFile(BaseFile* file)
{
	if (!m_model_info.m_text_reader(file, m_material_name_local))
		return FALSE;
	if (!m_model_info.m_text_reader(file, m_material_name_universal))
		return FALSE;
	static_assert(sizeof Vector4d32 == 16);
	if (!file->ReadBytes(&m_diffuse_colour, sizeof Vector4d32))
		return FALSE;
	if (!file->ReadVector32(&m_specular_colour))
		return FALSE;
	if (!file->ReadFloat32(&m_specular_strength))
		return FALSE;
	if (!file->ReadVector32(&m_ambient_colour))
		return FALSE;
	static_assert(sizeof PMXMaterialFlags == 1);
	if (!file->ReadBytes(&m_drawing_flags, sizeof PMXMaterialFlags))
		return FALSE;
	if (!file->ReadBytes(&m_edge_colour, sizeof(Vector4d32)))
		return FALSE;
	if (!file->ReadFloat32(&m_edge_scale))
		return FALSE;
	if (!m_model_info.m_texture_index_reader(file,m_texture_index))
		return FALSE;
	if (!m_model_info.m_texture_index_reader(file,m_environment_index))
		 return FALSE;
	if (!file->ReadChar(&m_environment_blend_mode))
		return FALSE;
	if (!file->ReadChar(&m_toon_reference))
		return FALSE;
	if (m_toon_reference == 0)
	{
		if (!m_model_info.m_texture_index_reader(file, m_toon_part))
		return FALSE;
	}
	else if (m_toon_reference == 1)
	{
		if (!file->ReadChar(&m_toon_internal))
			return FALSE;
	}
	if (!m_model_info.m_text_reader(file, m_meta_data))
		return FALSE;
	if (!file->ReadInt32(&m_surface_count))
		return FALSE;
	m_surface_count /= 3;
	return TRUE;
}

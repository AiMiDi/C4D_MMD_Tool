#include "pch.h"
#include "module/MMD/pmx_model_info_data.h"

void PMXModelInfoData::InitReader()
{
	m_text_reader = PMXTextReader(text_encoding);
	m_texture_index_reader = PMXIndexReader(texture_index_size);
	m_material_index_reader = PMXIndexReader(material_index_size);
	m_bone_index_reader = PMXIndexReader(bone_index_size);
	m_morph_index_reader = PMXIndexReader(morph_index_size);
	m_rigidbody_index_reader = PMXIndexReader(rigidbody_index_size);
}

Bool PMXModelInfoData::ReadFromFile(BaseFile* file)
{

	return true;
}

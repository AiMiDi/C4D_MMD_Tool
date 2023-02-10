/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & Walter White & CMT contributors.
Author:			Aimidi
Date:			2022/8/9
File:			pmx_weight.cpp
Description:	pmx weight data

**************************************************************************/

#include "pch.h"
#include "pmx_weight.h"

PMXWeight* PMXWeight::Alloc(const Char& type, const PMXModelInfo* index_reader)
{
	switch (type)
	{
	case 0:
		return NewObj(PMXWeight_BDEF1, index_reader).GetValue();
	case 1:
		return NewObj(PMXWeight_BDEF2, index_reader).GetValue();
	case 2:
		return NewObj(PMXWeight_BDEF4, index_reader).GetValue();
	case 3:
		return NewObj(PMXWeight_SDEF, index_reader).GetValue();
	case 4:
		return NewObj(PMXWeight_QDEF, index_reader).GetValue();
	default:
	{
		DebugStop("PMXWeight::Alloc type error!"_s);
		return nullptr;
	}
	}
}

inline Bool PMXWeight_BDEF1::ReadFromFile(BaseFile* file)
{
	if(!m_model_info->m_bone_index_reader(file, m_data->bone))
		return FALSE;
	return TRUE;
}
inline Bool PMXWeight_BDEF2::ReadFromFile(BaseFile* file)
{
	if(!m_model_info->m_bone_index_reader(file, m_data->bone[0]))
		return FALSE;
	if(!m_model_info->m_bone_index_reader(file, m_data->bone[1]))
		return FALSE;
	if (!file->ReadFloat32(&m_data->weight))
		return FALSE;
	return TRUE;
}
inline Bool PMXWeight_BDEF4::ReadFromFile(BaseFile* file)
{
	if(!m_model_info->m_bone_index_reader(file, m_data->bone[0]))
		return FALSE;
	if(!m_model_info->m_bone_index_reader(file, m_data->bone[1]))
		return FALSE;
	if(!m_model_info->m_bone_index_reader(file, m_data->bone[2]))
		return FALSE;
	if(!m_model_info->m_bone_index_reader(file, m_data->bone[3]))
		return FALSE;
	if (!file->ReadFloat32(&m_data->weight[0]))
		return FALSE;
	if (!file->ReadFloat32(&m_data->weight[1]))
		return FALSE;
	if (!file->ReadFloat32(&m_data->weight[2]))
		return FALSE;
	if (!file->ReadFloat32(&m_data->weight[3]))
		return FALSE;
	return TRUE;
}
inline Bool PMXWeight_SDEF::ReadFromFile(BaseFile* file)
{
	if(!m_model_info->m_bone_index_reader(file, m_data->bone[0]))
		return FALSE;
	if(!m_model_info->m_bone_index_reader(file, m_data->bone[1]))
		return FALSE;
	if (!file->ReadFloat32(&m_data->weight))
		return FALSE;
	if (!file->ReadVector32(&m_data->R0))
		return FALSE;
	if (!file->ReadVector32(&m_data->R1))
		return FALSE;
	if (!file->ReadVector32(&m_data->C))
		return FALSE;
	return TRUE;
}
inline Bool PMXWeight_QDEF::ReadFromFile(BaseFile* file)
{
	 if(!m_model_info->m_bone_index_reader(file, m_data->bone[0]))
		return FALSE;
	 if(!m_model_info->m_bone_index_reader(file, m_data->bone[1]))
		return FALSE;
	 if(!m_model_info->m_bone_index_reader(file, m_data->bone[2]))
		return FALSE;
	 if(!m_model_info->m_bone_index_reader(file, m_data->bone[3]))
		return FALSE;
	if (!file->ReadFloat32(&m_data->weight[0]))
		return FALSE;
	if (!file->ReadFloat32(&m_data->weight[1]))
		return FALSE;
	if (!file->ReadFloat32(&m_data->weight[2]))
		return FALSE;
	if (!file->ReadFloat32(&m_data->weight[3]))
		return FALSE;
	return TRUE;
}

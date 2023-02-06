/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & Walter White & CMT contributors.
Author:			Aimidi
Date:			2022/7/2
File:			pmx_data.cpp
Description:	pmx file data

**************************************************************************/

#include "pch.h"
#include "pmx.h"

PMX::PMX(String model_name_local, String model_name_universal):
	m_data(std::make_unique<data_type>(std::move(model_name_local), std::move(model_name_universal))){}

Bool PMX::LoadFromFile(Filename& fn)
{
	iferr_scope_handler{
#ifdef _DEBUG
		MessageDialog(err.ToString(nullptr));
#endif // _DEBUG	
		return FALSE;
	};

	AutoAlloc<BaseFile>	file;
	filename_util::SelectSuffixImportFile(fn, file, "pmx"_s);

	// read signature, value is "PMX "
	if (char signature[5]{ 0 }; !file->ReadBytes(signature, 4) && strncmp(signature, "PMX", 3) != 0)
	{
		ApplicationOutput("PMX::LoadFromFile() error at read signature."_s);
		return FALSE;
	}

	// read model info
	if(!m_data->model_info.ReadFromFile(file))
	{
		ApplicationOutput("PMX::LoadFromFile() error at read model info"_s);
		return FALSE;
	}

	// read vertex data
	if (!m_data->vertex_data.ReadFromFile(file))
	{
		ApplicationOutput("PMX::LoadFromFile() error at read vertex data"_s);
		return FALSE;
	}

	// read surface data
	if (!m_data->surface_data.ReadFromFile(file))
	{
		ApplicationOutput("PMX::LoadFromFile() error at read surface data"_s);
		return FALSE;
	}

	// read texture data
	if (!m_data->texture_data.ReadFromFile(file))
	{
		ApplicationOutput("PMX::LoadFromFile() error at read texture data"_s);
		return FALSE;
	}

	// read material data
	if (!m_data->material_data.ReadFromFile(file))
	{
		ApplicationOutput("PMX::LoadFromFile() error at read material data"_s);
		return FALSE;
	}

	// read bone data
	if (!m_data->bone_data.ReadFromFile(file))
	{
		ApplicationOutput("PMX::LoadFromFile() error at read bone data"_s);
		return FALSE;
	}

	// read morph data
	if (!m_data->morph_data.ReadFromFile(file))
	{
		ApplicationOutput("PMX::LoadFromFile() error at read morph data"_s);
		return FALSE;
	}

	// read rigid body data
	if (!m_data->rigid_body_data.ReadFromFile(file))
	{
		ApplicationOutput("PMX::LoadFromFile() error at read rigid body data"_s);
		return FALSE;
	}

	// read joint data
	if (!m_data->joint_data.ReadFromFile(file))
	{
		ApplicationOutput("PMX::LoadFromFile() error at read joint data"_s);
		return FALSE;
	}

	return TRUE;
}

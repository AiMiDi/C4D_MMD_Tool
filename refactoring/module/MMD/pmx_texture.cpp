/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & Walter White & CMT contributors.
Author:			Aimidi
Date:			2022/10/2
File:			pmx_texture.cpp
Description:	pmx texture data

**************************************************************************/


#include "pch.h"
#include "pmx_texture.h"

Bool PMXTexture::ReadFromFile(BaseFile* file)
{
	if (!m_model_info->m_text_reader(file, m_data->path))
		return FALSE;
	return TRUE;
}

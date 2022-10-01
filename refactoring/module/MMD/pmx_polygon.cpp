/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & Walter White & CMT contributors.
Author:			Aimidi
Date:			2022/10/2
File:			pmx_polygon.h
Description:	pmx polygon data

**************************************************************************/

#include "pch.h"
#include "pmx_polygon.h"

Bool PMXPolygon::ReadFromFile(BaseFile* file)
{
	if (!m_model_info->m_vertex_index_reader(file, m_data->a))
		return FALSE;
	if (!m_model_info->m_vertex_index_reader(file, m_data->b))
		return FALSE;
	if (!m_model_info->m_vertex_index_reader(file, m_data->c))
		return FALSE;
	return TRUE;
}

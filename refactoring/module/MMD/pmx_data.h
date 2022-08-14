/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & Walter White & CMT contributors.
Author:			Aimidi
Date:			2022/7/2
File:			pmx_data.h
Description:	pmx file data

**************************************************************************/

#ifndef _PMX_DATA_H_
#define _PMX_DATA_H_

#include "pch.h"

struct PMXDataCount
{
	Int32 vertex_data_count = 0;
	Int32 surface_data_count = 0;
	Int32 texture_data_count = 0;
	Int32 material_data_count = 0;
	Int32 bone_data_count = 0;
	Int32 morph_data_count = 0;
	Int32 display_data_count = 0;
	Int32 rigid_body_data_count = 0;
	Int32 joint_data_count = 0;
};

#endif // !_PMX_DATA_H_

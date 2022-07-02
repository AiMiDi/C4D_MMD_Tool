/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & Walter White & CMT contributors.
Author:			Aimidi
Date:			2022/7/2
File:			vpd_data.h
Description:	vpd file data

**************************************************************************/

#ifndef _VPD_DATA_H_
#define _VPD_DATA_H_

#include "pch.h"

/* VPD */
struct VPDBoneData
{
	String      name{};
	Vector32	translate{};
	Vector4d32	rotation{};
};
struct VPDMorphData
{
	String	    name{};
	Float32		weight{};
};
class VPDFile
{
	String model_name{};
	maxon::BaseArray<VPDBoneData> m_bones;
	maxon::BaseArray<VPDMorphData> m_morphs;
	MAXON_DISALLOW_COPY_AND_ASSIGN(VPDFile)
public:
	VPDFile() = default;
	~VPDFile()
	{
		m_bones.Reset();
		m_morphs.Reset();
	}
	/* 用于从文件导入到对象 */
	Bool LoadFromFile(const Filename& fn);
	/* 用于将对象保存到文件 */
	Bool SaveToFile(const Filename& fn) const;
};

#endif // !_VPD_DATA_H_
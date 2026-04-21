/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & CMT contributors.
Author:			Aimidi
Date:			2025/3/3
File:			mmd_display_frame.cpp
Description:	Display frame data (PMX display frame conversion, serialization)

**************************************************************************/

#include "module/core/cmt_old_sdk_stl_preload.h"
#include "mmd_model_manager.h"
#include "utils/io_util.hpp"
#include "utils/string_util.hpp"

using namespace io_util;

void DisplayFrameData::FromPMX(const libmmd::PMXDisplayFrame& pmx_frame)
{
	name = String(pmx_frame.m_name.c_str());
	name_universal = String(pmx_frame.m_englishName.c_str());
	is_special = (pmx_frame.m_flag == libmmd::PMXDisplayFrame::FrameType::SpecialFrame);
	iferr(targets.Resize(0)) return;
	for (const auto& t : pmx_frame.m_targets)
	{
		DisplayFrameTargetData td;
		td.type = (t.m_type == libmmd::PMXDisplayFrame::TargetType::BoneIndex)
			? DisplayFrameTargetType::Bone : DisplayFrameTargetType::Morph;
		td.index = t.m_index;
		iferr(targets.Append(td)) return;
	}
}

void DisplayFrameData::ToPMX(libmmd::PMXDisplayFrame& pmx_frame) const
{
	pmx_frame.m_name = string_util::GetStdString(name);
	pmx_frame.m_englishName = string_util::GetStdString(name_universal);
	pmx_frame.m_flag = is_special
		? libmmd::PMXDisplayFrame::FrameType::SpecialFrame
		: libmmd::PMXDisplayFrame::FrameType::DefaultFrame;
	pmx_frame.m_targets.clear();
	for (const auto& td : targets)
	{
		libmmd::PMXDisplayFrame::Target t;
		t.m_type = (td.type == DisplayFrameTargetType::Bone)
			? libmmd::PMXDisplayFrame::TargetType::BoneIndex
			: libmmd::PMXDisplayFrame::TargetType::MorphIndex;
		t.m_index = td.index;
		pmx_frame.m_targets.push_back(t);
	}
}

Bool DisplayFrameData::Read(HyperFile* hf)
{
	if (!ReadData(hf, name) || !ReadData(hf, name_universal))
		return false;
	if (!ReadData(hf, is_special))
		return false;
	Int32 count = 0;
	if (!ReadData(hf, count))
		return false;
	iferr(targets.Resize(count)) return false;
	for (Int32 i = 0; i < count; ++i)
	{
		Int32 type_val = 0;
		if (!ReadData(hf, type_val))
			return false;
		targets[i].type = static_cast<DisplayFrameTargetType>(type_val);
		if (!ReadData(hf, targets[i].index))
			return false;
	}
	return true;
}

Bool DisplayFrameData::Write(HyperFile* hf) const
{
	if (!WriteData(hf, name) || !WriteData(hf, name_universal))
		return false;
	if (!WriteData(hf, is_special))
		return false;
	const Int32 count = static_cast<Int32>(targets.GetCount());
	if (!WriteData(hf, count))
		return false;
	for (const auto& td : targets)
	{
		if (!WriteData(hf, static_cast<Int32>(td.type)))
			return false;
		if (!WriteData(hf, td.index))
			return false;
	}
	return true;
}

Bool DisplayFrameData::CopyTo(DisplayFrameData& dest) const
{
	dest.name = name;
	dest.name_universal = name_universal;
	dest.is_special = is_special;
	iferr(dest.targets.Resize(0)) return false;
	for (const auto& td : targets)
	{
		iferr(dest.targets.Append(td)) return false;
	}
	return true;
}

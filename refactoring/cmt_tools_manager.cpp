/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & Walter White & CMT contributors.
Author:			walter white/Aimidi
Date:			2022/7/31
File:			cmt_tools_manager.cpp
Description:	tools manager

**************************************************************************/

#include "pch.h"
#include "cmt_tools_manager.h"
#include "module/MMD/vmd.h"

namespace tools_manager
{
	bool ImportVMDCamera(const cmt_tools_setting::CameraImport& setting)
	{
		Filename vmd_fn;
		VMD vmd_animation;
		vmd_animation.LoadFromFile(vmd_fn);
		return true;
	}

	bool ExportVMDCamera(const cmt_tools_setting::CameraExport& setting)
	{
		Filename vmd_fn;
		VMD vmd_animation;
		vmd_animation.SaveToFile(vmd_fn);
		return true;
	}

	bool ImportVMDMotion(const cmt_tools_setting::MotionImport& setting)
	{
		return true;
	}

	bool ExportVMDMotion(const cmt_tools_setting::MotionExport& setting)
	{
		return true;
	}

	bool ImportPMXModel(const cmt_tools_setting::ModelImport& setting)
	{
		return true;
	}

	bool ExportPMXModel(const cmt_tools_setting::ModelExport& setting)
	{
		return true;
	}
}

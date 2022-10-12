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
	bool ImportVMDCamera(cmt_tools_setting::CameraImport& setting)
	{
		VMD vmd_animation;
		vmd_animation.LoadFromFile(setting.fn);
		return true;
	}

	bool ExportVMDCamera(cmt_tools_setting::CameraExport& setting)
	{
		VMD vmd_animation;
		vmd_animation.SaveToFile(setting.fn);
		return true;
	}

	bool ImportVMDMotion(cmt_tools_setting::MotionImport& setting)
	{
		return true;
	}

	bool ExportVMDMotion(cmt_tools_setting::MotionExport& setting)
	{
		return true;
	}

	bool ImportPMXModel(cmt_tools_setting::ModelImport& setting)
	{
		return true;
	}

	bool ExportPMXModel(cmt_tools_setting::ModelExport& setting)
	{
		return true;
	}
}

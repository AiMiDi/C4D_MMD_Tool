/**************************************************************************

Copyright:Copyright(c) 2023-present, Aimidi libMMD contributors.
Author:			walter white/Aimidi
Date:			2023/7/28
File:			cmt_tools_manager.cpp
Description:	tools manager

**************************************************************************/

#include "pch.h"
#include "cmt_tools_manager.h"

namespace tools_manager
{
	bool ImportVMDCamera(cmt_tools_setting::CameraImport& setting)
	{
		Filename vmd_filename;
		const std::string vmd_utf8_filename{ vmd_filename.GetString().GetCStringCopy(STRINGENCODING::UTF8) };
		libmmd::vmd_animation* vmd_animation = libmmd::create_vmd_animation();
		if (!vmd_animation->read_from_file(vmd_utf8_filename))
			return false;
		// TODO

		libmmd::delete_vmd_animation(&vmd_animation);
		return true;
	}

	bool ExportVMDCamera(cmt_tools_setting::CameraExport& setting)
	{
		Filename vmd_filename;
		const std::string vmd_utf8_filename{ vmd_filename.GetString().GetCStringCopy(STRINGENCODING::UTF8) };
		libmmd::vmd_animation* vmd_animation = libmmd::create_vmd_animation();
		if(!vmd_animation->write_to_file(vmd_utf8_filename))
			return false;
		// TODO

		libmmd::delete_vmd_animation(&vmd_animation);
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

/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & CMT contributors.
Author:			walter white/Aimidi
Date:			2022/7/31
File:			cmt_tools_manager.h
Description:	tools manager

**************************************************************************/

#pragma once

#include "cmt_tools_setting.h"

namespace CMTToolsManager
{
	bool ImportVMDCamera(const CMTToolsSetting::CameraImport& setting);
	bool ConversionCamera(const CMTToolsSetting::CameraConversion& setting);
	bool ExportVMDCamera(const CMTToolsSetting::CameraExport& setting);
	bool ImportVMDMotion(const CMTToolsSetting::MotionImport& setting, BaseObject* select_object = nullptr);
	bool ExportVMDMotion(const CMTToolsSetting::MotionExport& setting);
	bool ImportVPDPose(const CMTToolsSetting::PoseImport& setting, BaseObject* select_object = nullptr);
	bool ExportVPDPose(const CMTToolsSetting::PoseExport& setting, BaseObject* select_object = nullptr);
	bool ImportPMXModel (const CMTToolsSetting::ModelImport&  setting);
	bool ExportPMXModel (const CMTToolsSetting::ModelExport&  setting);
}

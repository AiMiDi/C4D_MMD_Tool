/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & CMT contributors.
Author:			walter white/Aimidi
Date:			2022/7/31
File:			cmt_tools_manager.h
Description:	tools manager

**************************************************************************/

#ifndef CMT_TOOLS_MANAGER_H__
#define CMT_TOOLS_MANAGER_H__

#include "cmt_tools_setting.h"

namespace CMTToolsManager 
{
	bool ImportVMDCamera(const CMTToolsSetting::CameraImport& setting);
	bool ConversionCamera(const CMTToolsSetting::CameraConversion& setting);
	bool ExportVMDCamera(const CMTToolsSetting::CameraExport& setting);
	bool ImportVMDMotion(const CMTToolsSetting::MotionImport& setting);
	bool ExportVMDMotion(const CMTToolsSetting::MotionExport& setting);
	bool ImportPMXModel (const CMTToolsSetting::ModelImport&  setting);
	bool ExportPMXModel (const CMTToolsSetting::ModelExport&  setting);
}	    

#endif // !CMT_TOOLS_MANAGER_H__

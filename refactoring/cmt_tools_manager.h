/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & Walter White & CMT contributors.
Author:			walter white/Aimidi
Date:			2022/7/31
File:			cmt_tools_manager.h
Description:	tools manager

**************************************************************************/

#ifndef _CMT_TOOLS_MANAGER_H_
#define _CMT_TOOLS_MANAGER_H_

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

#endif // !_CMT_TOOLS_MANAGER_H_

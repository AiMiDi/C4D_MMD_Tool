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

namespace tools_manager 
{
	bool ImportVMDCamera(cmt_tools_setting::CameraImport& setting);
	bool ExportVMDCamera(cmt_tools_setting::CameraExport& setting);
	bool ImportVMDMotion(cmt_tools_setting::MotionImport& setting);
	bool ExportVMDMotion(cmt_tools_setting::MotionExport& setting);
	bool ImportPMXModel (cmt_tools_setting::ModelImport&  setting);
	bool ExportPMXModel (cmt_tools_setting::ModelExport&  setting);
}

#endif // !_CMT_TOOLS_MANAGER_H_

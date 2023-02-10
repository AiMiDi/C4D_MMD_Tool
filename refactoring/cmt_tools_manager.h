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
	bool ImportVMDCamera(const cmt_tools_setting::CameraImport& setting);
	bool ExportVMDCamera(const cmt_tools_setting::CameraExport& setting);
	bool ImportVMDMotion(const cmt_tools_setting::MotionImport& setting);
	bool ExportVMDMotion(const cmt_tools_setting::MotionExport& setting);
	bool ImportPMXModel (const cmt_tools_setting::ModelImport&  setting);
	bool ExportPMXModel (const cmt_tools_setting::ModelExport&  setting);
}

#endif // !_CMT_TOOLS_MANAGER_H_

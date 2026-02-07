/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & CMT contributors.
Author:			Aimidi
Date:			2022/7/2
File:			vmd_loader_data.cpp
Description:	vmd data loader

**************************************************************************/

#include <c4d.h>
#include <c4d_symbols.h>
#include "plugin_resource.h"
#include "module/core/cmt_marco.h"
#include "vmd_loader.h"
#include <libMMD/Model/MMD/SjisToUnicode.h>
#include "module/ui/vmd_loader_camera_dialog.h"
#include "utils/filename_util.hpp"

Bool VMDLoaderData::Identify(BaseSceneLoader* node, const Filename& name, UChar* probe, Int32 size)
{
	Char VMDVersion[30]{ 0 };
	Char VMDModelName[20]{ 0 };
	CopyMem(probe, VMDVersion, 30);
	CopyMem(probe + 30, VMDModelName, 20);
	if (!filename_util::CheckSuffix(name, "vmd"_s))
	{
		return FALSE;
	}
	if (strncmp(VMDVersion, "Vocaloid Motion Data file", 25) != 0 || strncmp(VMDVersion, "Vocaloid Motion Data 0002", 25)!= 0)
	{
		// カメラ照明
		if (const auto u16_vmd_model_name = libmmd::ConvertSjisToU16String(VMDModelName);
			u16_vmd_model_name.find_first_of(u"\u30ab\u30e1\u30e9\u30fb\u7167\u660e") == 0)
		{
			m_is_camera = TRUE;
		}
		return TRUE;
	}
	return FALSE;
}

FILEERROR VMDLoaderData::Load(BaseSceneLoader* node, const Filename& name, BaseDocument* doc, SCENEFILTER filterflags,
	maxon::String* error, BaseThread* bt)
{
	if (m_is_camera)
	{
		VMDLoaderCameraDialog dlg_Camera(name, doc);
		dlg_Camera.Open(DLG_TYPE::MODAL, g_mmd_vmd_loader_id);
	}
	else {
		MessageDialog(GeLoadString(IDS_MES_IMPORT_VMD_CAM_ONLY));
	}
	return FILEERROR::NONE;
}

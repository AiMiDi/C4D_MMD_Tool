/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & Walter White & CMT contributors.
Author:			Aimidi
Date:			2022/7/2
File:			vmd_loader_data.cpp
Description:	vmd data loader

**************************************************************************/

#include "pch.h"
#include "vmd_loader_data.h"
#include "module/ui/vmd_loader_camera_dialog.h"

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
		const String ModelName = code_conversion::SJIStoUTF8(VMDModelName, 20);
		// カメラ・照明 
		if (ModelName.LexComparePart(L"\u30ab\u30e1\u30e9\u30fb\u7167\u660e"_s, 12, 0) == 0) 
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
		dlg_Camera.Open(DLG_TYPE::MODAL, ID_L_MMD_VMD_IMPORT, -1, -1, 350, 80);
	}
	else {
		MessageDialog(GeLoadString(IDS_MES_IMPORT_VMD_CAM_ONLY));
	}
	return FILEERROR::NONE;
}

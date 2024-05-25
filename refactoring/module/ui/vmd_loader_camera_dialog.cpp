/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & CMT contributors.
Author:			Aimidi
Date:			2022/7/1
File:			vmd_loader_camera_dialog.cpp
Description:	vmd data loader dialog

**************************************************************************/

#include "pch.h"
#include "vmd_loader_camera_dialog.h"

#include "cmt_tools_manager.h"
#include "cmt_tools_setting.h"

VMDLoaderCameraDialog::~VMDLoaderCameraDialog()
{
	DeleteObj(m_images);
}

Bool VMDLoaderCameraDialog::CreateLayout()
{
	// call default CreateLayout()
	if (!GeDialog::CreateLayout())
		return false;

	// load dialog from resource file
	if (!LoadDialogResource(DLG_CMT_VMD_IMPORT, nullptr, 0))
		return false;

	m_images = NewObj(ImagesUserArea, "mmd_tool_title.png"_s, 300, 95).GetValue();
	this->AttachUserArea((*m_images), DLG_CMT_TOOL_IMG);

	return TRUE;
}

Bool VMDLoaderCameraDialog::InitValues()
{
	SetFloat(DLG_CMT_TOOL_CAMERA_IMPORT_SIZE, 8.5);
	SetFloat(DLG_CMT_TOOL_CAMERA_IMPORT_OFFSET, 0);
	return TRUE;
}

Bool VMDLoaderCameraDialog::Command(Int32 id, const BaseContainer& msg)
{
	iferr_scope_handler{
		return FALSE;
	};
	switch (id)
	{
	case DLG_CMT_TOOL_CAMERA_IMPORT_BUTTON:
	{
		CMTToolsSetting::CameraImport setting(m_document);
		setting.fn = m_filename;
		GetFloat(DLG_CMT_TOOL_CAMERA_IMPORT_SIZE, setting.position_multiple);
		GetFloat(DLG_CMT_TOOL_CAMERA_IMPORT_OFFSET, setting.time_offset);
		CMTToolsManager::ImportVMDCamera(setting);
		Close();
		break;
	}
	case DLG_CMT_TOOL_CAMERA_CANCEL_BUTTON:
	{
		Close();
		break;
	}
	default:
		break;
	}
	return SUPER::Command(id, msg);
}

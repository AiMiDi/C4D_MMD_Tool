/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & Walter White & CMT contributors.
Author:			Aimidi
Date:			2022/7/1
File:			vmd_loader_camera_dialog.cpp
Description:	vmd data loader dialog

**************************************************************************/

#include "pch.h"
#include "vmd_loader_camera_dialog.h"

Bool VMDLoaderCameraDialog::CreateLayout()
{
	SetTitle(GeLoadString(DIG_CMT_TOOL_TITLE));
	m_images = NewObj(ImagesUserArea, "mmd_tool_title.png"_s, 300, 78).GetValue();
	C4DGadget* userAreaGadget = this->AddUserArea(999, BFH_SCALE, SizePix(300), SizePix(78));
	if (userAreaGadget != nullptr)
		this->AttachUserArea(*m_images, userAreaGadget);
	GroupBegin(1001, BFH_CENTER, 1, 2, GeLoadString(IDS_CMT_TOOL_CAMERA_IMPORT_GRP), 0, 0, 0);
	GroupBorder(BORDER_GROUP_IN);
	GroupBorderSpace(5, 5, 5, 10);
	GroupSpace(2, 5);

	GroupBegin(1002, BFH_LEFT, 2, 1, ""_s, 0, 350, 10);
	AddStaticText(100001, BFH_LEFT, 100, 10, GeLoadString(IDS_CMT_TOOL_SIZE), BORDER_NONE);
	AddEditNumberArrows(100002, BFH_LEFT, 250, 10);
	GroupEnd();

	GroupBegin(1003, BFH_LEFT, 2, 1, ""_s, 0, 350, 10);
	AddStaticText(100003, BFH_LEFT, 100, 10, GeLoadString(IDS_CMT_TOOL_OFFSET), BORDER_NONE);
	AddEditNumberArrows(100004, BFH_LEFT, 250, 10);
	GroupEnd();


	GroupBegin(1004, BFH_CENTER, 2, 1, ""_s, 0, 350, 10);
	GroupSpace(50, 0);
	AddButton(100005, BFH_CENTER, 100, 30, GeLoadString(IDS_CMT_TOOL_IMPORT_BUTTON));
	AddButton(100006, BFH_CENTER, 100, 30, GeLoadString(IDS_MSG_RENAME_CANCEL));
	GroupEnd();
	return TRUE;
}

Bool VMDLoaderCameraDialog::InitValues()
{
	SetFloat(100002, 8.5);
	SetFloat(100004, 0);
	return TRUE;
}

Bool VMDLoaderCameraDialog::Command(Int32 id, const BaseContainer& msg)
{
	iferr_scope_handler{
		return FALSE;
	};
	switch (id)
	{
	case 100005:
	{
		/*maxon::UniqueRef<VMDAnimation>	mmd_animation = NewObj(VMDAnimation)iferr_return;
		mmd_animation->m_camera_import_settings.fn = m_filename;
		mmd_animation->m_camera_import_settings.doc = m_document;
		GetFloat(100002, mmd_animation->m_camera_import_settings.position_multiple);
		GetFloat(100004, mmd_animation->m_camera_import_settings.time_offset);

		iferr(mmd_animation ->FromFileImportCamera())
		{
			return FALSE;
		}*/
		Close();
		break;
	}
	case 100006:
	{
		Close();
		break;
	}
	default:
		break;
	}
	return SUPER::Command(id, msg);
}

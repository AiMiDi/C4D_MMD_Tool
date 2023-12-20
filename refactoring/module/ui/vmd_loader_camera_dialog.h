/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & CMT contributors.
Author:			walter white
Date:			2022/6/30
File:			vmd_loader_camera_dialog.h
Description:	vmd data loader dialog

**************************************************************************/

#ifndef VMD_LOADER_DATA_DIALOG_H__
#define VMD_LOADER_DATA_DIALOG_H__

#include "pch.h"

class VMDLoaderCameraDialog final : public GeDialog
{
	Filename	m_filename;
	ImagesUserArea* m_images = nullptr;
	BaseDocument* m_document = nullptr;
	INSTANCEOF(VMDLoaderCameraDialog, GeDialog)
public:
	VMDLoaderCameraDialog(const Filename& fn, BaseDocument* doc) : m_filename(fn), m_document(doc){}
	~VMDLoaderCameraDialog() override;

	Bool CreateLayout() override;
	Bool InitValues() override;
	Bool Command(Int32 id, const BaseContainer& msg) override;
};

#endif // !VMD_LOADER_DATA_DIALOG_H__

/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & CMT contributors.
Author:			Aimidi
Date:			2022/7/33
File:			cmt_tools_dialog.h
Description:	CMT tools main dialog.

**************************************************************************/

#pragma once

#include <c4d.h>
#include <c4d_symbols.h>
#include "plugin_resource.h"
#include "module/core/cmt_marco.h"
#include "utils/images_user_area_util.hpp"
#include "motion_sizing_dialog.h"

class CMTToolDialog final : public GeDialog
{
	ImagesUserArea* m_images = nullptr;
public:
	CMTToolDialog() = default;
	~CMTToolDialog()override
	{
		DeleteObj(m_images);
	}
	CMTToolDialog(CMTToolDialog&&) = delete;
	void operator =(CMTToolDialog&&) = delete;
	MAXON_DISALLOW_COPY_AND_ASSIGN(CMTToolDialog)
		void GetItem(Int32 id, Float& value) const;
	void GetItem(Int32 id, Int32& value) const;
	void GetItem(Int32 id, Bool& value) const;
	Bool CreateLayout() override;
	Bool InitValues() override;
	Bool Command(Int32 id, const BaseContainer& msg) override;
};

class CMTToolCommand final : public CommandData
{
	CMTToolDialog cmd_tool_dialog;
	MotionSizingDialog sizing_dialog_;
	Bool TogglePanel();
	Bool ExecuteMenuItem(Int32 subid);
	Bool BuildSubmenu(BaseContainer& submenu);

public:
	Bool RestoreLayout(void* secret) override;
#if CMT_SDK_HAS_COMMANDDATA_EXECUTE_WITH_PARENT
	Bool Execute(BaseDocument* doc, GeDialog* parentManager) override
	{ return TogglePanel(); }
	Bool GetSubContainer(BaseDocument* doc, BaseContainer& submenu, GeDialog* parentManager) override
	{ return BuildSubmenu(submenu); }
	Bool ExecuteSubID(BaseDocument* doc, Int32 subid, GeDialog* parentManager) override
	{ return ExecuteMenuItem(subid); }
#else
	Bool Execute(BaseDocument* doc) override
	{ return TogglePanel(); }
	Bool GetSubContainer(BaseDocument* doc, BaseContainer& submenu) override
	{ return BuildSubmenu(submenu); }
	Bool ExecuteSubID(BaseDocument* doc, Int32 subid) override
	{ return ExecuteMenuItem(subid); }
#endif
};


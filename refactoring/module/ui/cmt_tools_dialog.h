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

public:
	Bool RestoreLayout(void* secret) override
	{
		return cmd_tool_dialog.RestoreLayout(g_cmt_command_id, 0, secret);
	}
#if API_VERSION >= 21000
	Bool Execute(BaseDocument* doc, GeDialog* parentManager) override
	{
		if (cmd_tool_dialog.IsOpen() == false)
			cmd_tool_dialog.Open(DLG_TYPE::ASYNC, DLG_CMT_TOOL);
		else
			cmd_tool_dialog.Close();
		return(true);
	}
#else
	Bool Execute(BaseDocument* doc) override
	{
		if (cmd_tool_dialog.IsOpen() == false)
			cmd_tool_dialog.Open(DLG_TYPE::ASYNC, DLG_CMT_TOOL);
		else
			cmd_tool_dialog.Close();
		return(true);
	}
#endif
};


/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & Walter White & CMT contributors.
Author:			Aimidi
Date:			2022/7/30
File:			cmt_tools_setting.cpp
Description:    CMT tools setting struct.

**************************************************************************/

#ifndef _CMT_TOOLS_SETTING_H_
#define _CMT_TOOLS_SETTING_H_

#include "pch.h"

namespace cmt_tools_setting
{
	struct CameraImport
	{
		Float		position_multiple = 8.5;
		Float		time_offset = 0;
		Filename	fn = Filename();
	};
	struct CameraExport
	{
		Float	position_multiple = 8.5;
		Float	time_offset = 0;
		Int32	use_rotation = 0;
		Bool    use_bake = true;
		Filename	fn = Filename();
	};
	struct CameraConversion {
		Float		distance = 0;
		Int32		use_rotation = 0;
		BaseObject* str_cam = nullptr;
	};
	struct MotionImport
	{
		Float	position_multiple = 8.5;
		Float	time_offset = 0;
		Bool    import_motion = true;
		Bool    import_morph = true;
		Bool    import_model_info = true;
		Bool	ignore_physical = true;
		Bool	delete_previous_animation = true;
		Bool	detail_report = false;
	};
	struct MotionExport
	{
		Float	position_multiple = 8.5;
		Float	time_offset = 0;
		Int32   use_rotation = 0;
		Bool    export_motion = true;
		Bool    export_morph = true;
		Bool    export_model_info = true;
		Bool    use_bake = true;
	};
	struct ModelImport
	{
		Float	position_multiple{};
		Bool	import_polygon{};
		Bool	import_normal{};
		Bool	import_uv{};
		Bool	import_material{};
		Bool	import_bone{};
		Bool	import_weights{};
		Bool	import_ik{};
		Bool	import_inherit{};
		Bool	import_expression{};
		Bool	import_multipart{};
		Bool	import_english{};
		Bool	import_english_check{};
	};
	struct ModelExport
	{
		Float	position_multiple{};
		Bool	export_polygon{};
		Bool	export_normal{};
		Bool	export_uv{};
		Bool	export_material{};
		Bool	export_bone{};
		Bool	export_weights{};
		Bool	export_ik{};
		Bool	export_inherit{};
		Bool	export_expression{};
	};
}

#endif //!_CMT_TOOLS_SETTING_H_

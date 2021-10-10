#ifndef __MMD_VPD_POSE_H__
#define __MMD_VPD_POSE_H__

#include "MMD_utility.h"
#include "description/TMMDBone.h"
#include <string>

namespace mmd {

	struct VPD_pose_import_settings {
		Float	position_multiple = 8.5;
		Bool    import_motion = true;
		Bool    import_morph = true;
	};
	struct VPD_post_export_settings {
		Float	position_multiple = 8.5;
		Bool    export_motion = true;
		Bool    export_morph = true;
	};

	class VPD_pose
	{		
		MAXON_DISALLOW_COPY_AND_ASSIGN(VPD_pose);
	private:	
		String model_name = String();
		maxon::PointerArray<VPD_Bone>	bones;
		maxon::PointerArray<VPD_Morph>	morphs;
		/* 用于从文件导入到对象 */
		maxon::Result<void> LoadFromFile(Filename& fn);
		/* 用于将对象保存到文件 */
		maxon::Result<void> SaveToFile(Filename& fn);
	public:
		/* 构造函数 */
		VPD_pose()
		{
		}
		/* 析构函数 */
		~VPD_pose()
		{
			bones.Reset();
			morphs.Reset();
		}
		/* 从文件导入姿势数据 */
		maxon::Result<void> FromFileImportPose(VPD_pose_import_settings setting);
		/* 从项目导出姿势数据 */
		maxon::Result<void> FromDocumentExportPose(VPD_post_export_settings setting);
	};
}

#endif // __MMD_VPD_POSE_H__

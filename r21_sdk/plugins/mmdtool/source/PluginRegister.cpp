#include "main.h"
#include "MMD_PMX_model.h"
#include "MMD_VMD_animation.h"
#include "MMD_PMX_tag.h"

enum                             // Uniquely identify all your dialog elements here.
{
	DLG_VMD_CAM_IMPORT_TITLE = 10000,
	DLG_VMD_CAM_IMPORT_SIZE,
	DLG_VMD_CAM_IMPORT_SIZE_NAME,
	DLG_VMD_CAM_IMPORT_OFFSET,
	DLG_VMD_CAM_IMPORT_OFFSET_NAME,
	DLG_VMD_CAM_IMPORT_BUTTON,

	DLG_VMD_CAM_EXPORT_TITLE,
	DLG_VMD_CAM_EXPORT_SIZE,
	DLG_VMD_CAM_EXPORT_SIZE_NAME,
	DLG_VMD_CAM_EXPORT_OFFSET,
	DLG_VMD_CAM_EXPORT_OFFSET_NAME,
	DLG_VMD_CAM_EXPORT_BUTTON,

	DLG_VMD_MOT_IMPORT_SIZE_NAME,
	DLG_VMD_MOT_IMPORT_SIZE,
	DLG_VMD_MOT_IMPORT_OFFSET_NAME,
	DLG_VMD_MOT_IMPORT_OFFSET,
	DLG_VMD_MOT_IMPORT_QUAT,
	DLG_VMD_MOT_IMPORT_DETAIL,
	DLG_VMD_MOT_IMPORT_BY_TAG,
	DLG_VMD_MOT_IMPORT_BUTTON,

	DLG_PMX_MOD_IMPORT_SIZE_NAME,
	DLG_PMX_MOD_IMPORT_SIZE,
	/*
	多边形Polygon  法线Normal
	UV             材质Material 
	骨骼Bone       权重Weights
	IK             付予Inherit 
	表情Expression 分部分Multipart
	*/
	DLG_PMX_MOD_IMPORT_POLYGON,//多边形Polygon
	DLG_PMX_MOD_IMPORT_NORMAL,//法线Normal
	DLG_PMX_MOD_IMPORT_UV,//UV
	DLG_PMX_MOD_IMPORT_MATERIAL,//材质Material 
	DLG_PMX_MOD_IMPORT_BONE,//骨骼Bone
	DLG_PMX_MOD_IMPORT_WEIGHTS,//权重Weights
	DLG_PMX_MOD_IMPORT_IK,//IK
	DLG_PMX_MOD_IMPORT_INHERIT,//付予Inherit 
	DLG_PMX_MOD_IMPORT_EXPRESSION,//表情Expression
	DLG_PMX_MOD_IMPORT_MULTIPART,//分部分Multipart
	DLG_PMX_MOD_IMPORT_ENGLISH,
	DLG_PMX_MOD_IMPORT_ENGLISH_CHECK,
	DLG_PMX_MOD_IMPORT_BUTTON,
};

class MMDToolDialog : public GeDialog 
{
public:
	MMDToolDialog(void) {}
	virtual ~MMDToolDialog(void) {}

	//----------
	//-- Set up dialog elements here:

	virtual Bool CreateLayout(void)
	{

		SetTitle(GeLoadString(IDS_VMD_TOOL_TITLE));

		BaseContainer settings;
		settings.SetBool(BITMAPBUTTON_BUTTON, false);
		void* const customGUI = AddCustomGui(999, CUSTOMGUI_BITMAPBUTTON, ""_s, BFH_SCALE, SizePix(300), SizePix(78), settings);
		BitmapButtonCustomGui* const bitmapButtonGUI = static_cast<BitmapButtonCustomGui*>(customGUI);
		if (bitmapButtonGUI)
		{
			bitmapButtonGUI->SetImage(AutoBitmap("mmd_tool_title.png"_s), true, false);
		}

		TabGroupBegin(1000, BFH_SCALEFIT | BFV_SCALEFIT);
		//CameraBegin
		GroupBegin(1100, BFH_CENTER, 1, 2, GeLoadString(IDS_VMD_CAM_TOOL_TITLE), 0, 350, 0);
		//ImportCameraBegin
		GroupBegin(1001, BFH_CENTER, 1, 2, GeLoadString(IDS_VMD_CAM_IMPORT_TITLE), 0, 0, 0);
		GroupBorder(BORDER_GROUP_IN);
		GroupBorderSpace(5, 5, 5, 10);
		GroupSpace(2, 5);

		GroupBegin(1002, BFH_LEFT, 2, 1, ""_s, 0, 350, 10);
		AddStaticText(DLG_VMD_CAM_IMPORT_SIZE_NAME, BFH_LEFT, 100, 10, GeLoadString(IDS_VMD_CAM_IMPORT_SIZE_NAME), BORDER_NONE);
		AddEditNumberArrows(DLG_VMD_CAM_IMPORT_SIZE, BFH_LEFT, 250, 10);
		GroupEnd();

		GroupBegin(1003, BFH_LEFT, 2, 1, ""_s, 0, 350, 10);
		AddStaticText(DLG_VMD_CAM_IMPORT_OFFSET_NAME, BFH_LEFT, 100, 10, GeLoadString(IDS_VMD_CAM_IMPORT_OFFSET_NAME), BORDER_NONE);
		AddEditNumberArrows(DLG_VMD_CAM_IMPORT_OFFSET, BFH_LEFT, 250, 10);
		GroupEnd();

		AddButton(DLG_VMD_CAM_IMPORT_BUTTON, BFH_CENTER, 300, 30, GeLoadString(IDS_VMD_CAM_IMPORT_BUTTON));
		GroupEnd();
		//ImportCameraEnd
		//ExportCameraBegin
		GroupBegin(1004, BFH_CENTER, 1, 2, GeLoadString(IDS_VMD_CAM_EXPORT_TITLE), 0, 0, 0);
		GroupBorder(BORDER_GROUP_IN);
		GroupBorderSpace(5, 5, 5, 10);
		GroupSpace(2, 5);

		GroupBegin(1005, BFH_LEFT, 2, 1, ""_s, 0, 350, 10);
		AddStaticText(DLG_VMD_CAM_EXPORT_SIZE_NAME, BFH_LEFT, 100, 10, GeLoadString(IDS_VMD_CAM_EXPORT_SIZE_NAME), BORDER_NONE);
		AddEditNumberArrows(DLG_VMD_CAM_EXPORT_SIZE, BFH_LEFT, 250, 10);
		GroupEnd();

		GroupBegin(1006, BFH_LEFT, 2, 1, ""_s, 0, 350, 10);
		AddStaticText(DLG_VMD_CAM_EXPORT_OFFSET_NAME, BFH_LEFT, 100, 10, GeLoadString(IDS_VMD_CAM_EXPORT_OFFSET_NAME), BORDER_NONE);
		AddEditNumberArrows(DLG_VMD_CAM_EXPORT_OFFSET, BFH_LEFT, 250, 10);
		GroupEnd();

		AddButton(DLG_VMD_CAM_EXPORT_BUTTON, BFH_CENTER, 300, 30, GeLoadString(IDS_VMD_CAM_EXPORT_BUTTON));
		GroupEnd();
		//ExportCameraEnd
		GroupEnd();
		//CameraEnd
		//MotionBegin
		GroupBegin(1200, BFH_CENTER, 1, 2, GeLoadString(IDS_VMD_MOT_TOOL_TITLE), 0, 350, 0);
		//ImportMotionBegin
		GroupBegin(1001, BFH_CENTER, 1, 2, GeLoadString(IDS_VMD_MOT_IMPORT_TITLE), 0, 0, 0);
		GroupBorder(BORDER_GROUP_IN);
		GroupBorderSpace(5, 5, 5, 10);
		GroupSpace(2, 5);

		GroupBegin(1002, BFH_LEFT, 2, 1, ""_s, 0, 350, 10);
		AddStaticText(DLG_VMD_MOT_IMPORT_SIZE_NAME, BFH_LEFT, 100, 10, GeLoadString(IDS_VMD_MOT_IMPORT_SIZE_NAME), BORDER_NONE);
		AddEditNumberArrows(DLG_VMD_MOT_IMPORT_SIZE, BFH_LEFT, 250, 10);
		GroupEnd();

		GroupBegin(1003, BFH_LEFT, 2, 1, ""_s, 0, 350, 10);
		AddStaticText(DLG_VMD_MOT_IMPORT_OFFSET_NAME, BFH_LEFT, 100, 10, GeLoadString(IDS_VMD_MOT_IMPORT_OFFSET_NAME), BORDER_NONE);
		AddEditNumberArrows(DLG_VMD_MOT_IMPORT_OFFSET, BFH_LEFT, 250, 10);
		GroupEnd();

		GroupBegin(1004, BFH_LEFT, 3, 1, ""_s, 0, 350, 10);
		AddCheckbox(DLG_VMD_MOT_IMPORT_QUAT, BFH_LEFT, 100, 0, GeLoadString(IDS_VMD_MOT_IMPORT_QUAT_NAME));
		AddCheckbox(DLG_VMD_MOT_IMPORT_DETAIL, BFH_LEFT, 100, 0, GeLoadString(IDS_VMD_MOT_IMPORT_DETAIL_NAME));
		AddCheckbox(DLG_VMD_MOT_IMPORT_BY_TAG, BFH_LEFT, 100, 0, GeLoadString(IDS_VMD_MOT_IMPORT_BY_TAG));
		GroupEnd();

		AddButton(DLG_VMD_MOT_IMPORT_BUTTON, BFH_CENTER, 300, 30, GeLoadString(IDS_VMD_MOT_IMPORT_BUTTON));
		GroupEnd();
		//ImportMotionEnd
		GroupEnd();
		//MotionEnd
		//ModelBegin
		GroupBegin(1300, BFH_CENTER, 1, 2, GeLoadString(IDS_PMX_MOD_TOOL_TITLE), 0, 350, 0);
		//ImportModelBegin
		GroupBegin(1005, BFH_CENTER, 1, 2, GeLoadString(IDS_PMX_MOD_IMPORT_TITLE), 0, 0, 0);
		GroupBorder(BORDER_GROUP_IN);
		GroupBorderSpace(5, 5, 5, 10);
		GroupSpace(2, 5);

		GroupBegin(1006, BFH_LEFT, 2, 1, ""_s, 0, 350, 10);
		AddStaticText(DLG_PMX_MOD_IMPORT_SIZE_NAME, BFH_LEFT, 100, 10, GeLoadString(IDS_PMX_MOD_IMPORT_SIZE_NAME), BORDER_NONE);
		AddEditNumberArrows(DLG_PMX_MOD_IMPORT_SIZE, BFH_LEFT, 250, 10);
		GroupEnd();

		GroupBegin(1007, BFH_CENTER, 2, 6, GeLoadString(IDS_PMX_MOD_IMPORT_SETTINGS), 0, 350, 0);
		GroupBorder(BORDER_GROUP_IN);
		GroupBorderSpace(5, 5, 5, 10);
		AddCheckbox(DLG_PMX_MOD_IMPORT_POLYGON, BFH_LEFT, 180, 13, GeLoadString(IDS_PMX_MOD_IMPORT_POLYGON));
		AddCheckbox(DLG_PMX_MOD_IMPORT_NORMAL, BFH_LEFT, 180, 13, GeLoadString(IDS_PMX_MOD_IMPORT_NORMAL));
		AddCheckbox(DLG_PMX_MOD_IMPORT_UV, BFH_LEFT, 180, 13, GeLoadString(IDS_PMX_MOD_IMPORT_UV));
		AddCheckbox(DLG_PMX_MOD_IMPORT_MATERIAL, BFH_LEFT, 180, 13, GeLoadString(IDS_PMX_MOD_IMPORT_MATERIAL));
		AddCheckbox(DLG_PMX_MOD_IMPORT_BONE, BFH_LEFT, 180, 13, GeLoadString(IDS_PMX_MOD_IMPORT_BONE));
		AddCheckbox(DLG_PMX_MOD_IMPORT_WEIGHTS, BFH_LEFT, 180, 13, GeLoadString(IDS_PMX_MOD_IMPORT_WEIGHTS));
		AddCheckbox(DLG_PMX_MOD_IMPORT_IK, BFH_LEFT, 180, 13, GeLoadString(IDS_PMX_MOD_IMPORT_IK));
		AddCheckbox(DLG_PMX_MOD_IMPORT_INHERIT, BFH_LEFT, 180, 13, GeLoadString(IDS_PMX_MOD_IMPORT_INHERIT));
		AddCheckbox(DLG_PMX_MOD_IMPORT_EXPRESSION, BFH_LEFT, 180, 13, GeLoadString(IDS_PMX_MOD_IMPORT_EXPRESSION));
		AddCheckbox(DLG_PMX_MOD_IMPORT_MULTIPART, BFH_LEFT, 180, 13, GeLoadString(IDS_PMX_MOD_IMPORT_MULTIPART));
		AddCheckbox(DLG_PMX_MOD_IMPORT_ENGLISH, BFH_LEFT, 180, 13, GeLoadString(IDS_PMX_MOD_IMPORT_ENGLISH));
		AddCheckbox(DLG_PMX_MOD_IMPORT_ENGLISH_CHECK, BFH_LEFT, 180, 13, GeLoadString(IDS_PMX_MOD_IMPORT_ENGLISH_CHECK));
		GroupEnd();
	
		AddButton(DLG_PMX_MOD_IMPORT_BUTTON, BFH_CENTER, 300, 30, GeLoadString(IDS_PMX_MOD_IMPORT_BUTTON));
		GroupEnd();
		//ImportModelEnd
		GroupEnd();
		//ModelEnd
		GroupEnd();
		return true;
	}

	//----------
	//-- Assign dialog elements their initial values here:

	virtual Bool InitValues(void)
	{
		SetFloat(DLG_VMD_CAM_IMPORT_SIZE, 8.5, 0, 100);
		SetFloat(DLG_VMD_CAM_IMPORT_OFFSET, 0);
		SetFloat(DLG_VMD_CAM_EXPORT_SIZE, 0.118, 0, 100);
		SetFloat(DLG_VMD_CAM_EXPORT_OFFSET, 0);
		SetFloat(DLG_VMD_MOT_IMPORT_SIZE, 8.5, 0, 100);
		SetFloat(DLG_VMD_MOT_IMPORT_OFFSET, 0);
		SetBool(DLG_VMD_MOT_IMPORT_QUAT, 1);
		SetBool(DLG_VMD_MOT_IMPORT_DETAIL, 0);
		SetBool(DLG_VMD_MOT_IMPORT_BY_TAG, 1);
		SetFloat(DLG_PMX_MOD_IMPORT_SIZE, 8.5, 0, 100);
		SetBool(DLG_PMX_MOD_IMPORT_POLYGON, 1);
		SetBool(DLG_PMX_MOD_IMPORT_NORMAL, 1);
		SetBool(DLG_PMX_MOD_IMPORT_UV, 1);
		SetBool(DLG_PMX_MOD_IMPORT_MATERIAL, 1);
		SetBool(DLG_PMX_MOD_IMPORT_BONE, 1);
		SetBool(DLG_PMX_MOD_IMPORT_WEIGHTS, 1);
		SetBool(DLG_PMX_MOD_IMPORT_IK, 1);
		SetBool(DLG_PMX_MOD_IMPORT_INHERIT, 1);
		SetBool(DLG_PMX_MOD_IMPORT_EXPRESSION, 1);
		SetBool(DLG_PMX_MOD_IMPORT_MULTIPART, 1);
		SetBool(DLG_PMX_MOD_IMPORT_ENGLISH, 0);
		SetBool(DLG_PMX_MOD_IMPORT_ENGLISH_CHECK, 0);
		return true;
	}

	//----------
	//-- Deal with any modification or "clicking" events here:

	virtual Bool Command(Int32 id, const BaseContainer &msg)
	{
		iferr_scope;
		switch (id)
		{
		case (DLG_VMD_CAM_IMPORT_BUTTON):
		{
			Float PositionMultiple_;
			Float TimeOffset_;
			GetFloat(DLG_VMD_CAM_IMPORT_SIZE, PositionMultiple_);
			GetFloat(DLG_VMD_CAM_IMPORT_OFFSET, TimeOffset_);
			iferr(mmd::VMDAnimation::FromFileImportCamera(PositionMultiple_, TimeOffset_))
			{
				return false;
			}
			break;
		}
		case (DLG_VMD_CAM_EXPORT_BUTTON):
		{
			Float PositionMultiple_;
			Float TimeOffset_;
			GetFloat(DLG_VMD_CAM_EXPORT_SIZE, PositionMultiple_);
			GetFloat(DLG_VMD_CAM_EXPORT_OFFSET, TimeOffset_);
			iferr(mmd::VMDAnimation::FromDocumentExportCamera(PositionMultiple_, TimeOffset_))
			{
				return false;
			}
			break;
		}
		case (DLG_VMD_MOT_IMPORT_BUTTON):
		{
			Float PositionMultiple_, TimeOffset_;
			Bool QuaternionRotationSW_, DetailReport_,ByTag_;
			GetFloat(DLG_VMD_MOT_IMPORT_SIZE, PositionMultiple_);
			GetFloat(DLG_VMD_MOT_IMPORT_OFFSET, TimeOffset_);
			GetBool(DLG_VMD_MOT_IMPORT_QUAT, QuaternionRotationSW_);
			GetBool(DLG_VMD_MOT_IMPORT_DETAIL, DetailReport_);
			GetBool(DLG_VMD_MOT_IMPORT_BY_TAG, ByTag_);
			iferr(mmd::VMDAnimation::FromFileImportMotions(PositionMultiple_, TimeOffset_, QuaternionRotationSW_, DetailReport_, ByTag_))
			{
				return false;
			}
			break;
		}
		case (DLG_PMX_MOD_IMPORT_BUTTON):
		{
			Float PositionMultiple_;
			GetFloat(DLG_PMX_MOD_IMPORT_SIZE, PositionMultiple_);
			mmd::PMX_Model_import_settings settings_;
			GetBool(DLG_PMX_MOD_IMPORT_POLYGON, settings_.Import_polygon);
			GetBool(DLG_PMX_MOD_IMPORT_NORMAL, settings_.Import_normal);
			GetBool(DLG_PMX_MOD_IMPORT_UV, settings_.Import_uv);
			GetBool(DLG_PMX_MOD_IMPORT_MATERIAL, settings_.Import_material);
			GetBool(DLG_PMX_MOD_IMPORT_BONE, settings_.Import_bone);
			GetBool(DLG_PMX_MOD_IMPORT_WEIGHTS, settings_.Import_weights);
			GetBool(DLG_PMX_MOD_IMPORT_IK, settings_.Import_ik);
			GetBool(DLG_PMX_MOD_IMPORT_INHERIT, settings_.Import_inherit);
			GetBool(DLG_PMX_MOD_IMPORT_EXPRESSION, settings_.Import_expression);
			GetBool(DLG_PMX_MOD_IMPORT_MULTIPART, settings_.Import_multipart);
			GetBool(DLG_PMX_MOD_IMPORT_ENGLISH, settings_.Import_english);
			GetBool(DLG_PMX_MOD_IMPORT_ENGLISH_CHECK, settings_.Import_english_check);
			iferr(mmd::PMXModel::FromFileImportModel(PositionMultiple_, settings_))
			{
				return false;
			}
			break;
		}
		case (DLG_PMX_MOD_IMPORT_BONE):
		{
			Bool Import_bone = 0;
			GetBool(DLG_PMX_MOD_IMPORT_BONE, Import_bone);

			if (Import_bone == 0) {
				SetBool(DLG_PMX_MOD_IMPORT_IK, 0);
				SetBool(DLG_PMX_MOD_IMPORT_INHERIT, 0);
				SetBool(DLG_PMX_MOD_IMPORT_WEIGHTS, 0);
				Enable(DLG_PMX_MOD_IMPORT_WEIGHTS, false);
				Enable(DLG_PMX_MOD_IMPORT_IK, false);
				Enable(DLG_PMX_MOD_IMPORT_INHERIT, false);
			}
			else {
				Enable(DLG_PMX_MOD_IMPORT_WEIGHTS, true);
				Enable(DLG_PMX_MOD_IMPORT_IK, true);
				Enable(DLG_PMX_MOD_IMPORT_INHERIT, true);
				SetBool(DLG_PMX_MOD_IMPORT_IK, 1);
				SetBool(DLG_PMX_MOD_IMPORT_INHERIT, 1);
				SetBool(DLG_PMX_MOD_IMPORT_WEIGHTS, 1);
			}
			break;
		}	
		case (DLG_PMX_MOD_IMPORT_POLYGON):
		{
			Bool Import_polygon = 0;
			GetBool(DLG_PMX_MOD_IMPORT_POLYGON, Import_polygon);

			if (Import_polygon == 0) {
				SetBool(DLG_PMX_MOD_IMPORT_NORMAL, 0);
				SetBool(DLG_PMX_MOD_IMPORT_UV, 0);
				SetBool(DLG_PMX_MOD_IMPORT_WEIGHTS, 0);
				SetBool(DLG_PMX_MOD_IMPORT_EXPRESSION, 0);
				Enable(DLG_PMX_MOD_IMPORT_WEIGHTS, false);
				Enable(DLG_PMX_MOD_IMPORT_NORMAL, false);
				Enable(DLG_PMX_MOD_IMPORT_UV, false);
				Enable(DLG_PMX_MOD_IMPORT_EXPRESSION, false);
			}
			else {
				Enable(DLG_PMX_MOD_IMPORT_WEIGHTS, true);
				Enable(DLG_PMX_MOD_IMPORT_NORMAL, true);
				Enable(DLG_PMX_MOD_IMPORT_UV, true);
				Enable(DLG_PMX_MOD_IMPORT_EXPRESSION, true);
				SetBool(DLG_PMX_MOD_IMPORT_EXPRESSION, 1);
				SetBool(DLG_PMX_MOD_IMPORT_NORMAL, 1);
				SetBool(DLG_PMX_MOD_IMPORT_UV, 1);
				SetBool(DLG_PMX_MOD_IMPORT_WEIGHTS, 1);
			}
			break;
		}
		case (DLG_PMX_MOD_IMPORT_ENGLISH):
		{
			Bool Import_english = 0;
			GetBool(DLG_PMX_MOD_IMPORT_ENGLISH, Import_english);

			if (Import_english == 0) {
				SetBool(DLG_PMX_MOD_IMPORT_ENGLISH_CHECK, 0);
			}
			else {
				SetBool(DLG_PMX_MOD_IMPORT_ENGLISH_CHECK, 1);
			}
			break;
		}
		}
		return true;
	}
};

class MMDTool : public CommandData
{
	MMDToolDialog mmd_tool_dialog;
public:
	virtual Bool Execute(BaseDocument* doc, GeDialog* parentManager) {
		if (mmd_tool_dialog.IsOpen() == false)
			mmd_tool_dialog.Open(DLG_TYPE::ASYNC, ID_MMD_TOOL);
		else
			mmd_tool_dialog.Close();
		return true;
	}
};

Bool RegisterPMXModelTag()
{
	return RegisterTagPlugin(ID_PMX_MODEL_TAG, GeLoadString(IDS_PMX_MODEL_TAG), TAG_ADDTOTAKEGROUP | TAG_VISIBLE , mmd::PMX_Model_Tag::Alloc, "PMX_Model_Tag"_s, AutoBitmap("MMDIcon.tif"_s), 0);
}

Bool RegisterPMXBoneTag()
{
	return RegisterTagPlugin(ID_PMX_BONE_TAG, GeLoadString(IDS_PMX_BONE_TAG), TAG_ADDTOTAKEGROUP | TAG_VISIBLE, mmd::PMX_Bone_Tag::Alloc, "PMX_Bone_Tag"_s, AutoBitmap("pmx_boen.tif"_s), 0);
}

/*
Bool RegisterPMXMaterialTag()
{
	return RegisterTagPlugin(ID_PMX_MATERIAL_TAG, GeLoadString(IDS_PMX_MATERIAL_TAG), TAG_EXPRESSION | TAG_VISIBLE, mmd::PMX_Material_Tag::Alloc, "PMX_Material_Tag"_s, AutoBitmap("pmx_material.tif"_s), 0);
}

Bool RegisterPMXDisplayTag()
{
	return RegisterTagPlugin(ID_PMX_DISPLAY_TAG, GeLoadString(IDS_PMX_DISPLAY_TAG), TAG_EXPRESSION | TAG_VISIBLE, mmd::PMX_Display_Tag::Alloc, "PMX_Display_Tag"_s, AutoBitmap("pmx_display.tif"_s), 0);
}

Bool RegisterPMXRigidTag()
{
	return RegisterTagPlugin(ID_PMX_RIGID_TAG, GeLoadString(IDS_PMX_RIGID_TAG), TAG_EXPRESSION | TAG_VISIBLE, mmd::PMX_Rigid_Tag::Alloc, "PMX_Rigid_Tag"_s, AutoBitmap("pmx_rigid.tif"_s), 0);
}

Bool RegisterPMXJointTag()
{
	return RegisterTagPlugin(ID_PMX_JOINT_TAG, GeLoadString(IDS_PMX_JOINT_TAG), TAG_EXPRESSION | TAG_VISIBLE, mmd::PMX_Joint_Tag::Alloc, "PMX_Joint_Tag"_s, AutoBitmap("pmx_joint.tif"_s), 0);
}
*/

Bool RegisterMMDTool() {
	return RegisterCommandPlugin(ID_MMD_TOOL, "MMDTool"_s, 0, AutoBitmap("MMDIcon.tif"_s), "MMD tool for C4D"_s, NewObjClear(MMDTool));
}

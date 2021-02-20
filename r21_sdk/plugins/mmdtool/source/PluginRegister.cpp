#include "main.h"
#include "MMD_PMX_model.h"
#include "MMD_VMD_animation.h"
#include "MMD_PMX_tag.h"

enum                                // Uniquely identify all your dialog elements here.
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
	DLG_VMD_MOT_IMPORT_BUTTON,

	DLG_PMX_MOD_IMPORT_SIZE_NAME,
	DLG_PMX_MOD_IMPORT_SIZE,
	DLG_PMX_MOD_IMPORT_MULTIPART,
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

		GroupBegin(1004, BFH_LEFT, 2, 1, ""_s, 0, 350, 10);
		AddCheckbox(DLG_VMD_MOT_IMPORT_QUAT, BFH_LEFT, 100, 0, GeLoadString(IDS_VMD_MOT_IMPORT_QUAT_NAME));
		AddCheckbox(DLG_VMD_MOT_IMPORT_DETAIL, BFH_LEFT, 100, 0, GeLoadString(IDS_VMD_MOT_IMPORT_DETAIL_NAME));
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

		AddCheckbox(DLG_PMX_MOD_IMPORT_MULTIPART, BFH_LEFT, 0, 0, GeLoadString(IDS_PMX_MOD_IMPORT_MULTIPART_NAME));

		AddButton(DLG_PMX_MOD_IMPORT_BUTTON, BFH_CENTER, 300, 30, GeLoadString(IDS_PMX_MOD_IMPORT_BUTTON));
		GroupEnd();
		//ImportModelEnd
		GroupEnd();
		//ModelEnd
		GroupEnd();
		return TRUE;
	}

	//----------
	//-- Assign dialog elements their initial values here:

	virtual Bool InitValues(void)
	{
		GeDialog::SetFloat(DLG_VMD_CAM_IMPORT_SIZE, 8.5, 0, 100);
		GeDialog::SetFloat(DLG_VMD_CAM_IMPORT_OFFSET, 0);
		GeDialog::SetFloat(DLG_VMD_CAM_EXPORT_SIZE, 0.118, 0, 100);
		GeDialog::SetFloat(DLG_VMD_CAM_EXPORT_OFFSET, 0);
		GeDialog::SetFloat(DLG_VMD_MOT_IMPORT_SIZE, 8.5, 0, 100);
		GeDialog::SetFloat(DLG_VMD_MOT_IMPORT_OFFSET, 0);
		GeDialog::SetBool(DLG_VMD_MOT_IMPORT_QUAT, 1);
		GeDialog::SetBool(DLG_VMD_MOT_IMPORT_DETAIL, 0);
		GeDialog::SetFloat(DLG_PMX_MOD_IMPORT_SIZE, 8.5, 0, 100);
		GeDialog::SetBool(DLG_PMX_MOD_IMPORT_MULTIPART, 1);
		return TRUE;
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
			GeDialog::GetFloat(DLG_VMD_CAM_IMPORT_SIZE, PositionMultiple_);
			GeDialog::GetFloat(DLG_VMD_CAM_IMPORT_OFFSET, TimeOffset_);
			iferr(mmd::VMDAnimation::FromFileImportCamera(PositionMultiple_, TimeOffset_))
			{
				return FALSE;
			}
			return TRUE;
		}
		case (DLG_VMD_CAM_EXPORT_BUTTON):
		{
			Float PositionMultiple_;
			Float TimeOffset_;
			GeDialog::GetFloat(DLG_VMD_CAM_EXPORT_SIZE, PositionMultiple_);
			GeDialog::GetFloat(DLG_VMD_CAM_EXPORT_OFFSET, TimeOffset_);
			iferr(mmd::VMDAnimation::FromDocumentExportCamera(PositionMultiple_, TimeOffset_))
			{
				return FALSE;
			}
			return TRUE;
		}
		case (DLG_VMD_MOT_IMPORT_BUTTON):
		{
			Float PositionMultiple_,TimeOffset_;
			Bool QuaternionRotationSW_, DetailReport_;
			GeDialog::GetFloat(DLG_VMD_MOT_IMPORT_SIZE, PositionMultiple_);
			GeDialog::GetFloat(DLG_VMD_MOT_IMPORT_OFFSET, TimeOffset_);
			GeDialog::GetBool(DLG_VMD_MOT_IMPORT_QUAT, QuaternionRotationSW_);
			GeDialog::GetBool(DLG_VMD_MOT_IMPORT_DETAIL, DetailReport_);
			iferr(mmd::VMDAnimation::FromFileImportMotions(PositionMultiple_, TimeOffset_, QuaternionRotationSW_, DetailReport_))
			{
				return FALSE;
			}
			return TRUE;
		}
		case (DLG_PMX_MOD_IMPORT_BUTTON):
		{
			Float PositionMultiple_;
			Bool Separate_ = 0;
			GeDialog::GetFloat(DLG_PMX_MOD_IMPORT_SIZE, PositionMultiple_);
			GeDialog::GetBool(DLG_PMX_MOD_IMPORT_MULTIPART, Separate_);
			iferr(mmd::PMXModel::FromFileImportModel(PositionMultiple_, Separate_))
			{
				return FALSE;
			}
			return TRUE;
		}
		}
		return TRUE;
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
		return TRUE;
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

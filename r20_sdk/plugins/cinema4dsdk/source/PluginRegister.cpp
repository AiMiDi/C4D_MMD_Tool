#include "main.h"
#include "MMD_PMX_model.h"
#include "MMD_VMD_animation.h"

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
	DLG_VMD_MOT_IMPORT_QUAT_NAME,
	DLG_VMD_MOT_IMPORT_QUAT,
	DLG_VMD_MOT_IMPORT_BUTTON,
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

		AddStaticText(DLG_VMD_CAM_IMPORT_TITLE, BFH_CENTER, 0, 15, "MMD Tool"_s, BORDER_NONE);

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
		AddButton(1, BFH_CENTER, 300, 30, "test"_s);
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

		AddCheckbox(DLG_VMD_MOT_IMPORT_QUAT, BFH_LEFT, 0, 0, GeLoadString(IDS_VMD_MOT_IMPORT_QUAT_NAME));

		AddButton(DLG_VMD_MOT_IMPORT_BUTTON, BFH_CENTER, 300, 30, GeLoadString(IDS_VMD_MOT_IMPORT_BUTTON));
		GroupEnd();
		//ImportMotionEnd
		GroupEnd();
		//MotionEnd
		GroupEnd();
		return TRUE;
	}

	//----------
	//-- Assign dialog elements their initial values here:

	virtual Bool InitValues(void)
	{
		this->SetFloat(DLG_VMD_CAM_IMPORT_SIZE, 8.5, 0, 100);
		this->SetFloat(DLG_VMD_CAM_IMPORT_OFFSET, 0);
		this->SetFloat(DLG_VMD_CAM_EXPORT_SIZE, 0.118, 0, 100);
		this->SetFloat(DLG_VMD_CAM_EXPORT_OFFSET, 0);
		this->SetFloat(DLG_VMD_MOT_IMPORT_SIZE, 8.5, 0, 100);
		this->SetFloat(DLG_VMD_MOT_IMPORT_OFFSET, 0);
		this->SetBool(DLG_VMD_MOT_IMPORT_QUAT, 1);
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
			this->GetFloat(DLG_VMD_CAM_IMPORT_SIZE, PositionMultiple_);
			this->GetFloat(DLG_VMD_CAM_IMPORT_OFFSET, TimeOffset_);
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
			this->GetFloat(DLG_VMD_CAM_EXPORT_SIZE, PositionMultiple_);
			this->GetFloat(DLG_VMD_CAM_EXPORT_OFFSET, TimeOffset_);
			iferr(mmd::VMDAnimation::FromDocumentExportCamera(PositionMultiple_, TimeOffset_))
			{
				return FALSE;
			}
			return TRUE;
		}
		case DLG_VMD_MOT_IMPORT_BUTTON:
		{
			Float PositionMultiple_;
			Float TimeOffset_;
			Bool QuaternionRotationSW_;
			this->GetFloat(DLG_VMD_MOT_IMPORT_SIZE, PositionMultiple_);
			this->GetFloat(DLG_VMD_MOT_IMPORT_OFFSET, TimeOffset_);
			this->GetBool(DLG_VMD_MOT_IMPORT_QUAT, QuaternionRotationSW_);
			iferr(mmd::VMDAnimation::FromFileImportMotions(PositionMultiple_, TimeOffset_, QuaternionRotationSW_))
			{
				return FALSE;
			}
			return TRUE;
		}
		case 1:
		{
			Float PositionMultiple_ = 10;
			Bool Separate_ = 0;
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
	virtual Bool Execute(BaseDocument* doc) {
		if (mmd_tool_dialog.IsOpen() == false)
			mmd_tool_dialog.Open(DLG_TYPE::ASYNC, 1056563, -1, -1, 0, 0);
		else
			mmd_tool_dialog.Close();
		return TRUE;
	}
};

Bool RegisterMMDTool() {
	return RegisterCommandPlugin(1056563, "MMDTool"_s, 0, AutoBitmap("MMDIcon.tif"_s), "MMD tool for C4D"_s, NewObjClear(MMDTool));
}
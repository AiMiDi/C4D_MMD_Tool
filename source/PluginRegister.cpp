#include "main.h"
#include "MMD_PMX_model.h"
#include "MMD_VMD_animation.h"
#include "MMD_PMX_Control.h"

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
	DLG_VMD_CAM_EXPORT_ROTATION_TWEEN_NAME,
	DLG_VMD_CAM_EXPORT_ROTATION_TWEEN,
	DLG_VMD_CAM_EXPORT_BUTTON,

	DLG_VMD_CAM_CONVER_DIS_NAME,
	DLG_VMD_CAM_CONVER_DIS,
	DLG_VMD_CAM_CONVER_ROTATION_TWEEN_NAME,
	DLG_VMD_CAM_CONVER_ROTATION_TWEEN,
	DLG_VMD_CAM_CONVER_BUTTON,


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

	DLG_ANIM_TOOL_FIX_ANIM_BUTTON,
};

class MMDToolDialog : public GeDialog
{
	ImagesGUI* Images = nullptr;
	std::string config_path = std::string((GeGetPluginResourcePath() + "config.yaml").GetString().GetCStringCopy(STRINGENCODING::UTF8));
public:
	MMDToolDialog() {	
	}
	virtual ~MMDToolDialog(void) {
		delete Images;
	}

	//----------
	//-- Set up dialog elements here:


	virtual Bool CreateLayout(void)
	{

		SetTitle(GeLoadString(IDS_VMD_TOOL_TITLE));
		Images = new ImagesGUI("mmd_tool_title.png"_s, 300, 78);
		C4DGadget* userAreaGadget = this->AddUserArea(999, BFH_SCALE, SizePix(300), SizePix(78));
		if (userAreaGadget != nullptr)
			this->AttachUserArea((*Images), userAreaGadget);

		TabGroupBegin(1000, BFH_SCALEFIT | BFV_SCALEFIT);
		//CameraBegin		
		GroupBegin(1100, BFH_CENTER, 1, 2, GeLoadString(IDS_VMD_CAM_TOOL_TITLE), 0, 350, 0);
		ScrollGroupBegin(1200, BFH_CENTER, SCROLLGROUP_VERT | SCROLLGROUP_BORDERIN, 0, 200);
		GroupBegin(1300, BFH_CENTER, 1, 2, ""_s, 0, 350, 0);
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

		GroupBegin(1007, BFH_LEFT, 2, 1, ""_s, 0, 350, 10);
		AddStaticText(DLG_VMD_CAM_EXPORT_ROTATION_TWEEN_NAME, BFH_LEFT, 100, 10, GeLoadString(IDS_VMD_CAM_EXPORT_ROTATION_TWEEN_NAME), BORDER_NONE);
		AddComboButton(DLG_VMD_CAM_EXPORT_ROTATION_TWEEN, BFH_LEFT, 242, 10);
		AddChild(DLG_VMD_CAM_EXPORT_ROTATION_TWEEN, 0, GeLoadString(IDS_VMD_CAM_EXPORT_ROTATION_TWEEN_X));
		AddChild(DLG_VMD_CAM_EXPORT_ROTATION_TWEEN, 1, GeLoadString(IDS_VMD_CAM_EXPORT_ROTATION_TWEEN_Y));
		AddChild(DLG_VMD_CAM_EXPORT_ROTATION_TWEEN, 2, GeLoadString(IDS_VMD_CAM_EXPORT_ROTATION_TWEEN_Z));
		GroupEnd();

		AddButton(DLG_VMD_CAM_EXPORT_BUTTON, BFH_CENTER, 300, 30, GeLoadString(IDS_VMD_CAM_EXPORT_BUTTON));
		GroupEnd();
		//ExportCameraEnd

		//ConversionCameraBegin
		GroupBegin(1008, BFH_CENTER, 1, 2, GeLoadString(IDS_VMD_CAM_CONVER_TITLE), 0, 0, 0);
		GroupBorder(BORDER_GROUP_IN);
		GroupBorderSpace(5, 5, 5, 10);
		GroupSpace(2, 5);

		GroupBegin(1009, BFH_LEFT, 2, 1, ""_s, 0, 350, 10);
		AddStaticText(DLG_VMD_CAM_CONVER_DIS_NAME, BFH_LEFT, 100, 10, GeLoadString(IDS_VMD_CAM_CONVER_DIS_NAME), BORDER_NONE);
		AddEditNumberArrows(DLG_VMD_CAM_CONVER_DIS, BFH_LEFT, 250, 10);
		GroupEnd();

		GroupBegin(1010, BFH_LEFT, 2, 1, ""_s, 0, 350, 10);
		AddStaticText(DLG_VMD_CAM_CONVER_ROTATION_TWEEN_NAME, BFH_LEFT, 100, 10, GeLoadString(IDS_VMD_CAM_CONVER_ROTATION_TWEEN_NAME), BORDER_NONE);
		AddComboButton(DLG_VMD_CAM_CONVER_ROTATION_TWEEN, BFH_LEFT, 242, 10);
		AddChild(DLG_VMD_CAM_CONVER_ROTATION_TWEEN, 0, GeLoadString(IDS_VMD_CAM_CONVER_ROTATION_TWEEN_X));
		AddChild(DLG_VMD_CAM_CONVER_ROTATION_TWEEN, 1, GeLoadString(IDS_VMD_CAM_CONVER_ROTATION_TWEEN_Y));
		AddChild(DLG_VMD_CAM_CONVER_ROTATION_TWEEN, 2, GeLoadString(IDS_VMD_CAM_CONVER_ROTATION_TWEEN_Z));
		GroupEnd();

		AddButton(DLG_VMD_CAM_CONVER_BUTTON, BFH_CENTER, 300, 30, GeLoadString(IDS_VMD_CAM_CONVER_BUTTON));
		GroupEnd();
		//ConversionCameraEnd
		GroupEnd();
		GroupEnd();
		GroupEnd();
		//CameraEnd
		//MotionBegin
		GroupBegin(1400, BFH_CENTER, 1, 2, GeLoadString(IDS_VMD_MOT_TOOL_TITLE), 0, 350, 0);
		//ImportMotionBegin
		GroupBegin(1101, BFH_CENTER, 1, 2, GeLoadString(IDS_VMD_MOT_IMPORT_TITLE), 0, 0, 0);
		GroupBorder(BORDER_GROUP_IN);
		GroupBorderSpace(5, 5, 5, 10);
		GroupSpace(2, 5);

		GroupBegin(1102, BFH_LEFT, 2, 1, ""_s, 0, 350, 10);
		AddStaticText(DLG_VMD_MOT_IMPORT_SIZE_NAME, BFH_LEFT, 100, 10, GeLoadString(IDS_VMD_MOT_IMPORT_SIZE_NAME), BORDER_NONE);
		AddEditNumberArrows(DLG_VMD_MOT_IMPORT_SIZE, BFH_LEFT, 250, 10);
		GroupEnd();

		GroupBegin(1103, BFH_LEFT, 2, 1, ""_s, 0, 350, 10);
		AddStaticText(DLG_VMD_MOT_IMPORT_OFFSET_NAME, BFH_LEFT, 100, 10, GeLoadString(IDS_VMD_MOT_IMPORT_OFFSET_NAME), BORDER_NONE);
		AddEditNumberArrows(DLG_VMD_MOT_IMPORT_OFFSET, BFH_LEFT, 250, 10);
		GroupEnd();

		GroupBegin(1104, BFH_LEFT, 3, 1, ""_s, 0, 350, 10);
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
		GroupBegin(1500, BFH_CENTER, 1, 2, GeLoadString(IDS_PMX_MOD_TOOL_TITLE), 0, 350, 0);
		//ImportModelBegin
		GroupBegin(1201, BFH_CENTER, 1, 2, GeLoadString(IDS_PMX_MOD_IMPORT_TITLE), 0, 0, 0);
		GroupBorder(BORDER_GROUP_IN);
		GroupBorderSpace(5, 5, 5, 10);
		GroupSpace(2, 5);

		GroupBegin(1202, BFH_LEFT, 2, 1, ""_s, 0, 350, 10);
		AddStaticText(DLG_PMX_MOD_IMPORT_SIZE_NAME, BFH_LEFT, 100, 10, GeLoadString(IDS_PMX_MOD_IMPORT_SIZE_NAME), BORDER_NONE);
		AddEditNumberArrows(DLG_PMX_MOD_IMPORT_SIZE, BFH_LEFT, 250, 10);
		GroupEnd();


		GroupBegin(1204, BFH_CENTER, 2, 6, GeLoadString(IDS_PMX_MOD_IMPORT_SETTINGS), 0, 350, 0);
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

		GroupBegin(1600, BFH_CENTER, 1, 1, GeLoadString(IDS_TOOL_GRP_TITLE), 0, 350, 0);
		//ToollBegin
		GroupBegin(1301, BFH_CENTER, 1, 1, GeLoadString(IDS_ANIM_TOOL_TITLE), 0, 0, 0);
		//AnimationBegin
		GroupBorder(BORDER_GROUP_IN);
		GroupBorderSpace(5, 5, 5, 10);
		GroupSpace(2, 5);
		AddButton(DLG_ANIM_TOOL_FIX_ANIM_BUTTON, BFH_CENTER, 350, 30, GeLoadString(IDS_ANIM_TOOL_FIX_ANIM_BUTTON));
		GroupEnd();
		//AnimationEnd
		GroupEnd();
		//ToolEnd

		GroupEnd();
		return true;
	}

	//----------
	//-- Assign dialog elements their initial values here:	
	
	YAML::Node LoadConfig() {
		try {		
			YAML::Node node(YAML::LoadFile(config_path));
			return node;
		}
		catch (YAML::BadFile) {
			GePrint("Failed to load the YAML file!"_s);
			YAML::Node node;
			std::ofstream fout(config_path);
			node["VMD_CAM_IMPORT_SIZE"] = 8.5;
			node["VMD_CAM_IMPORT_OFFSET"] = 0;
			node["VMD_CAM_EXPORT_SIZE"] = 8.5;
			node["VMD_CAM_EXPORT_OFFSET"] = 0;
			node["VMD_CAM_EXPORT_ROTATION_TWEEN"] = 0;
			node["VMD_CAM_CONVER_DIS"] = 0;
			node["VMD_CAM_CONVER_ROTATION_TWEEN"] = 0;
			node["VMD_MOT_IMPORT_SIZE"] = 8.5;
			node["VMD_MOT_IMPORT_OFFSET"] = 0;
			node["VMD_MOT_IMPORT_QUAT"] = true;
			node["VMD_MOT_IMPORT_DETAIL"] = false;
			node["VMD_MOT_IMPORT_BY_TAG"] = true;
			node["PMX_MOD_IMPORT_SIZE"] = 8.5;
			node["PMX_MOD_IMPORT_POLYGON"] = true;
			node["PMX_MOD_IMPORT_NORMAL"] = true;
			node["PMX_MOD_IMPORT_UV"] = true;
			node["PMX_MOD_IMPORT_MATERIAL"] = true;
			node["PMX_MOD_IMPORT_BONE"] = true;
			node["PMX_MOD_IMPORT_WEIGHTS"] = true;
			node["PMX_MOD_IMPORT_IK"] = true;
			node["PMX_MOD_IMPORT_INHERIT"] = true;
			node["PMX_MOD_IMPORT_EXPRESSION"] = true;
			node["PMX_MOD_IMPORT_MULTIPART"] = true;
			node["PMX_MOD_IMPORT_ENGLISH"] = false;
			node["PMX_MOD_IMPORT_ENGLISH_CHECK"] = false;
			fout << node;
			SetFloat(DLG_VMD_CAM_IMPORT_SIZE, 8.5, 0, 100);
			SetFloat(DLG_VMD_CAM_IMPORT_OFFSET, 0);
			SetFloat(DLG_VMD_CAM_EXPORT_SIZE, 8.5, 0, 100);
			SetFloat(DLG_VMD_CAM_EXPORT_OFFSET, 0);
			SetInt32(DLG_VMD_CAM_EXPORT_ROTATION_TWEEN, 0);
			SetFloat(DLG_VMD_CAM_CONVER_DIS, 0);
			SetInt32(DLG_VMD_CAM_CONVER_ROTATION_TWEEN, 0);
			SetFloat(DLG_VMD_MOT_IMPORT_SIZE, 8.5, 0, 100);
			SetFloat(DLG_VMD_MOT_IMPORT_OFFSET, 0);
			SetBool(DLG_VMD_MOT_IMPORT_QUAT, true);
			SetBool(DLG_VMD_MOT_IMPORT_DETAIL, false);
			SetBool(DLG_VMD_MOT_IMPORT_BY_TAG, true);
			SetFloat(DLG_PMX_MOD_IMPORT_SIZE, 8.5, 0, 100);
			SetBool(DLG_PMX_MOD_IMPORT_POLYGON, true);
			SetBool(DLG_PMX_MOD_IMPORT_NORMAL, true);
			SetBool(DLG_PMX_MOD_IMPORT_UV, true);
			SetBool(DLG_PMX_MOD_IMPORT_MATERIAL, true);
			SetBool(DLG_PMX_MOD_IMPORT_BONE, true);
			SetBool(DLG_PMX_MOD_IMPORT_WEIGHTS, true);
			SetBool(DLG_PMX_MOD_IMPORT_IK, true);
			SetBool(DLG_PMX_MOD_IMPORT_INHERIT, true);
			SetBool(DLG_PMX_MOD_IMPORT_EXPRESSION, true);
			SetBool(DLG_PMX_MOD_IMPORT_MULTIPART, true);
			SetBool(DLG_PMX_MOD_IMPORT_ENGLISH, false);
			SetBool(DLG_PMX_MOD_IMPORT_ENGLISH_CHECK, false);
			return node;
		}
	}

	virtual Bool InitValues(void)
	{
		YAML::Node config(LoadConfig());
		Bool updata = false;
		try {
			SetFloat(DLG_VMD_CAM_IMPORT_SIZE, config["VMD_CAM_IMPORT_SIZE"].as<float>(), 0, 100);
		}
		catch (YAML::BadConversion) {
			SetFloat(DLG_VMD_CAM_IMPORT_SIZE, 8.5, 0, 100);
			config["VMD_CAM_IMPORT_SIZE"] = 8.5;
			updata = true;
		}
		try {
			SetFloat(DLG_VMD_CAM_IMPORT_OFFSET, config["VMD_CAM_IMPORT_OFFSET"].as<float>());
		}
		catch (YAML::BadConversion) {
			SetFloat(DLG_VMD_CAM_IMPORT_OFFSET, 0);
			config["VMD_CAM_IMPORT_OFFSET"] = 0;
			updata = true;
		}
		try {
			SetFloat(DLG_VMD_CAM_EXPORT_SIZE, config["VMD_CAM_EXPORT_SIZE"].as<float>(), 0, 100);
		}
		catch (YAML::BadConversion) {
			SetFloat(DLG_VMD_CAM_EXPORT_SIZE, 8.5, 0, 100);
			config["VMD_CAM_EXPORT_SIZE"] = 8.5;
			updata = true;
		}
		try {
			SetFloat(DLG_VMD_CAM_EXPORT_OFFSET, config["VMD_CAM_EXPORT_OFFSET"].as<float>());
		}
		catch (YAML::BadConversion) {
			SetFloat(DLG_VMD_CAM_EXPORT_OFFSET, 0);
			config["VMD_CAM_EXPORT_OFFSET"] = 0;
			updata = true;
		}
		try {
			SetInt32(DLG_VMD_CAM_EXPORT_ROTATION_TWEEN, config["VMD_CAM_EXPORT_ROTATION_TWEEN"].as<int>());
		}
		catch (YAML::BadConversion) {

			SetInt32(DLG_VMD_CAM_EXPORT_ROTATION_TWEEN, 0);
			config["VMD_CAM_EXPORT_ROTATION_TWEEN"] = 0;
			updata = true;
		}
		try {
			SetFloat(DLG_VMD_CAM_CONVER_DIS, config["VMD_CAM_CONVER_DIS"].as<float>());
		}
		catch (YAML::BadConversion) {
			SetFloat(DLG_VMD_CAM_CONVER_DIS, 0);
			config["VMD_CAM_CONVER_DIS"] = 0;
			updata = true;
		}
		try {
			SetInt32(DLG_VMD_CAM_CONVER_ROTATION_TWEEN, config["VMD_CAM_CONVER_ROTATION_TWEEN"].as<int>());
		}
		catch (YAML::BadConversion) {
			SetInt32(DLG_VMD_CAM_CONVER_ROTATION_TWEEN, 0);
			config["VMD_CAM_CONVER_ROTATION_TWEEN"] = 0;
			updata = true;
		}
		try {
			SetFloat(DLG_VMD_MOT_IMPORT_SIZE, config["VMD_MOT_IMPORT_SIZE"].as<float>(), 0, 100);
		}
		catch (YAML::BadConversion) {
			SetFloat(DLG_VMD_MOT_IMPORT_SIZE, 8.5, 0, 100);
			config["VMD_MOT_IMPORT_SIZE"] = 8.5;
			updata = true;
		}
		try {
			SetFloat(DLG_VMD_MOT_IMPORT_OFFSET, config["VMD_MOT_IMPORT_OFFSET"].as<float>());
		}
		catch (YAML::BadConversion) {
			SetFloat(DLG_VMD_MOT_IMPORT_OFFSET, 0);
			config["VMD_MOT_IMPORT_OFFSET"] = 0;
			updata = true;
		}
		try {
			SetBool(DLG_VMD_MOT_IMPORT_QUAT, config["VMD_MOT_IMPORT_QUAT"].as<bool>());
		}
		catch (YAML::BadConversion) {
			SetBool(DLG_VMD_MOT_IMPORT_QUAT, true);
			config["VMD_MOT_IMPORT_QUAT"] = true;
			updata = true;
		}
		try {
			SetBool(DLG_VMD_MOT_IMPORT_DETAIL, config["VMD_MOT_IMPORT_DETAIL"].as<bool>());
		}
		catch (YAML::BadConversion) {
			SetBool(DLG_VMD_MOT_IMPORT_DETAIL, false);
			config["VMD_MOT_IMPORT_DETAIL"] = false;
			updata = true;
		}
		try {
			SetBool(DLG_VMD_MOT_IMPORT_BY_TAG, config["VMD_MOT_IMPORT_BY_TAG"].as<bool>());
		}
		catch (YAML::BadConversion) {
			SetBool(DLG_VMD_MOT_IMPORT_BY_TAG, true);
			config["VMD_MOT_IMPORT_BY_TAG"] = true;
			updata = true;
		}
		try {
			SetFloat(DLG_PMX_MOD_IMPORT_SIZE, config["PMX_MOD_IMPORT_SIZE"].as<float>(), 0, 100);
		}
		catch (YAML::BadConversion) {
			SetFloat(DLG_PMX_MOD_IMPORT_SIZE, 8.5, 0, 100);
			config["PMX_MOD_IMPORT_SIZE"] = 8.5;
			updata = true;
		}
		try {
			SetBool(DLG_PMX_MOD_IMPORT_POLYGON, config["PMX_MOD_IMPORT_POLYGON"].as<bool>());
		}
		catch (YAML::BadConversion) {
			SetBool(DLG_PMX_MOD_IMPORT_POLYGON, true);
			config["PMX_MOD_IMPORT_POLYGON"] = true;
			updata = true;
		}
		try {
			SetBool(DLG_PMX_MOD_IMPORT_NORMAL, config["PMX_MOD_IMPORT_NORMAL"].as<bool>());
		}
		catch (YAML::BadConversion) {
			SetBool(DLG_PMX_MOD_IMPORT_NORMAL, true);
			config["PMX_MOD_IMPORT_NORMAL"] = true;
			updata = true;
		}
		try {
			SetBool(DLG_PMX_MOD_IMPORT_UV, config["PMX_MOD_IMPORT_UV"].as<bool>());
		}
		catch (YAML::BadConversion) {
			SetBool(DLG_PMX_MOD_IMPORT_UV, true);
			config["PMX_MOD_IMPORT_UV"] = true;
			updata = true;
		}
		try {
			SetBool(DLG_PMX_MOD_IMPORT_MATERIAL, config["PMX_MOD_IMPORT_MATERIAL"].as<bool>());
		}
		catch (YAML::BadConversion) {
			SetBool(DLG_PMX_MOD_IMPORT_MATERIAL, true);
			config["PMX_MOD_IMPORT_MATERIAL"] = true;
			updata = true;
		}
		try {
			SetBool(DLG_PMX_MOD_IMPORT_BONE, config["PMX_MOD_IMPORT_BONE"].as<bool>());
		}
		catch (YAML::BadConversion) {
			SetBool(DLG_PMX_MOD_IMPORT_BONE, true);
			config["PMX_MOD_IMPORT_BONE"] = true;
			updata = true;
		}
		try {
			SetBool(DLG_PMX_MOD_IMPORT_WEIGHTS, config["PMX_MOD_IMPORT_WEIGHTS"].as<bool>());
		}
		catch (YAML::BadConversion) {
			SetBool(DLG_PMX_MOD_IMPORT_WEIGHTS, true);
			config["PMX_MOD_IMPORT_WEIGHTS"] = true;
			updata = true;
		}
		try {
			SetBool(DLG_PMX_MOD_IMPORT_IK, config["PMX_MOD_IMPORT_IK"].as<bool>());
		}
		catch (YAML::BadConversion) {
			SetBool(DLG_PMX_MOD_IMPORT_IK, true);
			config["PMX_MOD_IMPORT_IK"] = true;
			updata = true;
		}
		try {
			SetBool(DLG_PMX_MOD_IMPORT_INHERIT, config["PMX_MOD_IMPORT_INHERIT"].as<bool>());
		}
		catch (YAML::BadConversion) {
			SetBool(DLG_PMX_MOD_IMPORT_INHERIT, true);
			config["PMX_MOD_IMPORT_INHERIT"] = true;
			updata = true;
		}
		try {
			SetBool(DLG_PMX_MOD_IMPORT_EXPRESSION, config["PMX_MOD_IMPORT_EXPRESSION"].as<bool>());
		}
		catch (YAML::BadConversion) {
			SetBool(DLG_PMX_MOD_IMPORT_EXPRESSION, true);
			config["PMX_MOD_IMPORT_EXPRESSION"] = true;
			updata = true;
		}
		try {
			SetBool(DLG_PMX_MOD_IMPORT_MULTIPART, config["PMX_MOD_IMPORT_MULTIPART"].as<bool>());
		}
		catch (YAML::BadConversion) {
			SetBool(DLG_PMX_MOD_IMPORT_MULTIPART, true);
			config["PMX_MOD_IMPORT_MULTIPART"] = false;
			updata = true;
		}
		try {

			SetBool(DLG_PMX_MOD_IMPORT_ENGLISH, config["PMX_MOD_IMPORT_ENGLISH"].as<bool>());
		}
		catch (YAML::BadConversion) {
			SetBool(DLG_PMX_MOD_IMPORT_ENGLISH, false);
			config["PMX_MOD_IMPORT_ENGLISH"] = false;
			updata = true;
		}
		try {
			SetBool(DLG_PMX_MOD_IMPORT_ENGLISH_CHECK, config["PMX_MOD_IMPORT_ENGLISH_CHECK"].as<bool>());
		}
		catch (YAML::BadConversion) {
			SetBool(DLG_PMX_MOD_IMPORT_ENGLISH_CHECK, false);
			config["PMX_MOD_IMPORT_ENGLISH_CHECK"] = false;
			updata = true;
		}
		if (updata) {
			std::ofstream fout(config_path);
			fout << config;
		}
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
		Bool Import_english = 0;
		GetBool(DLG_PMX_MOD_IMPORT_ENGLISH, Import_english);
		if (Import_english == 0) {
			SetBool(DLG_PMX_MOD_IMPORT_ENGLISH_CHECK, 0);
		}
		else {
			SetBool(DLG_PMX_MOD_IMPORT_ENGLISH_CHECK, 1);
		}
		return true;
	}

	//----------
	//-- Deal with any modification or "clicking" events here:

	virtual Bool Command(Int32 id, const BaseContainer& msg)
	{
		iferr_scope;
		switch (id)
		{
		case DLG_VMD_CAM_IMPORT_BUTTON:
		{
			mmd::VMD_Camera_import_settings setting_;
			GetFloat(DLG_VMD_CAM_IMPORT_SIZE, setting_.PositionMultiple);
			GetFloat(DLG_VMD_CAM_IMPORT_OFFSET, setting_.TimeOffset);
			YAML::Node config(LoadConfig());
			config["VMD_CAM_IMPORT_SIZE"] = setting_.PositionMultiple;
			config["VMD_CAM_IMPORT_OFFSET"] = setting_.TimeOffset;
			std::ofstream fout(config_path);
			fout << config;
			iferr(mmd::VMDAnimation::FromFileImportCamera(setting_))
			{
				return false;
			}
			break;
		}
		case DLG_VMD_CAM_CONVER_BUTTON:
		{	
			mmd::VMD_Conversion_Camera_settings setting_;
			GetFloat(DLG_VMD_CAM_CONVER_DIS, setting_.distance);
			GetInt32(DLG_VMD_CAM_CONVER_ROTATION_TWEEN, setting_.use_rotation);
			YAML::Node config(LoadConfig());
			config["VMD_CAM_CONVER_DIS"] = setting_.distance;
			config["VMD_CAM_CONVER_ROTATION_TWEEN"] = setting_.use_rotation;
			std::ofstream fout(config_path);
			fout << config;
			iferr(mmd::OMMDCamera::ConversionCamera(setting_))
			{
				return false;
			}
			break;
		}
		case DLG_VMD_CAM_EXPORT_BUTTON:
		{
			mmd::VMD_Camera_export_settings setting_;
			GetFloat(DLG_VMD_CAM_EXPORT_SIZE, setting_.PositionMultiple);
			GetFloat(DLG_VMD_CAM_EXPORT_OFFSET, setting_.TimeOffset);
			GetInt32(DLG_VMD_CAM_EXPORT_ROTATION_TWEEN, setting_.use_rotation);
			YAML::Node config(LoadConfig());
			config["VMD_CAM_EXPORT_SIZE"] = setting_.PositionMultiple;
			config["VMD_CAM_EXPORT_OFFSET"] = setting_.TimeOffset;
			config["VMD_CAM_EXPORT_ROTATION_TWEEN"] = setting_.use_rotation;
			std::ofstream fout(config_path);
			fout << config;
			iferr(mmd::VMDAnimation::FromDocumentExportCamera(setting_))
			{
				return false;
			}
			break;
		}
		case DLG_VMD_MOT_IMPORT_BUTTON:
		{	
			mmd::VMD_Motions_import_settings setting_;
			GetFloat(DLG_VMD_MOT_IMPORT_SIZE, setting_.PositionMultiple);
			GetFloat(DLG_VMD_MOT_IMPORT_OFFSET, setting_.TimeOffset);
			GetBool(DLG_VMD_MOT_IMPORT_QUAT, setting_.QuaternionRotationSW);
			GetBool(DLG_VMD_MOT_IMPORT_DETAIL, setting_.DetailReport);
			GetBool(DLG_VMD_MOT_IMPORT_BY_TAG, setting_.ByTag);
			YAML::Node config(LoadConfig());
			config["VMD_MOT_IMPORT_SIZE"] = setting_.PositionMultiple;
			config["VMD_MOT_IMPORT_OFFSET"] = setting_.TimeOffset;
			config["VMD_MOT_IMPORT_QUAT"] = setting_.QuaternionRotationSW;
			config["VMD_MOT_IMPORT_DETAIL"] = setting_.DetailReport;
			config["VMD_MOT_IMPORT_BY_TAG"] = setting_.ByTag;
			std::ofstream fout(config_path);
			fout << config;
			iferr(mmd::VMDAnimation::FromFileImportMotions(setting_))
			{
				return false;
			}
			break;
		}
		case DLG_PMX_MOD_IMPORT_BUTTON:
		{				
			mmd::PMX_Model_import_settings setting_;
			GetFloat(DLG_PMX_MOD_IMPORT_SIZE, setting_.PositionMultiple);
			GetBool(DLG_PMX_MOD_IMPORT_POLYGON, setting_.Import_polygon);
			GetBool(DLG_PMX_MOD_IMPORT_NORMAL, setting_.Import_normal);
			GetBool(DLG_PMX_MOD_IMPORT_UV, setting_.Import_uv);
			GetBool(DLG_PMX_MOD_IMPORT_MATERIAL, setting_.Import_material);
			GetBool(DLG_PMX_MOD_IMPORT_BONE, setting_.Import_bone);
			GetBool(DLG_PMX_MOD_IMPORT_WEIGHTS, setting_.Import_weights);
			GetBool(DLG_PMX_MOD_IMPORT_IK, setting_.Import_ik);
			GetBool(DLG_PMX_MOD_IMPORT_INHERIT, setting_.Import_inherit);
			GetBool(DLG_PMX_MOD_IMPORT_EXPRESSION, setting_.Import_expression);
			GetBool(DLG_PMX_MOD_IMPORT_MULTIPART, setting_.Import_multipart);
			GetBool(DLG_PMX_MOD_IMPORT_ENGLISH, setting_.Import_english);
			GetBool(DLG_PMX_MOD_IMPORT_ENGLISH_CHECK, setting_.Import_english_check);
			YAML::Node config(LoadConfig());
			config["PMX_MOD_IMPORT_SIZE"] = setting_.PositionMultiple;
			config["PMX_MOD_IMPORT_POLYGON"] = setting_.Import_polygon;
			config["PMX_MOD_IMPORT_NORMAL"] = setting_.Import_normal;
			config["PMX_MOD_IMPORT_UV"] = setting_.Import_uv;
			config["PMX_MOD_IMPORT_MATERIAL"] = setting_.Import_material;
			config["PMX_MOD_IMPORT_BONE"] = setting_.Import_bone;
			config["PMX_MOD_IMPORT_WEIGHTS"] = setting_.Import_weights;
			config["PMX_MOD_IMPORT_IK"] = setting_.Import_ik;
			config["PMX_MOD_IMPORT_INHERIT"] = setting_.Import_inherit;
			config["PMX_MOD_IMPORT_EXPRESSION"] = setting_.Import_expression;
			config["PMX_MOD_IMPORT_MULTIPART"] = setting_.Import_multipart;
			config["PMX_MOD_IMPORT_ENGLISH"] = setting_.Import_english;
			config["PMX_MOD_IMPORT_ENGLISH_CHECK"] = setting_.Import_english_check;
			std::ofstream fout(config_path);
			fout << config;
			iferr(mmd::PMXModel::FromFileImportModel(setting_))
			{
				return false;
			}
			break;
		}
		case DLG_PMX_MOD_IMPORT_BONE:
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
		case DLG_PMX_MOD_IMPORT_POLYGON:
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
		case DLG_PMX_MOD_IMPORT_ENGLISH:
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
		case DLG_ANIM_TOOL_FIX_ANIM_BUTTON:
		{
			BaseDocument* doc = GetActiveDocument();
			if (doc == nullptr) {
				GePrint("error"_s);
				MessageDialog("error"_s);
				return true;
			}
			BaseObject* SelectObject = doc->GetActiveObject();
			if (SelectObject == nullptr) {
				GePrint(GeLoadString(IDS_MES_SELECT_ERR));
				MessageDialog(GeLoadString(IDS_MES_SELECT_ERR));
				return true;
			}

			maxon::Queue<BaseObject*> nodes;
			iferr(nodes.Push(SelectObject))return true;
			GeData data;
			while (!nodes.IsEmpty())
			{
				BaseObject* node = *(nodes.Pop());
				while (node != nullptr)
				{
					if (node->GetType() == Ojoint)
					{
							BaseTag* bone_tag = node->GetTag(ID_T_MMD_BONE);
							if (bone_tag != nullptr) {
								mmd::TMMDBone* pmx_bone_tag_data = bone_tag->GetNodeData<mmd::TMMDBone>();
								bone_tag->GetParameter(DescID(PMX_BONE_NAME_LOCAL), data, DESCFLAGS_GET::NONE);
								String bone_name = data.GetString();					
								if ((bone_name.LexComparePart(L"\u30b0\u30eb\u30fc\u30d6"_s, 5, 0) == 0) || (bone_name.LexComparePart(L"\u5168\u3066\u306e\u89aa"_s, 5, 0) == 0) || (bone_name.LexComparePart(L"\u8170"_s, 2, 0) == 0) || (bone_name.LexComparePart(L"\u8170\u30ad\u30e3\u30f3\u30bb\u30eb\u5de6"_s, 8, 0) == 0) || (bone_name.LexComparePart(L"\u8170\u30ad\u30e3\u30f3\u30bb\u30eb\u53f3"_s, 8, 0) == 0)) //グルーブ 全ての親 腰 腰キャンセル左 腰キャンセル右
								{
									CTrack* BoneTrackPX = node->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_X, DTYPE_REAL, 0)));
									CTrack::Free(BoneTrackPX);								
									CTrack* BoneTrackPY = node->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Y, DTYPE_REAL, 0)));
									CTrack::Free(BoneTrackPY);									
									CTrack* BoneTrackPZ = node->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Z, DTYPE_REAL, 0)));
									CTrack::Free(BoneTrackPZ);								
									CTrack* BoneTrackRX = node->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_X, DTYPE_REAL, 0)));
									CTrack::Free(BoneTrackRX);									
									CTrack* BoneTrackRY = node->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Y, DTYPE_REAL, 0)));
									CTrack::Free(BoneTrackRY);									
									CTrack* BoneTrackRZ = node->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Z, DTYPE_REAL, 0)));
									CTrack::Free(BoneTrackRZ);
									node->SetRelPos(Vector(0));
									node->SetRelRot(Vector(0));							
								}
							}
							else {
								String bone_name = node->GetName();
								if ((bone_name.LexComparePart(L"\u30b0\u30eb\u30fc\u30d6"_s, 5, 0) == 0) || (bone_name.LexComparePart(L"\u5168\u3066\u306e\u89aa"_s, 5, 0) == 0) || (bone_name.LexComparePart(L"\u8170"_s, 2, 0) == 0) || (bone_name.LexComparePart(L"\u8170\u30ad\u30e3\u30f3\u30bb\u30eb\u5de6"_s, 8, 0) == 0) || (bone_name.LexComparePart(L"\u8170\u30ad\u30e3\u30f3\u30bb\u30eb\u53f3"_s, 8, 0) == 0)) //グルーブ 全ての親 腰 腰キャンセル左 腰キャンセル右
								{
									CTrack* BoneTrackPX = node->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_X, DTYPE_REAL, 0)));
									CTrack::Free(BoneTrackPX);
									CTrack* BoneTrackPY = node->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Y, DTYPE_REAL, 0)));
									CTrack::Free(BoneTrackPY);
									CTrack* BoneTrackPZ = node->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Z, DTYPE_REAL, 0)));
									CTrack::Free(BoneTrackPZ);
									CTrack* BoneTrackRX = node->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_X, DTYPE_REAL, 0)));
									CTrack::Free(BoneTrackRX);
									CTrack* BoneTrackRY = node->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Y, DTYPE_REAL, 0)));
									CTrack::Free(BoneTrackRY);
									CTrack* BoneTrackRZ = node->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Z, DTYPE_REAL, 0)));
									CTrack::Free(BoneTrackRZ);
									node->SetRelPos(Vector(0));
									node->SetRelRot(Vector(0));
								}
							}
					}
					iferr(nodes.Push(node->GetDown()))return true;
					if (node != SelectObject) {
						node = node->GetNext();
					}
					else {
						break;
					}
				}
			}
			nodes.Reset();
			doc->SetTime(BaseTime(1, 30));
			doc->SetTime(BaseTime(0, 30));
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

Bool RegisterOMMDModelObject()
{
	return RegisterObjectPlugin(ID_O_MMD_MODEL, GeLoadString(IDS_O_MMD_MODEL), OBJECT_CALL_ADDEXECUTION, mmd::OMMDModel::Alloc, "OMMDModel"_s, AutoBitmap(1021433), 0);
}

Bool RegisterTMMDBone()
{
	return RegisterTagPlugin(ID_T_MMD_BONE, GeLoadString(IDS_T_MMD_BONE), TAG_VISIBLE | TAG_EXPRESSION, mmd::TMMDBone::Alloc, "TMMDBone"_s, AutoBitmap("TMMDBone.png"_s), 0);
}

Bool RegisterOMMDCamera()
{
	return RegisterObjectPlugin(ID_O_MMD_CAMERA, GeLoadString(IDS_O_MMD_CAMERA), OBJECT_CALL_ADDEXECUTION, mmd::OMMDCamera::Alloc, "OMMDCamera"_s, AutoBitmap("OMMDCamera.png"_s), 0);
}

Bool RegisterOMMDRigid()
{
	return RegisterObjectPlugin(ID_O_MMD_RIGID, GeLoadString(IDS_O_MMD_RIGID), OBJECT_CALL_ADDEXECUTION | PLUGINFLAG_HIDEPLUGINMENU , mmd::OMMDRigid::Alloc, "OMMDRigid"_s, AutoBitmap(Osphere), 0);
}
Bool RegisterOMMDJoint()
{
	return RegisterObjectPlugin(ID_O_MMD_JOINT, GeLoadString(IDS_O_MMD_JOINT), OBJECT_CALL_ADDEXECUTION | PLUGINFLAG_HIDEPLUGINMENU, mmd::OMMDJoint::Alloc, "OMMDJoint"_s, AutoBitmap(Ocube), 0);
}
Bool RegisterOMMDMeshRoot()
{
	return RegisterObjectPlugin(ID_O_MMD_MESH_ROOT, GeLoadString(IDS_O_MMD_MESH_ROOT), PLUGINFLAG_HIDEPLUGINMENU , mmd::OMMDMeshRoot::Alloc, "OMMDMeshRoot"_s, AutoBitmap(1022292), 0);
}
Bool RegisterOMMDBoneRoot()
{
	return RegisterObjectPlugin(ID_O_MMD_BONE_ROOT, GeLoadString(IDS_O_MMD_BONE_ROOT), PLUGINFLAG_HIDEPLUGINMENU , mmd::OMMDBoneRoot::Alloc, "OMMDBoneRoot"_s, AutoBitmap(1022292), 0);
}
Bool RegisterOMMDRigidRoot()
{
	return RegisterObjectPlugin(ID_O_MMD_RIGID_ROOT, GeLoadString(IDS_O_MMD_RIGID_ROOT), PLUGINFLAG_HIDEPLUGINMENU, mmd::OMMDRigidRoot::Alloc, "OMMDRigidRoot"_s, AutoBitmap(1022292), 0);
}
Bool RegisterOMMDJointRoot()
{
	return RegisterObjectPlugin(ID_O_MMD_JOINT_ROOT, GeLoadString(IDS_O_MMD_JOINT_ROOT), PLUGINFLAG_HIDEPLUGINMENU, mmd::OMMDJointRoot::Alloc, "OMMDJointRoot"_s, AutoBitmap(1022292), 0);
}
/*
Bool RegisterPMXMaterialTag()
{
	return RegisterTagPlugin(ID_T_MMD_MATERIAL, GeLoadString(IDS_T_MMD_MATERIAL), TAG_EXPRESSION | TAG_VISIBLE, mmd::PMX_Material_Tag::Alloc, "PMX_Material_Tag"_s, AutoBitmap("pmx_material.tif"_s), 0);
}

Bool RegisterPMXDisplayTag()
{
	return RegisterTagPlugin(ID_T_MMD_DISPLAY, GeLoadString(IDS_PMX_DISPLAY_TAG), TAG_EXPRESSION | TAG_VISIBLE, mmd::PMX_Display_Tag::Alloc, "PMX_Display_Tag"_s, AutoBitmap("pmx_display.tif"_s), 0);
}



Bool RegisterPMXJointTag()
{
	return RegisterTagPlugin(ID_PMX_JOINT_TAG, GeLoadString(IDS_PMX_JOINT_TAG), TAG_EXPRESSION | TAG_VISIBLE, mmd::PMX_Joint_Tag::Alloc, "PMX_Joint_Tag"_s, AutoBitmap("pmx_joint_obj.png"_s), 0);
}
*/

Bool RegisterVMDCamDrawSceneHook()
{
	return RegisterSceneHookPlugin(ID_S_MMD_CAM_DRAW, "VMD Cam Draw"_s, 0, mmd::VMD_Cam_Draw::Alloc, EXECUTIONPRIORITY_GENERATOR, 0);
}

Bool RegisterMMDTool() {
	return RegisterCommandPlugin(ID_MMD_TOOL, "MMDTool"_s, 0, AutoBitmap("MMDIcon.png"_s), "MMD tool for C4D"_s, NewObjClear(MMDTool));
}

Bool RegisterVMDImport()
{
	return RegisterSceneLoaderPlugin(ID_L_MMD_VMD_IMPORT, "VMD(.vmd)"_s, 0, mmd::VMDLoaderData::Alloc, "VMD import"_s);
}
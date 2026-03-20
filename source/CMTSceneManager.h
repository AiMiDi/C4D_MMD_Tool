/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & CMT contributors.
Author:			Aimidi
Date:			2022/7/31
File:			cmt_scene_manager.cpp
Description:	scene manager

**************************************************************************/

#pragma once

#include <c4d.h>
#include "maxon/baselist.h"
#include "c4d_baselinkarray.h"
#include "cmt_tools_setting.h"
#include "module/core/cmt_marco.h"
#include "libMMD/Model/MMD/PMXFile.h"
#include "libMMD/Model/MMD/VMDFile.h"
#include "libMMD/Model/MMD/VMDAnimation.h"
#include "libMMD/Model/MMD/VMDCameraAnimation.h"

struct IOLog
{
	maxon::TimeValue timing = maxon::TimeValue::GetTime();

	static void LogOutMem();
	static void LogReadFileErr();
	static void LogWriteFileErr();
};

struct LoadVmdCameraLog : IOLog
{
	UInt camera_frame_number;

	void LogOK();
	static void LogNotCameraError();
};

struct SaveVmdCameraLog : IOLog
{
	void LogOK();
};

struct ConversionVmdCameraLog : IOLog
{
	void LogOK();
};

struct LoadVmdMotionLog : IOLog
{
	UInt64 imported_bone_count = 0;
	UInt64 imported_morph_count = 0;
	UInt64 imported_motion_count = 0;

	maxon::BaseList<String> not_find_bone_name_list;
	maxon::BaseList<String> not_find_morph_name_list;

	void LogOK(Bool detail);
	static void LogNotMMDModelError();
	static void LogNotMotionError();
	static void LogSelectError();
};

struct SaveVmdMotionLog : IOLog
{
	UInt64 exported_bone_count = 0;
	UInt64 exported_morph_count = 0;
	UInt64 exported_frame_count = 0;

	void LogOK();
	static void LogNotMMDModelError();
	static void LogSelectError();
	static void LogNoAnimationError();
};

struct LoadModelLog : IOLog
{
	String model_name_local;
	String comments_local;
	String model_name_universal;
	String comments_universal;

	UInt vertex_data_count = 0;
	UInt surface_data_count = 0;
	UInt texture_data_count = 0;
	UInt material_data_count = 0;
	UInt bone_data_count = 0;
	UInt morph_data_count = 0;

	void Set(const MMDModelPtr& model, const libmmd::PMXFile& file, const CMTToolsSetting::ModelImport& setting);
	void LogOK();
	static void LogMMDDataPathErr();
	static void LogLoadModelErr();
};

struct SavePmxModelLog : IOLog
{

};

class CMTSceneManager final : public SceneHookData
{
	INSTANCEOF(CMTSceneManager, SceneHookData)
public:
	/**
	 * \brief Default constructor function
	 */
	explicit CMTSceneManager() = default;
	/**
	 * \brief Destructor function
	 */
	~CMTSceneManager() override = default;

	static NodeData* Alloc()
	{
		return NewObjClear(CMTSceneManager);
	}

	static BaseObject* LoadVMDCamera(const CMTToolsSetting::CameraImport& setting, std::unique_ptr<libmmd::VMDCameraAnimation> animation);
	static BaseObject* SaveVMDCamera(const CMTToolsSetting::CameraExport& setting, libmmd::VMDFile& data);
	static BaseObject* ConversionCamera(const CMTToolsSetting::CameraConversion& setting);

	static Bool LoadVMDMotion(const CMTToolsSetting::MotionImport& setting, const libmmd::VMDFile& vmd_file, LoadVmdMotionLog& log, BaseObject* select_object = nullptr);
	static Bool SaveVMDMotion(const CMTToolsSetting::MotionExport& setting,  libmmd::VMDFile&  data, SaveVmdMotionLog& log);

	static BaseObject* LoadPMXModel(const libmmd::PMXFile& pmx_file, const PMXModelPtr& pmx_model, const CMTToolsSetting::ModelImport& setting);
	static BaseObject* SavePMXModel(const CMTToolsSetting::ModelExport& setting, libmmd::PMXFile& data);

	void AddMMDCamera(SDK2024_Const BaseObject* camera);

	static CMTSceneManager* GetSceneManager(const BaseDocument* Document);

private:
	BaseLinkArray SceneCameraArray;

};

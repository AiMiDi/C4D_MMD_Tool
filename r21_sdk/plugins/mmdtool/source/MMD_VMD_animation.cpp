#include "MMD_VMD_animation.h"

mmd::VMDAnimation::VMDAnimation() {
	this->IsCamera = 0;
	this->MotionFrameNumber = 0;
	this->MorphFrameNumber = 0;
	this->CameraFrameNumber = 0;
	this->LightFrameNumber = 0;
}

mmd::VMDAnimation::~VMDAnimation()
{
	this->motion_frames.Reset();
	this->morph_frames.Reset();
	this->camera_frames.Reset();
	this->light_frames.Reset();
}

maxon::Result<void> mmd::VMDAnimation::LoadFromFile(BaseFile* const file)
{
	iferr_scope;
	Char VMDVersion[30]{ 0 };
	Char VMDModelName[20]{ 0 };
	mmd::VMD_Motion motion_frame;
	mmd::VMD_Morph morph_frame;
	mmd::VMD_Camera camera_frame;
	mmd::VMD_Light light_frame;
	if (!file->ReadBytes(VMDVersion, 30))return maxon::FAILED;
	if (!strncmp(VMDVersion, "Vocaloid Motion Data file", 26))
	{
		if (!file->ReadBytes(VMDModelName, 10))return maxon::FAILED;
		this->ModelName = EncodingConversion::JIStoUTF8(VMDModelName);
		if (!this->ModelName.LexComparePart("カメラ・照明"_s, 12, 0) == 0) {
			this->IsCamera = 1;
		}
		else {
			this->IsCamera = 0;
		}
	}
	else if (!strncmp(VMDVersion, "Vocaloid Motion Data 0002", 26))
	{
		if (!file->ReadBytes(VMDModelName, 20))return maxon::FAILED;
		this->ModelName = EncodingConversion::JIStoUTF8(VMDModelName);
		if (this->ModelName.LexComparePart("カメラ・照明"_s, 12, 0) == 0) {
			this->IsCamera = 1;
		}
		else {
			this->IsCamera = 0;
		}
		GePrint(this->ModelName +" "+ String::IntToString(this->IsCamera));
		if (!file->ReadUInt32(&(this->MotionFrameNumber)))return maxon::FAILED;
		for (UInt32 i = 0; i < this->MotionFrameNumber; i++) {
			//111 bytes
			Char bone_name[15]{ 0 };
			if (!file->ReadBytes(bone_name, 15))return maxon::FAILED;
			if (!file->ReadUInt32(&(motion_frame.frame_no)))return maxon::FAILED;
			if (!file->ReadFloat32(&(motion_frame.position.x)))return maxon::FAILED;
			if (!file->ReadFloat32(&(motion_frame.position.y)))return maxon::FAILED;
			if (!file->ReadFloat32(&(motion_frame.position.z)))return maxon::FAILED;
			if (!file->ReadFloat32(&(motion_frame.rotation.x)))return maxon::FAILED;
			if (!file->ReadFloat32(&(motion_frame.rotation.y)))return maxon::FAILED;
			if (!file->ReadFloat32(&(motion_frame.rotation.z)))return maxon::FAILED;
			if (!file->ReadFloat32(&(motion_frame.rotation.w)))return maxon::FAILED;
			if (!file->ReadUChar(&(motion_frame.XCurve.ax)))return maxon::FAILED;
			if (!file->Seek(3))return maxon::FAILED;
			if (!file->ReadUChar(&(motion_frame.XCurve.ay)))return maxon::FAILED;
			if (!file->Seek(3))return maxon::FAILED;
			if (!file->ReadUChar(&(motion_frame.XCurve.bx)))return maxon::FAILED;
			motion_frame.XCurve.bx = 127 - motion_frame.XCurve.bx;
			if (!file->Seek(3))return maxon::FAILED;
			if (!file->ReadUChar(&(motion_frame.XCurve.by)))return maxon::FAILED;
			motion_frame.XCurve.by = 127 - motion_frame.XCurve.by;
			if (!file->Seek(3))return maxon::FAILED;
			if (!file->ReadUChar(&(motion_frame.YCurve.ax)))return maxon::FAILED;
			if (!file->Seek(3))return maxon::FAILED;
			if (!file->ReadUChar(&(motion_frame.YCurve.ay)))return maxon::FAILED;
			if (!file->Seek(3))return maxon::FAILED;
			if (!file->ReadUChar(&(motion_frame.YCurve.bx)))return maxon::FAILED;
			motion_frame.YCurve.bx = 127 - motion_frame.YCurve.bx;
			if (!file->Seek(3))return maxon::FAILED;
			if (!file->ReadUChar(&(motion_frame.YCurve.by)))return maxon::FAILED;
			motion_frame.YCurve.by = 127 - motion_frame.YCurve.by;
			if (!file->Seek(3))return maxon::FAILED;
			if (!file->ReadUChar(&(motion_frame.ZCurve.ax)))return maxon::FAILED;
			if (!file->Seek(3))return maxon::FAILED;
			if (!file->ReadUChar(&(motion_frame.ZCurve.ay)))return maxon::FAILED;
			if (!file->Seek(3))return maxon::FAILED;
			if (!file->ReadUChar(&(motion_frame.ZCurve.bx)))return maxon::FAILED;
			motion_frame.ZCurve.bx = 127 - motion_frame.ZCurve.bx;
			if (!file->Seek(3))return maxon::FAILED;
			if (!file->ReadUChar(&(motion_frame.ZCurve.by)))return maxon::FAILED;
			motion_frame.ZCurve.by = 127 - motion_frame.ZCurve.by;
			if (!file->Seek(3))return maxon::FAILED;
			if (!file->ReadUChar(&(motion_frame.RCurve.ax)))return maxon::FAILED;
			if (!file->Seek(3))return maxon::FAILED;
			if (!file->ReadUChar(&(motion_frame.RCurve.ay)))return maxon::FAILED;
			if (!file->Seek(3))return maxon::FAILED;
			if (!file->ReadUChar(&(motion_frame.RCurve.bx)))return maxon::FAILED;
			motion_frame.RCurve.bx = 127 - motion_frame.RCurve.bx;
			if (!file->Seek(3))return maxon::FAILED;
			if (!file->ReadUChar(&(motion_frame.RCurve.by)))return maxon::FAILED;
			motion_frame.RCurve.by = 127 - motion_frame.RCurve.by;
			if (!file->Seek(3))return maxon::FAILED;
			motion_frame.bone_name = EncodingConversion::JIStoUTF8(bone_name);
			this->motion_frames.Append(motion_frame)iferr_return;
		}

		if (!file->ReadUInt32(&(this->MorphFrameNumber)))return maxon::FAILED;
		for (UInt32 i = 0; i < this->MorphFrameNumber; i++) {
			//23 bytes
			Char morph_name[15]{ 0 };
			if (!file->ReadBytes(morph_name, 15))return maxon::FAILED;
			if (!file->ReadUInt32(&(morph_frame.frame_no)))return maxon::FAILED;
			if (!file->ReadFloat32(&(morph_frame.weight)))return maxon::FAILED;
			morph_frame.morph_name = EncodingConversion::JIStoUTF8(morph_name);
			this->morph_frames.Append(morph_frame)iferr_return;
		}
		if (!file->ReadUInt32(&(this->CameraFrameNumber)))return maxon::FAILED;
		for (UInt32 i = 0; i < this->CameraFrameNumber; i++) {
			//61 bytes
			if (!file->ReadUInt32(&(camera_frame.frame_no)))return maxon::FAILED;
			if (!file->ReadFloat32(&(camera_frame.distance)))return maxon::FAILED;
			if (!file->ReadFloat32(&(camera_frame.position.x)))return maxon::FAILED;
			if (!file->ReadFloat32(&(camera_frame.position.y)))return maxon::FAILED;
			if (!file->ReadFloat32(&(camera_frame.position.z)))return maxon::FAILED;
			if (!file->ReadFloat32(&(camera_frame.rotation.y)))return maxon::FAILED;
			if (!file->ReadFloat32(&(camera_frame.rotation.x)))return maxon::FAILED;
			if (!file->ReadFloat32(&(camera_frame.rotation.z)))return maxon::FAILED;
			if (!file->ReadUChar(&(camera_frame.XCurve.ax)))return maxon::FAILED;
			if (!file->ReadUChar(&(camera_frame.XCurve.ay)))return maxon::FAILED;
			if (!file->ReadUChar(&(camera_frame.XCurve.bx)))return maxon::FAILED;
			camera_frame.XCurve.bx = 127 - camera_frame.XCurve.bx;
			if (!file->ReadUChar(&(camera_frame.XCurve.by)))return maxon::FAILED;
			camera_frame.XCurve.by = 127 - camera_frame.XCurve.by;
			if (!file->ReadUChar(&(camera_frame.YCurve.ax)))return maxon::FAILED;
			if (!file->ReadUChar(&(camera_frame.YCurve.ay)))return maxon::FAILED;
			if (!file->ReadUChar(&(camera_frame.YCurve.bx)))return maxon::FAILED;
			camera_frame.YCurve.bx = 127 - camera_frame.YCurve.bx;
			if (!file->ReadUChar(&(camera_frame.YCurve.by)))return maxon::FAILED;
			camera_frame.YCurve.by = 127 - camera_frame.YCurve.by;
			if (!file->ReadUChar(&(camera_frame.ZCurve.ax)))return maxon::FAILED;
			if (!file->ReadUChar(&(camera_frame.ZCurve.ay)))return maxon::FAILED;
			if (!file->ReadUChar(&(camera_frame.ZCurve.bx)))return maxon::FAILED;
			camera_frame.ZCurve.bx = 127 - camera_frame.ZCurve.bx;
			if (!file->ReadUChar(&(camera_frame.ZCurve.by)))return maxon::FAILED;
			camera_frame.ZCurve.by = 127 - camera_frame.ZCurve.by;
			if (!file->ReadUChar(&(camera_frame.RCurve.ax)))return maxon::FAILED;
			if (!file->ReadUChar(&(camera_frame.RCurve.ay)))return maxon::FAILED;
			if (!file->ReadUChar(&(camera_frame.RCurve.bx)))return maxon::FAILED;
			camera_frame.RCurve.bx = 127 - camera_frame.RCurve.bx;
			if (!file->ReadUChar(&(camera_frame.RCurve.by)))return maxon::FAILED;
			camera_frame.RCurve.by = 127 - camera_frame.RCurve.by;
			if (!file->ReadUChar(&(camera_frame.DCurve.ax)))return maxon::FAILED;
			if (!file->ReadUChar(&(camera_frame.DCurve.ay)))return maxon::FAILED;
			if (!file->ReadUChar(&(camera_frame.DCurve.bx)))return maxon::FAILED;
			camera_frame.DCurve.bx = 127 - camera_frame.DCurve.bx;
			if (!file->ReadUChar(&(camera_frame.DCurve.by)))return maxon::FAILED;
			camera_frame.DCurve.by = 127 - camera_frame.DCurve.by;
			if (!file->ReadUChar(&(camera_frame.VCurve.ax)))return maxon::FAILED;
			if (!file->ReadUChar(&(camera_frame.VCurve.ay)))return maxon::FAILED;
			if (!file->ReadUChar(&(camera_frame.VCurve.bx)))return maxon::FAILED;
			camera_frame.VCurve.bx = 127 - camera_frame.VCurve.bx;
			if (!file->ReadUChar(&(camera_frame.VCurve.by)))return maxon::FAILED;
			camera_frame.VCurve.by = 127 - camera_frame.VCurve.by;
			if (!file->ReadUInt32(&(camera_frame.viewing_angle)))return maxon::FAILED;
			if (!file->ReadUChar(&(camera_frame.perspective)))return maxon::FAILED;
			this->camera_frames.Append(camera_frame)iferr_return;
		}

		if (!file->ReadUInt32(&(this->LightFrameNumber)))return maxon::FAILED;
		for (UInt32 i = 0; i < this->LightFrameNumber; i++) {
			//28 bytes
			if (!file->ReadBytes(&light_frame, 28))return maxon::FAILED;
			this->light_frames.Append(light_frame)iferr_return;
		}
	}
	else
	{
		GePrint("File corruption or unknown version"_s);
		MessageDialog("Import failed; File corruption or unknown version"_s);
		return maxon::UnexpectedError(MAXON_SOURCE_LOCATION, "File corruption or unknown version"_s);
	}
	return maxon::OK;
}

maxon::Result<void> mmd::VMDAnimation::WriteToFile(BaseFile* const file) {
	const Char VMDVersion[30] = "Vocaloid Motion Data 0002\0\0\0\0";
	if (!file->WriteBytes(VMDVersion, 30)) {
		MessageDialog("Write VMDVersion to file failed: Write file error"_s);
		return maxon::UnexpectedError(MAXON_SOURCE_LOCATION, "Write file error"_s);
	}
	Char* VMDModelName = EncodingConversion::UTF8toJIS(this->ModelName);
	if (!file->WriteBytes(VMDModelName, 20)) {
		GePrint("Write file error"_s);
		MessageDialog("Write ModelName to file failed: Write file error"_s);
		return maxon::UnexpectedError(MAXON_SOURCE_LOCATION, "Write file error"_s);
	}
	if (!file->WriteUInt32(this->MotionFrameNumber)) {
		GePrint("Write file error"_s);
		MessageDialog("Write MotionFrameNumber to file failed: Write file error"_s);
		return maxon::UnexpectedError(MAXON_SOURCE_LOCATION, "Write file error"_s);
	}
	for (UInt32 i = 0; i < this->MotionFrameNumber; i++) {
		if (!file->WriteBytes(&((this->motion_frames)[i]), 111)) {
			GePrint("Write file error"_s);
			MessageDialog("Write motions to file failed: Write file error"_s);
			return maxon::UnexpectedError(MAXON_SOURCE_LOCATION, "Write file error"_s);
		}
	}
	GePrint("BoneFrameNumber:"_s + maxon::String::UIntToString((this->MotionFrameNumber)));
	if (!file->WriteUInt32(this->MorphFrameNumber)) {
		GePrint("Write file error"_s);
		MessageDialog("Write to file failed: Write file error"_s);
		return maxon::UnexpectedError(MAXON_SOURCE_LOCATION, "Write file error"_s);
	}
	for (UInt32 i = 0; i < this->MorphFrameNumber; i++) {
		if (!file->WriteBytes(&((this->morph_frames)[i]), 23)) {
			GePrint("Write file error"_s);
			MessageDialog("Write MorphFrameNumber to file failed: Write file error"_s);
			return maxon::UnexpectedError(MAXON_SOURCE_LOCATION, "Write file error"_s);
		}
	}
	GePrint("MorphFrameNumber:"_s + maxon::String::UIntToString((this->MorphFrameNumber)));
	if (!file->WriteUInt32(this->CameraFrameNumber)) {
		GePrint("Write file error"_s);
		MessageDialog("Write CameraFrameNumber to file failed: Write file error"_s);
		return maxon::UnexpectedError(MAXON_SOURCE_LOCATION, "Write file error"_s);
	}
	for (UInt32 i = 0; i < this->CameraFrameNumber; i++) {
		if (!file->WriteBytes(&((this->camera_frames)[i]), 61)) {
			GePrint("Write file error"_s);
			MessageDialog("Write to file failed: Write file error"_s);
			return maxon::UnexpectedError(MAXON_SOURCE_LOCATION, "Write file error"_s);
		}
	}
	GePrint("CameraFrameNumber:"_s + maxon::String::UIntToString((this->CameraFrameNumber)));
	if (!file->WriteUInt32(this->LightFrameNumber)) {
		GePrint("Write file error"_s);
		MessageDialog("Write to file failed: Write file error"_s);
		return maxon::UnexpectedError(MAXON_SOURCE_LOCATION, "Write file error"_s);
	}
	for (UInt32 i = 0; i < this->LightFrameNumber; i++) {
		if (!file->WriteBytes(&((this->light_frames)[i]), 28)) {
			GePrint("Write file error"_s);
			MessageDialog("Write to file failed: Write file error"_s);
			return maxon::UnexpectedError(MAXON_SOURCE_LOCATION, "Write file error"_s);
		}
	}
	GePrint("LightFrameNumber:"_s + maxon::String::UIntToString((this->LightFrameNumber)));
	return maxon::OK;
}

maxon::Result<void> mmd::VMDAnimation::FromFileImportCamera(Float &PositionMultiple, Float &TimeOffset) {
	iferr_scope;
	Filename fn;
	AutoAlloc <BaseFile> file;
	BaseDocument* doc = GetActiveDocument();
	if (doc == nullptr) {
		GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + "error");
		MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR));
		file.Free();
		return maxon::NullptrError(MAXON_SOURCE_LOCATION);
	}
	if (!fn.FileSelect(FILESELECTTYPE::ANYTHING, FILESELECT::LOAD, GeLoadString(IDS_MES_OPENFILE))) {
		file.Free();
		return maxon::NullptrError(MAXON_SOURCE_LOCATION);
	}
	if (file == nullptr) {
		GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
		MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
		return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
	}
	if (!file->Open(fn, FILEOPEN::READ, FILEDIALOG::ANY, BYTEORDER::V_INTEL, MACTYPE_CINEMA, MACCREATOR_CINEMA)) {
		GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_OPEN_FILE_ERR));
		MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_OPEN_FILE_ERR));
		file.Free();
		return maxon::UnexpectedError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_OPEN_FILE_ERR));
	}
	if (!(fn.CheckSuffix("vmd"_s) || (fn.CheckSuffix("VMD"_s)))) {
		GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_IMPORT_TYPE_ERR));
		MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_IMPORT_TYPE_ERR));
		file.Free();
		return maxon::IllegalArgumentError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_IMPORT_TYPE_ERR));
	}
	maxon::TimeValue timing = maxon::TimeValue::GetTime();
	StatusSetSpin();
	std::unique_ptr<mmd::VMDAnimation> mmd_animation(new mmd::VMDAnimation);
	if (mmd_animation == nullptr) {
		GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
		MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
		file.Free();
		return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
	}
	iferr(mmd_animation->LoadFromFile(file)) {
		GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_IMPORT_READ_ERR));
		MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_IMPORT_READ_ERR));
		file.Free();
		return maxon::UnexpectedError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_IMPORT_READ_ERR));
	}
	if (mmd_animation->IsCamera) {
		doc->StartUndo();
		BaseObject* VMDCamera = BaseObject::Alloc(Onull);//5140
		BaseObject* VMDCameraDistance = BaseObject::Alloc(Ocamera);//5103
		if (VMDCamera == nullptr) {
			GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			file.Free();
			return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
		}
		if (VMDCameraDistance == nullptr) {
			GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
			file.Free();
			return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
		}
		VMDCamera->SetName(fn.GetFileString());
		VMDCameraDistance->SetName("Camera"_s);
		BaseTag* ProtectionTag = BaseTag::Alloc(Tprotection);
		ProtectionTag->SetParameter(DescID(PROTECTION_P_Z), false, DESCFLAGS_SET::NONE);
		VMDCameraDistance->InsertTag(ProtectionTag);
		VMDCameraDistance->InsertUnder(VMDCamera);

		CTrack * CameraTrackPX = CTrack::Alloc(VMDCamera, DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_X, DTYPE_REAL, 0)));
		CTrack * CameraTrackPY = CTrack::Alloc(VMDCamera, DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Y, DTYPE_REAL, 0)));
		CTrack * CameraTrackPZ = CTrack::Alloc(VMDCamera, DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Z, DTYPE_REAL, 0)));
		CTrack * CameraTrackRX = CTrack::Alloc(VMDCamera, DescID(DescLevel(ID_BASEOBJECT_GLOBAL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_X, DTYPE_REAL, 0)));
		CTrack * CameraTrackRY = CTrack::Alloc(VMDCamera, DescID(DescLevel(ID_BASEOBJECT_GLOBAL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Y, DTYPE_REAL, 0)));
		CTrack * CameraTrackRZ = CTrack::Alloc(VMDCamera, DescID(DescLevel(ID_BASEOBJECT_GLOBAL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Z, DTYPE_REAL, 0)));
		CTrack * CameraTrackDistance = CTrack::Alloc(VMDCameraDistance, DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Z, DTYPE_REAL, 0)));
		CTrack * CameraTrackAOV = CTrack::Alloc(VMDCameraDistance, DescID(DescLevel(CAMERAOBJECT_APERTURE, DTYPE_REAL, 0)));
		CCurve * CameraCurvePX = CameraTrackPX->GetCurve();
		CCurve * CameraCurvePY = CameraTrackPY->GetCurve();
		CCurve * CameraCurvePZ = CameraTrackPZ->GetCurve();
		CCurve * CameraCurveRX = CameraTrackRX->GetCurve();
		CCurve * CameraCurveRY = CameraTrackRY->GetCurve();
		CCurve * CameraCurveRZ = CameraTrackRZ->GetCurve();
		CCurve * CameraCurveDistance = CameraTrackDistance->GetCurve();
		CCurve * CameraCurveAOV = CameraTrackAOV->GetCurve();
		VMDCamera->InsertTrackSorted(CameraTrackPX);
		VMDCamera->InsertTrackSorted(CameraTrackPY);
		VMDCamera->InsertTrackSorted(CameraTrackPZ);
		VMDCamera->InsertTrackSorted(CameraTrackRX);
		VMDCamera->InsertTrackSorted(CameraTrackRY);
		VMDCamera->InsertTrackSorted(CameraTrackRZ);
		VMDCameraDistance->InsertTrackSorted(CameraTrackDistance);
		VMDCameraDistance->InsertTrackSorted(CameraTrackAOV);

		Int32 Max30 = (doc->GetMaxTime()).GetFrame(30);
		Max30 = maxon::Max(Max30, (Int32)(mmd_animation->camera_frames.End() - 1).GetPtr()->frame_no);
		BaseTime KeyTime = BaseTime(0, 30);
		mmd::VMD_Camera CameraFrame, NextCameraFrame;
		Float TimeOfTwoFrames = 0.0, ValueOfTwoFrames = 0.0;
		BaseTime TimeLeft[8] = { BaseTime(0.0, 30) };
		Float ValueLeft[8] = { 0.0 };
		UInt32 camera_frame_number = mmd_animation->CameraFrameNumber;
		for (UInt32 i = 0; i < camera_frame_number; i++)
		{
			StatusSetText("Import camera..."_s);
			StatusSetBar(i * 100 / camera_frame_number);
			if (i == 0 && camera_frame_number != 1)
			{
				CameraFrame = mmd_animation->camera_frames[i];
				NextCameraFrame = mmd_animation->camera_frames[i + 1];
			}
			else if (i == mmd_animation->CameraFrameNumber - 1)
			{
				CameraFrame = NextCameraFrame;
			}
			else
			{
				CameraFrame = NextCameraFrame;
				NextCameraFrame = mmd_animation->camera_frames[i + 1];
			}


			TimeOfTwoFrames = NextCameraFrame.frame_no - CameraFrame.frame_no;
			KeyTime = BaseTime(CameraFrame.frame_no + TimeOffset + 1.0, 30);

			CKey* CameraKeyPX = CKey::Alloc();//PX
			CameraKeyPX->SetTime(CameraCurvePX, KeyTime);
			CameraKeyPX->SetValue(CameraCurvePX, CameraFrame.position.x * PositionMultiple);
			CameraKeyPX->ChangeNBit(NBIT::CKEY_BREAK, NBITCONTROL::SET);
			CameraKeyPX->ChangeNBit(NBIT::CKEY_REMOVEOVERSHOOT, NBITCONTROL::SET);
			ValueOfTwoFrames = NextCameraFrame.position.x * PositionMultiple - CameraFrame.position.x * PositionMultiple;		
			if (CameraFrame.XCurve.ax == 127 - CameraFrame.XCurve.bx&& CameraFrame.XCurve.ay == 127 - CameraFrame.XCurve.by) {
				CameraKeyPX->SetInterpolation(CameraCurvePX, CINTERPOLATION::LINEAR);
			}
			else {
				CameraKeyPX->SetTimeLeft(CameraCurvePX, TimeLeft[0]);
				CameraKeyPX->SetValueLeft(CameraCurvePX, ValueLeft[0]);
				CameraKeyPX->SetTimeRight(CameraCurvePX, BaseTime(TimeOfTwoFrames* ((Float)NextCameraFrame.XCurve.ax / 127.0), 30));
				CameraKeyPX->SetValueRight(CameraCurvePX, ValueOfTwoFrames* ((Float)NextCameraFrame.XCurve.ay / 127.0));//value和time都得记录..
			}			
			TimeLeft[0] = BaseTime(-TimeOfTwoFrames * ((Float)NextCameraFrame.XCurve.bx / 127.0), 30);
			ValueLeft[0] = -ValueOfTwoFrames * ((Float)NextCameraFrame.XCurve.by / 127.0);
			CameraCurvePX->InsertKey(CameraKeyPX);

			CKey* CameraKeyPY = CKey::Alloc();//PY
			CameraKeyPY->SetTime(CameraCurvePY, KeyTime);
			CameraKeyPY->SetValue(CameraCurvePY, CameraFrame.position.y * PositionMultiple);
			CameraKeyPY->ChangeNBit(NBIT::CKEY_BREAK, NBITCONTROL::SET);
			CameraKeyPY->ChangeNBit(NBIT::CKEY_REMOVEOVERSHOOT, NBITCONTROL::SET);
			ValueOfTwoFrames = NextCameraFrame.position.y * PositionMultiple - CameraFrame.position.y * PositionMultiple;
			if (CameraFrame.YCurve.ax == 127 - CameraFrame.YCurve.bx && CameraFrame.YCurve.ay == 127 - CameraFrame.YCurve.by) {
				CameraKeyPY->SetInterpolation(CameraCurvePY, CINTERPOLATION::LINEAR);
			}
			else {
				CameraKeyPY->SetTimeLeft(CameraCurvePY, TimeLeft[1]);
				CameraKeyPY->SetValueLeft(CameraCurvePY, ValueLeft[1]);
				CameraKeyPY->SetTimeRight(CameraCurvePY, BaseTime(TimeOfTwoFrames * ((Float)NextCameraFrame.YCurve.ax / 127.0), 30));
				CameraKeyPY->SetValueRight(CameraCurvePY, ValueOfTwoFrames * ((Float)NextCameraFrame.YCurve.ay / 127.0));
			}
			TimeLeft[1] = BaseTime(-TimeOfTwoFrames * ((Float)NextCameraFrame.YCurve.bx / 127.0), 30);
			ValueLeft[1] = -ValueOfTwoFrames * ((Float)NextCameraFrame.YCurve.by / 127.0);
			CameraCurvePY->InsertKey(CameraKeyPY);

			CKey* CameraKeyPZ = CKey::Alloc();//PZ
			CameraKeyPZ->SetTime(CameraCurvePZ, KeyTime);
			CameraKeyPZ->SetValue(CameraCurvePZ, CameraFrame.position.z * PositionMultiple);
			CameraKeyPZ->ChangeNBit(NBIT::CKEY_BREAK, NBITCONTROL::SET);
			CameraKeyPZ->ChangeNBit(NBIT::CKEY_REMOVEOVERSHOOT, NBITCONTROL::SET);
			ValueOfTwoFrames = NextCameraFrame.position.z * PositionMultiple - CameraFrame.position.z * PositionMultiple;
			if (CameraFrame.ZCurve.ax == 127 - CameraFrame.ZCurve.bx && CameraFrame.ZCurve.ay == 127 - CameraFrame.ZCurve.by) {
				CameraKeyPZ->SetInterpolation(CameraCurvePZ, CINTERPOLATION::LINEAR);
			}
			else {
				CameraKeyPZ->SetTimeLeft(CameraCurvePZ, TimeLeft[2]);
				CameraKeyPZ->SetValueLeft(CameraCurvePZ, ValueLeft[2]);
				CameraKeyPZ->SetTimeRight(CameraCurvePZ, BaseTime(TimeOfTwoFrames * ((Float)NextCameraFrame.ZCurve.ax / 127.0), 30));
				CameraKeyPZ->SetValueRight(CameraCurvePZ, ValueOfTwoFrames * ((Float)NextCameraFrame.ZCurve.ay / 127.0));
			}
			TimeLeft[2] = BaseTime(-TimeOfTwoFrames * ((Float)NextCameraFrame.ZCurve.bx / 127.0), 30);
			ValueLeft[2] = -ValueOfTwoFrames * ((Float)NextCameraFrame.ZCurve.by / 127.0);
			CameraCurvePZ->InsertKey(CameraKeyPZ);

			CKey* CameraKeyRX = CKey::Alloc();//RX
			CameraKeyRX->SetTime(CameraCurveRX, KeyTime);
			CameraKeyRX->SetValue(CameraCurveRX, CameraFrame.rotation.x);
			CameraKeyRX->ChangeNBit(NBIT::CKEY_BREAK, NBITCONTROL::SET);
			CameraKeyRX->ChangeNBit(NBIT::CKEY_REMOVEOVERSHOOT, NBITCONTROL::SET);
			ValueOfTwoFrames = NextCameraFrame.rotation.x - CameraFrame.rotation.x;
			if (CameraFrame.RCurve.ax == 127 - CameraFrame.RCurve.bx && CameraFrame.RCurve.ay == 127 - CameraFrame.RCurve.by) {
				CameraKeyRX->SetInterpolation(CameraCurveRX, CINTERPOLATION::LINEAR);
			}
			else {
				CameraKeyRX->SetTimeLeft(CameraCurveRX, TimeLeft[3]);
				CameraKeyRX->SetValueLeft(CameraCurveRX, ValueLeft[3]);
				CameraKeyRX->SetTimeRight(CameraCurveRX, BaseTime(TimeOfTwoFrames * ((Float)NextCameraFrame.RCurve.ax / 127.0), 30));
				CameraKeyRX->SetValueRight(CameraCurveRX, ValueOfTwoFrames * ((Float)NextCameraFrame.RCurve.ay / 127.0));
			}
			TimeLeft[3] = BaseTime(-TimeOfTwoFrames * ((Float)NextCameraFrame.RCurve.bx / 127.0), 30);
			ValueLeft[3] = -ValueOfTwoFrames * ((Float)NextCameraFrame.RCurve.by / 127.0);
			CameraCurveRX->InsertKey(CameraKeyRX);

			CKey* CameraKeyRY = CKey::Alloc();//RY
			CameraKeyRY->SetTime(CameraCurveRY, KeyTime);
			CameraKeyRY->SetValue(CameraCurveRY, CameraFrame.rotation.y);
			CameraKeyRY->ChangeNBit(NBIT::CKEY_BREAK, NBITCONTROL::SET);
			CameraKeyRY->ChangeNBit(NBIT::CKEY_REMOVEOVERSHOOT, NBITCONTROL::SET);
			ValueOfTwoFrames = NextCameraFrame.rotation.y - CameraFrame.rotation.y;
			if (CameraFrame.RCurve.ax == 127 - CameraFrame.RCurve.bx && CameraFrame.RCurve.ay == 127 - CameraFrame.RCurve.by) {
				CameraKeyRY->SetInterpolation(CameraCurveRY, CINTERPOLATION::LINEAR);
			}
			else {
				CameraKeyRY->SetTimeLeft(CameraCurveRY, TimeLeft[4]);
				CameraKeyRY->SetValueLeft(CameraCurveRY, ValueLeft[4]);
				CameraKeyRY->SetTimeRight(CameraCurveRY, BaseTime(TimeOfTwoFrames * ((Float)NextCameraFrame.RCurve.ax / 127.0), 30));
				CameraKeyRY->SetValueRight(CameraCurveRY, ValueOfTwoFrames * ((Float)NextCameraFrame.RCurve.ay / 127.0));
			}
			TimeLeft[4] = BaseTime(-TimeOfTwoFrames * ((Float)NextCameraFrame.RCurve.bx / 127.0), 30);
			ValueLeft[4] = -ValueOfTwoFrames * ((Float)NextCameraFrame.RCurve.by / 127.0);
			CameraCurveRY->InsertKey(CameraKeyRY);

			CKey* CameraKeyRZ = CKey::Alloc();//RZ
			CameraKeyRZ->SetTime(CameraCurveRZ, KeyTime);
			CameraKeyRZ->SetValue(CameraCurveRZ, CameraFrame.rotation.z);
			CameraKeyRZ->ChangeNBit(NBIT::CKEY_BREAK, NBITCONTROL::SET);
			CameraKeyRZ->ChangeNBit(NBIT::CKEY_REMOVEOVERSHOOT, NBITCONTROL::SET);
			ValueOfTwoFrames = NextCameraFrame.rotation.z - CameraFrame.rotation.z;
			if (CameraFrame.RCurve.ax == 127 - CameraFrame.RCurve.bx && CameraFrame.RCurve.ay == 127 - CameraFrame.RCurve.by) {
				CameraKeyRZ->SetInterpolation(CameraCurveRZ, CINTERPOLATION::LINEAR);
			}
			else {
				CameraKeyRZ->SetTimeLeft(CameraCurveRZ, TimeLeft[5]);
				CameraKeyRZ->SetValueLeft(CameraCurveRZ, ValueLeft[5]);
				CameraKeyRZ->SetTimeRight(CameraCurveRZ, BaseTime(TimeOfTwoFrames * ((Float)NextCameraFrame.RCurve.ax / 127.0), 30));
				CameraKeyRZ->SetValueRight(CameraCurveRZ, ValueOfTwoFrames * ((Float)NextCameraFrame.RCurve.ay / 127.0));
			}
			TimeLeft[5] = BaseTime(-TimeOfTwoFrames * ((Float)NextCameraFrame.RCurve.bx / 127.0), 30);
			ValueLeft[5] = -ValueOfTwoFrames * ((Float)NextCameraFrame.RCurve.by / 127.0);
			CameraCurveRZ->InsertKey(CameraKeyRZ);

			CKey* CameraKeyDistance = CKey::Alloc();;
			CameraKeyDistance->SetTime(CameraCurveDistance, KeyTime);
			CameraKeyDistance->SetValue(CameraCurveDistance, CameraFrame.distance * PositionMultiple);
			CameraKeyDistance->ChangeNBit(NBIT::CKEY_BREAK, NBITCONTROL::SET);
			CameraKeyDistance->ChangeNBit(NBIT::CKEY_REMOVEOVERSHOOT, NBITCONTROL::SET);
			ValueOfTwoFrames = NextCameraFrame.distance * PositionMultiple - CameraFrame.distance * PositionMultiple;
			if (CameraFrame.DCurve.ax == 127 - CameraFrame.DCurve.bx && CameraFrame.DCurve.ay == 127 - CameraFrame.DCurve.by) {
				CameraKeyDistance->SetInterpolation(CameraCurveDistance, CINTERPOLATION::LINEAR);
			}
			else {
				CameraKeyDistance->SetTimeLeft(CameraCurveDistance, TimeLeft[6]);
				CameraKeyDistance->SetValueLeft(CameraCurveDistance, ValueLeft[6]);
				CameraKeyDistance->SetTimeRight(CameraCurveDistance, BaseTime(TimeOfTwoFrames * ((Float)NextCameraFrame.DCurve.ax / 127.0), 30));
				CameraKeyDistance->SetValueRight(CameraCurveDistance, ValueOfTwoFrames * ((Float)NextCameraFrame.DCurve.ay / 127.0));
			}
			TimeLeft[6] = BaseTime(-TimeOfTwoFrames * ((Float)NextCameraFrame.DCurve.bx / 127.0), 30);
			ValueLeft[6] = -ValueOfTwoFrames * ((Float)NextCameraFrame.DCurve.by / 127.0);
			CameraCurveDistance->InsertKey(CameraKeyDistance);

			CKey* CameraKeyAOV = CKey::Alloc();
			CameraKeyAOV->SetTime(CameraCurveAOV, KeyTime);
			CameraKeyAOV->SetValue(CameraCurveAOV, CameraFrame.viewing_angle);
			CameraKeyAOV->ChangeNBit(NBIT::CKEY_BREAK, NBITCONTROL::SET);
			CameraKeyAOV->ChangeNBit(NBIT::CKEY_REMOVEOVERSHOOT, NBITCONTROL::SET);
			ValueOfTwoFrames = (Int32)NextCameraFrame.viewing_angle - (Int32)CameraFrame.viewing_angle;
			if (CameraFrame.VCurve.ax == 127 - CameraFrame.VCurve.bx && CameraFrame.VCurve.ay == 127 - CameraFrame.VCurve.by) {
				CameraKeyAOV->SetInterpolation(CameraCurveAOV, CINTERPOLATION::LINEAR);
			}
			else {
				CameraKeyAOV->SetTimeLeft(CameraCurveAOV, TimeLeft[7]);
				CameraKeyAOV->SetValueLeft(CameraCurveAOV, ValueLeft[7]);
				CameraKeyAOV->SetTimeRight(CameraCurveAOV, BaseTime(TimeOfTwoFrames * ((Float)NextCameraFrame.VCurve.ax / 127.0), 30));
				CameraKeyAOV->SetValueRight(CameraCurveAOV, ValueOfTwoFrames * ((Float)NextCameraFrame.VCurve.ay / 127.0));
			}
			TimeLeft[7] = BaseTime(-TimeOfTwoFrames * ((Float)NextCameraFrame.VCurve.bx / 127.0), 30);
			ValueLeft[7] = -ValueOfTwoFrames * ((Float)NextCameraFrame.VCurve.by / 127.0);
			CameraCurveAOV->InsertKey(CameraKeyAOV);
		}
		timing.Stop();
		StatusClear();
		doc->InsertObject(VMDCamera, nullptr, nullptr);
		doc->SetMaxTime(BaseTime(Max30, 30));
		doc->SetLoopMaxTime(BaseTime(Max30, 30));
		MessageDialog(GeLoadString(IDS_MES_IMPORT_OK, maxon::String::UIntToString(mmd_animation->CameraFrameNumber), String::FloatToString(timing.GetMilliseconds())));
		EventAdd(EVENT::NONE);
		doc->SetTime(BaseTime(1, 30));
		doc->SetTime(BaseTime(0, 30));
		file.Free();
		doc->EndUndo();
		return maxon::OK;
	}
	else {
		MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_IMPORT_CAM_ERR));
		file.Free();
		return maxon::UnexpectedError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_IMPORT_CAM_ERR));
	}
}

maxon::Result<void> mmd::VMDAnimation::FromDocumentExportCamera(Float& PositionMultiple, Float& TimeOffset) {
	iferr_scope;
	Filename fn;
	AutoAlloc<BaseFile> file;
	BaseDocument* doc = GetActiveDocument();
	if (doc == nullptr) {
		GePrint(GeLoadString(IDS_MES_EXPORT_ERR) + "error");
		MessageDialog(GeLoadString(IDS_MES_EXPORT_ERR) + "error");
		file.Free();
		return maxon::NullptrError(MAXON_SOURCE_LOCATION);
	}
	if (!fn.FileSelect(FILESELECTTYPE::ANYTHING, FILESELECT::SAVE, GeLoadString(IDS_MES_SAVEFILE)))
	{
		file.Free();
		return maxon::NullptrError(MAXON_SOURCE_LOCATION);
	}
	if (!(fn.CheckSuffix("vmd"_s) || (fn.CheckSuffix("VMD"_s)))) {
		fn.SetSuffix("vmd"_s);
	}
	if (file == nullptr) {
		GePrint(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
		MessageDialog(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
		return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
	}
	if (!file->Open(fn, FILEOPEN::WRITE, FILEDIALOG::ANY, BYTEORDER::V_INTEL, MACTYPE_CINEMA, MACCREATOR_CINEMA)) {
		GePrint(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_OPEN_FILE_ERR));
		MessageDialog(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_OPEN_FILE_ERR));
		file.Free();
		return maxon::UnexpectedError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_OPEN_FILE_ERR));
	}
	BaseObject* SelectObject = doc->GetActiveObject();
	if (SelectObject == nullptr) {
		GePrint(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_SELECT_ERR));
		MessageDialog(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_SELECT_ERR));
		file.Free();
		return maxon::NullptrError(MAXON_SOURCE_LOCATION);
	}
	if (SelectObject->GetType() != Onull || SelectObject->GetDown()->GetType() != Ocamera) {
		GePrint(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_EXPORT_TYPE_ERR));
		MessageDialog(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_EXPORT_TYPE_ERR));
		file.Free();
		return maxon::NullptrError(MAXON_SOURCE_LOCATION);
	}
	maxon::TimeValue timing = maxon::TimeValue::GetTime();
	StatusSetSpin();
	CTrack * CameraTrackPX = SelectObject->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_GLOBAL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_X, DTYPE_REAL, 0)));
	if (CameraTrackPX == nullptr) {
		GePrint(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_EXPORT_TRACK_ERR, "PX"_s));
		MessageDialog(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_EXPORT_TRACK_ERR, "PX"_s));
		file.Free();
		return maxon::NullptrError(MAXON_SOURCE_LOCATION);
	}
	CTrack * CameraTrackPY = SelectObject->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_GLOBAL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Y, DTYPE_REAL, 0)));
	if (CameraTrackPY == nullptr) {
		GePrint(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_EXPORT_TRACK_ERR, "PY"_s));
		MessageDialog(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_EXPORT_TRACK_ERR, "PY"_s));
		file.Free();
		return maxon::NullptrError(MAXON_SOURCE_LOCATION);
	}
	CTrack * CameraTrackPZ = SelectObject->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_GLOBAL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Z, DTYPE_REAL, 0)));
	if (CameraTrackPZ == nullptr) {
		GePrint(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_EXPORT_TRACK_ERR, "PZ"_s));
		MessageDialog(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_EXPORT_TRACK_ERR, "PZ"_s));
		file.Free();
		return maxon::NullptrError(MAXON_SOURCE_LOCATION);
	}
	CTrack * CameraTrackRX = SelectObject->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_X, DTYPE_REAL, 0)));
	if (CameraTrackRX == nullptr) {
		GePrint(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_EXPORT_TRACK_ERR, "RX"_s));
		MessageDialog(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_EXPORT_TRACK_ERR, "RX"_s));
		file.Free();
		return maxon::NullptrError(MAXON_SOURCE_LOCATION);
	}
	CTrack * CameraTrackRY = SelectObject->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Y, DTYPE_REAL, 0)));
	if (CameraTrackRY == nullptr) {
		GePrint(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_EXPORT_TRACK_ERR, "RY"_s));
		MessageDialog(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_EXPORT_TRACK_ERR, "RY"_s));
		file.Free();
		return maxon::NullptrError(MAXON_SOURCE_LOCATION);
	}
	CTrack * CameraTrackRZ = SelectObject->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Z, DTYPE_REAL, 0)));

	if (CameraTrackRZ == nullptr) {
		GePrint(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_EXPORT_TRACK_ERR, "RZ"_s));
		MessageDialog(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_EXPORT_TRACK_ERR, "RZ"_s));
		file.Free();
		return maxon::NullptrError(MAXON_SOURCE_LOCATION);
	}
	CTrack * CameraTrackDistance = SelectObject->GetDown()->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_GLOBAL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Z, DTYPE_REAL, 0)));

	if (CameraTrackDistance == nullptr) {
		GePrint(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_EXPORT_TRACK_ERR, "Distance"_s));
		MessageDialog(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_EXPORT_TRACK_ERR, "Distance"_s));
		file.Free();
		return maxon::NullptrError(MAXON_SOURCE_LOCATION);
	}
	CTrack * CameraTrackAOV = SelectObject->GetDown()->FindCTrack(DescID(DescLevel(CAMERAOBJECT_APERTURE, DTYPE_REAL, 0)));
	if (CameraTrackAOV == nullptr) {
		GePrint(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_EXPORT_TRACK_ERR, "AOV"_s));
		MessageDialog(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_EXPORT_TRACK_ERR, "AOV"_s));
		file.Free();
		return maxon::NullptrError(MAXON_SOURCE_LOCATION);
	}

	CCurve * CameraCurvePX = CameraTrackPX->GetCurve();
	CCurve * CameraCurvePY = CameraTrackPY->GetCurve();
	CCurve * CameraCurvePZ = CameraTrackPZ->GetCurve();
	CCurve * CameraCurveRX = CameraTrackRX->GetCurve();
	CCurve * CameraCurveRY = CameraTrackRY->GetCurve();
	CCurve * CameraCurveRZ = CameraTrackRZ->GetCurve();
	CCurve * CameraCurveDistance = CameraTrackDistance->GetCurve();
	CCurve * CameraCurveAOV = CameraTrackAOV->GetCurve();

	std::unique_ptr<mmd::VMDAnimation> mmd_animation(new mmd::VMDAnimation);
	if (mmd_animation == nullptr) {
		GePrint(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
		MessageDialog(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
		file.Free();
		return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
	}

	maxon::HashMap<maxon::Int32, mmd::VMD_Camera> Frames;

	for (Int32 i = 0; i < CameraCurvePX->GetKeyCount(); i++) {
		CKey* Key = CameraCurvePX->GetKey(i);
		if (Key) {
			Int32 CameraFrame_ = Key->GetTime().GetFrame(30) + TimeOffset;
			mmd::VMD_Camera CameraFrame;
			if (Frames.FindValue(CameraFrame_)) {
				CameraFrame = *(Frames.FindValue(CameraFrame_));
				Frames.Erase(CameraFrame_)iferr_return;
			}
			if (i != CameraCurvePX->GetKeyCount() - 1) {
				CKey* NextKey = CameraCurvePX->GetKey(i + 1);
				if (NextKey) {
					Int32 NextCameraFrame_ = NextKey->GetTime().GetFrame(30) + TimeOffset;
					Int32 TimeOfTwoFrames = NextCameraFrame_ - CameraFrame_;
					Float ValueOfTwoFrames = NextKey->GetValue() - Key->GetValue();
					CameraFrame.frame_no = (UInt32)CameraFrame_;
					CameraFrame.position.x = Key->GetValue() * PositionMultiple;
					CameraFrame.XCurve.ax = (UChar)((Key->GetTimeRight().GetFrame(30) * 128) / TimeOfTwoFrames);
					CameraFrame.XCurve.ay = (UChar)((Key->GetValueRight() * 127.0) / (ValueOfTwoFrames *  PositionMultiple));
					CameraFrame.XCurve.bx = (UChar)((NextKey->GetTimeLeft().GetFrame(30) * -128) / TimeOfTwoFrames);
					CameraFrame.XCurve.by = (UChar)((NextKey->GetValueLeft() * (Float)-128) / (ValueOfTwoFrames * PositionMultiple));
					Frames.Insert(CameraFrame_, CameraFrame)iferr_return;
				}
			}
			else {
				CameraFrame.frame_no = (UInt32)CameraFrame_;
				CameraFrame.position.x = Key->GetValue() * PositionMultiple;
				CameraFrame.XCurve.ax = 20;
				CameraFrame.XCurve.ay = 20;
				CameraFrame.XCurve.bx = 107;
				CameraFrame.XCurve.by = 107;
				Frames.Insert(CameraFrame_, CameraFrame)iferr_return;
			}
		}
	}
	for (Int32 i = 0; i < CameraCurvePY->GetKeyCount(); i++) {
		CKey* Key = CameraCurvePY->GetKey(i);
		if (Key) {
			Int32 CameraFrame_ = Key->GetTime().GetFrame(30) + TimeOffset;
			mmd::VMD_Camera CameraFrame;
			if (Frames.FindValue(CameraFrame_)) {
				CameraFrame = *(Frames.FindValue(CameraFrame_));
				Frames.Erase(CameraFrame_)iferr_return;
			}
			if (i != CameraCurvePY->GetKeyCount() - 1) {
				CKey* NextKey = CameraCurvePY->GetKey(i + 1);
				if (NextKey) {
					Int32 NextCameraFrame_ = NextKey->GetTime().GetFrame(30) + TimeOffset;
					Int32 TimeOfTwoFrames = NextCameraFrame_ - CameraFrame_;
					Float ValueOfTwoFrames = NextKey->GetValue() - Key->GetValue();
					CameraFrame.frame_no = (UInt32)CameraFrame_;
					CameraFrame.position.y = Key->GetValue() * PositionMultiple;
					CameraFrame.YCurve.ax = (UChar)((Key->GetTimeRight().GetFrame(30) * 128) / TimeOfTwoFrames);
					CameraFrame.YCurve.ay = (UChar)((Key->GetValueRight() * 127.0) / (ValueOfTwoFrames *  PositionMultiple));
					CameraFrame.YCurve.bx = (UChar)((NextKey->GetTimeLeft().GetFrame(30) * -128) / TimeOfTwoFrames);
					CameraFrame.YCurve.by = (UChar)((NextKey->GetValueLeft() * (Float)-128) / (ValueOfTwoFrames * PositionMultiple));
					Frames.Insert(CameraFrame_, CameraFrame)iferr_return;
				}

			}
			else {
				CameraFrame.frame_no = (UInt32)CameraFrame_;
				CameraFrame.position.y = Key->GetValue() * PositionMultiple;
				CameraFrame.YCurve.ax = 20;
				CameraFrame.YCurve.ay = 20;
				CameraFrame.YCurve.bx = 107;
				CameraFrame.YCurve.by = 107;
				Frames.Insert(CameraFrame_, CameraFrame)iferr_return;
			}
		}
	}
	for (Int32 i = 0; i < CameraCurvePZ->GetKeyCount(); i++) {
		CKey* Key = CameraCurvePZ->GetKey(i);
		if (Key) {
			Int32 CameraFrame_ = Key->GetTime().GetFrame(30) + TimeOffset;
			mmd::VMD_Camera CameraFrame;
			if (Frames.FindValue(CameraFrame_)) {
				CameraFrame = *(Frames.FindValue(CameraFrame_));
				Frames.Erase(CameraFrame_)iferr_return;
			}
			if (i != CameraCurvePZ->GetKeyCount() - 1) {
				CKey* NextKey = CameraCurvePZ->GetKey(i + 1);
				if (NextKey) {
					Int32 NextCameraFrame_ = NextKey->GetTime().GetFrame(30) + TimeOffset;
					Int32 TimeOfTwoFrames = NextCameraFrame_ - CameraFrame_;
					Float ValueOfTwoFrames = NextKey->GetValue() - Key->GetValue();
					CameraFrame.frame_no = (UInt32)CameraFrame_;
					CameraFrame.position.z = Key->GetValue() * PositionMultiple;
					CameraFrame.ZCurve.ax = (UChar)((Key->GetTimeRight().GetFrame(30) * 128) / TimeOfTwoFrames);
					CameraFrame.ZCurve.ay = (UChar)((Key->GetValueRight() * 127.0) / (ValueOfTwoFrames *  PositionMultiple));
					CameraFrame.ZCurve.bx = (UChar)((NextKey->GetTimeLeft().GetFrame(30) * -128) / TimeOfTwoFrames);
					CameraFrame.ZCurve.by = (UChar)((NextKey->GetValueLeft() * (Float)-128) / (ValueOfTwoFrames * PositionMultiple));
					Frames.Insert(CameraFrame_, CameraFrame)iferr_return;
				}

			}
			else {
				CameraFrame.frame_no = (UInt32)CameraFrame_;
				CameraFrame.position.z = Key->GetValue() * PositionMultiple;
				CameraFrame.ZCurve.ax = 20;
				CameraFrame.ZCurve.ay = 20;
				CameraFrame.ZCurve.bx = 107;
				CameraFrame.ZCurve.by = 107;
				Frames.Insert(CameraFrame_, CameraFrame)iferr_return;
			}
		}
	}

	Int32 RXKeyCount = CameraCurveRX->GetKeyCount() - 1;
	Int32 RYKeyCount = CameraCurveRY->GetKeyCount() - 1;
	Int32 RZKeyCount = CameraCurveRZ->GetKeyCount() - 1;
	Int32 RKeyCount = maxon::Max(maxon::Max(RXKeyCount, RYKeyCount), RZKeyCount);

	for (Int32 i = 0; i < RKeyCount; i++) {
		CKey* RXKey = nullptr;
		CKey* RYKey = nullptr;
		CKey* RZKey = nullptr;

		Int32 RXCameraFrame_ = 0;
		Int32 RYCameraFrame_ = 0;
		Int32 RZCameraFrame_ = 0;

		Bool ReadRX = 0, ReadRY = 0, ReadRZ = 0;

		if (RXKeyCount)
		{
			RXKey = CameraCurveRX->GetKey(i);
			RXCameraFrame_ = RXKey->GetTime().GetFrame(30) + TimeOffset;
		}

		if (RYKeyCount)
		{
			RYKey = CameraCurveRY->GetKey(i);
			RYCameraFrame_ = RYKey->GetTime().GetFrame(30) + TimeOffset;
		}

		if (RZKeyCount)
		{
			RZKey = CameraCurveRZ->GetKey(i);
			RZCameraFrame_ = RZKey->GetTime().GetFrame(30) + TimeOffset;
		}

		if (RXKeyCount&&RYKeyCount&&RZKeyCount)
		{
			if (RXKey&&RYKey&&RZKey)
			{
				if ((RXCameraFrame_ == RYCameraFrame_) && (RYCameraFrame_ == RZCameraFrame_))
				{
					ReadRX = 1;
					ReadRY = 1;
					ReadRZ = 1;
					mmd::VMD_Curve RXCurve;
					mmd::VMD_Curve RYCurve;
					mmd::VMD_Curve RZCurve;
					mmd::VMD_Camera CameraFrame;
					if (Frames.FindValue(RXCameraFrame_)) {
						CameraFrame = *(Frames.FindValue(RXCameraFrame_));
						Frames.Erase(RXCameraFrame_)iferr_return;
					}
					CameraFrame.frame_no = (UInt32)RXCameraFrame_;
					CameraFrame.rotation.y = RXKey->GetValue();
					if (i != RXKeyCount - 1) {
						CKey* RXNextKey = CameraCurveRX->GetKey(i + 1);
						Int32 NextCameraFrame_ = RXNextKey->GetTime().GetFrame(30) + TimeOffset;
						Int32 TimeOfTwoFrames = NextCameraFrame_ - RXCameraFrame_;
						Float ValueOfTwoFrames = RXNextKey->GetValue() - RXKey->GetValue();
						RXCurve.ax = (UChar)((RXKey->GetTimeRight().GetFrame(30) * 128) / TimeOfTwoFrames);
						RXCurve.ay = (UChar)((RXKey->GetValueRight() * 127.0) / ValueOfTwoFrames);
						RXCurve.bx = (UChar)((RXNextKey->GetTimeLeft().GetFrame(30) * -128) / TimeOfTwoFrames);
						RXCurve.by = (UChar)((RXNextKey->GetValueLeft() * (Float)-128) / ValueOfTwoFrames);
					}
					else {
						RXCurve.ax = 20;
						RXCurve.ay = 20;
						RXCurve.bx = 107;
						RXCurve.by = 107;
					}
					CameraFrame.frame_no = (UInt32)RYCameraFrame_;
					CameraFrame.rotation.x = RYKey->GetValue();
					if (i != RYKeyCount - 1) {
						CKey* RYNextKey = CameraCurveRY->GetKey(i + 1);
						Int32 NextCameraFrame_ = RYNextKey->GetTime().GetFrame(30) + TimeOffset;
						Int32 TimeOfTwoFrames = NextCameraFrame_ - RYCameraFrame_;
						Float ValueOfTwoFrames = RYNextKey->GetValue() - RYKey->GetValue();
						RYCurve.ax = (UChar)((RYKey->GetTimeRight().GetFrame(30) * 128) / TimeOfTwoFrames);
						RYCurve.ay = (UChar)((RYKey->GetValueRight() * 127.0) / ValueOfTwoFrames);
						RYCurve.bx = (UChar)((RYNextKey->GetTimeLeft().GetFrame(30) * -128) / TimeOfTwoFrames);
						RYCurve.by = (UChar)((RYNextKey->GetValueLeft() * (Float)-128) / ValueOfTwoFrames);
					}
					else {
						RYCurve.ax = 20;
						RYCurve.ay = 20;
						RYCurve.bx = 107;
						RYCurve.by = 107;
					}
					CameraFrame.frame_no = (UInt32)RYCameraFrame_;
					CameraFrame.rotation.z = RZKey->GetValue();
					if (i != RZKeyCount - 1) {
						CKey* RZNextKey = CameraCurveRZ->GetKey(i + 1);
						Int32 NextCameraFrame_ = RZNextKey->GetTime().GetFrame(30) + TimeOffset;
						Int32 TimeOfTwoFrames = NextCameraFrame_ - RZCameraFrame_;
						Float ValueOfTwoFrames = RZNextKey->GetValue() - RZKey->GetValue();
						RZCurve.ax = (UChar)((RZKey->GetTimeRight().GetFrame(30) * 128) / TimeOfTwoFrames);
						RZCurve.ay = (UChar)((RZKey->GetValueRight() * 127.0) / ValueOfTwoFrames);
						RZCurve.bx = (UChar)((RZNextKey->GetTimeLeft().GetFrame(30) * -128) / TimeOfTwoFrames);
						RZCurve.by = (UChar)((RZNextKey->GetValueLeft() * (Float)-128) / ValueOfTwoFrames);
					}
					else {
						RZCurve.ax = 20;
						RZCurve.ay = 20;
						RZCurve.bx = 107;
						RZCurve.by = 107;
					}
					CameraFrame.RCurve.ax = maxon::Max(maxon::Max(RXCurve.ax, RYCurve.ax), RZCurve.ax);
					CameraFrame.RCurve.ay = maxon::Max(maxon::Max(RXCurve.ay, RYCurve.ay), RZCurve.ay);
					CameraFrame.RCurve.bx = maxon::Max(maxon::Max(RXCurve.bx, RYCurve.bx), RZCurve.bx);
					CameraFrame.RCurve.by = maxon::Max(maxon::Max(RXCurve.by, RYCurve.by), RZCurve.by);
					Frames.Insert(RXCameraFrame_, CameraFrame)iferr_return;
					RXKeyCount--;
					RYKeyCount--;
					RZKeyCount--;
				}
			}
		}

		if (ReadRX != 1 && ReadRY != 1)
		{
			if (RXKeyCount&&RYKeyCount)
			{
				if (RXKey&&RYKey)
				{
					if (RYCameraFrame_ == RXCameraFrame_)
					{
						ReadRX = 1;
						ReadRY = 1;
						mmd::VMD_Curve RXCurve;
						mmd::VMD_Curve RYCurve;
						mmd::VMD_Camera CameraFrame;
						if (Frames.FindValue(RXCameraFrame_)) {
							CameraFrame = *(Frames.FindValue(RXCameraFrame_));
							Frames.Erase(RXCameraFrame_)iferr_return;
						}
						CameraFrame.frame_no = (UInt32)RXCameraFrame_;
						CameraFrame.rotation.y = RXKey->GetValue();
						if (i != RXKeyCount - 1) {
							CKey* RXNextKey = CameraCurveRX->GetKey(i + 1);
							Int32 NextCameraFrame_ = RXNextKey->GetTime().GetFrame(30) + TimeOffset;
							Int32 TimeOfTwoFrames = NextCameraFrame_ - RXCameraFrame_;
							Float ValueOfTwoFrames = RXNextKey->GetValue() - RXKey->GetValue();
							RXCurve.ax = (UChar)((RXKey->GetTimeRight().GetFrame(30) * 128) / TimeOfTwoFrames);
							RXCurve.ay = (UChar)((RXKey->GetValueRight() * 127.0) / ValueOfTwoFrames);
							RXCurve.bx = (UChar)((RXNextKey->GetTimeLeft().GetFrame(30) * -128) / TimeOfTwoFrames);
							RXCurve.by = (UChar)((RXNextKey->GetValueLeft() * (Float)-128) / ValueOfTwoFrames);
						}
						else {
							RXCurve.ax = 20;
							RXCurve.ay = 20;
							RXCurve.bx = 107;
							RXCurve.by = 107;
						}
						CameraFrame.frame_no = (UInt32)RYCameraFrame_;
						CameraFrame.rotation.x = RYKey->GetValue();
						if (i != RYKeyCount - 1) {
							CKey* RYNextKey = CameraCurveRY->GetKey(i + 1);
							Int32 NextCameraFrame_ = RYNextKey->GetTime().GetFrame(30) + TimeOffset;
							Int32 TimeOfTwoFrames = NextCameraFrame_ - RYCameraFrame_;
							Float ValueOfTwoFrames = RYNextKey->GetValue() - RYKey->GetValue();
							RYCurve.ax = (UChar)((RYKey->GetTimeRight().GetFrame(30) * 128) / TimeOfTwoFrames);
							RYCurve.ay = (UChar)((RYKey->GetValueRight() * 127.0) / ValueOfTwoFrames);
							RYCurve.bx = (UChar)((RYNextKey->GetTimeLeft().GetFrame(30) * -128) / TimeOfTwoFrames);
							RYCurve.by = (UChar)((RYNextKey->GetValueLeft() * (Float)-128) / ValueOfTwoFrames);
						}
						else {
							RYCurve.ax = 20;
							RYCurve.ay = 20;
							RYCurve.bx = 107;
							RYCurve.by = 107;
						}
						CameraFrame.RCurve.ax = maxon::Max(RXCurve.ax, RYCurve.ax);
						CameraFrame.RCurve.ay = maxon::Max(RXCurve.ay, RYCurve.ay);
						CameraFrame.RCurve.bx = maxon::Max(RXCurve.bx, RYCurve.bx);
						CameraFrame.RCurve.by = maxon::Max(RXCurve.by, RYCurve.by);
						Frames.Insert(RXCameraFrame_, CameraFrame)iferr_return;
						RXKeyCount--;
						RYKeyCount--;
					}
				}
			}
		}

		if (ReadRZ != 1 && ReadRY != 1)
		{
			if (RZKeyCount&&RYKeyCount)
			{
				if (RXKey&&RYKey)
				{
					if (RYCameraFrame_ == RZCameraFrame_)
					{
						ReadRZ = 1;
						ReadRY = 1;
						mmd::VMD_Curve RYCurve;
						mmd::VMD_Curve RZCurve;
						mmd::VMD_Camera CameraFrame;
						if (Frames.FindValue(RXCameraFrame_)) {
							CameraFrame = *(Frames.FindValue(RXCameraFrame_));
							Frames.Erase(RXCameraFrame_)iferr_return;
						}
						CameraFrame.frame_no = (UInt32)RYCameraFrame_;
						CameraFrame.rotation.x = RYKey->GetValue();
						if (i != RYKeyCount - 1) {
							CKey* RYNextKey = CameraCurveRY->GetKey(i + 1);
							Int32 NextCameraFrame_ = RYNextKey->GetTime().GetFrame(30) + TimeOffset;
							Int32 TimeOfTwoFrames = NextCameraFrame_ - RYCameraFrame_;
							Float ValueOfTwoFrames = RYNextKey->GetValue() - RYKey->GetValue();
							RYCurve.ax = (UChar)((RYKey->GetTimeRight().GetFrame(30) * 128) / TimeOfTwoFrames);
							RYCurve.ay = (UChar)((RYKey->GetValueRight() * 127.0) / ValueOfTwoFrames);
							RYCurve.bx = (UChar)((RYNextKey->GetTimeLeft().GetFrame(30) * -128) / TimeOfTwoFrames);
							RYCurve.by = (UChar)((RYNextKey->GetValueLeft() * (Float)-128) / ValueOfTwoFrames);
						}
						else {
							RYCurve.ax = 20;
							RYCurve.ay = 20;
							RYCurve.bx = 107;
							RYCurve.by = 107;
						}
						CameraFrame.frame_no = (UInt32)RYCameraFrame_;
						CameraFrame.rotation.z = RZKey->GetValue();
						if (i != RZKeyCount - 1) {
							CKey* RZNextKey = CameraCurveRZ->GetKey(i + 1);
							Int32 NextCameraFrame_ = RZNextKey->GetTime().GetFrame(30) + TimeOffset;
							Int32 TimeOfTwoFrames = NextCameraFrame_ - RZCameraFrame_;
							Float ValueOfTwoFrames = RZNextKey->GetValue() - RZKey->GetValue();
							RZCurve.ax = (UChar)((RZKey->GetTimeRight().GetFrame(30) * 128) / TimeOfTwoFrames);
							RZCurve.ay = (UChar)((RZKey->GetValueRight() * 127.0) / ValueOfTwoFrames);
							RZCurve.bx = (UChar)((RZNextKey->GetTimeLeft().GetFrame(30) * -128) / TimeOfTwoFrames);
							RZCurve.by = (UChar)((RZNextKey->GetValueLeft() * (Float)-128) / ValueOfTwoFrames);
						}
						else {
							RZCurve.ax = 20;
							RZCurve.ay = 20;
							RZCurve.bx = 107;
							RZCurve.by = 107;
						}
						CameraFrame.RCurve.ax = maxon::Max(RYCurve.ax, RZCurve.ax);
						CameraFrame.RCurve.ay = maxon::Max(RYCurve.ay, RZCurve.ay);
						CameraFrame.RCurve.bx = maxon::Max(RYCurve.bx, RZCurve.bx);
						CameraFrame.RCurve.by = maxon::Max(RYCurve.by, RZCurve.by);
						Frames.Insert(RXCameraFrame_, CameraFrame)iferr_return;
						RZKeyCount--;
						RYKeyCount--;
					}
				}
			}
		}

		if (ReadRX != 1 && ReadRZ != 1)
		{
			if (RXKeyCount&&RZKeyCount)
			{
				if (RXKey&&RYKey)
				{
					if (RYCameraFrame_ == RXCameraFrame_)
					{
						ReadRX = 1;
						ReadRZ = 1;
						mmd::VMD_Curve RXCurve;
						mmd::VMD_Curve RZCurve;
						mmd::VMD_Camera CameraFrame;
						if (Frames.FindValue(RXCameraFrame_)) {
							CameraFrame = *(Frames.FindValue(RXCameraFrame_));
							Frames.Erase(RXCameraFrame_)iferr_return;
						}
						CameraFrame.frame_no = (UInt32)RXCameraFrame_;
						CameraFrame.rotation.y = RXKey->GetValue();
						if (i != RXKeyCount - 1) {
							CKey* RXNextKey = CameraCurveRX->GetKey(i + 1);
							Int32 NextCameraFrame_ = RXNextKey->GetTime().GetFrame(30) + TimeOffset;
							Int32 TimeOfTwoFrames = NextCameraFrame_ - RXCameraFrame_;
							Float ValueOfTwoFrames = RXNextKey->GetValue() - RXKey->GetValue();
							RXCurve.ax = (UChar)((RXKey->GetTimeRight().GetFrame(30) * 128) / TimeOfTwoFrames);
							RXCurve.ay = (UChar)((RXKey->GetValueRight() * 127.0) / ValueOfTwoFrames);
							RXCurve.bx = (UChar)((RXNextKey->GetTimeLeft().GetFrame(30) * -128) / TimeOfTwoFrames);
							RXCurve.by = (UChar)((RXNextKey->GetValueLeft() * (Float)-128) / ValueOfTwoFrames);
						}
						else {
							RXCurve.ax = 20;
							RXCurve.ay = 20;
							RXCurve.bx = 107;
							RXCurve.by = 107;
						}
						CameraFrame.frame_no = (UInt32)RYCameraFrame_;
						CameraFrame.rotation.z = RZKey->GetValue();
						if (i != RZKeyCount - 1) {
							CKey* RZNextKey = CameraCurveRZ->GetKey(i + 1);
							Int32 NextCameraFrame_ = RZNextKey->GetTime().GetFrame(30) + TimeOffset;
							Int32 TimeOfTwoFrames = NextCameraFrame_ - RZCameraFrame_;
							Float ValueOfTwoFrames = RZNextKey->GetValue() - RZKey->GetValue();
							RZCurve.ax = (UChar)((RZKey->GetTimeRight().GetFrame(30) * 128) / TimeOfTwoFrames);
							RZCurve.ay = (UChar)((RZKey->GetValueRight() * 127.0) / ValueOfTwoFrames);
							RZCurve.bx = (UChar)((RZNextKey->GetTimeLeft().GetFrame(30) * -128) / TimeOfTwoFrames);
							RZCurve.by = (UChar)((RZNextKey->GetValueLeft() * (Float)-128) / ValueOfTwoFrames);
						}
						else {
							RZCurve.ax = 20;
							RZCurve.ay = 20;
							RZCurve.bx = 107;
							RZCurve.by = 107;
						}
						CameraFrame.RCurve.ax = maxon::Max(RXCurve.ax, RZCurve.ax);
						CameraFrame.RCurve.ay = maxon::Max(RXCurve.ay, RZCurve.ay);
						CameraFrame.RCurve.bx = maxon::Max(RXCurve.bx, RZCurve.bx);
						CameraFrame.RCurve.by = maxon::Max(RXCurve.by, RZCurve.by);
						Frames.Insert(RXCameraFrame_, CameraFrame)iferr_return;
						RXKeyCount--;
						RZKeyCount--;
					}
				}
			}
		}

		if (ReadRX != 1)
		{
			if (RXKeyCount)
			{
				if (RXKey)
				{
					mmd::VMD_Camera CameraFrame;
					if (Frames.FindValue(RXCameraFrame_)) {
						CameraFrame = *(Frames.FindValue(RXCameraFrame_));
						Frames.Erase(RXCameraFrame_)iferr_return;
					}
					CameraFrame.frame_no = (UInt32)RXCameraFrame_;
					CameraFrame.rotation.y = RXKey->GetValue();
					if (i != RXKeyCount - 1) {
						CKey* NextKey = CameraCurveRX->GetKey(i + 1);
						Int32 NextCameraFrame_ = NextKey->GetTime().GetFrame(30) + TimeOffset;
						Int32 TimeOfTwoFrames = NextCameraFrame_ - RXCameraFrame_;
						Float ValueOfTwoFrames = NextKey->GetValue() - RXKey->GetValue();
						CameraFrame.RCurve.ax = (UChar)((RXKey->GetTimeRight().GetFrame(30) * 128) / TimeOfTwoFrames);
						CameraFrame.RCurve.ay = (UChar)((RXKey->GetValueRight() * 127.0) / ValueOfTwoFrames);
						CameraFrame.RCurve.bx = (UChar)((NextKey->GetTimeLeft().GetFrame(30) * -128) / TimeOfTwoFrames);
						CameraFrame.RCurve.by = (UChar)((NextKey->GetValueLeft() * (Float)-128) / ValueOfTwoFrames);
						Frames.Insert(RXCameraFrame_, CameraFrame)iferr_return;
					}
					else {
						CameraFrame.RCurve.ax = 20;
						CameraFrame.RCurve.ay = 20;
						CameraFrame.RCurve.bx = 107;
						CameraFrame.RCurve.by = 107;
						Frames.Insert(RXCameraFrame_, CameraFrame)iferr_return;
					}
					RXKeyCount--;
				}
			}
		}

		if (ReadRY != 1)
		{
			if (RYKeyCount)
			{
				if (RXKey)
				{
					mmd::VMD_Camera CameraFrame;
					if (Frames.FindValue(RYCameraFrame_)) {
						CameraFrame = *(Frames.FindValue(RYCameraFrame_));
						Frames.Erase(RYCameraFrame_)iferr_return;
					}
					CameraFrame.frame_no = (UInt32)RYCameraFrame_;
					CameraFrame.rotation.x = RYKey->GetValue();
					if (i != RYKeyCount - 1) {
						CKey* NextKey = CameraCurveRY->GetKey(i + 1);
						Int32 NextCameraFrame_ = NextKey->GetTime().GetFrame(30) + TimeOffset;
						Int32 TimeOfTwoFrames = NextCameraFrame_ - RYCameraFrame_;
						Float ValueOfTwoFrames = NextKey->GetValue() - RYKey->GetValue();
						CameraFrame.RCurve.ax = (UChar)((RYKey->GetTimeRight().GetFrame(30) * 128) / TimeOfTwoFrames);
						CameraFrame.RCurve.ay = (UChar)((RYKey->GetValueRight() * 127.0) / ValueOfTwoFrames);
						CameraFrame.RCurve.bx = (UChar)((NextKey->GetTimeLeft().GetFrame(30) * -128) / TimeOfTwoFrames);
						CameraFrame.RCurve.by = (UChar)((NextKey->GetValueLeft() * (Float)-128) / ValueOfTwoFrames);
						Frames.Insert(RYCameraFrame_, CameraFrame)iferr_return;
					}
					else {
						CameraFrame.RCurve.ax = 20;
						CameraFrame.RCurve.ay = 20;
						CameraFrame.RCurve.bx = 107;
						CameraFrame.RCurve.by = 107;
						Frames.Insert(RYCameraFrame_, CameraFrame)iferr_return;
					}
					RYKeyCount--;
				}
			}
		}

		if (ReadRZ != 1)
		{
			if (RZKeyCount)
			{
				if (RXKey)
				{
					mmd::VMD_Camera CameraFrame;
					if (Frames.FindValue(RZCameraFrame_)) {
						CameraFrame = *(Frames.FindValue(RZCameraFrame_));
						Frames.Erase(RZCameraFrame_)iferr_return;
					}
					CameraFrame.frame_no = (UInt32)RYCameraFrame_;
					CameraFrame.rotation.z = RZKey->GetValue();
					if (i != RZKeyCount - 1) {
						CKey* NextKey = CameraCurveRZ->GetKey(i + 1);
						Int32 NextCameraFrame_ = NextKey->GetTime().GetFrame(30) + TimeOffset;
						Int32 TimeOfTwoFrames = NextCameraFrame_ - RZCameraFrame_;
						Float ValueOfTwoFrames = NextKey->GetValue() - RZKey->GetValue();
						CameraFrame.RCurve.ax = (UChar)((RZKey->GetTimeRight().GetFrame(30) * 128) / TimeOfTwoFrames);
						CameraFrame.RCurve.ay = (UChar)((RZKey->GetValueRight() * 127.0) / ValueOfTwoFrames);
						CameraFrame.RCurve.bx = (UChar)((NextKey->GetTimeLeft().GetFrame(30) * -128) / TimeOfTwoFrames);
						CameraFrame.RCurve.by = (UChar)((NextKey->GetValueLeft() * (Float)-128) / ValueOfTwoFrames);
						Frames.Insert(RZCameraFrame_, CameraFrame)iferr_return;
					}
					else {
						CameraFrame.RCurve.ax = 20;
						CameraFrame.RCurve.ay = 20;
						CameraFrame.RCurve.bx = 107;
						CameraFrame.RCurve.by = 107;
						Frames.Insert(RZCameraFrame_, CameraFrame)iferr_return;
					}
					RZKeyCount--;
				}
			}
		}
	}
	for (Int32 i = 0; i < CameraCurveDistance->GetKeyCount(); i++) {
		CKey* Key = CameraCurveDistance->GetKey(i);
		if (Key) {
			Int32 CameraFrame_ = Key->GetTime().GetFrame(30) + TimeOffset;
			mmd::VMD_Camera CameraFrame;
			if (Frames.FindValue(CameraFrame_))
			{
				CameraFrame = *(Frames.FindValue(CameraFrame_));
				Frames.Erase(CameraFrame_)iferr_return;
			}
			if (i != CameraCurveDistance->GetKeyCount() - 1)
			{
				CKey* NextKey = CameraCurveDistance->GetKey(i + 1);
				if (NextKey)
				{
					Int32 NextCameraFrame_ = NextKey->GetTime().GetFrame(30) + TimeOffset;
					Int32 TimeOfTwoFrames = NextCameraFrame_ - CameraFrame_;
					Float ValueOfTwoFrames = NextKey->GetValue() - Key->GetValue();
					CameraFrame.frame_no = (UInt32)CameraFrame_;
					CameraFrame.distance = Key->GetValue() * PositionMultiple;
					CameraFrame.DCurve.ax = (UChar)((Key->GetTimeRight().GetFrame(30) * 128) / TimeOfTwoFrames);
					CameraFrame.DCurve.ay = (UChar)((Key->GetValueRight() * 127.0) / (ValueOfTwoFrames *  PositionMultiple));
					CameraFrame.DCurve.bx = (UChar)((NextKey->GetTimeLeft().GetFrame(30) * -128) / TimeOfTwoFrames);
					CameraFrame.DCurve.by = (UChar)((NextKey->GetValueLeft() * (Float)-128) / (ValueOfTwoFrames * PositionMultiple));
					Frames.Insert(CameraFrame_, CameraFrame)iferr_return;
				}

			}
			else
			{
				CameraFrame.frame_no = (UInt32)CameraFrame_;
				CameraFrame.distance = Key->GetValue()* PositionMultiple;
				CameraFrame.DCurve.ax = 20;
				CameraFrame.DCurve.ay = 20;
				CameraFrame.DCurve.bx = 107;
				CameraFrame.DCurve.by = 107;
				Frames.Insert(CameraFrame_, CameraFrame)iferr_return;
			}
		}
	}
	for (Int32 i = 0; i < CameraCurveAOV->GetKeyCount(); i++)
	{
		CKey* Key = CameraCurveAOV->GetKey(i);
		if (Key)
		{
			Int32 CameraFrame_ = Key->GetTime().GetFrame(30) + TimeOffset;
			mmd::VMD_Camera CameraFrame;
			if (Frames.FindValue(CameraFrame_))
			{
				CameraFrame = *(Frames.FindValue(CameraFrame_));
				Frames.Erase(CameraFrame_)iferr_return;
			}
			if (i != CameraCurveAOV->GetKeyCount() - 1)
			{
				CKey* NextKey = CameraCurveAOV->GetKey(i + 1);
				if (NextKey)
				{
					Int32 NextCameraFrame_ = NextKey->GetTime().GetFrame(30) + TimeOffset;
					Int32 TimeOfTwoFrames = NextCameraFrame_ - CameraFrame_;
					Float ValueOfTwoFrames = NextKey->GetValue() - Key->GetValue();
					CameraFrame.frame_no = (UInt32)CameraFrame_;
					CameraFrame.viewing_angle = Key->GetValue();
					CameraFrame.VCurve.ax = (UChar)((Key->GetTimeRight().GetFrame(30) * 128) / TimeOfTwoFrames);
					CameraFrame.VCurve.ay = (UChar)((Key->GetValueRight() * 127.0) / ValueOfTwoFrames);
					CameraFrame.VCurve.bx = (UChar)((NextKey->GetTimeLeft().GetFrame(30) * -128) / TimeOfTwoFrames);
					CameraFrame.VCurve.by = (UChar)((NextKey->GetValueLeft() * (Float)-128) / ValueOfTwoFrames);
					Frames.Insert(CameraFrame_, CameraFrame)iferr_return;
				}

			}
			else
			{
				CameraFrame.frame_no = (UInt32)CameraFrame_;
				CameraFrame.viewing_angle = Key->GetValue();
				CameraFrame.VCurve.ax = 20;
				CameraFrame.VCurve.ay = 20;
				CameraFrame.VCurve.bx = 107;
				CameraFrame.VCurve.by = 107;
				Frames.Insert(CameraFrame_, CameraFrame)iferr_return;
			}
		}
	}

	mmd_animation->ModelName = "カメラ・照明"_s;
	mmd_animation->CameraFrameNumber = Frames.GetCount();
	for (mmd::VMD_Camera val : Frames.GetValues())
	{
		mmd_animation->camera_frames.Append(val)iferr_return;
	}
	iferr(mmd_animation->WriteToFile(file))
	{
		GePrint(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_EXPORT_WRITE_ERR));
		MessageDialog(GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_EXPORT_WRITE_ERR));
		file.Free();
		return maxon::UnexpectedError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_EXPORT_ERR) + GeLoadString(IDS_MES_EXPORT_WRITE_ERR));
	}
	timing.Stop();
	StatusClear();
	MessageDialog(GeLoadString(IDS_MES_EXPORT_OK, maxon::String::UIntToString(mmd_animation->CameraFrameNumber), String::FloatToString(timing.GetMilliseconds())));
	Frames.Reset();
	file.Free();
	return maxon::OK;
}

maxon::Result<void> mmd::VMDAnimation::FromFileImportMotions(Float& PositionMultiple, Float& TimeOffset, Bool& QuaternionRotationSW, Bool& DetailReport, Bool& ByTag) {
	iferr_scope;
	Filename fn;
	AutoAlloc<BaseFile> file;
	BaseDocument* doc = GetActiveDocument();
	if (doc == nullptr) {
		GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + "error");
		MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR));
		file.Free();
		return maxon::NullptrError(MAXON_SOURCE_LOCATION);
	}
	BaseObject* SelectObject = doc->GetActiveObject();
	if (SelectObject == nullptr) {
		GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_SELECT_ERR));
		MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_SELECT_ERR));
		file.Free();
		return maxon::NullptrError(MAXON_SOURCE_LOCATION);
	}
	if (!fn.FileSelect(FILESELECTTYPE::ANYTHING, FILESELECT::LOAD, GeLoadString(IDS_MES_OPENFILE))) {
		file.Free();
		return maxon::NullptrError(MAXON_SOURCE_LOCATION);
	}
	if (file == nullptr) {
		GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
		MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
		return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
	}
	if (!file->Open(fn, FILEOPEN::READ, FILEDIALOG::ANY, BYTEORDER::V_INTEL, MACTYPE_CINEMA, MACCREATOR_CINEMA)) {
		GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_OPEN_FILE_ERR));
		MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_OPEN_FILE_ERR));
		file.Free();
		return maxon::UnexpectedError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_OPEN_FILE_ERR));
	}
	if (!(fn.CheckSuffix("vmd"_s) || (fn.CheckSuffix("VMD"_s)))) {
		GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_IMPORT_TYPE_ERR));
		MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_IMPORT_TYPE_ERR));
		file.Free();
		return maxon::IllegalArgumentError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_IMPORT_TYPE_ERR));
	}
	maxon::TimeValue timing = maxon::TimeValue::GetTime();
	std::unique_ptr<mmd::VMDAnimation> mmd_animation(new mmd::VMDAnimation);
	if (mmd_animation == nullptr) {
		GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
		MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
		file.Free();
		return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_MEM_ERR));
	}
	iferr(mmd_animation->LoadFromFile(file)) {
		GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_IMPORT_READ_ERR));
		MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_IMPORT_READ_ERR));
		file.Free();
		return maxon::UnexpectedError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_IMPORT_READ_ERR));
	}
	if (mmd_animation->IsCamera == 1) {
		GePrint(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_IMPORT_MOD_ERR));
		MessageDialog(GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_IMPORT_MOD_ERR));
		file.Free();
		return maxon::IllegalArgumentError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_IMPORT_ERR) + GeLoadString(IDS_MES_IMPORT_MOD_ERR));
	}
	struct morph_id_tag
	{
		DescID id;
		BaseTag* tag;
	};
	maxon::HashMap<String, maxon::BaseArray<BaseObject*> > bone_name_map;
	maxon::HashMap<String, maxon::BaseArray<morph_id_tag> > morph_name_map;

	maxon::Queue<BaseObject*> nodes;
	nodes.Push(SelectObject)iferr_return;
	GeData data;

	while (!nodes.IsEmpty())
	{
		BaseObject* node = *(nodes.Pop());
		while (node != nullptr)
		{
			if (node->GetType() == Ojoint)
			{
				if (ByTag) {
					BaseTag* node_tag = node->GetTag(ID_PMX_BONE_TAG);
					if (node_tag != nullptr) {						
						
						node_tag->GetParameter(DescID(BONE_NAME_LOCAL), data, DESCFLAGS_GET::NONE);
						String bone_name = data.GetString();
						auto bone_arr_ptr = bone_name_map.Find(bone_name);
						if (bone_arr_ptr == nullptr) {
							maxon::BaseArray<BaseObject*>bone_arr;
							bone_arr.Append(node)iferr_return;
							bone_name_map.Insert(bone_name, bone_arr)iferr_return;
						}
						else {
							bone_arr_ptr->GetValue().Append(node)iferr_return;
						}
					}
					else {
						String bone_name = node->GetName();
						auto bone_arr_ptr = bone_name_map.Find(bone_name);
						if (bone_arr_ptr == nullptr) {
							maxon::BaseArray<BaseObject*>bone_arr;
							bone_arr.Append(node)iferr_return;
							bone_name_map.Insert(bone_name, bone_arr)iferr_return;
						}
						else {
							bone_arr_ptr->GetValue().Append(node)iferr_return;
						}
					}
				}
				else {
					String bone_name = node->GetName();
					auto bone_arr_ptr = bone_name_map.Find(bone_name);
					if (bone_arr_ptr == nullptr) {
						maxon::BaseArray<BaseObject*>bone_arr;
						bone_arr.Append(node)iferr_return;
						bone_name_map.Insert(bone_name, bone_arr)iferr_return;
					}
					else {
						bone_arr_ptr->GetValue().Append(node)iferr_return;
					}
				}			
			}
			BaseTag* const tag = node->GetTag(Tposemorph);
			if (tag != nullptr && tag->IsInstanceOf(Tposemorph))
			{
				CAPoseMorphTag* const pose_morph_tag = static_cast<CAPoseMorphTag*>(tag);
				for (Int32 i = 0; i < pose_morph_tag->GetMorphCount(); i++)
				{
					String morph_name = pose_morph_tag->GetMorph(i)->GetName();
					auto morph_arr_ptr = morph_name_map.Find(morph_name);
					if (morph_arr_ptr == nullptr) {
						maxon::BaseArray<morph_id_tag>morph_arr;
						morph_arr.Append(morph_id_tag{ pose_morph_tag->GetMorphID(i),tag })iferr_return;
						morph_name_map.Insert(morph_name, morph_arr)iferr_return;
					}
					else {
						morph_arr_ptr->GetValue().Append(morph_id_tag{ pose_morph_tag->GetMorphID(i),tag })iferr_return;
					}
				}
			}
			nodes.Push(node->GetDown())iferr_return;
			if (node != SelectObject) {
				node = node->GetNext();
			}
			else {
				break;
			}				
		}
	}
	nodes.Reset();

	maxon::HashMap<String, maxon::BaseList<VMD_Motion>*> MotionFrameList_map;
	maxon::HashMap<String, maxon::BaseList<VMD_Morph>*> MorphFrameList_map;
	Int32 MotionFrameNumber = mmd_animation->MotionFrameNumber;
	for (Int32 i = 0; i < MotionFrameNumber; i++)
	{
		String bone_name = mmd_animation->motion_frames[i].bone_name;
		auto MotionFrame_ptr = MotionFrameList_map.Find(bone_name);
		if (MotionFrame_ptr == nullptr)
		{
			maxon::BaseList<VMD_Motion>* MotionFrame = new maxon::BaseList<VMD_Motion>;
			MotionFrame->Append(mmd_animation->motion_frames[i])iferr_return;
			MotionFrameList_map.Insert(bone_name, MotionFrame)iferr_return;
		}
		else
		{
			MotionFrame_ptr->GetValue()->Append(mmd_animation->motion_frames[i])iferr_return;
		}
	}
	Int32 MorphFrameNumber = mmd_animation->MorphFrameNumber;
	for (Int32 i = 0; i < MorphFrameNumber; i++)
	{
		String morph_name = mmd_animation->morph_frames[i].morph_name;
		auto MorphFrame_ptr = MorphFrameList_map.Find(morph_name);
		if (MorphFrame_ptr == nullptr)
		{
			maxon::BaseList<VMD_Morph>* MorphFrame = new maxon::BaseList<VMD_Morph>;
			MorphFrame->Append(mmd_animation->morph_frames[i])iferr_return;
			MorphFrameList_map.Insert(morph_name, MorphFrame)iferr_return;
		}
		else
		{
			MorphFrame_ptr->GetValue()->Append(mmd_animation->morph_frames[i])iferr_return;
		}
	}
	Int32 MaxTime = maxon::Max((doc->GetMaxTime()).GetFrame(30), maxon::Max((Int32)(mmd_animation->motion_frames.End() - 1).GetPtr()->frame_no, (Int32)(mmd_animation->morph_frames.End() - 1).GetPtr()->frame_no));
	mmd_animation->~VMDAnimation();

	mmd::VMD_Motion MotionFrame;
	mmd::VMD_Motion NextMotionFrame;
	BaseTime MotionKeyTime = BaseTime(0, 30);
	Float TimeOfTwoMotionFrames = 0.0;
	Float ValueOfTwoMotionFrames = 0.0;
	BaseTime MotionKeyTimeLeft[6] = { BaseTime(0.0, 30) };
	Float MotionKeyValueLeft[6] = { 0.0 };
	maxon::BaseArray<String> not_find_bone_S;
	Int bone_cnt = 0;
	Int32 motion_frame_bone_number = MotionFrameList_map.GetCount();
	String motion_frame_bone_number_S = String::IntToString(motion_frame_bone_number);
	for (String motion_bone_name : MotionFrameList_map.GetKeys())
	{
		maxon::BaseList<mmd::VMD_Motion>* MotionFrameList = MotionFrameList_map.Find(motion_bone_name)->GetValue();
		auto bone_ptr = bone_name_map.Find(motion_bone_name);

		if (bone_ptr != nullptr)
		{
			for (BaseObject* bone : bone_ptr->GetValue()) {
				if (bone != nullptr)
				{
					if (QuaternionRotationSW && bone->IsQuaternionRotationMode() == false) {
						bone->SetQuaternionRotationMode(true, false);
					}
					CTrack* BoneTrackPX = bone->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_X, DTYPE_REAL, 0)));
					CTrack::Free(BoneTrackPX);
					BoneTrackPX = CTrack::Alloc(bone, DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_X, DTYPE_REAL, 0)));
					if (BoneTrackPX == nullptr)return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION);
					bone->InsertTrackSorted(BoneTrackPX);
					CTrack* BoneTrackPY = bone->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Y, DTYPE_REAL, 0)));
					CTrack::Free(BoneTrackPY);
					BoneTrackPY = CTrack::Alloc(bone, DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Y, DTYPE_REAL, 0)));
					if (BoneTrackPY == nullptr)return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION);
					bone->InsertTrackSorted(BoneTrackPY);
					CTrack* BoneTrackPZ = bone->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Z, DTYPE_REAL, 0)));
					CTrack::Free(BoneTrackPZ);
					BoneTrackPZ = CTrack::Alloc(bone, DescID(DescLevel(ID_BASEOBJECT_REL_POSITION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Z, DTYPE_REAL, 0)));
					if (BoneTrackPZ == nullptr)return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION);
					bone->InsertTrackSorted(BoneTrackPZ);
					CTrack* BoneTrackRX = bone->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_X, DTYPE_REAL, 0)));
					CTrack::Free(BoneTrackRX);
					BoneTrackRX = CTrack::Alloc(bone, DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_X, DTYPE_REAL, 0)));
					if (BoneTrackRX == nullptr)return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION);
					bone->InsertTrackSorted(BoneTrackRX);
					CTrack* BoneTrackRY = bone->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Y, DTYPE_REAL, 0)));
					CTrack::Free(BoneTrackRY);
					BoneTrackRY = CTrack::Alloc(bone, DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Y, DTYPE_REAL, 0)));
					if (BoneTrackRY == nullptr)return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION);
					bone->InsertTrackSorted(BoneTrackRY);
					CTrack* BoneTrackRZ = bone->FindCTrack(DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Z, DTYPE_REAL, 0)));
					CTrack::Free(BoneTrackRZ);
					BoneTrackRZ = CTrack::Alloc(bone, DescID(DescLevel(ID_BASEOBJECT_REL_ROTATION, DTYPE_VECTOR, 0), DescLevel(VECTOR_Z, DTYPE_REAL, 0)));
					if (BoneTrackRZ == nullptr)return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION);
					bone->InsertTrackSorted(BoneTrackRZ);

					CCurve* BoneCurvePX = BoneTrackPX->GetCurve();
					CCurve* BoneCurvePY = BoneTrackPY->GetCurve();
					CCurve* BoneCurvePZ = BoneTrackPZ->GetCurve();
					CCurve* BoneCurveRX = BoneTrackRX->GetCurve();
					CCurve* BoneCurveRY = BoneTrackRY->GetCurve();
					CCurve* BoneCurveRZ = BoneTrackRZ->GetCurve();
					Int32 motion_frame_number = MotionFrameList->GetCount();
					for (Int32 i = 0; i < motion_frame_number; i++)
					{
						StatusSetText("Import motion of bone " + String::IntToString(bone_cnt) + "/" + motion_frame_bone_number_S);
						StatusSetBar(i * 100 / motion_frame_number);
						if (i == 0 && motion_frame_number != 1)
						{
							MotionFrame = MotionFrameList->operator[](i);
							NextMotionFrame = MotionFrameList->operator[](i + 1);
						}
						else if (i == motion_frame_number - 1)
						{
							MotionFrame = NextMotionFrame;
						}
						else
						{
							MotionFrame = NextMotionFrame;
							NextMotionFrame = MotionFrameList->operator[](i + 1);
						}
						TimeOfTwoMotionFrames = NextMotionFrame.frame_no - MotionFrame.frame_no;
						MotionKeyTime = BaseTime(MotionFrame.frame_no + TimeOffset, 30);

						Vector32 rotation;
						rotation.x = -maxon::ATan2(2 * MotionFrame.rotation.y * MotionFrame.rotation.w + 2 * MotionFrame.rotation.x * MotionFrame.rotation.z, 1 - 2 * (MotionFrame.rotation.x * MotionFrame.rotation.x + MotionFrame.rotation.y * MotionFrame.rotation.y));
						rotation.y = -maxon::ASin(2 * (MotionFrame.rotation.x * MotionFrame.rotation.w - MotionFrame.rotation.y * MotionFrame.rotation.z));
						rotation.z = -maxon::ATan2(2 * MotionFrame.rotation.z * MotionFrame.rotation.w + 2 * MotionFrame.rotation.x * MotionFrame.rotation.y, 1 - 2 * (MotionFrame.rotation.x * MotionFrame.rotation.x + MotionFrame.rotation.z * MotionFrame.rotation.z));
						Vector32 next_rotation;
						next_rotation.x = -maxon::ATan2(2 * NextMotionFrame.rotation.y * NextMotionFrame.rotation.w + 2 * NextMotionFrame.rotation.x * NextMotionFrame.rotation.z, 1 - 2 * (NextMotionFrame.rotation.x * NextMotionFrame.rotation.x + NextMotionFrame.rotation.y * NextMotionFrame.rotation.y));
						next_rotation.y = -maxon::ASin(2 * (NextMotionFrame.rotation.x * NextMotionFrame.rotation.w - NextMotionFrame.rotation.y * NextMotionFrame.rotation.z));
						next_rotation.z = -maxon::ATan2(2 * NextMotionFrame.rotation.z * NextMotionFrame.rotation.w + 2 * NextMotionFrame.rotation.x * NextMotionFrame.rotation.y, 1 - 2 * (NextMotionFrame.rotation.x * NextMotionFrame.rotation.x + NextMotionFrame.rotation.z * NextMotionFrame.rotation.z));

						CKey* MotionKeyPX = CKey::Alloc();//PX
						MotionKeyPX->SetTime(BoneCurvePX, MotionKeyTime);
						MotionKeyPX->SetValue(BoneCurvePX, MotionFrame.position.x * PositionMultiple);
						MotionKeyPX->ChangeNBit(NBIT::CKEY_BREAK, NBITCONTROL::SET);
						MotionKeyPX->ChangeNBit(NBIT::CKEY_REMOVEOVERSHOOT, NBITCONTROL::SET);
						ValueOfTwoMotionFrames = NextMotionFrame.position.x * PositionMultiple - MotionFrame.position.x * PositionMultiple;
						if (MotionFrame.XCurve.ax == 127 - MotionFrame.XCurve.bx && MotionFrame.XCurve.ay == 127 - MotionFrame.XCurve.by) {
							MotionKeyPX->SetInterpolation(BoneCurvePX, CINTERPOLATION::LINEAR);
						}
						else {
							MotionKeyPX->SetTimeLeft(BoneCurvePX, MotionKeyTimeLeft[0]);
							MotionKeyPX->SetValueLeft(BoneCurvePX, MotionKeyValueLeft[0]);
							MotionKeyPX->SetTimeRight(BoneCurvePX, BaseTime(TimeOfTwoMotionFrames * ((Float)NextMotionFrame.XCurve.ax / 127.0), 30));
							MotionKeyPX->SetValueRight(BoneCurvePX, ValueOfTwoMotionFrames * ((Float)NextMotionFrame.XCurve.ay / 127.0));
						}
						MotionKeyTimeLeft[0] = BaseTime(-TimeOfTwoMotionFrames * ((Float)NextMotionFrame.XCurve.bx / 127.0), 30);
						MotionKeyValueLeft[0] = -ValueOfTwoMotionFrames * ((Float)NextMotionFrame.XCurve.by / 127.0);
						BoneCurvePX->InsertKey(MotionKeyPX);

						CKey* MotionKeyPY = CKey::Alloc();//PY
						MotionKeyPY->SetTime(BoneCurvePY, MotionKeyTime);
						MotionKeyPY->SetValue(BoneCurvePY, MotionFrame.position.y * PositionMultiple);
						MotionKeyPY->ChangeNBit(NBIT::CKEY_BREAK, NBITCONTROL::SET);
						MotionKeyPY->ChangeNBit(NBIT::CKEY_REMOVEOVERSHOOT, NBITCONTROL::SET);
						ValueOfTwoMotionFrames = NextMotionFrame.position.y * PositionMultiple - MotionFrame.position.y * PositionMultiple;
						if (MotionFrame.YCurve.ax == 127 - MotionFrame.YCurve.bx && MotionFrame.YCurve.ay == 127 - MotionFrame.YCurve.by) {
							MotionKeyPY->SetInterpolation(BoneCurvePY, CINTERPOLATION::LINEAR);
						}
						else {
							MotionKeyPY->SetTimeLeft(BoneCurvePY, MotionKeyTimeLeft[1]);
							MotionKeyPY->SetValueLeft(BoneCurvePY, MotionKeyValueLeft[1]);
							MotionKeyPY->SetTimeRight(BoneCurvePY, BaseTime(TimeOfTwoMotionFrames * ((Float)NextMotionFrame.YCurve.ax / 127.0), 30));
							MotionKeyPY->SetValueRight(BoneCurvePY, ValueOfTwoMotionFrames * ((Float)NextMotionFrame.YCurve.ay / 127.0));
						}
						MotionKeyTimeLeft[1] = BaseTime(-TimeOfTwoMotionFrames * ((Float)NextMotionFrame.YCurve.bx / 127.0), 30);
						MotionKeyValueLeft[1] = -ValueOfTwoMotionFrames * ((Float)NextMotionFrame.YCurve.by / 127.0);
						BoneCurvePY->InsertKey(MotionKeyPY);

						CKey* MotionKeyPZ = CKey::Alloc();//PZ
						MotionKeyPZ->SetTime(BoneCurvePZ, MotionKeyTime);
						MotionKeyPZ->SetValue(BoneCurvePZ, MotionFrame.position.z * PositionMultiple);
						MotionKeyPZ->ChangeNBit(NBIT::CKEY_BREAK, NBITCONTROL::SET);
						MotionKeyPZ->ChangeNBit(NBIT::CKEY_REMOVEOVERSHOOT, NBITCONTROL::SET);
						ValueOfTwoMotionFrames = NextMotionFrame.position.z * PositionMultiple - MotionFrame.position.z * PositionMultiple;
						if (MotionFrame.ZCurve.ax == 127 - MotionFrame.ZCurve.bx && MotionFrame.ZCurve.ay == 127 - MotionFrame.ZCurve.by) {
							MotionKeyPZ->SetInterpolation(BoneCurvePZ, CINTERPOLATION::LINEAR);
						}
						else {
							MotionKeyPZ->SetTimeLeft(BoneCurvePZ, MotionKeyTimeLeft[2]);
							MotionKeyPZ->SetValueLeft(BoneCurvePZ, MotionKeyValueLeft[2]);
							MotionKeyPZ->SetTimeRight(BoneCurvePZ, BaseTime(TimeOfTwoMotionFrames * ((Float)NextMotionFrame.ZCurve.ax / 127.0), 30));
							MotionKeyPZ->SetValueRight(BoneCurvePZ, ValueOfTwoMotionFrames * ((Float)NextMotionFrame.ZCurve.ay / 127.0));
						}
						MotionKeyTimeLeft[2] = BaseTime(-TimeOfTwoMotionFrames * ((Float)NextMotionFrame.ZCurve.bx / 127.0), 30);
						MotionKeyValueLeft[2] = -ValueOfTwoMotionFrames * ((Float)NextMotionFrame.ZCurve.by / 127.0);
						BoneCurvePZ->InsertKey(MotionKeyPZ);

						CKey* MotionKeyRX = CKey::Alloc();//RX
						MotionKeyRX->SetTime(BoneCurveRX, MotionKeyTime);
						MotionKeyRX->SetValue(BoneCurveRX, rotation.x);
						if (!QuaternionRotationSW) {
							MotionKeyRX->ChangeNBit(NBIT::CKEY_BREAK, NBITCONTROL::SET);
							MotionKeyRX->ChangeNBit(NBIT::CKEY_REMOVEOVERSHOOT, NBITCONTROL::SET);
							ValueOfTwoMotionFrames = next_rotation.x - rotation.x;
							if (MotionFrame.RCurve.ax == 127 - MotionFrame.RCurve.bx && MotionFrame.RCurve.ay == 127 - MotionFrame.RCurve.by) {
								MotionKeyRX->SetInterpolation(BoneCurveRX, CINTERPOLATION::LINEAR);
							}
							else {
								MotionKeyRX->SetTimeLeft(BoneCurveRX, MotionKeyTimeLeft[3]);
								MotionKeyRX->SetValueLeft(BoneCurveRX, MotionKeyValueLeft[3]);
								MotionKeyRX->SetTimeRight(BoneCurveRX, BaseTime(TimeOfTwoMotionFrames * ((Float)NextMotionFrame.RCurve.ax / 127.0), 30));
								MotionKeyRX->SetValueRight(BoneCurveRX, ValueOfTwoMotionFrames * ((Float)NextMotionFrame.RCurve.ay / 127.0));
							}
							MotionKeyTimeLeft[3] = BaseTime(-TimeOfTwoMotionFrames * ((Float)NextMotionFrame.RCurve.bx / 127.0), 30);
							MotionKeyValueLeft[3] = -ValueOfTwoMotionFrames * ((Float)NextMotionFrame.RCurve.by / 127.0);
						}
						BoneCurveRX->InsertKey(MotionKeyRX);

						CKey* MotionKeyRY = CKey::Alloc();//RY
						MotionKeyRY->SetTime(BoneCurveRY, MotionKeyTime);
						MotionKeyRY->SetValue(BoneCurveRY, rotation.y);
						if (!QuaternionRotationSW) {
							MotionKeyRY->ChangeNBit(NBIT::CKEY_BREAK, NBITCONTROL::SET);
							MotionKeyRY->ChangeNBit(NBIT::CKEY_REMOVEOVERSHOOT, NBITCONTROL::SET);
							ValueOfTwoMotionFrames = next_rotation.y - rotation.y;
							if (MotionFrame.RCurve.ax == 127 - MotionFrame.RCurve.bx && MotionFrame.RCurve.ay == 127 - MotionFrame.RCurve.by) {
								MotionKeyRY->SetInterpolation(BoneCurveRY, CINTERPOLATION::LINEAR);
							}
							else {
								MotionKeyRY->SetTimeLeft(BoneCurveRY, MotionKeyTimeLeft[4]);
								MotionKeyRY->SetValueLeft(BoneCurveRY, MotionKeyValueLeft[4]);
								MotionKeyRY->SetTimeRight(BoneCurveRY, BaseTime(TimeOfTwoMotionFrames * ((Float)NextMotionFrame.RCurve.ax / 127.0), 30));
								MotionKeyRY->SetValueRight(BoneCurveRY, ValueOfTwoMotionFrames * ((Float)NextMotionFrame.RCurve.ay / 127.0));
							}
							MotionKeyTimeLeft[4] = BaseTime(-TimeOfTwoMotionFrames * ((Float)NextMotionFrame.RCurve.bx / 127.0), 30);
							MotionKeyValueLeft[4] = -ValueOfTwoMotionFrames * ((Float)NextMotionFrame.RCurve.by / 127.0);
						}
						BoneCurveRY->InsertKey(MotionKeyRY);

						CKey* MotionKeyRZ = CKey::Alloc();//RZ
						MotionKeyRZ->SetTime(BoneCurveRZ, MotionKeyTime);
						MotionKeyRZ->SetValue(BoneCurveRZ, rotation.z);
						if (!QuaternionRotationSW) {
							MotionKeyRZ->ChangeNBit(NBIT::CKEY_BREAK, NBITCONTROL::SET);
							MotionKeyRZ->ChangeNBit(NBIT::CKEY_REMOVEOVERSHOOT, NBITCONTROL::SET);
							ValueOfTwoMotionFrames = next_rotation.z - rotation.z;
							if (MotionFrame.RCurve.ax == 127 - MotionFrame.RCurve.bx && MotionFrame.RCurve.ay == 127 - MotionFrame.RCurve.by) {
								MotionKeyRZ->SetInterpolation(BoneCurveRZ, CINTERPOLATION::LINEAR);
							}
							else {
								MotionKeyRZ->SetTimeLeft(BoneCurveRZ, MotionKeyTimeLeft[5]);
								MotionKeyRZ->SetValueLeft(BoneCurveRZ, MotionKeyValueLeft[5]);
								MotionKeyRZ->SetTimeRight(BoneCurveRZ, BaseTime(TimeOfTwoMotionFrames * ((Float)NextMotionFrame.RCurve.ax / 127.0), 30));
								MotionKeyRZ->SetValueRight(BoneCurveRZ, ValueOfTwoMotionFrames * ((Float)NextMotionFrame.RCurve.ay / 127.0));
							}
							MotionKeyTimeLeft[5] = BaseTime(-TimeOfTwoMotionFrames * ((Float)NextMotionFrame.RCurve.bx / 127.0), 30);
							MotionKeyValueLeft[5] = -ValueOfTwoMotionFrames * ((Float)NextMotionFrame.RCurve.by / 127.0);
						}
						BoneCurveRZ->InsertKey(MotionKeyRZ);
					}
					bone_cnt++;
				}
			}
		}
		else
		{
			not_find_bone_S.Append(motion_bone_name)iferr_return;
		}
	}

	mmd::VMD_Morph MorphFrame;
	maxon::BaseArray<String> not_find_morph_S;
	Int32 morph_cnt = 0;
	Int32 motion_frame_morph_number = MorphFrameList_map.GetCount();
	String motion_frame_morph_number_S = String::IntToString(motion_frame_morph_number);
	for (String morph_motion_name : MorphFrameList_map.GetKeys())
	{
		maxon::BaseList<mmd::VMD_Morph>* MorphFrameList = (MorphFrameList_map.Find(morph_motion_name)->GetValue());
		auto morph_ptr = morph_name_map.Find(morph_motion_name);
		if (morph_ptr != nullptr)
		{
			for (morph_id_tag& morph_id_tag_ : morph_ptr->GetValue()) {
				DescID morphID = morph_id_tag_.id;
				BaseTag* pose_morph_tag = morph_id_tag_.tag;
				CTrack* MorphTrack = pose_morph_tag->FindCTrack(morphID);
				if (MorphTrack == nullptr)
				{
					MorphTrack = CTrack::Alloc(pose_morph_tag, morphID);
					if (MorphTrack == nullptr)
						return maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION);
					pose_morph_tag->InsertTrackSorted(MorphTrack);
				}
				CCurve* MorphCurve = MorphTrack->GetCurve();
				Int32 morph_frame_number = MorphFrameList->GetCount();
				for (Int32 i = 0; i < morph_frame_number; i++)
				{
					StatusSetText("Import motion of morph " + String::IntToString(morph_cnt) + "/" + motion_frame_morph_number_S);
					StatusSetBar(i * 100 / morph_frame_number);
					MorphFrame = (*MorphFrameList)[i];
					CKey* MorphKey = CKey::Alloc();
					MorphKey->SetTime(MorphCurve, BaseTime(MorphFrame.frame_no + TimeOffset, 30));
					MorphKey->SetValue(MorphCurve, MorphFrame.weight);
					MorphCurve->InsertKey(MorphKey);
				}
				morph_cnt++;
			}
		}
		else
		{
			not_find_morph_S.Append(morph_motion_name)iferr_return;
		}
	}
	timing.Stop();
	StatusClear();
	doc->SetMaxTime(BaseTime(MaxTime, 30));
	doc->SetLoopMaxTime(BaseTime(MaxTime, 30));
	EventAdd(EVENT::NONE);
	doc->SetTime(BaseTime(1, 30));
	doc->SetTime(BaseTime(0, 30));
	String report = GeLoadString(IDS_MES_IMPORT_MOT_OK, String::IntToString(bone_cnt), String::IntToString(morph_cnt), String::IntToString(motion_frame_bone_number + motion_frame_morph_number), String::FloatToString(timing.GetMilliseconds())) + "\n";
	if (DetailReport == 1) {
		report += GeLoadString(IDS_MES_IMPORT_MOT_CF_BONE, String::IntToString(not_find_bone_S.GetCount())) + ":\n";
		for (String i : not_find_bone_S)
		{
			report += "\"" + i + "\" ";
		}
		report += "\n" + GeLoadString(IDS_MES_IMPORT_MOT_CF_MORPH, String::IntToString(not_find_morph_S.GetCount())) + ":\n";
		for (String i : not_find_morph_S)
		{
			report += "\"" + i + "\" ";
		}
	}
	MessageDialog(report);
	bone_name_map.Reset();
	morph_name_map.Reset();
	for (auto i : MorphFrameList_map.GetValues()) {
		delete i;
	}
	MorphFrameList_map.Reset();
	for (auto i : MotionFrameList_map.GetValues()) {
		delete i;
	}
	MotionFrameList_map.Reset();
	not_find_bone_S.Reset();
	not_find_morph_S.Reset();
	return maxon::OK;
}

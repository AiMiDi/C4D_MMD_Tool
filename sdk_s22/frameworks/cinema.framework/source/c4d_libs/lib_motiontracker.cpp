#include "lib_motiontracker.h"



static Sdk2dTrackDataLibrary *CheckLibClass2dTrackData(Int32 offset)
{
	static Sdk2dTrackDataLibrary* lib_class_2dTrackDataPtr = nullptr;
	return (Sdk2dTrackDataLibrary*)CheckLib(MT_2DTRACKDATACLASSLIB, offset, (C4DLibrary**)&lib_class_2dTrackDataPtr);
}


#define Mt2dTrackDataClassCall(b) 		Sdk2dTrackDataLibrary *lib = CheckLibClass2dTrackData(LIBOFFSET(Sdk2dTrackDataLibrary, b)); \
															if (!lib || !lib->b) return; \
															(((Mt2dTrackDataSdk*)this)->*lib->b)

#define Mt2dTrackDataClassCallR(a, b) Sdk2dTrackDataLibrary *lib = CheckLibClass2dTrackData(LIBOFFSET(Sdk2dTrackDataLibrary, b)); \
															if (!lib || !lib->b) return a; \
															return (((Mt2dTrackDataSdk*)this)->*lib->b)


Mt2dTrackData* Mt2dTrackData::Alloc()
{
	Sdk2dTrackDataLibrary *lib = CheckLibClass2dTrackData(LIBOFFSET(Sdk2dTrackDataLibrary, Alloc));
	if (!lib)
		return nullptr;

	return lib->Alloc();
}

void Mt2dTrackData::Free(Mt2dTrackData *&p)
{
	if (!p)
		return;

	Sdk2dTrackDataLibrary *lib = CheckLibClass2dTrackData(LIBOFFSET(Sdk2dTrackDataLibrary, Free));
	if (!lib)
		return;

	lib->Free(p);
	p = nullptr;
}


Int32 Mt2dTrackData::GetTrackCount() const
{
	Mt2dTrackDataClassCallR(0, GetTrackCountPtr)();
}


Mt2dTrack* Mt2dTrackData::GetTrackByIndex(Int32 idx) const
{
	Mt2dTrackDataClassCallR(nullptr, GetTrackByIndexPtr)(idx);
}


Mt2dTrack* Mt2dTrackData::GetTrackByName(const String& name) const
{
	Mt2dTrackDataClassCallR(nullptr, GetTrackByNamePtr)(name);
}


Mt2dTrack* Mt2dTrackData::GetTrackByGid(const MtTrkGid* sdkTrkGid) const
{
	Mt2dTrackDataClassCallR(nullptr, GetTrackByGidPtr)(sdkTrkGid);
}


BaseSelect* Mt2dTrackData::GetTrackIndices(Bool userTracks, Bool autoTracks) const
{
	Mt2dTrackDataClassCallR(nullptr, GetTrackIndicesPtr)(userTracks, autoTracks);
}


// PhSDK 3/7  Add method implementation for publicly exposed SDK class, which indirectly calls via function pointer in C4DLibrary derived link class  (corresponds to PhSDK 5)




// PhLibSDK 4/4 Create CheckLibClass and Call/CallR definitions;

static Sdk2dTrackLibrary *CheckLibClass2dTrack(Int32 offset)
{
	static Sdk2dTrackLibrary* lib_class_2dTrackPtr = nullptr;
	return (Sdk2dTrackLibrary*)CheckLib(MT_2DTRACKCLASSLIB, offset, (C4DLibrary**)&lib_class_2dTrackPtr);
}


#define Mt2dTrackClassCall(b) 		Sdk2dTrackLibrary *lib = CheckLibClass2dTrack(LIBOFFSET(Sdk2dTrackLibrary, b)); \
															if (!lib || !lib->b) return; \
															(((Mt2dTrackSdk*)this)->*lib->b)

#define Mt2dTrackClassCallR(a, b) Sdk2dTrackLibrary *lib = CheckLibClass2dTrack(LIBOFFSET(Sdk2dTrackLibrary, b)); \
															if (!lib || !lib->b) return a; \
															return (((Mt2dTrackSdk*)this)->*lib->b)

Mt2dTrack* Mt2dTrack::Alloc()
{
	Sdk2dTrackLibrary *lib = CheckLibClass2dTrack(LIBOFFSET(Sdk2dTrackLibrary, Alloc));
	if (!lib)
		return nullptr;

	return lib->Alloc();
}

void Mt2dTrack::Free(Mt2dTrack *&p)
{
	if (!p)
		return;

	Sdk2dTrackLibrary *lib = CheckLibClass2dTrack(LIBOFFSET(Sdk2dTrackLibrary, Free));
	if (!lib)
		return;

	lib->Free(p);
	p = nullptr;
}




String Mt2dTrack::GetName() const
{
	Mt2dTrackClassCallR("", GetNamePtr)();
}

MtTrkGid* Mt2dTrack::GetId() const
{
	Mt2dTrackClassCallR(nullptr, GetIdPtr)();
}


Mt2dTrackStatus Mt2dTrack::GetStatus() const
{
	Mt2dTrackClassCallR(Mt2dTrackStatus::INVALID_TRACK, GetStatusPtr)();
}


BaseSelect* Mt2dTrack::GetFramesWithTrackData() const
{
	Mt2dTrackClassCallR(0, GetFramesWithTrackDataPtr)();
}


MtData* Mt2dTrack::GetDataForFrame(Int32 frameNum) const
{
	Mt2dTrackClassCallR(0, GetDataForFramePtr)(frameNum);
}

MtData* Mt2dTrack::GetDataForCurrentFrame() const
{
	Mt2dTrackClassCallR(0, GetDataForCurrentFramePtr)();
}




static SdkDataLibrary *CheckLibClassData(Int32 offset)
{
	static SdkDataLibrary* lib_class_projPtr = nullptr;
	return (SdkDataLibrary*)CheckLib(MT_DATACLASSLIB, offset, (C4DLibrary**)&lib_class_projPtr);
}


#define MtDataClassCall(b) 		SdkDataLibrary *lib = CheckLibClassData(LIBOFFSET(SdkDataLibrary, b)); \
															if (!lib || !lib->b) return; \
															(((MtDataSdk*)this)->*lib->b)

#define MtDataClassCallR(a, b) SdkDataLibrary *lib = CheckLibClassData(LIBOFFSET(SdkDataLibrary, b)); \
															if (!lib || !lib->b) return a; \
															return (((MtDataSdk*)this)->*lib->b)


MtData* MtData::Alloc()
{
	SdkDataLibrary *lib = CheckLibClassData(LIBOFFSET(SdkDataLibrary, Alloc));
	if (!lib)
		return nullptr;

	return lib->Alloc();
}

void MtData::Free(MtData *&p)
{
	if (!p)
		return;

	SdkDataLibrary *lib = CheckLibClassData(LIBOFFSET(SdkDataLibrary, Free));
	if (!lib)
		return;

	lib->Free(p);
	p = nullptr;
}




Vector MtData::GetNormalisedPosition() const
{
	MtDataClassCallR(Vector(), GetNormalisedPositionPtr)();
}


Vector MtData::GetPixelPosition(MtFootageData* sdkFh, Bool originalRes) const
{
	MtDataClassCallR(Vector(), GetPixelPositionPtr)(sdkFh, originalRes);
}


Vector MtData::GetCameraSpaceDirection(Float focalLength, Float sensorWidth) const
{
	MtDataClassCallR(Vector(), GetCameraSpaceDirectionPtr)(focalLength, sensorWidth);
}





static SdkFootageDataLibrary *CheckLibClassFootage(Int32 offset)
{
	static SdkFootageDataLibrary* lib_class_footagePtr = nullptr;
	return (SdkFootageDataLibrary*)CheckLib(MT_FOOTAGEDATACLASSLIB, offset, (C4DLibrary**)&lib_class_footagePtr);
}


#define MtFootageClassCall(b) 		SdkFootageDataLibrary *lib = CheckLibClassFootage(LIBOFFSET(SdkFootageDataLibrary, b)); \
															if (!lib || !lib->b) return; \
															(((MtFootageDataSdk*)this)->*lib->b)

#define MtFootageClassCallR(a, b) SdkFootageDataLibrary *lib = CheckLibClassFootage(LIBOFFSET(SdkFootageDataLibrary, b)); \
															if (!lib || !lib->b) return a; \
															return (((MtFootageDataSdk*)this)->*lib->b)


MtFootageData* MtFootageData::Alloc()
{
	SdkFootageDataLibrary *lib = CheckLibClassFootage(LIBOFFSET(SdkFootageDataLibrary, Alloc));
	if (!lib)
		return nullptr;

	return lib->Alloc();
}

void MtFootageData::Free(MtFootageData *&p)
{
	if (!p)
		return;

	SdkFootageDataLibrary *lib = CheckLibClassFootage(LIBOFFSET(SdkFootageDataLibrary, Free));
	if (!lib)
		return;

	lib->Free(p);
	p = nullptr;
}



Filename MtFootageData::GetFootageName() const
{
	MtFootageClassCallR(Filename(), GetFootageNamePtr)();
}

Int32 MtFootageData::GetFirstFrameNumber() const
{
	MtFootageClassCallR(-1, GetFirstFrameNumberPtr)();
}

Int32 MtFootageData::GetLastFrameNumber() const
{
	MtFootageClassCallR(-1, GetLastFrameNumberPtr)();
}

Int32 MtFootageData::GetResolutionWidthPix(Bool originalRes) const
{
	MtFootageClassCallR(0, GetResolutionWidthPixPtr)(originalRes);
}

Int32 MtFootageData::GetResolutionHeightPix(Bool originalRes) const
{
	MtFootageClassCallR(0, GetResolutionHeightPixPtr)(originalRes);
}


Float MtFootageData::GetResolutionAspectRatio() const
{
	MtFootageClassCallR(1.0, GetResolutionAspectRatioPtr)();
}

Float MtFootageData::GetImageAspectRatio() const
{
	MtFootageClassCallR(1.0, GetImageAspectRatioPtr)();
}

Float MtFootageData::GetPixelAspectRatio() const
{
	MtFootageClassCallR(1.0, GetPixelAspectRatioPtr)();
}

Float MtFootageData::GetDownsamplingFactor() const
{
	MtFootageClassCallR(1.0, GetDownsamplingFactorPtr)();
}




static SdkTrkGidLibrary *CheckLibClassTrkGid(Int32 offset)
{
	static SdkTrkGidLibrary* lib_class_trkGidPtr = nullptr;
	return (SdkTrkGidLibrary*)CheckLib(MT_TRKGIDCLASSLIB, offset, (C4DLibrary**)&lib_class_trkGidPtr);
}


#define MtTrkGidClassCall(b) 		SdkTrkGidLibrary *lib = CheckLibClassTrkGid(LIBOFFSET(SdkTrkGidLibrary, b)); \
															if (!lib || !lib->b) return; \
															(((MtTrkGidSdk*)this)->*lib->b)

#define MtTrkGidClassCallR(a, b) SdkTrkGidLibrary *lib = CheckLibClassTrkGid(LIBOFFSET(SdkTrkGidLibrary, b)); \
															if (!lib || !lib->b) return a; \
															return (((MtTrkGidSdk*)this)->*lib->b)


MtTrkGid* MtTrkGid::Alloc()
{
	SdkTrkGidLibrary *lib = CheckLibClassTrkGid(LIBOFFSET(SdkTrkGidLibrary, Alloc));
	if (!lib)
		return nullptr;

	return lib->Alloc();
}

void MtTrkGid::Free(MtTrkGid *&p)
{
	if (!p)
		return;

	SdkTrkGidLibrary *lib = CheckLibClassTrkGid(LIBOFFSET(SdkTrkGidLibrary, Free));
	if (!lib)
		return;

	lib->Free(p);
	p = nullptr;
}

Int32 MtTrkGid::ToInt() const
{
	MtTrkGidClassCallR(0, ToIntPtr)();
}



//---------------------------------------------------------------
/// Motion Tracker Library
//---------------------------------------------------------------


static SdkMotionTrackerObjectLibrary* CheckMtExtendLib(Int32 offset)
{
	static SdkMotionTrackerObjectLibrary* lib_mtSdkExtendPtr = nullptr;
	return (SdkMotionTrackerObjectLibrary*)CheckLib(MOTIONTRACKER_SDK_EXTEND_LIB, offset, (C4DLibrary**)&lib_mtSdkExtendPtr);
}



MotionTrackerObject* MotionTrackerObject::Alloc()
{
	return (MotionTrackerObject*)C4DOS.Bo->Alloc(Omotiontracker);
}

void MotionTrackerObject::Free(MotionTrackerObject*& bl)
{
	C4DOS.Bl->Free(bl);
	bl = nullptr;
}



Mt2dTrackData* MotionTrackerObject::Get2dTrackData() const
{
	SdkMotionTrackerObjectLibrary *lib = CheckMtExtendLib(LIBOFFSET(SdkMotionTrackerObjectLibrary, Get2dTrackDataPtr));
	if (!lib)
		return 0;

	return lib->Get2dTrackDataPtr((BaseObject*)this);
}


MtFootageData*	MotionTrackerObject::GetFootageData() const
{
	SdkMotionTrackerObjectLibrary *lib = CheckMtExtendLib(LIBOFFSET(SdkMotionTrackerObjectLibrary, GetFootageDataPtr));
	if (!lib)
		return 0;

	return lib->GetFootageDataPtr((BaseObject*)this);
}




/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef LIB_MOTIONTRACKER_H__
#define LIB_MOTIONTRACKER_H__

#include "c4d_library.h"
#include "c4d_baseobject.h"


/// @addtogroup group_motiontrackerlibrary Motion Tracker
/// @ingroup group_library
/// @{

//----------------------------------------------------------------------------------------
/// Represents a persistent unique ID number for a track.
///
/// For any specific Motion Tracker Object this ID always represents the same track, even if other tracks are added or deleted.
/// @note In contrast, track indices are not guaranteed to always refer to the same tracks between sessions.
//----------------------------------------------------------------------------------------
class MtTrkGid
{
private:
	MtTrkGid();
	~MtTrkGid();

public:
	//----------------------------------------------------------------------------------------
	/// @markInternal
	//----------------------------------------------------------------------------------------
	static MtTrkGid* Alloc();

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{MtTrkGids}
	/// @param[in,out] p							@theToDestruct{MtTrkGid}
	//----------------------------------------------------------------------------------------
	static void Free(MtTrkGid *&p);

	//----------------------------------------------------------------------------------------
	/// Tests whether this and @formatParam{rhs} have the same value.
	/// @param[in] rhs								The object with which to compare.
	/// @return												@trueIfOtherwiseFalse{values match}
	//----------------------------------------------------------------------------------------
	Bool operator ==(const MtTrkGid& rhs)
	{
		return ToInt() == rhs.ToInt();
	}

	//----------------------------------------------------------------------------------------
	/// Returns the ID number as a raw integer.
	/// @return												The raw integer.
	//----------------------------------------------------------------------------------------
	Int32 ToInt() const;
};


class Mt2dTrack;

//----------------------------------------------------------------------------------------
/// Provides access to 2D Tracking data.
///
/// Allows specific tracks to be retrieved based on name, index or unique ID.
//----------------------------------------------------------------------------------------
class Mt2dTrackData
{
private:
	Mt2dTrackData();
	~Mt2dTrackData();

public:
	//----------------------------------------------------------------------------------------
	/// @markInternal
	//----------------------------------------------------------------------------------------
	static Mt2dTrackData* Alloc();

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{Mt2dTrackDatas}
	/// @param[in,out] p							@theToDestruct{Mt2dTrackData}
	//----------------------------------------------------------------------------------------
	static void Free(Mt2dTrackData *&p);

	//----------------------------------------------------------------------------------------
	/// Queries the number of 2D tracks.
	/// @return												The number of tracks.
	//----------------------------------------------------------------------------------------
	Int32 GetTrackCount() const;

	//----------------------------------------------------------------------------------------
	/// Retrieves a track by index.
	/// @note Caller is responsible for calling @c Free() on the returned track when it is no longer needed.
	/// @param[in] idx								The index of desired track: @em 0 <= @formatParam{idx} < GetTrackCount().
	/// @return												A copy of the track, or @formatConstant{nullptr}. @callerOwnsPointed{Mt2dTrack}
	//----------------------------------------------------------------------------------------
	Mt2dTrack* GetTrackByIndex(Int32 idx) const;

	//----------------------------------------------------------------------------------------
	/// Retrieves a track by global identifier.
	/// @warning Caller is responsible for calling @c Free() on the returned track when it is no longer needed.
	/// @param[in] sdkTrkGid					The global ID of the desired track. @callerOwnsPointed{MtTrkGid}
	/// @return												A copy of the track, or @formatConstant{nullptr}. @callerOwnsPointed{Mt2dTrack}
	//----------------------------------------------------------------------------------------
	Mt2dTrack* GetTrackByGid(const MtTrkGid* sdkTrkGid) const;

	//----------------------------------------------------------------------------------------
	/// Retrieves a BaseSelect containing the valid indices for the tracks.
	/// @warning Caller is responsible for calling @c Free() on the returned track when it is no longer needed.
	/// @note  If @formatParam{userTracks} is @formatConstant{true} and @formatParam{autoTracks} is @formatConstant{true} then the function returns all indices from @em 0 to GetTrackCount() - @em 1.
	/// @param[in] userTracks					@trueOtherwiseFalse{to include user created tracks}
	/// @param[in] autoTracks					@trueOtherwiseFalse{to include automatic tracks}
	/// @return												A copy of the track, or @formatConstant{nullptr}. @callerOwnsPointed{Mt2dTrack}
	//----------------------------------------------------------------------------------------
	BaseSelect* GetTrackIndices(Bool userTracks = true, Bool autoTracks = false) const;

	//----------------------------------------------------------------------------------------
	/// Retrieves a track by name.
	/// @warning Caller is responsible for calling @c Free() on the returned track when it is no longer needed.
	/// @note The function returns the first track matching @formatParam{name}.
	/// @param[in] name								The name of wanted track.
	/// @return												A copy of the track, or @formatConstant{nullptr}. @callerOwnsPointed{Mt2dTrack}
	//----------------------------------------------------------------------------------------
	Mt2dTrack* GetTrackByName(const String& name) const;
};


class MtData;
class MtFootageData;


/// @addtogroup Mt2dTrackStatus
/// @ingroup group_enumeration
/// @{
enum Mt2dTrackStatus
{
	INVALID_TRACK = -1,			///< Not a valid track.
	UNTRACKED = 0,					///< Has not yet been tracked.
	TRACKED_VALID = 1,			///< Has been tracked, and is up to date.
	TRACKED_STALE = 2				///< Has been tracked, but needs updating. (Changes have been made, but track has not yet been retracked.)
};
/// @}

//----------------------------------------------------------------------------------------
/// Represents a single 2D track.
///
/// Contains a set of image positions for a set of frames.
/// Provides information about which frames the track exists for, the status of the track, and position data for the frames on which the track exists.
///
/// This data represents the 2D motion of a single feature within the footage.
//----------------------------------------------------------------------------------------
class Mt2dTrack
{
private:
	Mt2dTrack();
	~Mt2dTrack();

public:
	//----------------------------------------------------------------------------------------
	/// @markInternal
	//----------------------------------------------------------------------------------------
	static Mt2dTrack* Alloc();

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{Mt2dTracks}
	/// @param[in,out] p							@theToDestruct{Mt2dTrack}
	//----------------------------------------------------------------------------------------
	static void Free(Mt2dTrack *&p);

	//----------------------------------------------------------------------------------------
	/// Queries the track name.
	/// @return												The track name.
	//----------------------------------------------------------------------------------------
	String GetName() const;

	//----------------------------------------------------------------------------------------
	/// Queries the track global ID.
	/// @warning Caller is responsible for calling @c Free() on the returned track ID when it is no longer needed.
	/// @return												The track ID.
	/// @return												A copy of the track ID, or @formatConstant{nullptr}. @callerOwnsPointed{MtTrkGid}
	//----------------------------------------------------------------------------------------
	MtTrkGid* GetId() const;

	//----------------------------------------------------------------------------------------
	/// Queries the track status.
	/// @return												The track status.
	//----------------------------------------------------------------------------------------
	Mt2dTrackStatus GetStatus() const;

	//----------------------------------------------------------------------------------------
	/// Retrieves a BaseSelect containing the set of frames for which 2D tracking data exists.
	/// @warning Caller is responsible for calling @c Free() on the returned selection when it is no longer needed.
	/// @return												A copy of the BaseSelect of frames. @callerOwnsPointed{BaseSelect}
	//----------------------------------------------------------------------------------------
	BaseSelect* GetFramesWithTrackData() const;

	//----------------------------------------------------------------------------------------
	/// Retrieves the tracking data for given frame number.
	/// @warning Caller is responsible for calling @c Free() on the returned tracking data when it is no longer needed.
	/// Returns a pointer to a copy of the data. Caller is owner, and is responsible for calling Free on the pointer when no longer needed.
	/// @return												A copy of the tracking data, or @formatParam{nullptr} if it does not exists for requested frame. @callerOwnsPointed{MtData}
	//----------------------------------------------------------------------------------------
	MtData* GetDataForFrame(Int32 frameNum) const;

	//----------------------------------------------------------------------------------------
	/// Retrieves the tracking data for current frame of active document.
	/// @warning Caller is responsible for calling @c Free() on the returned tracking data when it is no longer needed.
	/// @note Normally GetDataForFrame() should be used instead with the frame number passed explicitly.
	/// @return												A copy of the current frame tracking data, or @formatParam{nullptr} if it does not exists. @callerOwnsPointed{MtData}
	//----------------------------------------------------------------------------------------
	MtData* GetDataForCurrentFrame() const;
};

//----------------------------------------------------------------------------------------
/// Represents a single frame of a single track.
///
/// Contains image position information which can be queried as normalized coordinates, pixel coordinates, or corresponding camera ray direction.
//----------------------------------------------------------------------------------------
class MtData
{
private:
	MtData();
	~MtData();

public:
	//----------------------------------------------------------------------------------------
	/// Retrieves the track position in normalized coordinates.
	/// @return												The track position:
	/// - Vector::x is in range @em -0.5 to @em +0.5 from left to right of image.
	/// - Vector::y is in range <em>-0.5/aspect</em> to <em>+0.5/aspect</em> from top to bottom of image, where @em aspect is the image aspect ratio.
	//----------------------------------------------------------------------------------------
	Vector GetNormalisedPosition() const;

	//----------------------------------------------------------------------------------------
	/// Retrieves the track position in footage pixel coordinates.
	/// @param[in] sdkFh							The footage object, used to define resolution and aspect ratio. @callerOwnsPointed{MtFootageData}
	/// @param[in] originalRes				If @formatConstant{true}, the returned pixel coordinates are for the original footage. If @formatConstant{false}, the returned pixel coordinates are for the downsampled footage.
	/// @return												The track position.
	//----------------------------------------------------------------------------------------
	Vector GetPixelPosition(MtFootageData* sdkFh, Bool originalRes) const;


	//----------------------------------------------------------------------------------------
	/// Generates a ray in camera space corresponding to the position of the track.
	/// @note If parameters are taken from the reconstructed camera then this generates a camera space ray corresponding to the position of the track.
	/// @param[in] focalLength				The focal length to use for the camera (in mm).
	/// @param[in] sensorWidth				The sensor width to use for the camera (in mm).
	/// @return												The ray in camera space corresponding to the position of the track.
	//----------------------------------------------------------------------------------------
	Vector GetCameraSpaceDirection(Float focalLength, Float sensorWidth) const;

public:
	//----------------------------------------------------------------------------------------
	/// @markInternal
	//----------------------------------------------------------------------------------------
	static MtData* Alloc();

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{MtDatas}
	/// @param[in,out] p							@theToDestruct{MtData}
	//----------------------------------------------------------------------------------------
	static void Free(MtData *&p);
};

//----------------------------------------------------------------------------------------
/// Provides basic information about the footage that has been loaded into the motion tracker.
///
/// Includes frame range, aspect ratio information, source filename, and downsampling settings.
//----------------------------------------------------------------------------------------
class MtFootageData
{
private:
	MtFootageData();
	~MtFootageData();

public:
	//----------------------------------------------------------------------------------------
	/// Retrieves the filename of the footage (the first frame if an image sequence).
	/// @return												The filename.
	//----------------------------------------------------------------------------------------
	Filename GetFootageName() const;

	//----------------------------------------------------------------------------------------
	/// Retrieves the frame number of the first frame in the footage.
	/// @return												The first frame number. @em -1 if no footage loaded.
	//----------------------------------------------------------------------------------------
	Int32 GetFirstFrameNumber() const;

	//----------------------------------------------------------------------------------------
	/// Retrieves the frame number of the last frame in the footage.
	/// @return												The last frame number. @em -1 if no footage loaded.
	//----------------------------------------------------------------------------------------
	Int32 GetLastFrameNumber() const;

	//----------------------------------------------------------------------------------------
	/// Queries the width in pixels of the footage.
	/// @param[in] originalRes				If @formatConstant{true}, the returned pixel coordinates are for the original footage. If @formatConstant{false}, the returned pixel coordinates are for the downsampled footage.
	/// @return												The width of footage in pixels.
	//----------------------------------------------------------------------------------------
	Int32 GetResolutionWidthPix(Bool originalRes) const;

	//----------------------------------------------------------------------------------------
	/// Queries the height in pixels of the footage.
	/// @param[in] originalRes				If @formatConstant{true}, the returned pixel coordinates are for the original footage. If @formatConstant{false}, the returned pixel coordinates are for the downsampled footage.
	/// @return												The height of footage in pixels.
	//----------------------------------------------------------------------------------------
	Int32 GetResolutionHeightPix(Bool originalRes) const;

	//----------------------------------------------------------------------------------------
	/// Queries the aspect ratio of the horizontal to vertical resolution. Ignores pixel aspect ratio.
	/// @return												The aspect ratio from resolution.
	//----------------------------------------------------------------------------------------
	Float GetResolutionAspectRatio() const;

	//----------------------------------------------------------------------------------------
	/// Queries the aspect ratio of the footage including effects of pixel aspect ratio.
	/// @note GetImageAspectRatio() == GetResolutionAspectRatio() * GetPixelAspectRatio()
	/// @return												The aspect ratio of footage.
	//----------------------------------------------------------------------------------------
	Float GetImageAspectRatio() const;

	//----------------------------------------------------------------------------------------
	/// Queries the pixel aspect ratio of the footage.
	/// @return												The pixel aspect ratio.
	//----------------------------------------------------------------------------------------
	Float GetPixelAspectRatio() const;

	//----------------------------------------------------------------------------------------
	/// Queries the downsampling factor used for the footage.
	/// @return												The downsampling factor.
	//----------------------------------------------------------------------------------------
	Float GetDownsamplingFactor() const;

public:
	//----------------------------------------------------------------------------------------
	/// @markInternal
	//----------------------------------------------------------------------------------------
	static MtFootageData* Alloc();

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{MtFootageDatas}
	/// @param[in,out] p							@theToDestruct{MtFootageData}
	//----------------------------------------------------------------------------------------
	static void Free(MtFootageData *&p);
};


//----------------------------------------------------------------------------------------
/// Represents a Motion Tracker object.
///
/// Provides read access to Footage and 2D Tracking information for the object.
/// This allows access to the raw 2D Tracks to be used for user purposes, e.g. to drive custom animation systems.
//----------------------------------------------------------------------------------------
class MotionTrackerObject : public BaseObject
{
private:
	MotionTrackerObject();
	~MotionTrackerObject();

public:
	/// @name Alloc/Free
	/// @{

	//----------------------------------------------------------------------------------------
	/// @allocatesA{motion tracker object}
	/// @return												@allocReturn{motion tracker object}
	//----------------------------------------------------------------------------------------
	static MotionTrackerObject* Alloc();

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{MotionTrackerObjects}
	/// @param[in,out] bl							@theToDestruct{MotionTrackerObject}
	//----------------------------------------------------------------------------------------
	static void Free(MotionTrackerObject*& bl);

	/// @}


	//----------------------------------------------------------------------------------------
	/// Retrieves the full set of 2D tracking data.
	/// @warning Caller is responsible for calling @c Free() on the returned tracking data when it is no longer needed.
	/// @return												A copy of the 2D tracking data, or @formatConstant{nullptr}. @callerOwnsPointed{Mt2dTrackData}
	//----------------------------------------------------------------------------------------
	Mt2dTrackData* Get2dTrackData() const;

	//----------------------------------------------------------------------------------------
	/// Retrieves the footage data.
	/// @warning Caller is responsible for calling @c Free() on the returned footage data when it is no longer needed.
	/// @return												A copy of the footage data, or @formatConstant{nullptr}. @callerOwnsPointed{MtFootageData}
	//----------------------------------------------------------------------------------------
	MtFootageData* GetFootageData() const;
};


/// Motion Tracker library ID.
#define MOTIONTRACKER_SDK_EXTEND_LIB 1037203

/// Mt2dTrackData class library ID.
#define MT_2DTRACKDATACLASSLIB 1037237

/// Mt2dTrack class library ID.
#define MT_2DTRACKCLASSLIB 1037238

/// MtData class library ID.
#define MT_DATACLASSLIB 1037239

/// MtFootageData class library ID.
#define MT_FOOTAGEDATACLASSLIB 1037240

/// MtTrkGid class library ID.
#define MT_TRKGIDCLASSLIB 1037241


class Mt2dTrackDataSdk;
class Mt2dTrackSdk;
class MtDataSdk;
class MtTrkGidSdk;
class MtFootageDataSdk;

/// @}

/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF


struct Sdk2dTrackDataLibrary : public C4DLibrary
{
	Mt2dTrackData*	(*Alloc)();
	void						(*Free)(Mt2dTrackData *&p);

	Int32						(Mt2dTrackDataSdk::*GetTrackCountPtr)() const;
	Mt2dTrack*			(Mt2dTrackDataSdk::*GetTrackByIndexPtr)(Int32 idx) const;
	Mt2dTrack*			(Mt2dTrackDataSdk::*GetTrackByNamePtr)(const String& name) const;
	Mt2dTrack*			(Mt2dTrackDataSdk::*GetTrackByGidPtr)(const MtTrkGid* sdkTrkGid) const;
	BaseSelect*			(Mt2dTrackDataSdk::*GetTrackIndicesPtr)(Bool userTracks, Bool autoTracks) const;
};


struct Sdk2dTrackLibrary : public C4DLibrary
{
	Mt2dTrack*			(*Alloc)();
	void						(*Free)(Mt2dTrack *&p);

	Mt2dTrackStatus	(Mt2dTrackSdk::*GetStatusPtr)() const;
	MtTrkGid*				(Mt2dTrackSdk::*GetIdPtr)() const;
	String					(Mt2dTrackSdk::*GetNamePtr)() const;
	BaseSelect*			(Mt2dTrackSdk::*GetFramesWithTrackDataPtr)() const;
	MtData*					(Mt2dTrackSdk::*GetDataForFramePtr)(Int32 frameNum) const;
	MtData*					(Mt2dTrackSdk::*GetDataForCurrentFramePtr)() const;
};


struct SdkDataLibrary : public C4DLibrary
{
	MtData*					(*Alloc)();
	void						(*Free)(MtData *&p);

	Vector					(MtDataSdk::*GetNormalisedPositionPtr)() const;
	Vector					(MtDataSdk::*GetPixelPositionPtr)(MtFootageData* sdkFh, Bool originalRes) const;
	Vector					(MtDataSdk::*GetCameraSpaceDirectionPtr)(Float focalLength, Float sensorWidth) const;
};


struct SdkTrkGidLibrary : public C4DLibrary
{
	MtTrkGid*					(*Alloc)();
	void(*Free)(MtTrkGid *&p);

	Int32(MtTrkGidSdk::*ToIntPtr)() const;
};


struct SdkFootageDataLibrary : public C4DLibrary
{
	MtFootageData*					(*Alloc)();
	void(*Free)(MtFootageData *&p);

	Filename(MtFootageDataSdk::*GetFootageNamePtr)() const;
	Int32(MtFootageDataSdk::*GetFirstFrameNumberPtr)() const;
	Int32(MtFootageDataSdk::*GetLastFrameNumberPtr)() const;
	Int32(MtFootageDataSdk::*GetResolutionWidthPixPtr)(Bool originalRes) const;
	Int32(MtFootageDataSdk::*GetResolutionHeightPixPtr)(Bool originalRes) const;
	Float(MtFootageDataSdk::*GetResolutionAspectRatioPtr)() const;
	Float(MtFootageDataSdk::*GetImageAspectRatioPtr)() const;
	Float(MtFootageDataSdk::*GetPixelAspectRatioPtr)() const;
	Float(MtFootageDataSdk::*GetDownsamplingFactorPtr)() const;
};


struct SdkMotionTrackerObjectLibrary : public C4DLibrary
{
	Mt2dTrackData* (*Get2dTrackDataPtr)(BaseObject* op);
	MtFootageData* (*GetFootageDataPtr)(BaseObject* op);
};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

#endif // LIB_MOTIONTRACKER_H__

/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef C4D_VIDEOPOSTPLUGIN_H__
#define C4D_VIDEOPOSTPLUGIN_H__

#include "ge_math.h"
#include "c4d_basetime.h"
#include "c4d_videopostdata.h"
#include "c4d_nodeplugin.h"

class GlFrameBuffer;

/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

struct VIDEOPOSTPLUGIN : public NODEPLUGIN
{
	Int32 priority;

	Bool					(VideoPostData::*Draw													)(BaseVideoPost *node, BaseDraw *bd, BaseDrawHelp *bh);
	void					(VideoPostData::*AllocateBuffers							)(BaseVideoPost *node, Render *render, BaseDocument *doc);
	VIDEOPOSTINFO	(VideoPostData::*GetRenderInfo								)(BaseVideoPost *node);

	RENDERRESULT	(VideoPostData::*Execute											)(BaseVideoPost *node, VideoPostStruct *vps);
	void					(VideoPostData::*ExecuteLine									)(BaseVideoPost *node, PixelPost *pp);
	void					(VideoPostData::*ExecutePixel									)(BaseVideoPost *node, PixelPost *pp, Int32 x, Int32 subx, Int32 suby);

	void					(VideoPostData::*CalcVolumetric								)(BaseVideoPost *node, VolumeData *vd);
	void					(VideoPostData::*CalcShadow										)(BaseVideoPost *node, VolumeData *vd);
	Bool					(VideoPostData::*GlDraw												)(BaseVideoPost *node, BaseDraw *bd, GlFrameBuffer* fbuf, Int32 colortex, Int32 depthtex, VIDEOPOST_GLDRAW flags);

	Vector				(VideoPostData::*ComputeDiffuseGI							)(BaseVideoPost *node, VolumeData *vd, Float receive_strength);
	Vector				(VideoPostData::*ComputeDiffuseCaustic				)(BaseVideoPost *node, VolumeData *vd, Float sampleradius, Int32 accuracy);

	void					(VideoPostData::*CreateRay										)(Ray *dst, Float x, Float y);
	VIDEOPOST_GLINFO	(VideoPostData::*GetGlInfo								)(BaseVideoPost *node, BaseDocument* doc, BaseDraw *bd);
	Int32					(VideoPostData::*StereoGetCameraCountEditor		)(BaseVideoPost *node, BaseDocument* doc, BaseDraw *bd);
	Bool					(VideoPostData::*StereoGetCameraInfo					)(BaseVideoPost *node, BaseDocument* doc, BaseDraw *bd, RenderData* rd, Int32 index, StereoCameraInfo& info);
	Int32					(VideoPostData::*StereoGetSceneHookID					)(BaseVideoPost *node);
	Bool					(VideoPostData::*StereoMergeImages						)(BaseVideoPost *node, BaseBitmap* dest, const BaseBitmap* const* source, Int32 cnt, const BaseContainer &settings, COLORSPACETRANSFORMATION transform);
	Int32					(VideoPostData::*StereoGetCameraCountRenderer	)(BaseVideoPost *node, BaseDocument* doc, RenderData* rd);

	Bool					(VideoPostData::*RenderEngineCheck						)(BaseVideoPost *node, Int32 id);

	Vector				(VideoPostData::*ComputeVolumeCaustic					)(BaseVideoPost *node, const Vector64 &p, Int32 cpu_index);

	void					(VideoPostData::*SetDiffuseWeight							)(BaseVideoPost *node, Int32 cpu_index, Float weight);

	void					(VideoPostData::*CreateExtendedRay						)(Ray *dst, Float x, Float y, Float lensx, Float lensy, Float time);

	Bool					(VideoPostData::*NetFrameInit									)(BaseVideoPost *node, BaseDocument* doc, RenderJob* job, Int32 assignedClients, const NetRenderData* renderData, MultipassBitmap* frameBmp, BaseThread* bt, Int32& realdepth);
	void					(VideoPostData::*NetFrameFree									)(BaseVideoPost *node);
	Bool					(VideoPostData::*NetFrameMessage							)(BaseVideoPost *node, const C4DUuid& remoteUuid, const NetRenderBuffer& data, NetRenderBuffer *result);

	Bool					(VideoPostData::*NetCreateBuffer							)(BaseVideoPost *node, VideoPostStruct *vps, Int32 x, Int32 y, Int32 sizex, Int32 sizey, Int32 &id, Int32 &subid);

	Bool					(VideoPostData::*GetMotionInfo								)(BaseVideoPost *node, MotionInfo& info);

	void*	reserved[(32-27)*C4DPL_MEMBERMULTIPLIER-1];
};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

#endif // C4D_VIDEOPOSTPLUGIN_H__

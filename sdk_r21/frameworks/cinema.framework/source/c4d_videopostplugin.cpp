#ifdef __API_INTERN__
	#include "operatingsystem.h"
#endif
#include "c4d_videopost.h"
#include "c4d_general.h"
#include "c4d_resource.h"

Bool VideoPostData::Draw(BaseVideoPost* node, BaseDraw* bd, BaseDrawHelp* bh)
{
	return true;
}

void VideoPostData::CalcVolumetric(BaseVideoPost* node, VolumeData* vd)
{
}

void VideoPostData::CalcShadow(BaseVideoPost* node, VolumeData* vd)
{
}

void VideoPostData::AllocateBuffers(BaseVideoPost* node, Render* render, BaseDocument* doc)
{
}

VIDEOPOSTINFO VideoPostData::GetRenderInfo(BaseVideoPost* node)
{
	return VIDEOPOSTINFO::NONE;
}

RENDERRESULT VideoPostData::Execute(BaseVideoPost* node, VideoPostStruct* vps)
{
	return RENDERRESULT::OK;
}

void VideoPostData::ExecuteLine(BaseVideoPost* node, PixelPost* pp)
{
}

void VideoPostData::ExecutePixel(BaseVideoPost* node, PixelPost* pp, Int32 x, Int32 subx, Int32 suby)
{
}

Bool VideoPostData::GlDraw(BaseVideoPost* node, BaseDraw* bd, GlFrameBuffer* fbuf, Int32 colortex, Int32 depthtex, VIDEOPOST_GLDRAW flags)
{
	return true;
}

VIDEOPOST_GLINFO VideoPostData::GetGlInfo(BaseVideoPost* node, BaseDocument* doc, BaseDraw* bd)
{
	return VIDEOPOST_GLINFO::NONE;
}

void VideoPostData::SetDiffuseWeight(BaseVideoPost* node, Int32 cpu_index, Float weight)
{
}

Vector VideoPostData::ComputeDiffuseGI(BaseVideoPost* node, VolumeData* vd, Float receive_strength)
{
	return Vector(0.0);
}

Vector VideoPostData::ComputeDiffuseCaustic(BaseVideoPost* node, VolumeData* vd, Float sampleradius, Int32 accuracy)
{
	return Vector(0.0);
}

Vector VideoPostData::ComputeVolumeCaustic(BaseVideoPost* node, const Vector64& p, Int32 cpu_index)
{
	return Vector(0.0);
}

void VideoPostData::CreateRay(Ray* dst, Float x, Float y)
{
}

void VideoPostData::CreateExtendedRay(Ray* dst, Float x, Float y, Float lensx, Float lensy, Float time)
{
}

Int32 VideoPostData::StereoGetCameraCountEditor(BaseVideoPost* node, BaseDocument* doc, BaseDraw* bd)
{
	return NOTOK;
}

Int32 VideoPostData::StereoGetCameraCountRenderer(BaseVideoPost* node, BaseDocument* doc, RenderData* rd)
{
	return NOTOK;
}

Bool VideoPostData::StereoGetCameraInfo(BaseVideoPost* node, BaseDocument* doc, BaseDraw* bd, RenderData* rd, Int32 index, StereoCameraInfo& info)
{
	return false;
}

Int32 VideoPostData::StereoGetSceneHookID(BaseVideoPost* node)
{
	return 0;
}

Bool VideoPostData::StereoMergeImages(BaseVideoPost* node, BaseBitmap* dest, const BaseBitmap* const* source, Int32 cnt, const BaseContainer& settings, COLORSPACETRANSFORMATION transform)
{
	return false;
}

Bool VideoPostData::RenderEngineCheck(BaseVideoPost* node, Int32 id)
{
	return true;
}

Bool VideoPostData::NetFrameInit(BaseVideoPost* node, BaseDocument* doc, RenderJob* job, Int32 assignedClients, const NetRenderData* renderData, MultipassBitmap* frameBmp, BaseThread* bt, Int32& realdepth)
{
	return false;
}

void VideoPostData::NetFrameFree(BaseVideoPost* node)
{
}

Bool VideoPostData::NetFrameMessage(BaseVideoPost* node, const C4DUuid& remoteUuid, const NetRenderBuffer& data, NetRenderBuffer* result)
{
	return false;
}

Bool VideoPostData::NetCreateBuffer(BaseVideoPost* node, VideoPostStruct* vps, Int32 x, Int32 y, Int32 sizex, Int32 sizey, Int32& id, Int32& subid)
{
	return false;
}

Bool VideoPostData::GetMotionInfo(BaseVideoPost* node, MotionInfo& info)
{
	return false;
}

Bool RegisterVideoPostPlugin(Int32 id, const maxon::String& str, Int32 info, DataAllocator* g, const maxon::String& description, Int32 disklevel, Int32 priority)
{
	if (description.IsPopulated() && !RegisterDescription(id, description))
		return false;

	VIDEOPOSTPLUGIN np;
	ClearMem(&np, sizeof(np));

	FillNodePlugin(&np, info, g, nullptr, disklevel);

	np.priority	= priority;
	np.Draw	= &VideoPostData::Draw;
	np.GlDraw	= &VideoPostData::GlDraw;
	np.GetGlInfo = &VideoPostData::GetGlInfo;
	np.AllocateBuffers = &VideoPostData::AllocateBuffers;
	np.GetRenderInfo = &VideoPostData::GetRenderInfo;
	np.Execute = &VideoPostData::Execute;
	np.ExecuteLine	= &VideoPostData::ExecuteLine;
	np.ExecutePixel	= &VideoPostData::ExecutePixel;
	np.CalcVolumetric = &VideoPostData::CalcVolumetric;
	np.CalcShadow = &VideoPostData::CalcShadow;
	np.ComputeDiffuseGI = &VideoPostData::ComputeDiffuseGI;
	np.ComputeDiffuseCaustic	= &VideoPostData::ComputeDiffuseCaustic;
	np.ComputeVolumeCaustic = &VideoPostData::ComputeVolumeCaustic;
	np.CreateRay = &VideoPostData::CreateRay;
	np.CreateExtendedRay = &VideoPostData::CreateExtendedRay;
	np.StereoGetCameraCountEditor = &VideoPostData::StereoGetCameraCountEditor;
	np.StereoGetCameraCountRenderer = &VideoPostData::StereoGetCameraCountRenderer;
	np.StereoGetCameraInfo	= &VideoPostData::StereoGetCameraInfo;
	np.StereoGetSceneHookID = &VideoPostData::StereoGetSceneHookID;
	np.StereoMergeImages = &VideoPostData::StereoMergeImages;
	np.RenderEngineCheck = &VideoPostData::RenderEngineCheck;
	np.SetDiffuseWeight	 = &VideoPostData::SetDiffuseWeight;
	np.NetFrameInit	= &VideoPostData::NetFrameInit;
	np.NetFrameFree	= &VideoPostData::NetFrameFree;
	np.NetFrameMessage = &VideoPostData::NetFrameMessage;
	np.NetCreateBuffer = &VideoPostData::NetCreateBuffer;
	np.GetMotionInfo = &VideoPostData::GetMotionInfo;

	return GeRegisterPlugin(PLUGINTYPE::VIDEOPOST, id, str, &np, sizeof(np));
}

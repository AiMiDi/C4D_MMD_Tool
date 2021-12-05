#ifdef __API_INTERN__
	#error "Not in kernel"
#endif

#include "c4d_memory.h"
#include "c4d_videopost.h"

BaseVideoPost* BaseVideoPost::Alloc(Int32 type)
{
	return C4DOS.Bd->VpAlloc(type);
}

void BaseVideoPost::Free(BaseVideoPost*& bl)
{
	C4DOS.Bl->Free(bl);
	bl = nullptr;
}

Bool BaseVideoPost::RenderEngineCheck(Int32 id)
{
	return C4DOS.Bd->VpRenderEngineCheck(this, id);
}

Bool BaseVideoPost::StereoMergeImages(BaseBitmap* dest, const BaseBitmap* const* source, Int32 cnt, const BaseContainer& settings, COLORSPACETRANSFORMATION transform)
{
	return C4DOS.Bd->VpStereoMergeImages(this, dest, source, cnt, settings, transform);
}

Int32 BaseVideoPost::StereoGetCameraCountEditor(BaseDocument* doc, BaseDraw* bd)
{
	return C4DOS.Bd->VpStereoGetCameraCountEditor(this, doc, bd);
}

Int32 BaseVideoPost::StereoGetCameraCountRenderer(BaseDocument* doc, RenderData* rd)
{
	return C4DOS.Bd->VpStereoGetCameraCountRenderer(this, doc, rd);
}

Bool BaseVideoPost::StereoGetCameraInfo(BaseDocument* doc, BaseDraw* bd, RenderData* rd, Int32 index, StereoCameraInfo& info)
{
	return C4DOS.Bd->VpStereoGetCameraInfo(this, doc, bd, rd, index, info);
}

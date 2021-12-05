#include "c4d_basedraw.h"
#include "lib_description.h"



BaseDrawHelp* BaseDrawHelp::Alloc(BaseDraw* bd, BaseDocument* doc)
{
	return C4DOS.Br->BbAlloc(bd, doc);
}

void BaseDrawHelp::Free(BaseDrawHelp*& p)
{
	if (!p)
		return;
	C4DOS.Br->BbFree(p);
}

void BaseView::GetFrame(Int32* cl, Int32* ct, Int32* cr, Int32* cb)
{
	C4DOS.Bv->GetFrame(this, cl, ct, cr, cb);
}

void BaseView::GetSafeFrame(Int32* cl, Int32* ct, Int32* cr, Int32* cb)
{
	C4DOS.Bv->GetSafeFrame(this, cl, ct, cr, cb);
}

void BaseView::GetViewParameter(Vector* offset, Vector* scale, Vector* scale_z) const
{
	C4DOS.Bv->GetParameter(this, offset, scale, scale_z);
}

Bool BaseView::TestClipping3D(const Vector& mp, const Vector& rad, const Matrix& mg, Bool* clip2d, Bool* clipz)
{
	return C4DOS.Bv->TestClipping3D(this, mp, rad, mg, clip2d, clipz);
}


Int32 BaseDraw::GetFrameScreen(Int32* cl, Int32* ct, Int32* cr, Int32* cb)
{
	return C4DOS.Bv->GetFrameScreen(this, cl, ct, cr, cb);
}

const Matrix4d& BaseDraw::GetViewMatrix(Int32 n)
{
	return C4DOS.Bv->GetViewMatrix(this, n);
}

ViewportSelect* ViewportSelect::Alloc()
{
	return C4DOS.Bv->VSAlloc();
}

void ViewportSelect::Free(ViewportSelect*& p)
{
	if (!p)
		return;
	C4DOS.Bv->VSFree(p);
}

Bool ViewportSelect::Init(Int32 w, Int32 h, BaseDraw* bd, BaseObject* op, Int32 mode, Bool onlyvisible, VIEWPORTSELECTFLAGS flags)
{
	return C4DOS.Bv->VSInitObj(this, w, h, bd, op, mode, onlyvisible, flags);
}

Bool ViewportSelect::Init(Int32 w, Int32 h, BaseDraw* bd, AtomArray* ar, Int32 mode, Bool onlyvisible, VIEWPORTSELECTFLAGS flags)
{
	return C4DOS.Bv->VSInitAr(this, w, h, bd, ar, mode, onlyvisible, flags);
}

const ViewportPixel* ViewportSelect::GetPixelInfoPoint(Int32 x, Int32 y) const
{
	return C4DOS.Bv->VSGetPixelInfoPoint(this, x, y);
}

const ViewportPixel* ViewportSelect::GetPixelInfoPolygon(Int32 x, Int32 y) const
{
	return C4DOS.Bv->VSGetPixelInfoPolygon(this, x, y);
}

const ViewportPixel* ViewportSelect::GetPixelInfoEdge(Int32 x, Int32 y) const
{
	return C4DOS.Bv->VSGetPixelInfoEdge(this, x, y);
}

Bool ViewportSelect::GetPointPixelBuffer(const ViewportPixel *const*&pixelBuffer, Int32 *pixelCount) const
{
	return C4DOS.Bv->VSGetPointPixelBuffer(this, pixelBuffer, pixelCount);
}

Bool ViewportSelect::GetEdgePixelBuffer(const ViewportPixel *const*&pixelBuffer, Int32 *pixelCount) const
{
	return C4DOS.Bv->VSGetEdgePixelBuffer(this, pixelBuffer, pixelCount);
}

Bool ViewportSelect::GetPolygonPixelBuffer(const ViewportPixel *const*&pixelBuffer, Int32 *pixelCount) const
{
	return C4DOS.Bv->VSGetPolygonPixelBuffer(this, pixelBuffer, pixelCount);
}

Int32 ViewportSelect::GetPixelCount() const
{
	return C4DOS.Bv->VSGetPixelCount(this);
}

void ViewportSelect::ShowHotspot(EditorWindow* bw, Int32 x, Int32 y)
{
	C4DOS.Bv->VSShowHotspot(this, bw, x, y);
}

void ViewportSelect::ShowHotspot(EditorWindow* bw, Int32 x, Int32 y, Int32 rad, Bool bRemove)
{
	C4DOS.Bv->VSShowHotspotS(bw, x, y, rad, bRemove);
}

void ViewportSelect::SetBrushRadius(Int32 r)
{
	C4DOS.Bv->VSSetBrushRadius(this, r);
}

const ViewportPixel* ViewportSelect::GetNearestPoint(BaseObject* op, Int32& x, Int32& y, Int32 maxrad, Bool onlyselected, Int32* ignorelist, Int32 ignorecnt) const
{
	return C4DOS.Bv->VSGetNearestPoint(this, op, x, y, maxrad, onlyselected, ignorelist, ignorecnt);
}

const ViewportPixel* ViewportSelect::GetNearestPolygon(BaseObject* op, Int32& x, Int32& y, Int32 maxrad, Bool onlyselected, Int32* ignorelist, Int32 ignorecnt) const
{
	return C4DOS.Bv->VSGetNearestPolygon(this, op, x, y, maxrad, onlyselected, ignorelist, ignorecnt);
}

const ViewportPixel* ViewportSelect::GetNearestEdge(BaseObject* op, Int32& x, Int32& y, Int32 maxrad, Bool onlyselected, Int32* ignorelist, Int32 ignorecnt) const
{
	return C4DOS.Bv->VSGetNearestEdge(this, op, x, y, maxrad, onlyselected, ignorelist, ignorecnt);
}

void ViewportSelect::ClearPixelInfo(Int32 x, Int32 y, UChar mask)
{
	C4DOS.Bv->VSClearPixelInfo(this, x, y, mask);
}

Bool ViewportSelect::GetCameraCoordinates(Float x, Float y, Float z, Vector& v) const
{
	return C4DOS.Bv->VSGetCameraCoordinates(this, x, y, z, v);
}

Bool ViewportSelect::DrawPolygon(const Vector* p, Int32 ptcnt, Int32 i, BaseObject* op, Int32 onlyvisible)
{
	return C4DOS.Bv->VSDrawPolygon(this, p, ptcnt, i, op, onlyvisible);
}

Bool ViewportSelect::DrawHandle(const Vector& p, Int32 i, BaseObject* op, Int32 onlyvisible)
{
	return C4DOS.Bv->VSDrawHandle(this, p, i, op, onlyvisible);
}

Bool ViewportSelect::PickObject(BaseDraw* bd, BaseDocument* doc, Int32 x, Int32 y, Int32 rad, VIEWPORT_PICK_FLAGS flags, LassoSelection* ls, C4DObjectList* list, Matrix4d* m)
{
	return C4DOS.Bv->VSPickObject(bd, doc, x, y, rad, flags, ls, list, m);
}

Bool ViewportSelect::PickObject(BaseDraw* bd, BaseDocument* doc, Int32 x, Int32 y, Int32 rad, Int32& xr, Int32& yr, Int32& wr, Int32& hr, const ViewportPixel*const*& pixels, VIEWPORT_PICK_FLAGS flags, LassoSelection* ls, C4DObjectList* list, Matrix4d* m)
{
	return C4DOS.Bv->VSPickObject1(bd, doc, x, y, rad, xr, yr, wr, hr, pixels, flags, ls, list, m);
}

Bool ViewportSelect::PickObject(BaseDraw* bd, BaseDocument* doc, Int32 x1, Int32 y1, Int32 x2, Int32 y2, Int32& xr, Int32& yr, Int32& wr, Int32& hr, const ViewportPixel*const*& pixels, VIEWPORT_PICK_FLAGS flags, LassoSelection* ls, C4DObjectList* list, Matrix4d* m)
{
	return C4DOS.Bv->VSPickObject2(bd, doc, x1, y1, x2, y2, xr, yr, wr, hr, pixels, flags, ls, list, m);
}

GeData BaseDraw::GetParameterData(Int32 id)
{
	GeData t_data;
	BaseList2D::GetParameter(DescLevel(id), t_data, DESCFLAGS_GET::NONE);
	return t_data;
}

Float BaseView::PW_S(Float z, Bool horizontal)
{
	return C4DOS.Bv->PW_S(this, z, horizontal);
}

Float BaseView::WP_S(Float z, Bool horizontal)
{
	return C4DOS.Bv->WP_S(this, z, horizontal);
}

Float BaseView::PW_W(const Vector& p, Bool horizontal)
{
	return C4DOS.Bv->PW_W(this, p, horizontal);
}

Float BaseView::WP_W(const Vector& p, Bool horizontal)
{
	return C4DOS.Bv->WP_W(this, p, horizontal);
}

Vector BaseView::ProjectPointOnLine(const Vector& p, const Vector& v, Float mouse_x, Float mouse_y, Float* offset, Int32* err)
{
	return C4DOS.Bv->ProjectPointOnLine(this, p, v, mouse_x, mouse_y, offset, err);
}

Vector BaseView::ProjectPointOnPlane(const Vector& p, const Vector& v, Float mouse_x, Float mouse_y, Int32* err)
{
	return C4DOS.Bv->ProjectPointOnPlane(this, p, v, mouse_x, mouse_y, err);
}

void DrawTools(const AtomArray *activeobjects, const AtomArray *activetags, BaseDocument *doc, BaseDraw *bd, BaseThread *bt, TOOLDRAW drawflags, Bool inversez)
{
	return C4DOS.Br->DrawTools(activeobjects, activetags, doc, bd, bt, drawflags, inversez);
}


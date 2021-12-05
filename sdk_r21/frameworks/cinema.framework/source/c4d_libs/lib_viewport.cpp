#include "lib_viewport.h"

//////////////////////////////////////////////////////////////////////////

ViewportHUDLib *lib_viewhud = nullptr;
ViewportHighlightLib *lib_viewhlight = nullptr;
ViewportHUDControlLib *lib_viewhudctrl = nullptr;

static ViewportHUDLib *CheckViewportHUDLib(Int32 offset) { return (ViewportHUDLib*)CheckLib(LIBRARY_HUD, offset, (C4DLibrary**)&lib_viewhud); }
static ViewportHighlightLib *CheckViewportHighlightLib(Int32 offset) { return (ViewportHighlightLib*)CheckLib(LIBRARY_HIGHLIGHT, offset, (C4DLibrary**)&lib_viewhlight); }

static ViewportHUDControlLib *CheckViewportHUDControlLib(Int32 offset)
{
	return (ViewportHUDControlLib*)CheckLib(LIBRARY_HUD_CONTROL, offset, (C4DLibrary**)&lib_viewhudctrl);
}

#define ViewportHUDLibCall(b) 		ViewportHUDLib *lib = CheckViewportHUDLib(LIBOFFSET(ViewportHUDLib, b)); \
															if (!lib || !lib->b) return; \
															(((iViewportHUD*)this)->*lib->b)

#define ViewportHUDLibCallR(a, b)  ViewportHUDLib *lib = CheckViewportHUDLib(LIBOFFSET(ViewportHUDLib, b)); \
															if (!lib || !lib->b) return a; \
															return (((iViewportHUD*)this)->*lib->b)

#define ViewportHighlightLibCall(b) 		ViewportHighlightLib *lib = CheckViewportHighlightLib(LIBOFFSET(ViewportHighlightLib, b)); \
															if (!lib || !lib->b) return; \
															(((iViewportHighlight*)this)->*lib->b)

#define ViewportHighlightLibCallR(a, b)  ViewportHighlightLib *lib = CheckViewportHighlightLib(LIBOFFSET(ViewportHighlightLib, b)); \
															if (!lib || !lib->b) return a; \
															return (((iViewportHighlight*)this)->*lib->b)

#define ViewportHUDControlLibCall(b)  ViewportHUDControlLib *lib = CheckViewportHUDControlLib(LIBOFFSET(ViewportHUDControlLib, b)); \
															if (!lib || !lib->b) return; \
															(lib->b)

#define ViewportHUDControlLibCallR(a, b)  ViewportHUDControlLib *lib = CheckViewportHUDControlLib(LIBOFFSET(ViewportHUDControlLib, b)); \
															if (!lib || !lib->b) return a; \
															return (lib->b)

//////////////////////////////////////////////////////////////////////////

ViewportHUD* ViewportHUD::Alloc()
{
	ViewportHUDLib *lib = CheckViewportHUDLib(LIBOFFSET(ViewportHUDLib, Alloc)); if (!lib) return nullptr;
	return (ViewportHUD*)lib->Alloc();
}

void ViewportHUD::Free(ViewportHUD *&p)
{
	if (!p) return;
	ViewportHUDLib *lib = CheckViewportHUDLib(LIBOFFSET(ViewportHUDLib, Free)); if (!lib) return;
	iViewportHUD* i = (iViewportHUD*)p;
	lib->Free(i);
	p = nullptr;
}

//////////////////////////////////////////////////////////////////////////

ViewportHUDControl *ViewportHUD::AddDescID(BaseDocument *doc, BaseList2D *obj, const DescID &id, const BaseContainer &data)
{
	ViewportHUDLibCallR(nullptr, AddDescID)(doc, obj, id, data);
}

Bool ViewportHUD::BeginGroup()
{
	ViewportHUDLibCallR(false, BeginGroup)();
}

ViewportHUDControl *ViewportHUD::EndGroup()
{
	ViewportHUDLibCallR(nullptr, EndGroup)();
}

Bool ViewportHUD::SetElement(BaseDocument *doc, Int32 id, Bool state)
{
	ViewportHUDLibCallR(false, SetElement)(doc, id, state);
}

Bool ViewportHUD::IsValidControl(BaseDocument *doc, BaseList2D *obj, const DescID &id, const BaseContainer &data)
{
	ViewportHUDLibCallR(false, IsValidControl)(doc, obj, id, data);
}

Bool ViewportHUD::DrawHUD(BaseDocument *doc, GeClipMap *clipmap, Int32 fps, BaseDraw *bd, Int32 flags)
{
	ViewportHUDLibCallR(false, DrawHUD)(doc, clipmap, fps, bd, flags);
}

ViewportHUDControl *ViewportHUD::AddControl(Int32 type, BaseDocument *doc, BaseDraw *bd, BaseList2D *obj, const DescID &id, const BaseContainer &data, const GeData &t_data, Int32 datatype)
{
	ViewportHUDLibCallR(nullptr, AddControl)(type, doc, bd, obj, id, data, t_data, datatype);
}

ViewportHUDControl *ViewportHUD::FindControl(BaseDocument *doc, BaseDraw *bd, BaseList2D *bl, const DescID &id)
{
	ViewportHUDLibCallR(nullptr, FindControl)(doc, bd, bl, id);
}

VIEWHUD_FLAG ViewportHUD::SetFlags(BaseDocument *doc, VIEWHUD_FLAG flags)
{
	ViewportHUDLibCallR(VIEWHUD_FLAG::NONE, SetFlags)(doc, flags);
}

VIEWHUD_FLAG ViewportHUD::GetFlags(BaseDocument *doc)
{
	ViewportHUDLibCallR(VIEWHUD_FLAG::NONE, GetFlags)(doc);
}

void ViewportHUD::ValidateControls(BaseDocument *doc)
{
	ViewportHUDLibCall(ValidateControls)(doc);
}

void ViewportHUD::UpdateControls(BaseDocument *doc)
{
	ViewportHUDLibCall(UpdateControls)(doc);
}

void ViewportHUD::UpdateData(BaseDocument *doc, BaseList2D *bl)
{
	ViewportHUDLibCall(UpdateData)(doc, bl);
}

//////////////////////////////////////////////////////////////////////////

void ViewportHUDControl::SetLabel(const String &label) { ViewportHUDControlLibCall(SetLabel)(this, label); }
String ViewportHUDControl::GetLabel() { ViewportHUDControlLibCallR(String(), GetLabel)(this); }
void ViewportHUDControl::RemoveFlag(Int32 flag) { ViewportHUDControlLibCall(RemoveFlag)(this, flag); }
void ViewportHUDControl::SetFlag(Int32 flag) { ViewportHUDControlLibCall(SetFlag)(this, flag); }
Int32 ViewportHUDControl::GetFlags() { ViewportHUDControlLibCallR(0, GetFlags)(this); }
void ViewportHUDControl::SetFlags(Int32 flag) { ViewportHUDControlLibCall(SetFlags)(this, flag); }
Int32 ViewportHUDControl::GetType() { ViewportHUDControlLibCallR(0, GetType)(this); }
Float ViewportHUDControl::GetLeft() { ViewportHUDControlLibCallR(0, GetLeft)(this); }
Float ViewportHUDControl::GetTop() { ViewportHUDControlLibCallR(0, GetTop)(this); }
String ViewportHUDControl::GetNameLabel() { ViewportHUDControlLibCallR(String(), GetNameLabel)(this); }
Int32 ViewportHUDControl::GetWidth() { ViewportHUDControlLibCallR(0, GetWidth)(this); }
Int32 ViewportHUDControl::GetHeight() { ViewportHUDControlLibCallR(0, GetHeight)(this); }
IconData *ViewportHUDControl::GetIconData() { ViewportHUDControlLibCallR(nullptr, GetIconData)(this); }
void ViewportHUDControl::SetActionID(Int32 id) { ViewportHUDControlLibCall(SetActionID)(this, id); }
void ViewportHUDControl::SetAction(const String &str) { ViewportHUDControlLibCall(SetAction)(this, str); }
void ViewportHUDControl::SetTopLeft(Float left, Float top) { ViewportHUDControlLibCall(SetTopLeft)(this, left, top); }
void ViewportHUDControl::SetActiveMode(Int32 mode) { ViewportHUDControlLibCall(SetActiveMode)(this, mode); }
void ViewportHUDControl::SetDisplayFlags(Int32 flags) { ViewportHUDControlLibCall(SetDisplayFlags)(this, flags); }
Int32 ViewportHUDControl::GetDisplayFlags() { ViewportHUDControlLibCallR(0, GetDisplayFlags)(this); }
void ViewportHUDControl::RemoveDisplayFlags(Int32 flags) { ViewportHUDControlLibCall(RemoveDisplayFlags)(this, flags); }
void ViewportHUDControl::SetObjectPos(Int32 left, Int32 top) { ViewportHUDControlLibCall(SetObjectPos)(this, left, top); }
void ViewportHUDControl::SetUnits(Int32 units) { ViewportHUDControlLibCall(SetUnits)(this, units); }
void ViewportHUDControl::SetName(const String &name) { ViewportHUDControlLibCall(SetName)(this, name); }
String ViewportHUDControl::GetName() { ViewportHUDControlLibCallR(String(), GetName)(this); }
void ViewportHUDControl::SetControlID(Int32 id) { ViewportHUDControlLibCall(SetControlID)(this, id); }
Int32 ViewportHUDControl::GetControlID() { ViewportHUDControlLibCallR(NOTOK, GetControlID)(this); }
Int32 ViewportHUDControl::GetControlCloneID() { ViewportHUDControlLibCallR(NOTOK, GetControlCloneID)(this); }
Int32 ViewportHUDControl::GetGroupID() { ViewportHUDControlLibCallR(NOTOK, GetGroupID)(this); }
void ViewportHUDControl::SetGroupID(Int32 id) { ViewportHUDControlLibCall(SetGroupID)(this, id); }
void ViewportHUDControl::SetIconFile(BaseDocument *doc, const Filename &fname) { ViewportHUDControlLibCall(SetIconFile)(this, doc, fname); }
Int32 ViewportHUDControl::GetActiveMode() { ViewportHUDControlLibCallR(0, GetActiveMode)(this); }
Int32 ViewportHUDControl::GetActiveParamFlags() { ViewportHUDControlLibCallR(0, GetActiveParamFlags)(this); }
void ViewportHUDControl::SetActiveParamFlags(Int32 flags) { ViewportHUDControlLibCall(SetActiveParamFlags)(this, flags); }
void ViewportHUDControl::SetActiveParam(BaseDocument *doc, const String &param) { ViewportHUDControlLibCall(SetActiveParam)(this, doc, param); }
String ViewportHUDControl::GetActiveParam() { ViewportHUDControlLibCallR(String(), GetActiveParam)(this); }

//////////////////////////////////////////////////////////////////////////

ViewportHighlight* ViewportHighlight::Alloc()
{
	ViewportHighlightLib *lib = CheckViewportHighlightLib(LIBOFFSET(ViewportHighlightLib, Alloc)); if (!lib) return nullptr;
	return (ViewportHighlight*)lib->Alloc();
}

void ViewportHighlight::Free(ViewportHighlight *&p)
{
	if (!p) return;
	ViewportHighlightLib *lib = CheckViewportHighlightLib(LIBOFFSET(ViewportHighlightLib, Free)); if (!lib) return;
	iViewportHighlight* i = (iViewportHighlight*)p;
	lib->Free(i);
	p = nullptr;
}

//////////////////////////////////////////////////////////////////////////

Bool ViewportHighlight::Update(BaseDocument *pDoc, BaseDraw *pDraw, Int32 x, Int32 y, Int32 max_radius)
{
	ViewportHighlightLibCallR(false, Update)(pDoc, pDraw, x, y, max_radius);
}

Bool ViewportHighlight::Draw(BaseDocument *pDoc, BaseDraw *pDraw)
{
	ViewportHighlightLibCallR(false, Draw)(pDoc, pDraw);
}

Bool ViewportHighlight::Changed(BaseDocument *pDoc)
{
	ViewportHighlightLibCallR(false, Changed)(pDoc);
}

void ViewportHighlight::ResetChanged(BaseDocument *pDoc)
{
	ViewportHighlightLibCall(ResetChanged)(pDoc);
}

Bool ViewportHighlight::HasHit(BaseDocument *pDoc)
{
	ViewportHighlightLibCallR(false, HasHit)(pDoc);
}

void ViewportHighlight::GetHit(BaseDocument *pDoc, HighlightHitData *hitdata)
{
	ViewportHighlightLibCall(GetHit)(pDoc, hitdata);
}

void ViewportHighlight::SetMode(BaseDocument *pDoc, Int32 mode)
{
	ViewportHighlightLibCall(SetMode)(pDoc, mode);
}

void ViewportHighlight::SetColor(BaseDocument *pDoc, Vector hcol)
{
	ViewportHighlightLibCall(SetColor)(pDoc, hcol);
}

void ViewportHighlight::SetFlags(BaseDocument *pDoc, Int32 flags)
{
	ViewportHighlightLibCall(SetFlags)(pDoc, flags);
}

ViewportSelect *ViewportHighlight::GetViewportSelect(BaseDocument *pDoc, BaseDraw *pDraw)
{
	ViewportHighlightLibCallR(nullptr, GetViewportSelect)(pDoc, pDraw);
}

AtomArray *ViewportHighlight::GetObjects(BaseDocument *pDoc)
{
	ViewportHighlightLibCallR(nullptr, GetObjects)(pDoc);
}

Int32 ViewportHighlight::GetFlags(BaseDocument *pDoc)
{
	ViewportHighlightLibCallR(0, GetFlags)(pDoc);
}

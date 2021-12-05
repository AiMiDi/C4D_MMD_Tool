#include "lib_paint.h"

#define PaintLibCall(a, b, c)	PaintLibrary *lib = CheckPaintLib(LIBOFFSET(PaintLibrary, b)); \
	if (!lib || !lib->b) return a; \
	return (((c)this)->*(lib->b))

#define PaintLibMethodCall(b) 		PaintLibrary *lib = CheckPaintLib(LIBOFFSET(PaintLibrary, b)); \
	if (!lib || !lib->b) return; \
	(lib->b)

#define PaintLibMethodCallR(a, b)  PaintLibrary *lib = CheckPaintLib(LIBOFFSET(PaintLibrary, b)); \
	if (!lib || !lib->b) return a; \
	return (lib->b)

PaintLibrary *lib_paint = nullptr;

static PaintLibrary *CheckPaintLib(Int32 offset)
{
	return (PaintLibrary*)CheckLib(C4D_PAINT_LIBRARY_ID, offset, (C4DLibrary**)&lib_paint);
}

PaintManager* GetPaintManager()
{
	PaintLibrary *lib = CheckPaintLib(LIBOFFSET(PaintLibrary, GetPaintManager));
	if (!lib || !lib->GetPaintManager) return nullptr;
	return (PaintManager*)lib->GetPaintManager();
}

PaintView* GetPaintView(PaintManager *paintManager, Int32 viewId)
{
	PaintLibrary *lib = CheckPaintLib(LIBOFFSET(PaintLibrary, GetPaintView));
	if (!lib || !lib->GetPaintView) return nullptr;
	return (PaintView*)lib->GetPaintView(paintManager, viewId);
}

void PaintView::Free(PaintView *&p)
{
	if (!p) return;
	PaintLibrary *lib = CheckPaintLib(LIBOFFSET(PaintLibrary, Free)); if (!lib) return;
	iPaintView* i = (iPaintView*)p;
	lib->Free(i);
	p = nullptr;
}

// PaintManager methods

Int32 PaintManager::GetViewCount(){ PaintLibCall(false, GetViewCount, iPaintManager*)(); }
maxon::BaseArray<Int32>* PaintManager::GetViewIds(){ PaintLibCall(nullptr, GetViewIds, iPaintManager*)(); }
Int32 PaintManager::GetActiveViewId(){ PaintLibCall(NOTOK, GetActiveViewId, iPaintManager*)(); }
Bool PaintManager::ResetActiveView(){ PaintLibCall(false, ResetActiveView, iPaintManager*)(); }

Bool PaintManager::GetAllowSelectUpdate(){ PaintLibCall(false, GetAllowSelectUpdate, iPaintManager*)(); }
Bool PaintManager::SetAllowSelectUpdate(Bool _allowSelectUpdate){ PaintLibCall(false, SetAllowSelectUpdate, iPaintManager*)(_allowSelectUpdate); }

// PaintView methods

Bool PaintView::GetShowMesh(Bool& showMesh){ PaintLibCall(false, GetShowMesh, iPaintView*)(showMesh); }
Bool PaintView::SetShowMesh(Bool showMesh){ PaintLibCall(false, SetShowMesh, iPaintView*)(showMesh); }
Bool PaintView::SetContextFromSelection(){ PaintLibCall(false, SetContextFromSelection, iPaintView*)(); }
Bool PaintView::FitToScreen(){ PaintLibCall(false, FitToScreen, iPaintView*)(); }


void	BPSingleColorSettings::SetRGB(const Vector &rgb, Float i) { PaintLibMethodCall(bpsinglecolorsettingsSetRGB)(this, rgb, i); }
void	BPSingleColorSettings::GetRGB(Vector &v, Float &h) { PaintLibMethodCall(bpsinglecolorsettingsGetRGB)(this, v, h); }

BPSingleColorSettings* BPColorSettings::GetChannel(Int32 channelid) { PaintLibMethodCallR(nullptr, bpcolorsettingsGetChannel)(this, channelid); }

BPColorSettings *				BPColorSettingsHelpers::GetColorSettings(Bool bg) { PaintLibMethodCallR(nullptr, bpcolorsettingshelpersGetColorSettings)(bg); }
BPSingleColorSettings*	BPColorSettingsHelpers::GetChannelColorSettings(Bool bg, Int32 channelid) { PaintLibMethodCallR(nullptr, bpcolorsettingshelpersGetChannelColorSettings)(bg, channelid); }
BPSingleColorSettings*	BPColorSettingsHelpers::GetSelectedSingleColorSettings(Bool bg, Int32 *channelid) { PaintLibMethodCallR(nullptr, bpcolorsettingshelpersGetSelectedSingleColorSettings)(bg, channelid); }
void										BPColorSettingsHelpers::SetSelectedColorSettings(Bool bg, Int32 channelid) { PaintLibMethodCall(bpcolorsettingshelpersSetSelectedColorSettings)(bg, channelid); }
Bool										BPColorSettingsHelpers::GetGlobalChannelEnabling(Int32 channelid) { PaintLibMethodCallR(false, bpcolorsettingshelpersGetGlobalChannelEnabling)(channelid); }
void										BPColorSettingsHelpers::SetGlobalChannelEnabling(Int32 channelid, Bool enable) { PaintLibMethodCall(bpcolorsettingshelpersSetGlobalChannelEnabling)(channelid, enable); }
Bool										BPColorSettingsHelpers::GetMultiMode(void) { PaintLibMethodCallR(false, bpcolorsettingshelpersGetMultiMode)(); }
void										BPColorSettingsHelpers::SetMultiMode(Bool multi) { PaintLibMethodCall(bpcolorsettingshelpersSetMultiMode)(multi); }
Bool										BPColorSettingsHelpers::ToggleFgBg(void) { PaintLibMethodCallR(false, bpcolorsettingshelpersToggleFgBg)(); }
BPPaintSettings*				BPColorSettingsHelpers::GetActiveColorPreset() { PaintLibMethodCallR(nullptr, bpcolorsettingshelpersGetActiveColorPreset)(); }
void										BPColorSettingsHelpers::SetActiveColorPreset(BPPaintSettings *set) { PaintLibMethodCall(bpcolorsettingshelpersSetActiveColorPreset)(set); }
Bool										BPColorSettingsHelpers::SaveColorSettings(BPPaintSettings *set) { PaintLibMethodCallR(false, bpcolorsettingshelpersSaveColorSettings)(set); }
Bool										BPColorSettingsHelpers::DefineColorPreset(PaintTexture *tex, PaintLayerBmp *layer, PaintLayerBmp *mask, BPSingleColorSettings *color, Bool wallpaper) { PaintLibMethodCallR(false, bpcolorsettingshelpersDefineColorPreset)(tex, layer, mask, color, wallpaper); }


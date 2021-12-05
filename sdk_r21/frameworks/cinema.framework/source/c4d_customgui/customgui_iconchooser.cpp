#include "customgui_iconchooser.h"
#include "c4d_string.h"
#include "c4d_gui.h"

static IconChooserCustomGuiLib* libIconChooser = nullptr;

static IconChooserCustomGuiLib* CheckIconChooserCustomGuiLib(Int32 offset)
{
	return (IconChooserCustomGuiLib*)CheckLib(CUSTOMGUI_ICONCHOOSER, offset, (C4DLibrary**)&libIconChooser);
}

#define IconCall(b)	IconChooserCustomGuiLib *lib = CheckIconChooserCustomGuiLib(LIBOFFSET(IconChooserCustomGuiLib, b)); \
												if (lib && lib->b) (lib->b)

#define IconCallR(a, b) IconChooserCustomGuiLib *lib = CheckIconChooserCustomGuiLib(LIBOFFSET(IconChooserCustomGuiLib, b)); \
												if (!lib || !lib->b) return a; \
												return (lib->b)

void FillCustomIconSettingsFromBaseList2D(CustomIconSettings& settings, const BaseContainer& data, Int32 defaultIconId, Bool fillDefault)
{
	IconCall(FillCustomIconSettingsFromBaseList2D)(settings, data, defaultIconId, fillDefault);
}

Bool GetCustomIcon(GetCustomIconData& cid, const CustomIconSettings& settings, Bool drawBeforeColoring, CustomIconGetIdDelegate* getIdCallback, CustomIconDrawDelegate* drawCallback)
{
	IconCallR(false, GetCustomIcon)(cid, settings, drawBeforeColoring, getIdCallback, drawCallback);
}

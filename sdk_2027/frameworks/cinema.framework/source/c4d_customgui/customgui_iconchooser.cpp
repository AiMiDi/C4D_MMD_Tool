#include "customgui_iconchooser.h"
#include "c4d_string.h"
#include "c4d_gui.h"

namespace cinema
{

static IconChooserCustomGuiLib* libIconChooser = nullptr;

static IconChooserCustomGuiLib* CheckIconChooserCustomGuiLib(Int32 offset)
{
	return CheckLib<IconChooserCustomGuiLib>(CUSTOMGUI_ICONCHOOSER, offset, libIconChooser);
}

#define IconCall(b)	cinema::IconChooserCustomGuiLib *lib = cinema::CheckIconChooserCustomGuiLib(LIBOFFSET(cinema::IconChooserCustomGuiLib, b)); \
												if (lib && lib->b) (lib->b)

#define IconCallR(a, b) cinema::IconChooserCustomGuiLib *lib = cinema::CheckIconChooserCustomGuiLib(LIBOFFSET(cinema::IconChooserCustomGuiLib, b)); \
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

} // namespace cinema

#include "lib_iconcollection.h"
#include "ge_autoptr.h"
#include "c4d_baselist.h"

namespace cinema
{

static IconCollectionLib* library_icon = nullptr;

static IconCollectionLib* CheckIconCollectionLib(Int32 offset)
{
	return CheckLib<IconCollectionLib>(LIBRARY_ICON_COLLECTION, offset, library_icon);
}

Bool RegisterIcon(Int32 iconId, BaseBitmap* bmp, Int32 x, Int32 y, Int32 w, Int32 h, ICONFLAG flags)
{
	IconCollectionLib *lib = CheckIconCollectionLib(LIBOFFSET(IconCollectionLib, RegisterIconBitmap)); if (!lib || !lib->RegisterIconBitmap) return false;
	return lib->RegisterIconBitmap(iconId, bmp, x, y, w, h, flags);
}

Bool RegisterIcon(Int32 iconId, Filename fn, Int32 x, Int32 y, Int32 w, Int32 h, ICONFLAG flags)
{
	IconCollectionLib *lib = CheckIconCollectionLib(LIBOFFSET(IconCollectionLib, RegisterIconFile)); if (!lib || !lib->RegisterIconFile) return false;
	return lib->RegisterIconFile(iconId, fn, x, y, w, h, flags);
}

Bool GetIcon(Int32 iconId, IconData* data)
{
	IconCollectionLib *lib = CheckIconCollectionLib(LIBOFFSET(IconCollectionLib, GetIcon)); if (!lib || !lib->GetIcon) return false;
	return lib->GetIcon(iconId, data);
}

Bool ColorizeIcon(Int32 iconId, const GeData& color)
{
	IconCollectionLib *lib = CheckIconCollectionLib(LIBOFFSET(IconCollectionLib, ColorizeIcon)); if (!lib || !lib->ColorizeIcon) return false;
	return lib->ColorizeIcon(iconId, color);
}

BaseBitmap* GetColorizedIcon(Int32 iconId, const GeData& color)
{
	IconCollectionLib *lib = CheckIconCollectionLib(LIBOFFSET(IconCollectionLib, GetColorizedIcon)); if (!lib || !lib->GetColorizedIcon) return nullptr;
	return lib->GetColorizedIcon(iconId, color);
}

Bool UnregisterIcon(Int32 iconId)
{
	IconCollectionLib *lib = CheckIconCollectionLib(LIBOFFSET(IconCollectionLib, UnregisterIcon)); if (!lib || !lib->UnregisterIcon) return false;
	return lib->UnregisterIcon(iconId);
}

} // namespace cinema

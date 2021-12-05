#include "lib_iconcollection.h"
#include "ge_autoptr.h"
#include "c4d_baselist.h"

static IconCollectionLib *library_icon = nullptr;

static IconCollectionLib *CheckIconCollectionLib(Int32 offset)
{
	return (IconCollectionLib*)CheckLib(LIBRARY_ICON_COLLECTION, offset, (C4DLibrary**)&library_icon);
}

Bool RegisterIcon(Int32 lIconID, BaseBitmap * pBmp, Int32 x, Int32 y, Int32 w, Int32 h, ICONFLAG lFlags)
{
	IconCollectionLib *lib = CheckIconCollectionLib(LIBOFFSET(IconCollectionLib, RegisterIconBitmap)); if (!lib || !lib->RegisterIconBitmap) return false;
	return lib->RegisterIconBitmap(lIconID, pBmp, x, y, w, h, lFlags);
}

Bool RegisterIcon(Int32 lIconID, Filename fn, Int32 x, Int32 y, Int32 w, Int32 h, ICONFLAG lFlags)
{
	IconCollectionLib *lib = CheckIconCollectionLib(LIBOFFSET(IconCollectionLib, RegisterIconFile)); if (!lib || !lib->RegisterIconFile) return false;
	return lib->RegisterIconFile(lIconID, fn, x, y, w, h, lFlags);
}

Bool GetIcon(Int32 lIconID, IconData* pData)
{
	IconCollectionLib *lib = CheckIconCollectionLib(LIBOFFSET(IconCollectionLib, GetIcon)); if (!lib || !lib->GetIcon) return false;
	return lib->GetIcon(lIconID, pData);
}

Bool UnregisterIcon(Int32 lIconID)
{
	IconCollectionLib *lib = CheckIconCollectionLib(LIBOFFSET(IconCollectionLib, UnregisterIcon)); if (!lib || !lib->UnregisterIcon) return false;
	return lib->UnregisterIcon(lIconID);
}

#include "c4d_library.h"
#include "lib_filtertree.h"

static FilterTreeLib* lib_filtertree = nullptr;

static FilterTreeLib *CheckLibFilterTree(Int32 offset)
{
	return (FilterTreeLib*)CheckLib(ID_LIB_FILTERTREE, offset, (C4DLibrary**)&lib_filtertree);
}

void ManagerInfo::UpdateManagerInfo()
{
	FilterTreeLib *lib = CheckLibFilterTree(LIBOFFSET(FilterTreeLib, UpdateManagerInfo));
	if (!lib || !lib->UpdateManagerInfo) return;
	(*lib->UpdateManagerInfo)(this);
}

Bool ShowObjectArt(BaseDocument *doc, Int32 art, const ManagerInfo &minfo)
{
	FilterTreeLib *lib = CheckLibFilterTree(LIBOFFSET(FilterTreeLib, ShowObjectArt));
	if (!lib || !lib->ShowObjectArt) return false;
	return (*lib->ShowObjectArt)(doc, art, minfo);
}

Bool IsObjectHidden(BaseDocument *doc, BaseList2D *bl, const ManagerInfo &minfo)
{
	FilterTreeLib *lib = CheckLibFilterTree(LIBOFFSET(FilterTreeLib, IsObjectHidden));
	if (!lib || !lib->IsObjectHidden) return false;
	return (*lib->IsObjectHidden)(doc, bl, minfo);
}

Bool IsObjectSearchable(BaseDocument *doc, BaseList2D *bl, const ManagerInfo &minfo)
{
	FilterTreeLib *lib = CheckLibFilterTree(LIBOFFSET(FilterTreeLib, IsObjectSearchable));
	if (!lib || !lib->IsObjectSearchable) return false;
	return (*lib->IsObjectSearchable)(doc, bl, minfo);
}

Bool IsLayerHidden(BaseDocument *doc, LayerObject *op, const ManagerInfo &minfo)
{
	FilterTreeLib *lib = CheckLibFilterTree(LIBOFFSET(FilterTreeLib, IsLayerHidden));
	if (!lib || !lib->IsLayerHidden) return false;
	return (*lib->IsLayerHidden)(doc, op, minfo);
}

Bool SetLayerHidden(BaseDocument *doc, LayerObject *op, const ManagerInfo &minfo, Bool hide)
{
	FilterTreeLib *lib = CheckLibFilterTree(LIBOFFSET(FilterTreeLib, SetLayerHidden));
	if (!lib || !lib->SetLayerHidden) return false;
	return (*lib->SetLayerHidden)(doc, op, minfo, hide);
}

Bool BuildFilterList(BaseDocument *doc)
{
	FilterTreeLib *lib = CheckLibFilterTree(LIBOFFSET(FilterTreeLib, BuildFilterList));
	if (!lib || !lib->BuildFilterList) return false;
	return (*lib->BuildFilterList)(doc);
}

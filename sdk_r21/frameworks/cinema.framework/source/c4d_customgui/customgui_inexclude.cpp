#include "customgui_inexclude.h"
#include "c4d_string.h"
#include "c4d_gui.h"


static CustomGuiInExcludeLib *lib_inexclude = nullptr;


static CustomGuiInExcludeLib *CheckCustomGuiInExcludeLib(Int32 offset)
{
	return (CustomGuiInExcludeLib*)CheckLib(CUSTOMGUI_INEXCLUDE_LIST, offset, (C4DLibrary**)&lib_inexclude);
}

#define InExcludeCall(b) 			CustomGuiInExcludeLib *lib = CheckCustomGuiInExcludeLib(LIBOFFSET(CustomGuiInExcludeLib, b)); \
															if (!lib || !lib->b) return; \
															(((iIncludeExcludeData*)this)->*lib->b)

#define InExcludeCallR(a, b) 		CustomGuiInExcludeLib *lib = CheckCustomGuiInExcludeLib(LIBOFFSET(CustomGuiInExcludeLib, b)); \
															if (!lib || !lib->b) return a; \
															return (((iIncludeExcludeData*)this)->*lib->b)

#define InExcludeGuiCall(b) 		CustomGuiInExcludeLib *lib = CheckCustomGuiInExcludeLib(LIBOFFSET(CustomGuiInExcludeLib, b)); \
															if (!lib || !lib->b) return; \
															(((iInExcludeCustomGui*)this)->*lib->b)

#define InExcludeGuiCallR(a, b) CustomGuiInExcludeLib *lib = CheckCustomGuiInExcludeLib(LIBOFFSET(CustomGuiInExcludeLib, b)); \
															if (!lib || !lib->b) return a; \
															return (((iInExcludeCustomGui*)this)->*lib->b)

#define IncludeTableCallR(a, b) 		CustomGuiInExcludeLib *lib = CheckCustomGuiInExcludeLib(LIBOFFSET(CustomGuiInExcludeLib, b)); \
															if (!lib || !lib->b) return a; \
															return (((iInclusionTable*)this)->*lib->b)

Bool InExcludeData::InsertObject(BaseList2D* pObject, Int32 lFlags) { InExcludeCallR(false, InsertObject)(pObject, lFlags); }
Int32 InExcludeData::GetObjectIndex(BaseDocument *doc, BaseList2D* pObject) const { InExcludeCallR(-1, GetObjectIndex)(doc, pObject); }
Bool InExcludeData::DeleteObject(Int32 lIndex) { InExcludeCallR(false, DeleteObject)(lIndex); }
Int32 InExcludeData::GetObjectCount() const { InExcludeCallR(0, GetObjectCount)(); }
Int32 InExcludeData::GetFlags(Int32 lIndex) const { InExcludeCallR(0, GetFlags)(lIndex); }
void InExcludeData::SetFlags(Int32 lIndex, Int32 lFlags) { InExcludeCall(SetFlags)(lIndex, lFlags); }
Int32 InExcludeData::GetFlagCount() const { InExcludeCallR(0, GetFlagCount)(); }
void InExcludeData::SetFlagCount(Int32 lFlagCount) { InExcludeCall(SetFlagCount)(lFlagCount); }
Int32 InExcludeData::GetDefaultFlag() const { InExcludeCallR(0, GetDefaultFlag)(); }
void InExcludeData::SetDefaultFlag(Int32 defaultFlag)  { InExcludeCall(SetDefaultFlag)(defaultFlag); }

BaseList2D* InExcludeData::ObjectFromIndex(BaseDocument *doc, Int32 lIndex) const { InExcludeCallR(nullptr, ObjectFromIndex)(doc, lIndex); }
InclusionTable* InExcludeData::BuildInclusionTable(BaseDocument *doc, Int32 hierarchy_bit) { InExcludeCallR(nullptr, BuildInclusionTable)(doc, hierarchy_bit); }
BaseContainer* InExcludeData::GetData(Int32 lIndex) const { InExcludeCallR(nullptr, GetData)(lIndex); }

Bool InclusionTable::Check(BaseList2D *op) { IncludeTableCallR(false, Check)(op); }
Bool InclusionTable::Check(BaseList2D *op, Int32 &flags) { IncludeTableCallR(false, CheckFlags)(op, flags); }
Int32 InclusionTable::GetObjectCount() { IncludeTableCallR(false, GetObjectCountT)(); }
BaseList2D* InclusionTable::GetObject(Int32 lIndex) { IncludeTableCallR(nullptr, GetObject)(lIndex); }
void FreeInclusionTable(InclusionTable *&pTable)
{
	if (!pTable) return;
	CustomGuiInExcludeLib *lib = CheckCustomGuiInExcludeLib(LIBOFFSET(CustomGuiInExcludeLib, LIB_FreeInclusionTable));
	if (!lib || !lib->LIB_FreeInclusionTable) return;
	InclusionTable* t = pTable;
	(lib->LIB_FreeInclusionTable)((iInclusionTable*)t);
	pTable = nullptr;
}

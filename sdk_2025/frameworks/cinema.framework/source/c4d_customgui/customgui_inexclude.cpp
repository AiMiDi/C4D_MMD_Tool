#include "customgui_inexclude.h"
#include "c4d_string.h"
#include "c4d_gui.h"

namespace cinema
{

static CustomGuiInExcludeLib *lib_inexclude = nullptr;


static CustomGuiInExcludeLib *CheckCustomGuiInExcludeLib(Int32 offset)
{
	return CheckLib<CustomGuiInExcludeLib>(CUSTOMGUI_INEXCLUDE_LIST, offset, lib_inexclude);
}

#define InExcludeCall(b) 			cinema::CustomGuiInExcludeLib *lib = cinema::CheckCustomGuiInExcludeLib(LIBOFFSET(cinema::CustomGuiInExcludeLib, b)); \
															if (!lib || !lib->b) return; \
															((reinterpret_cast<cinema::iIncludeExcludeData*>(this))->*lib->b)

#define InExcludeCallR(a, b) 		cinema::CustomGuiInExcludeLib *lib = cinema::CheckCustomGuiInExcludeLib(LIBOFFSET(cinema::CustomGuiInExcludeLib, b)); \
															if (!lib || !lib->b) return a; \
															return ((reinterpret_cast<cinema::iIncludeExcludeData*>(this))->*lib->b)

#define InExcludeCallConstR(a, b) 		const cinema::CustomGuiInExcludeLib *lib = cinema::CheckCustomGuiInExcludeLib(LIBOFFSET(cinema::CustomGuiInExcludeLib, b)); \
															if (!lib || !lib->b) return a; \
															return ((reinterpret_cast<const cinema::iIncludeExcludeData*>(this))->*lib->b)

#define InExcludeGuiCall(b) 		cinema::CustomGuiInExcludeLib *lib = cinema::CheckCustomGuiInExcludeLib(LIBOFFSET(cinema::CustomGuiInExcludeLib, b)); \
															if (!lib || !lib->b) return; \
															((reinterpret_cast<cinema::iInExcludeCustomGui*>(this))->*lib->b)

#define InExcludeGuiCallR(a, b) cinema::CustomGuiInExcludeLib *lib = cinema::CheckCustomGuiInExcludeLib(LIBOFFSET(cinema::CustomGuiInExcludeLib, b)); \
															if (!lib || !lib->b) return a; \
															return ((reinterpret_cast<cinema::iInExcludeCustomGui*>(this))->*lib->b)

#define IncludeTableCallR(a, b) 		cinema::CustomGuiInExcludeLib *lib = cinema::CheckCustomGuiInExcludeLib(LIBOFFSET(cinema::CustomGuiInExcludeLib, b)); \
															if (!lib || !lib->b) return a; \
															return ((reinterpret_cast<cinema::iInclusionTable*>(this))->*lib->b)

#define IncludeTableCallConstR(a, b) 		const cinema::CustomGuiInExcludeLib *lib = cinema::CheckCustomGuiInExcludeLib(LIBOFFSET(cinema::CustomGuiInExcludeLib, b)); \
															if (!lib || !lib->b) return a; \
															return ((reinterpret_cast<const cinema::iInclusionTable*>(this))->*lib->b)

Bool InExcludeData::InsertObject(const BaseList2D* pObject, Int32 lFlags) { InExcludeCallR(false, InsertObject)(pObject, lFlags); }
Int32 InExcludeData::GetObjectIndex(const BaseDocument *doc, const BaseList2D* pObject) const { InExcludeCallConstR(-1, GetObjectIndex)(doc, pObject); }
Bool InExcludeData::DeleteObject(Int32 lIndex) { InExcludeCallR(false, DeleteObject)(lIndex); }
void InExcludeData::Reset() { InExcludeCall(Reset)(); }
Int32 InExcludeData::GetObjectCount() const { InExcludeCallConstR(0, GetObjectCount)(); }
Int32 InExcludeData::GetFlags(Int32 lIndex) const { InExcludeCallConstR(0, GetFlags)(lIndex); }
void InExcludeData::SetFlags(Int32 lIndex, Int32 lFlags) { InExcludeCall(SetFlags)(lIndex, lFlags); }
Int32 InExcludeData::GetFlagCount() const { InExcludeCallConstR(0, GetFlagCount)(); }
void InExcludeData::SetFlagCount(Int32 lFlagCount) { InExcludeCall(SetFlagCount)(lFlagCount); }
Int32 InExcludeData::GetDefaultFlag() const { InExcludeCallConstR(0, GetDefaultFlag)(); }
void InExcludeData::SetDefaultFlag(Int32 defaultFlag)  { InExcludeCall(SetDefaultFlag)(defaultFlag); }

const BaseList2D* InExcludeData::ObjectFromIndex(const BaseDocument *doc, Int32 lIndex) const { InExcludeCallConstR(nullptr, ObjectFromIndex)(doc, lIndex); }
InclusionTable* InExcludeData::BuildInclusionTable(const BaseDocument *doc, Int32 hierarchy_bit) const { InExcludeCallConstR(nullptr, BuildInclusionTable)(doc, hierarchy_bit); }
BaseContainer* InExcludeData::GetData(Int32 lIndex)
{
	InExcludeCallR(nullptr, GetData)(lIndex);
}
const BaseContainer* InExcludeData::GetData(Int32 lIndex) const
{
	InExcludeCallConstR(nullptr, GetDataC)(lIndex);
}

Bool InclusionTable::Check(const BaseList2D *op) const { IncludeTableCallConstR(false, Check)(op); }
Bool InclusionTable::Check(const BaseList2D *op, Int32 &flags) const { IncludeTableCallConstR(false, CheckFlags)(op, flags); }
Int32 InclusionTable::GetObjectCount() const { IncludeTableCallConstR(false, GetObjectCountT)(); }
BaseList2D* InclusionTable::GetObject(Int32 lIndex) const { IncludeTableCallConstR(nullptr, GetObject)(lIndex); }
void FreeInclusionTable(InclusionTable *&pTable)
{
	if (!pTable) return;
	CustomGuiInExcludeLib *lib = CheckCustomGuiInExcludeLib(LIBOFFSET(CustomGuiInExcludeLib, LIB_FreeInclusionTable));
	if (!lib || !lib->LIB_FreeInclusionTable) return;
	InclusionTable* t = pTable;
	(lib->LIB_FreeInclusionTable)(reinterpret_cast<iInclusionTable*>(t));
	pTable = nullptr;
}

} // namespace cinema

#include "customgui_matassign.h"
#include "c4d_string.h"
#include "c4d_gui.h"

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_BEGIN
#endif

static CustomGuiMatAssignLib *lib_matassign = nullptr;


static CustomGuiMatAssignLib *CheckGuiMatAssignLib(Int32 offset)
{
	return CheckLib<CustomGuiMatAssignLib>(CUSTOMGUI_MATASSIGN, offset, lib_matassign);
}

#define MatAssignCall(b) 			CustomGuiMatAssignLib *lib = CheckGuiMatAssignLib(LIBOFFSET(CustomGuiMatAssignLib, b)); \
															if (!lib || !lib->b) return; \
															(reinterpret_cast<iMatAssignData*>(this)->*lib->b)

#define MatAssignCallR(a, b) 	CustomGuiMatAssignLib *lib = CheckGuiMatAssignLib(LIBOFFSET(CustomGuiMatAssignLib, b)); \
															if (!lib || !lib->b) return a; \
															return (reinterpret_cast<iMatAssignData*>(this)->*lib->b)

#define MatAssignCallRC(a, b) CustomGuiMatAssignLib *lib = CheckGuiMatAssignLib(LIBOFFSET(CustomGuiMatAssignLib, b)); \
															if (!lib || !lib->b) return a; \
															return (reinterpret_cast<const iMatAssignData*>(this)->*lib->b)

#define MatAssignGuiCall(b) 		CustomGuiMatAssignLib *lib = CheckGuiMatAssignLib(LIBOFFSET(CustomGuiMatAssignLib, b)); \
															if (!lib || !lib->b) return; \
															(reinterpret_cast<iMatAssignCustomGui*>(this)->*lib->b)

#define MatAssignGuiCallR(a, b) CustomGuiMatAssignLib *lib = CheckGuiMatAssignLib(LIBOFFSET(CustomGuiMatAssignLib, b)); \
															if (!lib || !lib->b) return a; \
															return (reinterpret_cast<iMatAssignCustomGui*>(this)->*lib->b)

#define MatAssignTableCallR(a, b) 	CustomGuiMatAssignLib *lib = CheckGuiMatAssignLib(LIBOFFSET(CustomGuiMatAssignLib, b)); \
															if (!lib || !lib->b) return a; \
															return (reinterpret_cast<iMatAssignTable*>(this)->*lib->b)

Bool MatAssignData::InsertObject(BaseList2D* pObject, Int32 lFlags) { MatAssignCallR(false, InsertObject)(pObject, lFlags); }
Int32 MatAssignData::GetObjectIndex(BaseDocument *doc, BaseList2D* pObject) { MatAssignCallR(-1, GetObjectIndex)(doc, pObject); }
Bool MatAssignData::DeleteObject(Int32 lIndex) { MatAssignCallR(false, DeleteObject)(lIndex); }
Int32 MatAssignData::GetObjectCount() const { MatAssignCallRC(0, GetObjectCount)(); }
BaseList2D* MatAssignData::ObjectFromIndex(BaseDocument *doc, Int32 lIndex) { MatAssignCallR(nullptr, ObjectFromIndex)(doc, lIndex); }
BaseList2D* MatAssignData::ObjectFromIndex(BaseDocument* doc, Int32 lIndex) const
{
	return MAXON_REMOVE_CONST(this)->ObjectFromIndex(doc, lIndex);
}
void MatAssignData::SetMaterial(const AtomArray &materials) { MatAssignCall(SetMaterial)(materials); }
Bool MatAssignData::GetMaterial(BaseDocument *doc, AtomArray &materials) { MatAssignCallR(false, GetMaterial)(doc, materials); }

Bool MatAssignTable::Check(BaseList2D *op) { MatAssignTableCallR(false, Check)(op); }
Int32 MatAssignTable::GetObjectCount() { MatAssignTableCallR(false, GetObjectCountT)(); }
BaseList2D* MatAssignTable::GetObject(Int32 lIndex) { MatAssignTableCallR(nullptr, GetObject)(lIndex); }
void FreeInclusionTable(MatAssignTable *&pTable)
{
	if (!pTable) return;
	CustomGuiMatAssignLib *lib = CheckGuiMatAssignLib(LIBOFFSET(CustomGuiMatAssignLib, LIB_FreeInclusionTable));
	if (!lib || !lib->LIB_FreeInclusionTable) return;
	MatAssignTable* t = pTable;
	(lib->LIB_FreeInclusionTable)(reinterpret_cast<iMatAssignTable*>(t));
	pTable = nullptr;
}

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_END
#endif

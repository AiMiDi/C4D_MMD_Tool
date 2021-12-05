#include "customgui_unitscale.h"
#include "c4d_string.h"
#include "c4d_gui.h"

static UnitScaleCustomGuiLib *lib_UnitScale = nullptr;

static UnitScaleCustomGuiLib *CheckUnitScaleCustomGuiLib(Int32 offset)
{
	return (UnitScaleCustomGuiLib*)CheckLib(CUSTOMGUI_UNITSCALE, offset, (C4DLibrary**)&lib_UnitScale);
}

#define UnitScaleCall(b) 			UnitScaleCustomGuiLib *lib = CheckUnitScaleCustomGuiLib(LIBOFFSET(UnitScaleCustomGuiLib, b)); \
															if (!lib || !lib->b) return; \
															(((iUnitScaleData*)this)->*lib->b)

#define UnitScaleCallR(a, b) 		UnitScaleCustomGuiLib *lib = CheckUnitScaleCustomGuiLib(LIBOFFSET(UnitScaleCustomGuiLib, b)); \
															if (!lib || !lib->b) return a; \
															return (((iUnitScaleData*)this)->*lib->b)

#define UnitScaleGuiCall(b) 		UnitScaleCustomGuiLib *lib = CheckUnitScaleCustomGuiLib(LIBOFFSET(UnitScaleCustomGuiLib, b)); \
															if (!lib || !lib->b) return; \
															(((iUnitScaleCustomGui*)this)->*lib->b)

#define UnitScaleGuiCallR(a, b) UnitScaleCustomGuiLib *lib = CheckUnitScaleCustomGuiLib(LIBOFFSET(UnitScaleCustomGuiLib, b)); \
															if (!lib || !lib->b) return a; \
															return (((iUnitScaleCustomGui*)this)->*lib->b)

Bool UnitScaleCustomGui::SetValue(const UnitScaleData *data) { UnitScaleGuiCallR(false, SetValue)(data); }
Bool UnitScaleCustomGui::GetValue(UnitScaleData *data) const { UnitScaleGuiCallR(false, GetValue)(data); }

Bool UnitScaleData::SetUnitScale(Float scale, DOCUMENT_UNIT unit) { UnitScaleCallR(false, SetUnitScale)(scale, unit); } // same like above
Bool UnitScaleData::GetUnitScale(Float &scale, DOCUMENT_UNIT &unit) const { UnitScaleCallR(false, GetUnitScale)(scale, unit); }

Bool UnitScaleData::operator == (const UnitScaleData& b) const
{
	UnitScaleCallR(false, UnitScaleEqual)((const iUnitScaleData&)b);
}

Bool UnitScaleData::operator != (const UnitScaleData& b) const
{
	return !(*this == b);
}

UnitScaleData* UnitScaleData::Alloc()
{
	UnitScaleCustomGuiLib *lib = CheckUnitScaleCustomGuiLib(LIBOFFSET(UnitScaleCustomGuiLib, iUnitScaleData_Alloc));
	if (!lib || !lib->iUnitScaleData_Alloc) return nullptr;
	return (*lib->iUnitScaleData_Alloc)();
}

void UnitScaleData::Free(UnitScaleData *&data)
{
	UnitScaleCustomGuiLib *lib = CheckUnitScaleCustomGuiLib(LIBOFFSET(UnitScaleCustomGuiLib, iUnitScaleData_Free));
	if (!lib || !lib->iUnitScaleData_Free) return;
	(*lib->iUnitScaleData_Free)(data);
}

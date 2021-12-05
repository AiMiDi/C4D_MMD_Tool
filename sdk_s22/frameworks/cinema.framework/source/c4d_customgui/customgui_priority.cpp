#include "customgui_priority.h"
#include "c4d_string.h"
#include "c4d_gui.h"

static PriorityCustomGuiLib *lib_Priority = nullptr;

static PriorityCustomGuiLib *CheckPriorityCustomGuiLib(Int32 offset)
{
	return (PriorityCustomGuiLib*)CheckLib(CUSTOMGUI_PRIORITY, offset, (C4DLibrary**)&lib_Priority);
}

#define PriorityCall(b) 			PriorityCustomGuiLib *lib = CheckPriorityCustomGuiLib(LIBOFFSET(PriorityCustomGuiLib, b)); \
															if (!lib || !lib->b) return; \
															(((iPriorityData*)this)->*lib->b)

#define PriorityCallR(a, b) 		PriorityCustomGuiLib *lib = CheckPriorityCustomGuiLib(LIBOFFSET(PriorityCustomGuiLib, b)); \
															if (!lib || !lib->b) return a; \
															return (((iPriorityData*)this)->*lib->b)

#define PriorityGuiCall(b) 		PriorityCustomGuiLib *lib = CheckPriorityCustomGuiLib(LIBOFFSET(PriorityCustomGuiLib, b)); \
															if (!lib || !lib->b) return; \
															(((iPriorityCustomGui*)this)->*lib->b)

#define PriorityGuiCallR(a, b) PriorityCustomGuiLib *lib = CheckPriorityCustomGuiLib(LIBOFFSET(PriorityCustomGuiLib, b)); \
															if (!lib || !lib->b) return a; \
															return (((iPriorityCustomGui*)this)->*lib->b)

Bool PriorityCustomGui::SetValue(Int32 lValueID, const GeData &data) { PriorityGuiCallR(false, SetValue)(lValueID, data); }
GeData PriorityCustomGui::GetValue(Int32 lValueID) const { PriorityGuiCallR(GeData(), GetValue)(lValueID); }

Bool PriorityData::SetPriorityValue(Int32 lValueID, const GeData &data) { PriorityCallR(false, SetPriorityValue)(lValueID, data); } // same like above
GeData PriorityData::GetPriorityValue(Int32 lValueID) const { PriorityCallR(GeData(), GetPriorityValue)(lValueID); }

#include "customgui_priority.h"
#include "c4d_string.h"
#include "c4d_gui.h"

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_BEGIN
#endif

static PriorityCustomGuiLib *lib_Priority = nullptr;

static PriorityCustomGuiLib *CheckPriorityCustomGuiLib(Int32 offset)
{
	return CheckLib<PriorityCustomGuiLib>(CUSTOMGUI_PRIORITY, offset, lib_Priority);
}

#define PriorityCall(b) 			PriorityCustomGuiLib *lib = CheckPriorityCustomGuiLib(LIBOFFSET(PriorityCustomGuiLib, b)); \
															if (!lib || !lib->b) return; \
															(reinterpret_cast<iPriorityData*>(this)->*lib->b)

#define PriorityCallR(a, b) 		PriorityCustomGuiLib *lib = CheckPriorityCustomGuiLib(LIBOFFSET(PriorityCustomGuiLib, b)); \
															if (!lib || !lib->b) return a; \
															return (reinterpret_cast<iPriorityData*>(this)->*lib->b)

#define PriorityCallRC(a, b) 	PriorityCustomGuiLib *lib = CheckPriorityCustomGuiLib(LIBOFFSET(PriorityCustomGuiLib, b)); \
															if (!lib || !lib->b) return a; \
															return (reinterpret_cast<const iPriorityData*>(this)->*lib->b)

#define PriorityGuiCall(b) 		PriorityCustomGuiLib *lib = CheckPriorityCustomGuiLib(LIBOFFSET(PriorityCustomGuiLib, b)); \
															if (!lib || !lib->b) return; \
															(reinterpret_cast<iPriorityCustomGui*>(this)->*lib->b)

#define PriorityGuiCallR(a, b) PriorityCustomGuiLib *lib = CheckPriorityCustomGuiLib(LIBOFFSET(PriorityCustomGuiLib, b)); \
															if (!lib || !lib->b) return a; \
															return (reinterpret_cast<iPriorityCustomGui*>(this)->*lib->b)

#define PriorityGuiCallRC(a, b) PriorityCustomGuiLib *lib = CheckPriorityCustomGuiLib(LIBOFFSET(PriorityCustomGuiLib, b)); \
															if (!lib || !lib->b) return a; \
															return (reinterpret_cast<const iPriorityCustomGui*>(this)->*lib->b)

Bool PriorityCustomGui::SetValue(Int32 lValueID, const GeData &data) { PriorityGuiCallR(false, SetValue)(lValueID, data); }
GeData PriorityCustomGui::GetValue(Int32 lValueID) const { PriorityGuiCallRC(GeData(), GetValue)(lValueID); }

Bool PriorityData::SetPriorityValue(Int32 lValueID, const GeData &data) { PriorityCallR(false, SetPriorityValue)(lValueID, data); } // same like above
GeData PriorityData::GetPriorityValue(Int32 lValueID) const { PriorityCallRC(GeData(), GetPriorityValue)(lValueID); }

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_END
#endif

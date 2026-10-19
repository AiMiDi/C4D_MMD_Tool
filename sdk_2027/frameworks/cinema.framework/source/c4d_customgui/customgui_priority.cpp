#include "customgui_priority.h"
#include "c4d_string.h"
#include "c4d_gui.h"

namespace cinema
{

static PriorityCustomGuiLib *lib_Priority = nullptr;

static PriorityCustomGuiLib *CheckPriorityCustomGuiLib(Int32 offset)
{
	return CheckLib<PriorityCustomGuiLib>(CUSTOMGUI_PRIORITY, offset, lib_Priority);
}

#define PriorityCall(b) 			cinema::PriorityCustomGuiLib *lib = cinema::CheckPriorityCustomGuiLib(LIBOFFSET(cinema::PriorityCustomGuiLib, b)); \
															if (!lib || !lib->b) return; \
															(reinterpret_cast<cinema::iPriorityData*>(this)->*lib->b)

#define PriorityCallR(a, b) 		cinema::PriorityCustomGuiLib *lib = cinema::CheckPriorityCustomGuiLib(LIBOFFSET(cinema::PriorityCustomGuiLib, b)); \
															if (!lib || !lib->b) return a; \
															return (reinterpret_cast<cinema::iPriorityData*>(this)->*lib->b)

#define PriorityCallRC(a, b) 	cinema::PriorityCustomGuiLib *lib = cinema::CheckPriorityCustomGuiLib(LIBOFFSET(cinema::PriorityCustomGuiLib, b)); \
															if (!lib || !lib->b) return a; \
															return (reinterpret_cast<const cinema::iPriorityData*>(this)->*lib->b)

#define PriorityGuiCall(b) 		cinema::PriorityCustomGuiLib *lib = cinema::CheckPriorityCustomGuiLib(LIBOFFSET(cinema::PriorityCustomGuiLib, b)); \
															if (!lib || !lib->b) return; \
															(reinterpret_cast<cinema::iPriorityCustomGui*>(this)->*lib->b)

#define PriorityGuiCallR(a, b) cinema::PriorityCustomGuiLib *lib = cinema::CheckPriorityCustomGuiLib(LIBOFFSET(cinema::PriorityCustomGuiLib, b)); \
															if (!lib || !lib->b) return a; \
															return (reinterpret_cast<cinema::iPriorityCustomGui*>(this)->*lib->b)

#define PriorityGuiCallRC(a, b) cinema::PriorityCustomGuiLib *lib = cinema::CheckPriorityCustomGuiLib(LIBOFFSET(cinema::PriorityCustomGuiLib, b)); \
															if (!lib || !lib->b) return a; \
															return (reinterpret_cast<const cinema::iPriorityCustomGui*>(this)->*lib->b)

Bool PriorityCustomGui::SetValue(Int32 lValueID, const GeData &data) { PriorityGuiCallR(false, SetValue)(lValueID, data); }
GeData PriorityCustomGui::GetValue(Int32 lValueID) const { PriorityGuiCallRC(GeData(), GetValue)(lValueID); }

Bool PriorityData::SetPriorityValue(Int32 lValueID, const GeData &data) { PriorityCallR(false, SetPriorityValue)(lValueID, data); } // same like above
GeData PriorityData::GetPriorityValue(Int32 lValueID) const { PriorityCallRC(GeData(), GetPriorityValue)(lValueID); }

} // namespace cinema

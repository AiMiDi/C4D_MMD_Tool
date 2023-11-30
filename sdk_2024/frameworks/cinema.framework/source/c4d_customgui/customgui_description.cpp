#include "customgui_description.h"
#include "c4d_gui.h"
#include "c4d_string.h"
#include "lib_description.h"

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_BEGIN
#endif

static DescriptionGuiLib *lib_description = nullptr;


static DescriptionGuiLib *CheckDescriptionGuiLib(Int32 offset)
{
	return CheckLib<DescriptionGuiLib>(CUSTOMGUI_DESCRIPTION, offset, lib_description);
}


void DescriptionCustomGui::SetObjectList(const AtomArray &list, Bool limitExceeded)
{
	DescriptionGuiLib *lib = CheckDescriptionGuiLib(LIBOFFSET(DescriptionGuiLib, SetObjectList));
	if (!lib || !lib->SetObjectList) return;

	(reinterpret_cast<iDescriptionCustomGui*>(this)->*lib->SetObjectList)(list, limitExceeded);
}

void DescriptionCustomGui::SetObject(C4DAtom *op)
{
	DescriptionGuiLib *lib = CheckDescriptionGuiLib(LIBOFFSET(DescriptionGuiLib, SetObject));
	if (!lib || !lib->SetObject) return;

	(reinterpret_cast<iDescriptionCustomGui*>(this)->*lib->SetObject)(op);
}

Bool DescriptionCustomGui::GetObjectList(AtomArray &list)
{
	DescriptionGuiLib *lib = CheckDescriptionGuiLib(LIBOFFSET(DescriptionGuiLib, GetObjectList));
	if (!lib || !lib->GetObjectList) return false;

	return (reinterpret_cast<iDescriptionCustomGui*>(this)->*lib->GetObjectList)(list);
}

void DescriptionCustomGui::SetMaster(GeDialog *dlg, MasterCallBackFunc *func)
{
	DescriptionGuiLib *lib = CheckDescriptionGuiLib(LIBOFFSET(DescriptionGuiLib, SetMaster));
	if (!lib || !lib->SetMaster) return;

	(reinterpret_cast<iDescriptionCustomGui*>(this)->*lib->SetMaster)(dlg, func);
}

GeData DescriptionCustomGui::MasterMessage(const BaseContainer &msg)
{
	DescriptionGuiLib *lib = CheckDescriptionGuiLib(LIBOFFSET(DescriptionGuiLib, MasterMessage));
	if (!lib || !lib->MasterMessage) return false;

	return (reinterpret_cast<iDescriptionCustomGui*>(this)->*lib->MasterMessage)(msg);
}

String DescriptionCustomGui::GetFilterString(AMFILTERFLAGS &flags)
{
	DescriptionGuiLib *lib = CheckDescriptionGuiLib(LIBOFFSET(DescriptionGuiLib, GetFilterString));
	if (!lib || !lib->GetFilterString) return String();

	return (reinterpret_cast<iDescriptionCustomGui*>(this)->*lib->GetFilterString)(flags);
}

void DescriptionCustomGui::SetFilterString(const maxon::String &filter, AMFILTERFLAGS flags)
{
	DescriptionGuiLib *lib = CheckDescriptionGuiLib(LIBOFFSET(DescriptionGuiLib, SetFilterString));
	if (!lib || !lib->SetFilterString) return;

	(reinterpret_cast<iDescriptionCustomGui*>(this)->*lib->SetFilterString)(filter, flags);
}

void DescriptionCustomGui::SetFilter(DescriptionFilter *flt)
{
	DescriptionGuiLib *lib = CheckDescriptionGuiLib(LIBOFFSET(DescriptionGuiLib, SetFilter));
	if (!lib || !lib->SetFilter) return;

	(reinterpret_cast<iDescriptionCustomGui*>(this)->*lib->SetFilter)(flt);
}

DescID DescriptionCustomGui::HighlightDescID(const DescID& id, Bool check)
{
	DescriptionGuiLib *lib = CheckDescriptionGuiLib(LIBOFFSET(DescriptionGuiLib, HighlightDescID));
	if (!lib || !lib->HighlightDescID) return DescID();

	return (reinterpret_cast<iDescriptionCustomGui*>(this)->*lib->HighlightDescID)(id, check);
}

void DescriptionCustomGui::SetActiveTabPage(const DescID &activetab)
{
	DescriptionGuiLib *lib = CheckDescriptionGuiLib(LIBOFFSET(DescriptionGuiLib, SetActiveTabPage));
	if (!lib || !lib->SetActiveTabPage) return;

	return (reinterpret_cast<iDescriptionCustomGui*>(this)->*lib->SetActiveTabPage)(activetab);
}

Bool DescriptionCustomGui::GetDescIDSelection(BaseContainer &selection)
{
	DescriptionGuiLib *lib = CheckDescriptionGuiLib(LIBOFFSET(DescriptionGuiLib, GetDescIDSelection));
	if (!lib || !lib->GetDescIDSelection) return false;

	return (reinterpret_cast<iDescriptionCustomGui*>(this)->*lib->GetDescIDSelection)(selection);
}

void DescriptionCustomGui::SetTranslation(const maxon::Delegate<Bool(GeListNode* node, const DescID& id, DescID& resultId, C4DAtom*& resultAtom)>& func, Bool objectControl)
{
	DescriptionGuiLib *lib = CheckDescriptionGuiLib(LIBOFFSET(DescriptionGuiLib, SetTranslation));
	if (!lib || !lib->SetTranslation) return;

	(reinterpret_cast<iDescriptionCustomGui*>(this)->*lib->SetTranslation)(func, objectControl);
}

void DescriptionCustomGui::ClearTranslation()
{
	DescriptionGuiLib *lib = CheckDescriptionGuiLib(LIBOFFSET(DescriptionGuiLib, ClearTranslation));
	if (!lib || !lib->ClearTranslation) return;

	(reinterpret_cast<iDescriptionCustomGui*>(this)->*lib->ClearTranslation)();
}

maxon::Result<void> DescriptionCustomGui::ModifyDescription(maxon::Delegate<void(GeListNode* node, Description& description, DESCFLAGS_DESC flags)>&& func)
{
	DescriptionGuiLib *lib = CheckDescriptionGuiLib(LIBOFFSET(DescriptionGuiLib, ModifyDescription));
	if (!lib || !lib->ModifyDescription)
		return maxon::UnexpectedError(MAXON_SOURCE_LOCATION);

	return (reinterpret_cast<iDescriptionCustomGui*>(this)->*lib->ModifyDescription)(std::move(func));
}

void DescriptionCustomGui::ClearModifyDescription()
{
	DescriptionGuiLib *lib = CheckDescriptionGuiLib(LIBOFFSET(DescriptionGuiLib, ClearModifyDescription));
	if (!lib || !lib->ClearModifyDescription) return;

	(reinterpret_cast<iDescriptionCustomGui*>(this)->*lib->ClearModifyDescription)();
}

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_END
#endif

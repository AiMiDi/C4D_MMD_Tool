#include "customgui_description.h"
#include "c4d_gui.h"
#include "c4d_string.h"
#include "lib_description.h"


static DescriptionGuiLib *lib_description = nullptr;


static DescriptionGuiLib *CheckDescriptionLib(Int32 offset)
{
	return (DescriptionGuiLib*)CheckLib(CUSTOMGUI_DESCRIPTION, offset, (C4DLibrary**)&lib_description);
}


void DescriptionCustomGui::SetObjectList(const AtomArray &list, Bool limitExceeded)
{
	DescriptionGuiLib *lib = CheckDescriptionLib(LIBOFFSET(DescriptionGuiLib, SetObjectList));
	if (!lib || !lib->SetObjectList) return;

	(((iDescriptionCustomGui*)this)->*lib->SetObjectList)(list, limitExceeded);
}

void DescriptionCustomGui::SetObject(C4DAtom *op)
{
	DescriptionGuiLib *lib = CheckDescriptionLib(LIBOFFSET(DescriptionGuiLib, SetObject));
	if (!lib || !lib->SetObject) return;

	(((iDescriptionCustomGui*)this)->*lib->SetObject)(op);
}

Bool DescriptionCustomGui::GetObjectList(AtomArray &list)
{
	DescriptionGuiLib *lib = CheckDescriptionLib(LIBOFFSET(DescriptionGuiLib, GetObjectList));
	if (!lib || !lib->GetObjectList) return false;

	return (((iDescriptionCustomGui*)this)->*lib->GetObjectList)(list);
}

void DescriptionCustomGui::SetMaster(GeDialog *dlg, MasterCallBackFunc *func)
{
	DescriptionGuiLib *lib = CheckDescriptionLib(LIBOFFSET(DescriptionGuiLib, SetMaster));
	if (!lib || !lib->SetMaster) return;

	(((iDescriptionCustomGui*)this)->*lib->SetMaster)(dlg, func);
}

GeData DescriptionCustomGui::MasterMessage(const BaseContainer &msg)
{
	DescriptionGuiLib *lib = CheckDescriptionLib(LIBOFFSET(DescriptionGuiLib, MasterMessage));
	if (!lib || !lib->MasterMessage) return false;

	return (((iDescriptionCustomGui*)this)->*lib->MasterMessage)(msg);
}

String DescriptionCustomGui::GetFilterString(AMFILTERFLAGS &flags)
{
	DescriptionGuiLib *lib = CheckDescriptionLib(LIBOFFSET(DescriptionGuiLib, GetFilterString));
	if (!lib || !lib->GetFilterString) return String();

	return (((iDescriptionCustomGui*)this)->*lib->GetFilterString)(flags);
}

void DescriptionCustomGui::SetFilterString(const maxon::String &filter, AMFILTERFLAGS flags)
{
	DescriptionGuiLib *lib = CheckDescriptionLib(LIBOFFSET(DescriptionGuiLib, SetFilterString));
	if (!lib || !lib->SetFilterString) return;

	(((iDescriptionCustomGui*)this)->*lib->SetFilterString)(filter, flags);
}

void DescriptionCustomGui::SetFilter(DescriptionFilter *flt)
{
	DescriptionGuiLib *lib = CheckDescriptionLib(LIBOFFSET(DescriptionGuiLib, SetFilter));
	if (!lib || !lib->SetFilter) return;

	(((iDescriptionCustomGui*)this)->*lib->SetFilter)(flt);
}

DescID DescriptionCustomGui::HighlightDescID(const DescID& id, Bool check)
{
	DescriptionGuiLib *lib = CheckDescriptionLib(LIBOFFSET(DescriptionGuiLib, HighlightDescID));
	if (!lib || !lib->HighlightDescID) return DescID();

	return (((iDescriptionCustomGui*)this)->*lib->HighlightDescID)(id, check);
}

void DescriptionCustomGui::SetActiveTabPage(const DescID &activetab)
{
	DescriptionGuiLib *lib = CheckDescriptionLib(LIBOFFSET(DescriptionGuiLib, SetActiveTabPage));
	if (!lib || !lib->SetActiveTabPage) return;

	return (((iDescriptionCustomGui*)this)->*lib->SetActiveTabPage)(activetab);
}

Bool DescriptionCustomGui::GetDescIDSelection(BaseContainer &selection)
{
	DescriptionGuiLib *lib = CheckDescriptionLib(LIBOFFSET(DescriptionGuiLib, GetDescIDSelection));
	if (!lib || !lib->GetDescIDSelection) return false;

	return (((iDescriptionCustomGui*)this)->*lib->GetDescIDSelection)(selection);
}

void DescriptionCustomGui::SetTranslation(const maxon::Delegate<Bool(GeListNode* node, const DescID& id, DescID& resultId, C4DAtom*& resultAtom)>& func, Bool objectControl)
{
	DescriptionGuiLib *lib = CheckDescriptionLib(LIBOFFSET(DescriptionGuiLib, SetTranslation));
	if (!lib || !lib->SetTranslation) return;

	(((iDescriptionCustomGui*)this)->*lib->SetTranslation)(func, objectControl);
}

void DescriptionCustomGui::ClearTranslation()
{
	DescriptionGuiLib *lib = CheckDescriptionLib(LIBOFFSET(DescriptionGuiLib, ClearTranslation));
	if (!lib || !lib->ClearTranslation) return;

	(((iDescriptionCustomGui*)this)->*lib->ClearTranslation)();
}

maxon::Result<void> DescriptionCustomGui::ModifyDescription(maxon::Delegate<void(GeListNode* node, Description& description, DESCFLAGS_DESC flags)>&& func)
{
	DescriptionGuiLib *lib = CheckDescriptionLib(LIBOFFSET(DescriptionGuiLib, ModifyDescription));
	if (!lib || !lib->ModifyDescription)
		return maxon::UnexpectedError(MAXON_SOURCE_LOCATION);

	return (((iDescriptionCustomGui*)this)->*lib->ModifyDescription)(std::move(func));
}

void DescriptionCustomGui::ClearModifyDescription()
{
	DescriptionGuiLib *lib = CheckDescriptionLib(LIBOFFSET(DescriptionGuiLib, ClearModifyDescription));
	if (!lib || !lib->ClearModifyDescription) return;

	(((iDescriptionCustomGui*)this)->*lib->ClearModifyDescription)();
}

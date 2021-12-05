#include "customgui_descproperty.h"
#include "c4d_string.h"
#include "c4d_gui.h"


static CustomGuiDescriptionPropertyLib *lib_matlink = nullptr;


static CustomGuiDescriptionPropertyLib *CheckDescProperty(Int32 offset)
{
	return (CustomGuiDescriptionPropertyLib*)CheckLib(CUSTOMGUI_DESCRIPTIONPROPERTY, offset, (C4DLibrary**)&lib_matlink);
}

void DescriptionPropertyCustomGui::SetState(DESCPROP flags)
{
	CustomGuiDescriptionPropertyLib *lib = CheckDescProperty(LIBOFFSET(CustomGuiDescriptionPropertyLib, SetData));
	if (!lib || !lib->SetData) return;

	(((iDescriptionPropertyCustomGui*)this)->*lib->SetState)(flags);
}

DESCPROP DescriptionPropertyCustomGui::GetState()
{
	CustomGuiDescriptionPropertyLib *lib = CheckDescProperty(LIBOFFSET(CustomGuiDescriptionPropertyLib, GetState));
	if (!lib || !lib->GetState) return DESCPROP::NONE;

	return (((iDescriptionPropertyCustomGui*)this)->*lib->GetState)();
}

void DescriptionPropertyCustomGui::SetDescID(const DescID &id)
{
	CustomGuiDescriptionPropertyLib *lib = CheckDescProperty(LIBOFFSET(CustomGuiDescriptionPropertyLib, SetDescID));
	if (!lib || !lib->GetState) return;

	(((iDescriptionPropertyCustomGui*)this)->*lib->SetDescID)(id);
}

Int32 DescriptionPropertyCustomGui::GetPartCount()
{
	CustomGuiDescriptionPropertyLib *lib = CheckDescProperty(LIBOFFSET(CustomGuiDescriptionPropertyLib, GetPartCount));
	if (!lib || !lib->GetPartCount) return 0;

	return (((iDescriptionPropertyCustomGui*)this)->*lib->GetPartCount)();
}

void DescriptionPropertyCustomGui::GetPartInfo(Int32 part, maxon::String &str, DescID &id, Bool &onoff)
{
	CustomGuiDescriptionPropertyLib *lib = CheckDescProperty(LIBOFFSET(CustomGuiDescriptionPropertyLib, GetPartInfo));
	if (!lib || !lib->GetPartInfo) return;

	(((iDescriptionPropertyCustomGui*)this)->*lib->GetPartInfo)(part, str, id, onoff);
}

void DescriptionPropertyCustomGui::SetSelection(const DescID &id, Bool onoff)
{
	CustomGuiDescriptionPropertyLib *lib = CheckDescProperty(LIBOFFSET(CustomGuiDescriptionPropertyLib, SetSelection));
	if (!lib || !lib->SetSelection) return;

	(((iDescriptionPropertyCustomGui*)this)->*lib->SetSelection)(id, onoff);
}

void DescriptionPropertyCustomGui::ChangeSettings(const BaseContainer &settings)
{
	CustomGuiDescriptionPropertyLib *lib = CheckDescProperty(LIBOFFSET(CustomGuiDescriptionPropertyLib, ChangeSettings));
	if (!lib || !lib->ChangeSettings) return;

	(((iDescriptionPropertyCustomGui*)this)->*lib->ChangeSettings)(settings);
}

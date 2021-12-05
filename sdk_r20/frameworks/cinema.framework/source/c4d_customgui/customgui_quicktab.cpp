#include "customgui_quicktab.h"
#include "c4d_string.h"
#include "c4d_gui.h"


QuickTabLib *lib_quicktab = nullptr;


static QuickTabLib *CheckQuickTabLib(Int32 offset)
{
	return (QuickTabLib*)CheckLib(CUSTOMGUI_QUICKTAB, offset, (C4DLibrary**)&lib_quicktab);
}

void QuickTabCustomGui::ClearStrings()
{
	QuickTabLib *lib = CheckQuickTabLib(LIBOFFSET(QuickTabLib, ClearStrings));
	if (!lib || !lib->ClearStrings) return;
	(((iQuickTabCustomGui*)this)->*lib->ClearStrings)();
}

void QuickTabCustomGui::AppendString(Int32 id, const maxon::String &str, Bool checked)
{
	QuickTabLib *lib = CheckQuickTabLib(LIBOFFSET(QuickTabLib, AppendString));
	if (!lib || !lib->AppendString) return;
	(((iQuickTabCustomGui*)this)->*lib->AppendString)(id, str, checked);
}

void QuickTabCustomGui::SetTextColor(Int32 id, Int32 col)
{
	QuickTabLib *lib = CheckQuickTabLib(LIBOFFSET(QuickTabLib, SetTextColor));
	if (!lib || !lib->SetTextColor) return;
	(((iQuickTabCustomGui*)this)->*lib->SetTextColor)(id, col);
}

void QuickTabCustomGui::SetTextColorSelected(Int32 id, Int32 col)
{
	QuickTabLib *lib = CheckQuickTabLib(LIBOFFSET(QuickTabLib, SetTextColorSelected));
	if (!lib || !lib->SetTextColorSelected) return;
	(((iQuickTabCustomGui*)this)->*lib->SetTextColorSelected)(id, col);
}

void QuickTabCustomGui::SetBackgroundColorSelected(Int32 id, Int32 col)
{
	QuickTabLib *lib = CheckQuickTabLib(LIBOFFSET(QuickTabLib, SetBackgroundColorSelected));
	if (!lib || !lib->SetBackgroundColorSelected) return;
	(((iQuickTabCustomGui*)this)->*lib->SetBackgroundColorSelected)(id, col);
}

void QuickTabCustomGui::SetLayerColor(Int32 id, Bool show, const Vector &col)
{
	QuickTabLib *lib = CheckQuickTabLib(LIBOFFSET(QuickTabLib, SetLayerColor));
	if (!lib || !lib->SetLayerColor) return;
	(((iQuickTabCustomGui*)this)->*lib->SetLayerColor)(id, show, col);
}

void QuickTabCustomGui::DoLayoutChange()
{
	QuickTabLib *lib = CheckQuickTabLib(LIBOFFSET(QuickTabLib, DoLayoutChange));
	if (!lib || !lib->DoLayoutChange) return;
	(((iQuickTabCustomGui*)this)->*lib->DoLayoutChange)();
}

Bool QuickTabCustomGui::IsSelected(Int32 id)
{
	QuickTabLib *lib = CheckQuickTabLib(LIBOFFSET(QuickTabLib, IsSelected));
	if (!lib || !lib->IsSelected) return false;
	return (((iQuickTabCustomGui*)this)->*lib->IsSelected)(id);
}

Bool QuickTabCustomGui::Select(Int32 id, Bool b)
{
	QuickTabLib *lib = CheckQuickTabLib(LIBOFFSET(QuickTabLib, Select));
	if (!lib || !lib->Select) return false;
	return (((iQuickTabCustomGui*)this)->*lib->Select)(id, b);
}


#include "customgui_bitmapbutton.h"
#include "c4d_string.h"
#include "c4d_gui.h"
#include "lib_iconcollection.h"


BitmapButtonLib *lib_bitmapbutton = nullptr;


static BitmapButtonLib *CheckButtonLib(Int32 offset)
{
	return (BitmapButtonLib*)CheckLib(CUSTOMGUI_BITMAPBUTTON, offset, (C4DLibrary**)&lib_bitmapbutton);
}

Bool BitmapButtonCustomGui::SetImage(BaseBitmap *bmp, Bool copybmp, Bool secondstate)
{
	BitmapButtonLib *lib = CheckButtonLib(LIBOFFSET(BitmapButtonLib, SetImageA));
	if (!lib || !lib->SetImageA) return false;

	return (((iBitmapButtonCustomGui*)this)->*lib->SetImageA)(bmp, copybmp, secondstate);
}

Bool BitmapButtonCustomGui::SetImage(IconData *bmp, Bool secondstate)
{
	BitmapButtonLib *lib = CheckButtonLib(LIBOFFSET(BitmapButtonLib, SetImageA));
	if (!lib || !lib->SetImageC) return false;

	return (((iBitmapButtonCustomGui*)this)->*lib->SetImageC)(bmp, secondstate);
}

Bool BitmapButtonCustomGui::SetImage(Int32 icon_id, Bool secondstate)
{
	BitmapButtonLib *lib = CheckButtonLib(LIBOFFSET(BitmapButtonLib, SetImageA));
	if (!lib || !lib->SetImageC) return false;

	IconData dat;
	if (!GetIcon(icon_id, &dat)) return false;

	return (((iBitmapButtonCustomGui*)this)->*lib->SetImageC)(&dat, secondstate);
}

Bool BitmapButtonCustomGui::SetImage(const Filename &name, Bool secondstate)
{
	BitmapButtonLib *lib = CheckButtonLib(LIBOFFSET(BitmapButtonLib, SetImageA));
	if (!lib || !lib->SetImageB) return false;

	return (((iBitmapButtonCustomGui*)this)->*lib->SetImageB)(name, secondstate);
}

void BitmapButtonCustomGui::SetToggleState(Bool set)
{
	BitmapButtonLib *lib = CheckButtonLib(LIBOFFSET(BitmapButtonLib, SetToggleState));
	if (!lib || !lib->SetToggleState) return;

	(((iBitmapButtonCustomGui*)this)->*lib->SetToggleState)(set);
}

void BitmapButtonCustomGui::SetDragArray(const AtomArray *array)
{
	BitmapButtonLib *lib = CheckButtonLib(LIBOFFSET(BitmapButtonLib, SetDragArray));
	if (!lib || !lib->SetDragArray) return;

	(((iBitmapButtonCustomGui*)this)->*lib->SetDragArray)(array);
}

void BitmapButtonCustomGui::SetCommandDragId(Int32 cmdid)
{
	BitmapButtonLib *lib = CheckButtonLib(LIBOFFSET(BitmapButtonLib, SetCommandDragId));
	if (!lib || !lib->SetCommandDragId) return;

	(((iBitmapButtonCustomGui*)this)->*lib->SetCommandDragId)(cmdid);
}

Int32 BitmapButtonCustomGui::GetMaxWidth() const
{
	BitmapButtonLib *lib = CheckButtonLib(LIBOFFSET(BitmapButtonLib, GetMaxWidth));
	if (!lib || !lib->GetMaxWidth) return 0;

	return (((iBitmapButtonCustomGui*)this)->*lib->GetMaxWidth)();
}

void BitmapButtonCustomGui::SetCallback(const BitmapButtonCallback &cb)
{
	BitmapButtonLib *lib = CheckButtonLib(LIBOFFSET(BitmapButtonLib, SetCallback));
	if (!lib || !lib->SetCallback) return;

	(((iBitmapButtonCustomGui*)this)->*lib->SetCallback)(cb);
}


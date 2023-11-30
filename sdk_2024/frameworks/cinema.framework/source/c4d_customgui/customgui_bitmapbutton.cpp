#include "customgui_bitmapbutton.h"
#include "c4d_string.h"
#include "c4d_gui.h"
#include "lib_iconcollection.h"

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_BEGIN
#endif

BitmapButtonLib *lib_bitmapbutton = nullptr;


static BitmapButtonLib *CheckButtonLib(Int32 offset)
{
	return CheckLib<BitmapButtonLib>(CUSTOMGUI_BITMAPBUTTON, offset, lib_bitmapbutton);
}

Bool BitmapButtonCustomGui::SetImage(BaseBitmap *bmp, Bool copybmp, Bool secondstate)
{
	BitmapButtonLib *lib = CheckButtonLib(LIBOFFSET(BitmapButtonLib, SetImageA));
	if (!lib || !lib->SetImageA) return false;

	return (reinterpret_cast<iBitmapButtonCustomGui*>(this)->*lib->SetImageA)(bmp, copybmp, secondstate);
}

Bool BitmapButtonCustomGui::SetImage(IconData *bmp, Bool secondstate)
{
	BitmapButtonLib *lib = CheckButtonLib(LIBOFFSET(BitmapButtonLib, SetImageA));
	if (!lib || !lib->SetImageC) return false;

	return (reinterpret_cast<iBitmapButtonCustomGui*>(this)->*lib->SetImageC)(bmp, secondstate);
}

Bool BitmapButtonCustomGui::SetImage(Int32 icon_id, Bool secondstate)
{
	BitmapButtonLib *lib = CheckButtonLib(LIBOFFSET(BitmapButtonLib, SetImageA));
	if (!lib || !lib->SetImageC) return false;

	IconData dat;
	if (!GetIcon(icon_id, &dat)) return false;

	return (reinterpret_cast<iBitmapButtonCustomGui*>(this)->*lib->SetImageC)(&dat, secondstate);
}

Bool BitmapButtonCustomGui::SetImage(const Filename &name, Bool secondstate)
{
	BitmapButtonLib *lib = CheckButtonLib(LIBOFFSET(BitmapButtonLib, SetImageA));
	if (!lib || !lib->SetImageB) return false;

	return (reinterpret_cast<iBitmapButtonCustomGui*>(this)->*lib->SetImageB)(name, secondstate);
}

void BitmapButtonCustomGui::SetToggleState(Bool set)
{
	BitmapButtonLib *lib = CheckButtonLib(LIBOFFSET(BitmapButtonLib, SetToggleState));
	if (!lib || !lib->SetToggleState) return;

	(reinterpret_cast<iBitmapButtonCustomGui*>(this)->*lib->SetToggleState)(set);
}

void BitmapButtonCustomGui::SetTooltip(const String& tooltip)
{
	BitmapButtonLib *lib = CheckButtonLib(LIBOFFSET(BitmapButtonLib, SetTooltip));
	if (!lib || !lib->SetTooltip) return;

	(reinterpret_cast<iBitmapButtonCustomGui*>(this)->*lib->SetTooltip)(tooltip);
}

void BitmapButtonCustomGui::SetDragArray(const AtomArray *array)
{
	BitmapButtonLib *lib = CheckButtonLib(LIBOFFSET(BitmapButtonLib, SetDragArray));
	if (!lib || !lib->SetDragArray) return;

	(reinterpret_cast<iBitmapButtonCustomGui*>(this)->*lib->SetDragArray)(array);
}

void BitmapButtonCustomGui::SetCommandDragId(Int32 cmdid)
{
	BitmapButtonLib *lib = CheckButtonLib(LIBOFFSET(BitmapButtonLib, SetCommandDragId));
	if (!lib || !lib->SetCommandDragId) return;

	(reinterpret_cast<iBitmapButtonCustomGui*>(this)->*lib->SetCommandDragId)(cmdid);
}

Int32 BitmapButtonCustomGui::GetMaxWidth() const
{
	BitmapButtonLib *lib = CheckButtonLib(LIBOFFSET(BitmapButtonLib, GetMaxWidth));
	if (!lib || !lib->GetMaxWidth) return 0;

	return (reinterpret_cast<const iBitmapButtonCustomGui*>(this)->*lib->GetMaxWidth)();
}

void BitmapButtonCustomGui::SetCallback(const BitmapButtonCallback &cb)
{
	BitmapButtonLib *lib = CheckButtonLib(LIBOFFSET(BitmapButtonLib, SetCallback));
	if (!lib || !lib->SetCallback) return;

	(reinterpret_cast<iBitmapButtonCustomGui*>(this)->*lib->SetCallback)(cb);
}

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_END
#endif

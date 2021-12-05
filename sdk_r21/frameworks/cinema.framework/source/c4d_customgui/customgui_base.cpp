#include "customgui_base.h"


Bool iBaseCustomGui::SetObjects(const AtomArray &ar)
{
	return false;
}



void FillBaseCustomGui(BaseCustomGuiLib &basecustomguilib)
{
	basecustomguilib.Redraw								= &iBaseCustomGui::CustomGuiRedraw					;
	basecustomguilib.LayoutChanged				= &iBaseCustomGui::CustomGuiLayoutChanged		;
	basecustomguilib.GetWidth							= &iBaseCustomGui::CustomGuiWidth						;
	basecustomguilib.GetHeight						= &iBaseCustomGui::CustomGuiHeight					;
	basecustomguilib.Activate							= &iBaseCustomGui::CustomGuiActivate				;
	basecustomguilib.SetDefaultForResEdit	= &iBaseCustomGui::SetDefaultForResEdit			;
	basecustomguilib.SetData							= &iBaseCustomGui::SetData									;
	basecustomguilib.GetData							= &iBaseCustomGui::GetData									;
	basecustomguilib.SetLayoutMode				= &iBaseCustomGui::SetLayoutMode						;
	basecustomguilib.GetLayoutMode				= &iBaseCustomGui::GetLayoutMode						;
	basecustomguilib.SupportLayoutSwitch	= &iBaseCustomGui::SupportLayoutSwitch			;
	basecustomguilib.SetObjects						= &iBaseCustomGui::SetObjects								;
}

Int32 _BaseCustomGui::GetWidth(Int32 LIBRARYID)
{
	BaseCustomGuiLib *lib = (BaseCustomGuiLib*)CheckLib(LIBRARYID, LIBOFFSET(BaseCustomGuiLib, GetWidth), nullptr);
	if (!lib || !lib->GetWidth) return false;
	return (((iBaseCustomGui*)this)->*lib->GetWidth)();
}

Int32 _BaseCustomGui::GetHeight(Int32 LIBRARYID)
{
	BaseCustomGuiLib *lib = (BaseCustomGuiLib*)CheckLib(LIBRARYID, LIBOFFSET(BaseCustomGuiLib, GetHeight), nullptr);
	if (!lib || !lib->GetHeight) return false;
	return (((iBaseCustomGui*)this)->*lib->GetHeight)();
}

void _BaseCustomGui::Redraw(Int32 LIBRARYID)
{
	BaseCustomGuiLib *lib = (BaseCustomGuiLib*)CheckLib(LIBRARYID, LIBOFFSET(BaseCustomGuiLib, Redraw), nullptr);
	if (!lib || !lib->Redraw) return;
	(((iBaseCustomGui*)this)->*lib->Redraw)();
}

Bool _BaseCustomGui::LayoutChanged(Int32 LIBRARYID)
{
	BaseCustomGuiLib *lib = (BaseCustomGuiLib*)CheckLib(LIBRARYID, LIBOFFSET(BaseCustomGuiLib, LayoutChanged), nullptr);
	if (!lib || !lib->LayoutChanged) return false;
	return (((iBaseCustomGui*)this)->*lib->LayoutChanged)();
}

Bool _BaseCustomGui::Activate(Int32 LIBRARYID)
{
	BaseCustomGuiLib *lib = (BaseCustomGuiLib*)CheckLib(LIBRARYID, LIBOFFSET(BaseCustomGuiLib, Activate), nullptr);
	if (!lib || !lib->Activate) return false;
	return (((iBaseCustomGui*)this)->*lib->Activate)();
}

Bool _BaseCustomGui::SetDefaultForResEdit(Int32 LIBRARYID)
{
	BaseCustomGuiLib *lib = (BaseCustomGuiLib*)CheckLib(LIBRARYID, LIBOFFSET(BaseCustomGuiLib, SetDefaultForResEdit), nullptr);
	if (!lib || !lib->SetDefaultForResEdit) return false;
	return (((iBaseCustomGui*)this)->*lib->SetDefaultForResEdit)();
}

Bool _BaseCustomGui::SetData(Int32 LIBRARYID, const TriState<GeData> &tristate)
{
	BaseCustomGuiLib *lib = (BaseCustomGuiLib*)CheckLib(LIBRARYID, LIBOFFSET(BaseCustomGuiLib, SetData), nullptr);
	if (!lib || !lib->SetData) return false;
	return (((iBaseCustomGui*)this)->*lib->SetData)(tristate);
}

TriState<GeData> _BaseCustomGui::GetData(Int32 LIBRARYID)
{
	BaseCustomGuiLib *lib = (BaseCustomGuiLib*)CheckLib(LIBRARYID, LIBOFFSET(BaseCustomGuiLib, GetData), nullptr);
	if (!lib || !lib->GetData)
	{
		TriState<GeData> tri;
		return tri;
	}
	return (((iBaseCustomGui*)this)->*lib->GetData)();
}

void _BaseCustomGui::SetLayoutMode(Int32 LIBRARYID, Int32 mode)
{
	BaseCustomGuiLib *lib = (BaseCustomGuiLib*)CheckLib(LIBRARYID, LIBOFFSET(BaseCustomGuiLib, SetLayoutMode), nullptr);
	if (!lib || !lib->SetLayoutMode) return;
	(((iBaseCustomGui*)this)->*lib->SetLayoutMode)(mode);
}

Int32 _BaseCustomGui::GetLayoutMode(Int32 LIBRARYID)
{
	BaseCustomGuiLib *lib = (BaseCustomGuiLib*)CheckLib(LIBRARYID, LIBOFFSET(BaseCustomGuiLib, GetLayoutMode), nullptr);
	if (!lib || !lib->GetLayoutMode) return 0;
	return (((iBaseCustomGui*)this)->*lib->GetLayoutMode)();
}

Bool _BaseCustomGui::SupportLayoutSwitch(Int32 LIBRARYID)
{
	BaseCustomGuiLib *lib = (BaseCustomGuiLib*)CheckLib(LIBRARYID, LIBOFFSET(BaseCustomGuiLib, SupportLayoutSwitch), nullptr);
	if (!lib || !lib->SupportLayoutSwitch) return 0;
	return (((iBaseCustomGui*)this)->*lib->SupportLayoutSwitch)();
}

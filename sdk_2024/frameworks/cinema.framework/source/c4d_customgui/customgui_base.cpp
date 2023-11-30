#include "customgui_base.h"

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_BEGIN
#endif

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

static BaseCustomGuiLib* g_basecustomguilib;

Int32 _BaseCustomGui::GetWidth(Int32 LIBRARYID)
{
	BaseCustomGuiLib *lib = CheckLib<BaseCustomGuiLib>(LIBRARYID, LIBOFFSET(BaseCustomGuiLib, GetWidth), g_basecustomguilib);
	if (!lib || !lib->GetWidth) return false;
	return (reinterpret_cast<iBaseCustomGui*>(this)->*lib->GetWidth)();
}

Int32 _BaseCustomGui::GetHeight(Int32 LIBRARYID)
{
	BaseCustomGuiLib *lib = CheckLib<BaseCustomGuiLib>(LIBRARYID, LIBOFFSET(BaseCustomGuiLib, GetHeight), g_basecustomguilib);
	if (!lib || !lib->GetHeight) return false;
	return (reinterpret_cast<iBaseCustomGui*>(this)->*lib->GetHeight)();
}

void _BaseCustomGui::Redraw(Int32 LIBRARYID)
{
	BaseCustomGuiLib *lib = CheckLib<BaseCustomGuiLib>(LIBRARYID, LIBOFFSET(BaseCustomGuiLib, Redraw), g_basecustomguilib);
	if (!lib || !lib->Redraw) return;
	(reinterpret_cast<iBaseCustomGui*>(this)->*lib->Redraw)();
}

Bool _BaseCustomGui::LayoutChanged(Int32 LIBRARYID)
{
	BaseCustomGuiLib *lib = CheckLib<BaseCustomGuiLib>(LIBRARYID, LIBOFFSET(BaseCustomGuiLib, LayoutChanged), g_basecustomguilib);
	if (!lib || !lib->LayoutChanged) return false;
	return (reinterpret_cast<iBaseCustomGui*>(this)->*lib->LayoutChanged)();
}

Bool _BaseCustomGui::Activate(Int32 LIBRARYID)
{
	BaseCustomGuiLib *lib = CheckLib<BaseCustomGuiLib>(LIBRARYID, LIBOFFSET(BaseCustomGuiLib, Activate), g_basecustomguilib);
	if (!lib || !lib->Activate) return false;
	return (reinterpret_cast<iBaseCustomGui*>(this)->*lib->Activate)();
}

Bool _BaseCustomGui::SetDefaultForResEdit(Int32 LIBRARYID)
{
	BaseCustomGuiLib *lib = CheckLib<BaseCustomGuiLib>(LIBRARYID, LIBOFFSET(BaseCustomGuiLib, SetDefaultForResEdit), g_basecustomguilib);
	if (!lib || !lib->SetDefaultForResEdit) return false;
	return (reinterpret_cast<iBaseCustomGui*>(this)->*lib->SetDefaultForResEdit)();
}

Bool _BaseCustomGui::SetData(Int32 LIBRARYID, const TriState<GeData> &tristate)
{
	BaseCustomGuiLib *lib = CheckLib<BaseCustomGuiLib>(LIBRARYID, LIBOFFSET(BaseCustomGuiLib, SetData), g_basecustomguilib);
	if (!lib || !lib->SetData) return false;
	return (reinterpret_cast<iBaseCustomGui*>(this)->*lib->SetData)(tristate);
}

TriState<GeData> _BaseCustomGui::GetData(Int32 LIBRARYID)
{
	BaseCustomGuiLib *lib = CheckLib<BaseCustomGuiLib>(LIBRARYID, LIBOFFSET(BaseCustomGuiLib, GetData), g_basecustomguilib);
	if (!lib || !lib->GetData)
	{
		TriState<GeData> tri;
		return tri;
	}
	return (reinterpret_cast<iBaseCustomGui*>(this)->*lib->GetData)();
}

void _BaseCustomGui::SetLayoutMode(Int32 LIBRARYID, Int32 mode)
{
	BaseCustomGuiLib *lib = CheckLib<BaseCustomGuiLib>(LIBRARYID, LIBOFFSET(BaseCustomGuiLib, SetLayoutMode), g_basecustomguilib);
	if (!lib || !lib->SetLayoutMode) return;
	(reinterpret_cast<iBaseCustomGui*>(this)->*lib->SetLayoutMode)(mode);
}

Int32 _BaseCustomGui::GetLayoutMode(Int32 LIBRARYID)
{
	BaseCustomGuiLib *lib = CheckLib<BaseCustomGuiLib>(LIBRARYID, LIBOFFSET(BaseCustomGuiLib, GetLayoutMode), g_basecustomguilib);
	if (!lib || !lib->GetLayoutMode) return 0;
	return (reinterpret_cast<iBaseCustomGui*>(this)->*lib->GetLayoutMode)();
}

Bool _BaseCustomGui::SupportLayoutSwitch(Int32 LIBRARYID)
{
	BaseCustomGuiLib *lib = CheckLib<BaseCustomGuiLib>(LIBRARYID, LIBOFFSET(BaseCustomGuiLib, SupportLayoutSwitch), g_basecustomguilib);
	if (!lib || !lib->SupportLayoutSwitch) return 0;
	return (reinterpret_cast<iBaseCustomGui*>(this)->*lib->SupportLayoutSwitch)();
}

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_END
#endif

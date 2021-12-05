#include "c4d_baseplugin.h"

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_BEGIN
#endif

BaseData::BaseData(void)
{
}

BaseData::~BaseData(void)
{
}

void BaseData::Destructor(void)
{
	BaseData* _this;

	_this = this;
	DeleteObj(_this);
}

#ifndef __API_INTERN__

#define Call(fnc) (this->*C4DOS.Ge->fnc)

void* BasePlugin::GetPluginStructure()
{
	return Call(GetPluginStructure) ();
}

Int32 BasePlugin::GetInfo()
{
	return Call(GetInfo) ();
}

Filename BasePlugin::GetFilename()
{
	return Call(GetFilename) ();
}

Int32 BasePlugin::GetID()
{
	return Call(GetID) ();
}

TOOLDRAW ToolPlugin::Draw(BaseDocument *doc, BaseDraw *bd, BaseDrawHelp *bh, BaseThread *bt, TOOLDRAWFLAGS flags)
{
	return Call(Draw)(doc, bd, bh, bt, flags);
}

Bool ToolPlugin::InitDisplayControl(BaseDocument *doc, BaseDraw *bd, const AtomArray *active)
{
	return Call(InitDisplayControl)(doc, bd, active);
}

void ToolPlugin::FreeDisplayControl()
{
	Call(FreeDisplayControl)();
}

Bool ToolPlugin::DisplayControl(BaseDocument *doc, BaseObject *op, BaseObject *chainstart, BaseDraw *bd, BaseDrawHelp *bh, ControlDisplayStruct &cds) const
{
	return Call(DisplayControl)(doc, op, chainstart, bd, bh, cds);
}

BasePlugin* FindPlugin(Int32 id, PLUGINTYPE type)
{
	return (*C4DOS.Ge->FindPlugin)(id, type);
}

void RemovePlugin(BasePlugin* plug)
{
	(*C4DOS.Ge->RemovePlugin)(plug);
}

BasePlugin*	GetFirstPlugin()
{
	return (*C4DOS.Ge->GetFirstPlugin)();
}

Bool FilterPluginList(AtomArray& arr, PLUGINTYPE type, Bool sortbyname)
{
	return (*C4DOS.Ge->FilterPluginList)(arr, type, sortbyname);
}

void BuildGlobalTagPluginContainer(BaseContainer* plugincontainer, Int32* id, UInt& newFeatureVersion)
{
	(*C4DOS.Ge->BuildGlobalTagPluginContainer)(plugincontainer, id, newFeatureVersion	);
}

Int32 ResolveGlobalTagPluginContainer(Int32* id)
{
	return (*C4DOS.Ge->ResolveGlobalTagPluginContainer)(id);
}

// private
Filename* GetLocalFilename()
{
	return (*C4DOS.Ge->GetLocalFilename)();
}

// private
BasePlugin* CreatePluginEntry(const maxon::String& fn, BasePlugin* bp)
{
	return (*C4DOS.Ge->CreatePluginEntry)(fn, bp);
}

// private
void SetLocalHierarchy(BasePlugin* parent, BasePlugin* pred)
{
	C4DOS.Ge->SetLocalHierarchy(parent, pred);
}

#endif

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_END
#endif

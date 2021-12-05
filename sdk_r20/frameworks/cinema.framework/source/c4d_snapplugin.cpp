#include "c4d_snapplugin.h"

SnapCoreLib* snaplib_cache;

static SnapCoreLib* CheckSnapLib(Int32 offset)
{
	return (SnapCoreLib*)CheckLib(ID_SNAPCORE_LIB, offset, (C4DLibrary**)&snaplib_cache);
}

Bool SnapCore::Init(BaseDocument* doc, BaseDraw* bd, AtomArray* exclude/*= nullptr*/)
{
	SnapCoreLib* slib = CheckSnapLib(LIBOFFSET(SnapCoreLib, Init));
	if (!slib || !slib->Init)
		return false;

	return (((iSnapCore*)this)->*(slib->Init))(doc, bd, exclude);
}

Bool SnapCore::Update(void)
{
	SnapCoreLib* slib = CheckSnapLib(LIBOFFSET(SnapCoreLib, Update));
	if (!slib || !slib->Update)
		return false;

	return (((iSnapCore*)this)->*(slib->Update))();
}

Bool SnapCore::Snap(const Vector& p, SnapResult& result, SNAPFLAGS flags)
{
	SnapCoreLib* slib = CheckSnapLib(LIBOFFSET(SnapCoreLib, Snap));
	if (!slib || !slib->Snap)
		return false;

	return (((iSnapCore*)this)->*(slib->Snap))(p, result, flags);
}

Bool SnapCore::Intersect(const Vector& p, const Vector& n, Bool plane, SnapResult& result, SNAPFLAGS flags)
{
	SnapCoreLib* slib = CheckSnapLib(LIBOFFSET(SnapCoreLib, Intersect));
	if (!slib || !slib->Intersect)
		return false;

	return (((iSnapCore*)this)->*(slib->Intersect))(p, n, plane, result, flags);
}

BaseObject* SnapCore::AddInferred(BaseDocument* doc, const Matrix& mat, INFERREDGUIDETYPE type)
{
	SnapCoreLib* slib = CheckSnapLib(LIBOFFSET(SnapCoreLib, AddInferred));
	if (!slib || !slib->AddInferred)
		return nullptr;

	return (BaseObject*)(((iSnapCore*)this)->*(slib->AddInferred))(doc, mat, type);
}

Bool SnapCore::FlushInferred(void)
{
	SnapCoreLib* slib = CheckSnapLib(LIBOFFSET(SnapCoreLib, FlushInferred));
	if (!slib || !slib->FlushInferred)
		return false;

	return (((iSnapCore*)this)->*(slib->FlushInferred))();

}

void SnapCore::SetToolObject(BaseObject* op)
{
	SnapCoreLib* slib = CheckSnapLib(LIBOFFSET(SnapCoreLib, SetToolObject));
	if (!slib || !slib->SetToolObject)
		return;

	(((iSnapCore*)this)->*(slib->SetToolObject))(op);
}

SnapCore* SnapCore::Alloc(void)
{
	SnapCoreLib* slib = CheckSnapLib(LIBOFFSET(SnapCoreLib, Alloc));
	if (!slib || !slib->Alloc)
		return nullptr;

	return (SnapCore*)slib->Alloc();
}

void SnapCore::Free(SnapCore*& p)
{
	SnapCoreLib* slib = CheckSnapLib(LIBOFFSET(SnapCoreLib, Free));
	if (!slib || !slib->Free)
		return;

	iSnapCore* tmp = (iSnapCore*)p;
	slib->Free(tmp);
	p = nullptr;
}

void SnapCore::SetCustomExcludeList(maxon::BaseArray<SnapExclude>* snapExcludeList)
{
	SnapCoreLib* slib = CheckSnapLib(LIBOFFSET(SnapCoreLib, SetCustomExcludeList));
	if (!slib || !slib->SetCustomExcludeList)
		return;
	(((iSnapCore*)this)->*(slib->SetCustomExcludeList))(snapExcludeList);
}

//////////////////////////////////////////////////////////////////////////
// !Helper functions
Bool IsSnapEnabled(BaseDocument* doc, Int32 mode)
{
	SnapCoreLib* slib = CheckSnapLib(LIBOFFSET(SnapCoreLib, IsSnapEnabled));
	if (!slib || !slib->IsSnapEnabled)
		return false;

	return slib->IsSnapEnabled(mode, doc);
}

void EnableSnap(Bool state, BaseDocument* doc, Int32 mode)
{
	SnapCoreLib* slib = CheckSnapLib(LIBOFFSET(SnapCoreLib, EnableSnap));
	if (!slib || !slib->EnableSnap)
		return;

	slib->EnableSnap(mode, state, doc);
}

BaseContainer SnapSettings(BaseDocument* doc, Int32 snapmode/* = NOTOK*/)
{
	SnapCoreLib* slib = CheckSnapLib(LIBOFFSET(SnapCoreLib, GetSnapSettings));
	if (!slib || !slib->GetSnapSettings)
		return BaseContainer();

	return slib->GetSnapSettings(doc, snapmode);
}

void SnapSettings(BaseDocument* doc, const BaseContainer& bc, Int32 snapmode/*= NOTOK*/)
{
	SnapCoreLib* slib = CheckSnapLib(LIBOFFSET(SnapCoreLib, SetSnapSettings));
	if (!slib || !slib->SetSnapSettings)
		return;

	slib->SetSnapSettings(doc, bc, snapmode);
}

Bool IsQuantizeEnabled(BaseDocument* doc)
{
	SnapCoreLib* slib = CheckSnapLib(LIBOFFSET(SnapCoreLib, IsQuantizeEnabled));
	if (!slib || !slib->IsQuantizeEnabled)
		return false;

	return slib->IsQuantizeEnabled(doc);
}

Float QuantizeStep(BaseDocument* doc, BaseDraw* bd, Int32 quantize_mode)
{
	SnapCoreLib* slib = CheckSnapLib(LIBOFFSET(SnapCoreLib, GetQuantizeStep));
	if (!slib || !slib->GetQuantizeStep)
		return false;

	return slib->GetQuantizeStep(doc, bd, quantize_mode);
}

void QuantizeStep(BaseDocument* doc, BaseDraw* bd, Int32 quantize_mode, Float val)
{
	SnapCoreLib* slib = CheckSnapLib(LIBOFFSET(SnapCoreLib, SetQuantizeStep));
	if (!slib || !slib->SetQuantizeStep)
		return;

	slib->SetQuantizeStep(doc, bd, quantize_mode, val);
}

Bool GetConstructionPlane(BaseDraw* bd, Matrix* mg, Vector* scale, BaseObject** op)
{
	SnapCoreLib* slib = CheckSnapLib(LIBOFFSET(SnapCoreLib, GetConstructionPlane));
	if (!slib || !slib->GetConstructionPlane)
		return false;

	return slib->GetConstructionPlane(bd, mg, scale, op);
}

BaseObject* GetWorkplaneObject(BaseDocument* doc)
{
	SnapCoreLib* slib = CheckSnapLib(LIBOFFSET(SnapCoreLib, GetWorkplaneObject));
	if (!slib || !slib->GetWorkplaneObject)
		return nullptr;

	return slib->GetWorkplaneObject(doc);
}

Bool WorkplaneLock(BaseDocument* doc)
{
	SnapCoreLib* slib = CheckSnapLib(LIBOFFSET(SnapCoreLib, GetWorkplaneLock));
	if (!slib || !slib->GetWorkplaneLock)
		return false;

	return slib->GetWorkplaneLock(doc);
}

void WorkplaneLock(BaseDraw* bd, Int32 locked)
{
	SnapCoreLib* slib = CheckSnapLib(LIBOFFSET(SnapCoreLib, SetWorkplaneLock));
	if (!slib || !slib->SetWorkplaneLock)
		return;

	slib->SetWorkplaneLock(bd, locked);
}

Matrix GetWorkplaneMatrix(BaseDocument* doc, BaseDraw* bd)
{
	SnapCoreLib* slib = CheckSnapLib(LIBOFFSET(SnapCoreLib, GetWorkplaneMatrix));
	if (!slib || !slib->GetWorkplaneMatrix)
		return Matrix();

	return slib->GetWorkplaneMatrix(doc, bd);
}

//////////////////////////////////////////////////////////////////////////
// ! Internal Snap Registration
static Bool GeRegisterSnapModePlugin(Int32 id, const maxon::String& str, BaseBitmap* icon, const maxon::String& help, Int32 parent, SNAPPLUGIN& np, Int32 flags)
{
	SnapCoreLib* slib = CheckSnapLib(LIBOFFSET(SnapCoreLib, GeRegisterSnapModePlugin));
	if (!slib || !slib->GeRegisterSnapModePlugin)
		return false;

	return slib->GeRegisterSnapModePlugin(id, str, icon, help, parent, np, flags);
}

//////////////////////////////////////////////////////////////////////////
// ! SnapData registration
// !
static void FillSnapPlugin(SNAPPLUGIN* np, SnapDataAllocator* npalloc, Int32 info, BaseBitmap* icon, Int32 parent_mode, SNAPPRIORITY priority, const maxon::String& help)
{
	np->adr	= nullptr;
	np->Allocator	 = npalloc;
	np->Destructor = &SnapData::Destructor;

	np->Init = &SnapData::Init;
	np->Free = &SnapData::Free;
	np->InitSnap = &SnapData::InitSnap;
	np->Snap = &SnapData::Snap;
	np->Intersect	= &SnapData::Intersect;
	np->FreeSnap	= &SnapData::FreeSnap;
	np->Draw = &SnapData::Draw;
	np->GetCursorInfo	= &SnapData::GetCursorInfo;
	np->MouseInput = &SnapData::MouseInput;
	np->KeyboardInput	= &SnapData::KeyboardInput;

	np->command_icon = icon;
	np->parent_mode	 = parent_mode;
	np->priority = priority;
	np->help = (String*)&help;
	np->info = info;
}

Bool RegisterSnapPlugin(Int32 id, const maxon::String& str, const maxon::String& help, Int32 snapinfo, SnapDataAllocator* npalloc, BaseBitmap* icon, SNAPPRIORITY priority, Int32 parent_mode)
{
	SNAPPLUGIN np;
	ClearMem(&np, sizeof(np));
	FillSnapPlugin(&np, npalloc, snapinfo, icon, parent_mode, priority, help);

	return GeRegisterSnapModePlugin(id, str, icon, help, parent_mode, np, snapinfo);
}

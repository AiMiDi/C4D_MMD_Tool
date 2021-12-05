#ifdef __API_INTERN__
	#error "Not in the kernel"
#endif

/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) 1989-2006 MAXON Computer GmbH, all rights reserved  //
/////////////////////////////////////////////////////////////

//----------------------------------------------------
// Falloff controller system
#include "c4d_falloffplugin.h"
#include "c4d_resource.h"
#include "c4d_general.h"

//------------------------------------------
// FalloffData
Bool FalloffData::Init(FalloffDataData& falldata, BaseContainer* bc) { return true; }
Bool FalloffData::InitFalloff(BaseContainer* bc, FalloffDataData& falldata)	{	return true; }
void FalloffData::Sample(const Vector& p, const FalloffDataData& data, Float* res)	{	(*res) = 1.0;	}
void FalloffData::FreeFalloff(FalloffDataData& falldata)	{ }
Bool FalloffData::CheckDirty(BaseContainer* bc)	{	return false;	}
Bool FalloffData::GetDVisible(DescID& id, BaseContainer* bc, BaseContainer* desc_bc)	{	return true; }
Int32 FalloffData::GetHandleCount(BaseContainer* bc, const FalloffDataData& data)	{	return 0;	}
void FalloffData::GetHandle(BaseContainer* bc, Int32 i, HandleInfo& info, const FalloffDataData& data)	{	}
void FalloffData::SetHandle(BaseContainer* bc, Int32 i, Vector p, const FalloffDataData& data)	{	}
DRAWRESULT FalloffData::Draw(const FalloffDataData& data, DRAWPASS drawpass, BaseDraw* bd, BaseDrawHelp* bh)	{	return DRAWRESULT::OK; }
Bool FalloffData::Message(Int32 type, BaseContainer* bc, void* m_data) { return true; }

//-------------------------------------------
// FalloffContol

FalloffControlLib* falloff_libcache = nullptr;

static FalloffControlLib* CheckFalloffLib(Int32 offset)
{
	return (FalloffControlLib*)CheckLib(ID_C4DFALLOFFLIB, offset, (C4DLibrary**)&falloff_libcache);
}

BaseContainer* C4D_Falloff::GetContainerInstance(void)
{
	FalloffControlLib* flib = CheckFalloffLib(LIBOFFSET(FalloffControlLib, GetContainerInstance));
	if (!flib || !flib->GetContainerInstance)
		return nullptr;

	return (((iC4D_Falloff*)this)->*(flib->GetContainerInstance))();
}

void C4D_Falloff::SetDirty(void)
{
	FalloffControlLib* flib = CheckFalloffLib(LIBOFFSET(FalloffControlLib, SetDirty));
	if (!flib || !flib->SetDirty)
		return;

	(((iC4D_Falloff*)this)->*(flib->SetDirty))();
}

Int32 C4D_Falloff::GetDirty(BaseDocument* doc, BaseContainer* bc)
{
	FalloffControlLib* flib = CheckFalloffLib(LIBOFFSET(FalloffControlLib, GetDirty));
	if (!flib || !flib->GetDirty)
		return 0;

	return (((iC4D_Falloff*)this)->*(flib->GetDirty))(doc, bc);
}

Int32	C4D_Falloff::GetHandleCount(BaseContainer* bc)
{
	FalloffControlLib* flib = CheckFalloffLib(LIBOFFSET(FalloffControlLib, GetHandleCount));
	if (!flib || !flib->GetHandleCount)
		return 0;

	return (((iC4D_Falloff*)this)->*(flib->GetHandleCount))(bc);
}

void C4D_Falloff::GetHandle(Int32 i, BaseContainer* bc, HandleInfo& info)
{
	FalloffControlLib* flib = CheckFalloffLib(LIBOFFSET(FalloffControlLib, GetHandle));
	if (!flib || !flib->GetHandle)
		return;

	(((iC4D_Falloff*)this)->*(flib->GetHandle))(i, bc, info);
}

void C4D_Falloff::SetHandle(Int32 i, Vector p, BaseContainer* bc, const HandleInfo& info)
{
	FalloffControlLib* flib = CheckFalloffLib(LIBOFFSET(FalloffControlLib, SetHandle));
	if (!flib || !flib->SetHandle)
		return;

	(((iC4D_Falloff*)this)->*(flib->SetHandle))(i, p, bc, info);
}

void C4D_Falloff::SetMg(Matrix mg)
{
	FalloffControlLib* flib = CheckFalloffLib(LIBOFFSET(FalloffControlLib, SetMg));
	if (!flib || !flib->SetMg)
		return;

	(((iC4D_Falloff*)this)->*(flib->SetMg))(mg);
}

Matrix C4D_Falloff::GetMg(void)
{
	FalloffControlLib* flib = CheckFalloffLib(LIBOFFSET(FalloffControlLib, GetMg));
	if (!flib || !flib->GetMg)
		return Matrix();

	return (((iC4D_Falloff*)this)->*(flib->GetMg))();
}

void C4D_Falloff::SetData(FalloffDataData falldata)
{
	FalloffControlLib* flib = CheckFalloffLib(LIBOFFSET(FalloffControlLib, SetData));
	if (!flib || !flib->SetData)
		return;

	(((iC4D_Falloff*)this)->*(flib->SetData))(falldata);
}

FalloffDataData	C4D_Falloff::GetData(void)
{
	FalloffControlLib* flib = CheckFalloffLib(LIBOFFSET(FalloffControlLib, GetData));
	if (!flib || !flib->GetData)
		return FalloffDataData();

	return (((iC4D_Falloff*)this)->*(flib->GetData))();
}

Bool C4D_Falloff::SetMode(Int32 type, BaseContainer* bc)
{
	FalloffControlLib* flib = CheckFalloffLib(LIBOFFSET(FalloffControlLib, SetMode));
	if (!flib || !flib->SetMode)
		return false;

	return (((iC4D_Falloff*)this)->*(flib->SetMode))(type, bc);
}

Int32	C4D_Falloff::GetMode(void)
{
	FalloffControlLib* flib = CheckFalloffLib(LIBOFFSET(FalloffControlLib, GetMode));
	if (!flib || !flib->GetMode)
		return 0;

	return (((iC4D_Falloff*)this)->*(flib->GetMode))();
}

void C4D_Falloff::SetTime(BaseTime time, BaseContainer* bc)
{
	FalloffControlLib* flib = CheckFalloffLib(LIBOFFSET(FalloffControlLib, SetTime));
	if (!flib || !flib->SetTime)
		return;

	(((iC4D_Falloff*)this)->*(flib->SetTime))(time, bc);
}

Bool C4D_Falloff::InitFalloff(BaseContainer* bc, BaseDocument* doc, BaseObject* op)
{
	FalloffControlLib* flib = CheckFalloffLib(LIBOFFSET(FalloffControlLib, InitFalloff));
	if (!flib || !flib->InitFalloff)
		return false;

	return (((iC4D_Falloff*)this)->*(flib->InitFalloff))(bc, doc, op);
}

Bool C4D_Falloff::AddFalloffToDescription(Description* description, BaseContainer* bc, DESCFLAGS_DESC flags, Bool showValue, Bool showColor, Bool showDirection, Bool showRotation)
{
	FalloffControlLib* flib = CheckFalloffLib(LIBOFFSET(FalloffControlLib, AddFalloffToDescription));
	if (!flib || !flib->AddFalloffToDescription)
		return false;

	return (((iC4D_Falloff*)this)->*(flib->AddFalloffToDescription))(description, bc, flags, showValue, showColor, showDirection, showRotation);
}

Bool C4D_Falloff::GetDEnabling(const DescID& id, const BaseContainer& bc, Bool& enabled)
{
	FalloffControlLib* flib = CheckFalloffLib(LIBOFFSET(FalloffControlLib, GetDEnabling));
	if (!flib || !flib->AddFalloffToDescription)
		return false;

	return (((iC4D_Falloff*)this)->*(flib->GetDEnabling))(id, bc, enabled);
}

Bool C4D_Falloff::Message(Int32 id, BaseContainer* bc, void* m_data)
{
	FalloffControlLib* flib = CheckFalloffLib(LIBOFFSET(FalloffControlLib, Message));
	if (!flib || !flib->Message)
		return false;

	return (((iC4D_Falloff*)this)->*(flib->Message))(id, bc, m_data);
}

Bool C4D_Falloff::Draw(BaseDraw* bd, BaseDrawHelp* bh, DRAWPASS drawpass, BaseContainer* bc)
{
	FalloffControlLib* flib = CheckFalloffLib(LIBOFFSET(FalloffControlLib, Draw));
	if (!flib || !flib->Draw)
		return false;

	return (((iC4D_Falloff*)this)->*(flib->Draw))(bd, bh, drawpass, bc) == DRAWRESULT::OK;
}

Bool C4D_Falloff::PreSample(BaseDocument* doc, BaseList2D* op, const FieldInput& inputs, FIELDSAMPLE_FLAG flags)
{
	FalloffControlLib* flib = CheckFalloffLib(LIBOFFSET(FalloffControlLib, PreSample));
	if (!flib || !flib->PreSample)
		return false;

	return (((iC4D_Falloff*)this)->*(flib->PreSample))(doc, op, inputs, flags);
}

const FieldOutput* C4D_Falloff::GetSamples()
{
	FalloffControlLib* flib = CheckFalloffLib(LIBOFFSET(FalloffControlLib, GetSamples));
	if (!flib || !flib->GetSamples)
		return nullptr;

	return (((iC4D_Falloff*)this)->*(flib->GetSamples))();
}

void C4D_Falloff::Sample(const Vector& p, Float* result, Bool usespline, Float weight, BaseList2D* op, Int index)
{
	FalloffControlLib* flib = CheckFalloffLib(LIBOFFSET(FalloffControlLib, Sample));
	if (!flib || !flib->Sample)
		return;

	(((iC4D_Falloff*)this)->*(flib->Sample))(p, result, usespline, weight, op, index);
}

void C4D_Falloff::MultiSample(const Vector* p, Float* result, Int count, Bool usespline, Float weight, BaseList2D* op)
{
	FalloffControlLib* flib = CheckFalloffLib(LIBOFFSET(FalloffControlLib, MultiSample));
	if (!flib || !flib->MultiSample)
		return;

	(((iC4D_Falloff*)this)->*(flib->MultiSample))(p, result, count, usespline, weight, op);
}

Bool C4D_Falloff::HasContent(BaseContainer* bc) const
{
	FalloffControlLib* flib = CheckFalloffLib(LIBOFFSET(FalloffControlLib, HasContent));
	if (!flib || !flib->HasContent)
		return false;

	return (((iC4D_Falloff*)this)->*(flib->HasContent))(bc);
}


C4D_Falloff*	C4D_Falloff::Alloc(Int cType/* = 0*/)
{
	FalloffControlLib* flib = CheckFalloffLib(LIBOFFSET(FalloffControlLib, Alloc));
	if (!flib || !flib->Alloc)
		return nullptr;

	return (C4D_Falloff*)flib->Alloc(cType);
}

Bool C4D_Falloff::CopyTo(C4D_Falloff* dest) const
{
	FalloffControlLib* flib = CheckFalloffLib(LIBOFFSET(FalloffControlLib, CopyTo));
	if (!flib || !flib->CopyTo)
		return false;

	iC4D_Falloff* temp = (iC4D_Falloff*)dest;
	if (!temp)
		return false;
	return (((iC4D_Falloff*)this)->*(flib->CopyTo))(temp);
}

void C4D_Falloff::Free(C4D_Falloff*& node)
{
	FalloffControlLib* flib = CheckFalloffLib(LIBOFFSET(FalloffControlLib, Free));
	if (!flib || !flib->Free)
		return;

	iC4D_Falloff* tmp = (iC4D_Falloff*)node;
	flib->Free(tmp);
	node = nullptr;
}

Bool C4D_Falloff::IsFields() const
{
	FalloffControlLib* flib = CheckFalloffLib(LIBOFFSET(FalloffControlLib, IsFields));
	if (!flib || !flib->IsFields)
		return false;

	return (((iC4D_Falloff*)this)->*(flib->IsFields))();
}

FIELDLIST_FLAGS C4D_Falloff::GetChannelFlags() const
{
	FalloffControlLib* flib = CheckFalloffLib(LIBOFFSET(FalloffControlLib, GetChannelFlags));
	if (!flib || !flib->GetChannelFlags)
		return FIELDLIST_FLAGS::NONE;

	return (((iC4D_Falloff*)this)->*(flib->GetChannelFlags))();

}
void C4D_Falloff::SetChannelFlags(FIELDLIST_FLAGS flags, BaseContainer* bc)
{
	FalloffControlLib* flib = CheckFalloffLib(LIBOFFSET(FalloffControlLib, SetChannelFlags));
	if (!flib || !flib->SetChannelFlags)
		return;

	(((iC4D_Falloff*)this)->*(flib->SetChannelFlags))(flags, bc);

}

//-----------------------------------
// Registration

void FillFalloffPlugin(FALLOFFPLUGIN* fp, Int32 info, FalloffDataAllocator* g)
{
	fp->allocator	= g;
	fp->adr	= g();

	fp->Destructor = &FalloffData::Destructor;

	fp->Init = &FalloffData::Init;
	fp->InitFalloff	= &FalloffData::InitFalloff;
	fp->Sample = &FalloffData::Sample;
	fp->FreeFalloff	= &FalloffData::FreeFalloff;
	fp->CheckDirty	= &FalloffData::CheckDirty;
	fp->Message	= &FalloffData::Message;
	fp->GetDVisible	= &FalloffData::GetDVisible;
	fp->GetHandleCount = &FalloffData::GetHandleCount;
	fp->GetHandle	= &FalloffData::GetHandle;
	fp->SetHandle	= &FalloffData::SetHandle;
	fp->Draw = &FalloffData::Draw;
	fp->info = info;
}

Bool RegisterFalloffPlugin(Int32 id, const maxon::String& str, Int32 info, FalloffDataAllocator* g, const maxon::String& description)
{
	if (description.IsPopulated() && !RegisterDescription(id, description))
		return false;

	FALLOFFPLUGIN fp;
	ClearMem(&fp, sizeof(fp));

	FillFalloffPlugin(&fp, info, g);
	return GeRegisterPlugin(PLUGINTYPE::FALLOFF, id, str, &fp, sizeof(fp));	// shoudl be used in the newer versions of cinema
}

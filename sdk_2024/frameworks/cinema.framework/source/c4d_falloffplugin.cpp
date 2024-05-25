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
#include "c4d_accessedobjects.h"

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_BEGIN
#endif

inline Vector SwapPointToWorld(const Int32 axis, const Vector& p)
{
	switch (axis)
	{
		case 1:
			return Vector(p.y, -p.x, p.z);
			break;
		case 0:
			return Vector(-p.y, p.x, p.z);
			break;
		case 2:
			return Vector(-p.x, -p.y, p.z);
			break;
		case 5:
			return Vector(p.x, -p.z, p.y);
			break;
		case 4:
			return Vector(p.x, p.z, -p.y);
			break;
		default: break;
	}
	return p;
}

Bool FalloffDataData::SetMg(const Matrix& mg, Bool force)
{
	if (!force && _nodemat == mg)
		return false;
	_nodemat = mg;
	_inverseNodeMat = ~mg;
	_mat = mg;
	_mat.off += _mat.sqmat * _offset;
	_mat.sqmat.v1 = _mat.sqmat.v1 * _scale * _size.x;
	_mat.sqmat.v2 = _mat.sqmat.v2 * _scale * _size.y;
	_mat.sqmat.v3 = _mat.sqmat.v3 * _scale * _size.z;
	_mat = _mat * Matrix(Vector(), SwapPointToWorld(_axis, Vector(1, 0, 0)), SwapPointToWorld(_axis, Vector(0, 1, 0)),
																	 SwapPointToWorld(_axis, Vector(0, 0, 1)));
	_imat = ~_mat;
	return true;
}

//------------------------------------------
// FalloffData
Bool FalloffData::Init(BaseContainer* bc) { return true; }
Bool FalloffData::InitFalloff(const BaseDocument* doc, const BaseContainer* bc, FalloffDataData& falldata) const	{	return true; }
void FalloffData::Sample(const Vector& p, const FalloffDataData& data, Float* res) const { (*res) = 1.0; }
Bool FalloffData::CheckDirty(const BaseDocument* doc, const BaseContainer* bc) { return false; }
Bool FalloffData::GetDVisible(const DescID& id, const BaseContainer* bc, BaseContainer* desc_bc) const { return true; }
Int32 FalloffData::GetHandleCount(BaseContainer* bc, const FalloffDataData& data)	{	return 0;	}
void FalloffData::GetHandle(BaseContainer* bc, Int32 i, HandleInfo& info, const FalloffDataData& data)	{	}
void FalloffData::SetHandle(BaseContainer* bc, Int32 i, Vector p, const FalloffDataData& data)	{	}
DRAWRESULT FalloffData::Draw(const FalloffDataData& data, DRAWPASS drawpass, BaseDraw* bd, BaseDrawHelp* bh)	{	return DRAWRESULT::OK; }
Bool FalloffData::Message(Int32 type, BaseContainer* bc, void* m_data) { return true; }
maxon::Result<Bool> FalloffData::GetAccessedObjects(const BaseList2D* op, METHOD_ID method, AccessedObjectsCallback& access) const { return access.MayAccessAnything(); }

//-------------------------------------------
// FalloffContol

FalloffControlLib* falloff_libcache = nullptr;

static FalloffControlLib* CheckFalloffLib(Int32 offset)
{
	return CheckLib<FalloffControlLib>(ID_C4DFALLOFFLIB, offset, falloff_libcache);
}

BaseContainer* C4D_Falloff::GetContainerInstance()
{
	FalloffControlLib* flib = CheckFalloffLib(LIBOFFSET(FalloffControlLib, GetContainerInstance));
	if (!flib || !flib->GetContainerInstance)
		return nullptr;

	return (reinterpret_cast<iC4D_Falloff*>(this)->*(flib->GetContainerInstance))();
}

void C4D_Falloff::SetDirty()
{
	FalloffControlLib* flib = CheckFalloffLib(LIBOFFSET(FalloffControlLib, SetDirty));
	if (!flib || !flib->SetDirty)
		return;

	(reinterpret_cast<iC4D_Falloff*>(this)->*(flib->SetDirty))();
}

Int32 C4D_Falloff::GetDirty(BaseList2D* op, const BaseDocument* doc)
{
	FalloffControlLib* flib = CheckFalloffLib(LIBOFFSET(FalloffControlLib, GetDirty));
	if (!flib || !flib->GetDirty)
		return 0;

	return (reinterpret_cast<iC4D_Falloff*>(this)->*(flib->GetDirty))(op, doc);
}

Int32	C4D_Falloff::GetHandleCount() const
{
	FalloffControlLib* flib = CheckFalloffLib(LIBOFFSET(FalloffControlLib, GetHandleCount));
	if (!flib || !flib->GetHandleCount)
		return 0;

	return (reinterpret_cast<const iC4D_Falloff*>(this)->*(flib->GetHandleCount))();
}

void C4D_Falloff::GetHandle(Int32 i, HandleInfo& info) const
{
	FalloffControlLib* flib = CheckFalloffLib(LIBOFFSET(FalloffControlLib, GetHandle));
	if (!flib || !flib->GetHandle)
		return;

	(reinterpret_cast<const iC4D_Falloff*>(this)->*(flib->GetHandle))(i, info);
}

void C4D_Falloff::SetHandle(Int32 i, Vector p, const HandleInfo& info)
{
	FalloffControlLib* flib = CheckFalloffLib(LIBOFFSET(FalloffControlLib, SetHandle));
	if (!flib || !flib->SetHandle)
		return;

	(reinterpret_cast<iC4D_Falloff*>(this)->*(flib->SetHandle))(i, p, info);
}

void C4D_Falloff::SetMg(const Matrix& mg)
{
	FalloffControlLib* flib = CheckFalloffLib(LIBOFFSET(FalloffControlLib, SetMg));
	if (!flib || !flib->SetMg)
		return;

	(reinterpret_cast<iC4D_Falloff*>(this)->*(flib->SetMg))(mg);
}

const Matrix& C4D_Falloff::GetMg() const
{
	FalloffControlLib* flib = CheckFalloffLib(LIBOFFSET(FalloffControlLib, GetMg));
	if (!flib || !flib->GetMg)
		return maxon::DefaultValue<const Matrix&>();

	return (reinterpret_cast<const iC4D_Falloff*>(this)->*(flib->GetMg))();
}
/*
void C4D_Falloff::SetData(FalloffDataData falldata)
{
	FalloffControlLib* flib = CheckFalloffLib(LIBOFFSET(FalloffControlLib, SetData));
	if (!flib || !flib->SetData)
		return;

	(reinterpret_cast<iC4D_Falloff*>(this)->*(flib->SetData))(falldata);
}

const FalloffDataData& C4D_Falloff::GetData() const
{
	FalloffControlLib* flib = CheckFalloffLib(LIBOFFSET(FalloffControlLib, GetData));
	if (!flib || !flib->GetData)
		return maxon::DefaultValue<const FalloffDataData&>();

	return (reinterpret_cast<iC4D_Falloff*>(this)->*(flib->GetData))();
}
*/
Bool C4D_Falloff::SetMode(Int32 type)
{
	FalloffControlLib* flib = CheckFalloffLib(LIBOFFSET(FalloffControlLib, SetMode));
	if (!flib || !flib->SetMode)
		return false;

	return (reinterpret_cast<iC4D_Falloff*>(this)->*(flib->SetMode))(type);
}

Int32	C4D_Falloff::GetMode() const
{
	FalloffControlLib* flib = CheckFalloffLib(LIBOFFSET(FalloffControlLib, GetMode));
	if (!flib || !flib->GetMode)
		return 0;

	return (reinterpret_cast<const iC4D_Falloff*>(this)->*(flib->GetMode))();
}

void C4D_Falloff::SetTime(BaseTime time)
{
	FalloffControlLib* flib = CheckFalloffLib(LIBOFFSET(FalloffControlLib, SetTime));
	if (!flib || !flib->SetTime)
		return;

	(reinterpret_cast<iC4D_Falloff*>(this)->*(flib->SetTime))(time);
}

Bool C4D_Falloff::InitFalloff(BaseDocument* doc, BaseObject* op)
{
	FalloffControlLib* flib = CheckFalloffLib(LIBOFFSET(FalloffControlLib, InitFalloff));
	if (!flib || !flib->InitFalloff)
		return false;

	return (reinterpret_cast<iC4D_Falloff*>(this)->*(flib->InitFalloff))(doc, op);
}

Bool C4D_Falloff::InitFalloff(const BaseDocument* doc, const BaseObject* op, FalloffDataData& data) const
{
	FalloffControlLib* flib = CheckFalloffLib(LIBOFFSET(FalloffControlLib, InitFalloff2));
	if (!flib || !flib->InitFalloff)
		return false;

	return (reinterpret_cast<const iC4D_Falloff*>(this)->*(flib->InitFalloff2))(doc, op, data);
}

Bool C4D_Falloff::AddFalloffToDescription(const BaseList2D* op, Description* description, DESCFLAGS_DESC flags, Bool showValue, Bool showColor, Bool showDirection, Bool showRotation) const
{
	FalloffControlLib* flib = CheckFalloffLib(LIBOFFSET(FalloffControlLib, AddFalloffToDescription));
	if (!flib || !flib->AddFalloffToDescription)
		return false;

	return (reinterpret_cast<const iC4D_Falloff*>(this)->*(flib->AddFalloffToDescription))(op, description, flags, showValue, showColor, showDirection, showRotation);
}

Bool C4D_Falloff::GetDEnabling(const DescID& id, Bool& enabled) const
{
	FalloffControlLib* flib = CheckFalloffLib(LIBOFFSET(FalloffControlLib, GetDEnabling));
	if (!flib || !flib->AddFalloffToDescription)
		return false;

	return (reinterpret_cast<const iC4D_Falloff*>(this)->*(flib->GetDEnabling))(id, enabled);
}

Bool C4D_Falloff::Message(BaseList2D* op, Int32 id, void* m_data)
{
	FalloffControlLib* flib = CheckFalloffLib(LIBOFFSET(FalloffControlLib, Message));
	if (!flib || !flib->Message)
		return false;

	return (reinterpret_cast<iC4D_Falloff*>(this)->*(flib->Message))(op, id, m_data);
}

Bool C4D_Falloff::Draw(BaseList2D* op, BaseDraw* bd, BaseDrawHelp* bh, DRAWPASS drawpass)
{
	FalloffControlLib* flib = CheckFalloffLib(LIBOFFSET(FalloffControlLib, Draw));
	if (!flib || !flib->Draw)
		return false;

	return (reinterpret_cast<iC4D_Falloff*>(this)->*(flib->Draw))(op, bd, bh, drawpass) == DRAWRESULT::OK;
}

Bool C4D_Falloff::PreSample(const BaseList2D* op, const BaseDocument* doc, const FieldInput& inputs, FieldOutput& result, const FalloffDataData& data, FIELDSAMPLE_FLAG flags) const
{
	FalloffControlLib* flib = CheckFalloffLib(LIBOFFSET(FalloffControlLib, PreSample));
	if (!flib || !flib->PreSample)
		return false;

	return (reinterpret_cast<const iC4D_Falloff*>(this)->*(flib->PreSample))(op, doc, inputs, result, data, flags);
}

void C4D_Falloff::Sample(const BaseList2D* op, const Vector& p, Float* result, const FieldOutput* fieldSamples, const FalloffDataData& data, Bool usespline, Float weight, Int index) const
{
	FalloffControlLib* flib = CheckFalloffLib(LIBOFFSET(FalloffControlLib, Sample));
	if (!flib || !flib->Sample)
		return;

	(((iC4D_Falloff*)this)->*(flib->Sample))(op, p, result, fieldSamples, data, usespline, weight, index);
}

void C4D_Falloff::MultiSample(const BaseList2D* op, const Vector* p, Float* result, Int count, const FalloffDataData& data, Bool usespline, Float weight) const
{
	FalloffControlLib* flib = CheckFalloffLib(LIBOFFSET(FalloffControlLib, MultiSample));
	if (!flib || !flib->MultiSample)
		return;

	(((iC4D_Falloff*)this)->*(flib->MultiSample))(op, p, result, count, data, usespline, weight);
}

Bool C4D_Falloff::HasContent() const
{
	FalloffControlLib* flib = CheckFalloffLib(LIBOFFSET(FalloffControlLib, HasContent));
	if (!flib || !flib->HasContent)
		return false;

	return (reinterpret_cast<const iC4D_Falloff*>(this)->*(flib->HasContent))();
}


C4D_Falloff* C4D_Falloff::Alloc(BaseContainer* parentBc, Int cType /* = 0*/)
{
	FalloffControlLib* flib = CheckFalloffLib(LIBOFFSET(FalloffControlLib, Alloc));
	if (!flib || !flib->Alloc)
		return nullptr;

	return (C4D_Falloff*)flib->Alloc(parentBc, cType);
}

Bool C4D_Falloff::CopyTo(C4D_Falloff* dest, BaseList2D* destObj) const
{
	FalloffControlLib* flib = CheckFalloffLib(LIBOFFSET(FalloffControlLib, CopyTo));
	if (!flib || !flib->CopyTo)
		return false;

	iC4D_Falloff* temp = (iC4D_Falloff*)dest;
	if (!temp)
		return false;
	return (reinterpret_cast<const iC4D_Falloff*>(this)->*(flib->CopyTo))(temp, destObj);
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

	return (reinterpret_cast<const iC4D_Falloff*>(this)->*(flib->IsFields))();
}

FIELDLIST_FLAGS C4D_Falloff::GetChannelFlags() const
{
	FalloffControlLib* flib = CheckFalloffLib(LIBOFFSET(FalloffControlLib, GetChannelFlags));
	if (!flib || !flib->GetChannelFlags)
		return FIELDLIST_FLAGS::NONE;

	return (reinterpret_cast<const iC4D_Falloff*>(this)->*(flib->GetChannelFlags))();

}
void C4D_Falloff::SetChannelFlags(FIELDLIST_FLAGS flags)
{
	FalloffControlLib* flib = CheckFalloffLib(LIBOFFSET(FalloffControlLib, SetChannelFlags));
	if (!flib || !flib->SetChannelFlags)
		return;

	(reinterpret_cast<iC4D_Falloff*>(this)->*(flib->SetChannelFlags))(flags);
}

maxon::Result<Bool> C4D_Falloff::GetAccessedObjects(const BaseList2D* op, METHOD_ID method, AccessedObjectsCallback& access) const
{
	FalloffControlLib* flib = CheckFalloffLib(LIBOFFSET(FalloffControlLib, GetAccessedObjects));
	if (!flib || !flib->GetAccessedObjects)
		return access.MayAccessAnything();

	return (reinterpret_cast<const iC4D_Falloff*>(this)->*(flib->GetAccessedObjects))(op, method, access);
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
	fp->CheckDirty	= &FalloffData::CheckDirty;
	fp->Message	= &FalloffData::Message;
	fp->GetDVisible	= &FalloffData::GetDVisible;
	fp->GetHandleCount = &FalloffData::GetHandleCount;
	fp->GetHandle	= &FalloffData::GetHandle;
	fp->SetHandle	= &FalloffData::SetHandle;
	fp->Draw = &FalloffData::Draw;
	fp->GetAccessedObjects = &FalloffData::GetAccessedObjects;
	fp->infoBits = info;
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

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_END
#endif

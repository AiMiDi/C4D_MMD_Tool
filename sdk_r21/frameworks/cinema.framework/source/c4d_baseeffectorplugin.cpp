/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) 1989-2006 MAXON Computer GmbH, all rights reserved  //
/////////////////////////////////////////////////////////////

#include "c4d_baseeffectorplugin.h"
#include "c4d_resource.h"
#include "c4d_general.h"

EffectorDataLib* efflib_cache;
MoDataLib*			 modlib_cache;


static EffectorDataLib* CheckEffectorLib(Int32 offset)
{
	return (EffectorDataLib*)CheckLib(BASEEFFECTORLIB_ID, offset, (C4DLibrary**)&efflib_cache);
}

static MoDataLib* CheckMoDataLib(Int32 offset)
{
	return (MoDataLib*)CheckLib(MODATALIB_ID, offset, (C4DLibrary**)&modlib_cache);
}

Bool EffectorData::InitEffector(GeListNode* node) { return true; }
void EffectorData::FreeEffector(GeListNode* node) { }
Bool EffectorData::AddToExecution(BaseObject* op, PriorityList* list)	{ list->Add(op, EXECUTIONPRIORITY_EXPRESSION, EXECUTIONFLAGS::NONE); return true; }
Bool EffectorData::IsInstanceOf(const GeListNode* node, Int32 type) const { return type == Obaseeffector; }

Bool EffectorData::Init(GeListNode* node)
{
	EffectorDataLib* elib = CheckEffectorLib(LIBOFFSET(EffectorDataLib, Effector_Init));
	if (!elib || !elib->Effector_Init)
		return false;

	if (!elib->Effector_Init(node))
		return false;

	return InitEffector(node);
}

void EffectorData::Free(GeListNode* node)
{
	EffectorDataLib* elib = CheckEffectorLib(LIBOFFSET(EffectorDataLib, Effector_Free));
	if (!elib || !elib->Effector_Free)
		return;

	elib->Effector_Free(node);

	FreeEffector(node);
}

Int32 EffectorData::GetHandleCount(BaseObject* op)
{
	EffectorDataLib* elib = CheckEffectorLib(LIBOFFSET(EffectorDataLib, Effector_GetHandleCount));
	if (!elib || !elib->Effector_GetHandleCount)
		return 0;

	return elib->Effector_GetHandleCount(op);
}

void EffectorData::GetHandle(BaseObject* op, Int32 i, HandleInfo& info)
{
	EffectorDataLib* elib = CheckEffectorLib(LIBOFFSET(EffectorDataLib, Effector_GetHandle));
	if (!elib || !elib->Effector_GetHandle)
		return;

	elib->Effector_GetHandle(op, i, info);
}

void EffectorData::SetHandle(BaseObject* op, Int32 i, Vector p, const HandleInfo& info)
{
	EffectorDataLib* elib = CheckEffectorLib(LIBOFFSET(EffectorDataLib, Effector_SetHandle));
	if (!elib || !elib->Effector_SetHandle)
		return;

	elib->Effector_SetHandle(op, i, p, info);
}

Bool EffectorData::GetDDescription(GeListNode* node, Description* description, DESCFLAGS_DESC& flags)
{
	EffectorDataLib* elib = CheckEffectorLib(LIBOFFSET(EffectorDataLib, Effector_GetDDescription));
	if (!elib || !elib->Effector_GetDDescription)
		return false;

	Bool res = elib->Effector_GetDDescription(node, description, flags);

	if (!res)
		return false;

	return true;
}

Bool EffectorData::GetDEnabling(GeListNode *node, const DescID &id, const GeData &t_data, DESCFLAGS_ENABLE flags, const BaseContainer *itemdesc)
{
	EffectorDataLib* elib = CheckEffectorLib(LIBOFFSET(EffectorDataLib, Effector_GetDEnabling));
	if (!elib || !elib->Effector_GetDEnabling)
		return false;

	return elib->Effector_GetDEnabling(node, id, t_data, flags, itemdesc);
}

EXECUTIONRESULT EffectorData::Execute(BaseObject* op, BaseDocument* doc, BaseThread* bt, Int32 priority, EXECUTIONFLAGS flags)
{
	EffectorDataLib* elib = CheckEffectorLib(LIBOFFSET(EffectorDataLib, Effector_Execute));
	if (!elib || !elib->Effector_Execute)
		return EXECUTIONRESULT::OUTOFMEMORY;

	return elib->Effector_Execute(op, doc, bt, priority, flags);
}

Bool EffectorData::ExecuteEffector(BaseObject* op, BaseDocument* doc, BaseObject* gen, MoData* md, Float strength, BaseThread* thread)
{
	EffectorDataLib* elib = CheckEffectorLib(LIBOFFSET(EffectorDataLib, Effector_ExecuteEffector));
	if (!elib || !elib->Effector_ExecuteEffector)
		return false;

	return elib->Effector_ExecuteEffector(op, doc, gen, md, strength, thread);
}

void EffectorData::ModifyPoints(BaseObject* op, BaseObject* gen, BaseDocument* doc, EffectorDataStruct* data, MoData* md, BaseThread* thread)
{
	EffectorDataLib* elib = CheckEffectorLib(LIBOFFSET(EffectorDataLib, Effector_ModifyPoints));
	if (!elib || !elib->Effector_ModifyPoints)
		return;

	iferr (elib->Effector_ModifyPoints(op, gen, doc, data, md, thread))
	{
		err.DiagOutput();
	}
}

Bool EffectorData::ModifyObject(BaseObject* mod, BaseDocument* doc, BaseObject* op, const Matrix& op_mg, const Matrix& mod_mg, Float lod, Int32 flags, BaseThread* thread)
{
	EffectorDataLib* elib = CheckEffectorLib(LIBOFFSET(EffectorDataLib, Effector_ModifyObject));
	if (!elib || !elib->Effector_ModifyObject)
		return false;

	return elib->Effector_ModifyObject(mod, doc, op, op_mg, mod_mg, lod, flags, thread);
}

Bool EffectorData::Message(GeListNode* node, Int32 type, void* t_data)
{
	EffectorDataLib* elib = CheckEffectorLib(LIBOFFSET(EffectorDataLib, Effector_Message));
	if (!elib || !elib->Effector_Message)
		return false;

	Bool res = elib->Effector_Message(node, type, t_data);

	if (!res)
		return false;

	return ObjectData::Message(node, type, t_data);
}

void EffectorData::GetDimension(BaseObject* op, Vector* mp, Vector* rad)
{
	EffectorDataLib* elib = CheckEffectorLib(LIBOFFSET(EffectorDataLib, Effector_GetDimension));
	if (!elib || !elib->Effector_GetDimension)
		return;

	elib->Effector_GetDimension(op, mp, rad);
}

DRAWRESULT EffectorData::Draw(BaseObject* op, DRAWPASS type, BaseDraw* bd, BaseDrawHelp* bh)
{
	EffectorDataLib* elib = CheckEffectorLib(LIBOFFSET(EffectorDataLib, Effector_Draw));
	if (!elib || !elib->Effector_Draw)
		return DRAWRESULT::FAILURE;

	Bool res = elib->Effector_Draw(op, type, bd, bh);

	if (!res)
		return DRAWRESULT::FAILURE;

	return ObjectData::Draw(op, type, bd, bh);
}

Bool EffectorData::CopyTo(NodeData* dest, GeListNode* snode, GeListNode* dnode, COPYFLAGS flags, AliasTrans* trn)
{
	EffectorDataLib* elib = CheckEffectorLib(LIBOFFSET(EffectorDataLib, Effector_CopyTo));
	if (!elib || !elib->Effector_CopyTo)
		return false;

	if (!elib->Effector_CopyTo(dest, snode, dnode, flags, trn))
		return false;

	return ObjectData::CopyTo(dest, snode, dnode, flags, trn);
}

void EffectorData::AddEffectorDependence(BaseObject* op)
{
	EffectorDataLib* elib = CheckEffectorLib(LIBOFFSET(EffectorDataLib, Effector_AddEffectorDependence));
	if (!elib || !elib->Effector_AddEffectorDependence)
		return;

	elib->Effector_AddEffectorDependence(this->Get(), op);
}

EffectorDataStruct* EffectorData::GetEffectorData(void)
{
	EffectorDataLib* elib = CheckEffectorLib(LIBOFFSET(EffectorDataLib, Effector_GetEffectorData));
	if (!elib || !elib->Effector_GetEffectorData)
		return nullptr;

	return elib->Effector_GetEffectorData(this->Get());
}

C4D_Falloff* EffectorData::GetFalloff(void)
{
	EffectorDataLib* elib = CheckEffectorLib(LIBOFFSET(EffectorDataLib, Effector_GetFalloff));
	if (!elib || !elib->Effector_GetFalloff)
		return nullptr;

	return elib->Effector_GetFalloff(this->Get());
}

FieldOutput*	EffectorData::CalcFields(BaseDocument* doc, BaseObject* generatorObject, MoData* md, FIELDSAMPLE_FLAG flags)
{
	EffectorDataLib* elib = CheckEffectorLib(LIBOFFSET(EffectorDataLib, Effector_GetFieldResult));
	if (!elib || !elib->Effector_GetFieldResult)
		return nullptr;

	return elib->Effector_GetFieldResult(this->Get(), doc, generatorObject, md, flags);
}

void EffectorData::CalcPlacebo(BaseObject* op, BaseObject* gen, BaseDocument* doc, EffectorDataStruct* data, Int32 index, MoData* md, const Vector& globalpos, Float fall_weight)
{
}

// modify data->strengths values accordingly in CalcPointValue
void EffectorData::CalcPointValue(BaseObject* op, BaseObject* gen, BaseDocument* doc, EffectorDataStruct* data, Int32 index, MoData* md, const Vector& globalpos, Float fall_weight)
{
}

// called seperately as it may not be needed (and therefore sometimes might reduce number of calculations
Vector EffectorData::CalcPointColor(BaseObject* op, BaseObject* gen, BaseDocument* doc, EffectorDataStruct* data, Int32 index, MoData* md, const Vector& globalpos, Float fall_weight)
{
	return Vector(1.0);
}

Int32 EffectorData::GetEffectorFlags(void)
{
	return EFFECTORFLAGS_HASFALLOFF;
}

Bool EffectorData::ModifyDDescription(GeListNode* node, Description* description, AtomArray* ar)
{
	return true;
}

void EffectorData::InitPoints(BaseObject* op, BaseObject* gen, BaseDocument* doc, EffectorDataStruct* data, MoData* md, BaseThread* thread)
{
}

void EffectorData::FreePoints(void)
{
}


//---------------------------------------
// MoData

UInt32 MoData::GetDirty(MDDIRTY mask) const
{
	MoDataLib* mlib = CheckMoDataLib(LIBOFFSET(MoDataLib, GetDirty));
	if (!mlib || !mlib->GetDirty)
		return 0;

	return (((const iMoData*)this)->*(mlib->GetDirty))(mask);
}

void MoData::SetDirty(MDDIRTY mask)
{
	MoDataLib* mlib = CheckMoDataLib(LIBOFFSET(MoDataLib, SetDirty));
	if (!mlib || !mlib->SetDirty)
		return;

	(((iMoData*)this)->*(mlib->SetDirty))(mask);
}

Bool MoData::SetWithEx(const MoDataEx& md)
{
	MoDataLib* mlib = CheckMoDataLib(LIBOFFSET(MoDataLib, SetWithEx));
	if (!mlib || !mlib->SetWithEx)
		return false;

	return (((iMoData*)this)->*(mlib->SetWithEx))(md);
}

void MoData::Clear(Bool reset)
{
	MoDataLib* mlib = CheckMoDataLib(LIBOFFSET(MoDataLib, Clear));
	if (!mlib || !mlib->Clear)
		return;

	(((iMoData*)this)->*(mlib->Clear))(reset);
}

Bool MoData::Read(HyperFile* hf)
{
	MoDataLib* mlib = CheckMoDataLib(LIBOFFSET(MoDataLib, Read));
	if (!mlib || !mlib->Read)
		return false;

	return (((iMoData*)this)->*(mlib->Read))(hf);
}

Bool MoData::Write(HyperFile* hf)
{
	MoDataLib* mlib = CheckMoDataLib(LIBOFFSET(MoDataLib, Write));
	if (!mlib || !mlib->Write)
		return false;

	return (((iMoData*)this)->*(mlib->Write))(hf);
}

Int MoData::GetMemorySize(void)
{
	MoDataLib* mlib = CheckMoDataLib(LIBOFFSET(MoDataLib, GetMemorySize));
	if (!mlib || !mlib->GetMemorySize)
		return 0;

	return (((iMoData*)this)->*(mlib->GetMemorySize))();
}

Bool MoData::SetCount(Int cnt)
{
	MoDataLib* mlib = CheckMoDataLib(LIBOFFSET(MoDataLib, SetCount));
	if (!mlib || !mlib->SetCount)
		return false;

	return (((iMoData*)this)->*(mlib->SetCount))(cnt);
}

Int MoData::GetCount(void)
{
	MoDataLib* mlib = CheckMoDataLib(LIBOFFSET(MoDataLib, GetCount));
	if (!mlib || !mlib->GetCount)
		return 0;

	return (((iMoData*)this)->*(mlib->GetCount))();
}

Int32 MoData::GetArrayCount(void)
{
	MoDataLib* mlib = CheckMoDataLib(LIBOFFSET(MoDataLib, GetArrayCount));
	if (!mlib || !mlib->GetArrayCount)
		return 0;

	return (((iMoData*)this)->*(mlib->GetArrayCount))();
}

DescID MoData::GetArrayDescID(Int32 index) const
{
	MoDataLib* mlib = CheckMoDataLib(LIBOFFSET(MoDataLib, GetArrayDescID));
	if (!mlib || !mlib->GetArrayDescID)
		return DescID();

	return (((iMoData*)this)->*(mlib->GetArrayDescID))(index);
}

Int32 MoData::GetArrayID(Int32 index) const
{
	MoDataLib* mlib = CheckMoDataLib(LIBOFFSET(MoDataLib, GetArrayID));
	if (!mlib || !mlib->GetArrayID)
		return 0;

	return (((iMoData*)this)->*(mlib->GetArrayID))(index);
}

Int32 MoData::GetArrayIndexType(Int32 index)
{
	MoDataLib* mlib = CheckMoDataLib(LIBOFFSET(MoDataLib, GetArrayIndexType));
	if (!mlib || !mlib->GetArrayIndexType)
		return 0;

	return (((iMoData*)this)->*(mlib->GetArrayIndexType))(index);
}

Int32 MoData::GetArrayType(Int32 id)
{
	MoDataLib* mlib = CheckMoDataLib(LIBOFFSET(MoDataLib, GetArrayType));
	if (!mlib || !mlib->GetArrayType)
		return 0;

	return (((iMoData*)this)->*(mlib->GetArrayType))(id);
}

Int MoData::GetArrayIndex(const DescID& id)
{
	MoDataLib* mlib = CheckMoDataLib(LIBOFFSET(MoDataLib, GetArrayIndex1));
	if (!mlib || !mlib->GetArrayIndex1)
		return 0;

	return (((iMoData*)this)->*(mlib->GetArrayIndex1))(id);
}

Int MoData::GetArrayIndex(Int32 id)
{
	MoDataLib* mlib = CheckMoDataLib(LIBOFFSET(MoDataLib, GetArrayIndex2));
	if (!mlib || !mlib->GetArrayIndex2)
		return 0;

	return (((iMoData*)this)->*(mlib->GetArrayIndex2))(id);
}

BaseContainer* MoData::GetDataInstance(const DescID& id)
{
	MoDataLib* mlib = CheckMoDataLib(LIBOFFSET(MoDataLib, GetDataInstance1));
	if (!mlib || !mlib->GetDataInstance1)
		return nullptr;

	return (((iMoData*)this)->*(mlib->GetDataInstance1))(id);
}

BaseContainer* MoData::GetDataInstance(Int32 id/*= NOTOK*/)
{
	MoDataLib* mlib = CheckMoDataLib(LIBOFFSET(MoDataLib, GetDataInstance2));
	if (!mlib || !mlib->GetDataInstance2)
		return nullptr;

	return (((iMoData*)this)->*(mlib->GetDataInstance2))(id);
}

BaseContainer* MoData::GetDataIndexInstance(Int32 index)
{
	MoDataLib* mlib = CheckMoDataLib(LIBOFFSET(MoDataLib, GetDataIndexInstance));
	if (!mlib || !mlib->GetDataIndexInstance)
		return nullptr;

	return (((iMoData*)this)->*(mlib->GetDataIndexInstance))(index);
}

BaseContainer MoData::GetData(Int32 id/*= NOTOK*/)
{
	MoDataLib* mlib = CheckMoDataLib(LIBOFFSET(MoDataLib, GetData));
	if (!mlib || !mlib->GetData)
		return BaseContainer();

	return (((iMoData*)this)->*(mlib->GetData))(id);
}

void MoData::SetData(const BaseContainer& bc, Int32 id/*= NOTOK*/)
{
	MoDataLib* mlib = CheckMoDataLib(LIBOFFSET(MoDataLib, SetData));
	if (!mlib || !mlib->SetData)
		return;

	(((iMoData*)this)->*(mlib->SetData))(bc, id);
}

static AutoLock autolock_dummy;

AutoLock& MoData::GetAutoLock(void)
{
	MoDataLib* mlib = CheckMoDataLib(LIBOFFSET(MoDataLib, GetAutoLock));
	if (!mlib || !mlib->GetAutoLock)
		return autolock_dummy;

	return (((iMoData*)this)->*(mlib->GetAutoLock))();
}

Int32 MoData::AddArray(const DescID& id, const maxon::String& name, Int32 default_flags)
{
	MoDataLib* mlib = CheckMoDataLib(LIBOFFSET(MoDataLib, AddArray1));
	if (!mlib || !mlib->AddArray1)
		return 0;

	return (((iMoData*)this)->*(mlib->AddArray1))(id, name, default_flags);
}

Int32 MoData::AddArray(Int32 id, Int32 type, const  maxon::String& name, Int32 default_flags)
{
	MoDataLib* mlib = CheckMoDataLib(LIBOFFSET(MoDataLib, AddArray2));
	if (!mlib || !mlib->AddArray2)
		return 0;

	return (((iMoData*)this)->*(mlib->AddArray2))(id, type, name, default_flags);
}

Bool MoData::RemoveArray(const DescID& id)
{
	MoDataLib* mlib = CheckMoDataLib(LIBOFFSET(MoDataLib, RemoveArray1));
	if (!mlib || !mlib->RemoveArray1)
		return false;

	return (((iMoData*)this)->*(mlib->RemoveArray1))(id);
}

Bool MoData::RemoveArray(Int32 id)
{
	MoDataLib* mlib = CheckMoDataLib(LIBOFFSET(MoDataLib, RemoveArray2));
	if (!mlib || !mlib->RemoveArray2)
		return false;

	return (((iMoData*)this)->*(mlib->RemoveArray2))(id);
}

Int32 MoData::GetFlags(const DescID& id)
{
	MoDataLib* mlib = CheckMoDataLib(LIBOFFSET(MoDataLib, GetFlags1));
	if (!mlib || !mlib->GetFlags1)
		return 0;

	return (((iMoData*)this)->*(mlib->GetFlags1))(id);
}

Int32 MoData::GetFlags(Int32 id)
{
	MoDataLib* mlib = CheckMoDataLib(LIBOFFSET(MoDataLib, GetFlags2));
	if (!mlib || !mlib->GetFlags2)
		return 0;

	return (((iMoData*)this)->*(mlib->GetFlags2))(id);
}

Int32 MoData::GetIndexFlags(Int32 index)
{
	MoDataLib* mlib = CheckMoDataLib(LIBOFFSET(MoDataLib, GetIndexFlags));
	if (!mlib || !mlib->GetIndexFlags)
		return 0;

	return (((iMoData*)this)->*(mlib->GetIndexFlags))(index);
}

void MoData::SetFlags(const DescID& id, Int32 flags)
{
	MoDataLib* mlib = CheckMoDataLib(LIBOFFSET(MoDataLib, SetFlags1));
	if (!mlib || !mlib->SetFlags1)
		return;

	(((iMoData*)this)->*(mlib->SetFlags1))(id, flags);
}

void MoData::SetFlags(Int32 id, Int32 flags)
{
	MoDataLib* mlib = CheckMoDataLib(LIBOFFSET(MoDataLib, SetFlags2));
	if (!mlib || !mlib->SetFlags2)
		return;

	(((iMoData*)this)->*(mlib->SetFlags2))(id, flags);
}

void MoData::SetIndexFlags(Int32 index, Int32 flags)
{
	MoDataLib* mlib = CheckMoDataLib(LIBOFFSET(MoDataLib, SetIndexFlags));
	if (!mlib || !mlib->SetIndexFlags)
		return;

	(((iMoData*)this)->*(mlib->SetIndexFlags))(index, flags);
}

void MoData::SetFlag(const DescID& id, Int32 flag)
{
	MoDataLib* mlib = CheckMoDataLib(LIBOFFSET(MoDataLib, SetFlag1));
	if (!mlib || !mlib->SetFlag1)
		return;

	(((iMoData*)this)->*(mlib->SetFlag1))(id, flag);
}

void MoData::SetFlag(Int32 id, Int32 flag)
{
	MoDataLib* mlib = CheckMoDataLib(LIBOFFSET(MoDataLib, SetFlag2));
	if (!mlib || !mlib->SetFlag2)
		return;

	(((iMoData*)this)->*(mlib->SetFlag2))(id, flag);
}

void MoData::SetIndexFlag(Int32 index, Int32 flag)
{
	MoDataLib* mlib = CheckMoDataLib(LIBOFFSET(MoDataLib, SetIndexFlag));
	if (!mlib || !mlib->SetIndexFlag)
		return;

	(((iMoData*)this)->*(mlib->SetIndexFlag))(index, flag);
}

void MoData::DelFlag(const DescID& id, Int32 flag)
{
	MoDataLib* mlib = CheckMoDataLib(LIBOFFSET(MoDataLib, DelFlag1));
	if (!mlib || !mlib->DelFlag1)
		return;

	(((iMoData*)this)->*(mlib->DelFlag1))(id, flag);
}

void MoData::DelFlag(Int32 id, Int32 flag)
{
	MoDataLib* mlib = CheckMoDataLib(LIBOFFSET(MoDataLib, DelFlag2));
	if (!mlib || !mlib->DelFlag2)
		return;

	(((iMoData*)this)->*(mlib->DelFlag2))(id, flag);
}

void MoData::DelIndexFlag(Int32 index, Int32 flag)
{
	MoDataLib* mlib = CheckMoDataLib(LIBOFFSET(MoDataLib, DelIndexFlag));
	if (!mlib || !mlib->DelIndexFlag)
		return;

	(((iMoData*)this)->*(mlib->DelIndexFlag))(index, flag);
}

void MoData::SetName(const DescID& id, const maxon::String& name)
{
	MoDataLib* mlib = CheckMoDataLib(LIBOFFSET(MoDataLib, SetName1));
	if (!mlib || !mlib->SetName1)
		return;

	(((iMoData*)this)->*(mlib->SetName1))(id, name);
}

void MoData::SetName(Int32 id, const maxon::String& name)
{
	MoDataLib* mlib = CheckMoDataLib(LIBOFFSET(MoDataLib, SetName2));
	if (!mlib || !mlib->SetName2)
		return;

	(((iMoData*)this)->*(mlib->SetName2))(id, name);
}

void MoData::SetIndexName(Int32 index, const maxon::String& name)
{
	MoDataLib* mlib = CheckMoDataLib(LIBOFFSET(MoDataLib, SetIndexName));
	if (!mlib || !mlib->SetIndexName)
		return;

	(((iMoData*)this)->*(mlib->SetIndexName))(index, name);
}

String MoData::GetName(const DescID& id)
{
	MoDataLib* mlib = CheckMoDataLib(LIBOFFSET(MoDataLib, GetName1));
	if (!mlib || !mlib->GetName1)
		return "";

	return (((iMoData*)this)->*(mlib->GetName1))(id);
}

String MoData::GetName(Int32 id)
{
	MoDataLib* mlib = CheckMoDataLib(LIBOFFSET(MoDataLib, GetName2));
	if (!mlib || !mlib->GetName2)
		return "";

	return (((iMoData*)this)->*(mlib->GetName2))(id);
}

String MoData::GetIndexName(Int32 index)
{
	MoDataLib* mlib = CheckMoDataLib(LIBOFFSET(MoDataLib, GetIndexName));
	if (!mlib || !mlib->GetIndexName)
		return "";

	return (((iMoData*)this)->*(mlib->GetIndexName))(index);
}

void* MoData::GetArray(const DescID& id) const
{
	MoDataLib* mlib = CheckMoDataLib(LIBOFFSET(MoDataLib, GetArray1));
	if (!mlib || !mlib->GetArray1)
		return nullptr;

	return (((iMoData*)this)->*(mlib->GetArray1))(id);
}

MDArray<Char> MoData::GetCharArray(const DescID& id, Char default_value) const
{
	MoDataLib* mlib = CheckMoDataLib(LIBOFFSET(MoDataLib, GetCharArray1));
	if (!mlib || !mlib->GetCharArray1)
		return MDArray<Char>(nullptr, 0, default_value);

	return (((iMoData*)this)->*(mlib->GetCharArray1))(id, default_value);
}

MDArray<UChar> MoData::GetUCharArray(const DescID& id, UChar default_value) const
{
	MoDataLib* mlib = CheckMoDataLib(LIBOFFSET(MoDataLib, GetUCharArray1));
	if (!mlib || !mlib->GetUCharArray1)
		return MDArray<UChar>(nullptr, 0, default_value);

	return (((iMoData*)this)->*(mlib->GetUCharArray1))(id, default_value);
}

MDArray<Int32> MoData::GetLongArray(const DescID& id, Int32 default_value) const
{
	MoDataLib* mlib = CheckMoDataLib(LIBOFFSET(MoDataLib, GetLongArray1));
	if (!mlib || !mlib->GetLongArray1)
		return MDArray<Int32>(nullptr, 0, default_value);

	return (((iMoData*)this)->*(mlib->GetLongArray1))(id, default_value);
}

MDArray<UInt32> MoData::GetULongArray(const DescID& id, UInt32 default_value) const
{
	MoDataLib* mlib = CheckMoDataLib(LIBOFFSET(MoDataLib, GetULongArray1));
	if (!mlib || !mlib->GetULongArray1)
		return MDArray<UInt32>(nullptr, 0, default_value);

	return (((iMoData*)this)->*(mlib->GetULongArray1))(id, default_value);
}

MDArray<Bool> MoData::GetBoolArray(const DescID& id, Bool default_value) const
{
	MoDataLib* mlib = CheckMoDataLib(LIBOFFSET(MoDataLib, GetBoolArray1));
	if (!mlib || !mlib->GetBoolArray1)
		return MDArray<Bool>(nullptr, 0, default_value);

	return (((iMoData*)this)->*(mlib->GetBoolArray1))(id, default_value);
}

MDArray<Int64> MoData::GetLLongArray(const DescID& id, Int64 default_value) const
{
	MoDataLib* mlib = CheckMoDataLib(LIBOFFSET(MoDataLib, GetLLongArray1));
	if (!mlib || !mlib->GetLLongArray1)
		return MDArray<Int64>(nullptr, 0, default_value);

	return (((iMoData*)this)->*(mlib->GetLLongArray1))(id, default_value);
}

MDArray<Float> MoData::GetRealArray(const DescID& id, Float default_value) const
{
	MoDataLib* mlib = CheckMoDataLib(LIBOFFSET(MoDataLib, GetRealArray1));
	if (!mlib || !mlib->GetRealArray1)
		return MDArray<Float>(nullptr, 0, default_value);

	return (((iMoData*)this)->*(mlib->GetRealArray1))(id, default_value);
}

MDArray<Matrix> MoData::GetMatrixArray(const DescID& id, Matrix default_value) const
{
	MoDataLib* mlib = CheckMoDataLib(LIBOFFSET(MoDataLib, GetMatrixArray1));
	if (!mlib || !mlib->GetMatrixArray1)
		return MDArray<Matrix>(nullptr, 0, default_value);

	return (((iMoData*)this)->*(mlib->GetMatrixArray1))(id, default_value);
}

MDArray<Vector> MoData::GetVectorArray(const DescID& id, Vector default_value) const
{
	MoDataLib* mlib = CheckMoDataLib(LIBOFFSET(MoDataLib, GetVectorArray1));
	if (!mlib || !mlib->GetVectorArray1)
		return MDArray<Vector>(nullptr, 0, default_value);

	return (((iMoData*)this)->*(mlib->GetVectorArray1))(id, default_value);
}

void* MoData::GetArray(Int32 id, MD_TYPE type) const
{
	MoDataLib* mlib = CheckMoDataLib(LIBOFFSET(MoDataLib, GetArray2));
	if (!mlib || !mlib->GetArray2)
		return nullptr;

	return (((iMoData*)this)->*(mlib->GetArray2))(id, type);
}

MDArray<Char> MoData::GetCharArray(Int32 id, Char default_value) const
{
	MoDataLib* mlib = CheckMoDataLib(LIBOFFSET(MoDataLib, GetCharArray2));
	if (!mlib || !mlib->GetCharArray2)
		return MDArray<Char>(nullptr, 0, default_value);

	return (((iMoData*)this)->*(mlib->GetCharArray2))(id, default_value);
}

MDArray<UChar> MoData::GetUCharArray(Int32 id, UChar default_value) const
{
	MoDataLib* mlib = CheckMoDataLib(LIBOFFSET(MoDataLib, GetUCharArray2));
	if (!mlib || !mlib->GetUCharArray2)
		return MDArray<UChar>(nullptr, 0, default_value);

	return (((iMoData*)this)->*(mlib->GetUCharArray2))(id, default_value);
}

MDArray<Int32> MoData::GetLongArray(Int32 id, Int32 default_value) const
{
	MoDataLib* mlib = CheckMoDataLib(LIBOFFSET(MoDataLib, GetLongArray2));
	if (!mlib || !mlib->GetLongArray2)
		return MDArray<Int32>(nullptr, 0, default_value);

	return (((iMoData*)this)->*(mlib->GetLongArray2))(id, default_value);
}

MDArray<UInt32> MoData::GetULongArray(Int32 id, UInt32 default_value) const
{
	MoDataLib* mlib = CheckMoDataLib(LIBOFFSET(MoDataLib, GetULongArray2));
	if (!mlib || !mlib->GetULongArray2)
		return MDArray<UInt32>(nullptr, 0, default_value);

	return (((iMoData*)this)->*(mlib->GetULongArray2))(id, default_value);
}

MDArray<Bool> MoData::GetBoolArray(Int32 id, Bool default_value) const
{
	MoDataLib* mlib = CheckMoDataLib(LIBOFFSET(MoDataLib, GetBoolArray2));
	if (!mlib || !mlib->GetBoolArray2)
		return MDArray<Bool>(nullptr, 0, default_value);

	return (((iMoData*)this)->*(mlib->GetBoolArray2))(id, default_value);
}

MDArray<Int64> MoData::GetLLongArray(Int32 id, Int64 default_value) const
{
	MoDataLib* mlib = CheckMoDataLib(LIBOFFSET(MoDataLib, GetLLongArray2));
	if (!mlib || !mlib->GetLLongArray2)
		return MDArray<Int64>(nullptr, 0, default_value);

	return (((iMoData*)this)->*(mlib->GetLLongArray2))(id, default_value);
}

MDArray<Float> MoData::GetRealArray(Int32 id, Float default_value) const
{
	MoDataLib* mlib = CheckMoDataLib(LIBOFFSET(MoDataLib, GetRealArray2));
	if (!mlib || !mlib->GetRealArray2)
		return MDArray<Float>(nullptr, 0, default_value);

	return (((iMoData*)this)->*(mlib->GetRealArray2))(id, default_value);
}

MDArray<Matrix> MoData::GetMatrixArray(Int32 id, Matrix default_value) const
{
	MoDataLib* mlib = CheckMoDataLib(LIBOFFSET(MoDataLib, GetMatrixArray2));
	if (!mlib || !mlib->GetMatrixArray2)
		return MDArray<Matrix>(nullptr, 0, default_value);

	return (((iMoData*)this)->*(mlib->GetMatrixArray2))(id, default_value);
}

MDArray<Vector> MoData::GetVectorArray(Int32 id, Vector default_value) const
{
	MoDataLib* mlib = CheckMoDataLib(LIBOFFSET(MoDataLib, GetVectorArray2));
	if (!mlib || !mlib->GetVectorArray2)
		return MDArray<Vector>(nullptr, 0, default_value);

	return (((iMoData*)this)->*(mlib->GetVectorArray2))(id, default_value);
}

void* MoData::GetIndexArray(Int32 index) const
{
	MoDataLib* mlib = CheckMoDataLib(LIBOFFSET(MoDataLib, GetIndexArray));
	if (!mlib || !mlib->GetIndexArray)
		return nullptr;

	return (((iMoData*)this)->*(mlib->GetIndexArray))(index);
}

MDArray<Char> MoData::GetCharIndexArray(Int32 index) const
{
	MoDataLib* mlib = CheckMoDataLib(LIBOFFSET(MoDataLib, GetCharIndexArray));
	if (!mlib || !mlib->GetCharIndexArray)
		return MDArray<Char>(nullptr, 0, Char(0));

	return (((iMoData*)this)->*(mlib->GetCharIndexArray))(index);
}

MDArray<UChar> MoData::GetUCharIndexArray(Int32 index) const
{
	MoDataLib* mlib = CheckMoDataLib(LIBOFFSET(MoDataLib, GetUCharIndexArray));
	if (!mlib || !mlib->GetUCharIndexArray)
		return MDArray<UChar>(nullptr, 0, UChar(0));

	return (((iMoData*)this)->*(mlib->GetUCharIndexArray))(index);
}

MDArray<Int32> MoData::GetLongIndexArray(Int32 index) const
{
	MoDataLib* mlib = CheckMoDataLib(LIBOFFSET(MoDataLib, GetLongIndexArray));
	if (!mlib || !mlib->GetLongIndexArray)
		return MDArray<Int32>(nullptr, 0, Int32(0));

	return (((iMoData*)this)->*(mlib->GetLongIndexArray))(index);
}

MDArray<UInt32> MoData::GetULongIndexArray(Int32 index) const
{
	MoDataLib* mlib = CheckMoDataLib(LIBOFFSET(MoDataLib, GetULongIndexArray));
	if (!mlib || !mlib->GetULongIndexArray)
		return MDArray<UInt32>(nullptr, 0, UInt32(0));

	return (((iMoData*)this)->*(mlib->GetULongIndexArray))(index);
}

MDArray<Bool> MoData::GetBoolIndexArray(Int32 index) const
{
	MoDataLib* mlib = CheckMoDataLib(LIBOFFSET(MoDataLib, GetBoolIndexArray));
	if (!mlib || !mlib->GetBoolIndexArray)
		return MDArray<Bool>(nullptr, 0, false);

	return (((iMoData*)this)->*(mlib->GetBoolIndexArray))(index);
}

MDArray<Int64> MoData::GetLLongIndexArray(Int32 index) const
{
	MoDataLib* mlib = CheckMoDataLib(LIBOFFSET(MoDataLib, GetLLongIndexArray));
	if (!mlib || !mlib->GetLLongIndexArray)
		return MDArray<Int64>(nullptr, 0, Int64(0));

	return (((iMoData*)this)->*(mlib->GetLLongIndexArray))(index);
}

MDArray<Float> MoData::GetRealIndexArray(Int32 index) const
{
	MoDataLib* mlib = CheckMoDataLib(LIBOFFSET(MoDataLib, GetRealIndexArray));
	if (!mlib || !mlib->GetRealIndexArray)
		return MDArray<Float>(nullptr, 0, 0.0);

	return (((iMoData*)this)->*(mlib->GetRealIndexArray))(index);
}

MDArray<Matrix> MoData::GetMatrixIndexArray(Int32 index) const
{
	MoDataLib* mlib = CheckMoDataLib(LIBOFFSET(MoDataLib, GetMatrixIndexArray));
	if (!mlib || !mlib->GetMatrixIndexArray)
		return MDArray<Matrix>(nullptr, 0, Matrix());

	return (((iMoData*)this)->*(mlib->GetMatrixIndexArray))(index);
}

MDArray<Vector> MoData::GetVectorIndexArray(Int32 index) const
{
	MoDataLib* mlib = CheckMoDataLib(LIBOFFSET(MoDataLib, GetVectorIndexArray));
	if (!mlib || !mlib->GetVectorIndexArray)
		return MDArray<Vector>(nullptr, 0, Vector(0.0));

	return (((iMoData*)this)->*(mlib->GetVectorIndexArray))(index);
}

Bool MoData::CopyTo(MoData* dest, Bool merge_data, Int max_count)
{
	MoDataLib* mlib = CheckMoDataLib(LIBOFFSET(MoDataLib, CopyTo));
	if (!mlib || !mlib->CopyTo)
		return false;

	iMoData* d = (iMoData*)dest;

	return (((iMoData*)this)->*(mlib->CopyTo))(d, merge_data, max_count);
}

Bool MoData::MergeData(MoData* source, Float percent)
{
	MoDataLib* mlib = CheckMoDataLib(LIBOFFSET(MoDataLib, MergeData));
	if (!mlib || !mlib->MergeData)
		return false;

	iMoData* s = (iMoData*)source;
	return (((iMoData*)this)->*(mlib->MergeData))(s, percent);
}

void MoData::Flush(void)
{
	MoDataLib* mlib = CheckMoDataLib(LIBOFFSET(MoDataLib, Flush));
	if (!mlib || !mlib->Flush)
		return;

	(((iMoData*)this)->*(mlib->Flush))();
}

void MoData::SetOffset(Int offset)
{
	MoDataLib* mlib = CheckMoDataLib(LIBOFFSET(MoDataLib, SetOffset));
	if (!mlib || !mlib->SetOffset)
		return;

	(((iMoData*)this)->*(mlib->SetOffset))(offset);
}

void MoData::SetLimit(Int limit)
{
	MoDataLib* mlib = CheckMoDataLib(LIBOFFSET(MoDataLib, SetLimit));
	if (!mlib || !mlib->SetLimit)
		return;

	(((iMoData*)this)->*(mlib->SetLimit))(limit);
}

MoData* MoData::Alloc(void)
{
	MoDataLib* mlib = CheckMoDataLib(LIBOFFSET(MoDataLib, Alloc));
	if (!mlib || !mlib->Alloc)
		return nullptr;

	return (MoData*)mlib->Alloc();
}

void MoData::Free(MoData*& d)
{
	MoDataLib* mlib = CheckMoDataLib(LIBOFFSET(MoDataLib, GetCount));
	if (!mlib || !mlib->GetCount)
		return;

	iMoData* tmp = (iMoData*)d;
	mlib->Free(tmp);
	d = nullptr;
}


//---------------------------------------
// Registration

static void FillEffectorPlugin(EFFECTORPLUGIN* np, DataAllocator* npalloc, Int32 info, Int32 disklevel, BaseBitmap* icon)
{
	FillNodePlugin(np, info, npalloc, icon, disklevel);

	np->command_icon = icon;
	np->GetDimension = &ObjectData::GetDimension;
	np->Draw = &ObjectData::Draw;
	np->DetectHandle = &ObjectData::DetectHandle;
	np->MoveHandle = &ObjectData::MoveHandle;
	np->Execute	= &ObjectData::Execute;
	np->AddToExecution	= &ObjectData::AddToExecution;
	np->GetModelingAxis	= &ObjectData::GetModelingAxis;

	np->GetEffectorData	= &EffectorData::GetEffectorData;
	np->GetFalloff = &EffectorData::GetFalloff;
	np->AddEffectorDependence = &EffectorData::AddEffectorDependence;
	np->GetEffectorFlags = &EffectorData::GetEffectorFlags;
	np->ModifyDDescription = &EffectorData::ModifyDDescription;
	np->ExecuteEffector	= &EffectorData::ExecuteEffector;
	np->InitPoints = &EffectorData::InitPoints;
	np->ModifyPoints = &EffectorData::ModifyPoints;
	np->FreePoints	= &EffectorData::FreePoints;
	np->CalcPlacebo	= &EffectorData::CalcPlacebo;
	np->CalcPointValue = &EffectorData::CalcPointValue;
	np->CalcPointColor = &EffectorData::CalcPointColor;

	np->InitEffector = &EffectorData::InitEffector;
	np->FreeEffector = &EffectorData::FreeEffector;
}

Bool RegisterEffectorPlugin(Int32 id, const maxon::String& str, Int32 objectinfo, DataAllocator* npalloc, const maxon::String& description, BaseBitmap* icon, Int32 disklevel)
{
	// only allow registration if MoGfx is present
	EffectorDataLib* elib = CheckEffectorLib(LIBOFFSET(EffectorDataLib, Effector_Init));
	if (!elib)
		return false;

	if (description.IsPopulated() && !RegisterDescription(id, description))
		return false;

	objectinfo |= OBJECT_MODIFIER;
	objectinfo |= OBJECT_CAMERADEPENDENT;

	EFFECTORPLUGIN np;
	ClearMem(&np, sizeof(np));
	FillEffectorPlugin(&np, npalloc, objectinfo, disklevel, icon);

	np.CheckDirty	= &ObjectData::CheckDirty;
	np.ModifyObject	= &ObjectData::ModifyObject;

	if (objectinfo & OBJECT_PARTICLEMODIFIER)
		np.ModifyParticles = &ObjectData::ModifyParticles;

	if (objectinfo & OBJECT_ISSPLINE)
		np.GetContour = &ObjectData::GetContour;

	if (objectinfo & OBJECT_GENERATOR)
		np.GetVirtualObjects = &ObjectData::GetVirtualObjects;

	return GeRegisterPlugin(PLUGINTYPE::OBJECT, id, str, &np, sizeof(np));
}

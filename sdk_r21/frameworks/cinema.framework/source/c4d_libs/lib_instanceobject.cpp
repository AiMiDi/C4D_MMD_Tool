#include "lib_instanceobject.h"

static InstanceObjectLibrary* instance_lib_cache = nullptr;

static InstanceObjectLibrary* CheckInstanceObjectLibrary(Int32 offset)
{
	return (InstanceObjectLibrary*)CheckLib(ID_INSTANCEOBJECT_LIB, offset, (C4DLibrary**)&instance_lib_cache);
}

InstanceObject* InstanceObject::Alloc()
{
	InstanceObjectLibrary* lib = CheckInstanceObjectLibrary(LIBOFFSET(InstanceObjectLibrary, Alloc));
	if (!lib)
		return nullptr;

	return lib->Alloc();
}

void InstanceObject::Free(InstanceObject*& op)
{
	if (!op)
		return;
	InstanceObjectLibrary* lib = CheckInstanceObjectLibrary(LIBOFFSET(InstanceObjectLibrary, Free));
	if (!lib)
		return;

	lib->Free(op);
	op = nullptr;
}

void InstanceObject::UpdateInstanceList(BaseObject* pObj, InstanceObjectList* pCurrent, InstanceObjectList *&pList, const Matrix &m, const void* instanceCRC)
{
	InstanceObjectLibrary* lib = CheckInstanceObjectLibrary(LIBOFFSET(InstanceObjectLibrary, UpdateInstanceList));
	if (!lib || !lib->UpdateInstanceList)
		return;

	lib->UpdateInstanceList(pObj, pCurrent, pList, m, instanceCRC);
}

void InstanceObject::RecurseGenList(BaseObject *op, BaseObject *generator, HierarchyHelp* hh)
{
	InstanceObjectLibrary* lib = CheckInstanceObjectLibrary(LIBOFFSET(InstanceObjectLibrary, RecurseGenList));
	if (!lib || !lib->RecurseGenList)
		return;

	lib->RecurseGenList(op, generator, hh);
}

maxon::Result<void> InstanceObject::AddCacheInstanceData(InstanceObjectList*& pList)
{
	InstanceObjectLibrary* lib = CheckInstanceObjectLibrary(LIBOFFSET(InstanceObjectLibrary, AddCacheInstanceData));
	if (!lib || !lib->AddCacheInstanceData)
		return maxon::UnresolvedError(MAXON_SOURCE_LOCATION, "Function not defined in Library or Library doesn't exist"_s);

	return (((iInstanceObject*)this)->*(lib->AddCacheInstanceData))(pList);
}

Bool InstanceObject::IsMultiInstance() const
{
	InstanceObjectLibrary* lib = CheckInstanceObjectLibrary(LIBOFFSET(InstanceObjectLibrary, IsMultiInstance));
	if (!lib || !lib->IsMultiInstance)
		return false;

	return (((iInstanceObject*)this)->*(lib->IsMultiInstance))();
}

BaseObject* InstanceObject::GetReferenceObject(BaseDocument* doc) const
{
	InstanceObjectLibrary* lib = CheckInstanceObjectLibrary(LIBOFFSET(InstanceObjectLibrary, GetReferenceObject));
	if (!lib || !lib->GetReferenceObject)
		return nullptr;

	return (((iInstanceObject*)this)->*(lib->GetReferenceObject))(doc);
}

maxon::Result<void> InstanceObject::SetReferenceObject(BaseObject* refObj)
{
	InstanceObjectLibrary* lib = CheckInstanceObjectLibrary(LIBOFFSET(InstanceObjectLibrary, SetReferenceObject));
	if (!lib || !lib->SetReferenceObject)
		return maxon::UnresolvedError(MAXON_SOURCE_LOCATION, "Function not defined in Library or Library doesn't exist"_s);

	return (((iInstanceObject*)this)->*(lib->SetReferenceObject))(refObj);
}

UInt InstanceObject::GetInstanceCount() const
{
	InstanceObjectLibrary* lib = CheckInstanceObjectLibrary(LIBOFFSET(InstanceObjectLibrary, GetInstanceCount));
	if (!lib || !lib->GetInstanceCount)
		return 0;

	return (((iInstanceObject*)this)->*(lib->GetInstanceCount))();
}

maxon::Result<void>	InstanceObject::SetInstanceMatrices(const maxon::BaseArray<Matrix>& matrices)
{
	InstanceObjectLibrary* lib = CheckInstanceObjectLibrary(LIBOFFSET(InstanceObjectLibrary, SetInstanceMatrices));
	if (!lib || !lib->SetInstanceMatrices)
		return maxon::UnresolvedError(MAXON_SOURCE_LOCATION, "Function not defined in Library or Library doesn't exist"_s);

	return (((iInstanceObject*)this)->*(lib->SetInstanceMatrices))(matrices);
}

const maxon::BaseArray<Matrix>*	InstanceObject::GetInstanceMatrices() const
{
	InstanceObjectLibrary* lib = CheckInstanceObjectLibrary(LIBOFFSET(InstanceObjectLibrary, GetInstanceMatrices));
	if (!lib || !lib->GetInstanceMatrices)
		return nullptr;

	return (((iInstanceObject*)this)->*(lib->GetInstanceMatrices))();
}

Matrix	InstanceObject::GetInstanceMatrix(UInt index) const
{
	InstanceObjectLibrary* lib = CheckInstanceObjectLibrary(LIBOFFSET(InstanceObjectLibrary, GetInstanceMatrix));
	if (!lib || !lib->GetInstanceMatrix)
		return Matrix();

	return (((iInstanceObject*)this)->*(lib->GetInstanceMatrix))(index);
}

maxon::Result<void> InstanceObject::SetInstanceMatrix(UInt index, const Matrix& globalMatrix)
{
	InstanceObjectLibrary* lib = CheckInstanceObjectLibrary(LIBOFFSET(InstanceObjectLibrary, SetInstanceMatrix));
	if (!lib || !lib->SetInstanceMatrix)
		return maxon::UnresolvedError(MAXON_SOURCE_LOCATION, "Function not defined in Library or Library doesn't exist"_s);

	return (((iInstanceObject*)this)->*(lib->SetInstanceMatrix))(index, globalMatrix);
}

UInt32	InstanceObject::GetMatrixDirtyID(UInt index) const
{
	InstanceObjectLibrary* lib = CheckInstanceObjectLibrary(LIBOFFSET(InstanceObjectLibrary, GetMatrixDirtyID));
	if (!lib || !lib->GetMatrixDirtyID)
		return (UInt32)NOTOK;

	return (((iInstanceObject*)this)->*(lib->GetMatrixDirtyID))(index);
}

maxon::Result<void>	InstanceObject::SetInstanceColors(const maxon::BaseArray<maxon::Color64>& colors)
{
	InstanceObjectLibrary* lib = CheckInstanceObjectLibrary(LIBOFFSET(InstanceObjectLibrary, SetInstanceColors));
	if (!lib || !lib->SetInstanceColors)
		return maxon::UnresolvedError(MAXON_SOURCE_LOCATION, "Function not defined in Library or Library doesn't exist"_s);

	return (((iInstanceObject*)this)->*(lib->SetInstanceColors))(colors);
}

const maxon::BaseArray<maxon::Color64>*	InstanceObject::GetInstanceColors() const
{
	InstanceObjectLibrary* lib = CheckInstanceObjectLibrary(LIBOFFSET(InstanceObjectLibrary, GetInstanceColors));
	if (!lib || !lib->GetInstanceColors)
		return nullptr;

	return (((iInstanceObject*)this)->*(lib->GetInstanceColors))();
}

maxon::Color64	InstanceObject::GetInstanceColor(UInt index) const
{
	InstanceObjectLibrary* lib = CheckInstanceObjectLibrary(LIBOFFSET(InstanceObjectLibrary, GetInstanceColor));
	if (!lib || !lib->GetInstanceColor)
		return maxon::Color64();

	return (((iInstanceObject*)this)->*(lib->GetInstanceColor))(index);
}

maxon::Result<void>	InstanceObject::SetInstanceUniqueIPs(const maxon::BaseArray<Int32>& uniqueIPs)
{
	InstanceObjectLibrary* lib = CheckInstanceObjectLibrary(LIBOFFSET(InstanceObjectLibrary, SetInstanceUniqueIPs));
	if (!lib || !lib->SetInstanceUniqueIPs)
		return maxon::UnresolvedError(MAXON_SOURCE_LOCATION, "Function not defined in Library or Library doesn't exist"_s);
	
	return (((iInstanceObject*)this)->*(lib->SetInstanceUniqueIPs))(uniqueIPs);
}

const maxon::BaseArray<Int32>*	InstanceObject::GetInstanceUniqueIPs() const
{
	InstanceObjectLibrary* lib = CheckInstanceObjectLibrary(LIBOFFSET(InstanceObjectLibrary, GetInstanceUniqueIPs));
	if (!lib || !lib->GetInstanceUniqueIPs)
		return nullptr;
	
	return (((iInstanceObject*)this)->*(lib->GetInstanceUniqueIPs))();
}

Int32	InstanceObject::GetInstanceUniqueIP(UInt index) const
{
	InstanceObjectLibrary* lib = CheckInstanceObjectLibrary(LIBOFFSET(InstanceObjectLibrary, GetInstanceUniqueIP));
	if (!lib || !lib->GetInstanceUniqueIP)
		return 0;
	
	return (((iInstanceObject*)this)->*(lib->GetInstanceUniqueIP))(index);
}



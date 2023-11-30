#include "lib_instanceobject.h"
#include "maxon/errortypes.h"

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_BEGIN
#endif

static InstanceObjectLibrary* instance_lib_cache = nullptr;

static InstanceObjectLibrary* CheckInstanceObjectLibrary(Int32 offset)
{
	return CheckLib<InstanceObjectLibrary>(ID_INSTANCEOBJECT_LIB, offset, instance_lib_cache);
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

void InstanceObject::RecurseGenList(const BaseObject *op, BaseObject *generator, const HierarchyHelp* hh)
{
	InstanceObjectLibrary* lib = CheckInstanceObjectLibrary(LIBOFFSET(InstanceObjectLibrary, RecurseGenList));
	if (!lib || !lib->RecurseGenList)
		return;

	lib->RecurseGenList(op, generator, hh);
}

Bool InstanceObject::IsMultiInstance() const
{
	InstanceObjectLibrary* lib = CheckInstanceObjectLibrary(LIBOFFSET(InstanceObjectLibrary, IsMultiInstance));
	if (!lib || !lib->IsMultiInstance)
		return false;

	return (reinterpret_cast<const iInstanceObject*>(this)->*(lib->IsMultiInstance))();
}

const BaseObject* InstanceObject::GetReferenceObject(const BaseDocument* doc) const
{
	InstanceObjectLibrary* lib = CheckInstanceObjectLibrary(LIBOFFSET(InstanceObjectLibrary, GetReferenceObject));
	if (!lib || !lib->GetReferenceObject)
		return nullptr;

	return (reinterpret_cast<const iInstanceObject*>(this)->*(lib->GetReferenceObject))(doc);
}

maxon::Result<void> InstanceObject::SetReferenceObject(BaseObject* refObj)
{
	InstanceObjectLibrary* lib = CheckInstanceObjectLibrary(LIBOFFSET(InstanceObjectLibrary, SetReferenceObject));
	if (!lib || !lib->SetReferenceObject)
		return maxon::UnresolvedError(MAXON_SOURCE_LOCATION, "Function not defined in Library or Library doesn't exist"_s);

	return (reinterpret_cast<iInstanceObject*>(this)->*(lib->SetReferenceObject))(refObj);
}

UInt InstanceObject::GetInstanceCount() const
{
	InstanceObjectLibrary* lib = CheckInstanceObjectLibrary(LIBOFFSET(InstanceObjectLibrary, GetInstanceCount));
	if (!lib || !lib->GetInstanceCount)
		return 0;

	return (reinterpret_cast<const iInstanceObject*>(this)->*(lib->GetInstanceCount))();
}

maxon::Result<void>	InstanceObject::SetInstanceMatrices(const maxon::BaseArray<Matrix>& matrices)
{
	InstanceObjectLibrary* lib = CheckInstanceObjectLibrary(LIBOFFSET(InstanceObjectLibrary, SetInstanceMatrices));
	if (!lib || !lib->SetInstanceMatrices)
		return maxon::UnresolvedError(MAXON_SOURCE_LOCATION, "Function not defined in Library or Library doesn't exist"_s);

	return (reinterpret_cast<iInstanceObject*>(this)->*(lib->SetInstanceMatrices))(matrices);
}

maxon::Result<void> InstanceObject::SetInstanceMatrices(maxon::BaseArray<Matrix>&& matrices)
{
	InstanceObjectLibrary* lib = CheckInstanceObjectLibrary(LIBOFFSET(InstanceObjectLibrary, SetInstanceMatricesMove));
	if (!lib || !lib->SetInstanceMatricesMove)
		return maxon::UnresolvedError(MAXON_SOURCE_LOCATION, "Function not defined in Library or Library doesn't exist"_s);

	return (reinterpret_cast<iInstanceObject*>(this)->*(lib->SetInstanceMatricesMove))(std::move(matrices));
}

const maxon::BaseArray<Matrix>*	InstanceObject::GetInstanceMatrices() const
{
	InstanceObjectLibrary* lib = CheckInstanceObjectLibrary(LIBOFFSET(InstanceObjectLibrary, GetInstanceMatrices));
	if (!lib || !lib->GetInstanceMatrices)
		return nullptr;

	return (reinterpret_cast<const iInstanceObject*>(this)->*(lib->GetInstanceMatrices))();
}

Matrix	InstanceObject::GetInstanceMatrix(UInt index) const
{
	InstanceObjectLibrary* lib = CheckInstanceObjectLibrary(LIBOFFSET(InstanceObjectLibrary, GetInstanceMatrix));
	if (!lib || !lib->GetInstanceMatrix)
		return Matrix();

	return (reinterpret_cast<const iInstanceObject*>(this)->*(lib->GetInstanceMatrix))(index);
}

maxon::Result<void> InstanceObject::SetInstanceMatrix(UInt index, const Matrix& globalMatrix)
{
	InstanceObjectLibrary* lib = CheckInstanceObjectLibrary(LIBOFFSET(InstanceObjectLibrary, SetInstanceMatrix));
	if (!lib || !lib->SetInstanceMatrix)
		return maxon::UnresolvedError(MAXON_SOURCE_LOCATION, "Function not defined in Library or Library doesn't exist"_s);

	return (reinterpret_cast<iInstanceObject*>(this)->*(lib->SetInstanceMatrix))(index, globalMatrix);
}

const maxon::BaseArray<Matrix>* InstanceObject::GetInstanceDeformationMatrices() const
{
	InstanceObjectLibrary* lib = CheckInstanceObjectLibrary(LIBOFFSET(InstanceObjectLibrary, GetInstanceDeformationMatrices));
	if (!lib || !lib->GetInstanceDeformationMatrices)
		return nullptr;

	return (reinterpret_cast<const iInstanceObject*>(this)->*(lib->GetInstanceDeformationMatrices))();
}

const maxon::BaseArray<Matrix>* InstanceObject::GetInstanceUndeformedMatrices() const
{
	InstanceObjectLibrary* lib = CheckInstanceObjectLibrary(LIBOFFSET(InstanceObjectLibrary, GetInstanceUndeformedMatrices));
	if (!lib || !lib->GetInstanceUndeformedMatrices)
		return nullptr;

	return (reinterpret_cast<const iInstanceObject*>(this)->*(lib->GetInstanceUndeformedMatrices))();
}

const maxon::BaseArray<Matrix>* InstanceObject::GetInstanceUndeformedLocalMatrices() const
{
	InstanceObjectLibrary* lib = CheckInstanceObjectLibrary(LIBOFFSET(InstanceObjectLibrary, GetInstanceUndeformedLocalMatrices));
	if (!lib || !lib->GetInstanceUndeformedLocalMatrices)
		return nullptr;

	return (reinterpret_cast<const iInstanceObject*>(this)->*(lib->GetInstanceUndeformedLocalMatrices))();
}

maxon::Result<void>	InstanceObject::SetInstanceDeformationMatrices(const maxon::BaseArray<Matrix>& matrices)
{
	InstanceObjectLibrary* lib = CheckInstanceObjectLibrary(LIBOFFSET(InstanceObjectLibrary, SetInstanceDeformationMatrices));
	if (!lib || !lib->SetInstanceDeformationMatrices)
		return maxon::UnresolvedError(MAXON_SOURCE_LOCATION, "Function not defined in Library or Library doesn't exist"_s);

	return (reinterpret_cast<iInstanceObject*>(this)->*(lib->SetInstanceDeformationMatrices))(matrices);
}

maxon::Result<void> InstanceObject::SetInstanceDeformationMatrices(maxon::BaseArray<Matrix>&& matrices)
{
	InstanceObjectLibrary* lib = CheckInstanceObjectLibrary(LIBOFFSET(InstanceObjectLibrary, SetInstanceDeformationMatricesMove));
	if (!lib || !lib->SetInstanceDeformationMatricesMove)
		return maxon::UnresolvedError(MAXON_SOURCE_LOCATION, "Function not defined in Library or Library doesn't exist"_s);

	return (reinterpret_cast<iInstanceObject*>(this)->*(lib->SetInstanceDeformationMatricesMove))(std::move(matrices));
}

Bool InstanceObject::HasDeformationMatrices()
{
	InstanceObjectLibrary* lib = CheckInstanceObjectLibrary(LIBOFFSET(InstanceObjectLibrary, HasDeformationMatrices));
	if (!lib || !lib->HasDeformationMatrices)
		return false;

	return (reinterpret_cast<iInstanceObject*>(this)->*(lib->HasDeformationMatrices))();
}

void InstanceObject::ClearInstanceDeformedMatrices()
{
	InstanceObjectLibrary* lib = CheckInstanceObjectLibrary(LIBOFFSET(InstanceObjectLibrary, ClearInstanceDeformedMatrices));
	if (!lib || !lib->ClearInstanceDeformedMatrices)
		return;

	(reinterpret_cast<iInstanceObject*>(this)->*(lib->ClearInstanceDeformedMatrices))();
}

UInt32	InstanceObject::GetMatrixDirtyID(UInt index) const
{
	InstanceObjectLibrary* lib = CheckInstanceObjectLibrary(LIBOFFSET(InstanceObjectLibrary, GetMatrixDirtyID));
	if (!lib || !lib->GetMatrixDirtyID)
		return (UInt32)NOTOK;

	return (reinterpret_cast<const iInstanceObject*>(this)->*(lib->GetMatrixDirtyID))(index);
}

maxon::Result<void>	InstanceObject::SetInstanceColors(const maxon::BaseArray<maxon::Color64>& colors)
{
	InstanceObjectLibrary* lib = CheckInstanceObjectLibrary(LIBOFFSET(InstanceObjectLibrary, SetInstanceColors));
	if (!lib || !lib->SetInstanceColors)
		return maxon::UnresolvedError(MAXON_SOURCE_LOCATION, "Function not defined in Library or Library doesn't exist"_s);

	return (reinterpret_cast<iInstanceObject*>(this)->*(lib->SetInstanceColors))(colors);
}

maxon::Result<void> InstanceObject::SetInstanceColors(maxon::BaseArray<maxon::Color64>&& colors)
{
	InstanceObjectLibrary* lib = CheckInstanceObjectLibrary(LIBOFFSET(InstanceObjectLibrary, SetInstanceColorsMove));
	if (!lib || !lib->SetInstanceColorsMove)
		return maxon::UnresolvedError(MAXON_SOURCE_LOCATION, "Function not defined in Library or Library doesn't exist"_s);

	return (reinterpret_cast<iInstanceObject*>(this)->*(lib->SetInstanceColorsMove))(std::move(colors));
}

const maxon::BaseArray<maxon::Color64>*	InstanceObject::GetInstanceColors() const
{
	InstanceObjectLibrary* lib = CheckInstanceObjectLibrary(LIBOFFSET(InstanceObjectLibrary, GetInstanceColors));
	if (!lib || !lib->GetInstanceColors)
		return nullptr;

	return (reinterpret_cast<const iInstanceObject*>(this)->*(lib->GetInstanceColors))();
}

maxon::Color64	InstanceObject::GetInstanceColor(UInt index) const
{
	InstanceObjectLibrary* lib = CheckInstanceObjectLibrary(LIBOFFSET(InstanceObjectLibrary, GetInstanceColor));
	if (!lib || !lib->GetInstanceColor)
		return maxon::Color64();

	return (reinterpret_cast<const iInstanceObject*>(this)->*(lib->GetInstanceColor))(index);
}

maxon::Result<void>	InstanceObject::SetInstanceUniqueIPs(const maxon::BaseArray<Int32>& uniqueIPs)
{
	InstanceObjectLibrary* lib = CheckInstanceObjectLibrary(LIBOFFSET(InstanceObjectLibrary, SetInstanceUniqueIPs));
	if (!lib || !lib->SetInstanceUniqueIPs)
		return maxon::UnresolvedError(MAXON_SOURCE_LOCATION, "Function not defined in Library or Library doesn't exist"_s);
	
	return (reinterpret_cast<iInstanceObject*>(this)->*(lib->SetInstanceUniqueIPs))(uniqueIPs);
}

maxon::Result<void> InstanceObject::SetInstanceUniqueIPs(maxon::BaseArray<Int32>&& uniqueIPs)
{
	InstanceObjectLibrary* lib = CheckInstanceObjectLibrary(LIBOFFSET(InstanceObjectLibrary, SetInstanceUniqueIPsMove));
	if (!lib || !lib->SetInstanceUniqueIPsMove)
		return maxon::UnresolvedError(MAXON_SOURCE_LOCATION, "Function not defined in Library or Library doesn't exist"_s);

	return (reinterpret_cast<iInstanceObject*>(this)->*(lib->SetInstanceUniqueIPsMove))(std::move(uniqueIPs));
}

const maxon::BaseArray<Int32>*	InstanceObject::GetInstanceUniqueIPs() const
{
	InstanceObjectLibrary* lib = CheckInstanceObjectLibrary(LIBOFFSET(InstanceObjectLibrary, GetInstanceUniqueIPs));
	if (!lib || !lib->GetInstanceUniqueIPs)
		return nullptr;
	
	return (reinterpret_cast<const iInstanceObject*>(this)->*(lib->GetInstanceUniqueIPs))();
}

Int32	InstanceObject::GetInstanceUniqueIP(UInt index) const
{
	InstanceObjectLibrary* lib = CheckInstanceObjectLibrary(LIBOFFSET(InstanceObjectLibrary, GetInstanceUniqueIP));
	if (!lib || !lib->GetInstanceUniqueIP)
		return 0;
	
	return (reinterpret_cast<const iInstanceObject*>(this)->*(lib->GetInstanceUniqueIP))(index);
}

maxon::Block<const maxon::UniqueHash>	InstanceObject::GetInstancePersistentHashes() const
{
	InstanceObjectLibrary* lib = CheckInstanceObjectLibrary(LIBOFFSET(InstanceObjectLibrary, GetInstancePersistentHashes));
	if (!lib || !lib->GetInstancePersistentHashes)
		return {};
	
	return (reinterpret_cast<const iInstanceObject*>(this)->*(lib->GetInstancePersistentHashes))();
}

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_END
#endif

#include "lib_customdatatag.h"

static CustomaDataTagLibrary* customDatatTag_lib_cache = nullptr;

CustomaDataTagLibrary* CheckCustomaDataTagLibrary(Int32 offset)
{
	return (CustomaDataTagLibrary*)CheckLib(ID_CUSTOMDATA_TAG_LIB, offset, (C4DLibrary**)&customDatatTag_lib_cache);
}

CustomDataTag* CustomDataTag::Alloc(Int32 tagId)
{
	CustomaDataTagLibrary* lib = CheckCustomaDataTagLibrary(LIBOFFSET(CustomaDataTagLibrary, Alloc));
	if (!lib)
		return nullptr;

	return lib->Alloc(tagId);
}

void CustomDataTag::Free(CustomDataTag*& tag)
{
	if (!tag)
		return;

	CustomaDataTagLibrary* lib = CheckCustomaDataTagLibrary(LIBOFFSET(CustomaDataTagLibrary, Free));
	if (!lib)
		return;

	lib->Free(tag);
	tag = nullptr;
}

maxon::Result<void> CustomDataTag::InitData()
{
	CustomaDataTagLibrary* lib = CheckCustomaDataTagLibrary(LIBOFFSET(CustomaDataTagLibrary, InitData));
	if (!lib || !lib->InitData)
		return maxon::IllegalStateError(MAXON_SOURCE_LOCATION);
	return (((iCustomDataTag*)this)->*(lib->InitData))();
}

maxon::Result<maxon::CustomDataTagClass> CustomDataTag::GetCustomDataTagClass() const
{
	CustomaDataTagLibrary* lib = CheckCustomaDataTagLibrary(LIBOFFSET(CustomaDataTagLibrary, GetCustomDataTagClass));
	if (!lib || !lib->GetCustomDataTagClass)
		return maxon::IllegalStateError(MAXON_SOURCE_LOCATION);
	return (((iCustomDataTag*)this)->*(lib->GetCustomDataTagClass))();
}

maxon::Result<maxon::DataType> CustomDataTag::GetDataType() const
{
	CustomaDataTagLibrary* lib = CheckCustomaDataTagLibrary(LIBOFFSET(CustomaDataTagLibrary, GetDataType));
	if (!lib || !lib->GetDataType)
		return maxon::IllegalStateError(MAXON_SOURCE_LOCATION);
	return (((iCustomDataTag*)this)->*(lib->GetDataType))();
}

CUSTOMDATATAG_MODE CustomDataTag::GetMode() const
{
	CustomaDataTagLibrary* lib = CheckCustomaDataTagLibrary(LIBOFFSET(CustomaDataTagLibrary, GetMode));
	if (!lib || !lib->GetMode)
		return CUSTOMDATATAG_MODE::VERTEX;
	return (((iCustomDataTag*)this)->*(lib->GetMode))();
}

void CustomDataTag::SetMode(CUSTOMDATATAG_MODE mode)
{
	CustomaDataTagLibrary* lib = CheckCustomaDataTagLibrary(LIBOFFSET(CustomaDataTagLibrary, SetMode));
	if (!lib || !lib->SetMode)
		return;
	(((iCustomDataTag*)this)->*(lib->SetMode))(mode);
}

maxon::Result<void> CustomDataTag::Resize(Int newCount)
{
	CustomaDataTagLibrary* lib = CheckCustomaDataTagLibrary(LIBOFFSET(CustomaDataTagLibrary, Resize));
	if (!lib || !lib->Resize)
		return maxon::IllegalStateError(MAXON_SOURCE_LOCATION);
	return (((iCustomDataTag*)this)->*(lib->Resize))(newCount);
}

Int CustomDataTag::GetComponentCount() const
{
	CustomaDataTagLibrary* lib = CheckCustomaDataTagLibrary(LIBOFFSET(CustomaDataTagLibrary, GetComponentCount));
	if (!lib || !lib->GetComponentCount)
		return NOTOK;
	return (((iCustomDataTag*)this)->*(lib->GetComponentCount))();
}

const void* CustomDataTag::GetConstVertexDataPtr(Int32 vertexIndex) const
{
	CustomaDataTagLibrary* lib = CheckCustomaDataTagLibrary(LIBOFFSET(CustomaDataTagLibrary, GetConstVertexDataPtr));
	if (!lib || !lib->GetConstVertexDataPtr)
		return nullptr;
	return (((iCustomDataTag*)this)->*(lib->GetConstVertexDataPtr))(vertexIndex);
}

void* CustomDataTag::GetVertexDataPtr(Int32 vertexIndex)
{
	CustomaDataTagLibrary* lib = CheckCustomaDataTagLibrary(LIBOFFSET(CustomaDataTagLibrary, GetVertexDataPtr));
	if (!lib || !lib->GetVertexDataPtr)
		return nullptr;
	return (((iCustomDataTag*)this)->*(lib->GetVertexDataPtr))(vertexIndex);
}

void CustomDataTag::SetVertexDataPtr(void* data, Int32 vertexIndex)
{
	CustomaDataTagLibrary* lib = CheckCustomaDataTagLibrary(LIBOFFSET(CustomaDataTagLibrary, SetVertexDataPtr));
	if (!lib || !lib->SetVertexDataPtr)
		return;
	(((iCustomDataTag*)this)->*(lib->SetVertexDataPtr))(data, vertexIndex);
}

const void* CustomDataTag::GetConstPolyVertexDataPtr(Int32 polygonIndex, Int32 polyVertexIndex) const
{
	CustomaDataTagLibrary* lib = CheckCustomaDataTagLibrary(LIBOFFSET(CustomaDataTagLibrary, GetConstPolyVertexDataPtr));
	if (!lib || !lib->GetConstPolyVertexDataPtr)
		return nullptr;
	return (((iCustomDataTag*)this)->*(lib->GetConstPolyVertexDataPtr))(polygonIndex, polyVertexIndex);
}


void* CustomDataTag::GetPolyVertexDataPtr(Int32 polygonIndex, Int32 polyVertexIndex)
{
	CustomaDataTagLibrary* lib = CheckCustomaDataTagLibrary(LIBOFFSET(CustomaDataTagLibrary, GetPolyVertexDataPtr));
	if (!lib || !lib->GetPolyVertexDataPtr)
		return nullptr;
	return (((iCustomDataTag*)this)->*(lib->GetPolyVertexDataPtr))(polygonIndex, polyVertexIndex);
}

void CustomDataTag::SetPolyVertexDataPtr(const void* data, Int32 polygonIndex, Int32 polyVertexIndex)
{
	CustomaDataTagLibrary* lib = CheckCustomaDataTagLibrary(LIBOFFSET(CustomaDataTagLibrary, SetPolyVertexDataPtr));
	if (!lib || !lib->SetPolyVertexDataPtr)
		return;
	(((iCustomDataTag*)this)->*(lib->SetPolyVertexDataPtr))(data, polygonIndex, polyVertexIndex);
}

const maxon::PolyData<const void*> CustomDataTag::GetConstPolygonDataPtr(Int32 polygonIndex) const
{
	CustomaDataTagLibrary* lib = CheckCustomaDataTagLibrary(LIBOFFSET(CustomaDataTagLibrary, GetConstPolygonDataPtr));
	if (!lib || !lib->GetConstPolygonDataPtr)
		return maxon::PolyData<const void*>();
	return (((iCustomDataTag*)this)->*(lib->GetConstPolygonDataPtr))(polygonIndex);
}

maxon::PolyData<void*> CustomDataTag::GetPolygonDataPtr(Int32 polygonIndex)
{
	CustomaDataTagLibrary* lib = CheckCustomaDataTagLibrary(LIBOFFSET(CustomaDataTagLibrary, GetPolygonDataPtr));
	if (!lib || !lib->GetPolygonDataPtr)
		return maxon::PolyData<void*>();
	return (((iCustomDataTag*)this)->*(lib->GetPolygonDataPtr))(polygonIndex);
}

void CustomDataTag::SetPolygonDataPtr(maxon::PolyData<void*> data, Int32 polygonIndex)
{
	CustomaDataTagLibrary* lib = CheckCustomaDataTagLibrary(LIBOFFSET(CustomaDataTagLibrary, SetPolygonDataPtr));
	if (!lib || !lib->SetPolygonDataPtr)
		return;
	(((iCustomDataTag*)this)->*(lib->SetPolygonDataPtr))(data, polygonIndex);
}

maxon::MeshAttribute CustomDataTag::GetVertexAttribute(Int32 vertexIndex)
{
	CustomaDataTagLibrary* lib = CheckCustomaDataTagLibrary(LIBOFFSET(CustomaDataTagLibrary, GetVertexAttribute));
	if (!lib || !lib->GetVertexAttribute)
		return maxon::MeshAttribute();
	return (((iCustomDataTag*)this)->*(lib->GetVertexAttribute))(vertexIndex);
}

void CustomDataTag::SetVertexAttribute(const maxon::MeshAttribute& data, Int32 vertexIndex)
{
	CustomaDataTagLibrary* lib = CheckCustomaDataTagLibrary(LIBOFFSET(CustomaDataTagLibrary, SetVertexAttribute));
	if (!lib || !lib->SetVertexAttribute)
		return;
	(((iCustomDataTag*)this)->*(lib->SetVertexAttribute))(data, vertexIndex);
}

maxon::MeshAttribute CustomDataTag::GetPolyVertexAttribute(Int32 polygonIndex, Int32 polyVertexIndex)
{
	CustomaDataTagLibrary* lib = CheckCustomaDataTagLibrary(LIBOFFSET(CustomaDataTagLibrary, GetPolyVertexAttribute));
	if (!lib || !lib->GetPolyVertexAttribute)
		return maxon::MeshAttribute();
	return (((iCustomDataTag*)this)->*(lib->GetPolyVertexAttribute))(polygonIndex, polyVertexIndex);
}

void CustomDataTag::SetPolyVertexAttribute(const maxon::MeshAttribute& data, Int32 polygonIndex, Int32 polyVertexIndex)
{
	CustomaDataTagLibrary* lib = CheckCustomaDataTagLibrary(LIBOFFSET(CustomaDataTagLibrary, SetPolyVertexAttribute));
	if (!lib || !lib->SetPolyVertexAttribute)
		return;
	(((iCustomDataTag*)this)->*(lib->SetPolyVertexAttribute))(data, polygonIndex, polyVertexIndex);
}

maxon::PolyData<maxon::MeshAttribute> CustomDataTag::GetPolygonAttribute(Int32 polygonIndex)
{
	CustomaDataTagLibrary* lib = CheckCustomaDataTagLibrary(LIBOFFSET(CustomaDataTagLibrary, GetPolygonAttribute));
	if (!lib || !lib->GetPolygonAttribute)
		return maxon::PolyData<maxon::MeshAttribute>();
	return (((iCustomDataTag*)this)->*(lib->GetPolygonAttribute))(polygonIndex);
}

void CustomDataTag::SetPolygonAttribute(maxon::PolyData<maxon::MeshAttribute> data, Int32 polygonIndex)
{
	CustomaDataTagLibrary* lib = CheckCustomaDataTagLibrary(LIBOFFSET(CustomaDataTagLibrary, SetPolygonAttribute));
	if (!lib || !lib->SetPolygonAttribute)
		return;
	(((iCustomDataTag*)this)->*(lib->SetPolygonAttribute))(data, polygonIndex);
}

maxon::Result<void> CustomDataTag::DisplayControl(BaseDocument* doc, BaseObject* op, BaseDraw* bd, BaseDrawHelp* bh, ControlDisplayStruct& cds)
{
	CustomaDataTagLibrary* lib = CheckCustomaDataTagLibrary(LIBOFFSET(CustomaDataTagLibrary, DisplayControl));
	if (!lib || !lib->DisplayControl)
		return maxon::IllegalStateError(MAXON_SOURCE_LOCATION);
	return (((iCustomDataTag*)this)->*(lib->DisplayControl))(doc, op, bd, bh, cds);
}

maxon::Result<void> CustomDataTag::InitDisplayControl(BaseDocument* doc, BaseDraw* bd, const AtomArray* active)
{
	CustomaDataTagLibrary* lib = CheckCustomaDataTagLibrary(LIBOFFSET(CustomaDataTagLibrary, InitDisplayControl));
	if (!lib || !lib->InitDisplayControl)
		return maxon::IllegalStateError(MAXON_SOURCE_LOCATION);
	return (((iCustomDataTag*)this)->*(lib->InitDisplayControl))(doc, bd, active);
}

void CustomDataTag::FreeDisplayControl()
{
	CustomaDataTagLibrary* lib = CheckCustomaDataTagLibrary(LIBOFFSET(CustomaDataTagLibrary, FreeDisplayControl));
	if (!lib || !lib->FreeDisplayControl)
		return;
	(((iCustomDataTag*)this)->*(lib->FreeDisplayControl))();
}

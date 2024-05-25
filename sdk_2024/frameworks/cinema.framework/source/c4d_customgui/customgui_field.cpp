#include "customgui_field.h"
#include "c4d_string.h"
#include "c4d_gui.h"
#include "c4d_accessedobjects.h"

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_BEGIN
#endif

static CustomGuiFieldLib* lib_field = nullptr;

static CustomGuiFieldLib* CheckGuiFieldLib(Int32 offset)
{
	return CheckLib<CustomGuiFieldLib>(CUSTOMGUI_FIELDLIST, offset, lib_field);
}

#define FieldGuiCall(b)	CustomGuiFieldLib* lib = CheckGuiFieldLib(LIBOFFSET(CustomGuiFieldLib, b)); \
	if (!lib || !lib->b) return; \
	(reinterpret_cast<iFieldCustomDatatype*>(this)->*lib->b)

#define FieldGuiCallC(b)	CustomGuiFieldLib* lib = CheckGuiFieldLib(LIBOFFSET(CustomGuiFieldLib, b)); \
	if (!lib || !lib->b) return; \
	(reinterpret_cast<const iFieldCustomDatatype*>(this)->*lib->b)

#define FieldGuiCallR(a, b)	CustomGuiFieldLib* lib = CheckGuiFieldLib(LIBOFFSET(CustomGuiFieldLib, b)); \
	if (!lib || !lib->b) return a; \
	return (reinterpret_cast<iFieldCustomDatatype*>(this)->*lib->b)

#define FieldGuiCallRC(a, b)	CustomGuiFieldLib* lib = CheckGuiFieldLib(LIBOFFSET(CustomGuiFieldLib, b)); \
	if (!lib || !lib->b) return a; \
	return (reinterpret_cast<const iFieldCustomDatatype*>(this)->*lib->b)

FieldList* FieldList::Alloc()
{
	CustomGuiFieldLib* lib = CheckGuiFieldLib(LIBOFFSET(CustomGuiFieldLib, AllocFieldList));
	if (!lib || !lib->AllocFieldList)
		return nullptr;
	return lib->AllocFieldList();
}

void FieldList::Free(FieldList*& list)
{
	CustomGuiFieldLib* lib = CheckGuiFieldLib(LIBOFFSET(CustomGuiFieldLib, FreeFieldList));
	if (lib && lib->FreeFieldList)
		lib->FreeFieldList(list);
	list = nullptr;
}

maxon::Result<FieldOutput> FieldList::SampleListSimple(const BaseList2D& caller, const FieldInput& inputs, FIELDSAMPLE_FLAG flags) const
{
	FieldGuiCallRC(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION), SampleListSimple) (caller, inputs, flags);
}

maxon::Result<void> FieldList::SampleList(const FieldInfo& info, const FieldInput& inputs, FieldOutput& outputs) const
{
	FieldGuiCallRC(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION), SampleList) (info, inputs, outputs);
}

maxon::Result<void> FieldList::SampleListWithLambda(const FieldInfo& info, const FieldLambdaInput&& inputFunc, const FieldLambdaOutput&& outputFunc) const
{
	FieldGuiCallRC(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION), SampleListWithLambda) (info, std::forward<const FieldLambdaInput>(inputFunc), std::forward<const FieldLambdaOutput>(outputFunc));
}

maxon::Result<maxon::GenericData> FieldList::DirectInitSampling(const FieldInfo& info) const
{
	FieldGuiCallRC(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION), DirectInitSampling) (info);
}

maxon::Result<void> FieldList::DirectSample(const FieldInput& inputs, FieldOutputBlock& outputs, const FieldInfo& info, const maxon::GenericData& extraData) const
{
	FieldGuiCallRC(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION), DirectSample) (inputs, outputs, info, extraData);
}

void FieldList::DirectFreeSampling(const FieldInfo& info, maxon::GenericData& extraData) const
{
	FieldGuiCallC (DirectFreeSampling)(info, extraData);
}

maxon::Result<void> FieldList::ForEachLayer(const maxon::Delegate<maxon::Result<void>(const FieldLayer* layer, const maxon::GenericData& extra)>& callback, const maxon::GenericData& listData) const
{
	FieldGuiCallRC (maxon::FunctionNotImplementedError(MAXON_SOURCE_LOCATION), ForEachLayer)(callback, listData);
}

UInt32 FieldList::GetDirty(const BaseDocument* doc) const
{
	FieldGuiCallRC(0, GetDirty) (doc);
}

Int32 FieldList::GetCount() const
{
	FieldGuiCallRC(0, GetCount) ();
}

void FieldList::Flush()
{
	FieldGuiCall (Flush)();
}

maxon::Result<void> FieldList::InsertLayer(FieldLayer* layer, FieldLayer* parent/*= nullptr*/, FieldLayer* prev/*= nullptr*/)
{
	FieldGuiCallR(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION), InsertLayer) (layer, parent, prev);
}

const GeListHead* FieldList::GetLayersRootConst() const
{
	FieldGuiCallRC(nullptr, GetLayersRootConst)();
}

GeListHead* FieldList::GetLayersRootWritable(Bool create)
{
	FieldGuiCallR(nullptr, GetLayersRootWritable)(create);
}

maxon::Result<void> FieldList::GetSelected(maxon::BaseArray<FieldLayer*>& selected, Bool includeChildren) const
{
	FieldGuiCallRC(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION), GetSelected) (selected, includeChildren);
}

maxon::Result<void> FieldList::FindByReference(FieldLayerLink link, BaseDocument* doc, maxon::BaseArray<FieldLayer*>& found) const
{
	FieldGuiCallRC(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION), FindByReference) (link, doc, found);
}

void FieldList::SetFlags(FIELDLIST_FLAGS flags, Bool state)
{
	FieldGuiCall (SetFlags)(flags, state);
}

FIELDLIST_FLAGS FieldList::GetFlags() const
{
	FieldGuiCallRC(FIELDLIST_FLAGS::NONE, GetFlags) ();
}

Bool FieldList::CheckFlag(FIELDLIST_FLAGS flag) const
{
	FieldGuiCallRC(false, CheckFlag) (flag);
}

Bool FieldList::HasContent(FIELDLAYER_CHANNELFLAG channel) const
{
	FieldGuiCallRC(false, HasContent) (channel);
}

maxon::Result<Bool> FieldList::GetAccessedObjects(const BaseList2D* caller, METHOD_ID method, AccessedObjectsCallback& access) const
{
	FieldGuiCallRC(access.MayAccessAnything(), GetAccessedObjects) (caller, method, access);
}

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_END
#endif

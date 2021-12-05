#include "customgui_field.h"
#include "c4d_string.h"
#include "c4d_gui.h"

static CustomGuiFieldLib* lib_field = nullptr;

static CustomGuiFieldLib* CheckGuiFieldLib(Int32 offset)
{
	return (CustomGuiFieldLib*)CheckLib(CUSTOMGUI_FIELDLIST, offset, (C4DLibrary**)lib_field);
}

#define FieldGuiCall(b)	CustomGuiFieldLib* lib = CheckGuiFieldLib(LIBOFFSET(CustomGuiFieldLib, b)); \
	if (!lib || !lib->b) return; \
	(((iFieldCustomDatatype*)this)->*lib->b)

#define FieldGuiCallR(a, b)	CustomGuiFieldLib* lib = CheckGuiFieldLib(LIBOFFSET(CustomGuiFieldLib, b)); \
	if (!lib || !lib->b) return a; \
	return (((iFieldCustomDatatype*)this)->*lib->b)

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

maxon::Result<FieldOutput> FieldList::SampleListSimple(BaseList2D& caller, const FieldInput& inputs, FIELDSAMPLE_FLAG flags)
{
	FieldGuiCallR(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION), SampleListSimple) (caller, inputs, flags);
}

maxon::Result<void> FieldList::SampleList(const FieldInfo& info, const FieldInput& inputs, FieldOutput& outputs)
{
	FieldGuiCallR(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION), SampleList) (info, inputs, outputs);
}

maxon::Result<void> FieldList::SampleListWithLambda(const FieldInfo& info, const FieldLambdaInput&& inputFunc, const FieldLambdaOutput&& outputFunc)
{
	FieldGuiCallR(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION), SampleListWithLambda) (info, std::forward<const FieldLambdaInput>(inputFunc), std::forward<const FieldLambdaOutput>(outputFunc));
}

maxon::Result<void> FieldList::DirectInitSampling(const FieldInfo& info)
{
	FieldGuiCallR(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION), DirectInitSampling) (info);
}

maxon::Result<void> FieldList::DirectSample(const FieldInput& inputs, FieldOutputBlock& outputs, const FieldInfo& info)
{
	FieldGuiCallR(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION), DirectSample) (inputs, outputs, info);
}

void FieldList::DirectFreeSampling(const FieldInfo& info)
{
	FieldGuiCall (DirectFreeSampling)(info);
}

UInt32 FieldList::GetDirty(BaseDocument* doc) const
{
	FieldGuiCallR(0, GetDirty) (doc);
}

Int32 FieldList::GetCount() const
{
	FieldGuiCallR(0, GetCount) ();
}

void FieldList::Flush()
{
	FieldGuiCall (Flush)();
}

maxon::Result<void> FieldList::InsertLayer(FieldLayer* layer, FieldLayer* parent/*= nullptr*/, FieldLayer* prev/*= nullptr*/)
{
	FieldGuiCallR(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION), InsertLayer) (layer, parent, prev);
}

GeListHead* FieldList::GetLayersRoot() const
{
	FieldGuiCallR(nullptr, GetLayersRoot) ();
}

maxon::Result<void> FieldList::GetSelected(maxon::BaseArray<FieldLayer*>& selected, Bool includeChildren) const
{
	FieldGuiCallR(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION), GetSelected) (selected, includeChildren);
}

maxon::Result<void> FieldList::FindByReference(FieldLayerLink link, BaseDocument* doc, maxon::BaseArray<FieldLayer*>& found) const
{
	FieldGuiCallR(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION), FindByReference) (link, doc, found);
}

void FieldList::SetFlags(FIELDLIST_FLAGS flags, Bool state)
{
	FieldGuiCall (SetFlags)(flags, state);
}

FIELDLIST_FLAGS FieldList::GetFlags() const
{
	FieldGuiCallR(FIELDLIST_FLAGS::NONE, GetFlags) ();
}

Bool FieldList::CheckFlag(FIELDLIST_FLAGS flag) const
{
	FieldGuiCallR(false, CheckFlag) (flag);
}

Bool FieldList::HasContent(FIELDLAYER_CHANNELFLAG channel) const
{
	FieldGuiCallR(false, HasContent) (channel);
}

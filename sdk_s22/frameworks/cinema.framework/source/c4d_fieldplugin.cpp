#include "c4d_fieldplugin.h"
#include "c4d_tagplugin.h"
#include "c4d_general.h"
#include "c4d_resource.h"

// // FieldDataPlugin ////

void FillFieldPlugin(FIELDPLUGIN& np, DataAllocator* npalloc, Int32 info, Int32 disklevel, BaseBitmap* icon)
{
	FillObjectPlugin(&np, npalloc, info, disklevel, icon);

	np.InitSampling = &FieldData::InitSampling;
	np.FreeSampling = &FieldData::FreeSampling;
	np.Sample = &FieldData::Sample;
	np.GetFieldFlags = &FieldData::GetFieldFlags;
}

Bool RegisterFieldPlugin(Int32 id, const maxon::String& str, const maxon::String& help, Int32 objectinfo, DataAllocator* npalloc, const maxon::String& description, BaseBitmap* icon, Int32 disklevel)
{
	if (description.GetLength() && !RegisterDescription(id, description))
		return false;

	objectinfo |= OBJECT_FIELDOBJECT;

	FIELDPLUGIN np;
	ClearMem(&np, sizeof(np));
	FillFieldPlugin(np, npalloc, objectinfo, disklevel, icon);

	np._help = (String*)&help;

	np.CheckDirty = &ObjectData::CheckDirty;

	if (objectinfo & OBJECT_MODIFIER)
		np.ModifyObject = &ObjectData::ModifyObject;

	if (objectinfo & OBJECT_PARTICLEMODIFIER)
		np.ModifyParticles = &ObjectData::ModifyParticles;

	if (objectinfo & OBJECT_ISSPLINE)
		np.GetContour = &ObjectData::GetContour;

	if (objectinfo & OBJECT_GENERATOR)
		np.GetVirtualObjects = &ObjectData::GetVirtualObjects;

	return GeRegisterPlugin(PLUGINTYPE::OBJECT, id, str, &np, sizeof(np));
}

// // FieldDataPlugin ////

// // FieldLayerDataPlugin ////

void FillFieldLayerPlugin(FIELDLAYERPLUGIN& np, DataAllocator* npalloc, Int32 info, BaseBitmap* icon, Int32 disklevel, FieldLayerAcceptDragFunction* dragFunc)
{
	FillNodePlugin(&np, info, npalloc, icon, disklevel);

	np.AcceptDrag = dragFunc;

	np.InitSampling = &FieldLayerData::InitSampling;
	np.Sample = &FieldLayerData::Sample;
	if (info&FIELDLAYER_AGGREGATE)
		np.Aggregate = &FieldLayerData::Aggregate;
	np.FreeSampling = &FieldLayerData::FreeSampling;
	np.IsEqual = &FieldLayerData::IsEqual;
	np.GetLinkedObject = &FieldLayerData::GetLinkedObject;
	np.SetLinkedObject = &FieldLayerData::SetLinkedObject;
	np.CheckDirty = &FieldLayerData::CheckDirty;
}

Bool RegisterFieldLayerPlugin(Int32 id, const maxon::String& str, const maxon::String& help, const maxon::String& dragInstruction, Int32 objectinfo, DataAllocator* npalloc, const maxon::String& description, BaseBitmap* icon, Int32 disklevel, FieldLayerAcceptDragFunction* dragFunc)
{
	if (description.GetLength() && !RegisterDescription(id, description))
		return false;

	FIELDLAYERPLUGIN np;
	ClearMem(&np, sizeof(np));
	FillFieldLayerPlugin(np, npalloc, objectinfo, icon, disklevel, dragFunc);
	np._help = (String*)&help;
	np._pickInstruction = (String*)&dragInstruction;

	return GeRegisterPlugin(PLUGINTYPE::FIELDLAYER, id, str, &np, sizeof(np));
}

// // FieldLayerDataPlugin ////

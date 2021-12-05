#include "lib_volumebuilder.h"

//---------------------------------------------------------------
/// Simple class example
//---------------------------------------------------------------

VolumeBuilderLib* lib_volumebuilder = nullptr;

static VolumeBuilderLib *CheckVolumeBuilderLib(Int32 offset)
{
	return (VolumeBuilderLib*)CheckLib(LIBRARY_VOLUMEBUILDER, offset, (C4DLibrary**)&lib_volumebuilder);
}


#define VolumeBuilderLibCall(b) 		VolumeBuilderLib *lib = CheckVolumeBuilderLib(LIBOFFSET(VolumeBuilderLib, b)); \
															if (!lib || !lib->b) return; \
															(((iVolumeBuilder*)this)->*lib->b)

#define VolumeBuilderLibCallR(a, b) VolumeBuilderLib *lib = CheckVolumeBuilderLib(LIBOFFSET(VolumeBuilderLib, b)); \
															if (!lib || !lib->b) return a; \
															return (((iVolumeBuilder*)this)->*lib->b)


Bool VolumeBuilder::InputObjectIsChild(Int32 index) const
{
	VolumeBuilderLibCallR(false, InputObjectIsChild)(index);
}

Int32 VolumeBuilder::GetListEntryCount()
{
	VolumeBuilderLibCallR(0, GetListEntryCount)();
}

Int32 VolumeBuilder::GetInputObjectCount(Bool countDouble)
{
	VolumeBuilderLibCallR(NOTOK, GetInputObjectCount)(countDouble);
}

BaseObject* VolumeBuilder::GetInputObject(Int32 index) const
{
	VolumeBuilderLibCallR(nullptr, GetInputObject)(index);
}

BaseObject* VolumeBuilder::GetInputObjectByType(Int32 type, Int32 startIndex, Int32& index)
{
	VolumeBuilderLibCallR(nullptr, GetInputObjectByType)(type, startIndex, index);
}

Bool VolumeBuilder::AddSceneObject(BaseObject* object, Int32 index, Bool enabled, BOOLTYPE boolMode, MIXTYPE mixMode)
{
	VolumeBuilderLibCallR(false, AddSceneObject)(object, index, enabled, boolMode, mixMode);
}

Bool VolumeBuilder::RemoveObject(Int32 index)
{
	VolumeBuilderLibCallR(false, RemoveObject)(index);
}

void VolumeBuilder::ClearInputObjects()
{
	VolumeBuilderLibCall(ClearInputObjects)();
}

BaseContainer* VolumeBuilder::GetSettingsContainerForIndex(Int32 index) const
{
	VolumeBuilderLibCallR(nullptr, GetSettingsContainerForIndex)(index);
}

BaseContainer* VolumeBuilder::GetSettingsContainerForObject(BaseObject* object) const
{
	VolumeBuilderLibCallR(nullptr, GetSettingsContainerForObject)(object);
}

void VolumeBuilder::SetBoolMode(Int32 index, BOOLTYPE mode)
{
	VolumeBuilderLibCall(SetBoolMode)(index, mode);
}

BOOLTYPE VolumeBuilder::GetBoolMode(Int32 index) const
{
	VolumeBuilderLibCallR(BOOLTYPE::NONE, GetBoolMode)(index);
}

void VolumeBuilder::SetMixMode(Int32 index, MIXTYPE mode)
{
	VolumeBuilderLibCall(SetMixMode)(index, mode);
}

MIXTYPE VolumeBuilder::GetMixMode(Int32 index) const
{
	VolumeBuilderLibCallR(MIXTYPE::NONE, GetMixMode)(index);
}

void VolumeBuilder::SetMixVectorMode(Int32 index, MIXVECTORTYPE mode)
{
	VolumeBuilderLibCall(SetMixVectorMode)(index, mode);
}

MIXVECTORTYPE VolumeBuilder::GetMixVectorMode(Int32 index) const
{
	VolumeBuilderLibCallR(MIXVECTORTYPE::NONE, GetMixVectorMode)(index);
}

void VolumeBuilder::SetEnable(Int32 index, Bool enable)
{
	VolumeBuilderLibCall(SetEnable)(index, enable);
}

Bool VolumeBuilder::GetEnable(Int32 index) const
{
	VolumeBuilderLibCallR(false, GetEnable)(index);
}

void VolumeBuilder::SetSelected(Int32 index, Bool select)
{
	VolumeBuilderLibCall(SetSelected)(index, select);
}

Bool VolumeBuilder::GetSelected(Int32 index) const
{
	VolumeBuilderLibCallR(false, GetSelected)(index);
}

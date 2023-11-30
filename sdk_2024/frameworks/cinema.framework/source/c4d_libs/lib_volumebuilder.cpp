#include "lib_volumebuilder.h"

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_BEGIN
#endif

//---------------------------------------------------------------
/// Simple class example
//---------------------------------------------------------------

VolumeBuilderLib* lib_volumebuilder = nullptr;

static VolumeBuilderLib *CheckVolumeBuilderLib(Int32 offset)
{
	return CheckLib<VolumeBuilderLib>(LIBRARY_VOLUMEBUILDER, offset, lib_volumebuilder);
}


#define VolumeBuilderLibCall(b) 		VolumeBuilderLib *lib = CheckVolumeBuilderLib(LIBOFFSET(VolumeBuilderLib, b)); \
															if (!lib || !lib->b) return; \
															(reinterpret_cast<iVolumeBuilder*>(this)->*lib->b)

#define VolumeBuilderLibCallR(a, b) VolumeBuilderLib *lib = CheckVolumeBuilderLib(LIBOFFSET(VolumeBuilderLib, b)); \
															if (!lib || !lib->b) return a; \
															return (reinterpret_cast<iVolumeBuilder*>(this)->*lib->b)

#define VolumeBuilderLibCallRC(a, b) VolumeBuilderLib *lib = CheckVolumeBuilderLib(LIBOFFSET(VolumeBuilderLib, b)); \
															if (!lib || !lib->b) return a; \
															return (reinterpret_cast<const iVolumeBuilder*>(this)->*lib->b)


Bool VolumeBuilder::InputObjectIsChild(Int32 index) const
{
	VolumeBuilderLibCallRC(false, InputObjectIsChild)(index);
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
	VolumeBuilderLibCallRC(nullptr, GetInputObject)(index);
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
	VolumeBuilderLibCallRC(nullptr, GetSettingsContainerForIndex)(index);
}

BaseContainer* VolumeBuilder::GetSettingsContainerForObject(BaseObject* object) const
{
	VolumeBuilderLibCallRC(nullptr, GetSettingsContainerForObject)(object);
}

void VolumeBuilder::SetBoolMode(Int32 index, BOOLTYPE mode)
{
	VolumeBuilderLibCall(SetBoolMode)(index, mode);
}

BOOLTYPE VolumeBuilder::GetBoolMode(Int32 index) const
{
	VolumeBuilderLibCallRC(BOOLTYPE::NONE, GetBoolMode)(index);
}

void VolumeBuilder::SetMixMode(Int32 index, MIXTYPE mode)
{
	VolumeBuilderLibCall(SetMixMode)(index, mode);
}

MIXTYPE VolumeBuilder::GetMixMode(Int32 index) const
{
	VolumeBuilderLibCallRC(MIXTYPE::NONE, GetMixMode)(index);
}

void VolumeBuilder::SetMixVectorMode(Int32 index, MIXVECTORTYPE mode)
{
	VolumeBuilderLibCall(SetMixVectorMode)(index, mode);
}

MIXVECTORTYPE VolumeBuilder::GetMixVectorMode(Int32 index) const
{
	VolumeBuilderLibCallRC(MIXVECTORTYPE::NONE, GetMixVectorMode)(index);
}

void VolumeBuilder::SetEnable(Int32 index, Bool enable)
{
	VolumeBuilderLibCall(SetEnable)(index, enable);
}

Bool VolumeBuilder::GetEnable(Int32 index) const
{
	VolumeBuilderLibCallRC(false, GetEnable)(index);
}

void VolumeBuilder::SetSelected(Int32 index, Bool select)
{
	VolumeBuilderLibCall(SetSelected)(index, select);
}

Bool VolumeBuilder::GetSelected(Int32 index) const
{
	VolumeBuilderLibCallRC(false, GetSelected)(index);
}

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_END
#endif

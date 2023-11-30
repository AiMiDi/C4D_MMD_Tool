#include "customgui_soundeffector.h"
#include "c4d_string.h"
#include "c4d_gui.h"
#include "c4d_objectdata.h"

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_BEGIN
#endif

static CustomGuiSoundDataLib* lib_SoundDataControl = nullptr;

static CustomGuiSoundDataLib* CheckCustomGuiSoundDataLib(Int32 offset)
{
	return CheckLib<CustomGuiSoundDataLib>(CUSTOMGUI_SOUNDEFFECTOR, offset, lib_SoundDataControl);
}

#define SoundDataCall(func)	CustomGuiSoundDataLib* lib = CheckCustomGuiSoundDataLib(LIBOFFSET(CustomGuiSoundDataLib, func)); \
														if (!lib || !lib->func) return; \
														(reinterpret_cast<iSoundData*>(this)->*lib->func)
#define SoundDataCallC(func)	CustomGuiSoundDataLib* lib = CheckCustomGuiSoundDataLib(LIBOFFSET(CustomGuiSoundDataLib, func)); \
														if (!lib || !lib->func) return; \
														(reinterpret_cast<const iSoundData*>(this)->*lib->func)
#define SoundDataCallR(returnV, func)	CustomGuiSoundDataLib* lib = CheckCustomGuiSoundDataLib(LIBOFFSET(CustomGuiSoundDataLib, func)); \
																			if (!lib || !lib->func) return returnV; \
																			return (reinterpret_cast<iSoundData*>(this)->*lib->func)
#define SoundDataCallRC(returnV, func)	CustomGuiSoundDataLib* lib = CheckCustomGuiSoundDataLib(LIBOFFSET(CustomGuiSoundDataLib, func)); \
																			if (!lib || !lib->func) return returnV; \
																			return (reinterpret_cast<const iSoundData*>(this)->*lib->func)
#define SoundDataGuiCall(func)	CustomGuiSoundDataLib* lib = CheckCustomGuiSoundDataLib(LIBOFFSET(CustomGuiSoundDataLib, func)); \
																if (!lib || !lib->func) return; \
																(reinterpret_cast<iSoundDataCustomGui*>(this)->*lib->func)
#define SoundDataGuiCallR(returnV, func)	CustomGuiSoundDataLib* lib = CheckCustomGuiSoundDataLib(LIBOFFSET(CustomGuiSoundDataLib, func)); \
																					if (!lib || !lib->func) return returnV; \
																					return (reinterpret_cast<iSoundDataCustomGui*>(this)->*lib->func)
#define SoundDataGuiCallRC(returnV, func)	CustomGuiSoundDataLib* lib = CheckCustomGuiSoundDataLib(LIBOFFSET(CustomGuiSoundDataLib, func)); \
																					if (!lib || !lib->func) return returnV; \
																					return (reinterpret_cast<const iSoundDataCustomGui*>(this)->*lib->func)
#define ProbeCall(func)	CustomGuiSoundDataLib* lib = CheckCustomGuiSoundDataLib(LIBOFFSET(CustomGuiSoundDataLib, func)); \
												if (!lib || !lib->func) return; \
												(reinterpret_cast<iProbe*>(this)->*lib->func)
#define ProbeCallR(returnV, func)	CustomGuiSoundDataLib* lib = CheckCustomGuiSoundDataLib(LIBOFFSET(CustomGuiSoundDataLib, func)); \
																	if (!lib || !lib->func) return returnV; \
																	return (reinterpret_cast<iProbe*>(this)->*lib->func)
#define ProbeCallRC(returnV, func)	CustomGuiSoundDataLib* lib = CheckCustomGuiSoundDataLib(LIBOFFSET(CustomGuiSoundDataLib, func)); \
																	if (!lib || !lib->func) return returnV; \
																	return (reinterpret_cast<const iProbe*>(this)->*lib->func)

// Probe
Float Probe::GetRight() const
{
	ProbeCallRC(22050.0, GetRight)();
}

Float Probe::GetLeft() const
{
	ProbeCallRC(1.0, GetLeft)();
}

Float Probe::GetBottom() const
{
	ProbeCallRC(0.0f, GetBottom)();
}

Float Probe::GetTop() const
{
	ProbeCallRC(1.0f, GetTop)();
}

Bool Probe::SetRight(Float right)
{
	ProbeCallR(false, SetRight)(right);
}

Bool Probe::SetLeft(Float left)
{
	ProbeCallR(false, SetLeft)(left);
}

Bool Probe::SetTop(Float top)
{
	ProbeCallR(false, SetTop)(top);
}

Bool Probe::SetBottom(Float bottom)
{
	ProbeCallR(false, SetBottom)(bottom);
}

void Probe::ValidateDimensions()
{
	ProbeCall(ValidateDimensions)();
}


// SoundEffectorCustomGui
Bool SoundEffectorCustomGui::SetGUIOwnerOverride(BaseList2D* bl)
{
	SoundDataGuiCallR(false, SetGUIOwnerOverride)(bl);
}

BaseList2D* SoundEffectorCustomGui::GetGUIOwnerOverride(BaseDocument* doc) const
{
	SoundDataGuiCallRC(nullptr, GetGUIOwnerOverride)(doc);
}

// SoundDataType
Int SoundEffectorData::CreateProbe(Float left, Float right, Float top, Float bottom, Bool selected)
{
	SoundDataCallR(-1, CreateProbe)(left, right, top, bottom, selected);
}

Int SoundEffectorData::GetProbeCount()  const
{
	SoundDataCallRC(-1, GetProbeCount)();
}

Probe* SoundEffectorData::GetProbe(Int index) const
{
	SoundDataCallRC(nullptr, GetProbe)(index);
}

Bool SoundEffectorData::DeleteProbe(Int index)
{
	SoundDataCallR(false, DeleteProbe)(index);
}

void SoundEffectorData::UpdateProbeOrder()
{
	SoundDataCall(UpdateProbeOrder)();
}

Bool SoundEffectorData::InitSampling(BaseDocument* doc)
{
	SoundDataCallR(true, InitSampling)(doc);
}

Bool SoundEffectorData::Sample(Int index, Int count, Float& value, Vector& color)
{
	SoundDataCallR(true, Sample)(index, count, value, color);
}

Bool SoundEffectorData::SampleArray(Int offset, Int count, Int totalCount, Float* values, Vector* colors)
{
	SoundDataCallR(true, SampleArray)(offset, count, totalCount, values, colors);
}

Bool SoundEffectorData::SampleArray(Int offset, Int count, Int totalCount, Float* values, Vector* colors) const
{
	SoundDataCallRC(true, SampleArrayConst)(offset, count, totalCount, values, colors);
}

Bool SoundEffectorData::FreeSampling()
{
	SoundDataCallR(true, FreeSampling)();
}

Bool SoundEffectorData::SetActiveSoundTrack(CTrack* track, BaseDocument* doc)
{
	SoundDataCallR(true, SetActiveSoundTrack)(track, doc);
}

CTrack* SoundEffectorData::GetActiveSoundTrack(BaseDocument* doc)
{
	SoundDataCallR(nullptr, GetActiveSoundTrack)(doc);
}


Bool SoundEffectorData::CopyTo(SoundEffectorData* pDest) const
{
	SoundDataCallRC(false, CopyTo)(pDest);
}

SoundEffectorData* SoundEffectorData::Alloc()
{
	CustomGuiSoundDataLib* lib = CheckCustomGuiSoundDataLib(LIBOFFSET(CustomGuiSoundDataLib, SoundData_Alloc));
	if (!lib || !lib->SoundData_Alloc) return nullptr;
	return (SoundEffectorData*)lib->SoundData_Alloc();
}

void SoundEffectorData::Free(SoundEffectorData*& pData)
{
	CustomGuiSoundDataLib* lib = CheckCustomGuiSoundDataLib(LIBOFFSET(CustomGuiSoundDataLib, SoundData_Free));
	if (!lib || !lib->SoundData_Free) return;
	lib->SoundData_Free(reinterpret_cast<iSoundData*&>(pData));
}

void SoundEffectorData::GetRange(Float* xmin, Float* xmax, Float* ymin, Float* ymax) const
{
	SoundDataCallC(GetRange)(xmin, xmax, ymax, ymin);
}

void SoundEffectorData::SetRange(Float xmin, Float xmax, Float ymin, Float ymax)
{
	SoundDataCall(SetRange)(xmin, xmax,  ymax, ymin);
}

Float SoundEffectorData::GetLinLog() const
{
	SoundDataCallRC(1.0, GetLinLog)();
}
void SoundEffectorData::SetLinLog(Float value)
{
	SoundDataCall(SetLinLog)(value);
}

Bool SoundEffectorData::GetFreeze() const
{
	SoundDataCallRC(false, GetFreeze)();
}

Bool SoundEffectorData::CreateDefaultProbe()
{
	SoundDataCallR(false, CreateDefaultProbe)();
}

void SoundEffectorData::SetFreeze(Bool freeze)
{
	SoundDataCall(SetFreeze)(freeze);
}

const Gradient* SoundEffectorData::GetGradient() const
{
	SoundDataCallRC(nullptr, GetGradient)();
}

Int32 SoundEffectorData::GetGradientDirection() const
{
	SoundDataCallRC(1, GetGradientDirection)();
}

void SoundEffectorData::SetGradientDirection(Int32 direction)
{
	SoundDataCall(SetGradientDirection)(direction);
}

Bool SoundEffectorData::IsFFTSamplingCacheDirty(const BaseDocument& doc) const
{
	SoundDataCallRC(false, IsFFTSamplingCacheDirty)(doc);
}

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_END
#endif

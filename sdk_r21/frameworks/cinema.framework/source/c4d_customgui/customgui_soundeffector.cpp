#include "customgui_soundeffector.h"
#include "c4d_string.h"
#include "c4d_gui.h"
#include "c4d_objectdata.h"

static CustomGuiSoundDataLib* lib_SoundDataControl = nullptr;

static CustomGuiSoundDataLib* CheckCustomGuiSoundDataLib(Int32 offset)
{
	return (CustomGuiSoundDataLib*)CheckLib(CUSTOMGUI_SOUNDEFFECTOR, offset, (C4DLibrary**)&lib_SoundDataControl);
}

#define SoundDataCall(func)	CustomGuiSoundDataLib* lib = CheckCustomGuiSoundDataLib(LIBOFFSET(CustomGuiSoundDataLib, func)); \
														if (!lib || !lib->func) return; \
														(((iSoundData*)this)->*lib->func)
#define SoundDataCallR(returnV, func)	CustomGuiSoundDataLib* lib = CheckCustomGuiSoundDataLib(LIBOFFSET(CustomGuiSoundDataLib, func)); \
																			if (!lib || !lib->func) return returnV; \
																			return (((iSoundData*)this)->*lib->func)
#define SoundDataGuiCall(func)	CustomGuiSoundDataLib* lib = CheckCustomGuiSoundDataLib(LIBOFFSET(CustomGuiSoundDataLib, func)); \
																if (!lib || !lib->func) return; \
																(((iSoundDataCustomGui*)this)->*lib->func)
#define SoundDataGuiCallR(returnV, func)	CustomGuiSoundDataLib* lib = CheckCustomGuiSoundDataLib(LIBOFFSET(CustomGuiSoundDataLib, func)); \
																					if (!lib || !lib->func) return returnV; \
																					return (((iSoundDataCustomGui*)this)->*lib->func)
#define ProbeCall(func)	CustomGuiSoundDataLib* lib = CheckCustomGuiSoundDataLib(LIBOFFSET(CustomGuiSoundDataLib, func)); \
												if (!lib || !lib->func) return; \
												(((iProbe*)this)->*lib->func)
#define ProbeCallR(returnV, func)	CustomGuiSoundDataLib* lib = CheckCustomGuiSoundDataLib(LIBOFFSET(CustomGuiSoundDataLib, func)); \
																	if (!lib || !lib->func) return returnV; \
																	return (((iProbe*)this)->*lib->func)

// Probe
Float Probe::GetRight() const
{
	ProbeCallR(22050.0, GetRight)();
}

Float Probe::GetLeft() const
{
	ProbeCallR(1.0, GetLeft)();
}

Float Probe::GetBottom() const
{
	ProbeCallR(0.0f, GetBottom)();
}

Float Probe::GetTop() const
{
	ProbeCallR(1.0f, GetTop)();
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
	SoundDataGuiCallR(nullptr, GetGUIOwnerOverride)(doc);
}

// SoundDataType
Int SoundEffectorData::CreateProbe(Float left, Float right, Float top, Float bottom, Bool selected)
{
	SoundDataCallR(-1, CreateProbe)(left, right, top, bottom, selected);
}

Int SoundEffectorData::GetProbeCount()  const
{
	SoundDataCallR(-1, GetProbeCount)();
}

Probe* SoundEffectorData::GetProbe(Int index) const
{
	SoundDataCallR(nullptr, GetProbe)(index);
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
	SoundDataCallR(true, SampleArrayConst)(offset, count, totalCount, values, colors);
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


Bool SoundEffectorData::CopyTo(SoundEffectorData* pDest)
{
	SoundDataCallR(false, CopyTo)(pDest);
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
	lib->SoundData_Free((iSoundData*&)pData);
}

void SoundEffectorData::GetRange(Float* xmin, Float* xmax, Float* ymin, Float* ymax) const
{
	SoundDataCall(GetRange)(xmin, xmax, ymax, ymin);
}

void SoundEffectorData::SetRange(Float xmin, Float xmax, Float ymin, Float ymax)
{
	SoundDataCall(SetRange)(xmin, xmax,  ymax, ymin);
}

Float SoundEffectorData::GetLinLog() const
{
	SoundDataCallR(1.0, GetLinLog)();
}
void SoundEffectorData::SetLinLog(Float value)
{
	SoundDataCall(SetLinLog)(value);
}

Bool SoundEffectorData::GetFreeze() const
{
	SoundDataCallR(false, GetFreeze)();
}

Bool SoundEffectorData::CreateDefaultProbe()
{
	SoundDataCallR(false, CreateDefaultProbe)();
}

void SoundEffectorData::SetFreeze(Bool freeze)
{
	SoundDataCall(SetFreeze)(freeze);
}

Gradient* SoundEffectorData::GetGradient() const
{
	SoundDataCallR(nullptr, GetGradient)();
}

Int32 SoundEffectorData::GetGradientDirection() const
{
	SoundDataCallR(1, GetGradientDirection)();
}

void SoundEffectorData::SetGradientDirection(Int32 direction)
{
	SoundDataCall(SetGradientDirection)(direction);
}

Bool SoundEffectorData::IsFFTSamplingCacheDirty(BaseDocument& doc) const
{
	SoundDataCallR(false, IsFFTSamplingCacheDirty)(doc);
}

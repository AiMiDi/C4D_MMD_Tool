#include "customgui_range.h"

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_BEGIN
#endif

static RangeSliderLib* libRangeSloder = nullptr;

static RangeSliderLib* CheckRangeSliderLib(Int32 offset)
{
	return CheckLib<RangeSliderLib>(CUSTOMGUI_RANGE, offset, libRangeSloder);
}

#define RangeSliderCall(b) 			RangeSliderLib *lib = CheckRangeSliderLib(LIBOFFSET(RangeSliderLib, b)); \
																if (!lib || !lib->b) return; \
																(reinterpret_cast<iRangeData*>(this)->*lib->b)

#define RangeSliderCallC(b) 		RangeSliderLib *lib = CheckRangeSliderLib(LIBOFFSET(RangeSliderLib, b)); \
																if (!lib || !lib->b) return; \
																(reinterpret_cast<const iRangeData*>(this)->*lib->b)

#define RangeSliderCallR(a, b)	RangeSliderLib *lib = CheckRangeSliderLib(LIBOFFSET(RangeSliderLib, b)); \
																if (!lib || !lib->b) return a; \
																return (reinterpret_cast<iRangeData*>(this)->*lib->b)

#define RangeSliderCallRC(a, b)	RangeSliderLib *lib = CheckRangeSliderLib(LIBOFFSET(RangeSliderLib, b)); \
																if (!lib || !lib->b) return a; \
																return (reinterpret_cast<const iRangeData*>(this)->*lib->b)

RangeData* RangeData::Alloc()
{
	RangeSliderLib *lib = CheckRangeSliderLib(LIBOFFSET(RangeSliderLib, AllocRangeData));
	if (!lib || !lib->AllocRangeData)
		return nullptr;
	return lib->AllocRangeData();
}

void RangeData::Free(RangeData*& data)
{
	RangeSliderLib *lib = CheckRangeSliderLib(LIBOFFSET(RangeSliderLib, FreeRangeData));
	if (lib && lib->FreeRangeData)
		lib->FreeRangeData(data);
	data = nullptr;
}

void RangeData::CopyTo(RangeData* dst) const
{
	RangeSliderCallC(CopyTo)(dst);
}

Bool RangeData::Init(Int rangeNumber)
{
	RangeSliderCallR(false, Init)(rangeNumber);
}

Bool RangeData::AddValue(Float value)
{
	RangeSliderCallR(false, AddValue)(value);
}

Int RangeData::GetRangesCount() const
{
	RangeSliderCallRC(NOTOK, GetRangesCount)();
}

Int RangeData::GetKnotsCount() const
{
	RangeSliderCallRC(NOTOK, GetKnotsCount)();
}

Bool RangeData::SetKnotValue(Int nodeIndex, Float value)
{
	RangeSliderCallR(false, SetKnotValue)(nodeIndex, value);
}

Float RangeData::GetKnotValue(Int nodeIndex) const
{
	RangeSliderCallRC(false, GetKnotValue)(nodeIndex);
}

Int RangeData::GetKnotIndexByValue(Float value) const
{
	RangeSliderCallRC(false, GetKnotIndexByValue)(value);
}

void RangeData::DeleteKnot(Int nodeIndex)
{
	RangeSliderCall(DeleteKnot)(nodeIndex);
}

Float RangeData::GetCurrentValue() const
{
	RangeSliderCallRC(0.0, GetCurrentValue)();
}

void RangeData::SetCurrentValue(Float value)
{
	RangeSliderCall(SetCurrentValue)(value);
}

RangePair RangeData::GetRange(Int index) const
{
	RangeSliderCallRC(RangePair(), GetRange)(index);
}

Int RangeData::GetRangeIndex(Float value) const
{
	RangeSliderCallRC(NOTOK, GetRangeIndex)(value);
}

Int RangeData::GetSelectedRange() const
{
	RangeSliderCallRC(NOTOK, GetSelectedRange)();
}

Int RangeData::GetSelectedKnot() const
{
	RangeSliderCallRC(NOTOK, GetSelectedKnot)();
}

void RangeData::SetSelectedRange(Int levelIndex)
{
	RangeSliderCall(SetSelectedRange)(levelIndex);
}

void RangeData::SetSelectedKnot(Int nodeIndex)
{
	RangeSliderCall(SetSelectedKnot)(nodeIndex);
}

Bool RangeData::IsPerRangeColorMode() const
{
	RangeSliderCallRC(false, IsPerRangeColorMode)();
}

void RangeData::SetColorMode(Bool perRange)
{
	RangeSliderCall(SetColorMode)(perRange);
}

Vector RangeData::GetRangeColor(Int index) const
{
	RangeSliderCallRC(Vector(), GetRangeColor)(index);
}

void RangeData::SetRangeColor(Int index, const Vector& color)
{
	RangeSliderCall(SetRangeColor)(index, color);
}

Bool RangeData::IsRandomColorMode() const
{
	RangeSliderCallRC(false, IsRandomColorMode)();
}

void RangeData::SetRandomColorMode(Bool random)
{
	RangeSliderCall(SetRandomColorMode)(random);
}

void RangeData::Reset(Bool invalidateObject)
{
	RangeSliderCall(Reset)(invalidateObject);
}

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_END
#endif

#include "customgui_range.h"

static RangeSliderLib* libRangeSloder = nullptr;

static RangeSliderLib* CheckRangeSliderLib(Int32 offset)
{
	return (RangeSliderLib*)CheckLib(CUSTOMGUI_RANGE, offset, (C4DLibrary**)&libRangeSloder);
}

#define RangeSliderCall(b) 			RangeSliderLib *lib = CheckRangeSliderLib(LIBOFFSET(RangeSliderLib, b)); \
																if (!lib || !lib->b) return; \
																(((iRangeData*)this)->*lib->b)

#define RangeSliderCallR(a, b)	RangeSliderLib *lib = CheckRangeSliderLib(LIBOFFSET(RangeSliderLib, b)); \
																if (!lib || !lib->b) return a; \
																return (((iRangeData*)this)->*lib->b)

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

void RangeData::CopyTo(RangeData* dst)
{
	RangeSliderCall(CopyTo)(dst);
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
	RangeSliderCallR(NOTOK, GetRangesCount)();
}

Int RangeData::GetKnotsCount() const
{
	RangeSliderCallR(NOTOK, GetKnotsCount)();
}

Bool RangeData::SetKnotValue(Int nodeIndex, Float value)
{
	RangeSliderCallR(false, SetKnotValue)(nodeIndex, value);
}

Float RangeData::GetKnotValue(Int nodeIndex) const
{
	RangeSliderCallR(false, GetKnotValue)(nodeIndex);
}

Int RangeData::GetKnotIndexByValue(Float value) const
{
	RangeSliderCallR(false, GetKnotIndexByValue)(value);
}

void RangeData::DeleteKnot(Int nodeIndex)
{
	RangeSliderCall(DeleteKnot)(nodeIndex);
}

Float RangeData::GetCurrentValue() const
{
	RangeSliderCallR(0.0, GetCurrentValue)();
}

void RangeData::SetCurrentValue(Float value)
{
	RangeSliderCall(SetCurrentValue)(value);
}

RangePair RangeData::GetRange(Int index) const
{
	RangeSliderCallR(RangePair(), GetRange)(index);
}

Int RangeData::GetRangeIndex(Float value) const
{
	RangeSliderCallR(NOTOK, GetRangeIndex)(value);
}

Int RangeData::GetSelectedRange() const
{
	RangeSliderCallR(NOTOK, GetSelectedRange)();
}

Int RangeData::GetSelectedKnot() const
{
	RangeSliderCallR(NOTOK, GetSelectedKnot)();
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
	RangeSliderCallR(false, IsPerRangeColorMode)();
}

void RangeData::SetColorMode(Bool perRange)
{
	RangeSliderCall(SetColorMode)(perRange);
}

Vector RangeData::GetRangeColor(Int index) const
{
	RangeSliderCallR(Vector(), GetRangeColor)(index);
}

void RangeData::SetRangeColor(Int index, const Vector& color)
{
	RangeSliderCall(SetRangeColor)(index, color);
}

Bool RangeData::IsRandomColorMode() const
{
	RangeSliderCallR(false, IsRandomColorMode)();
}

void RangeData::SetRandomColorMode(Bool random)
{
	RangeSliderCall(SetRandomColorMode)(random);
}

void RangeData::Reset(Bool invalidateObject)
{
	RangeSliderCall(Reset)(invalidateObject);
}

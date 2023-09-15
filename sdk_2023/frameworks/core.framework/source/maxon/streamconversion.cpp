#include "maxon/streamconversion.h"

namespace maxon
{

template <typename SRCTYPE, typename DSTTYPE> MAXON_ATTRIBUTE_FORCE_INLINE Result<void> AddConversionTestSettingT(MAXON_SOURCE_LOCATION_DECLARATION, BaseArray<DataDictionary>& resultArray,
								const Block<const ConversionTestSet>& set, const Block<const SRCTYPE>& srcData, const Block<const DSTTYPE>& compareData, Bool forbidLargeTest)
{
	DataDictionary res;
	BaseArray<ConversionTestSet> conversionSet;

	iferr_scope;

	conversionSet.CopyFrom(set) iferr_return;

	res.Set(STREAMCONVERSIONTEST::SOURCELOCATION, MAXON_SOURCE_LOCATION_FORWARD) iferr_return;
	res.Set(STREAMCONVERSIONTEST::CONVERSIONTESTSET, std::move(conversionSet)) iferr_return;
	res.Set(STREAMCONVERSIONTEST::FORBIDSOURCEDUPLICATION, forbidLargeTest) iferr_return;

	if (srcData.GetCount())
	{
		BaseArray<SRCTYPE> array;
		array.CopyFrom(srcData) iferr_return;
		Data tmp;
		tmp.Set(std::move(array)) iferr_return;
		res.SetData(ConvertKeyToDataPtr<IsDerived<maxon::RESTRICT>, false>(STREAMCONVERSIONTEST::SRCDATA.Get()), std::move(tmp)) iferr_return;
	}

	if (compareData.GetCount())
	{
		BaseArray<DSTTYPE> array;
		array.CopyFrom(compareData) iferr_return;
		Data tmp;
		tmp.Set(std::move(array)) iferr_return;
		res.SetData(ConvertKeyToDataPtr<IsDerived<maxon::RESTRICT>, false>(STREAMCONVERSIONTEST::COMPAREDATA.Get()), std::move(tmp)) iferr_return;
	}

	resultArray.Append(res) iferr_return;

	return OK;
}

Result<void> AddConversionTestSetting(MAXON_SOURCE_LOCATION_DECLARATION, BaseArray<DataDictionary>& resultArray, const Block<const ConversionTestSet>& set, const Block<const Char>& srcData, const Block<const Char>& compareData, Bool forbidLargeTest)
{
	return AddConversionTestSettingT(MAXON_SOURCE_LOCATION_FORWARD, resultArray, set, srcData, compareData, forbidLargeTest);
}

Result<void> AddConversionTestSetting(MAXON_SOURCE_LOCATION_DECLARATION, BaseArray<DataDictionary>& resultArray, const Block<const ConversionTestSet>& set, const Block<const Utf32Char>& srcData, const Block<const Char>& compareData, Bool forbidLargeTest)
{
	return AddConversionTestSettingT(MAXON_SOURCE_LOCATION_FORWARD, resultArray, set, srcData, compareData, forbidLargeTest);
}

Result<void> AddConversionTestSetting(MAXON_SOURCE_LOCATION_DECLARATION, BaseArray<DataDictionary>& resultArray, const Block<const ConversionTestSet>& set, const Block<const Char>& srcData, const Block<const Utf32Char>& compareData, Bool forbidLargeTest)
{
	return AddConversionTestSettingT(MAXON_SOURCE_LOCATION_FORWARD, resultArray, set, srcData, compareData, forbidLargeTest);
}

Result<void> AddConversionTestSetting(MAXON_SOURCE_LOCATION_DECLARATION, BaseArray<DataDictionary>& resultArray, const Block<const ConversionTestSet>& set, const Block<const Utf32Char>& srcData, const Block<const Utf32Char>& compareData, Bool forbidLargeTest)
{
	return AddConversionTestSettingT(MAXON_SOURCE_LOCATION_FORWARD, resultArray, set, srcData, compareData, forbidLargeTest);
}


}

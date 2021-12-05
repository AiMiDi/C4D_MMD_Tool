#ifndef DATADICTIONARY_H__
#define DATADICTIONARY_H__

#include "maxon/datadictionaryiterator.h"
#include "maxon/hashmap.h"
#include "maxon/fid.h"
#include "maxon/array.h"

namespace maxon
{

/// @addtogroup DATATYPE
/// @{

class DataDictionary;


//----------------------------------------------------------------------------------------
/// Class to store and find any data type under any type of key.
/// @code
/// 	DataDictionary values;
/// 	values.Set(Data("MachineName"_s), Data(Application::GetMachineInfo().Get(MACHINEINFO::COMPUTERNAME)));
/// 	values.Set(Data(Int(100)),                   Data(Application::GetMachineInfo().Get(MACHINEINFO::OSVERSION)));
/// 	values.Set(Data(Vector(1, 0, 0)),            Data(String::IntToString(Application::GetMachineInfo().Get(MACHINEINFO::NUMBEROFPROCESSORS))));
/// @endcode
//----------------------------------------------------------------------------------------
class DataDictionaryInterface
{
	MAXON_INTERFACE_NONVIRTUAL(DataDictionaryInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.interface.datadictionary");

public:
	//----------------------------------------------------------------------------------------
	/// Set Data under a specific id.
	/// @param[in] key								Key under which the data is stored.
	/// @param[in] data								Reference to the data.
	/// @return												OK on success.
	/// @MAXON_ANNOTATION{returnsThis}
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> SetData(ForwardingDataPtr&& key, const Data& data);

	//----------------------------------------------------------------------------------------
	/// Set Data under a specific id.
	/// @param[in] key								Key under which the data should be stored.
	/// @param[in] data								Reference to the data.
	/// @return												OK on success.
	/// @MAXON_ANNOTATION{returnsThis}
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> SetData(ForwardingDataPtr&& key, Data&& data);

	//----------------------------------------------------------------------------------------
	/// Get data stored under a specific id.
	/// @param[in] key								Key under which the data should be stored.
	/// @return												Data as Data class.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Data> GetData(const ConstDataPtr& key) const;

	//----------------------------------------------------------------------------------------
	/// Check if there is data stored under a specific key.
	/// @param[in] key								Key under which the data should be stored.
	/// @return												True if existent.
	//----------------------------------------------------------------------------------------
	template <typename KEY> MAXON_FUNCTION Bool Existing(KEY&& key) const
	{
		iferr (Data data = DataDictionaryInterface::GetData(ConvertKeyToDataPtr<IsDerived<maxon::RESTRICT>, false>(std::forward<KEY>(key))))
			return false;

		return true;
	}

	//----------------------------------------------------------------------------------------
	/// Remove a data entry from the dictionary. This function doesn't check if the dictionary contained the key.
	/// @param[in] key								Key under which the data is stored.
	/// @return												OK on success. This function doesn't check if the dictionary contained the key.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> EraseData(const ConstDataPtr& key);
	
	//----------------------------------------------------------------------------------------
	/// Frees the entire dictionary. After this call the DataDictionary is empty.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void Reset();

	//----------------------------------------------------------------------------------------
	/// Checks if the dictionary is empty.
	/// @return												True if the dictionary does not contain any elements.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool IsEmpty() const;

	//----------------------------------------------------------------------------------------
	/// Checks if the dictionary contains anything.
	/// @return												True if the dictionary contains any elements.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION Bool IsPopulated() const
	{
		return !IsEmpty();
	}

	//----------------------------------------------------------------------------------------
	/// Returns a readable string of the content.
	/// @param[in] formatStatement		Nullptr or additional formatting instruction. Currently no additional formatting instructions are supported.
	/// @return												The converted result.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD String ToString(const FormatStatement* formatStatement) const;

	//----------------------------------------------------------------------------------------
	/// Describe all elements of this class for I/O operations.
	/// @param[in] stream							The stream that is used to register the class members.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> DescribeIO(const DataSerializeInterface& stream);

	//----------------------------------------------------------------------------------------
	/// Compares this DataDictionary with another if both are identical.
	/// @param[in] other							The other DataDictionary to compare this object with.
	/// @return												True if the object is identical.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool IsEqual(const DataDictionaryInterface* other, EQUALITY equality) const;

	//----------------------------------------------------------------------------------------
	/// Returns a hash code for this DataDictionary which depends on the content.
	/// @return												Hash code for the dictionary.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD UInt GetHashCode() const;

	//----------------------------------------------------------------------------------------
	/// Get data stored under a specific key. If the key is not found an error will be returned.
	/// This functions offers 2 possible calls. First using an FId "dict.Get(MAXCHINEINFO::COMPUTERNAME)" or second using any type directly together with the result type "dict.Get<String>(Int32(5))".
	/// The data type needs to be registered.
	/// @param[in] key								Key under which the data is stored.
	/// @return												Data converted to the right type on success.
	//----------------------------------------------------------------------------------------
	template <typename T = void, typename KEY> MAXON_FUNCTION Result<typename std::conditional<IsFidClass<KEY>::value, typename IsFidClass<KEY>::type, T>::type> Get(KEY&& key) const
	{
		using TT = typename std::conditional<IsFidClass<KEY>::value, typename IsFidClass<KEY>::type, T>::type;
		iferr (Data data = DataDictionaryInterface::GetData(ConvertKeyToDataPtr<IsDerived<maxon::RESTRICT>, false>(std::forward<KEY>(key))))
			return err;
		iferr (auto&& res = data.template Get<TT>())
			return err;
		MAXON_WARNING_PUSH
		MAXON_WARNING_DISABLE_REDUNDANT_MOVE
		return std::move(res);
		MAXON_WARNING_POP
	}

	//----------------------------------------------------------------------------------------
	/// Get data stored under a specific key. If the key is not found the given default value will be returned.
	/// This functions offers 2 possible calls. First using an FId "dict.Get(MAXCHINEINFO::COMPUTERNAME, String())" or second using any type directly together with the result type "dict.Get(Int32(5), String())".
	/// The data type needs to be registered.
	/// @param[in] key								Key under which the data is stored.
	/// @param[in] defaultValue				Default value which should be returned if the key cannot be found.
	/// @return												Data converted to the right type if found in the dictionary, otherwise the default value.
	//----------------------------------------------------------------------------------------
	template <typename T, typename KEY>
	MAXON_FUNCTION typename std::conditional<IsFidClass<KEY>::value, typename IsFidClass<KEY>::type, T>::type Get(KEY&& key, const T& defaultValue) const
	{
		using TT = typename std::conditional<IsFidClass<KEY>::value, typename IsFidClass<KEY>::type, T>::type;
		iferr (Data data = DataDictionaryInterface::GetData(ConvertKeyToDataPtr<IsDerived<maxon::RESTRICT>, false>(std::forward<KEY>(key))))
			return defaultValue;
		iferr (auto&& res = data.template Get<TT>())
			return defaultValue;
		MAXON_WARNING_PUSH
		MAXON_WARNING_DISABLE_REDUNDANT_MOVE
		return std::move(res);
		MAXON_WARNING_POP
	}

	//----------------------------------------------------------------------------------------
	/// Get data stored under a specific key. If the key is not found the given default value will be returned.
	/// This functions offers 2 possible calls. First using an FId "dict.Get(MAXCHINEINFO::COMPUTERNAME, String())" or second using any type directly together with the result type "dict.Get(Int32(5), String())".
	/// The data type needs to be registered.
	/// @param[in] key								Key under which the data is stored.
	/// @param[in] defaultValue				Default value which should be returned if the key cannot be found.
	/// @return												Data converted to the right type if found in the dictionary, otherwise the default value.
	//----------------------------------------------------------------------------------------
	template <typename T, typename KEY>
	MAXON_FUNCTION typename std::conditional<IsFidClass<KEY>::value, typename IsFidClass<KEY>::type, T>::type Get(KEY&& key, T&& defaultValue) const
	{
		using TT = typename std::conditional<IsFidClass<KEY>::value, typename IsFidClass<KEY>::type, T>::type;
		MAXON_WARNING_PUSH
		MAXON_WARNING_DISABLE_REDUNDANT_MOVE
		iferr (Data data = DataDictionaryInterface::GetData(ConvertKeyToDataPtr<IsDerived<maxon::RESTRICT>, false>(std::forward<KEY>(key))))
			return std::move(defaultValue);
		iferr (auto&& res = data.template Get<TT>())
			return std::move(defaultValue);
		return std::move(res);
		MAXON_WARNING_POP
	}

	//----------------------------------------------------------------------------------------
	/// Get data stored under a specific key. If the key is not found the given default value will be returned.
	/// This functions offers 2 possible calls. First using an FId "dict.Get(MAXCHINEINFO::COMPUTERNAME, String())" or second using any type directly together with the result type "dict.Get(Int32(5), String())".
	/// The data type needs to be registered.
	/// @param[in] key								Key under which the data is stored.
	/// @return												Data converted to the right type if found in the dictionary, otherwise the default value.
	//----------------------------------------------------------------------------------------
	template <typename KEY>
	MAXON_FUNCTION typename IsFidClass<KEY>::type GetOrDefault(KEY&& key) const;

	//----------------------------------------------------------------------------------------
	/// Set data under a specific id. this function is template to allow implicit Set calls for each data type.
	/// This functions offers 2 possible calls. First using an FId "dict.Set(MAXCHINEINFO::COMPUTERNAME, "data"_s)" or second using any type directly "dict.Set(Int32(5), "data"_s)".
	/// The data type needs to be registered.
	/// @param[in] key								Key under which the data is stored.
	/// @param[in] data								Data to be stored in the dictionary.
	/// @return												OK on success.
	/// @MAXON_ANNOTATION{returnsThis}
	//----------------------------------------------------------------------------------------
	template <typename T, typename KEY> MAXON_FUNCTION Result<void> Set(KEY&& key, T&& data)
	{
		using TT = typename std::conditional<IsFidClass<KEY>::value && !std::is_same<typename IsFidClass<KEY>::type, Data>::value, typename maxon::Substitute<T, typename IsFidClass<KEY>::type>::type, T>::type;
		Data tmp;
		iferr (tmp.Set(std::forward<TT>(data)))
			return err;
		return DataDictionaryInterface::SetData(ConvertKeyToDataPtr<IsDerived<maxon::RESTRICT>, false>(std::forward<KEY>(key)), std::move(tmp));
	}

	//----------------------------------------------------------------------------------------
	/// Erase data stored under a specific key. This function doesn't check if the dictionary contained the key.
	/// This functions offers 2 possible calls. First using an FId "dict.Erase(MAXCHINEINFO::COMPUTERNAME)" or second using any type directly "dict.Erase(Int32(5))".
	/// The data type needs to be registered.
	/// @param[in] key								Key under which the data is stored.
	/// @return												OK on success. This function doesn't check if the dictionary contained the key.
	//----------------------------------------------------------------------------------------
	template <typename KEY> MAXON_FUNCTION Result<void> Erase(KEY&& key)
	{
		return DataDictionaryInterface::EraseData(ConvertKeyToDataPtr<IsDerived<maxon::RESTRICT>, false>(std::forward<KEY>(key)));
	}

	//----------------------------------------------------------------------------------------
	/// Returns a copy of the data stored under a specific id. Can be used for types that do
	/// no support copy assignment.
	/// @param[in] key								Key under which the data is stored.
	/// @param[out] dst								Used to return the data.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	template <typename T, typename KEY> MAXON_FUNCTION Result<void> GetCopy(KEY&& key, T& dst) const
	{
		iferr (const Data& data = DataDictionaryInterface::GetData(ConvertKeyToDataPtr<IsDerived<maxon::RESTRICT>, false>(std::forward<KEY>(key))))
			return err;
		return GetCopyHelper(data, dst, OVERLOAD_MAX_RANK);
	}

	using Iterator = DataDictionaryIterator;
	using ConstIterator = DataDictionaryIterator;

	//----------------------------------------------------------------------------------------
	/// Helper functions for iterator.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void InitIterator(DataDictionaryIteratorInterface* iterator, Bool end) const;

	//----------------------------------------------------------------------------------------
	/// Returns the begin iterator of the DataDictionary. You can use the Iterator to run through all elements of the DataDictionary.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION ConstIterator Begin() const
	{
		return ConstIterator(this, false);
	}

	//----------------------------------------------------------------------------------------
	/// Returns the end iterator of the DataDictionary. You can use the Iterator to run through all elements of the DataDictionary.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION ConstIterator End() const
	{
		return ConstIterator(this, true);
	}

	//----------------------------------------------------------------------------------------
	/// Get data stored under a specific id.
	/// @param[in] key								Key under which the data should be stored.
	/// @return												Pointer to internal data, or nullptr if there is no value for key.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const Data* PrivateGetData(const ConstDataPtr& key) const;

private:
	template <typename T> Result<void> GetCopyHelper(const Data& data, T& dst, OverloadRank0) const
	{
		const T* src = data.template GetPtr<T>();
		if (src == nullptr)
			return IllegalStateErrorObject();

		// Use AssignCopy/CopyFrom To support types for which copy assignment might fail.
		iferr (AssignCopy(dst, *src))
			return err;

		return OK;
	}

	template <typename T> typename std::enable_if<GetCollectionKind<T>::value == COLLECTION_KIND::ARRAY, Result<void>>::type GetCopyHelper(const Data& data, T& dst, OverloadRank1) const
	{
		using ArrayType = Array<typename T::ValueType>;
		const ArrayType* src = data.template GetPtr<ArrayType>();
		if (src == nullptr)
			return IllegalStateErrorObject();

		if (src->GetPointer())
		{
			iferr (dst.CopyFrom(*(src->GetPointer())))
				return err;
		}

		return OK;
	}
};


// include autogenerated headerfile here
#include "datadictionary1.hxx"


// include autogenerated headerfile here
#include "datadictionary2.hxx"

#if (defined MAXON_TARGET_WINDOWS) && (defined MAXON_TARGET_DEBUG)
	// definition for natvis file
	struct DataDictionaryNatVisHelper : public HashMap<Data, Data> {};
	static DataDictionaryNatVisHelper g_natvisHelperDataDictionary;
#endif

DataDictionaryIterator::DataDictionaryIterator(const DataDictionaryInterface* dict, Bool ends) : _hasIterator(true), _pair(NullValue<const Data&>(), NullValue<const Data&>())
{
	dict->InitIterator(GetIterator(), ends);
	if (!ends && GetIterator()->HasValue())
		GetIterator()->GetKeyAndData(_pair);
}

//----------------------------------------------------------------------------------------
/// MergeDataDictionaries combines the two given data dictionaries into the base dictionary.
/// The same keys in 'other' will overwrite the base values.
/// @param[in] base								Dictionary to merge as the base.
/// @param[in] other							Dictionary to merge into base. this values will overwrite values with the same key in 'base'.
/// @param[in] mergeSubContainers	True if sub dictionaries inside the dictionary should be merged recursively as well. False if the
/// 															dictionary is treated like atomic data.
/// @return												OK on success.
//----------------------------------------------------------------------------------------
Result<void> MergeDataDictionaries(DataDictionary& base, const DataDictionary& other, Bool mergeSubContainers);
Result<void> MergeDataDictionariesPreferBase(DataDictionary& base, const DataDictionary& other, Bool mergeSubContainers);

//----------------------------------------------------------------------------------------
/// GetDataDescriptionValueI returns a data description value from the data base.
/// @param[in] databaseScope			Database id.
/// @param[in] attributeData			Attribute to query.
/// @param[in] keyPtr							Key to query.
/// @return												Data on success.
//----------------------------------------------------------------------------------------
Result<Data> GetDataDescriptionValueI(const Id& databaseScope, const InternedId& attributeData, const ConstDataPtr& keyPtr);

//----------------------------------------------------------------------------------------
/// Returns the defined description value of any attribute.
/// Example usage:
/// @code
/// Int32 min = GetDataDescriptionValue(MACHINEINFO::NUMBEROFPROCESSORS, DESCRIPTION::DATA::BASE::MINVALUE) iferr_return;
/// Int32 max = GetDataDescriptionValue(MACHINEINFO::NUMBEROFPROCESSORS, DESCRIPTION::DATA::BASE::MAXVALUE) iferr_return;
/// @endcode
/// @param[in] attribute					Attribute to find.
/// @param[in] key								Value to return, e.g. DESCRIPTION::DATA::BASE::MAXVALUE.
/// @return												Requested value on success. The return type will be determined by the data type of ATTRIBUTETYPE.
//----------------------------------------------------------------------------------------
template <typename ATTRIBUTETYPE, typename KEY>
static Result<typename IsFidClass<ATTRIBUTETYPE>::type> GetDataDescriptionValue(ATTRIBUTETYPE&& attribute, KEY&& key)
{
	iferr_scope;
	using TT = typename IsFidClass<ATTRIBUTETYPE>::type;
	Data res = GetDataDescriptionValueI(attribute.GetDatabaseScope(), attribute.Get(), ConstDataPtr(key.Get())) iferr_return;
	auto&& x = res.Get<TT>() iferr_return;
	return std::move(x);
}
template <typename ATTRIBUTETYPE>
static Result<typename IsFidClass<ATTRIBUTETYPE>::type> GetDataDescriptionValue2(ATTRIBUTETYPE&& attribute, const ConstDataPtr& key)
{
	iferr_scope;
	using TT = typename IsFidClass<ATTRIBUTETYPE>::type;
	Data res = GetDataDescriptionValueI(attribute.GetDatabaseScope(), attribute.Get(), key) iferr_return;
	auto&& x = res.Get<TT>() iferr_return;
	return std::move(x);
}

//----------------------------------------------------------------------------------------
/// Returns the defined key value description of any attribute.
/// Example usage:
/// @code
/// BaseArray<Tuple<Id, Data>> dataTypeList = GetDataDescriptionValueFromKey(DESCRIPTION::DATA::BASE::DATATYPE, DESCRIPTION::DATA::BASE::ENUM) iferr_return;
/// @endcode
/// @param[in] attribute					Attribute to find.
/// @param[in] key								Value to return, e.g. DESCRIPTION::DATA::BASE::ENUM.
/// @return												Requested value on success. The return type will be determined by the data type of KEY.
//----------------------------------------------------------------------------------------
template <typename ATTRIBUTETYPE, typename KEY>
static Result<typename IsFidClass<KEY>::type> GetDataDescriptionValueFromKey(ATTRIBUTETYPE&& attribute, KEY&& key)
{
	iferr_scope;
	using TT = typename IsFidClass<KEY>::type;
	Data res = GetDataDescriptionValueI(attribute.GetDatabaseScope(), attribute.Get(), ConstDataPtr(key.Get())) iferr_return;
	auto&& x = res.Get<TT>() iferr_return;
	return std::move(x);
}

//----------------------------------------------------------------------------------------
// this fallback will be chosen if KEY has no DEFAULTVALUE defined in the headerfile.
//----------------------------------------------------------------------------------------
template <typename KEY> inline typename IsFidClass<KEY>::type GetDefaultFromFidIfAvailable(KEY&& key, OverloadRank0)
{
	using TT = typename IsFidClass<KEY>::type;
	return TT();
}

//----------------------------------------------------------------------------------------
// this overload will be chosen if KEY has a DEFAULTVALUE defined.
//----------------------------------------------------------------------------------------
template <typename KEY>
inline typename SFINAEHelper<typename IsFidClass<KEY>::type, decltype(std::remove_reference<KEY>::type::DEFAULTVALUE)>::type
GetDefaultFromFidIfAvailable(KEY&& key, OverloadRank2)
{
	return key.DEFAULTVALUE;
}

//----------------------------------------------------------------------------------------
/// Returns the Id of DESCRIPTION::DATA::BASE::DEFAULTVALUE.
//----------------------------------------------------------------------------------------
ConstDataPtr GetDefaultValueKey();

template <typename KEY>
typename IsFidClass<KEY>::type DataDictionaryInterface::GetOrDefault(KEY&& key) const
{
	using TT = typename IsFidClass<KEY>::type;
	MAXON_WARNING_PUSH
	MAXON_WARNING_DISABLE_REDUNDANT_MOVE
	ifnoerr (Data data = DataDictionaryInterface::GetData(ConstDataPtr(key.Get())))
	{
		ifnoerr (auto&& res = data.template Get<TT>())
			return std::move(res);
	}

	ifnoerr (TT r = GetDataDescriptionValue2(key, GetDefaultValueKey()))
		return std::move(r);

	return GetDefaultFromFidIfAvailable(key, OVERLOAD_MAX_RANK);
	MAXON_WARNING_POP
}

//----------------------------------------------------------------------------------------
/// TransferPropertyIfAvailable copies the value of src into dst if available.
/// @param[in] src								Source object.
/// @param[in] srcType						Source property type id.
/// @param[in] dst								Destination object.
/// @param[in] dstType						Destination property type id.
/// @return												OK on success.
//----------------------------------------------------------------------------------------
template <typename SRCCLASS, typename PROPSRCTYPE, typename DSTCLASS, typename PROPDSTTYPE>
inline Result<void> TransferPropertyIfAvailable(const SRCCLASS& src, PROPSRCTYPE&& srcType, DSTCLASS& dst, PROPDSTTYPE&& dstType)
{
	iferr_scope;
	ifnoerr (auto data = src.Get(std::move(srcType)))
	{
		dst.Set(std::move(dstType), std::move(data)) iferr_return;
	}
	return OK;
}


/// @}

} // namespace maxon

#endif // DATADICTIONARY_H__

#ifndef DATADICTIONARYOBJECT_H__
#define DATADICTIONARYOBJECT_H__

#include "maxon/datatype.h"
#include "maxon/datadictionary.h"
#include "maxon/objectbase.h"

namespace maxon
{


template <typename INTERFACE> struct DataDictionaryKeySet
{
	template <typename CHECK> struct Check
	{
		template <typename... BASES> struct BasesHandler
		{
			static const Int mask = Or<Int, DataDictionaryKeySet<BASES>::template Check<CHECK>::mask...>::value;
		};
		// bit 0 set: there is an interface with RESTRICT_DICTIONARY_PROPS member which allows CHECK
		// bit 1 set: there is an interface with RESTRICT_DICTIONARY_PROPS member
		// i.e., the key is allowed when the value is not 2
		static const Int mask = (GetRestrict<INTERFACE>::value ? (std::is_base_of<typename GetRestrict<INTERFACE>::type, CHECK>::value ? 3 : 2) : 0)
			| INTERFACE::Hxx1::template SubstituteBases<BasesHandler>::mask;
		static const Bool value = mask != 2;
	};
};

class DataDictionaryObjectRef;

/// @addtogroup DATATYPE
/// @{

//----------------------------------------------------------------------------------------
/// Class to store and find any data type under any type of key.
/// @code
/// 	DataDictionaryObjectRef values;
/// 	values.Set(Data("MachineName"_s), Data(Application::GetMachineInfo().Get(MACHINEINFO::COMPUTERNAME)));
/// 	values.Set(Data(Int(100)),                   Data(Application::GetMachineInfo().Get(MACHINEINFO::OSVERSION)));
/// 	values.Set(Data(Vector(1, 0, 0)),            Data(String::IntToString(Application::GetMachineInfo().Get(MACHINEINFO::NUMBEROFPROCESSORS))));
/// @endcode
//----------------------------------------------------------------------------------------
class DataDictionaryObjectInterface : MAXON_INTERFACE_BASES(ObjectInterface)
{
	MAXON_INTERFACE(DataDictionaryObjectInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.datadictionaryobject");

public:
	//----------------------------------------------------------------------------------------
	/// Set Data under a specific id.
	/// the data type needs to be registered.
	/// @param[in] key								Id under which the data is stored.
	/// @param[in,out] data						Move reference to the data.
	/// @return												OK on success.
	/// @MAXON_ANNOTATION{returnsThis}
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> SetData(ForwardingDataPtr&& key, Data&& data);

	//----------------------------------------------------------------------------------------
	/// Set Data under a specific id.
	/// @param[in] key								Id under which the data is stored.
	/// @param[in] data								Reference to the data.
	/// @return												OK on success.
	/// @MAXON_ANNOTATION{returnsThis}
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION Result<void> SetData(ForwardingDataPtr&& key, const Data& data)
	{
		iferr_scope;
		Data d;
		d.CopyFrom(data) iferr_return;
		return SetData(std::move(key), std::move(d));
	}

	//----------------------------------------------------------------------------------------
	/// Get data stored under a specific id.
	/// @param[in] key								Id under which the data is stored.
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
		iferr (Data data = GetData(ConvertKeyToDataPtr<IsDerived<maxon::RESTRICT>, false>(std::forward<KEY>(key))))
			return false;

		return true;
	}
	//----------------------------------------------------------------------------------------
	/// Remove a data entry from the dictionary. This function doesn't check if the dictionary contained the key.
	/// @param[in] key								Id under which the data is stored.
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
	/// @MAXON_ANNOTATION{default=true}
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
	/// Get data stored under a specific key. If the key is not found an error will be returned.
	/// This functions offers 2 possible calls. First using an FId "dict.Get(MAXCHINEINFO::COMPUTERNAME)" or second using any type directly together with the result type "dict.Get<String>(Int32(5))".
	/// The data type needs to be registered.
	/// @param[in] key								Key under which the data is stored.
	/// @return												Data converted to the right type on success.
	/// @MAXON_ANNOTATION{refclassParameter=REFCLASS}
	//----------------------------------------------------------------------------------------
	template <typename REFCLASS, typename T = void, typename KEY>
	MAXON_FUNCTION Result<typename std::conditional<IsFidClass<KEY>::value, typename IsFidClass<KEY>::type, T>::type> Get(KEY&& key) const
	{
		using TT = typename std::conditional<IsFidClass<KEY>::value, typename IsFidClass<KEY>::type, T>::type;
		iferr (Data data = DataDictionaryObjectInterface::GetData(ConvertKeyToDataPtr<DataDictionaryKeySet<typename REFCLASS::ReferencedType>, false>(std::forward<KEY>(key))))
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
	/// @MAXON_ANNOTATION{refclassParameter=REFCLASS}
	//----------------------------------------------------------------------------------------
	template <typename REFCLASS, typename T, typename KEY>
	MAXON_FUNCTION typename std::conditional<IsFidClass<KEY>::value, typename IsFidClass<KEY>::type, T>::type Get(KEY&& key, const T& defaultValue) const
	{
		using TT = typename std::conditional<IsFidClass<KEY>::value, typename IsFidClass<KEY>::type, T>::type;
		iferr (Data data = DataDictionaryObjectInterface::GetData(ConvertKeyToDataPtr<DataDictionaryKeySet<typename REFCLASS::ReferencedType>, false>(std::forward<KEY>(key))))
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
	/// @MAXON_ANNOTATION{refclassParameter=REFCLASS}
	//----------------------------------------------------------------------------------------
	template <typename REFCLASS, typename T, typename KEY>
	MAXON_FUNCTION typename std::conditional<IsFidClass<KEY>::value, typename IsFidClass<KEY>::type, T>::type Get(KEY&& key, T&& defaultValue) const
	{
		using TT = typename std::conditional<IsFidClass<KEY>::value, typename IsFidClass<KEY>::type, T>::type;
		MAXON_WARNING_PUSH
		MAXON_WARNING_DISABLE_REDUNDANT_MOVE
		iferr (Data data = DataDictionaryObjectInterface::GetData(ConvertKeyToDataPtr<DataDictionaryKeySet<typename REFCLASS::ReferencedType>, false>(std::forward<KEY>(key))))
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
	/// @MAXON_ANNOTATION{returnsThis,refclassParameter=REFCLASS}
	//----------------------------------------------------------------------------------------
	template <typename REFCLASS, typename T, typename KEY> MAXON_FUNCTION Result<void> Set(KEY&& key, T&& data)
	{
		using TT = typename std::conditional<IsFidClass<KEY>::value && !std::is_same<typename IsFidClass<KEY>::type, Data>::value, typename maxon::Substitute<T, typename IsFidClass<KEY>::type>::type, T>::type;
		Data tmp;
		iferr (tmp.Set(std::forward<TT>(data)))
			return err;
		return DataDictionaryObjectInterface::SetData(ConvertKeyToDataPtr<DataDictionaryKeySet<typename REFCLASS::ReferencedType>, false>(std::forward<KEY>(key)), std::move(tmp));
	}

	//----------------------------------------------------------------------------------------
	/// Erase data stored under a specific key. This function doesn't check if the dictionary contained the key.
	/// This functions offers 2 possible calls. First using an FId "dict.Erase(MAXCHINEINFO::COMPUTERNAME)" or second using any type directly "dict.Erase(Int32(5))".
	/// The data type needs to be registered.
	/// @param[in] key								Key under which the data is stored.
	/// @return												OK on success. This function doesn't check if the dictionary contained the key.
	/// @MAXON_ANNOTATION{refclassParameter=REFCLASS}
	//----------------------------------------------------------------------------------------
	template <typename REFCLASS, typename KEY> MAXON_FUNCTION Result<void> Erase(KEY&& key)
	{
		return DataDictionaryObjectInterface::EraseData(ConvertKeyToDataPtr<DataDictionaryKeySet<typename REFCLASS::ReferencedType>, false>(std::forward<KEY>(key)));
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
};



//----------------------------------------------------------------------------------------
/// Extends DataDictionaryObjectInterface to wrap a DataDictionary into a DataDictionaryObjectInterface.
/// @code
/// 	DataDictionaryObjectRef values;
/// 	values.Set(Data("MachineName"_s), Data(Application::GetMachineInfo().Get(MACHINEINFO::COMPUTERNAME)));
/// 	values.Set(Data(Int(100)),                   Data(Application::GetMachineInfo().Get(MACHINEINFO::OSVERSION)));
/// 	values.Set(Data(Vector(1, 0, 0)),            Data(String::IntToString(Application::GetMachineInfo().Get(MACHINEINFO::NUMBEROFPROCESSORS))));
/// @endcode
//----------------------------------------------------------------------------------------
class DataDictionaryReferenceObjectInterface : MAXON_INTERFACE_BASES(DataDictionaryObjectInterface)
{
	MAXON_INTERFACE(DataDictionaryReferenceObjectInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.datadictionaryreferenceobject");

public:
	/// @MAXON_ANNOTATION{returnsThis}
	MAXON_METHOD Result<void> Init(DataDictionary* reference);

	/// @MAXON_ANNOTATION{returnsThis}
	MAXON_METHOD Result<void> Init(const DataDictionary* reference);

	MAXON_METHOD const DataDictionary& GetDataContainer() const;
};

// include autogenerated headerfile here
#include "datadictionaryobject1.hxx"


//----------------------------------------------------------------------------------------
/// Implementation of the DataDictionaryObjectInterface without any data stored.
/// This class can be used as a base component for you own inherited classes which overrides SetData/GetData.
//----------------------------------------------------------------------------------------
MAXON_DECLARATION(Class<DataDictionaryObjectRef>, DataDictionaryObjectEmptyClass, "net.maxon.class.datadictionaryobjectempty");

//----------------------------------------------------------------------------------------
/// Implementation of the DataDictionaryObjectInterface without locking, so it's not threadsafe.
//----------------------------------------------------------------------------------------
MAXON_DECLARATION(Class<DataDictionaryObjectRef>, DataDictionaryObjectClass, "net.maxon.class.datadictionaryobject");

//----------------------------------------------------------------------------------------
/// Implementation of the DataDictionaryObjectInterface with a spinlock protected hashmap, so it's threadsafe.
//----------------------------------------------------------------------------------------
MAXON_DECLARATION(Class<DataDictionaryObjectRef>, DataDictionaryObjectLockedClass, "net.maxon.class.datadictionaryobjectlocked");

//----------------------------------------------------------------------------------------
/// Implementation of the DataDictionaryObjectInterface with a lockfree hashmap, so it's threadsafe.
//----------------------------------------------------------------------------------------
MAXON_DECLARATION(Class<DataDictionaryObjectRef>, DataDictionaryObjectSyncedClass, "net.maxon.class.datadictionaryobjectsynced");

//----------------------------------------------------------------------------------------
/// Implementation of the DataDictionaryObjectInterface with a reference to a DataDictionary. This allows to pass DataDictionary to all
/// functions expecting a DataDictionaryObjectRef.
//----------------------------------------------------------------------------------------
MAXON_DECLARATION(Class<DataDictionaryReferenceObjectRef>, DataDictionaryObjectReferenceClass, "net.maxon.class.datadictionaryobjectreference");


// include autogenerated headerfile here
#include "datadictionaryobject2.hxx"

DataDictionaryIterator::DataDictionaryIterator(const DataDictionaryObjectInterface* dict, Bool ends) : _hasIterator(true), _pair(NullValue<const Data&>(), NullValue<const Data&>())
{
	dict->InitIterator(GetIterator(), ends);
	if (!ends && GetIterator()->HasValue())
		GetIterator()->GetKeyAndData(_pair);
}

//----------------------------------------------------------------------------------------
/// Creates a DataDictionaryObjectRef for a given DataDictionary pointer. All calls to SetData, GetData, EraseData will be routed to the DataDictionary.
/// So this allows to pass a DataDictionary to all functions which expect a DataDictionaryObjectRef.
/// Important: the DataDictionary object needs to be saved and be valid all the time. Otherwise it will crash.
/// @param[in] reference					Pointer to a DataDictionary.
/// @return												DataDictionaryObjectRef which wraps the DataDictionary.
//----------------------------------------------------------------------------------------
Result<DataDictionaryObjectRef> CreateDataDictionaryReferenceObject(DataDictionary* reference);
Result<DataDictionaryObjectRef> CreateDataDictionaryReferenceObject(const DataDictionary* reference);

//----------------------------------------------------------------------------------------
/// Returns a DataDictionary copy the given DataDictionaryObjectRef.
/// @param[in] ref								Reference to a DataDictionaryObjectRef.
/// @return												DataDictionary with the copy of all data.
//----------------------------------------------------------------------------------------
Result<DataDictionary> GetDataDictionaryFromDataDictionaryObjectRef(const DataDictionaryObjectRef& ref);



template <typename KEY> 
typename IsFidClass<KEY>::type DataDictionaryObjectInterface::GetOrDefault(KEY&& key) const
{
	using TT = typename IsFidClass<KEY>::type;
	MAXON_WARNING_PUSH
	MAXON_WARNING_DISABLE_REDUNDANT_MOVE
	ifnoerr (Data data = DataDictionaryObjectInterface::GetData(ConstDataPtr(key.Get())))
	{
		ifnoerr (auto&& res = data.template Get<TT>())
			return std::move(res);
	}

	ifnoerr (TT r = GetDataDescriptionValue2(key, GetDefaultValueKey()))
		return std::move(r);

	return GetDefaultFromFidIfAvailable(key, OVERLOAD_MAX_RANK);
	MAXON_WARNING_POP
}



/// @}

} // namespace maxon

#endif // DATADICTIONARYOBJECT_H__

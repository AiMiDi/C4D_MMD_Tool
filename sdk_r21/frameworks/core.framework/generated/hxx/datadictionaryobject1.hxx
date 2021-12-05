#if 1
class DataDictionaryObjectRef;

struct DataDictionaryObjectInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, DataDictionaryObjectInterface>::value || ObjectInterface::HasBase::template Check<I>::value; static I* Cast(DataDictionaryObjectInterface* ptr) { return static_cast<I*>(static_cast<maxon::ObjectInterface*>(ptr)); } }; };
struct DataDictionaryObjectInterface::Hxx1
{
	class Reference;
	using ReferenceClass = DataDictionaryObjectRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ObjectInterface>;
	/// Intermediate helper class for DataDictionaryObjectInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using Iterator = DataDictionaryObjectInterface::Iterator;
		using ConstIterator = DataDictionaryObjectInterface::ConstIterator;
/// Get data stored under a specific id.
/// @param[in] key								Id under which the data is stored.
/// @return												Data as Data class.
		inline Result<Data> GetData(const ConstDataPtr& key) const;
/// Check if there is data stored under a specific key.
/// @param[in] key								Key under which the data should be stored.
/// @return												True if existent.
		template <typename KEY> inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type Existing(KEY&& key) const;
/// Checks if the dictionary is empty.
/// @return												True if the dictionary does not contain any elements.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type IsEmpty() const;
/// Checks if the dictionary contains anything.
/// @return												True if the dictionary contains any elements.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type IsPopulated() const;
/// Get data stored under a specific key. If the key is not found an error will be returned.
/// This functions offers 2 possible calls. First using an FId "dict.Get(MAXCHINEINFO::COMPUTERNAME)" or second using any type directly together with the result type "dict.Get<String>(Int32(5))".
/// The data type needs to be registered.
/// @param[in] key								Key under which the data is stored.
/// @return												Data converted to the right type on success.
		template <typename T = void, typename KEY> inline Result<typename std::conditional<IsFidClass<KEY>::value, typename IsFidClass<KEY>::type, T>::type> Get(KEY&& key) const;
/// Get data stored under a specific key. If the key is not found the given default value will be returned.
/// This functions offers 2 possible calls. First using an FId "dict.Get(MAXCHINEINFO::COMPUTERNAME, String())" or second using any type directly together with the result type "dict.Get(Int32(5), String())".
/// The data type needs to be registered.
/// @param[in] key								Key under which the data is stored.
/// @param[in] defaultValue				Default value which should be returned if the key cannot be found.
/// @return												Data converted to the right type if found in the dictionary, otherwise the default value.
		template <typename T, typename KEY> inline typename std::conditional<S::HAS_ERROR, maxon::Result<typename std::conditional<IsFidClass<KEY>::value, typename IsFidClass<KEY>::type, T>::type>, typename std::conditional<IsFidClass<KEY>::value, typename IsFidClass<KEY>::type, T>::type>::type Get(KEY&& key, const T& defaultValue) const;
/// Get data stored under a specific key. If the key is not found the given default value will be returned.
/// This functions offers 2 possible calls. First using an FId "dict.Get(MAXCHINEINFO::COMPUTERNAME, String())" or second using any type directly together with the result type "dict.Get(Int32(5), String())".
/// The data type needs to be registered.
/// @param[in] key								Key under which the data is stored.
/// @param[in] defaultValue				Default value which should be returned if the key cannot be found.
/// @return												Data converted to the right type if found in the dictionary, otherwise the default value.
		template <typename T, typename KEY> inline typename std::conditional<S::HAS_ERROR, maxon::Result<typename std::conditional<IsFidClass<KEY>::value, typename IsFidClass<KEY>::type, T>::type>, typename std::conditional<IsFidClass<KEY>::value, typename IsFidClass<KEY>::type, T>::type>::type Get(KEY&& key, T&& defaultValue) const;
/// Get data stored under a specific key. If the key is not found the given default value will be returned.
/// This functions offers 2 possible calls. First using an FId "dict.Get(MAXCHINEINFO::COMPUTERNAME, String())" or second using any type directly together with the result type "dict.Get(Int32(5), String())".
/// The data type needs to be registered.
/// @param[in] key								Key under which the data is stored.
/// @return												Data converted to the right type if found in the dictionary, otherwise the default value.
		template <typename KEY> inline typename std::conditional<S::HAS_ERROR, maxon::Result<typename IsFidClass<KEY>::type>, typename IsFidClass<KEY>::type>::type GetOrDefault(KEY&& key) const;
/// Helper functions for iterator.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type InitIterator(DataDictionaryIteratorInterface* iterator, Bool end) const;
/// Returns the begin iterator of the DataDictionary. You can use the Iterator to run through all elements of the DataDictionary.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<ConstIterator>, ConstIterator>::type Begin() const;
/// Returns the end iterator of the DataDictionary. You can use the Iterator to run through all elements of the DataDictionary.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<ConstIterator>, ConstIterator>::type End() const;
	};
	/// Intermediate helper class for DataDictionaryObjectInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, DataDictionaryObjectRef, true>::type&() const { return reinterpret_cast<const DataDictionaryObjectRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, DataDictionaryObjectRef, false>::type&() { return reinterpret_cast<const DataDictionaryObjectRef&>(this->GetBaseRef()); }
/// Set Data under a specific id.
/// the data type needs to be registered.
/// @param[in] key								Id under which the data is stored.
/// @param[in,out] data						Move reference to the data.
/// @return												OK on success.
		inline maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)> SetData(ForwardingDataPtr&& key, Data&& data) const;
/// Set Data under a specific id.
/// @param[in] key								Id under which the data is stored.
/// @param[in] data								Reference to the data.
/// @return												OK on success.
		inline maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)> SetData(ForwardingDataPtr&& key, const Data& data) const;
/// Remove a data entry from the dictionary. This function doesn't check if the dictionary contained the key.
/// @param[in] key								Id under which the data is stored.
/// @return												OK on success. This function doesn't check if the dictionary contained the key.
		inline Result<void> EraseData(const ConstDataPtr& key) const;
/// Frees the entire dictionary. After this call the DataDictionary is empty.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type Reset() const;
/// Set data under a specific id. this function is template to allow implicit Set calls for each data type.
/// This functions offers 2 possible calls. First using an FId "dict.Set(MAXCHINEINFO::COMPUTERNAME, "data"_s)" or second using any type directly "dict.Set(Int32(5), "data"_s)".
/// The data type needs to be registered.
/// @param[in] key								Key under which the data is stored.
/// @param[in] data								Data to be stored in the dictionary.
/// @return												OK on success.
		template <typename T, typename KEY> inline maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)> Set(KEY&& key, T&& data) const;
/// Erase data stored under a specific key. This function doesn't check if the dictionary contained the key.
/// This functions offers 2 possible calls. First using an FId "dict.Erase(MAXCHINEINFO::COMPUTERNAME)" or second using any type directly "dict.Erase(Int32(5))".
/// The data type needs to be registered.
/// @param[in] key								Key under which the data is stored.
/// @return												OK on success. This function doesn't check if the dictionary contained the key.
		template <typename KEY> inline Result<void> Erase(KEY&& key) const;
	};
	/// Intermediate helper class for DataDictionaryObjectInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, DataDictionaryObjectRef, false>::type&() { return reinterpret_cast<const DataDictionaryObjectRef&>(this->GetBaseRef()); }
/// Set Data under a specific id.
/// the data type needs to be registered.
/// @param[in] key								Id under which the data is stored.
/// @param[in,out] data						Move reference to the data.
/// @return												OK on success.
		inline maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)> SetData(ForwardingDataPtr&& key, Data&& data);
/// Set Data under a specific id.
/// @param[in] key								Id under which the data is stored.
/// @param[in] data								Reference to the data.
/// @return												OK on success.
		inline maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)> SetData(ForwardingDataPtr&& key, const Data& data);
/// Remove a data entry from the dictionary. This function doesn't check if the dictionary contained the key.
/// @param[in] key								Id under which the data is stored.
/// @return												OK on success. This function doesn't check if the dictionary contained the key.
		inline Result<void> EraseData(const ConstDataPtr& key);
/// Frees the entire dictionary. After this call the DataDictionary is empty.
		inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type Reset();
/// Set data under a specific id. this function is template to allow implicit Set calls for each data type.
/// This functions offers 2 possible calls. First using an FId "dict.Set(MAXCHINEINFO::COMPUTERNAME, "data"_s)" or second using any type directly "dict.Set(Int32(5), "data"_s)".
/// The data type needs to be registered.
/// @param[in] key								Key under which the data is stored.
/// @param[in] data								Data to be stored in the dictionary.
/// @return												OK on success.
		template <typename T, typename KEY> inline maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)> Set(KEY&& key, T&& data);
/// Erase data stored under a specific key. This function doesn't check if the dictionary contained the key.
/// This functions offers 2 possible calls. First using an FId "dict.Erase(MAXCHINEINFO::COMPUTERNAME)" or second using any type directly "dict.Erase(Int32(5))".
/// The data type needs to be registered.
/// @param[in] key								Key under which the data is stored.
/// @return												OK on success. This function doesn't check if the dictionary contained the key.
		template <typename KEY> inline Result<void> Erase(KEY&& key);
		explicit operator maxon::Bool() const MAXON_WORKAROUND_CLANG_DELETED_FUNCTION(S);
		explicit operator maxon::Bool() MAXON_WORKAROUND_CLANG_DELETED_FUNCTION(S);
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type> { };
};
class DataDictionaryObjectInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<DataDictionaryObjectRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<DataDictionaryObjectInterface, maxon::StrongRefHandler, DataDictionaryObjectRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<DataDictionaryObjectInterface, maxon::StrongRefHandler, DataDictionaryObjectRef>>>>);
	using NonConst = typename Super::ReferenceClass;
};

/// DataDictionaryObjectRef is the reference class of DataDictionaryObjectInterface.
///
/// Class to store and find any data type under any type of key.
/// @code
/// 	DataDictionaryObjectRef values;
/// 	values.Set(Data("MachineName"_s), Data(Application::GetMachineInfo().Get(MACHINEINFO::COMPUTERNAME)));
/// 	values.Set(Data(Int(100)),                   Data(Application::GetMachineInfo().Get(MACHINEINFO::OSVERSION)));
/// 	values.Set(Data(Vector(1, 0, 0)),            Data(String::IntToString(Application::GetMachineInfo().Get(MACHINEINFO::NUMBEROFPROCESSORS))));
/// @endcode
class DataDictionaryObjectRef : public DataDictionaryObjectInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(DataDictionaryObjectRef, typename DataDictionaryObjectInterface::Hxx1::Reference);
};

class DataDictionaryReferenceObjectRef;

struct DataDictionaryReferenceObjectInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, DataDictionaryReferenceObjectInterface>::value || DataDictionaryObjectInterface::HasBase::template Check<I>::value; static I* Cast(DataDictionaryReferenceObjectInterface* ptr) { return static_cast<I*>(static_cast<maxon::ObjectInterface*>(ptr)); } }; };
struct DataDictionaryReferenceObjectInterface::Hxx1
{
	class Reference;
	using ReferenceClass = DataDictionaryReferenceObjectRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<DataDictionaryObjectInterface>;
	/// Intermediate helper class for DataDictionaryReferenceObjectInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<const DataDictionary&>, const DataDictionary&>::type GetDataContainer() const;
	};
	/// Intermediate helper class for DataDictionaryReferenceObjectInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, DataDictionaryReferenceObjectRef, true>::type&() const { return reinterpret_cast<const DataDictionaryReferenceObjectRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, DataDictionaryReferenceObjectRef, false>::type&() { return reinterpret_cast<const DataDictionaryReferenceObjectRef&>(this->GetBaseRef()); }
		inline maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)> Init(DataDictionary* reference) const;
		inline maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)> Init(const DataDictionary* reference) const;
	};
	/// Intermediate helper class for DataDictionaryReferenceObjectInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, DataDictionaryReferenceObjectRef, false>::type&() { return reinterpret_cast<const DataDictionaryReferenceObjectRef&>(this->GetBaseRef()); }
		inline maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)> Init(DataDictionary* reference);
		inline maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)> Init(const DataDictionary* reference);
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename DataDictionaryObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename DataDictionaryObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename DataDictionaryObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type> { };
};
class DataDictionaryReferenceObjectInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<DataDictionaryReferenceObjectRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<DataDictionaryReferenceObjectInterface, maxon::StrongRefHandler, DataDictionaryReferenceObjectRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<DataDictionaryReferenceObjectInterface, maxon::StrongRefHandler, DataDictionaryReferenceObjectRef>>>>);
	using NonConst = typename Super::ReferenceClass;
};

/// DataDictionaryReferenceObjectRef is the reference class of DataDictionaryReferenceObjectInterface.
///
/// Extends DataDictionaryObjectInterface to wrap a DataDictionary into a DataDictionaryObjectInterface.
/// @code
/// 	DataDictionaryObjectRef values;
/// 	values.Set(Data("MachineName"_s), Data(Application::GetMachineInfo().Get(MACHINEINFO::COMPUTERNAME)));
/// 	values.Set(Data(Int(100)),                   Data(Application::GetMachineInfo().Get(MACHINEINFO::OSVERSION)));
/// 	values.Set(Data(Vector(1, 0, 0)),            Data(String::IntToString(Application::GetMachineInfo().Get(MACHINEINFO::NUMBEROFPROCESSORS))));
/// @endcode
class DataDictionaryReferenceObjectRef : public DataDictionaryReferenceObjectInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(DataDictionaryReferenceObjectRef, typename DataDictionaryReferenceObjectInterface::Hxx1::Reference);
};

#endif

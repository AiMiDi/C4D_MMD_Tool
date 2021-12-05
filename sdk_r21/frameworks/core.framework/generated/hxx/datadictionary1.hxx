#if 1
class DataDictionary;

struct DataDictionaryInterface::Hxx1
{
	class Reference;
	class NonConstRef;
	using ReferenceClass = DataDictionary;
	/// Intermediate helper class for DataDictionaryInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using Iterator = DataDictionaryInterface::Iterator;
		using ConstIterator = DataDictionaryInterface::ConstIterator;
/// Get data stored under a specific id.
/// @param[in] key								Key under which the data should be stored.
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
/// Returns a readable string of the content.
/// @param[in] formatStatement		Nullptr or additional formatting instruction. Currently no additional formatting instructions are supported.
/// @return												The converted result.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type ToString(const FormatStatement* formatStatement) const;
/// Describe all elements of this class for I/O operations.
/// @param[in] stream							The stream that is used to register the class members.
/// @return												OK on success.
		static inline Result<void> DescribeIO(const DataSerializeInterface& stream);
/// Compares this DataDictionary with another if both are identical.
/// @param[in] other							The other DataDictionary to compare this object with.
/// @return												True if the object is identical.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type IsEqual(const DataDictionaryInterface* other, EQUALITY equality) const;
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
/// Returns a copy of the data stored under a specific id. Can be used for types that do
/// no support copy assignment.
/// @param[in] key								Key under which the data is stored.
/// @param[out] dst								Used to return the data.
/// @return												OK on success.
		template <typename T, typename KEY> inline Result<void> GetCopy(KEY&& key, T& dst) const;
/// Helper functions for iterator.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type InitIterator(DataDictionaryIteratorInterface* iterator, Bool end) const;
/// Returns the begin iterator of the DataDictionary. You can use the Iterator to run through all elements of the DataDictionary.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<ConstIterator>, ConstIterator>::type Begin() const;
/// Returns the end iterator of the DataDictionary. You can use the Iterator to run through all elements of the DataDictionary.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<ConstIterator>, ConstIterator>::type End() const;
	};
	/// Intermediate helper class for DataDictionaryInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
/// Set Data under a specific id.
/// @param[in] key								Key under which the data is stored.
/// @param[in] data								Reference to the data.
/// @return												OK on success.
		inline maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)> SetData(ForwardingDataPtr&& key, const Data& data) const;
/// Set Data under a specific id.
/// @param[in] key								Key under which the data should be stored.
/// @param[in] data								Reference to the data.
/// @return												OK on success.
		inline maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)> SetData(ForwardingDataPtr&& key, Data&& data) const;
/// Remove a data entry from the dictionary. This function doesn't check if the dictionary contained the key.
/// @param[in] key								Key under which the data is stored.
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
	/// Intermediate helper class for DataDictionaryInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, DataDictionary, false>::type&() const { return reinterpret_cast<const DataDictionary&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, DataDictionary, false>::type&() { return reinterpret_cast<const DataDictionary&>(this->GetBaseRef()); }
/// Set Data under a specific id.
/// @param[in] key								Key under which the data is stored.
/// @param[in] data								Reference to the data.
/// @return												OK on success.
		inline maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)> SetData(ForwardingDataPtr&& key, const Data& data);
/// Set Data under a specific id.
/// @param[in] key								Key under which the data should be stored.
/// @param[in] data								Reference to the data.
/// @return												OK on success.
		inline maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)> SetData(ForwardingDataPtr&& key, Data&& data);
/// Remove a data entry from the dictionary. This function doesn't check if the dictionary contained the key.
/// @param[in] key								Key under which the data is stored.
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
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ST::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ST::type>, ReferenceFunctionsImpl<typename ST::type>>::type> { };
};
class DataDictionaryInterface::Hxx1::Reference :
#ifdef DOXYGEN
public COWReferenceFunctionsImplDoxy<DataDictionary>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const DataDictionaryInterface, maxon::StrongCOWRefHandler, DataDictionary>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const DataDictionaryInterface, maxon::StrongCOWRefHandler, DataDictionary>>>>);
	using NonConst = Hxx1::NonConstRef;
	static MAXON_ATTRIBUTE_FORCE_INLINE maxon::ResultMemT<DataDictionary> Create();
};

class DataDictionaryInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<NonConstRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<DataDictionaryInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<DataDictionaryInterface, maxon::StrongRefHandler, NonConstRef>>>>);
};

/// DataDictionary is the reference class of DataDictionaryInterface.
///
/// Class to store and find any data type under any type of key.
/// @code
/// 	DataDictionary values;
/// 	values.Set(Data("MachineName"_s), Data(Application::GetMachineInfo().Get(MACHINEINFO::COMPUTERNAME)));
/// 	values.Set(Data(Int(100)),                   Data(Application::GetMachineInfo().Get(MACHINEINFO::OSVERSION)));
/// 	values.Set(Data(Vector(1, 0, 0)),            Data(String::IntToString(Application::GetMachineInfo().Get(MACHINEINFO::NUMBEROFPROCESSORS))));
/// @endcode
class DataDictionary : public DataDictionaryInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(DataDictionary, typename DataDictionaryInterface::Hxx1::Reference);
};

#if (defined MAXON_TARGET_WINDOWS) && (defined MAXON_TARGET_DEBUG)
#endif
#endif

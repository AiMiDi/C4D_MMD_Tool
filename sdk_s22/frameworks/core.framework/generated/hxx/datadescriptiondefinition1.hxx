#if 1
class DataDescriptionDefinition;

struct DataDescriptionDefinitionInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, DataDescriptionDefinitionInterface>::value || ObserverObjectInterface::HasBase::template Check<I>::value; static I* Cast(DataDescriptionDefinitionInterface* ptr) { return static_cast<I*>(static_cast<maxon::ObjectInterface*>(ptr)); } }; };
struct DataDescriptionDefinitionInterface::Hxx1
{
	class Reference;
	class NonConstRef;
	using ReferenceClass = DataDescriptionDefinition;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ObserverObjectInterface>;
	/// Intermediate helper class for DataDescriptionDefinitionInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
/// Returns the info dictionary.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<DataDictionary>, DataDictionary>::type GetInfo() const;
/// Returns the number of entries in the description.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type GetEntryCount() const;
/// Returns a array with all entries.
		inline Result<BaseArray<DataDescriptionEntry>> GetEntries() const;
/// Returns a specific entry with the given index.
/// @param[in] idx								Index to return.
/// @return												Entry on success.
		inline Result<DataDescriptionEntry> GetEntry(Int idx) const;
/// FindEntry searches the first occurrence of the entry.
/// @param[in] id									Id to search.
/// @return												Entry on success.
		inline Result<DataDescriptionEntry> FindEntry(const InternedId& id) const;
/// Merges the given descriptions.
/// @param[in] target							Target description to overwrite.
/// @param[in] source							New entries to merge into target.
/// @param[in] overwriteIncludes	True to overwrite the includes of target id source has includes.
/// @return												OK on success.
		static inline Result<void> MergeDescriptionDefinition(DataDescriptionDefinition& target, const DataDescriptionDefinition& source, Bool overwriteIncludes, Bool skipIncludes);
		static inline Result<Data> GetDataDefaults(const DataDictionary& dataEntry);
		static inline Result<Data> GetDataValueOrDefaults(const InternedId& dataId, const DataDictionary& dataEntry, GETDATAFLAGS flags, const GetDataCallbackType& getDataCallback);
		static inline DataDescriptionDefinition Create();
		static inline const DataDescriptionDefinitionInterface* NullValuePtr();
	};
	/// Intermediate helper class for DataDescriptionDefinitionInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
/// SetInfo the info dictionary of the description.
/// @param[in] info								Dictionary with infos.
/// @return												OK on success.
		inline Result<void> SetInfo(const DataDictionary& info) const;
/// AddEntry to the description.
/// @param[in] props							Attribute to add to the end of the list.
/// @return												Index of the new attribute on success.
		inline Result<Int> AddEntry(const DataDescriptionEntry& props) const;
/// Replaces an entry.
/// @param[in] props							Properties to replace.
/// @return												OK on success.
		inline Result<void> ReplaceEntry(const DataDescriptionEntry& props) const;
/// Replaces an entry.
/// @param[in] idx								Index to replace.
/// @param[in] props							Properties to replace.
/// @return												True if changes were detected. False if the data was identical.
		inline Result<Bool> ReplaceEntry(Int idx, const DataDescriptionEntry& props) const;
/// EraseEntry an attribute from the description.
/// @param[in] idx								Index of the attribute to delete.
/// @return												OK on success.
		inline Result<void> EraseEntry(Int idx) const;
/// Resets the description and clear all attributes.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type Reset() const;
	};
	/// Intermediate helper class for DataDescriptionDefinitionInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, DataDescriptionDefinition, false>::type&() const { return reinterpret_cast<const DataDescriptionDefinition&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, DataDescriptionDefinition, false>::type&() { return reinterpret_cast<const DataDescriptionDefinition&>(this->GetBaseRef()); }
/// SetInfo the info dictionary of the description.
/// @param[in] info								Dictionary with infos.
/// @return												OK on success.
		inline Result<void> SetInfo(const DataDictionary& info);
/// AddEntry to the description.
/// @param[in] props							Attribute to add to the end of the list.
/// @return												Index of the new attribute on success.
		inline Result<Int> AddEntry(const DataDescriptionEntry& props);
/// Replaces an entry.
/// @param[in] props							Properties to replace.
/// @return												OK on success.
		inline Result<void> ReplaceEntry(const DataDescriptionEntry& props);
/// Replaces an entry.
/// @param[in] idx								Index to replace.
/// @param[in] props							Properties to replace.
/// @return												True if changes were detected. False if the data was identical.
		inline Result<Bool> ReplaceEntry(Int idx, const DataDescriptionEntry& props);
/// EraseEntry an attribute from the description.
/// @param[in] idx								Index of the attribute to delete.
/// @return												OK on success.
		inline Result<void> EraseEntry(Int idx);
/// Resets the description and clear all attributes.
		inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type Reset();
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ObserverObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ObserverObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename ObserverObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type> { };
};
class DataDescriptionDefinitionInterface::Hxx1::Reference :
#ifdef DOXYGEN
public COWReferenceFunctionsImplDoxy<DataDescriptionDefinition>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const DataDescriptionDefinitionInterface, maxon::StrongCOWRefHandler, DataDescriptionDefinition>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const DataDescriptionDefinitionInterface, maxon::StrongCOWRefHandler, DataDescriptionDefinition>>>>);
	using NonConst = Hxx1::NonConstRef;
};

class DataDescriptionDefinitionInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<NonConstRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<DataDescriptionDefinitionInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<DataDescriptionDefinitionInterface, maxon::StrongRefHandler, NonConstRef>>>>);
};

/// DataDescriptionDefinition is the reference class of DataDescriptionDefinitionInterface.
///
/// Interface to store descriptions definitions of objects. The DataDescription definition defines a sequence of "commands" to define
/// attributes, include, commands, strings, etc.
class DataDescriptionDefinition : public DataDescriptionDefinitionInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(DataDescriptionDefinition, typename DataDescriptionDefinitionInterface::Hxx1::Reference);
};

#endif

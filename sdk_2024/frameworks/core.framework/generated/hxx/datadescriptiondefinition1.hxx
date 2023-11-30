#if 1
class DataDescriptionDefinition;

struct DataDescriptionDefinitionInterface::HasBaseDetector { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, DataDescriptionDefinitionInterface>::value || ObjectInterface::HasBaseDetector::template Check<I>::value; static I* Cast(DataDescriptionDefinitionInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct DataDescriptionDefinitionInterface::Hxx1
{
	class Reference;
	class NonConstRef;
	using ReferenceClass = DataDescriptionDefinition;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ObjectInterface>;
	/// Intermediate helper class for DataDescriptionDefinitionInterface.
	template <typename S> class ConstFn DOXYGEN_SWITCH_REVERSED(, : public S)
	{
	public:
		ConstFn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = DataDescriptionDefinitionInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static ConstFn PrivateLookupFn(DataDescriptionDefinitionInterface**);
/// Returns the info dictionary.
		inline HXXADDRET2(DataDictionary) GetInfo() const;
/// Returns the number of entries in the description.
		inline HXXADDRET2(Int) GetEntryCount() const;
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
		static inline const DataDescriptionDefinitionInterface* DefaultValuePtr();
	};
	/// Intermediate helper class for DataDescriptionDefinitionInterface.
	template <typename S> class Fn : public ConstFn<S>
	{
	public:
		Fn() = default;
		using PrivateBaseClass = ConstFn<S>;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = DataDescriptionDefinitionInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static Fn PrivateLookupFn(DataDescriptionDefinitionInterface**);
/// SetInfo the info dictionary of the description.
/// @param[in] info								Dictionary with infos.
/// @return												OK on success.
		inline Result<void> SetInfo(const DataDictionary& info) const;
/// AddEntry to the description.
/// @param[in] props							Attribute to add to the end of the list.
/// @return												Index of the new attribute on success.
		inline Result<Int> AddEntry(const DataDescriptionEntry& props) const;
/// Replaces an entry. Will add a new entry if #props identifier is not found.
/// @param[in] props							Properties to replace.
/// @return												OK on success.
		inline Result<void> ReplaceEntry(const DataDescriptionEntry& props) const;
/// Replaces an entry.
/// @param[in] idx								Index to replace.
/// @param[in] props							Properties to replace.
/// @return												True if changes were detected. False if the data was identical. Error if #idx is invalid.
		inline Result<Bool> ReplaceEntry(Int idx, const DataDescriptionEntry& props) const;
/// Erase an attribute from the description.
/// @param[in] idx								Index of the attribute to delete.
/// @return												OK on success.
		inline Result<void> EraseEntry(Int idx) const;
/// Erase an attribute from the description.
/// @param[in] id									Id to erase.
/// @return												OK on success. Error if attribute is not found.
		inline Result<void> EraseEntry(const InternedId& id) const;
/// Resets the description and clear all attributes.
		inline HXXADDRET2(void) Reset() const;
	};
	/// Intermediate helper class for DataDescriptionDefinitionInterface.
	template <typename S> class COWFn : public ConstFn<S>
	{
	public:
		COWFn() = default;
		using PrivateBaseClass = ConstFn<S>;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = DataDescriptionDefinitionInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static COWFn PrivateLookupFn(DataDescriptionDefinitionInterface**);
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
/// Replaces an entry. Will add a new entry if #props identifier is not found.
/// @param[in] props							Properties to replace.
/// @return												OK on success.
		inline Result<void> ReplaceEntry(const DataDescriptionEntry& props);
/// Replaces an entry.
/// @param[in] idx								Index to replace.
/// @param[in] props							Properties to replace.
/// @return												True if changes were detected. False if the data was identical. Error if #idx is invalid.
		inline Result<Bool> ReplaceEntry(Int idx, const DataDescriptionEntry& props);
/// Erase an attribute from the description.
/// @param[in] idx								Index of the attribute to delete.
/// @return												OK on success.
		inline Result<void> EraseEntry(Int idx);
/// Erase an attribute from the description.
/// @param[in] id									Id to erase.
/// @return												OK on success. Error if attribute is not found.
		inline Result<void> EraseEntry(const InternedId& id);
/// Resets the description and clear all attributes.
		inline HXXADDRET1(void) Reset();
	};
	template <typename ST> struct FnHelper : public std::conditional<
	maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
	COWFn<typename ObjectInterface::Hxx1::template FnHelper<ST>::type>,
	typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstFn<typename ObjectInterface::Hxx1::template FnHelper<ST>::type>, Fn<typename ObjectInterface::Hxx1::template FnHelper<ST>::type>>::type
	> { };
};
class DataDescriptionDefinitionInterface::Hxx1::Reference :
#ifdef DOXYGEN
public COWFnDoxy<DataDescriptionDefinition>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<const DataDescriptionDefinitionInterface, maxon::StrongCOWRefHandler, DataDescriptionDefinition>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<const DataDescriptionDefinitionInterface, maxon::StrongCOWRefHandler, DataDescriptionDefinition>>>>);
	using NonConst = Hxx1::NonConstRef;
};

class DataDescriptionDefinitionInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public FnDoxy<NonConstRef>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<DataDescriptionDefinitionInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<DataDescriptionDefinitionInterface, maxon::StrongRefHandler, NonConstRef>>>>);
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

constexpr inline const maxon::Char* DT_LanguageStringDataDescriptionDefinition_CppName() { return "maxon::LanguageStringDataDescriptionDefinition"; }
#endif

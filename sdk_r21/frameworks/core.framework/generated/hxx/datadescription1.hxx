#if 1
class DataDescription;

struct DataDescriptionInterface::Hxx1
{
	class Reference;
	class NonConstRef;
	using ReferenceClass = DataDescription;
	/// Intermediate helper class for DataDescriptionInterface.
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
		inline Result<BaseArray<DataDictionary>> GetEntries() const;
/// Returns a specific entry with the given id.
/// @param[in] id									Id to find
/// @return												DataDictionary on success. Error if the requested attribute was not in the description-
		inline Result<DataDictionary> GetEntry(const InternedId& id) const;
/// Compares two descriptions.
/// @param[in] other							Other description to compare.
/// @param[in] equality						See @EQUALITY.
/// @return												True in equality.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type IsEqual(const DataDescriptionInterface* other, EQUALITY equality) const;
/// Compares the 2 values.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<COMPARERESULT>, COMPARERESULT>::type Compare(const DataDescriptionInterface* other) const;
/// Returns a readable string of the content.
/// @param[in] formatStatement		Nullptr or additional formatting instruction. Use "{N}" for nive formatting of the name only. Otherwise the unique id is printed together with the name.
/// @return												The converted result.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type ToString(const FormatStatement* formatStatement) const;
/// Describe all elements of this class for I/O operations.
/// @param[in] stream							The stream that is used to register the class members.
/// @return												OK on success.
		static inline Result<void> DescribeIO(const DataSerializeInterface& stream);
	};
	/// Intermediate helper class for DataDescriptionInterface.
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
/// SetEntry description.
/// @param[in] props							Properties to set. The DESCRIPTION::BASE::IDENTIFIER will be used as key for the hashmap.
/// @param[in] merge							True if the container should be merged with the existing props im the description. The given props will
///																have priority over the existing.
/// @return												true if properties has been changed.
		inline Result<Bool> SetEntry(const DataDictionary& props, Bool merge = false) const;
/// Deletes a attribute from the description.
/// @param[in] id									Id of the attribute to delete.
/// @return												OK on success.
		inline Result<void> EraseEntry(const InternedId& id) const;
/// Resets the description and clear all attributes.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type Reset() const;
	};
	/// Intermediate helper class for DataDescriptionInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, DataDescription, false>::type&() const { return reinterpret_cast<const DataDescription&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, DataDescription, false>::type&() { return reinterpret_cast<const DataDescription&>(this->GetBaseRef()); }
/// SetInfo the info dictionary of the description.
/// @param[in] info								Dictionary with infos.
/// @return												OK on success.
		inline Result<void> SetInfo(const DataDictionary& info);
/// SetEntry description.
/// @param[in] props							Properties to set. The DESCRIPTION::BASE::IDENTIFIER will be used as key for the hashmap.
/// @param[in] merge							True if the container should be merged with the existing props im the description. The given props will
///																have priority over the existing.
/// @return												true if properties has been changed.
		inline Result<Bool> SetEntry(const DataDictionary& props, Bool merge = false);
/// Deletes a attribute from the description.
/// @param[in] id									Id of the attribute to delete.
/// @return												OK on success.
		inline Result<void> EraseEntry(const InternedId& id);
/// Resets the description and clear all attributes.
		inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type Reset();
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ST::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ST::type>, ReferenceFunctionsImpl<typename ST::type>>::type> { };
};
class DataDescriptionInterface::Hxx1::Reference :
#ifdef DOXYGEN
public COWReferenceFunctionsImplDoxy<DataDescription>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const DataDescriptionInterface, maxon::StrongCOWRefHandler, DataDescription>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const DataDescriptionInterface, maxon::StrongCOWRefHandler, DataDescription>>>>);
	using NonConst = Hxx1::NonConstRef;
	static MAXON_ATTRIBUTE_FORCE_INLINE maxon::ResultMemT<DataDescription> Create();
};

class DataDescriptionInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<NonConstRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<DataDescriptionInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<DataDescriptionInterface, maxon::StrongRefHandler, NonConstRef>>>>);
};

/// DataDescription is the reference class of DataDescriptionInterface.
///
/// Interface to store descriptions of objects. The DataDescription object is a cow object. It stores a compiled version of the
/// DataDescriptionDefinitionRef for each datatype.
class DataDescription : public DataDescriptionInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(DataDescription, typename DataDescriptionInterface::Hxx1::Reference);
};

#endif

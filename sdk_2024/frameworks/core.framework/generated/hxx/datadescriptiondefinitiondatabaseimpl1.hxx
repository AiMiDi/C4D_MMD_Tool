#if 1
class DataDescriptionDefinitionDatabaseImplRef;

struct DataDescriptionDefinitionDatabaseImplInterface::HasBaseDetector { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, DataDescriptionDefinitionDatabaseImplInterface>::value || ObjectInterface::HasBaseDetector::template Check<I>::value; static I* Cast(DataDescriptionDefinitionDatabaseImplInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct DataDescriptionDefinitionDatabaseImplInterface::Hxx1
{
	class Reference;
	using ReferenceClass = DataDescriptionDefinitionDatabaseImplRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ObjectInterface>;
	/// Intermediate helper class for DataDescriptionDefinitionDatabaseImplInterface.
	template <typename S> class ConstFn DOXYGEN_SWITCH_REVERSED(, : public S)
	{
	public:
		ConstFn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = DataDescriptionDefinitionDatabaseImplInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static ConstFn PrivateLookupFn(DataDescriptionDefinitionDatabaseImplInterface**);
/// checks if the database contains the datatype.
/// @param[in] category						Database category (e.g. DATADESCRIPTION_CATEGORY_DATA / DATADESCRIPTION_CATEGORY_UI).
/// @param[in] dataType						Data type id to load.
/// @param[in] language						Language (only valid for category DATADESCRIPTION_CATEGORY_STRING).
/// @return												True if the database contains the data type.
		inline HXXADDRET2(Bool) Contains(const Id& category, const IdAndVersion& dataType, const LanguageRef& language) const;
/// Loads a description from the registered databases.
/// @param[in] category						Database category (e.g. DATADESCRIPTION_CATEGORY_DATA / DATADESCRIPTION_CATEGORY_UI).
/// @param[in] language						Language (only valid for category DATADESCRIPTION_CATEGORY_STRING).
/// @param[in] dataType						Data type id to load.
/// @param[out] foundInDatabase		Optional: Pointer to an Id of the database where the entry was found.
/// @return												DataDescriptionDefinition on success.
		inline Result<DataDescriptionDefinition> LoadDescription(LOADDESCRIPTIONMODE mode, const Id& category, const LanguageRef& language, const IdAndVersion& dataType, Id* foundInDatabase = nullptr) const;
/// Return all registered descriptions.
/// @param[in] category						Database category (e.g. DATADESCRIPTION_CATEGORY_DATA / DATADESCRIPTION_CATEGORY_UI).
/// @param[in] language						Language (only valid for category DATADESCRIPTION_CATEGORY_STRING).
/// @return												Array on success.
		inline Result<BaseArray<IdAndVersion>> GetRegisteredDescriptions(const Id& category, const LanguageRef& language) const;
/// Returns all registered languages of this database.
/// @return												Array with languages on success.
		inline Result<BaseArray<LanguageRef>> GetRegisteredLanguages() const;
/// Save all databases (including user changes and version update changes).
/// @return												OK on success.
		inline Result<void> WriteDataBases() const;
/// Checks if the given id is unique in all databases.
/// @param[in] searchId						Id to search for.
/// @return												True if the id is unique. False if the id already exists.
		inline Result<Bool> CheckUniqueAttributeName(const InternedId& searchId) const;
/// Updates the description from the given DataDescriptionDefinition.
/// @param[in] category						Category to search.
/// @param[in] dataTypeId					Data type id to process.
/// @param[in] language						Language to process.
/// @return												OK on success.
		inline Result<DataDescription> UpdateDescriptions(const Id& category, const IdAndVersion& dataTypeId, const LanguageRef& language) const;
/// Returns true if the database is writable.
/// @param[in] languageId					Language id to check.
		inline HXXADDRET2(Bool) IsWritableDatabase(const Id& languageId) const;
/// Returns the number of changes made since the last Write().
/// This includes user changes and all automatic version update changes.
/// @return												The number of changes.
		inline HXXADDRET2(Int) GetChangeCounts() const;
/// Returns the number of changes made by user since the last Write().
/// @return												The number of changes.
		inline HXXADDRET2(Int) GetUserChangeCount() const;
/// Writes all changes permanently to hard drive.
/// @return												OK on success.
		inline Result<void> Write() const;
	};
	/// Intermediate helper class for DataDescriptionDefinitionDatabaseImplInterface.
	template <typename S> class Fn : public ConstFn<S>
	{
	public:
		Fn() = default;
		using PrivateBaseClass = ConstFn<S>;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = DataDescriptionDefinitionDatabaseImplInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static Fn PrivateLookupFn(DataDescriptionDefinitionDatabaseImplInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, DataDescriptionDefinitionDatabaseImplRef, true>::type&() const { return reinterpret_cast<const DataDescriptionDefinitionDatabaseImplRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, DataDescriptionDefinitionDatabaseImplRef, false>::type&() { return reinterpret_cast<const DataDescriptionDefinitionDatabaseImplRef&>(this->GetBaseRef()); }
/// Stores the given description under the given values.
/// @param[in] databaseId					Database id (see RegisterDatabase()/GetRegisteredDatabases()).
/// @param[in] category						Database category (e.g. DATADESCRIPTION_CATEGORY_DATA / DATADESCRIPTION_CATEGORY_UI).
/// @param[in] language						Language (only valid for category DATADESCRIPTION_CATEGORY_STRING).
/// @param[in] dataType						Data type id to store.
/// @param[in] description				Description data to store.
/// @return												Tuple with a Bool (changed or not) and the pointer of the stored description if changed. Error otherwise.
		inline Result<Tuple<Bool, DataDescriptionDefinition*>> StoreDescription(const Id& databaseId, const Id& category, const LanguageRef& language, const IdAndVersion& dataType, const DataDescriptionDefinition& description, const DataDescriptionDefinition& overwrittenDescription, Bool usePendingSystem) const;
/// DeleteDescription deletes a description from the database.
/// @param[in] category						Database category (e.g. DATADESCRIPTION_CATEGORY_DATA / DATADESCRIPTION_CATEGORY_UI).
/// @param[in] language						Language (only valid for category DATADESCRIPTION_CATEGORY_STRING).
/// @param[in] dataType						Data type id to delete.
/// @return												True/False on success. True means the description was found and deleted. False if the description was not found.
		inline Result<Bool> DeleteDescription(const Id& category, const LanguageRef& language, const IdAndVersion& dataType) const;
/// Renames a id in all databases to the new id.
/// @param[in] oldId							Old id to rename
/// @param[in] newId							Id to replace.
/// @return												Number of values that were renamed.
		inline Result<Int> RenameId(const Id& oldId, const Id& newId) const;
/// Renames an attribute in all databases.
/// @param[in] oldId							Old attribute key.
/// @param[in] newId							New attribute key.
/// @return												Number of values that were renamed.
		inline Result<Int> RenameAttribute(const InternedId& oldId, const InternedId& newId) const;
/// Save all databases edited by a user.
/// @return												OK on success.
		inline Result<void> WriteUserChangedDataBases() const;
	};
	/// Intermediate helper class for DataDescriptionDefinitionDatabaseImplInterface.
	template <typename S> class COWFn : public ConstFn<S>
	{
	public:
		COWFn() = default;
		using PrivateBaseClass = ConstFn<S>;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = DataDescriptionDefinitionDatabaseImplInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static COWFn PrivateLookupFn(DataDescriptionDefinitionDatabaseImplInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, DataDescriptionDefinitionDatabaseImplRef, false>::type&() { return reinterpret_cast<const DataDescriptionDefinitionDatabaseImplRef&>(this->GetBaseRef()); }
/// Stores the given description under the given values.
/// @param[in] databaseId					Database id (see RegisterDatabase()/GetRegisteredDatabases()).
/// @param[in] category						Database category (e.g. DATADESCRIPTION_CATEGORY_DATA / DATADESCRIPTION_CATEGORY_UI).
/// @param[in] language						Language (only valid for category DATADESCRIPTION_CATEGORY_STRING).
/// @param[in] dataType						Data type id to store.
/// @param[in] description				Description data to store.
/// @return												Tuple with a Bool (changed or not) and the pointer of the stored description if changed. Error otherwise.
		inline Result<Tuple<Bool, DataDescriptionDefinition*>> StoreDescription(const Id& databaseId, const Id& category, const LanguageRef& language, const IdAndVersion& dataType, const DataDescriptionDefinition& description, const DataDescriptionDefinition& overwrittenDescription, Bool usePendingSystem);
/// DeleteDescription deletes a description from the database.
/// @param[in] category						Database category (e.g. DATADESCRIPTION_CATEGORY_DATA / DATADESCRIPTION_CATEGORY_UI).
/// @param[in] language						Language (only valid for category DATADESCRIPTION_CATEGORY_STRING).
/// @param[in] dataType						Data type id to delete.
/// @return												True/False on success. True means the description was found and deleted. False if the description was not found.
		inline Result<Bool> DeleteDescription(const Id& category, const LanguageRef& language, const IdAndVersion& dataType);
/// Renames a id in all databases to the new id.
/// @param[in] oldId							Old id to rename
/// @param[in] newId							Id to replace.
/// @return												Number of values that were renamed.
		inline Result<Int> RenameId(const Id& oldId, const Id& newId);
/// Renames an attribute in all databases.
/// @param[in] oldId							Old attribute key.
/// @param[in] newId							New attribute key.
/// @return												Number of values that were renamed.
		inline Result<Int> RenameAttribute(const InternedId& oldId, const InternedId& newId);
/// Save all databases edited by a user.
/// @return												OK on success.
		inline Result<void> WriteUserChangedDataBases();
	};
	template <typename ST> struct FnHelper : public std::conditional<
	maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
	COWFn<typename ObjectInterface::Hxx1::template FnHelper<ST>::type>,
	typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstFn<typename ObjectInterface::Hxx1::template FnHelper<ST>::type>, Fn<typename ObjectInterface::Hxx1::template FnHelper<ST>::type>>::type
	> { };
};
class DataDescriptionDefinitionDatabaseImplInterface::Hxx1::Reference :
#ifdef DOXYGEN
public FnDoxy<DataDescriptionDefinitionDatabaseImplRef>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<DataDescriptionDefinitionDatabaseImplInterface, maxon::StrongRefHandler, DataDescriptionDefinitionDatabaseImplRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<DataDescriptionDefinitionDatabaseImplInterface, maxon::StrongRefHandler, DataDescriptionDefinitionDatabaseImplRef>>>>);
	using NonConst = typename Super::ReferenceClass;
};

/// DataDescriptionDefinitionDatabaseImplRef is the reference class of DataDescriptionDefinitionDatabaseImplInterface.
///
/// Allows to create different implementations of data description database stores.
class DataDescriptionDefinitionDatabaseImplRef : public DataDescriptionDefinitionDatabaseImplInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(DataDescriptionDefinitionDatabaseImplRef, typename DataDescriptionDefinitionDatabaseImplInterface::Hxx1::Reference);
	using ConstPtr = typename DataDescriptionDefinitionDatabaseImplInterface::ConstPtr;
};

#endif

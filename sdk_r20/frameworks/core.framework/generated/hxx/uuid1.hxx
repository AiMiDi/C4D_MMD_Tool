#if 1
class Uuid;

struct UuidInterface::ReferenceClassHelper { using type = Uuid; };

/// Intermediate helper class for UuidInterface.
template <typename S> class UuidInterface::ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
{
public:
	ConstReferenceFunctionsImpl() = default;
	using PrivateBaseClass = S;
	using PrivateBaseClass::PrivateBaseClass;
/// Returns whether the object is empty or not.
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type IsEmpty() const;
/// Returns whether the object is populated or not.
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type IsPopulated() const;
/// Gets a given memory block of a uuid. The id must be 16 bytes long. Please note that native window functions return little endian for the first 3 components which is different to this call.
/// @param[in] uuid								Pointer to memory of a uuid in big endian format.
/// @param[in] uuidSize						Size of the memory block that receives the uuid.
/// @return												OK on success.
	inline Result<void> Get(UChar* uuid, Int uuidSize) const;
/// Converts the uuid into a string. The format will be "00000000-0000-0000-0000-000000000000" and the letters will be uppercase.
/// @param[in] formatStatement		Format statement for string formating.
/// @return												String representation of the uuid.
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type ToString(const FormatStatement* formatStatement) const;
/// Compares the uuid against another uuid.
/// @param[in] uuid								The uuid to compare with.
/// @return												See COMPARERESULT.
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<COMPARERESULT>, COMPARERESULT>::type Compare(const UuidInterface* uuid) const;
/// Describes all elements of this class for I/O operations.
/// @param[in] stream							The stream that is used to register the class members.
/// @return												OK on success.
	static inline Result<void> DescribeIO(const DataSerializeInterface& stream);
/// Creates a new uuid and returns the string of it.
	static inline Result<String> CreateUuidString();
};
#ifdef DOXYGEN
template <typename REF> class UuidInterface::ConstReferenceFunctionsImplDoxy : public UuidInterface::ConstReferenceFunctionsImpl<REF> { };
#endif

/// Intermediate helper class for UuidInterface.
template <typename S> class UuidInterface::ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	ReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
/// Creates a new uuid.
	inline Result<void> CreateId() const;
/// Sets a given uuid string. The id must be of the format "00000000-0000-0000-0000-000000000000".
/// @param[in] uuid								String with a valid uuid.
/// @return												OK on success. Returns IllegalArgumentError if the id could not be parsed.
	inline Result<void> Set(const String& uuid) const;
/// Sets a given memory block of a uuid. The id must be 16 bytes long. Please note that native window functions return little endian for the first 3 components which is different to this call.
/// @param[in] uuid								Pointer to memory of a uuid in big endian format.
/// @param[in] uuidSize						Size of the memory block that keeps the uuid.
/// @return												OK on success. Returns IllegalArgumentError if the id could not be parsed.
	inline Result<void> Set(const UChar* uuid, Int uuidSize) const;
};
#ifdef DOXYGEN
template <typename REF> class UuidInterface::ReferenceFunctionsImplDoxy : public UuidInterface::ReferenceFunctionsImpl<REF> { };
#endif

/// Intermediate helper class for UuidInterface.
template <typename S> class UuidInterface::COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	COWReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, Uuid, false>::type&() const { return reinterpret_cast<const Uuid&>(this->GetBaseRef()); }
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, Uuid, false>::type&() { return reinterpret_cast<const Uuid&>(this->GetBaseRef()); }
/// Creates a new uuid.
	inline Result<void> CreateId();
/// Sets a given uuid string. The id must be of the format "00000000-0000-0000-0000-000000000000".
/// @param[in] uuid								String with a valid uuid.
/// @return												OK on success. Returns IllegalArgumentError if the id could not be parsed.
	inline Result<void> Set(const String& uuid);
/// Sets a given memory block of a uuid. The id must be 16 bytes long. Please note that native window functions return little endian for the first 3 components which is different to this call.
/// @param[in] uuid								Pointer to memory of a uuid in big endian format.
/// @param[in] uuidSize						Size of the memory block that keeps the uuid.
/// @return												OK on success. Returns IllegalArgumentError if the id could not be parsed.
	inline Result<void> Set(const UChar* uuid, Int uuidSize);
	explicit operator maxon::Bool() const MAXON_WORKAROUND_CLANG_DELETED_FUNCTION(S);
	explicit operator maxon::Bool() MAXON_WORKAROUND_CLANG_DELETED_FUNCTION(S);
};
#ifdef DOXYGEN
template <typename REF> class UuidInterface::COWReferenceFunctionsImplDoxy : public UuidInterface::COWReferenceFunctionsImpl<REF> { };
#endif

template <typename ST> struct UuidInterface::ReferenceFunctions { using type = typename std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ST::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ST::type>, ReferenceFunctionsImpl<typename ST::type>>::type>::type; };
class UuidInterface::Reference :
#ifdef DOXYGEN
public COWReferenceFunctionsImplDoxy<Uuid>
#else
public maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<const UuidInterface, maxon::StrongCOWRefHandler, Uuid>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<const UuidInterface, maxon::StrongCOWRefHandler, Uuid>>>>);
	using NonConst = NonConstRef;
	static MAXON_ATTRIBUTE_FORCE_INLINE maxon::ResultMemT<Uuid> Create();
/// @param[in] uuid								String with a valid uuid.
	static MAXON_ATTRIBUTE_FORCE_INLINE maxon::ResultMemT<Uuid> Create(const String& uuid);
/// @param[in] uuid								Pointer to memory of a uuid in big endian format.
/// @param[in] uuidSize						Size of the memory block that receives the uuid.
	static MAXON_ATTRIBUTE_FORCE_INLINE maxon::ResultMemT<Uuid> Create(const UChar* uuid, Int uuidSize);
};

class UuidInterface::NonConstRef :
#ifdef DOXYGEN
public COWReferenceFunctionsImplDoxy<NonConstRef>
#else
public maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<UuidInterface, maxon::StrongCOWRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<UuidInterface, maxon::StrongCOWRefHandler, NonConstRef>>>>);
};

#if (defined MAXON_TARGET_WINDOWS) && (defined MAXON_TARGET_DEBUG)
#endif
#endif

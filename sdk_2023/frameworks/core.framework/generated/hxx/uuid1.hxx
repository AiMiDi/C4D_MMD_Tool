#if 1
class Uuid;

struct UuidInterface::Hxx1
{
	class NonConstRef;
	using ReferenceClass = Uuid;
	/// Intermediate helper class for UuidInterface.
	template <typename S> class ConstFn DOXYGEN_SWITCH_REVERSED(, : public S)
	{
	public:
		ConstFn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static ConstFn PrivateLookupFn(UuidInterface**);
/// Returns whether the object is empty or not. A Uuid is empty if it hasn't been constructed yet, or
/// if a copy operation on the object failed, or if it just contains 0-values.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type IsEmpty() const;
/// Returns whether the object is populated or not. Always the opposite of IsEmpty().
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type IsPopulated() const;
/// Gets a given memory block of a uuid. The id must be 16 bytes long. Please note that native window functions return little endian for the first 3 components which is different to this call.
/// @param[in] uuid								Pointer to memory of a uuid in big endian format.
/// @param[in] uuidSize						Size of the memory block that receives the uuid.
/// @return												OK on success.
		inline Result<void> Get(UChar* uuid, Int uuidSize) const;
/// Converts the uuid into a string. The format will be "00000000-0000-0000-0000-000000000000" and the letters will be uppercase.
/// @param[in] formatStatement		Format statement for string formating.
/// @return												String representation of the uuid.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type ToString(const FormatStatement* formatStatement = nullptr) const;
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
/// Creates a new uuid and writes it to the raw buffer.
/// @param[out] uuid							The raw 128 bits of the uuid are written to this buffer.
		static inline Result<void> CreateUuid(maxon::AddArrayT<UChar, 16>& uuid);
	};
	/// Intermediate helper class for UuidInterface.
	template <typename S> class Fn : public ConstFn<S>
	{
	public:
		Fn() = default;
		using PrivateBaseClass = ConstFn<S>;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static Fn PrivateLookupFn(UuidInterface**);
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
	/// Intermediate helper class for UuidInterface.
	template <typename S> class COWFn : public ConstFn<S>
	{
	public:
		COWFn() = default;
		using PrivateBaseClass = ConstFn<S>;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static COWFn PrivateLookupFn(UuidInterface**);
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
		explicit operator maxon::Bool() const = delete;
		
		explicit operator maxon::Bool() = delete;
	};
	template <typename ST> struct FnHelper : public std::conditional<
	maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
	COWFn<typename ST::type>,
	typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstFn<typename ST::type>, Fn<typename ST::type>>::type
	> { };
};
class UuidInterface::Reference :
#ifdef DOXYGEN
public COWFnDoxy<Uuid>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<const UuidInterface, maxon::StrongCOWRefHandler, Uuid>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<const UuidInterface, maxon::StrongCOWRefHandler, Uuid>>>>);
	using NonConst = Hxx1::NonConstRef;
	static MAXON_ATTRIBUTE_FORCE_INLINE maxon::ResultMemT<Uuid> Create();
/// @param[in] uuid								String with a valid uuid.
	static MAXON_ATTRIBUTE_FORCE_INLINE maxon::ResultMemT<Uuid> Create(const String& uuid);
/// @param[in] uuid								Pointer to memory of a uuid in big endian format.
/// @param[in] uuidSize						Size of the memory block that receives the uuid.
	static MAXON_ATTRIBUTE_FORCE_INLINE maxon::ResultMemT<Uuid> Create(const UChar* uuid, Int uuidSize);
};

class UuidInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public FnDoxy<NonConstRef>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<UuidInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<UuidInterface, maxon::StrongRefHandler, NonConstRef>>>>);
};

#if (defined MAXON_TARGET_WINDOWS) && (defined MAXON_TARGET_DEBUG)
#endif
#endif

#if 1
namespace URLFLAGS
{
#ifndef PRIVATE_MAXON_GUARD_maxon_URLFLAGS
#define PRIVATE_MAXON_GUARD_maxon_URLFLAGS
	class RESTRICT : public maxon::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
#endif
}
class CryptoKey;

struct CryptoKeyInterface::ReferenceClassHelper { using type = CryptoKey; };

/// Intermediate helper class for CryptoKeyInterface.
template <typename S> class CryptoKeyInterface::ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
{
public:
	ConstReferenceFunctionsImpl() = default;
	using PrivateBaseClass = S;
	using PrivateBaseClass::PrivateBaseClass;
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, CryptoKey, false>::type&() const { return reinterpret_cast<const CryptoKey&>(this->GetBaseRef()); }
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, CryptoKey, false>::type&() { return reinterpret_cast<const CryptoKey&>(this->GetBaseRef()); }
/// Returns the cryptography algorithm.
/// @return												Id of the used cryptography algorithm.
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<const Id&>, const Id&>::type GetCryptoAlgorithm() const;
/// Returns the cryptography block size in bits.
/// @return												Block size in bits.
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type GetBlockBitSize() const;
/// Returns the cryptography data of key 1.
/// @return												Pointer to the memory of key 1.
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<const void*>, const void*>::type GetKey1() const;
/// Returns the cryptography size of key 1.
/// @return												Key 1 size in bits.
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type GetKey1BitSize() const;
/// Returns the cryptography data of key 2.
/// @return												Pointer to the memory of key 2.
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<const void*>, const void*>::type GetKey2() const;
/// Returns the cryptography size of key 2.
/// @return												Key 2 size in bits.
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type GetKey2BitSize() const;
/// Returns the additional flags.
/// @return												The flags.
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<UInt64>, UInt64>::type GetFlags() const;
/// Returns the callback delegate.
/// @return												The delegate of the callback.
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<const BLOCK_CIPHER_CTR_CALLBACK&>, const BLOCK_CIPHER_CTR_CALLBACK&>::type GetCallbackFunction() const;
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type ToString(const FormatStatement* formatStatement) const;
};
#ifdef DOXYGEN
template <typename REF> class CryptoKeyInterface::ConstReferenceFunctionsImplDoxy : public CryptoKeyInterface::ConstReferenceFunctionsImpl<REF> { };
#endif

/// Intermediate helper class for CryptoKeyInterface.
template <typename S> class CryptoKeyInterface::ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	ReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
};
#ifdef DOXYGEN
template <typename REF> class CryptoKeyInterface::ReferenceFunctionsImplDoxy : public CryptoKeyInterface::ReferenceFunctionsImpl<REF> { };
#endif

/// Intermediate helper class for CryptoKeyInterface.
template <typename S> class CryptoKeyInterface::COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	COWReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
};
#ifdef DOXYGEN
template <typename REF> class CryptoKeyInterface::COWReferenceFunctionsImplDoxy : public CryptoKeyInterface::COWReferenceFunctionsImpl<REF> { };
#endif

template <typename ST> struct CryptoKeyInterface::ReferenceFunctions { using type = typename std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ST::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ST::type>, ReferenceFunctionsImpl<typename ST::type>>::type>::type; };
class CryptoKeyInterface::Reference :
#ifdef DOXYGEN
public ConstReferenceFunctionsImplDoxy<CryptoKey>
#else
public maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<const CryptoKeyInterface, maxon::StrongRefHandler, CryptoKey>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<const CryptoKeyInterface, maxon::StrongRefHandler, CryptoKey>>>>);
	using NonConst = NonConstRef;
/// Allocates the class.
/// @param[in] cryptoAlgorithm		Id of an encryption algorithm. e.g. CryptographyClasses::AES.GetId().
/// @param[in] blockSizeBits			Blocksize of the algorithm in bits.
/// @param[in] key1								Pointer to the data of key 1.
/// @param[in] key1BitSize				Size of the key 1 in bits.
/// @param[in] key2								Pointer to the data of key 2.
/// @param[in] key2BitSize				Size of the key 2 in bits.
/// @param[in] flags							Additional flags.
/// @param[in] callback						Callback function for CTR mode. Please consult the documentation of the cryptography algorithm for an explanation.
	static MAXON_ATTRIBUTE_FORCE_INLINE maxon::ResultMemT<CryptoKey> Create(const Id& cryptoAlgorithm, Int blockSizeBits, const void* key1, Int key1BitSize, const void* key2 = nullptr, Int key2BitSize = 0, UInt64 flags = 0, BLOCK_CIPHER_CTR_CALLBACK&& callback = BLOCK_CIPHER_CTR_CALLBACK());
};

class CryptoKeyInterface::NonConstRef :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<NonConstRef>
#else
public maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<CryptoKeyInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<CryptoKeyInterface, maxon::StrongRefHandler, NonConstRef>>>>);
};

namespace CryptographyOptions
{
#ifndef PRIVATE_MAXON_GUARD_maxon_CryptographyOptions
#define PRIVATE_MAXON_GUARD_maxon_CryptographyOptions
	class RESTRICT : public maxon::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
#endif
}
#endif

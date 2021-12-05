#if 1
struct CryptographyStreamConversionInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, CryptographyStreamConversionInterface>::value || StreamConversionInterface::HasBase::Check<I>::value; static I* Cast(CryptographyStreamConversionInterface* ptr) { return static_cast<I*>(static_cast<maxon::Object*>(ptr)); } }; };
class CryptographyStreamConversionRef;

struct CryptographyStreamConversionInterface::ReferenceClassHelper { using type = CryptographyStreamConversionRef; };

/// Intermediate helper class for CryptographyStreamConversionInterface.
template <typename S> class CryptographyStreamConversionInterface::ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
{
public:
	ConstReferenceFunctionsImpl() = default;
	using PrivateBaseClass = S;
	using PrivateBaseClass::PrivateBaseClass;
/// Checks if the algorithm is a chaining chiffre (i.e. a value that was calculated in the current block is used in the next block).
/// For example, CBC is a chaining chiffre, whereas ECB is not a chaining chiffre.
/// @return												True, if it is a chaining chiffre.
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type IsChainingChiffre() const;
};
#ifdef DOXYGEN
template <typename REF> class CryptographyStreamConversionInterface::ConstReferenceFunctionsImplDoxy : public CryptographyStreamConversionInterface::ConstReferenceFunctionsImpl<REF>, public StreamConversionInterface::ConstReferenceFunctionsImplDoxy<REF> { };
#endif

/// Intermediate helper class for CryptographyStreamConversionInterface.
template <typename S> class CryptographyStreamConversionInterface::ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	ReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, CryptographyStreamConversionRef, true>::type&() const { return reinterpret_cast<const CryptographyStreamConversionRef&>(this->GetBaseRef()); }
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, CryptographyStreamConversionRef, false>::type&() { return reinterpret_cast<const CryptographyStreamConversionRef&>(this->GetBaseRef()); }
};
#ifdef DOXYGEN
template <typename REF> class CryptographyStreamConversionInterface::ReferenceFunctionsImplDoxy : public CryptographyStreamConversionInterface::ReferenceFunctionsImpl<REF>, public StreamConversionInterface::ReferenceFunctionsImplDoxy<REF> { };
#endif

/// Intermediate helper class for CryptographyStreamConversionInterface.
template <typename S> class CryptographyStreamConversionInterface::COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	COWReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, CryptographyStreamConversionRef, false>::type&() { return reinterpret_cast<const CryptographyStreamConversionRef&>(this->GetBaseRef()); }
};
#ifdef DOXYGEN
template <typename REF> class CryptographyStreamConversionInterface::COWReferenceFunctionsImplDoxy : public CryptographyStreamConversionInterface::COWReferenceFunctionsImpl<REF>, public StreamConversionInterface::COWReferenceFunctionsImplDoxy<REF> { };
#endif

template <typename ST> struct CryptographyStreamConversionInterface::ReferenceFunctions { using type = typename std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename StreamConversionInterface::ReferenceFunctions<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename StreamConversionInterface::ReferenceFunctions<ST>::type>, ReferenceFunctionsImpl<typename StreamConversionInterface::ReferenceFunctions<ST>::type>>::type>::type; };
class CryptographyStreamConversionInterface::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<CryptographyStreamConversionRef>
#else
public maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<CryptographyStreamConversionInterface, maxon::StrongRefHandler, CryptographyStreamConversionRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<CryptographyStreamConversionInterface, maxon::StrongRefHandler, CryptographyStreamConversionRef>>>>);
	using NonConst = Super::ReferenceClass;
};

/// CryptographyStreamConversionRef is the reference class of CryptographyStreamConversionInterface.
///
/// CryptographyRef class for encrypting and decrypting.
/// To allocate an instance of a CryptographyRef call CryptographyClasses::Get("<name>").Create().
/// Currently supported cryptography methods are:
///
/// AES
///		Use CryptographyClasses::AES as name to allocate a new instance.
///		Block size and key size must be 128, 192 or 256 bit.
///		The encryption and decryption are hardware accelerated if the hardware has AES instructions.
///		key1 is the key that is used for encryption and decryption. The following modes are supported:
///		ECB: keySize2 must be 0, key2 must be nullptr, otherwise Init will return IllegalArgumentError.
///		CBC, PCBC, CFB, OFB: keySize2 must be blockSize, key2 must not be nullptr, otherwise Init will return IllegalArgumentError. This is the initialization vector for the chiffre.
///		CTR: keySize2 must be 0, key2 must be nullptr, callback must be the address of an BLOCK_CIPHER_CTR_CALLBACK function, otherwise Init will return IllegalArgumentError.
///		userData of the Encrypt and Decrypt functions are not used except for CTR mode.
///
/// Blowfish
///		Use CRYPTOGRAPHYTYPE_BLOWFISH as the name to allocate the class. Blowfish is a keyed, symmetric block cipher. @see https://en.wikipedia.org/wiki/Blowfish_(cipher)
///		The Block size must be 64 or 2048 bit. Valid key lengths are 32 to 448 bit (must be divisible by 8).
///   The Init() flag bit 1 enables the streaming mode which causes that identical blocks are encrypted different and so it's harder to find patterns.
///
///   Use "blowfish.legacy" as the name to allocate the class which is compatible to cinema 4d r5 - r14 blowfish.
///		The Block size must be 64 or 2048 bit. Valid key lengths are 32 to 448 bit (must be divisible by 8).
///   The Init() flag bit 1 enables the streaming mode which causes that identical blocks are encrypted different and so it's harder to find patterns.
///   In this mode it's possible to call Encrypt() even if the datasize is not % blocksize. If the blocksize is 2048 bit the rest is encoded with 64 bit.
///   the rest is unencrypted! It's exactly the behavior that cinema 4d had. it's not recommended to use that for new code anymore!
class CryptographyStreamConversionRef : public CryptographyStreamConversionInterface::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(CryptographyStreamConversionRef, Reference);
};

namespace BLOWFISHLEGACYENDECODER_OPTIONS
{
#ifndef PRIVATE_MAXON_GUARD_maxon_BLOWFISHLEGACYENDECODER_OPTIONS
#define PRIVATE_MAXON_GUARD_maxon_BLOWFISHLEGACYENDECODER_OPTIONS
	class RESTRICT : public maxon::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
#endif
}
#endif

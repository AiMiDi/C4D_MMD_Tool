#if 1
namespace URLFLAGS
{
#ifndef PRIVATE_MAXON_GUARD_maxon_URLFLAGS
#define PRIVATE_MAXON_GUARD_maxon_URLFLAGS
	class RESTRICT : public maxon::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
#endif
}
class CryptoKey;

struct CryptoKeyInterface::Hxx1
{
	class NonConstRef;
	using ReferenceClass = CryptoKey;
	/// Intermediate helper class for CryptoKeyInterface.
	template <typename S> class ConstFn DOXYGEN_SWITCH_REVERSED(, : public S)
	{
	public:
		ConstFn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static ConstFn PrivateLookupFn(CryptoKeyInterface**);
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
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type ToString(const FormatStatement* formatStatement = nullptr) const;
	};
	template <typename ST> struct FnHelper : public std::conditional<
	false, void,
	ConstFn<typename ST::type>
	> { };
};
class CryptoKeyInterface::Reference :
#ifdef DOXYGEN
public ConstFnDoxy<CryptoKey>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<const CryptoKeyInterface, maxon::StrongRefHandler, CryptoKey>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<const CryptoKeyInterface, maxon::StrongRefHandler, CryptoKey>>>>);
	using NonConst = Hxx1::NonConstRef;
/// Allocates the class.
/// @param[in] cryptoAlgorithm		Id of an encryption algorithm. e.g. StreamConversions::AesEncoder.GetId().
/// @param[in] blockSizeBits			Blocksize of the algorithm in bits.
/// @param[in] key1								Pointer to the data of key 1.
/// @param[in] key1BitSize				Size of the key 1 in bits.
/// @param[in] key2								Pointer to the data of key 2.
/// @param[in] key2BitSize				Size of the key 2 in bits.
/// @param[in] flags							Additional flags.
/// @param[in] callback						Callback function for CTR mode. Please consult the documentation of the cryptography algorithm for an explanation.
	static MAXON_ATTRIBUTE_FORCE_INLINE maxon::ResultMemT<CryptoKey> Create(const Id& cryptoAlgorithm, Int blockSizeBits, const void* key1, Int key1BitSize, const void* key2 = nullptr, Int key2BitSize = 0, UInt64 flags = 0, BLOCK_CIPHER_CTR_CALLBACK&& callback = BLOCK_CIPHER_CTR_CALLBACK());
};

class CryptoKeyInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public FnDoxy<NonConstRef>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<CryptoKeyInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<CryptoKeyInterface, maxon::StrongRefHandler, NonConstRef>>>>);
};

namespace CryptographyOptions
{
#ifndef PRIVATE_MAXON_GUARD_maxon_CryptographyOptions
#define PRIVATE_MAXON_GUARD_maxon_CryptographyOptions
	class RESTRICT : public maxon::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
#endif
}
#endif

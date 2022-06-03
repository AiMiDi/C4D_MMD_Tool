#if 1
namespace maxon
{
	namespace URLFLAGS
	{
		CRYPTO_KEY_PrivateAttribute CRYPTO_KEY;
	}
	const maxon::Char* const CryptoKeyInterface::MTable::_ids = 
		"Free@2feccf2896f1931d\0" // void Free(const CryptoKeyInterface* object)
		"Alloc@ba60b2aeead158d2\0" // CryptoKeyInterface* Alloc(const maxon::SourceLocation& allocLocation, const Id& cryptoAlgorithm, Int blockSizeBits, const void* key1, Int key1BitSize, const void* key2, Int key2BitSize, UInt64 flags, BLOCK_CIPHER_CTR_CALLBACK&& callback)
		"GetCryptoAlgorithm@daec66e7da84a648\0" // const Id& GetCryptoAlgorithm() const
		"GetBlockBitSize@7d0e6f3d29c239e7\0" // Int GetBlockBitSize() const
		"GetKey1@c912d069b43da345\0" // const void* GetKey1() const
		"GetKey1BitSize@7d0e6f3d29c239e7\0" // Int GetKey1BitSize() const
		"GetKey2@c912d069b43da345\0" // const void* GetKey2() const
		"GetKey2BitSize@7d0e6f3d29c239e7\0" // Int GetKey2BitSize() const
		"GetFlags@55e89195f712e11e\0" // UInt64 GetFlags() const
		"GetCallbackFunction@bcd582bda3f126a4\0" // const BLOCK_CIPHER_CTR_CALLBACK& GetCallbackFunction() const
		"ToString@a73a45c584c879d4\0" // String ToString(const FormatStatement* formatStatement) const
	"";
	MAXON_WARNING_PUSH
	MAXON_WARNING_DISABLE_DEPRECATED
	class CryptoKeyInterface::Hxx2::Unresolved : public CryptoKeyInterface
	{
	public:
		static const Unresolved* Get(const CryptoKeyInterface* o) { return (const Unresolved*) o; }
		static Unresolved* Get(CryptoKeyInterface* o) { return (Unresolved*) o; }
		static void Free(const CryptoKeyInterface* object) { if (object && maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return CryptoKeyInterface::Free(object); return maxon::PrivateLogNullptrError();}
		static CryptoKeyInterface* Alloc(const maxon::SourceLocation& allocLocation, const Id& cryptoAlgorithm, Int blockSizeBits, const void* key1, Int key1BitSize, const void* key2, Int key2BitSize, UInt64 flags, BLOCK_CIPHER_CTR_CALLBACK&& callback) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return CryptoKeyInterface::Alloc(allocLocation, cryptoAlgorithm, blockSizeBits, key1, key1BitSize, key2, key2BitSize, flags, std::forward<BLOCK_CIPHER_CTR_CALLBACK>(callback)); return nullptr;}
		const Id& GetCryptoAlgorithm() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const CryptoKeyInterface*) this)->GetCryptoAlgorithm(); return maxon::PrivateIncompleteNullReturnValue<const Id&>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		Int GetBlockBitSize() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const CryptoKeyInterface*) this)->GetBlockBitSize(); return 0;}
		const void* GetKey1() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const CryptoKeyInterface*) this)->GetKey1(); return nullptr;}
		Int GetKey1BitSize() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const CryptoKeyInterface*) this)->GetKey1BitSize(); return 0;}
		const void* GetKey2() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const CryptoKeyInterface*) this)->GetKey2(); return nullptr;}
		Int GetKey2BitSize() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const CryptoKeyInterface*) this)->GetKey2BitSize(); return 0;}
		UInt64 GetFlags() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const CryptoKeyInterface*) this)->GetFlags(); return 0;}
		const BLOCK_CIPHER_CTR_CALLBACK& GetCallbackFunction() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const CryptoKeyInterface*) this)->GetCallbackFunction(); return maxon::PrivateIncompleteNullReturnValue<const BLOCK_CIPHER_CTR_CALLBACK&>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		String ToString(const FormatStatement* formatStatement) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const CryptoKeyInterface*) this)->ToString(formatStatement); return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
	};
	MAXON_WARNING_POP
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::NULL_RETURN_TYPE CryptoKeyInterface::MTable::_returnTypes[] = 
	{
		maxon::NULL_RETURN_TYPE::VOID_ZERO_FREE_FUNCTION,
		maxon::details::NullReturnType<CryptoKeyInterface*>::value,
		maxon::details::NullReturnType<const Id&>::value,
		maxon::details::NullReturnType<Int>::value,
		maxon::details::NullReturnType<const void*>::value,
		maxon::details::NullReturnType<Int>::value,
		maxon::details::NullReturnType<const void*>::value,
		maxon::details::NullReturnType<Int>::value,
		maxon::details::NullReturnType<UInt64>::value,
		maxon::details::NullReturnType<const BLOCK_CIPHER_CTR_CALLBACK&>::value,
		maxon::details::NullReturnType<String>::value,
		maxon::NULL_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool CryptoKeyInterface::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->CryptoKeyInterface_Free = &Hxx2::Wrapper<Hxx2::Unresolved>::CryptoKeyInterface_Free;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->CryptoKeyInterface_Alloc = &Hxx2::Wrapper<Hxx2::Unresolved>::CryptoKeyInterface_Alloc;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<const Id&>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->CryptoKeyInterface_GetCryptoAlgorithm = &Hxx2::Wrapper<Hxx2::Unresolved>::CryptoKeyInterface_GetCryptoAlgorithm;
		#else
		tbl->CryptoKeyInterface_GetCryptoAlgorithm = &Hxx2::Wrapper<Hxx2::Unresolved>::CryptoKeyInterface_GetCryptoAlgorithm;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->CryptoKeyInterface_GetBlockBitSize = &Hxx2::Wrapper<Hxx2::Unresolved>::CryptoKeyInterface_GetBlockBitSize;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->CryptoKeyInterface_GetKey1 = &Hxx2::Wrapper<Hxx2::Unresolved>::CryptoKeyInterface_GetKey1;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->CryptoKeyInterface_GetKey1BitSize = &Hxx2::Wrapper<Hxx2::Unresolved>::CryptoKeyInterface_GetKey1BitSize;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->CryptoKeyInterface_GetKey2 = &Hxx2::Wrapper<Hxx2::Unresolved>::CryptoKeyInterface_GetKey2;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->CryptoKeyInterface_GetKey2BitSize = &Hxx2::Wrapper<Hxx2::Unresolved>::CryptoKeyInterface_GetKey2BitSize;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->CryptoKeyInterface_GetFlags = &Hxx2::Wrapper<Hxx2::Unresolved>::CryptoKeyInterface_GetFlags;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<const BLOCK_CIPHER_CTR_CALLBACK&>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->CryptoKeyInterface_GetCallbackFunction = &Hxx2::Wrapper<Hxx2::Unresolved>::CryptoKeyInterface_GetCallbackFunction;
		#else
		tbl->CryptoKeyInterface_GetCallbackFunction = &Hxx2::Wrapper<Hxx2::Unresolved>::CryptoKeyInterface_GetCallbackFunction;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<String>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->CryptoKeyInterface_ToString = &Hxx2::Wrapper<Hxx2::Unresolved>::CryptoKeyInterface_ToString;
		#else
		tbl->CryptoKeyInterface_ToString = &Hxx2::Wrapper<Hxx2::Unresolved>::CryptoKeyInterface_ToString;
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (maxon::Char*) tbl, _returnTypes, SIZEOF(MTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(CryptoKeyInterface, "net.maxon.interface.cryptokey", nullptr);
	template <typename DUMMY> maxon::Int CryptoKeyInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		| maxon::details::InstantiateNullReturnValue<String>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<const BLOCK_CIPHER_CTR_CALLBACK&>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<const Id&>(OVERLOAD_MAX_RANK)
		;
	}
	namespace CryptographyOptions
	{
		CRYPTOKEY_PrivateAttribute CRYPTOKEY;
	}
}
#endif
static maxon::details::ForceEvaluation s_forceEval_cryptography_key(0
	| maxon::CryptoKeyInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
);

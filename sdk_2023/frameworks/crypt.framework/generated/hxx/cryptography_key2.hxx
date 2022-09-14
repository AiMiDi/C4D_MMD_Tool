
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1
constexpr const maxon::Char* CryptoKeyInterface::PrivateGetCppName() { return "maxon::CryptoKey"; }

struct CryptoKeyInterface::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = true;
	PRIVATE_MAXON_SF_POINTER(CryptoKeyInterface_Free, Free, MAXON_EXPAND_VA_ARGS, (void), const CryptoKeyInterface* object);
	PRIVATE_MAXON_SF_POINTER(CryptoKeyInterface_Alloc, Alloc, MAXON_IGNORE_VA_ARGS, (CryptoKeyInterface*), const maxon::SourceLocation& allocLocation, const Id& cryptoAlgorithm, Int blockSizeBits, const void* key1, Int key1BitSize, const void* key2, Int key2BitSize, UInt64 flags, BLOCK_CIPHER_CTR_CALLBACK&& callback);
	PRIVATE_MAXON_MF_POINTER(CryptoKeyInterface_GetCryptoAlgorithm, GetCryptoAlgorithm, false, CryptoKeyInterface, const, (const Id&));
	PRIVATE_MAXON_MF_POINTER(CryptoKeyInterface_GetBlockBitSize, GetBlockBitSize, false, CryptoKeyInterface, const, (Int));
	PRIVATE_MAXON_MF_POINTER(CryptoKeyInterface_GetKey1, GetKey1, false, CryptoKeyInterface, const, (const void*));
	PRIVATE_MAXON_MF_POINTER(CryptoKeyInterface_GetKey1BitSize, GetKey1BitSize, false, CryptoKeyInterface, const, (Int));
	PRIVATE_MAXON_MF_POINTER(CryptoKeyInterface_GetKey2, GetKey2, false, CryptoKeyInterface, const, (const void*));
	PRIVATE_MAXON_MF_POINTER(CryptoKeyInterface_GetKey2BitSize, GetKey2BitSize, false, CryptoKeyInterface, const, (Int));
	PRIVATE_MAXON_MF_POINTER(CryptoKeyInterface_GetFlags, GetFlags, false, CryptoKeyInterface, const, (UInt64));
	PRIVATE_MAXON_MF_POINTER(CryptoKeyInterface_GetCallbackFunction, GetCallbackFunction, false, CryptoKeyInterface, const, (const BLOCK_CIPHER_CTR_CALLBACK&));
	PRIVATE_MAXON_MF_POINTER(CryptoKeyInterface_ToString, ToString, false, CryptoKeyInterface, const, (String), const FormatStatement* formatStatement);
	template <typename IMPL> void Init()
	{
		CryptoKeyInterface_Free = CryptoKeyInterface_Free_GetPtr<IMPL>(true);
		CryptoKeyInterface_Alloc = CryptoKeyInterface_Alloc_GetPtr<IMPL>(true);
		CryptoKeyInterface_GetCryptoAlgorithm = CryptoKeyInterface_GetCryptoAlgorithm_GetPtr<IMPL>(0, true).first;
		CryptoKeyInterface_GetBlockBitSize = CryptoKeyInterface_GetBlockBitSize_GetPtr<IMPL>(0, true).first;
		CryptoKeyInterface_GetKey1 = CryptoKeyInterface_GetKey1_GetPtr<IMPL>(0, true).first;
		CryptoKeyInterface_GetKey1BitSize = CryptoKeyInterface_GetKey1BitSize_GetPtr<IMPL>(0, true).first;
		CryptoKeyInterface_GetKey2 = CryptoKeyInterface_GetKey2_GetPtr<IMPL>(0, true).first;
		CryptoKeyInterface_GetKey2BitSize = CryptoKeyInterface_GetKey2BitSize_GetPtr<IMPL>(0, true).first;
		CryptoKeyInterface_GetFlags = CryptoKeyInterface_GetFlags_GetPtr<IMPL>(0, true).first;
		CryptoKeyInterface_GetCallbackFunction = CryptoKeyInterface_GetCallbackFunction_GetPtr<IMPL>(0, true).first;
		CryptoKeyInterface_ToString = CryptoKeyInterface_ToString_GetPtr<IMPL>(0, true).first;
	}
};

struct CryptoKeyInterface::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
		using Implementation = C;
		static void CryptoKeyInterface_Free(const CryptoKeyInterface* object) { return C::Free(object); }
		static CryptoKeyInterface* CryptoKeyInterface_Alloc(const maxon::SourceLocation& allocLocation, const Id& cryptoAlgorithm, Int blockSizeBits, const void* key1, Int key1BitSize, const void* key2, Int key2BitSize, UInt64 flags, BLOCK_CIPHER_CTR_CALLBACK&& callback) { return C::Alloc(allocLocation, cryptoAlgorithm, blockSizeBits, key1, key1BitSize, key2, key2BitSize, flags, std::forward<BLOCK_CIPHER_CTR_CALLBACK>(callback)); }
		PRIVATE_MAXON_MF_WRAPPER(CryptoKeyInterface_GetCryptoAlgorithm, CryptoKeyInterface, const, (const Id&)) { return C::Get(PRIVATE_MAXON_MF_THIS(const CryptoKeyInterface))->GetCryptoAlgorithm(); }
		PRIVATE_MAXON_MF_WRAPPER(CryptoKeyInterface_GetBlockBitSize, CryptoKeyInterface, const, (Int)) { return C::Get(PRIVATE_MAXON_MF_THIS(const CryptoKeyInterface))->GetBlockBitSize(); }
		PRIVATE_MAXON_MF_WRAPPER(CryptoKeyInterface_GetKey1, CryptoKeyInterface, const, (const void*)) { return C::Get(PRIVATE_MAXON_MF_THIS(const CryptoKeyInterface))->GetKey1(); }
		PRIVATE_MAXON_MF_WRAPPER(CryptoKeyInterface_GetKey1BitSize, CryptoKeyInterface, const, (Int)) { return C::Get(PRIVATE_MAXON_MF_THIS(const CryptoKeyInterface))->GetKey1BitSize(); }
		PRIVATE_MAXON_MF_WRAPPER(CryptoKeyInterface_GetKey2, CryptoKeyInterface, const, (const void*)) { return C::Get(PRIVATE_MAXON_MF_THIS(const CryptoKeyInterface))->GetKey2(); }
		PRIVATE_MAXON_MF_WRAPPER(CryptoKeyInterface_GetKey2BitSize, CryptoKeyInterface, const, (Int)) { return C::Get(PRIVATE_MAXON_MF_THIS(const CryptoKeyInterface))->GetKey2BitSize(); }
		PRIVATE_MAXON_MF_WRAPPER(CryptoKeyInterface_GetFlags, CryptoKeyInterface, const, (UInt64)) { return C::Get(PRIVATE_MAXON_MF_THIS(const CryptoKeyInterface))->GetFlags(); }
		PRIVATE_MAXON_MF_WRAPPER(CryptoKeyInterface_GetCallbackFunction, CryptoKeyInterface, const, (const BLOCK_CIPHER_CTR_CALLBACK&)) { return C::Get(PRIVATE_MAXON_MF_THIS(const CryptoKeyInterface))->GetCallbackFunction(); }
		PRIVATE_MAXON_MF_WRAPPER(CryptoKeyInterface_ToString, CryptoKeyInterface, const, (String), const FormatStatement* formatStatement) { return C::Get(PRIVATE_MAXON_MF_THIS(const CryptoKeyInterface))->ToString(formatStatement); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto CryptoKeyInterface::Free(const CryptoKeyInterface* object) -> void
{
	return MTable::_instance.CryptoKeyInterface_Free(object);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CryptoKeyInterface::Alloc(const maxon::SourceLocation& allocLocation, const Id& cryptoAlgorithm, Int blockSizeBits, const void* key1, Int key1BitSize, const void* key2, Int key2BitSize, UInt64 flags, BLOCK_CIPHER_CTR_CALLBACK&& callback) -> CryptoKeyInterface*
{
	return MTable::_instance.CryptoKeyInterface_Alloc(allocLocation, cryptoAlgorithm, blockSizeBits, key1, key1BitSize, key2, key2BitSize, flags, std::forward<BLOCK_CIPHER_CTR_CALLBACK>(callback));
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CryptoKeyInterface::GetCryptoAlgorithm() const -> const Id&
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.CryptoKeyInterface_GetCryptoAlgorithm);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CryptoKeyInterface::GetBlockBitSize() const -> Int
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.CryptoKeyInterface_GetBlockBitSize);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CryptoKeyInterface::GetKey1() const -> const void*
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.CryptoKeyInterface_GetKey1);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CryptoKeyInterface::GetKey1BitSize() const -> Int
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.CryptoKeyInterface_GetKey1BitSize);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CryptoKeyInterface::GetKey2() const -> const void*
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.CryptoKeyInterface_GetKey2);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CryptoKeyInterface::GetKey2BitSize() const -> Int
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.CryptoKeyInterface_GetKey2BitSize);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CryptoKeyInterface::GetFlags() const -> UInt64
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.CryptoKeyInterface_GetFlags);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CryptoKeyInterface::GetCallbackFunction() const -> const BLOCK_CIPHER_CTR_CALLBACK&
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.CryptoKeyInterface_GetCallbackFunction);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CryptoKeyInterface::ToString(const FormatStatement* formatStatement) const -> String
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.CryptoKeyInterface_ToString, formatStatement);
}

auto CryptoKeyInterface::Reference::Create(const Id& cryptoAlgorithm, Int blockSizeBits, const void* key1, Int key1BitSize, const void* key2, Int key2BitSize, UInt64 flags, BLOCK_CIPHER_CTR_CALLBACK&& callback) -> maxon::ResultMemT<CryptoKey>
{
	CryptoKeyInterface* res_ = CryptoKeyInterface::Alloc(MAXON_SOURCE_LOCATION, cryptoAlgorithm, blockSizeBits, key1, key1BitSize, key2, key2BitSize, flags, std::forward<BLOCK_CIPHER_CTR_CALLBACK>(callback));
	return CryptoKey(maxon::ForwardResultPtr<CryptoKeyInterface>(res_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CryptoKeyInterface::Hxx1::ConstFn<S>::GetCryptoAlgorithm() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const Id&>, const Id&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const Id&>, const Id&>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const CryptoKeyInterface* o_ = (const CryptoKeyInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = CryptoKeyInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const Id&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.CryptoKeyInterface_GetCryptoAlgorithm));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CryptoKeyInterface::Hxx1::ConstFn<S>::GetBlockBitSize() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const CryptoKeyInterface* o_ = (const CryptoKeyInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = CryptoKeyInterface::NullValuePtr(); if (!o_) return 0; } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.CryptoKeyInterface_GetBlockBitSize));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CryptoKeyInterface::Hxx1::ConstFn<S>::GetKey1() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const void*>, const void*>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const void*>, const void*>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const CryptoKeyInterface* o_ = (const CryptoKeyInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = CryptoKeyInterface::NullValuePtr(); if (!o_) return nullptr; } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.CryptoKeyInterface_GetKey1));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CryptoKeyInterface::Hxx1::ConstFn<S>::GetKey1BitSize() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const CryptoKeyInterface* o_ = (const CryptoKeyInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = CryptoKeyInterface::NullValuePtr(); if (!o_) return 0; } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.CryptoKeyInterface_GetKey1BitSize));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CryptoKeyInterface::Hxx1::ConstFn<S>::GetKey2() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const void*>, const void*>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const void*>, const void*>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const CryptoKeyInterface* o_ = (const CryptoKeyInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = CryptoKeyInterface::NullValuePtr(); if (!o_) return nullptr; } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.CryptoKeyInterface_GetKey2));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CryptoKeyInterface::Hxx1::ConstFn<S>::GetKey2BitSize() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const CryptoKeyInterface* o_ = (const CryptoKeyInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = CryptoKeyInterface::NullValuePtr(); if (!o_) return 0; } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.CryptoKeyInterface_GetKey2BitSize));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CryptoKeyInterface::Hxx1::ConstFn<S>::GetFlags() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<UInt64>, UInt64>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<UInt64>, UInt64>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const CryptoKeyInterface* o_ = (const CryptoKeyInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = CryptoKeyInterface::NullValuePtr(); if (!o_) return 0; } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.CryptoKeyInterface_GetFlags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CryptoKeyInterface::Hxx1::ConstFn<S>::GetCallbackFunction() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const BLOCK_CIPHER_CTR_CALLBACK&>, const BLOCK_CIPHER_CTR_CALLBACK&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const BLOCK_CIPHER_CTR_CALLBACK&>, const BLOCK_CIPHER_CTR_CALLBACK&>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const CryptoKeyInterface* o_ = (const CryptoKeyInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = CryptoKeyInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const BLOCK_CIPHER_CTR_CALLBACK&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.CryptoKeyInterface_GetCallbackFunction));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CryptoKeyInterface::Hxx1::ConstFn<S>::ToString(const FormatStatement* formatStatement) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const CryptoKeyInterface* o_ = (const CryptoKeyInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = CryptoKeyInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.CryptoKeyInterface_ToString, formatStatement));
}
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_cryptography_key)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_CryptoKeyInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_CryptoKeyInterface() { new (s_ui_maxon_CryptoKeyInterface) maxon::EntityUse(CryptoKeyInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/cryptography_key.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_CryptoKeyInterface(CryptoKeyInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/cryptography_key.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif


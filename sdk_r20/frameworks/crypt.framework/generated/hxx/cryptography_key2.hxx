
#ifndef DOXYGEN

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wmisleading-indentation"
#endif

#if 1

struct CryptoKeyInterface::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = true;
	void (*_CryptoKeyInterface_Free) (const CryptoKeyInterface* object);
	CryptoKeyInterface* (*_CryptoKeyInterface_Alloc) (const maxon::SourceLocation& allocLocation, const Id& cryptoAlgorithm, Int blockSizeBits, const void* key1, Int key1BitSize, const void* key2, Int key2BitSize, UInt64 flags, BLOCK_CIPHER_CTR_CALLBACK&& callback);
	const Id& (*_CryptoKeyInterface_GetCryptoAlgorithm) (const CryptoKeyInterface* this_);
	Int (*_CryptoKeyInterface_GetBlockBitSize) (const CryptoKeyInterface* this_);
	const void* (*_CryptoKeyInterface_GetKey1) (const CryptoKeyInterface* this_);
	Int (*_CryptoKeyInterface_GetKey1BitSize) (const CryptoKeyInterface* this_);
	const void* (*_CryptoKeyInterface_GetKey2) (const CryptoKeyInterface* this_);
	Int (*_CryptoKeyInterface_GetKey2BitSize) (const CryptoKeyInterface* this_);
	UInt64 (*_CryptoKeyInterface_GetFlags) (const CryptoKeyInterface* this_);
	const BLOCK_CIPHER_CTR_CALLBACK& (*_CryptoKeyInterface_GetCallbackFunction) (const CryptoKeyInterface* this_);
	String (*_CryptoKeyInterface_ToString) (const CryptoKeyInterface* this_, const FormatStatement* formatStatement);
	template <typename IMPL> static void Init(MTable* tbl)
	{
		tbl->_CryptoKeyInterface_Free = &IMPL::_CryptoKeyInterface_Free;
		tbl->_CryptoKeyInterface_Alloc = &IMPL::_CryptoKeyInterface_Alloc;
		tbl->_CryptoKeyInterface_GetCryptoAlgorithm = &IMPL::_CryptoKeyInterface_GetCryptoAlgorithm;
		tbl->_CryptoKeyInterface_GetBlockBitSize = &IMPL::_CryptoKeyInterface_GetBlockBitSize;
		tbl->_CryptoKeyInterface_GetKey1 = &IMPL::_CryptoKeyInterface_GetKey1;
		tbl->_CryptoKeyInterface_GetKey1BitSize = &IMPL::_CryptoKeyInterface_GetKey1BitSize;
		tbl->_CryptoKeyInterface_GetKey2 = &IMPL::_CryptoKeyInterface_GetKey2;
		tbl->_CryptoKeyInterface_GetKey2BitSize = &IMPL::_CryptoKeyInterface_GetKey2BitSize;
		tbl->_CryptoKeyInterface_GetFlags = &IMPL::_CryptoKeyInterface_GetFlags;
		tbl->_CryptoKeyInterface_GetCallbackFunction = &IMPL::_CryptoKeyInterface_GetCallbackFunction;
		tbl->_CryptoKeyInterface_ToString = &IMPL::_CryptoKeyInterface_ToString;
	}
};

template <typename C> class CryptoKeyInterface::Wrapper
{
public:
	static void _CryptoKeyInterface_Free(const CryptoKeyInterface* object) { return C::Free(object); }
	static CryptoKeyInterface* _CryptoKeyInterface_Alloc(const maxon::SourceLocation& allocLocation, const Id& cryptoAlgorithm, Int blockSizeBits, const void* key1, Int key1BitSize, const void* key2, Int key2BitSize, UInt64 flags, BLOCK_CIPHER_CTR_CALLBACK&& callback) { return C::Alloc(allocLocation, cryptoAlgorithm, blockSizeBits, key1, key1BitSize, key2, key2BitSize, flags, std::forward<BLOCK_CIPHER_CTR_CALLBACK>(callback)); }
	static const Id& _CryptoKeyInterface_GetCryptoAlgorithm(const CryptoKeyInterface* this_) { return ((const C*) this_)->GetCryptoAlgorithm(); }
	static Int _CryptoKeyInterface_GetBlockBitSize(const CryptoKeyInterface* this_) { return ((const C*) this_)->GetBlockBitSize(); }
	static const void* _CryptoKeyInterface_GetKey1(const CryptoKeyInterface* this_) { return ((const C*) this_)->GetKey1(); }
	static Int _CryptoKeyInterface_GetKey1BitSize(const CryptoKeyInterface* this_) { return ((const C*) this_)->GetKey1BitSize(); }
	static const void* _CryptoKeyInterface_GetKey2(const CryptoKeyInterface* this_) { return ((const C*) this_)->GetKey2(); }
	static Int _CryptoKeyInterface_GetKey2BitSize(const CryptoKeyInterface* this_) { return ((const C*) this_)->GetKey2BitSize(); }
	static UInt64 _CryptoKeyInterface_GetFlags(const CryptoKeyInterface* this_) { return ((const C*) this_)->GetFlags(); }
	static const BLOCK_CIPHER_CTR_CALLBACK& _CryptoKeyInterface_GetCallbackFunction(const CryptoKeyInterface* this_) { return ((const C*) this_)->GetCallbackFunction(); }
	static String _CryptoKeyInterface_ToString(const CryptoKeyInterface* this_, const FormatStatement* formatStatement) { return ((const C*) this_)->ToString(formatStatement); }
};

MAXON_ATTRIBUTE_FORCE_INLINE auto CryptoKeyInterface::Free(const CryptoKeyInterface* object) -> void
{
	return MTable::_instance._CryptoKeyInterface_Free(object);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CryptoKeyInterface::Alloc(const maxon::SourceLocation& allocLocation, const Id& cryptoAlgorithm, Int blockSizeBits, const void* key1, Int key1BitSize, const void* key2, Int key2BitSize, UInt64 flags, BLOCK_CIPHER_CTR_CALLBACK&& callback) -> CryptoKeyInterface*
{
	return MTable::_instance._CryptoKeyInterface_Alloc(allocLocation, cryptoAlgorithm, blockSizeBits, key1, key1BitSize, key2, key2BitSize, flags, std::forward<BLOCK_CIPHER_CTR_CALLBACK>(callback));
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CryptoKeyInterface::GetCryptoAlgorithm() const -> const Id&
{
	return MTable::_instance._CryptoKeyInterface_GetCryptoAlgorithm(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CryptoKeyInterface::GetBlockBitSize() const -> Int
{
	return MTable::_instance._CryptoKeyInterface_GetBlockBitSize(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CryptoKeyInterface::GetKey1() const -> const void*
{
	return MTable::_instance._CryptoKeyInterface_GetKey1(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CryptoKeyInterface::GetKey1BitSize() const -> Int
{
	return MTable::_instance._CryptoKeyInterface_GetKey1BitSize(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CryptoKeyInterface::GetKey2() const -> const void*
{
	return MTable::_instance._CryptoKeyInterface_GetKey2(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CryptoKeyInterface::GetKey2BitSize() const -> Int
{
	return MTable::_instance._CryptoKeyInterface_GetKey2BitSize(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CryptoKeyInterface::GetFlags() const -> UInt64
{
	return MTable::_instance._CryptoKeyInterface_GetFlags(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CryptoKeyInterface::GetCallbackFunction() const -> const BLOCK_CIPHER_CTR_CALLBACK&
{
	return MTable::_instance._CryptoKeyInterface_GetCallbackFunction(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CryptoKeyInterface::ToString(const FormatStatement* formatStatement) const -> String
{
	return MTable::_instance._CryptoKeyInterface_ToString(this, formatStatement);
}

auto CryptoKeyInterface::Reference::Create(const Id& cryptoAlgorithm, Int blockSizeBits, const void* key1, Int key1BitSize, const void* key2, Int key2BitSize, UInt64 flags, BLOCK_CIPHER_CTR_CALLBACK&& callback) -> maxon::ResultMemT<CryptoKey>
{
	CryptoKeyInterface* res_ = CryptoKeyInterface::Alloc(MAXON_SOURCE_LOCATION, cryptoAlgorithm, blockSizeBits, key1, key1BitSize, key2, key2BitSize, flags, std::forward<BLOCK_CIPHER_CTR_CALLBACK>(callback));
	return CryptoKey(maxon::ForwardResultPtr<CryptoKeyInterface>(res_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CryptoKeyInterface::ConstReferenceFunctionsImpl<S>::GetCryptoAlgorithm() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const Id&>, const Id&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<const Id&>, const Id&>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CryptoKeyInterface* o_ = (const CryptoKeyInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = CryptoKeyInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const Id&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance._CryptoKeyInterface_GetCryptoAlgorithm(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CryptoKeyInterface::ConstReferenceFunctionsImpl<S>::GetBlockBitSize() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CryptoKeyInterface* o_ = (const CryptoKeyInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = CryptoKeyInterface::NullValuePtr(); if (!o_) return 0; } 
	return (MTable::_instance._CryptoKeyInterface_GetBlockBitSize(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CryptoKeyInterface::ConstReferenceFunctionsImpl<S>::GetKey1() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const void*>, const void*>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<const void*>, const void*>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CryptoKeyInterface* o_ = (const CryptoKeyInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = CryptoKeyInterface::NullValuePtr(); if (!o_) return nullptr; } 
	return (MTable::_instance._CryptoKeyInterface_GetKey1(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CryptoKeyInterface::ConstReferenceFunctionsImpl<S>::GetKey1BitSize() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CryptoKeyInterface* o_ = (const CryptoKeyInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = CryptoKeyInterface::NullValuePtr(); if (!o_) return 0; } 
	return (MTable::_instance._CryptoKeyInterface_GetKey1BitSize(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CryptoKeyInterface::ConstReferenceFunctionsImpl<S>::GetKey2() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const void*>, const void*>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<const void*>, const void*>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CryptoKeyInterface* o_ = (const CryptoKeyInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = CryptoKeyInterface::NullValuePtr(); if (!o_) return nullptr; } 
	return (MTable::_instance._CryptoKeyInterface_GetKey2(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CryptoKeyInterface::ConstReferenceFunctionsImpl<S>::GetKey2BitSize() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CryptoKeyInterface* o_ = (const CryptoKeyInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = CryptoKeyInterface::NullValuePtr(); if (!o_) return 0; } 
	return (MTable::_instance._CryptoKeyInterface_GetKey2BitSize(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CryptoKeyInterface::ConstReferenceFunctionsImpl<S>::GetFlags() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<UInt64>, UInt64>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<UInt64>, UInt64>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CryptoKeyInterface* o_ = (const CryptoKeyInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = CryptoKeyInterface::NullValuePtr(); if (!o_) return 0; } 
	return (MTable::_instance._CryptoKeyInterface_GetFlags(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CryptoKeyInterface::ConstReferenceFunctionsImpl<S>::GetCallbackFunction() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const BLOCK_CIPHER_CTR_CALLBACK&>, const BLOCK_CIPHER_CTR_CALLBACK&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<const BLOCK_CIPHER_CTR_CALLBACK&>, const BLOCK_CIPHER_CTR_CALLBACK&>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CryptoKeyInterface* o_ = (const CryptoKeyInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = CryptoKeyInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const BLOCK_CIPHER_CTR_CALLBACK&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance._CryptoKeyInterface_GetCallbackFunction(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CryptoKeyInterface::ConstReferenceFunctionsImpl<S>::ToString(const FormatStatement* formatStatement) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CryptoKeyInterface* o_ = (const CryptoKeyInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = CryptoKeyInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance._CryptoKeyInterface_ToString(o_, formatStatement));
}
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
static maxon::EntityUse s_ui_maxon_CryptoKeyInterface(CryptoKeyInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/cryptography_key.h", false);
#endif
namespace CryptographyOptions
{
	struct CRYPTOKEY_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0x518397d794f3fb62LL), maxon::UInt(36))> { };
}
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif


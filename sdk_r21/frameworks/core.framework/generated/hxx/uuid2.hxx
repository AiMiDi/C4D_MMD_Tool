
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1

struct UuidInterface::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = true;
	void (*_UuidInterface_Free) (const UuidInterface* object);
	UuidInterface* (*_UuidInterface_Alloc) (const maxon::SourceLocation& allocLocation);
	UuidInterface* (*_UuidInterface_Alloc_1) (const maxon::SourceLocation& allocLocation, const UuidInterface& object);
	UuidInterface* (*_UuidInterface_Alloc_2) (const maxon::SourceLocation& allocLocation, const String& uuid);
	UuidInterface* (*_UuidInterface_Alloc_3) (const maxon::SourceLocation& allocLocation, const UChar* uuid, Int uuidSize);
	Bool (*_UuidInterface_IsEmpty) (const UuidInterface* this_);
	Result<void> (*_UuidInterface_CreateId) (UuidInterface* this_);
	Result<void> (*_UuidInterface_Set) (UuidInterface* this_, const String& uuid);
	Result<void> (*_UuidInterface_Set_1) (UuidInterface* this_, const UChar* uuid, Int uuidSize);
	Result<void> (*_UuidInterface_Get) (const UuidInterface* this_, UChar* uuid, Int uuidSize);
	String (*_UuidInterface_ToString) (const UuidInterface* this_, const FormatStatement* formatStatement);
	COMPARERESULT (*_UuidInterface_Compare) (const UuidInterface* this_, const UuidInterface* uuid);
	UInt (*_UuidInterface_GetHashCode) (const UuidInterface* this_);
	Result<void> (*_UuidInterface_DescribeIO) (const DataSerializeInterface& stream);
	Result<String> (*_UuidInterface_CreateUuidString) ();
	template <typename IMPL> void Init()
	{
		_UuidInterface_Free = &IMPL::_UuidInterface_Free;
		_UuidInterface_Alloc = &IMPL::_UuidInterface_Alloc;
		_UuidInterface_Alloc_1 = &IMPL::_UuidInterface_Alloc_1;
		_UuidInterface_Alloc_2 = &IMPL::_UuidInterface_Alloc_2;
		_UuidInterface_Alloc_3 = &IMPL::_UuidInterface_Alloc_3;
		_UuidInterface_IsEmpty = &IMPL::_UuidInterface_IsEmpty;
		_UuidInterface_CreateId = &IMPL::_UuidInterface_CreateId;
		_UuidInterface_Set = &IMPL::_UuidInterface_Set;
		_UuidInterface_Set_1 = &IMPL::_UuidInterface_Set_1;
		_UuidInterface_Get = &IMPL::_UuidInterface_Get;
		_UuidInterface_ToString = &IMPL::_UuidInterface_ToString;
		_UuidInterface_Compare = &IMPL::_UuidInterface_Compare;
		_UuidInterface_GetHashCode = &IMPL::_UuidInterface_GetHashCode;
		_UuidInterface_DescribeIO = &IMPL::_UuidInterface_DescribeIO;
		_UuidInterface_CreateUuidString = &IMPL::_UuidInterface_CreateUuidString;
	}
};

struct UuidInterface::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
	static void _UuidInterface_Free(const UuidInterface* object) { return C::Free(object); }
	static UuidInterface* _UuidInterface_Alloc(const maxon::SourceLocation& allocLocation) { return C::Alloc(allocLocation); }
	static UuidInterface* _UuidInterface_Alloc_1(const maxon::SourceLocation& allocLocation, const UuidInterface& object) { return C::Alloc(allocLocation, ((const C&) object)); }
	static UuidInterface* _UuidInterface_Alloc_2(const maxon::SourceLocation& allocLocation, const String& uuid) { return C::Alloc(allocLocation, uuid); }
	static UuidInterface* _UuidInterface_Alloc_3(const maxon::SourceLocation& allocLocation, const UChar* uuid, Int uuidSize) { return C::Alloc(allocLocation, uuid, uuidSize); }
	static Bool _UuidInterface_IsEmpty(const UuidInterface* this_) { return ((const C*) this_)->IsEmpty(); }
	static Result<void> _UuidInterface_CreateId(UuidInterface* this_) { return ((C*) this_)->CreateId(); }
	static Result<void> _UuidInterface_Set(UuidInterface* this_, const String& uuid) { return ((C*) this_)->Set(uuid); }
	static Result<void> _UuidInterface_Set_1(UuidInterface* this_, const UChar* uuid, Int uuidSize) { return ((C*) this_)->Set(uuid, uuidSize); }
	static Result<void> _UuidInterface_Get(const UuidInterface* this_, UChar* uuid, Int uuidSize) { return ((const C*) this_)->Get(uuid, uuidSize); }
	static String _UuidInterface_ToString(const UuidInterface* this_, const FormatStatement* formatStatement) { return ((const C*) this_)->ToString(formatStatement); }
	static COMPARERESULT _UuidInterface_Compare(const UuidInterface* this_, const UuidInterface* uuid) { return ((const C*) this_)->Compare(uuid); }
	static UInt _UuidInterface_GetHashCode(const UuidInterface* this_) { return ((const C*) this_)->GetHashCode(); }
	static Result<void> _UuidInterface_DescribeIO(const DataSerializeInterface& stream) { return C::DescribeIO(stream); }
	static Result<String> _UuidInterface_CreateUuidString() { return C::CreateUuidString(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto UuidInterface::Free(const UuidInterface* object) -> void
{
	return MTable::_instance._UuidInterface_Free(object);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UuidInterface::Alloc(const maxon::SourceLocation& allocLocation) -> UuidInterface*
{
	return MTable::_instance._UuidInterface_Alloc(allocLocation);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UuidInterface::Alloc(const maxon::SourceLocation& allocLocation, const UuidInterface& object) -> UuidInterface*
{
	return MTable::_instance._UuidInterface_Alloc_1(allocLocation, object);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UuidInterface::Alloc(const maxon::SourceLocation& allocLocation, const String& uuid) -> UuidInterface*
{
	return MTable::_instance._UuidInterface_Alloc_2(allocLocation, uuid);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UuidInterface::Alloc(const maxon::SourceLocation& allocLocation, const UChar* uuid, Int uuidSize) -> UuidInterface*
{
	return MTable::_instance._UuidInterface_Alloc_3(allocLocation, uuid, uuidSize);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UuidInterface::IsEmpty() const -> Bool
{
	return MTable::_instance._UuidInterface_IsEmpty(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UuidInterface::CreateId() -> Result<void>
{
	return MTable::_instance._UuidInterface_CreateId(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UuidInterface::Set(const String& uuid) -> Result<void>
{
	return MTable::_instance._UuidInterface_Set(this, uuid);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UuidInterface::Set(const UChar* uuid, Int uuidSize) -> Result<void>
{
	return MTable::_instance._UuidInterface_Set_1(this, uuid, uuidSize);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UuidInterface::Get(UChar* uuid, Int uuidSize) const -> Result<void>
{
	return MTable::_instance._UuidInterface_Get(this, uuid, uuidSize);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UuidInterface::ToString(const FormatStatement* formatStatement) const -> String
{
	return MTable::_instance._UuidInterface_ToString(this, formatStatement);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UuidInterface::Compare(const UuidInterface* uuid) const -> COMPARERESULT
{
	return MTable::_instance._UuidInterface_Compare(this, uuid);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UuidInterface::GetHashCode() const -> UInt
{
	return MTable::_instance._UuidInterface_GetHashCode(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UuidInterface::DescribeIO(const DataSerializeInterface& stream) -> Result<void>
{
	return MTable::_instance._UuidInterface_DescribeIO(stream);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UuidInterface::CreateUuidString() -> Result<String>
{
	return MTable::_instance._UuidInterface_CreateUuidString();
}

auto UuidInterface::Reference::Create() -> maxon::ResultMemT<Uuid>
{
	UuidInterface* res_ = UuidInterface::Alloc(MAXON_SOURCE_LOCATION);
	return Uuid(maxon::ForwardResultPtr<UuidInterface>(res_));
}
auto UuidInterface::Reference::Create(const String& uuid) -> maxon::ResultMemT<Uuid>
{
	UuidInterface* res_ = UuidInterface::Alloc(MAXON_SOURCE_LOCATION, uuid);
	return Uuid(maxon::ForwardResultPtr<UuidInterface>(res_));
}
auto UuidInterface::Reference::Create(const UChar* uuid, Int uuidSize) -> maxon::ResultMemT<Uuid>
{
	UuidInterface* res_ = UuidInterface::Alloc(MAXON_SOURCE_LOCATION, uuid, uuidSize);
	return Uuid(maxon::ForwardResultPtr<UuidInterface>(res_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UuidInterface::Hxx1::ConstReferenceFunctionsImpl<S>::IsEmpty() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UuidInterface* o_ = (const UuidInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UuidInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (MTable::_instance._UuidInterface_IsEmpty(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UuidInterface::Hxx1::ConstReferenceFunctionsImpl<S>::IsPopulated() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UuidInterface* o_ = (const UuidInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UuidInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->IsPopulated());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UuidInterface::Hxx1::ReferenceFunctionsImpl<S>::CreateId() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); UuidInterface* o_ = (UuidInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._UuidInterface_CreateId(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UuidInterface::Hxx1::COWReferenceFunctionsImpl<S>::CreateId() -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); UuidInterface* o_ = (UuidInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (MTable::_instance._UuidInterface_CreateId(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UuidInterface::Hxx1::ReferenceFunctionsImpl<S>::Set(const String& uuid) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); UuidInterface* o_ = (UuidInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._UuidInterface_Set(o_, uuid));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UuidInterface::Hxx1::COWReferenceFunctionsImpl<S>::Set(const String& uuid) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); UuidInterface* o_ = (UuidInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (MTable::_instance._UuidInterface_Set(o_, uuid));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UuidInterface::Hxx1::ReferenceFunctionsImpl<S>::Set(const UChar* uuid, Int uuidSize) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); UuidInterface* o_ = (UuidInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._UuidInterface_Set_1(o_, uuid, uuidSize));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UuidInterface::Hxx1::COWReferenceFunctionsImpl<S>::Set(const UChar* uuid, Int uuidSize) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); UuidInterface* o_ = (UuidInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (MTable::_instance._UuidInterface_Set_1(o_, uuid, uuidSize));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UuidInterface::Hxx1::ConstReferenceFunctionsImpl<S>::Get(UChar* uuid, Int uuidSize) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UuidInterface* o_ = (const UuidInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UuidInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance._UuidInterface_Get(o_, uuid, uuidSize));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UuidInterface::Hxx1::ConstReferenceFunctionsImpl<S>::ToString(const FormatStatement* formatStatement) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UuidInterface* o_ = (const UuidInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UuidInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance._UuidInterface_ToString(o_, formatStatement));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UuidInterface::Hxx1::ConstReferenceFunctionsImpl<S>::Compare(const UuidInterface* uuid) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<COMPARERESULT>, COMPARERESULT>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<COMPARERESULT>, COMPARERESULT>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UuidInterface* o_ = (const UuidInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UuidInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<COMPARERESULT>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance._UuidInterface_Compare(o_, uuid));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UuidInterface::Hxx1::ConstReferenceFunctionsImpl<S>::DescribeIO(const DataSerializeInterface& stream) -> Result<void> { return (MTable::_instance._UuidInterface_DescribeIO(stream)); }
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UuidInterface::Hxx1::ConstReferenceFunctionsImpl<S>::CreateUuidString() -> Result<String> { return (MTable::_instance._UuidInterface_CreateUuidString()); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_UuidInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_UuidInterface() { new (s_ui_maxon_UuidInterface) maxon::EntityUse(UuidInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/uuid.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_UuidInterface(UuidInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/uuid.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#if (defined MAXON_TARGET_WINDOWS) && (defined MAXON_TARGET_DEBUG)
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif


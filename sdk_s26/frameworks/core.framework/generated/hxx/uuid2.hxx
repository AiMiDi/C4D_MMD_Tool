
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1
constexpr const maxon::Char* UuidInterface::PrivateGetCppName() { return "maxon::Uuid"; }

struct UuidInterface::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = true;
	void (*UuidInterface_Free) (const UuidInterface* object);
	UuidInterface* (*UuidInterface_Alloc) (const maxon::SourceLocation& allocLocation);
	UuidInterface* (*UuidInterface_Alloc_1) (const maxon::SourceLocation& allocLocation, const UuidInterface& object);
	UuidInterface* (*UuidInterface_Alloc_2) (const maxon::SourceLocation& allocLocation, const String& uuid);
	UuidInterface* (*UuidInterface_Alloc_3) (const maxon::SourceLocation& allocLocation, const UChar* uuid, Int uuidSize);
	Bool (*UuidInterface_IsEmpty) (const UuidInterface* this_);
	Result<void> (*UuidInterface_CreateId) (UuidInterface* this_);
	Result<void> (*UuidInterface_Set) (UuidInterface* this_, const String& uuid);
	Result<void> (*UuidInterface_Set_1) (UuidInterface* this_, const UChar* uuid, Int uuidSize);
	Result<void> (*UuidInterface_Get) (const UuidInterface* this_, UChar* uuid, Int uuidSize);
	String (*UuidInterface_ToString) (const UuidInterface* this_, const FormatStatement* formatStatement);
	COMPARERESULT (*UuidInterface_Compare) (const UuidInterface* this_, const UuidInterface* uuid);
	HashInt (*UuidInterface_GetHashCode) (const UuidInterface* this_);
	Result<void> (*UuidInterface_DescribeIO) (const DataSerializeInterface& stream);
	Result<String> (*UuidInterface_CreateUuidString) ();
	Result<void> (*UuidInterface_CreateUuid) (maxon::AddArrayT<UChar, 16>& uuid);
	template <typename IMPL> void Init()
	{
		UuidInterface_Free = &IMPL::UuidInterface_Free;
		UuidInterface_Alloc = &IMPL::UuidInterface_Alloc;
		UuidInterface_Alloc_1 = &IMPL::UuidInterface_Alloc_1;
		UuidInterface_Alloc_2 = &IMPL::UuidInterface_Alloc_2;
		UuidInterface_Alloc_3 = &IMPL::UuidInterface_Alloc_3;
		UuidInterface_IsEmpty = &IMPL::UuidInterface_IsEmpty;
		UuidInterface_CreateId = &IMPL::UuidInterface_CreateId;
		UuidInterface_Set = &IMPL::UuidInterface_Set;
		UuidInterface_Set_1 = &IMPL::UuidInterface_Set_1;
		UuidInterface_Get = &IMPL::UuidInterface_Get;
		UuidInterface_ToString = &IMPL::UuidInterface_ToString;
		UuidInterface_Compare = &IMPL::UuidInterface_Compare;
		UuidInterface_GetHashCode = &IMPL::UuidInterface_GetHashCode;
		UuidInterface_DescribeIO = &IMPL::UuidInterface_DescribeIO;
		UuidInterface_CreateUuidString = &IMPL::UuidInterface_CreateUuidString;
		UuidInterface_CreateUuid = &IMPL::UuidInterface_CreateUuid;
	}
};

struct UuidInterface::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
		static void UuidInterface_Free(const UuidInterface* object) { return C::Free(object); }
		static UuidInterface* UuidInterface_Alloc(const maxon::SourceLocation& allocLocation) { return C::Alloc(allocLocation); }
		static UuidInterface* UuidInterface_Alloc_1(const maxon::SourceLocation& allocLocation, const UuidInterface& object) { return C::Alloc(allocLocation, ((const C&) object)); }
		static UuidInterface* UuidInterface_Alloc_2(const maxon::SourceLocation& allocLocation, const String& uuid) { return C::Alloc(allocLocation, uuid); }
		static UuidInterface* UuidInterface_Alloc_3(const maxon::SourceLocation& allocLocation, const UChar* uuid, Int uuidSize) { return C::Alloc(allocLocation, uuid, uuidSize); }
		static Bool UuidInterface_IsEmpty(const UuidInterface* this_) { return C::Get(this_)->IsEmpty(); }
		static Result<void> UuidInterface_CreateId(UuidInterface* this_) { return C::Get(this_)->CreateId(); }
		static Result<void> UuidInterface_Set(UuidInterface* this_, const String& uuid) { return C::Get(this_)->Set(uuid); }
		static Result<void> UuidInterface_Set_1(UuidInterface* this_, const UChar* uuid, Int uuidSize) { return C::Get(this_)->Set(uuid, uuidSize); }
		static Result<void> UuidInterface_Get(const UuidInterface* this_, UChar* uuid, Int uuidSize) { return C::Get(this_)->Get(uuid, uuidSize); }
		static String UuidInterface_ToString(const UuidInterface* this_, const FormatStatement* formatStatement) { return C::Get(this_)->ToString(formatStatement); }
		static COMPARERESULT UuidInterface_Compare(const UuidInterface* this_, const UuidInterface* uuid) { return C::Get(this_)->Compare(uuid); }
		static HashInt UuidInterface_GetHashCode(const UuidInterface* this_) { return C::Get(this_)->GetHashCode(); }
		static Result<void> UuidInterface_DescribeIO(const DataSerializeInterface& stream) { return C::DescribeIO(stream); }
		static Result<String> UuidInterface_CreateUuidString() { return C::CreateUuidString(); }
		static Result<void> UuidInterface_CreateUuid(maxon::AddArrayT<UChar, 16>& uuid) { return C::CreateUuid(uuid); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto UuidInterface::Free(const UuidInterface* object) -> void
{
	return MTable::_instance.UuidInterface_Free(object);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UuidInterface::Alloc(const maxon::SourceLocation& allocLocation) -> UuidInterface*
{
	return MTable::_instance.UuidInterface_Alloc(allocLocation);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UuidInterface::Alloc(const maxon::SourceLocation& allocLocation, const UuidInterface& object) -> UuidInterface*
{
	return MTable::_instance.UuidInterface_Alloc_1(allocLocation, object);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UuidInterface::Alloc(const maxon::SourceLocation& allocLocation, const String& uuid) -> UuidInterface*
{
	return MTable::_instance.UuidInterface_Alloc_2(allocLocation, uuid);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UuidInterface::Alloc(const maxon::SourceLocation& allocLocation, const UChar* uuid, Int uuidSize) -> UuidInterface*
{
	return MTable::_instance.UuidInterface_Alloc_3(allocLocation, uuid, uuidSize);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UuidInterface::IsEmpty() const -> Bool
{
	return MTable::_instance.UuidInterface_IsEmpty(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UuidInterface::CreateId() -> Result<void>
{
	return MTable::_instance.UuidInterface_CreateId(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UuidInterface::Set(const String& uuid) -> Result<void>
{
	return MTable::_instance.UuidInterface_Set(this, uuid);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UuidInterface::Set(const UChar* uuid, Int uuidSize) -> Result<void>
{
	return MTable::_instance.UuidInterface_Set_1(this, uuid, uuidSize);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UuidInterface::Get(UChar* uuid, Int uuidSize) const -> Result<void>
{
	return MTable::_instance.UuidInterface_Get(this, uuid, uuidSize);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UuidInterface::ToString(const FormatStatement* formatStatement) const -> String
{
	return MTable::_instance.UuidInterface_ToString(this, formatStatement);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UuidInterface::Compare(const UuidInterface* uuid) const -> COMPARERESULT
{
	return MTable::_instance.UuidInterface_Compare(this, uuid);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UuidInterface::GetHashCode() const -> HashInt
{
	return MTable::_instance.UuidInterface_GetHashCode(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UuidInterface::DescribeIO(const DataSerializeInterface& stream) -> Result<void>
{
	return MTable::_instance.UuidInterface_DescribeIO(stream);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UuidInterface::CreateUuidString() -> Result<String>
{
	return MTable::_instance.UuidInterface_CreateUuidString();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UuidInterface::CreateUuid(maxon::AddArrayT<UChar, 16>& uuid) -> Result<void>
{
	return MTable::_instance.UuidInterface_CreateUuid(uuid);
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
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UuidInterface::Hxx1::ConstFn<S>::IsEmpty() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UuidInterface* o_ = (const UuidInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UuidInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (MTable::_instance.UuidInterface_IsEmpty(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UuidInterface::Hxx1::ConstFn<S>::IsPopulated() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UuidInterface* o_ = (const UuidInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UuidInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->IsPopulated());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UuidInterface::Hxx1::Fn<S>::CreateId() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); UuidInterface* o_ = (UuidInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.UuidInterface_CreateId(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UuidInterface::Hxx1::COWFn<S>::CreateId() -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); UuidInterface* o_ = (UuidInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (MTable::_instance.UuidInterface_CreateId(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UuidInterface::Hxx1::Fn<S>::Set(const String& uuid) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); UuidInterface* o_ = (UuidInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.UuidInterface_Set(o_, uuid));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UuidInterface::Hxx1::COWFn<S>::Set(const String& uuid) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); UuidInterface* o_ = (UuidInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (MTable::_instance.UuidInterface_Set(o_, uuid));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UuidInterface::Hxx1::Fn<S>::Set(const UChar* uuid, Int uuidSize) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); UuidInterface* o_ = (UuidInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.UuidInterface_Set_1(o_, uuid, uuidSize));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UuidInterface::Hxx1::COWFn<S>::Set(const UChar* uuid, Int uuidSize) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); UuidInterface* o_ = (UuidInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (MTable::_instance.UuidInterface_Set_1(o_, uuid, uuidSize));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UuidInterface::Hxx1::ConstFn<S>::Get(UChar* uuid, Int uuidSize) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UuidInterface* o_ = (const UuidInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UuidInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.UuidInterface_Get(o_, uuid, uuidSize));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UuidInterface::Hxx1::ConstFn<S>::ToString(const FormatStatement* formatStatement) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UuidInterface* o_ = (const UuidInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UuidInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance.UuidInterface_ToString(o_, formatStatement));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UuidInterface::Hxx1::ConstFn<S>::Compare(const UuidInterface* uuid) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<COMPARERESULT>, COMPARERESULT>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<COMPARERESULT>, COMPARERESULT>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UuidInterface* o_ = (const UuidInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UuidInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<COMPARERESULT>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance.UuidInterface_Compare(o_, uuid));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UuidInterface::Hxx1::ConstFn<S>::DescribeIO(const DataSerializeInterface& stream) -> Result<void>
{
	return (MTable::_instance.UuidInterface_DescribeIO(stream));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UuidInterface::Hxx1::ConstFn<S>::CreateUuidString() -> Result<String>
{
	return (MTable::_instance.UuidInterface_CreateUuidString());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UuidInterface::Hxx1::ConstFn<S>::CreateUuid(maxon::AddArrayT<UChar, 16>& uuid) -> Result<void>
{
	return (MTable::_instance.UuidInterface_CreateUuid(uuid));
}
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_uuid)
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


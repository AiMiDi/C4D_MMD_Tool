
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
	PRIVATE_MAXON_SF_POINTER(UuidInterface_Free, Free, MAXON_EXPAND_VA_ARGS, (void), const UuidInterface* object);
	PRIVATE_MAXON_SF_POINTER(UuidInterface_Alloc, Alloc, MAXON_IGNORE_VA_ARGS, (UuidInterface*), const maxon::SourceLocation& allocLocation);
	PRIVATE_MAXON_SF_POINTER(UuidInterface_Alloc_1, Alloc, MAXON_IGNORE_VA_ARGS, (UuidInterface*), const maxon::SourceLocation& allocLocation, const UuidInterface& object);
	PRIVATE_MAXON_SF_POINTER(UuidInterface_Alloc_2, Alloc, MAXON_IGNORE_VA_ARGS, (UuidInterface*), const maxon::SourceLocation& allocLocation, const String& uuid);
	PRIVATE_MAXON_SF_POINTER(UuidInterface_Alloc_3, Alloc, MAXON_IGNORE_VA_ARGS, (UuidInterface*), const maxon::SourceLocation& allocLocation, const UChar* uuid, Int uuidSize);
	PRIVATE_MAXON_MF_POINTER(UuidInterface_IsEmpty, IsEmpty, false, UuidInterface, const, (Bool));
	PRIVATE_MAXON_MF_POINTER(UuidInterface_CreateId, CreateId, false, UuidInterface,, (Result<void>));
	PRIVATE_MAXON_MF_POINTER(UuidInterface_Set, Set, false, UuidInterface,, (Result<void>), const String& uuid);
	PRIVATE_MAXON_MF_POINTER(UuidInterface_Set_1, Set, false, UuidInterface,, (Result<void>), const UChar* uuid, Int uuidSize);
	PRIVATE_MAXON_MF_POINTER(UuidInterface_Get, Get, false, UuidInterface, const, (Result<void>), UChar* uuid, Int uuidSize);
	PRIVATE_MAXON_MF_POINTER(UuidInterface_ToString, ToString, false, UuidInterface, const, (String), const FormatStatement* formatStatement);
	PRIVATE_MAXON_MF_POINTER(UuidInterface_Compare, Compare, false, UuidInterface, const, (COMPARERESULT), const UuidInterface* uuid);
	PRIVATE_MAXON_MF_POINTER(UuidInterface_GetHashCode, GetHashCode, false, UuidInterface, const, (HashInt));
	PRIVATE_MAXON_MF_POINTER(UuidInterface_GetUniqueHashCode, GetUniqueHashCode, false, UuidInterface, const, (UniqueHash));
	PRIVATE_MAXON_SF_POINTER(UuidInterface_DescribeIO, DescribeIO, MAXON_EXPAND_VA_ARGS, (Result<void>), const DataSerializeInterface& stream);
	PRIVATE_MAXON_SF_POINTER(UuidInterface_CreateUuidString, CreateUuidString, MAXON_EXPAND_VA_ARGS, (Result<String>));
	PRIVATE_MAXON_SF_POINTER(UuidInterface_CreateUuid, CreateUuid, MAXON_EXPAND_VA_ARGS, (Result<void>), maxon::AddArrayT<UChar, 16>& uuid);
	template <typename IMPL> void Init()
	{
		UuidInterface_Free = UuidInterface_Free_GetPtr<IMPL>(true);
		UuidInterface_Alloc = UuidInterface_Alloc_GetPtr<IMPL>(true);
		UuidInterface_Alloc_1 = UuidInterface_Alloc_1_GetPtr<IMPL>(true);
		UuidInterface_Alloc_2 = UuidInterface_Alloc_2_GetPtr<IMPL>(true);
		UuidInterface_Alloc_3 = UuidInterface_Alloc_3_GetPtr<IMPL>(true);
		UuidInterface_IsEmpty = UuidInterface_IsEmpty_GetPtr<IMPL>(0, true).first;
		UuidInterface_CreateId = UuidInterface_CreateId_GetPtr<IMPL>(0, true).first;
		UuidInterface_Set = UuidInterface_Set_GetPtr<IMPL>(0, true).first;
		UuidInterface_Set_1 = UuidInterface_Set_1_GetPtr<IMPL>(0, true).first;
		UuidInterface_Get = UuidInterface_Get_GetPtr<IMPL>(0, true).first;
		UuidInterface_ToString = UuidInterface_ToString_GetPtr<IMPL>(0, true).first;
		UuidInterface_Compare = UuidInterface_Compare_GetPtr<IMPL>(0, true).first;
		UuidInterface_GetHashCode = UuidInterface_GetHashCode_GetPtr<IMPL>(0, true).first;
		UuidInterface_GetUniqueHashCode = UuidInterface_GetUniqueHashCode_GetPtr<IMPL>(0, true).first;
		UuidInterface_DescribeIO = UuidInterface_DescribeIO_GetPtr<IMPL>(true);
		UuidInterface_CreateUuidString = UuidInterface_CreateUuidString_GetPtr<IMPL>(true);
		UuidInterface_CreateUuid = UuidInterface_CreateUuid_GetPtr<IMPL>(true);
	}
};

struct UuidInterface::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
		using Implementation = C;
		static void UuidInterface_Free(const UuidInterface* object) { return C::Free(object); }
		static UuidInterface* UuidInterface_Alloc(const maxon::SourceLocation& allocLocation) { return C::Alloc(allocLocation); }
		static UuidInterface* UuidInterface_Alloc_1(const maxon::SourceLocation& allocLocation, const UuidInterface& object) { return C::Alloc(allocLocation, ((const C&) object)); }
		static UuidInterface* UuidInterface_Alloc_2(const maxon::SourceLocation& allocLocation, const String& uuid) { return C::Alloc(allocLocation, uuid); }
		static UuidInterface* UuidInterface_Alloc_3(const maxon::SourceLocation& allocLocation, const UChar* uuid, Int uuidSize) { return C::Alloc(allocLocation, uuid, uuidSize); }
		PRIVATE_MAXON_MF_WRAPPER(UuidInterface_IsEmpty, UuidInterface, const, (Bool)) { return C::Get(PRIVATE_MAXON_MF_THIS(const UuidInterface))->IsEmpty(); }
		PRIVATE_MAXON_MF_WRAPPER(UuidInterface_CreateId, UuidInterface,, (Result<void>)) { return C::Get(PRIVATE_MAXON_MF_THIS(UuidInterface))->CreateId(); }
		PRIVATE_MAXON_MF_WRAPPER(UuidInterface_Set, UuidInterface,, (Result<void>), const String& uuid) { return C::Get(PRIVATE_MAXON_MF_THIS(UuidInterface))->Set(uuid); }
		PRIVATE_MAXON_MF_WRAPPER(UuidInterface_Set_1, UuidInterface,, (Result<void>), const UChar* uuid, Int uuidSize) { return C::Get(PRIVATE_MAXON_MF_THIS(UuidInterface))->Set(uuid, uuidSize); }
		PRIVATE_MAXON_MF_WRAPPER(UuidInterface_Get, UuidInterface, const, (Result<void>), UChar* uuid, Int uuidSize) { return C::Get(PRIVATE_MAXON_MF_THIS(const UuidInterface))->Get(uuid, uuidSize); }
		PRIVATE_MAXON_MF_WRAPPER(UuidInterface_ToString, UuidInterface, const, (String), const FormatStatement* formatStatement) { return C::Get(PRIVATE_MAXON_MF_THIS(const UuidInterface))->ToString(formatStatement); }
		PRIVATE_MAXON_MF_WRAPPER(UuidInterface_Compare, UuidInterface, const, (COMPARERESULT), const UuidInterface* uuid) { return C::Get(PRIVATE_MAXON_MF_THIS(const UuidInterface))->Compare(uuid); }
		PRIVATE_MAXON_MF_WRAPPER(UuidInterface_GetHashCode, UuidInterface, const, (HashInt)) { return C::Get(PRIVATE_MAXON_MF_THIS(const UuidInterface))->GetHashCode(); }
		PRIVATE_MAXON_MF_WRAPPER(UuidInterface_GetUniqueHashCode, UuidInterface, const, (UniqueHash)) { return C::Get(PRIVATE_MAXON_MF_THIS(const UuidInterface))->GetUniqueHashCode(); }
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
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.UuidInterface_IsEmpty);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UuidInterface::CreateId() -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.UuidInterface_CreateId);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UuidInterface::Set(const String& uuid) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.UuidInterface_Set, uuid);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UuidInterface::Set(const UChar* uuid, Int uuidSize) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.UuidInterface_Set_1, uuid, uuidSize);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UuidInterface::Get(UChar* uuid, Int uuidSize) const -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.UuidInterface_Get, uuid, uuidSize);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UuidInterface::ToString(const FormatStatement* formatStatement) const -> String
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.UuidInterface_ToString, formatStatement);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UuidInterface::Compare(const UuidInterface* uuid) const -> COMPARERESULT
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.UuidInterface_Compare, uuid);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UuidInterface::GetHashCode() const -> HashInt
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.UuidInterface_GetHashCode);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UuidInterface::GetUniqueHashCode() const -> UniqueHash
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.UuidInterface_GetUniqueHashCode);
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
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const UuidInterface* o_ = (const UuidInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = UuidInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UuidInterface_IsEmpty));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UuidInterface::Hxx1::ConstFn<S>::IsPopulated() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const UuidInterface* o_ = (const UuidInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = UuidInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->IsPopulated());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UuidInterface::Hxx1::Fn<S>::CreateId() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); UuidInterface* o_ = (UuidInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UuidInterface_CreateId));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UuidInterface::Hxx1::COWFn<S>::CreateId() -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); UuidInterface* o_ = (UuidInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UuidInterface_CreateId));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UuidInterface::Hxx1::Fn<S>::Set(const String& uuid) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); UuidInterface* o_ = (UuidInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UuidInterface_Set, uuid));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UuidInterface::Hxx1::COWFn<S>::Set(const String& uuid) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); UuidInterface* o_ = (UuidInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UuidInterface_Set, uuid));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UuidInterface::Hxx1::Fn<S>::Set(const UChar* uuid, Int uuidSize) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); UuidInterface* o_ = (UuidInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UuidInterface_Set_1, uuid, uuidSize));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UuidInterface::Hxx1::COWFn<S>::Set(const UChar* uuid, Int uuidSize) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); UuidInterface* o_ = (UuidInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UuidInterface_Set_1, uuid, uuidSize));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UuidInterface::Hxx1::ConstFn<S>::Get(UChar* uuid, Int uuidSize) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const UuidInterface* o_ = (const UuidInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = UuidInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UuidInterface_Get, uuid, uuidSize));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UuidInterface::Hxx1::ConstFn<S>::ToString(const FormatStatement* formatStatement) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const UuidInterface* o_ = (const UuidInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = UuidInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UuidInterface_ToString, formatStatement));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UuidInterface::Hxx1::ConstFn<S>::Compare(const UuidInterface* uuid) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<COMPARERESULT>, COMPARERESULT>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<COMPARERESULT>, COMPARERESULT>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const UuidInterface* o_ = (const UuidInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = UuidInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<COMPARERESULT>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UuidInterface_Compare, uuid));
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



#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1

struct DataDictionaryObjectInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(EraseData);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetData);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(InitIterator);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(IsEmpty);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Reset);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(SetData);
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	PRIVATE_MAXON_MF_POINTER(DataDictionaryObjectInterface_SetData, SetData, true, maxon::GenericComponent,, (Result<void>), ForwardingDataPtr&& key, Data&& data);
	maxon::Int DataDictionaryObjectInterface_SetData_Offset;
	PRIVATE_MAXON_MF_POINTER(DataDictionaryObjectInterface_GetData, GetData, true, maxon::GenericComponent, const, (Result<Data>), const ConstDataPtr& key);
	maxon::Int DataDictionaryObjectInterface_GetData_Offset;
	PRIVATE_MAXON_MF_POINTER(DataDictionaryObjectInterface_EraseData, EraseData, true, maxon::GenericComponent,, (Result<void>), const ConstDataPtr& key);
	maxon::Int DataDictionaryObjectInterface_EraseData_Offset;
	PRIVATE_MAXON_MF_POINTER(DataDictionaryObjectInterface_Reset, Reset, true, maxon::GenericComponent,, (void));
	maxon::Int DataDictionaryObjectInterface_Reset_Offset;
	PRIVATE_MAXON_MF_POINTER(DataDictionaryObjectInterface_IsEmpty, IsEmpty, true, maxon::GenericComponent, const, (Bool));
	maxon::Int DataDictionaryObjectInterface_IsEmpty_Offset;
	PRIVATE_MAXON_MF_POINTER(DataDictionaryObjectInterface_InitIterator, InitIterator, true, maxon::GenericComponent, const, (void), DataDictionaryIteratorInterface* iterator, Bool end);
	maxon::Int DataDictionaryObjectInterface_InitIterator_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDictionaryObjectInterface, SetData))
	{
		maxon::Tie(DataDictionaryObjectInterface_SetData, DataDictionaryObjectInterface_SetData_Offset) = DataDictionaryObjectInterface_SetData_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDictionaryObjectInterface, GetData))
	{
		maxon::Tie(DataDictionaryObjectInterface_GetData, DataDictionaryObjectInterface_GetData_Offset) = DataDictionaryObjectInterface_GetData_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDictionaryObjectInterface, EraseData))
	{
		maxon::Tie(DataDictionaryObjectInterface_EraseData, DataDictionaryObjectInterface_EraseData_Offset) = DataDictionaryObjectInterface_EraseData_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDictionaryObjectInterface, Reset))
	{
		maxon::Tie(DataDictionaryObjectInterface_Reset, DataDictionaryObjectInterface_Reset_Offset) = DataDictionaryObjectInterface_Reset_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDictionaryObjectInterface, IsEmpty))
	{
		maxon::Tie(DataDictionaryObjectInterface_IsEmpty, DataDictionaryObjectInterface_IsEmpty_Offset) = DataDictionaryObjectInterface_IsEmpty_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDictionaryObjectInterface, InitIterator))
	{
		maxon::Tie(DataDictionaryObjectInterface_InitIterator, DataDictionaryObjectInterface_InitIterator_Offset) = DataDictionaryObjectInterface_InitIterator_GetPtr<W>(offset, true);
	}
	}
	template <typename S> using CombinedMTable = maxon::PrivateCombinedMTable<DataDictionaryObjectInterface, typename ObjectInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<DataDictionaryObjectInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct DataDictionaryObjectInterface::Hxx2
{
	template <typename S> class CWrapper : public ObjectInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(EraseData);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetData);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(InitIterator);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(IsEmpty);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Reset);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(SetData);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename ObjectInterface::Hxx2::template CWrapper<S>;
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (DataDictionaryObjectInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, DataDictionaryObjectInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		PRIVATE_MAXON_MF_WRAPPER(DataDictionaryObjectInterface_SetData, maxon::GenericComponent,, (Result<void>), ForwardingDataPtr&& key, Data&& data) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->SetData(std::forward<ForwardingDataPtr>(key), std::forward<Data>(data)); }
		PRIVATE_MAXON_MF_WRAPPER(DataDictionaryObjectInterface_GetData, maxon::GenericComponent, const, (Result<Data>), const ConstDataPtr& key) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetData(key); }
		PRIVATE_MAXON_MF_WRAPPER(DataDictionaryObjectInterface_EraseData, maxon::GenericComponent,, (Result<void>), const ConstDataPtr& key) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->EraseData(key); }
		PRIVATE_MAXON_MF_WRAPPER(DataDictionaryObjectInterface_Reset, maxon::GenericComponent,, (void)) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->Reset(); }
		PRIVATE_MAXON_MF_WRAPPER(DataDictionaryObjectInterface_IsEmpty, maxon::GenericComponent, const, (Bool)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->IsEmpty(); }
		PRIVATE_MAXON_MF_WRAPPER(DataDictionaryObjectInterface_InitIterator, maxon::GenericComponent, const, (void), DataDictionaryIteratorInterface* iterator, Bool end) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->InitIterator(iterator, end); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryObjectInterface::SetData(ForwardingDataPtr&& key, Data&& data) -> Result<void>
{
	const DataDictionaryObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataDictionaryObjectInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.DataDictionaryObjectInterface_SetData_Offset), mt_.DataDictionaryObjectInterface_SetData, std::forward<ForwardingDataPtr>(key), std::forward<Data>(data));
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryObjectInterface::GetData(const ConstDataPtr& key) const -> Result<Data>
{
	const DataDictionaryObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataDictionaryObjectInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.DataDictionaryObjectInterface_GetData_Offset), mt_.DataDictionaryObjectInterface_GetData, key);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryObjectInterface::EraseData(const ConstDataPtr& key) -> Result<void>
{
	const DataDictionaryObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataDictionaryObjectInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.DataDictionaryObjectInterface_EraseData_Offset), mt_.DataDictionaryObjectInterface_EraseData, key);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryObjectInterface::Reset() -> void
{
	const DataDictionaryObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataDictionaryObjectInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.DataDictionaryObjectInterface_Reset_Offset), mt_.DataDictionaryObjectInterface_Reset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryObjectInterface::IsEmpty() const -> Bool
{
	const DataDictionaryObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataDictionaryObjectInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.DataDictionaryObjectInterface_IsEmpty_Offset), mt_.DataDictionaryObjectInterface_IsEmpty);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryObjectInterface::InitIterator(DataDictionaryIteratorInterface* iterator, Bool end) const -> void
{
	const DataDictionaryObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataDictionaryObjectInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.DataDictionaryObjectInterface_InitIterator_Offset), mt_.DataDictionaryObjectInterface_InitIterator, iterator, end);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryObjectInterface::Hxx1::Fn<S>::SetData(ForwardingDataPtr&& key, Data&& data) const -> maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)>
{
	HXXRETURN1(maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)>); HXXRES; HXXNONCONST(, , false, HXXRET2b(NULLPTR)) HXXTABLE(DataDictionaryObjectInterface_SetData); 
	auto res_ = PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataDictionaryObjectInterface_SetData_Offset), mt_.DataDictionaryObjectInterface_SetData, std::forward<ForwardingDataPtr>(key), std::forward<Data>(data));
	return ReturnHelper::Return(this, res_.GetErrorStorage());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryObjectInterface::Hxx1::COWFn<S>::SetData(ForwardingDataPtr&& key, Data&& data) -> maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)>
{
	HXXRETURN1(maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2b(MAKE_WRITABLE_FAILED)) HXXTABLE(DataDictionaryObjectInterface_SetData); 
	auto res_ = PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataDictionaryObjectInterface_SetData_Offset), mt_.DataDictionaryObjectInterface_SetData, std::forward<ForwardingDataPtr>(key), std::forward<Data>(data));
	return ReturnHelper::Return(this, res_.GetErrorStorage());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryObjectInterface::Hxx1::Fn<S>::SetData(ForwardingDataPtr&& key, const Data& data) const -> maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)>
{
	HXXRETURN1(maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)>); HXXRES; HXXNONCONST(, , false, HXXRET2b(NULLPTR)) 
	auto res_ = o_->SetData(std::forward<ForwardingDataPtr>(key), data);
	return ReturnHelper::Return(this, res_.GetErrorStorage());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryObjectInterface::Hxx1::COWFn<S>::SetData(ForwardingDataPtr&& key, const Data& data) -> maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)>
{
	HXXRETURN1(maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)>); HXXSUPER("DataDictionaryObjectInterface::SetData"); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2b(MAKE_WRITABLE_FAILED)) 
	auto res_ = o_->SetData(std::forward<ForwardingDataPtr>(key), data);
	return ReturnHelper::Return(this, res_.GetErrorStorage());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryObjectInterface::Hxx1::ConstFn<S>::GetData(const ConstDataPtr& key) const -> Result<Data>
{
	HXXRETURN0(Result<Data>); HXXRES; HXXCONST(HXXRET1(NULLPTR)) HXXTABLE(DataDictionaryObjectInterface_GetData); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.DataDictionaryObjectInterface_GetData_Offset), mt_.DataDictionaryObjectInterface_GetData, key));
}
template <typename S> template <typename KEY> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryObjectInterface::Hxx1::ConstFn<S>::Contains(KEY&& key) const -> HXXADDRET2(Bool)
{
	HXXRETURN0(HXXADDRET2(Bool)); HXXSUPER("DataDictionaryObjectInterface::Contains"); HXXRES; HXXCONST(maxon::PrivateLogNullptrError(false)) 
	return (o_->Contains<KEY>(std::forward<KEY>(key)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryObjectInterface::Hxx1::Fn<S>::EraseData(const ConstDataPtr& key) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(DataDictionaryObjectInterface_EraseData); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataDictionaryObjectInterface_EraseData_Offset), mt_.DataDictionaryObjectInterface_EraseData, key));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryObjectInterface::Hxx1::COWFn<S>::EraseData(const ConstDataPtr& key) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(DataDictionaryObjectInterface_EraseData); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataDictionaryObjectInterface_EraseData_Offset), mt_.DataDictionaryObjectInterface_EraseData, key));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryObjectInterface::Hxx1::Fn<S>::Reset() const -> HXXADDRET2(void)
{
	HXXRETURN0(HXXADDRET2(void)); HXXRES; HXXNONCONST(DebugStop(), , false, maxon::PrivateLogNullptrError()) HXXTABLE(DataDictionaryObjectInterface_Reset); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataDictionaryObjectInterface_Reset_Offset), mt_.DataDictionaryObjectInterface_Reset);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryObjectInterface::Hxx1::COWFn<S>::Reset() -> HXXADDRET1(void)
{
	HXXRETURN0(HXXADDRET1(void)); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(DataDictionaryObjectInterface_Reset); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataDictionaryObjectInterface_Reset_Offset), mt_.DataDictionaryObjectInterface_Reset);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryObjectInterface::Hxx1::ConstFn<S>::IsEmpty() const -> HXXADDRET2(Bool)
{
	HXXRETURN0(HXXADDRET2(Bool)); HXXRES; HXXCONST(true) HXXTABLE(DataDictionaryObjectInterface_IsEmpty); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.DataDictionaryObjectInterface_IsEmpty_Offset), mt_.DataDictionaryObjectInterface_IsEmpty));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryObjectInterface::Hxx1::ConstFn<S>::IsPopulated() const -> HXXADDRET2(Bool)
{
	HXXRETURN0(HXXADDRET2(Bool)); HXXSUPER("DataDictionaryObjectInterface::IsPopulated"); HXXRES; HXXCONST(maxon::PrivateLogNullptrError(false)) 
	return (o_->IsPopulated());
}
template <typename S> template <typename T, typename KEY> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryObjectInterface::Hxx1::ConstFn<S>::Get(KEY&& key) const -> Result<typename std::conditional<std::is_void<T>::value, typename IsFidClass<KEY>::type, T>::type>
{
	HXXRETURN0(Result<typename std::conditional<std::is_void<T>::value, typename IsFidClass<KEY>::type, T>::type>); HXXSUPER("DataDictionaryObjectInterface::Get"); HXXRES; HXXCONST(HXXRET1(NULLPTR)) 
	return (o_->Get<maxon::details::GetReferenceClass<S>, T, KEY>(std::forward<KEY>(key)));
}
template <typename S> template <typename T, typename KEY> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryObjectInterface::Hxx1::ConstFn<S>::Get(KEY&& key, const T& defaultValue) const -> HXXADDRET2(typename std::conditional<IsFidClass<KEY>::value&&GetCollectionKind<T>::value!=COLLECTION_KIND::ARRAY, typename IsFidClass<KEY>::type, T>::type)
{
	HXXRETURN0(HXXADDRET2(typename std::conditional<IsFidClass<KEY>::value&&GetCollectionKind<T>::value!=COLLECTION_KIND::ARRAY, typename IsFidClass<KEY>::type, T>::type)); HXXSUPER("DataDictionaryObjectInterface::Get"); HXXRES; HXXCONST(maxon::PrivateDefaultReturnValue<typename std::conditional<IsFidClass<KEY>::value&&GetCollectionKind<T>::value!=COLLECTION_KIND::ARRAY, typename IsFidClass<KEY>::type, T>::type>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK)) 
	return (o_->Get<maxon::details::GetReferenceClass<S>, T, KEY>(std::forward<KEY>(key), defaultValue));
}
template <typename S> template <typename T, typename KEY> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryObjectInterface::Hxx1::ConstFn<S>::Get(KEY&& key, T&& defaultValue) const -> HXXADDRET2(typename std::conditional<IsFidClass<KEY>::value&&GetCollectionKind<T>::value!=COLLECTION_KIND::ARRAY, typename IsFidClass<KEY>::type, T>::type)
{
	HXXRETURN0(HXXADDRET2(typename std::conditional<IsFidClass<KEY>::value&&GetCollectionKind<T>::value!=COLLECTION_KIND::ARRAY, typename IsFidClass<KEY>::type, T>::type)); HXXSUPER("DataDictionaryObjectInterface::Get"); HXXRES; HXXCONST(maxon::PrivateDefaultReturnValue<typename std::conditional<IsFidClass<KEY>::value&&GetCollectionKind<T>::value!=COLLECTION_KIND::ARRAY, typename IsFidClass<KEY>::type, T>::type>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK)) 
	return (o_->Get<maxon::details::GetReferenceClass<S>, T, KEY>(std::forward<KEY>(key), std::forward<T>(defaultValue)));
}
template <typename S> template <typename T, typename KEY> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryObjectInterface::Hxx1::ConstFn<S>::GetOrDefault(KEY&& key) const -> HXXADDRET2(typename std::conditional<std::is_void<T>::value, typename IsFidClass<KEY>::type, T>::type)
{
	HXXRETURN0(HXXADDRET2(typename std::conditional<std::is_void<T>::value, typename IsFidClass<KEY>::type, T>::type)); HXXSUPER("DataDictionaryObjectInterface::GetOrDefault"); HXXRES; HXXCONST(maxon::PrivateDefaultReturnValue<typename std::conditional<std::is_void<T>::value, typename IsFidClass<KEY>::type, T>::type>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK)) 
	return (o_->GetOrDefault<T, KEY>(std::forward<KEY>(key)));
}
template <typename S> template <typename T, typename KEY> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryObjectInterface::Hxx1::Fn<S>::Set(KEY&& key, T&& data) const -> maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)>
{
	HXXRETURN1(maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)>); HXXRES; HXXNONCONST(, , false, HXXRET2b(NULLPTR)) 
	auto res_ = o_->Set<maxon::details::GetReferenceClass<S>, T, KEY>(std::forward<KEY>(key), std::forward<T>(data));
	return ReturnHelper::Return(this, res_.GetErrorStorage());
}
template <typename S> template <typename T, typename KEY> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryObjectInterface::Hxx1::COWFn<S>::Set(KEY&& key, T&& data) -> maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)>
{
	HXXRETURN1(maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)>); HXXSUPER("DataDictionaryObjectInterface::Set"); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2b(MAKE_WRITABLE_FAILED)) 
	auto res_ = o_->Set<maxon::details::GetReferenceClass<S>, T, KEY>(std::forward<KEY>(key), std::forward<T>(data));
	return ReturnHelper::Return(this, res_.GetErrorStorage());
}
template <typename S> template <typename KEY> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryObjectInterface::Hxx1::Fn<S>::Erase(KEY&& key) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) 
	return (o_->Erase<maxon::details::GetReferenceClass<S>, KEY>(std::forward<KEY>(key)));
}
template <typename S> template <typename KEY> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryObjectInterface::Hxx1::COWFn<S>::Erase(KEY&& key) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXSUPER("DataDictionaryObjectInterface::Erase"); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) 
	return (o_->Erase<maxon::details::GetReferenceClass<S>, KEY>(std::forward<KEY>(key)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryObjectInterface::Hxx1::ConstFn<S>::InitIterator(DataDictionaryIteratorInterface* iterator, Bool end) const -> HXXADDRET2(void)
{
	HXXRETURN0(HXXADDRET2(void)); HXXRES; HXXCONST(maxon::PrivateLogNullptrError()) HXXTABLE(DataDictionaryObjectInterface_InitIterator); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.DataDictionaryObjectInterface_InitIterator_Offset), mt_.DataDictionaryObjectInterface_InitIterator, iterator, end);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryObjectInterface::Hxx1::ConstFn<S>::Begin() const -> HXXADDRET2(ConstIterator)
{
	HXXRETURN0(HXXADDRET2(ConstIterator)); HXXSUPER("DataDictionaryObjectInterface::Begin"); HXXRES; HXXCONST(HXXRET3(NULLPTR, ConstIterator)) 
	return (o_->Begin());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryObjectInterface::Hxx1::ConstFn<S>::End() const -> HXXADDRET2(ConstIterator)
{
	HXXRETURN0(HXXADDRET2(ConstIterator)); HXXSUPER("DataDictionaryObjectInterface::End"); HXXRES; HXXCONST(HXXRET3(NULLPTR, ConstIterator)) 
	return (o_->End());
}
auto DataDictionaryObjectInterface::GetPtr() -> Ptr { return Ptr(this); }
auto DataDictionaryObjectInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_datadictionaryobject)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_DataDictionaryObjectInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_DataDictionaryObjectInterface() { new (s_ui_maxon_DataDictionaryObjectInterface) maxon::EntityUse(DataDictionaryObjectInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/datadictionaryobject.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_DataDictionaryObjectInterface(DataDictionaryObjectInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/datadictionaryobject.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif

struct DataDictionaryReferenceObjectInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetDataContainer);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Init);
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	PRIVATE_MAXON_MF_POINTER(DataDictionaryReferenceObjectInterface_Init, Init, true, maxon::GenericComponent,, (Result<void>), DataDictionary* reference);
	maxon::Int DataDictionaryReferenceObjectInterface_Init_Offset;
	PRIVATE_MAXON_MF_POINTER(DataDictionaryReferenceObjectInterface_Init_1, Init, true, maxon::GenericComponent,, (Result<void>), const DataDictionary* reference);
	maxon::Int DataDictionaryReferenceObjectInterface_Init_1_Offset;
	PRIVATE_MAXON_MF_POINTER(DataDictionaryReferenceObjectInterface_GetDataContainer, GetDataContainer, true, maxon::GenericComponent, const, (const DataDictionary&));
	maxon::Int DataDictionaryReferenceObjectInterface_GetDataContainer_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDictionaryReferenceObjectInterface, Init))
	{
		maxon::Tie(DataDictionaryReferenceObjectInterface_Init, DataDictionaryReferenceObjectInterface_Init_Offset) = DataDictionaryReferenceObjectInterface_Init_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDictionaryReferenceObjectInterface, Init))
	{
		maxon::Tie(DataDictionaryReferenceObjectInterface_Init_1, DataDictionaryReferenceObjectInterface_Init_1_Offset) = DataDictionaryReferenceObjectInterface_Init_1_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDictionaryReferenceObjectInterface, GetDataContainer))
	{
		maxon::Tie(DataDictionaryReferenceObjectInterface_GetDataContainer, DataDictionaryReferenceObjectInterface_GetDataContainer_Offset) = DataDictionaryReferenceObjectInterface_GetDataContainer_GetPtr<W>(offset, true);
	}
	}
	template <typename S> using CombinedMTable = maxon::PrivateCombinedMTable<DataDictionaryReferenceObjectInterface, typename DataDictionaryObjectInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<DataDictionaryReferenceObjectInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct DataDictionaryReferenceObjectInterface::Hxx2
{
	template <typename S> class CWrapper : public DataDictionaryObjectInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetDataContainer);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Init);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename DataDictionaryObjectInterface::Hxx2::template CWrapper<S>;
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (DataDictionaryReferenceObjectInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, DataDictionaryReferenceObjectInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		PRIVATE_MAXON_MF_WRAPPER(DataDictionaryReferenceObjectInterface_Init, maxon::GenericComponent,, (Result<void>), DataDictionary* reference) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->Init(reference); }
		PRIVATE_MAXON_MF_WRAPPER(DataDictionaryReferenceObjectInterface_Init_1, maxon::GenericComponent,, (Result<void>), const DataDictionary* reference) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->Init(reference); }
		PRIVATE_MAXON_MF_WRAPPER(DataDictionaryReferenceObjectInterface_GetDataContainer, maxon::GenericComponent, const, (const DataDictionary&)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetDataContainer(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryReferenceObjectInterface::Init(DataDictionary* reference) -> Result<void>
{
	const DataDictionaryReferenceObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataDictionaryReferenceObjectInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.DataDictionaryReferenceObjectInterface_Init_Offset), mt_.DataDictionaryReferenceObjectInterface_Init, reference);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryReferenceObjectInterface::Init(const DataDictionary* reference) -> Result<void>
{
	const DataDictionaryReferenceObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataDictionaryReferenceObjectInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.DataDictionaryReferenceObjectInterface_Init_1_Offset), mt_.DataDictionaryReferenceObjectInterface_Init_1, reference);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryReferenceObjectInterface::GetDataContainer() const -> const DataDictionary&
{
	const DataDictionaryReferenceObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataDictionaryReferenceObjectInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.DataDictionaryReferenceObjectInterface_GetDataContainer_Offset), mt_.DataDictionaryReferenceObjectInterface_GetDataContainer);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryReferenceObjectInterface::Hxx1::Fn<S>::Init(DataDictionary* reference) const -> maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)>
{
	HXXRETURN1(maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)>); HXXRES; HXXNONCONST(, , false, HXXRET2b(NULLPTR)) HXXTABLE(DataDictionaryReferenceObjectInterface_Init); 
	auto res_ = PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataDictionaryReferenceObjectInterface_Init_Offset), mt_.DataDictionaryReferenceObjectInterface_Init, reference);
	return ReturnHelper::Return(this, res_.GetErrorStorage());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryReferenceObjectInterface::Hxx1::COWFn<S>::Init(DataDictionary* reference) -> maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)>
{
	HXXRETURN1(maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2b(MAKE_WRITABLE_FAILED)) HXXTABLE(DataDictionaryReferenceObjectInterface_Init); 
	auto res_ = PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataDictionaryReferenceObjectInterface_Init_Offset), mt_.DataDictionaryReferenceObjectInterface_Init, reference);
	return ReturnHelper::Return(this, res_.GetErrorStorage());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryReferenceObjectInterface::Hxx1::Fn<S>::Init(const DataDictionary* reference) const -> maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)>
{
	HXXRETURN1(maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)>); HXXRES; HXXNONCONST(, , false, HXXRET2b(NULLPTR)) HXXTABLE(DataDictionaryReferenceObjectInterface_Init_1); 
	auto res_ = PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataDictionaryReferenceObjectInterface_Init_1_Offset), mt_.DataDictionaryReferenceObjectInterface_Init_1, reference);
	return ReturnHelper::Return(this, res_.GetErrorStorage());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryReferenceObjectInterface::Hxx1::COWFn<S>::Init(const DataDictionary* reference) -> maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)>
{
	HXXRETURN1(maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2b(MAKE_WRITABLE_FAILED)) HXXTABLE(DataDictionaryReferenceObjectInterface_Init_1); 
	auto res_ = PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataDictionaryReferenceObjectInterface_Init_1_Offset), mt_.DataDictionaryReferenceObjectInterface_Init_1, reference);
	return ReturnHelper::Return(this, res_.GetErrorStorage());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryReferenceObjectInterface::Hxx1::ConstFn<S>::GetDataContainer() const -> HXXADDRET2(const DataDictionary&)
{
	HXXRETURN0(HXXADDRET2(const DataDictionary&)); HXXRES; HXXCONST(HXXRET3(NULLPTR, const DataDictionary&)) HXXTABLE(DataDictionaryReferenceObjectInterface_GetDataContainer); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.DataDictionaryReferenceObjectInterface_GetDataContainer_Offset), mt_.DataDictionaryReferenceObjectInterface_GetDataContainer));
}
auto DataDictionaryReferenceObjectInterface::GetPtr() -> Ptr { return Ptr(this); }
auto DataDictionaryReferenceObjectInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_datadictionaryobject)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_DataDictionaryReferenceObjectInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_DataDictionaryReferenceObjectInterface() { new (s_ui_maxon_DataDictionaryReferenceObjectInterface) maxon::EntityUse(DataDictionaryReferenceObjectInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/datadictionaryobject.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_DataDictionaryReferenceObjectInterface(DataDictionaryReferenceObjectInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/datadictionaryobject.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif


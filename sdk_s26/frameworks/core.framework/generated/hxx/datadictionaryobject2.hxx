
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
	Result<void> (*DataDictionaryObjectInterface_SetData) (maxon::GenericComponent* this_, ForwardingDataPtr&& key, Data&& data);
	maxon::Int DataDictionaryObjectInterface_SetData_Offset;
	Result<Data> (*DataDictionaryObjectInterface_GetData) (const maxon::GenericComponent* this_, const ConstDataPtr& key);
	maxon::Int DataDictionaryObjectInterface_GetData_Offset;
	Result<void> (*DataDictionaryObjectInterface_EraseData) (maxon::GenericComponent* this_, const ConstDataPtr& key);
	maxon::Int DataDictionaryObjectInterface_EraseData_Offset;
	void (*DataDictionaryObjectInterface_Reset) (maxon::GenericComponent* this_);
	maxon::Int DataDictionaryObjectInterface_Reset_Offset;
	Bool (*DataDictionaryObjectInterface_IsEmpty) (const maxon::GenericComponent* this_);
	maxon::Int DataDictionaryObjectInterface_IsEmpty_Offset;
	void (*DataDictionaryObjectInterface_InitIterator) (const maxon::GenericComponent* this_, DataDictionaryIteratorInterface* iterator, Bool end);
	maxon::Int DataDictionaryObjectInterface_InitIterator_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDictionaryObjectInterface, SetData))
	{
		DataDictionaryObjectInterface_SetData = &W::DataDictionaryObjectInterface_SetData;
		DataDictionaryObjectInterface_SetData_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDictionaryObjectInterface, GetData))
	{
		DataDictionaryObjectInterface_GetData = &W::DataDictionaryObjectInterface_GetData;
		DataDictionaryObjectInterface_GetData_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDictionaryObjectInterface, EraseData))
	{
		DataDictionaryObjectInterface_EraseData = &W::DataDictionaryObjectInterface_EraseData;
		DataDictionaryObjectInterface_EraseData_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDictionaryObjectInterface, Reset))
	{
		DataDictionaryObjectInterface_Reset = &W::DataDictionaryObjectInterface_Reset;
		DataDictionaryObjectInterface_Reset_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDictionaryObjectInterface, IsEmpty))
	{
		DataDictionaryObjectInterface_IsEmpty = &W::DataDictionaryObjectInterface_IsEmpty;
		DataDictionaryObjectInterface_IsEmpty_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDictionaryObjectInterface, InitIterator))
	{
		DataDictionaryObjectInterface_InitIterator = &W::DataDictionaryObjectInterface_InitIterator;
		DataDictionaryObjectInterface_InitIterator_Offset = offset;
	}
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<DataDictionaryObjectInterface, typename ObjectInterface::MTable::template CombinedMTable<S>>;
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
			if (!S::Implementation::PROXY && !(Super0::InitMTablesWithBases(info, offset))) return false;
			auto* vt = (DataDictionaryObjectInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, DataDictionaryObjectInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		static Result<void> DataDictionaryObjectInterface_SetData(maxon::GenericComponent* this_, ForwardingDataPtr&& key, Data&& data) { return ((typename S::Implementation*) this_)->SetData(std::forward<ForwardingDataPtr>(key), std::forward<Data>(data)); }
		static Result<Data> DataDictionaryObjectInterface_GetData(const maxon::GenericComponent* this_, const ConstDataPtr& key) { return ((const typename S::Implementation*) this_)->GetData(key); }
		static Result<void> DataDictionaryObjectInterface_EraseData(maxon::GenericComponent* this_, const ConstDataPtr& key) { return ((typename S::Implementation*) this_)->EraseData(key); }
		static void DataDictionaryObjectInterface_Reset(maxon::GenericComponent* this_) { return ((typename S::Implementation*) this_)->Reset(); }
		static Bool DataDictionaryObjectInterface_IsEmpty(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->IsEmpty(); }
		static void DataDictionaryObjectInterface_InitIterator(const maxon::GenericComponent* this_, DataDictionaryIteratorInterface* iterator, Bool end) { return ((const typename S::Implementation*) this_)->InitIterator(iterator, end); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryObjectInterface::SetData(ForwardingDataPtr&& key, Data&& data) -> Result<void>
{
	const DataDictionaryObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataDictionaryObjectInterface, this); return mt_.DataDictionaryObjectInterface_SetData((maxon::GenericComponent*) this + mt_.DataDictionaryObjectInterface_SetData_Offset, std::forward<ForwardingDataPtr>(key), std::forward<Data>(data));
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryObjectInterface::GetData(const ConstDataPtr& key) const -> Result<Data>
{
	const DataDictionaryObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataDictionaryObjectInterface, this); return mt_.DataDictionaryObjectInterface_GetData((const maxon::GenericComponent*) this + mt_.DataDictionaryObjectInterface_GetData_Offset, key);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryObjectInterface::EraseData(const ConstDataPtr& key) -> Result<void>
{
	const DataDictionaryObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataDictionaryObjectInterface, this); return mt_.DataDictionaryObjectInterface_EraseData((maxon::GenericComponent*) this + mt_.DataDictionaryObjectInterface_EraseData_Offset, key);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryObjectInterface::Reset() -> void
{
	const DataDictionaryObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataDictionaryObjectInterface, this); return mt_.DataDictionaryObjectInterface_Reset((maxon::GenericComponent*) this + mt_.DataDictionaryObjectInterface_Reset_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryObjectInterface::IsEmpty() const -> Bool
{
	const DataDictionaryObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataDictionaryObjectInterface, this); return mt_.DataDictionaryObjectInterface_IsEmpty((const maxon::GenericComponent*) this + mt_.DataDictionaryObjectInterface_IsEmpty_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryObjectInterface::InitIterator(DataDictionaryIteratorInterface* iterator, Bool end) const -> void
{
	const DataDictionaryObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataDictionaryObjectInterface, this); return mt_.DataDictionaryObjectInterface_InitIterator((const maxon::GenericComponent*) this + mt_.DataDictionaryObjectInterface_InitIterator_Offset, iterator, end);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryObjectInterface::Hxx1::Fn<S>::SetData(ForwardingDataPtr&& key, Data&& data) const -> maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), true, maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataDictionaryObjectInterface* o_ = (DataDictionaryObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDictionaryObjectInterface, o_, DataDictionaryObjectInterface_SetData) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DataDictionaryObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDictionaryObjectInterface>() : PRIVATE_MAXON_VTABLE(DataDictionaryObjectInterface, o_); 
	auto res_ = mt_.DataDictionaryObjectInterface_SetData(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataDictionaryObjectInterface_SetData_Offset, std::forward<ForwardingDataPtr>(key), std::forward<Data>(data));
	return ReturnHelper::Return(this, res_.GetErrorStorage());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryObjectInterface::Hxx1::COWFn<S>::SetData(ForwardingDataPtr&& key, Data&& data) -> maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), true, maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataDictionaryObjectInterface* o_ = (DataDictionaryObjectInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDictionaryObjectInterface, o_, DataDictionaryObjectInterface_SetData) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DataDictionaryObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDictionaryObjectInterface>() : PRIVATE_MAXON_VTABLE(DataDictionaryObjectInterface, o_); 
	auto res_ = mt_.DataDictionaryObjectInterface_SetData(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataDictionaryObjectInterface_SetData_Offset, std::forward<ForwardingDataPtr>(key), std::forward<Data>(data));
	return ReturnHelper::Return(this, res_.GetErrorStorage());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryObjectInterface::Hxx1::Fn<S>::SetData(ForwardingDataPtr&& key, const Data& data) const -> maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), true, maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataDictionaryObjectInterface* o_ = (DataDictionaryObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR)); } 
	auto res_ = o_->SetData(std::forward<ForwardingDataPtr>(key), data);
	return ReturnHelper::Return(this, res_.GetErrorStorage());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryObjectInterface::Hxx1::COWFn<S>::SetData(ForwardingDataPtr&& key, const Data& data) -> maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), true, maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)>>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION DataDictionaryObjectInterface::SetData on super."); if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataDictionaryObjectInterface* o_ = (DataDictionaryObjectInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	auto res_ = o_->SetData(std::forward<ForwardingDataPtr>(key), data);
	return ReturnHelper::Return(this, res_.GetErrorStorage());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryObjectInterface::Hxx1::ConstFn<S>::GetData(const ConstDataPtr& key) const -> Result<Data>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Data>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DataDictionaryObjectInterface* o_ = (const DataDictionaryObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DataDictionaryObjectInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDictionaryObjectInterface, o_, DataDictionaryObjectInterface_GetData) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DataDictionaryObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDictionaryObjectInterface>() : PRIVATE_MAXON_VTABLE(DataDictionaryObjectInterface, o_); 
	return (mt_.DataDictionaryObjectInterface_GetData(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.DataDictionaryObjectInterface_GetData_Offset, key));
}
template <typename S> template <typename KEY> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryObjectInterface::Hxx1::ConstFn<S>::Contains(KEY&& key) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION DataDictionaryObjectInterface::Contains on super."); if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DataDictionaryObjectInterface* o_ = (const DataDictionaryObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DataDictionaryObjectInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->Contains<KEY>(std::forward<KEY>(key)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryObjectInterface::Hxx1::Fn<S>::EraseData(const ConstDataPtr& key) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataDictionaryObjectInterface* o_ = (DataDictionaryObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDictionaryObjectInterface, o_, DataDictionaryObjectInterface_EraseData) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DataDictionaryObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDictionaryObjectInterface>() : PRIVATE_MAXON_VTABLE(DataDictionaryObjectInterface, o_); 
	return (mt_.DataDictionaryObjectInterface_EraseData(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataDictionaryObjectInterface_EraseData_Offset, key));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryObjectInterface::Hxx1::COWFn<S>::EraseData(const ConstDataPtr& key) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataDictionaryObjectInterface* o_ = (DataDictionaryObjectInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDictionaryObjectInterface, o_, DataDictionaryObjectInterface_EraseData) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DataDictionaryObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDictionaryObjectInterface>() : PRIVATE_MAXON_VTABLE(DataDictionaryObjectInterface, o_); 
	return (mt_.DataDictionaryObjectInterface_EraseData(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataDictionaryObjectInterface_EraseData_Offset, key));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryObjectInterface::Hxx1::Fn<S>::Reset() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataDictionaryObjectInterface* o_ = (DataDictionaryObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDictionaryObjectInterface, o_, DataDictionaryObjectInterface_Reset) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DataDictionaryObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDictionaryObjectInterface>() : PRIVATE_MAXON_VTABLE(DataDictionaryObjectInterface, o_); 
	mt_.DataDictionaryObjectInterface_Reset(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataDictionaryObjectInterface_Reset_Offset);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryObjectInterface::Hxx1::COWFn<S>::Reset() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataDictionaryObjectInterface* o_ = (DataDictionaryObjectInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDictionaryObjectInterface, o_, DataDictionaryObjectInterface_Reset) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DataDictionaryObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDictionaryObjectInterface>() : PRIVATE_MAXON_VTABLE(DataDictionaryObjectInterface, o_); 
	mt_.DataDictionaryObjectInterface_Reset(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataDictionaryObjectInterface_Reset_Offset);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryObjectInterface::Hxx1::ConstFn<S>::IsEmpty() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DataDictionaryObjectInterface* o_ = (const DataDictionaryObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DataDictionaryObjectInterface::NullValuePtr(); if (!o_) return true; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDictionaryObjectInterface, o_, DataDictionaryObjectInterface_IsEmpty) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DataDictionaryObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDictionaryObjectInterface>() : PRIVATE_MAXON_VTABLE(DataDictionaryObjectInterface, o_); 
	return (mt_.DataDictionaryObjectInterface_IsEmpty(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.DataDictionaryObjectInterface_IsEmpty_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryObjectInterface::Hxx1::ConstFn<S>::IsPopulated() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION DataDictionaryObjectInterface::IsPopulated on super."); if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DataDictionaryObjectInterface* o_ = (const DataDictionaryObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DataDictionaryObjectInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->IsPopulated());
}
template <typename S> template <typename T, typename KEY> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryObjectInterface::Hxx1::ConstFn<S>::Get(KEY&& key) const -> Result<typename std::conditional<std::is_void<T>::value, typename IsFidClass<KEY>::type, T>::type>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<typename std::conditional<std::is_void<T>::value, typename IsFidClass<KEY>::type, T>::type>>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION DataDictionaryObjectInterface::Get on super."); if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DataDictionaryObjectInterface* o_ = (const DataDictionaryObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DataDictionaryObjectInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->Get<maxon::details::GetReferenceClass<S>, T, KEY>(std::forward<KEY>(key)));
}
template <typename S> template <typename T, typename KEY> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryObjectInterface::Hxx1::ConstFn<S>::Get(KEY&& key, const T& defaultValue) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<typename std::conditional<IsFidClass<KEY>::value&&GetCollectionKind<T>::value!=COLLECTION_KIND::ARRAY, typename IsFidClass<KEY>::type, T>::type>, typename std::conditional<IsFidClass<KEY>::value&&GetCollectionKind<T>::value!=COLLECTION_KIND::ARRAY, typename IsFidClass<KEY>::type, T>::type>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<typename std::conditional<IsFidClass<KEY>::value&&GetCollectionKind<T>::value!=COLLECTION_KIND::ARRAY, typename IsFidClass<KEY>::type, T>::type>, typename std::conditional<IsFidClass<KEY>::value&&GetCollectionKind<T>::value!=COLLECTION_KIND::ARRAY, typename IsFidClass<KEY>::type, T>::type>::type>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION DataDictionaryObjectInterface::Get on super."); if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DataDictionaryObjectInterface* o_ = (const DataDictionaryObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DataDictionaryObjectInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<typename std::conditional<IsFidClass<KEY>::value&&GetCollectionKind<T>::value!=COLLECTION_KIND::ARRAY, typename IsFidClass<KEY>::type, T>::type>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (o_->Get<maxon::details::GetReferenceClass<S>, T, KEY>(std::forward<KEY>(key), defaultValue));
}
template <typename S> template <typename T, typename KEY> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryObjectInterface::Hxx1::ConstFn<S>::Get(KEY&& key, T&& defaultValue) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<typename std::conditional<IsFidClass<KEY>::value&&GetCollectionKind<T>::value!=COLLECTION_KIND::ARRAY, typename IsFidClass<KEY>::type, T>::type>, typename std::conditional<IsFidClass<KEY>::value&&GetCollectionKind<T>::value!=COLLECTION_KIND::ARRAY, typename IsFidClass<KEY>::type, T>::type>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<typename std::conditional<IsFidClass<KEY>::value&&GetCollectionKind<T>::value!=COLLECTION_KIND::ARRAY, typename IsFidClass<KEY>::type, T>::type>, typename std::conditional<IsFidClass<KEY>::value&&GetCollectionKind<T>::value!=COLLECTION_KIND::ARRAY, typename IsFidClass<KEY>::type, T>::type>::type>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION DataDictionaryObjectInterface::Get on super."); if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DataDictionaryObjectInterface* o_ = (const DataDictionaryObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DataDictionaryObjectInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<typename std::conditional<IsFidClass<KEY>::value&&GetCollectionKind<T>::value!=COLLECTION_KIND::ARRAY, typename IsFidClass<KEY>::type, T>::type>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (o_->Get<maxon::details::GetReferenceClass<S>, T, KEY>(std::forward<KEY>(key), std::forward<T>(defaultValue)));
}
template <typename S> template <typename T, typename KEY> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryObjectInterface::Hxx1::ConstFn<S>::GetOrDefault(KEY&& key) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<typename std::conditional<std::is_void<T>::value, typename IsFidClass<KEY>::type, T>::type>, typename std::conditional<std::is_void<T>::value, typename IsFidClass<KEY>::type, T>::type>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<typename std::conditional<std::is_void<T>::value, typename IsFidClass<KEY>::type, T>::type>, typename std::conditional<std::is_void<T>::value, typename IsFidClass<KEY>::type, T>::type>::type>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION DataDictionaryObjectInterface::GetOrDefault on super."); if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DataDictionaryObjectInterface* o_ = (const DataDictionaryObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DataDictionaryObjectInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<typename std::conditional<std::is_void<T>::value, typename IsFidClass<KEY>::type, T>::type>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (o_->GetOrDefault<T, KEY>(std::forward<KEY>(key)));
}
template <typename S> template <typename T, typename KEY> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryObjectInterface::Hxx1::Fn<S>::Set(KEY&& key, T&& data) const -> maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), true, maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataDictionaryObjectInterface* o_ = (DataDictionaryObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR)); } 
	auto res_ = o_->Set<maxon::details::GetReferenceClass<S>, T, KEY>(std::forward<KEY>(key), std::forward<T>(data));
	return ReturnHelper::Return(this, res_.GetErrorStorage());
}
template <typename S> template <typename T, typename KEY> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryObjectInterface::Hxx1::COWFn<S>::Set(KEY&& key, T&& data) -> maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), true, maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)>>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION DataDictionaryObjectInterface::Set on super."); if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataDictionaryObjectInterface* o_ = (DataDictionaryObjectInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	auto res_ = o_->Set<maxon::details::GetReferenceClass<S>, T, KEY>(std::forward<KEY>(key), std::forward<T>(data));
	return ReturnHelper::Return(this, res_.GetErrorStorage());
}
template <typename S> template <typename KEY> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryObjectInterface::Hxx1::Fn<S>::Erase(KEY&& key) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataDictionaryObjectInterface* o_ = (DataDictionaryObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->Erase<maxon::details::GetReferenceClass<S>, KEY>(std::forward<KEY>(key)));
}
template <typename S> template <typename KEY> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryObjectInterface::Hxx1::COWFn<S>::Erase(KEY&& key) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION DataDictionaryObjectInterface::Erase on super."); if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataDictionaryObjectInterface* o_ = (DataDictionaryObjectInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (o_->Erase<maxon::details::GetReferenceClass<S>, KEY>(std::forward<KEY>(key)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryObjectInterface::Hxx1::ConstFn<S>::InitIterator(DataDictionaryIteratorInterface* iterator, Bool end) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DataDictionaryObjectInterface* o_ = (const DataDictionaryObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DataDictionaryObjectInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDictionaryObjectInterface, o_, DataDictionaryObjectInterface_InitIterator) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DataDictionaryObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDictionaryObjectInterface>() : PRIVATE_MAXON_VTABLE(DataDictionaryObjectInterface, o_); 
	mt_.DataDictionaryObjectInterface_InitIterator(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.DataDictionaryObjectInterface_InitIterator_Offset, iterator, end);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryObjectInterface::Hxx1::ConstFn<S>::Begin() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<ConstIterator>, ConstIterator>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<ConstIterator>, ConstIterator>::type>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION DataDictionaryObjectInterface::Begin on super."); if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DataDictionaryObjectInterface* o_ = (const DataDictionaryObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DataDictionaryObjectInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<ConstIterator>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (o_->Begin());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryObjectInterface::Hxx1::ConstFn<S>::End() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<ConstIterator>, ConstIterator>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<ConstIterator>, ConstIterator>::type>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION DataDictionaryObjectInterface::End on super."); if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DataDictionaryObjectInterface* o_ = (const DataDictionaryObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DataDictionaryObjectInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<ConstIterator>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
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
	Result<void> (*DataDictionaryReferenceObjectInterface_Init) (maxon::GenericComponent* this_, DataDictionary* reference);
	maxon::Int DataDictionaryReferenceObjectInterface_Init_Offset;
	Result<void> (*DataDictionaryReferenceObjectInterface_Init_1) (maxon::GenericComponent* this_, const DataDictionary* reference);
	maxon::Int DataDictionaryReferenceObjectInterface_Init_1_Offset;
	const DataDictionary& (*DataDictionaryReferenceObjectInterface_GetDataContainer) (const maxon::GenericComponent* this_);
	maxon::Int DataDictionaryReferenceObjectInterface_GetDataContainer_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDictionaryReferenceObjectInterface, Init))
	{
		DataDictionaryReferenceObjectInterface_Init = &W::DataDictionaryReferenceObjectInterface_Init;
		DataDictionaryReferenceObjectInterface_Init_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDictionaryReferenceObjectInterface, Init))
	{
		DataDictionaryReferenceObjectInterface_Init_1 = &W::DataDictionaryReferenceObjectInterface_Init_1;
		DataDictionaryReferenceObjectInterface_Init_1_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDictionaryReferenceObjectInterface, GetDataContainer))
	{
		DataDictionaryReferenceObjectInterface_GetDataContainer = &W::DataDictionaryReferenceObjectInterface_GetDataContainer;
		DataDictionaryReferenceObjectInterface_GetDataContainer_Offset = offset;
	}
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<DataDictionaryReferenceObjectInterface, typename DataDictionaryObjectInterface::MTable::template CombinedMTable<S>>;
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
			if (!S::Implementation::PROXY && !(Super0::InitMTablesWithBases(info, offset))) return false;
			auto* vt = (DataDictionaryReferenceObjectInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, DataDictionaryReferenceObjectInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		static Result<void> DataDictionaryReferenceObjectInterface_Init(maxon::GenericComponent* this_, DataDictionary* reference) { return ((typename S::Implementation*) this_)->Init(reference); }
		static Result<void> DataDictionaryReferenceObjectInterface_Init_1(maxon::GenericComponent* this_, const DataDictionary* reference) { return ((typename S::Implementation*) this_)->Init(reference); }
		static const DataDictionary& DataDictionaryReferenceObjectInterface_GetDataContainer(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetDataContainer(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryReferenceObjectInterface::Init(DataDictionary* reference) -> Result<void>
{
	const DataDictionaryReferenceObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataDictionaryReferenceObjectInterface, this); return mt_.DataDictionaryReferenceObjectInterface_Init((maxon::GenericComponent*) this + mt_.DataDictionaryReferenceObjectInterface_Init_Offset, reference);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryReferenceObjectInterface::Init(const DataDictionary* reference) -> Result<void>
{
	const DataDictionaryReferenceObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataDictionaryReferenceObjectInterface, this); return mt_.DataDictionaryReferenceObjectInterface_Init_1((maxon::GenericComponent*) this + mt_.DataDictionaryReferenceObjectInterface_Init_1_Offset, reference);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryReferenceObjectInterface::GetDataContainer() const -> const DataDictionary&
{
	const DataDictionaryReferenceObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataDictionaryReferenceObjectInterface, this); return mt_.DataDictionaryReferenceObjectInterface_GetDataContainer((const maxon::GenericComponent*) this + mt_.DataDictionaryReferenceObjectInterface_GetDataContainer_Offset);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryReferenceObjectInterface::Hxx1::Fn<S>::Init(DataDictionary* reference) const -> maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), true, maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataDictionaryReferenceObjectInterface* o_ = (DataDictionaryReferenceObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDictionaryReferenceObjectInterface, o_, DataDictionaryReferenceObjectInterface_Init) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DataDictionaryReferenceObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDictionaryReferenceObjectInterface>() : PRIVATE_MAXON_VTABLE(DataDictionaryReferenceObjectInterface, o_); 
	auto res_ = mt_.DataDictionaryReferenceObjectInterface_Init(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataDictionaryReferenceObjectInterface_Init_Offset, reference);
	return ReturnHelper::Return(this, res_.GetErrorStorage());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryReferenceObjectInterface::Hxx1::COWFn<S>::Init(DataDictionary* reference) -> maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), true, maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataDictionaryReferenceObjectInterface* o_ = (DataDictionaryReferenceObjectInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDictionaryReferenceObjectInterface, o_, DataDictionaryReferenceObjectInterface_Init) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DataDictionaryReferenceObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDictionaryReferenceObjectInterface>() : PRIVATE_MAXON_VTABLE(DataDictionaryReferenceObjectInterface, o_); 
	auto res_ = mt_.DataDictionaryReferenceObjectInterface_Init(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataDictionaryReferenceObjectInterface_Init_Offset, reference);
	return ReturnHelper::Return(this, res_.GetErrorStorage());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryReferenceObjectInterface::Hxx1::Fn<S>::Init(const DataDictionary* reference) const -> maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), true, maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataDictionaryReferenceObjectInterface* o_ = (DataDictionaryReferenceObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDictionaryReferenceObjectInterface, o_, DataDictionaryReferenceObjectInterface_Init_1) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DataDictionaryReferenceObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDictionaryReferenceObjectInterface>() : PRIVATE_MAXON_VTABLE(DataDictionaryReferenceObjectInterface, o_); 
	auto res_ = mt_.DataDictionaryReferenceObjectInterface_Init_1(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataDictionaryReferenceObjectInterface_Init_1_Offset, reference);
	return ReturnHelper::Return(this, res_.GetErrorStorage());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryReferenceObjectInterface::Hxx1::COWFn<S>::Init(const DataDictionary* reference) -> maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), true, maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataDictionaryReferenceObjectInterface* o_ = (DataDictionaryReferenceObjectInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDictionaryReferenceObjectInterface, o_, DataDictionaryReferenceObjectInterface_Init_1) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DataDictionaryReferenceObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDictionaryReferenceObjectInterface>() : PRIVATE_MAXON_VTABLE(DataDictionaryReferenceObjectInterface, o_); 
	auto res_ = mt_.DataDictionaryReferenceObjectInterface_Init_1(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataDictionaryReferenceObjectInterface_Init_1_Offset, reference);
	return ReturnHelper::Return(this, res_.GetErrorStorage());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryReferenceObjectInterface::Hxx1::ConstFn<S>::GetDataContainer() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const DataDictionary&>, const DataDictionary&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const DataDictionary&>, const DataDictionary&>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DataDictionaryReferenceObjectInterface* o_ = (const DataDictionaryReferenceObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DataDictionaryReferenceObjectInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const DataDictionary&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDictionaryReferenceObjectInterface, o_, DataDictionaryReferenceObjectInterface_GetDataContainer) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DataDictionaryReferenceObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDictionaryReferenceObjectInterface>() : PRIVATE_MAXON_VTABLE(DataDictionaryReferenceObjectInterface, o_); 
	return (mt_.DataDictionaryReferenceObjectInterface_GetDataContainer(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.DataDictionaryReferenceObjectInterface_GetDataContainer_Offset));
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



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
	static const maxon::Bool HAS_NONSTATIC = false;
	Result<void> (*_DataDictionaryObjectInterface_SetData) (maxon::GenericComponent* this_, ForwardingDataPtr&& key, Data&& data);
	maxon::Int _DataDictionaryObjectInterface_SetData_Offset;
	Result<Data> (*_DataDictionaryObjectInterface_GetData) (const maxon::GenericComponent* this_, const ConstDataPtr& key);
	maxon::Int _DataDictionaryObjectInterface_GetData_Offset;
	Result<void> (*_DataDictionaryObjectInterface_EraseData) (maxon::GenericComponent* this_, const ConstDataPtr& key);
	maxon::Int _DataDictionaryObjectInterface_EraseData_Offset;
	void (*_DataDictionaryObjectInterface_Reset) (maxon::GenericComponent* this_);
	maxon::Int _DataDictionaryObjectInterface_Reset_Offset;
	Bool (*_DataDictionaryObjectInterface_IsEmpty) (const maxon::GenericComponent* this_);
	maxon::Int _DataDictionaryObjectInterface_IsEmpty_Offset;
	void (*_DataDictionaryObjectInterface_InitIterator) (const maxon::GenericComponent* this_, DataDictionaryIteratorInterface* iterator, Bool end);
	maxon::Int _DataDictionaryObjectInterface_InitIterator_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDictionaryObjectInterface, SetData))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDictionaryObjectInterface, SetData), W, MTable>::type::_DataDictionaryObjectInterface_SetData;
			_DataDictionaryObjectInterface_SetData = reinterpret_cast<const decltype(_DataDictionaryObjectInterface_SetData)&>(ptr);
			_DataDictionaryObjectInterface_SetData_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDictionaryObjectInterface, GetData))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDictionaryObjectInterface, GetData), W, MTable>::type::_DataDictionaryObjectInterface_GetData;
			_DataDictionaryObjectInterface_GetData = reinterpret_cast<const decltype(_DataDictionaryObjectInterface_GetData)&>(ptr);
			_DataDictionaryObjectInterface_GetData_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDictionaryObjectInterface, EraseData))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDictionaryObjectInterface, EraseData), W, MTable>::type::_DataDictionaryObjectInterface_EraseData;
			_DataDictionaryObjectInterface_EraseData = reinterpret_cast<const decltype(_DataDictionaryObjectInterface_EraseData)&>(ptr);
			_DataDictionaryObjectInterface_EraseData_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDictionaryObjectInterface, Reset))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDictionaryObjectInterface, Reset), W, MTable>::type::_DataDictionaryObjectInterface_Reset;
			_DataDictionaryObjectInterface_Reset = reinterpret_cast<const decltype(_DataDictionaryObjectInterface_Reset)&>(ptr);
			_DataDictionaryObjectInterface_Reset_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDictionaryObjectInterface, IsEmpty))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDictionaryObjectInterface, IsEmpty), W, MTable>::type::_DataDictionaryObjectInterface_IsEmpty;
			_DataDictionaryObjectInterface_IsEmpty = reinterpret_cast<const decltype(_DataDictionaryObjectInterface_IsEmpty)&>(ptr);
			_DataDictionaryObjectInterface_IsEmpty_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDictionaryObjectInterface, InitIterator))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDictionaryObjectInterface, InitIterator), W, MTable>::type::_DataDictionaryObjectInterface_InitIterator;
			_DataDictionaryObjectInterface_InitIterator = reinterpret_cast<const decltype(_DataDictionaryObjectInterface_InitIterator)&>(ptr);
			_DataDictionaryObjectInterface_InitIterator_Offset = offset;
		}
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!ObjectInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<DataDictionaryObjectInterface, typename ObjectInterface::MTable::template CombinedMTable<S>>;
	PRIVATE_MAXON_COMPBASE(DataDictionaryObjectInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct DataDictionaryObjectInterface::Hxx2
{
	template <typename S> class Wrapper : public ObjectInterface::Hxx2::template Wrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(EraseData);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetData);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(InitIterator);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(IsEmpty);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Reset);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(SetData);
	static Result<void> _DataDictionaryObjectInterface_SetData(maxon::GenericComponent* this_, ForwardingDataPtr&& key, Data&& data) { return ((typename S::Implementation*) this_)->SetData(std::forward<ForwardingDataPtr>(key), std::forward<Data>(data)); }
	static Result<Data> _DataDictionaryObjectInterface_GetData(const maxon::GenericComponent* this_, const ConstDataPtr& key) { return ((const typename S::Implementation*) this_)->GetData(key); }
	static Result<void> _DataDictionaryObjectInterface_EraseData(maxon::GenericComponent* this_, const ConstDataPtr& key) { return ((typename S::Implementation*) this_)->EraseData(key); }
	static void _DataDictionaryObjectInterface_Reset(maxon::GenericComponent* this_) { return ((typename S::Implementation*) this_)->Reset(); }
	static Bool _DataDictionaryObjectInterface_IsEmpty(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->IsEmpty(); }
	static void _DataDictionaryObjectInterface_InitIterator(const maxon::GenericComponent* this_, DataDictionaryIteratorInterface* iterator, Bool end) { return ((const typename S::Implementation*) this_)->InitIterator(iterator, end); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryObjectInterface::SetData(ForwardingDataPtr&& key, Data&& data) -> Result<void>
{
	const DataDictionaryObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataDictionaryObjectInterface, this); return mt_._DataDictionaryObjectInterface_SetData((maxon::GenericComponent*) this + mt_._DataDictionaryObjectInterface_SetData_Offset, std::forward<ForwardingDataPtr>(key), std::forward<Data>(data));
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryObjectInterface::GetData(const ConstDataPtr& key) const -> Result<Data>
{
	const DataDictionaryObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataDictionaryObjectInterface, this); return mt_._DataDictionaryObjectInterface_GetData((const maxon::GenericComponent*) this + mt_._DataDictionaryObjectInterface_GetData_Offset, key);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryObjectInterface::EraseData(const ConstDataPtr& key) -> Result<void>
{
	const DataDictionaryObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataDictionaryObjectInterface, this); return mt_._DataDictionaryObjectInterface_EraseData((maxon::GenericComponent*) this + mt_._DataDictionaryObjectInterface_EraseData_Offset, key);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryObjectInterface::Reset() -> void
{
	const DataDictionaryObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataDictionaryObjectInterface, this); return mt_._DataDictionaryObjectInterface_Reset((maxon::GenericComponent*) this + mt_._DataDictionaryObjectInterface_Reset_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryObjectInterface::IsEmpty() const -> Bool
{
	const DataDictionaryObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataDictionaryObjectInterface, this); return mt_._DataDictionaryObjectInterface_IsEmpty((const maxon::GenericComponent*) this + mt_._DataDictionaryObjectInterface_IsEmpty_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryObjectInterface::InitIterator(DataDictionaryIteratorInterface* iterator, Bool end) const -> void
{
	const DataDictionaryObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataDictionaryObjectInterface, this); return mt_._DataDictionaryObjectInterface_InitIterator((const maxon::GenericComponent*) this + mt_._DataDictionaryObjectInterface_InitIterator_Offset, iterator, end);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryObjectInterface::Hxx1::ReferenceFunctionsImpl<S>::SetData(ForwardingDataPtr&& key, Data&& data) const -> maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), true, maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataDictionaryObjectInterface* o_ = (DataDictionaryObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR)); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDictionaryObjectInterface, o_, DataDictionaryObjectInterface_SetData) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<DataDictionaryObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDictionaryObjectInterface>() : PRIVATE_MAXON_VTABLE(DataDictionaryObjectInterface, o_); 
	auto res_ = mt_._DataDictionaryObjectInterface_SetData(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._DataDictionaryObjectInterface_SetData_Offset, std::forward<ForwardingDataPtr>(key), std::forward<Data>(data));
	return ReturnHelper::Return(this, res_.GetErrorStorage());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryObjectInterface::Hxx1::COWReferenceFunctionsImpl<S>::SetData(ForwardingDataPtr&& key, Data&& data) -> maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), true, maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataDictionaryObjectInterface* o_ = (DataDictionaryObjectInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDictionaryObjectInterface, o_, DataDictionaryObjectInterface_SetData) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<DataDictionaryObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDictionaryObjectInterface>() : PRIVATE_MAXON_VTABLE(DataDictionaryObjectInterface, o_); 
	auto res_ = mt_._DataDictionaryObjectInterface_SetData(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._DataDictionaryObjectInterface_SetData_Offset, std::forward<ForwardingDataPtr>(key), std::forward<Data>(data));
	return ReturnHelper::Return(this, res_.GetErrorStorage());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryObjectInterface::Hxx1::ReferenceFunctionsImpl<S>::SetData(ForwardingDataPtr&& key, const Data& data) const -> maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), true, maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataDictionaryObjectInterface* o_ = (DataDictionaryObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR)); 
	auto res_ = o_->SetData(std::forward<ForwardingDataPtr>(key), data);
	return ReturnHelper::Return(this, res_.GetErrorStorage());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryObjectInterface::Hxx1::COWReferenceFunctionsImpl<S>::SetData(ForwardingDataPtr&& key, const Data& data) -> maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), true, maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)>>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION DataDictionaryObjectInterface::SetData on super."); if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataDictionaryObjectInterface* o_ = (DataDictionaryObjectInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	auto res_ = o_->SetData(std::forward<ForwardingDataPtr>(key), data);
	return ReturnHelper::Return(this, res_.GetErrorStorage());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryObjectInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetData(const ConstDataPtr& key) const -> Result<Data>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Data>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DataDictionaryObjectInterface* o_ = (const DataDictionaryObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DataDictionaryObjectInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDictionaryObjectInterface, o_, DataDictionaryObjectInterface_GetData) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<DataDictionaryObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDictionaryObjectInterface>() : PRIVATE_MAXON_VTABLE(DataDictionaryObjectInterface, o_); 
	return (mt_._DataDictionaryObjectInterface_GetData(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._DataDictionaryObjectInterface_GetData_Offset, key));
}
template <typename S> template <typename KEY> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryObjectInterface::Hxx1::ConstReferenceFunctionsImpl<S>::Existing(KEY&& key) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION DataDictionaryObjectInterface::Existing on super."); if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DataDictionaryObjectInterface* o_ = (const DataDictionaryObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DataDictionaryObjectInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->Existing<KEY>(std::forward<KEY>(key)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryObjectInterface::Hxx1::ReferenceFunctionsImpl<S>::EraseData(const ConstDataPtr& key) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataDictionaryObjectInterface* o_ = (DataDictionaryObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDictionaryObjectInterface, o_, DataDictionaryObjectInterface_EraseData) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<DataDictionaryObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDictionaryObjectInterface>() : PRIVATE_MAXON_VTABLE(DataDictionaryObjectInterface, o_); 
	return (mt_._DataDictionaryObjectInterface_EraseData(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._DataDictionaryObjectInterface_EraseData_Offset, key));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryObjectInterface::Hxx1::COWReferenceFunctionsImpl<S>::EraseData(const ConstDataPtr& key) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataDictionaryObjectInterface* o_ = (DataDictionaryObjectInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDictionaryObjectInterface, o_, DataDictionaryObjectInterface_EraseData) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<DataDictionaryObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDictionaryObjectInterface>() : PRIVATE_MAXON_VTABLE(DataDictionaryObjectInterface, o_); 
	return (mt_._DataDictionaryObjectInterface_EraseData(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._DataDictionaryObjectInterface_EraseData_Offset, key));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryObjectInterface::Hxx1::ReferenceFunctionsImpl<S>::Reset() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataDictionaryObjectInterface* o_ = (DataDictionaryObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateLogNullptrError(); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDictionaryObjectInterface, o_, DataDictionaryObjectInterface_Reset) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<DataDictionaryObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDictionaryObjectInterface>() : PRIVATE_MAXON_VTABLE(DataDictionaryObjectInterface, o_); 
	mt_._DataDictionaryObjectInterface_Reset(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._DataDictionaryObjectInterface_Reset_Offset);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryObjectInterface::Hxx1::COWReferenceFunctionsImpl<S>::Reset() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataDictionaryObjectInterface* o_ = (DataDictionaryObjectInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDictionaryObjectInterface, o_, DataDictionaryObjectInterface_Reset) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<DataDictionaryObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDictionaryObjectInterface>() : PRIVATE_MAXON_VTABLE(DataDictionaryObjectInterface, o_); 
	mt_._DataDictionaryObjectInterface_Reset(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._DataDictionaryObjectInterface_Reset_Offset);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryObjectInterface::Hxx1::ConstReferenceFunctionsImpl<S>::IsEmpty() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DataDictionaryObjectInterface* o_ = (const DataDictionaryObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DataDictionaryObjectInterface::NullValuePtr(); if (!o_) return true; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDictionaryObjectInterface, o_, DataDictionaryObjectInterface_IsEmpty) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<DataDictionaryObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDictionaryObjectInterface>() : PRIVATE_MAXON_VTABLE(DataDictionaryObjectInterface, o_); 
	return (mt_._DataDictionaryObjectInterface_IsEmpty(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._DataDictionaryObjectInterface_IsEmpty_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryObjectInterface::Hxx1::ConstReferenceFunctionsImpl<S>::IsPopulated() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION DataDictionaryObjectInterface::IsPopulated on super."); if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DataDictionaryObjectInterface* o_ = (const DataDictionaryObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DataDictionaryObjectInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->IsPopulated());
}
template <typename S> template <typename T, typename KEY> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryObjectInterface::Hxx1::ConstReferenceFunctionsImpl<S>::Get(KEY&& key) const -> Result<typename std::conditional<IsFidClass<KEY>::value, typename IsFidClass<KEY>::type, T>::type>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<typename std::conditional<IsFidClass<KEY>::value, typename IsFidClass<KEY>::type, T>::type>>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION DataDictionaryObjectInterface::Get on super."); if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DataDictionaryObjectInterface* o_ = (const DataDictionaryObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DataDictionaryObjectInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->Get<maxon::details::GetReferenceClass<S>, T, KEY>(std::forward<KEY>(key)));
}
template <typename S> template <typename T, typename KEY> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryObjectInterface::Hxx1::ConstReferenceFunctionsImpl<S>::Get(KEY&& key, const T& defaultValue) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<typename std::conditional<IsFidClass<KEY>::value, typename IsFidClass<KEY>::type, T>::type>, typename std::conditional<IsFidClass<KEY>::value, typename IsFidClass<KEY>::type, T>::type>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<typename std::conditional<IsFidClass<KEY>::value, typename IsFidClass<KEY>::type, T>::type>, typename std::conditional<IsFidClass<KEY>::value, typename IsFidClass<KEY>::type, T>::type>::type>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION DataDictionaryObjectInterface::Get on super."); if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DataDictionaryObjectInterface* o_ = (const DataDictionaryObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DataDictionaryObjectInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<typename std::conditional<IsFidClass<KEY>::value, typename IsFidClass<KEY>::type, T>::type>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (o_->Get<maxon::details::GetReferenceClass<S>, T, KEY>(std::forward<KEY>(key), defaultValue));
}
template <typename S> template <typename T, typename KEY> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryObjectInterface::Hxx1::ConstReferenceFunctionsImpl<S>::Get(KEY&& key, T&& defaultValue) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<typename std::conditional<IsFidClass<KEY>::value, typename IsFidClass<KEY>::type, T>::type>, typename std::conditional<IsFidClass<KEY>::value, typename IsFidClass<KEY>::type, T>::type>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<typename std::conditional<IsFidClass<KEY>::value, typename IsFidClass<KEY>::type, T>::type>, typename std::conditional<IsFidClass<KEY>::value, typename IsFidClass<KEY>::type, T>::type>::type>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION DataDictionaryObjectInterface::Get on super."); if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DataDictionaryObjectInterface* o_ = (const DataDictionaryObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DataDictionaryObjectInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<typename std::conditional<IsFidClass<KEY>::value, typename IsFidClass<KEY>::type, T>::type>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (o_->Get<maxon::details::GetReferenceClass<S>, T, KEY>(std::forward<KEY>(key), std::forward<T>(defaultValue)));
}
template <typename S> template <typename KEY> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryObjectInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetOrDefault(KEY&& key) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<typename IsFidClass<KEY>::type>, typename IsFidClass<KEY>::type>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<typename IsFidClass<KEY>::type>, typename IsFidClass<KEY>::type>::type>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION DataDictionaryObjectInterface::GetOrDefault on super."); if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DataDictionaryObjectInterface* o_ = (const DataDictionaryObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DataDictionaryObjectInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<typename IsFidClass<KEY>::type>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (o_->GetOrDefault<KEY>(std::forward<KEY>(key)));
}
template <typename S> template <typename T, typename KEY> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryObjectInterface::Hxx1::ReferenceFunctionsImpl<S>::Set(KEY&& key, T&& data) const -> maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), true, maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataDictionaryObjectInterface* o_ = (DataDictionaryObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR)); 
	auto res_ = o_->Set<maxon::details::GetReferenceClass<S>, T, KEY>(std::forward<KEY>(key), std::forward<T>(data));
	return ReturnHelper::Return(this, res_.GetErrorStorage());
}
template <typename S> template <typename T, typename KEY> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryObjectInterface::Hxx1::COWReferenceFunctionsImpl<S>::Set(KEY&& key, T&& data) -> maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), true, maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)>>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION DataDictionaryObjectInterface::Set on super."); if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataDictionaryObjectInterface* o_ = (DataDictionaryObjectInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	auto res_ = o_->Set<maxon::details::GetReferenceClass<S>, T, KEY>(std::forward<KEY>(key), std::forward<T>(data));
	return ReturnHelper::Return(this, res_.GetErrorStorage());
}
template <typename S> template <typename KEY> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryObjectInterface::Hxx1::ReferenceFunctionsImpl<S>::Erase(KEY&& key) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataDictionaryObjectInterface* o_ = (DataDictionaryObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (o_->Erase<maxon::details::GetReferenceClass<S>, KEY>(std::forward<KEY>(key)));
}
template <typename S> template <typename KEY> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryObjectInterface::Hxx1::COWReferenceFunctionsImpl<S>::Erase(KEY&& key) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION DataDictionaryObjectInterface::Erase on super."); if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataDictionaryObjectInterface* o_ = (DataDictionaryObjectInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (o_->Erase<maxon::details::GetReferenceClass<S>, KEY>(std::forward<KEY>(key)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryObjectInterface::Hxx1::ConstReferenceFunctionsImpl<S>::InitIterator(DataDictionaryIteratorInterface* iterator, Bool end) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DataDictionaryObjectInterface* o_ = (const DataDictionaryObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DataDictionaryObjectInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDictionaryObjectInterface, o_, DataDictionaryObjectInterface_InitIterator) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<DataDictionaryObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDictionaryObjectInterface>() : PRIVATE_MAXON_VTABLE(DataDictionaryObjectInterface, o_); 
	mt_._DataDictionaryObjectInterface_InitIterator(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._DataDictionaryObjectInterface_InitIterator_Offset, iterator, end);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryObjectInterface::Hxx1::ConstReferenceFunctionsImpl<S>::Begin() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<ConstIterator>, ConstIterator>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<ConstIterator>, ConstIterator>::type>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION DataDictionaryObjectInterface::Begin on super."); if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DataDictionaryObjectInterface* o_ = (const DataDictionaryObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DataDictionaryObjectInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<ConstIterator>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (o_->Begin());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryObjectInterface::Hxx1::ConstReferenceFunctionsImpl<S>::End() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<ConstIterator>, ConstIterator>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<ConstIterator>, ConstIterator>::type>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION DataDictionaryObjectInterface::End on super."); if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DataDictionaryObjectInterface* o_ = (const DataDictionaryObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DataDictionaryObjectInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<ConstIterator>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (o_->End());
}
auto DataDictionaryObjectInterface::GetPtr() -> Ptr { return Ptr(this); }
auto DataDictionaryObjectInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
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
	static const maxon::Bool HAS_NONSTATIC = false;
	Result<void> (*_DataDictionaryReferenceObjectInterface_Init) (maxon::GenericComponent* this_, DataDictionary* reference);
	maxon::Int _DataDictionaryReferenceObjectInterface_Init_Offset;
	Result<void> (*_DataDictionaryReferenceObjectInterface_Init_1) (maxon::GenericComponent* this_, const DataDictionary* reference);
	maxon::Int _DataDictionaryReferenceObjectInterface_Init_1_Offset;
	const DataDictionary& (*_DataDictionaryReferenceObjectInterface_GetDataContainer) (const maxon::GenericComponent* this_);
	maxon::Int _DataDictionaryReferenceObjectInterface_GetDataContainer_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDictionaryReferenceObjectInterface, Init))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDictionaryReferenceObjectInterface, Init), W, MTable>::type::_DataDictionaryReferenceObjectInterface_Init;
			_DataDictionaryReferenceObjectInterface_Init = reinterpret_cast<const decltype(_DataDictionaryReferenceObjectInterface_Init)&>(ptr);
			_DataDictionaryReferenceObjectInterface_Init_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDictionaryReferenceObjectInterface, Init))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDictionaryReferenceObjectInterface, Init), W, MTable>::type::_DataDictionaryReferenceObjectInterface_Init_1;
			_DataDictionaryReferenceObjectInterface_Init_1 = reinterpret_cast<const decltype(_DataDictionaryReferenceObjectInterface_Init_1)&>(ptr);
			_DataDictionaryReferenceObjectInterface_Init_1_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDictionaryReferenceObjectInterface, GetDataContainer))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataDictionaryReferenceObjectInterface, GetDataContainer), W, MTable>::type::_DataDictionaryReferenceObjectInterface_GetDataContainer;
			_DataDictionaryReferenceObjectInterface_GetDataContainer = reinterpret_cast<const decltype(_DataDictionaryReferenceObjectInterface_GetDataContainer)&>(ptr);
			_DataDictionaryReferenceObjectInterface_GetDataContainer_Offset = offset;
		}
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!DataDictionaryObjectInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<DataDictionaryReferenceObjectInterface, typename DataDictionaryObjectInterface::MTable::template CombinedMTable<S>>;
	PRIVATE_MAXON_COMPBASE(DataDictionaryReferenceObjectInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct DataDictionaryReferenceObjectInterface::Hxx2
{
	template <typename S> class Wrapper : public DataDictionaryObjectInterface::Hxx2::template Wrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetDataContainer);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Init);
	static Result<void> _DataDictionaryReferenceObjectInterface_Init(maxon::GenericComponent* this_, DataDictionary* reference) { return ((typename S::Implementation*) this_)->Init(reference); }
	static Result<void> _DataDictionaryReferenceObjectInterface_Init_1(maxon::GenericComponent* this_, const DataDictionary* reference) { return ((typename S::Implementation*) this_)->Init(reference); }
	static const DataDictionary& _DataDictionaryReferenceObjectInterface_GetDataContainer(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetDataContainer(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryReferenceObjectInterface::Init(DataDictionary* reference) -> Result<void>
{
	const DataDictionaryReferenceObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataDictionaryReferenceObjectInterface, this); return mt_._DataDictionaryReferenceObjectInterface_Init((maxon::GenericComponent*) this + mt_._DataDictionaryReferenceObjectInterface_Init_Offset, reference);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryReferenceObjectInterface::Init(const DataDictionary* reference) -> Result<void>
{
	const DataDictionaryReferenceObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataDictionaryReferenceObjectInterface, this); return mt_._DataDictionaryReferenceObjectInterface_Init_1((maxon::GenericComponent*) this + mt_._DataDictionaryReferenceObjectInterface_Init_1_Offset, reference);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryReferenceObjectInterface::GetDataContainer() const -> const DataDictionary&
{
	const DataDictionaryReferenceObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataDictionaryReferenceObjectInterface, this); return mt_._DataDictionaryReferenceObjectInterface_GetDataContainer((const maxon::GenericComponent*) this + mt_._DataDictionaryReferenceObjectInterface_GetDataContainer_Offset);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryReferenceObjectInterface::Hxx1::ReferenceFunctionsImpl<S>::Init(DataDictionary* reference) const -> maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), true, maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataDictionaryReferenceObjectInterface* o_ = (DataDictionaryReferenceObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR)); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDictionaryReferenceObjectInterface, o_, DataDictionaryReferenceObjectInterface_Init) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<DataDictionaryReferenceObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDictionaryReferenceObjectInterface>() : PRIVATE_MAXON_VTABLE(DataDictionaryReferenceObjectInterface, o_); 
	auto res_ = mt_._DataDictionaryReferenceObjectInterface_Init(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._DataDictionaryReferenceObjectInterface_Init_Offset, reference);
	return ReturnHelper::Return(this, res_.GetErrorStorage());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryReferenceObjectInterface::Hxx1::COWReferenceFunctionsImpl<S>::Init(DataDictionary* reference) -> maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), true, maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataDictionaryReferenceObjectInterface* o_ = (DataDictionaryReferenceObjectInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDictionaryReferenceObjectInterface, o_, DataDictionaryReferenceObjectInterface_Init) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<DataDictionaryReferenceObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDictionaryReferenceObjectInterface>() : PRIVATE_MAXON_VTABLE(DataDictionaryReferenceObjectInterface, o_); 
	auto res_ = mt_._DataDictionaryReferenceObjectInterface_Init(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._DataDictionaryReferenceObjectInterface_Init_Offset, reference);
	return ReturnHelper::Return(this, res_.GetErrorStorage());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryReferenceObjectInterface::Hxx1::ReferenceFunctionsImpl<S>::Init(const DataDictionary* reference) const -> maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), true, maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataDictionaryReferenceObjectInterface* o_ = (DataDictionaryReferenceObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR)); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDictionaryReferenceObjectInterface, o_, DataDictionaryReferenceObjectInterface_Init_1) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<DataDictionaryReferenceObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDictionaryReferenceObjectInterface>() : PRIVATE_MAXON_VTABLE(DataDictionaryReferenceObjectInterface, o_); 
	auto res_ = mt_._DataDictionaryReferenceObjectInterface_Init_1(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._DataDictionaryReferenceObjectInterface_Init_1_Offset, reference);
	return ReturnHelper::Return(this, res_.GetErrorStorage());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryReferenceObjectInterface::Hxx1::COWReferenceFunctionsImpl<S>::Init(const DataDictionary* reference) -> maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), true, maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataDictionaryReferenceObjectInterface* o_ = (DataDictionaryReferenceObjectInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDictionaryReferenceObjectInterface, o_, DataDictionaryReferenceObjectInterface_Init_1) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<DataDictionaryReferenceObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDictionaryReferenceObjectInterface>() : PRIVATE_MAXON_VTABLE(DataDictionaryReferenceObjectInterface, o_); 
	auto res_ = mt_._DataDictionaryReferenceObjectInterface_Init_1(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._DataDictionaryReferenceObjectInterface_Init_1_Offset, reference);
	return ReturnHelper::Return(this, res_.GetErrorStorage());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataDictionaryReferenceObjectInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetDataContainer() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const DataDictionary&>, const DataDictionary&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const DataDictionary&>, const DataDictionary&>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DataDictionaryReferenceObjectInterface* o_ = (const DataDictionaryReferenceObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DataDictionaryReferenceObjectInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const DataDictionary&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataDictionaryReferenceObjectInterface, o_, DataDictionaryReferenceObjectInterface_GetDataContainer) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<DataDictionaryReferenceObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataDictionaryReferenceObjectInterface>() : PRIVATE_MAXON_VTABLE(DataDictionaryReferenceObjectInterface, o_); 
	return (mt_._DataDictionaryReferenceObjectInterface_GetDataContainer(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._DataDictionaryReferenceObjectInterface_GetDataContainer_Offset));
}
auto DataDictionaryReferenceObjectInterface::GetPtr() -> Ptr { return Ptr(this); }
auto DataDictionaryReferenceObjectInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
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


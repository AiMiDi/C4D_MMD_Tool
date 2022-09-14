
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1

struct ParametricTypeInterface::MTable
{
	MTable() { }
	template <typename C> explicit MTable(C*) { Init<typename maxon::SFINAEHelper<Hxx2, C>::type::template Wrapper<C>>(); }
	template <typename C> MTable(C*, maxon::Bool) { Init<C>(); }
	PRIVATE_MAXON_MF_POINTER(ParametricTypeInterface_GetId, GetId, false, ParametricTypeInterface, const, (const Id&));
	PRIVATE_MAXON_MF_POINTER(ParametricTypeInterface_Instantiate, Instantiate, false, ParametricTypeInterface, const, (Result<DataType>), const Block<const Member>& args, const Block<const Int64>& iargs);
	PRIVATE_MAXON_MF_POINTER(ParametricTypeInterface_IsBaseOfOrSame, IsBaseOfOrSame, false, ParametricTypeInterface, const, (Bool), const DataType& type, const DataType& other);
	PRIVATE_MAXON_MF_POINTER(ParametricTypeInterface_Convert, Convert, false, ParametricTypeInterface, const, (Result<void>), const DataPtr& dest, const ConstDataPtr& src, CONVERSION_FLAGS ignore);
	PRIVATE_MAXON_MF_POINTER(ParametricTypeInterface_Parse, Parse, false, ParametricTypeInterface, const, (Result<Tuple<DataType, const Char*>>), const Char* params);
	PRIVATE_MAXON_MF_POINTER(ParametricTypeInterface_ResetInstantiated, ResetInstantiated, false, ParametricTypeInterface, const, (void), DataTypeImpl* type);
	PRIVATE_MAXON_MF_POINTER(ParametricTypeInterface_GetLeakingLink, GetLeakingLink, false, ParametricTypeInterface, const, (DataTypeImpl*&), DataTypeImpl* type);
	maxon::ClassInfoBase _info;
	template <typename IMPL> void Init()
	{
		void (*free) (const ParametricTypeInterface*) = &IMPL::Implementation::Free;
		_info._free = reinterpret_cast<void(*)(const void*)>(free);
		_info.PrivateInitName(maxon::details::GetTypeNameHelper<typename IMPL::Implementation>());
		ParametricTypeInterface_GetId = ParametricTypeInterface_GetId_GetPtr<IMPL>(0, true).first;
		ParametricTypeInterface_Instantiate = ParametricTypeInterface_Instantiate_GetPtr<IMPL>(0, true).first;
		ParametricTypeInterface_IsBaseOfOrSame = ParametricTypeInterface_IsBaseOfOrSame_GetPtr<IMPL>(0, true).first;
		ParametricTypeInterface_Convert = ParametricTypeInterface_Convert_GetPtr<IMPL>(0, true).first;
		ParametricTypeInterface_Parse = ParametricTypeInterface_Parse_GetPtr<IMPL>(0, true).first;
		ParametricTypeInterface_ResetInstantiated = ParametricTypeInterface_ResetInstantiated_GetPtr<IMPL>(0, true).first;
		ParametricTypeInterface_GetLeakingLink = ParametricTypeInterface_GetLeakingLink_GetPtr<IMPL>(0, true).first;
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset) { return true; }
	template <typename S> using CombinedMTable = S;
};

struct ParametricTypeInterface::Hxx2
{
	template <typename C> using CWrapper = C;
	template <typename C> class Wrapper
	{
	public:
		using Implementation = C;
		PRIVATE_MAXON_MF_WRAPPER(ParametricTypeInterface_GetId, ParametricTypeInterface, const, (const Id&)) { return C::Get(PRIVATE_MAXON_MF_THIS(const ParametricTypeInterface))->GetId(); }
		PRIVATE_MAXON_MF_WRAPPER(ParametricTypeInterface_Instantiate, ParametricTypeInterface, const, (Result<DataType>), const Block<const Member>& args, const Block<const Int64>& iargs) { return C::Get(PRIVATE_MAXON_MF_THIS(const ParametricTypeInterface))->Instantiate(args, iargs); }
		PRIVATE_MAXON_MF_WRAPPER(ParametricTypeInterface_IsBaseOfOrSame, ParametricTypeInterface, const, (Bool), const DataType& type, const DataType& other) { return C::Get(PRIVATE_MAXON_MF_THIS(const ParametricTypeInterface))->IsBaseOfOrSame(type, other); }
		PRIVATE_MAXON_MF_WRAPPER(ParametricTypeInterface_Convert, ParametricTypeInterface, const, (Result<void>), const DataPtr& dest, const ConstDataPtr& src, CONVERSION_FLAGS ignore) { return C::Get(PRIVATE_MAXON_MF_THIS(const ParametricTypeInterface))->Convert(dest, src, ignore); }
		PRIVATE_MAXON_MF_WRAPPER(ParametricTypeInterface_Parse, ParametricTypeInterface, const, (Result<Tuple<DataType, const Char*>>), const Char* params) { return C::Get(PRIVATE_MAXON_MF_THIS(const ParametricTypeInterface))->Parse(params); }
		PRIVATE_MAXON_MF_WRAPPER(ParametricTypeInterface_ResetInstantiated, ParametricTypeInterface, const, (void), DataTypeImpl* type) { return C::Get(PRIVATE_MAXON_MF_THIS(const ParametricTypeInterface))->ResetInstantiated(type); }
		PRIVATE_MAXON_MF_WRAPPER(ParametricTypeInterface_GetLeakingLink, ParametricTypeInterface, const, (DataTypeImpl*&), DataTypeImpl* type) { return C::Get(PRIVATE_MAXON_MF_THIS(const ParametricTypeInterface))->GetLeakingLink(type); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto ParametricTypeInterface::GetId() const -> const Id&
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((ParametricTypeInterface::MTable*) (this->_vtableCls + 1))[-1].ParametricTypeInterface_GetId);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ParametricTypeInterface::Instantiate(const Block<const Member>& args, const Block<const Int64>& iargs) const -> Result<DataType>
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((ParametricTypeInterface::MTable*) (this->_vtableCls + 1))[-1].ParametricTypeInterface_Instantiate, args, iargs);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ParametricTypeInterface::IsBaseOfOrSame(const DataType& type, const DataType& other) const -> Bool
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((ParametricTypeInterface::MTable*) (this->_vtableCls + 1))[-1].ParametricTypeInterface_IsBaseOfOrSame, type, other);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ParametricTypeInterface::Convert(const DataPtr& dest, const ConstDataPtr& src, CONVERSION_FLAGS ignore) const -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((ParametricTypeInterface::MTable*) (this->_vtableCls + 1))[-1].ParametricTypeInterface_Convert, dest, src, ignore);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ParametricTypeInterface::Parse(const Char* params) const -> Result<Tuple<DataType, const Char*>>
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((ParametricTypeInterface::MTable*) (this->_vtableCls + 1))[-1].ParametricTypeInterface_Parse, params);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ParametricTypeInterface::ResetInstantiated(DataTypeImpl* type) const -> void
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((ParametricTypeInterface::MTable*) (this->_vtableCls + 1))[-1].ParametricTypeInterface_ResetInstantiated, type);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ParametricTypeInterface::GetLeakingLink(DataTypeImpl* type) const -> DataTypeImpl*&
{
	return PRIVATE_MAXON_MF_INVOKE((this), ((ParametricTypeInterface::MTable*) (this->_vtableCls + 1))[-1].ParametricTypeInterface_GetLeakingLink, type);
}

ParametricTypeInterface::ParametricTypeInterface(const MTable& vtable) : _vtableCls(&vtable._info) { }
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ParametricTypeInterface::Hxx1::ConstFn<S>::GetId() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const Id&>, const Id&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const Id&>, const Id&>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const ParametricTypeInterface* o_ = (const ParametricTypeInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = ParametricTypeInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const Id&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), ((ParametricTypeInterface::MTable*) (o_->_vtableCls + 1))[-1].ParametricTypeInterface_GetId));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ParametricTypeInterface::Hxx1::ConstFn<S>::Instantiate(const Block<const Member>& args, const Block<const Int64>& iargs) const -> Result<DataType>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<DataType>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const ParametricTypeInterface* o_ = (const ParametricTypeInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = ParametricTypeInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), ((ParametricTypeInterface::MTable*) (o_->_vtableCls + 1))[-1].ParametricTypeInterface_Instantiate, args, iargs));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ParametricTypeInterface::Hxx1::ConstFn<S>::Instantiate(const DataType& type, const Block<const Int64>& iargs) const -> Result<DataType>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<DataType>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const ParametricTypeInterface* o_ = (const ParametricTypeInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = ParametricTypeInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->Instantiate(type, iargs));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ParametricTypeInterface::Hxx1::ConstFn<S>::Instantiate(const Block<const DataType>& types, const Block<const Int64>& iargs) const -> Result<DataType>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<DataType>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const ParametricTypeInterface* o_ = (const ParametricTypeInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = ParametricTypeInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->Instantiate(types, iargs));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ParametricTypeInterface::Hxx1::ConstFn<S>::Instantiate(Result<DataType>&& type, const Block<const Int64>& iargs) const -> Result<DataType>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<DataType>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const ParametricTypeInterface* o_ = (const ParametricTypeInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = ParametricTypeInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->Instantiate(std::forward<Result<DataType>>(type), iargs));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ParametricTypeInterface::Hxx1::ConstFn<S>::IsBaseOfOrSame(const DataType& type, const DataType& other) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const ParametricTypeInterface* o_ = (const ParametricTypeInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = ParametricTypeInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), ((ParametricTypeInterface::MTable*) (o_->_vtableCls + 1))[-1].ParametricTypeInterface_IsBaseOfOrSame, type, other));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ParametricTypeInterface::Hxx1::ConstFn<S>::Convert(const DataPtr& dest, const ConstDataPtr& src, CONVERSION_FLAGS ignore) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const ParametricTypeInterface* o_ = (const ParametricTypeInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = ParametricTypeInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), ((ParametricTypeInterface::MTable*) (o_->_vtableCls + 1))[-1].ParametricTypeInterface_Convert, dest, src, ignore));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ParametricTypeInterface::Hxx1::ConstFn<S>::Parse(const Char* params) const -> Result<Tuple<DataType, const Char*>>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Tuple<DataType, const Char*>>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const ParametricTypeInterface* o_ = (const ParametricTypeInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = ParametricTypeInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), ((ParametricTypeInterface::MTable*) (o_->_vtableCls + 1))[-1].ParametricTypeInterface_Parse, params));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ParametricTypeInterface::Hxx1::ConstFn<S>::ResetInstantiated(DataTypeImpl* type) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const ParametricTypeInterface* o_ = (const ParametricTypeInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = ParametricTypeInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(); } 
	PRIVATE_MAXON_MF_INVOKE((o_), ((ParametricTypeInterface::MTable*) (o_->_vtableCls + 1))[-1].ParametricTypeInterface_ResetInstantiated, type);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif


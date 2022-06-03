
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
	const Id& (*ParametricTypeInterface_GetId) (const ParametricTypeInterface* this_);
	Result<DataType> (*ParametricTypeInterface_Instantiate) (const ParametricTypeInterface* this_, const Block<const Member>& args, const Block<const Int64>& iargs);
	Bool (*ParametricTypeInterface_IsBaseOfOrSame) (const ParametricTypeInterface* this_, const DataType& type, const DataType& other);
	Result<void> (*ParametricTypeInterface_Convert) (const ParametricTypeInterface* this_, const DataPtr& dest, const ConstDataPtr& src, CONVERSION_FLAGS ignore);
	Result<Tuple<DataType, const Char*>> (*ParametricTypeInterface_Parse) (const ParametricTypeInterface* this_, const Char* params);
	void (*ParametricTypeInterface_ResetInstantiated) (const ParametricTypeInterface* this_, DataTypeImpl* type);
	DataTypeImpl*& (*ParametricTypeInterface_GetLeakingLink) (const ParametricTypeInterface* this_, DataTypeImpl* type);
	maxon::ClassInfoBase _info;
	template <typename IMPL> void Init()
	{
		void (*free) (const ParametricTypeInterface*) = &IMPL::Implementation::Free;
		_info._free = reinterpret_cast<void(*)(const void*)>(free);
		ParametricTypeInterface_GetId = &IMPL::ParametricTypeInterface_GetId;
		ParametricTypeInterface_Instantiate = &IMPL::ParametricTypeInterface_Instantiate;
		ParametricTypeInterface_IsBaseOfOrSame = &IMPL::ParametricTypeInterface_IsBaseOfOrSame;
		ParametricTypeInterface_Convert = &IMPL::ParametricTypeInterface_Convert;
		ParametricTypeInterface_Parse = &IMPL::ParametricTypeInterface_Parse;
		ParametricTypeInterface_ResetInstantiated = &IMPL::ParametricTypeInterface_ResetInstantiated;
		ParametricTypeInterface_GetLeakingLink = &IMPL::ParametricTypeInterface_GetLeakingLink;
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
		static const Id& ParametricTypeInterface_GetId(const ParametricTypeInterface* this_) { return C::Get(this_)->GetId(); }
		static Result<DataType> ParametricTypeInterface_Instantiate(const ParametricTypeInterface* this_, const Block<const Member>& args, const Block<const Int64>& iargs) { return C::Get(this_)->Instantiate(args, iargs); }
		static Bool ParametricTypeInterface_IsBaseOfOrSame(const ParametricTypeInterface* this_, const DataType& type, const DataType& other) { return C::Get(this_)->IsBaseOfOrSame(type, other); }
		static Result<void> ParametricTypeInterface_Convert(const ParametricTypeInterface* this_, const DataPtr& dest, const ConstDataPtr& src, CONVERSION_FLAGS ignore) { return C::Get(this_)->Convert(dest, src, ignore); }
		static Result<Tuple<DataType, const Char*>> ParametricTypeInterface_Parse(const ParametricTypeInterface* this_, const Char* params) { return C::Get(this_)->Parse(params); }
		static void ParametricTypeInterface_ResetInstantiated(const ParametricTypeInterface* this_, DataTypeImpl* type) { return C::Get(this_)->ResetInstantiated(type); }
		static DataTypeImpl*& ParametricTypeInterface_GetLeakingLink(const ParametricTypeInterface* this_, DataTypeImpl* type) { return C::Get(this_)->GetLeakingLink(type); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto ParametricTypeInterface::GetId() const -> const Id&
{
	return ((ParametricTypeInterface::MTable*) (this->_vtableCls + 1))[-1].ParametricTypeInterface_GetId(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ParametricTypeInterface::Instantiate(const Block<const Member>& args, const Block<const Int64>& iargs) const -> Result<DataType>
{
	return ((ParametricTypeInterface::MTable*) (this->_vtableCls + 1))[-1].ParametricTypeInterface_Instantiate(this, args, iargs);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ParametricTypeInterface::IsBaseOfOrSame(const DataType& type, const DataType& other) const -> Bool
{
	return ((ParametricTypeInterface::MTable*) (this->_vtableCls + 1))[-1].ParametricTypeInterface_IsBaseOfOrSame(this, type, other);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ParametricTypeInterface::Convert(const DataPtr& dest, const ConstDataPtr& src, CONVERSION_FLAGS ignore) const -> Result<void>
{
	return ((ParametricTypeInterface::MTable*) (this->_vtableCls + 1))[-1].ParametricTypeInterface_Convert(this, dest, src, ignore);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ParametricTypeInterface::Parse(const Char* params) const -> Result<Tuple<DataType, const Char*>>
{
	return ((ParametricTypeInterface::MTable*) (this->_vtableCls + 1))[-1].ParametricTypeInterface_Parse(this, params);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ParametricTypeInterface::ResetInstantiated(DataTypeImpl* type) const -> void
{
	return ((ParametricTypeInterface::MTable*) (this->_vtableCls + 1))[-1].ParametricTypeInterface_ResetInstantiated(this, type);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ParametricTypeInterface::GetLeakingLink(DataTypeImpl* type) const -> DataTypeImpl*&
{
	return ((ParametricTypeInterface::MTable*) (this->_vtableCls + 1))[-1].ParametricTypeInterface_GetLeakingLink(this, type);
}

ParametricTypeInterface::ParametricTypeInterface(const MTable& vtable) : _vtableCls(&vtable._info) { }
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ParametricTypeInterface::Hxx1::ConstFn<S>::GetId() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const Id&>, const Id&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const Id&>, const Id&>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ParametricTypeInterface* o_ = (const ParametricTypeInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ParametricTypeInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const Id&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (((ParametricTypeInterface::MTable*) (o_->_vtableCls + 1))[-1].ParametricTypeInterface_GetId(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ParametricTypeInterface::Hxx1::ConstFn<S>::Instantiate(const Block<const Member>& args, const Block<const Int64>& iargs) const -> Result<DataType>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<DataType>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ParametricTypeInterface* o_ = (const ParametricTypeInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ParametricTypeInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (((ParametricTypeInterface::MTable*) (o_->_vtableCls + 1))[-1].ParametricTypeInterface_Instantiate(o_, args, iargs));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ParametricTypeInterface::Hxx1::ConstFn<S>::Instantiate(const DataType& type, const Block<const Int64>& iargs) const -> Result<DataType>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<DataType>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ParametricTypeInterface* o_ = (const ParametricTypeInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ParametricTypeInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->Instantiate(type, iargs));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ParametricTypeInterface::Hxx1::ConstFn<S>::Instantiate(const Block<const DataType>& types, const Block<const Int64>& iargs) const -> Result<DataType>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<DataType>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ParametricTypeInterface* o_ = (const ParametricTypeInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ParametricTypeInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->Instantiate(types, iargs));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ParametricTypeInterface::Hxx1::ConstFn<S>::Instantiate(Result<DataType>&& type, const Block<const Int64>& iargs) const -> Result<DataType>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<DataType>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ParametricTypeInterface* o_ = (const ParametricTypeInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ParametricTypeInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->Instantiate(std::forward<Result<DataType>>(type), iargs));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ParametricTypeInterface::Hxx1::ConstFn<S>::IsBaseOfOrSame(const DataType& type, const DataType& other) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ParametricTypeInterface* o_ = (const ParametricTypeInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ParametricTypeInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (((ParametricTypeInterface::MTable*) (o_->_vtableCls + 1))[-1].ParametricTypeInterface_IsBaseOfOrSame(o_, type, other));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ParametricTypeInterface::Hxx1::ConstFn<S>::Convert(const DataPtr& dest, const ConstDataPtr& src, CONVERSION_FLAGS ignore) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ParametricTypeInterface* o_ = (const ParametricTypeInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ParametricTypeInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (((ParametricTypeInterface::MTable*) (o_->_vtableCls + 1))[-1].ParametricTypeInterface_Convert(o_, dest, src, ignore));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ParametricTypeInterface::Hxx1::ConstFn<S>::Parse(const Char* params) const -> Result<Tuple<DataType, const Char*>>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Tuple<DataType, const Char*>>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ParametricTypeInterface* o_ = (const ParametricTypeInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ParametricTypeInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (((ParametricTypeInterface::MTable*) (o_->_vtableCls + 1))[-1].ParametricTypeInterface_Parse(o_, params));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ParametricTypeInterface::Hxx1::ConstFn<S>::ResetInstantiated(DataTypeImpl* type) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ParametricTypeInterface* o_ = (const ParametricTypeInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ParametricTypeInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(); } 
	((ParametricTypeInterface::MTable*) (o_->_vtableCls + 1))[-1].ParametricTypeInterface_ResetInstantiated(o_, type);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif


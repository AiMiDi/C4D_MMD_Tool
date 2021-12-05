
#ifndef DOXYGEN

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wmisleading-indentation"
#endif

#if 1

struct FFTInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetSupportOptions);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Transform1D);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Transform2D);
	static const maxon::Char* const _ids;
	static const maxon::Bool HAS_NONSTATIC = false;
	Result<void> (*_FFTInterface_Transform1D) (const maxon::GenericComponent* this_, const ArrayInterface<Generic>& in, WritableArrayInterface<Generic>& out, FFT_FLAGS fftFlags);
	maxon::Int _FFTInterface_Transform1D_Offset;
	Result<void> (*_FFTInterface_Transform2D) (const maxon::GenericComponent* this_, const ConstMatrixNxMInterface& in, const MatrixNxMInterface& out, FFT_FLAGS fftFlags);
	maxon::Int _FFTInterface_Transform2D_Offset;
	FFT_SUPPORT (*_FFTInterface_GetSupportOptions) (const maxon::GenericComponent* this_);
	maxon::Int _FFTInterface_GetSupportOptions_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
		if (PRIVATE_MAXON_IMPLEMENTS(W::Implementation, FFTInterface, Transform1D))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(W::Implementation, FFTInterface, Transform1D), W, MTable>::type::_FFTInterface_Transform1D;
			_FFTInterface_Transform1D = reinterpret_cast<const decltype(_FFTInterface_Transform1D)&>(ptr);
			_FFTInterface_Transform1D_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(W::Implementation, FFTInterface, Transform2D))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(W::Implementation, FFTInterface, Transform2D), W, MTable>::type::_FFTInterface_Transform2D;
			_FFTInterface_Transform2D = reinterpret_cast<const decltype(_FFTInterface_Transform2D)&>(ptr);
			_FFTInterface_Transform2D_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(W::Implementation, FFTInterface, GetSupportOptions))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(W::Implementation, FFTInterface, GetSupportOptions), W, MTable>::type::_FFTInterface_GetSupportOptions;
			_FFTInterface_GetSupportOptions = reinterpret_cast<const decltype(_FFTInterface_GetSupportOptions)&>(ptr);
			_FFTInterface_GetSupportOptions_Offset = offset;
		}
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!Object::MTable::InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::Object::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<FFTInterface, Object::MTable::CombinedMTable<S>>;
	PRIVATE_MAXON_COMPBASE(FFTInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

template <typename S> class FFTInterface::Wrapper : public Object::Wrapper<S>
{
public:
	PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetSupportOptions);
	PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Transform1D);
	PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Transform2D);
	static Result<void> _FFTInterface_Transform1D(const maxon::GenericComponent* this_, const ArrayInterface<Generic>& in, WritableArrayInterface<Generic>& out, FFT_FLAGS fftFlags) { return ((const typename S::Implementation*) this_)->Transform1D(in, out, fftFlags); }
	static Result<void> _FFTInterface_Transform2D(const maxon::GenericComponent* this_, const ConstMatrixNxMInterface& in, const MatrixNxMInterface& out, FFT_FLAGS fftFlags) { return ((const typename S::Implementation*) this_)->Transform2D(in, out, fftFlags); }
	static FFT_SUPPORT _FFTInterface_GetSupportOptions(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetSupportOptions(); }
};

MAXON_ATTRIBUTE_FORCE_INLINE auto FFTInterface::Transform1D(const ArrayInterface<Generic>& in, WritableArrayInterface<Generic>& out, FFT_FLAGS fftFlags) const -> Result<void>
{
	const FFTInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(FFTInterface, this); return mt_._FFTInterface_Transform1D((const maxon::GenericComponent*) this + mt_._FFTInterface_Transform1D_Offset, in, out, fftFlags);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto FFTInterface::Transform2D(const ConstMatrixNxMInterface& in, const MatrixNxMInterface& out, FFT_FLAGS fftFlags) const -> Result<void>
{
	const FFTInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(FFTInterface, this); return mt_._FFTInterface_Transform2D((const maxon::GenericComponent*) this + mt_._FFTInterface_Transform2D_Offset, in, out, fftFlags);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto FFTInterface::GetSupportOptions() const -> FFT_SUPPORT
{
	const FFTInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(FFTInterface, this); return mt_._FFTInterface_GetSupportOptions((const maxon::GenericComponent*) this + mt_._FFTInterface_GetSupportOptions_Offset);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto FFTInterface::ConstReferenceFunctionsImpl<S>::Transform1D(const ArrayInterface<Generic>& in, WritableArrayInterface<Generic>& out, FFT_FLAGS fftFlags) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const FFTInterface* o_ = (const FFTInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = FFTInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(FFTInterface, o_, FFTInterface_Transform1D) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<FFTInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<FFTInterface>() : PRIVATE_MAXON_VTABLE(FFTInterface, o_); 
	return (mt_._FFTInterface_Transform1D(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._FFTInterface_Transform1D_Offset, in, out, fftFlags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto FFTInterface::ConstReferenceFunctionsImpl<S>::Transform2D(const ConstMatrixNxMInterface& in, const MatrixNxMInterface& out, FFT_FLAGS fftFlags) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const FFTInterface* o_ = (const FFTInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = FFTInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(FFTInterface, o_, FFTInterface_Transform2D) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<FFTInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<FFTInterface>() : PRIVATE_MAXON_VTABLE(FFTInterface, o_); 
	return (mt_._FFTInterface_Transform2D(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._FFTInterface_Transform2D_Offset, in, out, fftFlags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto FFTInterface::ConstReferenceFunctionsImpl<S>::GetSupportOptions() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<FFT_SUPPORT>, FFT_SUPPORT>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<FFT_SUPPORT>, FFT_SUPPORT>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const FFTInterface* o_ = (const FFTInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = FFTInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<FFT_SUPPORT>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(FFTInterface, o_, FFTInterface_GetSupportOptions) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<FFTInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<FFTInterface>() : PRIVATE_MAXON_VTABLE(FFTInterface, o_); 
	return (mt_._FFTInterface_GetSupportOptions(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._FFTInterface_GetSupportOptions_Offset));
}
auto FFTInterface::GetPtr() -> Ptr { return Ptr(this); }
auto FFTInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
static maxon::EntityUse s_ui_maxon_FFTInterface(FFTInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/fft.h", false);
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif


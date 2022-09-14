
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1

struct FFTInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetSupportOptions);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Transform1D);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Transform2D);
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	PRIVATE_MAXON_MF_POINTER(FFTInterface_Transform1D, Transform1D, true, maxon::GenericComponent, const, (Result<void>), const ArrayInterface<Generic>& in, WritableArrayInterface<Generic>& out, FFT_FLAGS fftFlags);
	maxon::Int FFTInterface_Transform1D_Offset;
	PRIVATE_MAXON_MF_POINTER(FFTInterface_Transform2D, Transform2D, true, maxon::GenericComponent, const, (Result<void>), const ConstMatrixNxMInterface& in, const MatrixNxMInterface& out, FFT_FLAGS fftFlags);
	maxon::Int FFTInterface_Transform2D_Offset;
	PRIVATE_MAXON_MF_POINTER(FFTInterface_GetSupportOptions, GetSupportOptions, true, maxon::GenericComponent, const, (FFT_SUPPORT));
	maxon::Int FFTInterface_GetSupportOptions_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, FFTInterface, Transform1D))
	{
		maxon::Tie(FFTInterface_Transform1D, FFTInterface_Transform1D_Offset) = FFTInterface_Transform1D_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, FFTInterface, Transform2D))
	{
		maxon::Tie(FFTInterface_Transform2D, FFTInterface_Transform2D_Offset) = FFTInterface_Transform2D_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, FFTInterface, GetSupportOptions))
	{
		maxon::Tie(FFTInterface_GetSupportOptions, FFTInterface_GetSupportOptions_Offset) = FFTInterface_GetSupportOptions_GetPtr<W>(offset, true);
	}
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<FFTInterface, typename ObjectInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<FFTInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct FFTInterface::Hxx2
{
	template <typename S> class CWrapper : public ObjectInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetSupportOptions);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Transform1D);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Transform2D);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename ObjectInterface::Hxx2::template CWrapper<S>;
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (FFTInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, FFTInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		PRIVATE_MAXON_MF_WRAPPER(FFTInterface_Transform1D, maxon::GenericComponent, const, (Result<void>), const ArrayInterface<Generic>& in, WritableArrayInterface<Generic>& out, FFT_FLAGS fftFlags) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->Transform1D(in, out, fftFlags); }
		PRIVATE_MAXON_MF_WRAPPER(FFTInterface_Transform2D, maxon::GenericComponent, const, (Result<void>), const ConstMatrixNxMInterface& in, const MatrixNxMInterface& out, FFT_FLAGS fftFlags) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->Transform2D(in, out, fftFlags); }
		PRIVATE_MAXON_MF_WRAPPER(FFTInterface_GetSupportOptions, maxon::GenericComponent, const, (FFT_SUPPORT)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetSupportOptions(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto FFTInterface::Transform1D(const ArrayInterface<Generic>& in, WritableArrayInterface<Generic>& out, FFT_FLAGS fftFlags) const -> Result<void>
{
	const FFTInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(FFTInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.FFTInterface_Transform1D_Offset), mt_.FFTInterface_Transform1D, in, out, fftFlags);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto FFTInterface::Transform2D(const ConstMatrixNxMInterface& in, const MatrixNxMInterface& out, FFT_FLAGS fftFlags) const -> Result<void>
{
	const FFTInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(FFTInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.FFTInterface_Transform2D_Offset), mt_.FFTInterface_Transform2D, in, out, fftFlags);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto FFTInterface::GetSupportOptions() const -> FFT_SUPPORT
{
	const FFTInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(FFTInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.FFTInterface_GetSupportOptions_Offset), mt_.FFTInterface_GetSupportOptions);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto FFTInterface::Hxx1::ConstFn<S>::Transform1D(const ArrayInterface<Generic>& in, WritableArrayInterface<Generic>& out, FFT_FLAGS fftFlags) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const FFTInterface* o_ = (const FFTInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = FFTInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(FFTInterface, o_, FFTInterface_Transform1D) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<FFTInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<FFTInterface>() : PRIVATE_MAXON_VTABLE(FFTInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.FFTInterface_Transform1D_Offset), mt_.FFTInterface_Transform1D, in, out, fftFlags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto FFTInterface::Hxx1::ConstFn<S>::Transform2D(const ConstMatrixNxMInterface& in, const MatrixNxMInterface& out, FFT_FLAGS fftFlags) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const FFTInterface* o_ = (const FFTInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = FFTInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(FFTInterface, o_, FFTInterface_Transform2D) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<FFTInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<FFTInterface>() : PRIVATE_MAXON_VTABLE(FFTInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.FFTInterface_Transform2D_Offset), mt_.FFTInterface_Transform2D, in, out, fftFlags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto FFTInterface::Hxx1::ConstFn<S>::GetSupportOptions() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<FFT_SUPPORT>, FFT_SUPPORT>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<FFT_SUPPORT>, FFT_SUPPORT>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const FFTInterface* o_ = (const FFTInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = FFTInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<FFT_SUPPORT>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(FFTInterface, o_, FFTInterface_GetSupportOptions) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<FFTInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<FFTInterface>() : PRIVATE_MAXON_VTABLE(FFTInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.FFTInterface_GetSupportOptions_Offset), mt_.FFTInterface_GetSupportOptions));
}
auto FFTInterface::GetPtr() -> Ptr { return Ptr(this); }
auto FFTInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_fft)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_FFTInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_FFTInterface() { new (s_ui_maxon_FFTInterface) maxon::EntityUse(FFTInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/fft.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_FFTInterface(FFTInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/fft.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif



#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1
#ifdef MAXON_TARGET_WINDOWS
#else
#endif

struct IoPipeInOutputStreamInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetReadHandle);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetWriteHandle);
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	PRIVATE_MAXON_MF_POINTER(IoPipeInOutputStreamInterface_GetReadHandle, GetReadHandle, true, maxon::GenericComponent, const, (PIPEHANDLE));
	maxon::Int IoPipeInOutputStreamInterface_GetReadHandle_Offset;
	PRIVATE_MAXON_MF_POINTER(IoPipeInOutputStreamInterface_GetWriteHandle, GetWriteHandle, true, maxon::GenericComponent, const, (PIPEHANDLE));
	maxon::Int IoPipeInOutputStreamInterface_GetWriteHandle_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoPipeInOutputStreamInterface, GetReadHandle))
	{
		maxon::Tie(IoPipeInOutputStreamInterface_GetReadHandle, IoPipeInOutputStreamInterface_GetReadHandle_Offset) = IoPipeInOutputStreamInterface_GetReadHandle_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoPipeInOutputStreamInterface, GetWriteHandle))
	{
		maxon::Tie(IoPipeInOutputStreamInterface_GetWriteHandle, IoPipeInOutputStreamInterface_GetWriteHandle_Offset) = IoPipeInOutputStreamInterface_GetWriteHandle_GetPtr<W>(offset, true);
	}
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<IoPipeInOutputStreamInterface, typename InOutputStreamInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<IoPipeInOutputStreamInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct IoPipeInOutputStreamInterface::Hxx2
{
	template <typename S> class CWrapper : public InOutputStreamInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetReadHandle);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetWriteHandle);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename InOutputStreamInterface::Hxx2::template CWrapper<S>;
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (IoPipeInOutputStreamInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, IoPipeInOutputStreamInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		PRIVATE_MAXON_MF_WRAPPER(IoPipeInOutputStreamInterface_GetReadHandle, maxon::GenericComponent, const, (PIPEHANDLE)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetReadHandle(); }
		PRIVATE_MAXON_MF_WRAPPER(IoPipeInOutputStreamInterface_GetWriteHandle, maxon::GenericComponent, const, (PIPEHANDLE)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetWriteHandle(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto IoPipeInOutputStreamInterface::GetReadHandle() const -> PIPEHANDLE
{
	const IoPipeInOutputStreamInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(IoPipeInOutputStreamInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.IoPipeInOutputStreamInterface_GetReadHandle_Offset), mt_.IoPipeInOutputStreamInterface_GetReadHandle);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoPipeInOutputStreamInterface::GetWriteHandle() const -> PIPEHANDLE
{
	const IoPipeInOutputStreamInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(IoPipeInOutputStreamInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.IoPipeInOutputStreamInterface_GetWriteHandle_Offset), mt_.IoPipeInOutputStreamInterface_GetWriteHandle);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoPipeInOutputStreamInterface::Hxx1::ConstFn<S>::GetReadHandle() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<PIPEHANDLE>, PIPEHANDLE>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<PIPEHANDLE>, PIPEHANDLE>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const IoPipeInOutputStreamInterface* o_ = (const IoPipeInOutputStreamInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = IoPipeInOutputStreamInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<PIPEHANDLE>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoPipeInOutputStreamInterface, o_, IoPipeInOutputStreamInterface_GetReadHandle) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<IoPipeInOutputStreamInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoPipeInOutputStreamInterface>() : PRIVATE_MAXON_VTABLE(IoPipeInOutputStreamInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.IoPipeInOutputStreamInterface_GetReadHandle_Offset), mt_.IoPipeInOutputStreamInterface_GetReadHandle));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoPipeInOutputStreamInterface::Hxx1::ConstFn<S>::GetWriteHandle() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<PIPEHANDLE>, PIPEHANDLE>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<PIPEHANDLE>, PIPEHANDLE>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const IoPipeInOutputStreamInterface* o_ = (const IoPipeInOutputStreamInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = IoPipeInOutputStreamInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<PIPEHANDLE>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoPipeInOutputStreamInterface, o_, IoPipeInOutputStreamInterface_GetWriteHandle) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<IoPipeInOutputStreamInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoPipeInOutputStreamInterface>() : PRIVATE_MAXON_VTABLE(IoPipeInOutputStreamInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.IoPipeInOutputStreamInterface_GetWriteHandle_Offset), mt_.IoPipeInOutputStreamInterface_GetWriteHandle));
}
auto IoPipeInOutputStreamInterface::GetPtr() -> Ptr { return Ptr(this); }
auto IoPipeInOutputStreamInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_iostream_pipe)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_IoPipeInOutputStreamInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_IoPipeInOutputStreamInterface() { new (s_ui_maxon_IoPipeInOutputStreamInterface) maxon::EntityUse(IoPipeInOutputStreamInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/iostream_pipe.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_IoPipeInOutputStreamInterface(IoPipeInOutputStreamInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/iostream_pipe.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif


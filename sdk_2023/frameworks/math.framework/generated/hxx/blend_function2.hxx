
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1

struct BlendFunctionInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(MapValue);
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	PRIVATE_MAXON_MF_POINTER(BlendFunctionInterface_MapValue, MapValue, true, maxon::GenericComponent,, (Result<Data>), Float x, const Data& startValue, const Data& endValue);
	maxon::Int BlendFunctionInterface_MapValue_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BlendFunctionInterface, MapValue))
	{
		maxon::Tie(BlendFunctionInterface_MapValue, BlendFunctionInterface_MapValue_Offset) = BlendFunctionInterface_MapValue_GetPtr<W>(offset, true);
	}
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<BlendFunctionInterface, typename ObjectInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<BlendFunctionInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct BlendFunctionInterface::Hxx2
{
	template <typename S> class CWrapper : public ObjectInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(MapValue);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename ObjectInterface::Hxx2::template CWrapper<S>;
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (BlendFunctionInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, BlendFunctionInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		PRIVATE_MAXON_MF_WRAPPER(BlendFunctionInterface_MapValue, maxon::GenericComponent,, (Result<Data>), Float x, const Data& startValue, const Data& endValue) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->MapValue(x, startValue, endValue); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto BlendFunctionInterface::MapValue(Float x, const Data& startValue, const Data& endValue) -> Result<Data>
{
	const BlendFunctionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(BlendFunctionInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.BlendFunctionInterface_MapValue_Offset), mt_.BlendFunctionInterface_MapValue, x, startValue, endValue);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BlendFunctionInterface::Hxx1::Fn<S>::MapValue(Float x, const Data& startValue, const Data& endValue) const -> Result<Data>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Data>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); BlendFunctionInterface* o_ = (BlendFunctionInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BlendFunctionInterface, o_, BlendFunctionInterface_MapValue) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<BlendFunctionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BlendFunctionInterface>() : PRIVATE_MAXON_VTABLE(BlendFunctionInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.BlendFunctionInterface_MapValue_Offset), mt_.BlendFunctionInterface_MapValue, x, startValue, endValue));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BlendFunctionInterface::Hxx1::COWFn<S>::MapValue(Float x, const Data& startValue, const Data& endValue) -> Result<Data>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Data>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); BlendFunctionInterface* o_ = (BlendFunctionInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BlendFunctionInterface, o_, BlendFunctionInterface_MapValue) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<BlendFunctionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BlendFunctionInterface>() : PRIVATE_MAXON_VTABLE(BlendFunctionInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.BlendFunctionInterface_MapValue_Offset), mt_.BlendFunctionInterface_MapValue, x, startValue, endValue));
}
auto BlendFunctionInterface::GetPtr() -> Ptr { return Ptr(this); }
auto BlendFunctionInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_blend_function)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_BlendFunctionInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_BlendFunctionInterface() { new (s_ui_maxon_BlendFunctionInterface) maxon::EntityUse(BlendFunctionInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/blend_function.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_BlendFunctionInterface(BlendFunctionInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/blend_function.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif


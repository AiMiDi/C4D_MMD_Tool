
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1

struct ConvexDecompositionInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Cancel);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Clear);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Compute);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(FetchResults);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetProgress);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetSettings);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Init);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(IsReady);
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	PRIVATE_MAXON_MF_POINTER(ConvexDecompositionInterface_Init, Init, true, maxon::GenericComponent,, (Result<void>), Float levelOfDetail, UInt32 maxVoxelCount);
	maxon::Int ConvexDecompositionInterface_Init_Offset;
	PRIVATE_MAXON_MF_POINTER(ConvexDecompositionInterface_Init_1, Init, true, maxon::GenericComponent,, (Result<void>), const DataDictionary& settings);
	maxon::Int ConvexDecompositionInterface_Init_1_Offset;
	PRIVATE_MAXON_MF_POINTER(ConvexDecompositionInterface_GetSettings, GetSettings, true, maxon::GenericComponent, const, (Result<DataDictionary>));
	maxon::Int ConvexDecompositionInterface_GetSettings_Offset;
	PRIVATE_MAXON_MF_POINTER(ConvexDecompositionInterface_IsReady, IsReady, true, maxon::GenericComponent, const, (Bool));
	maxon::Int ConvexDecompositionInterface_IsReady_Offset;
	PRIVATE_MAXON_MF_POINTER(ConvexDecompositionInterface_GetProgress, GetProgress, true, maxon::GenericComponent, const, (Result<UInt16>));
	maxon::Int ConvexDecompositionInterface_GetProgress_Offset;
	PRIVATE_MAXON_MF_POINTER(ConvexDecompositionInterface_Compute, Compute, true, maxon::GenericComponent,, (Result<void>), const GeometryObject& geometryObject);
	maxon::Int ConvexDecompositionInterface_Compute_Offset;
	PRIVATE_MAXON_MF_POINTER(ConvexDecompositionInterface_FetchResults, FetchResults, true, maxon::GenericComponent,, (Result<Array<GeometryObject>>));
	maxon::Int ConvexDecompositionInterface_FetchResults_Offset;
	PRIVATE_MAXON_MF_POINTER(ConvexDecompositionInterface_Cancel, Cancel, true, maxon::GenericComponent,, (Result<void>));
	maxon::Int ConvexDecompositionInterface_Cancel_Offset;
	PRIVATE_MAXON_MF_POINTER(ConvexDecompositionInterface_Clear, Clear, true, maxon::GenericComponent,, (Result<void>));
	maxon::Int ConvexDecompositionInterface_Clear_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ConvexDecompositionInterface, Init))
	{
		maxon::Tie(ConvexDecompositionInterface_Init, ConvexDecompositionInterface_Init_Offset) = ConvexDecompositionInterface_Init_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ConvexDecompositionInterface, Init))
	{
		maxon::Tie(ConvexDecompositionInterface_Init_1, ConvexDecompositionInterface_Init_1_Offset) = ConvexDecompositionInterface_Init_1_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ConvexDecompositionInterface, GetSettings))
	{
		maxon::Tie(ConvexDecompositionInterface_GetSettings, ConvexDecompositionInterface_GetSettings_Offset) = ConvexDecompositionInterface_GetSettings_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ConvexDecompositionInterface, IsReady))
	{
		maxon::Tie(ConvexDecompositionInterface_IsReady, ConvexDecompositionInterface_IsReady_Offset) = ConvexDecompositionInterface_IsReady_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ConvexDecompositionInterface, GetProgress))
	{
		maxon::Tie(ConvexDecompositionInterface_GetProgress, ConvexDecompositionInterface_GetProgress_Offset) = ConvexDecompositionInterface_GetProgress_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ConvexDecompositionInterface, Compute))
	{
		maxon::Tie(ConvexDecompositionInterface_Compute, ConvexDecompositionInterface_Compute_Offset) = ConvexDecompositionInterface_Compute_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ConvexDecompositionInterface, FetchResults))
	{
		maxon::Tie(ConvexDecompositionInterface_FetchResults, ConvexDecompositionInterface_FetchResults_Offset) = ConvexDecompositionInterface_FetchResults_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ConvexDecompositionInterface, Cancel))
	{
		maxon::Tie(ConvexDecompositionInterface_Cancel, ConvexDecompositionInterface_Cancel_Offset) = ConvexDecompositionInterface_Cancel_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ConvexDecompositionInterface, Clear))
	{
		maxon::Tie(ConvexDecompositionInterface_Clear, ConvexDecompositionInterface_Clear_Offset) = ConvexDecompositionInterface_Clear_GetPtr<W>(offset, true);
	}
	}
	template <typename S> using CombinedMTable = maxon::PrivateCombinedMTable<ConvexDecompositionInterface, typename ObjectInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<ConvexDecompositionInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct ConvexDecompositionInterface::Hxx2
{
	template <typename S> class CWrapper : public ObjectInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Cancel);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Clear);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Compute);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(FetchResults);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetProgress);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetSettings);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Init);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(IsReady);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename ObjectInterface::Hxx2::template CWrapper<S>;
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (ConvexDecompositionInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, ConvexDecompositionInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		PRIVATE_MAXON_MF_WRAPPER(ConvexDecompositionInterface_Init, maxon::GenericComponent,, (Result<void>), Float levelOfDetail, UInt32 maxVoxelCount) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->Init(levelOfDetail, maxVoxelCount); }
		PRIVATE_MAXON_MF_WRAPPER(ConvexDecompositionInterface_Init_1, maxon::GenericComponent,, (Result<void>), const DataDictionary& settings) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->Init(settings); }
		PRIVATE_MAXON_MF_WRAPPER(ConvexDecompositionInterface_GetSettings, maxon::GenericComponent, const, (Result<DataDictionary>)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetSettings(); }
		PRIVATE_MAXON_MF_WRAPPER(ConvexDecompositionInterface_IsReady, maxon::GenericComponent, const, (Bool)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->IsReady(); }
		PRIVATE_MAXON_MF_WRAPPER(ConvexDecompositionInterface_GetProgress, maxon::GenericComponent, const, (Result<UInt16>)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetProgress(); }
		PRIVATE_MAXON_MF_WRAPPER(ConvexDecompositionInterface_Compute, maxon::GenericComponent,, (Result<void>), const GeometryObject& geometryObject) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->Compute(geometryObject); }
		PRIVATE_MAXON_MF_WRAPPER(ConvexDecompositionInterface_FetchResults, maxon::GenericComponent,, (Result<Array<GeometryObject>>)) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->FetchResults(); }
		PRIVATE_MAXON_MF_WRAPPER(ConvexDecompositionInterface_Cancel, maxon::GenericComponent,, (Result<void>)) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->Cancel(); }
		PRIVATE_MAXON_MF_WRAPPER(ConvexDecompositionInterface_Clear, maxon::GenericComponent,, (Result<void>)) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->Clear(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto ConvexDecompositionInterface::Init(Float levelOfDetail, UInt32 maxVoxelCount) -> Result<void>
{
	const ConvexDecompositionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ConvexDecompositionInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.ConvexDecompositionInterface_Init_Offset), mt_.ConvexDecompositionInterface_Init, levelOfDetail, maxVoxelCount);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ConvexDecompositionInterface::Init(const DataDictionary& settings) -> Result<void>
{
	const ConvexDecompositionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ConvexDecompositionInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.ConvexDecompositionInterface_Init_1_Offset), mt_.ConvexDecompositionInterface_Init_1, settings);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ConvexDecompositionInterface::GetSettings() const -> Result<DataDictionary>
{
	const ConvexDecompositionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ConvexDecompositionInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.ConvexDecompositionInterface_GetSettings_Offset), mt_.ConvexDecompositionInterface_GetSettings);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ConvexDecompositionInterface::IsReady() const -> Bool
{
	const ConvexDecompositionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ConvexDecompositionInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.ConvexDecompositionInterface_IsReady_Offset), mt_.ConvexDecompositionInterface_IsReady);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ConvexDecompositionInterface::GetProgress() const -> Result<UInt16>
{
	const ConvexDecompositionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ConvexDecompositionInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.ConvexDecompositionInterface_GetProgress_Offset), mt_.ConvexDecompositionInterface_GetProgress);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ConvexDecompositionInterface::Compute(const GeometryObject& geometryObject) -> Result<void>
{
	const ConvexDecompositionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ConvexDecompositionInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.ConvexDecompositionInterface_Compute_Offset), mt_.ConvexDecompositionInterface_Compute, geometryObject);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ConvexDecompositionInterface::FetchResults() -> Result<Array<GeometryObject>>
{
	const ConvexDecompositionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ConvexDecompositionInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.ConvexDecompositionInterface_FetchResults_Offset), mt_.ConvexDecompositionInterface_FetchResults);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ConvexDecompositionInterface::Cancel() -> Result<void>
{
	const ConvexDecompositionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ConvexDecompositionInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.ConvexDecompositionInterface_Cancel_Offset), mt_.ConvexDecompositionInterface_Cancel);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ConvexDecompositionInterface::Clear() -> Result<void>
{
	const ConvexDecompositionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ConvexDecompositionInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.ConvexDecompositionInterface_Clear_Offset), mt_.ConvexDecompositionInterface_Clear);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ConvexDecompositionInterface::Hxx1::Fn<S>::Init(Float levelOfDetail, UInt32 maxVoxelCount) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(ConvexDecompositionInterface_Init); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ConvexDecompositionInterface_Init_Offset), mt_.ConvexDecompositionInterface_Init, levelOfDetail, maxVoxelCount));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ConvexDecompositionInterface::Hxx1::COWFn<S>::Init(Float levelOfDetail, UInt32 maxVoxelCount) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(ConvexDecompositionInterface_Init); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ConvexDecompositionInterface_Init_Offset), mt_.ConvexDecompositionInterface_Init, levelOfDetail, maxVoxelCount));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ConvexDecompositionInterface::Hxx1::Fn<S>::Init(const DataDictionary& settings) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(ConvexDecompositionInterface_Init_1); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ConvexDecompositionInterface_Init_1_Offset), mt_.ConvexDecompositionInterface_Init_1, settings));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ConvexDecompositionInterface::Hxx1::COWFn<S>::Init(const DataDictionary& settings) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(ConvexDecompositionInterface_Init_1); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ConvexDecompositionInterface_Init_1_Offset), mt_.ConvexDecompositionInterface_Init_1, settings));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ConvexDecompositionInterface::Hxx1::ConstFn<S>::GetSettings() const -> Result<DataDictionary>
{
	HXXRETURN0(Result<DataDictionary>); HXXRES; HXXCONST(HXXRET1(NULLPTR)) HXXTABLE(ConvexDecompositionInterface_GetSettings); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ConvexDecompositionInterface_GetSettings_Offset), mt_.ConvexDecompositionInterface_GetSettings));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ConvexDecompositionInterface::Hxx1::ConstFn<S>::IsReady() const -> HXXADDRET2(Bool)
{
	HXXRETURN0(HXXADDRET2(Bool)); HXXRES; HXXCONST(maxon::PrivateLogNullptrError(false)) HXXTABLE(ConvexDecompositionInterface_IsReady); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ConvexDecompositionInterface_IsReady_Offset), mt_.ConvexDecompositionInterface_IsReady));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ConvexDecompositionInterface::Hxx1::ConstFn<S>::GetProgress() const -> Result<UInt16>
{
	HXXRETURN0(Result<UInt16>); HXXRES; HXXCONST(HXXRET1(NULLPTR)) HXXTABLE(ConvexDecompositionInterface_GetProgress); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.ConvexDecompositionInterface_GetProgress_Offset), mt_.ConvexDecompositionInterface_GetProgress));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ConvexDecompositionInterface::Hxx1::Fn<S>::Compute(const GeometryObject& geometryObject) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(ConvexDecompositionInterface_Compute); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ConvexDecompositionInterface_Compute_Offset), mt_.ConvexDecompositionInterface_Compute, geometryObject));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ConvexDecompositionInterface::Hxx1::COWFn<S>::Compute(const GeometryObject& geometryObject) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(ConvexDecompositionInterface_Compute); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ConvexDecompositionInterface_Compute_Offset), mt_.ConvexDecompositionInterface_Compute, geometryObject));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ConvexDecompositionInterface::Hxx1::Fn<S>::FetchResults() const -> Result<Array<GeometryObject>>
{
	HXXRETURN0(Result<Array<GeometryObject>>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(ConvexDecompositionInterface_FetchResults); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ConvexDecompositionInterface_FetchResults_Offset), mt_.ConvexDecompositionInterface_FetchResults));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ConvexDecompositionInterface::Hxx1::COWFn<S>::FetchResults() -> Result<Array<GeometryObject>>
{
	HXXRETURN0(Result<Array<GeometryObject>>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(ConvexDecompositionInterface_FetchResults); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ConvexDecompositionInterface_FetchResults_Offset), mt_.ConvexDecompositionInterface_FetchResults));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ConvexDecompositionInterface::Hxx1::Fn<S>::Cancel() const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(ConvexDecompositionInterface_Cancel); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ConvexDecompositionInterface_Cancel_Offset), mt_.ConvexDecompositionInterface_Cancel));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ConvexDecompositionInterface::Hxx1::COWFn<S>::Cancel() -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(ConvexDecompositionInterface_Cancel); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ConvexDecompositionInterface_Cancel_Offset), mt_.ConvexDecompositionInterface_Cancel));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ConvexDecompositionInterface::Hxx1::Fn<S>::Clear() const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(ConvexDecompositionInterface_Clear); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ConvexDecompositionInterface_Clear_Offset), mt_.ConvexDecompositionInterface_Clear));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ConvexDecompositionInterface::Hxx1::COWFn<S>::Clear() -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(ConvexDecompositionInterface_Clear); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ConvexDecompositionInterface_Clear_Offset), mt_.ConvexDecompositionInterface_Clear));
}
auto ConvexDecompositionInterface::GetPtr() -> Ptr { return Ptr(this); }
auto ConvexDecompositionInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_convexdecomposition)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_ConvexDecompositionInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_ConvexDecompositionInterface() { new (s_ui_maxon_ConvexDecompositionInterface) maxon::EntityUse(ConvexDecompositionInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/convexdecomposition/convexdecomposition.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_ConvexDecompositionInterface(ConvexDecompositionInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/convexdecomposition/convexdecomposition.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif


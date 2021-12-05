#if 1
namespace maxon
{
	namespace enum37 { enum class SPLINEMAPPER_KNOT_INTERPOLATION_TYPE
	{
		BEZIER,	///< Bezier (aka Spline) interpolation, uses tangents settings to calculate the interpolation.
		LINEAR,	///< Linear interpolation.
		CUBIC		///< Cubic interpolation.
	} ; }
	maxon::String PrivateToString_SPLINEMAPPER_KNOT_INTERPOLATION_TYPE37(std::underlying_type<enum37::SPLINEMAPPER_KNOT_INTERPOLATION_TYPE>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum37::SPLINEMAPPER_KNOT_INTERPOLATION_TYPE::BEZIER, (maxon::UInt64) enum37::SPLINEMAPPER_KNOT_INTERPOLATION_TYPE::LINEAR, (maxon::UInt64) enum37::SPLINEMAPPER_KNOT_INTERPOLATION_TYPE::CUBIC};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "SPLINEMAPPER_KNOT_INTERPOLATION_TYPE", SIZEOF(x), false, values, "BEZIER\0LINEAR\0CUBIC\0", fmt);
	}
	namespace enum52 { enum class SPLINEMAPPER_KNOT_FLAGS
	{
		BREAK_TANGENTS	= (1 << 0),	///< Break knot tangents (used only with @ref SPLINEMAPPER_KNOT_INTERPOLATION_TYPE::BEZIER interpolation type)
		LOCK_X					= (1 << 1),	///< Lock knot's X movement.
		LOCK_Y					= (1 << 2),	///< Lock knot's Y movement.
		LOCK_ANGLE			= (1 << 3),	///< Lock knot's tangent angle. (used only with @ref SPLINEMAPPER_KNOT_INTERPOLATION_TYPE::BEZIER interpolation type)
		LOCK_LENGTH			= (1 << 4),	///< Lock knot's tangent length. (used only with @ref SPLINEMAPPER_KNOT_INTERPOLATION_TYPE::BEZIER interpolation type)
		KEEPVISUALANGLE	= (1 << 5) ///< Keep visual angle between knot's tangents. (used only with @ref SPLINEMAPPER_KNOT_INTERPOLATION_TYPE::BEZIER interpolation type)
	} ; }
	maxon::String PrivateToString_SPLINEMAPPER_KNOT_FLAGS52(std::underlying_type<enum52::SPLINEMAPPER_KNOT_FLAGS>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum52::SPLINEMAPPER_KNOT_FLAGS::BREAK_TANGENTS, (maxon::UInt64) enum52::SPLINEMAPPER_KNOT_FLAGS::LOCK_X, (maxon::UInt64) enum52::SPLINEMAPPER_KNOT_FLAGS::LOCK_Y, (maxon::UInt64) enum52::SPLINEMAPPER_KNOT_FLAGS::LOCK_ANGLE, (maxon::UInt64) enum52::SPLINEMAPPER_KNOT_FLAGS::LOCK_LENGTH, (maxon::UInt64) enum52::SPLINEMAPPER_KNOT_FLAGS::KEEPVISUALANGLE};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "SPLINEMAPPER_KNOT_FLAGS", SIZEOF(x), true, values, "BREAK_TANGENTS\0LOCK_X\0LOCK_Y\0LOCK_ANGLE\0LOCK_LENGTH\0KEEPVISUALANGLE\0", fmt);
	}
	namespace enum99 { enum class SPLINEMAPPER_SPLINE_TYPE
	{
		SOFT,					///< Soft.
		EASEIN,				///< Ease in.
		EASEOUT,			///< Ease out.
		EASEEASE,			///< Ease ease.
		ZERO,					///< Zero angle/length.
		UNIFY					///< Unify.
	} ; }
	maxon::String PrivateToString_SPLINEMAPPER_SPLINE_TYPE99(std::underlying_type<enum99::SPLINEMAPPER_SPLINE_TYPE>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum99::SPLINEMAPPER_SPLINE_TYPE::SOFT, (maxon::UInt64) enum99::SPLINEMAPPER_SPLINE_TYPE::EASEIN, (maxon::UInt64) enum99::SPLINEMAPPER_SPLINE_TYPE::EASEOUT, (maxon::UInt64) enum99::SPLINEMAPPER_SPLINE_TYPE::EASEEASE, (maxon::UInt64) enum99::SPLINEMAPPER_SPLINE_TYPE::ZERO, (maxon::UInt64) enum99::SPLINEMAPPER_SPLINE_TYPE::UNIFY};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "SPLINEMAPPER_SPLINE_TYPE", SIZEOF(x), false, values, "SOFT\0EASEIN\0EASEOUT\0EASEEASE\0ZERO\0UNIFY\0", fmt);
	}
	namespace enum110 { enum class SPLINEMAPPER_RANGE_STATE
	{
		NONE,
		SET,
		UISET
	} ; }
	maxon::String PrivateToString_SPLINEMAPPER_RANGE_STATE110(std::underlying_type<enum110::SPLINEMAPPER_RANGE_STATE>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum110::SPLINEMAPPER_RANGE_STATE::NONE, (maxon::UInt64) enum110::SPLINEMAPPER_RANGE_STATE::SET, (maxon::UInt64) enum110::SPLINEMAPPER_RANGE_STATE::UISET};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "SPLINEMAPPER_RANGE_STATE", SIZEOF(x), false, values, "NONE\0SET\0UISET\0", fmt);
	}
	const maxon::Char* const SplineMapperInterface::MTable::_ids = 
		"Free@0460a2987fc122d4\0" // void Free(const SplineMapperInterface* object)
		"Alloc@d12fc50c26389b93\0" // SplineMapperInterface* Alloc(const maxon::SourceLocation& allocLocation)
		"Alloc@95e6a3b2be282eeb\0" // SplineMapperInterface* Alloc(const maxon::SourceLocation& allocLocation, const SplineMapperInterface& object)
		"GetPoint@0238dfdf9fa4f6ac\0" // Vector2d GetPoint(Float positionX) const
		"GetRange@2a1ff239ba65b313\0" // void GetRange(Vector2d& min, Vector2d& max) const
		"SetRange@a20993a9ffa525cd\0" // void SetRange(const Vector2d& min, const Vector2d& max)
		"AdaptRange@a20993a9ffa525cd\0" // void AdaptRange(const Vector2d& min, const Vector2d& max)
		"GetTension@f358997b3\0" // Float GetTension() const
		"SetTension@b6e526897a28d\0" // void SetTension(Float tension)
		"GetKnotCount@4386c86\0" // Int GetKnotCount() const
		"GetKnot@f2765bcb1c9d48fc\0" // SplineMapperKnot* GetKnot(Int knotIndex)
		"SetKnot@b2363ae6a3c86fd9\0" // Bool SetKnot(Int knotIndex, const SplineMapperKnot& knot)
		"InsertKnot@4edb525485968e3a\0" // Result<void> InsertKnot(Int knotIndex, const SplineMapperKnot& knot)
		"InsertKnot@213f9329f446549c\0" // Result<Int> InsertKnot(Float x, Float y, Int flags, Bool adaptTangents)
		"DeleteKnot@44dd4274e7521437\0" // Result<void> DeleteKnot(Int knotIndex)
		"DeleteAllKnots@6b2e10f\0" // void DeleteAllKnots()
		"GetKnots@0d7f00441bb7de0a\0" // const BaseArray<SplineMapperKnot>& GetKnots() const
		"GetKnotsRW@fe7cd8db0be54ca9\0" // BaseArray<SplineMapperKnot>* GetKnotsRW()
		"SortKnots@6b2e10f\0" // void SortKnots()
		"ClampPosition@2cf216ce07240f34\0" // Vector2d ClampPosition(const Vector2d& position) const
	"";
	MAXON_WARNING_PUSH
	MAXON_WARNING_DISABLE_DEPRECATED
	class SplineMapperInterface::Hxx2::Unresolved : public SplineMapperInterface
	{
	public:
		static const Unresolved* Get(const SplineMapperInterface* o) { return (const Unresolved*) o; }
		static Unresolved* Get(SplineMapperInterface* o) { return (Unresolved*) o; }
		static void Free(const SplineMapperInterface* object) { if (object && maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return SplineMapperInterface::Free(object); return maxon::PrivateLogNullptrError();}
		static SplineMapperInterface* Alloc(const maxon::SourceLocation& allocLocation) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return SplineMapperInterface::Alloc(allocLocation); return nullptr;}
		static SplineMapperInterface* Alloc(const maxon::SourceLocation& allocLocation, const SplineMapperInterface& object) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return SplineMapperInterface::Alloc(allocLocation, object); return nullptr;}
		Vector2d GetPoint(Float positionX) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const SplineMapperInterface*) this)->GetPoint(positionX); return maxon::PrivateIncompleteNullReturnValue<Vector2d>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		void GetRange(Vector2d& min, Vector2d& max) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const SplineMapperInterface*) this)->GetRange(min, max); return maxon::PrivateLogNullptrError();}
		void SetRange(const Vector2d& min, const Vector2d& max) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((SplineMapperInterface*) this)->SetRange(min, max); return maxon::PrivateLogNullptrError();}
		void AdaptRange(const Vector2d& min, const Vector2d& max) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((SplineMapperInterface*) this)->AdaptRange(min, max); return maxon::PrivateLogNullptrError();}
		Float GetTension() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const SplineMapperInterface*) this)->GetTension(); return 0;}
		void SetTension(Float tension) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((SplineMapperInterface*) this)->SetTension(tension); return maxon::PrivateLogNullptrError();}
		Int GetKnotCount() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const SplineMapperInterface*) this)->GetKnotCount(); return 0;}
		SplineMapperKnot* GetKnot(Int knotIndex) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((SplineMapperInterface*) this)->GetKnot(knotIndex); return nullptr;}
		Bool SetKnot(Int knotIndex, const SplineMapperKnot& knot) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((SplineMapperInterface*) this)->SetKnot(knotIndex, knot); return maxon::PrivateLogNullptrError(false);}
		Result<void> InsertKnot(Int knotIndex, const SplineMapperKnot& knot) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((SplineMapperInterface*) this)->InsertKnot(knotIndex, knot); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<Int> InsertKnot(Float x, Float y, Int flags, Bool adaptTangents) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((SplineMapperInterface*) this)->InsertKnot(x, y, flags, adaptTangents); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> DeleteKnot(Int knotIndex) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((SplineMapperInterface*) this)->DeleteKnot(knotIndex); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		void DeleteAllKnots() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((SplineMapperInterface*) this)->DeleteAllKnots(); return maxon::PrivateLogNullptrError();}
		const BaseArray<SplineMapperKnot>& GetKnots() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const SplineMapperInterface*) this)->GetKnots(); return maxon::PrivateIncompleteNullReturnValue<const BaseArray<SplineMapperKnot>&>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		BaseArray<SplineMapperKnot>* GetKnotsRW() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((SplineMapperInterface*) this)->GetKnotsRW(); return nullptr;}
		void SortKnots() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((SplineMapperInterface*) this)->SortKnots(); return maxon::PrivateLogNullptrError();}
		Vector2d ClampPosition(const Vector2d& position) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const SplineMapperInterface*) this)->ClampPosition(position); return maxon::PrivateIncompleteNullReturnValue<Vector2d>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
	};
	MAXON_WARNING_POP
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::NULL_RETURN_TYPE SplineMapperInterface::MTable::_returnTypes[] = 
	{
		maxon::NULL_RETURN_TYPE::VOID_ZERO_FREE_FUNCTION,
		maxon::details::NullReturnType<SplineMapperInterface*>::value,
		maxon::details::NullReturnType<SplineMapperInterface*>::value,
		maxon::details::NullReturnType<Vector2d>::value,
		maxon::details::NullReturnType<void>::value,
		maxon::details::NullReturnType<void>::value,
		maxon::details::NullReturnType<void>::value,
		maxon::details::NullReturnType<Float>::value,
		maxon::details::NullReturnType<void>::value,
		maxon::details::NullReturnType<Int>::value,
		maxon::details::NullReturnType<SplineMapperKnot*>::value,
		maxon::details::NullReturnType<Bool>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<Int>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<void>::value,
		maxon::details::NullReturnType<const BaseArray<SplineMapperKnot>&>::value,
		maxon::details::NullReturnType<BaseArray<SplineMapperKnot>*>::value,
		maxon::details::NullReturnType<void>::value,
		maxon::details::NullReturnType<Vector2d>::value,
		maxon::NULL_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool SplineMapperInterface::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_SplineMapperInterface_Free = &Hxx2::Wrapper<Hxx2::Unresolved>::_SplineMapperInterface_Free;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_SplineMapperInterface_Alloc = &Hxx2::Wrapper<Hxx2::Unresolved>::_SplineMapperInterface_Alloc;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_SplineMapperInterface_Alloc_1 = &Hxx2::Wrapper<Hxx2::Unresolved>::_SplineMapperInterface_Alloc_1;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Vector2d>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_SplineMapperInterface_GetPoint = &Hxx2::Wrapper<Hxx2::Unresolved>::_SplineMapperInterface_GetPoint;
		#else
		tbl->_SplineMapperInterface_GetPoint = &Hxx2::Wrapper<Hxx2::Unresolved>::_SplineMapperInterface_GetPoint;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_SplineMapperInterface_GetRange = &Hxx2::Wrapper<Hxx2::Unresolved>::_SplineMapperInterface_GetRange;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_SplineMapperInterface_SetRange = &Hxx2::Wrapper<Hxx2::Unresolved>::_SplineMapperInterface_SetRange;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_SplineMapperInterface_AdaptRange = &Hxx2::Wrapper<Hxx2::Unresolved>::_SplineMapperInterface_AdaptRange;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_SplineMapperInterface_GetTension = &Hxx2::Wrapper<Hxx2::Unresolved>::_SplineMapperInterface_GetTension;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_SplineMapperInterface_SetTension = &Hxx2::Wrapper<Hxx2::Unresolved>::_SplineMapperInterface_SetTension;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_SplineMapperInterface_GetKnotCount = &Hxx2::Wrapper<Hxx2::Unresolved>::_SplineMapperInterface_GetKnotCount;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_SplineMapperInterface_GetKnot = &Hxx2::Wrapper<Hxx2::Unresolved>::_SplineMapperInterface_GetKnot;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_SplineMapperInterface_SetKnot = &Hxx2::Wrapper<Hxx2::Unresolved>::_SplineMapperInterface_SetKnot;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_SplineMapperInterface_InsertKnot = &Hxx2::Wrapper<Hxx2::Unresolved>::_SplineMapperInterface_InsertKnot;
		#else
		tbl->_SplineMapperInterface_InsertKnot = &Hxx2::Wrapper<Hxx2::Unresolved>::_SplineMapperInterface_InsertKnot;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<Int>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_SplineMapperInterface_InsertKnot_1 = &Hxx2::Wrapper<Hxx2::Unresolved>::_SplineMapperInterface_InsertKnot_1;
		#else
		tbl->_SplineMapperInterface_InsertKnot_1 = &Hxx2::Wrapper<Hxx2::Unresolved>::_SplineMapperInterface_InsertKnot_1;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_SplineMapperInterface_DeleteKnot = &Hxx2::Wrapper<Hxx2::Unresolved>::_SplineMapperInterface_DeleteKnot;
		#else
		tbl->_SplineMapperInterface_DeleteKnot = &Hxx2::Wrapper<Hxx2::Unresolved>::_SplineMapperInterface_DeleteKnot;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_SplineMapperInterface_DeleteAllKnots = &Hxx2::Wrapper<Hxx2::Unresolved>::_SplineMapperInterface_DeleteAllKnots;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<const BaseArray<SplineMapperKnot>&>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_SplineMapperInterface_GetKnots = &Hxx2::Wrapper<Hxx2::Unresolved>::_SplineMapperInterface_GetKnots;
		#else
		tbl->_SplineMapperInterface_GetKnots = &Hxx2::Wrapper<Hxx2::Unresolved>::_SplineMapperInterface_GetKnots;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_SplineMapperInterface_GetKnotsRW = &Hxx2::Wrapper<Hxx2::Unresolved>::_SplineMapperInterface_GetKnotsRW;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_SplineMapperInterface_SortKnots = &Hxx2::Wrapper<Hxx2::Unresolved>::_SplineMapperInterface_SortKnots;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Vector2d>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_SplineMapperInterface_ClampPosition = &Hxx2::Wrapper<Hxx2::Unresolved>::_SplineMapperInterface_ClampPosition;
		#else
		tbl->_SplineMapperInterface_ClampPosition = &Hxx2::Wrapper<Hxx2::Unresolved>::_SplineMapperInterface_ClampPosition;
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (maxon::Char*) tbl, _returnTypes, SIZEOF(MTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(SplineMapperInterface, "net.maxon.interface.splinemapper", nullptr);
	template <typename DUMMY> maxon::Int SplineMapperInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		| maxon::details::InstantiateNullReturnValue<Vector2d>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<const BaseArray<SplineMapperKnot>&>(OVERLOAD_MAX_RANK)
		;
	}
}
#endif
static maxon::details::ForceEvaluation s_forceEval_splinemapper(0
	| maxon::SplineMapperInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
);

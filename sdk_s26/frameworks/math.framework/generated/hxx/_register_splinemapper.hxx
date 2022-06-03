#if 1
namespace maxon
{
	namespace enum38
	{
		enum class SPLINEMAPPER_KNOT_INTERPOLATION_TYPE
		{
			BEZIER,	///< Bezier (aka Spline) interpolation, uses tangents settings to calculate the interpolation.
			LINEAR,	///< Linear interpolation.
			CUBIC		///< Cubic interpolation.
		} ;
		static const maxon::UInt64 SPLINEMAPPER_KNOT_INTERPOLATION_TYPE_values[] = {maxon::UInt64(enum38::SPLINEMAPPER_KNOT_INTERPOLATION_TYPE::BEZIER), maxon::UInt64(enum38::SPLINEMAPPER_KNOT_INTERPOLATION_TYPE::LINEAR), maxon::UInt64(enum38::SPLINEMAPPER_KNOT_INTERPOLATION_TYPE::CUBIC)};
		static const maxon::EnumInfo SPLINEMAPPER_KNOT_INTERPOLATION_TYPE_info{"SPLINEMAPPER_KNOT_INTERPOLATION_TYPE", SIZEOF(SPLINEMAPPER_KNOT_INTERPOLATION_TYPE), false, "BEZIER\0LINEAR\0CUBIC\0", SPLINEMAPPER_KNOT_INTERPOLATION_TYPE_values, std::extent<decltype(SPLINEMAPPER_KNOT_INTERPOLATION_TYPE_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_SPLINEMAPPER_KNOT_INTERPOLATION_TYPE38(){ return enum38::SPLINEMAPPER_KNOT_INTERPOLATION_TYPE_info; }
	namespace enum55
	{
		enum class SPLINEMAPPER_KNOT_FLAGS : Int
		{
			NONE            = 0,
			BREAK_TANGENTS	= (1 << 0),	///< Break knot tangents (used only with @ref SPLINEMAPPER_KNOT_INTERPOLATION_TYPE::BEZIER interpolation type)
			LOCK_X					= (1 << 1),	///< Lock knot's X movement.
			LOCK_Y					= (1 << 2),	///< Lock knot's Y movement.
			LOCK_ANGLE			= (1 << 3),	///< Lock knot's tangent angle. (used only with @ref SPLINEMAPPER_KNOT_INTERPOLATION_TYPE::BEZIER interpolation type)
			LOCK_LENGTH			= (1 << 4),	///< Lock knot's tangent length. (used only with @ref SPLINEMAPPER_KNOT_INTERPOLATION_TYPE::BEZIER interpolation type)
			KEEPVISUALANGLE	= (1 << 5), ///< Keep visual angle between knot's tangents. (used only with @ref SPLINEMAPPER_KNOT_INTERPOLATION_TYPE::BEZIER interpolation type)
			SELECTED				= (1 << 6), ///< selected in ui
		} ;
		static const maxon::UInt64 SPLINEMAPPER_KNOT_FLAGS_values[] = {maxon::UInt64(enum55::SPLINEMAPPER_KNOT_FLAGS::NONE), maxon::UInt64(enum55::SPLINEMAPPER_KNOT_FLAGS::BREAK_TANGENTS), maxon::UInt64(enum55::SPLINEMAPPER_KNOT_FLAGS::LOCK_X), maxon::UInt64(enum55::SPLINEMAPPER_KNOT_FLAGS::LOCK_Y), maxon::UInt64(enum55::SPLINEMAPPER_KNOT_FLAGS::LOCK_ANGLE), maxon::UInt64(enum55::SPLINEMAPPER_KNOT_FLAGS::LOCK_LENGTH), maxon::UInt64(enum55::SPLINEMAPPER_KNOT_FLAGS::KEEPVISUALANGLE), maxon::UInt64(enum55::SPLINEMAPPER_KNOT_FLAGS::SELECTED)};
		static const maxon::EnumInfo SPLINEMAPPER_KNOT_FLAGS_info{"SPLINEMAPPER_KNOT_FLAGS", SIZEOF(SPLINEMAPPER_KNOT_FLAGS), true, "NONE\0BREAK_TANGENTS\0LOCK_X\0LOCK_Y\0LOCK_ANGLE\0LOCK_LENGTH\0KEEPVISUALANGLE\0SELECTED\0", SPLINEMAPPER_KNOT_FLAGS_values, std::extent<decltype(SPLINEMAPPER_KNOT_FLAGS_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_SPLINEMAPPER_KNOT_FLAGS55(){ return enum55::SPLINEMAPPER_KNOT_FLAGS_info; }
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(DT_SplineMapperKnot,, "net.maxon.datatype.splinemapperknot");
	namespace enum131
	{
		enum class SPLINEMAPPER_SPLINE_TYPE
		{
			SOFT,					///< Soft.
			EASEIN,				///< Ease in.
			EASEOUT,			///< Ease out.
			EASEEASE,			///< Ease ease.
			ZERO,					///< Zero angle/length.
			UNIFY					///< Unify.
		} ;
		static const maxon::UInt64 SPLINEMAPPER_SPLINE_TYPE_values[] = {maxon::UInt64(enum131::SPLINEMAPPER_SPLINE_TYPE::SOFT), maxon::UInt64(enum131::SPLINEMAPPER_SPLINE_TYPE::EASEIN), maxon::UInt64(enum131::SPLINEMAPPER_SPLINE_TYPE::EASEOUT), maxon::UInt64(enum131::SPLINEMAPPER_SPLINE_TYPE::EASEEASE), maxon::UInt64(enum131::SPLINEMAPPER_SPLINE_TYPE::ZERO), maxon::UInt64(enum131::SPLINEMAPPER_SPLINE_TYPE::UNIFY)};
		static const maxon::EnumInfo SPLINEMAPPER_SPLINE_TYPE_info{"SPLINEMAPPER_SPLINE_TYPE", SIZEOF(SPLINEMAPPER_SPLINE_TYPE), false, "SOFT\0EASEIN\0EASEOUT\0EASEEASE\0ZERO\0UNIFY\0", SPLINEMAPPER_SPLINE_TYPE_values, std::extent<decltype(SPLINEMAPPER_SPLINE_TYPE_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_SPLINEMAPPER_SPLINE_TYPE131(){ return enum131::SPLINEMAPPER_SPLINE_TYPE_info; }
	namespace enum142
	{
		enum class SPLINEMAPPER_RANGE_STATE
		{
			NONE,
			SET,
			UISET
		} ;
		static const maxon::UInt64 SPLINEMAPPER_RANGE_STATE_values[] = {maxon::UInt64(enum142::SPLINEMAPPER_RANGE_STATE::NONE), maxon::UInt64(enum142::SPLINEMAPPER_RANGE_STATE::SET), maxon::UInt64(enum142::SPLINEMAPPER_RANGE_STATE::UISET)};
		static const maxon::EnumInfo SPLINEMAPPER_RANGE_STATE_info{"SPLINEMAPPER_RANGE_STATE", SIZEOF(SPLINEMAPPER_RANGE_STATE), false, "NONE\0SET\0UISET\0", SPLINEMAPPER_RANGE_STATE_values, std::extent<decltype(SPLINEMAPPER_RANGE_STATE_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_SPLINEMAPPER_RANGE_STATE142(){ return enum142::SPLINEMAPPER_RANGE_STATE_info; }
	const maxon::Char* const SplineMapperInterface::MTable::_ids = 
		"Free@e3272e43e2fcaec3\0" // void Free(const SplineMapperInterface* object)
		"Alloc@28f6c393733b87a8\0" // SplineMapperInterface* Alloc(const maxon::SourceLocation& allocLocation)
		"Alloc@459d37e1737f50b4\0" // SplineMapperInterface* Alloc(const maxon::SourceLocation& allocLocation, const SplineMapperInterface& object)
		"GetPoint@52df8bf65efb6c85\0" // Vector2d GetPoint(Float positionX) const
		"GetRange@a08a05d8d5a84f7a\0" // void GetRange(Vector2d& min, Vector2d& max) const
		"SetRange@c228e9a08f78fc1c\0" // void SetRange(const Vector2d& min, const Vector2d& max)
		"AdaptRange@c228e9a08f78fc1c\0" // void AdaptRange(const Vector2d& min, const Vector2d& max)
		"GetTension@e6d3186387d3ce58\0" // Float GetTension() const
		"SetTension@9999e08c086b1526\0" // void SetTension(Float tension)
		"GetKnotCount@7d0e6f3d29c239e7\0" // Int GetKnotCount() const
		"GetKnot@842d7475266c6351\0" // SplineMapperKnot* GetKnot(Int knotIndex)
		"SetKnot@479e565ef92394f8\0" // Bool SetKnot(Int knotIndex, const SplineMapperKnot& knot)
		"IsEqual@4cd6ea6ef1e74f96\0" // Bool IsEqual(const SplineMapperInterface* other, EQUALITY equality) const
		"GetHashCode@b22918402154097b\0" // HashInt GetHashCode() const
		"InsertKnot@b467954cdbe66c9\0" // Result<void> InsertKnot(Int knotIndex, const SplineMapperKnot& knot)
		"InsertKnot@1fc3108f634c590f\0" // Result<Int> InsertKnot(Float x, Float y, SPLINEMAPPER_KNOT_FLAGS flags, Bool adaptTangents)
		"DeleteKnot@c49f7df11faba36e\0" // Result<void> DeleteKnot(Int knotIndex)
		"DeleteAllKnots@780cdac8f1a33934\0" // void DeleteAllKnots()
		"GetKnots@a38df7fed8da3981\0" // const BaseArray<SplineMapperKnot>& GetKnots() const
		"GetKnotsRW@707fd377d5ceb8a\0" // BaseArray<SplineMapperKnot>* GetKnotsRW()
		"SortKnots@780cdac8f1a33934\0" // void SortKnots()
		"ClampPosition@e13826ea6fa0e899\0" // Vector2d ClampPosition(const Vector2d& position) const
		"DescribeIO@fe3f1bd5a495cc32\0" // Result<void> DescribeIO(const DataSerializeInterface& stream)
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
		Bool IsEqual(const SplineMapperInterface* other, EQUALITY equality) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const SplineMapperInterface*) this)->IsEqual(other, equality); return maxon::PrivateLogNullptrError(false);}
		HashInt GetHashCode() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const SplineMapperInterface*) this)->GetHashCode(); return maxon::PrivateIncompleteNullReturnValue<HashInt>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		Result<void> InsertKnot(Int knotIndex, const SplineMapperKnot& knot) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((SplineMapperInterface*) this)->InsertKnot(knotIndex, knot); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<Int> InsertKnot(Float x, Float y, SPLINEMAPPER_KNOT_FLAGS flags, Bool adaptTangents) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((SplineMapperInterface*) this)->InsertKnot(x, y, flags, adaptTangents); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> DeleteKnot(Int knotIndex) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((SplineMapperInterface*) this)->DeleteKnot(knotIndex); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		void DeleteAllKnots() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((SplineMapperInterface*) this)->DeleteAllKnots(); return maxon::PrivateLogNullptrError();}
		const BaseArray<SplineMapperKnot>& GetKnots() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const SplineMapperInterface*) this)->GetKnots(); return maxon::PrivateIncompleteNullReturnValue<const BaseArray<SplineMapperKnot>&>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		BaseArray<SplineMapperKnot>* GetKnotsRW() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((SplineMapperInterface*) this)->GetKnotsRW(); return nullptr;}
		void SortKnots() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((SplineMapperInterface*) this)->SortKnots(); return maxon::PrivateLogNullptrError();}
		Vector2d ClampPosition(const Vector2d& position) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const SplineMapperInterface*) this)->ClampPosition(position); return maxon::PrivateIncompleteNullReturnValue<Vector2d>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		static Result<void> DescribeIO(const DataSerializeInterface& stream) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return SplineMapperInterface::DescribeIO(stream); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
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
		maxon::details::NullReturnType<Bool>::value,
		maxon::details::NullReturnType<HashInt>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<Int>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<void>::value,
		maxon::details::NullReturnType<const BaseArray<SplineMapperKnot>&>::value,
		maxon::details::NullReturnType<BaseArray<SplineMapperKnot>*>::value,
		maxon::details::NullReturnType<void>::value,
		maxon::details::NullReturnType<Vector2d>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::NULL_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool SplineMapperInterface::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->SplineMapperInterface_Free = &Hxx2::Wrapper<Hxx2::Unresolved>::SplineMapperInterface_Free;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->SplineMapperInterface_Alloc = &Hxx2::Wrapper<Hxx2::Unresolved>::SplineMapperInterface_Alloc;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->SplineMapperInterface_Alloc_1 = &Hxx2::Wrapper<Hxx2::Unresolved>::SplineMapperInterface_Alloc_1;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Vector2d>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->SplineMapperInterface_GetPoint = &Hxx2::Wrapper<Hxx2::Unresolved>::SplineMapperInterface_GetPoint;
		#else
		tbl->SplineMapperInterface_GetPoint = &Hxx2::Wrapper<Hxx2::Unresolved>::SplineMapperInterface_GetPoint;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->SplineMapperInterface_GetRange = &Hxx2::Wrapper<Hxx2::Unresolved>::SplineMapperInterface_GetRange;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->SplineMapperInterface_SetRange = &Hxx2::Wrapper<Hxx2::Unresolved>::SplineMapperInterface_SetRange;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->SplineMapperInterface_AdaptRange = &Hxx2::Wrapper<Hxx2::Unresolved>::SplineMapperInterface_AdaptRange;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->SplineMapperInterface_GetTension = &Hxx2::Wrapper<Hxx2::Unresolved>::SplineMapperInterface_GetTension;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->SplineMapperInterface_SetTension = &Hxx2::Wrapper<Hxx2::Unresolved>::SplineMapperInterface_SetTension;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->SplineMapperInterface_GetKnotCount = &Hxx2::Wrapper<Hxx2::Unresolved>::SplineMapperInterface_GetKnotCount;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->SplineMapperInterface_GetKnot = &Hxx2::Wrapper<Hxx2::Unresolved>::SplineMapperInterface_GetKnot;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->SplineMapperInterface_SetKnot = &Hxx2::Wrapper<Hxx2::Unresolved>::SplineMapperInterface_SetKnot;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->SplineMapperInterface_IsEqual = &Hxx2::Wrapper<Hxx2::Unresolved>::SplineMapperInterface_IsEqual;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<HashInt>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->SplineMapperInterface_GetHashCode = &Hxx2::Wrapper<Hxx2::Unresolved>::SplineMapperInterface_GetHashCode;
		#else
		tbl->SplineMapperInterface_GetHashCode = &Hxx2::Wrapper<Hxx2::Unresolved>::SplineMapperInterface_GetHashCode;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->SplineMapperInterface_InsertKnot = &Hxx2::Wrapper<Hxx2::Unresolved>::SplineMapperInterface_InsertKnot;
		#else
		tbl->SplineMapperInterface_InsertKnot = &Hxx2::Wrapper<Hxx2::Unresolved>::SplineMapperInterface_InsertKnot;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<Int>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->SplineMapperInterface_InsertKnot_1 = &Hxx2::Wrapper<Hxx2::Unresolved>::SplineMapperInterface_InsertKnot_1;
		#else
		tbl->SplineMapperInterface_InsertKnot_1 = &Hxx2::Wrapper<Hxx2::Unresolved>::SplineMapperInterface_InsertKnot_1;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->SplineMapperInterface_DeleteKnot = &Hxx2::Wrapper<Hxx2::Unresolved>::SplineMapperInterface_DeleteKnot;
		#else
		tbl->SplineMapperInterface_DeleteKnot = &Hxx2::Wrapper<Hxx2::Unresolved>::SplineMapperInterface_DeleteKnot;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->SplineMapperInterface_DeleteAllKnots = &Hxx2::Wrapper<Hxx2::Unresolved>::SplineMapperInterface_DeleteAllKnots;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<const BaseArray<SplineMapperKnot>&>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->SplineMapperInterface_GetKnots = &Hxx2::Wrapper<Hxx2::Unresolved>::SplineMapperInterface_GetKnots;
		#else
		tbl->SplineMapperInterface_GetKnots = &Hxx2::Wrapper<Hxx2::Unresolved>::SplineMapperInterface_GetKnots;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->SplineMapperInterface_GetKnotsRW = &Hxx2::Wrapper<Hxx2::Unresolved>::SplineMapperInterface_GetKnotsRW;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->SplineMapperInterface_SortKnots = &Hxx2::Wrapper<Hxx2::Unresolved>::SplineMapperInterface_SortKnots;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Vector2d>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->SplineMapperInterface_ClampPosition = &Hxx2::Wrapper<Hxx2::Unresolved>::SplineMapperInterface_ClampPosition;
		#else
		tbl->SplineMapperInterface_ClampPosition = &Hxx2::Wrapper<Hxx2::Unresolved>::SplineMapperInterface_ClampPosition;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->SplineMapperInterface_DescribeIO = &Hxx2::Wrapper<Hxx2::Unresolved>::SplineMapperInterface_DescribeIO;
		#else
		tbl->SplineMapperInterface_DescribeIO = &Hxx2::Wrapper<Hxx2::Unresolved>::SplineMapperInterface_DescribeIO;
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
		| maxon::details::InstantiateNullReturnValue<HashInt>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<Vector2d>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<const BaseArray<SplineMapperKnot>&>(OVERLOAD_MAX_RANK)
		;
	}
}
#endif
static maxon::details::ForceEvaluation s_forceEval_splinemapper(0
	| maxon::SplineMapperInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
);

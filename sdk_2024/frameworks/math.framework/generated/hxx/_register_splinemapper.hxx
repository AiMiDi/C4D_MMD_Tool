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
		Vector2d GetPoint(Float positionX) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const SplineMapperInterface*) this)->GetPoint(positionX); return HXXRET3(UNRESOLVED, Vector2d);}
		void GetRange(Vector2d& min, Vector2d& max) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const SplineMapperInterface*) this)->GetRange(min, max); return maxon::PrivateLogNullptrError();}
		void SetRange(const Vector2d& min, const Vector2d& max) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((SplineMapperInterface*) this)->SetRange(min, max); return maxon::PrivateLogNullptrError();}
		void AdaptRange(const Vector2d& min, const Vector2d& max) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((SplineMapperInterface*) this)->AdaptRange(min, max); return maxon::PrivateLogNullptrError();}
		Float GetTension() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const SplineMapperInterface*) this)->GetTension(); return 0;}
		void SetTension(Float tension) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((SplineMapperInterface*) this)->SetTension(tension); return maxon::PrivateLogNullptrError();}
		Int GetKnotCount() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const SplineMapperInterface*) this)->GetKnotCount(); return 0;}
		SplineMapperKnot* GetKnot(Int knotIndex) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((SplineMapperInterface*) this)->GetKnot(knotIndex); return nullptr;}
		Bool SetKnot(Int knotIndex, const SplineMapperKnot& knot) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((SplineMapperInterface*) this)->SetKnot(knotIndex, knot); return maxon::PrivateLogNullptrError(false);}
		Bool IsEqual(const SplineMapperInterface* other, EQUALITY equality) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const SplineMapperInterface*) this)->IsEqual(other, equality); return maxon::PrivateLogNullptrError(false);}
		HashInt GetHashCode() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const SplineMapperInterface*) this)->GetHashCode(); return HXXRET3(UNRESOLVED, HashInt);}
		Result<void> InsertKnot(Int knotIndex, const SplineMapperKnot& knot) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((SplineMapperInterface*) this)->InsertKnot(knotIndex, knot); return HXXRET1(UNRESOLVED);}
		Result<Int> InsertKnot(Float x, Float y, SPLINEMAPPER_KNOT_FLAGS flags, Bool adaptTangents) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((SplineMapperInterface*) this)->InsertKnot(x, y, flags, adaptTangents); return HXXRET1(UNRESOLVED);}
		Result<void> DeleteKnot(Int knotIndex) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((SplineMapperInterface*) this)->DeleteKnot(knotIndex); return HXXRET1(UNRESOLVED);}
		void DeleteAllKnots() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((SplineMapperInterface*) this)->DeleteAllKnots(); return maxon::PrivateLogNullptrError();}
		const BaseArray<SplineMapperKnot>& GetKnots() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const SplineMapperInterface*) this)->GetKnots(); return HXXRET3(UNRESOLVED, const BaseArray<SplineMapperKnot>&);}
		BaseArray<SplineMapperKnot>* GetKnotsRW() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((SplineMapperInterface*) this)->GetKnotsRW(); return nullptr;}
		void SortKnots() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((SplineMapperInterface*) this)->SortKnots(); return maxon::PrivateLogNullptrError();}
		Vector2d ClampPosition(const Vector2d& position) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const SplineMapperInterface*) this)->ClampPosition(position); return HXXRET3(UNRESOLVED, Vector2d);}
		static Result<void> DescribeIO(const DataSerializeInterface& stream) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return SplineMapperInterface::DescribeIO(stream); return HXXRET1(UNRESOLVED);}
	};
	MAXON_WARNING_POP
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::UNRESOLVED_RETURN_TYPE SplineMapperInterface::MTable::_returnTypes[] = 
	{
		maxon::UNRESOLVED_RETURN_TYPE::VOID_ZERO_FREE_FUNCTION,
		maxon::details::UnresolvedReturnType<SplineMapperInterface*>::value,
		maxon::details::UnresolvedReturnType<SplineMapperInterface*>::value,
		maxon::details::UnresolvedReturnType<Vector2d>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<void>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<void>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<void>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Float>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<void>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Int>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<SplineMapperKnot*>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Bool>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Bool>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<HashInt>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Result<void>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Result<Int>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Result<void>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<void>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<const BaseArray<SplineMapperKnot>&>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<BaseArray<SplineMapperKnot>*>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<void>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Vector2d>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Result<void>>::value,
		maxon::UNRESOLVED_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool SplineMapperInterface::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->SplineMapperInterface_Free = PRIVATE_MAXON_MF_CAST(decltype(SplineMapperInterface_Free), &Hxx2::Wrapper<Hxx2::Unresolved>::SplineMapperInterface_Free);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->SplineMapperInterface_Alloc = PRIVATE_MAXON_MF_CAST(decltype(SplineMapperInterface_Alloc), &Hxx2::Wrapper<Hxx2::Unresolved>::SplineMapperInterface_Alloc);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->SplineMapperInterface_Alloc_1 = PRIVATE_MAXON_MF_CAST(decltype(SplineMapperInterface_Alloc_1), &Hxx2::Wrapper<Hxx2::Unresolved>::SplineMapperInterface_Alloc_1);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Vector2d>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->SplineMapperInterface_GetPoint = PRIVATE_MAXON_MF_CAST(decltype(SplineMapperInterface_GetPoint), &Hxx2::Wrapper<Hxx2::Unresolved>::SplineMapperInterface_GetPoint);
		#else
		tbl->SplineMapperInterface_GetPoint = PRIVATE_MAXON_MF_CAST(decltype(SplineMapperInterface_GetPoint), &Hxx2::Wrapper<Hxx2::Unresolved>::SplineMapperInterface_GetPoint);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->SplineMapperInterface_GetRange = PRIVATE_MAXON_MF_CAST(decltype(SplineMapperInterface_GetRange), &Hxx2::Wrapper<Hxx2::Unresolved>::SplineMapperInterface_GetRange);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->SplineMapperInterface_SetRange = PRIVATE_MAXON_MF_CAST(decltype(SplineMapperInterface_SetRange), &Hxx2::Wrapper<Hxx2::Unresolved>::SplineMapperInterface_SetRange);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->SplineMapperInterface_AdaptRange = PRIVATE_MAXON_MF_CAST(decltype(SplineMapperInterface_AdaptRange), &Hxx2::Wrapper<Hxx2::Unresolved>::SplineMapperInterface_AdaptRange);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->SplineMapperInterface_GetTension = PRIVATE_MAXON_MF_CAST(decltype(SplineMapperInterface_GetTension), &Hxx2::Wrapper<Hxx2::Unresolved>::SplineMapperInterface_GetTension);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->SplineMapperInterface_SetTension = PRIVATE_MAXON_MF_CAST(decltype(SplineMapperInterface_SetTension), &Hxx2::Wrapper<Hxx2::Unresolved>::SplineMapperInterface_SetTension);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->SplineMapperInterface_GetKnotCount = PRIVATE_MAXON_MF_CAST(decltype(SplineMapperInterface_GetKnotCount), &Hxx2::Wrapper<Hxx2::Unresolved>::SplineMapperInterface_GetKnotCount);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->SplineMapperInterface_GetKnot = PRIVATE_MAXON_MF_CAST(decltype(SplineMapperInterface_GetKnot), &Hxx2::Wrapper<Hxx2::Unresolved>::SplineMapperInterface_GetKnot);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->SplineMapperInterface_SetKnot = PRIVATE_MAXON_MF_CAST(decltype(SplineMapperInterface_SetKnot), &Hxx2::Wrapper<Hxx2::Unresolved>::SplineMapperInterface_SetKnot);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->SplineMapperInterface_IsEqual = PRIVATE_MAXON_MF_CAST(decltype(SplineMapperInterface_IsEqual), &Hxx2::Wrapper<Hxx2::Unresolved>::SplineMapperInterface_IsEqual);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<HashInt>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->SplineMapperInterface_GetHashCode = PRIVATE_MAXON_MF_CAST(decltype(SplineMapperInterface_GetHashCode), &Hxx2::Wrapper<Hxx2::Unresolved>::SplineMapperInterface_GetHashCode);
		#else
		tbl->SplineMapperInterface_GetHashCode = PRIVATE_MAXON_MF_CAST(decltype(SplineMapperInterface_GetHashCode), &Hxx2::Wrapper<Hxx2::Unresolved>::SplineMapperInterface_GetHashCode);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->SplineMapperInterface_InsertKnot = PRIVATE_MAXON_MF_CAST(decltype(SplineMapperInterface_InsertKnot), &Hxx2::Wrapper<Hxx2::Unresolved>::SplineMapperInterface_InsertKnot);
		#else
		tbl->SplineMapperInterface_InsertKnot = PRIVATE_MAXON_MF_CAST(decltype(SplineMapperInterface_InsertKnot), &Hxx2::Wrapper<Hxx2::Unresolved>::SplineMapperInterface_InsertKnot);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<Int>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->SplineMapperInterface_InsertKnot_1 = PRIVATE_MAXON_MF_CAST(decltype(SplineMapperInterface_InsertKnot_1), &Hxx2::Wrapper<Hxx2::Unresolved>::SplineMapperInterface_InsertKnot_1);
		#else
		tbl->SplineMapperInterface_InsertKnot_1 = PRIVATE_MAXON_MF_CAST(decltype(SplineMapperInterface_InsertKnot_1), &Hxx2::Wrapper<Hxx2::Unresolved>::SplineMapperInterface_InsertKnot_1);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->SplineMapperInterface_DeleteKnot = PRIVATE_MAXON_MF_CAST(decltype(SplineMapperInterface_DeleteKnot), &Hxx2::Wrapper<Hxx2::Unresolved>::SplineMapperInterface_DeleteKnot);
		#else
		tbl->SplineMapperInterface_DeleteKnot = PRIVATE_MAXON_MF_CAST(decltype(SplineMapperInterface_DeleteKnot), &Hxx2::Wrapper<Hxx2::Unresolved>::SplineMapperInterface_DeleteKnot);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->SplineMapperInterface_DeleteAllKnots = PRIVATE_MAXON_MF_CAST(decltype(SplineMapperInterface_DeleteAllKnots), &Hxx2::Wrapper<Hxx2::Unresolved>::SplineMapperInterface_DeleteAllKnots);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<const BaseArray<SplineMapperKnot>&>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->SplineMapperInterface_GetKnots = PRIVATE_MAXON_MF_CAST(decltype(SplineMapperInterface_GetKnots), &Hxx2::Wrapper<Hxx2::Unresolved>::SplineMapperInterface_GetKnots);
		#else
		tbl->SplineMapperInterface_GetKnots = PRIVATE_MAXON_MF_CAST(decltype(SplineMapperInterface_GetKnots), &Hxx2::Wrapper<Hxx2::Unresolved>::SplineMapperInterface_GetKnots);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->SplineMapperInterface_GetKnotsRW = PRIVATE_MAXON_MF_CAST(decltype(SplineMapperInterface_GetKnotsRW), &Hxx2::Wrapper<Hxx2::Unresolved>::SplineMapperInterface_GetKnotsRW);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->SplineMapperInterface_SortKnots = PRIVATE_MAXON_MF_CAST(decltype(SplineMapperInterface_SortKnots), &Hxx2::Wrapper<Hxx2::Unresolved>::SplineMapperInterface_SortKnots);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Vector2d>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->SplineMapperInterface_ClampPosition = PRIVATE_MAXON_MF_CAST(decltype(SplineMapperInterface_ClampPosition), &Hxx2::Wrapper<Hxx2::Unresolved>::SplineMapperInterface_ClampPosition);
		#else
		tbl->SplineMapperInterface_ClampPosition = PRIVATE_MAXON_MF_CAST(decltype(SplineMapperInterface_ClampPosition), &Hxx2::Wrapper<Hxx2::Unresolved>::SplineMapperInterface_ClampPosition);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->SplineMapperInterface_DescribeIO = PRIVATE_MAXON_MF_CAST(decltype(SplineMapperInterface_DescribeIO), &Hxx2::Wrapper<Hxx2::Unresolved>::SplineMapperInterface_DescribeIO);
		#else
		tbl->SplineMapperInterface_DescribeIO = PRIVATE_MAXON_MF_CAST(decltype(SplineMapperInterface_DescribeIO), &Hxx2::Wrapper<Hxx2::Unresolved>::SplineMapperInterface_DescribeIO);
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (const void**) tbl, _returnTypes, SIZEOF(MTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(SplineMapperInterface, "net.maxon.interface.splinemapper", nullptr, maxon::EntityBase::FLAGS::NONE);
	template <typename DUMMY> maxon::Int SplineMapperInterface::PrivateInstantiateDefaultValueHelper()
	{
		return 0
		| maxon::details::InstantiateDefaultReturnValue<HashInt>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateDefaultReturnValue<Vector2d>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateDefaultReturnValue<const BaseArray<SplineMapperKnot>&>(OVERLOAD_MAX_RANK)
		;
	}
}
#endif
static maxon::details::ForceEvaluation s_forceEval_splinemapper(0
	| maxon::SplineMapperInterface::PrivateInstantiateDefaultValueHelper<maxon::Int>()
);

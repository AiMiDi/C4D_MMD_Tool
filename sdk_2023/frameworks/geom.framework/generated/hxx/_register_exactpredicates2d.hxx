#if 1
namespace maxon
{
	const maxon::Char* const ExactPredicates2DInterface::MTable::_ids = 
		"Orient@9c753cc8f94080b5\0" // Float Orient(const Vector2d& pointA, const Vector2d& pointB, const Vector2d& pointC)
		"InCircle@bd75899157ebd233\0" // Float InCircle(const Vector2d& pointA, const Vector2d& pointB, const Vector2d& pointC, const Vector2d& testPoint)
		"InTriangle@19b87006ed59c750\0" // Result<Float> InTriangle(const Vector2d& pointA, const Vector2d& pointB, const Vector2d& pointC, const Vector2d& testPoint)
		"InSector@19b87006ed59c750\0" // Result<Float> InSector(const Vector2d& center, const Vector2d& rayA, const Vector2d& rayB, const Vector2d& testPoint)
		"OutlineSelfIntersectionTest@877e936705fc1636\0" // Result<Bool> OutlineSelfIntersectionTest(const Block<const Vector2d>& outline)
		"OutlinesIntersectionTest@4e8a61fbacf0ca42\0" // Result<Bool> OutlinesIntersectionTest(const Block<const Vector2d>& outline1, const Block<const Vector2d>& outline2)
		"OutlinesIntersectionTest@56b282feb5ae175c\0" // Result<Bool> OutlinesIntersectionTest(const Block<const Block<const Vector2d>>& outlines)
	"";
	MAXON_WARNING_PUSH
	MAXON_WARNING_DISABLE_DEPRECATED
	class ExactPredicates2DInterface::Hxx2::Unresolved : public ExactPredicates2DInterface
	{
	public:
		static const Unresolved* Get(const ExactPredicates2DInterface* o) { return (const Unresolved*) o; }
		static Unresolved* Get(ExactPredicates2DInterface* o) { return (Unresolved*) o; }
		static Float Orient(const Vector2d& pointA, const Vector2d& pointB, const Vector2d& pointC) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ExactPredicates2DInterface::Orient(pointA, pointB, pointC); return 0;}
		static Float InCircle(const Vector2d& pointA, const Vector2d& pointB, const Vector2d& pointC, const Vector2d& testPoint) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ExactPredicates2DInterface::InCircle(pointA, pointB, pointC, testPoint); return 0;}
		static Result<Float> InTriangle(const Vector2d& pointA, const Vector2d& pointB, const Vector2d& pointC, const Vector2d& testPoint) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ExactPredicates2DInterface::InTriangle(pointA, pointB, pointC, testPoint); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<Float> InSector(const Vector2d& center, const Vector2d& rayA, const Vector2d& rayB, const Vector2d& testPoint) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ExactPredicates2DInterface::InSector(center, rayA, rayB, testPoint); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<Bool> OutlineSelfIntersectionTest(const Block<const Vector2d>& outline) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ExactPredicates2DInterface::OutlineSelfIntersectionTest(outline); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<Bool> OutlinesIntersectionTest(const Block<const Vector2d>& outline1, const Block<const Vector2d>& outline2) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ExactPredicates2DInterface::OutlinesIntersectionTest(outline1, outline2); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<Bool> OutlinesIntersectionTest(const Block<const Block<const Vector2d>>& outlines) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ExactPredicates2DInterface::OutlinesIntersectionTest(outlines); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
	};
	MAXON_WARNING_POP
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::NULL_RETURN_TYPE ExactPredicates2DInterface::MTable::_returnTypes[] = 
	{
		maxon::details::NullReturnType<Float>::value,
		maxon::details::NullReturnType<Float>::value,
		maxon::details::NullReturnType<Result<Float>>::value,
		maxon::details::NullReturnType<Result<Float>>::value,
		maxon::details::NullReturnType<Result<Bool>>::value,
		maxon::details::NullReturnType<Result<Bool>>::value,
		maxon::details::NullReturnType<Result<Bool>>::value,
		maxon::NULL_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool ExactPredicates2DInterface::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->ExactPredicates2DInterface_Orient = PRIVATE_MAXON_MF_CAST(decltype(ExactPredicates2DInterface_Orient), &Hxx2::Wrapper<Hxx2::Unresolved>::ExactPredicates2DInterface_Orient);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->ExactPredicates2DInterface_InCircle = PRIVATE_MAXON_MF_CAST(decltype(ExactPredicates2DInterface_InCircle), &Hxx2::Wrapper<Hxx2::Unresolved>::ExactPredicates2DInterface_InCircle);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<Float>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->ExactPredicates2DInterface_InTriangle = PRIVATE_MAXON_MF_CAST(decltype(ExactPredicates2DInterface_InTriangle), &Hxx2::Wrapper<Hxx2::Unresolved>::ExactPredicates2DInterface_InTriangle);
		#else
		tbl->ExactPredicates2DInterface_InTriangle = PRIVATE_MAXON_MF_CAST(decltype(ExactPredicates2DInterface_InTriangle), &Hxx2::Wrapper<Hxx2::Unresolved>::ExactPredicates2DInterface_InTriangle);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<Float>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->ExactPredicates2DInterface_InSector = PRIVATE_MAXON_MF_CAST(decltype(ExactPredicates2DInterface_InSector), &Hxx2::Wrapper<Hxx2::Unresolved>::ExactPredicates2DInterface_InSector);
		#else
		tbl->ExactPredicates2DInterface_InSector = PRIVATE_MAXON_MF_CAST(decltype(ExactPredicates2DInterface_InSector), &Hxx2::Wrapper<Hxx2::Unresolved>::ExactPredicates2DInterface_InSector);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<Bool>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->ExactPredicates2DInterface_OutlineSelfIntersectionTest = PRIVATE_MAXON_MF_CAST(decltype(ExactPredicates2DInterface_OutlineSelfIntersectionTest), &Hxx2::Wrapper<Hxx2::Unresolved>::ExactPredicates2DInterface_OutlineSelfIntersectionTest);
		#else
		tbl->ExactPredicates2DInterface_OutlineSelfIntersectionTest = PRIVATE_MAXON_MF_CAST(decltype(ExactPredicates2DInterface_OutlineSelfIntersectionTest), &Hxx2::Wrapper<Hxx2::Unresolved>::ExactPredicates2DInterface_OutlineSelfIntersectionTest);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<Bool>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->ExactPredicates2DInterface_OutlinesIntersectionTest = PRIVATE_MAXON_MF_CAST(decltype(ExactPredicates2DInterface_OutlinesIntersectionTest), &Hxx2::Wrapper<Hxx2::Unresolved>::ExactPredicates2DInterface_OutlinesIntersectionTest);
		#else
		tbl->ExactPredicates2DInterface_OutlinesIntersectionTest = PRIVATE_MAXON_MF_CAST(decltype(ExactPredicates2DInterface_OutlinesIntersectionTest), &Hxx2::Wrapper<Hxx2::Unresolved>::ExactPredicates2DInterface_OutlinesIntersectionTest);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<Bool>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->ExactPredicates2DInterface_OutlinesIntersectionTest_1 = PRIVATE_MAXON_MF_CAST(decltype(ExactPredicates2DInterface_OutlinesIntersectionTest_1), &Hxx2::Wrapper<Hxx2::Unresolved>::ExactPredicates2DInterface_OutlinesIntersectionTest_1);
		#else
		tbl->ExactPredicates2DInterface_OutlinesIntersectionTest_1 = PRIVATE_MAXON_MF_CAST(decltype(ExactPredicates2DInterface_OutlinesIntersectionTest_1), &Hxx2::Wrapper<Hxx2::Unresolved>::ExactPredicates2DInterface_OutlinesIntersectionTest_1);
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (maxon::Char*) tbl, _returnTypes, SIZEOF(MTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(ExactPredicates2DInterface, "net.maxon.interface.exactpredicates2d", nullptr);
}
#endif

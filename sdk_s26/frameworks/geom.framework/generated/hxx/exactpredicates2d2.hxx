
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1
constexpr const maxon::Char* ExactPredicates2DInterface::PrivateGetCppName() { return nullptr; }

struct ExactPredicates2DInterface::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = false;
	Float (*ExactPredicates2DInterface_Orient) (const Vector2d& pointA, const Vector2d& pointB, const Vector2d& pointC);
	Float (*ExactPredicates2DInterface_InCircle) (const Vector2d& pointA, const Vector2d& pointB, const Vector2d& pointC, const Vector2d& testPoint);
	Result<Float> (*ExactPredicates2DInterface_InTriangle) (const Vector2d& pointA, const Vector2d& pointB, const Vector2d& pointC, const Vector2d& testPoint);
	Result<Float> (*ExactPredicates2DInterface_InSector) (const Vector2d& center, const Vector2d& rayA, const Vector2d& rayB, const Vector2d& testPoint);
	Result<Bool> (*ExactPredicates2DInterface_OutlineSelfIntersectionTest) (const Block<const Vector2d>& outline);
	Result<Bool> (*ExactPredicates2DInterface_OutlinesIntersectionTest) (const Block<const Vector2d>& outline1, const Block<const Vector2d>& outline2);
	Result<Bool> (*ExactPredicates2DInterface_OutlinesIntersectionTest_1) (const Block<const Block<const Vector2d>>& outlines);
	template <typename IMPL> void Init()
	{
		ExactPredicates2DInterface_Orient = &IMPL::ExactPredicates2DInterface_Orient;
		ExactPredicates2DInterface_InCircle = &IMPL::ExactPredicates2DInterface_InCircle;
		ExactPredicates2DInterface_InTriangle = &IMPL::ExactPredicates2DInterface_InTriangle;
		ExactPredicates2DInterface_InSector = &IMPL::ExactPredicates2DInterface_InSector;
		ExactPredicates2DInterface_OutlineSelfIntersectionTest = &IMPL::ExactPredicates2DInterface_OutlineSelfIntersectionTest;
		ExactPredicates2DInterface_OutlinesIntersectionTest = &IMPL::ExactPredicates2DInterface_OutlinesIntersectionTest;
		ExactPredicates2DInterface_OutlinesIntersectionTest_1 = &IMPL::ExactPredicates2DInterface_OutlinesIntersectionTest_1;
	}
};

struct ExactPredicates2DInterface::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
		static Float ExactPredicates2DInterface_Orient(const Vector2d& pointA, const Vector2d& pointB, const Vector2d& pointC) { return C::Orient(pointA, pointB, pointC); }
		static Float ExactPredicates2DInterface_InCircle(const Vector2d& pointA, const Vector2d& pointB, const Vector2d& pointC, const Vector2d& testPoint) { return C::InCircle(pointA, pointB, pointC, testPoint); }
		static Result<Float> ExactPredicates2DInterface_InTriangle(const Vector2d& pointA, const Vector2d& pointB, const Vector2d& pointC, const Vector2d& testPoint) { return C::InTriangle(pointA, pointB, pointC, testPoint); }
		static Result<Float> ExactPredicates2DInterface_InSector(const Vector2d& center, const Vector2d& rayA, const Vector2d& rayB, const Vector2d& testPoint) { return C::InSector(center, rayA, rayB, testPoint); }
		static Result<Bool> ExactPredicates2DInterface_OutlineSelfIntersectionTest(const Block<const Vector2d>& outline) { return C::OutlineSelfIntersectionTest(outline); }
		static Result<Bool> ExactPredicates2DInterface_OutlinesIntersectionTest(const Block<const Vector2d>& outline1, const Block<const Vector2d>& outline2) { return C::OutlinesIntersectionTest(outline1, outline2); }
		static Result<Bool> ExactPredicates2DInterface_OutlinesIntersectionTest_1(const Block<const Block<const Vector2d>>& outlines) { return C::OutlinesIntersectionTest(outlines); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto ExactPredicates2DInterface::Orient(const Vector2d& pointA, const Vector2d& pointB, const Vector2d& pointC) -> Float
{
	return MTable::_instance.ExactPredicates2DInterface_Orient(pointA, pointB, pointC);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ExactPredicates2DInterface::InCircle(const Vector2d& pointA, const Vector2d& pointB, const Vector2d& pointC, const Vector2d& testPoint) -> Float
{
	return MTable::_instance.ExactPredicates2DInterface_InCircle(pointA, pointB, pointC, testPoint);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ExactPredicates2DInterface::InTriangle(const Vector2d& pointA, const Vector2d& pointB, const Vector2d& pointC, const Vector2d& testPoint) -> Result<Float>
{
	return MTable::_instance.ExactPredicates2DInterface_InTriangle(pointA, pointB, pointC, testPoint);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ExactPredicates2DInterface::InSector(const Vector2d& center, const Vector2d& rayA, const Vector2d& rayB, const Vector2d& testPoint) -> Result<Float>
{
	return MTable::_instance.ExactPredicates2DInterface_InSector(center, rayA, rayB, testPoint);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ExactPredicates2DInterface::OutlineSelfIntersectionTest(const Block<const Vector2d>& outline) -> Result<Bool>
{
	return MTable::_instance.ExactPredicates2DInterface_OutlineSelfIntersectionTest(outline);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ExactPredicates2DInterface::OutlinesIntersectionTest(const Block<const Vector2d>& outline1, const Block<const Vector2d>& outline2) -> Result<Bool>
{
	return MTable::_instance.ExactPredicates2DInterface_OutlinesIntersectionTest(outline1, outline2);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ExactPredicates2DInterface::OutlinesIntersectionTest(const Block<const Block<const Vector2d>>& outlines) -> Result<Bool>
{
	return MTable::_instance.ExactPredicates2DInterface_OutlinesIntersectionTest_1(outlines);
}

#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_exactpredicates2d)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_ExactPredicates2DInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_ExactPredicates2DInterface() { new (s_ui_maxon_ExactPredicates2DInterface) maxon::EntityUse(ExactPredicates2DInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/exactpredicates2d.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_ExactPredicates2DInterface(ExactPredicates2DInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/exactpredicates2d.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif


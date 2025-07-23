
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1
constexpr const maxon::Char* NormalsHelperInterface::PrivateGetCppName() { return nullptr; }
#if 0
#endif

struct NormalsHelperInterface::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::UNRESOLVED_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = false;
#if 0
	PRIVATE_MAXON_SF_POINTER(NormalsHelperInterface_CalculatePolygonNormalsSSE, CalculatePolygonNormalsSSE, MAXON_EXPAND_VA_ARGS, (Result<void>), const Block<const Vector4d32>& points, const Block<const SimplePolygon>& polygons, Bool normalized, Block<Vector4d32>& polygonNormals);
	PRIVATE_MAXON_SF_POINTER(NormalsHelperInterface_CalculatePointNormalsAveragedSSE, CalculatePointNormalsAveragedSSE, MAXON_EXPAND_VA_ARGS, (Result<void>), NORMALS_STYLE style, const Block<const Vector4d32>& points, const Block<const SimplePolygon>& polygons, Int pointCount, const Block<const Vector4d32>& polygonNormals, Block<Vector4d32>& pointNormals);
	PRIVATE_MAXON_SF_POINTER(NormalsHelperInterface_CalculateShadingNormalsAveragedSSE, CalculateShadingNormalsAveragedSSE, MAXON_EXPAND_VA_ARGS, (Result<void>), NORMALS_STYLE style, const Block<const Vector4d32>& points, const Block<const SimplePolygon>& polygons, Int pointCount, const Block<const Vector4d32>& polygonNormals, Block<Vector4d32>& shadingNormals);
	PRIVATE_MAXON_SF_POINTER(NormalsHelperInterface_CalculateShadingNormalsSSE, CalculateShadingNormalsSSE, MAXON_EXPAND_VA_ARGS, (Result<void>), NORMALS_STYLE style, const Block<const Vector4d32>& points, const Block<const SimplePolygon>& polygons, Int pointCount, const Block<const Vector4d32>& polygonNormals, Float32 angle, const Block<const UChar>& shadingBreaks, Block<Vector4d32>& shadingNormals);
#endif
	PRIVATE_MAXON_SF_POINTER(NormalsHelperInterface_CalculatePolygonNormals, CalculatePolygonNormals, MAXON_EXPAND_VA_ARGS, (Result<void>), const Block<const Vector>& points, const Block<const SimplePolygon>& polygons, Bool normalized, Block<Vector32>& polygonNormals);
	PRIVATE_MAXON_SF_POINTER(NormalsHelperInterface_CalculatePolygonNormals_1, CalculatePolygonNormals, MAXON_EXPAND_VA_ARGS, (Result<void>), const Block<const Vector>& points, const Block<const SimplePolygon>& polygons, Bool normalized, Block<Vector>& polygonNormals);
	PRIVATE_MAXON_SF_POINTER(NormalsHelperInterface_CalculatePolygonNormals_2, CalculatePolygonNormals, MAXON_EXPAND_VA_ARGS, (Result<void>), const Block<const Vector32>& points, const Block<const SimplePolygon>& polygons, Bool normalized, Block<Vector32>& polygonNormals);
	PRIVATE_MAXON_SF_POINTER(NormalsHelperInterface_CalculatePointNormalsAveraged, CalculatePointNormalsAveraged, MAXON_EXPAND_VA_ARGS, (Result<void>), NORMALS_STYLE style, const Block<const Vector>& points, const Block<const SimplePolygon>& polygons, const Block<const Vector32>& polygonNormals, Block<Vector32>& pointNormals);
	PRIVATE_MAXON_SF_POINTER(NormalsHelperInterface_CalculateShadingNormalsAveraged, CalculateShadingNormalsAveraged, MAXON_EXPAND_VA_ARGS, (Result<void>), NORMALS_STYLE style, const Block<const Vector>& points, const Block<const SimplePolygon>& polygons, const Block<const Vector32>& polygonNormals, Block<Vector32>& shadingNormals);
	PRIVATE_MAXON_SF_POINTER(NormalsHelperInterface_CalculateShadingNormals, CalculateShadingNormals, MAXON_EXPAND_VA_ARGS, (Result<void>), NORMALS_STYLE style, const Block<const Vector>& points, const Block<const SimplePolygon>& polygons, const Block<const Vector32>& polygonNormals, Float32 angle, const Block<const UChar>& shadingBreaks, Block<Vector32>& shadingNormals);
	template <typename IMPL> void Init()
	{
#if 0
		NormalsHelperInterface_CalculatePolygonNormalsSSE = NormalsHelperInterface_CalculatePolygonNormalsSSE_GetPtr<IMPL>(true);
		NormalsHelperInterface_CalculatePointNormalsAveragedSSE = NormalsHelperInterface_CalculatePointNormalsAveragedSSE_GetPtr<IMPL>(true);
		NormalsHelperInterface_CalculateShadingNormalsAveragedSSE = NormalsHelperInterface_CalculateShadingNormalsAveragedSSE_GetPtr<IMPL>(true);
		NormalsHelperInterface_CalculateShadingNormalsSSE = NormalsHelperInterface_CalculateShadingNormalsSSE_GetPtr<IMPL>(true);
#endif
		NormalsHelperInterface_CalculatePolygonNormals = NormalsHelperInterface_CalculatePolygonNormals_GetPtr<IMPL>(true);
		NormalsHelperInterface_CalculatePolygonNormals_1 = NormalsHelperInterface_CalculatePolygonNormals_1_GetPtr<IMPL>(true);
		NormalsHelperInterface_CalculatePolygonNormals_2 = NormalsHelperInterface_CalculatePolygonNormals_2_GetPtr<IMPL>(true);
		NormalsHelperInterface_CalculatePointNormalsAveraged = NormalsHelperInterface_CalculatePointNormalsAveraged_GetPtr<IMPL>(true);
		NormalsHelperInterface_CalculateShadingNormalsAveraged = NormalsHelperInterface_CalculateShadingNormalsAveraged_GetPtr<IMPL>(true);
		NormalsHelperInterface_CalculateShadingNormals = NormalsHelperInterface_CalculateShadingNormals_GetPtr<IMPL>(true);
	}
};

struct NormalsHelperInterface::Hxx2
{
	class Unresolved;
	template <typename S> class Wrapper
	{
	public:
		using Implementation = S;
#if 0
		static Result<void> NormalsHelperInterface_CalculatePolygonNormalsSSE(const Block<const Vector4d32>& points, const Block<const SimplePolygon>& polygons, Bool normalized, Block<Vector4d32>& polygonNormals) { return S::CalculatePolygonNormalsSSE(points, polygons, normalized, polygonNormals); }
		static Result<void> NormalsHelperInterface_CalculatePointNormalsAveragedSSE(NORMALS_STYLE style, const Block<const Vector4d32>& points, const Block<const SimplePolygon>& polygons, Int pointCount, const Block<const Vector4d32>& polygonNormals, Block<Vector4d32>& pointNormals) { return S::CalculatePointNormalsAveragedSSE(style, points, polygons, pointCount, polygonNormals, pointNormals); }
		static Result<void> NormalsHelperInterface_CalculateShadingNormalsAveragedSSE(NORMALS_STYLE style, const Block<const Vector4d32>& points, const Block<const SimplePolygon>& polygons, Int pointCount, const Block<const Vector4d32>& polygonNormals, Block<Vector4d32>& shadingNormals) { return S::CalculateShadingNormalsAveragedSSE(style, points, polygons, pointCount, polygonNormals, shadingNormals); }
		static Result<void> NormalsHelperInterface_CalculateShadingNormalsSSE(NORMALS_STYLE style, const Block<const Vector4d32>& points, const Block<const SimplePolygon>& polygons, Int pointCount, const Block<const Vector4d32>& polygonNormals, Float32 angle, const Block<const UChar>& shadingBreaks, Block<Vector4d32>& shadingNormals) { return S::CalculateShadingNormalsSSE(style, points, polygons, pointCount, polygonNormals, angle, shadingBreaks, shadingNormals); }
#endif
		static Result<void> NormalsHelperInterface_CalculatePolygonNormals(const Block<const Vector>& points, const Block<const SimplePolygon>& polygons, Bool normalized, Block<Vector32>& polygonNormals) { return S::CalculatePolygonNormals(points, polygons, normalized, polygonNormals); }
		static Result<void> NormalsHelperInterface_CalculatePolygonNormals_1(const Block<const Vector>& points, const Block<const SimplePolygon>& polygons, Bool normalized, Block<Vector>& polygonNormals) { return S::CalculatePolygonNormals(points, polygons, normalized, polygonNormals); }
		static Result<void> NormalsHelperInterface_CalculatePolygonNormals_2(const Block<const Vector32>& points, const Block<const SimplePolygon>& polygons, Bool normalized, Block<Vector32>& polygonNormals) { return S::CalculatePolygonNormals(points, polygons, normalized, polygonNormals); }
		static Result<void> NormalsHelperInterface_CalculatePointNormalsAveraged(NORMALS_STYLE style, const Block<const Vector>& points, const Block<const SimplePolygon>& polygons, const Block<const Vector32>& polygonNormals, Block<Vector32>& pointNormals) { return S::CalculatePointNormalsAveraged(style, points, polygons, polygonNormals, pointNormals); }
		static Result<void> NormalsHelperInterface_CalculateShadingNormalsAveraged(NORMALS_STYLE style, const Block<const Vector>& points, const Block<const SimplePolygon>& polygons, const Block<const Vector32>& polygonNormals, Block<Vector32>& shadingNormals) { return S::CalculateShadingNormalsAveraged(style, points, polygons, polygonNormals, shadingNormals); }
		static Result<void> NormalsHelperInterface_CalculateShadingNormals(NORMALS_STYLE style, const Block<const Vector>& points, const Block<const SimplePolygon>& polygons, const Block<const Vector32>& polygonNormals, Float32 angle, const Block<const UChar>& shadingBreaks, Block<Vector32>& shadingNormals) { return S::CalculateShadingNormals(style, points, polygons, polygonNormals, angle, shadingBreaks, shadingNormals); }
	};

};
#if 0
MAXON_ATTRIBUTE_FORCE_INLINE auto NormalsHelperInterface::CalculatePolygonNormalsSSE(const Block<const Vector4d32>& points, const Block<const SimplePolygon>& polygons, Bool normalized, Block<Vector4d32>& polygonNormals) -> Result<void>
{
	return MTable::_instance.NormalsHelperInterface_CalculatePolygonNormalsSSE(points, polygons, normalized, polygonNormals);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NormalsHelperInterface::CalculatePointNormalsAveragedSSE(NORMALS_STYLE style, const Block<const Vector4d32>& points, const Block<const SimplePolygon>& polygons, Int pointCount, const Block<const Vector4d32>& polygonNormals, Block<Vector4d32>& pointNormals) -> Result<void>
{
	return MTable::_instance.NormalsHelperInterface_CalculatePointNormalsAveragedSSE(style, points, polygons, pointCount, polygonNormals, pointNormals);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NormalsHelperInterface::CalculateShadingNormalsAveragedSSE(NORMALS_STYLE style, const Block<const Vector4d32>& points, const Block<const SimplePolygon>& polygons, Int pointCount, const Block<const Vector4d32>& polygonNormals, Block<Vector4d32>& shadingNormals) -> Result<void>
{
	return MTable::_instance.NormalsHelperInterface_CalculateShadingNormalsAveragedSSE(style, points, polygons, pointCount, polygonNormals, shadingNormals);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NormalsHelperInterface::CalculateShadingNormalsSSE(NORMALS_STYLE style, const Block<const Vector4d32>& points, const Block<const SimplePolygon>& polygons, Int pointCount, const Block<const Vector4d32>& polygonNormals, Float32 angle, const Block<const UChar>& shadingBreaks, Block<Vector4d32>& shadingNormals) -> Result<void>
{
	return MTable::_instance.NormalsHelperInterface_CalculateShadingNormalsSSE(style, points, polygons, pointCount, polygonNormals, angle, shadingBreaks, shadingNormals);
}
#endif
MAXON_ATTRIBUTE_FORCE_INLINE auto NormalsHelperInterface::CalculatePolygonNormals(const Block<const Vector>& points, const Block<const SimplePolygon>& polygons, Bool normalized, Block<Vector32>& polygonNormals) -> Result<void>
{
	return MTable::_instance.NormalsHelperInterface_CalculatePolygonNormals(points, polygons, normalized, polygonNormals);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NormalsHelperInterface::CalculatePolygonNormals(const Block<const Vector>& points, const Block<const SimplePolygon>& polygons, Bool normalized, Block<Vector>& polygonNormals) -> Result<void>
{
	return MTable::_instance.NormalsHelperInterface_CalculatePolygonNormals_1(points, polygons, normalized, polygonNormals);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NormalsHelperInterface::CalculatePolygonNormals(const Block<const Vector32>& points, const Block<const SimplePolygon>& polygons, Bool normalized, Block<Vector32>& polygonNormals) -> Result<void>
{
	return MTable::_instance.NormalsHelperInterface_CalculatePolygonNormals_2(points, polygons, normalized, polygonNormals);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NormalsHelperInterface::CalculatePointNormalsAveraged(NORMALS_STYLE style, const Block<const Vector>& points, const Block<const SimplePolygon>& polygons, const Block<const Vector32>& polygonNormals, Block<Vector32>& pointNormals) -> Result<void>
{
	return MTable::_instance.NormalsHelperInterface_CalculatePointNormalsAveraged(style, points, polygons, polygonNormals, pointNormals);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NormalsHelperInterface::CalculateShadingNormalsAveraged(NORMALS_STYLE style, const Block<const Vector>& points, const Block<const SimplePolygon>& polygons, const Block<const Vector32>& polygonNormals, Block<Vector32>& shadingNormals) -> Result<void>
{
	return MTable::_instance.NormalsHelperInterface_CalculateShadingNormalsAveraged(style, points, polygons, polygonNormals, shadingNormals);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NormalsHelperInterface::CalculateShadingNormals(NORMALS_STYLE style, const Block<const Vector>& points, const Block<const SimplePolygon>& polygons, const Block<const Vector32>& polygonNormals, Float32 angle, const Block<const UChar>& shadingBreaks, Block<Vector32>& shadingNormals) -> Result<void>
{
	return MTable::_instance.NormalsHelperInterface_CalculateShadingNormals(style, points, polygons, polygonNormals, angle, shadingBreaks, shadingNormals);
}

#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_normalshelper)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_NormalsHelper_NormalsHelperInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_NormalsHelper_NormalsHelperInterface() { new (s_ui_maxon_NormalsHelper_NormalsHelperInterface) maxon::EntityUse(NormalsHelperInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/normalshelper.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_NormalsHelper_NormalsHelperInterface(NormalsHelperInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/normalshelper.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif


#if 1
namespace maxon
{
	namespace NormalsHelper
	{
		namespace enum30
		{
			enum class NORMALS_STYLE
				{
					UNIFORM,              ///< uniform shading
					ANGLE_WEIGHTED,       ///< angle weighted shading
					AREA_WEIGHTED,        ///< area weighted shading
					ANGLE_AREA_WEIGHTED,  ///< angle and area weighted shading
					SQUARE_AREA_WEIGHTED  ///< shading weighted by the square of the area. Produces more uniform results, but not fully scale invariant.
				} ;
			static const maxon::UInt64 NORMALS_STYLE_values[] = {maxon::UInt64(enum30::NORMALS_STYLE::UNIFORM), maxon::UInt64(enum30::NORMALS_STYLE::ANGLE_WEIGHTED), maxon::UInt64(enum30::NORMALS_STYLE::AREA_WEIGHTED), maxon::UInt64(enum30::NORMALS_STYLE::ANGLE_AREA_WEIGHTED), maxon::UInt64(enum30::NORMALS_STYLE::SQUARE_AREA_WEIGHTED)};
			static const maxon::EnumInfo NORMALS_STYLE_info{"NORMALS_STYLE", SIZEOF(NORMALS_STYLE), false, "UNIFORM\0ANGLE_WEIGHTED\0AREA_WEIGHTED\0ANGLE_AREA_WEIGHTED\0SQUARE_AREA_WEIGHTED\0", NORMALS_STYLE_values, std::extent<decltype(NORMALS_STYLE_values)>::value};
		}
		const maxon::EnumInfo& PrivateGetEnumInfo_NORMALS_STYLE30(){ return enum30::NORMALS_STYLE_info; }
#if 0
#endif
		const maxon::Char* const NormalsHelperInterface::MTable::_ids = 
#if 0
		"CalculatePolygonNormalsSSE@c5cebbaff5632455\0" // Result<void> CalculatePolygonNormalsSSE(const Block<const Vector4d32>& points, const Block<const SimplePolygon>& polygons, Bool normalized, Block<Vector4d32>& polygonNormals)
		"CalculatePointNormalsAveragedSSE@b2ad83853b39eea9\0" // Result<void> CalculatePointNormalsAveragedSSE(NORMALS_STYLE style, const Block<const Vector4d32>& points, const Block<const SimplePolygon>& polygons, Int pointCount, const Block<const Vector4d32>& polygonNormals, Block<Vector4d32>& pointNormals)
		"CalculateShadingNormalsAveragedSSE@b2ad83853b39eea9\0" // Result<void> CalculateShadingNormalsAveragedSSE(NORMALS_STYLE style, const Block<const Vector4d32>& points, const Block<const SimplePolygon>& polygons, Int pointCount, const Block<const Vector4d32>& polygonNormals, Block<Vector4d32>& shadingNormals)
		"CalculateShadingNormalsSSE@a597e7fb2afd0bb4\0" // Result<void> CalculateShadingNormalsSSE(NORMALS_STYLE style, const Block<const Vector4d32>& points, const Block<const SimplePolygon>& polygons, Int pointCount, const Block<const Vector4d32>& polygonNormals, Float32 angle, const Block<const UChar>& shadingBreaks, Block<Vector4d32>& shadingNormals)
#endif
		"CalculatePolygonNormals@dd78cfd07e0f986e\0" // Result<void> CalculatePolygonNormals(const Block<const Vector>& points, const Block<const SimplePolygon>& polygons, Bool normalized, Block<Vector32>& polygonNormals)
		"CalculatePolygonNormals@ace95b98dfbd924d\0" // Result<void> CalculatePolygonNormals(const Block<const Vector>& points, const Block<const SimplePolygon>& polygons, Bool normalized, Block<Vector>& polygonNormals)
		"CalculatePolygonNormals@7351f0485e9c86c5\0" // Result<void> CalculatePolygonNormals(const Block<const Vector32>& points, const Block<const SimplePolygon>& polygons, Bool normalized, Block<Vector32>& polygonNormals)
		"CalculatePointNormalsAveraged@1f4f02beba0f912d\0" // Result<void> CalculatePointNormalsAveraged(NORMALS_STYLE style, const Block<const Vector>& points, const Block<const SimplePolygon>& polygons, const Block<const Vector32>& polygonNormals, Block<Vector32>& pointNormals)
		"CalculateShadingNormalsAveraged@1f4f02beba0f912d\0" // Result<void> CalculateShadingNormalsAveraged(NORMALS_STYLE style, const Block<const Vector>& points, const Block<const SimplePolygon>& polygons, const Block<const Vector32>& polygonNormals, Block<Vector32>& shadingNormals)
		"CalculateShadingNormals@b148043befac4358\0" // Result<void> CalculateShadingNormals(NORMALS_STYLE style, const Block<const Vector>& points, const Block<const SimplePolygon>& polygons, const Block<const Vector32>& polygonNormals, Float32 angle, const Block<const UChar>& shadingBreaks, Block<Vector32>& shadingNormals)
		"";
		MAXON_WARNING_PUSH
		MAXON_WARNING_DISABLE_DEPRECATED
		class NormalsHelperInterface::Hxx2::Unresolved : public NormalsHelperInterface
		{
		public:
			static const Unresolved* Get(const NormalsHelperInterface* o) { return (const Unresolved*) o; }
			static Unresolved* Get(NormalsHelperInterface* o) { return (Unresolved*) o; }
#if 0
			static Result<void> CalculatePolygonNormalsSSE(const Block<const Vector4d32>& points, const Block<const SimplePolygon>& polygons, Bool normalized, Block<Vector4d32>& polygonNormals) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return NormalsHelperInterface::CalculatePolygonNormalsSSE(points, polygons, normalized, polygonNormals); return HXXRET1(UNRESOLVED);}
			static Result<void> CalculatePointNormalsAveragedSSE(NORMALS_STYLE style, const Block<const Vector4d32>& points, const Block<const SimplePolygon>& polygons, Int pointCount, const Block<const Vector4d32>& polygonNormals, Block<Vector4d32>& pointNormals) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return NormalsHelperInterface::CalculatePointNormalsAveragedSSE(style, points, polygons, pointCount, polygonNormals, pointNormals); return HXXRET1(UNRESOLVED);}
			static Result<void> CalculateShadingNormalsAveragedSSE(NORMALS_STYLE style, const Block<const Vector4d32>& points, const Block<const SimplePolygon>& polygons, Int pointCount, const Block<const Vector4d32>& polygonNormals, Block<Vector4d32>& shadingNormals) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return NormalsHelperInterface::CalculateShadingNormalsAveragedSSE(style, points, polygons, pointCount, polygonNormals, shadingNormals); return HXXRET1(UNRESOLVED);}
			static Result<void> CalculateShadingNormalsSSE(NORMALS_STYLE style, const Block<const Vector4d32>& points, const Block<const SimplePolygon>& polygons, Int pointCount, const Block<const Vector4d32>& polygonNormals, Float32 angle, const Block<const UChar>& shadingBreaks, Block<Vector4d32>& shadingNormals) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return NormalsHelperInterface::CalculateShadingNormalsSSE(style, points, polygons, pointCount, polygonNormals, angle, shadingBreaks, shadingNormals); return HXXRET1(UNRESOLVED);}
#endif
			static Result<void> CalculatePolygonNormals(const Block<const Vector>& points, const Block<const SimplePolygon>& polygons, Bool normalized, Block<Vector32>& polygonNormals) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return NormalsHelperInterface::CalculatePolygonNormals(points, polygons, normalized, polygonNormals); return HXXRET1(UNRESOLVED);}
			static Result<void> CalculatePolygonNormals(const Block<const Vector>& points, const Block<const SimplePolygon>& polygons, Bool normalized, Block<Vector>& polygonNormals) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return NormalsHelperInterface::CalculatePolygonNormals(points, polygons, normalized, polygonNormals); return HXXRET1(UNRESOLVED);}
			static Result<void> CalculatePolygonNormals(const Block<const Vector32>& points, const Block<const SimplePolygon>& polygons, Bool normalized, Block<Vector32>& polygonNormals) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return NormalsHelperInterface::CalculatePolygonNormals(points, polygons, normalized, polygonNormals); return HXXRET1(UNRESOLVED);}
			static Result<void> CalculatePointNormalsAveraged(NORMALS_STYLE style, const Block<const Vector>& points, const Block<const SimplePolygon>& polygons, const Block<const Vector32>& polygonNormals, Block<Vector32>& pointNormals) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return NormalsHelperInterface::CalculatePointNormalsAveraged(style, points, polygons, polygonNormals, pointNormals); return HXXRET1(UNRESOLVED);}
			static Result<void> CalculateShadingNormalsAveraged(NORMALS_STYLE style, const Block<const Vector>& points, const Block<const SimplePolygon>& polygons, const Block<const Vector32>& polygonNormals, Block<Vector32>& shadingNormals) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return NormalsHelperInterface::CalculateShadingNormalsAveraged(style, points, polygons, polygonNormals, shadingNormals); return HXXRET1(UNRESOLVED);}
			static Result<void> CalculateShadingNormals(NORMALS_STYLE style, const Block<const Vector>& points, const Block<const SimplePolygon>& polygons, const Block<const Vector32>& polygonNormals, Float32 angle, const Block<const UChar>& shadingBreaks, Block<Vector32>& shadingNormals) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return NormalsHelperInterface::CalculateShadingNormals(style, points, polygons, polygonNormals, angle, shadingBreaks, shadingNormals); return HXXRET1(UNRESOLVED);}
		};
		MAXON_WARNING_POP
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		const maxon::UNRESOLVED_RETURN_TYPE NormalsHelperInterface::MTable::_returnTypes[] = 
		{
#if 0
			maxon::details::UnresolvedReturnType<Result<void>>::value,
			maxon::details::UnresolvedReturnType<Result<void>>::value,
			maxon::details::UnresolvedReturnType<Result<void>>::value,
			maxon::details::UnresolvedReturnType<Result<void>>::value,
#endif
			maxon::details::UnresolvedReturnType<Result<void>>::value,
			maxon::details::UnresolvedReturnType<Result<void>>::value,
			maxon::details::UnresolvedReturnType<Result<void>>::value,
			maxon::details::UnresolvedReturnType<Result<void>>::value,
			maxon::details::UnresolvedReturnType<Result<void>>::value,
			maxon::details::UnresolvedReturnType<Result<void>>::value,
			maxon::UNRESOLVED_RETURN_TYPE::OTHER
		};
	#endif
		maxon::Bool NormalsHelperInterface::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
		{
#if 0
			#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
			if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->NormalsHelperInterface_CalculatePolygonNormalsSSE = PRIVATE_MAXON_MF_CAST(decltype(NormalsHelperInterface_CalculatePolygonNormalsSSE), &Hxx2::Wrapper<Hxx2::Unresolved>::NormalsHelperInterface_CalculatePolygonNormalsSSE);
			#else
			tbl->NormalsHelperInterface_CalculatePolygonNormalsSSE = PRIVATE_MAXON_MF_CAST(decltype(NormalsHelperInterface_CalculatePolygonNormalsSSE), &Hxx2::Wrapper<Hxx2::Unresolved>::NormalsHelperInterface_CalculatePolygonNormalsSSE);
			#endif
			#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
			if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->NormalsHelperInterface_CalculatePointNormalsAveragedSSE = PRIVATE_MAXON_MF_CAST(decltype(NormalsHelperInterface_CalculatePointNormalsAveragedSSE), &Hxx2::Wrapper<Hxx2::Unresolved>::NormalsHelperInterface_CalculatePointNormalsAveragedSSE);
			#else
			tbl->NormalsHelperInterface_CalculatePointNormalsAveragedSSE = PRIVATE_MAXON_MF_CAST(decltype(NormalsHelperInterface_CalculatePointNormalsAveragedSSE), &Hxx2::Wrapper<Hxx2::Unresolved>::NormalsHelperInterface_CalculatePointNormalsAveragedSSE);
			#endif
			#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
			if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->NormalsHelperInterface_CalculateShadingNormalsAveragedSSE = PRIVATE_MAXON_MF_CAST(decltype(NormalsHelperInterface_CalculateShadingNormalsAveragedSSE), &Hxx2::Wrapper<Hxx2::Unresolved>::NormalsHelperInterface_CalculateShadingNormalsAveragedSSE);
			#else
			tbl->NormalsHelperInterface_CalculateShadingNormalsAveragedSSE = PRIVATE_MAXON_MF_CAST(decltype(NormalsHelperInterface_CalculateShadingNormalsAveragedSSE), &Hxx2::Wrapper<Hxx2::Unresolved>::NormalsHelperInterface_CalculateShadingNormalsAveragedSSE);
			#endif
			#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
			if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->NormalsHelperInterface_CalculateShadingNormalsSSE = PRIVATE_MAXON_MF_CAST(decltype(NormalsHelperInterface_CalculateShadingNormalsSSE), &Hxx2::Wrapper<Hxx2::Unresolved>::NormalsHelperInterface_CalculateShadingNormalsSSE);
			#else
			tbl->NormalsHelperInterface_CalculateShadingNormalsSSE = PRIVATE_MAXON_MF_CAST(decltype(NormalsHelperInterface_CalculateShadingNormalsSSE), &Hxx2::Wrapper<Hxx2::Unresolved>::NormalsHelperInterface_CalculateShadingNormalsSSE);
			#endif
#endif
			#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
			if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->NormalsHelperInterface_CalculatePolygonNormals = PRIVATE_MAXON_MF_CAST(decltype(NormalsHelperInterface_CalculatePolygonNormals), &Hxx2::Wrapper<Hxx2::Unresolved>::NormalsHelperInterface_CalculatePolygonNormals);
			#else
			tbl->NormalsHelperInterface_CalculatePolygonNormals = PRIVATE_MAXON_MF_CAST(decltype(NormalsHelperInterface_CalculatePolygonNormals), &Hxx2::Wrapper<Hxx2::Unresolved>::NormalsHelperInterface_CalculatePolygonNormals);
			#endif
			#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
			if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->NormalsHelperInterface_CalculatePolygonNormals_1 = PRIVATE_MAXON_MF_CAST(decltype(NormalsHelperInterface_CalculatePolygonNormals_1), &Hxx2::Wrapper<Hxx2::Unresolved>::NormalsHelperInterface_CalculatePolygonNormals_1);
			#else
			tbl->NormalsHelperInterface_CalculatePolygonNormals_1 = PRIVATE_MAXON_MF_CAST(decltype(NormalsHelperInterface_CalculatePolygonNormals_1), &Hxx2::Wrapper<Hxx2::Unresolved>::NormalsHelperInterface_CalculatePolygonNormals_1);
			#endif
			#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
			if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->NormalsHelperInterface_CalculatePolygonNormals_2 = PRIVATE_MAXON_MF_CAST(decltype(NormalsHelperInterface_CalculatePolygonNormals_2), &Hxx2::Wrapper<Hxx2::Unresolved>::NormalsHelperInterface_CalculatePolygonNormals_2);
			#else
			tbl->NormalsHelperInterface_CalculatePolygonNormals_2 = PRIVATE_MAXON_MF_CAST(decltype(NormalsHelperInterface_CalculatePolygonNormals_2), &Hxx2::Wrapper<Hxx2::Unresolved>::NormalsHelperInterface_CalculatePolygonNormals_2);
			#endif
			#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
			if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->NormalsHelperInterface_CalculatePointNormalsAveraged = PRIVATE_MAXON_MF_CAST(decltype(NormalsHelperInterface_CalculatePointNormalsAveraged), &Hxx2::Wrapper<Hxx2::Unresolved>::NormalsHelperInterface_CalculatePointNormalsAveraged);
			#else
			tbl->NormalsHelperInterface_CalculatePointNormalsAveraged = PRIVATE_MAXON_MF_CAST(decltype(NormalsHelperInterface_CalculatePointNormalsAveraged), &Hxx2::Wrapper<Hxx2::Unresolved>::NormalsHelperInterface_CalculatePointNormalsAveraged);
			#endif
			#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
			if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->NormalsHelperInterface_CalculateShadingNormalsAveraged = PRIVATE_MAXON_MF_CAST(decltype(NormalsHelperInterface_CalculateShadingNormalsAveraged), &Hxx2::Wrapper<Hxx2::Unresolved>::NormalsHelperInterface_CalculateShadingNormalsAveraged);
			#else
			tbl->NormalsHelperInterface_CalculateShadingNormalsAveraged = PRIVATE_MAXON_MF_CAST(decltype(NormalsHelperInterface_CalculateShadingNormalsAveraged), &Hxx2::Wrapper<Hxx2::Unresolved>::NormalsHelperInterface_CalculateShadingNormalsAveraged);
			#endif
			#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
			if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->NormalsHelperInterface_CalculateShadingNormals = PRIVATE_MAXON_MF_CAST(decltype(NormalsHelperInterface_CalculateShadingNormals), &Hxx2::Wrapper<Hxx2::Unresolved>::NormalsHelperInterface_CalculateShadingNormals);
			#else
			tbl->NormalsHelperInterface_CalculateShadingNormals = PRIVATE_MAXON_MF_CAST(decltype(NormalsHelperInterface_CalculateShadingNormals), &Hxx2::Wrapper<Hxx2::Unresolved>::NormalsHelperInterface_CalculateShadingNormals);
			#endif
		#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
			return assembler(&_interface, (const void**) tbl, _returnTypes, SIZEOF(MTable) / SIZEOF(void*));
		#else
			return true;
		#endif
		}
		MAXON_INTERFACE_REGISTER(NormalsHelperInterface, "net.maxon.geom.normalshelper", nullptr, maxon::EntityBase::FLAGS::NONE);
	}
}
#endif

#ifndef NORMALSHELPER_H__
#define NORMALSHELPER_H__

#include "maxon/simplemesh.h"
#include "maxon/vector.h"
#include "maxon/vector4d.h"

// IMPORTANT NOTE:
// i am not sure about SSE stuff, it seemed to be used in fvp, and that is what i based this implementation upon
// but in there, there seems to be a lot of conversion between vec3->vec4->vec3 (for to me no obvious reason)
// that should be checked, probably with Thomas, and if not required, should be removed. 

// i am also unsure whether the SSE version is that much faster anyways (due to auto vectorization by the compiler and stuff). 

namespace maxon
{

namespace NormalsHelper
{
	//----------------------------------------------------------------------------------------
	/// Style of the generated point/vertex normals. 
	//----------------------------------------------------------------------------------------
	enum class NORMALS_STYLE
	{
		UNIFORM,              ///< uniform shading
		ANGLE_WEIGHTED,       ///< angle weighted shading
		AREA_WEIGHTED,        ///< area weighted shading
		ANGLE_AREA_WEIGHTED,  ///< angle and area weighted shading
		SQUARE_AREA_WEIGHTED  ///< shading weighted by the square of the area. Produces more uniform results, but not fully scale invariant.
	} MAXON_ENUM_LIST(NORMALS_STYLE);

	//----------------------------------------------------------------------------------------
	/// Normal generation utilities for shading of meshes. 
	//----------------------------------------------------------------------------------------
	class NormalsHelperInterface
	{
		MAXON_INTERFACE_NONVIRTUAL(NormalsHelperInterface, MAXON_REFERENCE_STATIC, "net.maxon.geom.normalshelper");

	public:

#if 0
		//----------------------------------------------------------------------------------------
		/// Computes the polygon normals for the given polygons and points.
		/// If normalized is set to True, the output polygon normals will be normalized to range [0-1].
		/// Otherwise, the normals will be scaled with the polygon area. 
		/// If using the UNIFORM or ANGLE_WEIGHTED normals style, one should normalize the normals. 
		/// This version uses SSE.
		/// @param[in] points           Block containing the points of the mesh. 
		/// @param[in] polygons         Block containing the polygons of the mesh. For triangles, polygon.c == polygon.d
		/// @param[in] normalized       Whether the output normals should be normalized to [0-1] range. 
		/// @param[out] polygonNormals  The generated polygon normals. This block should be resized before, such that the size of the block equals the number of polygons.
		/// @return                     OK on success, otherwise error.
		//----------------------------------------------------------------------------------------
		static MAXON_METHOD Result<void> CalculatePolygonNormalsSSE(const Block<const Vector4d32>& points, const Block<const SimplePolygon>& polygons, Bool normalized, Block<Vector4d32>& polygonNormals);

		//----------------------------------------------------------------------------------------
		/// Computes the point normals (average normal of all adjacent polygons) using the style specified.
		/// Polygons will share the same normal for each point. This version does not take into consideration the shading break angle, or the shading break edges. 
		/// If style is set to UNIFORM or ANGLE_WEIGHTED, the given polygon normals should be normalized. 
		/// Note that ANGLE_WEIGHTED style can have a significant performance impact. 
		/// This version uses SSE.
		/// @param[in] style            The style of the normals to generate. 
		/// @param[in] points           Block containing the points of the mesh. 
		/// @param[in] polygons         Block containing the polygons of the mesh. For triangles, polygon.c == polygon.d
		/// @param[in] pointCount       The number of points in the mesh. No polygon in the polygons block should have a point index higher than this point count.
		/// @param[in] polygonNormals   The input array of polygon normals, size of which will correspond to the number of polygons. Depending on the style, the normals may or may not need to be normalized.
		/// @param[out] pointNormals    The generated point normals. The size of this block should correspond to the point count.
		/// @return                     OK on success, otherwise error.
		//----------------------------------------------------------------------------------------
		static MAXON_METHOD Result<void> CalculatePointNormalsAveragedSSE(NORMALS_STYLE style, const Block<const Vector4d32>& points, const Block<const SimplePolygon>& polygons, Int pointCount, const Block<const Vector4d32>& polygonNormals, Block<Vector4d32>& pointNormals);

		//----------------------------------------------------------------------------------------
		/// Computes the shading (per polygon vertex) normals
		/// Each polygon will have four resulting normals, one for each point in the polygon.
		/// Polygons will share the same normal for each point. This version does not take into consideration the shading break angle, or the shading break edges. 
		/// If style is set to UNIFORM or ANGLE_WEIGHTED, the given polygon normals should be normalized. 
		/// Note that ANGLE_WEIGHTED style can have a significant performance impact. 
		/// This version uses SSE.
		/// @param[in] style            The style of the normals to generate. 
		/// @param[in] points           Block containing the points of the mesh. 
		/// @param[in] polygons         Block containing the polygons of the mesh. For triangles, polygon.c == polygon.d
		/// @param[in] pointCount       The number of points in the mesh. No polygon in the polygons block should have a point index higher than this point count.
		/// @param[in] polygonNormals   The input array of polygon normals, size of which will correspond to the number of polygons. Depending on the style, the normals may or may not need to be normalized.
		/// @param[out] shadingNormals  The generated shading normals. The size of this block should correspond to 4 * polygonCount.
		/// @return                     OK on success, otherwise error.
		//----------------------------------------------------------------------------------------
		static MAXON_METHOD Result<void> CalculateShadingNormalsAveragedSSE(NORMALS_STYLE style, const Block<const Vector4d32>& points, const Block<const SimplePolygon>& polygons, Int pointCount, const Block<const Vector4d32>& polygonNormals, Block<Vector4d32>& shadingNormals);

		//----------------------------------------------------------------------------------------
		/// Computes the shading (per polygon vertex) normals
		/// Each polygon will have four resulting normals, one for each point in the polygon.
		/// This version takes into consideration the shading break angle, as well as the shading break edges.
		/// If style is set to UNIFORM or ANGLE_WEIGHTED, the given polygon normals should be normalized. 
		/// Note that ANGLE_WEIGHTED style can have a significant performance impact. 
		/// This version uses SSE.
		/// @param[in] style            The style of the normals to generate. 
		/// @param[in] points           Block containing the points of the mesh. 
		/// @param[in] polygons         Block containing the polygons of the mesh. For triangles, polygon.c == polygon.d
		/// @param[in] pointCount       The number of points in the mesh. No polygon in the polygons block should have a point index higher than this point count.
		/// @param[in] polygonNormals   The input array of polygon normals, size of which will correspond to the number of polygons. Depending on the style, the normals may or may not need to be normalized.
		/// @param[in] angle            The angle threshold at which to break the shading. 
		/// @param[in] shadingBreaks    The Compacted array which denotes the shading break edges. for each polygon, the individual bits correspond to the individual edges of that polygon. An empty block can be given, to avoid checking the edges. 
		/// @param[out] shadingNormals  The generated shading normals. The size of this block should correspond to 4 * polygonCount.
		/// @return                     OK on success, otherwise error.
		//----------------------------------------------------------------------------------------
		static MAXON_METHOD Result<void> CalculateShadingNormalsSSE(NORMALS_STYLE style, const Block<const Vector4d32>& points, const Block<const SimplePolygon>& polygons, Int pointCount, const Block<const Vector4d32>& polygonNormals, Float32 angle, const Block<const UChar>& shadingBreaks, Block<Vector4d32>& shadingNormals);
#endif

		//----------------------------------------------------------------------------------------
		/// Computes the polygon normals for the given polygons and points.
		/// If normalized is set to True, the output polygon normals will be normalized to range [0-1].
		/// Otherwise, the normals will be scaled with the polygon area. 
		/// If using the UNIFORM or ANGLE_WEIGHTED normals style, one should normalize the normals. 
		/// @param[in] points           Block containing the points of the mesh. 
		/// @param[in] polygons         Block containing the polygons of the mesh. For triangles, polygon.c == polygon.d
		/// @param[in] normalized       Whether the output normals should be normalized to [0-1] range. 
		/// @param[out] polygonNormals  The generated polygon normals. This block should be resized before, such that the size of the block equals the number of polygons.
		/// @return                     OK on success, otherwise error.
		//----------------------------------------------------------------------------------------
		static MAXON_METHOD Result<void> CalculatePolygonNormals(const Block<const Vector>& points, const Block<const SimplePolygon>& polygons, Bool normalized, Block<Vector32>& polygonNormals);

		//----------------------------------------------------------------------------------------
		/// Computes the polygon normals for the given polygons and points.
		/// If normalized is set to True, the output polygon normals will be normalized to range [0-1].
		/// Otherwise, the normals will be scaled with the polygon area. 
		/// If using the UNIFORM or ANGLE_WEIGHTED normals style, one should normalize the normals. 
		/// @param[in] points           Block containing the points of the mesh. 
		/// @param[in] polygons         Block containing the polygons of the mesh. For triangles, polygon.c == polygon.d
		/// @param[in] normalized       Whether the output normals should be normalized to [0-1] range. 
		/// @param[out] polygonNormals  The generated polygon normals. This block should be resized before, such that the size of the block equals the number of polygons.
		/// @return                     OK on success, otherwise error.
		//----------------------------------------------------------------------------------------
		static MAXON_METHOD Result<void> CalculatePolygonNormals(const Block<const Vector>& points, const Block<const SimplePolygon>& polygons, Bool normalized, Block<Vector>& polygonNormals);

		//----------------------------------------------------------------------------------------
		/// Computes the polygon normals for the given polygons and points.
		/// If normalized is set to True, the output polygon normals will be normalized to range [0-1].
		/// Otherwise, the normals will be scaled with the polygon area. 
		/// If using the UNIFORM or ANGLE_WEIGHTED normals style, one should normalize the normals. 
		/// @param[in] points           Block containing the points of the mesh. 
		/// @param[in] polygons         Block containing the polygons of the mesh. For triangles, polygon.c == polygon.d
		/// @param[in] normalized       Whether the output normals should be normalized to [0-1] range. 
		/// @param[out] polygonNormals  The generated polygon normals. This block should be resized before, such that the size of the block equals the number of polygons.
		/// @return                     OK on success, otherwise error.
		//----------------------------------------------------------------------------------------
		static MAXON_METHOD Result<void> CalculatePolygonNormals(const Block<const Vector32>& points, const Block<const SimplePolygon>& polygons, Bool normalized, Block<Vector32>& polygonNormals);

		//----------------------------------------------------------------------------------------
		/// Computes the point normals (average normal of all adjacent polygons) using the style specified.
		/// Polygons will share the same normal for each point. This version does not take into consideration the shading break angle, or the shading break edges. 
		/// If style is set to UNIFORM or ANGLE_WEIGHTED, the given polygon normals should be normalized. 
		/// Note that ANGLE_WEIGHTED style can have a significant performance impact. 
		/// @param[in] style            The style of the normals to generate. 
		/// @param[in] points           Block containing the points of the mesh. 
		/// @param[in] polygons         Block containing the polygons of the mesh. For triangles, polygon.c == polygon.d
		/// @param[in] polygonNormals   The input array of polygon normals, size of which will correspond to the number of polygons. Depending on the style, the normals may or may not need to be normalized.
		/// @param[out] pointNormals    The generated point normals. The size of this block should correspond to the point count.
		/// @return                     OK on success, otherwise error.
		//----------------------------------------------------------------------------------------
		static MAXON_METHOD Result<void> CalculatePointNormalsAveraged(NORMALS_STYLE style, const Block<const Vector>& points, const Block<const SimplePolygon>& polygons, const Block<const Vector32>& polygonNormals, Block<Vector32>& pointNormals);

		//----------------------------------------------------------------------------------------
		/// Computes the shading (per polygon vertex) normals
		/// Each polygon will have four resulting normals, one for each point in the polygon.
		/// Polygons will share the same normal for each point. This version does not take into consideration the shading break angle, or the shading break edges. 
		/// If style is set to UNIFORM or ANGLE_WEIGHTED, the given polygon normals should be normalized. 
		/// Note that ANGLE_WEIGHTED style can have a significant performance impact. 
		/// @param[in] style            The style of the normals to generate. 
		/// @param[in] points           Block containing the points of the mesh. 
		/// @param[in] polygons         Block containing the polygons of the mesh. For triangles, polygon.c == polygon.d
		/// @param[in] polygonNormals   The input array of polygon normals, size of which will correspond to the number of polygons. Depending on the style, the normals may or may not need to be normalized.
		/// @param[out] shadingNormals  The generated shading normals. The size of this block should correspond to 4 * polygonCount.
		/// @return                     OK on success, otherwise error.
		//----------------------------------------------------------------------------------------
		static MAXON_METHOD Result<void> CalculateShadingNormalsAveraged(NORMALS_STYLE style, const Block<const Vector>& points, const Block<const SimplePolygon>& polygons, const Block<const Vector32>& polygonNormals, Block<Vector32>& shadingNormals);

		//----------------------------------------------------------------------------------------
		/// Computes the shading (per polygon vertex) normals
		/// Each polygon will have four resulting normals, one for each point in the polygon.
		/// This version takes into consideration the shading break angle, as well as the shading break edges.
		/// If style is set to UNIFORM or ANGLE_WEIGHTED, the given polygon normals should be normalized. 
		/// Note that ANGLE_WEIGHTED style can have a significant performance impact. 
		/// @param[in] style            The style of the normals to generate. 
		/// @param[in] points           Block containing the points of the mesh. 
		/// @param[in] polygons         Block containing the polygons of the mesh. For triangles, polygon.c == polygon.d
		/// @param[in] polygonNormals   The input array of polygon normals, size of which will correspond to the number of polygons. Depending on the style, the normals may or may not need to be normalized.
		/// @param[in] angle            The angle threshold at which to break the shading. 
		/// @param[in] shadingBreaks    The Compacted array which denotes the shading break edges. for each polygon, the individual bits correspond to the individual edges of that polygon. An empty block can be given, to avoid checking the edges. 
		/// @param[out] shadingNormals  The generated shading normals. The size of this block should correspond to 4 * polygonCount.
		/// @return                     OK on success, otherwise error.
		//----------------------------------------------------------------------------------------
		static MAXON_METHOD Result<void> CalculateShadingNormals(NORMALS_STYLE style, const Block<const Vector>& points, const Block<const SimplePolygon>& polygons, const Block<const Vector32>& polygonNormals, Float32 angle, const Block<const UChar>& shadingBreaks, Block<Vector32>& shadingNormals);
	};


#include "normalshelper1.hxx"
#include "normalshelper2.hxx"

} // namespace NormalsHelper

} // namespace maxon

#endif // NORMALSHELPER_H__

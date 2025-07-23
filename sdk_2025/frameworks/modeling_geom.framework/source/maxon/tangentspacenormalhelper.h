#ifndef TANGENTSPACENORMALHELPER_H__
#define TANGENTSPACENORMALHELPER_H__

#include "maxon/simplemesh.h"
#include "maxon/parallelfor.h"
#include "maxon/matrix.h"

namespace maxon
{

namespace TangentSpaceNormalHelper
{
	//----------------------------------------------------------------------------------------
	/// Computes the normal of a triangle from the three points. 
	/// @param[in] prevPoint           Previous triangle point.
	/// @param[in] currPoint           Corner triangle point. 
	/// @param[in] nextPoint           Next triangle point. 
	/// @return                        The normal vector for the triangle.
	//----------------------------------------------------------------------------------------
	Vector ComputeNormal(const Vector& prevPoint, const Vector& currPoint, const Vector& nextPoint);

	//----------------------------------------------------------------------------------------
	/// Computes the tangent of a triangle from the three points. 
	/// @param[in] prevPoint           Previous triangle point.
	/// @param[in] currPoint           Corner triangle point. 
	/// @param[in] nextPoint           Next triangle point. 
	/// @return                        The tangent vector for the triangle.
	//----------------------------------------------------------------------------------------
	Vector ComputeTangent(const Vector& prevPoint, const Vector& currPoint, const Vector& nextPoint);

	//----------------------------------------------------------------------------------------
	/// Computes the tangent space normal from the object space normal in the space of the given triangle points. 
	/// @param[in] prevPoint           Previous triangle point.
	/// @param[in] currPoint           Corner triangle point. 
	/// @param[in] nextPoint           Next triangle point. 
	/// @param[in] objectSpaceNormal   The normal in object space.
	/// @return                        The normal vector in tangent space. 
	//----------------------------------------------------------------------------------------
	Vector ConvertToTangentSpaceNormal(const Vector& prevPoint, const Vector& currPoint, const Vector& nextPoint, const Vector& objectSpaceNormal);

	//----------------------------------------------------------------------------------------
	/// Computes the object space normal from the tangent space normal in the space of the given triangle points. 
	/// @param[in] prevPoint           Previous triangle point.
	/// @param[in] currPoint           Corner triangle point. 
	/// @param[in] nextPoint           Next triangle point. 
	/// @param[in] tangentSpaceNormal  The normal in tangent space.
	/// @return                        The normal vector in object space. 
	//----------------------------------------------------------------------------------------
	Vector ConvertToObjectSpaceNormal(const Vector& prevPoint, const Vector& currPoint, const Vector& nextPoint, const Vector& tangentSpaceNormal);

	//----------------------------------------------------------------------------------------
	/// Computes the normal of the given polygon, at the corner specified by the given index. 
	/// The normal is computed in object space, as the cross product of the incoming and outgoing edges. 
	/// @param[in] points              The points of the polygon object. 
	/// @param[in] polygonPoints       The vertex indices which form the current polygon. The list should not contain duplicate entries. In case of a triangle, three vertices should be provided. 
	/// @param[in] index               The index which specifies the corner of the polygon, for which the normal will be calculated. always in range [0, polygonPoints.GetCount() - 1]
	/// @return                        The normal for the specified corner of the given polygon in object space. Normalized to length == 1.0_f. 
	//----------------------------------------------------------------------------------------
	Vector ComputeNormal(const Block<const Vector>& points, const Block<const Int32> polygonPoints, Int32 index);

	//----------------------------------------------------------------------------------------
	/// Computes the tangent of the given polygon, at the corner specified by the given index. 
	/// The tangent is computed as a vector which points from the point specified by the index, to a point which is defined as the sum of vectors, defined by the incoming and outgoing edges into this vertex. 
	/// By definition, the tangent computed by this function will be perpendicular to the normal computed by ComputeNormal(). 
	/// @param[in] points              The points of the polygon object. 
	/// @param[in] polygonPoints       The vertex indices which form the current polygon. The list should not contain duplicate entries. In case of a triangle, three vertices should be provided. 
	/// @param[in] index               The index which specifies the corner of the polygon, for which the normal will be calculated. always in range [0, polygonPoints.GetCount() - 1]
	/// @return                        The tangent for the specified corner of the given polygon in object space. Normalized to length == 1.0_f. 
	//----------------------------------------------------------------------------------------
	Vector ComputeTangent(const Block<const Vector>& points, const Block<const Int32> polygonPoints, Int32 index);

	//----------------------------------------------------------------------------------------
	/// The bitangent is a vector that is perpendicular both to the tangent, computed by ComputeTangent() and the normal, computed by ComputeNormal()
	/// Simply, it is a cross product of the normal and the tangent vector. 
	/// The three vectors(normal, tangent, binormal) will form the basis of a matrix used to convert the custom vertex normals from object space to tangent (local to polygon) space. 
	/// @param[in] normal              The computed normal for the corner of a polygon. Computed by ComputeNormal().
	/// @param[in] tangent             The computed tangent for the corner of a polygon. Computed by ComputeTangent(). 
	/// @return                        The bitangent for the specified corner of the given polygon in object space. Normalized to length == 1.0_f. 
	//----------------------------------------------------------------------------------------
	Vector ComputeBiTangent(const Vector& normal, const Vector& tangent);

	//----------------------------------------------------------------------------------------
	/// Converts the given object space custom vertex normal, to a tangent space normal, for the specified corner of the given polygon. 
	/// For the conversion, a matrix using the normal, tangent and binormal will be used. 
	/// @param[in] points              The points of the polygon object. 
	/// @param[in] polygonPoints       The vertex indices which form the current polygon. The list should not contain duplicate entries. In case of a triangle, three vertices should be provided. 
	/// @param[in] index               The index which specifies the corner of the polygon, for which the normal will be calculated. always in range [0, polygonPoints.GetCount() - 1]
	/// @param[in] objectSpaceNormal   The custom vertex normal (in object space) that should be converted to tangent space. 
	/// @return                        The custom normal vector, converted to tangent space. 
	//----------------------------------------------------------------------------------------
	Vector ConvertToTangentSpaceNormal(const Block<const Vector>& points, const Block<const Int32> polygonPoints, Int32 index, const Vector& objectSpaceNormal);

	//----------------------------------------------------------------------------------------
	/// Converts the given tangent space custom vertex normal, to an object space normal, for the specified corner of the given polygon. 
	/// For the conversion, a matrix using the normal, tangent and binormal will be used. 
	/// @param[in] points              The points of the polygon object. 
	/// @param[in] polygonPoints       The vertex indices which form the current polygon. The list should not contain duplicate entries. In case of a triangle, three vertices should be provided. 
	/// @param[in] index               The index which specifies the corner of the polygon, for which the normal will be calculated. always in range [0, polygonPoints.GetCount() - 1]
	/// @param[in] tangentSpaceNormal  The custom vertex normal (in tangent space) that should be converted to object space. 
	/// @return                        The custom normal vector, converted to object space. 
	//----------------------------------------------------------------------------------------
	Vector ConvertToObjectSpaceNormal(const Block<const Vector>& points, const Block<const Int32> polygonPoints, Int32 index, const Vector& tangentSpaceNormal);

	//----------------------------------------------------------------------------------------
	/// A simple structure to store a single vertex cycle and the data required to reconstruct the correct normals, when converting to and from tangent space representations.
	/// In the usual case (without disjoined data, triangualted mesh) there will be a single vertex cycle around a vertex, with 6 polygons. 
	/// neighbor information (for each polygon, at which index is the vertex in question present) is stored. 
	//----------------------------------------------------------------------------------------
	struct NormalVertexCycle
	{
		BufferedBaseArray<Int32, 6> _polygons;            ///< Specifies the polygons that are a part of this cycle. 
		BufferedBaseArray<Int32, 6> _vertexIdxInPolygon;  ///< for each polygon in this cycle, specifies at which position in the polygon outline [0-3] is the vertex found

		Result<void> CopyFrom(const NormalVertexCycle& src);
	};

	//----------------------------------------------------------------------------------------
	/// A structure that stores all vertex cycles around a vertex. 
	/// Since in the most common case, the data will not be disjoined (all polygons adjacent to a vertex will share the same vertex normal) a BufferedBaseArray with a size of 1 is used. 
	/// In the cases where the normals are split, the structure will contain more than one vertex cycle. 
	//----------------------------------------------------------------------------------------
	class NormalVertexCycles
	{

	public:
		BufferedBaseArray<NormalVertexCycle, 1> _cycles;  ///< A list of vertex cycles around the vertex. Each entry contains the polygons, normal per polygon, and the index of the vertex in the outline of each polygon.
		Int32 _vertex;                                    ///< the vertex that owns these vertex cycles. 

		Result<void> CopyFrom(const NormalVertexCycles& src);

		//----------------------------------------------------------------------------------------
		/// Initializes the vertex cycles for this vertex. 
		/// The vertex cycles are split if the difference between provided normals is greater than an Epsilon value. 
		/// In the case that all custom normals are aligned, a single vertex cycle will be created. 
		/// @param[in] vertex                  The vertex which will own the vertex cycles.  
		/// @param[in] pointPolys              The list of polygons that are adjacent to the given vertex. The list should not contain duplicate entries. 
		/// @param[in] normals                 For each polygon, stores the vertex normals. The normals will usually be in object space. normals.GetCount() = 4 * polygonCount.
		/// @param[in] vertexIdxInPolygon      For each polygon, specifies at which position in the outline is the given vertex located. Each value will be in range [0, 3]
		/// @return                            OK on success, otherwise error. 
		//----------------------------------------------------------------------------------------
		Result<void> Init(Int32 vertex, const Block<const Int32>& pointPolys, const Block<const Vector>& normals, const Block<const Int32>& vertexIdxInPolygon);

		//----------------------------------------------------------------------------------------
		/// Converts the stored custom vertex normal for the vertex cycles from object space to tangent space representation
		/// This should be called after ::Init() was called. 
		/// The points passed to this function should usually be the ones before any mesh modification occurred. 
		/// @param[in] points                  The 3D data for the points in the polygon object. 
		/// @param[in] polygons                The list of polygons in the object. each polygon is represented by four vertex indices. 
		/// @param[in] inNormals               The input normals in object space. inNormals.GetCount() = 4 * polygonCount
		/// @param[out] outNormals             The block that will hold the output normals (tangent space). outNormals.GetCount() = 4 * polygonCount. This should be stored and used later for conversion back to object space, once the mesh changes. 
		/// @return                            OK on success, otherwise error. 
		//----------------------------------------------------------------------------------------
    Result<void> ConvertDataToTangentSpace(const Block<const Vector>& points, const Block<const SimplePolygon>& polygons, const Block<const Vector>& inNormals, Block<Vector>& outNormals) const;

		//----------------------------------------------------------------------------------------
		/// Converts the stored custom vertex normal for the vertex cycles from tangent space to object space representation
		/// This should be called after ::ConvertDataToTangentSpace() was called. 
		/// The points passed to this function should usually be the after all mesh modifications are finished
		/// This should not be called if the modification altered the topology of the mesh/polygon object. (ie the order of points in a polygon changed, the number of points/polygons changed etc). 
		/// Note that after this is executed, the normals will not be averaged out, even if they belong to the same cycle. For that, call ::AverageOutVertexCycleNormals() afterwards. 
		/// @param[in] points                  The 3D data for the points in the polygon object. 
		/// @param[in] polygons                The list of polygons in the object. each polygon is represented by four vertex indices. 
		/// @param[in] inNormals               The normals in tangent space. inNormals.GetCount() = 4 * polygonCount
		/// @param[out] outNormals             The block that will hold the output normals (object space). outNormals.GetCount() = 4 * polygonCount. These should in general be written into the target object (eg. normal tag). 
		/// @return                            OK on success, otherwise error. 
		//----------------------------------------------------------------------------------------
    Result<void> ConvertDataToObjectSpace(const Block<const Vector>& points, const Block<const SimplePolygon>& polygons, const Block<const Vector>& inNormals, Block<Vector>& outNormals) const;

		//----------------------------------------------------------------------------------------
		/// Iterates over the vertex cycles, and for each vertex cycle, ensures that every custom normal value is aligned. 
		/// This will ensure that there will be no shading breaks at the positions where there was none to start with.
		/// This should be called after ::ConvertDataToObjectSpace() was called. 
		/// @param[in, out] normals            For each polygon, stores the vertex normals. The should be in object space. normals.GetCount() = 4 * polygonCount. This will average out the object space normals after conversion from tangent space to preserve smooths shading in vertex cycles.
		//----------------------------------------------------------------------------------------
		Result<void> AverageOutVertexCycleNormals(Block<Vector>& normals) const;

	};

	template <typename NEIGHBORTYPE>
	struct NeighborWrapper
	{
		template<typename FN>
		static Result<void> GetPointPolysFn(NEIGHBORTYPE& neighbor, Int32 pointIndex, const FN& fn)
		{
			return OK;
		};
	};

	//----------------------------------------------------------------------------------------
	/// A structure that for each vertex in the mesh, stores the vertex cycle and normal data required for conversion of normals to and from object and tangent space. 
	/// Since the normal tag present on the polygon object does not store topology and vertex cycle information (which polygon around a vertex share the same normal) 
	/// the cycles are determined by checking if the normals for the given polygons are aligned (within threshold). 
	//----------------------------------------------------------------------------------------
	class TangentSpaceNormalData
	{
	private:
		struct VertexCyclesParallelForContext : ParallelFor::BaseContext
		{
			BaseArray<Int32> vertexIdxInPolygons;
			BaseArray<Int32> polygonsAroundVertex;
		};

	public:
		BaseArray<NormalVertexCycles> _normalVertexCycles;  ///< Stores the vertex cycles for each vertex in the mesh. If the data is not disjoined (vertex and all of it's one ring edges are smootly shaded), the vertex will have only a single cycle. 

		Result<void> CopyFrom(const TangentSpaceNormalData& src);

		//----------------------------------------------------------------------------------------
		/// Initializes the vertex cycles, converts the input data to a tangent space representation and stores it. 
		/// @param[in] points                  The points of the polygon object. 
		/// @param[in] polygons                The list of polygons in the object. each polygon is represented by four vertex indices. 
		/// @param[in, out] inputNormals       The custom input normals in object space. They will be converted to tangent space by this call. inputNormals.GetCount() = 4 * polygons.GetCount(). Normals are stored as (p0vn0, p0vn1, p0vn2, p0vn3, p1vn0, p1vn1, p1vn2, p1vn3, ...).
		/// @param[in] neighbor                Neighbor class. 
		/// @return                            OK on success, otherwise error. 
		//----------------------------------------------------------------------------------------
		template <typename NEIGHBORTYPE>
		Result<void> Init(const Block<const Vector>& points, const Block<const SimplePolygon>& polygons, Block<Vector>& inputNormals, NEIGHBORTYPE& neighbor)
		{
			iferr_scope_handler
			{
				_normalVertexCycles.Flush();
				return err;
			};

			_normalVertexCycles.Resize(points.GetCount(), maxon::COLLECTION_RESIZE_FLAGS::ON_GROW_UNINITIALIZED | maxon::COLLECTION_RESIZE_FLAGS::FIT_TO_SIZE) iferr_return;

			ParallelFor::Dynamic<VertexCyclesParallelForContext, PARALLELFORFLAGS::INITTHREADED_FINALIZESYNC>(0, points.GetCount(),
				[](VertexCyclesParallelForContext& context) -> Result<void>
				{
					// init thread local data. 
					iferr_scope;
					context.vertexIdxInPolygons.EnsureCapacity(6) iferr_return;
					context.polygonsAroundVertex.EnsureCapacity(6) iferr_return;
					return OK;
				},
				[&normalVertexCycles = _normalVertexCycles, &points, &polygons, &inputNormals, &neighbor](Int index, VertexCyclesParallelForContext& context) -> Result<void>
				{
					// loop body
					iferr_scope;
					Int32 vertex = (Int32)index;
					memset(&normalVertexCycles[vertex], 0, sizeof(NormalVertexCycles));
					NormalVertexCycles& cycles = normalVertexCycles[vertex];
					cycles._vertex = NOTOK;

					context.vertexIdxInPolygons.Flush();
					context.polygonsAroundVertex.Flush();

					NeighborWrapper<NEIGHBORTYPE>::GetPointPolysFn(neighbor, vertex,
						[&polygons, &context, &vertex](Int32 polyIdx) -> Result<void>
						{
							iferr_scope;
							context.polygonsAroundVertex.Append(polyIdx) iferr_return;
							const SimplePolygon& simplePoly = polygons[polyIdx];
							if (simplePoly.a == vertex)
							{
								context.vertexIdxInPolygons.Append(0) iferr_return;
							}
							else if (simplePoly.b == vertex)
							{
								context.vertexIdxInPolygons.Append(1) iferr_return;
							}
							else if (simplePoly.c == vertex)
							{
								context.vertexIdxInPolygons.Append(2) iferr_return;
							}
							else if (simplePoly.d == vertex)
							{
								context.vertexIdxInPolygons.Append(3) iferr_return;
							}
							else
							{
								return IllegalStateError(MAXON_SOURCE_LOCATION, "Invalid mesh neighbor structure"_s);
							}
							return OK;
						}) iferr_return;

					cycles.Init(vertex, context.polygonsAroundVertex, inputNormals, context.vertexIdxInPolygons) iferr_return;
					cycles.ConvertDataToTangentSpace(points, polygons, inputNormals, inputNormals) iferr_return;

					return OK;
				},
					[](VertexCyclesParallelForContext& context) -> void
				{
					// finalize
				}, ParallelFor::Granularity(128, points.GetCount() > 1023));

			_pointCount = (Int32)points.GetCount();
			_polygonCount = (Int32)polygons.GetCount();

			return OK;
		}

		//----------------------------------------------------------------------------------------
		/// converts the data from tangent space to object space, and populates the given block with the converted data...
		/// @param[in] updatedPointPoisitions  The points of the polygon object. These should be the positions after the modifications are completed. 
		/// @param[in] polygons                The list of polygons in the object. each polygon is represented by four vertex indices.
    /// @param[out] inNormals              The normals in tangent space, in general, computed by the ::Init() call. 
		/// @param[out] outNormals             The custom vertex normals (in object space), outNormals.GetCount() = 4 * polygons.GetCount(). Normals are stored as (p0vn0, p0vn1, p0vn2, p0vn3, p1vn0, p1vn1, p1vn2, p1vn3, ...). 
		/// @return                            OK on success, otherwise error. 
		//----------------------------------------------------------------------------------------
		Result<void> ComputeUpdatedNormals(const Block<const Vector>& updatedPointPoisitions, const Block<const SimplePolygon>& polygons, const Block<const Vector>& inNormals, Block<Vector>& outNormals) const;

		//----------------------------------------------------------------------------------------
		/// Clear all stored normal data and vertex cycles, but do not free memory. 
		//----------------------------------------------------------------------------------------
		void Flush();

		//----------------------------------------------------------------------------------------
		/// Check if the data is initalized. 
		/// The data is inialized if the number of stored vertex cyclies is greater than zero. 
		/// @return                            True if initialized, otherwise false.  
		//----------------------------------------------------------------------------------------
		Bool IsInitialized() const;

		//----------------------------------------------------------------------------------------
		/// Check if the topology of the objects is valid.
		/// The topology will be valid if the given point count and polygon count are equal to the number of points and polygons used to initialize the data.
		/// Note that if the order of points in polygons (topology) changed, but the count did not, this will return true, but the conversion might yield unexpected results. 
		/// Therefore, inside the deformers, additional logic should be performed (i.e. checking the actual topology) to decide if the normals should be transformed or not. 
		/// @param[in] pointCount              The number of points on the updated object, after deformation was performed
		/// @param[in] polygonCount            The number of polygons on the updated object, after deformation was performed. 
		/// @return                            True if valid, otherwise false.  
		//----------------------------------------------------------------------------------------
		Bool IsTopologyValid(Int32 pointCount, Int32 polygonCount) const;

	private:
		Int32 _pointCount = NOTOK;
		Int32 _polygonCount = NOTOK;
	};

} // namespace TangentSpaceNormalHelper

} // namespace maxon

#endif // TANGENTSPACENORMALHELPER_H__

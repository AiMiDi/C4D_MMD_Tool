#ifndef VOLUMETOOLS_H__
#define VOLUMETOOLS_H__

#include "volume.h"
#include "maxon/matrix.h"
#include "maxon/basearray.h"
#include "lib_volumebuilder.h"
#include "maxon/thread.h"
#include "maxon/datadictionary.h"

class PolygonObject;
class FieldList;
class BaseDocument;
class BaseList2D;
class SplineData;

namespace maxon
{

class PointsToVolumeListRef;

enum class SDFFILTERTYPE
{
	NONE = 0,
	GAUSSIAN = 1,
	DILATE = 2,
	ERODE = 3,
	MEANVALUE = 4,
	MEDIANVALUE = 5,
	MEANCURVATURE = 6,
	LAPLACIANFLOW = 7,
	RENORMALIZE = 8,
	OPEN = 9,
	CLOSE = 10,
	TRACK = 11,
	RESIZE = 12
} MAXON_ENUM_LIST(SDFFILTERTYPE, "net.maxon.volume.datatype.sdffiltertype");

enum class FILTERTYPE
{
	NONE = 0,
	GAUSSIAN = 1,
	MEANVALUE = 2,
	MEDIANVALUE = 3,
	OFFSET = 4,
	REMAP = 5,
	CURVEREMAP = 6
} MAXON_ENUM_LIST(FILTERTYPE, "net.maxon.volume.datatype.enum.filtertype");

enum class FILTERACCURACY
{
	NONE = 0,
	FIRST = 1,
	SECOND = 2,
	THIRD = 3,
	WENO5 = 4,
	HJWENO5 = 5
} MAXON_ENUM_LIST(FILTERACCURACY, "net.maxon.volume.datatype.enum.filteraccuracy");

struct SDFFilterSettings
{
	MAXON_OPERATOR_EQUALITY(SDFFilterSettings, filterType, iterations, stencilWidth, offset, halfWidth, accuracy, strength)

	SDFFILTERTYPE filterType = SDFFILTERTYPE::NONE;
	Int iterations = 0;
	Int32 stencilWidth = 3;
	Float32 offset = 1.0;
	Int32 halfWidth = 3;
	FILTERACCURACY accuracy = FILTERACCURACY::FIRST;
	Float strength = 1.0;
};

MAXON_DATATYPE(SDFFilterSettings, "net.maxon.volume.datatype.sdffiltersettings");

struct FilterSettings
{
	MAXON_OPERATOR_EQUALITY(FilterSettings, filterType, iterations, radius, offset, strength, remap_oldMin, remap_oldMax, remap_newMin, remap_newMax)

	FILTERTYPE filterType = FILTERTYPE::NONE;
	Int iterations = 0;
	Int32 radius = 3;
	Float32 offset = 1.0;
	Float strength = 1.0;
	Float remap_oldMin = 0.0;
	Float remap_oldMax = 1.0;
	Float remap_newMin = 0.0;
	Float remap_newMax = 1.0;
	SplineData* splineData = nullptr;
};

MAXON_DATATYPE(FilterSettings, "net.maxon.volume.datatype.filtersettings");

enum class RESAMPLEINTERPOLATIONTYPE
{
	NONE = 0,
	NEAREST = 1,
	LINEAR = 2,
	QUADRATIC = 3
} MAXON_ENUM_LIST(RESAMPLEINTERPOLATIONTYPE, "net.maxon.datatype.enum.resampleinterpolationtype");

struct FieldSampleData
{
	Matrix targetRelativeSpace;											// The target coordinate system for the sampled data.
	Matrix extraTransform;													// An extra transformation for the sample positions of the field.
	FIELDLAYER_FLAG flags = FIELDLAYER_FLAG::NONE;	// Output flags of the field sampling.
	::FieldList* fieldList = nullptr;								// The field list object to use.
	::BaseList2D* fieldOwner = nullptr;							// Can be either a field object for direct sampling or needs to be the owner of this field list.
	::BaseDocument* doc = nullptr;									// The document to evaluate the field list for (for field object links).
};

MAXON_DATATYPE(FieldSampleData, "net.maxon.volume.datatype.fieldsampledata");

using DelegatePointObjectsPair = Pair<Delegate<Result<void>(void*, PointsToVolumeListRef&)>, BaseArray<void*>>;
using DelegatePointObjectsPairList = BaseArray<DelegatePointObjectsPair>;

struct VolumeConversionPolygon
{
	void SetTriangle() { d = maxon::LIMIT<UInt32>::Max(); }
	Bool IsTriangle() const { return d == maxon::LIMIT<UInt32>::Max(); }

	UInt32& operator[](UInt index) const { return ((UInt32*)this)[index & 3]; }

	UInt32 a = maxon::LIMIT<UInt32>::Max();
	UInt32 b = maxon::LIMIT<UInt32>::Max();
	UInt32 c = maxon::LIMIT<UInt32>::Max();
	UInt32 d = maxon::LIMIT<UInt32>::Max();

	static const Int32 size = 4;
};

MAXON_DATATYPE(VolumeConversionPolygon, "net.maxon.volume.datatype.volumeconversionpolygon");

//----------------------------------------------------------------------------------------
/// VolumeToolsInterface provides methods to process volumes.
//----------------------------------------------------------------------------------------
class VolumeToolsInterface
{
	MAXON_INTERFACE_NONVIRTUAL(VolumeToolsInterface, MAXON_REFERENCE_NONE, "net.maxon.interface.volumetools");

public:
	//----------------------------------------------------------------------------------------
	/// Read and return the gridnames from a .vdb file.
	/// @param[in] filename						The url of the file.
	/// @return												A list of strings that represent the grid names in the .vdb file.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<BaseArray<String>> GetGridNamesFromFile(const Url& filename);

	//----------------------------------------------------------------------------------------
	/// Read and return the metadata from a .vdb file.
	/// @param[in] filename						The url of the file.
	/// @return												A data dictionary with metadata stored under string keys.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<DataDictionary> GetMetaDataFromFile(const Url& filename);

	//----------------------------------------------------------------------------------------
	/// Loads volumes from a .vdb file.
	/// @param[in] filename						The url of the file to load from.
	/// @param[in] scale							A scale factor for loading the grids.
	/// @param[out] gridNames					If a BaseArray is passed, it will be filled with the grid names.
	/// @param[in] gridIndices				Optional list of indices that should be loaded from the file.
	/// @param[in] metaData						If passed, will be filled with the metadata from the file.
	/// @return												A list of volumes that were loaded from the .vdb file.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<BaseArray<VolumeRef>> LoadVDBFile(const Url& filename, Float scale, BaseArray<String>* gridNames = nullptr, const BaseArray<Int>* gridIndices = nullptr, DataDictionary* metaData = nullptr);

	//----------------------------------------------------------------------------------------
	/// Loads a grid into a volume from a .vdb file.
	/// @param[in] filename						The url of the file to load from.
	/// @param[in] scale							A scale factor for loading the grids.
	/// @param[in] gridIndex					The index of the grid in the .vdb file.
	/// @param[in] volume							The volume reference to load the grid into.
	/// @param[in] metaData						If passed, will be filled with the metadata from the file.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> LoadGridIntoVolume(const Url& filename, Float scale, Int gridIndex, VolumeRef& volume, DataDictionary* metaData = nullptr);

	//----------------------------------------------------------------------------------------
	/// Loads all grids into a list of volumes from a .vdb file.
	/// @param[in] filename						The url of the file to load from.
	/// @param[in] scale							A scale factor for loading the grids.
	/// @param[out] volume						The output list of loaded volumes.
	/// @param[in] metaData						If passed, will be filled with the metadata from the file.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> LoadAllGridsIntoVolumes(const Url& filename, Float scale, maxon::BaseArray<VolumeRef>& volume, DataDictionary* metaData = nullptr);

	//----------------------------------------------------------------------------------------
	/// Saves volumes to a .vdb file.
	/// @param[in] filename						The url of the file to save to.
	/// @param[in] scale							A scale factor for saving the grids.
	/// @param[in] volumes						A list of volumes that should be saved to the .vdb file.
	/// @param[in] metaData						Optional Metadata to write to the file. Have to added under string keys to the data dictionary.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> SaveVDBFile(const Url& filename, Float scale, BaseArray<VolumeRef>& volumes, const DataDictionary& metaData = DataDictionary());

	//----------------------------------------------------------------------------------------
	/// Bools two SDF volumes into one with a given bool type of ::BOOLTYPE.
	/// @param[in] volumeOne					The first SDF volume for the boolean operation.
	/// @param[in] volumeTwo					The second SDF volume for the boolean operation.
	/// @param[in] type								The bool type ::BOOLTYPE.
	/// @return												The booled volume.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<VolumeRef> BoolVolumes(const VolumeRef& volumeOne, const VolumeRef& volumeTwo, BOOLTYPE type);

	//----------------------------------------------------------------------------------------
	/// Mix two volumes into one with a given mix type of ::MIXTYPE.
	/// @param[in] volumeOne					The first volume for the mix operation.
	/// @param[in] volumeTwo					The second volume for the mix operation.
	/// @param[in] type								The mix type ::MIXTYPE.
	/// @return												The mixed volume.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<VolumeRef> MixVolumes(const VolumeRef& volumeOne, const VolumeRef& volumeTwo, MIXTYPE type);

	//----------------------------------------------------------------------------------------
	/// Extracts a polygon object iso surface from a volume. This is done by a marching cube algorithm.
	/// @param[in] volume							The volume to extract a surface from.
	/// @param[in] iso								The iso value at which a surface should be extracted.
	/// @param[in] adaptiveValue			An adaptive value between 0.0 and 1.0 that reduces the polygon count based on curvature.
	/// @return												The extracted polygon object.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<PolygonObject*> VolumeToMesh(const VolumeRef& volume, Float iso, Float adaptiveValue);

	//----------------------------------------------------------------------------------------
	/// Converts a polygon object to a SDF volume.
	/// @param[in] vertices						The vertex positions of the polygon object.
	/// @param[in] polygons						The polygon information. This needs to be a list of ::VolumeConversionPolygon
	/// @param[in] polygonObjectMatrix	The global position, scale and rotation matrix of the polygon object.
	/// @param[in] gridSize						The desired gridsize of the created volume.
	/// @param[in] bandWidthInterior	The amount of exterior voxels that distance information is calculated for.
	/// @param[in] bandWidthExterior	The amount of interior voxels that distance information is calculated for.
	/// @param[in] thread							A thread reference that cancellation is tested against.
	/// @param[in] creationTransform	An optional override to the target grid matrix. If this is used the @formatParam{gridSize} is ignored.
	/// @return												The converted SDF volume representing the input polygon object.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<VolumeRef> MeshToVolume(const Block<Vector>& vertices, const Block<VolumeConversionPolygon>& polygons, Matrix polygonObjectMatrix, Float gridSize, Int32 bandWidthInterior, Int32 bandWidthExterior, const ThreadRef& thread, const Matrix* creationTransform = nullptr);
	
	//----------------------------------------------------------------------------------------
	/// Converts points in space to a SDF volume. This can be used to convert particles, vertices, spline sampling points or other points to a volume.
	/// @code
	/// // maxon scope is assumed
	///	// the polygon object to convert its vertices from
	///	PolygonObject* somePolyObject = ...;
	///
	/// auto addVertices = [&](void* object, PointsToVolumeListRef& pointsList) -> Result<void>
	/// {
	/// 	iferr_scope;
	///
	///		if (!object)
	///			return IllegalArgumentError(CREATE);
	///
	///		PolygonObject* polyObj = (PolygonObject*)object;
	///		const Vector* points = polyObj->GetPointR();
	///		Matrix objectPosition = polyObj->GetMg();
	///
	/// 	for (Int32 pointIndex = 0; pointIndex < pointCount; pointIndex++)
	/// 	{
	///			// add the points to the particlelist, the radius is captured by reference
	/// 		pointsList.AppendPoint(objectPosition * points[pointIndex], radius) iferr_return;
	/// 	}
	///
	/// 	return OK;
	/// };
	///
	/// // create a delegate/object pair
	/// DelegatePointObjectsPair polySampling;
	/// // set the delegate to the pair
	/// polySampling.first = addVertices;
	///
	/// // add the one polygon object to the list of converted objects. This can be multiple objects processed by the delegate
	/// polySampling.second.Resize(1) iferr_return;
	/// polySampling.second[0] = polygonObject;
	/// 
	/// // add the pair to the list for the conversion
	/// DelegatePointObjectsPairList pointObjects;
	/// pointObjects.Append(polySampling) iferr_return;
	///
	/// // call the conversion
	/// Volume newVolume = VolumeToolsInterface::PointsToVolume(pointObjects, gridSize, bandWidth, thread, gridMatrix) iferr_return;
	/// }
	/// @endcode
	/// @param[in] pointObjects				A list of Delegate/Object pairs that specify how to get point positions from the object.
	/// @param[in] gridSize						The desired gridsize of the created volume.				
	/// @param[in] bandWidth					The amount of voxels around the creates spheres that distance information is calculated for.
	/// @param[in] thread							A thread reference that cancellation is tested against.
	/// @param[in] creationTransform	An optional override to the target grid matrix. If this is used the @formatParam{gridSize} is ignored.
	/// @param[in] velocityScale			A velocity scale that the volumes will be extended to if they have a direction set.
	/// @return												The converted SDF volume representing the input polygon object.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<VolumeRef> PointsToVolume(const DelegatePointObjectsPairList& pointObjects, Float gridSize, Int32 bandWidth, const ThreadRef& thread, const Matrix* creationTransform = nullptr, Float velocityScale = 0.0);
	
	//----------------------------------------------------------------------------------------
	/// Applies a filter operation to a SDF volume. This work only on SDF volumes.
	/// @param[in] volume							The volume that should be filtered.
	/// @param[in] filterType					Settings for the filter operation. See ::SDFFilterSettings.
	/// @param[in] thread							A thread reference that cancellation is tested against.
	/// @param[in] maskVolume					An optional volume object to be used as mask.
	/// @param[in] maskField					An optional field data struct to be used as field mask.
	/// @return												A new filtered version of the input volume.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<VolumeRef> ApplySDFFilterToVolume(const VolumeRef& volume, const SDFFilterSettings& filterType, const ThreadRef& thread, const VolumeRef* maskVolume = nullptr, FieldSampleData* maskField = nullptr);
	
	//----------------------------------------------------------------------------------------
	/// Applies a filter operation to a volume.
	/// @param[in] volume							The volume that should be filtered.
	/// @param[in] filterType					Settings for the filter operation. See ::FilterSettings.
	/// @param[in] thread							A thread reference that cancellation is tested against.
	/// @param[in] maskVolume					An optional volume object to be used as mask.
	/// @param[in] maskField					An optional field data struct to be used as field mask.
	/// @return												A new filtered version of the input volume.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<VolumeRef> ApplyFilterToVolume(const VolumeRef& volume, const FilterSettings& filterType, const ThreadRef& thread, const VolumeRef* maskVolume = nullptr, FieldSampleData* maskField = nullptr);
	
	//----------------------------------------------------------------------------------------
	/// Convert a field list into a volume. This can either be done in a box that samples the grid fully or with a volume reference. 
	/// In case of a volume the active voxels of the volume will be sampled and the result will have the same structure as the reference volume.
	/// @param[in] fieldData					A data struct about the fieldlist data.
	/// @param[in] gridSize						The voxel size of the resulting volume.
	/// @param[in] sampleBox					A bounding box.
	/// @param[in] thread							A thread reference that cancellation is tested against.
	/// @param[in] volumeReference		An optional volume object that will define the sampling positions by it's active voxels. If this is used the @formatParam{voxelSize} and @formatParam{sampleBox} are ignored.
	/// @param[in] creationTransform	An optional override to the target grid matrix. If this is used the @formatParam{gridSize} is ignored.
	/// @return												A volume that contains the values of the field in the active voxels.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<VolumeRef> ConvertFieldsToVolume(FieldSampleData& fieldData, Float gridSize, const Range<Vector>& sampleBox, const ThreadRef& thread, const VolumeRef* volumeReference = nullptr, const Matrix* creationTransform = nullptr);
	
	//----------------------------------------------------------------------------------------
	/// Convert a SDF Volume to a fog volume. The interiour of the SDF object will be filled with data ranging from 0.0 to 1.0 with a falloff.
	/// @param[in] volume							The SDF volume that should be converted.
	/// @param[in] cutoff							The distance for the falloff from 0.0 (SDF 0.0 value) to 1.0.
	/// @return												A fog volume.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<VolumeRef> ConvertSDFToFog(const VolumeRef& volume, Float cutoff = LIMIT<Float>::Max());

	//----------------------------------------------------------------------------------------
	/// Convert a fog Volume to a SDF volume. The resulting surface of the SDF volume is defined by the passed iso value.
	/// @param[in] volume							The fog volume that should be converted.
	/// @param[in] iso								The iso value at which the surface should be created.
	/// @param[in] thread							A thread reference that cancellation is tested against.
	/// @return												A SDF volume.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<VolumeRef> ConvertFogToSDF(const VolumeRef& volume, Float iso, const ThreadRef& thread);

	//----------------------------------------------------------------------------------------
	/// Resample a volume into a new transformation matrix.
	/// @param[in] volume							The volume that should be resampled.
	/// @param[in] resampleTransform	The transformation matrix in which the volume should be resampled into.
	/// @param[in] interpolationType	The resample interpolation type. See ::RESAMPLEINTERPOLATIONTYPE.
	/// @param[in] thread							A thread reference that cancellation is tested against.
	/// @return												The created resampled volume.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<VolumeRef> ResampleVolume(const VolumeRef& volume, const Matrix& resampleTransform, const RESAMPLEINTERPOLATIONTYPE interpolationType, const ThreadRef& thread);
	
	//----------------------------------------------------------------------------------------
	/// Creates a volume mask for a volume reference with values sampled from a field.
	/// @param[in] fieldData					A data struct about the fieldlist data.
	/// @param[in] volumeReference		The reference volume that samples the field into the mask.
	/// @param[in] background					The background of the mask. This will become the maskvalue in areas that have no active voxel in the @formatParam{volumeReference}.
	/// @param[in] thread							A thread reference that cancellation is tested against.
	/// @return												The created mask volume.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<VolumeRef> CreateMaskFromField(FieldSampleData& fieldData, const VolumeRef& volumeReference, Float background, const ThreadRef& thread);
	
	//----------------------------------------------------------------------------------------
	/// Creates a new float volume with default transform. The gridtype will be ::GRIDCLASS::UNKNOWN.
	/// @param[in] background					The background value for the volume.
	/// @return												The newly created volume.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<VolumeRef> CreateNewFloat32Volume(Float32 background);

	//----------------------------------------------------------------------------------------
	/// Creates a gradient volume from a numeric volume.
	/// @param[in] volume							The numeric volume.
	/// @param[in] thread							A thread reference that cancellation is tested against.
	/// @return												The newly created gradient volume.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<VolumeRef> CreateGradientVolume(const VolumeRef& volume, const ThreadRef& thread);

	//----------------------------------------------------------------------------------------
	/// Creates a SDF volume of a spherical shape.
	/// @param[in] radius							The radius of the created sphere.
	/// @param[in] position						The position of the sphere.
	/// @param[in] gridSize						The desired gridsize of the created volume.
	/// @param[in] bandWidth					The amount of interior and exterior voxels that distance information is calculated for.
	/// @param[in] thread							A thread reference that cancellation is tested against.
	/// @param[in] creationTransform	An optional override to the target grid matrix. If this is used the @formatParam{gridSize} is ignored.
	/// @return												The created SDF volume representing the input sphere settings.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<VolumeRef> CreateSphereVolume(Float radius, const Vector& position, Float gridSize, Int32 bandWidth, const ThreadRef& thread, const Matrix* creationTransform = nullptr);

	//----------------------------------------------------------------------------------------
	/// Creates a SDF volume of a platonic shape.
	/// @param[in] sides							The number of sides of the platonic
	/// @param[in] size								The size of the created platonic.
	/// @param[in] position						The position of the platonic.
	/// @param[in] gridSize						The desired gridsize of the created volume.
	/// @param[in] bandWidth					The amount of interior and exterior voxels that distance information is calculated for.
	/// @param[in] thread							A thread reference that cancellation is tested against.
	/// @param[in] creationTransform	An optional override to the target grid matrix. If this is used the @formatParam{gridSize} is ignored.
	/// @return												The created SDF volume representing the input platonic settings.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<VolumeRef> CreatePlatonicVolume(Int32 sides, Float size, const Vector& position, Float gridSize, Int32 bandWidth, const ThreadRef& thread, const Matrix* creationTransform = nullptr);
};

class	PointsToVolumeListInterface
{
	MAXON_INTERFACE_NONVIRTUAL(PointsToVolumeListInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.pointstovolumelist");

public:
	static MAXON_METHOD Result<PointsToVolumeListInterface*> Alloc(MAXON_SOURCE_LOCATION_DECLARATION, Float scale, Float velicityScale);

	//----------------------------------------------------------------------------------------
	/// Adds a point to the point list that will be converted to a volume.
	/// @param[in] position						The position of the point.
	/// @param[in] radius							The radius of the volume sphere that will be created around that point.
	/// @param[in] velocity						The velocity of the points for trails.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> AppendPoint(const Vector& position, Float radius, const Vector& velocity = Vector(0.0));

	//----------------------------------------------------------------------------------------
	/// Returns the amount of points that were added to the point list.
	/// @return												The amount of already added points.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Int GetCount() const;
};


#include "volumetools1.hxx"
#include "volumetools2.hxx"

} // namespace maxon

#endif // VOLUMETOOLS_H__

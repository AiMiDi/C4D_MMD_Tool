#ifndef VOLUMETOOLS_H__
#define VOLUMETOOLS_H__

#include "volume.h"
#include "maxon/matrix.h"
#include "maxon/basearray.h"
#include "lib_volumebuilder.h"
#include "maxon/thread.h"
#include "maxon/datadictionary.h"
#include "maxon/optional.h"

class PolygonObject;
class FieldList;
class BaseDocument;
class BaseList2D;
class SplineData;

namespace maxon
{

class PointsToVolumeListRef;

enum class POLYGONCONVERSIONFLAGS
{
	NONE = 0,
	UNSIGNED_DISTANCE_FIELD = 1 << 0,
	DISABLE_INTERSECTING_VOXEL_REMOVAL = 1 << 1,
	DISABLE_RENORMALIZATION = 1 << 2,
	DISABLE_NARROW_BAND_TRIMMING = 1 << 3,
} MAXON_ENUM_FLAGS(POLYGONCONVERSIONFLAGS, "net.maxon.volume.datatype.enum.polygonconversionflags");

enum class MIXVECTORTYPE
{
	NONE = 0,
	NORMAL = 1,
	ADD = 2,
	SUBTRACT = 3,
	CROSS = 4
} MAXON_ENUM_LIST(MIXVECTORTYPE, "net.maxon.volume.datatype.enum.mixvectortype");

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
} MAXON_ENUM_LIST(SDFFILTERTYPE, "net.maxon.volume.datatype.enum.sdffiltertype");

enum class FILTERTYPE
{
	NONE = 0,
	GAUSSIAN = 1,
	MEANVALUE = 2,
	MEDIANVALUE = 3,
	ADD = 4,
	REMAP = 5,
	CURVEREMAP = 6,
	MULTIPLY = 7,
	ABS = 8,
	INVERT = 9,
} MAXON_ENUM_LIST(FILTERTYPE, "net.maxon.volume.datatype.enum.filtertype");

enum class VECTORFILTERTYPE
{
	NONE = 0,
	GAUSSIAN = 1,
	MEANVALUE = 2,
	MEDIANVALUE = 3,
	CURL = 4,
	NORMALIZE = 5,
	INVERT = 6,
	SCALE = 7,
	ROTATE = 8,
} MAXON_ENUM_LIST(VECTORFILTERTYPE, "net.maxon.volume.datatype.enum.vectorfiltertype");

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
	MAXON_OPERATOR_EQUALITY(FilterSettings, filterType, iterations, radius, offset, strength, remap_oldMin, remap_oldMax, remap_newMin, remap_newMax, invertPoint)

	FILTERTYPE filterType = FILTERTYPE::NONE;
	Int iterations = 0;
	Int32 radius = 3;
	Float32 offset = 1.0f;
	Float strength = 1.0_f;
	Float remap_oldMin = 0.0_f;
	Float remap_oldMax = 1.0_f;
	Float remap_newMin = 0.0_f;
	Float remap_newMax = 1.0_f;
	Float invertPoint = 0.5_f;
	SplineData* splineData = nullptr;
};

MAXON_DATATYPE(FilterSettings, "net.maxon.volume.datatype.filtersettings");

enum class RESAMPLEINTERPOLATIONTYPE
{
	NONE = 0,
	NEAREST = 1,
	LINEAR = 2,
	QUADRATIC = 3
} MAXON_ENUM_LIST(RESAMPLEINTERPOLATIONTYPE, "net.maxon.volume.datatype.enum.resampleinterpolationtype");

struct FieldSampleData
{
	Matrix targetRelativeSpace;											// The target coordinate system for the sampled data.
	Matrix extraTransform;													// An extra transformation for the sample positions of the field.
	FIELDLAYER_FLAG flags = FIELDLAYER_FLAG::NONE;	// Output flags of the field sampling.
	::FieldList* fieldList = nullptr;								// The field list object to use. Can be nullptr if fieldOwner is a field object for direct field sampling.
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
	MAXON_INTERFACE_NONVIRTUAL(VolumeToolsInterface, MAXON_REFERENCE_NONE, "net.maxon.volume.interface.volumetools");

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
	/// @param[out] metaData					If passed, will be filled with the metadata from the file.
	/// @return												A list of volumes that were loaded from the .vdb file.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<BaseArray<Volume>> LoadVDBFile(const Url& filename, Float scale, BaseArray<String>* gridNames = nullptr, const BaseArray<Int>* gridIndices = nullptr, DataDictionary* metaData = nullptr);

	//----------------------------------------------------------------------------------------
	/// Loads a grid into a volume from a .vdb file.
	/// @param[in] filename						The url of the file to load from.
	/// @param[in] scale							A scale factor for loading the grids.
	/// @param[in] gridIndex					The index of the grid in the .vdb file.
	/// @param[out] volume						The volume reference to load the grid into.
	/// @param[out] metaData					If passed, will be filled with the metadata from the file.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> LoadGridIntoVolume(const Url& filename, Float scale, Int gridIndex, Volume& volume, DataDictionary* metaData = nullptr);

	//----------------------------------------------------------------------------------------
	/// Loads all grids into a list of volumes from a .vdb file.
	/// @param[in] filename						The url of the file to load from.
	/// @param[in] scale							A scale factor for loading the grids.
	/// @param[out] volume						The output list of loaded volumes.
	/// @param[out] metaData					If passed, will be filled with the metadata from the file.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> LoadAllGridsIntoVolumes(const Url& filename, Float scale, maxon::BaseArray<Volume>& volume, DataDictionary* metaData = nullptr);

	//----------------------------------------------------------------------------------------
	/// Saves volumes to a .vdb file.
	/// @param[in] filename						The url of the file to save to.
	/// @param[in] scale							A scale factor for saving the grids.
	/// @param[in] volumes						A list of volumes that should be saved to the .vdb file.
	/// @param[in] metaData						Optional Metadata to write to the file. Have to be added under string keys to the data dictionary.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> SaveVDBFile(const Url& filename, Float scale, BaseArray<Volume>& volumes, const DataDictionary& metaData = DataDictionary());

	//----------------------------------------------------------------------------------------
	/// Bools two SDF volumes into one with a given bool type of ::BOOLTYPE.
	/// @param[in] volumeOne					The first SDF volume for the boolean operation.
	/// @param[in] volumeTwo					The second SDF volume for the boolean operation.
	/// @param[in] type								The bool type ::BOOLTYPE.
	/// @return												The booled volume.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Volume> BoolVolumes(const Volume& volumeOne, const Volume& volumeTwo, BOOLTYPE type);

	//----------------------------------------------------------------------------------------
	/// Mix two volumes into one with a given mix type of ::MIXTYPE.
	/// @param[in] volumeOne					The first volume for the mix operation.
	/// @param[in] volumeTwo					The second volume for the mix operation.
	/// @param[in] type								The mix type ::MIXTYPE.
	/// @return												The mixed volume.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Volume> MixVolumes(const Volume& volumeOne, const Volume& volumeTwo, MIXTYPE type);

	//----------------------------------------------------------------------------------------
	/// Extracts a polygon object iso surface from a volume. This is done by a marching cube algorithm.
	/// @param[in] volume							The volume to extract a surface from.
	/// @param[in] iso								The iso value at which a surface should be extracted.
	/// @param[in] adaptiveValue			An adaptive value between 0.0 and 1.0 that reduces the polygon count based on curvature.
	/// @return												The extracted polygon object.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<PolygonObject*> VolumeToMesh(const Volume& volume, Float iso, Float adaptiveValue);

	//----------------------------------------------------------------------------------------
	/// Converts a polygon object to a SDF volume.
	/// @param[in] vertices						The vertex positions of the polygon object.
	/// @param[in] polygons						The polygon information. This needs to be a list of ::VolumeConversionPolygon
	/// @param[in] polygonObjectMatrix	The global position, scale and rotation matrix of the polygon object.
	/// @param[in] gridSize						The desired gridsize of the created volume.
	/// @param[in] bandWidthInterior	The amount of exterior voxels that distance information is calculated for.
	/// @param[in] bandWidthExterior	The amount of interior voxels that distance information is calculated for.
	/// @param[in] thread							A thread reference that cancellation is tested against.
	/// @param[in] conversionSettings Optional settings for the conversion to Volume ::POLYGONCONVERSIONFLAGS.
	/// @param[in] creationTransform	An optional override to the target grid matrix. If this is used the @formatParam{gridSize} is ignored.
	/// @return												The converted SDF volume representing the input polygon object.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Volume> MeshToVolume(const Block<Vector>& vertices, const Block<VolumeConversionPolygon>& polygons, Matrix polygonObjectMatrix, Float gridSize, Int32 bandWidthInterior, Int32 bandWidthExterior, const ThreadRef& thread, POLYGONCONVERSIONFLAGS conversionSettings = POLYGONCONVERSIONFLAGS::NONE, const Matrix* creationTransform = nullptr);
	
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
	static MAXON_METHOD Result<Volume> PointsToVolume(const DelegatePointObjectsPairList& pointObjects, Float gridSize, Int32 bandWidth, const ThreadRef& thread, const Matrix* creationTransform = nullptr, Float velocityScale = 0.0);
	
	//----------------------------------------------------------------------------------------
	/// Applies a filter operation to a SDF volume. This work only on SDF volumes.
	/// @param[in] volume							The volume that should be filtered.
	/// @param[in] filterType					Settings for the filter operation. See ::SDFFilterSettings.
	/// @param[in] thread							A thread reference that cancellation is tested against.
	/// @param[in] maskVolume					An optional volume object to be used as mask.
	/// @param[in] maskField					An optional field data struct to be used as field mask.
	/// @return												A new filtered version of the input volume.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Volume> ApplySDFFilterToVolume(const Volume& volume, const SDFFilterSettings& filterType, const ThreadRef& thread, const Volume* maskVolume = nullptr, FieldSampleData* maskField = nullptr);
	
	//----------------------------------------------------------------------------------------
	/// Applies a filter operation to a volume.
	/// @param[in] volume							The volume that should be filtered.
	/// @param[in] filterType					Settings for the filter operation. See ::FilterSettings.
	/// @param[in] thread							A thread reference that cancellation is tested against.
	/// @param[in] maskVolume					An optional volume object to be used as mask.
	/// @param[in] maskField					An optional field data struct to be used as field mask.
	/// @return												A new filtered version of the input volume.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Volume> ApplyFilterToVolume(const Volume& volume, const FilterSettings& filterType, const ThreadRef& thread, const Volume* maskVolume = nullptr, FieldSampleData* maskField = nullptr);
	
	//----------------------------------------------------------------------------------------
	/// Convert a field list or a field object into a volume. This can either be done in a box that samples the grid fully or with a volume reference. 
	/// In case of a volume the active voxels of the volume will be sampled and the result will have the same structure as the reference volume.
	/// Note that FieldSampleData can have information for a field list or a field object. If FieldSampleData's @formatParam{fieldOwner} is a field object, @formatParam{fieldList} can be nullptr.
	/// @param[in] fieldData					A data struct about the fieldlist data.
	/// @param[in] gridSize						The voxel size of the resulting volume.
	/// @param[in] sampleBox					A bounding box.
	/// @param[in] thread							A thread reference that cancellation is tested against.
	/// @param[in] volumeReference		An optional volume object that will define the sampling positions by it's active voxels. If this is used the @formatParam{voxelSize} and @formatParam{sampleBox} are ignored.
	/// @param[in] creationTransform	An optional override to the target grid matrix. If this is used the @formatParam{gridSize} is ignored.
	/// @return												A volume that contains the values of the field in the active voxels.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Volume> ConvertFieldsToVolume(FieldSampleData& fieldData, Float gridSize, const Range<Vector>& sampleBox, const ThreadRef& thread, const Volume* volumeReference = nullptr, const Matrix* creationTransform = nullptr);
	
	//----------------------------------------------------------------------------------------
	/// Convert a SDF Volume to a fog volume. The interiour of the SDF object will be filled with data ranging from 0.0 to 1.0 with a falloff.
	/// @param[in] volume							The SDF volume that should be converted.
	/// @param[in] cutoff							The distance for the falloff from 0.0 (SDF 0.0 value) to 1.0.
	/// @return												A fog volume.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Volume> ConvertSDFToFog(const Volume& volume, Float cutoff = LIMIT<Float>::Max());

	//----------------------------------------------------------------------------------------
	/// Convert a fog Volume to a SDF volume. The resulting surface of the SDF volume is defined by the passed iso value.
	/// @param[in] volume							The fog volume that should be converted.
	/// @param[in] iso								The iso value at which the surface should be created.
	/// @param[in] thread							A thread reference that cancellation is tested against.
	/// @return												A SDF volume.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Volume> ConvertFogToSDF(const Volume& volume, Float iso, const ThreadRef& thread);

	//----------------------------------------------------------------------------------------
	/// Resample a volume into a new transformation matrix.
	/// @param[in] volume							The volume that should be resampled.
	/// @param[in] resampleTransform	The transformation matrix in which the volume should be resampled into.
	/// @param[in] interpolationType	The resample interpolation type. See ::RESAMPLEINTERPOLATIONTYPE.
	/// @param[in] thread							A thread reference that cancellation is tested against.
	/// @return												The created resampled volume.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Volume> ResampleVolume(const Volume& volume, const Matrix& resampleTransform, const RESAMPLEINTERPOLATIONTYPE interpolationType, const ThreadRef& thread);
	
	//----------------------------------------------------------------------------------------
	/// Creates a volume mask for a volume reference with values sampled from a field.
	/// @param[in] fieldData					A data struct about the fieldlist data.
	/// @param[in] volumeReference		The reference volume that samples the field into the mask.
	/// @param[in] background					The background of the mask. This will become the maskvalue in areas that have no active voxel in the @formatParam{volumeReference}.
	/// @param[in] thread							A thread reference that cancellation is tested against.
	/// @return												The created mask volume.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Volume> CreateMaskFromField(FieldSampleData& fieldData, const Volume& volumeReference, Float background, const ThreadRef& thread);
	
	//----------------------------------------------------------------------------------------
	/// Creates a new float volume with default transform. The gridtype will be ::GRIDCLASS::UNKNOWN.
	/// @param[in] background					The background value for the volume.
	/// @return												The newly created volume.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Volume> CreateNewFloat32Volume(Float32 background);

	//----------------------------------------------------------------------------------------
	/// Creates a gradient volume from a numeric volume.
	/// @param[in] volume							The numeric volume.
	/// @param[in] thread							A thread reference that cancellation is tested against.
	/// @return												The newly created gradient volume.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Volume> CreateGradientVolume(const Volume& volume, const ThreadRef& thread);

	//----------------------------------------------------------------------------------------
	/// Creates a SDF volume of a spherical shape.
	/// @param[in] radius							The radius of the created sphere.
	/// @param[in] position						The position of the sphere.
	/// @param[in] gridSize						The desired gridsize of the created volume.
	/// @param[in] bandWidth					The amount of interior and exterior voxels that distance information is calculated for. Should be greater than 1.
	/// @param[in] thread							A thread reference that cancellation is tested against.
	/// @param[in] creationTransform	An optional override to the target grid matrix. If this is used the @formatParam{gridSize} is ignored.
	/// @return												The created SDF volume representing the input sphere settings.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Volume> CreateSphereVolume(Float radius, const Vector& position, Float gridSize, Int32 bandWidth, const ThreadRef& thread, const Matrix* creationTransform = nullptr);

	//----------------------------------------------------------------------------------------
	/// Creates a SDF volume of a platonic shape. If invalid Arguments are set the function returns an empty volume
	/// @param[in] sides							The number of sides of the platonic. Define the valid Arguments in the description of the parameter
	/// @param[in] size								The size of the created platonic.
	/// @param[in] position						The position of the platonic.
	/// @param[in] gridSize						The desired gridsize of the created volume.
	/// @param[in] bandWidth					The amount of interior and exterior voxels that distance information is calculated for.  Should be greater than 1.
	/// @param[in] thread							A thread reference that cancellation is tested against.
	/// @param[in] creationTransform	An optional override to the target grid matrix. If this is used the @formatParam{gridSize} is ignored.
	/// @return												The created SDF volume representing the input platonic settings.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Volume> CreatePlatonicVolume(Int32 sides, Float size, const Vector& position, Float gridSize, Int32 bandWidth, const ThreadRef& thread, const Matrix* creationTransform = nullptr);

	//----------------------------------------------------------------------------------------
	/// Creates a new float vector volume with default transform. The gridtype will be ::GRIDCLASS::UNKNOWN.
	/// @param[in] background					The background vector value for the volume.
	/// @return												The newly created volume.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Volume> CreateNewVector32Volume(Vector32 background);

	//----------------------------------------------------------------------------------------
	/// Mix two vector volumes into one with a given mix type of ::MIXVECTORTYPE.
	/// @param[in] volumeOne					The first vector volume for the mix operation.
	/// @param[in] volumeTwo					The second vector volume for the mix operation.
	/// @param[in] type								The mix type ::MIXVECTORTYPE.
	/// @return												The mixed vector volume.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Volume> MixVectorVolumes(const Volume& volumeOne, const Volume& volumeTwo, MIXVECTORTYPE type);

	//----------------------------------------------------------------------------------------
	/// Convert a field lists directional channel or a field object into a vector volume. This can either be done in a box that samples the grid fully or with a volume reference. 
	/// In case of a volume the active voxels of the volume will be sampled and the result will have the same structure as the reference volume.
	/// Note that FieldSampleData can have information for a field list or a field object. If FieldSampleData's @formatParam{fieldOwner} is a field object, @formatParam{fieldList} can be nullptr.
	/// @param[in] fieldData					A data struct about the fieldlist data.
	/// @param[in] gridSize						The voxel size of the resulting volume.
	/// @param[in] sampleBox					A bounding box.
	/// @param[in] thread							A thread reference that cancellation is tested against.
	/// @param[in] volumeReference		An optional volume object that will define the sampling positions by it's active voxels. If this is used the @formatParam{voxelSize} and @formatParam{sampleBox} are ignored.
	/// @param[in] creationTransform	An optional override to the target grid matrix. If this is used the @formatParam{gridSize} is ignored.
	/// @return												A vector volume that contains the directions of the field in the active voxels.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Volume> ConvertFieldsToVectorVolume(FieldSampleData& fieldData, Float gridSize, const Range<Vector>& sampleBox, const ThreadRef& thread, const Volume* volumeReference = nullptr, const Matrix* creationTransform = nullptr);

	//----------------------------------------------------------------------------------------
	/// Creates a normalized vector volume from an input vector volume.
	/// @param[in] volume							The vector volume that should be normalized.
	/// @param[in] thread							A thread reference that cancellation is tested against.
	/// @return												The newly created normalized vector volume.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Volume> NormalizeVectorVolume(const Volume& volume, const ThreadRef& thread);

	//----------------------------------------------------------------------------------------
	/// Creates a vector volume representing the curl of a vector volume.
	/// @param[in] volume							The vector volume the curl should be calculated from.
	/// @param[in] thread							A thread reference that cancellation is tested against.
	/// @return												The newly created curl vector volume.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Volume> CreateCurlVolume(const Volume& volume, const ThreadRef& thread);

	//----------------------------------------------------------------------------------------
	/// Creates a curvature volume from a numeric volume.
	/// @param[in] volume							The numeric volume.
	/// @param[in] thread							A thread reference that cancellation is tested against.
	/// @return												The newly created curvature volume.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Volume> CreateMeanCurvatureVolume(const Volume& volume, const ThreadRef& thread);

	//----------------------------------------------------------------------------------------
	///	Rotate the vectors of a vector volume by a specified angle around a rotation axis.
	/// @param[in] volume							The vector volume to rotate.
	/// @param[in] rotationAxis				The rotation axis to rotate around.
	/// @param[in] angle							The angle in radians to rotate.
	/// @param[in] thread							A thread reference that cancellation is tested against.
	/// @param[in] maskField					An optional field data struct to be used as field mask.
	/// @return												The newly created curvature volume.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Volume> RotateVectorVolume(const Volume& volume, const Vector& rotationAxis, const Float angle, const ThreadRef& thread, FieldSampleData* maskField = nullptr);

	//----------------------------------------------------------------------------------------
	/// Convert a vector volume to a fog volume. The resulting volume will have the length of the vectors stored at the original voxel position.
	/// @param[in] volume							The fog volume that should be converted.
	/// @param[in] thread							A thread reference that cancellation is tested against.
	/// @return												A fog volume with the length of the vectors stored.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Volume> ConvertVectorToFog(const Volume& volume, const ThreadRef& thread);

	//----------------------------------------------------------------------------------------
	/// Does a linear blend operation of two volume grids. Both grids need to have the same type and this type needs to be blendable.
	/// @param[in] volumeA						The first volume of the blend operation.
	/// @param[in] volumeB						The second volume of the blend operation.
	/// @param[in] blendValue					The linear blend value between A and B. 1.0 results in A, 0.0 in B
	/// @param[in] thread							A thread reference that cancellation is tested against.
	/// @return												A Volume that is the blend between Volume A and Volume B.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Volume> BlendVolumes(const Volume& volumeA, const Volume& volumeB, const Float blendValue, const ThreadRef& thread);
};

class	PointsToVolumeListInterface
{
	MAXON_INTERFACE_NONVIRTUAL(PointsToVolumeListInterface, MAXON_REFERENCE_NORMAL, "net.maxon.volume.interface.pointstovolumelist");

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

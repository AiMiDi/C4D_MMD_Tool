#ifndef VOLUME_H__
#define VOLUME_H__

#include "maxon/interface.h"
#include "maxon/url.h"
#include "maxon/range.h"
#include "maxon/vector.h"
#include "maxon/matrix.h"
#include "maxon/datadictionary.h"
#include "ge_prepass.h"

namespace maxon
{

class Volume;

//----------------------------------------------------------------------------------------
/// VolumeInterface represents a core volume object in cinema
//----------------------------------------------------------------------------------------
class VolumeInterface : MAXON_INTERFACE_BASES(ObjectInterface)
{
	MAXON_INTERFACE(VolumeInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.volume.interface.volume");
	MAXON_INTERFACE_SINGLE_IMPLEMENTATION

public:

	//----------------------------------------------------------------------------------------
	/// Creates a new volume from a .vdb file.
	/// @param[in] url								The url of the file.
	/// @param[in] scale							The scale to load the volume with.
	/// @param[in] gridIndex					The index of the grid in the file.
	/// @return												The newly created Volume.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Volume> CreateFromFile(const Url& url, Float scale, Int gridIndex);

	//----------------------------------------------------------------------------------------
	/// Loads a grid from .vdb file into this volume object.
	/// @param[in] url								The url of the file.
	/// @param[in] scale							The scale to load the volume with.
	/// @param[in] gridIndex					The index of the grid in the file.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> LoadFromFile(const Url& url, Float scale, Int gridIndex);

	//----------------------------------------------------------------------------------------
	/// Writes the attached grid to a .vdb file.
	/// @param[in] url								The url of the file.
	/// @param[in] scale							The scale to write the volume with.
	/// @param[in] metaData						Optional meta data to write to the file. These need to be stored with a string key in the data dictionary.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> WriteToFile(const Url& url, Float scale, const DataDictionary& metaData = DataDictionary()) const;

	//----------------------------------------------------------------------------------------
	/// Retrieve if a grid is attached to this volume.
	/// @return												True if this volume holds a grid.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool HasGrid() const;

	//----------------------------------------------------------------------------------------
	/// Retrieve the datatype of this grid.
	/// @return												The GRIDTYPE of this volume.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD GRIDTYPE GetGridType() const;

	//----------------------------------------------------------------------------------------
	/// Retrieve the grid class of this grid.
	/// @return												The GRIDCLASS of this volume.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD GRIDCLASS GetGridClass() const;

	//----------------------------------------------------------------------------------------
	/// Set the grid class for this grid.
	/// @param[in] gridClass					The GRIDCLASS to set for this volume.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void SetGridClass(GRIDCLASS gridClass);

	//----------------------------------------------------------------------------------------
	/// Set the grid transform for this grid.
	/// @param[in] newTransform				The transformation matrix to set for this volume.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void SetGridTransform(Matrix newTransform);

	//----------------------------------------------------------------------------------------
	/// Retrieve the grid transform for this grid.
	/// @return												The transformation matrix of this volume.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Matrix GetGridTransform() const;

	//----------------------------------------------------------------------------------------
	/// Set the grid name for this grid.
	/// @param[in] name								The name to set for this volume.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void SetGridName(String name) const;

	//----------------------------------------------------------------------------------------
	/// Retrieve the grid name for this grid.
	/// @return												The name of this volume.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD String GetGridName() const;

	//----------------------------------------------------------------------------------------
	/// Retrieve the bounding box of all active voxels of this grid.
	/// @return												The bounding box of the active voxels of this volume.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const Range<Vector>& GetWorldBoundingBox() const;

	//----------------------------------------------------------------------------------------
	/// Retrieve the active voxel dimensions.
	/// @return												The active voxel dimensions of this volume.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD IntVector32 GetActiveVoxelDim() const;

	//----------------------------------------------------------------------------------------
	/// Retrieve the active voxel count.
	/// @return												The amount of active voxels in this volume.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Int GetActiveVoxelCount() const;

	//----------------------------------------------------------------------------------------
	/// Retrieve the background value of the grid.
	/// @return												The background value of the grid.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Data GetBackground() const;

	//----------------------------------------------------------------------------------------
	/// Returns the amount of memory in bytes used by this volume.
	/// @return												The memory usage in bytes.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Int GetMemUsage() const;

	//----------------------------------------------------------------------------------------
	/// Returns the Min and Max values of the volume.
	/// If it is the first time being called the resulting values are being cached.
	/// Only works for numerical gridtypes. If the volume is a vector volume, the magnitude of the vectors will be used.
	/// @param[in] includeBackground	If true the volume background will be part of the Range, otherwise not.
	/// @return												The Minimum and Maximum Value of this volume.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Range<Float> GetMinMaxValues(Bool includeBackground = false) const;
};

#include "volume1.hxx"
#include "volume2.hxx"

} // namespace maxon

#endif // VOLUME_H__

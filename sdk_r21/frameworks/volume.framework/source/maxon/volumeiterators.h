#ifndef VOLUMEITERATORS_H__
#define VOLUMEITERATORS_H__

#include "maxon/matrix.h"
#include "maxon/vector.h"
#include "maxon/interface.h"
#include "maxon/apibase.h"
#include "maxon/volume.h"

namespace maxon
{

enum class ITERATORTYPE
{
	ALL = 0,
	ON = 1,
	OFF = 2
} MAXON_ENUM_LIST(ITERATORTYPE);

enum class TREEVOXELLEVEL
{
	ROOT = 0,
	TWO = 1,
	THREE = 2,
	LEAF = 3
} MAXON_ENUM_LIST(TREEVOXELLEVEL);

template <typename TYPE, ITERATORTYPE iteratorType>
class GridIteratorRef;

template <typename TYPE, ITERATORTYPE iteratorType>
class GridIteratorInterface;


//----------------------------------------------------------------------------------------
/// Helper class to create the templated interface GridIteratorInterface
//----------------------------------------------------------------------------------------
class GridIteratorCreationInterface
{
	MAXON_INTERFACE_NONVIRTUAL(GridIteratorCreationInterface, MAXON_REFERENCE_NONE, "net.maxon.volume.interface.griditeratorcreation");

public:
	template <typename TYPE, ITERATORTYPE iteratorType>
	static MAXON_FUNCTION Result<GridIteratorRef<TYPE, iteratorType>> Create()
	{
		iferr_scope;
		void* ptr = Create(GetDataType<TYPE>(), iteratorType) iferr_return;
		return GridIteratorRef<TYPE, iteratorType>((GridIteratorInterface<TYPE, iteratorType>*)ptr);
	}

	static MAXON_METHOD Result<void*> Create(const DataType& dataType, ITERATORTYPE iteratorType);
};

//----------------------------------------------------------------------------------------
/// GridIteratorInterface allows to iterate over the active voxels of a volume.
//----------------------------------------------------------------------------------------
template <typename TYPE, ITERATORTYPE iteratorType>
class GridIteratorInterface
{
	MAXON_INTERFACE_SIMPLE_VIRTUAL(GridIteratorInterface, MAXON_REFERENCE_NORMAL);

public:

	static MAXON_FUNCTION Result<GridIteratorRef<TYPE, iteratorType>> Create()
	{
		iferr_scope;
		void* ptr = GridIteratorCreationInterface::Create(GetDataType<TYPE>(), iteratorType) iferr_return;
		return GridIteratorRef<TYPE, iteratorType>((GridIteratorInterface<TYPE, iteratorType>*)ptr);
	}

	//----------------------------------------------------------------------------------------
	/// Initialize the iterator with a volume object.
	/// @param[in] volumeObject				The volume object to initialize this iterator for.
	/// @return												True if the accessor was initialized with a volume, false otherse.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Init(const Volume& volumeObject);

	//----------------------------------------------------------------------------------------
	/// Retrieve the index position of the volume at current iterator position.
	/// @return												The index position at current iterator position.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD IntVector32 GetCoords() const;

	//----------------------------------------------------------------------------------------
	/// Retrieve the value of the volume at current iterator position.
	/// @return												The value at current iterator position.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD TYPE GetValue() const;

	//----------------------------------------------------------------------------------------
	/// Check if the iterator is not at its end.
	/// @return												True if the iterator is not at the end, false otherwise.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool IsNotAtEnd() const;

	//----------------------------------------------------------------------------------------
	/// Steps the iterator to the next active voxel.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void StepNext();

	//----------------------------------------------------------------------------------------
	/// Get a reference to the volume object this iterator is initialized for.
	/// @return												The volume object the iterator was initialized with.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Volume GetVolume() const;

	//----------------------------------------------------------------------------------------
	/// Returns the voxel tree level of the current voxel.
	/// @return												The voxel level of the current iterator position.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD TREEVOXELLEVEL GetVoxelLevel() const;
};



#include "volumeiterators1.hxx"
#include "volumeiterators2.hxx"

}// namespace maxon

#endif // VOLUMEITERATORS_H__

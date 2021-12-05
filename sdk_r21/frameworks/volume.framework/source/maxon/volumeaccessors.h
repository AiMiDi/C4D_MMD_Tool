#ifndef VOLUMEACCESSORS_H__
#define VOLUMEACCESSORS_H__

#include "volume.h"
#include "maxon/matrix.h"
#include "maxon/datatype.h"
#include "maxon/basearray.h"
#include "maxon/vector.h"
#include "maxon/interface.h"
#include "maxon/apibase.h"
#include "maxon/volume.h"

namespace maxon
{

enum class VOLUMESAMPLER
{
	NEAREST = 1,
	LINEAR = 2,
	QUADRATIC = 3
} MAXON_ENUM_LIST(VOLUMESAMPLER, "net.maxon.volume.datatype.enum.volumesampler");


template <typename T>
class GridAccessorRef;

template <typename TYPE>
class GridAccessorInterface;

//----------------------------------------------------------------------------------------
/// Helper class to create the templated interface GridAccessorInterface
//----------------------------------------------------------------------------------------
class GridAccessorCreationInterface
{
	MAXON_INTERFACE_NONVIRTUAL(GridAccessorCreationInterface, MAXON_REFERENCE_NONE, "net.maxon.volume.interface.gridaccessorcreation");

public:
	template <typename T>
	static MAXON_FUNCTION Result<GridAccessorRef<T>> Create()
	{
		iferr_scope;
		void* ptr = Create(GetDataType<T>()) iferr_return;
		return GridAccessorRef<T>((GridAccessorInterface<T>*)ptr);
	}
	static MAXON_METHOD Result<void*> Create(const DataType& dataType);
};

//----------------------------------------------------------------------------------------
/// GridAccessorInterface allows to access volume data
//----------------------------------------------------------------------------------------
template <typename TYPE>
class GridAccessorInterface
{
	MAXON_INTERFACE_SIMPLE_VIRTUAL(GridAccessorInterface, MAXON_REFERENCE_NORMAL);

public:

	static MAXON_FUNCTION Result<GridAccessorRef<TYPE>> Create()
	{
		iferr_scope;
		void* ptr = GridAccessorCreationInterface::Create(GetDataType<TYPE>()) iferr_return;
		return GridAccessorRef<TYPE>((GridAccessorInterface<TYPE>*)ptr);
	}

	//----------------------------------------------------------------------------------------
	/// Initialize the accessor with a volume object in a read only state.
	/// @note if GetValue at a world position wants to be used a VOLUMESAMPLER needs to be passed or SetSampler needs to be called.
	/// @param[in] volumeObject				The volume object to initialize this accessor for.
	/// @param[in] sampler						The used sampler for position sampling.
	/// @return												True if the accessor was initialized with a volume, false otherwise.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Init(const Volume& volumeObject, VOLUMESAMPLER sampler = VOLUMESAMPLER::NEAREST);

	//----------------------------------------------------------------------------------------
	/// Initialize the accessor with a volume object with both read and write access.
	/// @note if GetValue() at a world position is needed, a VOLUMESAMPLER must be passed or SetSampler needs to be called.
	/// @param[in] volumeObject				The volume object to initialize this accessor for.
	/// @param[in] sampler						The sampler to use for position sampling.
	/// @return												True if the accessor was initialized with a volume, false otherwise.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> InitWithWriteAccess(Volume& volumeObject, VOLUMESAMPLER sampler = VOLUMESAMPLER::NEAREST);

	//----------------------------------------------------------------------------------------
	/// Changes the sampler Type.
	/// @param[in] sampler						The used sampler for position sampling.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> SetSampler(VOLUMESAMPLER sampler);

	//----------------------------------------------------------------------------------------
	/// Retrieve the value of the volume at the given voxel index.
	/// @param[in] coords							The voxel index at which the data should be retrieved.
	/// @return												The voxel value at the voxel index.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD TYPE GetValue(const IntVector32& coords) const;

	//----------------------------------------------------------------------------------------
	/// Retrieve the value of the volume at the given world position.
	/// @note the returned value depends on the VOLUMESAMPLER that was set.
	/// @param[in] position						The world position at which the data should be retrieved.
	/// @return												The voxel value at the world position.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD TYPE GetValue(const Vector& position) const;

	//----------------------------------------------------------------------------------------
	/// Retrieve the sub voxel index position of the volume at the given world position.
	/// @note this value depends on the VOLUMESAMPLER that was set.
	/// @param[in] position						The world position at which the sub voxel index position should be retrieved.
	/// @return												The sub voxel index position at the passed position.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Vector GetCoords(const Vector& position) const;

	//----------------------------------------------------------------------------------------
	/// Sets a voxel value at a voxel index.
	/// @note this will activate a voxel
	/// @param[in] coords							The voxel index at which the value will be set.
	/// @param[in] val								The value to set.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> SetValue(const IntVector32& coords, const TYPE val);

	//----------------------------------------------------------------------------------------
	/// Sets a voxel value at a voxel index.
	/// @note same as SetValue, but this will not activate a voxel
	/// @param[in] coords							The voxel index at which the value will be set.
	/// @param[in] val								The value to set.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> SetValueOnly(const IntVector32& coords, const TYPE val);

	//----------------------------------------------------------------------------------------
	/// Sets the active state of a voxel at a voxel index.
	/// @param[in] coords							The voxel index at which the active state will be set.
	/// @param[in] state							The state to set, true means active, false inactive.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> SetActiveState(const IntVector32& coords, Bool state);

	//----------------------------------------------------------------------------------------
	/// Retrieve the active state of a voxel at a voxel index.
	/// @param[in] coords							The voxel index at which the active state will be checked.
	/// @return												The active state of the voxel at that voxel index.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool GetActiveState(const IntVector32& coords) const;
};

template <>
class GridAccessorRef<Generic> : public BaseRef<GridAccessorInterface<void*>, StrongRefHandler>
{
};

using GridAccessorBase = GridAccessorRef<Generic>;

MAXON_DATATYPE(GridAccessorBase, "net.maxon.volume.datatype.gridaccessorbaseref");


#include "volumeaccessors1.hxx"
#include "volumeaccessors2.hxx"

}// namespace maxon

#endif // VOLUMEACCESSORS_H__

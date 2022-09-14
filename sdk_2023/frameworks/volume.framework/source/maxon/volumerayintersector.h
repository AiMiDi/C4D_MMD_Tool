#ifndef VOLUMERAYINTERSECTOR_H__
#define VOLUMERAYINTERSECTOR_H__

#include "volume.h"
#include "maxon/matrix.h"
#include "maxon/datatype.h"
#include "maxon/basearray.h"
#include "maxon/vector.h"
#include "maxon/interface.h"
#include "maxon/volume.h"
#include "maxon/volumeaccessors.h"

namespace maxon
{
// @markInternal
enum class VOLUME_RAY_TYPE
{
	WORLD_SPACE,	///< world space
	INDEX_SPACE		///< index space
} MAXON_ENUM_LIST(VOLUME_RAY_TYPE, "net.maxon.volume.datatype.enum.raytype");

// @markInternal
struct VolumeRay
{
	Vector _origin;																///< Ray start point.
	Vector _direction;														///< Ray direction.
	Float  _tmin{ 0.0_f };												///< Minimum hit distance.
	Float  _tmax{ LIMIT<Float>::MAX };						///< Maximum hit distance.
};

// @markInternal
template<typename TYPE>
struct VolumeRayHit
{
	Vector in;		///< in
	Vector out;		///< out
	TYPE   value; ///< value
};

template <typename T>
class VolumeRayIntersectorRef;

template <typename TYPE>
class VolumeRayIntersectorInterface;

//----------------------------------------------------------------------------------------
/// @markInternal Helper class to create the templated interface VolumeRayIntersector.
//----------------------------------------------------------------------------------------
class VolumeRayIntersectorCreationInterface
{
	MAXON_INTERFACE_NONVIRTUAL(VolumeRayIntersectorCreationInterface, MAXON_REFERENCE_NONE, "net.maxon.volume.interface.volumerayintersectorinterface");

public:
	template <typename T>
	static MAXON_FUNCTION Result<VolumeRayIntersectorRef<T>> Create()
	{
		iferr_scope;
		void* ptr = Create(GetDataType<T>()) iferr_return;
		return VolumeRayIntersectorRef<T>((VolumeRayIntersectorInterface<T>*)ptr);
	}
	static MAXON_METHOD Result<void*> Create(const DataType& dataType);
};


//----------------------------------------------------------------------------------------
/// @markInternal VolumeRayIntersectorInterface allows to access perform volume-ray intersection.
//----------------------------------------------------------------------------------------
template <typename TYPE>
class VolumeRayIntersectorInterface
{
	MAXON_INTERFACE_SIMPLE_VIRTUAL(VolumeRayIntersectorInterface, MAXON_REFERENCE_NORMAL);

public:

	static MAXON_FUNCTION Result<VolumeRayIntersectorRef<TYPE>> Create()
	{
		iferr_scope;
		void* ptr = VolumeRayIntersectorCreationInterface::Create(GetDataType<TYPE>()) iferr_return;
		return VolumeRayIntersectorRef<TYPE>((VolumeRayIntersectorInterface<TYPE>*)ptr);
	}

	//----------------------------------------------------------------------------------------
	/// Initialize the intersector with a volume object in a read only state.
	/// @param[in] volumeObject				The volume object to initialize this intersector for.
	/// @param[in] isSDF							If true this volume is interpreted as SDF and an SDF intersector is used instead of a value intersector.
	/// @return												True if the intersector was initialized with a volume, false otherwise.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Init(const Volume& volumeObject, Bool isSDF = false);

	//----------------------------------------------------------------------------------------
	/// Perform a ray-volume intersection and gives the position of the hit (if any), but
	/// does not retrieve the value of the volume at the intersection point.
	/// @param[in] ray								The ray used for the intersection test.
	/// @param[in] hit								The structure holding the two intersection points.
	/// @param[in] rayType						The space this ray should be cast in.
	/// @return												True if the ray has hit the volume this intersector has been 
	///																initialized with, false otherwise.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Bool> GetClosestHit(const VolumeRay& ray, VolumeRayHit<TYPE>& hit, VOLUME_RAY_TYPE rayType = VOLUME_RAY_TYPE::WORLD_SPACE);

	//----------------------------------------------------------------------------------------
	/// Perform a ray-volume intersection and gives the position of the hit (if any), as
	/// well as the value of the volume at the intersection point.
	/// @param[in] ray								The ray used for the intersection test.
	/// @param[in] hit								The structure holding the two intersection points and the value.
	/// @param[in] accessor 					The accessor to use to sample the volume's value with.
	/// @param[in] rayType						The space this ray should be cast in.
	/// @return												True if the ray has hit the volume this intersector has been 
	///																initialized with, false otherwise.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Bool> GetClosestHit(const VolumeRay& ray, VolumeRayHit<TYPE>& hit, const maxon::GridAccessorRef<TYPE>& accessor, 
		VOLUME_RAY_TYPE rayType = VOLUME_RAY_TYPE::WORLD_SPACE);

	//----------------------------------------------------------------------------------------
	/// Perform a ray-volume intersection and gives the position of the first hit (if any) that verifies
	/// the given condition, and also gives the value of the volume at the intersection point.
	/// @param[in] ray								The ray used for the intersection test.
	/// @param[in] hit								The structure holding the two intersection points and the value.
	/// @param[in] condition					The condition that needs to be fulfilled to choose an intersection point.
	///																The algorithm works by looking at the intersection points in a closest-first
	///																order, and stops and returns at the first point that fulfills the condition.
	/// @param[in] accessor 					The accessor to use to sample the volume's value with.
	/// @param[in] rayType						The space this ray should be cast in.
	/// @return												True if the ray has hit the volume this intersector has been 
	///																initialized with, false otherwise.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Bool> GetClosestHit(const VolumeRay& ray, VolumeRayHit<TYPE>& hit, Delegate<Bool(TYPE, Bool)>&& condition,
		const maxon::GridAccessorRef<TYPE>& accessor, VOLUME_RAY_TYPE rayType = VOLUME_RAY_TYPE::WORLD_SPACE);

	//----------------------------------------------------------------------------------------
	/// Perform a ray-volume intersection and gives the position of all the hits (if any) that verify
	/// the given condition, and also gives the value of the volume at each intersection point.
	/// @param[in] ray								The ray used for the intersection test.
	/// @param[in] hit								The structure holding the two intersection points and the value.
	/// @param[in] condition					The condition that needs to be fulfilled to choose an intersection point.
	///																The algorithm works by looking at the intersection points in a closest-first
	///																order, and stops and returns at the first point that fulfills the condition.
	/// @param[in] accessor 					The accessor to use to sample the volume's value with.
	/// @param[in] rayType						The space this ray should be cast in.
	/// @return												True if the ray has hit the volume this intersector has been 
	///																initialized with, false otherwise.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Bool> GetAllHits(const VolumeRay& ray, BaseArray<VolumeRayHit<TYPE>>& hit, Delegate<Bool(TYPE, Bool)>&& condition,
		const maxon::GridAccessorRef<TYPE>& accessor, VOLUME_RAY_TYPE rayType = VOLUME_RAY_TYPE::WORLD_SPACE);

};



template <>
class VolumeRayIntersectorRef<Generic> : public BaseRef<VolumeRayIntersectorInterface<void*>, StrongRefHandler>
{
};

using VolumeRayIntersectorBase = VolumeRayIntersectorRef<Generic>;

MAXON_DATATYPE(VolumeRayIntersectorBase, "net.maxon.volume.datatype.volumerayintersectorbaseref");

#include "volumerayintersector1.hxx"
#include "volumerayintersector2.hxx"

}

#endif // VOLUMERAYINTERSECTOR_H__

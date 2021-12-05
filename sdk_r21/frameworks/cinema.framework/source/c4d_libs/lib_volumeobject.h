/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef LIB_VOLUMEOBJECT_H__
#define LIB_VOLUMEOBJECT_H__

#include "c4d_library.h"
#include "maxon/forwardref.h"

#ifdef __API_INTERN__
#include "baseobject.h"
#else
#include "c4d_baseobject.h"
#endif

#ifdef __API_INTERN__
#include "hntag.h"
#endif

/// @addtogroup group_volumeobjectlibrary VolumeObject
/// @ingroup group_library
/// @{

namespace maxon
{
class VolumeInterface;
}

//----------------------------------------------------------------------------------------
/// The volume object class of type @ref Ovolume.
/// @addAllocFreeAutoAllocNote
//----------------------------------------------------------------------------------------
class VolumeObject : public BaseObject
{
private:
	VolumeObject();
	~VolumeObject();
public:
	/// @name Alloc/Free
	/// @{

	//----------------------------------------------------------------------------------------
	/// @allocatesA{VolumeObject object}
	/// @return												@allocReturn{VolumeObject object}
	//----------------------------------------------------------------------------------------
	static VolumeObject* Alloc() 
	{ 
#ifdef __API_INTERN__
		return (VolumeObject*)AllocObject(Ovolume);
#else
		return (VolumeObject*)BaseList2D::Alloc(Ovolume);
#endif
	}

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{VolumeObject objects}
	/// @param[in] p									@theToDestruct{VolumeObject object}
	//----------------------------------------------------------------------------------------
	static void Free(VolumeObject*& p)
	{
#ifdef __API_INTERN__
		DeleteObj(p);
#else
		BaseList2D::Free((BaseList2D*&)p);
#endif
	
	}

	/// @}

	/// @name Operations
	/// @{

	//----------------------------------------------------------------------------------------
	/// Returns the core volume object represented by this volume object
	/// @return												The core volume object.
	//----------------------------------------------------------------------------------------
	const maxon::VolumeInterface* GetVolume() const;

	//----------------------------------------------------------------------------------------
	/// Set a core volume instance to this volume object
	/// @param[in] volumeObj					The core volume to be set to this volume.
	//----------------------------------------------------------------------------------------
	void SetVolume(const maxon::VolumeInterface* volumeObj);

	//----------------------------------------------------------------------------------------
	/// Returns the grid type of this volume object
	/// @return												The grid type of this volume object.
	//----------------------------------------------------------------------------------------
	GRIDTYPE GetGridType() const;

	//----------------------------------------------------------------------------------------
	///	Returns the grid class of this volume object
	/// @return												The grid class of this volume object.
	//----------------------------------------------------------------------------------------
	GRIDCLASS GetGridClass() const;

	/// @}
};

/// Volume library ID.
#define LIBRARY_VOLUMEOBJECT 1039962

/// @}

/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

class iVolumeObject;

struct VolumeObjectLib : public C4DLibrary
{
	const maxon::VolumeInterface*				(iVolumeObject::*GetVolume)() const;
	void																(iVolumeObject::*SetVolume)(const maxon::VolumeInterface*);
	GRIDTYPE														(iVolumeObject::*GetGridType)() const;
	GRIDCLASS														(iVolumeObject::*GetGridClass)() const;
};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

#endif // LIB_VOLUMEOBJECT_H__

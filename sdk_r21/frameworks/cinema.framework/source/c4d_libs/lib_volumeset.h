/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef LIB_VOLUMESET_H__
#define LIB_VOLUMESET_H__

#include "c4d_library.h"
#include "lib_volumeobject.h"

#ifdef __API_INTERN__
#include "baseobject.h"
#include "intbaselist.h"
#else
#include "c4d_baseobject.h"
#endif

#ifdef __API_INTERN__
#include "hntag.h"
#endif


/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

class iVolumeSet;

struct VolumeSetLib : public C4DLibrary
{
	void																(iVolumeSet::*AddVolume)(VolumeObject*);
	Bool																(iVolumeSet::*DetachVolume)(VolumeObject*);
	Bool																(iVolumeSet::*DetachVolumeAtIndex)(Int32);
	VolumeObject*												(iVolumeSet::*GetVolumeAtIndex)(Int32) const;
};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// Volume library ID.
#define LIBRARY_VOLUMESET 1050526

namespace
{
VolumeSetLib* lib_volumegroup = nullptr;

static VolumeSetLib* CheckVolumeSetLib(Int32 offset)
{
	return (VolumeSetLib*)CheckLib(LIBRARY_VOLUMESET, offset, (C4DLibrary**)&lib_volumegroup);
}
}


#define VolumeSetLibCall(b) VolumeSetLib* lib = CheckVolumeSetLib(LIBOFFSET(VolumeSetLib, b)); \
															if (!lib || !lib->b) return; \
															(((iVolumeSet*)this)->*lib->b)

#define VolumeSetLibCallR(a, b) VolumeSetLib* lib = CheckVolumeSetLib(LIBOFFSET(VolumeSetLib, b)); \
																	if (!lib || !lib->b) return a; \
																	return (((iVolumeSet*)this)->*lib->b)

/// @endcond

/// @addtogroup group_volumegrouplibrary VolumeSet
/// @ingroup group_library
/// @{

//----------------------------------------------------------------------------------------
/// The volume group class of type @ref Ovolumeset.
/// A volume group is a container for multiple volume objects. The .vdb file format exporter will store all volumes in the volumegroup into a single file.
/// @addAllocFreeAutoAllocNote
//----------------------------------------------------------------------------------------
class VolumeSet : public BaseObject
{
private:
	VolumeSet();
	~VolumeSet();
public:
	/// @name Alloc/Free
	/// @{

	//----------------------------------------------------------------------------------------
	/// @allocatesA{VolumeSet object}
	/// @return												@allocReturn{VolumeSet object}
	//----------------------------------------------------------------------------------------
	static VolumeSet* Alloc()
	{
#ifdef __API_INTERN__
		return (VolumeSet*)AllocObject(Ovolumeset);
#else
		return (VolumeSet*)BaseList2D::Alloc(Ovolumeset);
#endif
	}

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{VolumeSet objects}
	/// @param[in] p									@theToDestruct{VolumeSet object}
	//----------------------------------------------------------------------------------------
	static void Free(VolumeSet*& p)
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
	/// Adds a volume to this group
	/// @param[in] volumeObj					The volume object that should be added to the group.
	//----------------------------------------------------------------------------------------
	void AddVolume(VolumeObject* volumeObj)
	{
		VolumeSetLibCall(AddVolume)(volumeObj);
	}

	//----------------------------------------------------------------------------------------
	/// Detaches a volume from this group and moves it into the object system
	/// @param[in] volumeObj					The volume object that should be detached to the group.
	/// @return												True if the volume was found in the group and detached.
	//----------------------------------------------------------------------------------------
	Bool DetachVolume(VolumeObject* volumeObj)
	{
		VolumeSetLibCallR(false, DetachVolume)(volumeObj);
	}

	//----------------------------------------------------------------------------------------
	/// Detaches a volume from this group and moves it into the object system
	/// @param[in] index							The index of the volume object that should be detached to the group.
	/// @return												True if the index was whithin the bounds of the group if the volume was sucessfully  detached from the group.
	//----------------------------------------------------------------------------------------
	Bool DetachVolumeAtIndex(Int32 index)
	{
		VolumeSetLibCallR(false, DetachVolumeAtIndex)(index);
	}

	//----------------------------------------------------------------------------------------
	/// Returns the volume object in this group at a specified index
	/// @param[in] index							The index to get the volume at.
	/// @return												The volume object at the index. Nullptr if there is none at the index.
	//----------------------------------------------------------------------------------------
	VolumeObject* GetVolumeAtIndex(Int32 index) const
	{
		VolumeSetLibCallR(nullptr, GetVolumeAtIndex)(index);
	}
	/// @}
};

/// @}



#endif // LIB_VOLUMESET_H__

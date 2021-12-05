/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef LIB_VOLUMETAG_H__
#define LIB_VOLUMETAG_H__

#include "c4d_library.h"

#ifdef __API_INTERN__
#include "basetag.h"
#else
#include "c4d_basetag.h"
#include "c4d_baselinkarray.h"
#endif

#ifdef __API_INTERN__
#include "hntag.h"
#endif

#define ID_VOLUME_TAG 1050995

/// @addtogroup group_volumetaglibrary VolumeTag
/// @ingroup group_library
/// @{

namespace maxon
{
class VolumeInterface;
}

enum class VOLUMECHANNEL
{
	NONE = 0,
	ALBEDO = 1,
	DENSITY = 2,
	EMISSION = 3
} MAXON_ENUM_LIST(VOLUMECHANNEL);

//----------------------------------------------------------------------------------------
/// The volume tag class of type @ref Tvolume.
/// @addAllocFreeAutoAllocNote
//----------------------------------------------------------------------------------------
class VolumeTag : public BaseTag
{
private:
	VolumeTag();
	~VolumeTag();
public:
	/// @name Alloc/Free
	/// @{

	//----------------------------------------------------------------------------------------
	/// @allocatesA{VolumeTag object}
	/// @return												@allocReturn{VolumeTag object}
	//----------------------------------------------------------------------------------------
	static VolumeTag* Alloc() { return (VolumeTag*)BaseTag::Alloc(ID_VOLUME_TAG); }

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{VolumeTag objects}
	/// @param[in] p									@theToDestruct{VolumeTag object}
	//----------------------------------------------------------------------------------------
	static void Free(VolumeTag*& p)	{ BaseTag::Free((BaseTag*&)p); }

	/// @}

	/// @name Operations
	/// @{

	//----------------------------------------------------------------------------------------
	/// Returns the list of all found volume objects in the hierarchy
	/// @return												The list of found volume objects in the hierarchy.
	//----------------------------------------------------------------------------------------
	const BaseLinkArray& GetVolumeObjectList() const;

	//----------------------------------------------------------------------------------------
	/// Returns the volume object selected as the volume in the requested channel.
	/// @param[in] channel						The channel to return the volume object for.
	/// @return												If a volume is selected in the channel, returns the correct volume object, otherwise nullptr.
	//----------------------------------------------------------------------------------------
	const BaseObject* GetVolumeObject(VOLUMECHANNEL channel);

	//----------------------------------------------------------------------------------------
	/// Returns the core volume selected as the volume in the requested channel.
	/// @param[in] channel						The channel to return the core volume for.
	/// @return												If a volume is selected in the channel, returns the correct core volume, otherwise nullptr.
	//----------------------------------------------------------------------------------------
	maxon::VolumeInterface* GetVolume(VOLUMECHANNEL channel);

	/// @}
};

/// Volume library ID.
#define LIBRARY_VOLUMETAG 1050997

/// @}

/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

class iVolumeTag;

struct VolumeTagLib : public C4DLibrary
{
	const BaseLinkArray&								(iVolumeTag::*GetVolumeObjectList)() const;
	const BaseObject*										(iVolumeTag::*GetVolumeObject)(VOLUMECHANNEL);
	maxon::VolumeInterface*							(iVolumeTag::*GetVolume)(VOLUMECHANNEL);
};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

#endif // LIB_VOLUMETAG_H__

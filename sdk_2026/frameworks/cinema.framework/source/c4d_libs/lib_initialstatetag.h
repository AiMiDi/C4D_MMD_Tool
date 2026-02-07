/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef LIB_INITIALSTATETAG_H__
#define LIB_INITIALSTATETAG_H__

#include "c4d_library.h"
#include "maxon/block.h"
#include "maxon/quaternion.h"

#ifdef __API_INTERN__
#include "basetag.h"
#else
#include "c4d_basetag.h"
#endif

/// @addtogroup group_particlegroupobjectlibrary InitialStateTag
/// @ingroup group_library
/// @{

namespace cinema
{

enum class INITSTATEFLAG
{
	POSITIONS = 0,
	RESTRICTIONS = 1
} MAXON_ENUM_LIST(INITSTATEFLAG);

using InitStates = maxon::Tuple<maxon::StrongCOWRef<AutoAlloc<BaseObject>>, maxon::StrongCOWRef<AutoAlloc<BaseObject>>>;
using InitStatesMap = maxon::HashMap<maxon::HashInt, InitStates>;

//----------------------------------------------------------------------------------------
/// The particle group object object class of type @ref Ofpgroup.
/// @addAllocFreeAutoAllocNote
//----------------------------------------------------------------------------------------
class InitialStateTag : public BaseTag
{
private:
	InitialStateTag();
	~InitialStateTag();
public:
	/// @name Alloc/Free
	/// @{

	//----------------------------------------------------------------------------------------
	/// @allocatesA{InitialStateTag object}
	/// @return												@allocReturn{InitialStateTag object}
	//----------------------------------------------------------------------------------------
	static InitialStateTag* Alloc()
	{
#ifdef __API_INTERN__
		return (InitialStateTag*)AllocObject(Tinitialstate);
#else
		return (InitialStateTag*)BaseList2D::Alloc(Tinitialstate);
#endif
	}

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{InitialStateTag objects}
	/// @param[in] p									@theToDestruct{InitialStateTag object}
	//----------------------------------------------------------------------------------------
	static void Free(InitialStateTag*& p)
	{
#ifdef __API_INTERN__
		DeleteObj(p);
#else
		BaseList2D::Free(reinterpret_cast<BaseList2D*&>(p));
#endif	
	}

	/// @}

	/// @name Operations
	/// @{
	
	//----------------------------------------------------------------------------------------
	/// Checks if there are any init states associated with hashInt
	//----------------------------------------------------------------------------------------
	Bool Contains(maxon::HashInt hashInt) const;

	//----------------------------------------------------------------------------------------
	/// Checks if there's an init state for the specified initStateFlag associated with hashInt
	//----------------------------------------------------------------------------------------
	Bool ContainsInitState(maxon::HashInt hashInt, INITSTATEFLAG initStateFlag) const;

	//----------------------------------------------------------------------------------------
	/// Stores the init states for positions and restrictions
	//----------------------------------------------------------------------------------------
	maxon::Result<void> StoreInitStates(maxon::HashInt hashInt, BaseObject* positionsInitState, BaseObject* constraintsInitState);

	//----------------------------------------------------------------------------------------
	/// Stores the init state for the specified initStateFlag
	//----------------------------------------------------------------------------------------
	maxon::Result<void> StoreInitState(maxon::HashInt hashInt, BaseObject* initState, INITSTATEFLAG initStateFlag);

	//----------------------------------------------------------------------------------------
	/// Gets the init states of positions and restrictions
	//----------------------------------------------------------------------------------------
	const InitStates* GetInitStates(maxon::HashInt hashInt) const;

	//----------------------------------------------------------------------------------------
	/// Gets the init state for the specified initStateFlag
	//----------------------------------------------------------------------------------------
	const BaseObject* GetInitState(maxon::HashInt hashInt, INITSTATEFLAG initStateFlag) const;
	/// @}
};

/// Particle Group Object library ID.
#define LIBRARY_INITIALSTATETAG 1066336

/// @}

/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

class CINEWARE_SINGLEINHERITANCE iInitialStateTag;

struct InitialStateTagLib : public C4DLibrary
{
	Bool(iInitialStateTag::* Contains)(maxon::HashInt hashInt) const;
	Bool(iInitialStateTag::* ContainsInitState)(maxon::HashInt hashInt, INITSTATEFLAG initStateFlag) const;
	maxon::Result<void>(iInitialStateTag::* StoreInitStates)(maxon::HashInt hashInt, BaseObject* positionsInitState, BaseObject* constraintsInitState);
	maxon::Result<void>(iInitialStateTag::* StoreInitState)(maxon::HashInt hashInt, BaseObject* initState, INITSTATEFLAG initStateFlag);
	const InitStates*(iInitialStateTag::* GetInitStates)(maxon::HashInt hashInt) const;
	const BaseObject*(iInitialStateTag::* GetInitState)(maxon::HashInt hashInt, INITSTATEFLAG initStateFlag) const;
};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

} // namespace cinema

#endif // LIB_INITIALSTATETAG_H__

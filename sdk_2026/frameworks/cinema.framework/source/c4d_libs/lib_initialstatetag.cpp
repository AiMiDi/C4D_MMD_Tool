#include "lib_initialstatetag.h"

namespace cinema
{

InitialStateTagLib* lib_initialstatetag = nullptr;

static InitialStateTagLib* CheckInitialStateTagLib(Int32 offset)
{
	return CheckLib<InitialStateTagLib>(LIBRARY_INITIALSTATETAG, offset, lib_initialstatetag);
}

#define InitialStateTagLibCall(b) 		cinema::InitialStateTagLib* lib = cinema::CheckInitialStateTagLib(LIBOFFSET(cinema::InitialStateTagLib, b)); \
															if (!lib || !lib->b) return; \
															(reinterpret_cast<cinema::iInitialStateTag*>(this)->*lib->b)

#define InitialStateTagLibCallR(a, b) cinema::InitialStateTagLib* lib = cinema::CheckInitialStateTagLib(LIBOFFSET(cinema::InitialStateTagLib, b)); \
															if (!lib || !lib->b) return a; \
															return (reinterpret_cast<cinema::iInitialStateTag*>(this)->*lib->b)

#define InitialStateTagLibCallRC(a, b) cinema::InitialStateTagLib* lib = cinema::CheckInitialStateTagLib(LIBOFFSET(cinema::InitialStateTagLib, b)); \
															if (!lib || !lib->b) return a; \
															return (reinterpret_cast<const cinema::iInitialStateTag*>(this)->*lib->b)

Bool InitialStateTag::Contains(maxon::HashInt hashInt) const
{
	InitialStateTagLibCallRC(false, Contains)(hashInt);
}

Bool InitialStateTag::ContainsInitState(maxon::HashInt hashInt, INITSTATEFLAG initStateFlag) const
{
	InitialStateTagLibCallRC(false, ContainsInitState)(hashInt, initStateFlag);
}

maxon::Result<void> InitialStateTag::StoreInitStates(maxon::HashInt hashInt, BaseObject* positionsInitState, BaseObject* constraintsInitState)
{
	InitialStateTagLibCallR(maxon::OK, StoreInitStates)(hashInt, positionsInitState, constraintsInitState);
}

maxon::Result<void> InitialStateTag::StoreInitState(maxon::HashInt hashInt, BaseObject* initState, INITSTATEFLAG initStateFlag)
{
	InitialStateTagLibCallR(maxon::OK, StoreInitState)(hashInt, initState, initStateFlag);
}

const InitStates* InitialStateTag::GetInitStates(maxon::HashInt hashInt) const
{
	InitialStateTagLibCallRC(nullptr, GetInitStates)(hashInt);
}

const BaseObject* InitialStateTag::GetInitState(maxon::HashInt hashInt, INITSTATEFLAG initStateFlag) const
{
	InitialStateTagLibCallRC(nullptr, GetInitState)(hashInt, initStateFlag);
}

} // namespace cinema

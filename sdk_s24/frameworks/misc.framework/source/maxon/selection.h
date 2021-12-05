#ifndef SELECTION_H__
#define SELECTION_H__

#include "maxon/apibase.h"

namespace maxon
{

//----------------------------------------------------------------------------------------
/// Tests if a specific flag is set in a MAXON enum flag set.
/// @note Helper for MAXON_ENUM_FLAGS.
/// @param[in] flags          Given enum flag set.
/// @param[in] flag           Specific flag.
//----------------------------------------------------------------------------------------
template <typename T, typename E> inline Bool TestFlag(const T flags, const E flag)
{
	return Bool(flags & flag);
}

//----------------------------------------------------------------------------------------
/// Sets a specific flag in a MAXON enum flag set.
/// @note Helper for MAXON_ENUM_FLAGS.
/// @param[in] flags          Given enum flag set.
/// @param[in] flag           Specific flag.
//----------------------------------------------------------------------------------------
template <typename T, typename E> inline void SetFlag(T& flags, const E flag)
{
	flags |= flag;
}

//----------------------------------------------------------------------------------------
/// Deletes a specific flag in a MAXON enum flag set.
/// @note Helper for MAXON_ENUM_FLAGS.
/// @param[in] flags          Given enum flag set.
/// @param[in] flag           Specific flag.
//----------------------------------------------------------------------------------------
template <typename T, typename E> inline void DelFlag(T& flags, const E flag)
{
	flags &= ~flag;
}

//----------------------------------------------------------------------------------------
/// Toggles a flag in a MAXON enum flag set
/// @note Helper for MAXON_ENUM_FLAGS.
/// @param[in] flags          Given enum flag set.
/// @param[in] flag           Specific flag.
//----------------------------------------------------------------------------------------
template <typename T, typename E> inline void ToggleFlag(T& flags, const E flag)
{
	flags ^= flag;
}

//----------------------------------------------------------------------------------------
/// Selection Modifier
//----------------------------------------------------------------------------------------
enum class SELECTION_MODE : UChar
{
	NEW      = 0, ///< new selection - needs reset of all previously existing selections
	ADD      = 1, ///< add to selection
	SUBTRACT = 2, ///< subtract selection
	TOGGLE   = 3, ///< toggle selection
} MAXON_ENUM_LIST(SELECTION_MODE);

//----------------------------------------------------------------------------------------
/// Selection status.
//----------------------------------------------------------------------------------------
enum class SELECTION_STATUS : UChar
{
	NONE     = 0,      ///< no selection at all
	SELECTED = 1 << 0, ///< item (e.g. widget/presenter) is selected
	IMPLICIT = 1 << 1, ///< item (e.g. widget/presenter) is implicitly selected
} MAXON_ENUM_FLAGS(SELECTION_STATUS);


} // namespace maxon

#endif // SELECTION_H__

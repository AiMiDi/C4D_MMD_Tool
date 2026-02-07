#ifndef SELECTION_H__
#define SELECTION_H__

#include "maxon/apibase.h"

namespace maxon
{

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

/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef LIB_TLMARKER_H__
#define LIB_TLMARKER_H__

#ifdef __API_INTERN__
#include "c4d_basetime.h"
#include "ge_string.h"
#include "c4d_library.h"
#include "c4d_gui.h"
#else
#include "c4d_library.h"
#include "c4d_string.h"
#include "c4d_basetime.h"
#endif

class BaseDocument;
class BaseList2D;

/// @addtogroup group_tlmarkerlibrary Timeline Marker
/// @ingroup group_library
/// @{

/// Timeline marker library ID.
#define C4D_TLMARKER_LIBRARY_ID		465001534

//----------------------------------------------------------------------------------------
/// Retrieves the first timeline marker of the document.
/// @param[in] doc								The document. @callerOwnsPointed{document}
/// @return												The first timeline marker. @cinemaOwnsPointed{marker}
//----------------------------------------------------------------------------------------
BaseList2D* GetFirstMarker(BaseDocument* doc);

//----------------------------------------------------------------------------------------
/// Inserts a timeline marker into the document at a given time.\n
/// Optionally an insertion point @formatParam{pPred} in the timeline marker list can be specified, giving the marker before the wanted insertion point.
/// @param[in] doc								The document. @callerOwnsPointed{document}
/// @param[in] pPred							The optional timeline marker to use as list insertion point. @callerOwnsPointed{marker}
/// @param[in] time								The time position of the timeline marker.
/// @param[in] name								The name of the timeline marker.
/// @return												The added timeline marker, or @formatConstant{nullptr} if insertion failed.
//----------------------------------------------------------------------------------------
BaseList2D* AddMarker(BaseDocument* doc, BaseList2D* pPred, BaseTime time, String name);

/// @}

/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

struct TLMarkerLibrary : public C4DLibrary
{
	BaseList2D*	(*GetFirstMarker)(BaseDocument* doc);
	BaseList2D*	(*AddMarker)(BaseDocument* doc, BaseList2D* pPred, BaseTime time, String name);
};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

#endif // LIB_TLMARKER_H__

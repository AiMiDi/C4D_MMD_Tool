/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef C4D_UNIQUEIDMAP_H__
#define C4D_UNIQUEIDMAP_H__

#include "maxon/interface.h"

namespace cinema
{

//-------------------------------------------------------------------------------------------------
/// The BaseList2D class uses a UniqueIDMap to store application ID data, see BaseList2D::AddUniqueID.
//-------------------------------------------------------------------------------------------------
class UniqueIDMapInterface
{
	MAXON_INTERFACE_NONVIRTUAL(UniqueIDMapInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.c4d.interface.uniqueidmap");
public:
	//----------------------------------------------------------------------------------------
	/// Checks for a specific unique application ID data, see BaseList2D::AddUniqueID.
	/// @note This is used for instance to identify scenes written by external applications.
	/// @param[in] appid							A unique application ID. It has to be registered at MAXON, at least it should be obtained from developers.maxon.net.
	/// @return												The block of memory which has been set previously as unique id for appid.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD maxon::Opt<const maxon::Block<const maxon::Byte>&> FindUniqueID(maxon::Int32 appid) const;

	MAXON_METHOD maxon::String ToString(const maxon::FormatStatement* fs = nullptr) const;
};

#include "c4d_uniqueidmap1.hxx"
#include "c4d_uniqueidmap2.hxx"

} // namespace cinema

#endif // C4D_UNIQUEIDMAP_H__

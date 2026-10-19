/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef LIB_TOOLHINTS_H__
#define LIB_TOOLHINTS_H__

#include "maxon/object.h"
#include "maxon/interfacebase.h"

namespace maxon
{

//----------------------------------------------------------------------------------------
/// This interface allows to add resources containing the tool hints to a global storage.
//----------------------------------------------------------------------------------------
class ToolHintsInterface
{
	MAXON_INTERFACE_NONVIRTUAL(ToolHintsInterface, MAXON_REFERENCE_STATIC, "net.maxon.c4dbase.toolhints");

public:
	enum class QUALIFIER : UChar
	{
		NONE	= 0,
		SHIFT	= 1 << 0,
		CTRL	= 1 << 1,
		ALT		= 1 << 2,
		ESC		= 1 << 3
	} MAXON_ENUM_FLAGS_CLASS(QUALIFIER);

	enum class MOSUE_BUTTON : UChar
	{
		NONE		= 0,
		LEFT		= 1,
		MIDDLE	= 2,
		RIGHT		= 3
	} MAXON_ENUM_LIST_CLASS(MOSUE_BUTTON);

	enum class MOSUE_DIRECTION : UChar
	{
		NONE				= 0,
		HORIZONTAL	= 1,
		VERTICAL		= 2
	} MAXON_ENUM_LIST_CLASS(MOSUE_DIRECTION);

	struct ToolHint
	{ 
		using ModeType = UInt32;
		QUALIFIER qualifier = QUALIFIER::NONE;
		MOSUE_BUTTON mouseButton = MOSUE_BUTTON::NONE;
		MOSUE_DIRECTION mouseDirection = MOSUE_DIRECTION::NONE;
		ModeType modes = (ModeType)-1; // Bitmap for Mpoints, Medges etc.
		String text;

		HashInt GetHashCode() const
		{
			return MAXON_HASHCODE(qualifier, mouseButton, mouseDirection, modes, text);
		}
	};

	//----------------------------------------------------------------------------------------
	/// Adds an URL containg tool hints to the storage.
	/// @param[in] url								Url of the file containing the hints.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> AddToolHints(const Url& url);

	//----------------------------------------------------------------------------------------
	/// Gets the tool hints for a specific tool. If there are no hints, an empty block is returned.
	/// @param[in] toolId							Tool ID.
	/// @return												Hints for the specified tool.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD StridedBlock<const ToolHint> GetToolHints(Int32 toolId);
};

} // namespace maxon

#include "lib_toolhints1.hxx"
#include "lib_toolhints2.hxx"

#endif // LIB_TOOLHINTS_H__

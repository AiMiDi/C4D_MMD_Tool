/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef C4D_HELP_H__
#define C4D_HELP_H__

#ifndef __API_INTERN__

#include "ge_math.h"

class String;

//----------------------------------------------------------------------------------------
/// Plugin help support callback. Can be used to display context sensitive help when the user selects "Show Help" for an object or attribute.
/// @note All names are always uppercase.
/// @warning Only return @formatConstant{true} for your own object types.
/// @param[in] opType							The object type name, for example @em "OATOM".
/// @param[in] baseType						The name of the base object type that @formatParam{opType} is derived from, usually the same as @formatParam{opType}.
/// @param[in] group							The name of the group in the attribute manager, for example @em "ID_OBJECTPROPERTIES".
/// @param[in] property						The name of the object property, for example @em "ATOMOBJECT_SINGLE".
/// @return												@trueIfOtherwiseFalse{if the plugin can display help for this request}\n
//----------------------------------------------------------------------------------------
typedef Bool (*PluginHelpDelegate)(const maxon::String& opType, const maxon::String& baseType, const maxon::String& group, const maxon::String& property);

//----------------------------------------------------------------------------------------
/// Registers the delegate for plugin help support.
/// @param[in] pluginId						@uniquePluginID
/// @param[in] delegate						The help handler for this plugin.
/// @return												@trueIfOtherwiseFalse{successful}
//----------------------------------------------------------------------------------------
Bool RegisterPluginHelpDelegate(Int32 pluginId, PluginHelpDelegate delegate);

//----------------------------------------------------------------------------------------
/// Opens the help browser for the indicated topic.
/// @note All names are always uppercase.
/// @param[in] opType							The object type name, for example @em "OATOM".
/// @param[in] baseType						The name of the base object type that @formatParam{opType} is derived from, usually the same as @formatParam{opType}.
/// @param[in] group							The name of the group in the attribute manager, for example @em "ID_OBJECTPROPERTIES".
/// @param[in] property						The name of the object property, for example @em "ATOMOBJECT_SINGLE".
//----------------------------------------------------------------------------------------
void OpenHelpBrowser(const maxon::String& opType, const maxon::String& baseType, const maxon::String& group, const maxon::String& property);

#endif

#endif // C4D_HELP_H__

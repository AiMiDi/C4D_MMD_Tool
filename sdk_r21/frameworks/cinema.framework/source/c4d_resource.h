/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef C4D_RESOURCE_H__
#define C4D_RESOURCE_H__

#ifndef __API_INTERN__
	#include "ge_math.h"
	#include "c4d_string.h"
	#include "c4d_file.h"
#else
	#include "ge_math.h"
	#include "ge_string.h"
#endif

class Filename;
class BaseContainer;
class GeData;

//----------------------------------------------------------------------------------------
/// This class allows to access resource files on the hard drive, for example to load dialog resources or to access string tables.
//----------------------------------------------------------------------------------------
class GeResource
{
private:
	class LocalResource * lr;
	Bool state, glob;
	Filename* initfn;
	Bool _regardIsStopped;

public:
	//----------------------------------------------------------------------------------------
	/// Default constructor.
	//----------------------------------------------------------------------------------------
	GeResource();

	//----------------------------------------------------------------------------------------
	/// Default destructor.
	//----------------------------------------------------------------------------------------
	~GeResource();

	//----------------------------------------------------------------------------------------
	/// Initializes the resources from the default folder of the plugin.
	/// @return												@trueOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool Init();

	//----------------------------------------------------------------------------------------
	/// Initializes the resources from their files in the @em 'res' folder.
	/// @param[in] path								The root path of the plugin's directory to find the @em 'res' folder.
	/// @param[in] regardIsStopped		@markInternal
	/// @return												@trueOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool Init(const Filename& path, Bool regardIsStopped = true);

	//----------------------------------------------------------------------------------------
	/// Lets access the @C4D main application string resource.
	/// @return												@trueOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool InitAsGlobal();

	//----------------------------------------------------------------------------------------
	/// Loads a string from the string resource file.
	/// @param[in] id									The ID for the string in the resource file.
	/// @return												The string from the resource file for the passed ID.
	//----------------------------------------------------------------------------------------
	const String& LoadString(Int32 id);

	//----------------------------------------------------------------------------------------
	/// @markPrivate
	//----------------------------------------------------------------------------------------
	Bool ReloadResource();	// Dangerous! Do not use in release code!!!

	//----------------------------------------------------------------------------------------
	/// Frees all resources used by the class and sets the internal pointer to @formatConstant{nullptr}.
	/// @note Init() needs to be called before the object can be used again.
	//----------------------------------------------------------------------------------------
	void Free();

	//----------------------------------------------------------------------------------------
	/// Gets the main program's resource.
	/// @return												The internal @C4D resource. @cinemaOwnsPointed{resource}
	//----------------------------------------------------------------------------------------
	LocalResource* Get() { return lr; }
};

//----------------------------------------------------------------------------------------
/// Loads a string from the plugins global resource file.
/// @param[in] id									The ID of the string to get.
/// @return												The string that matched the passed @formatParam{id}.
//----------------------------------------------------------------------------------------
const String& GeLoadString(Int32 id);

//----------------------------------------------------------------------------------------
/// Loads a string and replace the @em '#' with the placeholder string.
/// @note	In @C4D there is a convention that in strings @em '#' is a placeholder for dynamic parts (this allows to translate a whole sentence as sentence structure and word placement may be reverted in other languages).\n
///				For example if the string is: "loading of file '#' failed", then the actual filename can be passed as @formatParam{p1}.
/// @param[in] id									The ID of the string to get.
/// @param[in] p1									The string to insert into the placeholder.
/// @return												The completed string.
//----------------------------------------------------------------------------------------
String GeLoadString(Int32 id, const maxon::String& p1);

//----------------------------------------------------------------------------------------
/// Loads a string and replace the @em '#' placeholders with the appropriate string.
/// @note	In @C4D there is a convention that in strings @em '#' is a placeholder for dynamic parts (this allows to translate a whole sentence as sentence structure and word placement may be reverted in other languages).\n
///				For example if the string is: "loading of file '#' failed", then the actual filename can be passed as @formatParam{p1}.
/// @param[in] id									The ID of the string to get.
/// @param[in] p1									The string to insert into the first placeholder.
/// @param[in] p2									The string to insert into the second placeholder.
/// @return												The completed string.
//----------------------------------------------------------------------------------------
String GeLoadString(Int32 id, const maxon::String& p1, const maxon::String& p2);

//----------------------------------------------------------------------------------------
/// Loads a string and replace the @em '#' placeholders with the appropriate string.
/// @note	In @C4D there is a convention that in strings @em '#' is a placeholder for dynamic parts (this allows to translate a whole sentence as sentence structure and word placement may be reverted in other languages).\n
///				For example if the string is: "loading of file '#' failed", then the actual filename can be passed as @formatParam{p1}.
/// @param[in] id									The ID of the string to get.
/// @param[in] p1									The string to insert into the first placeholder.
/// @param[in] p2									The string to insert into the second placeholder.
/// @param[in] p3									The string to insert into the third placeholder.
/// @return												The completed string.
//----------------------------------------------------------------------------------------
String GeLoadString(Int32 id, const maxon::String& p1, const maxon::String& p2, const maxon::String& p3);

//----------------------------------------------------------------------------------------
/// Loads a string and replace the @em '#' placeholders with the appropriate string.
/// @note	In @C4D there is a convention that in strings @em '#' is a placeholder for dynamic parts (this allows to translate a whole sentence as sentence structure and word placement may be reverted in other languages).\n
///				For example if the string is: "loading of file '#' failed", then the actual filename can be passed as @formatParam{p1}.
/// @param[in] id									The ID of the string to get.
/// @param[in] p1									The string to insert into the first placeholder.
/// @param[in] p2									The string to insert into the second placeholder.
/// @param[in] p3									The string to insert into the third placeholder.
/// @param[in] p4									The string to insert into the fourth placeholder.
/// @return												The completed string.
//----------------------------------------------------------------------------------------
String GeLoadString(Int32 id, const maxon::String& p1, const maxon::String& p2, const maxon::String& p3, const maxon::String& p4);

//----------------------------------------------------------------------------------------
/// Registers a description for a plugin ID.
/// This is not needed for plugin types whose @c Register() functions have a @c description parameter.
/// @param[in] id									The plugin ID. If this is a standalone description, use a unique ID.
/// @param[in] idstr							The name of the description resource file to use for the plugin without @em .res extension, for example @em "registered".\n
///																The name has to be unique, i.e. @em "Tdisplay" cannot be used for 2 different descriptions.\n
///																See %Description Resource for more information.
/// @param[in] res								Pass this to search in a specific resource class. Otherwise the default path is used.
/// @return												@trueIfOtherwiseFalse{the description was registered}
//----------------------------------------------------------------------------------------
Bool RegisterDescription(Int32 id, const maxon::String& idstr, LocalResource* res = nullptr);

//----------------------------------------------------------------------------------------
/// Gets the menu container of a main menu.
/// @param[in] menuname						The main menu name, e.g. @em "M_EDITOR" (the same name as on disk or that can be seen in the Menu Editor).
/// @return												The menu container: @enumerateEnum{MENURESOURCE}
//----------------------------------------------------------------------------------------
BaseContainer* GetMenuResource(const maxon::String& menuname);

//----------------------------------------------------------------------------------------
/// Searches a menu container for a certain plugin command (which is a string identifier, for example @em "PLUGIN_CMD_1000472").
/// @param[in] bc									The menu container to search. @callerOwnsPointed{container}
/// @param[in] searchstr					The search string.
/// @return												@trueIfOtherwiseFalse{the command was found}
//----------------------------------------------------------------------------------------
Bool SearchMenuResource(BaseContainer* bc, const maxon::String& searchstr);

//----------------------------------------------------------------------------------------
/// Searches for the @em "Plugins" main menu category in @em "M_EDITOR".
/// @param[in] identifier					The menu identifier.
/// @return												The found menu container, or @formatConstant{nullptr}. @cinemaOwnsPointed{data}
//----------------------------------------------------------------------------------------
GeData* SearchPluginMenuResource(const maxon::String& identifier = "IDS_EDITOR_PLUGINS"_s);

//----------------------------------------------------------------------------------------
/// Searches for the @em "Plugins" main menu category in @em "M_EDITOR" or optionally a sub-menu specified by @formatParam{bc}.
/// @param[in] identifier					The menu identifier.
/// @param[in] bc									The sub-menu container.
/// @return												The found menu container, or @formatConstant{nullptr}. @cinemaOwnsPointed{data}
//----------------------------------------------------------------------------------------
GeData* SearchPluginSubMenuResource(const maxon::String& identifier = "IDS_EDITOR_PLUGINS"_s, BaseContainer* bc = nullptr);

//----------------------------------------------------------------------------------------
/// Gets a plugin's resource path.
/// @return												The resource path for the current plugin.
//----------------------------------------------------------------------------------------
Filename GeGetPluginResourcePath();

//----------------------------------------------------------------------------------------
/// Forces a menu update.
/// @note Not necessary when reacting to @ref C4DPL_BUILDMENU.
//----------------------------------------------------------------------------------------
void UpdateMenus(void);

/// Global resources for @C4D.
extern GeResource g_resource;

//----------------------------------------------------------------------------------------
/// @markPrivate
//----------------------------------------------------------------------------------------
void FreeResource();

#endif // C4D_RESOURCE_H__

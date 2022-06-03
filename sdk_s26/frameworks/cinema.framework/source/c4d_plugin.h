/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef C4D_PLUGIN_H__
#define C4D_PLUGIN_H__

#include "ge_math.h"

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_BEGIN
#endif

#define C4DPL_VERSION									0x0005			///< The version of @C4D plugin API.

/// @addtogroup C4DPL_ERROR
/// @ingroup group_enumeration
/// @{
#define C4DPL_ERROR					-1			///< An unknown error occurred.
#define C4DPL_ERROR_VERSION	-3			///< Incorrect version of @C4D.
/// @}

/// @addtogroup C4DPL_MESSAGES
/// @ingroup group_enumeration
/// @{
#define C4DPL_INIT_SYS			1			///< Initialize system.
#define C4DPL_INIT					2			///< Initialize the plugin, calling PluginStart().
#define C4DPL_END						3			///< End the plugin, calling PluginEnd().
#define C4DPL_INIT_VERSION	4			///< Get the @C4D API version this plugin was compiled with.
#define C4DPL_MESSAGE				6			///< Receive plugin message, calling PluginMessage().
/// @}

/// @addtogroup C4DPL_MESSAGES
/// @ingroup group_enumeration
/// @{
#define C4DMSG_PRIORITY 0						///< Called to query plugins about their loading time priority. Answer with SetPluginPriority(), passing the message data along.
#define C4DPL_BUILDMENU 1001188			///< Called when the menus are built during startup.\n
																		///< Use GetMenuResource() etc. to add menus here if necessary. See @em main.cpp in the SDK examples.
/// @}

/// @addtogroup C4DPL_INIT_PRIORITY
/// @ingroup group_enumeration
/// @{
#define C4DPL_INIT_PRIORITY_XTENSIONS				20000			///< Base priority for extensions.
#define C4DPL_INIT_PRIORITY_OBJECTS					19000			///< Base priority for objects.
#define C4DPL_INIT_PRIORITY_MODELING				18500			///< Base priority for modeling.
#define C4DPL_INIT_PRIORITY_SHADER					18000			///< Base priority for shader modules.
#define C4DPL_INIT_PRIORITY_ADVANCEDRENDER	17000			///< Base priority for the Advanced %Render module.
#define C4DPL_INIT_PRIORITY_MOCCA						15000			///< Base priority for MOCCA.
#define C4DPL_INIT_PRIORITY_NEWMAN					12000			///< Base priority for @C4D managers.
#define C4DPL_INIT_PRIORITY_SLA							850				///< Base priority for SLA.

#define C4DPL_INIT_PRIORITY_MODULES 10000			///< Base priority for modules.
#define C4DPL_INIT_PRIORITY_PLUGINS 0					///< Base priority for plugins.
/// @}

/// @addtogroup C4DPL_MESSAGES
/// @ingroup group_enumeration
/// @{
#define C4DPL_STARTACTIVITY					1000					///< Sent to all plugins after all PluginStart() have been called.
#define C4DPL_ENDACTIVITY						1001					///< Sent to all plugins before any PluginEnd() has been called.\n
																									///< This allows to close dialogs, end threads, delete temporary/undo buffers etc. In PluginEnd() it might crash as some resources from other plugins might already be freed.\n
																									///< Consider the following example: Your plugin starts before the gradient datatype plugin (extensions) is registered.\n
																									///< During runtime store a BaseContainer that contains such a GeData. Now to free the BaseContainer in PluginEnd() you will get a crash as the gradient already has been unloaded.\n
																									///< So it is necessary to free all that data depending on other plugins (and all threads, dialogs) when @ref C4DPL_ENDACTIVITY is sent.
#define C4DPL_COMMANDLINEARGS				1002					///< Sent to let plugins parse the command line arguments used when starting @C4D. The @c data pointer should be cast to C4DPL_CommandLineArgs.
#define C4DPL_ENDPLUGINACTIVITY0		1026848				///< Sent after @ref C4DPL_ENDACTIVITY but before the current document is freed. Should only be used if absolutely necessary.
#define C4DPL_ENDPLUGINACTIVITY1		200000272			///< Sent to all plugins after all documents are closed, but before the plugin registrations are destroyed.\n
																									///< A plugin should use @ref C4DPL_ENDACTIVITY whenever possible and @ref C4DPL_ENDPLUGINACTIVITY1 or @ref C4DPL_ENDPLUGINACTIVITY2 only when absolutely necessary.
#define C4DPL_ENDPLUGINACTIVITY2		200000276			///< Sent after all plugin registrations are destroyed, so for example any custom GUI datatypes will no longer be accessible (freeing of a BaseContainer holding one of these will crash).\n
																									///< A plugin should use @ref C4DPL_ENDACTIVITY whenever possible and @ref C4DPL_ENDPLUGINACTIVITY1 or @ref C4DPL_ENDPLUGINACTIVITY2 only when absolutely necessary.
#define C4DPL_CHANGEDSECURITYTOKEN	300002143			///< Sent to all plugins if the Security Token of Team %Render was changed.
#define C4DPL_SHUTDOWNTHREADS				300002148			///< Sent to all plugins before the threading system of @C4D is shutdown. After that no threads should be started.
#define C4DPL_LAYOUTCHANGED					300002164			///< Sent to all plugins after the layout has been switched.
#define C4DPL_RELOADPYTHONPLUGINS		1026963				///< Sent when Python plugins are to be reloaded.
/// @}

struct C4DPL_CommandLineArgs
{
	Int32								argc;				///< Number of arguments in argv.
	char**							argv;				///< Argument array.
	Int32								argc_w;			///< Number of arguments in @ref argv_w (Unicode encoding, Windows only).
	Utf16Char**					argv_w;			///< Argument array (Unicode encoding, Windows only).
	const char*					orig;				///< The complete argument string.
	const Utf16Char*		orig_w;			///< The complete unicode argument string (Unicode encoding, Windows only).
};

/// Sent to allow plugins to start any other actions when @C4D tries to show an image (e.g. in the shader popup).\n
/// The @c data pointer should be cast to C4DPL_EditImage.
#define C4DPL_EDITIMAGE	1003			///< @ingroup C4DPL_MESSAGES

struct C4DPL_EditImage
{
	class Filename * imagefn;			///< Image that triggered the message.
	Bool return_processed;				///< Set this to @formatConstant{true} if the image was processed.
};

/// Sent when @C4D is about to close.
#define C4DPL_ENDPROGRAM		1001084			///< @ingroup C4DPL_MESSAGES

/// Sent when a device has changed. The @c data pointer should be cast to C4DPL_DeviceChange.
#define C4DPL_DEVICECHANGE	1001190			///< @ingroup C4DPL_MESSAGES

struct C4DPL_DeviceChange
{
	class String* name;			///< The name of the device.
	Bool eject;							///< @formatConstant{true} if the device was ejected, otherwise @formatConstant{false}.
};

/// @addtogroup C4DPL_MESSAGES
/// @ingroup group_enumeration
/// @{
#define C4DPL_NETWORK_CHANGE	310002007			///< Sent to all plugins if the network configuration on the system changed.
#define C4DPL_SYSTEM_SLEEP		310002008			///< Send to all plugins if the system goes to sleep.
#define C4DPL_SYSTEM_WAKE			310002009			///< Send to all plugins if the system wakes up.
#define C4DPL_PROGRAM_STARTED	450000215			///< Sent when the application has been started.
/// @}

/// @markPrivate
#define C4DPL_REGISTERPYPLUG	1026805			///< @ingroup C4DPL_MESSAGES

/// @markPrivate
#define C4DPL_NETRENDERRESULT 310002006			///< @ingroup C4DPL_MESSAGES

/// @markPrivate
struct C4DPL_NetRenderResult
{
	Int32 result;
	void* node;
};

//----------------------------------------------------------------------------------------
/// Called when a plugin is loaded from @C4D. Think of it as the equivalent to the usual @c main() function.\n
/// Here register all the plugin types and initialize them.\n
/// For example, the basics needed are:
/// @code
/// Bool PluginStart()
/// {
/// 	if (!g_resource.Init())
/// 		return false;				// Do not start plugin without resource
///
/// 	if (!RegisterMyPlugin())
/// 		return false;
///
/// 	return true;
/// }
/// @endcode
/// @return												@trueIfOtherwiseFalse{the plugin was loaded}
//----------------------------------------------------------------------------------------
Bool PluginStart(void);

//----------------------------------------------------------------------------------------
/// Called when the plugin is unloaded from @C4D.\n
/// Here free the plugin registrations and any resources which are not owned or already freed by other plugins (see PluginMessage()).\n
/// To free complex structures from other modules see @ref C4DPL_ENDACTIVITY.\n
/// For example:
/// @code
/// void PluginEnd(void)
/// {
/// 	FreeMyPlugin();
/// }
/// @endcode
//----------------------------------------------------------------------------------------
void PluginEnd(void);

//----------------------------------------------------------------------------------------
/// Called to receive plugin messages.\n
/// These can either be from @C4D or from other plugins via GePluginMessage(). Here is an example:
/// @code
/// Bool PluginMessage(Int32 id, void *data)
/// {
/// 	switch (id)
/// 	{
/// 		case C4DMSG_PRIORITY:
/// 			SetPluginPriority(data, C4DPL_INIT_PRIORITY_PLUGINS+100);
/// 			return true;
/// 		case MY_MESSAGE:
/// 			...
/// 			return true;
/// 	}
///
/// 	return false;
/// }
/// @endcode
/// @param[in] id									The message ID. Built-in ones are: @enumerateEnum{C4DPL_MESSAGES}
/// @param[in] data								The message data.
/// @return												@trueIfOtherwiseFalse{the message was consumed}
//----------------------------------------------------------------------------------------
Bool PluginMessage(Int32 id, void* data);

//----------------------------------------------------------------------------------------
/// Sets the priority for a plugin.
/// @param[in] data								The message data of the priority message.
/// @param[in] i									The plugin priority. Build the priority from one of the base priorities: @enumerateEnum{C4DPL_INIT_PRIORITY}
//----------------------------------------------------------------------------------------
#define SetPluginPriority(data, i) { *((Int32*)(data)) = i; }

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_END
#endif

#endif // C4D_PLUGIN_H__

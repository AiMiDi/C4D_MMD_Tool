/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef C4D_BASEPLUGIN_H__
#define C4D_BASEPLUGIN_H__

#include "ge_math.h"
#include "c4d_basedata.h"
#include "c4d_baselist.h"

class String;


/// @addtogroup PLUGINFLAG
/// @ingroup group_enumeration
/// @{
#define PLUGINFLAG_HIDE							(1 << 29)			///< Hide the plugin (for example, in Commander).
#define PLUGINFLAG_SMALLNODE				(1 << 30)			///< Create a small node.
#define PLUGINFLAG_HIDEPLUGINMENU		(1 << 28)			///< Hide the plugin's menu entry.
#define PLUGINFLAG_REFRESHALWAYS		(1 << 25)			///< @markDeprecated Legacy plugin flag.
/// @}

/// @markInternal
#ifdef MAXON_TARGET_MACOS
	#define C4DPL_MEMBERMULTIPLIER 2
#elif defined MAXON_TARGET_WINDOWS
	#define	C4DPL_MEMBERMULTIPLIER 1
#else
	#define	C4DPL_MEMBERMULTIPLIER 2
#endif

/// @markInternal
struct BASEPLUGIN
{
	Int32 info;

	void (BaseData::*Destructor)(void);

	void* reserved[(8 - 1) * C4DPL_MEMBERMULTIPLIER - 1];
};

/// @markInternal
struct STATICPLUGIN : public BASEPLUGIN
{
	BaseData* adr;

	void* reserved[(8 - 0) * C4DPL_MEMBERMULTIPLIER - 1];
};


#ifndef __API_INTERN__

//-------------------------------------------------------------------------------------------------
/// The base class for @C4D plugins.
//-------------------------------------------------------------------------------------------------
class BasePlugin : public BaseList2D
{
private:
	BasePlugin();

protected:
	~BasePlugin();

public:

	/// @name Navigation
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the next plugin in the list. Convenience version of inherited GeListNode::GetNext() returning a @ref BasePlugin*.
	/// @return												The next plugin, or @formatConstant{nullptr} if there is none. @cinemaOwnsPointed{plugin}
	//----------------------------------------------------------------------------------------
	BasePlugin* GetNext(void) { return (BasePlugin*)AtCall(GetNext)(); }

	//----------------------------------------------------------------------------------------
	/// Gets the previous plugin in the list. Convenience version of inherited GeListNode::GetPred() returning a @ref BasePlugin*.
	/// @return												The previous plugin, or @formatConstant{nullptr} if there is none. @cinemaOwnsPointed{plugin}
	//----------------------------------------------------------------------------------------
	BasePlugin* GetPred(void) { return (BasePlugin*)AtCall(GetPred)(); }

	//----------------------------------------------------------------------------------------
	/// Gets the parent plugin of the list node. Convenience version of inherited GeListNode::GetUp() returning a @ref BasePlugin*.
	/// @return												The parent plugin, or @formatConstant{nullptr} if there is none. @cinemaOwnsPointed{plugin}
	//----------------------------------------------------------------------------------------
	BasePlugin* GetUp(void) { return (BasePlugin*)AtCall(GetUp)(); }

	//----------------------------------------------------------------------------------------
	/// Gets the first child plugin of the list node. Convenience version of inherited GeListNode::GetDown() returning a @ref BasePlugin*.
	/// @return												The first child plugin, or @formatConstant{nullptr} if there is none. @cinemaOwnsPointed{plugin}
	//----------------------------------------------------------------------------------------
	BasePlugin* GetDown(void) { return (BasePlugin*)AtCall(GetDown)(); }

	//----------------------------------------------------------------------------------------
	/// Gets the last child plugin of the list node. Convenience version of inherited GeListNode::GetDownLast() returning a @ref BasePlugin*.
	/// @return												The last child plugin, or @formatConstant{nullptr} if there is none. @cinemaOwnsPointed{plugin}
	//----------------------------------------------------------------------------------------
	BasePlugin* GetDownLast(void) { return (BasePlugin*)AtCall(GetDownLast)(); }

	/// @}

	/// @name Information
	/// @{

	//----------------------------------------------------------------------------------------
	/// Retrieves the structure of the plugin. @markPrivate
	/// @return												The private plugin structure.
	//----------------------------------------------------------------------------------------
	void* GetPluginStructure();

	//----------------------------------------------------------------------------------------
	/// Gets the information flags for the plugin.
	/// @return												The info flags: @enumerateEnum{PLUGINFLAG}
	//----------------------------------------------------------------------------------------
	Int32 GetInfo();

	//----------------------------------------------------------------------------------------
	/// Gets the filename for the plugin file.
	/// @return												The plugin file's filename.
	//----------------------------------------------------------------------------------------
	Filename GetFilename();

	//----------------------------------------------------------------------------------------
	/// Gets the plugin ID.
	/// @return												The plugin ID.
	//----------------------------------------------------------------------------------------
	Int32 GetID();

	//----------------------------------------------------------------------------------------
	/// Gets the type. Convenience version of inherited C4DAtom::GetType() returning a @ref PLUGINTYPE.
	/// @return												The plugin type: @enumerateEnum{PLUGINTYPE}
	//----------------------------------------------------------------------------------------
	PLUGINTYPE GetPluginType() const { return (PLUGINTYPE)GetType(); }

	/// @}
};

//-------------------------------------------------------------------------------------------------
/// The base class for @C4D tool plugins.
/// @since R19
//-------------------------------------------------------------------------------------------------
class ToolPlugin : public BasePlugin
{
private:
	ToolPlugin();
	~ToolPlugin();

public:

	//----------------------------------------------------------------------------------------
	/// @markPrivate
	//----------------------------------------------------------------------------------------
	TOOLDRAW Draw(BaseDocument *doc, BaseDraw *bd, BaseDrawHelp *bh, BaseThread *bt, TOOLDRAWFLAGS flags);
};

class AtomArray;

//----------------------------------------------------------------------------------------
/// Finds a plugin from its @formatParam{id} and @formatParam{type}.
/// @note For CUSTOMDATATYPEPLUGIN  and RESOURCEDATATYPEPLUGIN, please use FindCustomDataTypePlugin() and FindResourceDataTypePlugin()
/// @param[in] id									The plugin ID.
/// @param[in] type								The plugin type: @enumerateEnum{PLUGINTYPE}
/// @return												The found plugin or @formatConstant{nullptr}. @cinemaOwnsPointed{plugin}
//----------------------------------------------------------------------------------------
BasePlugin* FindPlugin(Int32 id, PLUGINTYPE type);

//----------------------------------------------------------------------------------------
/// Gets the first registered plugin in the plugin list.
/// @return												The first plugin or @formatConstant{nullptr}. @cinemaOwnsPointed{plugin}
//----------------------------------------------------------------------------------------
BasePlugin* GetFirstPlugin();

//----------------------------------------------------------------------------------------
/// Browses recursively through the plugin list looking for plugin of the specified type.\n
/// For example, to find all bitmap saver plugins use:
/// @code
/// AtomArray plugins;
/// if (FilterPluginList(plugins, PLUGINTYPE::BITMAPSAVER, true))
/// 	...
/// @endcode
/// @param[out] arr								Filled with the found plugins.
/// @param[in] type								The plugin type to filter: @enumerateEnum{PLUGINTYPE}
/// @param[in] sortbyname					If @formatConstant{true} then the found plugins are sorted alphabetically by name.
/// @return												@trueIfOtherwiseFalse{successful}
//----------------------------------------------------------------------------------------
Bool FilterPluginList(AtomArray& arr, PLUGINTYPE type, Bool sortbyname);

//-------------------------------------------------------------------------------------------------
/// @markPrivate
//-------------------------------------------------------------------------------------------------
void RemovePlugin(BasePlugin* plug);

//-------------------------------------------------------------------------------------------------
/// @markPrivate
//-------------------------------------------------------------------------------------------------
void BuildGlobalTagPluginContainer(BaseContainer* plugincontainer, Int32* id, UInt& newFeatureVersion);

//-------------------------------------------------------------------------------------------------
/// @markPrivate
//-------------------------------------------------------------------------------------------------
Int32 ResolveGlobalTagPluginContainer(Int32* id);

//-------------------------------------------------------------------------------------------------
/// @markPrivate
//-------------------------------------------------------------------------------------------------
Filename* GetLocalFilename();

//-------------------------------------------------------------------------------------------------
/// @markPrivate
//-------------------------------------------------------------------------------------------------
BasePlugin* CreatePluginEntry(const maxon::String& foldername, BasePlugin* bp);

//-------------------------------------------------------------------------------------------------
/// @markPrivate
//-------------------------------------------------------------------------------------------------
void SetLocalHierarchy(BasePlugin* parent, BasePlugin* pred);

#else
	#include "ge_plugin.h"
#endif

#endif // C4D_BASEPLUGIN_H__

/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef LIB_BROWSER_H__
#define LIB_BROWSER_H__

#include "c4d_gui.h"
#ifndef __API_INTERN__
	#include "c4d_file.h"
	#include "c4d_baseplugin.h"
#else
	#include "ge_file.h"
	#include "c4d_baseplugin.h"
#endif
#include "c4d_library.h"

namespace maxon
{
class AssetDescription;
}

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_BEGIN
#endif

/// @addtogroup group_browserlibrary Browser
/// @ingroup group_library
/// @{

#ifndef BROWSERPLUGININTERFACE_H__
class CINEWARE_SINGLEINHERITANCE iBrowser {};
class CINEWARE_SINGLEINHERITANCE BrowserURL {};
class CINEWARE_SINGLEINHERITANCE ReferenceObject {};
class CINEWARE_SINGLEINHERITANCE RTreeNode {};
class CINEWARE_SINGLEINHERITANCE BrowserContentNode {};
class CINEWARE_SINGLEINHERITANCE BrowserPluginInterface {};
#else
class iBrowser;
class BrowserURL;
class ReferenceObject;
class RTreeNode;
class BrowserContentNode;
class BrowserPluginInterface;
#endif

class GvNode;

#ifdef BROWSERPLUGININTERFACE_H__
#define SDKBrowserURL BrowserURL
#else
class SDKBrowserURL
{
public:
	SDKBrowserURL() {};
	SDKBrowserURL(const String&) {};
	SDKBrowserURL(const Filename&) {};
};
#endif


#ifdef BROWSERPLUGININTERFACE_H__
#define SDKBrowserIcon BrowserIcon
#else
#endif

//----------------------------------------------------------------------------------------
/// Base class for the browser nodes.
//----------------------------------------------------------------------------------------
class SDKReferenceObject
{
private:
	SDKReferenceObject();
	virtual ~SDKReferenceObject();
public:
	//----------------------------------------------------------------------------------------
	/// Increments the reference count.
	//----------------------------------------------------------------------------------------
	void add_reference(void);

	//----------------------------------------------------------------------------------------
	/// Decrements the reference count.
	//----------------------------------------------------------------------------------------
	void remove_reference(void);
};

#include "sdkreferenceobjectptr.h"

class SDKRTreeNode;
/// Defines a reference object pointer to a @ref SDKRTreeNode.
typedef SDKReferenceObjectPtr<SDKRTreeNode> SDKRTreeNodeRef;

#ifdef BROWSERPLUGININTERFACE_H__
#define SDKBrowserPluginRef BrowserPluginRef
#define SDKBrowserContentNodeRef BrowserContentNodeRef
#define SDKBrowserPreviewData BrowserPreviewData
#define SDKBrowserPreviewInfo BrowserPreviewInfo
#define SDKBrowserPluginInterface BrowserPluginInterface
#endif

#ifdef BROWSERPLUGININTERFACE_H__
#define SDKBrowserContentNode BrowserContentNode
#endif


/// Browser drag message.
#define DRAGTYPE_BROWSER 1017705


#ifdef BROWSERPLUGININTERFACE_H__
#define SDKBrowsePresets BrowseURL
#endif

/// @markPrivate

//----------------------------------------------------------------------------------------
/// The main browser library class.
//----------------------------------------------------------------------------------------
class SDKBrowser
{
private:

	SDKBrowser();
	~SDKBrowser();

public:

#ifndef BROWSERINTERFACE_H__
	/// @name SDKBrowserCategory
	/// @{
	enum
	{
		CategoryPresetNodes		= 0,			///< Preset category.
		CategoryCatalogNodes	= 1,			///< Catalog category.

		ddumdumdimdum
	};
	/// @}

	/// @name SDKBrowserFind
	/// @{
	enum
	{
		FindExactMatch				= 1,			///< Find exact match.
		FindBestMatch					= 2,			///< Find best match.
		ForceDirectoryUpdate	= 4				///< Force directory update.
	};
	/// @}

	/// @name SDKBrowserFileSystemTypes
	/// @{
	enum
	{
		Computer = 0,				///< Computer.
		Drive,							///< Drive.
		DriveCD,						///< CD drive.
		Folder,							///< Folder.
		FolderOpen,					///< Open folder.
		FolderPresets,			///< Presets folder.
		FolderCatalogs,			///< Catalogs folder.
		FolderSearch,				///< Search folder.
		Document,						///< Document folder.
		ThreeDFile,					///< 3D file.
		ImageFile,					///< Image file.
		MovieFile,					///< Movie file.
		Preset							///< Preset.
	};
	/// @}

	/// @name SDKBrowserPresetDb
	/// @{
	enum
	{
		UserPresetDb		= 1,			///< %User preset library database index.
		InvalidPresetDb	= -1			///< Invalid database index.
	};
	/// @}

	/// @name SDKBrowserPresetLibrary
	/// @{
	enum
	{
		ReadOnlyPresetLibrary	= 1,			///< Disable write operations to the preset library (regardless of the file system settings).
		SystemPresetLibrary		= 2,			///< System preset library.
		IgnoreROPresetLibrary	= 4				///< Ignore a read-only flag in the preset library and makes it writable.
	};
	/// @}

	/// @name SDKBrowserPreview
	/// @{
	enum
	{
		PreviewReplace	= 0,			///< Previews are replaced.
		PreviewAppend		= 1				///< Previews are appended.
	};
	/// @}
#endif
	static Bool MountPresetLibrary(const Filename& fn, UInt32 flags, SDKBrowserURL* domain = nullptr);
	static Bool ConvertPresetLibrary(const Filename& fn, Bool ask);
};



/// Content Browser library ID.
#define BROWSER_LIB_ID 1017645

/// @}


/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

struct BrowserMethods
{
	Bool						(*MountPresetLibrary)(const Filename &fn, UInt32 flags, SDKBrowserURL *domain);
	Bool						(*ConvertPresetLibrary)(const Filename& fn, Bool ask);
};

//////////////////////////////////////////////////////////////////////////

struct ReferenceObjectMethods
{
	void	(ReferenceObject::*add_reference)(void);
	void	(ReferenceObject::*remove_reference)(void);
	void	*reserved[6 * C4DPL_MEMBERMULTIPLIER]; // reserved ptmf entries
};

//////////////////////////////////////////////////////////////////////////
struct BrowserLib : public C4DLibrary
{
	ReferenceObjectMethods reference_object;
	BrowserMethods *browser;
};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

class Description;

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_END
#endif

#endif // LIB_BROWSER_H__

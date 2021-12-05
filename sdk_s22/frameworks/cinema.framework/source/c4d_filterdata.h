/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef C4D_FILTERDATA_H__
#define C4D_FILTERDATA_H__

#include "c4d_nodedata.h"
#include "c4d_file.h"

class Filename;
class String;
class BaseContainer;
class BaseDocument;
class BaseBitmap;
class BaseSceneLoader;
class BaseSceneSaver;
class PluginMovieData;
class BaseThread;
class BaseSound;


/// @addtogroup PLUGINFLAG_BITMAPLOADER
/// @ingroup group_enumeration
/// @{
/// Bitmap loader plugin flags.
#define PLUGINFLAG_BITMAPLOADER_MOVIE			(1 << 6)			///< Bitmap loader support movie.
/// @}

//----------------------------------------------------------------------------------------
/// Data structure for loading a movie in a bitmap loader.
//----------------------------------------------------------------------------------------
struct BitmapLoaderAnimatedData
{
	//----------------------------------------------------------------------------------------
	/// Default constructor.
	//----------------------------------------------------------------------------------------
	BitmapLoaderAnimatedData()
	{
		Int32 i; for (i = 0; i < 16; i++)
			moviedata[i] = nullptr;
	}

	Filename	moviename;					///< The file name of the movie.
	void*			moviedata[16];			///< The data for the movie.
};

struct GV_VALUE_HANDLER;

/// @addtogroup BITMAPLOADERACTION
/// @ingroup group_enumeration
/// @{
/// Action types for loading animated bitmaps.
/// @see BitmapLoaderData::LoadAnimated
enum class BITMAPLOADERACTION
{
	INIT = 1,					///< Initialize.
	LOAD = 2,					///< Load.
	FREE = 3,					///< Free.
	INITLAYERSET = 4,	///< Initialize with a layerset. This call is optional but must be called before @ref BITMAPLOADERACTION::INIT. The BaseBitmap pointer must point to  a <tt>const LayerSet*</tt>. @since R19
} MAXON_ENUM_LIST(BITMAPLOADERACTION);
/// @}

//----------------------------------------------------------------------------------------
/// A data class for creating bitmap loader plugins.\n
/// Use RegisterBitmapLoaderPlugin() to register a bitmap loader plugin.
//----------------------------------------------------------------------------------------
class BitmapLoaderData : public BaseData
{
public:
	//----------------------------------------------------------------------------------------
	/// Called to identify a file type as one that can be loaded using the bitmap loader.\n
	/// If possible, the file should not be identified through its suffix, but through the @formatParam{probe} data.
	/// @param[in] name								The filename of the file.
	/// @param[in] probe							The start of a small chunk of data from the start of the file to identify the file type. @cinemaOwnsPointed{array}
	/// @param[in] size								The size of the @formatParam{probe} chunk, usually @em 1024 bytes.
	/// @return												@trueIfOtherwiseFalse{the bitmap loader recognizes the file type}
	//----------------------------------------------------------------------------------------
	virtual Bool Identify(const Filename& name, UChar* probe, Int32 size) = 0;

	//----------------------------------------------------------------------------------------
	/// Called to load an image file into a bitmap.
	/// @param[in] name								The name of the file to load.
	/// @param[in] bm									The bitmap to load the image file into. @cinemaOwnsPointed{bitmap}
	/// @param[in] frame							The frame number for formats containing multiple images in a file such as @em QuickTime or @em AVI.
	/// @return												The result of loading the file: @enumerateEnum{IMAGERESULT}
	//----------------------------------------------------------------------------------------
	virtual IMAGERESULT Load(const Filename& name, BaseBitmap* bm, Int32 frame) = 0;

	//----------------------------------------------------------------------------------------
	/// Called to get the plugin ID of the corresponding BitmapSaverData, if there is one.
	/// @return												The plugin ID of the corresponding bitmap saver, or @formatConstant{nullptr} if there is none.
	//----------------------------------------------------------------------------------------
	virtual Int32 GetSaver(void);

	//----------------------------------------------------------------------------------------
	/// Called to get information on the loading of movies.
	/// @param[in] name								The name of the file to check.
	/// @param[out] frames						Set this to the number of frames.
	/// @param[out] fps								Set this to the number of frames-per-second.
	/// @return												@trueIfOtherwiseFalse{the information could be retrieved}
	//----------------------------------------------------------------------------------------
	virtual Bool GetInformation(const Filename& name, Int32* frames, Float* fps);

	//----------------------------------------------------------------------------------------
	/// Called to accelerate the loading of animated bitmaps.
	/// @note When LoadAnimated() is called with @ref BITMAPLOADERACTION::INIT @formatParam{action} (@formatParam{bm} is @formatConstant{nullptr} and @formatParam{frame} is @em 0)
	/// the loader can open the movie file @formatParam{bd}->@link BitmapLoaderAnimatedData::moviename moviename@endlink and store data in the buffer field @formatParam{bd}->@link BitmapLoaderAnimatedData::moviedata moviedata@endlink<i>[16]</i>.\n
	/// For every call of @ref BITMAPLOADERACTION::INIT, there is a @ref BITMAPLOADERACTION::FREE (@formatParam{bm} is @formatConstant{nullptr} and @formatParam{frame} is 0) in which the image loader closes the movie file.\n
	/// In between @ref BITMAPLOADERACTION::LOAD is called with a valid @formatParam{bm} and @formatParam{frame}.
	///
	/// Loaders that overload @ref LoadAnimated do not need to implement code twice, @ref Load should in that case just look like this:
	/// @code
	/// IMAGERESULT MyLoader::Load(const Filename &name, BaseBitmap *bm, Int32 frame)
	/// {
	/// 	BitmapLoaderAnimatedData data;
	/// 	data.moviename = name;
	///
	/// 	IMAGERESULT result = LoadAnimated(&data, BITMAPLOADERACTION::INIT, nullptr, 0);
	/// 	if (result==IMAGERESULT::OK)
	/// 		err = LoadAnimated(&data, BITMAPLOADERACTION::LOAD, bm, frame);
	/// 	LoadAnimated(&data, BITMAPLOADERACTION::FREE, nullptr, 0);
	///
	/// 	return err;
	/// }
	/// @endcode
	/// @param[in] bd									The bitmap loader animated data. @cinemaOwnsPointed{data}
	/// @param[in] action							The bitmap loader action: @enumerateEnum{BITMAPLOADERACTION}
	/// @param[out] bm								To be filled with the frame bitmap in @ref BITMAPLOADERACTION::LOAD @formatParam{action} call. @cinemaOwnsPointed{bitmap}
	/// @param[in] frame							The frame to put into bitmap @formatParam{bm}.
	/// @return												The result of loading the animated file: @enumerateEnum{IMAGERESULT}
	//----------------------------------------------------------------------------------------
	virtual IMAGERESULT LoadAnimated(BitmapLoaderAnimatedData* bd, BITMAPLOADERACTION action, BaseBitmap* bm, Int32 frame);

	//----------------------------------------------------------------------------------------
	/// Called to extract the sound of animated bitmaps.
	/// @param[in] bd									The bitmap loader animated data. @cinemaOwnsPointed{data}
	/// @param[in] snd								The extracted sound. @cinemaOwnsPointed{sound}
	/// @return												The result of extracting the sound: @enumerateEnum{IMAGERESULT}
	//----------------------------------------------------------------------------------------
	virtual IMAGERESULT ExtractSound(BitmapLoaderAnimatedData* bd, BaseSound* snd);

	//----------------------------------------------------------------------------------------
	/// Called by the <i>Picture Viewer</i> to determine whether a movie has sound or not.
	/// @param[in] bd									The bitmap loader animated data. @cinemaOwnsPointed{data}
	/// @return												The result: @enumerateEnum{IMAGERESULT}
	//----------------------------------------------------------------------------------------
	virtual IMAGERESULT HasSound(BitmapLoaderAnimatedData* bd);
};

/// @addtogroup PLUGINFLAG_BITMAPSAVER
/// @ingroup group_enumeration
/// @{
/// Bitmap saver plugin flags.
#define PLUGINFLAG_BITMAPSAVER_SUPPORT_8BIT					 (1 << 1)			///< Support @em 8-bit bitmaps.
#define PLUGINFLAG_BITMAPSAVER_SUPPORT_16BIT				 (1 << 2)			///< Support @em 16-bit bitmaps.
#define PLUGINFLAG_BITMAPSAVER_SUPPORT_32BIT				 (1 << 0)			///< Support @em 32-bit bitmaps.
#define PLUGINFLAG_BITMAPSAVER_SUPPORT_8BIT_LAYERS	 (1 << 3)			///< Support @em 8-bit layered bitmaps.
#define PLUGINFLAG_BITMAPSAVER_SUPPORT_16BIT_LAYERS	 (1 << 4)			///< Support @em 16-bit layered bitmaps.
#define PLUGINFLAG_BITMAPSAVER_SUPPORT_32BIT_LAYERS	 (1 << 5)			///< Support @em 32-bit layered bitmaps.
#define PLUGINFLAG_BITMAPSAVER_MOVIE								 (1 << 6)			///< Support movies.
#define PLUGINFLAG_BITMAPSAVER_SUPPORT_COLORPROFILES (1 << 7)			///< Support color profiles.
#define PLUGINFLAG_BITMAPSAVER_SUPPORT_SOUND				 (1 << 8)			///< Support sound export. @since R19

#define PLUGINFLAG_BITMAPSAVER_ALLOWOPTIONS	(1 << 27)			///< Flag to identify savers that have the 2em "Edit..." menu enabled.
#define PLUGINFLAG_BITMAPSAVER_FORCESUFFIX	(1 << 26)			///< Ensure that saved files always get the specified suffix.
/// @}

//----------------------------------------------------------------------------------------
/// A data class for creating bitmap saver plugins.\n
/// Use RegisterBitmapSaverPlugin() to register a bitmap saver plugin.
//----------------------------------------------------------------------------------------
class BitmapSaverData : public BaseData
{
public:
	//----------------------------------------------------------------------------------------
	/// Called to save a bitmap to a file.
	/// @param[in] name								The name of the file to save.
	/// @param[in] bm									The bitmap to save the image from. @cinemaOwnsPointed{bitmap}
	/// @param[in] data								The settings container for the bitmap saver. These are stored with the general preferences. @cinemaOwnsPointed{container}
	/// @param[in] savebits						The save bits flags: @enumerateEnum{SAVEBIT}
	/// @return												The result of saving the file: @enumerateEnum{IMAGERESULT}
	//----------------------------------------------------------------------------------------
	virtual IMAGERESULT Save(const Filename& name, BaseBitmap* bm, BaseContainer* data, SAVEBIT savebits);

	//----------------------------------------------------------------------------------------
	/// Called to open the settings dialog for the bitmap loader/saver.
	/// @param[in] data								The settings container for the bitmap saver. These are stored with the general preferences. @cinemaOwnsPointed{container}
	/// @return												@trueIfOtherwiseFalse{the settings dialog opened successfully}
	//----------------------------------------------------------------------------------------
	virtual Bool Edit(BaseContainer* data);

	//----------------------------------------------------------------------------------------
	/// Called to get the maximum number of alpha channels this format supports with the current settings.
	/// @param[in] data								The settings container for the bitmap saver. These are stored with the general preferences. @cinemaOwnsPointed{container}
	/// @return												The number of alpha channels.
	//----------------------------------------------------------------------------------------
	virtual Int32 GetMaxAlphas(BaseContainer* data);

	//----------------------------------------------------------------------------------------
	/// Called to get the maximum resolution of the image format.
	/// @param[in] layers							@trueIfOtherwiseFalse{layers are to be saved}
	/// @return												The maximum resolution supported by the image format.
	//----------------------------------------------------------------------------------------
	virtual Int32 GetMaxResolution(Bool layers);

	//----------------------------------------------------------------------------------------
	/// Corrects the given input size to the preferred saver size.
	/// @since R19
	/// @param[in] settings						Optional settings to use.
	/// @param[in] videoWidth					Resolution width to check.
	/// @param[in] videoHeight				Resolution height to check.
	/// @param[out] videoWidthPadded	Corrected resolution width.
	/// @param[out] videoHeightPadded	Corrected resolution height.
	//----------------------------------------------------------------------------------------
	virtual void CorrectResolution(const BaseContainer* settings, Int32 videoWidth, Int32 videoHeight, Int32& videoWidthPadded, Int32& videoHeightPadded);

	/// @name Movie Saver
	/// @{

	//----------------------------------------------------------------------------------------
	/// Called to open a movie for saving.\n
	/// Here is some code from QuickTime saver:
	/// @code
	/// IMAGERESULT QTMovieSaver::Open(PluginMovieData *&md, const Filename &name, BaseBitmap *bm, BaseContainer *data, SAVEBIT savebits, Int32 fps)
	/// {
	/// 	md = nullptr;
	/// 	MacMovie* sa = nullptr;
	/// 	sa = (MacMovie*)NewMemClear(sizeof(MacMovie));
	/// 	if (!sa)
	/// 		return IMAGERESULT::OUTOFMEMORY;
	/// 	md = (PluginMovieData*)sa;
	/// 	...
	/// }
	/// @endcode
	/// @param[in,out] md							An opaque pointer that can be used by the bitmap saver to store data in (by casting it to the dummy type @c PluginMovieData).
	/// @param[in] name								The name of the file to load.
	/// @param[in] bm									A typical frame of the movie, used for dimensions.
	/// @param[in] data								The settings container for the bitmap saver. These are stored with the general preferences. @cinemaOwnsPointed{container}
	/// @param[in] savebits						The save bits flags: @enumerateEnum{SAVEBIT}
	/// @param[in] fps								The frames per second.
	/// @return												The result of opening a movie: @enumerateEnum{IMAGERESULT}
	//----------------------------------------------------------------------------------------
	virtual IMAGERESULT Open(PluginMovieData*& md, const Filename& name, BaseBitmap* bm, BaseContainer* data, SAVEBIT savebits, Int32 fps);

	//----------------------------------------------------------------------------------------
	/// Called to write a frame to a movie.
	/// @param[in] md									An opaque pointer that can be set in @ref Open and used here.
	/// @param[in] bm									The bitmap frame to save to the movie. @cinemaOwnsPointed{bitmap}
	/// @return												The result of writing a frame to a movie: @enumerateEnum{IMAGERESULT}
	//----------------------------------------------------------------------------------------
	virtual IMAGERESULT Write(PluginMovieData* md, BaseBitmap* bm);

	//----------------------------------------------------------------------------------------
	/// Called to close a movie opened with @ref Open.
	/// @param[in] md									The opaque pointer that can be set in @ref Open and that should be freed and set to @formatConstant{nullptr}.
	/// @return												The result: @enumerateEnum{IMAGERESULT}\n
	/// 															Changed in R19. Previously returned @c void.
	//----------------------------------------------------------------------------------------
	virtual IMAGERESULT Close(PluginMovieData*& md);

	//----------------------------------------------------------------------------------------
	/// Adds sound to a movie.
	/// @param[in] md									An opaque pointer that can be set in @ref Open and used here.
	/// @param[in] snd								The sound to add. @cinemaOwnsPointed{sound}
	/// @return												The result: @enumerateEnum{IMAGERESULT}
	//----------------------------------------------------------------------------------------
	virtual IMAGERESULT AddSound(PluginMovieData* md, BaseSound* snd);

	/// @}
};

/// @addtogroup PLUGINFLAG_SCENELOADER
/// @ingroup group_enumeration
/// @{
/// Scene loader plugin flags.
#define PLUGINFLAG_SCENELOADER_MERGEORIGINAL (1 << 26)
/// @}

/// @addtogroup PLUGINFLAG_SCENEFILTER
/// @ingroup group_enumeration
/// @{
/// Scene filter plugin flags.
#define PLUGINFLAG_SCENEFILTER_DIALOGCONTROL (1 << 27)
/// @}

//----------------------------------------------------------------------------------------
/// A data class for creating scene loader plugins.\n
/// Use RegisterSceneLoaderPlugin() to register a scene loader plugin.
//----------------------------------------------------------------------------------------
class SceneLoaderData : public NodeData
{
public:
	//----------------------------------------------------------------------------------------
	/// Called to identify the file type as one that can be loaded using the scene loader.\n
	/// If possible, the file should not be identified through the suffix, but through the @formatParam{probe} data.
	/// @param[in] node								Equal to <tt>static_cast</tt><@link BaseSceneLoader@endlink*>->Get(). Provided for speed and convenience. @cinemaOwnsPointed{node}
	/// @param[in] name								The name of the file.
	/// @param[in] probe							The start of a small chunk of data from the start of the file to identify the file type. @cinemaOwnsPointed{array}
	/// @param[in] size								The size of the @formatParam{probe} chunk, usually @em 1024 bytes.
	/// @return												@trueIfOtherwiseFalse{the scene loader recognizes the file type}
	//----------------------------------------------------------------------------------------
	virtual Bool Identify(BaseSceneLoader* node, const Filename& name, UChar* probe, Int32 size) = 0;

	//----------------------------------------------------------------------------------------
	/// Loads a file into a document.
	/// @param[in] node								Equal to <tt>static_cast</tt><@link BaseSceneLoader@endlink*>->Get(). Provided for speed and convenience. @cinemaOwnsPointed{node}
	/// @param[in] name								The name of the file.
	/// @param[in] doc								The document to load the scene into. @cinemaOwnsPointed{document}
	/// @param[in] filterflags				The scene filter flags: @enumerateEnum{SCENEFILTER}
	/// @param[in] error							A string to hold any error message if loading fails. @cinemaOwnsPointed{string}
	/// @param[in] bt									The thread for the loading. @cinemaOwnsPointed{thread}
	/// @return												The result of loading the file: @enumerateEnum{FILEERROR}
	//----------------------------------------------------------------------------------------
	virtual FILEERROR Load(BaseSceneLoader* node, const Filename& name, BaseDocument* doc, SCENEFILTER filterflags, maxon::String* error, BaseThread* bt) = 0;

	// Inherited from NodeData
	// virtual Bool Init(GeListNode *node);
	// virtual void Free(GeListNode *node);
	// virtual Bool Read(GeListNode *node, HyperFile *hf, Int32 level);
	// virtual Bool Write(GeListNode *node, HyperFile *hf);
	// virtual Bool Message(GeListNode *node, Int32 type, void *data);
	// virtual Bool CopyTo(NodeData *dest, GeListNode *snode, GeListNode *dnode, COPYFLAGS flags, AliasTrans *trn);
	// virtual void GetBubbleHelp(GeListNode *node, maxon::String &str);
	// virtual BaseDocument* GetDocument(GeListNode *node);
	// virtual Int32 GetBranchInfo(GeListNode *node, BranchInfo *info, Int32 max, GETBRANCHINFO flags);
	// virtual Bool GetDDescription(GeListNode *node, Description *description, DESCFLAGS_DESC &flags);
	// virtual Bool GetDParameter(GeListNode *node, const DescID &id,GeData &t_data,DESCFLAGS_GET &flags);
	// virtual Bool GetDEnabling(GeListNode *node, const DescID &id,const GeData &t_data,DESCFLAGS_ENABLE flags,const BaseContainer *itemdesc);
	// virtual Bool SetDParameter(GeListNode *node, const DescID &id,const GeData &t_data,DESCFLAGS_SET &flags);
	// static NodeData *Alloc(void) { return NewObjClear(MyNodeData); }
	// Inherited from NodeData
};

//----------------------------------------------------------------------------------------
/// A data class for creating scene saver plugins.\n
/// Use RegisterSceneSaverPlugin() to register a scene saver plugin.
//----------------------------------------------------------------------------------------
class SceneSaverData : public NodeData
{
public:
	//----------------------------------------------------------------------------------------
	/// Called to save a document.
	/// @note	Calling @formatParam{doc}->@link BaseDocument::GetDocumentPath GetDocumentPath()@endlink from a scene saver invoked by @ref SaveDocument() is now consistent with the GUI behavior of the export.\n
	///				@formatParam{doc}->@link BaseDocument::GetDocumentPath GetDocumentPath()@endlink now always returns the current path of the document instead of the target path of the file to save for all formats (except @C4D (*.c4d) and @C4D XML (*.xml)).\n
	///				A new document data @ref DOCUMENT_SAVEDOC_DESTINATIONPATH (only set when saving) can be accessed in scene savers to get the destination path of the exported file.
	/// @param[in] node								Equal to <tt>static_cast</tt><@link BaseSceneSaver@endlink*>->Get(). Provided for speed and convenience. @cinemaOwnsPointed{node}
	/// @param[in] name								The name of the file.
	/// @param[in] doc								The document to save the scene from. @cinemaOwnsPointed{document}
	/// @param[in] filterflags				The scene filter flags: @enumerateEnum{SCENEFILTER}
	/// @return												The result of saving the file: @enumerateEnum{FILEERROR}
	//----------------------------------------------------------------------------------------
	virtual FILEERROR Save(BaseSceneSaver* node, const Filename& name, BaseDocument* doc, SCENEFILTER filterflags) = 0;

	// Inherited from NodeData
	// virtual Bool Init(GeListNode *node);
	// virtual void Free(GeListNode *node);
	// virtual Bool Read(GeListNode *node, HyperFile *hf, Int32 level);
	// virtual Bool Write(GeListNode *node, HyperFile *hf);
	// virtual Bool Message(GeListNode *node, Int32 type, void *data);
	// virtual Bool CopyTo(NodeData *dest, GeListNode *snode, GeListNode *dnode, COPYFLAGS flags, AliasTrans *trn);
	// virtual void GetBubbleHelp(GeListNode *node, maxon::String &str);
	// virtual BaseDocument* GetDocument(GeListNode *node);
	// virtual Int32 GetBranchInfo(GeListNode *node, BranchInfo *info, Int32 max, GETBRANCHINFO flags);
	// virtual Bool GetDDescription(GeListNode *node, Description *description, DESCFLAGS_DESC &flags);
	// virtual Bool GetDParameter(GeListNode *node, const DescID &id,GeData &t_data,DESCFLAGS_GET &flags);
	// virtual Bool GetDEnabling(GeListNode *node, const DescID &id,const GeData &t_data,DESCFLAGS_ENABLE flags,const BaseContainer *itemdesc);
	// virtual Bool SetDParameter(GeListNode *node, const DescID &id,const GeData &t_data,DESCFLAGS_SET &flags);
	// static NodeData *Alloc(void) { return NewObjClear(MyNodeData); }
	// Inherited from NodeData
};

//----------------------------------------------------------------------------------------
/// Registers a bitmap loader plugin.
/// @param[in] id									@uniquePluginID
/// @param[in] str								The name of the plugin.\n
/// 															To affect the order that plugins are displayed in menus add <i>"#$n"</i> as a prefix to this name, where @em n is a number.\n
/// 															Lower numbers are displayed before higher numbers. If name is <i>"--"</i> it will show up as a menu separator.
/// @param[in] info								The plugin info flags: @enumerateEnum{PLUGINFLAG} @enumerateEnum{PLUGINFLAG_BITMAPLOADER}
/// @param[in] dat								A data instance for the bitmap loader plugin. @C4D takes over the ownership of the pointed plugin.
/// @return												@trueIfOtherwiseFalse{the bitmap loader plugin was registered}
//----------------------------------------------------------------------------------------
Bool RegisterBitmapLoaderPlugin(Int32 id, const maxon::String& str, Int32 info, BitmapLoaderData* dat);

//----------------------------------------------------------------------------------------
/// Registers a bitmap saver plugin.
/// @param[in] id									@uniquePluginID
/// @param[in] str								The name of the plugin.\n
/// 															To affect the order that plugins are displayed in menus add <i>"#$n"</i> as a prefix to this name, where @em n is a number.\n
/// 															Lower numbers are displayed before higher numbers. If name is <i>"--"</i> it will show up as a menu separator.
/// @param[in] info								The plugin info flags: @enumerateEnum{PLUGINFLAG} @enumerateEnum{PLUGINFLAG_BITMAPSAVER}
/// @param[in] dat								A data instance for the bitmap saver plugin. @C4D takes over the ownership of the pointed plugin.
/// @param[in] suffix							The file format suffix.
/// @return												@trueIfOtherwiseFalse{the bitmap saver plugin was registered}
//----------------------------------------------------------------------------------------
Bool RegisterBitmapSaverPlugin(Int32 id, const maxon::String& str, Int32 info, BitmapSaverData* dat, const maxon::String& suffix);

//----------------------------------------------------------------------------------------
/// Registers a scene loader plugin.
/// @param[in] id									@uniquePluginID
/// @param[in] str								The name of the plugin.\n
/// 															To affect the order that plugins are displayed in menus add <i>"#$n"</i> as a prefix to this name, where @em n is a number.\n
/// 															Lower numbers are displayed before higher numbers. If name is <i>"--"</i> it will show up as a menu separator.
/// @param[in] info								The plugin info flags: @enumerateEnum{PLUGINFLAG} @enumerateEnum{PLUGINFLAG_SCENELOADER} @enumerateEnum{PLUGINFLAG_SCENEFILTER}
/// @param[in] g									The allocator for the scene loader plugin. This is a pointer to a function that creates a new instance of SceneLoaderData with NewObj().
/// @param[in] description				The name of the description resource file to use for the track plugin without @em .res extension, for example @em "Ffiltername".\n
/// 															The name has to be unique, i.e. @em "Tdisplay" cannot be used for 2 different descriptions. See Description Resource for more information.
/// @return												@trueIfOtherwiseFalse{the scene loader plugin was registered}
//----------------------------------------------------------------------------------------
Bool RegisterSceneLoaderPlugin(Int32 id, const maxon::String& str, Int32 info, DataAllocator* g, const maxon::String& description);

//----------------------------------------------------------------------------------------
/// Registers a scene saver plugin.
/// @param[in] id									@uniquePluginID
/// @param[in] str								The name of the plugin.\n
/// 															To affect the order that plugins are displayed in menus add <i>"#$n"</i> as a prefix to this name, where @em n is a number.\n
/// 															Lower numbers are displayed before higher numbers. If name is <i>"--"</i> it will show up as a menu separator.
/// @param[in] info								The plugin info flags: @enumerateEnum{PLUGINFLAG} @enumerateEnum{PLUGINFLAG_SCENEFILTER}
/// @param[in] g									The allocator for the scene saver plugin. This is a pointer to a function that creates a new instance of SceneSaverData with NewObj().
/// @param[in] description				The name of the description resource file to use for the track plugin without @em .res extension, for example @em "Ffiltername".\n
/// 															The name has to be unique, i.e. @em "Tdisplay" cannot be used for 2 different descriptions. See Description Resource for more information.
/// @param[in] suffix							The file format suffix.
/// @return												@trueIfOtherwiseFalse{the scene saver plugin was registered}
//----------------------------------------------------------------------------------------
Bool RegisterSceneSaverPlugin(Int32 id, const maxon::String& str, Int32 info, DataAllocator* g, const maxon::String& description, const maxon::String& suffix);

#endif // C4D_FILTERDATA_H__

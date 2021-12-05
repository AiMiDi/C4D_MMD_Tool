/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef LIB_TOKEN_H__
#define LIB_TOKEN_H__

#include "c4d_library.h"
#include "ge_math.h"
#include "lib_takesystem.h"

#ifdef __API_INTERN__
#include "basedocument.h"
#include "ge_file.h"
#else
#include "c4d_basedocument.h"
#include "c4d_file.h"
#endif

/// @addtogroup group_tokensystemlibrary Token System Library
/// @ingroup group_library
/// @{
/// @since R17.032
/// @see The @ref page_overview_tokensystem article.

/// Token library ID.
#define ID_TOKEN_LIB	431000109

/// @markPrivate
#define INVALID_FRAME	-100000000

//----------------------------------------------------------------------------------------
/// Token hook definition. Use RegisterToken() to register a custom Token.\n
/// Here is an example from the Take Token:
/// @code
/// static String TakeTokenHook(void *data)
/// {
/// 	RenderPathData* rDataPath = (RenderPathData*)data;
/// 	if (!rDataPath)
/// 		return String();
///
/// 	if (rDataPath->_cTake)
/// 		return rDataPath->_cTake->GetName();
///
/// 	return String();
/// }
///
/// if (!RegisterToken(String("take"), String("Current Take Name"), String("MyTake"), TakeTokenHook))
/// {
/// 	return false;
/// }
/// @endcode
/// @see The @ref page_manual_tokensystem_custom example.
//----------------------------------------------------------------------------------------
typedef String TOKENHOOK(void* data);

//----------------------------------------------------------------------------------------
/// Data structure that represents a Token.
//----------------------------------------------------------------------------------------
struct TokenEntry
{
public:
	//----------------------------------------------------------------------------------------
	/// Constructor.
	/// @param[in] token							The keyword for the Token (without "$").
	/// @param[in] help								The help string which identifies the Token.
	/// @param[in] example						An optional example string.
	//----------------------------------------------------------------------------------------
	TokenEntry(const String& token, const String& help, const String& example) : _token(token), _help(help), _example(example) { }

	String	_token;									///< The keyword for the Token (without "$").
	String	_help;									///< The help string which identifies the Token.
	String	_example;								///< An optional example string.
};

//----------------------------------------------------------------------------------------
/// Data structure to collect render information in handling Tokens in render output path.
//----------------------------------------------------------------------------------------
struct RenderPathData
{
public:

	//----------------------------------------------------------------------------------------
	/// Constructor.
	/// @param[in] doc								The BaseDocument used for rendering, can be a clone of original document.
	/// @param[in] rData							The RenderData used for rendering.
	/// @param[in] rBc								The BaseContainer with the render settings (can be different from @c _rData->GetDataInstance() eg. RQ change paths).
	/// @param[in] take								The BaseTake used for rendering.
	/// @param[in] frame							The frame number used for rendering or @ref NOTOK if the frame is not yet recognized.
	/// @param[in] layerName					The pass user name if multipass is activated.
	/// @param[in] layerTypeName			The pass type name if multipass is activated.
	/// @param[in] layerType					The pass ID used for rendering or @ref NOTOK if multipass is not active or not yet recognized.
	/// @param[in] isLight						@formatConstant{true} if the pass is a separated light pass.
	/// @param[in] lightNumber				The light number id.
	/// @param[in] isMaterial					@formatConstant{true} if the pass is a separated reflectance material pass.
	/// @param[in] nodeName						if @ref _isLight is @formatConstant{true} or @ref _isMaterial is @formatConstant{true} store here the object scene name.
	/// @param[in] node								An owner node for certain tokens such as MoGraph cache tokens.
	//----------------------------------------------------------------------------------------
	RenderPathData(BaseDocument* doc = nullptr, RenderData* rData = nullptr, BaseContainer* rBc = nullptr, BaseTake* take = nullptr, Int32 frame = NOTOK, const String& layerName = String(), const String& layerTypeName = String(), Int32 layerType = NOTOK, Bool isLight = false, Int32 lightNumber = NOTOK, Bool isMaterial = false, const String& nodeName = String(), BaseList2D* node = nullptr) : _doc(doc), _rData(rData), _rBc(rBc), _cTake(take), _frame(frame), _layerName(layerName), _layerTypeName(layerTypeName), _layerType(layerType), _isLight(isLight), _lightNumber(lightNumber), _isMaterial(isMaterial), _nodeName(nodeName), _checkUnresolved(false), _node(node) { }

	BaseDocument*		_doc;									///< The BaseDocument used for rendering, can be a clone of original document.
	RenderData*			_rData;								///< The RenderData used for rendering.
	BaseContainer*	_rBc;									///< The BaseContainer with the render settings (can be different from @c _rData->GetDataInstance() eg. RQ change paths).
	BaseTake*				_cTake;								///< The BaseTake used for rendering.
	Int32						_frame;								///< The frame number used for rendering or @ref NOTOK if the frame is not yet recognized.
	String					_layerName;						///< The pass user name if multipass is activated.
	String					_layerTypeName;				///< The pass type name if multipass is activated.
	Int32						_layerType;						///< The pass ID used for rendering or @ref NOTOK if multipass is not active or not yet recognized.
	Bool						_isLight;							///< @formatConstant{true} if the pass is a separated light pass.
	Int32						_lightNumber;					///< The light number id.
	Bool						_isMaterial;					///< @formatConstant{true} if the pass is a separated reflectance material pass.
	String					_nodeName;						///< if @ref _isLight is @formatConstant{true} or @ref _isMaterial is @formatConstant{true} store here the object scene name.
	Bool 						_checkUnresolved;			///< if true warning strings will be used for the Tokens that cannot be resolved.
	BaseList2D*			_node;								///< An owner node for certain tokens such as MoGraph cache tokens. @since R18
};

//----------------------------------------------------------------------------------------
/// Fills a list will all available Token entries.
/// @param[out] tokenList					The array to be filled.
/// @return												@trueIfOtherwiseFalse{successful}
//----------------------------------------------------------------------------------------
Bool GetAllTokenEntries(maxon::BaseArray<TokenEntry>& tokenList);

//----------------------------------------------------------------------------------------
/// Converts tokenized path String to standard String by replacing all Tokens with correct values if found.
/// @param[in] path								The original path String.
/// @param[in] rpData							The data used to extract value for Tokens. @callerOwnsPointed{RenderPathData}
/// @return												The converted String, or the original path if any error.
//----------------------------------------------------------------------------------------
String StringConvertTokens(const String& path, const RenderPathData* rpData);

//----------------------------------------------------------------------------------------
/// Converts tokenized path Filename into standard Filename by replacing all Tokens with correct values if found.
/// @param[in] path								The original path Filename.
/// @param[in] rpData							The data used to extract value for Tokens. @callerOwnsPointed{RenderPathData}
/// @return												The converted FileName, or the original path if any error.
//----------------------------------------------------------------------------------------
Filename FilenameConvertTokens(const Filename& path, const RenderPathData* rpData);

//----------------------------------------------------------------------------------------
/// Converts tokenized path String to standard String by replacing all Tokens with correct values if found. Tokens added to @formatParam{exclude} array are ignored.
/// @param[in] path								The original path String.
/// @param[in] rpData							The data used to extract value for the Tokens. @callerOwnsPointed{RenderPathData}
/// @param[in] exclude						A list of Tokens strings to be ignored.
/// @return												The converted String or the original path if any error.
//----------------------------------------------------------------------------------------
String StringConvertTokensFilter(const String& path, const RenderPathData* rpData, const maxon::BaseArray<String>& exclude);

//----------------------------------------------------------------------------------------
/// Converts tokenized path Filename into standard Filename by replacing all Tokens with correct values if found. Tokens added to @formatParam{exclude} array are ignored.
/// @param[in] path								The original path Filename.
/// @param[in] rpData							The data used to extract value for Tokens. @callerOwnsPointed{RenderPathData}
/// @param[in] exclude						A list of Tokens strings to be ignored.
/// @return												The converted FileName or the original path if any error.
//----------------------------------------------------------------------------------------
Filename FilenameConvertTokensFilter(const Filename& path, const RenderPathData* rpData, const maxon::BaseArray<String>& exclude);

//----------------------------------------------------------------------------------------
/// Searches for the first Token in path. If it is found and it is in-between "/.." returns the preceeding directory path String.
/// @param[in] path								The original path String.
/// @return												The root String path, or the original String if no Token is found.
//----------------------------------------------------------------------------------------
String StringExtractRoot(const String& path);

//----------------------------------------------------------------------------------------
/// Searches for the first Token in path. If it is found and it is in-between "/..", returns the preceeding directory path Filename.
/// @param[in] path								The original path Filename.
/// @return												The root Filename path, or the original Filename if no Token is found.
//----------------------------------------------------------------------------------------
Filename FilenameExtractRoot(const Filename& path);

//----------------------------------------------------------------------------------------
/// Splits path in two parts if a Token is found as sub-folders and extracts root and filename path starting at sub-folder.
/// @param[in] path								The original path Filename.
/// @param[out] root							The root Filename path.
/// @param[out] fileName					The sub-folder and filename.
/// @return												@trueIfOtherwiseFalse{a Token is found}
//----------------------------------------------------------------------------------------
Bool FilenameSlicePath(const Filename& path, Filename& root, Filename& fileName);

//----------------------------------------------------------------------------------------
/// Registers a new Token that can be used in a render filename.
/// @note	The key is the identifier for the Token and has to be unique. For this reason identify your plugin in the Token key as a prefix.\n
/// 			Example: "myplug.pass" instead of just "pass" as it will collide wit the generic "pass" Token definition.
/// @param[in] key								The key string for the Token itself without the "$".
/// @param[in] help								An help string used to show the Token in the menu.
/// @param[in] example						An example string for the use of the Token.
/// @param[in] hook								An implemented @ref TOKENHOOK used to define the string to replace the Token.
/// @return												@trueIfOtherwiseFalse{successful}
//----------------------------------------------------------------------------------------
Bool RegisterToken(const String& key, const String& help, const String& example, TOKENHOOK* hook);

//----------------------------------------------------------------------------------------
/// Registers a new Token that can be used in a render filename but hides it from the render filename menu.
/// @note	The key is the identifier for the Token and has to be unique. For this reason identify your plugin in the Token key as a prefix.\n
/// 			Example: "myplug.pass" instead of just "pass" as it will collide wit the generic "pass" Token definition.
/// @since R18
/// @param[in] key								The key string for the Token itself without the "$".
/// @param[in] help								An help string used to show the Token in the menu.
/// @param[in] example						An example string for the use of the Token.
/// @param[in] hook								An implemented @ref TOKENHOOK used to define the string to replace the Token.
/// @return												@trueIfOtherwiseFalse{successful}
//----------------------------------------------------------------------------------------
Bool RegisterHiddenToken(const String& key, const String& help, const String& example, TOKENHOOK* hook);

/// @}

/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

//----------------------------------------------------------------------------------------
/// Registers a new Python Token that can be used in a render filename.
/// @note	The key is the identifier for the Token and has to be unique. For this reason identify your plugin in the Token key as a prefix.\n
/// 			Example: "myplug.pass" instead of just "pass" as it will collide wit the generic "pass" Token definition.
/// @param[in] key								The key string for the Token itself without the "$".
/// @param[in] help								An help string used to show the Token in the menu.
/// @param[in] example						An example string for the use of the Token.
/// @param[in] callback								A pointer to a PyObject representing a function, that accept one parameter and return a String used to define the string to replace the Token.
/// @return												@trueIfOtherwiseFalse{successful}
//----------------------------------------------------------------------------------------
Bool RegisterPythonToken(const String& key, const String& help, const String& example, void* callback);

//----------------------------------------------------------------------------------------
/// Registers a new Python Token that can be used in a render filename but hides it from the render filename menu.
/// @note	The key is the identifier for the Token and has to be unique. For this reason identify your plugin in the Token key as a prefix.\n
/// 			Example: "myplug.pass" instead of just "pass" as it will collide wit the generic "pass" Token definition.
/// @since R20
/// @param[in] key								The key string for the Token itself without the "$".
/// @param[in] help								An help string used to show the Token in the menu.
/// @param[in] example						An example string for the use of the Token.
/// @param[in] callback								A pointer to a PyObject representing a function, that accept one parameter and return a String used to define the string to replace the Token.
/// @return												@trueIfOtherwiseFalse{successful}
//----------------------------------------------------------------------------------------
Bool RegisterPythonHiddenToken(const String& key, const String& help, const String& example, void* callback);

struct TokenLibrary : public C4DLibrary
{
	Bool			(*GetAllTokenEntries)							(maxon::BaseArray<TokenEntry>& tokenList);
	String		(*StringConvertTokens)						(const String& path, const RenderPathData* rpData);
	Filename	(*FilenameConvertTokens)					(const Filename& path, const RenderPathData* rpData);
	String		(*StringExtractRoot)							(const String& path);
	Filename	(*FilenameExtractRoot)						(const Filename& path);
	Bool			(*FilenameSlicePath)							(const Filename& path, Filename& root, Filename& fileName);
	Bool			(*RegisterToken)									(const String& key, const String& help, const String& example, TOKENHOOK* hook);
	String	 	(*StringConvertTokensFilter)  		(const String& path, const RenderPathData* rpData, const maxon::BaseArray<String>& exclude);
	Filename	(*FilenameConvertTokensFilter) 		(const Filename& path, const RenderPathData* rpData, const maxon::BaseArray<String>& exclude);
	Bool			(*RegisterHiddenToken)						(const String& key, const String& help, const String& example, TOKENHOOK* hook);
	Bool(*RegisterPythonToken)							(const String& key, const String& help, const String& example, void* callback);
	Bool(*RegisterPythonHiddenToken)							(const String& key, const String& help, const String& example, void* callback);

};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

#endif // LIB_TOKEN_H__

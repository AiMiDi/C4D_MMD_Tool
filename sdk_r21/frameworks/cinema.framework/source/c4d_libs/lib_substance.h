/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef LIB_SUBSTANCE_H__
#define LIB_SUBSTANCE_H__

#include "c4d_library.h"
#ifdef __API_INTERN__
#include "basedocument.h"
#else
#include "c4d_basedocument.h"
#endif

/// @addtogroup group_substancelibrary Substance Library
/// @ingroup group_library
/// @{
/// @since R18
/// @see The @ref page_overview_substances article.
///
///
/// The Substance library contains everything needed to control the Substance Engine integration in @C4D.
/// Main topics are:
///   - Importing Substance assets into @C4D
///   - Creating materials from Substance assets and/or manually mapping Substance output channels into @C4D materials (or other places)
///   - Manipulating Substance Input parameters
///
/// Importing Substance Assets:
/// @note There's also the command ::ID_SUBSTANCE_COMMAND_LOADASSET, which may be shorter, if user interaction is wanted.
///
/// @code
/// void MySubstanceImport()
/// {
///   BaseDocument* const doc = GetActiveDocument();
///   if (doc == nullptr)
///     return;
///
///   // Setup import parameters
///   Filename fn = "some_path/nice_substance.sbsar";
///   SUBSTANCE_IMPORT_COPY copyMode = SUBSTANCE_IMPORT_COPY::NO; // do not copy the Substance archive into the project directory and use absolute path to refer to the file
///   const Bool errPopup = false; // Don't open any error messages
///   const Bool addUndo = true; // Yes, please add an undo step for the import
///   const Bool noMaterial = true; // No material will be created on import
///   BaseList2D* myImportedAsset = nullptr;
///   SUBSTANCE_IMPORT_RESULT result;
///
///   // Import
///   doc->StartUndo(); // DON'T FORGET, mandatory since we chose to add an undo step
///   result = ImportSubstance(doc, fn, copyMode, errPopup, addUndo, noMaterial, &myImportedAsset);
///   doc->EndUndo(); // DON'T FORGET, mandatory since we chose to add an undo step
///   if (result != SUBSTANCE_IMPORT_RESULT::SUCCESS)
///   {
///     // something went wrong, handle error here...
///     return;
///   }
///   // The substance got successfully inserted into the document
///   // ...
///   // return;
/// }
/// @endcode
///
/// Auto-creating basic material from a Substance:
/// @code
/// void MySubstanceCreateMaterial()
/// {
///   BaseDocument* const doc = GetActiveDocument();
///   if (doc == nullptr)
///     return;
///   BaseList2D* asset = GetFirstSubstance(doc);
///   if (asset == nullptr)
///   {
///     // No Substance asset in the scene
///     return;
///   }
///
///   const Int32 graphIdx = 0; // Use the first graph of the Substance
///   const SUBSTANCE_MATERIAL_MODE mode = SUBSTANCE_MATERIAL_MODE::METALLIC; // Use PBR metallic/roughness workflow
///   BaseMaterial* const mat = CreateMaterial(myImportedAsset, graphIdx, mode);
///   if (mat == nullptr)
///   {
///     // Failed to create material
///     return;
///   }
///   doc->InsertMaterial(mat);
/// }
/// @endcode
///
/// Iterate over all graphs, inputs and outputs of a Substance:
/// @code
/// void MyPrintAllSubstances()
/// {
///   BaseDocument* const doc = GetActiveDocument();
///   if (doc == nullptr)
///     return;
///   AutoAlloc<AtomArray> arrSubstances;
///   if (arrSubstances == nullptr)
///     return;
///   const Bool onlySelected = false; // Get all Substances in the document
///   GetSubstances(doc, arrSubstances, onlySelected);
///   for (Int32 idxSubstance = 0; idxSubstance < arrSubstances->GetCount(); ++idxSubstance)
///   {
///     BaseList2D* const asset = static_cast<BaseList2D*>(arrSubstances->GetIndex(idxSubstance));
///     if (asset == nullptr)
///       continue; // This should not happen, but safe is safe
///
///     GePrint("Substance: " + asset->GetName();
///
///     String graphName = "";
///     void* lastGraph = nullptr, graph = nullptr;
///
///     while (graph = GetSubstanceGraph(asset, lastGraph, graphName))
///     {
///       GePrint("  Graph: " + graphName);
///
///       UInt32 inputUid;
///       Int32 inputDescId;
///       Int32 inputNumElements;
///       SUBSTANCE_INPUT_TYPE inputType;
///       String inputName;
///       void* lastInput = nullptr, input = nullptr;
///
///       GePrint("  Inputs:");
///       while (input = GetSubstanceInput(asset, graph, lastInput, inputUid, inputDescId, inputNumElements, inputType, inputName))
///       {
///         GePrint("    " + inputName + " (" + String::HexToString(inputUid) + ", " + String::IntToString(inputDescId) + ", " + String::IntToString(inputNuMElements) + ", " + String::IntToString((Int32)inputType) + ")");
///         lastInput = input;
///       }
///
///       UInt32 outputUid;
///       SUBSTANCE_OUTPUT_TYPE outputType;
///       String outputName;
///       void* lastOutput = nullptr, output = nullptr;
///
///       GePrint("  Outputs:");
///       while (output = GetSubstanceOutput(asset, graph, lastOutput, outputUid, outputType, outputName, nullptr))
///       {
///         GePrint("    " + outputName + " (" + String::HexToString(outputUid) + ", " + String::IntToString((Int32)outputType) + ")");
///         lastOutput = output;
///       }
///       lastGraph = graph;
///     }
///   }
/// }
/// @endcode
///
/// Changing Substance input parameters:
///
/// This basically works the same as with every other NodeData based entity in @C4D, via SetParameter(). @see SUBSTANCE_INPUT_TYPE
/// @warning Under no circumstances the BaseContainer of a Substance assets should be accessed directly.
/// The IDs for use with SetParameter() can be obtained via GetSubstanceInput().
///
///
/// Chapter Substance shader and its parameters:
///
/// The Substance shader has two parameters, ::SUBSTANCESHADER_ASSET and ::SUBSTANCESHADER_CHANNEL.
///
/// - ::SUBSTANCESHADER_ASSET is a link to a Substance asset.
/// - ::SUBSTANCESHADER_CHANNEL stores the outputUid (to be obtained via GetSubstanceOutput()) of the selected Substance output channel.
//-------------------------------------------------------------------------------------------------

/// @addtogroup group_substance_plugin_ids Substance Plugin IDs
/// @ingroup group_enumeration
/// @{
/// Substance Plugin IDs
static const Int32 ID_SUBSTANCE_ASSET										= 1032106;		///< ID of the Substance asset. @since R18
static const Int32 ID_SUBSTANCE_SHADER									= 1032171;		///< ID of the Substance shader. @since R18
static const Int32 ID_SUBSTANCE_LIBRARY									= 1034607;		///< ID of Substance library. @since R18
static const Int32 ID_SUBSTANCE_PREFERENCES							= 1036471;		///< ID of Substance preferences. @since R18
static const Int32 ID_SUBSTANCE_PRESET									= 1036526;		///< ID of the Substance content browser preset. @since R18
/// @}

/// @addtogroup group_substance_command_ids Substance Command IDs
/// @ingroup group_enumeration
/// @{
/// Substance Command IDs, use with CallCommand()
static const Int32 ID_SUBSTANCE_COMMAND_OPENMANAGER									= 1032108;		///< Opens the Substance Asset Manager. @since R18
static const Int32 ID_SUBSTANCE_COMMAND_SYNCTRCLIENTS								= 1036066;		///< Synchronizes the Substance Engine setting of all TeamRender clients based on the setting in Substance preferences. @since R18

static const Int32 ID_SUBSTANCE_COMMAND_LOADASSET										= 1032109;		///< Opens a file requester and imports the chosen Substance asset into the active document. @since R18
static const Int32 ID_SUBSTANCE_COMMAND_LOADFOLDER									= 1038450;		///< Opens a folder requester and import all Substance assets from selected folder into the active document. @since R19
static const Int32 ID_SUBSTANCE_COMMAND_REIMPORT										= 1036975;		///< Reloads the Substance assets currently selected in Substance Asset Manager. @since R18

static const Int32 ID_SUBSTANCE_COMMAND_CUT													= 1038399;		///< Cuts selected Substance Assets to clipboard. @since R19
static const Int32 ID_SUBSTANCE_COMMAND_COPY												= 1038400;		///< Copies selected Substance Assets to clipboard. @since R19
static const Int32 ID_SUBSTANCE_COMMAND_PASTE												= 1038401;		///< Pastes Substance Assets from clipboard. @since R19
static const Int32 ID_SUBSTANCE_COMMAND_REMOVE											= 1038402;		///< Deletes selected Substance Assets from scene. @since R19
static const Int32 ID_SUBSTANCE_COMMAND_REMOVEUNUSED								= 1038403;		///< Deletes all unused Substance Assets from scene. @since R19
static const Int32 ID_SUBSTANCE_COMMAND_SELECT_ALL									= 1037143;		///< Selects all Substance assets in the active document. @since R18
static const Int32 ID_SUBSTANCE_COMMAND_DESELECT_ALL								= 1037144;		///< De-selects all Substance assets in the active document. @since R18
static const Int32 ID_SUBSTANCE_COMMAND_SELECTFROMMATERIAL					= 1038404;		///< Selects Substance Assets based on selected materials. @since R19
static const Int32 ID_SUBSTANCE_COMMAND_SELECTFROMMARKEDMATERIAL		= 1038405;		///< Selects Substance Assets based on marked materials. @since R19
static const Int32 ID_SUBSTANCE_COMMAND_SELECTFROMOBJECT						= 1038406;		///< Selects Substance Assets based on selected objects/tags. @since R19
static const Int32 ID_SUBSTANCE_COMMAND_SELECTMATERIALS							= 1038407;		///< Selects materials using the selected Substance Assets. @since R19
static const Int32 ID_SUBSTANCE_COMMAND_SELECTOBJECTS								= 1038408;		///< Selects objects using the selected Substance Assets. @since R19
static const Int32 ID_SUBSTANCE_COMMAND_ENABLEALL										= 1038409;		///< Enables all Substance Assets. @since R19
static const Int32 ID_SUBSTANCE_COMMAND_DISABLEALL									= 1038410;		///< Disables all Substance Assets. @since R19
static const Int32 ID_SUBSTANCE_COMMAND_OPENPREFS										= 1038411;		///< Opens Substance preferences page. @since R19

static const Int32 ID_SUBSTANCE_COMMAND_CREATEMATERIAL							= 1038412;		///< Creates standard material from selected Substance Assets. @since R19
static const Int32 ID_SUBSTANCE_COMMAND_CREATEMATERIALMETALLIC			= 1038413;		///< Creates metallic material from selected Substance Assets. @since R19
static const Int32 ID_SUBSTANCE_COMMAND_CREATEMATERIALGLOSSY				= 1038414;		///< Creates glossy material from selected Substance Assets. @since R19
static const Int32 ID_SUBSTANCE_COMMAND_DUPLICATE										= 1038415;		///< Duplicates selected Substance Assets. @since R19
static const Int32 ID_SUBSTANCE_COMMAND_DUPLICATEWITHMATERIAL				= 1038416;		///< Duplicates selected Substance Assets together with materials using them. @since R19

static const Int32 ID_SUBSTANCE_COMMAND_IMPORTPRESET								= 1038417;		///< Applies a Substance preset to the selected Substance Assets. @since R19
static const Int32 ID_SUBSTANCE_COMMAND_IMPORTPRESETMERGE						= 1038418;		///< Merges a Substance preset into the selected Substance Assets. @since R19
static const Int32 ID_SUBSTANCE_COMMAND_EXPORTPRESET								= 1038419;		///< Exports a Substance preset for the selected Substance Assets. @since R19

static const Int32 ID_SUBSTANCE_COMMAND_DISKCACHESELECTED						= 1038420;		///< Creates/updates disk cache for selected Substance Assets. @since R19
static const Int32 ID_SUBSTANCE_COMMAND_DISKCACHECHANGED						= 1038421;		///< Creates/updates disk cache for changed Substance Assets. @since R19
static const Int32 ID_SUBSTANCE_COMMAND_DISKCACHEALL								= 1038422;		///< Creates/updates disk cache for all Substance Assets. @since R19
static const Int32 ID_SUBSTANCE_COMMAND_DISKCACHECLEARSELECTED			= 1038423;		///< Deletes disk cache for selected Substance Assets. @since R19
static const Int32 ID_SUBSTANCE_COMMAND_DISKCACHECLEARALL						= 1038424;		///< Deletes disk cache for all Substance Assets. @since R19
/// @}

/// @addtogroup group_substance_message_ids Substance Message IDs
/// @ingroup group_enumeration
/// @{
/// Substance Message IDs, use with Message()
static const Int32 MSG_SUBSTANCE_SHD_GETBITMAP					= 1035319;		///< Send to a Substance shader to request its texture, thought for external renderers, the corresponding data is SubstanceShdGetBitmap. @since R18
/// @}

//----------------------------------------------------------------------------------------
/// Data structure for message ::MSG_SUBSTANCE_SHD_GETBITMAP.
/// @see group_substance_message_ids
/// @since R18
//----------------------------------------------------------------------------------------
struct SubstanceShdGetBitmap
{
	BaseBitmap*			_pBmp;			///< Pass as @formatConstant{nullptr}, contains pointer to texture bitmap on return. @senderOwnsPointed{bitmap}
	ICONDATAFLAGS		_bmpflags;	///< Pass ::ICONDATAFLAGS::NONE. Currently not in use..

	//----------------------------------------------------------------------------------------
	/// Default constructor.
	//----------------------------------------------------------------------------------------
	SubstanceShdGetBitmap() : _pBmp(nullptr), _bmpflags(ICONDATAFLAGS::NONE)
	{
	}
};

/// @addtogroup SUBSTANCE_MATERIAL_MODE
/// @ingroup group_enumeration
/// @{
/// @since R18
/// @note Values matches @em Fsubstanceimport resource.
enum class SUBSTANCE_MATERIAL_MODE
{
	STANDARD		= 0,		///< Create standard material.
	METALLIC		= 1,		///< Create metallic material.
	GLOSSY			= 2,		///< Create glossy material.
	AUTO				= 3,		///< Use heuristic to choose one of the three above (see @C4D's user manual).
	NONE				= 100,	///< Do not create material.
} MAXON_ENUM_LIST(SUBSTANCE_MATERIAL_MODE);
/// @}

/// @addtogroup SUBSTANCE_IMPORT_RESULT
/// @ingroup group_enumeration
/// @{
/// @since R18
enum class SUBSTANCE_IMPORT_RESULT
{
	SUCCESS,					///< Success.
	DOESNOTEXIST,			///< File not found.
	NOTANASSET,				///< Wrong file format.
	UNKNOWNERROR,			///< On memory error or when invalid parameters were passed.
} MAXON_ENUM_LIST(SUBSTANCE_IMPORT_RESULT);
/// @}

/// @addtogroup SUBSTANCE_IMPORT_COPY
/// @ingroup group_enumeration
/// @{
/// @since R18
/// @note Values matches @em Fsubstanceimport resource.
enum class SUBSTANCE_IMPORT_COPY
{
	YES,	///< Automatically copy file to project directory (relative file path).
	NO,		///< Do not copy file to project directory (absolute file path).
	ASK,	///< Ask user.
} MAXON_ENUM_LIST(SUBSTANCE_IMPORT_COPY);
/// @}

/// @addtogroup SUBSTANCE_INPUT_TYPE
/// @ingroup group_enumeration
/// @{
/// @since R18
enum class SUBSTANCE_INPUT_TYPE
{
	INTEGER,			///< ::Int32 Integer, one DescID.
	INTEGER_2,		///< ::Int32 Two component integer vector, two DescID.
	INTEGER_3,		///< ::Int32 Three component integer vector, three DescID objects.
	INTEGER_4,		///< ::Int32 Four component integer vector, four DescID objects.
	BOOL,					///< ::Bool Boolean, one DescID.
	FLOAT,				///< ::Float Float, one DescID.
	FLOAT_2,			///< ::Float Two component float vector, two DescID objects.
	FLOAT_3,			///< ::Float Three component float vector, three DescID objects.
	FLOAT_4,			///< ::Float Four component float vector, four DescID objects.
	IMAGE,				///< Filename Image input, one DescID.
	STRING,				///< String String, one DescID.
	COLOR_RGB,		///< ::Vector RGB color vector, one DescID.
	COLOR_RGBA,		///< ::Vector and ::Float RGBA color vector, two DescID objects.
	RESOLUTION,		///< ::Int32 Substance output resolution, two DescID objects , integer, range 4 to 11, 2^n pixels (16 pixels to 2048 pixels)
} MAXON_ENUM_LIST(SUBSTANCE_INPUT_TYPE);
/// @}

/// @addtogroup SUBSTANCE_OUTPUT_TYPE
/// @ingroup group_enumeration
/// @{
/// @since R18
enum class SUBSTANCE_OUTPUT_TYPE
{
	DIFFUSE,
	BASECOLOR,
	OPACITY,
	EMISSIVE,
	AMBIENT,
	AMBIENTOCCLUSION,
	MASK,
	NORMAL,
	BUMP,
	HEIGHT,
	DISPLACEMENT,
	SPECULAR,
	SPECULARLEVEL,
	SPECULARCOLOR,
	GLOSSINESS,
	ROUGHNESS,
	ANISOTROPYLEVEL,
	ANISOTROPYANGLE,
	TRANSMISSIVE,
	REFLECTION,
	REFRACTION,
	ENVIRONMENT,
	IOR,
	SCATTERING0,
	SCATTERING1,
	SCATTERING2,
	SCATTERING3,
	METALLIC,
	ANY,
	UNKNOWN,
	INTERNAL_COUNT
} MAXON_ENUM_LIST(SUBSTANCE_OUTPUT_TYPE);
/// @}

/// @name Create
/// @{

//----------------------------------------------------------------------------------------
/// Imports a Substance Asset file (.sbsar) into @formatParam{doc}.
/// @since R18
/// @param[in] doc								The document to import into.
/// @param[in] fn									The Substance Asset file.
/// @param[in,out] copyFile				The copy file flag: @enumerateEnum{SUBSTANCE_IMPORT_COPY}. Determines if Substance Asset files are copied into the project folder (and therefore referenced with relative path).\n
///																If set to ::SUBSTANCE_IMPORT_COPY::ASK, user's choice will be returned.\n
///																Note: When set to ::SUBSTANCE_IMPORT_COPY::ASK, the function obviously has to be called in a context, where user interaction is allowed.
/// @param[in] errPopup						If set to @formatConstant{true}, problems will be communicated to the user with a message requester.\n
///																Note: When set to @formatConstant{true}, the function obviously has to be called in a context, where user interaction is allowed.
/// @param[in] addUndo						If set to @formatConstant{true}, an undo step will be added for the import. Caller has to care for the surrounding BaseDocument::StartUndo() and BaseDocument::EndUndo() calls.
/// @param[in] createMaterial			Set to @formatConstant{true}, to have a material created based on the configuration in preferences. Set to @formatConstant{false}, to suppress any creation of materials.
/// @param[in,out] assetPtr				A pointer to a Substance asset pointer. If not @formatConstant{nullptr}, the pointer to the imported Substance Asset will be returned here.
/// @return												The result for the import: @enumerateEnum{SUBSTANCE_IMPORT_RESULT}
//----------------------------------------------------------------------------------------
SUBSTANCE_IMPORT_RESULT ImportSubstance(BaseDocument* const doc, const Filename& fn, SUBSTANCE_IMPORT_COPY& copyFile, Bool errPopup, Bool addUndo, Bool createMaterial, BaseList2D** assetPtr);

//----------------------------------------------------------------------------------------
/// Creates a @C4D standard material from @formatParam{asset}.
/// @since R18
/// @param[in] asset							The Substance asset.
/// @param[in] graphIndex					The index of the graph to use (for multi-graph Substances).
/// @param[in] mode								The material creation mode: @enumerateEnum{SUBSTANCE_MATERIAL_MODE}
/// @return												The created material. @callerOwnsPointed{material}
//----------------------------------------------------------------------------------------
BaseMaterial* CreateMaterial(BaseList2D* const asset, Int32 graphIndex, SUBSTANCE_MATERIAL_MODE mode);

//----------------------------------------------------------------------------------------
/// Creates a Substance shader linked to @formatParam{asset}.
/// @since R18
/// @param[in] asset							The Substance asset (may be @formatConstant{nullptr}).
/// @return												The created Substance shader. @callerOwnsPointed{shader}
//----------------------------------------------------------------------------------------
BaseShader* CreateSubstanceShader(BaseList2D* const asset);

//----------------------------------------------------------------------------------------
/// Creates a Substance shader, links it to @formatParam{asset}, sets the Substance output to @formatParam{outputUid} and assigns the shader to @formatParam{channelId} of @formatParam{c4dMaterial}.
/// @since R18
/// @param[in] asset							The Substance asset, the pointed Substance asset needs to be part of the document.
/// @param[in] c4dMaterial				The Material.
/// @param[in] channelId					The channel ID: @enumerateEnum{CHANNEL}
/// @param[in] outputUid					The unique ID of the Substance output to use.
/// @param[in] addUndo						If set to @formatConstant{true}, an undo step will be added for the import. Caller has to care for the surrounding BaseDocument::StartUndo() and BaseDocument::EndUndo() calls.
/// @return												@trueIfOtherwiseFalse{successful}
//----------------------------------------------------------------------------------------
Bool AssignChannelToMaterial(BaseList2D* const asset, Material* const c4dMaterial, Int32 channelId, Int32 outputUid, Bool addUndo);

/// @}

/// @name Get and Insert
/// @{

//----------------------------------------------------------------------------------------
/// Retrieves a pointer to the first Substance asset in @formatParam{doc}.
/// @since R18
/// @param[in] doc								The document.
/// @return												The first Substance asset or @formatConstant{nullptr}, if none exists. @cinemaOwnsPointed{Substance asset}
//----------------------------------------------------------------------------------------
BaseList2D* GetFirstSubstance(BaseDocument* const doc);

//----------------------------------------------------------------------------------------
/// Retrieves all (or only selected) substances assets @formatParam{doc}.
/// @since R18
/// @param[in] doc								The document.
/// @param[in] arr								The AtomArray to fill. @callerOwnsPointed{array}
/// @param[in] onlySelected				Set to @formatConstant{true} to get only selected Substance assets.
//----------------------------------------------------------------------------------------
void GetSubstances(BaseDocument* const doc, AtomArray* arr, Bool onlySelected);

//----------------------------------------------------------------------------------------
/// Inserts @formatParam{asset} into @formatParam{doc} (as last element).
/// @since R18
/// @param[in] doc								The document.
/// @param[in] asset							The Substance asset. On success @C4D takes over the ownership of the pointed Substance asset.
/// @return												@trueIfOtherwiseFalse{success}
//----------------------------------------------------------------------------------------
Bool InsertLastSubstance(BaseDocument* const doc, BaseList2D* asset);

/// @}

/// @name Graphs, Inputs, Outputs
/// @{

//----------------------------------------------------------------------------------------
/// Retrieves the Substance graph. This function may be used to iterate over the graphs of @formatParam{asset}.
/// @since R18
/// @param[in] asset							The Substance asset.
/// @param[in] prevGraph					Pass @formatConstant{nullptr} to get the first graph, pass a graph pointer to get the following graph.
/// @param[out] name							Name of the returned graph. Only valid if return value != @formatConstant{nullptr}.
/// @return												A pointer to identify the graph, may not be dereferenced. @formatConstant{nullptr} if graph is not available. @cinemaOwnsPointed{graph}
//----------------------------------------------------------------------------------------
void* GetSubstanceGraph(BaseList2D* const asset, void* const prevGraph, String& name);

//----------------------------------------------------------------------------------------
/// Retrieves a Substance input of an asset. This function may be used to iterate over the inputs of a @formatParam{graph} of @formatParam{asset}.
/// @since R18
/// @param[in] asset							The Substance asset.
/// @param[in] graph							The graph.
/// @param[in] prevInput					Pass @formatConstant{nullptr} to get the first input, pass an input pointer to get the following input.
/// @param[out] inputUid					The unique ID of the input. Only valid if return value != @formatConstant{nullptr}.
/// @param[out] firstId						The ID of the first component of the input parameter in @C4D (see also @formatParam{numElements}). This ID can be used to create a DescID for C4DAtom::SetParameter(). Only valid if return value != @formatConstant{nullptr}.
/// @param[out] numElements				The number of description elements used in @C4D to represent the Substance input parameter. Only valid if return value != @formatConstant{nullptr}.
/// @param[out] type							The data type of the input: @enumerateEnum{SUBSTANCE_INPUT_TYPE}. Only valid if return value != @formatConstant{nullptr}.
/// @param[out] name							Name of the returned input. Only valid if return value != @formatConstant{nullptr}.
/// @return												A pointer to identify the input, may not be dereferenced. @formatConstant{nullptr} if input is not available. @cinemaOwnsPointed{input}
//----------------------------------------------------------------------------------------
void* GetSubstanceInput(BaseList2D* const asset, void* const graph, void* const prevInput, UInt32& inputUid, Int32& firstId, Int32& numElements, SUBSTANCE_INPUT_TYPE& type, String& name);

//----------------------------------------------------------------------------------------
/// Retrieves a Substance input of an asset. This function may be used to iterate over the outputs of a @formatParam{graph} of @formatParam{asset}.
/// @since R18
/// @param[in] asset							The Substance asset.
/// @param[in] graph							The graph.
/// @param[in] prevOutput					Pass @formatConstant{nullptr} to get the first output, pass an output pointer to get the following output.
/// @param[out] outputUid					The unique ID of the output. Only valid if return value != @formatConstant{nullptr}.
/// @param[out] type							The output type ID. Only valid if return value != @formatConstant{nullptr}.
/// @param[out] name							The name of the returned output. Only valid if return value != @formatConstant{nullptr}.
/// @param[in,out] bmpPtr					A pointer to a BaseBitmap pointer. If not @formatConstant{nullptr}, a pointer to a clone of the output channel bitmap will be returned here. @callerOwnsPointed{BaseBitmap}. Only valid if return value != @formatConstant{nullptr}.
/// @return												A pointer to identify the output, may not be dereferenced, @cinemaOwnsPointed{output}, or nullptr if output is not available
//----------------------------------------------------------------------------------------
void* GetSubstanceOutput(BaseList2D* const asset, void* const graph, void* const prevOutput, UInt32& outputUid, SUBSTANCE_OUTPUT_TYPE& type, String& name, BaseBitmap** bmpPtr);

/// @}

/// @name Preferences
/// @{

//----------------------------------------------------------------------------------------
/// Convenience function to get the material creation mode set in Substance preferences.
/// @since R18
/// @return												The material creation mode: @enumerateEnum{SUBSTANCE_MATERIAL_MODE}
//----------------------------------------------------------------------------------------
SUBSTANCE_MATERIAL_MODE PrefsGetMaterialModeSetting();

//----------------------------------------------------------------------------------------
/// Convenience function to get the preview mode for Content Browser set in Substance preferences.
/// @since R18
/// @return												Zero for mosaic preview, otherwise rendered preview scene.
//----------------------------------------------------------------------------------------
Int32 PrefsGetPreviewSetting();

/// @}

/// @name Misc
/// @{

//----------------------------------------------------------------------------------------
/// Checks if @formatParam{mat} contains any Substance shaders.
/// @since R18
/// @param[in] mat								The material to check for Substance shaders.
/// @return												@trueIfOtherwiseFalse{the material uses a Substance shader}
//----------------------------------------------------------------------------------------
Bool MaterialUsesSubstance(BaseMaterial* const mat);

//----------------------------------------------------------------------------------------
/// Returns an image with previews of the output channels of @formatParam{asset}.
/// @since R18
/// @note While the Substance asset won't have to be re-rendered, this operation still involves downscaling of all Substance outputs.
/// @param[in] asset							The Substance asset.
/// @param[in] w									The width of the preview image.
/// @param[in] h									The weight of the preview image.
/// @return												A pointer to the resulting bitmap. @callerOwnsPointed{BaseBitmap}
//----------------------------------------------------------------------------------------
BaseBitmap* GetSubstanceMosaicPreview(BaseList2D* const asset, Int32 w, Int32 h);

/// @}

/// @name Private
/// @{

//----------------------------------------------------------------------------------------
/// @markPrivate
/// @since R18
//----------------------------------------------------------------------------------------
void UpdateImageInputPaths(BaseList2D* const asset, String& path);

//----------------------------------------------------------------------------------------
/// @markPrivate
/// @since R18
//----------------------------------------------------------------------------------------
void CloneReferencedSubstances(BaseDocument* const doc, BaseShader* const shd, BaseDocument* const ddoc, BaseShader* const dshd);

//----------------------------------------------------------------------------------------
/// @markPrivate
/// @since R18
//----------------------------------------------------------------------------------------
void CloneReferencedSubstancesObject(BaseDocument* const docSrc, BaseObject* const opSrc, BaseDocument* const docDst, BaseObject* const opDst);

//----------------------------------------------------------------------------------------
/// @markPrivate
/// @since R18
//----------------------------------------------------------------------------------------
void InsertSubstancePreviewScene(BaseDocument* const doc, BaseList2D* const asset);

//----------------------------------------------------------------------------------------
/// Returns the Substance logo bitmap. @markPrivate
/// @since R19
/// @return												The logo bitmap. @cinemaOwnsPointed{BaseBitmap}
//----------------------------------------------------------------------------------------
const BaseBitmap* GetContentBrowserOverlay();

/// @}

/// @}

/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

struct SubstanceLibrary : public C4DLibrary
{
	SUBSTANCE_IMPORT_RESULT					(*ImportSubstance)									(BaseDocument* const doc, const Filename& fn, SUBSTANCE_IMPORT_COPY& copyFile, Bool guiOp, Bool addUndo, Bool noMaterial, BaseList2D** assetPtr);
	Bool														(*AssignAssetChannelToMaterial)			(BaseList2D* const asset, Material* const c4dMaterial, const Int32 channelId, Int32 uid, Bool addUndo);
	BaseList2D*											(*GetFirstSubstance)								(BaseDocument* const doc);
	void														(*GetSubstances)										(BaseDocument* const doc, AtomArray* arr, Bool selected);
	Bool														(*SubstanceInsertLast)							(BaseDocument* const doc, BaseList2D* const asset);
	void														(*CloneReferencedSubstances)				(BaseDocument* const doc, BaseShader* const shd, BaseDocument* const ddoc, BaseShader* const dshd);
	void														(*CloneReferencedSubstancesObject)	(BaseDocument* const docSrc, BaseObject* const opSrc, BaseDocument* const docDst, BaseObject* const opDst);
	void														(*InsertSubstancePreviewScene)			(BaseDocument* const doc, BaseList2D* const bl2d);
	void														(*UpdateImageInputPaths)						(BaseList2D* const asset, String& path);
	BaseBitmap*											(*GetSubstanceMosaicPreview)				(BaseList2D* const asset, Int32 w, Int32 h);
	SUBSTANCE_MATERIAL_MODE					(*PrefsGetCreateMaterialSetting)		();
	Int32														(*PrefsGetPreviewSetting)						();
	BaseMaterial*										(*CreateMaterial)										(BaseList2D* const asset, Int32 graphIndex, SUBSTANCE_MATERIAL_MODE mode);
	BaseShader*											(*CreateSubstanceShader)						(BaseList2D* const asset);
	void*														(*SubstanceGetGraph)								(BaseList2D* const asset, void* const prevGraph, String& name);
	void*														(*SubstanceGetInput)								(BaseList2D* const asset, void* const graph, void* const prevInput, UInt32& uid, Int32& firstDescId, Int32& numElements, SUBSTANCE_INPUT_TYPE& type, String& name);
	void*														(*SubstanceGetOutput)								(BaseList2D* const asset, void* const graph, void* const prevOutput, UInt32& uid, UInt32& type, String& name, BaseBitmap** bmpPtr);
	Bool														(*MaterialUsesSubstance)						(BaseMaterial* const mat);
	const BaseBitmap*								(*GetContentBrowserOverlay)					();
};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

#endif // LIB_SUBSTANCE_H__

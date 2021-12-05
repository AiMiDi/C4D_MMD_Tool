/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef LIB_LAYERSHADER_H__
#define LIB_LAYERSHADER_H__

#include "c4d_library.h"
#include "c4d_basecontainer.h"

#ifdef __API_INTERN__
#include "pluginshader.h"
#else
#include "c4d_basechannel.h"
#endif

class BlendLayer;

/// @addtogroup group_layershaderlibrary Layer Shader
/// @ingroup group_library
/// @{

/// LayerShader library ID.
#define LAYER_SHADER_LIB			450000055

/// @addtogroup LayerType
/// @ingroup group_enumeration
/// @{
/// The types for the layers of LayerShader.
enum LayerType
{
	TypeUnknown							= 0,			///< Unknown layer.
	TypeFolder							= 1,			///< Folder.
	TypeShader							= 2,			///< Shader.
	TypeBrightnessContrast	= 3,			///< Brightness/Contrast.
	TypeHSL									= 4,			///< HSL.
	TypePosterize						= 5,			///< Posterize.
	TypeColorize						= 6,			///< Colorize.
	TypeClamp								= 7,			///< Clamp.
	TypeClip								= 8,			///< Clip.
	TypeDistorter						= 9,			///< Distorter.
	TypeTransform						= 10			///< Transformation.
};
/// @}

/// @addtogroup LayerFlags
/// @ingroup group_enumeration
/// @{
/// The flags for the layers of LayerShader.
enum LayerFlags
{
	LAYER_INVERT				= 1,			///< Invert.
	LAYER_ALPHA					= 2,			///< Alpha.
	LAYER_INVERT_ALPHA	= 6,			///< Invert alpha.
	LAYER_IMAGE_ALPHA		= 8				///< Image alpha.
};
/// @}

/// @addtogroup BlendMode
/// @ingroup group_enumeration
/// @{
/// The blend modes for the layers of LayerShader.
enum BlendMode
{
	BlendNormal = 1,			///< Normal.
	BlendMultiply,				///< Multiply.
	BlendScreen,					///< Screen.
	BlendOverlay,					///< Overlay.
	BlendHardLight,				///< Hard light.
	BlendSoftLight,				///< Soft light.
	BlendDodge,						///< Dodge.
	BlendBurn,						///< Burn.
	BlendDarken,					///< Darken.
	BlendLighten,					///< Lighten.
	BlendAdd,							///< Add.
	BlendSubtract,				///< Subtract.
	BlendDifference,			///< Difference.
	BlendExclusion,				///< Exclusion.
	BlendHue,							///< Hue.
	BlendSat,							///< Saturation.
	BlendColor,						///< Color.
	BlendLuminance,				///< Luminance.
	BlendLevr,						///< Levr.
	BlendAlphaMask				///< Alpha mask.
};
/// @}

/// @addtogroup LAYER_S_PARAM_ALL
/// @ingroup group_containerid
/// @{
/// Common parameters for all layer types.
#define LAYER_S_PARAM_ALL_ACTIVE				1000			///< ::Bool Active.
#define LAYER_S_PARAM_ALL_SELECTED			1001			///< ::Bool Selected.
#define LAYER_S_PARAM_ALL_FLAGS					1002			///< ::Int32 Flags: @enumerateEnum{LayerFlags}
/// @}

/// @addtogroup LAYER_S_PARAM_FOLDER
/// @ingroup group_containerid
/// @{
/// Parameters for @ref TypeFolder layers.
#define LAYER_S_PARAM_FOLDER_MODE				2000			///< ::Int32 Blend mode: @enumerateEnum{BlendMode}
#define LAYER_S_PARAM_FOLDER_BLEND			2001			///< ::Float Blend parameter.
#define LAYER_S_PARAM_FOLDER_OPEN				2002			///< ::Bool Folder is open.
#define LAYER_S_PARAM_FOLDER_FIRSTCHILD	2003			///< @c void* Pointer to the first child LayerShaderLayer, read-only.
/// @}

/// @addtogroup LAYER_S_PARAM_SHADER
/// @ingroup group_containerid
/// @{
/// Parameters for @ref TypeShader layers.
#define LAYER_S_PARAM_SHADER_MODE				2000			///< ::Int32 Blend mode: @enumerateEnum{BlendMode}
#define LAYER_S_PARAM_SHADER_BLEND			2001			///< ::Float Blend parameter.
#define LAYER_S_PARAM_SHADER_LINK				2002			///< @c void* Pointer to a BaseLink that contains the shader, read-only.
/// @}

/// @addtogroup LAYER_S_PARAM_BC
/// @ingroup group_containerid
/// @{
/// Parameters for @ref TypeBrightnessContrast layers.
#define LAYER_S_PARAM_BC_BRIGHTNESS			2000			///< ::Float Brightness.
#define LAYER_S_PARAM_BC_CONTRAST				2001			///< ::Float Contrast.
#define LAYER_S_PARAM_BC_GAMMA					2002			///< ::Float Gamma.
/// @}

/// @addtogroup LAYER_S_PARAM_HSL
/// @ingroup group_containerid
/// @{
/// Parameters for @ref TypeHSL layers.
#define LAYER_S_PARAM_HSL_HUE						2000			///< ::Float Hue.
#define LAYER_S_PARAM_HSL_SATURATION		2001			///< ::Float Saturation.
#define LAYER_S_PARAM_HSL_LIGHTNESS			2002			///< ::Float Lightness.
#define LAYER_S_PARAM_HSL_COLORIZE			2003			///< ::Int32 Colorize.
/// @}

/// @addtogroup LAYER_S_PARAM_POSTER
/// @ingroup group_containerid
/// @{
/// Parameters for @ref TypePosterize layers.
#define LAYER_S_PARAM_POSTER_LEVELS			2000			///< ::Int32 Poster levels.
#define LAYER_S_PARAM_POSTER_WIDTH			2001			///< ::Float Poster width.
/// @}

/// @addtogroup LAYER_S_PARAM_COLORIZE
/// @ingroup group_containerid
/// @{
/// Parameters for @ref TypeColorize layers.
#define LAYER_S_PARAM_COLORIZE_INPUT		2000			///< ::Int32 @em [0..6] Input. (See dialog.)
#define LAYER_S_PARAM_COLORIZE_GRADIENT	2001			///< Gradient Colorization gradient.
#define LAYER_S_PARAM_COLORIZE_OPEN			2002			///< ::Bool Full settings.
#define LAYER_S_PARAM_COLORIZE_CYCLE		2003			///< ::Bool Cycle.
/// @}

/// @addtogroup LAYER_S_PARAM_CLAMP
/// @ingroup group_containerid
/// @{
/// Parameters for @ref TypeClamp layers.
#define LAYER_S_PARAM_CLAMP_LOW_CLIP		2000			///< ::Float Clamp low clip.
#define LAYER_S_PARAM_CLAMP_HIGH_CLIP		2001			///< ::Float Clamp high clip.
/// @}

/// @addtogroup LAYER_S_PARAM_CLIP
/// @ingroup group_containerid
/// @{
// Parameters for @ref TypeClip layers.
#define LAYER_S_PARAM_CLIP_LOW_CLIP			2000			///< ::Float Low clipping.
#define LAYER_S_PARAM_CLIP_HIGH_CLIP		2001			///< ::Float High clipping.
/// @}

/// @addtogroup LAYER_S_PARAM_DISTORT
/// @ingroup group_containerid
/// @{
// Parameters for @ref TypeDistorter layers.
#define LAYER_S_PARAM_DISTORT_NOISE				2000			///< ::Int32 Noise type. (See dialog.)
#define LAYER_S_PARAM_DISTORT_STRENGTH		2001			///< ::Float Strength.
#define LAYER_S_PARAM_DISTORT_OCTACES			2002			///< ::Float Octaves.
#define LAYER_S_PARAM_DISTORT_TIME_SCALE	2003			///< ::Float Time scale.
#define LAYER_S_PARAM_DISTORT_NOISE_SCALE	2004			///< ::Float Noise scale.
#define LAYER_S_PARAM_DISTORT_3D_NOISE		2005			///< ::Bool 3D noise.
#define LAYER_S_PARAM_DISTORT_WRAP				2006			///< ::Int32 @em [0..3] Wrapping. (See dialog.)
/// @}

/// @addtogroup LAYER_S_PARAM_TRANS
/// @ingroup group_containerid
/// @{
// Parameters for @ref TypeTransform layers.
#define LAYER_S_PARAM_TRANS_ANGLE				2000			///< ::Float Angle.
#define LAYER_S_PARAM_TRANS_MIRROR			2001			///< ::Bool Mirror.
#define LAYER_S_PARAM_TRANS_FLIP				2002			///< ::Bool Flip.
#define LAYER_S_PARAM_TRANS_SCALE				2003			///< ::Vector Scale.
#define LAYER_S_PARAM_TRANS_MOVE				2004			///< ::Vector Move.
/// @}

//----------------------------------------------------------------------------------------
/// Represents a layer in a LayerShader.
//----------------------------------------------------------------------------------------
class LayerShaderLayer
{
private:
	LayerShaderLayer();
	~LayerShaderLayer();

public:
	//----------------------------------------------------------------------------------------
	/// Gets the next layer.
	/// @note Use this to navigate trough the layers of a layer shader.
	/// @return												The next layer. @theOwnsPointed{layer shader,layer}
	//----------------------------------------------------------------------------------------
	LayerShaderLayer* GetNext();

	//----------------------------------------------------------------------------------------
	/// Gets the layer type.
	/// @return												The layer type: @enumerateEnum{LayerType}
	//----------------------------------------------------------------------------------------
	LayerType GetType();

	//----------------------------------------------------------------------------------------
	/// Retrieves the name of the layer.
	/// @param[in] doc								The document for the operation. @callerOwnsPointed{documented}
	/// @return												The layer name.
	//----------------------------------------------------------------------------------------
	String GetName(BaseDocument* doc);

	//----------------------------------------------------------------------------------------
	/// Retrieves the preview bitmap.
	/// @return												The preview bitmap. @theOwnsPointed{layer shader,bitmap}
	//----------------------------------------------------------------------------------------
	BaseBitmap* GetPreview();

	//----------------------------------------------------------------------------------------
	/// Retrieves layer parameters.
	/// @param[in] id									The ID of the parameter to get:\n
	/// 															For all layers: @enumerateEnum{LAYER_S_PARAM_ALL}\n
	/// 															For folders (@ref TypeFolder): @enumerateEnum{LAYER_S_PARAM_FOLDER}\n
	/// 															For shaders (@ref TypeShader): @enumerateEnum{LAYER_S_PARAM_SHADER}\n
	/// 															For brightness/contrast layers (@ref TypeBrightnessContrast): @enumerateEnum{LAYER_S_PARAM_BC}\n
	/// 															For HSL layers (@ref TypeHSL): @enumerateEnum{LAYER_S_PARAM_HSL}\n
	/// 															For posterize layers (@ref TypePosterize): @enumerateEnum{LAYER_S_PARAM_POSTER}\n
	/// 															For colorize layers (@ref TypeColorize): @enumerateEnum{LAYER_S_PARAM_COLORIZE}\n
	/// 															For clamp layers (@ref TypeClamp): @enumerateEnum{LAYER_S_PARAM_CLAMP}\n
	/// 															For clip layers (@ref TypeClip): @enumerateEnum{LAYER_S_PARAM_CLIP}\n
	/// 															For distorter layers (@ref TypeDistorter): @enumerateEnum{LAYER_S_PARAM_DISTORT}\n
	/// 															For transform layers (@ref TypeTransform): @enumerateEnum{LAYER_S_PARAM_TRANS}\n.
	/// @param[out] d									Filled with the parameter value.
	/// @return												@trueIfOtherwiseFalse{the parameter could be retrieved}
	//----------------------------------------------------------------------------------------
	Bool GetParameter(Int32 id, GeData &d) const;

	//----------------------------------------------------------------------------------------
	/// Sets layer parameters.
	/// @param[in] id									The ID of the parameter to set:\n
	/// 															For all layers: @enumerateEnum{LAYER_S_PARAM_ALL}\n
	/// 															For folders (@ref TypeFolder): @enumerateEnum{LAYER_S_PARAM_FOLDER}\n
	/// 															For shaders (@ref TypeShader): @enumerateEnum{LAYER_S_PARAM_SHADER}\n
	/// 															For brightness/contrast layers (@ref TypeBrightnessContrast): @enumerateEnum{LAYER_S_PARAM_BC}\n
	/// 															For HSL layers (@ref TypeHSL): @enumerateEnum{LAYER_S_PARAM_HSL}\n
	/// 															For posterize layers (@ref TypePosterize): @enumerateEnum{LAYER_S_PARAM_POSTER}\n
	/// 															For colorize layers (@ref TypeColorize): @enumerateEnum{LAYER_S_PARAM_COLORIZE}\n
	/// 															For clamp layers (@ref TypeClamp): @enumerateEnum{LAYER_S_PARAM_CLAMP}\n
	/// 															For clip layers (@ref TypeClip): @enumerateEnum{LAYER_S_PARAM_CLIP}\n
	/// 															For distorter layers (@ref TypeDistorter): @enumerateEnum{LAYER_S_PARAM_DISTORT}\n
	/// 															For transform layers (@ref TypeTransform): @enumerateEnum{LAYER_S_PARAM_TRANS}\n.
	/// @param[in] d									The new parameter value.
	/// @return												@trueIfOtherwiseFalse{the parameter could be set}
	//----------------------------------------------------------------------------------------
	Bool SetParameter(Int32 id, const GeData &d);
};

//----------------------------------------------------------------------------------------
/// Represents a layer shader.\n
/// The Layer shader can contain several layers of different types (shaders, folders, effects).\n
/// It looks like this:
/// @image html layershader.png
//----------------------------------------------------------------------------------------
class LayerShader : public BaseShader
{
private:
	LayerShader();
	~LayerShader();

public:
	//----------------------------------------------------------------------------------------
	/// Returns the first layer of the shader.
	/// @note To navigate through all the layers of a layer shader, get its first layer then use LayerShaderLayer::GetNext.
	/// @return												The first layer in the layer shader. @theOwnsPointed{layer shader,layer}
	//----------------------------------------------------------------------------------------
	LayerShaderLayer* GetFirstLayer();
};

/// @}

/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

struct LayerShaderLib : public C4DLibrary
{
	LayerShaderLayer*		(*GetFirstLayer)(BaseShader* op);

	LayerShaderLayer*		(BlendLayer::*GetNext)();
	LayerType						(BlendLayer::*GetType)();
	String							(BlendLayer::*GetName)(BaseDocument* pDoc);
	BaseBitmap*					(BlendLayer::*GetPreview)();
	Bool								(BlendLayer::*GetParameter)(Int32 id, GeData &d) const;
	Bool								(BlendLayer::*SetParameter)(Int32 id, const GeData &d);
};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

#endif // LIB_LAYERSHADER_H__

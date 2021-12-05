/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef C4D_REFLECTION_H__
#define C4D_REFLECTION_H__

#include "ge_prepass.h"			// Important
#include "c4d_basecontainer.h"

/// @addtogroup REFLECTION_FLAG
/// @ingroup group_enumeration
/// @{
/// Reflection layer flags.
#define REFLECTION_FLAG_NONE													0x00			///< None.

#define REFLECTION_FLAG_SELECTED											0x01			///< Selected.
#define REFLECTION_FLAG_ACTIVE												0x02			///< Active.
#define REFLECTION_FLAG_TAB														0x04			///< Tab.
#define REFLECTION_FLAG_TRANSPARENCY									0x08			///< Transparency.

#define REFLECTION_FLAG_SEPARATE											0x10			///< Separate pass.
#define REFLECTION_FLAG_READY													0x20			///< Ready.
/// @}

/// @addtogroup REFLECTION_ADDITIVE_MODE
/// @ingroup group_enumeration
/// @{
/// Reflection layer additive modes.
#define REFLECTION_ADDITIVE_MODE_AVG									0			///< Average.
#define REFLECTION_ADDITIVE_MODE_MIN_EX								1			///< Minimum.
#define REFLECTION_ADDITIVE_MODE_MAX									2			///< Maximum.
#define REFLECTION_ADDITIVE_MODE_ADD									3			///< Additive.
#define REFLECTION_ADDITIVE_MODE_METAL								4			///< Metal.
/// @}

/// @addtogroup REFLECTION_DISTRIBUTION
/// @ingroup group_enumeration
/// @{
/// Reflection layer distributions.
#define REFLECTION_DISTRIBUTION_SIMPLE								0				///< Simple.
#define REFLECTION_DISTRIBUTION_SPECULAR_BLINN				1				///< Specular Blinn (Legacy).

#define REFLECTION_DISTRIBUTION_BECKMANN							2				///< Beckmann.
#define REFLECTION_DISTRIBUTION_GGX										3				///< GGX.
#define REFLECTION_DISTRIBUTION_PHONG									4				///< Phong.
#define REFLECTION_DISTRIBUTION_WARD									5				///< Ward.
#define REFLECTION_DISTRIBUTION_ANISOTROPIC						6				///< Anisotropic.

#define REFLECTION_DISTRIBUTION_LAMBERTIAN						7				///< Lambertian (Diffuse).
#define REFLECTION_DISTRIBUTION_ORENNAYAR							8				///< Oren-Nayar (Diffuse).

#define REFLECTION_DISTRIBUTION_IRAWAN								9				///< Irawan (Woven Cloth).

#define REFLECTION_DISTRIBUTION_SPECULAR_PHONG				10			///< Specular Phong (Legacy).
/// @}

/// @addtogroup REFLECTION_BUMP_MODE
/// @ingroup group_enumeration
/// @{
/// Reflection layer bump modes.
#define REFLECTION_BUMP_MODE_DEFAULT									0			///< Default.
#define REFLECTION_BUMP_MODE_BUMP											1			///< Custom bump map.
#define REFLECTION_BUMP_MODE_NORMAL										2			///< Custom normal map.
/// @}

/// @addtogroup REFLECTION_PROJECTION
/// @ingroup group_enumeration
/// @{
/// Reflection layer projections.
#define REFLECTION_PROJECTION_PLANAR									0			///< Planar.
#define REFLECTION_PROJECTION_RADIAL									1			///< Radial.
#define REFLECTION_PROJECTION_NONE										2			///< None.
/// @}

/// @addtogroup REFLECTION_MIRROR
/// @ingroup group_enumeration
/// @{
/// Reflection layer mirror.
#define REFLECTION_MIRROR_NONE												0			///< None.
#define REFLECTION_MIRROR_U														1			///< Mirror U.
#define REFLECTION_MIRROR_V														2			///< Mirror V.
#define REFLECTION_MIRROR_UV													3			///< Mirror U+V.
/// @}

/// @addtogroup REFLECTION_PATTERN
/// @ingroup group_enumeration
/// @{
/// Reflection layer patterns.
#define REFLECTION_PATTERN_NONE												0			///< None.
#define REFLECTION_PATTERN_CIRCULAR										1			///< Circular.
#define REFLECTION_PATTERN_BOX												2			///< Box.
#define REFLECTION_PATTERN_DIAGONAL										3			///< Diagonal.
#define REFLECTION_PATTERN_LATTICE										4			///< Lattice.
#define REFLECTION_PATTERN_CUSTOM											5			///< Custom.
/// @}

/// @addtogroup REFLECTION_SCRATCHES
/// @ingroup group_enumeration
/// @{
/// Reflection layer scratches.
#define REFLECTION_SCRATCHES_NONE											0			///< None.
#define REFLECTION_SCRATCHES_PRIMARY									1			///< Primary.
#define REFLECTION_SCRATCHES_SECONDARY								2			///< Secondary.
#define REFLECTION_SCRATCHES_BOTH											3			///< Primary + Secondary.
/// @}

/// @addtogroup REFLECTION_CLOTH_PRESET
/// @ingroup group_enumeration
/// @{
/// Reflection layer Cloth presets.
#define REFLECTION_CLOTH_PRESET_CUSTOM								0			///< Custom.
#define REFLECTION_CLOTH_PRESET_A											1			///< Blue Gabardine (Suits).
#define REFLECTION_CLOTH_PRESET_B											2			///< Blue Denim (Jeans).
#define REFLECTION_CLOTH_PRESET_C											3			///< Green Twill (Sturdy Fabric).
#define REFLECTION_CLOTH_PRESET_D											4			///< Brown Charmeuse (Lining).
#define REFLECTION_CLOTH_PRESET_E											5			///< Blue Shantung (Gowns).
#define REFLECTION_CLOTH_PRESET_F											6			///< Purple Polyester (Lining).
/// @}

/// @addtogroup REFLECTION_CLOTH_PATTERN
/// @ingroup group_enumeration
/// @{
/// Reflection layer Cloth patterns.
#define REFLECTION_CLOTH_PATTERN_COTTON_DENIM					0			///< Cotton Denim.
#define REFLECTION_CLOTH_PATTERN_COTTON_TWILL					1			///< Cotton Twill.
#define REFLECTION_CLOTH_PATTERN_POLYESTER_LINING			2			///< Polyester Lining.
#define REFLECTION_CLOTH_PATTERN_SILK_CHARMEUSE				3			///< Silk Charmeuse.
#define REFLECTION_CLOTH_PATTERN_SILK_SHANTUNG				4			///< Silk Shantung.
#define REFLECTION_CLOTH_PATTERN_WOOL_GABARDINE				5			///< Wool Gabardine.
/// @}

/// @addtogroup REFLECTION_CLOTH_QUALITY
/// @ingroup group_enumeration
/// @{
/// Reflection layer Cloth quality.
#define REFLECTION_CLOTH_QUALITY_LOW									0			///< Low.
#define REFLECTION_CLOTH_QUALITY_MEDIUM								1			///< Medium.
#define REFLECTION_CLOTH_QUALITY_HIGH									2			///< High.
/// @}

/// @addtogroup REFLECTION_FRESNEL
/// @ingroup group_enumeration
/// @{
/// Reflection layer Fresnel.
#define REFLECTION_FRESNEL_NONE												0			///< None.
#define REFLECTION_FRESNEL_DIELECTRIC									1			///< Dielectric.
#define REFLECTION_FRESNEL_CONDUCTOR									2			///< Conductor.
/// @}

/// @addtogroup REFLECTION_FRESNEL_DIELECTRIC
/// @ingroup group_enumeration
/// @{
/// Reflection layer Fresnel dielectrics.
#define REFLECTION_FRESNEL_DIELECTRIC_CUSTOM					0				///< Custom.
#define REFLECTION_FRESNEL_DIELECTRIC_ASPHALT					1				///< Asphalt.
#define REFLECTION_FRESNEL_DIELECTRIC_BEER						2				///< Beer.
#define REFLECTION_FRESNEL_DIELECTRIC_DIAMOND					3				///< Diamond.
#define REFLECTION_FRESNEL_DIELECTRIC_EMERALD					4				///< Emerald.
#define REFLECTION_FRESNEL_DIELECTRIC_ETHANOL					5				///< Ethanol.
#define REFLECTION_FRESNEL_DIELECTRIC_GLASS						6				///< Glass.
#define REFLECTION_FRESNEL_DIELECTRIC_JADE						7				///< Jade.
#define REFLECTION_FRESNEL_DIELECTRIC_MILK						8				///< Milk.
#define REFLECTION_FRESNEL_DIELECTRIC_OIL_VEGETABLE		9				///< Oil (Vegetable).
#define REFLECTION_FRESNEL_DIELECTRIC_PEARL						10			///< Pearl.
#define REFLECTION_FRESNEL_DIELECTRIC_PET							11			///< PET.
#define REFLECTION_FRESNEL_DIELECTRIC_PLEXIGLASS			12			///< Plexiglas.
#define REFLECTION_FRESNEL_DIELECTRIC_RUBY						13			///< Ruby.
#define REFLECTION_FRESNEL_DIELECTRIC_SAPPHIRE				14			///< Sapphire.
#define REFLECTION_FRESNEL_DIELECTRIC_WATER						15			///< Water.
#define REFLECTION_FRESNEL_DIELECTRIC_WATER_ICE				16			///< Water (Ice).
#define REFLECTION_FRESNEL_DIELECTRIC_WHISKEY					17			///< Whiskey.
/// @}

/// @addtogroup REFLECTION_FRESNEL_METAL
/// @ingroup group_enumeration
/// @{
/// Reflection layer Fresnel metals.
#define REFLECTION_FRESNEL_METAL_CUSTOM								0				///< Custom.
#define REFLECTION_FRESNEL_METAL_ALUMINUM							1				///< Aluminum.
#define REFLECTION_FRESNEL_METAL_BERYLLIUM						2				///< Beryllium.
#define REFLECTION_FRESNEL_METAL_CHROMIUM							3				///< Chromium.
#define REFLECTION_FRESNEL_METAL_COPPER								4				///< Copper.
#define REFLECTION_FRESNEL_METAL_COPPER_OXIDE					5				///< Copper Oxide.
#define REFLECTION_FRESNEL_METAL_GOLD									6				///< Gold.
#define REFLECTION_FRESNEL_METAL_IRIDIUM							7				///< Iridium.
#define REFLECTION_FRESNEL_METAL_IRON									8				///< Iron.
#define REFLECTION_FRESNEL_METAL_LITHIUM							9				///< Lithium.
#define REFLECTION_FRESNEL_METAL_MAGNESIUM_OXIDE			10			///< Magnesium Oxide.
#define REFLECTION_FRESNEL_METAL_MERCURY							11			///< Mercury.
#define REFLECTION_FRESNEL_METAL_NICKEL								12			///< Nickel.
#define REFLECTION_FRESNEL_METAL_NIOBIUM							13			///< Niobium.
#define REFLECTION_FRESNEL_METAL_POTASSIUM						14			///< Potassium.
#define REFLECTION_FRESNEL_METAL_RHODIUM							15			///< Rhodium.
#define REFLECTION_FRESNEL_METAL_SELENIUM							16			///< Selenium.
#define REFLECTION_FRESNEL_METAL_SILICON_CARBIDE			17			///< Silicon Carbide.
#define REFLECTION_FRESNEL_METAL_SILVER								18			///< Silver.
#define REFLECTION_FRESNEL_METAL_SODIUM								19			///< Sodium.
#define REFLECTION_FRESNEL_METAL_TANTALUM							20			///< Tantalum.
#define REFLECTION_FRESNEL_METAL_TELLURIUM						21			///< Telluride.
#define REFLECTION_FRESNEL_METAL_TIN_TELLURIDE				22			///< Tin Telluride.
#define REFLECTION_FRESNEL_METAL_TITANIUM_NITRIDE			23			///< Titanium Nitride.
#define REFLECTION_FRESNEL_METAL_TUNGSTEN							24			///< Tungsten.
#define REFLECTION_FRESNEL_METAL_VANADIUM							25			///< Vanadium.
#define REFLECTION_FRESNEL_METAL_CUSTOM_NBM						26			///< Custom value for NBM materials.
/// @}

/// @addtogroup REFLECTION_DEBUG_DUDV
/// @ingroup group_enumeration
/// @{
/// Reflection layer debug DU/DV.
#define REFLECTION_DEBUG_DUDV_NORMAL									0			///< Normal.
#define REFLECTION_DEBUG_DUDV_DEFAULT_U								1			///< Default U.
#define REFLECTION_DEBUG_DUDV_DEFAULT_V								2			///< Default V.
#define REFLECTION_DEBUG_DUDV_TANGENT_U								3			///< Tangent U.
#define REFLECTION_DEBUG_DUDV_TANGENT_V								4			///< Tangent V.
#define REFLECTION_DEBUG_DUDV_ANGLE										5			///< Angle.
/// @}

/// @addtogroup REFLECTION_DEBUG_SCRATCH
/// @ingroup group_enumeration
/// @{
/// Reflection layer debug Scratch.
#define REFLECTION_DEBUG_SCRATCH_NORMAL								0			///< Normal.
#define REFLECTION_DEBUG_SCRATCH_DDU									1			///< DDU.
#define REFLECTION_DEBUG_SCRATCH_DDV									2			///< DDV.
#define REFLECTION_DEBUG_SCRATCH_BOTH									3			///< DDU + DDV.
#define REFLECTION_DEBUG_SCRATCH_DELTA								4			///< Delta.
/// @}

/// @addtogroup REFLECTION_DEBUG_CLOTH
/// @ingroup group_enumeration
/// @{
/// Reflection layer debug Cloth.
#define REFLECTION_DEBUG_CLOTH_NORMAL									0			///< Normal.
#define REFLECTION_DEBUG_CLOTH_NOISE									1			///< Noise.
#define REFLECTION_DEBUG_CLOTH_YARNS									2			///< Yarns.
/// @}

// Maximum @em 16 reflection layers as we need unique IDs for all of them.
#define REFLECTION_MAX_LAYERS													16

/// @addtogroup REFLECTION_LAYER
/// @ingroup group_containerid
/// @{
/// Reflection layer data.
/// IDs are added to the layer base data ID. See ReflectionLayer::GetDataID.

#define REFLECTION_LAYER_DUMMY												0x0000			///< Dummy parameter value.
#define REFLECTION_LAYER_QUICKTAB											0x8000			///< QuickTabCustomGui Quick Tab.
#define REFLECTION_LAYER_ADD													0x8010			///< Button. Add button.
#define REFLECTION_LAYER_REMOVE												0x8020			///< Button. Remove button.
#define REFLECTION_LAYER_COPY													0x8030			///< Button. Copy button.
#define REFLECTION_LAYER_PASTE												0x8040			///< Button. Paste button.
#define REFLECTION_LAYER_DUPLICATE										0x8050			///< @markInternal
#define REFLECTION_LAYER_DATA													0x80A0			///< Layer data. @markInternal
#define REFLECTION_LAYER_GLOBAL_REFLECTION						0x80B0			///< ::Float Global reflection brightness.
#define REFLECTION_LAYER_GLOBAL_SPECULAR							0x80C0			///< ::Float Global specular brightness
#define REFLECTION_LAYER_GLOBAL_SEPARATE_PASS					0x80D0			///< ::Bool Separate Pass
#define REFLECTION_LAYER_GLOBAL_GROUP									0x80E0			///< Group. Global group.

#define REFLECTION_LAYER_IMPORTED											0x80F0			///< ::Bool Set to true if imported (unlikely).
#define REFLECTION_LAYER_ENABLED											0x80F1			///< @markInternal
#define REFLECTION_LAYER_LINEAR_TEXTURES							0x80F2			///< @markInternal
#define REFLECTION_LAYER_PREVIEWS											0x80FF			///< @markInternal Special ID. (Do not change!)

// Layers data IDs and size
#define REFLECTION_LAYER_LAYER_DATA										0x80000			///< Layer data reserves the whole @em 0x80000 group.
#define REFLECTION_LAYER_LAYER_SIZE										0x0200			///< Layer data size.

#define REFLECTION_LAYER_GROUP												0x0000			///< Layer Group.
#define REFLECTION_LAYER_MAIN_GROUP										0x0001			///< Main group.
#define REFLECTION_LAYER_MAIN_IMAGE_GROUP							0x0002			///< Image group.
#define REFLECTION_LAYER_MAIN_IMAGE_PREVIEW						0x0003			///< Image preview group.
#define REFLECTION_LAYER_MAIN_IMAGE_MODEL							0x0004			///< Image model group.
#define REFLECTION_LAYER_MAIN_IMAGE_ANISOTROPY				0x0005			///< Image anisotropy group.
#define REFLECTION_LAYER_MAIN_IMAGE_PRIMARY						0x0006			///< Image primary group.
#define REFLECTION_LAYER_MAIN_IMAGE_SECONDARY					0x0007			///< Image secondary group.
#define REFLECTION_LAYER_MAIN_IMAGE_DISTANCE					0x0008			///< Image distance group.
#define REFLECTION_LAYER_MAIN_IMAGE_CLOTH							0x0009			///< Image cloth group.

#define REFLECTION_LAYER_MAIN_DISTRIBUTION						0x0010			///< ::Int32 Distribution type: @enumerateEnum{REFLECTION_DISTRIBUTION}
#define REFLECTION_LAYER_MAIN_ADDITIVE								0x0011			///< ::Int32 Additive/attenuation: @enumerateEnum{REFLECTION_ADDITIVE_MODE}
#define REFLECTION_LAYER_MAIN_COLORED_REFLECTION			0x0012			///< ::Bool Colored reflection.
#define REFLECTION_LAYER_MAIN_COLORED_SPECULAR				0x0013			///< ::Bool Colored specular.
#define REFLECTION_LAYER_MAIN_BLEND_MODE							0x0014			///< ::Int32 Blend mode.
#define REFLECTION_LAYER_NAME													0x0015			///< ::String Layer name. @since R18
//#define REFLECTION_LAYER_NOT_SELECTION_FLAGS					0x0016			///< ::Int32 Not selection layer flags.
#define REFLECTION_LAYER_ID														0x0017			///< @markInternal ::Int32 Layer ID. @warning Do not change!
#define REFLECTION_LAYER_MAIN_IMAGE_TRISTATE					0x0018			///< Image tristate group. @since R18

#define REFLECTION_LAYER_MAIN_VALUE_ROUGHNESS					0x0020			///< ::Float Roughness.
#define REFLECTION_LAYER_MAIN_VALUE_FALLOFF						0x0021			///< ::Float Falloff.
#define REFLECTION_LAYER_MAIN_VALUE_INNER							0x0022			///< ::Float Inner width
#define REFLECTION_LAYER_MAIN_VALUE_ORENNAYAR					0x0023			///< ::Float Roughness.
#define REFLECTION_LAYER_MAIN_VALUE_REFLECTION				0x0024			///< ::Float Reflection strength.
#define REFLECTION_LAYER_MAIN_VALUE_SPECULAR					0x0025			///< ::Float Specular strength.

#define REFLECTION_LAYER_MAIN_SHADER_ROUGHNESS				0x0028			///< BaseLink Roughness shader.
#define REFLECTION_LAYER_MAIN_SHADER_FALLOFF					0x0029			///< BaseLink Falloff shader.
#define REFLECTION_LAYER_MAIN_SHADER_INNER						0x002A			///< BaseLink Inner width shader.
#define REFLECTION_LAYER_MAIN_SHADER_ORENNAYAR				0x002B			///< BaseLink Roughness shader.
#define REFLECTION_LAYER_MAIN_SHADER_REFLECTION				0x002C			///< BaseLink Reflection strength shader.
#define REFLECTION_LAYER_MAIN_SHADER_SPECULAR					0x002D			///< BaseLink Specular strength shader.

// Bump
#define REFLECTION_LAYER_MAIN_VALUE_BUMP							0x0030			///< ::Float Bump strength.
#define REFLECTION_LAYER_MAIN_VALUE_BUMP_MODE					0x0031			///< ::Int32 Bump mode: @enumerateEnum{REFLECTION_BUMP_MODE}
#define REFLECTION_LAYER_MAIN_VALUE_BUMP_SPACE				0x0032			///< ::Int32 Bump method.
#define REFLECTION_LAYER_MAIN_VALUE_BUMP_BUMP					0x0033			///< ::Float Strength.
#define REFLECTION_LAYER_MAIN_VALUE_BUMP_NORM					0x0034			///< ::Float Strength.
#define REFLECTION_LAYER_MAIN_VALUE_BUMP_MIPMAP				0x0035			///< ::Bool MIP falloff.
#define REFLECTION_LAYER_MAIN_VALUE_BUMP_REVERSEX			0x0036			///< ::Bool Flip X (Red).
#define REFLECTION_LAYER_MAIN_VALUE_BUMP_REVERSEY			0x0037			///< ::Bool Flip Y (Green).
#define REFLECTION_LAYER_MAIN_VALUE_BUMP_REVERSEZ			0x0038			///< ::Bool Flip Z (Blue)
#define REFLECTION_LAYER_MAIN_VALUE_BUMP_SWAP					0x0039			///< ::Bool Swap Y & Z (Y up).

#define REFLECTION_LAYER_MAIN_SHADER_BUMP							0x003A			///< BaseLink Bump shader.
#define REFLECTION_LAYER_MAIN_SHADER_BUMP_CUSTOM			0x003B			///< BaseLink Custom bump shader.

// Color
#define REFLECTION_LAYER_COLOR_GROUP									0x0040			///< Layer color group.
#define REFLECTION_LAYER_COLOR_COLOR									0x0041			///< ::Vector Color.
#define REFLECTION_LAYER_COLOR_BRIGHTNESS							0x0042			///< ::Float Brightness.
#define REFLECTION_LAYER_COLOR_TEXTURE								0x0043			///< BaseLink Texture.
#define REFLECTION_LAYER_COLOR_MIX_MODE								0x0044			///< ::Int32 Mix mode.
#define REFLECTION_LAYER_COLOR_MIX_STRENGTH						0x0045			///< ::Float Mix strength.

// Transparency
#define REFLECTION_LAYER_TRANS_GROUP									0x0050			///< Layer transparency group.
#define REFLECTION_LAYER_TRANS_COLOR									0x0051			///< ::Vector Color.
#define REFLECTION_LAYER_TRANS_BRIGHTNESS							0x0052			///< ::Float Brightness.
#define REFLECTION_LAYER_TRANS_TEXTURE								0x0053			///< BaseLink Texture.
#define REFLECTION_LAYER_TRANS_MIX_MODE								0x0054			///< ::Int32 Mix mode.
#define REFLECTION_LAYER_TRANS_MIX_STRENGTH						0x0055			///< ::Float Mix strength.

// Anisotropy
#define REFLECTION_LAYER_ANISO_GROUP									0x0060			///< Layer anisotropy group.
#define REFLECTION_LAYER_ANISO_PROJECTION							0x0061			///< ::Int32 Re-projection: @enumerateEnum{REFLECTION_PROJECTION}
#define REFLECTION_LAYER_ANISO_PROJECTION_SCALE				0x0062			///< ::Float Scale.
#define REFLECTION_LAYER_ANISO_PROJECTION_ANGLE				0x006F			///< ::Float Angle. ID out of order.
#define REFLECTION_LAYER_ANISO_PROJECTION_OFFSET_U		0x0063			///< ::Float Offset U.
#define REFLECTION_LAYER_ANISO_PROJECTION_OFFSET_V		0x0064			///< ::Float Offset V.
#define REFLECTION_LAYER_ANISO_PROJECTION_COUNT				0x0065			///< ::Int32 Re-projection Count.
#define REFLECTION_LAYER_ANISO_PATTERN								0x0066			///< ::Int32 Pattern: @enumerateEnum{REFLECTION_PATTERN}
#define REFLECTION_LAYER_ANISO_MIRROR									0x0067			///< ::Int32 Mirror: @enumerateEnum{REFLECTION_MIRROR}
#define REFLECTION_LAYER_ANISO_SCRATCHES							0x0068			///< ::Int32 Scratches: @enumerateEnum{REFLECTION_SCRATCHES}
#define REFLECTION_LAYER_ANISO_VALUE_CUSTOM						0x0069			///< ::Float Max angle.
#define REFLECTION_LAYER_ANISO_VALUE_ANISOTROPY				0x006A			///< ::Float Anisotropy.
#define REFLECTION_LAYER_ANISO_VALUE_ORIENTATION			0x006B			///< ::Float Orientation.
#define REFLECTION_LAYER_ANISO_SHADER_CUSTOM					0x006C			///< BaseLink Custom texture.
#define REFLECTION_LAYER_ANISO_SHADER_ANISOTROPY			0x006D			///< BaseLink Anisotropy texture.
#define REFLECTION_LAYER_ANISO_SHADER_ORIENTATION			0x006E			///< BaseLink Orientation texture.

#define REFLECTION_LAYER_PRIMARY_VALUE_AMPLITUDE			0x0070			///< ::Float Primary amplitude.
#define REFLECTION_LAYER_PRIMARY_VALUE_SCALE					0x0071			///< ::Float Primary scale.
#define REFLECTION_LAYER_PRIMARY_VALUE_LENGTH					0x0072			///< ::Float Primary length.
#define REFLECTION_LAYER_PRIMARY_VALUE_ATTENUATION		0x0073			///< ::Float Primary attenuation.
#define REFLECTION_LAYER_PRIMARY_SHADER_AMPLITUDE			0x0078			///< BaseLink Primary amplitude texture.
#define REFLECTION_LAYER_PRIMARY_SHADER_SCALE					0x0079			///< BaseLink Primary scale texture.
#define REFLECTION_LAYER_PRIMARY_SHADER_LENGTH				0x007A			///< BaseLink Primary length texture.
#define REFLECTION_LAYER_PRIMARY_SHADER_ATTENUATION		0x007B			///< BaseLink Primary attenuation texture.

#define REFLECTION_LAYER_SECONDARY_VALUE_AMPLITUDE		0x0080			///< ::Float Secondary amplitude.
#define REFLECTION_LAYER_SECONDARY_VALUE_SCALE				0x0081			///< ::Float Secondary scale.
#define REFLECTION_LAYER_SECONDARY_VALUE_LENGTH				0x0082			///< ::Float Secondary length.
#define REFLECTION_LAYER_SECONDARY_VALUE_ATTENUATION	0x0083			///< ::Float Secondary attenuation.
#define REFLECTION_LAYER_SECONDARY_SHADER_AMPLITUDE		0x0088			///< BaseLink Secondary amplitude texture.
#define REFLECTION_LAYER_SECONDARY_SHADER_SCALE				0x0089			///< BaseLink Secondary scale texture.
#define REFLECTION_LAYER_SECONDARY_SHADER_LENGTH			0x008A			///< BaseLink Secondary length texture.
#define REFLECTION_LAYER_SECONDARY_SHADER_ATTENUATION	0x008B			///< BaseLink Secondary attenuation texture.

// Fresnel
#define REFLECTION_LAYER_FRESNEL_GROUP								0x0090			///< Fresnel group.
#define REFLECTION_LAYER_FRESNEL_MODE									0x0091			///< ::Int32 Fresnel mode: @enumerateEnum{REFLECTION_FRESNEL}
#define REFLECTION_LAYER_FRESNEL_PRESET								0x0092			///< ::Int32 Fresnel (Dielectric) preset: @enumerateEnum{REFLECTION_FRESNEL_DIELECTRIC}
#define REFLECTION_LAYER_FRESNEL_METAL								0x0093			///< ::Int32 Metal preset: @enumerateEnum{REFLECTION_FRESNEL_METAL}
#define REFLECTION_LAYER_FRESNEL_INVERTED							0x0094			///< ::Bool Invert.
#define REFLECTION_LAYER_FRESNEL_OPAQUE								0x009D			///< ::Bool Opaque. ID out of order.
#define REFLECTION_LAYER_FRESNEL_VALUE_STRENGTH				0x0095			///< ::Float Strength.
#define REFLECTION_LAYER_FRESNEL_VALUE_IOR						0x0096			///< ::Float IOR.
#define REFLECTION_LAYER_FRESNEL_VALUE_ETA						0x0097			///< ::Float IOR.
#define REFLECTION_LAYER_FRESNEL_VALUE_ABSORP					0x0098			///< ::Float Absorption.
#define REFLECTION_LAYER_FRESNEL_SHADER_STRENGTH			0x0099			///< BaseLink Strength texture.
#define REFLECTION_LAYER_FRESNEL_SHADER_IOR						0x009A			///< BaseLink IOR texture.
#define REFLECTION_LAYER_FRESNEL_SHADER_ETA						0x009B			///< BaseLink IOR texture.
#define REFLECTION_LAYER_FRESNEL_SHADER_ABSORP				0x009C			///< BaseLink Absorption texture.
#define REFLECTION_LAYER_FRESNEL_VALUE_ETA2						0x009E			///< ::Vector IOR.
#define REFLECTION_LAYER_FRESNEL_VALUE_ABSORP2				0x009F			///< ::Vector Absorption.

// Sampling
#define REFLECTION_LAYER_SAMPLING_GROUP								0x00B0			///< Sampling group.
#define REFLECTION_LAYER_SAMPLING_DIM									0x00B1			///< ::Bool Distance dim.
#define REFLECTION_LAYER_SAMPLING_DIM_DISTANCE				0x00B2			///< ::Float Distance.
#define REFLECTION_LAYER_SAMPLING_DIM_FALLOFF					0x00B3			///< ::Float Falloff.
#define REFLECTION_LAYER_SAMPLING_CLAMP								0x00B4			///< ::Float Clamp secondary.
#define REFLECTION_LAYER_SAMPLING_CUTOFF							0x00B5			///< ::Float Cutoff.
#define REFLECTION_LAYER_SAMPLING_EXIT_COLOR					0x00B6			///< ::Vector Exit color.
#define REFLECTION_LAYER_SAMPLING_SEPARATE_PASS				0x00B7			///< ::Bool Separate pass.
#define REFLECTION_LAYER_SAMPLING_DIM_COLOR						0x00B9			///< ::Vector Distant color.
#define REFLECTION_LAYER_SAMPLING_SAMPLE_COUNT				0x00BA			///< ::Float Sampling subdivisions.

// Cloth
#define REFLECTION_LAYER_CLOTH_GROUP									0x00C0			///< Cloth group.
#define REFLECTION_LAYER_CLOTH_PRESET									0x00C1			///< ::Int32 Preset: @enumerateEnum{REFLECTION_CLOTH_PRESET}
#define REFLECTION_LAYER_CLOTH_PATTERN								0x00C2			///< ::Int32 Pattern: @enumerateEnum{REFLECTION_CLOTH_PATTERN}
#define REFLECTION_LAYER_CLOTH_QUALITY								0x00C3			///< ::Int32 Quality: @enumerateEnum{REFLECTION_CLOTH_QUALITY}
#define REFLECTION_LAYER_CLOTH_SMOOTHING							0x00C4			///< ::Float Smoothing.
#define REFLECTION_LAYER_CLOTH_SCATTERING_UNIFORM			0x00C5			///< ::Float Uniform scattering.
#define REFLECTION_LAYER_CLOTH_SCATTERING_FORWARD			0x00C6			///< ::Float Forward scattering.

#define REFLECTION_LAYER_CLOTH_VALUE_ORIENTATION			0x00D0			///< ::Float Orientation.
#define REFLECTION_LAYER_CLOTH_VALUE_SCALE_U					0x00D1			///< ::Float Scale U.
#define REFLECTION_LAYER_CLOTH_VALUE_SCALE_V					0x00D2			///< ::Float Scale V.
#define REFLECTION_LAYER_CLOTH_VALUE_HIGHLIGHTS				0x00D3			///< ::Float Highlights.

#define REFLECTION_LAYER_CLOTH_SHADER_ORIENTATION			0x00D8			///< BaseLink Orientation texture.
#define REFLECTION_LAYER_CLOTH_SHADER_SCALE_U					0x00D9			///< BaseLink Scale U texture.
#define REFLECTION_LAYER_CLOTH_SHADER_SCALE_V					0x00DA			///< BaseLink Scale V texture.
#define REFLECTION_LAYER_CLOTH_SHADER_HIGHLIGHTS			0x00DB			///< BaseLink Highlights texture.

#define REFLECTION_LAYER_CLOTH_NOISE_INTENSITY				0x00E0			///< ::Float Noise strength.
#define REFLECTION_LAYER_CLOTH_NOISE_SCALE						0x00E1			///< ::Float Noise scale.
#define REFLECTION_LAYER_CLOTH_NOISE_SHAPE_WARP				0x00E2			///< ::Float Yarn noise (Warp).
#define REFLECTION_LAYER_CLOTH_NOISE_SHAPE_WEFT				0x00E3			///< ::Float Yarn noise (Weft)
#define REFLECTION_LAYER_CLOTH_NOISE_SHAPE_SCALE			0x00E4			///< ::Float Yarn noise scale.

#define REFLECTION_LAYER_CLOTH_COLOR_DIFFUSE_WARP			0x00E8			///< ::Vector Diffuse warp.
#define REFLECTION_LAYER_CLOTH_COLOR_DIFFUSE_WEFT			0x00E9			///< ::Vector Diffuse weft.
#define REFLECTION_LAYER_CLOTH_COLOR_SPECULAR_WARP		0x00EA			///< ::Vector Specular warp.
#define REFLECTION_LAYER_CLOTH_COLOR_SPECULAR_WEFT		0x00EB			///< ::Vector Specular weft.

#define REFLECTION_LAYER_CLOTH_SHADER_DIFFUSE_WARP		0x00EC			///< ::BaseLink Diffuse warp texture.
#define REFLECTION_LAYER_CLOTH_SHADER_DIFFUSE_WEFT		0x00ED			///< ::BaseLink Diffuse weft texture.
#define REFLECTION_LAYER_CLOTH_SHADER_SPECULAR_WARP		0x00EE			///< ::BaseLink Specular warp texture.
#define REFLECTION_LAYER_CLOTH_SHADER_SPECULAR_WEFT		0x00EF			///< ::BaseLink Specular weft texture.

/// @name REFLECTION_LAYER_DEBUG
/// @ingroup group_containerid
/// @{
/// Reflection layer Debug.
#define REFLECTION_LAYER_DEBUG_GROUP									0x00F0			///< Group. Debug Group.
#define REFLECTION_LAYER_DEBUG_DUDV										0x00F1			///< ::Int32 Debug DUDV mode: @enumerateEnum{REFLECTION_DEBUG_DUDV}
#define REFLECTION_LAYER_DEBUG_SCRATCHES							0x00F2			///< ::Int32 Debug Scratch mode: @enumerateEnum{REFLECTION_DEBUG_SCRATCH}
#define REFLECTION_LAYER_DEBUG_WARMNESS								0x00F3			///< @markInternal
#define REFLECTION_LAYER_DEBUG_CLOTH									0x00F4			///< ::Int32 Debug Cloth mode: @enumerateEnum{REFLECTION_DEBUG_CLOTH}
/// @}

/// @}

//----------------------------------------------------------------------------------------
/// A reflection layer in a material.
/// @see Material Reflection Layers.
//----------------------------------------------------------------------------------------
class ReflectionLayer
{
public:
	//----------------------------------------------------------------------------------------
	/// Default constructor.
	//----------------------------------------------------------------------------------------
	ReflectionLayer();

	//----------------------------------------------------------------------------------------
	/// Retrieves the layer ID.
	/// @since R18
	/// @return												The layer ID. Must be a value greater or equal than @em 3, otherwise it failed.
	//----------------------------------------------------------------------------------------
	Int32 GetLayerID() const;

	//----------------------------------------------------------------------------------------
	/// Retrieves the layer base data ID to get/set its data.
	/// @return												The layer base data ID.
	//----------------------------------------------------------------------------------------
	Int32 GetDataID() const;

	//----------------------------------------------------------------------------------------
	/// Retrieves the layer name.
	/// @since R18
	/// @return												The layer name.
	//----------------------------------------------------------------------------------------
	String GetName() const;

	//----------------------------------------------------------------------------------------
	/// Sets the layer name. If not valid (i.e. empty or all chars are whitespaces) a default layer name will be used.
	/// @since R18
	/// @param[in] name								The layer name.
	//----------------------------------------------------------------------------------------
	void SetName(const maxon::String& name);

	//----------------------------------------------------------------------------------------
	/// Retrieves the flags for the layer.
	/// @since R18
	/// @return												The layer flags: @enumerateEnum{REFLECTION_FLAG}
	//----------------------------------------------------------------------------------------
	Int32 GetFlags() const;

	//----------------------------------------------------------------------------------------
	/// Sets the flags for the layer.
	/// @since R18
	/// @param[in] flags							The layer flags to set: @enumerateEnum{REFLECTION_FLAG}
	//----------------------------------------------------------------------------------------
	void SetFlags(Int32 flags);

protected:
	Int32 _layerDataID;						///< @markInternal Used to retrieve layer data from material container. Note: this ID is dynamic and could vary (based on the layer position in the list)
	Material* _parent;						///< @markInternal The owner of the reflection layer.
};

#endif // C4D_REFLECTION_H__

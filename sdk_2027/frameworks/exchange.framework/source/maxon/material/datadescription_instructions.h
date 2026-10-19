#ifndef DATADESCRIPTION_INSTRUCTIONS_H__
#define DATADESCRIPTION_INSTRUCTIONS_H__

#include "maxon/fid.h"
#include "maxon/vector.h"
#include "maxon/vector2d.h"

//----------------------------------------------------------------------------------------
// BEGIN - auto generated code, do not edit
//----------------------------------------------------------------------------------------
namespace maxon
{
namespace MATERIAL
{
	namespace INSTRUCTIONS
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.material.instructions");

		/// A texture channel selection attribute, designating which channel (or subset of channels) should be used.
		/// The payload is supposed to contain one of the enum-Ids.
		/// Texture only.
		MAXON_ATTRIBUTE(Id, CHANNELSELECT, "channelSelect",
			RESOURCE_DEFINE(ENUM_AUTO, LiteralId("AUTO"))
			RESOURCE_DEFINE(ENUM_R, LiteralId("R"))
			RESOURCE_DEFINE(ENUM_G, LiteralId("G"))
			RESOURCE_DEFINE(ENUM_B, LiteralId("B"))
			RESOURCE_DEFINE(ENUM_A, LiteralId("A"))
			RESOURCE_DEFINE(ENUM_RGB, LiteralId("RGB"))
			RESOURCE_DEFINE(ENUM_ALL, LiteralId("ALL")));

		/// A color space attribute, designating what color space are texture values encoded in.
		/// The payload is supposed to contain one of the enum-Ids.
		/// Texture only.
		MAXON_ATTRIBUTE(Id, COLORSPACE, "colorSpace",
			RESOURCE_DEFINE(ENUM_AUTO, LiteralId("Auto"))
			RESOURCE_DEFINE(ENUM_SRGB, LiteralId("sRGB"))
			RESOURCE_DEFINE(ENUM_RAW, LiteralId("Raw")));

		/// A scale (aka multiplier) attribute, designating a scaling factor for the parameter value (or values in the texture).
		/// The payload is Data that's supposed to contain one of the following types:
		/// Float / Vector2d / Vector / Vector4d / Color / ColorA
		MAXON_ATTRIBUTE(Data, VALUESCALE, "valueScale");

		/// A bias (aka offset) attribute, designating an offsetting value for the parameter value (or values in the texture).
		/// The payload is Data that's supposed to contain one of the following types:
		/// Float / Vector2d / Vector / Vector4d / Color / ColorA
		MAXON_ATTRIBUTE(Data, VALUEOFFSET, "valueOffset");

		/// A flag, designating, if UV mapping for the texture should be mirrorred along U-axis.
		/// Textures only
		MAXON_ATTRIBUTE(Bool, UVMIRRORU, "uvMirrorU");

		/// A flag, designating, if UV mapping for the texture should be mirrorred along V-axis.
		/// Textures only
		MAXON_ATTRIBUTE(Bool, UVMIRRORV, "uvMirrorV");

		/// A flag, designating, if UV mapping for the texture should use wrapping along U-axis.
		/// Textures only
		MAXON_ATTRIBUTE(Bool, UVWRAPU, "uvWrapU");

		/// A flag, designating, if UV mapping for the texture should use wrapping along V-axis.
		/// Textures only
		MAXON_ATTRIBUTE(Bool, UVWRAPV, "uvWrapV");

		/// A scale attribute, designating a scaling factors for the UV-mapping of the texture.
		/// The payload is supposed to contain Vector2d that corresponds to U and V axes.
		/// Texture only.
		MAXON_ATTRIBUTE(Vector2d, UVSCALE, "uvScale");

		/// An offset attribute, designating an offsetting values for the UV-mapping of the texture.
		/// The payload is supposed to contain Vector2d that corresponds to U and V axes.
		/// Texture only.
		MAXON_ATTRIBUTE(Vector2d, UVOFFSET, "uvOffset");

		/// A flag, designating if the instruction implementation is supposed to be organized in some way (e.g. by grouping nodes).
		MAXON_ATTRIBUTE(Bool, DOGROUPING, "doGrouping");

		/// A flag, designating if the instruction implementation is supposed to use implicit approach
		/// (e.g. use values directly in the nodes instead of creating a separate explicit "value" nodes).
		MAXON_ATTRIBUTE(Bool, MAKEIMPLICIT, "makeImplicit");

		/// A flag, designating if the parameter mapping is supposed to be disabled by default (e.g. by muting the node connection).
		MAXON_ATTRIBUTE(Bool, MUTE, "mute");

		/// Internal use.
		MAXON_ATTRIBUTE(DataDictionary, USERDATA, "userData");

		MAXON_ATTRIBUTE(Group, GROUP_MODIFIERS, "group.modifiers");

		MAXON_ATTRIBUTE(Group, GROUP_UV, "group.uv");

		MAXON_ATTRIBUTE(Group, GROUP_2COLUMNS_1, "group.2columns_1");

		MAXON_ATTRIBUTE(Group, GROUP_APPEARANCE, "group.appearance");
	}
}
}
//----------------------------------------------------------------------------------------
// END - auto generated code, do not edit
//----------------------------------------------------------------------------------------


#include "datadescription_instructions1.hxx"
#include "datadescription_instructions2.hxx"

#endif // DATADESCRIPTION_INSTRUCTIONS_H__

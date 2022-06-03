#ifndef CONVERSION_NODES_H__
#define CONVERSION_NODES_H__

#include "maxon/fid.h"
#include "maxon/vector.h"
#include "maxon/vector2d.h"
#include "maxon/vector4d.h"

//----------------------------------------------------------------------------------------
// BEGIN - auto generated code, do not edit
//----------------------------------------------------------------------------------------
namespace maxon
{
namespace PATTERN
{
	namespace NODE
	{
		namespace CONVERSION
		{
			namespace COLORTOFLOAT
			{
				MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.pattern.node.conversion.colortofloat");

				// supports MAXON::NODE::BASE::NODEPREVIEWIMAGE
				// supports MAXON::NODE::BASE::MATERIALPREVIEWIMAGE
				// supports MAXON::NODE::BASE::NAME
				// supports MAXON::NODE::BASE::ASSETVERSION
				// supports MAXON::NODE::BASE::COLOR
				// supports MAXON::NODE::BASE::PORTDISPLAY
				// supports MAXON::NODE::BASE::DISPLAYPREVIEW
				// supports MAXON::NODE::BASE::DISPLAYCOMMENT
				// supports MAXON::NODE::BASE::COMMENT
				// supports MAXON::NODE::BASE::FILTERTAGS
				// supports MAXON::NODE::BASE::CATEGORY
				// supports MAXON::NODE::BASE::ICON
				// supports MAXON::NODE::BASE::UPDATEPOLICY
				// supports MAXON::ASSET::BASE::PROTECTED

				MAXON_ATTRIBUTE(ColorA, COLOR, "color");

				MAXON_ATTRIBUTE(InternedId, MODE, "mode");
				MAXON_ATTRIBUTE(void, MODE_ENUM_RED, "red");
				MAXON_ATTRIBUTE(void, MODE_ENUM_GREEN, "green");
				MAXON_ATTRIBUTE(void, MODE_ENUM_BLUE, "blue");
				MAXON_ATTRIBUTE(void, MODE_ENUM_ALPHA, "alpha");
				MAXON_ATTRIBUTE(void, MODE_ENUM_AVERAGE, "average");
				MAXON_ATTRIBUTE(void, MODE_ENUM_LENGTH, "length");
				MAXON_ATTRIBUTE(void, MODE_ENUM_SQUAREDLENGTH, "squaredlength");
				MAXON_ATTRIBUTE(void, MODE_ENUM_LUMINANCE, "luminance");
				MAXON_ATTRIBUTE(void, MODE_ENUM_SUM, "sum");
				MAXON_ATTRIBUTE(void, MODE_ENUM_MIN, "min");
				MAXON_ATTRIBUTE(void, MODE_ENUM_MAX, "max");

				MAXON_ATTRIBUTE(Bool, USEALPHA, "usealpha");

				MAXON_ATTRIBUTE(Float, RESULT, "result");
			}

			namespace COMPOSECOLOR
			{
				MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.pattern.node.conversion.composecolor");

				// supports MAXON::NODE::BASE::NODEPREVIEWIMAGE
				// supports MAXON::NODE::BASE::MATERIALPREVIEWIMAGE
				// supports MAXON::NODE::BASE::NAME
				// supports MAXON::NODE::BASE::ASSETVERSION
				// supports MAXON::NODE::BASE::COLOR
				// supports MAXON::NODE::BASE::PORTDISPLAY
				// supports MAXON::NODE::BASE::DISPLAYPREVIEW
				// supports MAXON::NODE::BASE::DISPLAYCOMMENT
				// supports MAXON::NODE::BASE::COMMENT
				// supports MAXON::NODE::BASE::FILTERTAGS
				// supports MAXON::NODE::BASE::CATEGORY
				// supports MAXON::NODE::BASE::ICON
				// supports MAXON::NODE::BASE::UPDATEPOLICY
				// supports MAXON::ASSET::BASE::PROTECTED

				MAXON_ATTRIBUTE(Float, RED, "red");

				MAXON_ATTRIBUTE(Float, GREEN, "green");

				MAXON_ATTRIBUTE(Float, BLUE, "blue");

				MAXON_ATTRIBUTE(Color, RESULT, "result");
			}

			namespace COMPOSECOLORA
			{
				MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.pattern.node.conversion.composecolora");

				// supports MAXON::NODE::BASE::NODEPREVIEWIMAGE
				// supports MAXON::NODE::BASE::MATERIALPREVIEWIMAGE
				// supports MAXON::NODE::BASE::NAME
				// supports MAXON::NODE::BASE::ASSETVERSION
				// supports MAXON::NODE::BASE::COLOR
				// supports MAXON::NODE::BASE::PORTDISPLAY
				// supports MAXON::NODE::BASE::DISPLAYPREVIEW
				// supports MAXON::NODE::BASE::DISPLAYCOMMENT
				// supports MAXON::NODE::BASE::COMMENT
				// supports MAXON::NODE::BASE::FILTERTAGS
				// supports MAXON::NODE::BASE::CATEGORY
				// supports MAXON::NODE::BASE::ICON
				// supports MAXON::NODE::BASE::UPDATEPOLICY
				// supports MAXON::ASSET::BASE::PROTECTED

				MAXON_ATTRIBUTE(Color, RGB, "rgb");

				MAXON_ATTRIBUTE(Float, RED, "red");

				MAXON_ATTRIBUTE(Float, GREEN, "green");

				MAXON_ATTRIBUTE(Float, BLUE, "blue");

				MAXON_ATTRIBUTE(Float, ALPHA, "alpha");

				MAXON_ATTRIBUTE(ColorA, RESULT, "result");
			}

			namespace COMPOSEVECTOR2
			{
				MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.pattern.node.conversion.composevector2");

				// supports MAXON::NODE::BASE::NODEPREVIEWIMAGE
				// supports MAXON::NODE::BASE::MATERIALPREVIEWIMAGE
				// supports MAXON::NODE::BASE::NAME
				// supports MAXON::NODE::BASE::ASSETVERSION
				// supports MAXON::NODE::BASE::COLOR
				// supports MAXON::NODE::BASE::PORTDISPLAY
				// supports MAXON::NODE::BASE::DISPLAYPREVIEW
				// supports MAXON::NODE::BASE::DISPLAYCOMMENT
				// supports MAXON::NODE::BASE::COMMENT
				// supports MAXON::NODE::BASE::FILTERTAGS
				// supports MAXON::NODE::BASE::CATEGORY
				// supports MAXON::NODE::BASE::ICON
				// supports MAXON::NODE::BASE::UPDATEPOLICY
				// supports MAXON::ASSET::BASE::PROTECTED

				MAXON_ATTRIBUTE(Float, X, "x");

				MAXON_ATTRIBUTE(Float, Y, "y");

				MAXON_ATTRIBUTE(Vector2d, RESULT, "result");
			}

			namespace COMPOSEVECTOR3
			{
				MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.pattern.node.conversion.composevector3");

				// supports MAXON::NODE::BASE::NODEPREVIEWIMAGE
				// supports MAXON::NODE::BASE::MATERIALPREVIEWIMAGE
				// supports MAXON::NODE::BASE::NAME
				// supports MAXON::NODE::BASE::ASSETVERSION
				// supports MAXON::NODE::BASE::COLOR
				// supports MAXON::NODE::BASE::PORTDISPLAY
				// supports MAXON::NODE::BASE::DISPLAYPREVIEW
				// supports MAXON::NODE::BASE::DISPLAYCOMMENT
				// supports MAXON::NODE::BASE::COMMENT
				// supports MAXON::NODE::BASE::FILTERTAGS
				// supports MAXON::NODE::BASE::CATEGORY
				// supports MAXON::NODE::BASE::ICON
				// supports MAXON::NODE::BASE::UPDATEPOLICY
				// supports MAXON::ASSET::BASE::PROTECTED

				MAXON_ATTRIBUTE(Float, X, "x");

				MAXON_ATTRIBUTE(Float, Y, "y");

				MAXON_ATTRIBUTE(Float, Z, "z");

				MAXON_ATTRIBUTE(Vector, RESULT, "result");
			}

			namespace COMPOSEVECTOR4
			{
				MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.pattern.node.conversion.composevector4");

				// supports MAXON::NODE::BASE::NODEPREVIEWIMAGE
				// supports MAXON::NODE::BASE::MATERIALPREVIEWIMAGE
				// supports MAXON::NODE::BASE::NAME
				// supports MAXON::NODE::BASE::ASSETVERSION
				// supports MAXON::NODE::BASE::COLOR
				// supports MAXON::NODE::BASE::PORTDISPLAY
				// supports MAXON::NODE::BASE::DISPLAYPREVIEW
				// supports MAXON::NODE::BASE::DISPLAYCOMMENT
				// supports MAXON::NODE::BASE::COMMENT
				// supports MAXON::NODE::BASE::FILTERTAGS
				// supports MAXON::NODE::BASE::CATEGORY
				// supports MAXON::NODE::BASE::ICON
				// supports MAXON::NODE::BASE::UPDATEPOLICY
				// supports MAXON::ASSET::BASE::PROTECTED

				MAXON_ATTRIBUTE(Float, X, "x");

				MAXON_ATTRIBUTE(Float, Y, "y");

				MAXON_ATTRIBUTE(Float, Z, "z");

				MAXON_ATTRIBUTE(Float, W, "w");

				MAXON_ATTRIBUTE(Vector4d, RESULT, "result");
			}

			namespace CONVERTDEGREES
			{
				MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.pattern.node.conversion.convertdegrees");

				// supports MAXON::NODE::BASE::NODEPREVIEWIMAGE
				// supports MAXON::NODE::BASE::MATERIALPREVIEWIMAGE
				// supports MAXON::NODE::BASE::NAME
				// supports MAXON::NODE::BASE::ASSETVERSION
				// supports MAXON::NODE::BASE::COLOR
				// supports MAXON::NODE::BASE::PORTDISPLAY
				// supports MAXON::NODE::BASE::DISPLAYPREVIEW
				// supports MAXON::NODE::BASE::DISPLAYCOMMENT
				// supports MAXON::NODE::BASE::COMMENT
				// supports MAXON::NODE::BASE::FILTERTAGS
				// supports MAXON::NODE::BASE::CATEGORY
				// supports MAXON::NODE::BASE::ICON
				// supports MAXON::NODE::BASE::UPDATEPOLICY
				// supports MAXON::ASSET::BASE::PROTECTED

				MAXON_ATTRIBUTE(Float, VALUE, "value");

				MAXON_ATTRIBUTE(InternedId, MODE, "mode");
				MAXON_ATTRIBUTE(void, MODE_ENUM_RADTODEG, "radtodeg");
				MAXON_ATTRIBUTE(void, MODE_ENUM_DEGTORAD, "degtorad");

				MAXON_ATTRIBUTE(Float, RESULT, "result");
			}

			namespace SPLITCOLORCOMPONENTS
			{
				MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.pattern.node.conversion.splitcolorcomponents");

				// supports MAXON::NODE::BASE::NODEPREVIEWIMAGE
				// supports MAXON::NODE::BASE::MATERIALPREVIEWIMAGE
				// supports MAXON::NODE::BASE::NAME
				// supports MAXON::NODE::BASE::ASSETVERSION
				// supports MAXON::NODE::BASE::COLOR
				// supports MAXON::NODE::BASE::PORTDISPLAY
				// supports MAXON::NODE::BASE::DISPLAYPREVIEW
				// supports MAXON::NODE::BASE::DISPLAYCOMMENT
				// supports MAXON::NODE::BASE::COMMENT
				// supports MAXON::NODE::BASE::FILTERTAGS
				// supports MAXON::NODE::BASE::CATEGORY
				// supports MAXON::NODE::BASE::ICON
				// supports MAXON::NODE::BASE::UPDATEPOLICY
				// supports MAXON::ASSET::BASE::PROTECTED

				MAXON_ATTRIBUTE(ColorA, COLOR, "color");

				MAXON_ATTRIBUTE(Int, INDEX, "index");

				MAXON_ATTRIBUTE(Color, RGB, "rgb");

				MAXON_ATTRIBUTE(Float, R, "r");

				MAXON_ATTRIBUTE(Float, G, "g");

				MAXON_ATTRIBUTE(Float, B, "b");

				MAXON_ATTRIBUTE(Float, A, "a");

				MAXON_ATTRIBUTE(Float, INDEXEDCOMPONENT, "indexedcomponent");
			}

			namespace SPLITVECTORCOMPONENTS
			{
				MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.pattern.node.conversion.splitvectorcomponents");

				// supports MAXON::NODE::BASE::NODEPREVIEWIMAGE
				// supports MAXON::NODE::BASE::MATERIALPREVIEWIMAGE
				// supports MAXON::NODE::BASE::NAME
				// supports MAXON::NODE::BASE::ASSETVERSION
				// supports MAXON::NODE::BASE::COLOR
				// supports MAXON::NODE::BASE::PORTDISPLAY
				// supports MAXON::NODE::BASE::DISPLAYPREVIEW
				// supports MAXON::NODE::BASE::DISPLAYCOMMENT
				// supports MAXON::NODE::BASE::COMMENT
				// supports MAXON::NODE::BASE::FILTERTAGS
				// supports MAXON::NODE::BASE::CATEGORY
				// supports MAXON::NODE::BASE::ICON
				// supports MAXON::NODE::BASE::UPDATEPOLICY
				// supports MAXON::ASSET::BASE::PROTECTED

				MAXON_ATTRIBUTE(ColorA, VECTOR, "vector");

				MAXON_ATTRIBUTE(Int, INDEX, "index");

				MAXON_ATTRIBUTE(Vector, XYZ, "xyz");

				MAXON_ATTRIBUTE(Vector2d, XY, "xy");

				MAXON_ATTRIBUTE(Float, X, "x");

				MAXON_ATTRIBUTE(Float, Y, "y");

				MAXON_ATTRIBUTE(Float, Z, "z");

				MAXON_ATTRIBUTE(Float, W, "w");

				MAXON_ATTRIBUTE(Float, INDEXEDCOMPONENT, "indexedcomponent");
			}

			namespace VECTORTOFLOAT
			{
				MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.pattern.node.conversion.vectortofloat");

				// supports MAXON::NODE::BASE::NODEPREVIEWIMAGE
				// supports MAXON::NODE::BASE::MATERIALPREVIEWIMAGE
				// supports MAXON::NODE::BASE::NAME
				// supports MAXON::NODE::BASE::ASSETVERSION
				// supports MAXON::NODE::BASE::COLOR
				// supports MAXON::NODE::BASE::PORTDISPLAY
				// supports MAXON::NODE::BASE::DISPLAYPREVIEW
				// supports MAXON::NODE::BASE::DISPLAYCOMMENT
				// supports MAXON::NODE::BASE::COMMENT
				// supports MAXON::NODE::BASE::FILTERTAGS
				// supports MAXON::NODE::BASE::CATEGORY
				// supports MAXON::NODE::BASE::ICON
				// supports MAXON::NODE::BASE::UPDATEPOLICY
				// supports MAXON::ASSET::BASE::PROTECTED

				MAXON_ATTRIBUTE(ColorA, VECTOR, "vector");

				MAXON_ATTRIBUTE(InternedId, MODE, "mode");
				MAXON_ATTRIBUTE(void, MODE_ENUM_X, "x");
				MAXON_ATTRIBUTE(void, MODE_ENUM_Y, "y");
				MAXON_ATTRIBUTE(void, MODE_ENUM_Z, "z");
				MAXON_ATTRIBUTE(void, MODE_ENUM_W, "w");
				MAXON_ATTRIBUTE(void, MODE_ENUM_AVERAGE, "average");
				MAXON_ATTRIBUTE(void, MODE_ENUM_LENGTH, "length");
				MAXON_ATTRIBUTE(void, MODE_ENUM_SQUAREDLENGTH, "squaredlength");
				MAXON_ATTRIBUTE(void, MODE_ENUM_LUMINANCE, "luminance");
				MAXON_ATTRIBUTE(void, MODE_ENUM_SUM, "sum");
				MAXON_ATTRIBUTE(void, MODE_ENUM_MIN, "min");
				MAXON_ATTRIBUTE(void, MODE_ENUM_MAX, "max");

				MAXON_ATTRIBUTE(Float, RESULT, "result");
			}
		}
	}
}
}
//----------------------------------------------------------------------------------------
// END - auto generated code, do not edit
//----------------------------------------------------------------------------------------

#include "nodes_conversion1.hxx"
	
#include "nodes_conversion2.hxx"

#endif // CONVERSION_NODES_H__

#ifndef ASSET_METAPROPERTIES_H__
#define ASSET_METAPROPERTIES_H__

#include "maxon/fid.h"
#include "maxon/range.h"
#include "maxon/vector4d.h"

namespace maxon
{
class PixelFormat;
class FileFormat;
using InsertPointType = Tuple<Id, Vector, Vector2d, ColorA>;
}

//----------------------------------------------------------------------------------------
// BEGIN - auto generated code, do not edit
//----------------------------------------------------------------------------------------
namespace maxon
{
namespace ASSET
{
	namespace METAPROPERTIES
	{
		namespace BASE
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.asset.metaproperties.base");

			MAXON_ATTRIBUTE(String, NAME, "net.maxon.asset.metaproperties.base.name");

			MAXON_ATTRIBUTE(String, TYPE, "net.maxon.asset.metaproperties.base.type");

			MAXON_ATTRIBUTE(String, DATE, "net.maxon.asset.metaproperties.base.date");

			MAXON_ATTRIBUTE(String, FILEFORMAT, "net.maxon.asset.metaproperties.base.fileformat");

			MAXON_ATTRIBUTE(String, FILEFORMATVERSION, "net.maxon.asset.metaproperties.base.fileformatversion");

			MAXON_ATTRIBUTE(String, USAGE, "net.maxon.asset.metaproperties.base.usage");

			/// Set to True if the preview was generated automatically
			MAXON_ATTRIBUTE(Bool, AUTOMATICPREVIEW, "net.maxon.asset.metaproperties.base.automaticpreview");

			MAXON_ATTRIBUTE(Group, DETAILS, "net.maxon.asset.metaproperties.base.details");
		}

		namespace C4DFILE
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.asset.metaproperties.c4dfile");

			// supports MAXON::ASSET::METAPROPERTIES::BASE::NAME
			// supports MAXON::ASSET::METAPROPERTIES::BASE::TYPE
			// supports MAXON::ASSET::METAPROPERTIES::BASE::DATE
			// supports MAXON::ASSET::METAPROPERTIES::BASE::FILEFORMAT
			// supports MAXON::ASSET::METAPROPERTIES::BASE::FILEFORMATVERSION
			// supports MAXON::ASSET::METAPROPERTIES::BASE::USAGE
			// supports MAXON::ASSET::METAPROPERTIES::BASE::AUTOMATICPREVIEW

			MAXON_ATTRIBUTE(Int, POINTCOUNT, "net.maxon.asset.metaproperties.c4dfile.pointcount");

			MAXON_ATTRIBUTE(Int, POLYGONCOUNT, "net.maxon.asset.metaproperties.c4dfile.polygoncount");

			MAXON_ATTRIBUTE(Int, GEOMETRYOBJECTCOUNT, "net.maxon.asset.metaproperties.c4dfile.geometryobjectcount");

			MAXON_ATTRIBUTE(Int, MATERIALCOUNT, "net.maxon.asset.metaproperties.c4dfile.materialcount");

			/// matrix of the object in the global scene
			MAXON_ATTRIBUTE(Matrix, OBJECTMATRIX, "net.maxon.asset.metaproperties.c4dfile.objectmatrix");

			/// bounding box is scaled to 1 cm units (which is c4d default)
			MAXON_ATTRIBUTE(Range<Vector>, BOUNDINGBOX, "net.maxon.asset.metaproperties.c4dfile.boundingbox");

			/// array of insertion point relative to the bounding box system
			MAXON_ATTRIBUTE(MAXON_MACROARG_TYPE(Array<Tuple<Id, Vector, Vector2d, ColorA>>), INSERTIONPOINT, "net.maxon.asset.metaproperties.c4dfile.insertionpoint");
		}

		namespace MEDIA
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.asset.metaproperties.media");

			// supports MAXON::ASSET::METAPROPERTIES::BASE::NAME
			// supports MAXON::ASSET::METAPROPERTIES::BASE::TYPE
			// supports MAXON::ASSET::METAPROPERTIES::BASE::DATE
			// supports MAXON::ASSET::METAPROPERTIES::BASE::FILEFORMAT
			// supports MAXON::ASSET::METAPROPERTIES::BASE::FILEFORMATVERSION
			// supports MAXON::ASSET::METAPROPERTIES::BASE::USAGE
			// supports MAXON::ASSET::METAPROPERTIES::BASE::AUTOMATICPREVIEW

			MAXON_ATTRIBUTE(String, RESOLUTION, "net.maxon.asset.metaproperties.media.resolution");

			MAXON_ATTRIBUTE(Int, WIDTH, "net.maxon.asset.metaproperties.media.width");

			MAXON_ATTRIBUTE(Int, HEIGHT, "net.maxon.asset.metaproperties.media.height");

			MAXON_ATTRIBUTE(Int, BITDEPTH, "net.maxon.asset.metaproperties.media.bitdepth");

			MAXON_ATTRIBUTE(PixelFormat, PIXELFORMAT, "net.maxon.asset.metaproperties.media.pixelformat");

			MAXON_ATTRIBUTE(Bool, HASALPHA, "net.maxon.asset.metaproperties.media.hasalpha");

			MAXON_ATTRIBUTE(Int, ALPHACHANNELS, "net.maxon.asset.metaproperties.media.alphachannels");

			MAXON_ATTRIBUTE(Int, SUBIMAGECOUNT, "net.maxon.asset.metaproperties.media.subimagecount");

			MAXON_ATTRIBUTE(Float, DPI, "net.maxon.asset.metaproperties.media.dpi");

			MAXON_ATTRIBUTE(TimeValue, ANIMLENGTH, "net.maxon.asset.metaproperties.media.animlength");

			MAXON_ATTRIBUTE(Float, FPS, "net.maxon.asset.metaproperties.media.fps");

			MAXON_ATTRIBUTE(String, COLORPROFILE, "net.maxon.asset.metaproperties.media.colorprofile");
		}
	}
}
}
//----------------------------------------------------------------------------------------
// END - auto generated code, do not edit
//----------------------------------------------------------------------------------------


#include "asset_metaproperties1.hxx"
#include "asset_metaproperties2.hxx"

#endif // ASSET_METAPROPERTIES_H__

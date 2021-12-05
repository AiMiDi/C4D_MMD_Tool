#if 1
#if defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#endif
namespace maxon
{
	namespace rla
	{
		namespace enum64 { enum class ProjectionType : UInt32
		{
			ProjPerspective = 0,
			ProjParallel = 1
		} ; }
		maxon::String PrivateToString_ProjectionType64(std::underlying_type<enum64::ProjectionType>::type x, const maxon::FormatStatement* fmt)
		{
			const maxon::UInt64 values[] = {(maxon::UInt64) enum64::ProjectionType::ProjPerspective, (maxon::UInt64) enum64::ProjectionType::ProjParallel};
			return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "ProjectionType", SIZEOF(x), false, values, "ProjPerspective\0ProjParallel\0", fmt);
		}
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(DT_MAXRenderInfo,, "net.maxon.image.maxrenderinfo");
	}
	namespace MEDIASESSION
	{
		namespace RLA
		{
			namespace EXPORT
			{
				COVERAGE_PrivateAttribute COVERAGE;
				Z_PrivateAttribute Z;
				MATERIALID_PrivateAttribute MATERIALID;
				OBJECTBUFFER_PrivateAttribute OBJECTBUFFER;
				UV_PrivateAttribute UV;
				NORMAL_PrivateAttribute NORMAL;
				ORIGINALCOLOR_PrivateAttribute ORIGINALCOLOR;
				MAXRENDERINFO_PrivateAttribute MAXRENDERINFO;
				NAMETAB_PrivateAttribute NAMETAB;
			}
		}
		namespace RPF
		{
			namespace EXPORT
			{
				SUBPIXELWEIGHT_PrivateAttribute SUBPIXELWEIGHT;
				SUBPIXELMASK_PrivateAttribute SUBPIXELMASK;
				OBJECTID_PrivateAttribute OBJECTID;
				COLOR_PrivateAttribute COLOR;
				TRANSPARENCY_PrivateAttribute TRANSPARENCY;
			}
		}
	}
	namespace ImageSaverClasses
	{
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(Rla, , MEDIASESSION::RLA::EXPORT::GetId());
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(Rpf, , MEDIASESSION::RPF::EXPORT::GetId());
	}
	namespace enum196 { enum class RLACHANNELS
	{
		// GBuffer channels (number of bytes in parenthesis)
		Z       				= 0,  	// (4)  Z-Buffer depth, float
		MATERIALID  		= 1,  	// (1)  ID assigned to mtl via mtl editor
		NODE_ID 				= 2,  	// (2)  ID assigned to node via properties
		UV       				= 3, 		// (8)  UV coordinates - Point2
		NORMAL   				= 4, 		// (4)  Normal vector in view space, compressed
		REALPIX  				= 5, 		// (4)  Non clamped colors in "RealPixel" format
		COVERAGE 				= 6, 		// (1)  Pixel coverage
		BG 	     				= 7, 		// (3)  RGB color of what's behind layer
		NODE_RENDER_ID 	= 8, 		// (2)  Node render index, word
		COLOR		 				= 9, 		// (3)  Color (RGB)
		TRANSP		 			= 10, 	// (3)  Transparency (RGB)
		VELOC		 				= 11, 	// (8)  Velocity (Point2)
		WEIGHT		 			= 12, 	// (3)  Weight of layers contribution to pixel color
		MASK            = 13, 	// (2)  SubpixelMask
		MAXCOUNT				= 14,
	} ; }
	maxon::String PrivateToString_RLACHANNELS196(std::underlying_type<enum196::RLACHANNELS>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum196::RLACHANNELS::Z, (maxon::UInt64) enum196::RLACHANNELS::MATERIALID, (maxon::UInt64) enum196::RLACHANNELS::NODE_ID, (maxon::UInt64) enum196::RLACHANNELS::UV, (maxon::UInt64) enum196::RLACHANNELS::NORMAL, (maxon::UInt64) enum196::RLACHANNELS::REALPIX, (maxon::UInt64) enum196::RLACHANNELS::COVERAGE, (maxon::UInt64) enum196::RLACHANNELS::BG, (maxon::UInt64) enum196::RLACHANNELS::NODE_RENDER_ID, (maxon::UInt64) enum196::RLACHANNELS::COLOR, (maxon::UInt64) enum196::RLACHANNELS::TRANSP, (maxon::UInt64) enum196::RLACHANNELS::VELOC, (maxon::UInt64) enum196::RLACHANNELS::WEIGHT, (maxon::UInt64) enum196::RLACHANNELS::MASK, (maxon::UInt64) enum196::RLACHANNELS::MAXCOUNT};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "RLACHANNELS", SIZEOF(x), false, values, "Z\0MATERIALID\0NODE_ID\0UV\0NORMAL\0REALPIX\0COVERAGE\0BG\0NODE_RENDER_ID\0COLOR\0TRANSP\0VELOC\0WEIGHT\0MASK\0MAXCOUNT\0", fmt);
	}
	namespace enum214 { enum class RLAFLAGS
	{
		NONE						= 0,																				///< None.
		Z								= (1 << (Int)RLACHANNELS::Z),								///< Z.
		MATERIALID			= (1 << (Int)RLACHANNELS::MATERIALID),					///< MATERIALID.
		OBJECTBUFFER		= (1 << (Int)RLACHANNELS::NODE_ID),					///< Object buffer.
		UV							= (1 << (Int)RLACHANNELS::UV),							///< UV coordinates.
		NORMAL					= (1 << (Int)RLACHANNELS::NORMAL),					///< Normals.
		ORIGCOLOR				= (1 << (Int)RLACHANNELS::REALPIX),					///< Non-clamped color.
		COVERAGE				= (1 << (Int)RLACHANNELS::COVERAGE),				///< Coverage.
		BG							= (1 << (Int)RLACHANNELS::BG),							///< BG.
		OBJECTID				= (1 << (Int)RLACHANNELS::NODE_RENDER_ID),	///< Object ID.
		COLOR						= (1 << (Int)RLACHANNELS::COLOR),						///< Color.
		TRANSPARENCY		= (1 << (Int)RLACHANNELS::TRANSP),					///< Transparency.
		SUBPIXEL_WEIGHT	= (1 << (Int)RLACHANNELS::WEIGHT),					///< Sub-pixel weight.
		SUBPIXEL_MASK		= (1 << (Int)RLACHANNELS::MASK)							///< Sub-pixel mask.
	} ; }
	maxon::String PrivateToString_RLAFLAGS214(std::underlying_type<enum214::RLAFLAGS>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum214::RLAFLAGS::NONE, (maxon::UInt64) enum214::RLAFLAGS::Z, (maxon::UInt64) enum214::RLAFLAGS::MATERIALID, (maxon::UInt64) enum214::RLAFLAGS::OBJECTBUFFER, (maxon::UInt64) enum214::RLAFLAGS::UV, (maxon::UInt64) enum214::RLAFLAGS::NORMAL, (maxon::UInt64) enum214::RLAFLAGS::ORIGCOLOR, (maxon::UInt64) enum214::RLAFLAGS::COVERAGE, (maxon::UInt64) enum214::RLAFLAGS::BG, (maxon::UInt64) enum214::RLAFLAGS::OBJECTID, (maxon::UInt64) enum214::RLAFLAGS::COLOR, (maxon::UInt64) enum214::RLAFLAGS::TRANSPARENCY, (maxon::UInt64) enum214::RLAFLAGS::SUBPIXEL_WEIGHT, (maxon::UInt64) enum214::RLAFLAGS::SUBPIXEL_MASK};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "RLAFLAGS", SIZEOF(x), true, values, "NONE\0Z\0MATERIALID\0OBJECTBUFFER\0UV\0NORMAL\0ORIGCOLOR\0COVERAGE\0BG\0OBJECTID\0COLOR\0TRANSPARENCY\0SUBPIXEL_WEIGHT\0SUBPIXEL_MASK\0", fmt);
	}
}
#endif

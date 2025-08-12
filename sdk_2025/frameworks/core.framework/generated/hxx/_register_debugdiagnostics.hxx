#if 1
#ifndef APIBASE_H__
#endif
#if defined(MAXON_TARGET_MACOS) || defined(MAXON_TARGET_IOS)
#elif defined MAXON_TARGET_LINUX
#elif !defined(MAXON_TARGET_WINDOWS)
#endif
namespace maxon
{
	namespace enum32
	{
		enum class TARGETAUDIENCE
		{
			DEBUGGER = 1 << 1,
			DEVELOPERS = 1 << 2,
			USERS = 1 << 3,
			ALL = DEBUGGER | DEVELOPERS | USERS,
		} ;
		static const maxon::UInt64 TARGETAUDIENCE_values[] = {maxon::UInt64(enum32::TARGETAUDIENCE::DEBUGGER), maxon::UInt64(enum32::TARGETAUDIENCE::DEVELOPERS), maxon::UInt64(enum32::TARGETAUDIENCE::USERS), maxon::UInt64(enum32::TARGETAUDIENCE::ALL)};
		static const maxon::EnumInfo TARGETAUDIENCE_info{"TARGETAUDIENCE", SIZEOF(TARGETAUDIENCE), true, "DEBUGGER\0DEVELOPERS\0USERS\0ALL\0", TARGETAUDIENCE_values, std::extent<decltype(TARGETAUDIENCE_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_TARGETAUDIENCE32(){ return enum32::TARGETAUDIENCE_info; }
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(DT_TARGETAUDIENCE, , "net.maxon.datatype.enum.targetaudience");
	namespace enum43
	{
		enum class WRITEMETA
		{
			DEFAULT = 1 << 0,							// Default output.
			WARNING = 1 << 1,							// Warning output.
			CRITICAL = 1 << 2,						// Critical output.
		
			NONEWLINE = 1 << 3,						// No \n add the end of the string
		
			UI_SYNC_DRAW = 1 << 12				// Make a synchronous UI redraw
		} ;
		static const maxon::UInt64 WRITEMETA_values[] = {maxon::UInt64(enum43::WRITEMETA::DEFAULT), maxon::UInt64(enum43::WRITEMETA::WARNING), maxon::UInt64(enum43::WRITEMETA::CRITICAL), maxon::UInt64(enum43::WRITEMETA::NONEWLINE), maxon::UInt64(enum43::WRITEMETA::UI_SYNC_DRAW)};
		static const maxon::EnumInfo WRITEMETA_info{"WRITEMETA", SIZEOF(WRITEMETA), true, "DEFAULT\0WARNING\0CRITICAL\0NONEWLINE\0UI_SYNC_DRAW\0", WRITEMETA_values, std::extent<decltype(WRITEMETA_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_WRITEMETA43(){ return enum43::WRITEMETA_info; }
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(DT_WRITEMETA, , "net.maxon.datatype.enum.writemeta");
	namespace enum56
	{
		enum class OUTPUT
		{
			NONE					= 0,					///< No flag set.
			DIAGNOSTIC		= (1 << 0),		///< Diagnostic output, shows up if this group of output is activated. This is also the default.
			WARNING				= (1 << 1),		///< Warning output, shows up if this group of output is activated.
			CRITICAL			= (1 << 2),		///< Critical output, shows up if this group of output is activated.
		
			PRETTYPRINT		= (1 << 28),	///< If set, it is tried to break and indent long output according to parentheses and commas.
			NOLINEBREAK		= (1 << 29),	///< If set, no line break is added.
			HEADER				= (1 << 30)		///< If set, header with line number and file name is added.
		} ;
		static const maxon::UInt64 OUTPUT_values[] = {maxon::UInt64(enum56::OUTPUT::NONE), maxon::UInt64(enum56::OUTPUT::DIAGNOSTIC), maxon::UInt64(enum56::OUTPUT::WARNING), maxon::UInt64(enum56::OUTPUT::CRITICAL), maxon::UInt64(enum56::OUTPUT::PRETTYPRINT), maxon::UInt64(enum56::OUTPUT::NOLINEBREAK), maxon::UInt64(enum56::OUTPUT::HEADER)};
		static const maxon::EnumInfo OUTPUT_info{"OUTPUT", SIZEOF(OUTPUT), true, "NONE\0DIAGNOSTIC\0WARNING\0CRITICAL\0PRETTYPRINT\0NOLINEBREAK\0HEADER\0", OUTPUT_values, std::extent<decltype(OUTPUT_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_OUTPUT56(){ return enum56::OUTPUT_info; }
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(DT_OUTPUT, , "net.maxon.datatype.enum.output");
#ifdef MAXON_TARGET_DEBUG
#else
#endif
#ifdef MAXON_TARGET_DEBUG
#else
#endif
#ifdef MAXON_TARGET_MACOS
#endif
#if defined MAXON_TARGET_DEBUG
#else
#endif
}
#endif

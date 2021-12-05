#if 1
#ifndef APIBASE_H__
#endif
#if defined(MAXON_TARGET_MACOS) || defined(MAXON_TARGET_IOS)
#if defined(MAXON_TARGET_CPU_INTEL)
#elif defined MAXON_TARGET_64BIT
#else
#endif
#elif defined MAXON_TARGET_LINUX || defined MAXON_TARGET_ANDROID
#elif !defined(MAXON_TARGET_WINDOWS)
#endif
namespace maxon
{
	namespace enum38
	{
		enum class TARGETAUDIENCE
		{
			DEBUGGER = 1 << 1,
			DEVELOPERS = 1 << 2,
			USERS = 1 << 3,
			ALL = DEBUGGER | DEVELOPERS | USERS,
		} ;
		static const maxon::UInt64 TARGETAUDIENCE_values[] = {maxon::UInt64(enum38::TARGETAUDIENCE::DEBUGGER), maxon::UInt64(enum38::TARGETAUDIENCE::DEVELOPERS), maxon::UInt64(enum38::TARGETAUDIENCE::USERS), maxon::UInt64(enum38::TARGETAUDIENCE::ALL)};
		static const maxon::EnumInfo TARGETAUDIENCE_info{"TARGETAUDIENCE", SIZEOF(TARGETAUDIENCE), true, "DEBUGGER\0DEVELOPERS\0USERS\0ALL\0", TARGETAUDIENCE_values, std::extent<decltype(TARGETAUDIENCE_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_TARGETAUDIENCE38(){ return enum38::TARGETAUDIENCE_info; }
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(DT_TARGETAUDIENCE, , "net.maxon.datatype.enum.targetaudience");
	namespace enum49
	{
		enum class WRITEMETA
		{
			DEFAULT = 1 << 0,							// Default output.
			WARNING = 1 << 1,							// Warning output.
			CRITICAL = 1 << 2,						// Critical output.
		
			NONEWLINE = 1 << 3,						// No \n add the end of the string
		
			UI_SYNC_DRAW = 1 << 12				// Make a synchronous UI redraw
		} ;
		static const maxon::UInt64 WRITEMETA_values[] = {maxon::UInt64(enum49::WRITEMETA::DEFAULT), maxon::UInt64(enum49::WRITEMETA::WARNING), maxon::UInt64(enum49::WRITEMETA::CRITICAL), maxon::UInt64(enum49::WRITEMETA::NONEWLINE), maxon::UInt64(enum49::WRITEMETA::UI_SYNC_DRAW)};
		static const maxon::EnumInfo WRITEMETA_info{"WRITEMETA", SIZEOF(WRITEMETA), true, "DEFAULT\0WARNING\0CRITICAL\0NONEWLINE\0UI_SYNC_DRAW\0", WRITEMETA_values, std::extent<decltype(WRITEMETA_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_WRITEMETA49(){ return enum49::WRITEMETA_info; }
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(DT_WRITEMETA, , "net.maxon.datatype.enum.writemeta");
	namespace enum60
	{
		enum class OUTPUT
		{
			DIAGNOSTIC		= (1 << 0),	 ///< diagnostic output, shows up if this group of output is activated. This is also the default
			WARNING				= (1 << 1),	 ///< warning output, shows up if this group of output is activated
			CRITICAL			= (1 << 2),	 ///< critical output, shows up if this group of output is activated
		
			NOLINEBREAK		= (1 << 29), ///< if set, no line break is added
			HEADER				= (1 << 30)  ///< if set, header with line number and file name is added
		} ;
		static const maxon::UInt64 OUTPUT_values[] = {maxon::UInt64(enum60::OUTPUT::DIAGNOSTIC), maxon::UInt64(enum60::OUTPUT::WARNING), maxon::UInt64(enum60::OUTPUT::CRITICAL), maxon::UInt64(enum60::OUTPUT::NOLINEBREAK), maxon::UInt64(enum60::OUTPUT::HEADER)};
		static const maxon::EnumInfo OUTPUT_info{"OUTPUT", SIZEOF(OUTPUT), true, "DIAGNOSTIC\0WARNING\0CRITICAL\0NOLINEBREAK\0HEADER\0", OUTPUT_values, std::extent<decltype(OUTPUT_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_OUTPUT60(){ return enum60::OUTPUT_info; }
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

#if 1
#if 1
#endif
#if defined(MAXON_TARGET_MACOS)
#elif defined MAXON_TARGET_LINUX || defined MAXON_TARGET_ANDROID
#elif defined(MAXON_TARGET_IOS)
#if defined(MAXON_TARGET_CPU_INTEL)
#elif defined MAXON_TARGET_64BIT
#else
#endif
#elif !defined(MAXON_TARGET_WINDOWS)
#endif
namespace maxon
{
	namespace enum40 { enum class TARGETAUDIENCE
	{
		DEBUGGER = 1 << 1,
		DEVELOPERS = 1 << 2,
		USERS = 1 << 3,
		ALL = DEBUGGER | DEVELOPERS | USERS,
	} ; }
	maxon::String PrivateToString_TARGETAUDIENCE40(std::underlying_type<enum40::TARGETAUDIENCE>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum40::TARGETAUDIENCE::DEBUGGER, (maxon::UInt64) enum40::TARGETAUDIENCE::DEVELOPERS, (maxon::UInt64) enum40::TARGETAUDIENCE::USERS, (maxon::UInt64) enum40::TARGETAUDIENCE::ALL};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "TARGETAUDIENCE", SIZEOF(x), true, values, "DEBUGGER\0DEVELOPERS\0USERS\0ALL\0", fmt);
	}
	maxon::Id PrivateGetEnumId(TARGETAUDIENCE*) { return maxon::Id("net.maxon.datatype.enum.targetaudience"); }
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(DT_TARGETAUDIENCE, , "net.maxon.datatype.enum.targetaudience");
	namespace enum51 { enum class WRITEMETA
	{
		DEFAULT = 1 << 0,							// Default output.
		WARNING = 1 << 1,							// Warning output.
		CRITICAL = 1 << 2,						// Critical output.
	
		NONEWLINE = 1 << 3,						// No \n add the end of the string
	
		UI_SYNC_DRAW = 1 << 12				// Make a synchronous UI redraw
	} ; }
	maxon::String PrivateToString_WRITEMETA51(std::underlying_type<enum51::WRITEMETA>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum51::WRITEMETA::DEFAULT, (maxon::UInt64) enum51::WRITEMETA::WARNING, (maxon::UInt64) enum51::WRITEMETA::CRITICAL, (maxon::UInt64) enum51::WRITEMETA::NONEWLINE, (maxon::UInt64) enum51::WRITEMETA::UI_SYNC_DRAW};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "WRITEMETA", SIZEOF(x), true, values, "DEFAULT\0WARNING\0CRITICAL\0NONEWLINE\0UI_SYNC_DRAW\0", fmt);
	}
	maxon::Id PrivateGetEnumId(WRITEMETA*) { return maxon::Id("net.maxon.datatype.enum.writemeta"); }
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(DT_WRITEMETA, , "net.maxon.datatype.enum.writemeta");
	namespace enum62 { enum class OUTPUT
	{
		DIAGNOSTIC		= (1 << 0),	 ///< diagnostic output, shows up if this group of output is activated. This is also the default
		WARNING				= (1 << 1),	 ///< warning output, shows up if this group of output is activated
		CRITICAL			= (1 << 2),	 ///< critical output, shows up if this group of output is activated
	
		NOLINEBREAK		= (1 << 29), ///< if set, no line break is added
		HEADER				= (1 << 30)  ///< if set, header with line number and file name is added
	} ; }
	maxon::String PrivateToString_OUTPUT62(std::underlying_type<enum62::OUTPUT>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum62::OUTPUT::DIAGNOSTIC, (maxon::UInt64) enum62::OUTPUT::WARNING, (maxon::UInt64) enum62::OUTPUT::CRITICAL, (maxon::UInt64) enum62::OUTPUT::NOLINEBREAK, (maxon::UInt64) enum62::OUTPUT::HEADER};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "OUTPUT", SIZEOF(x), true, values, "DIAGNOSTIC\0WARNING\0CRITICAL\0NOLINEBREAK\0HEADER\0", fmt);
	}
	maxon::Id PrivateGetEnumId(OUTPUT*) { return maxon::Id("net.maxon.datatype.enum.output"); }
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

#if 1
#ifdef __API_INTERN__
#else
#endif
namespace enum81 { enum class TOOLTRANSFORM_FLAG
{
	NO_TRANSFORM	= (1 << 0),
	NO_RECURSE		= (1 << 1),
	NO_PARAMS			= (1 << 2),

	NONE					= 0
} ; }
maxon::String PrivateToString_TOOLTRANSFORM_FLAG81(std::underlying_type<enum81::TOOLTRANSFORM_FLAG>::type x, const maxon::FormatStatement* fmt)
{
	const maxon::UInt64 values[] = {(maxon::UInt64) enum81::TOOLTRANSFORM_FLAG::NO_TRANSFORM, (maxon::UInt64) enum81::TOOLTRANSFORM_FLAG::NO_RECURSE, (maxon::UInt64) enum81::TOOLTRANSFORM_FLAG::NO_PARAMS, (maxon::UInt64) enum81::TOOLTRANSFORM_FLAG::NONE};
	return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "TOOLTRANSFORM_FLAG", SIZEOF(x), true, values, "NO_TRANSFORM\0NO_RECURSE\0NO_PARAMS\0NONE\0", fmt);
}
namespace enum867 { enum class MULTILINEEDITTEXTMESSAGEFLAGS
{
	NONE	= 0,						///< No flags.
	SET		= (1 << 0)			///< Set.
} ; }
maxon::String PrivateToString_MULTILINEEDITTEXTMESSAGEFLAGS867(std::underlying_type<enum867::MULTILINEEDITTEXTMESSAGEFLAGS>::type x, const maxon::FormatStatement* fmt)
{
	const maxon::UInt64 values[] = {(maxon::UInt64) enum867::MULTILINEEDITTEXTMESSAGEFLAGS::NONE, (maxon::UInt64) enum867::MULTILINEEDITTEXTMESSAGEFLAGS::SET};
	return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "MULTILINEEDITTEXTMESSAGEFLAGS", SIZEOF(x), true, values, "NONE\0SET\0", fmt);
}
namespace enum1091 { enum class MSG_DOCUMENTINFO_TYPE_BEFOREMERGE_RESULT
{
	CANCEL,				///< Allows to cancel the merge.
	MERGE,				///< Default, as before, just merge.
	NEWSCENE			///< Overwrites the merge flag and loads the scene as opened with load.\n
								///< In that case the message @ref MSG_DOCUMENTINFO_TYPE_MERGE will not be send to the original document but a @ref MSG_DOCUMENTINFO_TYPE_LOAD message instead.
} ; }
maxon::String PrivateToString_MSG_DOCUMENTINFO_TYPE_BEFOREMERGE_RESULT1091(std::underlying_type<enum1091::MSG_DOCUMENTINFO_TYPE_BEFOREMERGE_RESULT>::type x, const maxon::FormatStatement* fmt)
{
	const maxon::UInt64 values[] = {(maxon::UInt64) enum1091::MSG_DOCUMENTINFO_TYPE_BEFOREMERGE_RESULT::CANCEL, (maxon::UInt64) enum1091::MSG_DOCUMENTINFO_TYPE_BEFOREMERGE_RESULT::MERGE, (maxon::UInt64) enum1091::MSG_DOCUMENTINFO_TYPE_BEFOREMERGE_RESULT::NEWSCENE};
	return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "MSG_DOCUMENTINFO_TYPE_BEFOREMERGE_RESULT", SIZEOF(x), false, values, "CANCEL\0MERGE\0NEWSCENE\0", fmt);
}
#ifndef __API_INTERN__
#endif
#endif

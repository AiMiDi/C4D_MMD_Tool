#if 1
#ifdef __API_INTERN__
#else
#endif
#ifdef CINEWARE_NAMESPACE_ENABLE
CINEWARE_NAMESPACE_BEGIN
#endif
namespace enum87
{
	enum class TOOLTRANSFORM_FLAG
	{
		NO_TRANSFORM	= (1 << 0),
		NO_RECURSE		= (1 << 1),
		NO_PARAMS			= (1 << 2),
	
		NONE					= 0
	} ;
	static const maxon::UInt64 TOOLTRANSFORM_FLAG_values[] = {maxon::UInt64(enum87::TOOLTRANSFORM_FLAG::NO_TRANSFORM), maxon::UInt64(enum87::TOOLTRANSFORM_FLAG::NO_RECURSE), maxon::UInt64(enum87::TOOLTRANSFORM_FLAG::NO_PARAMS), maxon::UInt64(enum87::TOOLTRANSFORM_FLAG::NONE)};
	static const maxon::EnumInfo TOOLTRANSFORM_FLAG_info{"TOOLTRANSFORM_FLAG", SIZEOF(TOOLTRANSFORM_FLAG), true, "NO_TRANSFORM\0NO_RECURSE\0NO_PARAMS\0NONE\0", TOOLTRANSFORM_FLAG_values, std::extent<decltype(TOOLTRANSFORM_FLAG_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_TOOLTRANSFORM_FLAG87(){ return enum87::TOOLTRANSFORM_FLAG_info; }
namespace enum890
{
	enum class MULTILINEEDITTEXTMESSAGEFLAGS
	{
		NONE	= 0,						///< No flags.
		SET		= (1 << 0)			///< Set.
	} ;
	static const maxon::UInt64 MULTILINEEDITTEXTMESSAGEFLAGS_values[] = {maxon::UInt64(enum890::MULTILINEEDITTEXTMESSAGEFLAGS::NONE), maxon::UInt64(enum890::MULTILINEEDITTEXTMESSAGEFLAGS::SET)};
	static const maxon::EnumInfo MULTILINEEDITTEXTMESSAGEFLAGS_info{"MULTILINEEDITTEXTMESSAGEFLAGS", SIZEOF(MULTILINEEDITTEXTMESSAGEFLAGS), true, "NONE\0SET\0", MULTILINEEDITTEXTMESSAGEFLAGS_values, std::extent<decltype(MULTILINEEDITTEXTMESSAGEFLAGS_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_MULTILINEEDITTEXTMESSAGEFLAGS890(){ return enum890::MULTILINEEDITTEXTMESSAGEFLAGS_info; }
namespace enum1128
{
	enum class MSG_DOCUMENTINFO_TYPE_BEFOREMERGE_RESULT
	{
		CANCEL,				///< Allows to cancel the merge.
		MERGE,				///< Default, as before, just merge.
		NEWSCENE			///< Overwrites the merge flag and loads the scene as opened with load.\n
									///< In that case the message @ref MSG_DOCUMENTINFO_TYPE_MERGE will not be send to the original document but a @ref MSG_DOCUMENTINFO_TYPE_LOAD message instead.
	} ;
	static const maxon::UInt64 MSG_DOCUMENTINFO_TYPE_BEFOREMERGE_RESULT_values[] = {maxon::UInt64(enum1128::MSG_DOCUMENTINFO_TYPE_BEFOREMERGE_RESULT::CANCEL), maxon::UInt64(enum1128::MSG_DOCUMENTINFO_TYPE_BEFOREMERGE_RESULT::MERGE), maxon::UInt64(enum1128::MSG_DOCUMENTINFO_TYPE_BEFOREMERGE_RESULT::NEWSCENE)};
	static const maxon::EnumInfo MSG_DOCUMENTINFO_TYPE_BEFOREMERGE_RESULT_info{"MSG_DOCUMENTINFO_TYPE_BEFOREMERGE_RESULT", SIZEOF(MSG_DOCUMENTINFO_TYPE_BEFOREMERGE_RESULT), false, "CANCEL\0MERGE\0NEWSCENE\0", MSG_DOCUMENTINFO_TYPE_BEFOREMERGE_RESULT_values, std::extent<decltype(MSG_DOCUMENTINFO_TYPE_BEFOREMERGE_RESULT_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_MSG_DOCUMENTINFO_TYPE_BEFOREMERGE_RESULT1128(){ return enum1128::MSG_DOCUMENTINFO_TYPE_BEFOREMERGE_RESULT_info; }
#ifndef __API_INTERN__
#endif
#ifdef CINEWARE_NAMESPACE_ENABLE
CINEWARE_NAMESPACE_END
#endif
#endif

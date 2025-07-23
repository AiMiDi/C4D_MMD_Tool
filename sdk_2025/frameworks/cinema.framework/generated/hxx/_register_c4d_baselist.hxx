#if 1
#ifdef __API_INTERN__
#else
#endif
namespace cinema
{
	namespace enum101
	{
		enum class TOOLTRANSFORM_FLAG
		{
			NO_TRANSFORM	= (1 << 0),
			NO_RECURSE		= (1 << 1),
			NO_PARAMS			= (1 << 2),
		
			NONE					= 0
		} ;
		static const maxon::UInt64 TOOLTRANSFORM_FLAG_values[] = {maxon::UInt64(enum101::TOOLTRANSFORM_FLAG::NO_TRANSFORM), maxon::UInt64(enum101::TOOLTRANSFORM_FLAG::NO_RECURSE), maxon::UInt64(enum101::TOOLTRANSFORM_FLAG::NO_PARAMS), maxon::UInt64(enum101::TOOLTRANSFORM_FLAG::NONE)};
		static const maxon::EnumInfo TOOLTRANSFORM_FLAG_info{"TOOLTRANSFORM_FLAG", SIZEOF(TOOLTRANSFORM_FLAG), true, "NO_TRANSFORM\0NO_RECURSE\0NO_PARAMS\0NONE\0", TOOLTRANSFORM_FLAG_values, std::extent<decltype(TOOLTRANSFORM_FLAG_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_TOOLTRANSFORM_FLAG101(){ return enum101::TOOLTRANSFORM_FLAG_info; }
	namespace enum134
	{
		enum class MODIFIER_FLAG : Int64
		{
			NO_NORMAL_DEFORMATION = (1 << 0),  ///< Will prevent the deformer or deformer tag from deforming the normals via tangent space transformation.
			NONE = 0                           ///< No flags.
		} ;
		static const maxon::UInt64 MODIFIER_FLAG_values[] = {maxon::UInt64(enum134::MODIFIER_FLAG::NO_NORMAL_DEFORMATION), maxon::UInt64(enum134::MODIFIER_FLAG::NONE)};
		static const maxon::EnumInfo MODIFIER_FLAG_info{"MODIFIER_FLAG", SIZEOF(MODIFIER_FLAG), true, "NO_NORMAL_DEFORMATION\0NONE\0", MODIFIER_FLAG_values, std::extent<decltype(MODIFIER_FLAG_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_MODIFIER_FLAG134(){ return enum134::MODIFIER_FLAG_info; }
	namespace enum943
	{
		enum class MULTILINEEDITTEXTMESSAGEFLAGS
		{
			NONE	= 0,						///< No flags.
			SET		= (1 << 0)			///< Set.
		} ;
		static const maxon::UInt64 MULTILINEEDITTEXTMESSAGEFLAGS_values[] = {maxon::UInt64(enum943::MULTILINEEDITTEXTMESSAGEFLAGS::NONE), maxon::UInt64(enum943::MULTILINEEDITTEXTMESSAGEFLAGS::SET)};
		static const maxon::EnumInfo MULTILINEEDITTEXTMESSAGEFLAGS_info{"MULTILINEEDITTEXTMESSAGEFLAGS", SIZEOF(MULTILINEEDITTEXTMESSAGEFLAGS), true, "NONE\0SET\0", MULTILINEEDITTEXTMESSAGEFLAGS_values, std::extent<decltype(MULTILINEEDITTEXTMESSAGEFLAGS_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_MULTILINEEDITTEXTMESSAGEFLAGS943(){ return enum943::MULTILINEEDITTEXTMESSAGEFLAGS_info; }
	namespace enum1043
	{
		enum class SCRIPT_CONTEXT
		{
				UNKNOWN = 0,                  ///< Used for unknown script types.
				SCRIPT_MANAGER = 1,           ///< Used for Script Manager scripts.
				GENERATOR_PYTHON = 2,         ///< Used for Python Generator object scripts.
				EFFECTOR_PARAMETER_MODE = 3,  ///< Used for Python Effector parameter control scripts.
				EFFECTOR_FULL_MODE = 4,       ///< Used for Python Effector full control scripts.
				FIELD_OBJECT = 5,             ///< Used for Python Field object scripts.
				FIELD_LAYER = 6,              ///< Used for Python Field layer scripts.
				TAG_PYTHON = 7,               ///< Used for Python tag scripts.
				TAG_INTERACTION = 8,          ///< Used for Interaction tag scripts.
				TAG_VISUAL_SELECTOR = 9,      ///< Used for Visual Selector tag scripts.
				TAG_CHARACTER_COMPONENT = 10, ///< Used for Character Component tag scripts.
				MAT_SKETCHTOON_COLOR = 11,    ///< Used for Sketch and Toon color channel scripts.
				MAT_SKETCHTOON_THICKNESS = 12,///< Used for Sketch and Toon thickness channel scripts.
				MAT_SKETCHTOON_OPACITY = 13,  ///< Used for Sketch and Toon opacity channel scripts.
				GVNODE_PYTHON = 14,           ///< Used for Python Xpresso node scripts.
		} ;
		static const maxon::UInt64 SCRIPT_CONTEXT_values[] = {maxon::UInt64(enum1043::SCRIPT_CONTEXT::UNKNOWN), maxon::UInt64(enum1043::SCRIPT_CONTEXT::SCRIPT_MANAGER), maxon::UInt64(enum1043::SCRIPT_CONTEXT::GENERATOR_PYTHON), maxon::UInt64(enum1043::SCRIPT_CONTEXT::EFFECTOR_PARAMETER_MODE), maxon::UInt64(enum1043::SCRIPT_CONTEXT::EFFECTOR_FULL_MODE), maxon::UInt64(enum1043::SCRIPT_CONTEXT::FIELD_OBJECT), maxon::UInt64(enum1043::SCRIPT_CONTEXT::FIELD_LAYER), maxon::UInt64(enum1043::SCRIPT_CONTEXT::TAG_PYTHON), maxon::UInt64(enum1043::SCRIPT_CONTEXT::TAG_INTERACTION), maxon::UInt64(enum1043::SCRIPT_CONTEXT::TAG_VISUAL_SELECTOR), maxon::UInt64(enum1043::SCRIPT_CONTEXT::TAG_CHARACTER_COMPONENT), maxon::UInt64(enum1043::SCRIPT_CONTEXT::MAT_SKETCHTOON_COLOR), maxon::UInt64(enum1043::SCRIPT_CONTEXT::MAT_SKETCHTOON_THICKNESS), maxon::UInt64(enum1043::SCRIPT_CONTEXT::MAT_SKETCHTOON_OPACITY), maxon::UInt64(enum1043::SCRIPT_CONTEXT::GVNODE_PYTHON)};
		static const maxon::EnumInfo SCRIPT_CONTEXT_info{"SCRIPT_CONTEXT", SIZEOF(SCRIPT_CONTEXT), false, "UNKNOWN\0SCRIPT_MANAGER\0GENERATOR_PYTHON\0EFFECTOR_PARAMETER_MODE\0EFFECTOR_FULL_MODE\0FIELD_OBJECT\0FIELD_LAYER\0TAG_PYTHON\0TAG_INTERACTION\0TAG_VISUAL_SELECTOR\0TAG_CHARACTER_COMPONENT\0MAT_SKETCHTOON_COLOR\0MAT_SKETCHTOON_THICKNESS\0MAT_SKETCHTOON_OPACITY\0GVNODE_PYTHON\0", SCRIPT_CONTEXT_values, std::extent<decltype(SCRIPT_CONTEXT_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_SCRIPT_CONTEXT1043(){ return enum1043::SCRIPT_CONTEXT_info; }
	namespace enum1051
	{
		enum class SCRIPT_LANGUAGE
		{
			UNKOWN = 0, ///< Used for all unknown syntaxes.
			PYTHON = 1, ///< Used for Standard CPython syntax.
			OSL = 2     ///< Used for Open Shading Language syntax.
		} ;
		static const maxon::UInt64 SCRIPT_LANGUAGE_values[] = {maxon::UInt64(enum1051::SCRIPT_LANGUAGE::UNKOWN), maxon::UInt64(enum1051::SCRIPT_LANGUAGE::PYTHON), maxon::UInt64(enum1051::SCRIPT_LANGUAGE::OSL)};
		static const maxon::EnumInfo SCRIPT_LANGUAGE_info{"SCRIPT_LANGUAGE", SIZEOF(SCRIPT_LANGUAGE), false, "UNKOWN\0PYTHON\0OSL\0", SCRIPT_LANGUAGE_values, std::extent<decltype(SCRIPT_LANGUAGE_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_SCRIPT_LANGUAGE1051(){ return enum1051::SCRIPT_LANGUAGE_info; }
	namespace enum1287
	{
		enum class MSG_DOCUMENTINFO_TYPE_BEFOREMERGE_RESULT
		{
			CANCEL,				///< Allows to cancel the merge.
			MERGE,				///< Default, as before, just merge.
			NEWSCENE			///< Overwrites the merge flag and loads the scene as opened with load.\n
										///< In that case the message @ref MSG_DOCUMENTINFO_TYPE_MERGE will not be send to the original document but a @ref MSG_DOCUMENTINFO_TYPE_LOAD message instead.
		} ;
		static const maxon::UInt64 MSG_DOCUMENTINFO_TYPE_BEFOREMERGE_RESULT_values[] = {maxon::UInt64(enum1287::MSG_DOCUMENTINFO_TYPE_BEFOREMERGE_RESULT::CANCEL), maxon::UInt64(enum1287::MSG_DOCUMENTINFO_TYPE_BEFOREMERGE_RESULT::MERGE), maxon::UInt64(enum1287::MSG_DOCUMENTINFO_TYPE_BEFOREMERGE_RESULT::NEWSCENE)};
		static const maxon::EnumInfo MSG_DOCUMENTINFO_TYPE_BEFOREMERGE_RESULT_info{"MSG_DOCUMENTINFO_TYPE_BEFOREMERGE_RESULT", SIZEOF(MSG_DOCUMENTINFO_TYPE_BEFOREMERGE_RESULT), false, "CANCEL\0MERGE\0NEWSCENE\0", MSG_DOCUMENTINFO_TYPE_BEFOREMERGE_RESULT_values, std::extent<decltype(MSG_DOCUMENTINFO_TYPE_BEFOREMERGE_RESULT_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_MSG_DOCUMENTINFO_TYPE_BEFOREMERGE_RESULT1287(){ return enum1287::MSG_DOCUMENTINFO_TYPE_BEFOREMERGE_RESULT_info; }
#ifndef __API_INTERN__
#endif
}
#endif

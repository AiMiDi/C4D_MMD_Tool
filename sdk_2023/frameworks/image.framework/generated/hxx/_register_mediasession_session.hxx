#if 1
namespace maxon
{
	namespace enum19
	{
		enum class MEDIASESSIONFLAGS
		{
			NONE = 0,
			RUNONLYANALYZE = 1 << 0, ///< run only the analyze but not the execute pass.
			FORCELOAD = 1 << 1,			 ///< loads the image even if it's already loaded.
		} ;
		static const maxon::UInt64 MEDIASESSIONFLAGS_values[] = {maxon::UInt64(enum19::MEDIASESSIONFLAGS::NONE), maxon::UInt64(enum19::MEDIASESSIONFLAGS::RUNONLYANALYZE), maxon::UInt64(enum19::MEDIASESSIONFLAGS::FORCELOAD)};
		static const maxon::EnumInfo MEDIASESSIONFLAGS_info{"MEDIASESSIONFLAGS", SIZEOF(MEDIASESSIONFLAGS), true, "NONE\0RUNONLYANALYZE\0FORCELOAD\0", MEDIASESSIONFLAGS_values, std::extent<decltype(MEDIASESSIONFLAGS_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_MEDIASESSIONFLAGS19(){ return enum19::MEDIASESSIONFLAGS_info; }
	const maxon::Char* const MediaSessionInterface::MTable::_ids = 
		"ConnectMediaConverter@9755663556e6c077\0" // Result<void> ConnectMediaConverter(const MediaConverterRef& input, const MediaConverterRef& output)
		"Convert@f96f46d9d75c5ee3\0" // Result<void> Convert(const TimeValue& targetTime, MEDIASESSIONFLAGS flags)
		"Close@3008090429c5a175\0" // Result<void> Close()
		"GetProgress@8752e62edb7eed02\0" // ProgressRef GetProgress() const
	"";
	const maxon::METHOD_FLAGS MediaSessionInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(MediaSessionInterface, , "net.maxon.image.interface.mediasession", "maxon.MediaSessionInterface", (ObserverObjectInterface::PrivateGetInterface()));
	template <typename DUMMY> maxon::Int MediaSessionInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		| maxon::details::InstantiateNullReturnValue<ProgressRef>(OVERLOAD_MAX_RANK)
		;
	}
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(MediaSessionObject, , "net.maxon.image.class.mediasessionobject");
}
#endif
static maxon::details::ForceEvaluation s_forceEval_mediasession_session(0
	| maxon::MediaSessionInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
);

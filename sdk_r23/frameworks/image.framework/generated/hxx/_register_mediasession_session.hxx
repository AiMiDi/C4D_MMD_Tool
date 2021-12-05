#if 1
namespace maxon
{
	namespace enum19 { enum class MEDIASESSIONFLAGS
	{
		NONE = 0,
		RUNONLYANALYZE = 1 << 0, ///< run only the analyze but not the execute pass.
		FORCELOAD = 1 << 1,			 ///< loads the image even if it's already loaded.
	} ; }
	maxon::String PrivateToString_MEDIASESSIONFLAGS19(std::underlying_type<enum19::MEDIASESSIONFLAGS>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum19::MEDIASESSIONFLAGS::NONE, (maxon::UInt64) enum19::MEDIASESSIONFLAGS::RUNONLYANALYZE, (maxon::UInt64) enum19::MEDIASESSIONFLAGS::FORCELOAD};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "MEDIASESSIONFLAGS", SIZEOF(x), true, values, "NONE\0RUNONLYANALYZE\0FORCELOAD\0", fmt);
	}
	const maxon::Char* const MediaSessionInterface::MTable::_ids = 
		"ConnectMediaConverter@9755663556e6c077\0" // Result<void> ConnectMediaConverter(const MediaConverterRef& input, const MediaConverterRef& output)
		"Convert@f96f46d9d75c5ee3\0" // Result<void> Convert(const TimeValue& targetTime, MEDIASESSIONFLAGS flags)
		"Close@3008090429c5a175\0" // Result<void> Close()
		"GetProgress@8b24e2918e2d98da\0" // MediaSessionProgressRef GetProgress() const
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(MediaSessionInterface, , "net.maxon.image.interface.mediasession", "maxon.MediaSessionInterface", (ObserverObjectInterface::PrivateGetInterface()));
	template <typename DUMMY> maxon::Int MediaSessionInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		| maxon::details::InstantiateNullReturnValue<MediaSessionProgressRef>(OVERLOAD_MAX_RANK)
		;
	}
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(MediaSessionObject, , "net.maxon.image.class.mediasessionobject");
}
#endif
static maxon::details::ForceEvaluation s_forceEval_mediasession_session(0
	| maxon::MediaSessionInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
);

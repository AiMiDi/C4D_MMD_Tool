#if 1
namespace maxon
{
#if defined(MAXON_TARGET_MACOS) || defined(MAXON_TARGET_IOS)
	namespace FileFormats
	{
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(MovieMP4, , "net.maxon.fileformat.moviemp4");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(MovieMov, , "net.maxon.fileformat.moviemov");
	}
#endif
}
#endif

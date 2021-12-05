#if 1
namespace maxon
{
#ifdef MAXON_TARGET_WINDOWS
	namespace FileFormats
	{
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(MovieWinMF, , "net.maxon.fileformat.moviewinmf");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(MovieMP4, , "net.maxon.fileformat.moviemp4");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(MovieWMV, , "net.maxon.fileformat.moviewmv");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(MovieASF, , "net.maxon.fileformat.movieasf");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(Movie3GP, , "net.maxon.fileformat.movie3gp");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(MovieAVI, , "net.maxon.fileformat.movieavi");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(AudioWinMF, , "net.maxon.fileformat.audiowinmf");
	}
	namespace FileFormatHandlers
	{
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(MovieWinMF, , "net.maxon.fileformathandler.moviewinmf");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(AudioWinMF, , "net.maxon.fileformathandler.audiowinmf");
	}
#elif defined MAXON_TARGET_MACOS
	namespace FileFormats
	{
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(MovieAVFoundation, , "net.maxon.fileformat.movieavfoundation");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(AudioAVFoundation, , "net.maxon.fileformat.audioavfoundation");
	}
	namespace FileFormatHandlers
	{
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(MovieAVFoundation, , "net.maxon.fileformathandler.movieavfoundation");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(AudioAVFoundation, , "net.maxon.fileformathandler.audioavfoundation");
	}
#endif
}
#endif

#if 1
namespace maxon
{
	namespace FileFormats
	{
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(ZipArchive, , "net.maxon.fileformat.ziparchive");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(GZipArchive, , "net.maxon.fileformat.gziparchive");
	}
	namespace FileFormatHandlers
	{
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(ZipDirectoryBrowser, , "net.maxon.fileformathandler.zipdirectorybrowser");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(GZipDirectoryBrowser, , "net.maxon.fileformathandler.gzipdirectorybrowser");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(ZipArchiveHandler, , "net.maxon.fileformathandler.ziparchivehandler");
#if 0
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(GZipArchiveHandler, , "net.maxon.fileformathandler.gziparchivehandler");
#endif
	}
}
#endif

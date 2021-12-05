#ifndef FILEFORMAT_ZIP_H__
#define FILEFORMAT_ZIP_H__


#include "maxon/fileformat_handler.h"


namespace maxon
{

//----------------------------------------------------------------------------------------
///
//----------------------------------------------------------------------------------------
namespace FileFormats
{
	MAXON_DECLARATION(FileFormat, ZipArchive, "net.maxon.fileformat.ziparchive");
	MAXON_DECLARATION(FileFormat, GZipArchive, "net.maxon.fileformat.gziparchive");
}

//----------------------------------------------------------------------------------------
/// Extent FileFormatHandler with zip file formats
//----------------------------------------------------------------------------------------
namespace FileFormatHandlers
{
	/// returns IoBrowseRef for directories
	MAXON_DECLARATION(FileFormatHandler, ZipDirectoryBrowser, "net.maxon.fileformathandler.zipdirectorybrowser");

	/// returns IoBrowseRef for directories
	MAXON_DECLARATION(FileFormatHandler, GZipDirectoryBrowser, "net.maxon.fileformathandler.gzipdirectorybrowser");

	/// returns ReadArchiveRef for directories
	MAXON_DECLARATION(FileFormatHandler, ZipArchiveHandler, "net.maxon.fileformathandler.ziparchivehandler");

#if 0
	/// TODO: (Tilo) implentation missing. returns ReadArchiveRef for directories
	MAXON_DECLARATION(FileFormatHandler, GZipArchiveHandler, "net.maxon.fileformathandler.gziparchivehandler");
#endif
};

}

#endif // FILEFORMAT_ZIP_H__

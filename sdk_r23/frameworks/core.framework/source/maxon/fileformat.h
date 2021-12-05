#ifndef FILEFORMAT_H__
#define FILEFORMAT_H__

#include "maxon/url.h"
#include "maxon/interfacebase.h"
#include "maxon/iostreams.h"

namespace maxon
{


namespace FILEFORMATPROPERTIES
{
	MAXON_ATTRIBUTE(Block<const String>, COMMONSUFFIXES, "net.maxon.fileformat.commonsuffixes"); ///< Returns a Block of Strings with common suffixes for this fileformat
}


//----------------------------------------------------------------------------------------
/// FileFormatInterface allows to implement and register file formats with its detection algorithm.
/// The FileFormats registry allows to register any format (e.g. FileFormats::Browsable, FileFormats::ImageJpg...).
//----------------------------------------------------------------------------------------
class FileFormatInterface : MAXON_INTERFACE_BASES(DataDictionaryObjectInterface)
{
	MAXON_INTERFACE(FileFormatInterface, MAXON_REFERENCE_CONST, "net.maxon.interface.fileformat");

private:
	Result<void> SetData(ForwardingDataPtr&& key, Data&& data) = delete;

public:
	//----------------------------------------------------------------------------------------
	/// For implementations to check if a given url/stream supports this file format.
	/// You should never call this function directly. It's triggered by FileFormatDetectionInterface::Detect()/DetectAll().
	/// @param[in] url								Url to check.
	/// @param[in] probeStream				Optional parameter that allows to read content in case that the url is a file.
	/// 															This stream is not a plain file stream but wraps a memory cache stream which allows to seek and read already loaded data without overhead.
	/// @return												Returns true if the url/stream fits to this file format implementation.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Bool> Detect(const Url& url, const InputStreamRef& probeStream) const;
};



#include "fileformat1.hxx"

//----------------------------------------------------------------------------------------
/// Registry to register/iterate all available FileFormat implementations.
//----------------------------------------------------------------------------------------
MAXON_REGISTRY(FileFormat, FileFormats, "net.maxon.registry.fileformats");

//----------------------------------------------------------------------------------------
///
//----------------------------------------------------------------------------------------
namespace FileFormats
{
	MAXON_DECLARATION(FileFormat, Browsable, "net.maxon.fileformat.browsable");
	MAXON_DECLARATION(FileFormat, File, "net.maxon.fileformat.file");
	MAXON_DECLARATION(FileFormat, MaxonDocumentBinary, "net.maxon.fileformat.maxondocumentbinary");
	MAXON_DECLARATION(FileFormat, MaxonDocumentJson, "net.maxon.fileformat.maxondocumentjson");
	MAXON_DECLARATION(FileFormat, MaxonDocumentXml, "net.maxon.fileformat.maxondocumentxml");
}

/// This class should be added to your own image fileformat implementation.
/// It implements default values for GetData() for FILEFORMATPROPERTIES of files.
MAXON_DECLARATION(Class<FileFormat>, FileFormatBaseClass, "net.maxon.class.fileformatbase");

#include "fileformat2.hxx"

}

#endif // FILEFORMAT_H__

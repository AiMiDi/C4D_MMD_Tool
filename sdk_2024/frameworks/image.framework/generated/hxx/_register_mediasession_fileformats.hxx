#if 1
namespace maxon
{
	const maxon::Char* const MediaSessionFileFormatHandlerInterface::MTable::_ids = 
	"";
	const maxon::METHOD_FLAGS MediaSessionFileFormatHandlerInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(MediaSessionFileFormatHandlerInterface, , "net.maxon.image.interface.mediasessionfileformathandler", (FileFormatHandlerInterface::PrivateGetInterface()));
	namespace FileFormats
	{
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(ImageJpg, , "net.maxon.fileformat.imagejpg");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(ImageBmp, , "net.maxon.fileformat.imagebmp");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(ImageIff, , "net.maxon.fileformat.imageiff");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(ImageIco, , "net.maxon.fileformat.imageico");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(ImagePng, , "net.maxon.fileformat.imagepng");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(ImageTiff, , "net.maxon.fileformat.imagetiff");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(ImageHdr, , "net.maxon.fileformat.imagehdr");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(ImagePict, , "net.maxon.fileformat.imagepict");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(ImagePsd, , "net.maxon.fileformat.imagepsd");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(ImagePsb, , "net.maxon.fileformat.imagepsb");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(ImageTga, , "net.maxon.fileformat.imagetga");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(ImageRla, , "net.maxon.fileformat.imagerla");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(ImageRpf, , "net.maxon.fileformat.imagerpf");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(ImageGif, , "net.maxon.fileformat.imagegif");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(ImageDds, , "net.maxon.fileformat.imagedds");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(ImageDpx, , "net.maxon.fileformat.imagedpx");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(MovieImageSequence, , "net.maxon.fileformat.movieimagesequence");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(AudioWav, , "net.maxon.fileformat.audiowav");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(AudioAiff, , "net.maxon.fileformat.audioaiff");
	}
	namespace FileFormatHandlers
	{
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(ImageLoaderJpg, , "net.maxon.fileformathandler.imageloaderjpg");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(ImageLoaderBmp, , "net.maxon.fileformathandler.imageloaderbmp");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(ImageLoaderIff, , "net.maxon.fileformathandler.imageloaderiff");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(ImageLoaderIco, , "net.maxon.fileformathandler.imageloaderico");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(ImageLoaderPng, , "net.maxon.fileformathandler.imageloaderpng");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(ImageLoaderTiff, , "net.maxon.fileformathandler.imageloadertiff");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(ImageLoaderHdr, , "net.maxon.fileformathandler.imageloaderhdr");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(ImageLoaderPict, , "net.maxon.fileformathandler.imageloaderpict");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(ImageLoaderPsd, , "net.maxon.fileformathandler.imageloaderpsd");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(ImageLoaderPsb, , "net.maxon.fileformathandler.imageloaderpsb");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(MovieImageSequence, , "net.maxon.fileformathandler.movieimagesequence");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(AudioLoaderWav, , "net.maxon.fileformathandler.audioloaderwav");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(AudioLoaderAiff, , "net.maxon.fileformathandler.audioloaderaiff");
	}
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(FileFormatImageBaseClass, , "net.maxon.image.class.fileformatimagebase");
}
#endif

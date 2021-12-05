#ifndef NETWORK_SMTPMAIL_H__
#define NETWORK_SMTPMAIL_H__

#include "maxon/apibase.h"
#include "maxon/url.h"
#include "maxon/error.h"
#include "maxon/array.h"
#include "maxon/block.h"

namespace maxon
{

/// @addtogroup IO
/// @{

#define MM_MediaText          "text"
#define MM_MediaImage         "image"
#define MM_MediaAudio         "audio"
#define MM_MediaVideo         "video"
#define MM_MediaApplication   "application"
#define MM_MediaMultiPart     "multipart"
#define MM_MediaMessage       "message"

#define MM_SubHtml            "html"
#define MM_SubPlain           "plain"

#define MM_SubRtf             "rtf"
#define MM_SubBinhex          "mac-binhex40"
#define MM_SubStuffit         "x-stuffit"
#define MM_SubZip             "x-zip-compressed"
#define MM_SubOctet           "octet-stream"
#define MM_SubPS              "postscript"
#define MM_SubPdf             "pdf"

#define MM_SubGif             "gif"
#define MM_SubJpeg            "jpeg"
#define MM_SubPng             "png"
#define MM_SubTiff            "tiff"

#define MM_SubMpeg            "mpeg"
#define MM_SubMov             "quicktime"
#define MM_SubAVI             "x-msvideo"

#define MM_EncodingBase64     "base64"

//----------------------------------------------------------------------------------------
/// attachment types for SmtpMailInterface
//----------------------------------------------------------------------------------------
enum class MEDIA
{
	UNKNOWN	= 0,	///< unknown media
	TEXT		= 1,	///< mediatype text
	IMAGE		= 2,	///< mediatype image
	AUDIO		= 3,	///< mediatype audio
	VIDEO		= 4,	///< mediatype video
	APP			= 5,	///< mediatype application
	MULTI		= 6,	///< mediatype multipart
} MAXON_ENUM_LIST(MEDIA);

//----------------------------------------------------------------------------------------
/// subtype of media types for SmtpMailInterface
//----------------------------------------------------------------------------------------
enum class MEDIASUB
{
	UNKNOWN					= 0,

	// text
	HTML						= 100,
	HTML_PLAIN			= 101,

	// image
	GIF							= 200,
	JPEG						= 201,
	PNG							= 202,
	TIFF						= 203,

	// video
	MPEG						= 400,
	QUICKTIME				= 401,
	X_MSVIDEO				= 402,

	// application
	RTF							= 500,
	MAC_BINHEX40		= 501,
	X_STUFFIT				= 502,
	ZIP							= 503,
	OCTET_STREAM		= 504,
	POSTSCRIPT			= 505,
	PDF							= 506,
} MAXON_ENUM_LIST(MEDIASUB);

//----------------------------------------------------------------------------------------
/// Smtp Error.
/// This error is returned from functions of the SmtpMailInterface.
//----------------------------------------------------------------------------------------
class SmtpErrorInterface : MAXON_INTERFACE_BASES(ErrorInterface)
{
	MAXON_INTERFACE(SmtpErrorInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.interface.smtperror");
};

enum class SMTPRECEIVERFIELD : UChar
{
	TO,
	CC,
	BCC
} MAXON_ENUM_LIST(SMTPRECEIVERFIELD);

struct SmtpReceiver
{
	SMTPRECEIVERFIELD	type;
	String						emailAddress;
	String						clearName;

	SmtpReceiver() : type(SMTPRECEIVERFIELD::TO)
	{
	}

	SmtpReceiver(const String& address, const String& name) : type(SMTPRECEIVERFIELD::TO), emailAddress(address), clearName(name)
	{
	}

	SmtpReceiver(SMTPRECEIVERFIELD xtype, const String& address, const String& name) : type(xtype), emailAddress(address), clearName(name)
	{
	}
};

//----------------------------------------------------------------------------------------
/// Send mail via smtp.
//----------------------------------------------------------------------------------------
class SmtpMailInterface
{
	MAXON_INTERFACE_NONVIRTUAL(SmtpMailInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.smtpmail");

public:
	//----------------------------------------------------------------------------------------
	/// function to allocate new instances of this object. use SmtpMailRef mail(MAXON_SOURCE_LOCATION); to allocate new object.
	/// SmtpMailRef is freed automatically.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD SmtpMailInterface* Alloc(MAXON_SOURCE_LOCATION_DECLARATION);

	//----------------------------------------------------------------------------------------
	/// Set the text body of the mail.
	/// @param[in] text								The text of the mail body.
	/// @return												IsOk() if the function succeded. HasError() if failed.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> AttachText(const String& text);

	//----------------------------------------------------------------------------------------
	/// Attach an binary file.
	/// @param[in] fname							The Url of the attachment. Set the right mode so that the mail gets the right type.
	/// @param[in] media							See MEDIA.
	/// @param[in] sub								See MEDIASUB.
	/// @return												IsOk() if the function succeded. HasError() if failed.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> AttachBin(const Url& fname, MEDIA media = MEDIA::UNKNOWN, MEDIASUB sub = MEDIASUB::UNKNOWN);

	//----------------------------------------------------------------------------------------
	/// Attach an binary file.
	/// @param[in] fileName						File name of the attachment.
	/// @param[in] data								Binary data to attach.
	/// @param[in] media							See MEDIA.
	/// @param[in] sub								See MEDIASUB.
	/// @return												IsOk() if the function succeded. HasError() if failed.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> AttachBin(const String& fileName, const Block<const Char>& data, MEDIA media = MEDIA::UNKNOWN, MEDIASUB sub = MEDIASUB::UNKNOWN);

	//----------------------------------------------------------------------------------------
	/// Set the sender email address and name.
	/// @param[in] sender							Email address of the sender.
	/// @param[in] senderClearName		Real name of the sender.
	/// @return												IsOk() if the function succeded. HasError() if failed.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> SetSender(const String& sender, const String& senderClearName);

	//----------------------------------------------------------------------------------------
	/// Get the sender email address and name.
	/// @param[out] sender						Retrieves the email address of the sender.
	/// @param[out] senderClearName		Retrieves the real name of the sender.
	/// @return												IsOk() if the function succeded. HasError() if failed.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> GetSender(String& sender, String& senderClearName) const;

	//----------------------------------------------------------------------------------------
	/// Set the receiver email address and name.
	/// @param[in] receiver						Email addresses of the receivers.
	/// @return												IsOk() if the function succeded. HasError() if failed.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> SetReceiver(const Block<const SmtpReceiver>& receiver);

	//----------------------------------------------------------------------------------------
	/// Get the receiver email address and name.
	/// @param[out] receiver					Retrieves the email address of the receiver.
	/// @return												IsOk() if the function succeded. HasError() if failed.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> GetReceiver(WritableArrayInterface<SmtpReceiver>& receiver) const;

	//----------------------------------------------------------------------------------------
	/// Set the subject of the mail.
	/// @param[in] subject						Mail subject.
	/// @return												IsOk() if the function succeded. HasError() if failed.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> SetSubject(const String& subject);

	//----------------------------------------------------------------------------------------
	/// Get the subject of the mail.
	/// @param[out] subject						Retrieves the email subject.
	/// @return												IsOk() if the function succeded. HasError() if failed.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> GetSubject(String& subject) const;

	//----------------------------------------------------------------------------------------
	/// Sets the login user name and password for the smtp server.
	/// @param[in] user								Username to logon at the smtp server.
	/// @param[in] passwd							Password to logon at the smtp server.
	/// @return												IsOk() if the function succeded. HasError() if failed.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> SetUserPassword(const String& user, const String& passwd);

	//----------------------------------------------------------------------------------------
	/// Gets the login user name and password for the smtp server.
	/// @param[out] user							Retrieves username to logon at the smtp server.
	/// @param[out] passwd						Retrieves to logon at the smtp server.
	/// @return												IsOk() if the function succeded. HasError() if failed.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> GetUserPassword(String& user, String& passwd) const;

	//----------------------------------------------------------------------------------------
	/// Start the process of sending the mail.
	/// @param[in] hostName						Smtp server address or name.
	/// @param[in] port								Smtp server port.
	/// @return												IsOk() if the function succeded. HasError() if failed.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> SendMimeMail(const String& hostName, Int port);
};

#include "network_smtpmail1.hxx"

#include "network_smtpmail2.hxx"

/// @}

} // namespace maxon


#endif // NETWORK_SMTPMAIL_H__

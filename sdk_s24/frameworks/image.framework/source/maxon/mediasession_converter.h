#ifndef MEDIASESSION_CONVERTER_H__
#define MEDIASESSION_CONVERTER_H__


#include "maxon/mediasession_base.h"
#include "maxon/mediasession_stream.h"



namespace maxon
{

class MediaStreamRef;
class MediaConverterRef;

//----------------------------------------------------------------------------------------
/// MediaConverterInterface is a generic interface to access media conversions.
/// It allows to connect streams and triggers the evaluation of the network.
//----------------------------------------------------------------------------------------
class MediaConverterInterface : MAXON_INTERFACE_BASES(MediaBaseInterface)
{
	MAXON_INTERFACE(MediaConverterInterface, MAXON_REFERENCE_NORMAL, "net.maxon.image.interface.mediaconverter");

public:

	//----------------------------------------------------------------------------------------
	/// Returns true for media importers: The converter supports the import strategy where the
	/// input pushes the read data to the output nodes.
	/// The media session can only connect converters which support the same strategies, e.g. MediaStreamImageDataImportInterface.
	/// @return												True for supported imported strategy, false otherwise.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool SupportImportStrategy() const;

	//----------------------------------------------------------------------------------------
	/// Returns true for media exporters: The converter supports the export strategy where the
	/// output pulls the required data from the input nodes.
	/// The media session can only connect converters which support the same strategies, e.g. MediaStreamImageDataExportInterface.
	/// @return												True for supported export strategy, false otherwise.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool SupportExportStrategy() const;

	//----------------------------------------------------------------------------------------
	/// Get the connected MediaConvertRef used as input. An empty array if it's the source/root.
	/// @return												Array of inputs.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<BaseArray<MediaConverterRef>> GetInputConverter() const;

	//----------------------------------------------------------------------------------------
	/// Adds an output stream to the converter.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> AddOutputStream(const MediaStreamRef& stream);

	//----------------------------------------------------------------------------------------
	/// Removes an output stream from the converter.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> RemoveOutputStream(const MediaStreamRef& stream);

	//----------------------------------------------------------------------------------------
	/// Returns all output streams of this converter.
	/// @param[in] flattenChildren		Return also all children streams by running recursively through all streams.
	/// @return												Array of output streams.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<BaseArray<MediaStreamRef>> GetOutputStreams(Bool flattenChildren) const;

	//----------------------------------------------------------------------------------------
	/// Analyzes the streams. A converter needs to call the same function for all inputs
	/// followed by calling stream.SubscribeStream() to signal the interest for one or more streams.
	/// @param[in] inputs							Block of input streams to evaluate.
	/// @param[in] targetTime					Target time to load.
	/// @param[in] flags							See MEDIASESSIONFLAGS for details.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Analyze(const Block<const MediaConverterRef>& inputs, const TimeValue& targetTime, MEDIASESSIONFLAGS flags);

	//----------------------------------------------------------------------------------------
	/// Prepares to execute the streams. Called after Analyze() and before Execute(). At this moment all requested streams are already subscribed.
	/// This allows to setup progress hooks to setup correctly with the necessary data.
	/// @param[in] inputs							Block of input streams to evaluate.
	/// @param[in] targetTime					Target time to load.
	/// @param[in] flags							See MEDIASESSIONFLAGS for details.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> PrepareExecute(const Block<const MediaConverterRef>& inputs, const TimeValue& targetTime, MEDIASESSIONFLAGS flags);

	//----------------------------------------------------------------------------------------
	/// Executes the streams.
	/// @param[in] inputs							Block of input streams to evaluate.
	/// @param[in] targetTime					Target time to load.
	/// @param[in] flags							See MEDIASESSIONFLAGS for details.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Execute(const Block<const MediaConverterRef>& inputs, const TimeValue& targetTime, MEDIASESSIONFLAGS flags);

	//----------------------------------------------------------------------------------------
	/// Closes the converter and closes all streams and operations.
	/// @param[in] inputs							Block of input streams to close.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Close(const Block<const MediaConverterRef>& inputs);
};


//----------------------------------------------------------------------------------------
/// An MediaConverterError is returned if a media converter want to return an error.
//----------------------------------------------------------------------------------------
class MediaConverterErrorInterface : MAXON_INTERFACE_BASES(ErrorInterface)
{
	MAXON_INTERFACE(MediaConverterErrorInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.image.interface.mediaconvertererror");
};



// include auto generated header file here
#include "mediasession_converter1.hxx"

MAXON_DECLARATION(Class<MediaConverterRef>, MediaConverterBaseClass, "net.maxon.image.class.mediaconverterbase");

// include auto generated header file here
#include "mediasession_converter2.hxx"


} // namespace maxon


#endif // MEDIASESSION_CONVERTER_H__

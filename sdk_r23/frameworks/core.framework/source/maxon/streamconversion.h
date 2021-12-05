#ifndef STREAMCONVERSION_H__
#define STREAMCONVERSION_H__

#include "maxon/dataformat.h"
#include "maxon/array.h"
#include "maxon/basearray.h"
#include "maxon/factory.h"
#include "maxon/blockbufferallocator.h"
#include "maxon/nullallocator.h"

namespace maxon
{

//----------------------------------------------------------------------------------------
/// StreamConversionInterface is a universal interface to convert data.
/// It can be used for Encryption, Compression, Encoding, Hashing, basically everything that streams data in and out.
//----------------------------------------------------------------------------------------
class StreamConversionInterface : MAXON_INTERFACE_BASES(DataDictionaryObjectInterface)
{
	MAXON_INTERFACE(StreamConversionInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.streamconversion");

public:
	//----------------------------------------------------------------------------------------
	/// Returns the recommended working size.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Int GetBatchSize() const;

	//----------------------------------------------------------------------------------------
	/// Returns the block size in of the encoder/decoder.
	/// The encoded/decoded data needs to be a multiple of GetBlockSize().
	/// This number is the count of elements of GetSourceType(), not the size in bytes!
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Int GetBlockSize() const;

	//----------------------------------------------------------------------------------------
	/// Returns the corresponding Stream converter id.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Id GetCounterpart() const;

	//----------------------------------------------------------------------------------------
	/// Returns the source data type which is accepted by this stream converter.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const DataType& GetSourceType() const;

	//----------------------------------------------------------------------------------------
	/// Returns the destination data type which is accepted by this stream converter.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const DataType& GetDestinationType() const;

	//----------------------------------------------------------------------------------------
	/// Returns true if the StreamConversionRef supports in-place conversion which means that
	/// source and destination pointers might be identical.
	/// If true is returned it's possible to call ConvertAllInplace().
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool SupportInplaceConversion() const;

	//----------------------------------------------------------------------------------------
	/// Converts (part of) the source data in @p src to @p dst. The stream conversion need not
	/// consume all of @p src, therefore it returns the number of actually consumed elements.
	/// The unconsumed elements should be passed to the stream conversion in the next invocation
	/// of @c ConvertImpl.
	///
	/// <B style="color:#0000FF">Note:</B> A StreamConversionInterface can be used only once! If you want to convert multiple streams you have to allocate a StreamConversionInterface for each Convert call.
	///
	///
	/// If @p inputFinished is @c false, this indicates that the source data @p src is only a part of
	/// the whole data, so further data may be passed to the stream conversion by further invocations
	/// of @c ConvertImpl. If @p inputFinished is @c true, then @p src is the last part of the whole data.
	/// Even then further invocations of @c ConvertImpl might be necessary, for example if
	/// @p dstLimitHint hinders the stream conversion to write the complete output to @p dst.
	/// If the call returns true in @p outputFinished this means that no further calls must happen.
	/// Usually this happens only if @p inputFinished was set to true.
	///
	/// So to ensure that the stream conversion has finished, you have to set @p inputFinished to @c true
	/// and invoke @c ConsumeImpl as long as @p outputFinished returns with false.
	///
	/// Stream converters which request a GetBlockSize() > 1 needs the data for one block in one chunk.
	/// So if there is not enough data delivered the functions returns '0' to request more input bytes.
	/// The caller needs to ensure that more data comes within this block.
	/// The ConvertAll() function respects this already and copies the data into a temp array.
	///
	/// @param[in] src								Input data. The element size has to match the size of the source type.
	/// @param[out] dst								Array to append the converted data to. New data will be appended to the end,
	/// 															so previously existing array elements are kept. The element size has to match the size of the destination type.
	/// @param[in] dstLimitHint				A hint to the stream conversion about the maximum number of elements to add to @p dst in a single invocation of @c ConvertImpl.
	/// 															The stream conversion should not exceed this limit by a large amount if possible.
	/// @param[in] inputFinished			If @c true, the data in @p src is the last part of the whole input data.
	/// @param[out] outputFinished		If @c true, the data in @p dst was the last part of the conversion.
	/// @return												Number of elements which the stream conversion has consumed from @p src.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Int> ConvertImpl(const Block<const Generic>& src, WritableArrayInterface<Generic>& dst, Int dstLimitHint, Bool inputFinished, Bool& outputFinished);

	//----------------------------------------------------------------------------------------
	/// @copydoc ConvertImpl
	//----------------------------------------------------------------------------------------
	template <typename SRC, typename DST> MAXON_FUNCTION Result<Int> Convert(const SRC& src, DST& dst, Int dstLimitHint, Bool inputFinished, Bool& outputFinished)
	{
		DebugAssert(GetSourceType() && GetSourceType()->GetSize() == SIZEOF(typename SRC::ValueType));
		DebugAssert(GetDestinationType() && GetDestinationType()->GetSize() == SIZEOF(typename DST::ValueType));
		Block<const typename SRC::ValueType> block = src;
		return ConvertImpl(block, dst.ToArray(), dstLimitHint, inputFinished, outputFinished);
	}

	//----------------------------------------------------------------------------------------
	/// Converts the complete source data in @p src to @p dst. The conversion will
	/// consume all of @p src.
	///
	/// @param[in] src								Input data. The element size has to match the size of the source type.
	/// @param[out] dst								Array to append the converted data to. New data will be appended to the end,
	/// 															so previously existing array elements are kept. The element size has to match the size of the destination type.
	/// @param[in] dstLimitHint				A hint to the stream conversion about the maximum number of elements to add to @p dst in a single invocation of @c ConvertImpl.
	/// 															The stream conversion should not exceed this limit by a large amount if possible.
	/// @return												OK on success.
	///
	/// <B style="color:#0000FF">Note:</B> A StreamConversionInterface can be used only once! If you want to convert multiple streams you have to allocate a StreamConversionInterface for each Convert call.
	///
	//----------------------------------------------------------------------------------------
	template <typename SRC, typename DST> MAXON_FUNCTION Result<void> ConvertAll(const SRC& src, DST& dst, Int dstLimitHint = 1 << 16)
	{
		Int blockSize = GetBlockSize();

		if (src.GetCount() % blockSize != 0)
			return IllegalStateError(MAXON_SOURCE_LOCATION, FormatString("source size @ must be a multiple of @.", src.GetCount(), blockSize));

		Block<const typename SRC::ValueType, false> block;
		Bool outputFinished = false;

		for (Int i = 0; i < src.GetCount() && !outputFinished; )
		{
			Int pos = src.GetBlock(i, block);
			block = block.Slice(i - pos);

			Int n = 0;
			if (MAXON_LIKELY(block.GetCount() >= blockSize))
			{
				iferr (n = Convert(block, dst, dstLimitHint, i + block.GetCount() >= src.GetCount(), outputFinished))
					return err;
				i += n;
			}

			if (MAXON_UNLIKELY(n == 0))
			{
				// add special handling for GetBlockSize() > 1 where all data needs to be in one continous block
				// we collect at least one GetBlockSize() in the temp array. this is important on the edges of
				// BlockArray<> with encryption algorithms.
				BaseArray<typename std::remove_const<typename SRC::ValueType>::type> tempBuffer;
				Int tmpIdx = i;

				// try to build a slightly bigger buffer than the requested blocksize
				const Int blockMultiplier = 4;

				while (true)
				{
					// fill at least the requested blocksize
					while (block.GetCount() > 0)
					{
						iferr (tempBuffer.Insert(tempBuffer.GetCount(), block))
							return err;

						tmpIdx += block.GetCount();

						if (tempBuffer.GetCount() >= blockSize)
							break;

						pos = src.GetBlock(tmpIdx, block);
						block = block.Slice(tmpIdx - pos, Min(block.GetCount(), tmpIdx - pos + blockMultiplier * blockSize));
					}

					// try to convert the available bytes
					iferr (n = Convert(tempBuffer, dst, dstLimitHint, tmpIdx >= src.GetCount(), outputFinished))
						return err;

					// did something so try the regular way.
					if (n > 0 || outputFinished)
						break;

					// we need more input than the blockSize suggests.
					// try to copy the next block and try again ...
					pos = src.GetBlock(tmpIdx, block);
					block = block.Slice(tmpIdx - pos, Min(block.GetCount(), tmpIdx - pos + blockMultiplier * blockSize));
				}

				i += n;
			}
		}

		while (!outputFinished)
		{
			iferr (Convert(ToBlock<const typename SRC::ValueType>(nullptr, 0), dst, dstLimitHint, true, outputFinished))
				return err;
		}

		return OK;
	}

	//----------------------------------------------------------------------------------------
	/// Converts the complete source data in @p data and overwrites the data in @p data. The conversion will
	/// consume all of @p data.
	/// @param[in,out] data						Input/Output data. The element size has to match the size of the source type.
	/// @return												OK on success.
	///
	/// <B style="color:#0000FF">Note:</B> A StreamConversionInterface can be used only once! If you want to convert multiple streams you have to allocate a StreamConversionInterface for each Convert call.
	///
	//----------------------------------------------------------------------------------------
	template <typename SRC> MAXON_FUNCTION Result<void> ConvertAllInplace(const SRC& data)
	{
		if (!SupportInplaceConversion())
			return FunctionNotImplementedError(MAXON_SOURCE_LOCATION).DbgStop();

		Block<const typename SRC::ValueType> block = data;
		using valueType = typename std::remove_const<typename SRC::ValueType>::type;
		BaseArray<valueType, 16, BASEARRAYFLAGS::NONE, BlockBufferAllocator<NullAllocator>> dstArray(BlockBufferAllocator<NullAllocator>((valueType*)block.GetFirst(), block.GetCount()));
		return ConvertAll(block, dstArray);
	}

	MAXON_METHOD Result<InputStreamRef> ConvertToStream(const InputStreamRef& in);

	MAXON_METHOD Result<InputStreamRef> ConvertToStream(const DataFormatBaseReaderRef& in);

	MAXON_METHOD Result<DataFormatBaseReaderRef> ConvertToReader(const InputStreamRef& in);

	MAXON_METHOD Result<DataFormatBaseReaderRef> ConvertToReader(const DataFormatBaseReaderRef& in);


	MAXON_METHOD Result<OutputStreamRef> ConvertToStream(const OutputStreamRef& out);

	MAXON_METHOD Result<OutputStreamRef> ConvertToStream(const DataFormatBaseWriterRef& out);

	MAXON_METHOD Result<DataFormatBaseWriterRef> ConvertToWriter(const OutputStreamRef& out);

	MAXON_METHOD Result<DataFormatBaseWriterRef> ConvertToWriter(const DataFormatBaseWriterRef& out);

};

#include "streamconversion1.hxx"

using StreamConversionFactory = Factory<StreamConversionRef(const DataDictionary&)>;

MAXON_REGISTRY(StreamConversionFactory, StreamConversions, "net.maxon.registry.streamconversions");

//----------------------------------------------------------------------------------------
/// Factory<StreamConversionRef()> Flags.
/// Container to return a set of test settings for this compression algorithm. For all this keys the unittest will be executed.
//----------------------------------------------------------------------------------------
namespace STREAMCONVERSIONFACTORYFLAGS
{
	/// Returns true if the StreamConversionRef is an encoder.
	MAXON_ATTRIBUTE(Bool, ISENCODER, "net.maxon.streamconversion.isencoder");
	/// Returns true if the StreamConversionRef is a hash algorithm.
	MAXON_ATTRIBUTE(Bool, ISHASHALGORITHM, "net.maxon.streamconversion.ishashalgorithm");
}

struct ConversionTestSet
{
	Id							conversionId;
	DataDictionary	conversionSettings;

	ConversionTestSet()
	{
	}

	ConversionTestSet(const Id& id, const DataDictionary&	set) : conversionId(id), conversionSettings(set)
	{
	}

	String ToString(const FormatStatement* format) const
	{
		return FormatString("(@, @)", conversionId, conversionSettings);
	}

	MAXON_OPERATOR_EQUALITY_HASHCODE(ConversionTestSet, conversionId, conversionSettings);
};

MAXON_DATATYPE(ConversionTestSet, "net.maxon.datatype.conversiontestset");

//----------------------------------------------------------------------------------------
/// Debug function to deliver a set of test settings for a StreamConversionInterface.
/// Container to return a set of test settings for this compression algorithm. For all this keys the unittest will be executed.
//----------------------------------------------------------------------------------------
namespace STREAMCONVERSIONTEST
{
	/// Registered Stream Encoder Id. See StreamConversions.
	MAXON_ATTRIBUTE(SourceLocation, SOURCELOCATION, "net.maxon.streamconversiontest.sourcelocation");
	/// Registered Stream Encoder Id with settings. See StreamConversions.
	MAXON_ATTRIBUTE(Array<ConversionTestSet>, CONVERSIONTESTSET, "net.maxon.streamconversiontest.conversiontestset");
	/// Optional source data to compress. If this is not set random data will be used.
	/// put the original array into the container. settings.SetData(DataPtr(STREAMCONVERSIONTEST::SRCDATA.Get()), Data(std::move(array)));
	MAXON_ATTRIBUTE(Array<UChar>, SRCDATA, "net.maxon.streamconversiontest.srcdata");
	/// Optional data to compare the result. If this is not set random data will be used.
	/// put the original array into the container. settings.SetData(DataPtr(STREAMCONVERSIONTEST::COMPAREDATA.Get()), Data(std::move(array)));
	MAXON_ATTRIBUTE(Array<UChar>, COMPAREDATA, "net.maxon.streamconversiontest.comparedata");
	/// Optional compare data size of one element (can be 1 or 2).
	MAXON_ATTRIBUTE(Bool, FORBIDSOURCEDUPLICATION, "net.maxon.streamconversiontest.forbidsourceduplication");
}

//----------------------------------------------------------------------------------------
/// DataDictionary used STREAMCONVERSIONTEST to for the tests.
//----------------------------------------------------------------------------------------
MAXON_REGISTRY(Factory<BaseArray<DataDictionary>()>, StreamConversionTests, "net.maxon.registry.streamconversiontests");

//----------------------------------------------------------------------------------------
/// Helper function to add crypto tests.
//----------------------------------------------------------------------------------------
Result<void> AddConversionTestSetting(MAXON_SOURCE_LOCATION_DECLARATION, BaseArray<DataDictionary>& resultArray, const Block<const ConversionTestSet>& set, const Block<const Char>& srcData, const Block<const Char>& compareData = Block<const Char>(), Bool forbidLargeTest = false);
Result<void> AddConversionTestSetting(MAXON_SOURCE_LOCATION_DECLARATION, BaseArray<DataDictionary>& resultArray, const Block<const ConversionTestSet>& set, const Block<const Utf32Char>& srcData, const Block<const Char>& compareData = Block<const Char>(), Bool forbidLargeTest = false);
Result<void> AddConversionTestSetting(MAXON_SOURCE_LOCATION_DECLARATION, BaseArray<DataDictionary>& resultArray, const Block<const ConversionTestSet>& set, const Block<const Char>& srcData, const Block<const Utf32Char>& compareData = Block<const Utf32Char>(), Bool forbidLargeTest = false);
Result<void> AddConversionTestSetting(MAXON_SOURCE_LOCATION_DECLARATION, BaseArray<DataDictionary>& resultArray, const Block<const ConversionTestSet>& set, const Block<const Utf32Char>& srcData, const Block<const Utf32Char>& compareData = Block<const Utf32Char>(), Bool forbidLargeTest = false);

template <typename TO, typename FROM> inline Factory<TO(const DataDictionary&)>& ConvertStreamConversionRef(FROM& obj)
{
	return reinterpret_cast<Factory<TO(const DataDictionary&)>&>(obj);
}

//----------------------------------------------------------------------------------------
/// Options for "base64" compression
//----------------------------------------------------------------------------------------
namespace BASE64_OPTIONS
{
	/// Maximum number of characters per line.
	MAXON_ATTRIBUTE(Int, MAXMIMELINELENGTH, "net.maxon.streamconversion.base64.maxmimelinelength");

	/// Add newline characters to the encoded string when the BASE64_OPTIONS::MAXMIMELINELENGTH is reached.
	MAXON_ATTRIBUTE(Bool, ADD_NEWLINE, "net.maxon.streamconversion.base64.add_newline");

	/// If true this disables the padding with '=' characters 
	MAXON_ATTRIBUTE(Bool, DISABLE_PADDING, "net.maxon.streamconversion.base64.disable_padding");
}

namespace StreamConversions
{
	/// DATACOMPRESSIONTYPE_BASE64: Base64 encoding/decoding (see BASE64_OPTIONS for options). Use Compress() to Encode, Uncompress() to decode.<br>
	MAXON_DECLARATION(StreamConversionFactory, Base64Encoder, "net.maxon.streamconversion.base64.encoder");
	MAXON_DECLARATION(StreamConversionFactory, Base64Decoder, "net.maxon.streamconversion.base64.decoder");
	MAXON_DECLARATION(StreamConversionFactory, Base64UrlEncoder, "net.maxon.streamconversion.base64url.encoder");
	MAXON_DECLARATION(StreamConversionFactory, Base64UrlDecoder, "net.maxon.streamconversion.base64url.decoder");
}

//----------------------------------------------------------------------------------------
/// Options for UTF text encoder
//----------------------------------------------------------------------------------------
namespace UTFTEXT_OPTIONS
{
	enum class TEXTENCODING
	{
		NONE									= 0, ///< No encoding takes place. The values are just extended or truncated.
		UTF8									= 1, ///< UTF-8 encoding.
		UTF16_BIGENDIAN				= 2, ///< UTF-16 encoding, Big Endian format.
		UTF16_LITTLEENDIAN		= 3, ///< UTF-16 encoding, Little Endian format.
		UTF32_BIGENDIAN				= 4, ///< UTF-32 encoding, Big Endian format.
		UTF32_LITTLEENDIAN		= 5  ///< UTF-32 encoding, Little Endian format.
	} MAXON_ENUM_LIST(TEXTENCODING);

	/// Encoding that will be used for the UTF text encoder.
	MAXON_ATTRIBUTE(TEXTENCODING, ENCODING, "net.maxon.streamconversion.utftext.encoding");

	/// Encoding that will be used for the UTF text decoder if no Byte Order Mark (BOM) is detected. Default is TEXTENCODING::UTF8.
	MAXON_ATTRIBUTE(TEXTENCODING, DEFAULT_DECODING, "net.maxon.streamconversion.utftext.default_decoding");

	/// suppresses writing the utf8 header
	MAXON_ATTRIBUTE(Bool, DONTWRITEHEADER, "net.maxon.streamconversion.utftext.dontwriteheader");
}

namespace StreamConversions
{
	/// UTF files encoding/decoding, based on Byte Order Mark (BOM)<br>
	MAXON_DECLARATION(StreamConversionFactory, UtfTextEncoder, "net.maxon.streamconversion.utftext.encoder");
	MAXON_DECLARATION(StreamConversionFactory, UtfTextDecoder, "net.maxon.streamconversion.utftext.decoder");

	/// BINARYTOHEX: Hex encoding/decoding. Use Compress() to Encode, Uncompress() to decode.<br>
	MAXON_DECLARATION(StreamConversionFactory, HexEncoder, "net.maxon.streamconversion.hex.encoder");
	MAXON_DECLARATION(StreamConversionFactory, HexDecoder, "net.maxon.streamconversion.hex.decoder");
}

MAXON_DECLARATION(Class<StreamConversionRef>, StreamConversionBaseClass, "net.maxon.class.streamconversionbase");


#include "streamconversion2.hxx"


}

#endif // STREAMCONVERSION_H__

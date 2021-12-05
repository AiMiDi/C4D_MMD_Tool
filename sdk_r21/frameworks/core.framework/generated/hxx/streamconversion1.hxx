#if 1
class StreamConversionRef;

struct StreamConversionInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, StreamConversionInterface>::value || DataDictionaryObjectInterface::HasBase::template Check<I>::value; static I* Cast(StreamConversionInterface* ptr) { return static_cast<I*>(static_cast<maxon::ObjectInterface*>(ptr)); } }; };
struct StreamConversionInterface::Hxx1
{
	class Reference;
	using ReferenceClass = StreamConversionRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<DataDictionaryObjectInterface>;
	/// Intermediate helper class for StreamConversionInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
/// Returns the recommended working size.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type GetBatchSize() const;
/// Returns the block size in of the encoder/decoder.
/// The encoded/decoded data needs to be a multiple of GetBlockSize().
/// This number is the count of elements of GetSourceType(), not the size in bytes!
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type GetBlockSize() const;
/// Returns the corresponding Stream converter id.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Id>, Id>::type GetCounterpart() const;
/// Returns the source data type which is accepted by this stream converter.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<const DataType&>, const DataType&>::type GetSourceType() const;
/// Returns the destination data type which is accepted by this stream converter.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<const DataType&>, const DataType&>::type GetDestinationType() const;
/// Returns true if the StreamConversionRef supports in-place conversion which means that
/// source and destination pointers might be identical.
/// If true is returned it's possible to call ConvertAllInplace().
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type SupportInplaceConversion() const;
	};
	/// Intermediate helper class for StreamConversionInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, StreamConversionRef, true>::type&() const { return reinterpret_cast<const StreamConversionRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, StreamConversionRef, false>::type&() { return reinterpret_cast<const StreamConversionRef&>(this->GetBaseRef()); }
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
		inline Result<Int> ConvertImpl(const Block<const Generic>& src, WritableArrayInterface<Generic>& dst, Int dstLimitHint, Bool inputFinished, Bool& outputFinished) const;
/// @copydoc ConvertImpl
		template <typename SRC, typename DST> inline Result<Int> Convert(const SRC& src, DST& dst, Int dstLimitHint, Bool inputFinished, Bool& outputFinished) const;
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
		template <typename SRC, typename DST> inline Result<void> ConvertAll(const SRC& src, DST& dst, Int dstLimitHint = 1<<16) const;
/// Converts the complete source data in @p data and overwrites the data in @p data. The conversion will
/// consume all of @p data.
/// @param[in,out] data						Input/Output data. The element size has to match the size of the source type.
/// @return												OK on success.
///
/// <B style="color:#0000FF">Note:</B> A StreamConversionInterface can be used only once! If you want to convert multiple streams you have to allocate a StreamConversionInterface for each Convert call.
///
		template <typename SRC> inline Result<void> ConvertAllInplace(const SRC& data) const;
		inline Result<InputStreamRef> ConvertToStream(const InputStreamRef& in) const;
		inline Result<InputStreamRef> ConvertToStream(const DataFormatBaseReaderRef& in) const;
		inline Result<DataFormatBaseReaderRef> ConvertToReader(const InputStreamRef& in) const;
		inline Result<DataFormatBaseReaderRef> ConvertToReader(const DataFormatBaseReaderRef& in) const;
		inline Result<OutputStreamRef> ConvertToStream(const OutputStreamRef& out) const;
		inline Result<OutputStreamRef> ConvertToStream(const DataFormatBaseWriterRef& out) const;
		inline Result<DataFormatBaseWriterRef> ConvertToWriter(const OutputStreamRef& out) const;
		inline Result<DataFormatBaseWriterRef> ConvertToWriter(const DataFormatBaseWriterRef& out) const;
	};
	/// Intermediate helper class for StreamConversionInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, StreamConversionRef, false>::type&() { return reinterpret_cast<const StreamConversionRef&>(this->GetBaseRef()); }
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
		inline Result<Int> ConvertImpl(const Block<const Generic>& src, WritableArrayInterface<Generic>& dst, Int dstLimitHint, Bool inputFinished, Bool& outputFinished);
/// @copydoc ConvertImpl
		template <typename SRC, typename DST> inline Result<Int> Convert(const SRC& src, DST& dst, Int dstLimitHint, Bool inputFinished, Bool& outputFinished);
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
		template <typename SRC, typename DST> inline Result<void> ConvertAll(const SRC& src, DST& dst, Int dstLimitHint = 1<<16);
/// Converts the complete source data in @p data and overwrites the data in @p data. The conversion will
/// consume all of @p data.
/// @param[in,out] data						Input/Output data. The element size has to match the size of the source type.
/// @return												OK on success.
///
/// <B style="color:#0000FF">Note:</B> A StreamConversionInterface can be used only once! If you want to convert multiple streams you have to allocate a StreamConversionInterface for each Convert call.
///
		template <typename SRC> inline Result<void> ConvertAllInplace(const SRC& data);
		inline Result<InputStreamRef> ConvertToStream(const InputStreamRef& in);
		inline Result<InputStreamRef> ConvertToStream(const DataFormatBaseReaderRef& in);
		inline Result<DataFormatBaseReaderRef> ConvertToReader(const InputStreamRef& in);
		inline Result<DataFormatBaseReaderRef> ConvertToReader(const DataFormatBaseReaderRef& in);
		inline Result<OutputStreamRef> ConvertToStream(const OutputStreamRef& out);
		inline Result<OutputStreamRef> ConvertToStream(const DataFormatBaseWriterRef& out);
		inline Result<DataFormatBaseWriterRef> ConvertToWriter(const OutputStreamRef& out);
		inline Result<DataFormatBaseWriterRef> ConvertToWriter(const DataFormatBaseWriterRef& out);
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename DataDictionaryObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename DataDictionaryObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename DataDictionaryObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type> { };
};
class StreamConversionInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<StreamConversionRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<StreamConversionInterface, maxon::StrongRefHandler, StreamConversionRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<StreamConversionInterface, maxon::StrongRefHandler, StreamConversionRef>>>>);
	using NonConst = typename Super::ReferenceClass;
};

/// StreamConversionRef is the reference class of StreamConversionInterface.
///
/// StreamConversionInterface is a universal interface to convert data.
/// It can be used for Encryption, Compression, Encoding, Hashing, basically everything that streams data in and out.
class StreamConversionRef : public StreamConversionInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(StreamConversionRef, typename StreamConversionInterface::Hxx1::Reference);
};

namespace STREAMCONVERSIONFACTORYFLAGS
{
#ifndef PRIVATE_MAXON_GUARD_maxon_STREAMCONVERSIONFACTORYFLAGS
#define PRIVATE_MAXON_GUARD_maxon_STREAMCONVERSIONFACTORYFLAGS
	class RESTRICT : public maxon::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
#endif
}
namespace STREAMCONVERSIONTEST
{
#ifndef PRIVATE_MAXON_GUARD_maxon_STREAMCONVERSIONTEST
#define PRIVATE_MAXON_GUARD_maxon_STREAMCONVERSIONTEST
	class RESTRICT : public maxon::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
#endif
}
namespace BASE64_OPTIONS
{
#ifndef PRIVATE_MAXON_GUARD_maxon_BASE64_OPTIONS
#define PRIVATE_MAXON_GUARD_maxon_BASE64_OPTIONS
	class RESTRICT : public maxon::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
#endif
}
namespace UTFTEXT_OPTIONS
{
#ifndef PRIVATE_MAXON_GUARD_maxon_UTFTEXT_OPTIONS
#define PRIVATE_MAXON_GUARD_maxon_UTFTEXT_OPTIONS
	class RESTRICT : public maxon::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
#endif
}
#endif

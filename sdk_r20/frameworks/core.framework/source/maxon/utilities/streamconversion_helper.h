#ifndef STREAMCONVERSION_HELPER_H__
#define STREAMCONVERSION_HELPER_H__

#include "maxon/thread.h"
#include "maxon/conditionvariable.h"
#include "maxon/streamconversion_impl_helper.h"

namespace maxon
{

template <typename SRCTYPE, typename DSTTYPE> class StreamConversionHelper;
template <typename SRCTYPE, typename DSTTYPE> class CollectorThread;

//----------------------------------------------------------------------------------------
/// This class implements a helper function for sequential access when using stream conversions
/// Usually with stream conversions you get an arbitrary number of bytes within the ConvertImpl callback.
/// This means you cannot longer read data in a classic linear fashion since you might not get enough bytes to finish your reading.
///
/// For example something simple like @code ReadBytes(buf, 4) @endcode is not possible whithout checking for the remaning bytes left.
/// In case of insufficient number of available bytes you have to store your current variable heap and continue reading in subsequent calls of ConvertImpl.
///
/// While this might be possible for simple algorithms it can get quite complex or even imposible when trying to read more elaborate
/// data files which are for example arranged in hierarchies with chunks or subchunks. Or think about using an external complex library
/// for accessing a data format like Alembic or TIFF. In this case you can not change the code structure - only replacing a ReadBytes access
/// is possible.
///
/// StreamConversionHelper frees you from dealing with stream bytes deliverd in arbitrary chunks.
/// First you simply overlad StreamConversionHelper template by specifying your source and dest datatype (here both Char) and fill the DoIt routine with your normal code e.g. reading the file (in this example decompressing a LZ4 stream)
/// @code
/// class Lz4StreamConversionHelper : public StreamConversionHelper<Char, Char>
/// {
/// public:
/// 	virtual Result<void> DoIt()
/// 	{
/// 		// ... read your data here
/// 		Lz4Decompress();
/// 	}
/// };
/// @endcode
///
/// In this example if you want to read 4 bytes (aka Chars) within the DoIt routine you simply write
/// @code
/// Char buf[4];
///	Read(buf, 4) iferr_return;
/// @endcode
///
/// Second you put the helper object somewhere on the stack - ideally as a static variable in your main StreamConversion class
/// and initialize it everytime ConvertImpl is called by simply calling AppendStream - boom you are done.
/// @code
/// class Lz4BaseImpl : public Component<Lz4BaseImpl, StreamConversionInterface>
/// {
/// 	MAXON_COMPONENT();
///
/// public:
/// 	Result<Int> ConvertImpl(const Block<const Generic>& xsrc, WritableArrayInterface<Generic>& xdst, Int dstLimitHint, Bool inputFinished, Bool& outputFinished)
/// 	{
/// 		iferr_scope;
///
/// 		const Block<const Char>&      src = reinterpret_cast<const Block<const Char>&>     (xsrc);
/// 		WritableArrayInterface<Char>& dst = reinterpret_cast<WritableArrayInterface<Char>&>(xdst);
///
/// 		helper.AppendStream(src, dst, inputFinished) iferr_return;
///
/// 		if (inputFinished)
/// 			outputFinished = true;
///
/// 		return helper.GetCurrentPosition();
/// 	}
///
/// protected:
/// 	Lz4StreamConversionHelper helper;
/// };
/// @endcode
//-------------------------------------------------------------------------------------------------

template <typename SRCTYPE, typename DSTTYPE> class StreamConversionHelper
{
public:
	//----------------------------------------------------------------------------------------
	/// Adds a new part of the stream to the existing one. Has to be called each time ConvertImpl is executed
	/// @param[in] src								input stream
	/// @param[in] dst								output stream
	/// @param[in] inputFinished			signal from ConvertImpl if this is the last part of the stream
	///
	/// Example: You put the helper object somewhere on the stack - ideally as a static variable in your main StreamConversion class
	/// and initialize it everytime ConvertImpl is called by simply calling AppendStream. Here a LZ4 stream of Chars as input is decoded.
	/// @code
	/// class Lz4BaseImpl : public Component<Lz4BaseImpl, StreamConversionInterface>
	/// {
	/// 	MAXON_COMPONENT();
	///
	/// public:
	/// 	Result<Int> ConvertImpl(const Block<const Generic>& xsrc, WritableArrayInterface<Generic>& xdst, Int dstLimitHint, Bool inputFinished, Bool& outputFinished)
	/// 	{
	/// 		iferr_scope;
	///
	/// 		const Block<const Char>&      src = reinterpret_cast<const Block<const Char>&>     (xsrc);
	/// 		WritableArrayInterface<Char>& dst = reinterpret_cast<WritableArrayInterface<Char>&>(xdst);
	///
	/// 		helper.AppendStream(src, dst, inputFinished) iferr_return;
	///
	/// 		if (inputFinished)
	/// 			outputFinished = true;
	///
	/// 		return helper.GetCurrentPosition();
	/// 	}
	///
	/// protected:
	/// 	Lz4StreamConversionHelper helper;
	/// };
	/// @endcode
	//----------------------------------------------------------------------------------------
	Result<void> AppendStream(const Block<const SRCTYPE>& src, WritableArrayInterface<DSTTYPE>& dst, Bool inputFinished);

	//----------------------------------------------------------------------------------------
	/// Append elements to the internal destination dst buffer specified in AppendStream.
	/// @param[in] buf								source buffer
	/// @param[in] count							number of elements to be copied from buf to dst
	//----------------------------------------------------------------------------------------
	Result<void> Write(DSTTYPE* buf, Int count);

	//----------------------------------------------------------------------------------------
	/// Simply copy elements to the internal destination dst buffer specified in AppendStream.
	/// This function is especially useful for speeding things up when the final size oft dst ist know.
	/// Instead of enlarging dst with each Write call this i just a plain Memcopy
	/// Note: you to have to garantue that the dest buffer is sufficiently large enough
	/// @param[in] buf								source buffer
	/// @param[in] count							number of elements to be copied from buf to dst
	/// @param[in] offset							number of elements to be copied from buf to dst
	//----------------------------------------------------------------------------------------
	Result<void> WriteWithOffset(DSTTYPE* buf, Int count, Int offset);

	//----------------------------------------------------------------------------------------
	/// Read elements from internal src buffer specified in AppendStream to buf.
	/// @param[in] buf								destination buffer
	/// @param[in] count							number of elements to be copied from src to buf
	//----------------------------------------------------------------------------------------
	Result<void> Read(SRCTYPE* buf, Int count);

	//----------------------------------------------------------------------------------------
	/// Read elements from internal src buffer specified in AppendStream to buf. Contrary to Read this routine does not read a specific
	/// number of elements but reads untile either the end of the stream is reached of the maxCount number.
	/// @param[in] buf								destination buffer
	/// @param[in] maxCount						max number of elements to be read
	/// @return												number of elements actually read
	//----------------------------------------------------------------------------------------
	Result<Int> ReadEOS(SRCTYPE* buf, Int maxCount);

	//----------------------------------------------------------------------------------------
	/// Skip elements
	/// @param[in] count							number of elements
	//----------------------------------------------------------------------------------------
	Result<void> Skip(Int count);

	//----------------------------------------------------------------------------------------
	/// Current reading position. Note that this is a relative position to the part of the stream that was initialized with AppendStream.
	/// @return												Current reading position
	//----------------------------------------------------------------------------------------
	MAXON_WARN_UNUSED Int GetCurrentPosition();

	//----------------------------------------------------------------------------------------
	/// Direct access to the destination array
	/// @return												pointer to destination array
	//----------------------------------------------------------------------------------------
	MAXON_WARN_UNUSED WritableArrayInterface<DSTTYPE>* GetDst();

	//----------------------------------------------------------------------------------------
	/// Check for end of stream condition.
	/// @return												True if end is reached.
	//----------------------------------------------------------------------------------------
	MAXON_WARN_UNUSED Bool  EndOfStreamReached();


protected:
	//----------------------------------------------------------------------------------------
	/// you have to overload this function
	/// here you fill in your code to process the data of the stream
	//----------------------------------------------------------------------------------------
	virtual Result<void> DoIt() = 0;

	virtual ~StreamConversionHelper()
	{
	}

private:
	template <typename SRCTYPE2, typename DSTTYPE2> friend class CollectorThread;
	ThreadRef						 _thread;

	ConditionVariableRef _inputAvailable  = ConditionVariableRef::Create(true) iferr_ignore("nullptr is OK");
	ConditionVariableRef _outputAvailable = ConditionVariableRef::Create(true) iferr_ignore("nullptr is OK");
	Error                _returnErrorVar; //  = nullptr; does no work due to linux compiler, but not ultimately necessary
	Bool                 _DoItDone        = false;

	// temp stream data
	const Block<const SRCTYPE>*      _src     = nullptr;
	WritableArrayInterface<DSTTYPE>* _dst     = nullptr;
	Int                        _seg_pos       = 0;
	Int                        _seg_count     = 0;
	Bool                       _inputFinished = false;

	Result<void> SignalEmitterThreadToContinue();
	Result<void> SignalCollectorThreadToContinue();
};


//----------------------------------------------------------------------------------------
// implementation
//----------------------------------------------------------------------------------------

// #define DEBUGOUTPUT
static MAXON_ATTRIBUTE_FORCE_INLINE void DebugPrint(const String& str)
{
	#ifdef DEBUGOUTPUT
		DiagnosticOutput(str);
	#endif
}

template <typename SRCTYPE, typename DSTTYPE> class CollectorThread  : public ThreadInterfaceTemplate<CollectorThread<SRCTYPE, DSTTYPE>>
{
public:
	explicit CollectorThread(StreamConversionHelper<SRCTYPE, DSTTYPE>& emitter) : _emitter(emitter)
	{
	}

	const char* GetName()	const { return "collector thread"; }

	Result<void> operator ()()
	{
		_emitter._inputAvailable.Wait(TIMEVALUE_INFINITE, WAITMODE::RETURN_ON_CANCEL);

		DebugPrint("2:\t\tWorking started"_s);

		// ... your code goes here ...
		iferr (_emitter.DoIt())
		{
			_emitter._returnErrorVar = err;
			_emitter._outputAvailable.Set(); // signal to main thread to continue
			return err;
		}

		DebugPrint("2:\t\tWorking ended"_s);

		_emitter._outputAvailable.Set(); // signal to main thread to continue
		DebugPrint("2:\t\t\toutput set"_s);

		_emitter._DoItDone = true;

		return OK;
	}

private:
	StreamConversionHelper<SRCTYPE, DSTTYPE>& _emitter;

};

template <typename SRCTYPE, typename DSTTYPE> MAXON_ATTRIBUTE_FORCE_INLINE Result<void> StreamConversionHelper<SRCTYPE, DSTTYPE>::AppendStream(const Block<const SRCTYPE>& src, WritableArrayInterface<DSTTYPE>& dst, Bool inputFinished)
{
	if (_DoItDone)
		return OK;

	iferr_scope;

	DebugPrint("1:\tStart AppendStream"_s);

	_src            = &reinterpret_cast<const Block<const SRCTYPE>&>(src);
	_dst            = &dst;
	_inputFinished  = inputFinished;
	_seg_pos        = 0;
	_seg_count      = _src->GetCount();
	_returnErrorVar = nullptr;

	if (!_thread)
	{
		using MyAllocType = CollectorThread<SRCTYPE, DSTTYPE>;
		_thread = NewObj(MyAllocType, *this) iferr_return;

		iferr (_thread.Start())
		{
			DiagnosticOutput("1:\\ttError: Could not start collector thread: @", err);
			return IllegalStateError(MAXON_SOURCE_LOCATION, "Could not start collector thread"_s);
		}
		DebugPrint("\n-----------------------------------------------"_s);
		DebugPrint("1:\tCollector thread started"_s);
	}



	SignalCollectorThreadToContinue() iferr_return;


	if (_returnErrorVar != Error(OK))
	{
		DebugPrint(_returnErrorVar.GetMessage());

		return _returnErrorVar;
	}

	DebugPrint("1:\tEnd AppendStream"_s);

	return OK;
}

template <typename SRCTYPE, typename DSTTYPE> MAXON_ATTRIBUTE_FORCE_INLINE Result<void> StreamConversionHelper<SRCTYPE, DSTTYPE>::Write(DSTTYPE* buf, Int count)
{
	if (_DoItDone)
		return OK;

	return _dst->Insert(_dst->GetCount(), ToBlock(buf, count));
}

template <typename SRCTYPE, typename DSTTYPE> MAXON_ATTRIBUTE_FORCE_INLINE Result<void> StreamConversionHelper<SRCTYPE, DSTTYPE>::WriteWithOffset(DSTTYPE* buf, Int count, Int offset)
{
	if (_DoItDone)
		return OK;

	if (MAXON_UNLIKELY(offset + count > _dst->GetCount()))
		return IllegalStateError(MAXON_SOURCE_LOCATION, "destination buffer too small"_s);

	Block<Char, false> block;
	Int copiedBytes = 0;
	while (copiedBytes < count)
	{
		Int blockOffset = _dst->GetBlock(offset + copiedBytes, block);

		Int bytesToCopy = block.GetCount();
		if (copiedBytes + bytesToCopy > count) // clipping at count border
			bytesToCopy = count - copiedBytes;

		DebugAssert(bytesToCopy);
		MemCopy(block.GetFirst() + offset + copiedBytes - blockOffset, buf + copiedBytes, bytesToCopy);

		copiedBytes += bytesToCopy;
	}

	return OK;
}

template <typename SRCTYPE, typename DSTTYPE> MAXON_ATTRIBUTE_FORCE_INLINE Result<void> StreamConversionHelper<SRCTYPE, DSTTYPE>::Read(SRCTYPE* buf, Int count)
{
	if (_DoItDone)
		return OK;

	iferr_scope;

	Int readCount = 0;

	DebugPrint(FormatString("2:\t\tReadBytes with @ bytes started", count));

	while (readCount < count)
	{
		// first of read all available bytes
		Int toRead = Min(Min(count, _seg_count - _seg_pos), count - readCount);
		MemCopyType(buf + readCount, _src->GetFirst() + _seg_pos, toRead);
		_seg_pos  += toRead;
		readCount += toRead;

		if (readCount == count) // we have fully read all bytes
		{
			DebugPrint(FormatString("2:\t\tReadBytes ended (all @ bytes read)", count));

			return OK;
		}

		// check for unexpected end of stream
		if (_inputFinished)
		{
			_returnErrorVar = IllegalStateError(MAXON_SOURCE_LOCATION, FormatString("Another @ bytes expected but stream too short", count - readCount));
			_outputAvailable.Set(); // signal to emitter thread to continue
			DebugPrint("2:\t\t\toutput set"_s);

			return _returnErrorVar;
		}

		DebugPrint("2:\t\tReadBytes: Wait for more Bytes"_s);

		// not enough bytes read, wait for more bytes
		SignalEmitterThreadToContinue() iferr_return;

		DebugPrint("2:\t\tReadBytes: Resumed reading"_s);

	}

	DebugStop("Should never reach this point");

	return OK;
}


template <typename SRCTYPE, typename DSTTYPE> MAXON_ATTRIBUTE_FORCE_INLINE Result<Int> StreamConversionHelper<SRCTYPE, DSTTYPE>::ReadEOS(SRCTYPE* buf, Int maxCount)
{
	if (_DoItDone)
		return 0;

	iferr_scope;

	Int readCount = 0;

	DebugPrint("2:\t\tReadBytesEOS started"_s);

	while (readCount < maxCount)
	{
		// first of read all available bytes
		Int toRead = Min(Min(maxCount, _seg_count - _seg_pos), maxCount - readCount);
		MemCopyType(buf + readCount, _src->GetFirst() + _seg_pos, toRead);
		_seg_pos  += toRead;
		readCount += toRead;

		if (readCount >= maxCount) // we have fully read all bytes
		{
			DebugPrint(FormatString("2:\t\tReadBytesEOS ended (all available @ bytes read)", readCount));

			return readCount;
		}

		if ((_seg_count - _seg_pos <= 0) && _inputFinished) // end of stream reached
		{
			DebugPrint(FormatString("2:\t\tReadBytesEOS ended (end of stream reached, @ bytes read)", readCount));

			return readCount;
		}

		// check for unexpected end of stream
		if (_inputFinished)
		{
			_returnErrorVar = IllegalStateError(MAXON_SOURCE_LOCATION, FormatString("Another @ bytes expected but stream too short", maxCount - readCount));
			_outputAvailable.Set(); // signal to emitter thread to continue
			DebugPrint("2:\t\t\toutput set"_s);

			return _returnErrorVar;
		}

		DebugPrint("2:\t\tReadBytes: Wait for more Bytes"_s);

		// not enough bytes read, wait for more bytes
		SignalEmitterThreadToContinue() iferr_return;

		DebugPrint("2:\t\tReadBytes: Resumed reading"_s);

	}

	DebugStop("Should never reach this point");

	return 0;
}


template <typename SRCTYPE, typename DSTTYPE> MAXON_ATTRIBUTE_FORCE_INLINE Result<void> StreamConversionHelper<SRCTYPE, DSTTYPE>::Skip(Int count)
{
	if (_DoItDone)
		return OK;

	iferr_scope;

	SRCTYPE dum;

	for (Int i = 0; i < count; i++)
	{
		Read(&dum, 1) iferr_return;
	}

	return OK;
}

template <typename SRCTYPE, typename DSTTYPE> MAXON_ATTRIBUTE_FORCE_INLINE Int StreamConversionHelper<SRCTYPE, DSTTYPE>::GetCurrentPosition()
{
	return _seg_pos;
}


template <typename SRCTYPE, typename DSTTYPE> MAXON_ATTRIBUTE_FORCE_INLINE Bool StreamConversionHelper<SRCTYPE, DSTTYPE>::EndOfStreamReached()
{
	return _seg_pos >= _seg_count && _inputFinished;
}


template <typename SRCTYPE, typename DSTTYPE> MAXON_ATTRIBUTE_FORCE_INLINE Result<void> StreamConversionHelper<SRCTYPE, DSTTYPE>::SignalEmitterThreadToContinue()
{
	if (_DoItDone)
		return OK;

	DebugPrint("1:\tStart Emitter & wait"_s);

	_outputAvailable.Set(); // signal to emitter thread to continue

	if (!_inputAvailable.Wait(TIMEVALUE_INFINITE, WAITMODE::RETURN_ON_CANCEL)) // lets wait for more bytes
		return ThreadCancelledError(MAXON_SOURCE_LOCATION);

	DebugPrint("1:\tEnd Emitter"_s);

	return OK;
}

template <typename SRCTYPE, typename DSTTYPE> MAXON_ATTRIBUTE_FORCE_INLINE Result<void> StreamConversionHelper<SRCTYPE, DSTTYPE>::SignalCollectorThreadToContinue()
{
	if (_DoItDone)
		return OK;

	DebugPrint("1:\tStart Collector & wait"_s);

	_inputAvailable.Set(); // hello I have new bytes for you, signal to collector thread to continue

	if (!_outputAvailable.Wait(TIMEVALUE_INFINITE, WAITMODE::RETURN_ON_CANCEL)) // wait until collector thread signals that he is done with reading
		return ThreadCancelledError(MAXON_SOURCE_LOCATION);

	DebugPrint("1:\tEnd Collector"_s);

	return OK;
}

template <typename SRCTYPE, typename DSTTYPE> MAXON_WARN_UNUSED WritableArrayInterface<DSTTYPE>* StreamConversionHelper<SRCTYPE, DSTTYPE>::GetDst()
{
	return _dst;
}




} // namespace maxon

#endif // STREAMCONVERSION_HELPER_H__

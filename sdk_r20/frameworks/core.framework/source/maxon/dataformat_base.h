#ifndef DATAFORMAT_BASE_H__
#define DATAFORMAT_BASE_H__


#include "maxon/datadictionaryobject.h"
#include "maxon/iostreams.h"


namespace maxon
{

//----------------------------------------------------------------------------------------
/// Parameters for DataFormatBaseInterface::SetData(), UrlInterface::GetData().
//----------------------------------------------------------------------------------------
namespace DATAFORMATBASEIDS
{
	MAXON_ATTRIBUTE(BaseStreamRef, STREAM, "net.maxon.dataformat.basestream");		///< Stream that is used.
}


//----------------------------------------------------------------------------------------
/// This class serializes data from IoStreams.
/// It defines a file format for each data type.
//----------------------------------------------------------------------------------------
class DataFormatBaseReaderInterface : MAXON_INTERFACE_BASES(DataDictionaryObjectInterface)
{
	MAXON_INTERFACE(DataFormatBaseReaderInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.dataformatbasereader");

public:
	//----------------------------------------------------------------------------------------
	/// Close the stream and the stream handle.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> CloseInput();

	MAXON_ADD_TO_REFERENCE_CLASS(
	//----------------------------------------------------------------------------------------
	/// Resets this reference to nullptr and closes the stream if this is the last reference to the stream.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	Result<void> ResetMaybeCloseInput()
	{
		Result<void> res = OK;
		if (this->GetPointer())
		{
			if (System::GetReferenceCounter(this->GetPointer()) == 1)
				res = this->GetPointer()->CloseInput();
			this->ResetPointer();
		}
		return res;
	}
	);

	//----------------------------------------------------------------------------------------
	/// Reads data from the stream and keeps the right byte order.
	/// E.g. if a Int64 is written into the stream on a little endian system it will be flipped when reading into a big endian system.
	/// @param[in] data								Pointer to a memory address with the data.
	/// @param[in] dataSize						Size of the data to write. Possible sizes are 1 (without byte order changes) or 2, 4, 8 (with byte order correction).
	/// @param[in] elementCount				Number of data elements.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION Result<void> ReadData(void* data, Int dataSize, Int elementCount);

	//----------------------------------------------------------------------------------------
	/// Reads data from the stream and keeps the right byte order.
	/// E.g. if a Int64 is written into the stream on a little endian system it will be flipped when reading into a big endian system.
	/// @param[in] data								Pointer to a memory address with the data.
	/// @param[in] dataSize						Size of the data to write. Possible sizes are 1 (without byte order changes) or 2, 4, 8 (with byte order correction).
	/// @param[in] elementCount				Number of data elements.
	/// @return												Returns the number of elements (not bytes) that have been read.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Int> ReadDataEOS(void* data, Int dataSize, Int elementCount);
};



//----------------------------------------------------------------------------------------
/// This class serializes data into IoStreams.
/// It defines a file format for each data type.
///
//----------------------------------------------------------------------------------------
class DataFormatBaseWriterInterface : MAXON_INTERFACE_BASES(DataDictionaryObjectInterface)
{
	MAXON_INTERFACE(DataFormatBaseWriterInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.dataformatbasewriter");

public:
	//----------------------------------------------------------------------------------------
	/// Close the stream and the stream handle.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> CloseOutput();

	MAXON_ADD_TO_REFERENCE_CLASS(
	//----------------------------------------------------------------------------------------
	/// Resets this reference to nullptr and closes the stream if this is the last reference to the stream.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	Result<void> ResetMaybeCloseOutput()
	{
		Result<void> res = OK;
		if (this->GetPointer())
		{
			if (System::GetReferenceCounter(this->GetPointer()) == 1)
				res = this->GetPointer()->CloseOutput();
			this->ResetPointer();
		}
		return res;
	}
	);

	//----------------------------------------------------------------------------------------
	/// Writes data to the stream and keeps the right byte order.
	/// If a Int64 is written into the stream on a little endian system it will be flipped when reading into a big endian system.
	/// @param[in] data								Pointer to a memory address with the data.
	/// @param[in] dataSize						Size of the data to write. Possible sizes are 1 (without byte order changes) or 2, 4, 8 (with byte order correction).
	/// @param[in] elementCount				Number of data elements.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> WriteData(const void* data, Int dataSize, Int elementCount);

	//----------------------------------------------------------------------------------------
	/// Flushes the output stream and forces any buffered output to be written.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Flush();

	//----------------------------------------------------------------------------------------
	/// Writes data to the stream and keeps the right byte order.
	/// @param[in] data								Data to write into the stream.
	/// @return												OK on success.
	/// @MAXON_ANNOTATION{returnsThis}
	//----------------------------------------------------------------------------------------
	template <typename T> MAXON_FUNCTION Result<void> Write(const Block<const T>& data)
	{
		return WriteData(data.GetFirst(), SIZEOF(T), data.GetCount());
	}
};


#include "dataformat_base1.hxx"

#include "dataformat_base2.hxx"

template <typename T> class WriterRef : public DataFormatBaseWriterRef
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(WriterRef, DataFormatBaseWriterRef);

	Result<void> Write(const Block<const T>& data) const
	{
		return DataFormatBaseWriterRef::Write<T>(data);
	}

	Result<void> Write(const T& data) const
	{
		return DataFormatBaseWriterRef::WriteData(&data, SIZEOF(T), 1);
	}

	static const WriterRef& NullValue()
	{
		return *static_cast<const WriterRef*>(&DataFormatBaseWriterRef::NullValue());
	}
};

template <> class WriterRef<Utf32Char> : public DataFormatBaseWriterRef
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(WriterRef, DataFormatBaseWriterRef);

	Result<void> Write(const Block<const Utf32Char>& data) const
	{
		return DataFormatBaseWriterRef::Write<Utf32Char>(data);
	}

	Result<void> Write(const Utf32Char& data) const
	{
		return DataFormatBaseWriterRef::WriteData(&data, SIZEOF(Utf32Char), 1);
	}

	Result<void> Write(const String& data) const
	{
		iferr_scope;
		for (Utf32Char c : data)
		{
			Write(c) iferr_return;
		}
		return OK;
	}

	static const WriterRef& NullValue()
	{
		return *static_cast<const WriterRef*>(&DataFormatBaseWriterRef::NullValue());
	}
};

template <typename T> class ReaderRef : public DataFormatBaseReaderRef
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(ReaderRef, DataFormatBaseReaderRef);

	Result<T> Read() const
	{
		iferr_scope;
		T value;
		DataFormatBaseReaderRef::ReadData(&value, SIZEOF(T), 1) iferr_return;
		return std::move(value);
	}

	Result<Int> ReadEOS(const Block<T>& data) const
	{
		return DataFormatBaseReaderRef::ReadDataEOS(data.GetFirst(), SIZEOF(T), data.GetCount());
	}

	static const ReaderRef& NullValue()
	{
		return *static_cast<const ReaderRef*>(&DataFormatBaseReaderRef::NullValue());
	}
};

template <> class ReaderRef<Utf32Char> : public DataFormatBaseReaderRef
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(ReaderRef, DataFormatBaseReaderRef);

	using T = Utf32Char;

	Result<T> Read() const
	{
		iferr_scope;
		T value;
		DataFormatBaseReaderRef::ReadData(&value, SIZEOF(T), 1) iferr_return;
		return std::move(value);
	}

	Result<Int> ReadEOS(const Block<T>& data) const
	{
		return DataFormatBaseReaderRef::ReadDataEOS(data.GetFirst(), SIZEOF(T), data.GetCount());
	}

	static const ReaderRef& NullValue()
	{
		return *static_cast<const ReaderRef*>(&DataFormatBaseReaderRef::NullValue());
	}

	Result<Tuple<String, Bool>> ReadLine() const
	{
		iferr_scope;
		BaseArray<T> chars;
		T value;
		while (true)
		{
			Int cnt = DataFormatBaseReaderRef::ReadDataEOS(&value, SIZEOF(T), 1) iferr_return;
			if (cnt == 0)
			{
				if (chars.IsEmpty())
					return Tuple<String, Bool>{String(), false};
				else
					return Tuple<String, Bool>{String(chars), true};
			}
			DebugAssert(cnt == 1);
			switch (value)
			{
				case '\n':
					return Tuple<String, Bool>{String(chars), true};
				case '\r':
					break;
				default:
					chars.Append(value) iferr_return;
					break;
			}
		}
	}

	class LinesIterator;

	Result<LinesIterator> GetLines() const;
};

class ReaderRef<Utf32Char>::LinesIterator
{
public:
	template <typename SUPER> using ResultFunctions = ResultIteratorFunctions<SUPER>;

	static Result<LinesIterator> Create(const ReaderRef& reader)
	{
		iferr_scope;
		LinesIterator it;
		it._reader = reader;
		it._line = reader.ReadLine() iferr_return;
		return std::move(it);
	}

	Bool HasEntry() const
	{
		return _line.second;
	}

	Result<void> operator ++()
	{
		iferr_scope;
		_line = _reader.ReadLine() iferr_return;
		return OK;
	}

	const String& operator *() const
	{
		return _line.first;
	}

private:
	ReaderRef _reader;
	Tuple<String, Bool> _line;
};

inline auto ReaderRef<Utf32Char>::GetLines() const -> Result<LinesIterator>
{
	return LinesIterator::Create(*this);
}

}

#endif // DATAFORMAT_BASE_H__

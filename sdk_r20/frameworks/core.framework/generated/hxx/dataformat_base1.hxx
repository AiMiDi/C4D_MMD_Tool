#if 1
namespace DATAFORMATBASEIDS
{
#ifndef PRIVATE_MAXON_GUARD_maxon_DATAFORMATBASEIDS
#define PRIVATE_MAXON_GUARD_maxon_DATAFORMATBASEIDS
	class RESTRICT : public maxon::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
#endif
}
struct DataFormatBaseReaderInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, DataFormatBaseReaderInterface>::value || DataDictionaryObjectInterface::HasBase::Check<I>::value; static I* Cast(DataFormatBaseReaderInterface* ptr) { return static_cast<I*>(static_cast<maxon::Object*>(ptr)); } }; };
class DataFormatBaseReaderRef;

struct DataFormatBaseReaderInterface::ReferenceClassHelper { using type = DataFormatBaseReaderRef; };

/// Intermediate helper class for DataFormatBaseReaderInterface.
template <typename S> class DataFormatBaseReaderInterface::ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
{
public:
	ConstReferenceFunctionsImpl() = default;
	using PrivateBaseClass = S;
	using PrivateBaseClass::PrivateBaseClass;
};
#ifdef DOXYGEN
template <typename REF> class DataFormatBaseReaderInterface::ConstReferenceFunctionsImplDoxy : public DataFormatBaseReaderInterface::ConstReferenceFunctionsImpl<REF>, public DataDictionaryObjectInterface::ConstReferenceFunctionsImplDoxy<REF> { };
#endif

/// Intermediate helper class for DataFormatBaseReaderInterface.
template <typename S> class DataFormatBaseReaderInterface::ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	ReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, DataFormatBaseReaderRef, true>::type&() const { return reinterpret_cast<const DataFormatBaseReaderRef&>(this->GetBaseRef()); }
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, DataFormatBaseReaderRef, false>::type&() { return reinterpret_cast<const DataFormatBaseReaderRef&>(this->GetBaseRef()); }
/// Close the stream and the stream handle.
/// @return												OK on success.
	inline Result<void> CloseInput() const;

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
	
	public:
/// Reads data from the stream and keeps the right byte order.
/// E.g. if a Int64 is written into the stream on a little endian system it will be flipped when reading into a big endian system.
/// @param[in] data								Pointer to a memory address with the data.
/// @param[in] dataSize						Size of the data to write. Possible sizes are 1 (without byte order changes) or 2, 4, 8 (with byte order correction).
/// @param[in] elementCount				Number of data elements.
/// @return												OK on success.
	inline Result<void> ReadData(void* data, Int dataSize, Int elementCount) const;
/// Reads data from the stream and keeps the right byte order.
/// E.g. if a Int64 is written into the stream on a little endian system it will be flipped when reading into a big endian system.
/// @param[in] data								Pointer to a memory address with the data.
/// @param[in] dataSize						Size of the data to write. Possible sizes are 1 (without byte order changes) or 2, 4, 8 (with byte order correction).
/// @param[in] elementCount				Number of data elements.
/// @return												Returns the number of elements (not bytes) that have been read.
	inline Result<Int> ReadDataEOS(void* data, Int dataSize, Int elementCount) const;
};
#ifdef DOXYGEN
template <typename REF> class DataFormatBaseReaderInterface::ReferenceFunctionsImplDoxy : public DataFormatBaseReaderInterface::ReferenceFunctionsImpl<REF>, public DataDictionaryObjectInterface::ReferenceFunctionsImplDoxy<REF> { };
#endif

/// Intermediate helper class for DataFormatBaseReaderInterface.
template <typename S> class DataFormatBaseReaderInterface::COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	COWReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, DataFormatBaseReaderRef, false>::type&() { return reinterpret_cast<const DataFormatBaseReaderRef&>(this->GetBaseRef()); }
/// Close the stream and the stream handle.
/// @return												OK on success.
	inline Result<void> CloseInput();
/// Reads data from the stream and keeps the right byte order.
/// E.g. if a Int64 is written into the stream on a little endian system it will be flipped when reading into a big endian system.
/// @param[in] data								Pointer to a memory address with the data.
/// @param[in] dataSize						Size of the data to write. Possible sizes are 1 (without byte order changes) or 2, 4, 8 (with byte order correction).
/// @param[in] elementCount				Number of data elements.
/// @return												OK on success.
	inline Result<void> ReadData(void* data, Int dataSize, Int elementCount);
/// Reads data from the stream and keeps the right byte order.
/// E.g. if a Int64 is written into the stream on a little endian system it will be flipped when reading into a big endian system.
/// @param[in] data								Pointer to a memory address with the data.
/// @param[in] dataSize						Size of the data to write. Possible sizes are 1 (without byte order changes) or 2, 4, 8 (with byte order correction).
/// @param[in] elementCount				Number of data elements.
/// @return												Returns the number of elements (not bytes) that have been read.
	inline Result<Int> ReadDataEOS(void* data, Int dataSize, Int elementCount);
};
#ifdef DOXYGEN
template <typename REF> class DataFormatBaseReaderInterface::COWReferenceFunctionsImplDoxy : public DataFormatBaseReaderInterface::COWReferenceFunctionsImpl<REF>, public DataDictionaryObjectInterface::COWReferenceFunctionsImplDoxy<REF> { };
#endif

template <typename ST> struct DataFormatBaseReaderInterface::ReferenceFunctions { using type = typename std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename DataDictionaryObjectInterface::ReferenceFunctions<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename DataDictionaryObjectInterface::ReferenceFunctions<ST>::type>, ReferenceFunctionsImpl<typename DataDictionaryObjectInterface::ReferenceFunctions<ST>::type>>::type>::type; };
class DataFormatBaseReaderInterface::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<DataFormatBaseReaderRef>
#else
public maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<DataFormatBaseReaderInterface, maxon::StrongRefHandler, DataFormatBaseReaderRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<DataFormatBaseReaderInterface, maxon::StrongRefHandler, DataFormatBaseReaderRef>>>>);
	using NonConst = Super::ReferenceClass;
};

/// DataFormatBaseReaderRef is the reference class of DataFormatBaseReaderInterface.
///
/// This class serializes data from IoStreams.
/// It defines a file format for each data type.
class DataFormatBaseReaderRef : public DataFormatBaseReaderInterface::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(DataFormatBaseReaderRef, Reference);
};

struct DataFormatBaseWriterInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, DataFormatBaseWriterInterface>::value || DataDictionaryObjectInterface::HasBase::Check<I>::value; static I* Cast(DataFormatBaseWriterInterface* ptr) { return static_cast<I*>(static_cast<maxon::Object*>(ptr)); } }; };
class DataFormatBaseWriterRef;

struct DataFormatBaseWriterInterface::ReferenceClassHelper { using type = DataFormatBaseWriterRef; };

/// Intermediate helper class for DataFormatBaseWriterInterface.
template <typename S> class DataFormatBaseWriterInterface::ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
{
public:
	ConstReferenceFunctionsImpl() = default;
	using PrivateBaseClass = S;
	using PrivateBaseClass::PrivateBaseClass;
};
#ifdef DOXYGEN
template <typename REF> class DataFormatBaseWriterInterface::ConstReferenceFunctionsImplDoxy : public DataFormatBaseWriterInterface::ConstReferenceFunctionsImpl<REF>, public DataDictionaryObjectInterface::ConstReferenceFunctionsImplDoxy<REF> { };
#endif

/// Intermediate helper class for DataFormatBaseWriterInterface.
template <typename S> class DataFormatBaseWriterInterface::ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	ReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, DataFormatBaseWriterRef, true>::type&() const { return reinterpret_cast<const DataFormatBaseWriterRef&>(this->GetBaseRef()); }
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, DataFormatBaseWriterRef, false>::type&() { return reinterpret_cast<const DataFormatBaseWriterRef&>(this->GetBaseRef()); }
/// Close the stream and the stream handle.
/// @return												OK on success.
	inline Result<void> CloseOutput() const;

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
	
	public:
/// Writes data to the stream and keeps the right byte order.
/// If a Int64 is written into the stream on a little endian system it will be flipped when reading into a big endian system.
/// @param[in] data								Pointer to a memory address with the data.
/// @param[in] dataSize						Size of the data to write. Possible sizes are 1 (without byte order changes) or 2, 4, 8 (with byte order correction).
/// @param[in] elementCount				Number of data elements.
/// @return												OK on success.
	inline Result<void> WriteData(const void* data, Int dataSize, Int elementCount) const;
/// Flushes the output stream and forces any buffered output to be written.
/// @return												OK on success.
	inline Result<void> Flush() const;
/// Writes data to the stream and keeps the right byte order.
/// @param[in] data								Data to write into the stream.
/// @return												OK on success.
	template <typename T> inline maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)> Write(const Block<const T>& data) const;
};
#ifdef DOXYGEN
template <typename REF> class DataFormatBaseWriterInterface::ReferenceFunctionsImplDoxy : public DataFormatBaseWriterInterface::ReferenceFunctionsImpl<REF>, public DataDictionaryObjectInterface::ReferenceFunctionsImplDoxy<REF> { };
#endif

/// Intermediate helper class for DataFormatBaseWriterInterface.
template <typename S> class DataFormatBaseWriterInterface::COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	COWReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, DataFormatBaseWriterRef, false>::type&() { return reinterpret_cast<const DataFormatBaseWriterRef&>(this->GetBaseRef()); }
/// Close the stream and the stream handle.
/// @return												OK on success.
	inline Result<void> CloseOutput();
/// Writes data to the stream and keeps the right byte order.
/// If a Int64 is written into the stream on a little endian system it will be flipped when reading into a big endian system.
/// @param[in] data								Pointer to a memory address with the data.
/// @param[in] dataSize						Size of the data to write. Possible sizes are 1 (without byte order changes) or 2, 4, 8 (with byte order correction).
/// @param[in] elementCount				Number of data elements.
/// @return												OK on success.
	inline Result<void> WriteData(const void* data, Int dataSize, Int elementCount);
/// Flushes the output stream and forces any buffered output to be written.
/// @return												OK on success.
	inline Result<void> Flush();
/// Writes data to the stream and keeps the right byte order.
/// @param[in] data								Data to write into the stream.
/// @return												OK on success.
	template <typename T> inline maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)> Write(const Block<const T>& data);
};
#ifdef DOXYGEN
template <typename REF> class DataFormatBaseWriterInterface::COWReferenceFunctionsImplDoxy : public DataFormatBaseWriterInterface::COWReferenceFunctionsImpl<REF>, public DataDictionaryObjectInterface::COWReferenceFunctionsImplDoxy<REF> { };
#endif

template <typename ST> struct DataFormatBaseWriterInterface::ReferenceFunctions { using type = typename std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename DataDictionaryObjectInterface::ReferenceFunctions<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename DataDictionaryObjectInterface::ReferenceFunctions<ST>::type>, ReferenceFunctionsImpl<typename DataDictionaryObjectInterface::ReferenceFunctions<ST>::type>>::type>::type; };
class DataFormatBaseWriterInterface::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<DataFormatBaseWriterRef>
#else
public maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<DataFormatBaseWriterInterface, maxon::StrongRefHandler, DataFormatBaseWriterRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<DataFormatBaseWriterInterface, maxon::StrongRefHandler, DataFormatBaseWriterRef>>>>);
	using NonConst = Super::ReferenceClass;
};

/// DataFormatBaseWriterRef is the reference class of DataFormatBaseWriterInterface.
///
/// This class serializes data into IoStreams.
/// It defines a file format for each data type.
///
class DataFormatBaseWriterRef : public DataFormatBaseWriterInterface::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(DataFormatBaseWriterRef, Reference);
};

#endif

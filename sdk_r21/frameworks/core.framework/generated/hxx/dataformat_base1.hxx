#if 1
namespace DATAFORMATBASEIDS
{
#ifndef PRIVATE_MAXON_GUARD_maxon_DATAFORMATBASEIDS
#define PRIVATE_MAXON_GUARD_maxon_DATAFORMATBASEIDS
	class RESTRICT : public maxon::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
#endif
}
class DataFormatBaseReaderRef;

struct DataFormatBaseReaderInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, DataFormatBaseReaderInterface>::value || DataDictionaryObjectInterface::HasBase::template Check<I>::value; static I* Cast(DataFormatBaseReaderInterface* ptr) { return static_cast<I*>(static_cast<maxon::ObjectInterface*>(ptr)); } }; };
struct DataFormatBaseReaderInterface::Hxx1
{
	class Reference;
	using ReferenceClass = DataFormatBaseReaderRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<DataDictionaryObjectInterface>;
	/// Intermediate helper class for DataFormatBaseReaderInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
	};
	/// Intermediate helper class for DataFormatBaseReaderInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
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
	/// Intermediate helper class for DataFormatBaseReaderInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
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
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename DataDictionaryObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename DataDictionaryObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename DataDictionaryObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type> { };
};
class DataFormatBaseReaderInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<DataFormatBaseReaderRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<DataFormatBaseReaderInterface, maxon::StrongRefHandler, DataFormatBaseReaderRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<DataFormatBaseReaderInterface, maxon::StrongRefHandler, DataFormatBaseReaderRef>>>>);
	using NonConst = typename Super::ReferenceClass;
};

/// DataFormatBaseReaderRef is the reference class of DataFormatBaseReaderInterface.
///
/// This class serializes data from IoStreams.
/// It defines a file format for each data type.
class DataFormatBaseReaderRef : public DataFormatBaseReaderInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(DataFormatBaseReaderRef, typename DataFormatBaseReaderInterface::Hxx1::Reference);
};

class DataFormatBaseWriterRef;

struct DataFormatBaseWriterInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, DataFormatBaseWriterInterface>::value || DataDictionaryObjectInterface::HasBase::template Check<I>::value; static I* Cast(DataFormatBaseWriterInterface* ptr) { return static_cast<I*>(static_cast<maxon::ObjectInterface*>(ptr)); } }; };
struct DataFormatBaseWriterInterface::Hxx1
{
	class Reference;
	using ReferenceClass = DataFormatBaseWriterRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<DataDictionaryObjectInterface>;
	/// Intermediate helper class for DataFormatBaseWriterInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
	};
	/// Intermediate helper class for DataFormatBaseWriterInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
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
	/// Intermediate helper class for DataFormatBaseWriterInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
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
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename DataDictionaryObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename DataDictionaryObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename DataDictionaryObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type> { };
};
class DataFormatBaseWriterInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<DataFormatBaseWriterRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<DataFormatBaseWriterInterface, maxon::StrongRefHandler, DataFormatBaseWriterRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<DataFormatBaseWriterInterface, maxon::StrongRefHandler, DataFormatBaseWriterRef>>>>);
	using NonConst = typename Super::ReferenceClass;
};

/// DataFormatBaseWriterRef is the reference class of DataFormatBaseWriterInterface.
///
/// This class serializes data into IoStreams.
/// It defines a file format for each data type.
///
class DataFormatBaseWriterRef : public DataFormatBaseWriterInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(DataFormatBaseWriterRef, typename DataFormatBaseWriterInterface::Hxx1::Reference);
};

#endif

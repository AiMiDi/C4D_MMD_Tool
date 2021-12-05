
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1

struct StreamConversionInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(ConvertImpl);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(ConvertToReader);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(ConvertToStream);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(ConvertToWriter);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetBatchSize);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetBlockSize);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetCounterpart);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetDestinationType);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetSourceType);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(SupportInplaceConversion);
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	Int (*_StreamConversionInterface_GetBatchSize) (const maxon::GenericComponent* this_);
	maxon::Int _StreamConversionInterface_GetBatchSize_Offset;
	Int (*_StreamConversionInterface_GetBlockSize) (const maxon::GenericComponent* this_);
	maxon::Int _StreamConversionInterface_GetBlockSize_Offset;
	Id (*_StreamConversionInterface_GetCounterpart) (const maxon::GenericComponent* this_);
	maxon::Int _StreamConversionInterface_GetCounterpart_Offset;
	const DataType& (*_StreamConversionInterface_GetSourceType) (const maxon::GenericComponent* this_);
	maxon::Int _StreamConversionInterface_GetSourceType_Offset;
	const DataType& (*_StreamConversionInterface_GetDestinationType) (const maxon::GenericComponent* this_);
	maxon::Int _StreamConversionInterface_GetDestinationType_Offset;
	Bool (*_StreamConversionInterface_SupportInplaceConversion) (const maxon::GenericComponent* this_);
	maxon::Int _StreamConversionInterface_SupportInplaceConversion_Offset;
	Result<Int> (*_StreamConversionInterface_ConvertImpl) (maxon::GenericComponent* this_, const Block<const Generic>& src, WritableArrayInterface<Generic>& dst, Int dstLimitHint, Bool inputFinished, Bool& outputFinished);
	maxon::Int _StreamConversionInterface_ConvertImpl_Offset;
	Result<InputStreamRef> (*_StreamConversionInterface_ConvertToStream) (maxon::GenericComponent* this_, const InputStreamRef& in);
	maxon::Int _StreamConversionInterface_ConvertToStream_Offset;
	Result<InputStreamRef> (*_StreamConversionInterface_ConvertToStream_1) (maxon::GenericComponent* this_, const DataFormatBaseReaderRef& in);
	maxon::Int _StreamConversionInterface_ConvertToStream_1_Offset;
	Result<DataFormatBaseReaderRef> (*_StreamConversionInterface_ConvertToReader) (maxon::GenericComponent* this_, const InputStreamRef& in);
	maxon::Int _StreamConversionInterface_ConvertToReader_Offset;
	Result<DataFormatBaseReaderRef> (*_StreamConversionInterface_ConvertToReader_1) (maxon::GenericComponent* this_, const DataFormatBaseReaderRef& in);
	maxon::Int _StreamConversionInterface_ConvertToReader_1_Offset;
	Result<OutputStreamRef> (*_StreamConversionInterface_ConvertToStream_2) (maxon::GenericComponent* this_, const OutputStreamRef& out);
	maxon::Int _StreamConversionInterface_ConvertToStream_2_Offset;
	Result<OutputStreamRef> (*_StreamConversionInterface_ConvertToStream_3) (maxon::GenericComponent* this_, const DataFormatBaseWriterRef& out);
	maxon::Int _StreamConversionInterface_ConvertToStream_3_Offset;
	Result<DataFormatBaseWriterRef> (*_StreamConversionInterface_ConvertToWriter) (maxon::GenericComponent* this_, const OutputStreamRef& out);
	maxon::Int _StreamConversionInterface_ConvertToWriter_Offset;
	Result<DataFormatBaseWriterRef> (*_StreamConversionInterface_ConvertToWriter_1) (maxon::GenericComponent* this_, const DataFormatBaseWriterRef& out);
	maxon::Int _StreamConversionInterface_ConvertToWriter_1_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, StreamConversionInterface, GetBatchSize))
	{
		auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, StreamConversionInterface, GetBatchSize), W, MTable>::type::_StreamConversionInterface_GetBatchSize;
		_StreamConversionInterface_GetBatchSize = reinterpret_cast<const decltype(_StreamConversionInterface_GetBatchSize)&>(ptr);
		_StreamConversionInterface_GetBatchSize_Offset = offset;
	}
	if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, StreamConversionInterface, GetBlockSize))
	{
		auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, StreamConversionInterface, GetBlockSize), W, MTable>::type::_StreamConversionInterface_GetBlockSize;
		_StreamConversionInterface_GetBlockSize = reinterpret_cast<const decltype(_StreamConversionInterface_GetBlockSize)&>(ptr);
		_StreamConversionInterface_GetBlockSize_Offset = offset;
	}
	if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, StreamConversionInterface, GetCounterpart))
	{
		auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, StreamConversionInterface, GetCounterpart), W, MTable>::type::_StreamConversionInterface_GetCounterpart;
		_StreamConversionInterface_GetCounterpart = reinterpret_cast<const decltype(_StreamConversionInterface_GetCounterpart)&>(ptr);
		_StreamConversionInterface_GetCounterpart_Offset = offset;
	}
	if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, StreamConversionInterface, GetSourceType))
	{
		auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, StreamConversionInterface, GetSourceType), W, MTable>::type::_StreamConversionInterface_GetSourceType;
		_StreamConversionInterface_GetSourceType = reinterpret_cast<const decltype(_StreamConversionInterface_GetSourceType)&>(ptr);
		_StreamConversionInterface_GetSourceType_Offset = offset;
	}
	if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, StreamConversionInterface, GetDestinationType))
	{
		auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, StreamConversionInterface, GetDestinationType), W, MTable>::type::_StreamConversionInterface_GetDestinationType;
		_StreamConversionInterface_GetDestinationType = reinterpret_cast<const decltype(_StreamConversionInterface_GetDestinationType)&>(ptr);
		_StreamConversionInterface_GetDestinationType_Offset = offset;
	}
	if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, StreamConversionInterface, SupportInplaceConversion))
	{
		auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, StreamConversionInterface, SupportInplaceConversion), W, MTable>::type::_StreamConversionInterface_SupportInplaceConversion;
		_StreamConversionInterface_SupportInplaceConversion = reinterpret_cast<const decltype(_StreamConversionInterface_SupportInplaceConversion)&>(ptr);
		_StreamConversionInterface_SupportInplaceConversion_Offset = offset;
	}
	if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, StreamConversionInterface, ConvertImpl))
	{
		auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, StreamConversionInterface, ConvertImpl), W, MTable>::type::_StreamConversionInterface_ConvertImpl;
		_StreamConversionInterface_ConvertImpl = reinterpret_cast<const decltype(_StreamConversionInterface_ConvertImpl)&>(ptr);
		_StreamConversionInterface_ConvertImpl_Offset = offset;
	}
	if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, StreamConversionInterface, ConvertToStream))
	{
		auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, StreamConversionInterface, ConvertToStream), W, MTable>::type::_StreamConversionInterface_ConvertToStream;
		_StreamConversionInterface_ConvertToStream = reinterpret_cast<const decltype(_StreamConversionInterface_ConvertToStream)&>(ptr);
		_StreamConversionInterface_ConvertToStream_Offset = offset;
	}
	if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, StreamConversionInterface, ConvertToStream))
	{
		auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, StreamConversionInterface, ConvertToStream), W, MTable>::type::_StreamConversionInterface_ConvertToStream_1;
		_StreamConversionInterface_ConvertToStream_1 = reinterpret_cast<const decltype(_StreamConversionInterface_ConvertToStream_1)&>(ptr);
		_StreamConversionInterface_ConvertToStream_1_Offset = offset;
	}
	if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, StreamConversionInterface, ConvertToReader))
	{
		auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, StreamConversionInterface, ConvertToReader), W, MTable>::type::_StreamConversionInterface_ConvertToReader;
		_StreamConversionInterface_ConvertToReader = reinterpret_cast<const decltype(_StreamConversionInterface_ConvertToReader)&>(ptr);
		_StreamConversionInterface_ConvertToReader_Offset = offset;
	}
	if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, StreamConversionInterface, ConvertToReader))
	{
		auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, StreamConversionInterface, ConvertToReader), W, MTable>::type::_StreamConversionInterface_ConvertToReader_1;
		_StreamConversionInterface_ConvertToReader_1 = reinterpret_cast<const decltype(_StreamConversionInterface_ConvertToReader_1)&>(ptr);
		_StreamConversionInterface_ConvertToReader_1_Offset = offset;
	}
	if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, StreamConversionInterface, ConvertToStream))
	{
		auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, StreamConversionInterface, ConvertToStream), W, MTable>::type::_StreamConversionInterface_ConvertToStream_2;
		_StreamConversionInterface_ConvertToStream_2 = reinterpret_cast<const decltype(_StreamConversionInterface_ConvertToStream_2)&>(ptr);
		_StreamConversionInterface_ConvertToStream_2_Offset = offset;
	}
	if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, StreamConversionInterface, ConvertToStream))
	{
		auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, StreamConversionInterface, ConvertToStream), W, MTable>::type::_StreamConversionInterface_ConvertToStream_3;
		_StreamConversionInterface_ConvertToStream_3 = reinterpret_cast<const decltype(_StreamConversionInterface_ConvertToStream_3)&>(ptr);
		_StreamConversionInterface_ConvertToStream_3_Offset = offset;
	}
	if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, StreamConversionInterface, ConvertToWriter))
	{
		auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, StreamConversionInterface, ConvertToWriter), W, MTable>::type::_StreamConversionInterface_ConvertToWriter;
		_StreamConversionInterface_ConvertToWriter = reinterpret_cast<const decltype(_StreamConversionInterface_ConvertToWriter)&>(ptr);
		_StreamConversionInterface_ConvertToWriter_Offset = offset;
	}
	if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, StreamConversionInterface, ConvertToWriter))
	{
		auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, StreamConversionInterface, ConvertToWriter), W, MTable>::type::_StreamConversionInterface_ConvertToWriter_1;
		_StreamConversionInterface_ConvertToWriter_1 = reinterpret_cast<const decltype(_StreamConversionInterface_ConvertToWriter_1)&>(ptr);
		_StreamConversionInterface_ConvertToWriter_1_Offset = offset;
	}
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!DataDictionaryObjectInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset);
		return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<StreamConversionInterface, typename DataDictionaryObjectInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<StreamConversionInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct StreamConversionInterface::Hxx2
{
	template <typename S> class CWrapper : public DataDictionaryObjectInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(ConvertImpl);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(ConvertToReader);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(ConvertToStream);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(ConvertToWriter);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetBatchSize);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetBlockSize);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetCounterpart);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetDestinationType);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetSourceType);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(SupportInplaceConversion);
		static Int _StreamConversionInterface_GetBatchSize(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetBatchSize(); }
		static Int _StreamConversionInterface_GetBlockSize(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetBlockSize(); }
		static Id _StreamConversionInterface_GetCounterpart(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetCounterpart(); }
		static const DataType& _StreamConversionInterface_GetSourceType(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetSourceType(); }
		static const DataType& _StreamConversionInterface_GetDestinationType(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetDestinationType(); }
		static Bool _StreamConversionInterface_SupportInplaceConversion(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->SupportInplaceConversion(); }
		static Result<Int> _StreamConversionInterface_ConvertImpl(maxon::GenericComponent* this_, const Block<const Generic>& src, WritableArrayInterface<Generic>& dst, Int dstLimitHint, Bool inputFinished, Bool& outputFinished) { return ((typename S::Implementation*) this_)->ConvertImpl(src, dst, dstLimitHint, inputFinished, outputFinished); }
		static Result<InputStreamRef> _StreamConversionInterface_ConvertToStream(maxon::GenericComponent* this_, const InputStreamRef& in) { return ((typename S::Implementation*) this_)->ConvertToStream(in); }
		static Result<InputStreamRef> _StreamConversionInterface_ConvertToStream_1(maxon::GenericComponent* this_, const DataFormatBaseReaderRef& in) { return ((typename S::Implementation*) this_)->ConvertToStream(in); }
		static Result<DataFormatBaseReaderRef> _StreamConversionInterface_ConvertToReader(maxon::GenericComponent* this_, const InputStreamRef& in) { return ((typename S::Implementation*) this_)->ConvertToReader(in); }
		static Result<DataFormatBaseReaderRef> _StreamConversionInterface_ConvertToReader_1(maxon::GenericComponent* this_, const DataFormatBaseReaderRef& in) { return ((typename S::Implementation*) this_)->ConvertToReader(in); }
		static Result<OutputStreamRef> _StreamConversionInterface_ConvertToStream_2(maxon::GenericComponent* this_, const OutputStreamRef& out) { return ((typename S::Implementation*) this_)->ConvertToStream(out); }
		static Result<OutputStreamRef> _StreamConversionInterface_ConvertToStream_3(maxon::GenericComponent* this_, const DataFormatBaseWriterRef& out) { return ((typename S::Implementation*) this_)->ConvertToStream(out); }
		static Result<DataFormatBaseWriterRef> _StreamConversionInterface_ConvertToWriter(maxon::GenericComponent* this_, const OutputStreamRef& out) { return ((typename S::Implementation*) this_)->ConvertToWriter(out); }
		static Result<DataFormatBaseWriterRef> _StreamConversionInterface_ConvertToWriter_1(maxon::GenericComponent* this_, const DataFormatBaseWriterRef& out) { return ((typename S::Implementation*) this_)->ConvertToWriter(out); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto StreamConversionInterface::GetBatchSize() const -> Int
{
	const StreamConversionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(StreamConversionInterface, this); return mt_._StreamConversionInterface_GetBatchSize((const maxon::GenericComponent*) this + mt_._StreamConversionInterface_GetBatchSize_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StreamConversionInterface::GetBlockSize() const -> Int
{
	const StreamConversionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(StreamConversionInterface, this); return mt_._StreamConversionInterface_GetBlockSize((const maxon::GenericComponent*) this + mt_._StreamConversionInterface_GetBlockSize_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StreamConversionInterface::GetCounterpart() const -> Id
{
	const StreamConversionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(StreamConversionInterface, this); return mt_._StreamConversionInterface_GetCounterpart((const maxon::GenericComponent*) this + mt_._StreamConversionInterface_GetCounterpart_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StreamConversionInterface::GetSourceType() const -> const DataType&
{
	const StreamConversionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(StreamConversionInterface, this); return mt_._StreamConversionInterface_GetSourceType((const maxon::GenericComponent*) this + mt_._StreamConversionInterface_GetSourceType_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StreamConversionInterface::GetDestinationType() const -> const DataType&
{
	const StreamConversionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(StreamConversionInterface, this); return mt_._StreamConversionInterface_GetDestinationType((const maxon::GenericComponent*) this + mt_._StreamConversionInterface_GetDestinationType_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StreamConversionInterface::SupportInplaceConversion() const -> Bool
{
	const StreamConversionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(StreamConversionInterface, this); return mt_._StreamConversionInterface_SupportInplaceConversion((const maxon::GenericComponent*) this + mt_._StreamConversionInterface_SupportInplaceConversion_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StreamConversionInterface::ConvertImpl(const Block<const Generic>& src, WritableArrayInterface<Generic>& dst, Int dstLimitHint, Bool inputFinished, Bool& outputFinished) -> Result<Int>
{
	const StreamConversionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(StreamConversionInterface, this); return mt_._StreamConversionInterface_ConvertImpl((maxon::GenericComponent*) this + mt_._StreamConversionInterface_ConvertImpl_Offset, src, dst, dstLimitHint, inputFinished, outputFinished);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StreamConversionInterface::ConvertToStream(const InputStreamRef& in) -> Result<InputStreamRef>
{
	const StreamConversionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(StreamConversionInterface, this); return mt_._StreamConversionInterface_ConvertToStream((maxon::GenericComponent*) this + mt_._StreamConversionInterface_ConvertToStream_Offset, in);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StreamConversionInterface::ConvertToStream(const DataFormatBaseReaderRef& in) -> Result<InputStreamRef>
{
	const StreamConversionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(StreamConversionInterface, this); return mt_._StreamConversionInterface_ConvertToStream_1((maxon::GenericComponent*) this + mt_._StreamConversionInterface_ConvertToStream_1_Offset, in);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StreamConversionInterface::ConvertToReader(const InputStreamRef& in) -> Result<DataFormatBaseReaderRef>
{
	const StreamConversionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(StreamConversionInterface, this); return mt_._StreamConversionInterface_ConvertToReader((maxon::GenericComponent*) this + mt_._StreamConversionInterface_ConvertToReader_Offset, in);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StreamConversionInterface::ConvertToReader(const DataFormatBaseReaderRef& in) -> Result<DataFormatBaseReaderRef>
{
	const StreamConversionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(StreamConversionInterface, this); return mt_._StreamConversionInterface_ConvertToReader_1((maxon::GenericComponent*) this + mt_._StreamConversionInterface_ConvertToReader_1_Offset, in);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StreamConversionInterface::ConvertToStream(const OutputStreamRef& out) -> Result<OutputStreamRef>
{
	const StreamConversionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(StreamConversionInterface, this); return mt_._StreamConversionInterface_ConvertToStream_2((maxon::GenericComponent*) this + mt_._StreamConversionInterface_ConvertToStream_2_Offset, out);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StreamConversionInterface::ConvertToStream(const DataFormatBaseWriterRef& out) -> Result<OutputStreamRef>
{
	const StreamConversionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(StreamConversionInterface, this); return mt_._StreamConversionInterface_ConvertToStream_3((maxon::GenericComponent*) this + mt_._StreamConversionInterface_ConvertToStream_3_Offset, out);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StreamConversionInterface::ConvertToWriter(const OutputStreamRef& out) -> Result<DataFormatBaseWriterRef>
{
	const StreamConversionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(StreamConversionInterface, this); return mt_._StreamConversionInterface_ConvertToWriter((maxon::GenericComponent*) this + mt_._StreamConversionInterface_ConvertToWriter_Offset, out);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StreamConversionInterface::ConvertToWriter(const DataFormatBaseWriterRef& out) -> Result<DataFormatBaseWriterRef>
{
	const StreamConversionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(StreamConversionInterface, this); return mt_._StreamConversionInterface_ConvertToWriter_1((maxon::GenericComponent*) this + mt_._StreamConversionInterface_ConvertToWriter_1_Offset, out);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StreamConversionInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetBatchSize() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StreamConversionInterface* o_ = (const StreamConversionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = StreamConversionInterface::NullValuePtr(); if (!o_) return 0; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(StreamConversionInterface, o_, StreamConversionInterface_GetBatchSize) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<StreamConversionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<StreamConversionInterface>() : PRIVATE_MAXON_VTABLE(StreamConversionInterface, o_); 
	return (mt_._StreamConversionInterface_GetBatchSize(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._StreamConversionInterface_GetBatchSize_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StreamConversionInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetBlockSize() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StreamConversionInterface* o_ = (const StreamConversionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = StreamConversionInterface::NullValuePtr(); if (!o_) return 0; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(StreamConversionInterface, o_, StreamConversionInterface_GetBlockSize) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<StreamConversionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<StreamConversionInterface>() : PRIVATE_MAXON_VTABLE(StreamConversionInterface, o_); 
	return (mt_._StreamConversionInterface_GetBlockSize(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._StreamConversionInterface_GetBlockSize_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StreamConversionInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetCounterpart() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Id>, Id>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Id>, Id>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StreamConversionInterface* o_ = (const StreamConversionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = StreamConversionInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<Id>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(StreamConversionInterface, o_, StreamConversionInterface_GetCounterpart) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<StreamConversionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<StreamConversionInterface>() : PRIVATE_MAXON_VTABLE(StreamConversionInterface, o_); 
	return (mt_._StreamConversionInterface_GetCounterpart(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._StreamConversionInterface_GetCounterpart_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StreamConversionInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetSourceType() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const DataType&>, const DataType&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const DataType&>, const DataType&>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StreamConversionInterface* o_ = (const StreamConversionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = StreamConversionInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const DataType&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(StreamConversionInterface, o_, StreamConversionInterface_GetSourceType) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<StreamConversionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<StreamConversionInterface>() : PRIVATE_MAXON_VTABLE(StreamConversionInterface, o_); 
	return (mt_._StreamConversionInterface_GetSourceType(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._StreamConversionInterface_GetSourceType_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StreamConversionInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetDestinationType() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const DataType&>, const DataType&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const DataType&>, const DataType&>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StreamConversionInterface* o_ = (const StreamConversionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = StreamConversionInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const DataType&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(StreamConversionInterface, o_, StreamConversionInterface_GetDestinationType) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<StreamConversionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<StreamConversionInterface>() : PRIVATE_MAXON_VTABLE(StreamConversionInterface, o_); 
	return (mt_._StreamConversionInterface_GetDestinationType(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._StreamConversionInterface_GetDestinationType_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StreamConversionInterface::Hxx1::ConstReferenceFunctionsImpl<S>::SupportInplaceConversion() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const StreamConversionInterface* o_ = (const StreamConversionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = StreamConversionInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(StreamConversionInterface, o_, StreamConversionInterface_SupportInplaceConversion) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<StreamConversionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<StreamConversionInterface>() : PRIVATE_MAXON_VTABLE(StreamConversionInterface, o_); 
	return (mt_._StreamConversionInterface_SupportInplaceConversion(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._StreamConversionInterface_SupportInplaceConversion_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StreamConversionInterface::Hxx1::ReferenceFunctionsImpl<S>::ConvertImpl(const Block<const Generic>& src, WritableArrayInterface<Generic>& dst, Int dstLimitHint, Bool inputFinished, Bool& outputFinished) const -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StreamConversionInterface* o_ = (StreamConversionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(StreamConversionInterface, o_, StreamConversionInterface_ConvertImpl) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<StreamConversionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<StreamConversionInterface>() : PRIVATE_MAXON_VTABLE(StreamConversionInterface, o_); 
	return (mt_._StreamConversionInterface_ConvertImpl(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._StreamConversionInterface_ConvertImpl_Offset, src, dst, dstLimitHint, inputFinished, outputFinished));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StreamConversionInterface::Hxx1::COWReferenceFunctionsImpl<S>::ConvertImpl(const Block<const Generic>& src, WritableArrayInterface<Generic>& dst, Int dstLimitHint, Bool inputFinished, Bool& outputFinished) -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StreamConversionInterface* o_ = (StreamConversionInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(StreamConversionInterface, o_, StreamConversionInterface_ConvertImpl) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<StreamConversionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<StreamConversionInterface>() : PRIVATE_MAXON_VTABLE(StreamConversionInterface, o_); 
	return (mt_._StreamConversionInterface_ConvertImpl(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._StreamConversionInterface_ConvertImpl_Offset, src, dst, dstLimitHint, inputFinished, outputFinished));
}
template <typename S> template <typename SRC, typename DST> MAXON_ATTRIBUTE_FORCE_INLINE auto StreamConversionInterface::Hxx1::ReferenceFunctionsImpl<S>::Convert(const SRC& src, DST& dst, Int dstLimitHint, Bool inputFinished, Bool& outputFinished) const -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StreamConversionInterface* o_ = (StreamConversionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->Convert<SRC, DST>(src, dst, dstLimitHint, inputFinished, outputFinished));
}
template <typename S> template <typename SRC, typename DST> MAXON_ATTRIBUTE_FORCE_INLINE auto StreamConversionInterface::Hxx1::COWReferenceFunctionsImpl<S>::Convert(const SRC& src, DST& dst, Int dstLimitHint, Bool inputFinished, Bool& outputFinished) -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int>>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION StreamConversionInterface::Convert on super."); if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StreamConversionInterface* o_ = (StreamConversionInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (o_->Convert<SRC, DST>(src, dst, dstLimitHint, inputFinished, outputFinished));
}
template <typename S> template <typename SRC, typename DST> MAXON_ATTRIBUTE_FORCE_INLINE auto StreamConversionInterface::Hxx1::ReferenceFunctionsImpl<S>::ConvertAll(const SRC& src, DST& dst, Int dstLimitHint) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StreamConversionInterface* o_ = (StreamConversionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->ConvertAll<SRC, DST>(src, dst, dstLimitHint));
}
template <typename S> template <typename SRC, typename DST> MAXON_ATTRIBUTE_FORCE_INLINE auto StreamConversionInterface::Hxx1::COWReferenceFunctionsImpl<S>::ConvertAll(const SRC& src, DST& dst, Int dstLimitHint) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION StreamConversionInterface::ConvertAll on super."); if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StreamConversionInterface* o_ = (StreamConversionInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (o_->ConvertAll<SRC, DST>(src, dst, dstLimitHint));
}
template <typename S> template <typename SRC> MAXON_ATTRIBUTE_FORCE_INLINE auto StreamConversionInterface::Hxx1::ReferenceFunctionsImpl<S>::ConvertAllInplace(const SRC& data) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StreamConversionInterface* o_ = (StreamConversionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->ConvertAllInplace<SRC>(data));
}
template <typename S> template <typename SRC> MAXON_ATTRIBUTE_FORCE_INLINE auto StreamConversionInterface::Hxx1::COWReferenceFunctionsImpl<S>::ConvertAllInplace(const SRC& data) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION StreamConversionInterface::ConvertAllInplace on super."); if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StreamConversionInterface* o_ = (StreamConversionInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (o_->ConvertAllInplace<SRC>(data));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StreamConversionInterface::Hxx1::ReferenceFunctionsImpl<S>::ConvertToStream(const InputStreamRef& in) const -> Result<InputStreamRef>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<InputStreamRef>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StreamConversionInterface* o_ = (StreamConversionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(StreamConversionInterface, o_, StreamConversionInterface_ConvertToStream) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<StreamConversionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<StreamConversionInterface>() : PRIVATE_MAXON_VTABLE(StreamConversionInterface, o_); 
	return (mt_._StreamConversionInterface_ConvertToStream(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._StreamConversionInterface_ConvertToStream_Offset, in));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StreamConversionInterface::Hxx1::COWReferenceFunctionsImpl<S>::ConvertToStream(const InputStreamRef& in) -> Result<InputStreamRef>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<InputStreamRef>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StreamConversionInterface* o_ = (StreamConversionInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(StreamConversionInterface, o_, StreamConversionInterface_ConvertToStream) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<StreamConversionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<StreamConversionInterface>() : PRIVATE_MAXON_VTABLE(StreamConversionInterface, o_); 
	return (mt_._StreamConversionInterface_ConvertToStream(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._StreamConversionInterface_ConvertToStream_Offset, in));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StreamConversionInterface::Hxx1::ReferenceFunctionsImpl<S>::ConvertToStream(const DataFormatBaseReaderRef& in) const -> Result<InputStreamRef>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<InputStreamRef>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StreamConversionInterface* o_ = (StreamConversionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(StreamConversionInterface, o_, StreamConversionInterface_ConvertToStream_1) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<StreamConversionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<StreamConversionInterface>() : PRIVATE_MAXON_VTABLE(StreamConversionInterface, o_); 
	return (mt_._StreamConversionInterface_ConvertToStream_1(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._StreamConversionInterface_ConvertToStream_1_Offset, in));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StreamConversionInterface::Hxx1::COWReferenceFunctionsImpl<S>::ConvertToStream(const DataFormatBaseReaderRef& in) -> Result<InputStreamRef>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<InputStreamRef>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StreamConversionInterface* o_ = (StreamConversionInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(StreamConversionInterface, o_, StreamConversionInterface_ConvertToStream_1) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<StreamConversionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<StreamConversionInterface>() : PRIVATE_MAXON_VTABLE(StreamConversionInterface, o_); 
	return (mt_._StreamConversionInterface_ConvertToStream_1(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._StreamConversionInterface_ConvertToStream_1_Offset, in));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StreamConversionInterface::Hxx1::ReferenceFunctionsImpl<S>::ConvertToReader(const InputStreamRef& in) const -> Result<DataFormatBaseReaderRef>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<DataFormatBaseReaderRef>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StreamConversionInterface* o_ = (StreamConversionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(StreamConversionInterface, o_, StreamConversionInterface_ConvertToReader) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<StreamConversionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<StreamConversionInterface>() : PRIVATE_MAXON_VTABLE(StreamConversionInterface, o_); 
	return (mt_._StreamConversionInterface_ConvertToReader(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._StreamConversionInterface_ConvertToReader_Offset, in));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StreamConversionInterface::Hxx1::COWReferenceFunctionsImpl<S>::ConvertToReader(const InputStreamRef& in) -> Result<DataFormatBaseReaderRef>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<DataFormatBaseReaderRef>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StreamConversionInterface* o_ = (StreamConversionInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(StreamConversionInterface, o_, StreamConversionInterface_ConvertToReader) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<StreamConversionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<StreamConversionInterface>() : PRIVATE_MAXON_VTABLE(StreamConversionInterface, o_); 
	return (mt_._StreamConversionInterface_ConvertToReader(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._StreamConversionInterface_ConvertToReader_Offset, in));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StreamConversionInterface::Hxx1::ReferenceFunctionsImpl<S>::ConvertToReader(const DataFormatBaseReaderRef& in) const -> Result<DataFormatBaseReaderRef>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<DataFormatBaseReaderRef>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StreamConversionInterface* o_ = (StreamConversionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(StreamConversionInterface, o_, StreamConversionInterface_ConvertToReader_1) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<StreamConversionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<StreamConversionInterface>() : PRIVATE_MAXON_VTABLE(StreamConversionInterface, o_); 
	return (mt_._StreamConversionInterface_ConvertToReader_1(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._StreamConversionInterface_ConvertToReader_1_Offset, in));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StreamConversionInterface::Hxx1::COWReferenceFunctionsImpl<S>::ConvertToReader(const DataFormatBaseReaderRef& in) -> Result<DataFormatBaseReaderRef>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<DataFormatBaseReaderRef>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StreamConversionInterface* o_ = (StreamConversionInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(StreamConversionInterface, o_, StreamConversionInterface_ConvertToReader_1) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<StreamConversionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<StreamConversionInterface>() : PRIVATE_MAXON_VTABLE(StreamConversionInterface, o_); 
	return (mt_._StreamConversionInterface_ConvertToReader_1(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._StreamConversionInterface_ConvertToReader_1_Offset, in));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StreamConversionInterface::Hxx1::ReferenceFunctionsImpl<S>::ConvertToStream(const OutputStreamRef& out) const -> Result<OutputStreamRef>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<OutputStreamRef>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StreamConversionInterface* o_ = (StreamConversionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(StreamConversionInterface, o_, StreamConversionInterface_ConvertToStream_2) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<StreamConversionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<StreamConversionInterface>() : PRIVATE_MAXON_VTABLE(StreamConversionInterface, o_); 
	return (mt_._StreamConversionInterface_ConvertToStream_2(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._StreamConversionInterface_ConvertToStream_2_Offset, out));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StreamConversionInterface::Hxx1::COWReferenceFunctionsImpl<S>::ConvertToStream(const OutputStreamRef& out) -> Result<OutputStreamRef>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<OutputStreamRef>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StreamConversionInterface* o_ = (StreamConversionInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(StreamConversionInterface, o_, StreamConversionInterface_ConvertToStream_2) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<StreamConversionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<StreamConversionInterface>() : PRIVATE_MAXON_VTABLE(StreamConversionInterface, o_); 
	return (mt_._StreamConversionInterface_ConvertToStream_2(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._StreamConversionInterface_ConvertToStream_2_Offset, out));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StreamConversionInterface::Hxx1::ReferenceFunctionsImpl<S>::ConvertToStream(const DataFormatBaseWriterRef& out) const -> Result<OutputStreamRef>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<OutputStreamRef>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StreamConversionInterface* o_ = (StreamConversionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(StreamConversionInterface, o_, StreamConversionInterface_ConvertToStream_3) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<StreamConversionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<StreamConversionInterface>() : PRIVATE_MAXON_VTABLE(StreamConversionInterface, o_); 
	return (mt_._StreamConversionInterface_ConvertToStream_3(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._StreamConversionInterface_ConvertToStream_3_Offset, out));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StreamConversionInterface::Hxx1::COWReferenceFunctionsImpl<S>::ConvertToStream(const DataFormatBaseWriterRef& out) -> Result<OutputStreamRef>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<OutputStreamRef>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StreamConversionInterface* o_ = (StreamConversionInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(StreamConversionInterface, o_, StreamConversionInterface_ConvertToStream_3) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<StreamConversionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<StreamConversionInterface>() : PRIVATE_MAXON_VTABLE(StreamConversionInterface, o_); 
	return (mt_._StreamConversionInterface_ConvertToStream_3(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._StreamConversionInterface_ConvertToStream_3_Offset, out));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StreamConversionInterface::Hxx1::ReferenceFunctionsImpl<S>::ConvertToWriter(const OutputStreamRef& out) const -> Result<DataFormatBaseWriterRef>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<DataFormatBaseWriterRef>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StreamConversionInterface* o_ = (StreamConversionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(StreamConversionInterface, o_, StreamConversionInterface_ConvertToWriter) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<StreamConversionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<StreamConversionInterface>() : PRIVATE_MAXON_VTABLE(StreamConversionInterface, o_); 
	return (mt_._StreamConversionInterface_ConvertToWriter(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._StreamConversionInterface_ConvertToWriter_Offset, out));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StreamConversionInterface::Hxx1::COWReferenceFunctionsImpl<S>::ConvertToWriter(const OutputStreamRef& out) -> Result<DataFormatBaseWriterRef>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<DataFormatBaseWriterRef>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StreamConversionInterface* o_ = (StreamConversionInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(StreamConversionInterface, o_, StreamConversionInterface_ConvertToWriter) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<StreamConversionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<StreamConversionInterface>() : PRIVATE_MAXON_VTABLE(StreamConversionInterface, o_); 
	return (mt_._StreamConversionInterface_ConvertToWriter(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._StreamConversionInterface_ConvertToWriter_Offset, out));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StreamConversionInterface::Hxx1::ReferenceFunctionsImpl<S>::ConvertToWriter(const DataFormatBaseWriterRef& out) const -> Result<DataFormatBaseWriterRef>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<DataFormatBaseWriterRef>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StreamConversionInterface* o_ = (StreamConversionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(StreamConversionInterface, o_, StreamConversionInterface_ConvertToWriter_1) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<StreamConversionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<StreamConversionInterface>() : PRIVATE_MAXON_VTABLE(StreamConversionInterface, o_); 
	return (mt_._StreamConversionInterface_ConvertToWriter_1(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._StreamConversionInterface_ConvertToWriter_1_Offset, out));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StreamConversionInterface::Hxx1::COWReferenceFunctionsImpl<S>::ConvertToWriter(const DataFormatBaseWriterRef& out) -> Result<DataFormatBaseWriterRef>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<DataFormatBaseWriterRef>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); StreamConversionInterface* o_ = (StreamConversionInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(StreamConversionInterface, o_, StreamConversionInterface_ConvertToWriter_1) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<StreamConversionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<StreamConversionInterface>() : PRIVATE_MAXON_VTABLE(StreamConversionInterface, o_); 
	return (mt_._StreamConversionInterface_ConvertToWriter_1(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._StreamConversionInterface_ConvertToWriter_1_Offset, out));
}
auto StreamConversionInterface::GetPtr() -> Ptr { return Ptr(this); }
auto StreamConversionInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_StreamConversionInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_StreamConversionInterface() { new (s_ui_maxon_StreamConversionInterface) maxon::EntityUse(StreamConversionInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/streamconversion.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_StreamConversionInterface(StreamConversionInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/streamconversion.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif



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
	PRIVATE_MAXON_MF_POINTER(StreamConversionInterface_GetBatchSize, GetBatchSize, true, maxon::GenericComponent, const, (Int));
	maxon::Int StreamConversionInterface_GetBatchSize_Offset;
	PRIVATE_MAXON_MF_POINTER(StreamConversionInterface_GetBlockSize, GetBlockSize, true, maxon::GenericComponent, const, (Int));
	maxon::Int StreamConversionInterface_GetBlockSize_Offset;
	PRIVATE_MAXON_MF_POINTER(StreamConversionInterface_GetCounterpart, GetCounterpart, true, maxon::GenericComponent, const, (Id));
	maxon::Int StreamConversionInterface_GetCounterpart_Offset;
	PRIVATE_MAXON_MF_POINTER(StreamConversionInterface_GetSourceType, GetSourceType, true, maxon::GenericComponent, const, (const DataType&));
	maxon::Int StreamConversionInterface_GetSourceType_Offset;
	PRIVATE_MAXON_MF_POINTER(StreamConversionInterface_GetDestinationType, GetDestinationType, true, maxon::GenericComponent, const, (const DataType&));
	maxon::Int StreamConversionInterface_GetDestinationType_Offset;
	PRIVATE_MAXON_MF_POINTER(StreamConversionInterface_SupportInplaceConversion, SupportInplaceConversion, true, maxon::GenericComponent, const, (Bool));
	maxon::Int StreamConversionInterface_SupportInplaceConversion_Offset;
	PRIVATE_MAXON_MF_POINTER(StreamConversionInterface_ConvertImpl, ConvertImpl, true, maxon::GenericComponent,, (Result<Int>), const Block<const Generic>& src, WritableArrayInterface<Generic>& dst, Int dstLimitHint, Bool inputFinished, Bool& outputFinished);
	maxon::Int StreamConversionInterface_ConvertImpl_Offset;
	PRIVATE_MAXON_MF_POINTER(StreamConversionInterface_ConvertToStream, ConvertToStream, true, maxon::GenericComponent,, (Result<InputStreamRef>), const InputStreamRef& in);
	maxon::Int StreamConversionInterface_ConvertToStream_Offset;
	PRIVATE_MAXON_MF_POINTER(StreamConversionInterface_ConvertToStream_1, ConvertToStream, true, maxon::GenericComponent,, (Result<InputStreamRef>), const DataFormatBaseReaderRef& in);
	maxon::Int StreamConversionInterface_ConvertToStream_1_Offset;
	PRIVATE_MAXON_MF_POINTER(StreamConversionInterface_ConvertToReader, ConvertToReader, true, maxon::GenericComponent,, (Result<DataFormatBaseReaderRef>), const InputStreamRef& in);
	maxon::Int StreamConversionInterface_ConvertToReader_Offset;
	PRIVATE_MAXON_MF_POINTER(StreamConversionInterface_ConvertToReader_1, ConvertToReader, true, maxon::GenericComponent,, (Result<DataFormatBaseReaderRef>), const DataFormatBaseReaderRef& in);
	maxon::Int StreamConversionInterface_ConvertToReader_1_Offset;
	PRIVATE_MAXON_MF_POINTER(StreamConversionInterface_ConvertToStream_2, ConvertToStream, true, maxon::GenericComponent,, (Result<OutputStreamRef>), const OutputStreamRef& out);
	maxon::Int StreamConversionInterface_ConvertToStream_2_Offset;
	PRIVATE_MAXON_MF_POINTER(StreamConversionInterface_ConvertToStream_3, ConvertToStream, true, maxon::GenericComponent,, (Result<OutputStreamRef>), const DataFormatBaseWriterRef& out);
	maxon::Int StreamConversionInterface_ConvertToStream_3_Offset;
	PRIVATE_MAXON_MF_POINTER(StreamConversionInterface_ConvertToWriter, ConvertToWriter, true, maxon::GenericComponent,, (Result<DataFormatBaseWriterRef>), const OutputStreamRef& out);
	maxon::Int StreamConversionInterface_ConvertToWriter_Offset;
	PRIVATE_MAXON_MF_POINTER(StreamConversionInterface_ConvertToWriter_1, ConvertToWriter, true, maxon::GenericComponent,, (Result<DataFormatBaseWriterRef>), const DataFormatBaseWriterRef& out);
	maxon::Int StreamConversionInterface_ConvertToWriter_1_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, StreamConversionInterface, GetBatchSize))
	{
		maxon::Tie(StreamConversionInterface_GetBatchSize, StreamConversionInterface_GetBatchSize_Offset) = StreamConversionInterface_GetBatchSize_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, StreamConversionInterface, GetBlockSize))
	{
		maxon::Tie(StreamConversionInterface_GetBlockSize, StreamConversionInterface_GetBlockSize_Offset) = StreamConversionInterface_GetBlockSize_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, StreamConversionInterface, GetCounterpart))
	{
		maxon::Tie(StreamConversionInterface_GetCounterpart, StreamConversionInterface_GetCounterpart_Offset) = StreamConversionInterface_GetCounterpart_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, StreamConversionInterface, GetSourceType))
	{
		maxon::Tie(StreamConversionInterface_GetSourceType, StreamConversionInterface_GetSourceType_Offset) = StreamConversionInterface_GetSourceType_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, StreamConversionInterface, GetDestinationType))
	{
		maxon::Tie(StreamConversionInterface_GetDestinationType, StreamConversionInterface_GetDestinationType_Offset) = StreamConversionInterface_GetDestinationType_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, StreamConversionInterface, SupportInplaceConversion))
	{
		maxon::Tie(StreamConversionInterface_SupportInplaceConversion, StreamConversionInterface_SupportInplaceConversion_Offset) = StreamConversionInterface_SupportInplaceConversion_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, StreamConversionInterface, ConvertImpl))
	{
		maxon::Tie(StreamConversionInterface_ConvertImpl, StreamConversionInterface_ConvertImpl_Offset) = StreamConversionInterface_ConvertImpl_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, StreamConversionInterface, ConvertToStream))
	{
		maxon::Tie(StreamConversionInterface_ConvertToStream, StreamConversionInterface_ConvertToStream_Offset) = StreamConversionInterface_ConvertToStream_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, StreamConversionInterface, ConvertToStream))
	{
		maxon::Tie(StreamConversionInterface_ConvertToStream_1, StreamConversionInterface_ConvertToStream_1_Offset) = StreamConversionInterface_ConvertToStream_1_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, StreamConversionInterface, ConvertToReader))
	{
		maxon::Tie(StreamConversionInterface_ConvertToReader, StreamConversionInterface_ConvertToReader_Offset) = StreamConversionInterface_ConvertToReader_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, StreamConversionInterface, ConvertToReader))
	{
		maxon::Tie(StreamConversionInterface_ConvertToReader_1, StreamConversionInterface_ConvertToReader_1_Offset) = StreamConversionInterface_ConvertToReader_1_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, StreamConversionInterface, ConvertToStream))
	{
		maxon::Tie(StreamConversionInterface_ConvertToStream_2, StreamConversionInterface_ConvertToStream_2_Offset) = StreamConversionInterface_ConvertToStream_2_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, StreamConversionInterface, ConvertToStream))
	{
		maxon::Tie(StreamConversionInterface_ConvertToStream_3, StreamConversionInterface_ConvertToStream_3_Offset) = StreamConversionInterface_ConvertToStream_3_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, StreamConversionInterface, ConvertToWriter))
	{
		maxon::Tie(StreamConversionInterface_ConvertToWriter, StreamConversionInterface_ConvertToWriter_Offset) = StreamConversionInterface_ConvertToWriter_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, StreamConversionInterface, ConvertToWriter))
	{
		maxon::Tie(StreamConversionInterface_ConvertToWriter_1, StreamConversionInterface_ConvertToWriter_1_Offset) = StreamConversionInterface_ConvertToWriter_1_GetPtr<W>(offset, true);
	}
	}
	template <typename S> using CombinedMTable = maxon::PrivateCombinedMTable<StreamConversionInterface, typename DataDictionaryObjectInterface::MTable::template CombinedMTable<S>>;
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
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename DataDictionaryObjectInterface::Hxx2::template CWrapper<S>;
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (StreamConversionInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, StreamConversionInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		PRIVATE_MAXON_MF_WRAPPER(StreamConversionInterface_GetBatchSize, maxon::GenericComponent, const, (Int)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetBatchSize(); }
		PRIVATE_MAXON_MF_WRAPPER(StreamConversionInterface_GetBlockSize, maxon::GenericComponent, const, (Int)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetBlockSize(); }
		PRIVATE_MAXON_MF_WRAPPER(StreamConversionInterface_GetCounterpart, maxon::GenericComponent, const, (Id)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetCounterpart(); }
		PRIVATE_MAXON_MF_WRAPPER(StreamConversionInterface_GetSourceType, maxon::GenericComponent, const, (const DataType&)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetSourceType(); }
		PRIVATE_MAXON_MF_WRAPPER(StreamConversionInterface_GetDestinationType, maxon::GenericComponent, const, (const DataType&)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetDestinationType(); }
		PRIVATE_MAXON_MF_WRAPPER(StreamConversionInterface_SupportInplaceConversion, maxon::GenericComponent, const, (Bool)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->SupportInplaceConversion(); }
		PRIVATE_MAXON_MF_WRAPPER(StreamConversionInterface_ConvertImpl, maxon::GenericComponent,, (Result<Int>), const Block<const Generic>& src, WritableArrayInterface<Generic>& dst, Int dstLimitHint, Bool inputFinished, Bool& outputFinished) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->ConvertImpl(src, dst, dstLimitHint, inputFinished, outputFinished); }
		PRIVATE_MAXON_MF_WRAPPER(StreamConversionInterface_ConvertToStream, maxon::GenericComponent,, (Result<InputStreamRef>), const InputStreamRef& in) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->ConvertToStream(in); }
		PRIVATE_MAXON_MF_WRAPPER(StreamConversionInterface_ConvertToStream_1, maxon::GenericComponent,, (Result<InputStreamRef>), const DataFormatBaseReaderRef& in) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->ConvertToStream(in); }
		PRIVATE_MAXON_MF_WRAPPER(StreamConversionInterface_ConvertToReader, maxon::GenericComponent,, (Result<DataFormatBaseReaderRef>), const InputStreamRef& in) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->ConvertToReader(in); }
		PRIVATE_MAXON_MF_WRAPPER(StreamConversionInterface_ConvertToReader_1, maxon::GenericComponent,, (Result<DataFormatBaseReaderRef>), const DataFormatBaseReaderRef& in) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->ConvertToReader(in); }
		PRIVATE_MAXON_MF_WRAPPER(StreamConversionInterface_ConvertToStream_2, maxon::GenericComponent,, (Result<OutputStreamRef>), const OutputStreamRef& out) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->ConvertToStream(out); }
		PRIVATE_MAXON_MF_WRAPPER(StreamConversionInterface_ConvertToStream_3, maxon::GenericComponent,, (Result<OutputStreamRef>), const DataFormatBaseWriterRef& out) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->ConvertToStream(out); }
		PRIVATE_MAXON_MF_WRAPPER(StreamConversionInterface_ConvertToWriter, maxon::GenericComponent,, (Result<DataFormatBaseWriterRef>), const OutputStreamRef& out) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->ConvertToWriter(out); }
		PRIVATE_MAXON_MF_WRAPPER(StreamConversionInterface_ConvertToWriter_1, maxon::GenericComponent,, (Result<DataFormatBaseWriterRef>), const DataFormatBaseWriterRef& out) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->ConvertToWriter(out); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto StreamConversionInterface::GetBatchSize() const -> Int
{
	const StreamConversionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(StreamConversionInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.StreamConversionInterface_GetBatchSize_Offset), mt_.StreamConversionInterface_GetBatchSize);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StreamConversionInterface::GetBlockSize() const -> Int
{
	const StreamConversionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(StreamConversionInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.StreamConversionInterface_GetBlockSize_Offset), mt_.StreamConversionInterface_GetBlockSize);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StreamConversionInterface::GetCounterpart() const -> Id
{
	const StreamConversionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(StreamConversionInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.StreamConversionInterface_GetCounterpart_Offset), mt_.StreamConversionInterface_GetCounterpart);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StreamConversionInterface::GetSourceType() const -> const DataType&
{
	const StreamConversionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(StreamConversionInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.StreamConversionInterface_GetSourceType_Offset), mt_.StreamConversionInterface_GetSourceType);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StreamConversionInterface::GetDestinationType() const -> const DataType&
{
	const StreamConversionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(StreamConversionInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.StreamConversionInterface_GetDestinationType_Offset), mt_.StreamConversionInterface_GetDestinationType);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StreamConversionInterface::SupportInplaceConversion() const -> Bool
{
	const StreamConversionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(StreamConversionInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.StreamConversionInterface_SupportInplaceConversion_Offset), mt_.StreamConversionInterface_SupportInplaceConversion);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StreamConversionInterface::ConvertImpl(const Block<const Generic>& src, WritableArrayInterface<Generic>& dst, Int dstLimitHint, Bool inputFinished, Bool& outputFinished) -> Result<Int>
{
	const StreamConversionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(StreamConversionInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.StreamConversionInterface_ConvertImpl_Offset), mt_.StreamConversionInterface_ConvertImpl, src, dst, dstLimitHint, inputFinished, outputFinished);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StreamConversionInterface::ConvertToStream(const InputStreamRef& in) -> Result<InputStreamRef>
{
	const StreamConversionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(StreamConversionInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.StreamConversionInterface_ConvertToStream_Offset), mt_.StreamConversionInterface_ConvertToStream, in);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StreamConversionInterface::ConvertToStream(const DataFormatBaseReaderRef& in) -> Result<InputStreamRef>
{
	const StreamConversionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(StreamConversionInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.StreamConversionInterface_ConvertToStream_1_Offset), mt_.StreamConversionInterface_ConvertToStream_1, in);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StreamConversionInterface::ConvertToReader(const InputStreamRef& in) -> Result<DataFormatBaseReaderRef>
{
	const StreamConversionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(StreamConversionInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.StreamConversionInterface_ConvertToReader_Offset), mt_.StreamConversionInterface_ConvertToReader, in);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StreamConversionInterface::ConvertToReader(const DataFormatBaseReaderRef& in) -> Result<DataFormatBaseReaderRef>
{
	const StreamConversionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(StreamConversionInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.StreamConversionInterface_ConvertToReader_1_Offset), mt_.StreamConversionInterface_ConvertToReader_1, in);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StreamConversionInterface::ConvertToStream(const OutputStreamRef& out) -> Result<OutputStreamRef>
{
	const StreamConversionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(StreamConversionInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.StreamConversionInterface_ConvertToStream_2_Offset), mt_.StreamConversionInterface_ConvertToStream_2, out);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StreamConversionInterface::ConvertToStream(const DataFormatBaseWriterRef& out) -> Result<OutputStreamRef>
{
	const StreamConversionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(StreamConversionInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.StreamConversionInterface_ConvertToStream_3_Offset), mt_.StreamConversionInterface_ConvertToStream_3, out);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StreamConversionInterface::ConvertToWriter(const OutputStreamRef& out) -> Result<DataFormatBaseWriterRef>
{
	const StreamConversionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(StreamConversionInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.StreamConversionInterface_ConvertToWriter_Offset), mt_.StreamConversionInterface_ConvertToWriter, out);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto StreamConversionInterface::ConvertToWriter(const DataFormatBaseWriterRef& out) -> Result<DataFormatBaseWriterRef>
{
	const StreamConversionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(StreamConversionInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.StreamConversionInterface_ConvertToWriter_1_Offset), mt_.StreamConversionInterface_ConvertToWriter_1, out);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StreamConversionInterface::Hxx1::ConstFn<S>::GetBatchSize() const -> HXXADDRET2(Int)
{
	HXXRETURN0(HXXADDRET2(Int)); HXXRES; HXXCONST(0) HXXTABLE(StreamConversionInterface_GetBatchSize); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.StreamConversionInterface_GetBatchSize_Offset), mt_.StreamConversionInterface_GetBatchSize));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StreamConversionInterface::Hxx1::ConstFn<S>::GetBlockSize() const -> HXXADDRET2(Int)
{
	HXXRETURN0(HXXADDRET2(Int)); HXXRES; HXXCONST(0) HXXTABLE(StreamConversionInterface_GetBlockSize); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.StreamConversionInterface_GetBlockSize_Offset), mt_.StreamConversionInterface_GetBlockSize));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StreamConversionInterface::Hxx1::ConstFn<S>::GetCounterpart() const -> HXXADDRET2(Id)
{
	HXXRETURN0(HXXADDRET2(Id)); HXXRES; HXXCONST(HXXRET3(NULLPTR, Id)) HXXTABLE(StreamConversionInterface_GetCounterpart); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.StreamConversionInterface_GetCounterpart_Offset), mt_.StreamConversionInterface_GetCounterpart));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StreamConversionInterface::Hxx1::ConstFn<S>::GetSourceType() const -> HXXADDRET2(const DataType&)
{
	HXXRETURN0(HXXADDRET2(const DataType&)); HXXRES; HXXCONST(HXXRET3(NULLPTR, const DataType&)) HXXTABLE(StreamConversionInterface_GetSourceType); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.StreamConversionInterface_GetSourceType_Offset), mt_.StreamConversionInterface_GetSourceType));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StreamConversionInterface::Hxx1::ConstFn<S>::GetDestinationType() const -> HXXADDRET2(const DataType&)
{
	HXXRETURN0(HXXADDRET2(const DataType&)); HXXRES; HXXCONST(HXXRET3(NULLPTR, const DataType&)) HXXTABLE(StreamConversionInterface_GetDestinationType); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.StreamConversionInterface_GetDestinationType_Offset), mt_.StreamConversionInterface_GetDestinationType));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StreamConversionInterface::Hxx1::ConstFn<S>::SupportInplaceConversion() const -> HXXADDRET2(Bool)
{
	HXXRETURN0(HXXADDRET2(Bool)); HXXRES; HXXCONST(maxon::PrivateLogNullptrError(false)) HXXTABLE(StreamConversionInterface_SupportInplaceConversion); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.StreamConversionInterface_SupportInplaceConversion_Offset), mt_.StreamConversionInterface_SupportInplaceConversion));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StreamConversionInterface::Hxx1::Fn<S>::ConvertImpl(const Block<const Generic>& src, WritableArrayInterface<Generic>& dst, Int dstLimitHint, Bool inputFinished, Bool& outputFinished) const -> Result<Int>
{
	HXXRETURN0(Result<Int>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(StreamConversionInterface_ConvertImpl); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.StreamConversionInterface_ConvertImpl_Offset), mt_.StreamConversionInterface_ConvertImpl, src, dst, dstLimitHint, inputFinished, outputFinished));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StreamConversionInterface::Hxx1::COWFn<S>::ConvertImpl(const Block<const Generic>& src, WritableArrayInterface<Generic>& dst, Int dstLimitHint, Bool inputFinished, Bool& outputFinished) -> Result<Int>
{
	HXXRETURN0(Result<Int>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(StreamConversionInterface_ConvertImpl); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.StreamConversionInterface_ConvertImpl_Offset), mt_.StreamConversionInterface_ConvertImpl, src, dst, dstLimitHint, inputFinished, outputFinished));
}
template <typename S> template <typename SRC, typename DST> MAXON_ATTRIBUTE_FORCE_INLINE auto StreamConversionInterface::Hxx1::Fn<S>::Convert(const SRC& src, DST& dst, Int dstLimitHint, Bool inputFinished, Bool& outputFinished) const -> Result<Int>
{
	HXXRETURN0(Result<Int>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) 
	return (o_->Convert<SRC, DST>(src, dst, dstLimitHint, inputFinished, outputFinished));
}
template <typename S> template <typename SRC, typename DST> MAXON_ATTRIBUTE_FORCE_INLINE auto StreamConversionInterface::Hxx1::COWFn<S>::Convert(const SRC& src, DST& dst, Int dstLimitHint, Bool inputFinished, Bool& outputFinished) -> Result<Int>
{
	HXXRETURN0(Result<Int>); HXXSUPER("StreamConversionInterface::Convert"); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) 
	return (o_->Convert<SRC, DST>(src, dst, dstLimitHint, inputFinished, outputFinished));
}
template <typename S> template <typename SRC, typename DST> MAXON_ATTRIBUTE_FORCE_INLINE auto StreamConversionInterface::Hxx1::Fn<S>::ConvertAll(const SRC& src, DST& dst, Int dstLimitHint) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) 
	return (o_->ConvertAll<SRC, DST>(src, dst, dstLimitHint));
}
template <typename S> template <typename SRC, typename DST> MAXON_ATTRIBUTE_FORCE_INLINE auto StreamConversionInterface::Hxx1::COWFn<S>::ConvertAll(const SRC& src, DST& dst, Int dstLimitHint) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXSUPER("StreamConversionInterface::ConvertAll"); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) 
	return (o_->ConvertAll<SRC, DST>(src, dst, dstLimitHint));
}
template <typename S> template <typename SRC> MAXON_ATTRIBUTE_FORCE_INLINE auto StreamConversionInterface::Hxx1::Fn<S>::ConvertAllInplace(const SRC& data) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) 
	return (o_->ConvertAllInplace<SRC>(data));
}
template <typename S> template <typename SRC> MAXON_ATTRIBUTE_FORCE_INLINE auto StreamConversionInterface::Hxx1::COWFn<S>::ConvertAllInplace(const SRC& data) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXSUPER("StreamConversionInterface::ConvertAllInplace"); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) 
	return (o_->ConvertAllInplace<SRC>(data));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StreamConversionInterface::Hxx1::Fn<S>::ConvertToStream(const InputStreamRef& in) const -> Result<InputStreamRef>
{
	HXXRETURN0(Result<InputStreamRef>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(StreamConversionInterface_ConvertToStream); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.StreamConversionInterface_ConvertToStream_Offset), mt_.StreamConversionInterface_ConvertToStream, in));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StreamConversionInterface::Hxx1::COWFn<S>::ConvertToStream(const InputStreamRef& in) -> Result<InputStreamRef>
{
	HXXRETURN0(Result<InputStreamRef>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(StreamConversionInterface_ConvertToStream); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.StreamConversionInterface_ConvertToStream_Offset), mt_.StreamConversionInterface_ConvertToStream, in));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StreamConversionInterface::Hxx1::Fn<S>::ConvertToStream(const DataFormatBaseReaderRef& in) const -> Result<InputStreamRef>
{
	HXXRETURN0(Result<InputStreamRef>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(StreamConversionInterface_ConvertToStream_1); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.StreamConversionInterface_ConvertToStream_1_Offset), mt_.StreamConversionInterface_ConvertToStream_1, in));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StreamConversionInterface::Hxx1::COWFn<S>::ConvertToStream(const DataFormatBaseReaderRef& in) -> Result<InputStreamRef>
{
	HXXRETURN0(Result<InputStreamRef>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(StreamConversionInterface_ConvertToStream_1); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.StreamConversionInterface_ConvertToStream_1_Offset), mt_.StreamConversionInterface_ConvertToStream_1, in));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StreamConversionInterface::Hxx1::Fn<S>::ConvertToReader(const InputStreamRef& in) const -> Result<DataFormatBaseReaderRef>
{
	HXXRETURN0(Result<DataFormatBaseReaderRef>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(StreamConversionInterface_ConvertToReader); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.StreamConversionInterface_ConvertToReader_Offset), mt_.StreamConversionInterface_ConvertToReader, in));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StreamConversionInterface::Hxx1::COWFn<S>::ConvertToReader(const InputStreamRef& in) -> Result<DataFormatBaseReaderRef>
{
	HXXRETURN0(Result<DataFormatBaseReaderRef>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(StreamConversionInterface_ConvertToReader); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.StreamConversionInterface_ConvertToReader_Offset), mt_.StreamConversionInterface_ConvertToReader, in));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StreamConversionInterface::Hxx1::Fn<S>::ConvertToReader(const DataFormatBaseReaderRef& in) const -> Result<DataFormatBaseReaderRef>
{
	HXXRETURN0(Result<DataFormatBaseReaderRef>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(StreamConversionInterface_ConvertToReader_1); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.StreamConversionInterface_ConvertToReader_1_Offset), mt_.StreamConversionInterface_ConvertToReader_1, in));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StreamConversionInterface::Hxx1::COWFn<S>::ConvertToReader(const DataFormatBaseReaderRef& in) -> Result<DataFormatBaseReaderRef>
{
	HXXRETURN0(Result<DataFormatBaseReaderRef>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(StreamConversionInterface_ConvertToReader_1); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.StreamConversionInterface_ConvertToReader_1_Offset), mt_.StreamConversionInterface_ConvertToReader_1, in));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StreamConversionInterface::Hxx1::Fn<S>::ConvertToStream(const OutputStreamRef& out) const -> Result<OutputStreamRef>
{
	HXXRETURN0(Result<OutputStreamRef>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(StreamConversionInterface_ConvertToStream_2); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.StreamConversionInterface_ConvertToStream_2_Offset), mt_.StreamConversionInterface_ConvertToStream_2, out));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StreamConversionInterface::Hxx1::COWFn<S>::ConvertToStream(const OutputStreamRef& out) -> Result<OutputStreamRef>
{
	HXXRETURN0(Result<OutputStreamRef>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(StreamConversionInterface_ConvertToStream_2); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.StreamConversionInterface_ConvertToStream_2_Offset), mt_.StreamConversionInterface_ConvertToStream_2, out));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StreamConversionInterface::Hxx1::Fn<S>::ConvertToStream(const DataFormatBaseWriterRef& out) const -> Result<OutputStreamRef>
{
	HXXRETURN0(Result<OutputStreamRef>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(StreamConversionInterface_ConvertToStream_3); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.StreamConversionInterface_ConvertToStream_3_Offset), mt_.StreamConversionInterface_ConvertToStream_3, out));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StreamConversionInterface::Hxx1::COWFn<S>::ConvertToStream(const DataFormatBaseWriterRef& out) -> Result<OutputStreamRef>
{
	HXXRETURN0(Result<OutputStreamRef>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(StreamConversionInterface_ConvertToStream_3); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.StreamConversionInterface_ConvertToStream_3_Offset), mt_.StreamConversionInterface_ConvertToStream_3, out));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StreamConversionInterface::Hxx1::Fn<S>::ConvertToWriter(const OutputStreamRef& out) const -> Result<DataFormatBaseWriterRef>
{
	HXXRETURN0(Result<DataFormatBaseWriterRef>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(StreamConversionInterface_ConvertToWriter); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.StreamConversionInterface_ConvertToWriter_Offset), mt_.StreamConversionInterface_ConvertToWriter, out));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StreamConversionInterface::Hxx1::COWFn<S>::ConvertToWriter(const OutputStreamRef& out) -> Result<DataFormatBaseWriterRef>
{
	HXXRETURN0(Result<DataFormatBaseWriterRef>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(StreamConversionInterface_ConvertToWriter); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.StreamConversionInterface_ConvertToWriter_Offset), mt_.StreamConversionInterface_ConvertToWriter, out));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StreamConversionInterface::Hxx1::Fn<S>::ConvertToWriter(const DataFormatBaseWriterRef& out) const -> Result<DataFormatBaseWriterRef>
{
	HXXRETURN0(Result<DataFormatBaseWriterRef>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(StreamConversionInterface_ConvertToWriter_1); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.StreamConversionInterface_ConvertToWriter_1_Offset), mt_.StreamConversionInterface_ConvertToWriter_1, out));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto StreamConversionInterface::Hxx1::COWFn<S>::ConvertToWriter(const DataFormatBaseWriterRef& out) -> Result<DataFormatBaseWriterRef>
{
	HXXRETURN0(Result<DataFormatBaseWriterRef>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(StreamConversionInterface_ConvertToWriter_1); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.StreamConversionInterface_ConvertToWriter_1_Offset), mt_.StreamConversionInterface_ConvertToWriter_1, out));
}
auto StreamConversionInterface::GetPtr() -> Ptr { return Ptr(this); }
auto StreamConversionInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_streamconversion)
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



#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1

struct MediaConverterInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(AddOutputStream);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Analyze);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Close);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Execute);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetInputConverter);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetOutputStreams);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(PrepareExecute);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(RemoveOutputStream);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(SupportExportStrategy);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(SupportImportStrategy);
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	Bool (*_MediaConverterInterface_SupportImportStrategy) (const maxon::GenericComponent* this_);
	maxon::Int _MediaConverterInterface_SupportImportStrategy_Offset;
	Bool (*_MediaConverterInterface_SupportExportStrategy) (const maxon::GenericComponent* this_);
	maxon::Int _MediaConverterInterface_SupportExportStrategy_Offset;
	Result<BaseArray<MediaConverterRef>> (*_MediaConverterInterface_GetInputConverter) (const maxon::GenericComponent* this_);
	maxon::Int _MediaConverterInterface_GetInputConverter_Offset;
	Result<void> (*_MediaConverterInterface_AddOutputStream) (maxon::GenericComponent* this_, const MediaStreamRef& stream);
	maxon::Int _MediaConverterInterface_AddOutputStream_Offset;
	Result<void> (*_MediaConverterInterface_RemoveOutputStream) (maxon::GenericComponent* this_, const MediaStreamRef& stream);
	maxon::Int _MediaConverterInterface_RemoveOutputStream_Offset;
	Result<BaseArray<MediaStreamRef>> (*_MediaConverterInterface_GetOutputStreams) (const maxon::GenericComponent* this_, Bool flattenChildren);
	maxon::Int _MediaConverterInterface_GetOutputStreams_Offset;
	Result<void> (*_MediaConverterInterface_Analyze) (maxon::GenericComponent* this_, const Block<const MediaConverterRef>& inputs, const TimeValue& targetTime, MEDIASESSIONFLAGS flags);
	maxon::Int _MediaConverterInterface_Analyze_Offset;
	Result<void> (*_MediaConverterInterface_PrepareExecute) (maxon::GenericComponent* this_, const Block<const MediaConverterRef>& inputs, const TimeValue& targetTime, MEDIASESSIONFLAGS flags);
	maxon::Int _MediaConverterInterface_PrepareExecute_Offset;
	Result<void> (*_MediaConverterInterface_Execute) (maxon::GenericComponent* this_, const Block<const MediaConverterRef>& inputs, const TimeValue& targetTime, MEDIASESSIONFLAGS flags);
	maxon::Int _MediaConverterInterface_Execute_Offset;
	Result<void> (*_MediaConverterInterface_Close) (maxon::GenericComponent* this_, const Block<const MediaConverterRef>& inputs);
	maxon::Int _MediaConverterInterface_Close_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaConverterInterface, SupportImportStrategy))
	{
		auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaConverterInterface, SupportImportStrategy), W, MTable>::type::_MediaConverterInterface_SupportImportStrategy;
		_MediaConverterInterface_SupportImportStrategy = reinterpret_cast<const decltype(_MediaConverterInterface_SupportImportStrategy)&>(ptr);
		_MediaConverterInterface_SupportImportStrategy_Offset = offset;
	}
	if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaConverterInterface, SupportExportStrategy))
	{
		auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaConverterInterface, SupportExportStrategy), W, MTable>::type::_MediaConverterInterface_SupportExportStrategy;
		_MediaConverterInterface_SupportExportStrategy = reinterpret_cast<const decltype(_MediaConverterInterface_SupportExportStrategy)&>(ptr);
		_MediaConverterInterface_SupportExportStrategy_Offset = offset;
	}
	if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaConverterInterface, GetInputConverter))
	{
		auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaConverterInterface, GetInputConverter), W, MTable>::type::_MediaConverterInterface_GetInputConverter;
		_MediaConverterInterface_GetInputConverter = reinterpret_cast<const decltype(_MediaConverterInterface_GetInputConverter)&>(ptr);
		_MediaConverterInterface_GetInputConverter_Offset = offset;
	}
	if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaConverterInterface, AddOutputStream))
	{
		auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaConverterInterface, AddOutputStream), W, MTable>::type::_MediaConverterInterface_AddOutputStream;
		_MediaConverterInterface_AddOutputStream = reinterpret_cast<const decltype(_MediaConverterInterface_AddOutputStream)&>(ptr);
		_MediaConverterInterface_AddOutputStream_Offset = offset;
	}
	if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaConverterInterface, RemoveOutputStream))
	{
		auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaConverterInterface, RemoveOutputStream), W, MTable>::type::_MediaConverterInterface_RemoveOutputStream;
		_MediaConverterInterface_RemoveOutputStream = reinterpret_cast<const decltype(_MediaConverterInterface_RemoveOutputStream)&>(ptr);
		_MediaConverterInterface_RemoveOutputStream_Offset = offset;
	}
	if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaConverterInterface, GetOutputStreams))
	{
		auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaConverterInterface, GetOutputStreams), W, MTable>::type::_MediaConverterInterface_GetOutputStreams;
		_MediaConverterInterface_GetOutputStreams = reinterpret_cast<const decltype(_MediaConverterInterface_GetOutputStreams)&>(ptr);
		_MediaConverterInterface_GetOutputStreams_Offset = offset;
	}
	if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaConverterInterface, Analyze))
	{
		auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaConverterInterface, Analyze), W, MTable>::type::_MediaConverterInterface_Analyze;
		_MediaConverterInterface_Analyze = reinterpret_cast<const decltype(_MediaConverterInterface_Analyze)&>(ptr);
		_MediaConverterInterface_Analyze_Offset = offset;
	}
	if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaConverterInterface, PrepareExecute))
	{
		auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaConverterInterface, PrepareExecute), W, MTable>::type::_MediaConverterInterface_PrepareExecute;
		_MediaConverterInterface_PrepareExecute = reinterpret_cast<const decltype(_MediaConverterInterface_PrepareExecute)&>(ptr);
		_MediaConverterInterface_PrepareExecute_Offset = offset;
	}
	if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaConverterInterface, Execute))
	{
		auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaConverterInterface, Execute), W, MTable>::type::_MediaConverterInterface_Execute;
		_MediaConverterInterface_Execute = reinterpret_cast<const decltype(_MediaConverterInterface_Execute)&>(ptr);
		_MediaConverterInterface_Execute_Offset = offset;
	}
	if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaConverterInterface, Close))
	{
		auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaConverterInterface, Close), W, MTable>::type::_MediaConverterInterface_Close;
		_MediaConverterInterface_Close = reinterpret_cast<const decltype(_MediaConverterInterface_Close)&>(ptr);
		_MediaConverterInterface_Close_Offset = offset;
	}
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!MediaBaseInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset);
		return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<MediaConverterInterface, typename MediaBaseInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<MediaConverterInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct MediaConverterInterface::Hxx2
{
	template <typename S> class CWrapper : public MediaBaseInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(AddOutputStream);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Analyze);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Close);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Execute);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetInputConverter);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetOutputStreams);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(PrepareExecute);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(RemoveOutputStream);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(SupportExportStrategy);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(SupportImportStrategy);
		static Bool _MediaConverterInterface_SupportImportStrategy(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->SupportImportStrategy(); }
		static Bool _MediaConverterInterface_SupportExportStrategy(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->SupportExportStrategy(); }
		static Result<BaseArray<MediaConverterRef>> _MediaConverterInterface_GetInputConverter(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetInputConverter(); }
		static Result<void> _MediaConverterInterface_AddOutputStream(maxon::GenericComponent* this_, const MediaStreamRef& stream) { return ((typename S::Implementation*) this_)->AddOutputStream(stream); }
		static Result<void> _MediaConverterInterface_RemoveOutputStream(maxon::GenericComponent* this_, const MediaStreamRef& stream) { return ((typename S::Implementation*) this_)->RemoveOutputStream(stream); }
		static Result<BaseArray<MediaStreamRef>> _MediaConverterInterface_GetOutputStreams(const maxon::GenericComponent* this_, Bool flattenChildren) { return ((const typename S::Implementation*) this_)->GetOutputStreams(flattenChildren); }
		static Result<void> _MediaConverterInterface_Analyze(maxon::GenericComponent* this_, const Block<const MediaConverterRef>& inputs, const TimeValue& targetTime, MEDIASESSIONFLAGS flags) { return ((typename S::Implementation*) this_)->Analyze(inputs, targetTime, flags); }
		static Result<void> _MediaConverterInterface_PrepareExecute(maxon::GenericComponent* this_, const Block<const MediaConverterRef>& inputs, const TimeValue& targetTime, MEDIASESSIONFLAGS flags) { return ((typename S::Implementation*) this_)->PrepareExecute(inputs, targetTime, flags); }
		static Result<void> _MediaConverterInterface_Execute(maxon::GenericComponent* this_, const Block<const MediaConverterRef>& inputs, const TimeValue& targetTime, MEDIASESSIONFLAGS flags) { return ((typename S::Implementation*) this_)->Execute(inputs, targetTime, flags); }
		static Result<void> _MediaConverterInterface_Close(maxon::GenericComponent* this_, const Block<const MediaConverterRef>& inputs) { return ((typename S::Implementation*) this_)->Close(inputs); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaConverterInterface::SupportImportStrategy() const -> Bool
{
	const MediaConverterInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaConverterInterface, this); return mt_._MediaConverterInterface_SupportImportStrategy((const maxon::GenericComponent*) this + mt_._MediaConverterInterface_SupportImportStrategy_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaConverterInterface::SupportExportStrategy() const -> Bool
{
	const MediaConverterInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaConverterInterface, this); return mt_._MediaConverterInterface_SupportExportStrategy((const maxon::GenericComponent*) this + mt_._MediaConverterInterface_SupportExportStrategy_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaConverterInterface::GetInputConverter() const -> Result<BaseArray<MediaConverterRef>>
{
	const MediaConverterInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaConverterInterface, this); return mt_._MediaConverterInterface_GetInputConverter((const maxon::GenericComponent*) this + mt_._MediaConverterInterface_GetInputConverter_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaConverterInterface::AddOutputStream(const MediaStreamRef& stream) -> Result<void>
{
	const MediaConverterInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaConverterInterface, this); return mt_._MediaConverterInterface_AddOutputStream((maxon::GenericComponent*) this + mt_._MediaConverterInterface_AddOutputStream_Offset, stream);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaConverterInterface::RemoveOutputStream(const MediaStreamRef& stream) -> Result<void>
{
	const MediaConverterInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaConverterInterface, this); return mt_._MediaConverterInterface_RemoveOutputStream((maxon::GenericComponent*) this + mt_._MediaConverterInterface_RemoveOutputStream_Offset, stream);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaConverterInterface::GetOutputStreams(Bool flattenChildren) const -> Result<BaseArray<MediaStreamRef>>
{
	const MediaConverterInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaConverterInterface, this); return mt_._MediaConverterInterface_GetOutputStreams((const maxon::GenericComponent*) this + mt_._MediaConverterInterface_GetOutputStreams_Offset, flattenChildren);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaConverterInterface::Analyze(const Block<const MediaConverterRef>& inputs, const TimeValue& targetTime, MEDIASESSIONFLAGS flags) -> Result<void>
{
	const MediaConverterInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaConverterInterface, this); return mt_._MediaConverterInterface_Analyze((maxon::GenericComponent*) this + mt_._MediaConverterInterface_Analyze_Offset, inputs, targetTime, flags);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaConverterInterface::PrepareExecute(const Block<const MediaConverterRef>& inputs, const TimeValue& targetTime, MEDIASESSIONFLAGS flags) -> Result<void>
{
	const MediaConverterInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaConverterInterface, this); return mt_._MediaConverterInterface_PrepareExecute((maxon::GenericComponent*) this + mt_._MediaConverterInterface_PrepareExecute_Offset, inputs, targetTime, flags);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaConverterInterface::Execute(const Block<const MediaConverterRef>& inputs, const TimeValue& targetTime, MEDIASESSIONFLAGS flags) -> Result<void>
{
	const MediaConverterInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaConverterInterface, this); return mt_._MediaConverterInterface_Execute((maxon::GenericComponent*) this + mt_._MediaConverterInterface_Execute_Offset, inputs, targetTime, flags);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaConverterInterface::Close(const Block<const MediaConverterRef>& inputs) -> Result<void>
{
	const MediaConverterInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaConverterInterface, this); return mt_._MediaConverterInterface_Close((maxon::GenericComponent*) this + mt_._MediaConverterInterface_Close_Offset, inputs);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaConverterInterface::Hxx1::ConstReferenceFunctionsImpl<S>::SupportImportStrategy() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const MediaConverterInterface* o_ = (const MediaConverterInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = MediaConverterInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaConverterInterface, o_, MediaConverterInterface_SupportImportStrategy) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MediaConverterInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaConverterInterface>() : PRIVATE_MAXON_VTABLE(MediaConverterInterface, o_); 
	return (mt_._MediaConverterInterface_SupportImportStrategy(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._MediaConverterInterface_SupportImportStrategy_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaConverterInterface::Hxx1::ConstReferenceFunctionsImpl<S>::SupportExportStrategy() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const MediaConverterInterface* o_ = (const MediaConverterInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = MediaConverterInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaConverterInterface, o_, MediaConverterInterface_SupportExportStrategy) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MediaConverterInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaConverterInterface>() : PRIVATE_MAXON_VTABLE(MediaConverterInterface, o_); 
	return (mt_._MediaConverterInterface_SupportExportStrategy(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._MediaConverterInterface_SupportExportStrategy_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaConverterInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetInputConverter() const -> Result<BaseArray<MediaConverterRef>>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<BaseArray<MediaConverterRef>>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const MediaConverterInterface* o_ = (const MediaConverterInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = MediaConverterInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaConverterInterface, o_, MediaConverterInterface_GetInputConverter) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MediaConverterInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaConverterInterface>() : PRIVATE_MAXON_VTABLE(MediaConverterInterface, o_); 
	return (mt_._MediaConverterInterface_GetInputConverter(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._MediaConverterInterface_GetInputConverter_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaConverterInterface::Hxx1::ReferenceFunctionsImpl<S>::AddOutputStream(const MediaStreamRef& stream) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MediaConverterInterface* o_ = (MediaConverterInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaConverterInterface, o_, MediaConverterInterface_AddOutputStream) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MediaConverterInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaConverterInterface>() : PRIVATE_MAXON_VTABLE(MediaConverterInterface, o_); 
	return (mt_._MediaConverterInterface_AddOutputStream(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._MediaConverterInterface_AddOutputStream_Offset, stream));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaConverterInterface::Hxx1::COWReferenceFunctionsImpl<S>::AddOutputStream(const MediaStreamRef& stream) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MediaConverterInterface* o_ = (MediaConverterInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaConverterInterface, o_, MediaConverterInterface_AddOutputStream) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MediaConverterInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaConverterInterface>() : PRIVATE_MAXON_VTABLE(MediaConverterInterface, o_); 
	return (mt_._MediaConverterInterface_AddOutputStream(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._MediaConverterInterface_AddOutputStream_Offset, stream));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaConverterInterface::Hxx1::ReferenceFunctionsImpl<S>::RemoveOutputStream(const MediaStreamRef& stream) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MediaConverterInterface* o_ = (MediaConverterInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaConverterInterface, o_, MediaConverterInterface_RemoveOutputStream) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MediaConverterInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaConverterInterface>() : PRIVATE_MAXON_VTABLE(MediaConverterInterface, o_); 
	return (mt_._MediaConverterInterface_RemoveOutputStream(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._MediaConverterInterface_RemoveOutputStream_Offset, stream));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaConverterInterface::Hxx1::COWReferenceFunctionsImpl<S>::RemoveOutputStream(const MediaStreamRef& stream) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MediaConverterInterface* o_ = (MediaConverterInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaConverterInterface, o_, MediaConverterInterface_RemoveOutputStream) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MediaConverterInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaConverterInterface>() : PRIVATE_MAXON_VTABLE(MediaConverterInterface, o_); 
	return (mt_._MediaConverterInterface_RemoveOutputStream(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._MediaConverterInterface_RemoveOutputStream_Offset, stream));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaConverterInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetOutputStreams(Bool flattenChildren) const -> Result<BaseArray<MediaStreamRef>>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<BaseArray<MediaStreamRef>>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const MediaConverterInterface* o_ = (const MediaConverterInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = MediaConverterInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaConverterInterface, o_, MediaConverterInterface_GetOutputStreams) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MediaConverterInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaConverterInterface>() : PRIVATE_MAXON_VTABLE(MediaConverterInterface, o_); 
	return (mt_._MediaConverterInterface_GetOutputStreams(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._MediaConverterInterface_GetOutputStreams_Offset, flattenChildren));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaConverterInterface::Hxx1::ReferenceFunctionsImpl<S>::Analyze(const Block<const MediaConverterRef>& inputs, const TimeValue& targetTime, MEDIASESSIONFLAGS flags) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MediaConverterInterface* o_ = (MediaConverterInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaConverterInterface, o_, MediaConverterInterface_Analyze) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MediaConverterInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaConverterInterface>() : PRIVATE_MAXON_VTABLE(MediaConverterInterface, o_); 
	return (mt_._MediaConverterInterface_Analyze(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._MediaConverterInterface_Analyze_Offset, inputs, targetTime, flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaConverterInterface::Hxx1::COWReferenceFunctionsImpl<S>::Analyze(const Block<const MediaConverterRef>& inputs, const TimeValue& targetTime, MEDIASESSIONFLAGS flags) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MediaConverterInterface* o_ = (MediaConverterInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaConverterInterface, o_, MediaConverterInterface_Analyze) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MediaConverterInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaConverterInterface>() : PRIVATE_MAXON_VTABLE(MediaConverterInterface, o_); 
	return (mt_._MediaConverterInterface_Analyze(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._MediaConverterInterface_Analyze_Offset, inputs, targetTime, flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaConverterInterface::Hxx1::ReferenceFunctionsImpl<S>::PrepareExecute(const Block<const MediaConverterRef>& inputs, const TimeValue& targetTime, MEDIASESSIONFLAGS flags) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MediaConverterInterface* o_ = (MediaConverterInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaConverterInterface, o_, MediaConverterInterface_PrepareExecute) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MediaConverterInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaConverterInterface>() : PRIVATE_MAXON_VTABLE(MediaConverterInterface, o_); 
	return (mt_._MediaConverterInterface_PrepareExecute(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._MediaConverterInterface_PrepareExecute_Offset, inputs, targetTime, flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaConverterInterface::Hxx1::COWReferenceFunctionsImpl<S>::PrepareExecute(const Block<const MediaConverterRef>& inputs, const TimeValue& targetTime, MEDIASESSIONFLAGS flags) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MediaConverterInterface* o_ = (MediaConverterInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaConverterInterface, o_, MediaConverterInterface_PrepareExecute) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MediaConverterInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaConverterInterface>() : PRIVATE_MAXON_VTABLE(MediaConverterInterface, o_); 
	return (mt_._MediaConverterInterface_PrepareExecute(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._MediaConverterInterface_PrepareExecute_Offset, inputs, targetTime, flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaConverterInterface::Hxx1::ReferenceFunctionsImpl<S>::Execute(const Block<const MediaConverterRef>& inputs, const TimeValue& targetTime, MEDIASESSIONFLAGS flags) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MediaConverterInterface* o_ = (MediaConverterInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaConverterInterface, o_, MediaConverterInterface_Execute) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MediaConverterInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaConverterInterface>() : PRIVATE_MAXON_VTABLE(MediaConverterInterface, o_); 
	return (mt_._MediaConverterInterface_Execute(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._MediaConverterInterface_Execute_Offset, inputs, targetTime, flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaConverterInterface::Hxx1::COWReferenceFunctionsImpl<S>::Execute(const Block<const MediaConverterRef>& inputs, const TimeValue& targetTime, MEDIASESSIONFLAGS flags) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MediaConverterInterface* o_ = (MediaConverterInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaConverterInterface, o_, MediaConverterInterface_Execute) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MediaConverterInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaConverterInterface>() : PRIVATE_MAXON_VTABLE(MediaConverterInterface, o_); 
	return (mt_._MediaConverterInterface_Execute(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._MediaConverterInterface_Execute_Offset, inputs, targetTime, flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaConverterInterface::Hxx1::ReferenceFunctionsImpl<S>::Close(const Block<const MediaConverterRef>& inputs) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MediaConverterInterface* o_ = (MediaConverterInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaConverterInterface, o_, MediaConverterInterface_Close) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MediaConverterInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaConverterInterface>() : PRIVATE_MAXON_VTABLE(MediaConverterInterface, o_); 
	return (mt_._MediaConverterInterface_Close(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._MediaConverterInterface_Close_Offset, inputs));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaConverterInterface::Hxx1::COWReferenceFunctionsImpl<S>::Close(const Block<const MediaConverterRef>& inputs) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MediaConverterInterface* o_ = (MediaConverterInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaConverterInterface, o_, MediaConverterInterface_Close) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MediaConverterInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaConverterInterface>() : PRIVATE_MAXON_VTABLE(MediaConverterInterface, o_); 
	return (mt_._MediaConverterInterface_Close(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._MediaConverterInterface_Close_Offset, inputs));
}
auto MediaConverterInterface::GetPtr() -> Ptr { return Ptr(this); }
auto MediaConverterInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_MediaConverterInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_MediaConverterInterface() { new (s_ui_maxon_MediaConverterInterface) maxon::EntityUse(MediaConverterInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/mediasession_converter.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_MediaConverterInterface(MediaConverterInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/mediasession_converter.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif

struct MediaConverterErrorInterface::MTable
{
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!ErrorInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<MediaConverterErrorInterface, typename ErrorInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<MediaConverterErrorInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct MediaConverterErrorInterface::Hxx2
{
	template <typename S> using CWrapper = typename ErrorInterface::Hxx2::template CWrapper<S>;
};

auto MediaConverterErrorInterface::GetPtr() -> Ptr { return Ptr(this); }
auto MediaConverterErrorInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_MediaConverterErrorInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_MediaConverterErrorInterface() { new (s_ui_maxon_MediaConverterErrorInterface) maxon::EntityUse(MediaConverterErrorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/mediasession_converter.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_MediaConverterErrorInterface(MediaConverterErrorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/mediasession_converter.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif


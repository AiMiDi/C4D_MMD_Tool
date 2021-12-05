
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1

struct LayerSetInterface::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = true;
	void (*_LayerSetInterface_Free) (const LayerSetInterface* object);
	LayerSetInterface* (*_LayerSetInterface_Alloc) (const maxon::SourceLocation& allocLocation);
	LayerSetInterface* (*_LayerSetInterface_Alloc_1) (const maxon::SourceLocation& allocLocation, const LayerSetInterface& object);
	Result<void> (*_LayerSetInterface_SetSelectedLayers) (LayerSetInterface* this_, const LayerHash& layers);
	const LayerHash& (*_LayerSetInterface_GetSelectedLayers) (const LayerSetInterface* this_);
	void (*_LayerSetInterface_SetSelectedImage) (LayerSetInterface* this_, const String& image);
	String (*_LayerSetInterface_GetSelectedImage) (const LayerSetInterface* this_);
	void (*_LayerSetInterface_SetMode) (LayerSetInterface* this_, LAYERSETMODE mode);
	LAYERSETMODE (*_LayerSetInterface_GetMode) (const LayerSetInterface* this_);
	void (*_LayerSetInterface_SetCalculateAlpha) (LayerSetInterface* this_, Bool calcAlpha);
	Bool (*_LayerSetInterface_GetCalculateAlpha) (const LayerSetInterface* this_);
	Bool (*_LayerSetInterface_IsEqual) (const LayerSetInterface* this_, const LayerSetInterface* other);
	UInt (*_LayerSetInterface_GetHashCode) (const LayerSetInterface* this_);
	Result<void> (*_LayerSetInterface_DescribeIO) (const DataSerializeInterface& stream);
	template <typename IMPL> void Init()
	{
		_LayerSetInterface_Free = &IMPL::_LayerSetInterface_Free;
		_LayerSetInterface_Alloc = &IMPL::_LayerSetInterface_Alloc;
		_LayerSetInterface_Alloc_1 = &IMPL::_LayerSetInterface_Alloc_1;
		_LayerSetInterface_SetSelectedLayers = &IMPL::_LayerSetInterface_SetSelectedLayers;
		_LayerSetInterface_GetSelectedLayers = &IMPL::_LayerSetInterface_GetSelectedLayers;
		_LayerSetInterface_SetSelectedImage = &IMPL::_LayerSetInterface_SetSelectedImage;
		_LayerSetInterface_GetSelectedImage = &IMPL::_LayerSetInterface_GetSelectedImage;
		_LayerSetInterface_SetMode = &IMPL::_LayerSetInterface_SetMode;
		_LayerSetInterface_GetMode = &IMPL::_LayerSetInterface_GetMode;
		_LayerSetInterface_SetCalculateAlpha = &IMPL::_LayerSetInterface_SetCalculateAlpha;
		_LayerSetInterface_GetCalculateAlpha = &IMPL::_LayerSetInterface_GetCalculateAlpha;
		_LayerSetInterface_IsEqual = &IMPL::_LayerSetInterface_IsEqual;
		_LayerSetInterface_GetHashCode = &IMPL::_LayerSetInterface_GetHashCode;
		_LayerSetInterface_DescribeIO = &IMPL::_LayerSetInterface_DescribeIO;
	}
};

struct LayerSetInterface::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
	static void _LayerSetInterface_Free(const LayerSetInterface* object) { return C::Free(object); }
	static LayerSetInterface* _LayerSetInterface_Alloc(const maxon::SourceLocation& allocLocation) { return C::Alloc(allocLocation); }
	static LayerSetInterface* _LayerSetInterface_Alloc_1(const maxon::SourceLocation& allocLocation, const LayerSetInterface& object) { return C::Alloc(allocLocation, ((const C&) object)); }
	static Result<void> _LayerSetInterface_SetSelectedLayers(LayerSetInterface* this_, const LayerHash& layers) { return ((C*) this_)->SetSelectedLayers(layers); }
	static const LayerHash& _LayerSetInterface_GetSelectedLayers(const LayerSetInterface* this_) { return ((const C*) this_)->GetSelectedLayers(); }
	static void _LayerSetInterface_SetSelectedImage(LayerSetInterface* this_, const String& image) { return ((C*) this_)->SetSelectedImage(image); }
	static String _LayerSetInterface_GetSelectedImage(const LayerSetInterface* this_) { return ((const C*) this_)->GetSelectedImage(); }
	static void _LayerSetInterface_SetMode(LayerSetInterface* this_, LAYERSETMODE mode) { return ((C*) this_)->SetMode(mode); }
	static LAYERSETMODE _LayerSetInterface_GetMode(const LayerSetInterface* this_) { return ((const C*) this_)->GetMode(); }
	static void _LayerSetInterface_SetCalculateAlpha(LayerSetInterface* this_, Bool calcAlpha) { return ((C*) this_)->SetCalculateAlpha(calcAlpha); }
	static Bool _LayerSetInterface_GetCalculateAlpha(const LayerSetInterface* this_) { return ((const C*) this_)->GetCalculateAlpha(); }
	static Bool _LayerSetInterface_IsEqual(const LayerSetInterface* this_, const LayerSetInterface* other) { return ((const C*) this_)->IsEqual(other); }
	static UInt _LayerSetInterface_GetHashCode(const LayerSetInterface* this_) { return ((const C*) this_)->GetHashCode(); }
	static Result<void> _LayerSetInterface_DescribeIO(const DataSerializeInterface& stream) { return C::DescribeIO(stream); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto LayerSetInterface::Free(const LayerSetInterface* object) -> void
{
	return MTable::_instance._LayerSetInterface_Free(object);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LayerSetInterface::Alloc(const maxon::SourceLocation& allocLocation) -> LayerSetInterface*
{
	return MTable::_instance._LayerSetInterface_Alloc(allocLocation);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LayerSetInterface::Alloc(const maxon::SourceLocation& allocLocation, const LayerSetInterface& object) -> LayerSetInterface*
{
	return MTable::_instance._LayerSetInterface_Alloc_1(allocLocation, object);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LayerSetInterface::SetSelectedLayers(const LayerHash& layers) -> Result<void>
{
	return MTable::_instance._LayerSetInterface_SetSelectedLayers(this, layers);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LayerSetInterface::GetSelectedLayers() const -> const LayerHash&
{
	return MTable::_instance._LayerSetInterface_GetSelectedLayers(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LayerSetInterface::SetSelectedImage(const String& image) -> void
{
	return MTable::_instance._LayerSetInterface_SetSelectedImage(this, image);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LayerSetInterface::GetSelectedImage() const -> String
{
	return MTable::_instance._LayerSetInterface_GetSelectedImage(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LayerSetInterface::SetMode(LAYERSETMODE mode) -> void
{
	return MTable::_instance._LayerSetInterface_SetMode(this, mode);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LayerSetInterface::GetMode() const -> LAYERSETMODE
{
	return MTable::_instance._LayerSetInterface_GetMode(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LayerSetInterface::SetCalculateAlpha(Bool calcAlpha) -> void
{
	return MTable::_instance._LayerSetInterface_SetCalculateAlpha(this, calcAlpha);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LayerSetInterface::GetCalculateAlpha() const -> Bool
{
	return MTable::_instance._LayerSetInterface_GetCalculateAlpha(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LayerSetInterface::IsEqual(const LayerSetInterface* other) const -> Bool
{
	return MTable::_instance._LayerSetInterface_IsEqual(this, other);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LayerSetInterface::GetHashCode() const -> UInt
{
	return MTable::_instance._LayerSetInterface_GetHashCode(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LayerSetInterface::DescribeIO(const DataSerializeInterface& stream) -> Result<void>
{
	return MTable::_instance._LayerSetInterface_DescribeIO(stream);
}

auto LayerSetInterface::Hxx1::Reference::Create() -> maxon::ResultMemT<LayerSet>
{
	LayerSetInterface* res_ = LayerSetInterface::Alloc(MAXON_SOURCE_LOCATION);
	return LayerSet(maxon::ForwardResultPtr<LayerSetInterface>(res_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LayerSetInterface::Hxx1::ReferenceFunctionsImpl<S>::SetSelectedLayers(const LayerHash& layers) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); LayerSetInterface* o_ = (LayerSetInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance._LayerSetInterface_SetSelectedLayers(o_, layers));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LayerSetInterface::Hxx1::COWReferenceFunctionsImpl<S>::SetSelectedLayers(const LayerHash& layers) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); LayerSetInterface* o_ = (LayerSetInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (MTable::_instance._LayerSetInterface_SetSelectedLayers(o_, layers));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LayerSetInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetSelectedLayers() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const LayerHash&>, const LayerHash&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const LayerHash&>, const LayerHash&>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const LayerSetInterface* o_ = (const LayerSetInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = LayerSetInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const LayerHash&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance._LayerSetInterface_GetSelectedLayers(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LayerSetInterface::Hxx1::ReferenceFunctionsImpl<S>::SetSelectedImage(const String& image) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); LayerSetInterface* o_ = (LayerSetInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } 
	MTable::_instance._LayerSetInterface_SetSelectedImage(o_, image);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LayerSetInterface::Hxx1::COWReferenceFunctionsImpl<S>::SetSelectedImage(const String& image) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); LayerSetInterface* o_ = (LayerSetInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	MTable::_instance._LayerSetInterface_SetSelectedImage(o_, image);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LayerSetInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetSelectedImage() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const LayerSetInterface* o_ = (const LayerSetInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = LayerSetInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance._LayerSetInterface_GetSelectedImage(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LayerSetInterface::Hxx1::ReferenceFunctionsImpl<S>::SetMode(LAYERSETMODE mode) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); LayerSetInterface* o_ = (LayerSetInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } 
	MTable::_instance._LayerSetInterface_SetMode(o_, mode);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LayerSetInterface::Hxx1::COWReferenceFunctionsImpl<S>::SetMode(LAYERSETMODE mode) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); LayerSetInterface* o_ = (LayerSetInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	MTable::_instance._LayerSetInterface_SetMode(o_, mode);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LayerSetInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetMode() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<LAYERSETMODE>, LAYERSETMODE>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<LAYERSETMODE>, LAYERSETMODE>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const LayerSetInterface* o_ = (const LayerSetInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = LayerSetInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<LAYERSETMODE>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance._LayerSetInterface_GetMode(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LayerSetInterface::Hxx1::ReferenceFunctionsImpl<S>::SetCalculateAlpha(Bool calcAlpha) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); LayerSetInterface* o_ = (LayerSetInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } 
	MTable::_instance._LayerSetInterface_SetCalculateAlpha(o_, calcAlpha);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LayerSetInterface::Hxx1::COWReferenceFunctionsImpl<S>::SetCalculateAlpha(Bool calcAlpha) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); LayerSetInterface* o_ = (LayerSetInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	MTable::_instance._LayerSetInterface_SetCalculateAlpha(o_, calcAlpha);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LayerSetInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetCalculateAlpha() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const LayerSetInterface* o_ = (const LayerSetInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = LayerSetInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (MTable::_instance._LayerSetInterface_GetCalculateAlpha(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LayerSetInterface::Hxx1::ConstReferenceFunctionsImpl<S>::IsEqual(const LayerSetInterface* other) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const LayerSetInterface* o_ = (const LayerSetInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = LayerSetInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (MTable::_instance._LayerSetInterface_IsEqual(o_, other));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LayerSetInterface::Hxx1::ReferenceFunctionsImpl<S>::FlushLayers() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); LayerSetInterface* o_ = (LayerSetInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } 
	o_->FlushLayers();
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LayerSetInterface::Hxx1::COWReferenceFunctionsImpl<S>::FlushLayers() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); LayerSetInterface* o_ = (LayerSetInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	o_->FlushLayers();
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LayerSetInterface::Hxx1::ConstReferenceFunctionsImpl<S>::HasLayerSelection() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const LayerSetInterface* o_ = (const LayerSetInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = LayerSetInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->HasLayerSelection());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LayerSetInterface::Hxx1::ConstReferenceFunctionsImpl<S>::IsLayerEnabled(const String& name) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const LayerSetInterface* o_ = (const LayerSetInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = LayerSetInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->IsLayerEnabled(name));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LayerSetInterface::Hxx1::ConstReferenceFunctionsImpl<S>::HasMultiImageSelection() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const LayerSetInterface* o_ = (const LayerSetInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = LayerSetInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->HasMultiImageSelection());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LayerSetInterface::Hxx1::ConstReferenceFunctionsImpl<S>::IsMultiImageEnabled(const String& name) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const LayerSetInterface* o_ = (const LayerSetInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = LayerSetInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->IsMultiImageEnabled(name));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LayerSetInterface::Hxx1::ReferenceFunctionsImpl<S>::RemoveLayer(const String& layer) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); LayerSetInterface* o_ = (LayerSetInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->RemoveLayer(layer));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LayerSetInterface::Hxx1::COWReferenceFunctionsImpl<S>::RemoveLayer(const String& layer) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); LayerSetInterface* o_ = (LayerSetInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (o_->RemoveLayer(layer));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LayerSetInterface::Hxx1::ReferenceFunctionsImpl<S>::AddLayer(const String& layer) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); LayerSetInterface* o_ = (LayerSetInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->AddLayer(layer));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LayerSetInterface::Hxx1::COWReferenceFunctionsImpl<S>::AddLayer(const String& layer) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); LayerSetInterface* o_ = (LayerSetInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (o_->AddLayer(layer));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LayerSetInterface::Hxx1::ConstReferenceFunctionsImpl<S>::DescribeIO(const DataSerializeInterface& stream) -> Result<void> { return (MTable::_instance._LayerSetInterface_DescribeIO(stream)); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_LayerSetInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_LayerSetInterface() { new (s_ui_maxon_LayerSetInterface) maxon::EntityUse(LayerSetInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/layerset.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_LayerSetInterface(LayerSetInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/layerset.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif


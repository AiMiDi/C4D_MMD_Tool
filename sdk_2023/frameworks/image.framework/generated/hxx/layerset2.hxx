
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1
constexpr const maxon::Char* LayerSetInterface::PrivateGetCppName() { return "maxon::LayerSet"; }

struct LayerSetInterface::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = true;
	PRIVATE_MAXON_SF_POINTER(LayerSetInterface_Free, Free, MAXON_EXPAND_VA_ARGS, (void), const LayerSetInterface* object);
	PRIVATE_MAXON_SF_POINTER(LayerSetInterface_Alloc, Alloc, MAXON_IGNORE_VA_ARGS, (LayerSetInterface*), const maxon::SourceLocation& allocLocation);
	PRIVATE_MAXON_SF_POINTER(LayerSetInterface_Alloc_1, Alloc, MAXON_IGNORE_VA_ARGS, (LayerSetInterface*), const maxon::SourceLocation& allocLocation, const LayerSetInterface& object);
	PRIVATE_MAXON_MF_POINTER(LayerSetInterface_SetSelectedLayers, SetSelectedLayers, false, LayerSetInterface,, (Result<void>), const LayerHash& layers);
	PRIVATE_MAXON_MF_POINTER(LayerSetInterface_GetSelectedLayers, GetSelectedLayers, false, LayerSetInterface, const, (const LayerHash&));
	PRIVATE_MAXON_MF_POINTER(LayerSetInterface_SetSelectedImage, SetSelectedImage, false, LayerSetInterface,, (void), const String& image);
	PRIVATE_MAXON_MF_POINTER(LayerSetInterface_GetSelectedImage, GetSelectedImage, false, LayerSetInterface, const, (String));
	PRIVATE_MAXON_MF_POINTER(LayerSetInterface_SetMode, SetMode, false, LayerSetInterface,, (void), LAYERSETMODE mode);
	PRIVATE_MAXON_MF_POINTER(LayerSetInterface_GetMode, GetMode, false, LayerSetInterface, const, (LAYERSETMODE));
	PRIVATE_MAXON_MF_POINTER(LayerSetInterface_SetCalculateAlpha, SetCalculateAlpha, false, LayerSetInterface,, (void), Bool calcAlpha);
	PRIVATE_MAXON_MF_POINTER(LayerSetInterface_GetCalculateAlpha, GetCalculateAlpha, false, LayerSetInterface, const, (Bool));
	PRIVATE_MAXON_MF_POINTER(LayerSetInterface_IsEqual, IsEqual, false, LayerSetInterface, const, (Bool), const LayerSetInterface* other);
	PRIVATE_MAXON_MF_POINTER(LayerSetInterface_GetHashCode, GetHashCode, false, LayerSetInterface, const, (HashInt));
	PRIVATE_MAXON_SF_POINTER(LayerSetInterface_DescribeIO, DescribeIO, MAXON_EXPAND_VA_ARGS, (Result<void>), const DataSerializeInterface& stream);
	template <typename IMPL> void Init()
	{
		LayerSetInterface_Free = LayerSetInterface_Free_GetPtr<IMPL>(true);
		LayerSetInterface_Alloc = LayerSetInterface_Alloc_GetPtr<IMPL>(true);
		LayerSetInterface_Alloc_1 = LayerSetInterface_Alloc_1_GetPtr<IMPL>(true);
		LayerSetInterface_SetSelectedLayers = LayerSetInterface_SetSelectedLayers_GetPtr<IMPL>(0, true).first;
		LayerSetInterface_GetSelectedLayers = LayerSetInterface_GetSelectedLayers_GetPtr<IMPL>(0, true).first;
		LayerSetInterface_SetSelectedImage = LayerSetInterface_SetSelectedImage_GetPtr<IMPL>(0, true).first;
		LayerSetInterface_GetSelectedImage = LayerSetInterface_GetSelectedImage_GetPtr<IMPL>(0, true).first;
		LayerSetInterface_SetMode = LayerSetInterface_SetMode_GetPtr<IMPL>(0, true).first;
		LayerSetInterface_GetMode = LayerSetInterface_GetMode_GetPtr<IMPL>(0, true).first;
		LayerSetInterface_SetCalculateAlpha = LayerSetInterface_SetCalculateAlpha_GetPtr<IMPL>(0, true).first;
		LayerSetInterface_GetCalculateAlpha = LayerSetInterface_GetCalculateAlpha_GetPtr<IMPL>(0, true).first;
		LayerSetInterface_IsEqual = LayerSetInterface_IsEqual_GetPtr<IMPL>(0, true).first;
		LayerSetInterface_GetHashCode = LayerSetInterface_GetHashCode_GetPtr<IMPL>(0, true).first;
		LayerSetInterface_DescribeIO = LayerSetInterface_DescribeIO_GetPtr<IMPL>(true);
	}
};

struct LayerSetInterface::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
		using Implementation = C;
		static void LayerSetInterface_Free(const LayerSetInterface* object) { return C::Free(object); }
		static LayerSetInterface* LayerSetInterface_Alloc(const maxon::SourceLocation& allocLocation) { return C::Alloc(allocLocation); }
		static LayerSetInterface* LayerSetInterface_Alloc_1(const maxon::SourceLocation& allocLocation, const LayerSetInterface& object) { return C::Alloc(allocLocation, ((const C&) object)); }
		PRIVATE_MAXON_MF_WRAPPER(LayerSetInterface_SetSelectedLayers, LayerSetInterface,, (Result<void>), const LayerHash& layers) { return C::Get(PRIVATE_MAXON_MF_THIS(LayerSetInterface))->SetSelectedLayers(layers); }
		PRIVATE_MAXON_MF_WRAPPER(LayerSetInterface_GetSelectedLayers, LayerSetInterface, const, (const LayerHash&)) { return C::Get(PRIVATE_MAXON_MF_THIS(const LayerSetInterface))->GetSelectedLayers(); }
		PRIVATE_MAXON_MF_WRAPPER(LayerSetInterface_SetSelectedImage, LayerSetInterface,, (void), const String& image) { return C::Get(PRIVATE_MAXON_MF_THIS(LayerSetInterface))->SetSelectedImage(image); }
		PRIVATE_MAXON_MF_WRAPPER(LayerSetInterface_GetSelectedImage, LayerSetInterface, const, (String)) { return C::Get(PRIVATE_MAXON_MF_THIS(const LayerSetInterface))->GetSelectedImage(); }
		PRIVATE_MAXON_MF_WRAPPER(LayerSetInterface_SetMode, LayerSetInterface,, (void), LAYERSETMODE mode) { return C::Get(PRIVATE_MAXON_MF_THIS(LayerSetInterface))->SetMode(mode); }
		PRIVATE_MAXON_MF_WRAPPER(LayerSetInterface_GetMode, LayerSetInterface, const, (LAYERSETMODE)) { return C::Get(PRIVATE_MAXON_MF_THIS(const LayerSetInterface))->GetMode(); }
		PRIVATE_MAXON_MF_WRAPPER(LayerSetInterface_SetCalculateAlpha, LayerSetInterface,, (void), Bool calcAlpha) { return C::Get(PRIVATE_MAXON_MF_THIS(LayerSetInterface))->SetCalculateAlpha(calcAlpha); }
		PRIVATE_MAXON_MF_WRAPPER(LayerSetInterface_GetCalculateAlpha, LayerSetInterface, const, (Bool)) { return C::Get(PRIVATE_MAXON_MF_THIS(const LayerSetInterface))->GetCalculateAlpha(); }
		PRIVATE_MAXON_MF_WRAPPER(LayerSetInterface_IsEqual, LayerSetInterface, const, (Bool), const LayerSetInterface* other) { return C::Get(PRIVATE_MAXON_MF_THIS(const LayerSetInterface))->IsEqual(other); }
		PRIVATE_MAXON_MF_WRAPPER(LayerSetInterface_GetHashCode, LayerSetInterface, const, (HashInt)) { return C::Get(PRIVATE_MAXON_MF_THIS(const LayerSetInterface))->GetHashCode(); }
		static Result<void> LayerSetInterface_DescribeIO(const DataSerializeInterface& stream) { return C::DescribeIO(stream); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto LayerSetInterface::Free(const LayerSetInterface* object) -> void
{
	return MTable::_instance.LayerSetInterface_Free(object);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LayerSetInterface::Alloc(const maxon::SourceLocation& allocLocation) -> LayerSetInterface*
{
	return MTable::_instance.LayerSetInterface_Alloc(allocLocation);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LayerSetInterface::Alloc(const maxon::SourceLocation& allocLocation, const LayerSetInterface& object) -> LayerSetInterface*
{
	return MTable::_instance.LayerSetInterface_Alloc_1(allocLocation, object);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LayerSetInterface::SetSelectedLayers(const LayerHash& layers) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.LayerSetInterface_SetSelectedLayers, layers);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LayerSetInterface::GetSelectedLayers() const -> const LayerHash&
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.LayerSetInterface_GetSelectedLayers);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LayerSetInterface::SetSelectedImage(const String& image) -> void
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.LayerSetInterface_SetSelectedImage, image);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LayerSetInterface::GetSelectedImage() const -> String
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.LayerSetInterface_GetSelectedImage);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LayerSetInterface::SetMode(LAYERSETMODE mode) -> void
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.LayerSetInterface_SetMode, mode);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LayerSetInterface::GetMode() const -> LAYERSETMODE
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.LayerSetInterface_GetMode);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LayerSetInterface::SetCalculateAlpha(Bool calcAlpha) -> void
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.LayerSetInterface_SetCalculateAlpha, calcAlpha);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LayerSetInterface::GetCalculateAlpha() const -> Bool
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.LayerSetInterface_GetCalculateAlpha);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LayerSetInterface::IsEqual(const LayerSetInterface* other) const -> Bool
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.LayerSetInterface_IsEqual, other);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LayerSetInterface::GetHashCode() const -> HashInt
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.LayerSetInterface_GetHashCode);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LayerSetInterface::DescribeIO(const DataSerializeInterface& stream) -> Result<void>
{
	return MTable::_instance.LayerSetInterface_DescribeIO(stream);
}

auto LayerSetInterface::Hxx1::Reference::Create() -> maxon::ResultMemT<LayerSet>
{
	LayerSetInterface* res_ = LayerSetInterface::Alloc(MAXON_SOURCE_LOCATION);
	return LayerSet(maxon::ForwardResultPtr<LayerSetInterface>(res_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LayerSetInterface::Hxx1::Fn<S>::SetSelectedLayers(const LayerHash& layers) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); LayerSetInterface* o_ = (LayerSetInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.LayerSetInterface_SetSelectedLayers, layers));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LayerSetInterface::Hxx1::COWFn<S>::SetSelectedLayers(const LayerHash& layers) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); LayerSetInterface* o_ = (LayerSetInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.LayerSetInterface_SetSelectedLayers, layers));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LayerSetInterface::Hxx1::ConstFn<S>::GetSelectedLayers() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const LayerHash&>, const LayerHash&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const LayerHash&>, const LayerHash&>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const LayerSetInterface* o_ = (const LayerSetInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = LayerSetInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const LayerHash&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.LayerSetInterface_GetSelectedLayers));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LayerSetInterface::Hxx1::Fn<S>::SetSelectedImage(const String& image) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); LayerSetInterface* o_ = (LayerSetInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } 
	PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.LayerSetInterface_SetSelectedImage, image);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LayerSetInterface::Hxx1::COWFn<S>::SetSelectedImage(const String& image) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); LayerSetInterface* o_ = (LayerSetInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.LayerSetInterface_SetSelectedImage, image);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LayerSetInterface::Hxx1::ConstFn<S>::GetSelectedImage() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const LayerSetInterface* o_ = (const LayerSetInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = LayerSetInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.LayerSetInterface_GetSelectedImage));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LayerSetInterface::Hxx1::Fn<S>::SetMode(LAYERSETMODE mode) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); LayerSetInterface* o_ = (LayerSetInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } 
	PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.LayerSetInterface_SetMode, mode);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LayerSetInterface::Hxx1::COWFn<S>::SetMode(LAYERSETMODE mode) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); LayerSetInterface* o_ = (LayerSetInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.LayerSetInterface_SetMode, mode);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LayerSetInterface::Hxx1::ConstFn<S>::GetMode() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<LAYERSETMODE>, LAYERSETMODE>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<LAYERSETMODE>, LAYERSETMODE>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const LayerSetInterface* o_ = (const LayerSetInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = LayerSetInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<LAYERSETMODE>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.LayerSetInterface_GetMode));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LayerSetInterface::Hxx1::Fn<S>::SetCalculateAlpha(Bool calcAlpha) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); LayerSetInterface* o_ = (LayerSetInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } 
	PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.LayerSetInterface_SetCalculateAlpha, calcAlpha);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LayerSetInterface::Hxx1::COWFn<S>::SetCalculateAlpha(Bool calcAlpha) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); LayerSetInterface* o_ = (LayerSetInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.LayerSetInterface_SetCalculateAlpha, calcAlpha);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LayerSetInterface::Hxx1::ConstFn<S>::GetCalculateAlpha() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const LayerSetInterface* o_ = (const LayerSetInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = LayerSetInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.LayerSetInterface_GetCalculateAlpha));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LayerSetInterface::Hxx1::ConstFn<S>::IsEqual(const LayerSetInterface* other) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const LayerSetInterface* o_ = (const LayerSetInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = LayerSetInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.LayerSetInterface_IsEqual, other));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LayerSetInterface::Hxx1::Fn<S>::FlushLayers() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); LayerSetInterface* o_ = (LayerSetInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } 
	o_->FlushLayers();
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LayerSetInterface::Hxx1::COWFn<S>::FlushLayers() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); LayerSetInterface* o_ = (LayerSetInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	o_->FlushLayers();
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LayerSetInterface::Hxx1::ConstFn<S>::HasLayerSelection() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const LayerSetInterface* o_ = (const LayerSetInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = LayerSetInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->HasLayerSelection());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LayerSetInterface::Hxx1::ConstFn<S>::IsLayerEnabled(const String& name) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const LayerSetInterface* o_ = (const LayerSetInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = LayerSetInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->IsLayerEnabled(name));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LayerSetInterface::Hxx1::ConstFn<S>::HasMultiImageSelection() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const LayerSetInterface* o_ = (const LayerSetInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = LayerSetInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->HasMultiImageSelection());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LayerSetInterface::Hxx1::ConstFn<S>::IsMultiImageEnabled(const String& name) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const LayerSetInterface* o_ = (const LayerSetInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = LayerSetInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->IsMultiImageEnabled(name));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LayerSetInterface::Hxx1::Fn<S>::RemoveLayer(const String& layer) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); LayerSetInterface* o_ = (LayerSetInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->RemoveLayer(layer));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LayerSetInterface::Hxx1::COWFn<S>::RemoveLayer(const String& layer) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); LayerSetInterface* o_ = (LayerSetInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (o_->RemoveLayer(layer));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LayerSetInterface::Hxx1::Fn<S>::AddLayer(const String& layer) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); LayerSetInterface* o_ = (LayerSetInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->AddLayer(layer));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LayerSetInterface::Hxx1::COWFn<S>::AddLayer(const String& layer) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); LayerSetInterface* o_ = (LayerSetInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (o_->AddLayer(layer));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LayerSetInterface::Hxx1::ConstFn<S>::DescribeIO(const DataSerializeInterface& stream) -> Result<void>
{
	return (MTable::_instance.LayerSetInterface_DescribeIO(stream));
}
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_layerset)
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


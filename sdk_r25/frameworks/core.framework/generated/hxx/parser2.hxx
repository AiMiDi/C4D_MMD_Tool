
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1

struct ParserInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetFileExtension);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Read);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Write);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(WriteFile);
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	Result<void> (*_ParserInterface_Read) (maxon::GenericComponent* this_, UrlOrInputStream&& nameOrStream, PARSERFLAGS flags, const StringDecodingRef& stringDecoding, const ValueReceiver<const DataDictionary&>& objects, BaseArray<Char>* originalToken);
	maxon::Int _ParserInterface_Read_Offset;
	Result<void> (*_ParserInterface_Write) (maxon::GenericComponent* this_, const DataDictionary& object, String& string, Bool niceFormatting);
	maxon::Int _ParserInterface_Write_Offset;
	Result<void> (*_ParserInterface_WriteFile) (maxon::GenericComponent* this_, UrlOrOutputStream&& out, const StringEncodingRef& stringEncoding, const DataDictionary& dict, Bool niceFormatting);
	maxon::Int _ParserInterface_WriteFile_Offset;
	String (*_ParserInterface_GetFileExtension) (const maxon::GenericComponent* this_);
	maxon::Int _ParserInterface_GetFileExtension_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ParserInterface, Read))
	{
		auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ParserInterface, Read), W, MTable>::type::_ParserInterface_Read;
		_ParserInterface_Read = reinterpret_cast<const decltype(_ParserInterface_Read)&>(ptr);
		_ParserInterface_Read_Offset = offset;
	}
	if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ParserInterface, Write))
	{
		auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ParserInterface, Write), W, MTable>::type::_ParserInterface_Write;
		_ParserInterface_Write = reinterpret_cast<const decltype(_ParserInterface_Write)&>(ptr);
		_ParserInterface_Write_Offset = offset;
	}
	if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ParserInterface, WriteFile))
	{
		auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ParserInterface, WriteFile), W, MTable>::type::_ParserInterface_WriteFile;
		_ParserInterface_WriteFile = reinterpret_cast<const decltype(_ParserInterface_WriteFile)&>(ptr);
		_ParserInterface_WriteFile_Offset = offset;
	}
	if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ParserInterface, GetFileExtension))
	{
		auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ParserInterface, GetFileExtension), W, MTable>::type::_ParserInterface_GetFileExtension;
		_ParserInterface_GetFileExtension = reinterpret_cast<const decltype(_ParserInterface_GetFileExtension)&>(ptr);
		_ParserInterface_GetFileExtension_Offset = offset;
	}
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!DataDictionaryObjectInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset);
		return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<ParserInterface, typename DataDictionaryObjectInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<ParserInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct ParserInterface::Hxx2
{
	template <typename S> class CWrapper : public DataDictionaryObjectInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetFileExtension);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Read);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Write);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(WriteFile);
		static Result<void> _ParserInterface_Read(maxon::GenericComponent* this_, UrlOrInputStream&& nameOrStream, PARSERFLAGS flags, const StringDecodingRef& stringDecoding, const ValueReceiver<const DataDictionary&>& objects, BaseArray<Char>* originalToken) { return ((typename S::Implementation*) this_)->Read(std::forward<UrlOrInputStream>(nameOrStream), flags, stringDecoding, objects, originalToken); }
		static Result<void> _ParserInterface_Write(maxon::GenericComponent* this_, const DataDictionary& object, String& string, Bool niceFormatting) { return ((typename S::Implementation*) this_)->Write(object, string, niceFormatting); }
		static Result<void> _ParserInterface_WriteFile(maxon::GenericComponent* this_, UrlOrOutputStream&& out, const StringEncodingRef& stringEncoding, const DataDictionary& dict, Bool niceFormatting) { return ((typename S::Implementation*) this_)->WriteFile(std::forward<UrlOrOutputStream>(out), stringEncoding, dict, niceFormatting); }
		static String _ParserInterface_GetFileExtension(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetFileExtension(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto ParserInterface::Read(UrlOrInputStream&& nameOrStream, PARSERFLAGS flags, const StringDecodingRef& stringDecoding, const ValueReceiver<const DataDictionary&>& objects, BaseArray<Char>* originalToken) -> Result<void>
{
	const ParserInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ParserInterface, this); return mt_._ParserInterface_Read((maxon::GenericComponent*) this + mt_._ParserInterface_Read_Offset, std::forward<UrlOrInputStream>(nameOrStream), flags, stringDecoding, objects, originalToken);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ParserInterface::Write(const DataDictionary& object, String& string, Bool niceFormatting) -> Result<void>
{
	const ParserInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ParserInterface, this); return mt_._ParserInterface_Write((maxon::GenericComponent*) this + mt_._ParserInterface_Write_Offset, object, string, niceFormatting);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ParserInterface::WriteFile(UrlOrOutputStream&& out, const StringEncodingRef& stringEncoding, const DataDictionary& dict, Bool niceFormatting) -> Result<void>
{
	const ParserInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ParserInterface, this); return mt_._ParserInterface_WriteFile((maxon::GenericComponent*) this + mt_._ParserInterface_WriteFile_Offset, std::forward<UrlOrOutputStream>(out), stringEncoding, dict, niceFormatting);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ParserInterface::GetFileExtension() const -> String
{
	const ParserInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ParserInterface, this); return mt_._ParserInterface_GetFileExtension((const maxon::GenericComponent*) this + mt_._ParserInterface_GetFileExtension_Offset);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ParserInterface::Hxx1::ReferenceFunctionsImpl<S>::Read(UrlOrInputStream&& nameOrStream, PARSERFLAGS flags, const StringDecodingRef& stringDecoding, const ValueReceiver<const DataDictionary&>& objects, BaseArray<Char>* originalToken) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ParserInterface* o_ = (ParserInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ParserInterface, o_, ParserInterface_Read) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ParserInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ParserInterface>() : PRIVATE_MAXON_VTABLE(ParserInterface, o_); 
	return (mt_._ParserInterface_Read(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._ParserInterface_Read_Offset, std::forward<UrlOrInputStream>(nameOrStream), flags, stringDecoding, objects, originalToken));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ParserInterface::Hxx1::COWReferenceFunctionsImpl<S>::Read(UrlOrInputStream&& nameOrStream, PARSERFLAGS flags, const StringDecodingRef& stringDecoding, const ValueReceiver<const DataDictionary&>& objects, BaseArray<Char>* originalToken) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ParserInterface* o_ = (ParserInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ParserInterface, o_, ParserInterface_Read) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ParserInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ParserInterface>() : PRIVATE_MAXON_VTABLE(ParserInterface, o_); 
	return (mt_._ParserInterface_Read(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._ParserInterface_Read_Offset, std::forward<UrlOrInputStream>(nameOrStream), flags, stringDecoding, objects, originalToken));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ParserInterface::Hxx1::ReferenceFunctionsImpl<S>::ReadString(const Block<const Char>& parserData, PARSERFLAGS flags, const StringDecodingRef& stringDecoding, const ValueReceiver<const DataDictionary&>& objects) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ParserInterface* o_ = (ParserInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->ReadString(parserData, flags, stringDecoding, objects));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ParserInterface::Hxx1::COWReferenceFunctionsImpl<S>::ReadString(const Block<const Char>& parserData, PARSERFLAGS flags, const StringDecodingRef& stringDecoding, const ValueReceiver<const DataDictionary&>& objects) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION ParserInterface::ReadString on super."); if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ParserInterface* o_ = (ParserInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (o_->ReadString(parserData, flags, stringDecoding, objects));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ParserInterface::Hxx1::ReferenceFunctionsImpl<S>::ReadString(const String& text, PARSERFLAGS flags, const StringDecodingRef& stringDecoding, const ValueReceiver<const DataDictionary&>& objects) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ParserInterface* o_ = (ParserInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->ReadString(text, flags, stringDecoding, objects));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ParserInterface::Hxx1::COWReferenceFunctionsImpl<S>::ReadString(const String& text, PARSERFLAGS flags, const StringDecodingRef& stringDecoding, const ValueReceiver<const DataDictionary&>& objects) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION ParserInterface::ReadString on super."); if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ParserInterface* o_ = (ParserInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (o_->ReadString(text, flags, stringDecoding, objects));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ParserInterface::Hxx1::ReferenceFunctionsImpl<S>::Write(const DataDictionary& object, String& string, Bool niceFormatting) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ParserInterface* o_ = (ParserInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ParserInterface, o_, ParserInterface_Write) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ParserInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ParserInterface>() : PRIVATE_MAXON_VTABLE(ParserInterface, o_); 
	return (mt_._ParserInterface_Write(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._ParserInterface_Write_Offset, object, string, niceFormatting));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ParserInterface::Hxx1::COWReferenceFunctionsImpl<S>::Write(const DataDictionary& object, String& string, Bool niceFormatting) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ParserInterface* o_ = (ParserInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ParserInterface, o_, ParserInterface_Write) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ParserInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ParserInterface>() : PRIVATE_MAXON_VTABLE(ParserInterface, o_); 
	return (mt_._ParserInterface_Write(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._ParserInterface_Write_Offset, object, string, niceFormatting));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ParserInterface::Hxx1::ReferenceFunctionsImpl<S>::WriteFile(UrlOrOutputStream&& out, const StringEncodingRef& stringEncoding, const DataDictionary& dict, Bool niceFormatting) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ParserInterface* o_ = (ParserInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ParserInterface, o_, ParserInterface_WriteFile) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ParserInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ParserInterface>() : PRIVATE_MAXON_VTABLE(ParserInterface, o_); 
	return (mt_._ParserInterface_WriteFile(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._ParserInterface_WriteFile_Offset, std::forward<UrlOrOutputStream>(out), stringEncoding, dict, niceFormatting));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ParserInterface::Hxx1::COWReferenceFunctionsImpl<S>::WriteFile(UrlOrOutputStream&& out, const StringEncodingRef& stringEncoding, const DataDictionary& dict, Bool niceFormatting) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ParserInterface* o_ = (ParserInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ParserInterface, o_, ParserInterface_WriteFile) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ParserInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ParserInterface>() : PRIVATE_MAXON_VTABLE(ParserInterface, o_); 
	return (mt_._ParserInterface_WriteFile(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._ParserInterface_WriteFile_Offset, std::forward<UrlOrOutputStream>(out), stringEncoding, dict, niceFormatting));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ParserInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetFileExtension() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ParserInterface* o_ = (const ParserInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ParserInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ParserInterface, o_, ParserInterface_GetFileExtension) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<ParserInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ParserInterface>() : PRIVATE_MAXON_VTABLE(ParserInterface, o_); 
	return (mt_._ParserInterface_GetFileExtension(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._ParserInterface_GetFileExtension_Offset));
}
auto ParserInterface::GetPtr() -> Ptr { return Ptr(this); }
auto ParserInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_ParserInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_ParserInterface() { new (s_ui_maxon_ParserInterface) maxon::EntityUse(ParserInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/parser.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_ParserInterface(ParserInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/parser.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif


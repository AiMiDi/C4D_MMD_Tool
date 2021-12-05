
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1
/// @cond INTERNAL

/// @endcond


struct IoBrowseInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetBasePath);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetCurrentPath);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetExtraData);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetNext);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetSize);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(HasEntry);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Init);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(IoGetAttributes);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(IoGetFlags);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(IoGetTime);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Reset);
	static const maxon::Char* const _ids;
	static const maxon::Bool HAS_NONSTATIC = false;
/// @cond INTERNAL

	Result<void> (*_IoBrowseInterface_Init) (maxon::GenericComponent* this_, IoConnectionInterface* connection, GETBROWSEITERATORFLAGS flags);
	maxon::Int _IoBrowseInterface_Init_Offset;
/// @endcond

	const Url& (*_IoBrowseInterface_GetBasePath) (const maxon::GenericComponent* this_);
	maxon::Int _IoBrowseInterface_GetBasePath_Offset;
	Result<void> (*_IoBrowseInterface_Reset) (maxon::GenericComponent* this_);
	maxon::Int _IoBrowseInterface_Reset_Offset;
	Result<void> (*_IoBrowseInterface_GetNext) (maxon::GenericComponent* this_);
	maxon::Int _IoBrowseInterface_GetNext_Offset;
	Bool (*_IoBrowseInterface_HasEntry) (const maxon::GenericComponent* this_);
	maxon::Int _IoBrowseInterface_HasEntry_Offset;
	Url (*_IoBrowseInterface_GetCurrentPath) (const maxon::GenericComponent* this_);
	maxon::Int _IoBrowseInterface_GetCurrentPath_Offset;
	IOBROWSEFLAGS (*_IoBrowseInterface_IoGetFlags) (const maxon::GenericComponent* this_);
	maxon::Int _IoBrowseInterface_IoGetFlags_Offset;
	Result<IOATTRIBUTES> (*_IoBrowseInterface_IoGetAttributes) (const maxon::GenericComponent* this_);
	maxon::Int _IoBrowseInterface_IoGetAttributes_Offset;
	Result<UniversalDateTime> (*_IoBrowseInterface_IoGetTime) (const maxon::GenericComponent* this_, IOTIMEMODE mode);
	maxon::Int _IoBrowseInterface_IoGetTime_Offset;
	Int64 (*_IoBrowseInterface_GetSize) (const maxon::GenericComponent* this_);
	maxon::Int _IoBrowseInterface_GetSize_Offset;
	String (*_IoBrowseInterface_GetExtraData) (const maxon::GenericComponent* this_);
	maxon::Int _IoBrowseInterface_GetExtraData_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
/// @cond INTERNAL

		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoBrowseInterface, Init))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoBrowseInterface, Init), W, MTable>::type::_IoBrowseInterface_Init;
			_IoBrowseInterface_Init = reinterpret_cast<const decltype(_IoBrowseInterface_Init)&>(ptr);
			_IoBrowseInterface_Init_Offset = offset;
		}
/// @endcond

		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoBrowseInterface, GetBasePath))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoBrowseInterface, GetBasePath), W, MTable>::type::_IoBrowseInterface_GetBasePath;
			_IoBrowseInterface_GetBasePath = reinterpret_cast<const decltype(_IoBrowseInterface_GetBasePath)&>(ptr);
			_IoBrowseInterface_GetBasePath_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoBrowseInterface, Reset))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoBrowseInterface, Reset), W, MTable>::type::_IoBrowseInterface_Reset;
			_IoBrowseInterface_Reset = reinterpret_cast<const decltype(_IoBrowseInterface_Reset)&>(ptr);
			_IoBrowseInterface_Reset_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoBrowseInterface, GetNext))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoBrowseInterface, GetNext), W, MTable>::type::_IoBrowseInterface_GetNext;
			_IoBrowseInterface_GetNext = reinterpret_cast<const decltype(_IoBrowseInterface_GetNext)&>(ptr);
			_IoBrowseInterface_GetNext_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoBrowseInterface, HasEntry))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoBrowseInterface, HasEntry), W, MTable>::type::_IoBrowseInterface_HasEntry;
			_IoBrowseInterface_HasEntry = reinterpret_cast<const decltype(_IoBrowseInterface_HasEntry)&>(ptr);
			_IoBrowseInterface_HasEntry_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoBrowseInterface, GetCurrentPath))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoBrowseInterface, GetCurrentPath), W, MTable>::type::_IoBrowseInterface_GetCurrentPath;
			_IoBrowseInterface_GetCurrentPath = reinterpret_cast<const decltype(_IoBrowseInterface_GetCurrentPath)&>(ptr);
			_IoBrowseInterface_GetCurrentPath_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoBrowseInterface, IoGetFlags))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoBrowseInterface, IoGetFlags), W, MTable>::type::_IoBrowseInterface_IoGetFlags;
			_IoBrowseInterface_IoGetFlags = reinterpret_cast<const decltype(_IoBrowseInterface_IoGetFlags)&>(ptr);
			_IoBrowseInterface_IoGetFlags_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoBrowseInterface, IoGetAttributes))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoBrowseInterface, IoGetAttributes), W, MTable>::type::_IoBrowseInterface_IoGetAttributes;
			_IoBrowseInterface_IoGetAttributes = reinterpret_cast<const decltype(_IoBrowseInterface_IoGetAttributes)&>(ptr);
			_IoBrowseInterface_IoGetAttributes_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoBrowseInterface, IoGetTime))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoBrowseInterface, IoGetTime), W, MTable>::type::_IoBrowseInterface_IoGetTime;
			_IoBrowseInterface_IoGetTime = reinterpret_cast<const decltype(_IoBrowseInterface_IoGetTime)&>(ptr);
			_IoBrowseInterface_IoGetTime_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoBrowseInterface, GetSize))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoBrowseInterface, GetSize), W, MTable>::type::_IoBrowseInterface_GetSize;
			_IoBrowseInterface_GetSize = reinterpret_cast<const decltype(_IoBrowseInterface_GetSize)&>(ptr);
			_IoBrowseInterface_GetSize_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoBrowseInterface, GetExtraData))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoBrowseInterface, GetExtraData), W, MTable>::type::_IoBrowseInterface_GetExtraData;
			_IoBrowseInterface_GetExtraData = reinterpret_cast<const decltype(_IoBrowseInterface_GetExtraData)&>(ptr);
			_IoBrowseInterface_GetExtraData_Offset = offset;
		}
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!ObjectInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<IoBrowseInterface, typename ObjectInterface::MTable::template CombinedMTable<S>>;
	PRIVATE_MAXON_COMPBASE(IoBrowseInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct IoBrowseInterface::Hxx2
{
	template <typename S> class Wrapper : public ObjectInterface::Hxx2::template Wrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetBasePath);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetCurrentPath);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetExtraData);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetNext);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetSize);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(HasEntry);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Init);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(IoGetAttributes);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(IoGetFlags);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(IoGetTime);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Reset);
/// @cond INTERNAL

	static Result<void> _IoBrowseInterface_Init(maxon::GenericComponent* this_, IoConnectionInterface* connection, GETBROWSEITERATORFLAGS flags) { return ((typename S::Implementation*) this_)->Init(connection, flags); }
/// @endcond

	static const Url& _IoBrowseInterface_GetBasePath(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetBasePath(); }
	static Result<void> _IoBrowseInterface_Reset(maxon::GenericComponent* this_) { return ((typename S::Implementation*) this_)->Reset(); }
	static Result<void> _IoBrowseInterface_GetNext(maxon::GenericComponent* this_) { return ((typename S::Implementation*) this_)->GetNext(); }
	static Bool _IoBrowseInterface_HasEntry(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->HasEntry(); }
	static Url _IoBrowseInterface_GetCurrentPath(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetCurrentPath(); }
	static IOBROWSEFLAGS _IoBrowseInterface_IoGetFlags(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->IoGetFlags(); }
	static Result<IOATTRIBUTES> _IoBrowseInterface_IoGetAttributes(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->IoGetAttributes(); }
	static Result<UniversalDateTime> _IoBrowseInterface_IoGetTime(const maxon::GenericComponent* this_, IOTIMEMODE mode) { return ((const typename S::Implementation*) this_)->IoGetTime(mode); }
	static Int64 _IoBrowseInterface_GetSize(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetSize(); }
	static String _IoBrowseInterface_GetExtraData(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetExtraData(); }
	};

};
/// @cond INTERNAL

MAXON_ATTRIBUTE_FORCE_INLINE auto IoBrowseInterface::Init(IoConnectionInterface* connection, GETBROWSEITERATORFLAGS flags) -> Result<void>
{
	const IoBrowseInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(IoBrowseInterface, this); return mt_._IoBrowseInterface_Init((maxon::GenericComponent*) this + mt_._IoBrowseInterface_Init_Offset, connection, flags);
}
/// @endcond

MAXON_ATTRIBUTE_FORCE_INLINE auto IoBrowseInterface::GetBasePath() const -> const Url&
{
	const IoBrowseInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(IoBrowseInterface, this); return mt_._IoBrowseInterface_GetBasePath((const maxon::GenericComponent*) this + mt_._IoBrowseInterface_GetBasePath_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoBrowseInterface::Reset() -> Result<void>
{
	const IoBrowseInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(IoBrowseInterface, this); return mt_._IoBrowseInterface_Reset((maxon::GenericComponent*) this + mt_._IoBrowseInterface_Reset_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoBrowseInterface::GetNext() -> Result<void>
{
	const IoBrowseInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(IoBrowseInterface, this); return mt_._IoBrowseInterface_GetNext((maxon::GenericComponent*) this + mt_._IoBrowseInterface_GetNext_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoBrowseInterface::HasEntry() const -> Bool
{
	const IoBrowseInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(IoBrowseInterface, this); return mt_._IoBrowseInterface_HasEntry((const maxon::GenericComponent*) this + mt_._IoBrowseInterface_HasEntry_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoBrowseInterface::GetCurrentPath() const -> Url
{
	const IoBrowseInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(IoBrowseInterface, this); return mt_._IoBrowseInterface_GetCurrentPath((const maxon::GenericComponent*) this + mt_._IoBrowseInterface_GetCurrentPath_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoBrowseInterface::IoGetFlags() const -> IOBROWSEFLAGS
{
	const IoBrowseInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(IoBrowseInterface, this); return mt_._IoBrowseInterface_IoGetFlags((const maxon::GenericComponent*) this + mt_._IoBrowseInterface_IoGetFlags_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoBrowseInterface::IoGetAttributes() const -> Result<IOATTRIBUTES>
{
	const IoBrowseInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(IoBrowseInterface, this); return mt_._IoBrowseInterface_IoGetAttributes((const maxon::GenericComponent*) this + mt_._IoBrowseInterface_IoGetAttributes_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoBrowseInterface::IoGetTime(IOTIMEMODE mode) const -> Result<UniversalDateTime>
{
	const IoBrowseInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(IoBrowseInterface, this); return mt_._IoBrowseInterface_IoGetTime((const maxon::GenericComponent*) this + mt_._IoBrowseInterface_IoGetTime_Offset, mode);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoBrowseInterface::GetSize() const -> Int64
{
	const IoBrowseInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(IoBrowseInterface, this); return mt_._IoBrowseInterface_GetSize((const maxon::GenericComponent*) this + mt_._IoBrowseInterface_GetSize_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoBrowseInterface::GetExtraData() const -> String
{
	const IoBrowseInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(IoBrowseInterface, this); return mt_._IoBrowseInterface_GetExtraData((const maxon::GenericComponent*) this + mt_._IoBrowseInterface_GetExtraData_Offset);
}

/// @cond INTERNAL

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoBrowseInterface::Hxx1::ReferenceFunctionsImpl<S>::Init(IoConnectionInterface* connection, GETBROWSEITERATORFLAGS flags) const -> maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), true, maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); IoBrowseInterface* o_ = (IoBrowseInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR)); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoBrowseInterface, o_, IoBrowseInterface_Init) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<IoBrowseInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoBrowseInterface>() : PRIVATE_MAXON_VTABLE(IoBrowseInterface, o_); 
	auto res_ = mt_._IoBrowseInterface_Init(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._IoBrowseInterface_Init_Offset, connection, flags);
	return ReturnHelper::Return(this, res_.GetErrorStorage());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoBrowseInterface::Hxx1::COWReferenceFunctionsImpl<S>::Init(IoConnectionInterface* connection, GETBROWSEITERATORFLAGS flags) -> maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), true, maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); IoBrowseInterface* o_ = (IoBrowseInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoBrowseInterface, o_, IoBrowseInterface_Init) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<IoBrowseInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoBrowseInterface>() : PRIVATE_MAXON_VTABLE(IoBrowseInterface, o_); 
	auto res_ = mt_._IoBrowseInterface_Init(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._IoBrowseInterface_Init_Offset, connection, flags);
	return ReturnHelper::Return(this, res_.GetErrorStorage());
}
/// @endcond

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoBrowseInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetBasePath() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const Url&>, const Url&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const Url&>, const Url&>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const IoBrowseInterface* o_ = (const IoBrowseInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = IoBrowseInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const Url&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoBrowseInterface, o_, IoBrowseInterface_GetBasePath) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<IoBrowseInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoBrowseInterface>() : PRIVATE_MAXON_VTABLE(IoBrowseInterface, o_); 
	return (mt_._IoBrowseInterface_GetBasePath(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._IoBrowseInterface_GetBasePath_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoBrowseInterface::Hxx1::ReferenceFunctionsImpl<S>::Reset() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); IoBrowseInterface* o_ = (IoBrowseInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoBrowseInterface, o_, IoBrowseInterface_Reset) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<IoBrowseInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoBrowseInterface>() : PRIVATE_MAXON_VTABLE(IoBrowseInterface, o_); 
	return (mt_._IoBrowseInterface_Reset(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._IoBrowseInterface_Reset_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoBrowseInterface::Hxx1::COWReferenceFunctionsImpl<S>::Reset() -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); IoBrowseInterface* o_ = (IoBrowseInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoBrowseInterface, o_, IoBrowseInterface_Reset) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<IoBrowseInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoBrowseInterface>() : PRIVATE_MAXON_VTABLE(IoBrowseInterface, o_); 
	return (mt_._IoBrowseInterface_Reset(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._IoBrowseInterface_Reset_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoBrowseInterface::Hxx1::ReferenceFunctionsImpl<S>::GetNext() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); IoBrowseInterface* o_ = (IoBrowseInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoBrowseInterface, o_, IoBrowseInterface_GetNext) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<IoBrowseInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoBrowseInterface>() : PRIVATE_MAXON_VTABLE(IoBrowseInterface, o_); 
	return (mt_._IoBrowseInterface_GetNext(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._IoBrowseInterface_GetNext_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoBrowseInterface::Hxx1::COWReferenceFunctionsImpl<S>::GetNext() -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); IoBrowseInterface* o_ = (IoBrowseInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoBrowseInterface, o_, IoBrowseInterface_GetNext) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<IoBrowseInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoBrowseInterface>() : PRIVATE_MAXON_VTABLE(IoBrowseInterface, o_); 
	return (mt_._IoBrowseInterface_GetNext(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._IoBrowseInterface_GetNext_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoBrowseInterface::Hxx1::ConstReferenceFunctionsImpl<S>::HasEntry() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const IoBrowseInterface* o_ = (const IoBrowseInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = IoBrowseInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoBrowseInterface, o_, IoBrowseInterface_HasEntry) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<IoBrowseInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoBrowseInterface>() : PRIVATE_MAXON_VTABLE(IoBrowseInterface, o_); 
	return (mt_._IoBrowseInterface_HasEntry(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._IoBrowseInterface_HasEntry_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoBrowseInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetCurrentPath() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Url>, Url>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Url>, Url>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const IoBrowseInterface* o_ = (const IoBrowseInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = IoBrowseInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<Url>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoBrowseInterface, o_, IoBrowseInterface_GetCurrentPath) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<IoBrowseInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoBrowseInterface>() : PRIVATE_MAXON_VTABLE(IoBrowseInterface, o_); 
	return (mt_._IoBrowseInterface_GetCurrentPath(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._IoBrowseInterface_GetCurrentPath_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoBrowseInterface::Hxx1::ConstReferenceFunctionsImpl<S>::IoGetFlags() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<IOBROWSEFLAGS>, IOBROWSEFLAGS>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<IOBROWSEFLAGS>, IOBROWSEFLAGS>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const IoBrowseInterface* o_ = (const IoBrowseInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = IoBrowseInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<IOBROWSEFLAGS>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoBrowseInterface, o_, IoBrowseInterface_IoGetFlags) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<IoBrowseInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoBrowseInterface>() : PRIVATE_MAXON_VTABLE(IoBrowseInterface, o_); 
	return (mt_._IoBrowseInterface_IoGetFlags(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._IoBrowseInterface_IoGetFlags_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoBrowseInterface::Hxx1::ConstReferenceFunctionsImpl<S>::IoGetAttributes() const -> Result<IOATTRIBUTES>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<IOATTRIBUTES>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const IoBrowseInterface* o_ = (const IoBrowseInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = IoBrowseInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoBrowseInterface, o_, IoBrowseInterface_IoGetAttributes) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<IoBrowseInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoBrowseInterface>() : PRIVATE_MAXON_VTABLE(IoBrowseInterface, o_); 
	return (mt_._IoBrowseInterface_IoGetAttributes(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._IoBrowseInterface_IoGetAttributes_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoBrowseInterface::Hxx1::ConstReferenceFunctionsImpl<S>::IoGetTime(IOTIMEMODE mode) const -> Result<UniversalDateTime>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<UniversalDateTime>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const IoBrowseInterface* o_ = (const IoBrowseInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = IoBrowseInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoBrowseInterface, o_, IoBrowseInterface_IoGetTime) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<IoBrowseInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoBrowseInterface>() : PRIVATE_MAXON_VTABLE(IoBrowseInterface, o_); 
	return (mt_._IoBrowseInterface_IoGetTime(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._IoBrowseInterface_IoGetTime_Offset, mode));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoBrowseInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetSize() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int64>, Int64>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int64>, Int64>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const IoBrowseInterface* o_ = (const IoBrowseInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = IoBrowseInterface::NullValuePtr(); if (!o_) return 0; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoBrowseInterface, o_, IoBrowseInterface_GetSize) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<IoBrowseInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoBrowseInterface>() : PRIVATE_MAXON_VTABLE(IoBrowseInterface, o_); 
	return (mt_._IoBrowseInterface_GetSize(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._IoBrowseInterface_GetSize_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoBrowseInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetExtraData() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const IoBrowseInterface* o_ = (const IoBrowseInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = IoBrowseInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoBrowseInterface, o_, IoBrowseInterface_GetExtraData) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<IoBrowseInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoBrowseInterface>() : PRIVATE_MAXON_VTABLE(IoBrowseInterface, o_); 
	return (mt_._IoBrowseInterface_GetExtraData(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._IoBrowseInterface_GetExtraData_Offset));
}
auto IoBrowseInterface::GetPtr() -> Ptr { return Ptr(this); }
auto IoBrowseInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_IoBrowseInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_IoBrowseInterface() { new (s_ui_maxon_IoBrowseInterface) maxon::EntityUse(IoBrowseInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/iobrowse.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_IoBrowseInterface(IoBrowseInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/iobrowse.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif


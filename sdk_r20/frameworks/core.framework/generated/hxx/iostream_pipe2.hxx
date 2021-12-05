
#ifndef DOXYGEN

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wmisleading-indentation"
#endif

#if 1
#ifdef MAXON_TARGET_WINDOWS
#else
#endif

struct IoPipeInOutputStreamInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetReadHandle);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetWriteHandle);
	static const maxon::Char* const _ids;
	static const maxon::Bool HAS_NONSTATIC = false;
	PIPEHANDLE (*_IoPipeInOutputStreamInterface_GetReadHandle) (const maxon::GenericComponent* this_);
	maxon::Int _IoPipeInOutputStreamInterface_GetReadHandle_Offset;
	PIPEHANDLE (*_IoPipeInOutputStreamInterface_GetWriteHandle) (const maxon::GenericComponent* this_);
	maxon::Int _IoPipeInOutputStreamInterface_GetWriteHandle_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
		if (PRIVATE_MAXON_IMPLEMENTS(W::Implementation, IoPipeInOutputStreamInterface, GetReadHandle))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(W::Implementation, IoPipeInOutputStreamInterface, GetReadHandle), W, MTable>::type::_IoPipeInOutputStreamInterface_GetReadHandle;
			_IoPipeInOutputStreamInterface_GetReadHandle = reinterpret_cast<const decltype(_IoPipeInOutputStreamInterface_GetReadHandle)&>(ptr);
			_IoPipeInOutputStreamInterface_GetReadHandle_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(W::Implementation, IoPipeInOutputStreamInterface, GetWriteHandle))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(W::Implementation, IoPipeInOutputStreamInterface, GetWriteHandle), W, MTable>::type::_IoPipeInOutputStreamInterface_GetWriteHandle;
			_IoPipeInOutputStreamInterface_GetWriteHandle = reinterpret_cast<const decltype(_IoPipeInOutputStreamInterface_GetWriteHandle)&>(ptr);
			_IoPipeInOutputStreamInterface_GetWriteHandle_Offset = offset;
		}
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!InOutputStreamInterface::MTable::InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::Object::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<IoPipeInOutputStreamInterface, InOutputStreamInterface::MTable::CombinedMTable<S>>;
	PRIVATE_MAXON_COMPBASE(IoPipeInOutputStreamInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

template <typename S> class IoPipeInOutputStreamInterface::Wrapper : public InOutputStreamInterface::Wrapper<S>
{
public:
	PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetReadHandle);
	PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetWriteHandle);
	static PIPEHANDLE _IoPipeInOutputStreamInterface_GetReadHandle(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetReadHandle(); }
	static PIPEHANDLE _IoPipeInOutputStreamInterface_GetWriteHandle(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetWriteHandle(); }
};

MAXON_ATTRIBUTE_FORCE_INLINE auto IoPipeInOutputStreamInterface::GetReadHandle() const -> PIPEHANDLE
{
	const IoPipeInOutputStreamInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(IoPipeInOutputStreamInterface, this); return mt_._IoPipeInOutputStreamInterface_GetReadHandle((const maxon::GenericComponent*) this + mt_._IoPipeInOutputStreamInterface_GetReadHandle_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoPipeInOutputStreamInterface::GetWriteHandle() const -> PIPEHANDLE
{
	const IoPipeInOutputStreamInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(IoPipeInOutputStreamInterface, this); return mt_._IoPipeInOutputStreamInterface_GetWriteHandle((const maxon::GenericComponent*) this + mt_._IoPipeInOutputStreamInterface_GetWriteHandle_Offset);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoPipeInOutputStreamInterface::ConstReferenceFunctionsImpl<S>::GetReadHandle() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<PIPEHANDLE>, PIPEHANDLE>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<PIPEHANDLE>, PIPEHANDLE>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const IoPipeInOutputStreamInterface* o_ = (const IoPipeInOutputStreamInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = IoPipeInOutputStreamInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<PIPEHANDLE>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoPipeInOutputStreamInterface, o_, IoPipeInOutputStreamInterface_GetReadHandle) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<IoPipeInOutputStreamInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoPipeInOutputStreamInterface>() : PRIVATE_MAXON_VTABLE(IoPipeInOutputStreamInterface, o_); 
	return (mt_._IoPipeInOutputStreamInterface_GetReadHandle(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._IoPipeInOutputStreamInterface_GetReadHandle_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoPipeInOutputStreamInterface::ConstReferenceFunctionsImpl<S>::GetWriteHandle() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<PIPEHANDLE>, PIPEHANDLE>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<PIPEHANDLE>, PIPEHANDLE>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const IoPipeInOutputStreamInterface* o_ = (const IoPipeInOutputStreamInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = IoPipeInOutputStreamInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<PIPEHANDLE>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoPipeInOutputStreamInterface, o_, IoPipeInOutputStreamInterface_GetWriteHandle) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<IoPipeInOutputStreamInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoPipeInOutputStreamInterface>() : PRIVATE_MAXON_VTABLE(IoPipeInOutputStreamInterface, o_); 
	return (mt_._IoPipeInOutputStreamInterface_GetWriteHandle(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._IoPipeInOutputStreamInterface_GetWriteHandle_Offset));
}
auto IoPipeInOutputStreamInterface::GetPtr() -> Ptr { return Ptr(this); }
auto IoPipeInOutputStreamInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
static maxon::EntityUse s_ui_maxon_IoPipeInOutputStreamInterface(IoPipeInOutputStreamInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/iostream_pipe.h", false);
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif


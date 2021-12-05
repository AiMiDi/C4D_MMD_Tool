
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1

struct CommandDataInterface::MTable
{
	static const maxon::Char* const _ids;
	static const maxon::Bool HAS_NONSTATIC = false;
	template <typename W> void Init(maxon::Int offset)
	{
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!DataDictionaryObjectInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<CommandDataInterface, typename DataDictionaryObjectInterface::MTable::template CombinedMTable<S>>;
	PRIVATE_MAXON_COMPBASE(CommandDataInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct CommandDataInterface::Hxx2
{
	template <typename S> class Wrapper : public DataDictionaryObjectInterface::Hxx2::template Wrapper<S>
	{
	public:
	};

};

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CommandDataInterface::Hxx1::ReferenceFunctionsImpl<S>::Invoke(const Id& command, Bool interactive) const -> Result<COMMANDRESULT>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<COMMANDRESULT>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CommandDataInterface* o_ = (CommandDataInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->Invoke(command, interactive));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CommandDataInterface::Hxx1::COWReferenceFunctionsImpl<S>::Invoke(const Id& command, Bool interactive) -> Result<COMMANDRESULT>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<COMMANDRESULT>>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION CommandDataInterface::Invoke on super."); if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CommandDataInterface* o_ = (CommandDataInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (o_->Invoke(command, interactive));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CommandDataInterface::Hxx1::ReferenceFunctionsImpl<S>::Invoke(const CommandClass& command, Bool interactive) const -> Result<COMMANDRESULT>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<COMMANDRESULT>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CommandDataInterface* o_ = (CommandDataInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->Invoke(command, interactive));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CommandDataInterface::Hxx1::COWReferenceFunctionsImpl<S>::Invoke(const CommandClass& command, Bool interactive) -> Result<COMMANDRESULT>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<COMMANDRESULT>>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION CommandDataInterface::Invoke on super."); if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CommandDataInterface* o_ = (CommandDataInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (o_->Invoke(command, interactive));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CommandDataInterface::Hxx1::ReferenceFunctionsImpl<S>::Invoke(const Id& command, Bool interactive, const SetParameters& setParameters) const -> Result<COMMANDRESULT>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<COMMANDRESULT>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CommandDataInterface* o_ = (CommandDataInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->Invoke(command, interactive, setParameters));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CommandDataInterface::Hxx1::COWReferenceFunctionsImpl<S>::Invoke(const Id& command, Bool interactive, const SetParameters& setParameters) -> Result<COMMANDRESULT>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<COMMANDRESULT>>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION CommandDataInterface::Invoke on super."); if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CommandDataInterface* o_ = (CommandDataInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (o_->Invoke(command, interactive, setParameters));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CommandDataInterface::Hxx1::ReferenceFunctionsImpl<S>::Invoke(const CommandClass& command, Bool interactive, const SetParameters& setParameters) const -> Result<COMMANDRESULT>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<COMMANDRESULT>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CommandDataInterface* o_ = (CommandDataInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->Invoke(command, interactive, setParameters));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CommandDataInterface::Hxx1::COWReferenceFunctionsImpl<S>::Invoke(const CommandClass& command, Bool interactive, const SetParameters& setParameters) -> Result<COMMANDRESULT>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<COMMANDRESULT>>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION CommandDataInterface::Invoke on super."); if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CommandDataInterface* o_ = (CommandDataInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (o_->Invoke(command, interactive, setParameters));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CommandDataInterface::Hxx1::ReferenceFunctionsImpl<S>::Interact(INTERACTIONTYPE interactionType) const -> Result<COMMANDRESULT>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<COMMANDRESULT>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CommandDataInterface* o_ = (CommandDataInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->Interact(interactionType));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CommandDataInterface::Hxx1::COWReferenceFunctionsImpl<S>::Interact(INTERACTIONTYPE interactionType) -> Result<COMMANDRESULT>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<COMMANDRESULT>>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION CommandDataInterface::Interact on super."); if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CommandDataInterface* o_ = (CommandDataInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (o_->Interact(interactionType));
}
template <typename S> template <typename... ARGS> MAXON_ATTRIBUTE_FORCE_INLINE auto CommandDataInterface::Hxx1::ReferenceFunctionsImpl<S>::Invoke(const CommandClass& command, Bool interactive, ARGS&&... args) const -> Result<COMMANDRESULT>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<COMMANDRESULT>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CommandDataInterface* o_ = (CommandDataInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->Invoke<ARGS...>(command, interactive, std::forward<ARGS>(args)...));
}
template <typename S> template <typename... ARGS> MAXON_ATTRIBUTE_FORCE_INLINE auto CommandDataInterface::Hxx1::COWReferenceFunctionsImpl<S>::Invoke(const CommandClass& command, Bool interactive, ARGS&&... args) -> Result<COMMANDRESULT>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<COMMANDRESULT>>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION CommandDataInterface::Invoke on super."); if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CommandDataInterface* o_ = (CommandDataInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (o_->Invoke<ARGS...>(command, interactive, std::forward<ARGS>(args)...));
}
auto CommandDataInterface::GetPtr() -> Ptr { return Ptr(this); }
auto CommandDataInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_CommandDataInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_CommandDataInterface() { new (s_ui_maxon_CommandDataInterface) maxon::EntityUse(CommandDataInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/commandbase.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_CommandDataInterface(CommandDataInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/commandbase.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif

struct LegacyCommandDataInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetLegacyData);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetLegacyDataCount);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(SetLegacyData);
	static const maxon::Char* const _ids;
	static const maxon::Bool HAS_NONSTATIC = false;
	Result<Generic*> (*_LegacyCommandDataInterface_GetLegacyData) (maxon::GenericComponent* this_, Int index);
	maxon::Int _LegacyCommandDataInterface_GetLegacyData_Offset;
	Result<void> (*_LegacyCommandDataInterface_SetLegacyData) (maxon::GenericComponent* this_, const Generic* data, Int index);
	maxon::Int _LegacyCommandDataInterface_SetLegacyData_Offset;
	Int (*_LegacyCommandDataInterface_GetLegacyDataCount) (const maxon::GenericComponent* this_);
	maxon::Int _LegacyCommandDataInterface_GetLegacyDataCount_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, LegacyCommandDataInterface, GetLegacyData))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, LegacyCommandDataInterface, GetLegacyData), W, MTable>::type::_LegacyCommandDataInterface_GetLegacyData;
			_LegacyCommandDataInterface_GetLegacyData = reinterpret_cast<const decltype(_LegacyCommandDataInterface_GetLegacyData)&>(ptr);
			_LegacyCommandDataInterface_GetLegacyData_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, LegacyCommandDataInterface, SetLegacyData))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, LegacyCommandDataInterface, SetLegacyData), W, MTable>::type::_LegacyCommandDataInterface_SetLegacyData;
			_LegacyCommandDataInterface_SetLegacyData = reinterpret_cast<const decltype(_LegacyCommandDataInterface_SetLegacyData)&>(ptr);
			_LegacyCommandDataInterface_SetLegacyData_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, LegacyCommandDataInterface, GetLegacyDataCount))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, LegacyCommandDataInterface, GetLegacyDataCount), W, MTable>::type::_LegacyCommandDataInterface_GetLegacyDataCount;
			_LegacyCommandDataInterface_GetLegacyDataCount = reinterpret_cast<const decltype(_LegacyCommandDataInterface_GetLegacyDataCount)&>(ptr);
			_LegacyCommandDataInterface_GetLegacyDataCount_Offset = offset;
		}
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!CommandDataInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<LegacyCommandDataInterface, typename CommandDataInterface::MTable::template CombinedMTable<S>>;
	PRIVATE_MAXON_COMPBASE(LegacyCommandDataInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct LegacyCommandDataInterface::Hxx2
{
	template <typename S> class Wrapper : public CommandDataInterface::Hxx2::template Wrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetLegacyData);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetLegacyDataCount);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(SetLegacyData);
	static Result<Generic*> _LegacyCommandDataInterface_GetLegacyData(maxon::GenericComponent* this_, Int index) { return ((typename S::Implementation*) this_)->GetLegacyData(index); }
	static Result<void> _LegacyCommandDataInterface_SetLegacyData(maxon::GenericComponent* this_, const Generic* data, Int index) { return ((typename S::Implementation*) this_)->SetLegacyData(data, index); }
	static Int _LegacyCommandDataInterface_GetLegacyDataCount(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetLegacyDataCount(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto LegacyCommandDataInterface::GetLegacyData(Int index) -> Result<Generic*>
{
	const LegacyCommandDataInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(LegacyCommandDataInterface, this); return mt_._LegacyCommandDataInterface_GetLegacyData((maxon::GenericComponent*) this + mt_._LegacyCommandDataInterface_GetLegacyData_Offset, index);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LegacyCommandDataInterface::SetLegacyData(const Generic* data, Int index) -> Result<void>
{
	const LegacyCommandDataInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(LegacyCommandDataInterface, this); return mt_._LegacyCommandDataInterface_SetLegacyData((maxon::GenericComponent*) this + mt_._LegacyCommandDataInterface_SetLegacyData_Offset, data, index);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LegacyCommandDataInterface::GetLegacyDataCount() const -> Int
{
	const LegacyCommandDataInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(LegacyCommandDataInterface, this); return mt_._LegacyCommandDataInterface_GetLegacyDataCount((const maxon::GenericComponent*) this + mt_._LegacyCommandDataInterface_GetLegacyDataCount_Offset);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LegacyCommandDataInterface::Hxx1::ReferenceFunctionsImpl<S>::GetLegacyData(Int index) const -> Result<Generic*>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Generic*>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); LegacyCommandDataInterface* o_ = (LegacyCommandDataInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(LegacyCommandDataInterface, o_, LegacyCommandDataInterface_GetLegacyData) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<LegacyCommandDataInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<LegacyCommandDataInterface>() : PRIVATE_MAXON_VTABLE(LegacyCommandDataInterface, o_); 
	return (mt_._LegacyCommandDataInterface_GetLegacyData(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._LegacyCommandDataInterface_GetLegacyData_Offset, index));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LegacyCommandDataInterface::Hxx1::COWReferenceFunctionsImpl<S>::GetLegacyData(Int index) -> Result<Generic*>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Generic*>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); LegacyCommandDataInterface* o_ = (LegacyCommandDataInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(LegacyCommandDataInterface, o_, LegacyCommandDataInterface_GetLegacyData) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<LegacyCommandDataInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<LegacyCommandDataInterface>() : PRIVATE_MAXON_VTABLE(LegacyCommandDataInterface, o_); 
	return (mt_._LegacyCommandDataInterface_GetLegacyData(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._LegacyCommandDataInterface_GetLegacyData_Offset, index));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LegacyCommandDataInterface::Hxx1::ReferenceFunctionsImpl<S>::SetLegacyData(const Generic* data, Int index) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); LegacyCommandDataInterface* o_ = (LegacyCommandDataInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(LegacyCommandDataInterface, o_, LegacyCommandDataInterface_SetLegacyData) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<LegacyCommandDataInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<LegacyCommandDataInterface>() : PRIVATE_MAXON_VTABLE(LegacyCommandDataInterface, o_); 
	return (mt_._LegacyCommandDataInterface_SetLegacyData(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._LegacyCommandDataInterface_SetLegacyData_Offset, data, index));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LegacyCommandDataInterface::Hxx1::COWReferenceFunctionsImpl<S>::SetLegacyData(const Generic* data, Int index) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); LegacyCommandDataInterface* o_ = (LegacyCommandDataInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(LegacyCommandDataInterface, o_, LegacyCommandDataInterface_SetLegacyData) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<LegacyCommandDataInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<LegacyCommandDataInterface>() : PRIVATE_MAXON_VTABLE(LegacyCommandDataInterface, o_); 
	return (mt_._LegacyCommandDataInterface_SetLegacyData(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._LegacyCommandDataInterface_SetLegacyData_Offset, data, index));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LegacyCommandDataInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetLegacyDataCount() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const LegacyCommandDataInterface* o_ = (const LegacyCommandDataInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = LegacyCommandDataInterface::NullValuePtr(); if (!o_) return 0; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(LegacyCommandDataInterface, o_, LegacyCommandDataInterface_GetLegacyDataCount) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<LegacyCommandDataInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<LegacyCommandDataInterface>() : PRIVATE_MAXON_VTABLE(LegacyCommandDataInterface, o_); 
	return (mt_._LegacyCommandDataInterface_GetLegacyDataCount(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._LegacyCommandDataInterface_GetLegacyDataCount_Offset));
}
template <typename S> template <typename LEGACYDATA> MAXON_ATTRIBUTE_FORCE_INLINE auto LegacyCommandDataInterface::Hxx1::ReferenceFunctionsImpl<S>::SetLegacyData(const LEGACYDATA& data, Int index) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); LegacyCommandDataInterface* o_ = (LegacyCommandDataInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->SetLegacyData<LEGACYDATA>(data, index));
}
template <typename S> template <typename LEGACYDATA> MAXON_ATTRIBUTE_FORCE_INLINE auto LegacyCommandDataInterface::Hxx1::COWReferenceFunctionsImpl<S>::SetLegacyData(const LEGACYDATA& data, Int index) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION LegacyCommandDataInterface::SetLegacyData on super."); if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); LegacyCommandDataInterface* o_ = (LegacyCommandDataInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (o_->SetLegacyData<LEGACYDATA>(data, index));
}
template <typename S> template <typename LEGACYDATA> MAXON_ATTRIBUTE_FORCE_INLINE auto LegacyCommandDataInterface::Hxx1::ReferenceFunctionsImpl<S>::GetLegacyData(Int index) const -> Result<LEGACYDATA&>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<LEGACYDATA&>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); LegacyCommandDataInterface* o_ = (LegacyCommandDataInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->GetLegacyData<LEGACYDATA>(index));
}
template <typename S> template <typename LEGACYDATA> MAXON_ATTRIBUTE_FORCE_INLINE auto LegacyCommandDataInterface::Hxx1::COWReferenceFunctionsImpl<S>::GetLegacyData(Int index) -> Result<LEGACYDATA&>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<LEGACYDATA&>>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION LegacyCommandDataInterface::GetLegacyData on super."); if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); LegacyCommandDataInterface* o_ = (LegacyCommandDataInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (o_->GetLegacyData<LEGACYDATA>(index));
}
auto LegacyCommandDataInterface::GetPtr() -> Ptr { return Ptr(this); }
auto LegacyCommandDataInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_LegacyCommandDataInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_LegacyCommandDataInterface() { new (s_ui_maxon_LegacyCommandDataInterface) maxon::EntityUse(LegacyCommandDataInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/commandbase.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_LegacyCommandDataInterface(LegacyCommandDataInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/commandbase.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif

struct CommandClassInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Execute);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetState);
	static const maxon::Char* const _ids;
	static const maxon::Bool HAS_NONSTATIC = false;
	Result<COMMANDSTATE> (*_CommandClassInterface_GetState) (const maxon::GenericComponent* this_, CommandDataRef& data);
	maxon::Int _CommandClassInterface_GetState_Offset;
	Result<COMMANDRESULT> (*_CommandClassInterface_Execute) (const maxon::GenericComponent* this_, CommandDataRef& data);
	maxon::Int _CommandClassInterface_Execute_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CommandClassInterface, GetState))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CommandClassInterface, GetState), W, MTable>::type::_CommandClassInterface_GetState;
			_CommandClassInterface_GetState = reinterpret_cast<const decltype(_CommandClassInterface_GetState)&>(ptr);
			_CommandClassInterface_GetState_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CommandClassInterface, Execute))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CommandClassInterface, Execute), W, MTable>::type::_CommandClassInterface_Execute;
			_CommandClassInterface_Execute = reinterpret_cast<const decltype(_CommandClassInterface_Execute)&>(ptr);
			_CommandClassInterface_Execute_Offset = offset;
		}
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!ObjectInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<CommandClassInterface, typename ObjectInterface::MTable::template CombinedMTable<S>>;
	PRIVATE_MAXON_COMPBASE(CommandClassInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct CommandClassInterface::Hxx2
{
	template <typename S> class Wrapper : public ObjectInterface::Hxx2::template Wrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Execute);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetState);
	static Result<COMMANDSTATE> _CommandClassInterface_GetState(const maxon::GenericComponent* this_, CommandDataRef& data) { return ((const typename S::Implementation*) this_)->GetState(data); }
	static Result<COMMANDRESULT> _CommandClassInterface_Execute(const maxon::GenericComponent* this_, CommandDataRef& data) { return ((const typename S::Implementation*) this_)->Execute(data); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto CommandClassInterface::GetState(CommandDataRef& data) const -> Result<COMMANDSTATE>
{
	const CommandClassInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CommandClassInterface, this); return mt_._CommandClassInterface_GetState((const maxon::GenericComponent*) this + mt_._CommandClassInterface_GetState_Offset, data);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CommandClassInterface::Execute(CommandDataRef& data) const -> Result<COMMANDRESULT>
{
	const CommandClassInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CommandClassInterface, this); return mt_._CommandClassInterface_Execute((const maxon::GenericComponent*) this + mt_._CommandClassInterface_Execute_Offset, data);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CommandClassInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetState(CommandDataRef& data) const -> Result<COMMANDSTATE>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<COMMANDSTATE>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CommandClassInterface* o_ = (const CommandClassInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = CommandClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CommandClassInterface, o_, CommandClassInterface_GetState) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<CommandClassInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CommandClassInterface>() : PRIVATE_MAXON_VTABLE(CommandClassInterface, o_); 
	return (mt_._CommandClassInterface_GetState(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._CommandClassInterface_GetState_Offset, data));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CommandClassInterface::Hxx1::ConstReferenceFunctionsImpl<S>::Execute(CommandDataRef& data) const -> Result<COMMANDRESULT>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<COMMANDRESULT>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CommandClassInterface* o_ = (const CommandClassInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = CommandClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CommandClassInterface, o_, CommandClassInterface_Execute) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<CommandClassInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CommandClassInterface>() : PRIVATE_MAXON_VTABLE(CommandClassInterface, o_); 
	return (mt_._CommandClassInterface_Execute(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._CommandClassInterface_Execute_Offset, data));
}
auto CommandClassInterface::GetPtr() -> Ptr { return Ptr(this); }
auto CommandClassInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_CommandClassInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_CommandClassInterface() { new (s_ui_maxon_CommandClassInterface) maxon::EntityUse(CommandClassInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/commandbase.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_CommandClassInterface(CommandClassInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/commandbase.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif

struct CommandInteractionClassInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Interact);
	static const maxon::Char* const _ids;
	static const maxon::Bool HAS_NONSTATIC = false;
	Result<COMMANDRESULT> (*_CommandInteractionClassInterface_Interact) (const maxon::GenericComponent* this_, CommandDataRef& data, INTERACTIONTYPE interactionType);
	maxon::Int _CommandInteractionClassInterface_Interact_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CommandInteractionClassInterface, Interact))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CommandInteractionClassInterface, Interact), W, MTable>::type::_CommandInteractionClassInterface_Interact;
			_CommandInteractionClassInterface_Interact = reinterpret_cast<const decltype(_CommandInteractionClassInterface_Interact)&>(ptr);
			_CommandInteractionClassInterface_Interact_Offset = offset;
		}
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!ObjectInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<CommandInteractionClassInterface, typename ObjectInterface::MTable::template CombinedMTable<S>>;
	PRIVATE_MAXON_COMPBASE(CommandInteractionClassInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct CommandInteractionClassInterface::Hxx2
{
	template <typename S> class Wrapper : public ObjectInterface::Hxx2::template Wrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Interact);
	static Result<COMMANDRESULT> _CommandInteractionClassInterface_Interact(const maxon::GenericComponent* this_, CommandDataRef& data, INTERACTIONTYPE interactionType) { return ((const typename S::Implementation*) this_)->Interact(data, interactionType); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto CommandInteractionClassInterface::Interact(CommandDataRef& data, INTERACTIONTYPE interactionType) const -> Result<COMMANDRESULT>
{
	const CommandInteractionClassInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CommandInteractionClassInterface, this); return mt_._CommandInteractionClassInterface_Interact((const maxon::GenericComponent*) this + mt_._CommandInteractionClassInterface_Interact_Offset, data, interactionType);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CommandInteractionClassInterface::Hxx1::ConstReferenceFunctionsImpl<S>::Interact(CommandDataRef& data, INTERACTIONTYPE interactionType) const -> Result<COMMANDRESULT>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<COMMANDRESULT>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CommandInteractionClassInterface* o_ = (const CommandInteractionClassInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = CommandInteractionClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CommandInteractionClassInterface, o_, CommandInteractionClassInterface_Interact) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<CommandInteractionClassInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CommandInteractionClassInterface>() : PRIVATE_MAXON_VTABLE(CommandInteractionClassInterface, o_); 
	return (mt_._CommandInteractionClassInterface_Interact(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._CommandInteractionClassInterface_Interact_Offset, data, interactionType));
}
auto CommandInteractionClassInterface::GetPtr() -> Ptr { return Ptr(this); }
auto CommandInteractionClassInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_CommandInteractionClassInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_CommandInteractionClassInterface() { new (s_ui_maxon_CommandInteractionClassInterface) maxon::EntityUse(CommandInteractionClassInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/commandbase.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_CommandInteractionClassInterface(CommandInteractionClassInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/commandbase.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif

struct CommandDescriptionClassInterface::MTable
{
	static const maxon::Char* const _ids;
	static const maxon::Bool HAS_NONSTATIC = false;
	template <typename W> void Init(maxon::Int offset)
	{
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!DataDictionaryReferenceObjectInterface::MTable::template InitWithBases<W>(info, offset) || !DataDescriptionObjectInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<CommandDescriptionClassInterface, typename DataDescriptionObjectInterface::MTable::template CombinedMTable<typename DataDictionaryReferenceObjectInterface::MTable::template CombinedMTable<S>>>;
	PRIVATE_MAXON_COMPBASE(CommandDescriptionClassInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct CommandDescriptionClassInterface::Hxx2
{
	template <typename S> class Wrapper : public DataDescriptionObjectInterface::Hxx2::template Wrapper<typename DataDictionaryReferenceObjectInterface::Hxx2::template Wrapper<S>>
	{
	public:
	};

};

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CommandDescriptionClassInterface::Hxx1::ConstReferenceFunctionsImpl<S>::SetContext(CommandDataRef& data) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION CommandDescriptionClassInterface::SetContext on super."); if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CommandDescriptionClassInterface* o_ = (const CommandDescriptionClassInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = CommandDescriptionClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->SetContext(data));
}
auto CommandDescriptionClassInterface::GetPtr() -> Ptr { return Ptr(this); }
auto CommandDescriptionClassInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_CommandDescriptionClassInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_CommandDescriptionClassInterface() { new (s_ui_maxon_CommandDescriptionClassInterface) maxon::EntityUse(CommandDescriptionClassInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/commandbase.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_CommandDescriptionClassInterface(CommandDescriptionClassInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/commandbase.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif

struct LegacyCommandClassInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(ConvertSettings);
	static const maxon::Char* const _ids;
	static const maxon::Bool HAS_NONSTATIC = false;
	Result<void> (*_LegacyCommandClassInterface_ConvertSettings) (const maxon::GenericComponent* this_, LegacyCommandDataRef& data);
	maxon::Int _LegacyCommandClassInterface_ConvertSettings_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, LegacyCommandClassInterface, ConvertSettings))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, LegacyCommandClassInterface, ConvertSettings), W, MTable>::type::_LegacyCommandClassInterface_ConvertSettings;
			_LegacyCommandClassInterface_ConvertSettings = reinterpret_cast<const decltype(_LegacyCommandClassInterface_ConvertSettings)&>(ptr);
			_LegacyCommandClassInterface_ConvertSettings_Offset = offset;
		}
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!CommandClassInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<LegacyCommandClassInterface, typename CommandClassInterface::MTable::template CombinedMTable<S>>;
	PRIVATE_MAXON_COMPBASE(LegacyCommandClassInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct LegacyCommandClassInterface::Hxx2
{
	template <typename S> class Wrapper : public CommandClassInterface::Hxx2::template Wrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(ConvertSettings);
	static Result<void> _LegacyCommandClassInterface_ConvertSettings(const maxon::GenericComponent* this_, LegacyCommandDataRef& data) { return ((const typename S::Implementation*) this_)->ConvertSettings(data); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto LegacyCommandClassInterface::ConvertSettings(LegacyCommandDataRef& data) const -> Result<void>
{
	const LegacyCommandClassInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(LegacyCommandClassInterface, this); return mt_._LegacyCommandClassInterface_ConvertSettings((const maxon::GenericComponent*) this + mt_._LegacyCommandClassInterface_ConvertSettings_Offset, data);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LegacyCommandClassInterface::Hxx1::ConstReferenceFunctionsImpl<S>::ConvertSettings(LegacyCommandDataRef& data) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const LegacyCommandClassInterface* o_ = (const LegacyCommandClassInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = LegacyCommandClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(LegacyCommandClassInterface, o_, LegacyCommandClassInterface_ConvertSettings) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<LegacyCommandClassInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<LegacyCommandClassInterface>() : PRIVATE_MAXON_VTABLE(LegacyCommandClassInterface, o_); 
	return (mt_._LegacyCommandClassInterface_ConvertSettings(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._LegacyCommandClassInterface_ConvertSettings_Offset, data));
}
auto LegacyCommandClassInterface::GetPtr() -> Ptr { return Ptr(this); }
auto LegacyCommandClassInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_LegacyCommandClassInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_LegacyCommandClassInterface() { new (s_ui_maxon_LegacyCommandClassInterface) maxon::EntityUse(LegacyCommandClassInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/commandbase.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_LegacyCommandClassInterface(LegacyCommandClassInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/commandbase.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif

struct MigratedCommandClassInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetMigratedCommandId);
	static const maxon::Char* const _ids;
	static const maxon::Bool HAS_NONSTATIC = false;
	Int32 (*_MigratedCommandClassInterface_GetMigratedCommandId) (const maxon::GenericComponent* this_);
	maxon::Int _MigratedCommandClassInterface_GetMigratedCommandId_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MigratedCommandClassInterface, GetMigratedCommandId))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MigratedCommandClassInterface, GetMigratedCommandId), W, MTable>::type::_MigratedCommandClassInterface_GetMigratedCommandId;
			_MigratedCommandClassInterface_GetMigratedCommandId = reinterpret_cast<const decltype(_MigratedCommandClassInterface_GetMigratedCommandId)&>(ptr);
			_MigratedCommandClassInterface_GetMigratedCommandId_Offset = offset;
		}
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!LegacyCommandClassInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<MigratedCommandClassInterface, typename LegacyCommandClassInterface::MTable::template CombinedMTable<S>>;
	PRIVATE_MAXON_COMPBASE(MigratedCommandClassInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct MigratedCommandClassInterface::Hxx2
{
	template <typename S> class Wrapper : public LegacyCommandClassInterface::Hxx2::template Wrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetMigratedCommandId);
	static Int32 _MigratedCommandClassInterface_GetMigratedCommandId(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetMigratedCommandId(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto MigratedCommandClassInterface::GetMigratedCommandId() const -> Int32
{
	const MigratedCommandClassInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MigratedCommandClassInterface, this); return mt_._MigratedCommandClassInterface_GetMigratedCommandId((const maxon::GenericComponent*) this + mt_._MigratedCommandClassInterface_GetMigratedCommandId_Offset);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MigratedCommandClassInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetMigratedCommandId() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int32>, Int32>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int32>, Int32>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const MigratedCommandClassInterface* o_ = (const MigratedCommandClassInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = MigratedCommandClassInterface::NullValuePtr(); if (!o_) return 0; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MigratedCommandClassInterface, o_, MigratedCommandClassInterface_GetMigratedCommandId) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<MigratedCommandClassInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MigratedCommandClassInterface>() : PRIVATE_MAXON_VTABLE(MigratedCommandClassInterface, o_); 
	return (mt_._MigratedCommandClassInterface_GetMigratedCommandId(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._MigratedCommandClassInterface_GetMigratedCommandId_Offset));
}
auto MigratedCommandClassInterface::GetPtr() -> Ptr { return Ptr(this); }
auto MigratedCommandClassInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_MigratedCommandClassInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_MigratedCommandClassInterface() { new (s_ui_maxon_MigratedCommandClassInterface) maxon::EntityUse(MigratedCommandClassInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/commandbase.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_MigratedCommandClassInterface(MigratedCommandClassInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/commandbase.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif

struct CommandConversionClassInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(ConvertInput);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(ConvertOutput);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(ExecuteCustomActions);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetCommandId);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetLegacyCommandId);
	static const maxon::Char* const _ids;
	static const maxon::Bool HAS_NONSTATIC = false;
	Result<void> (*_CommandConversionClassInterface_ConvertInput) (const maxon::GenericComponent* this_, LegacyCommandDataRef& data);
	maxon::Int _CommandConversionClassInterface_ConvertInput_Offset;
	Result<void> (*_CommandConversionClassInterface_ExecuteCustomActions) (const maxon::GenericComponent* this_, LegacyCommandDataRef& data, Int actionId, Int flags);
	maxon::Int _CommandConversionClassInterface_ExecuteCustomActions_Offset;
	Result<void> (*_CommandConversionClassInterface_ConvertOutput) (const maxon::GenericComponent* this_, LegacyCommandDataRef& data);
	maxon::Int _CommandConversionClassInterface_ConvertOutput_Offset;
	Int32 (*_CommandConversionClassInterface_GetLegacyCommandId) (const maxon::GenericComponent* this_);
	maxon::Int _CommandConversionClassInterface_GetLegacyCommandId_Offset;
	Id (*_CommandConversionClassInterface_GetCommandId) (const maxon::GenericComponent* this_);
	maxon::Int _CommandConversionClassInterface_GetCommandId_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CommandConversionClassInterface, ConvertInput))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CommandConversionClassInterface, ConvertInput), W, MTable>::type::_CommandConversionClassInterface_ConvertInput;
			_CommandConversionClassInterface_ConvertInput = reinterpret_cast<const decltype(_CommandConversionClassInterface_ConvertInput)&>(ptr);
			_CommandConversionClassInterface_ConvertInput_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CommandConversionClassInterface, ExecuteCustomActions))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CommandConversionClassInterface, ExecuteCustomActions), W, MTable>::type::_CommandConversionClassInterface_ExecuteCustomActions;
			_CommandConversionClassInterface_ExecuteCustomActions = reinterpret_cast<const decltype(_CommandConversionClassInterface_ExecuteCustomActions)&>(ptr);
			_CommandConversionClassInterface_ExecuteCustomActions_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CommandConversionClassInterface, ConvertOutput))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CommandConversionClassInterface, ConvertOutput), W, MTable>::type::_CommandConversionClassInterface_ConvertOutput;
			_CommandConversionClassInterface_ConvertOutput = reinterpret_cast<const decltype(_CommandConversionClassInterface_ConvertOutput)&>(ptr);
			_CommandConversionClassInterface_ConvertOutput_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CommandConversionClassInterface, GetLegacyCommandId))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CommandConversionClassInterface, GetLegacyCommandId), W, MTable>::type::_CommandConversionClassInterface_GetLegacyCommandId;
			_CommandConversionClassInterface_GetLegacyCommandId = reinterpret_cast<const decltype(_CommandConversionClassInterface_GetLegacyCommandId)&>(ptr);
			_CommandConversionClassInterface_GetLegacyCommandId_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CommandConversionClassInterface, GetCommandId))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CommandConversionClassInterface, GetCommandId), W, MTable>::type::_CommandConversionClassInterface_GetCommandId;
			_CommandConversionClassInterface_GetCommandId = reinterpret_cast<const decltype(_CommandConversionClassInterface_GetCommandId)&>(ptr);
			_CommandConversionClassInterface_GetCommandId_Offset = offset;
		}
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!ObjectInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<CommandConversionClassInterface, typename ObjectInterface::MTable::template CombinedMTable<S>>;
	PRIVATE_MAXON_COMPBASE(CommandConversionClassInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct CommandConversionClassInterface::Hxx2
{
	template <typename S> class Wrapper : public ObjectInterface::Hxx2::template Wrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(ConvertInput);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(ConvertOutput);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(ExecuteCustomActions);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetCommandId);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetLegacyCommandId);
	static Result<void> _CommandConversionClassInterface_ConvertInput(const maxon::GenericComponent* this_, LegacyCommandDataRef& data) { return ((const typename S::Implementation*) this_)->ConvertInput(data); }
	static Result<void> _CommandConversionClassInterface_ExecuteCustomActions(const maxon::GenericComponent* this_, LegacyCommandDataRef& data, Int actionId, Int flags) { return ((const typename S::Implementation*) this_)->ExecuteCustomActions(data, actionId, flags); }
	static Result<void> _CommandConversionClassInterface_ConvertOutput(const maxon::GenericComponent* this_, LegacyCommandDataRef& data) { return ((const typename S::Implementation*) this_)->ConvertOutput(data); }
	static Int32 _CommandConversionClassInterface_GetLegacyCommandId(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetLegacyCommandId(); }
	static Id _CommandConversionClassInterface_GetCommandId(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetCommandId(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto CommandConversionClassInterface::ConvertInput(LegacyCommandDataRef& data) const -> Result<void>
{
	const CommandConversionClassInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CommandConversionClassInterface, this); return mt_._CommandConversionClassInterface_ConvertInput((const maxon::GenericComponent*) this + mt_._CommandConversionClassInterface_ConvertInput_Offset, data);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CommandConversionClassInterface::ExecuteCustomActions(LegacyCommandDataRef& data, Int actionId, Int flags) const -> Result<void>
{
	const CommandConversionClassInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CommandConversionClassInterface, this); return mt_._CommandConversionClassInterface_ExecuteCustomActions((const maxon::GenericComponent*) this + mt_._CommandConversionClassInterface_ExecuteCustomActions_Offset, data, actionId, flags);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CommandConversionClassInterface::ConvertOutput(LegacyCommandDataRef& data) const -> Result<void>
{
	const CommandConversionClassInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CommandConversionClassInterface, this); return mt_._CommandConversionClassInterface_ConvertOutput((const maxon::GenericComponent*) this + mt_._CommandConversionClassInterface_ConvertOutput_Offset, data);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CommandConversionClassInterface::GetLegacyCommandId() const -> Int32
{
	const CommandConversionClassInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CommandConversionClassInterface, this); return mt_._CommandConversionClassInterface_GetLegacyCommandId((const maxon::GenericComponent*) this + mt_._CommandConversionClassInterface_GetLegacyCommandId_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CommandConversionClassInterface::GetCommandId() const -> Id
{
	const CommandConversionClassInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CommandConversionClassInterface, this); return mt_._CommandConversionClassInterface_GetCommandId((const maxon::GenericComponent*) this + mt_._CommandConversionClassInterface_GetCommandId_Offset);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CommandConversionClassInterface::Hxx1::ConstReferenceFunctionsImpl<S>::ConvertInput(LegacyCommandDataRef& data) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CommandConversionClassInterface* o_ = (const CommandConversionClassInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = CommandConversionClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CommandConversionClassInterface, o_, CommandConversionClassInterface_ConvertInput) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<CommandConversionClassInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CommandConversionClassInterface>() : PRIVATE_MAXON_VTABLE(CommandConversionClassInterface, o_); 
	return (mt_._CommandConversionClassInterface_ConvertInput(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._CommandConversionClassInterface_ConvertInput_Offset, data));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CommandConversionClassInterface::Hxx1::ConstReferenceFunctionsImpl<S>::ExecuteCustomActions(LegacyCommandDataRef& data, Int actionId, Int flags) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CommandConversionClassInterface* o_ = (const CommandConversionClassInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = CommandConversionClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CommandConversionClassInterface, o_, CommandConversionClassInterface_ExecuteCustomActions) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<CommandConversionClassInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CommandConversionClassInterface>() : PRIVATE_MAXON_VTABLE(CommandConversionClassInterface, o_); 
	return (mt_._CommandConversionClassInterface_ExecuteCustomActions(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._CommandConversionClassInterface_ExecuteCustomActions_Offset, data, actionId, flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CommandConversionClassInterface::Hxx1::ConstReferenceFunctionsImpl<S>::ConvertOutput(LegacyCommandDataRef& data) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CommandConversionClassInterface* o_ = (const CommandConversionClassInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = CommandConversionClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CommandConversionClassInterface, o_, CommandConversionClassInterface_ConvertOutput) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<CommandConversionClassInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CommandConversionClassInterface>() : PRIVATE_MAXON_VTABLE(CommandConversionClassInterface, o_); 
	return (mt_._CommandConversionClassInterface_ConvertOutput(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._CommandConversionClassInterface_ConvertOutput_Offset, data));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CommandConversionClassInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetLegacyCommandId() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int32>, Int32>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int32>, Int32>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CommandConversionClassInterface* o_ = (const CommandConversionClassInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = CommandConversionClassInterface::NullValuePtr(); if (!o_) return 0; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CommandConversionClassInterface, o_, CommandConversionClassInterface_GetLegacyCommandId) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<CommandConversionClassInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CommandConversionClassInterface>() : PRIVATE_MAXON_VTABLE(CommandConversionClassInterface, o_); 
	return (mt_._CommandConversionClassInterface_GetLegacyCommandId(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._CommandConversionClassInterface_GetLegacyCommandId_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CommandConversionClassInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetCommandId() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Id>, Id>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Id>, Id>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CommandConversionClassInterface* o_ = (const CommandConversionClassInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = CommandConversionClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<Id>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CommandConversionClassInterface, o_, CommandConversionClassInterface_GetCommandId) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<CommandConversionClassInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CommandConversionClassInterface>() : PRIVATE_MAXON_VTABLE(CommandConversionClassInterface, o_); 
	return (mt_._CommandConversionClassInterface_GetCommandId(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._CommandConversionClassInterface_GetCommandId_Offset));
}
auto CommandConversionClassInterface::GetPtr() -> Ptr { return Ptr(this); }
auto CommandConversionClassInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_CommandConversionClassInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_CommandConversionClassInterface() { new (s_ui_maxon_CommandConversionClassInterface) maxon::EntityUse(CommandConversionClassInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/commandbase.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_CommandConversionClassInterface(CommandConversionClassInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/commandbase.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif

struct CommandCacheInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Init);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Reset);
	static const maxon::Char* const _ids;
	static const maxon::Bool HAS_NONSTATIC = false;
	Result<void> (*_CommandCacheInterface_Init) (maxon::GenericComponent* this_, CommandDataRef& data);
	maxon::Int _CommandCacheInterface_Init_Offset;
	void (*_CommandCacheInterface_Reset) (maxon::GenericComponent* this_);
	maxon::Int _CommandCacheInterface_Reset_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CommandCacheInterface, Init))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CommandCacheInterface, Init), W, MTable>::type::_CommandCacheInterface_Init;
			_CommandCacheInterface_Init = reinterpret_cast<const decltype(_CommandCacheInterface_Init)&>(ptr);
			_CommandCacheInterface_Init_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CommandCacheInterface, Reset))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CommandCacheInterface, Reset), W, MTable>::type::_CommandCacheInterface_Reset;
			_CommandCacheInterface_Reset = reinterpret_cast<const decltype(_CommandCacheInterface_Reset)&>(ptr);
			_CommandCacheInterface_Reset_Offset = offset;
		}
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!ObjectInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<CommandCacheInterface, typename ObjectInterface::MTable::template CombinedMTable<S>>;
	PRIVATE_MAXON_COMPBASE(CommandCacheInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct CommandCacheInterface::Hxx2
{
	template <typename S> class Wrapper : public ObjectInterface::Hxx2::template Wrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Init);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Reset);
	static Result<void> _CommandCacheInterface_Init(maxon::GenericComponent* this_, CommandDataRef& data) { return ((typename S::Implementation*) this_)->Init(data); }
	static void _CommandCacheInterface_Reset(maxon::GenericComponent* this_) { return ((typename S::Implementation*) this_)->Reset(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto CommandCacheInterface::Init(CommandDataRef& data) -> Result<void>
{
	const CommandCacheInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CommandCacheInterface, this); return mt_._CommandCacheInterface_Init((maxon::GenericComponent*) this + mt_._CommandCacheInterface_Init_Offset, data);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CommandCacheInterface::Reset() -> void
{
	const CommandCacheInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CommandCacheInterface, this); return mt_._CommandCacheInterface_Reset((maxon::GenericComponent*) this + mt_._CommandCacheInterface_Reset_Offset);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CommandCacheInterface::Hxx1::ReferenceFunctionsImpl<S>::Init(CommandDataRef& data) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CommandCacheInterface* o_ = (CommandCacheInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CommandCacheInterface, o_, CommandCacheInterface_Init) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<CommandCacheInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CommandCacheInterface>() : PRIVATE_MAXON_VTABLE(CommandCacheInterface, o_); 
	return (mt_._CommandCacheInterface_Init(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CommandCacheInterface_Init_Offset, data));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CommandCacheInterface::Hxx1::COWReferenceFunctionsImpl<S>::Init(CommandDataRef& data) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CommandCacheInterface* o_ = (CommandCacheInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CommandCacheInterface, o_, CommandCacheInterface_Init) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<CommandCacheInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CommandCacheInterface>() : PRIVATE_MAXON_VTABLE(CommandCacheInterface, o_); 
	return (mt_._CommandCacheInterface_Init(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CommandCacheInterface_Init_Offset, data));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CommandCacheInterface::Hxx1::ReferenceFunctionsImpl<S>::Reset() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CommandCacheInterface* o_ = (CommandCacheInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CommandCacheInterface, o_, CommandCacheInterface_Reset) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<CommandCacheInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CommandCacheInterface>() : PRIVATE_MAXON_VTABLE(CommandCacheInterface, o_); 
	mt_._CommandCacheInterface_Reset(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CommandCacheInterface_Reset_Offset);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CommandCacheInterface::Hxx1::COWReferenceFunctionsImpl<S>::Reset() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CommandCacheInterface* o_ = (CommandCacheInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CommandCacheInterface, o_, CommandCacheInterface_Reset) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<CommandCacheInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CommandCacheInterface>() : PRIVATE_MAXON_VTABLE(CommandCacheInterface, o_); 
	mt_._CommandCacheInterface_Reset(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CommandCacheInterface_Reset_Offset);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
auto CommandCacheInterface::GetPtr() -> Ptr { return Ptr(this); }
auto CommandCacheInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_CommandCacheInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_CommandCacheInterface() { new (s_ui_maxon_CommandCacheInterface) maxon::EntityUse(CommandCacheInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/commandbase.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_CommandCacheInterface(CommandCacheInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/commandbase.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif

struct CommandExecutionInterface::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = false;
	Result<COMMANDRESULT> (*_CommandExecutionInterface_Invoke) (const CommandClass& command, CommandDataRef& data, Bool interactive);
	Result<COMMANDRESULT> (*_CommandExecutionInterface_Invoke_1) (const CommandClass& command, CommandDataRef& data, Bool interactive, const CommandDataInterface::SetParameters& setParameters);
	Result<COMMANDRESULT> (*_CommandExecutionInterface_Interact) (CommandDataRef& data, INTERACTIONTYPE interactionType);
	template <typename IMPL> void Init()
	{
		_CommandExecutionInterface_Invoke = &IMPL::_CommandExecutionInterface_Invoke;
		_CommandExecutionInterface_Invoke_1 = &IMPL::_CommandExecutionInterface_Invoke_1;
		_CommandExecutionInterface_Interact = &IMPL::_CommandExecutionInterface_Interact;
	}
};

struct CommandExecutionInterface::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
	static Result<COMMANDRESULT> _CommandExecutionInterface_Invoke(const CommandClass& command, CommandDataRef& data, Bool interactive) { return C::Invoke(command, data, interactive); }
	static Result<COMMANDRESULT> _CommandExecutionInterface_Invoke_1(const CommandClass& command, CommandDataRef& data, Bool interactive, const CommandDataInterface::SetParameters& setParameters) { return C::Invoke(command, data, interactive, setParameters); }
	static Result<COMMANDRESULT> _CommandExecutionInterface_Interact(CommandDataRef& data, INTERACTIONTYPE interactionType) { return C::Interact(data, interactionType); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto CommandExecutionInterface::Invoke(const CommandClass& command, CommandDataRef& data, Bool interactive) -> Result<COMMANDRESULT>
{
	return MTable::_instance._CommandExecutionInterface_Invoke(command, data, interactive);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CommandExecutionInterface::Invoke(const CommandClass& command, CommandDataRef& data, Bool interactive, const CommandDataInterface::SetParameters& setParameters) -> Result<COMMANDRESULT>
{
	return MTable::_instance._CommandExecutionInterface_Invoke_1(command, data, interactive, setParameters);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CommandExecutionInterface::Interact(CommandDataRef& data, INTERACTIONTYPE interactionType) -> Result<COMMANDRESULT>
{
	return MTable::_instance._CommandExecutionInterface_Interact(data, interactionType);
}

#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_CommandExecutionInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_CommandExecutionInterface() { new (s_ui_maxon_CommandExecutionInterface) maxon::EntityUse(CommandExecutionInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/commandbase.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_CommandExecutionInterface(CommandExecutionInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/commandbase.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif


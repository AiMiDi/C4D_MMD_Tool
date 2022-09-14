
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
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	template <typename S> using CombinedMTable = maxon::CombinedMTable<CommandDataInterface, typename DataDictionaryObjectInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<CommandDataInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct CommandDataInterface::Hxx2
{
	template <typename S> class CWrapper : public DataDictionaryObjectInterface::Hxx2::template CWrapper<S>
	{
	public:
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename DataDictionaryObjectInterface::Hxx2::template CWrapper<S>;
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (CommandDataInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, CommandDataInterface::_interface); if (!vt) return false;
			return true;
		}
	};

};

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CommandDataInterface::Hxx1::Fn<S>::Invoke(const Id& command, Bool interactive) const -> Result<COMMANDRESULT>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<COMMANDRESULT>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); CommandDataInterface* o_ = (CommandDataInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->Invoke(command, interactive));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CommandDataInterface::Hxx1::COWFn<S>::Invoke(const Id& command, Bool interactive) -> Result<COMMANDRESULT>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<COMMANDRESULT>>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION CommandDataInterface::Invoke on super."); if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); CommandDataInterface* o_ = (CommandDataInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (o_->Invoke(command, interactive));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CommandDataInterface::Hxx1::Fn<S>::Invoke(const CommandClass& command, Bool interactive) const -> Result<COMMANDRESULT>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<COMMANDRESULT>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); CommandDataInterface* o_ = (CommandDataInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->Invoke(command, interactive));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CommandDataInterface::Hxx1::COWFn<S>::Invoke(const CommandClass& command, Bool interactive) -> Result<COMMANDRESULT>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<COMMANDRESULT>>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION CommandDataInterface::Invoke on super."); if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); CommandDataInterface* o_ = (CommandDataInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (o_->Invoke(command, interactive));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CommandDataInterface::Hxx1::Fn<S>::Invoke(const Id& command, Bool interactive, const SetParameters& setParameters) const -> Result<COMMANDRESULT>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<COMMANDRESULT>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); CommandDataInterface* o_ = (CommandDataInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->Invoke(command, interactive, setParameters));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CommandDataInterface::Hxx1::COWFn<S>::Invoke(const Id& command, Bool interactive, const SetParameters& setParameters) -> Result<COMMANDRESULT>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<COMMANDRESULT>>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION CommandDataInterface::Invoke on super."); if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); CommandDataInterface* o_ = (CommandDataInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (o_->Invoke(command, interactive, setParameters));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CommandDataInterface::Hxx1::Fn<S>::Invoke(const CommandClass& command, Bool interactive, const SetParameters& setParameters) const -> Result<COMMANDRESULT>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<COMMANDRESULT>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); CommandDataInterface* o_ = (CommandDataInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->Invoke(command, interactive, setParameters));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CommandDataInterface::Hxx1::COWFn<S>::Invoke(const CommandClass& command, Bool interactive, const SetParameters& setParameters) -> Result<COMMANDRESULT>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<COMMANDRESULT>>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION CommandDataInterface::Invoke on super."); if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); CommandDataInterface* o_ = (CommandDataInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (o_->Invoke(command, interactive, setParameters));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CommandDataInterface::Hxx1::Fn<S>::Interact(INTERACTIONTYPE interactionType) const -> Result<COMMANDRESULT>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<COMMANDRESULT>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); CommandDataInterface* o_ = (CommandDataInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->Interact(interactionType));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CommandDataInterface::Hxx1::COWFn<S>::Interact(INTERACTIONTYPE interactionType) -> Result<COMMANDRESULT>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<COMMANDRESULT>>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION CommandDataInterface::Interact on super."); if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); CommandDataInterface* o_ = (CommandDataInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (o_->Interact(interactionType));
}
template <typename S> template <typename... ARGS> MAXON_ATTRIBUTE_FORCE_INLINE auto CommandDataInterface::Hxx1::Fn<S>::Invoke(const CommandClass& command, Bool interactive, ARGS&&... args) const -> Result<COMMANDRESULT>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<COMMANDRESULT>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); CommandDataInterface* o_ = (CommandDataInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->Invoke<ARGS...>(command, interactive, std::forward<ARGS>(args)...));
}
template <typename S> template <typename... ARGS> MAXON_ATTRIBUTE_FORCE_INLINE auto CommandDataInterface::Hxx1::COWFn<S>::Invoke(const CommandClass& command, Bool interactive, ARGS&&... args) -> Result<COMMANDRESULT>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<COMMANDRESULT>>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION CommandDataInterface::Invoke on super."); if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); CommandDataInterface* o_ = (CommandDataInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (o_->Invoke<ARGS...>(command, interactive, std::forward<ARGS>(args)...));
}
auto CommandDataInterface::GetPtr() -> Ptr { return Ptr(this); }
auto CommandDataInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_commandbase)
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
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	PRIVATE_MAXON_MF_POINTER(LegacyCommandDataInterface_GetLegacyData, GetLegacyData, true, maxon::GenericComponent,, (Result<Generic*>), Int index);
	maxon::Int LegacyCommandDataInterface_GetLegacyData_Offset;
	PRIVATE_MAXON_MF_POINTER(LegacyCommandDataInterface_SetLegacyData, SetLegacyData, true, maxon::GenericComponent,, (Result<void>), const Generic* data, Int index);
	maxon::Int LegacyCommandDataInterface_SetLegacyData_Offset;
	PRIVATE_MAXON_MF_POINTER(LegacyCommandDataInterface_GetLegacyDataCount, GetLegacyDataCount, true, maxon::GenericComponent, const, (Int));
	maxon::Int LegacyCommandDataInterface_GetLegacyDataCount_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, LegacyCommandDataInterface, GetLegacyData))
	{
		maxon::Tie(LegacyCommandDataInterface_GetLegacyData, LegacyCommandDataInterface_GetLegacyData_Offset) = LegacyCommandDataInterface_GetLegacyData_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, LegacyCommandDataInterface, SetLegacyData))
	{
		maxon::Tie(LegacyCommandDataInterface_SetLegacyData, LegacyCommandDataInterface_SetLegacyData_Offset) = LegacyCommandDataInterface_SetLegacyData_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, LegacyCommandDataInterface, GetLegacyDataCount))
	{
		maxon::Tie(LegacyCommandDataInterface_GetLegacyDataCount, LegacyCommandDataInterface_GetLegacyDataCount_Offset) = LegacyCommandDataInterface_GetLegacyDataCount_GetPtr<W>(offset, true);
	}
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<LegacyCommandDataInterface, typename CommandDataInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<LegacyCommandDataInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct LegacyCommandDataInterface::Hxx2
{
	template <typename S> class CWrapper : public CommandDataInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetLegacyData);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetLegacyDataCount);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(SetLegacyData);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename CommandDataInterface::Hxx2::template CWrapper<S>;
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (LegacyCommandDataInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, LegacyCommandDataInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		PRIVATE_MAXON_MF_WRAPPER(LegacyCommandDataInterface_GetLegacyData, maxon::GenericComponent,, (Result<Generic*>), Int index) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->GetLegacyData(index); }
		PRIVATE_MAXON_MF_WRAPPER(LegacyCommandDataInterface_SetLegacyData, maxon::GenericComponent,, (Result<void>), const Generic* data, Int index) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->SetLegacyData(data, index); }
		PRIVATE_MAXON_MF_WRAPPER(LegacyCommandDataInterface_GetLegacyDataCount, maxon::GenericComponent, const, (Int)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetLegacyDataCount(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto LegacyCommandDataInterface::GetLegacyData(Int index) -> Result<Generic*>
{
	const LegacyCommandDataInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(LegacyCommandDataInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.LegacyCommandDataInterface_GetLegacyData_Offset), mt_.LegacyCommandDataInterface_GetLegacyData, index);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LegacyCommandDataInterface::SetLegacyData(const Generic* data, Int index) -> Result<void>
{
	const LegacyCommandDataInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(LegacyCommandDataInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.LegacyCommandDataInterface_SetLegacyData_Offset), mt_.LegacyCommandDataInterface_SetLegacyData, data, index);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LegacyCommandDataInterface::GetLegacyDataCount() const -> Int
{
	const LegacyCommandDataInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(LegacyCommandDataInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.LegacyCommandDataInterface_GetLegacyDataCount_Offset), mt_.LegacyCommandDataInterface_GetLegacyDataCount);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LegacyCommandDataInterface::Hxx1::Fn<S>::GetLegacyData(Int index) const -> Result<Generic*>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Generic*>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); LegacyCommandDataInterface* o_ = (LegacyCommandDataInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(LegacyCommandDataInterface, o_, LegacyCommandDataInterface_GetLegacyData) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<LegacyCommandDataInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<LegacyCommandDataInterface>() : PRIVATE_MAXON_VTABLE(LegacyCommandDataInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.LegacyCommandDataInterface_GetLegacyData_Offset), mt_.LegacyCommandDataInterface_GetLegacyData, index));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LegacyCommandDataInterface::Hxx1::COWFn<S>::GetLegacyData(Int index) -> Result<Generic*>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Generic*>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); LegacyCommandDataInterface* o_ = (LegacyCommandDataInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(LegacyCommandDataInterface, o_, LegacyCommandDataInterface_GetLegacyData) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<LegacyCommandDataInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<LegacyCommandDataInterface>() : PRIVATE_MAXON_VTABLE(LegacyCommandDataInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.LegacyCommandDataInterface_GetLegacyData_Offset), mt_.LegacyCommandDataInterface_GetLegacyData, index));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LegacyCommandDataInterface::Hxx1::Fn<S>::SetLegacyData(const Generic* data, Int index) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); LegacyCommandDataInterface* o_ = (LegacyCommandDataInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(LegacyCommandDataInterface, o_, LegacyCommandDataInterface_SetLegacyData) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<LegacyCommandDataInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<LegacyCommandDataInterface>() : PRIVATE_MAXON_VTABLE(LegacyCommandDataInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.LegacyCommandDataInterface_SetLegacyData_Offset), mt_.LegacyCommandDataInterface_SetLegacyData, data, index));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LegacyCommandDataInterface::Hxx1::COWFn<S>::SetLegacyData(const Generic* data, Int index) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); LegacyCommandDataInterface* o_ = (LegacyCommandDataInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(LegacyCommandDataInterface, o_, LegacyCommandDataInterface_SetLegacyData) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<LegacyCommandDataInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<LegacyCommandDataInterface>() : PRIVATE_MAXON_VTABLE(LegacyCommandDataInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.LegacyCommandDataInterface_SetLegacyData_Offset), mt_.LegacyCommandDataInterface_SetLegacyData, data, index));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LegacyCommandDataInterface::Hxx1::ConstFn<S>::GetLegacyDataCount() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const LegacyCommandDataInterface* o_ = (const LegacyCommandDataInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = LegacyCommandDataInterface::NullValuePtr(); if (!o_) return 0; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(LegacyCommandDataInterface, o_, LegacyCommandDataInterface_GetLegacyDataCount) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<LegacyCommandDataInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<LegacyCommandDataInterface>() : PRIVATE_MAXON_VTABLE(LegacyCommandDataInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.LegacyCommandDataInterface_GetLegacyDataCount_Offset), mt_.LegacyCommandDataInterface_GetLegacyDataCount));
}
template <typename S> template <typename LEGACYDATA> MAXON_ATTRIBUTE_FORCE_INLINE auto LegacyCommandDataInterface::Hxx1::Fn<S>::SetLegacyData(const LEGACYDATA& data, Int index) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); LegacyCommandDataInterface* o_ = (LegacyCommandDataInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->SetLegacyData<LEGACYDATA>(data, index));
}
template <typename S> template <typename LEGACYDATA> MAXON_ATTRIBUTE_FORCE_INLINE auto LegacyCommandDataInterface::Hxx1::COWFn<S>::SetLegacyData(const LEGACYDATA& data, Int index) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION LegacyCommandDataInterface::SetLegacyData on super."); if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); LegacyCommandDataInterface* o_ = (LegacyCommandDataInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (o_->SetLegacyData<LEGACYDATA>(data, index));
}
template <typename S> template <typename LEGACYDATA> MAXON_ATTRIBUTE_FORCE_INLINE auto LegacyCommandDataInterface::Hxx1::Fn<S>::GetLegacyData(Int index) const -> Result<LEGACYDATA&>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<LEGACYDATA&>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); LegacyCommandDataInterface* o_ = (LegacyCommandDataInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->GetLegacyData<LEGACYDATA>(index));
}
template <typename S> template <typename LEGACYDATA> MAXON_ATTRIBUTE_FORCE_INLINE auto LegacyCommandDataInterface::Hxx1::COWFn<S>::GetLegacyData(Int index) -> Result<LEGACYDATA&>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<LEGACYDATA&>>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION LegacyCommandDataInterface::GetLegacyData on super."); if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); LegacyCommandDataInterface* o_ = (LegacyCommandDataInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (o_->GetLegacyData<LEGACYDATA>(index));
}
auto LegacyCommandDataInterface::GetPtr() -> Ptr { return Ptr(this); }
auto LegacyCommandDataInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_commandbase)
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
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	PRIVATE_MAXON_MF_POINTER(CommandClassInterface_GetState, GetState, true, maxon::GenericComponent, const, (Result<COMMANDSTATE>), CommandDataRef& data);
	maxon::Int CommandClassInterface_GetState_Offset;
	PRIVATE_MAXON_MF_POINTER(CommandClassInterface_Execute, Execute, true, maxon::GenericComponent, const, (Result<COMMANDRESULT>), CommandDataRef& data);
	maxon::Int CommandClassInterface_Execute_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CommandClassInterface, GetState))
	{
		maxon::Tie(CommandClassInterface_GetState, CommandClassInterface_GetState_Offset) = CommandClassInterface_GetState_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CommandClassInterface, Execute))
	{
		maxon::Tie(CommandClassInterface_Execute, CommandClassInterface_Execute_Offset) = CommandClassInterface_Execute_GetPtr<W>(offset, true);
	}
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<CommandClassInterface, typename ObjectInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<CommandClassInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct CommandClassInterface::Hxx2
{
	template <typename S> class CWrapper : public ObjectInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Execute);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetState);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename ObjectInterface::Hxx2::template CWrapper<S>;
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (CommandClassInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, CommandClassInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		PRIVATE_MAXON_MF_WRAPPER(CommandClassInterface_GetState, maxon::GenericComponent, const, (Result<COMMANDSTATE>), CommandDataRef& data) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetState(data); }
		PRIVATE_MAXON_MF_WRAPPER(CommandClassInterface_Execute, maxon::GenericComponent, const, (Result<COMMANDRESULT>), CommandDataRef& data) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->Execute(data); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto CommandClassInterface::GetState(CommandDataRef& data) const -> Result<COMMANDSTATE>
{
	const CommandClassInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CommandClassInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.CommandClassInterface_GetState_Offset), mt_.CommandClassInterface_GetState, data);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CommandClassInterface::Execute(CommandDataRef& data) const -> Result<COMMANDRESULT>
{
	const CommandClassInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CommandClassInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.CommandClassInterface_Execute_Offset), mt_.CommandClassInterface_Execute, data);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CommandClassInterface::Hxx1::ConstFn<S>::GetState(CommandDataRef& data) const -> Result<COMMANDSTATE>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<COMMANDSTATE>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const CommandClassInterface* o_ = (const CommandClassInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = CommandClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CommandClassInterface, o_, CommandClassInterface_GetState) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<CommandClassInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CommandClassInterface>() : PRIVATE_MAXON_VTABLE(CommandClassInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.CommandClassInterface_GetState_Offset), mt_.CommandClassInterface_GetState, data));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CommandClassInterface::Hxx1::ConstFn<S>::Execute(CommandDataRef& data) const -> Result<COMMANDRESULT>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<COMMANDRESULT>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const CommandClassInterface* o_ = (const CommandClassInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = CommandClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CommandClassInterface, o_, CommandClassInterface_Execute) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<CommandClassInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CommandClassInterface>() : PRIVATE_MAXON_VTABLE(CommandClassInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.CommandClassInterface_Execute_Offset), mt_.CommandClassInterface_Execute, data));
}
auto CommandClassInterface::GetPtr() -> Ptr { return Ptr(this); }
auto CommandClassInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_commandbase)
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
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	PRIVATE_MAXON_MF_POINTER(CommandInteractionClassInterface_Interact, Interact, true, maxon::GenericComponent, const, (Result<COMMANDRESULT>), CommandDataRef& data, INTERACTIONTYPE interactionType);
	maxon::Int CommandInteractionClassInterface_Interact_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CommandInteractionClassInterface, Interact))
	{
		maxon::Tie(CommandInteractionClassInterface_Interact, CommandInteractionClassInterface_Interact_Offset) = CommandInteractionClassInterface_Interact_GetPtr<W>(offset, true);
	}
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<CommandInteractionClassInterface, typename ObjectInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<CommandInteractionClassInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct CommandInteractionClassInterface::Hxx2
{
	template <typename S> class CWrapper : public ObjectInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Interact);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename ObjectInterface::Hxx2::template CWrapper<S>;
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (CommandInteractionClassInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, CommandInteractionClassInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		PRIVATE_MAXON_MF_WRAPPER(CommandInteractionClassInterface_Interact, maxon::GenericComponent, const, (Result<COMMANDRESULT>), CommandDataRef& data, INTERACTIONTYPE interactionType) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->Interact(data, interactionType); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto CommandInteractionClassInterface::Interact(CommandDataRef& data, INTERACTIONTYPE interactionType) const -> Result<COMMANDRESULT>
{
	const CommandInteractionClassInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CommandInteractionClassInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.CommandInteractionClassInterface_Interact_Offset), mt_.CommandInteractionClassInterface_Interact, data, interactionType);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CommandInteractionClassInterface::Hxx1::ConstFn<S>::Interact(CommandDataRef& data, INTERACTIONTYPE interactionType) const -> Result<COMMANDRESULT>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<COMMANDRESULT>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const CommandInteractionClassInterface* o_ = (const CommandInteractionClassInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = CommandInteractionClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CommandInteractionClassInterface, o_, CommandInteractionClassInterface_Interact) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<CommandInteractionClassInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CommandInteractionClassInterface>() : PRIVATE_MAXON_VTABLE(CommandInteractionClassInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.CommandInteractionClassInterface_Interact_Offset), mt_.CommandInteractionClassInterface_Interact, data, interactionType));
}
auto CommandInteractionClassInterface::GetPtr() -> Ptr { return Ptr(this); }
auto CommandInteractionClassInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_commandbase)
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
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	template <typename S> using CombinedMTable = maxon::CombinedMTable<CommandDescriptionClassInterface, typename DataDescriptionObjectInterface::MTable::template CombinedMTable<typename DataDictionaryReferenceObjectInterface::MTable::template CombinedMTable<S>>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<CommandDescriptionClassInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct CommandDescriptionClassInterface::Hxx2
{
	template <typename S> class CWrapper : public DataDescriptionObjectInterface::Hxx2::template CWrapper<typename DataDictionaryReferenceObjectInterface::Hxx2::template CWrapper<S>>
	{
	public:
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename DataDictionaryReferenceObjectInterface::Hxx2::template CWrapper<S>;
			using Super1 = typename DataDescriptionObjectInterface::Hxx2::template CWrapper<Super0>;
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset) && Super1::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (CommandDescriptionClassInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, CommandDescriptionClassInterface::_interface); if (!vt) return false;
			return true;
		}
	};

};

auto CommandDescriptionClassInterface::GetPtr() -> Ptr { return Ptr(this); }
auto CommandDescriptionClassInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_commandbase)
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
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	PRIVATE_MAXON_MF_POINTER(LegacyCommandClassInterface_ConvertSettings, ConvertSettings, true, maxon::GenericComponent, const, (Result<void>), LegacyCommandDataRef& data);
	maxon::Int LegacyCommandClassInterface_ConvertSettings_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, LegacyCommandClassInterface, ConvertSettings))
	{
		maxon::Tie(LegacyCommandClassInterface_ConvertSettings, LegacyCommandClassInterface_ConvertSettings_Offset) = LegacyCommandClassInterface_ConvertSettings_GetPtr<W>(offset, true);
	}
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<LegacyCommandClassInterface, typename CommandClassInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<LegacyCommandClassInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct LegacyCommandClassInterface::Hxx2
{
	template <typename S> class CWrapper : public CommandClassInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(ConvertSettings);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename CommandClassInterface::Hxx2::template CWrapper<S>;
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (LegacyCommandClassInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, LegacyCommandClassInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		PRIVATE_MAXON_MF_WRAPPER(LegacyCommandClassInterface_ConvertSettings, maxon::GenericComponent, const, (Result<void>), LegacyCommandDataRef& data) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->ConvertSettings(data); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto LegacyCommandClassInterface::ConvertSettings(LegacyCommandDataRef& data) const -> Result<void>
{
	const LegacyCommandClassInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(LegacyCommandClassInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.LegacyCommandClassInterface_ConvertSettings_Offset), mt_.LegacyCommandClassInterface_ConvertSettings, data);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LegacyCommandClassInterface::Hxx1::ConstFn<S>::ConvertSettings(LegacyCommandDataRef& data) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const LegacyCommandClassInterface* o_ = (const LegacyCommandClassInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = LegacyCommandClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(LegacyCommandClassInterface, o_, LegacyCommandClassInterface_ConvertSettings) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<LegacyCommandClassInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<LegacyCommandClassInterface>() : PRIVATE_MAXON_VTABLE(LegacyCommandClassInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.LegacyCommandClassInterface_ConvertSettings_Offset), mt_.LegacyCommandClassInterface_ConvertSettings, data));
}
auto LegacyCommandClassInterface::GetPtr() -> Ptr { return Ptr(this); }
auto LegacyCommandClassInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_commandbase)
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
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	PRIVATE_MAXON_MF_POINTER(MigratedCommandClassInterface_GetMigratedCommandId, GetMigratedCommandId, true, maxon::GenericComponent, const, (Int32));
	maxon::Int MigratedCommandClassInterface_GetMigratedCommandId_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MigratedCommandClassInterface, GetMigratedCommandId))
	{
		maxon::Tie(MigratedCommandClassInterface_GetMigratedCommandId, MigratedCommandClassInterface_GetMigratedCommandId_Offset) = MigratedCommandClassInterface_GetMigratedCommandId_GetPtr<W>(offset, true);
	}
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<MigratedCommandClassInterface, typename LegacyCommandClassInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<MigratedCommandClassInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct MigratedCommandClassInterface::Hxx2
{
	template <typename S> class CWrapper : public LegacyCommandClassInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetMigratedCommandId);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename LegacyCommandClassInterface::Hxx2::template CWrapper<S>;
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (MigratedCommandClassInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, MigratedCommandClassInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		PRIVATE_MAXON_MF_WRAPPER(MigratedCommandClassInterface_GetMigratedCommandId, maxon::GenericComponent, const, (Int32)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetMigratedCommandId(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto MigratedCommandClassInterface::GetMigratedCommandId() const -> Int32
{
	const MigratedCommandClassInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MigratedCommandClassInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.MigratedCommandClassInterface_GetMigratedCommandId_Offset), mt_.MigratedCommandClassInterface_GetMigratedCommandId);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MigratedCommandClassInterface::Hxx1::ConstFn<S>::GetMigratedCommandId() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int32>, Int32>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int32>, Int32>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const MigratedCommandClassInterface* o_ = (const MigratedCommandClassInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = MigratedCommandClassInterface::NullValuePtr(); if (!o_) return 0; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MigratedCommandClassInterface, o_, MigratedCommandClassInterface_GetMigratedCommandId) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MigratedCommandClassInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MigratedCommandClassInterface>() : PRIVATE_MAXON_VTABLE(MigratedCommandClassInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.MigratedCommandClassInterface_GetMigratedCommandId_Offset), mt_.MigratedCommandClassInterface_GetMigratedCommandId));
}
auto MigratedCommandClassInterface::GetPtr() -> Ptr { return Ptr(this); }
auto MigratedCommandClassInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_commandbase)
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
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	PRIVATE_MAXON_MF_POINTER(CommandConversionClassInterface_ConvertInput, ConvertInput, true, maxon::GenericComponent, const, (Result<void>), LegacyCommandDataRef& data);
	maxon::Int CommandConversionClassInterface_ConvertInput_Offset;
	PRIVATE_MAXON_MF_POINTER(CommandConversionClassInterface_ExecuteCustomActions, ExecuteCustomActions, true, maxon::GenericComponent, const, (Result<void>), LegacyCommandDataRef& data, Int actionId, Int flags);
	maxon::Int CommandConversionClassInterface_ExecuteCustomActions_Offset;
	PRIVATE_MAXON_MF_POINTER(CommandConversionClassInterface_ConvertOutput, ConvertOutput, true, maxon::GenericComponent, const, (Result<void>), LegacyCommandDataRef& data);
	maxon::Int CommandConversionClassInterface_ConvertOutput_Offset;
	PRIVATE_MAXON_MF_POINTER(CommandConversionClassInterface_GetLegacyCommandId, GetLegacyCommandId, true, maxon::GenericComponent, const, (Int32));
	maxon::Int CommandConversionClassInterface_GetLegacyCommandId_Offset;
	PRIVATE_MAXON_MF_POINTER(CommandConversionClassInterface_GetCommandId, GetCommandId, true, maxon::GenericComponent, const, (Id));
	maxon::Int CommandConversionClassInterface_GetCommandId_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CommandConversionClassInterface, ConvertInput))
	{
		maxon::Tie(CommandConversionClassInterface_ConvertInput, CommandConversionClassInterface_ConvertInput_Offset) = CommandConversionClassInterface_ConvertInput_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CommandConversionClassInterface, ExecuteCustomActions))
	{
		maxon::Tie(CommandConversionClassInterface_ExecuteCustomActions, CommandConversionClassInterface_ExecuteCustomActions_Offset) = CommandConversionClassInterface_ExecuteCustomActions_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CommandConversionClassInterface, ConvertOutput))
	{
		maxon::Tie(CommandConversionClassInterface_ConvertOutput, CommandConversionClassInterface_ConvertOutput_Offset) = CommandConversionClassInterface_ConvertOutput_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CommandConversionClassInterface, GetLegacyCommandId))
	{
		maxon::Tie(CommandConversionClassInterface_GetLegacyCommandId, CommandConversionClassInterface_GetLegacyCommandId_Offset) = CommandConversionClassInterface_GetLegacyCommandId_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CommandConversionClassInterface, GetCommandId))
	{
		maxon::Tie(CommandConversionClassInterface_GetCommandId, CommandConversionClassInterface_GetCommandId_Offset) = CommandConversionClassInterface_GetCommandId_GetPtr<W>(offset, true);
	}
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<CommandConversionClassInterface, typename ObjectInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<CommandConversionClassInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct CommandConversionClassInterface::Hxx2
{
	template <typename S> class CWrapper : public ObjectInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(ConvertInput);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(ConvertOutput);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(ExecuteCustomActions);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetCommandId);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetLegacyCommandId);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename ObjectInterface::Hxx2::template CWrapper<S>;
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (CommandConversionClassInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, CommandConversionClassInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		PRIVATE_MAXON_MF_WRAPPER(CommandConversionClassInterface_ConvertInput, maxon::GenericComponent, const, (Result<void>), LegacyCommandDataRef& data) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->ConvertInput(data); }
		PRIVATE_MAXON_MF_WRAPPER(CommandConversionClassInterface_ExecuteCustomActions, maxon::GenericComponent, const, (Result<void>), LegacyCommandDataRef& data, Int actionId, Int flags) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->ExecuteCustomActions(data, actionId, flags); }
		PRIVATE_MAXON_MF_WRAPPER(CommandConversionClassInterface_ConvertOutput, maxon::GenericComponent, const, (Result<void>), LegacyCommandDataRef& data) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->ConvertOutput(data); }
		PRIVATE_MAXON_MF_WRAPPER(CommandConversionClassInterface_GetLegacyCommandId, maxon::GenericComponent, const, (Int32)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetLegacyCommandId(); }
		PRIVATE_MAXON_MF_WRAPPER(CommandConversionClassInterface_GetCommandId, maxon::GenericComponent, const, (Id)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetCommandId(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto CommandConversionClassInterface::ConvertInput(LegacyCommandDataRef& data) const -> Result<void>
{
	const CommandConversionClassInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CommandConversionClassInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.CommandConversionClassInterface_ConvertInput_Offset), mt_.CommandConversionClassInterface_ConvertInput, data);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CommandConversionClassInterface::ExecuteCustomActions(LegacyCommandDataRef& data, Int actionId, Int flags) const -> Result<void>
{
	const CommandConversionClassInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CommandConversionClassInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.CommandConversionClassInterface_ExecuteCustomActions_Offset), mt_.CommandConversionClassInterface_ExecuteCustomActions, data, actionId, flags);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CommandConversionClassInterface::ConvertOutput(LegacyCommandDataRef& data) const -> Result<void>
{
	const CommandConversionClassInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CommandConversionClassInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.CommandConversionClassInterface_ConvertOutput_Offset), mt_.CommandConversionClassInterface_ConvertOutput, data);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CommandConversionClassInterface::GetLegacyCommandId() const -> Int32
{
	const CommandConversionClassInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CommandConversionClassInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.CommandConversionClassInterface_GetLegacyCommandId_Offset), mt_.CommandConversionClassInterface_GetLegacyCommandId);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CommandConversionClassInterface::GetCommandId() const -> Id
{
	const CommandConversionClassInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CommandConversionClassInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.CommandConversionClassInterface_GetCommandId_Offset), mt_.CommandConversionClassInterface_GetCommandId);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CommandConversionClassInterface::Hxx1::ConstFn<S>::ConvertInput(LegacyCommandDataRef& data) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const CommandConversionClassInterface* o_ = (const CommandConversionClassInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = CommandConversionClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CommandConversionClassInterface, o_, CommandConversionClassInterface_ConvertInput) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<CommandConversionClassInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CommandConversionClassInterface>() : PRIVATE_MAXON_VTABLE(CommandConversionClassInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.CommandConversionClassInterface_ConvertInput_Offset), mt_.CommandConversionClassInterface_ConvertInput, data));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CommandConversionClassInterface::Hxx1::ConstFn<S>::ExecuteCustomActions(LegacyCommandDataRef& data, Int actionId, Int flags) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const CommandConversionClassInterface* o_ = (const CommandConversionClassInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = CommandConversionClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CommandConversionClassInterface, o_, CommandConversionClassInterface_ExecuteCustomActions) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<CommandConversionClassInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CommandConversionClassInterface>() : PRIVATE_MAXON_VTABLE(CommandConversionClassInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.CommandConversionClassInterface_ExecuteCustomActions_Offset), mt_.CommandConversionClassInterface_ExecuteCustomActions, data, actionId, flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CommandConversionClassInterface::Hxx1::ConstFn<S>::ConvertOutput(LegacyCommandDataRef& data) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const CommandConversionClassInterface* o_ = (const CommandConversionClassInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = CommandConversionClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CommandConversionClassInterface, o_, CommandConversionClassInterface_ConvertOutput) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<CommandConversionClassInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CommandConversionClassInterface>() : PRIVATE_MAXON_VTABLE(CommandConversionClassInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.CommandConversionClassInterface_ConvertOutput_Offset), mt_.CommandConversionClassInterface_ConvertOutput, data));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CommandConversionClassInterface::Hxx1::ConstFn<S>::GetLegacyCommandId() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int32>, Int32>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int32>, Int32>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const CommandConversionClassInterface* o_ = (const CommandConversionClassInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = CommandConversionClassInterface::NullValuePtr(); if (!o_) return 0; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CommandConversionClassInterface, o_, CommandConversionClassInterface_GetLegacyCommandId) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<CommandConversionClassInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CommandConversionClassInterface>() : PRIVATE_MAXON_VTABLE(CommandConversionClassInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.CommandConversionClassInterface_GetLegacyCommandId_Offset), mt_.CommandConversionClassInterface_GetLegacyCommandId));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CommandConversionClassInterface::Hxx1::ConstFn<S>::GetCommandId() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Id>, Id>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Id>, Id>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const CommandConversionClassInterface* o_ = (const CommandConversionClassInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = CommandConversionClassInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<Id>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CommandConversionClassInterface, o_, CommandConversionClassInterface_GetCommandId) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<CommandConversionClassInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CommandConversionClassInterface>() : PRIVATE_MAXON_VTABLE(CommandConversionClassInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.CommandConversionClassInterface_GetCommandId_Offset), mt_.CommandConversionClassInterface_GetCommandId));
}
auto CommandConversionClassInterface::GetPtr() -> Ptr { return Ptr(this); }
auto CommandConversionClassInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_commandbase)
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
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	PRIVATE_MAXON_MF_POINTER(CommandCacheInterface_Init, Init, true, maxon::GenericComponent,, (Result<void>), CommandDataRef& data);
	maxon::Int CommandCacheInterface_Init_Offset;
	PRIVATE_MAXON_MF_POINTER(CommandCacheInterface_Reset, Reset, true, maxon::GenericComponent,, (void));
	maxon::Int CommandCacheInterface_Reset_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CommandCacheInterface, Init))
	{
		maxon::Tie(CommandCacheInterface_Init, CommandCacheInterface_Init_Offset) = CommandCacheInterface_Init_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CommandCacheInterface, Reset))
	{
		maxon::Tie(CommandCacheInterface_Reset, CommandCacheInterface_Reset_Offset) = CommandCacheInterface_Reset_GetPtr<W>(offset, true);
	}
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<CommandCacheInterface, typename ObjectInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<CommandCacheInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct CommandCacheInterface::Hxx2
{
	template <typename S> class CWrapper : public ObjectInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Init);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Reset);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename ObjectInterface::Hxx2::template CWrapper<S>;
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (CommandCacheInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, CommandCacheInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		PRIVATE_MAXON_MF_WRAPPER(CommandCacheInterface_Init, maxon::GenericComponent,, (Result<void>), CommandDataRef& data) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->Init(data); }
		PRIVATE_MAXON_MF_WRAPPER(CommandCacheInterface_Reset, maxon::GenericComponent,, (void)) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->Reset(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto CommandCacheInterface::Init(CommandDataRef& data) -> Result<void>
{
	const CommandCacheInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CommandCacheInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.CommandCacheInterface_Init_Offset), mt_.CommandCacheInterface_Init, data);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CommandCacheInterface::Reset() -> void
{
	const CommandCacheInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CommandCacheInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.CommandCacheInterface_Reset_Offset), mt_.CommandCacheInterface_Reset);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CommandCacheInterface::Hxx1::Fn<S>::Init(CommandDataRef& data) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); CommandCacheInterface* o_ = (CommandCacheInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CommandCacheInterface, o_, CommandCacheInterface_Init) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<CommandCacheInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CommandCacheInterface>() : PRIVATE_MAXON_VTABLE(CommandCacheInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.CommandCacheInterface_Init_Offset), mt_.CommandCacheInterface_Init, data));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CommandCacheInterface::Hxx1::COWFn<S>::Init(CommandDataRef& data) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); CommandCacheInterface* o_ = (CommandCacheInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CommandCacheInterface, o_, CommandCacheInterface_Init) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<CommandCacheInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CommandCacheInterface>() : PRIVATE_MAXON_VTABLE(CommandCacheInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.CommandCacheInterface_Init_Offset), mt_.CommandCacheInterface_Init, data));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CommandCacheInterface::Hxx1::Fn<S>::Reset() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); CommandCacheInterface* o_ = (CommandCacheInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CommandCacheInterface, o_, CommandCacheInterface_Reset) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<CommandCacheInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CommandCacheInterface>() : PRIVATE_MAXON_VTABLE(CommandCacheInterface, o_); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.CommandCacheInterface_Reset_Offset), mt_.CommandCacheInterface_Reset);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CommandCacheInterface::Hxx1::COWFn<S>::Reset() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); CommandCacheInterface* o_ = (CommandCacheInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CommandCacheInterface, o_, CommandCacheInterface_Reset) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<CommandCacheInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CommandCacheInterface>() : PRIVATE_MAXON_VTABLE(CommandCacheInterface, o_); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.CommandCacheInterface_Reset_Offset), mt_.CommandCacheInterface_Reset);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
auto CommandCacheInterface::GetPtr() -> Ptr { return Ptr(this); }
auto CommandCacheInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_commandbase)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_CommandCacheInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_CommandCacheInterface() { new (s_ui_maxon_CommandCacheInterface) maxon::EntityUse(CommandCacheInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/commandbase.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_CommandCacheInterface(CommandCacheInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/commandbase.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
constexpr const maxon::Char* CommandExecutionInterface::PrivateGetCppName() { return nullptr; }

struct CommandExecutionInterface::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = false;
	PRIVATE_MAXON_SF_POINTER(CommandExecutionInterface_Invoke, Invoke, MAXON_EXPAND_VA_ARGS, (Result<COMMANDRESULT>), const CommandClass& command, CommandDataRef& data, Bool interactive);
	PRIVATE_MAXON_SF_POINTER(CommandExecutionInterface_Invoke_1, Invoke, MAXON_EXPAND_VA_ARGS, (Result<COMMANDRESULT>), const CommandClass& command, CommandDataRef& data, Bool interactive, const CommandDataInterface::SetParameters& setParameters);
	PRIVATE_MAXON_SF_POINTER(CommandExecutionInterface_Interact, Interact, MAXON_EXPAND_VA_ARGS, (Result<COMMANDRESULT>), CommandDataRef& data, INTERACTIONTYPE interactionType);
	template <typename IMPL> void Init()
	{
		CommandExecutionInterface_Invoke = CommandExecutionInterface_Invoke_GetPtr<IMPL>(true);
		CommandExecutionInterface_Invoke_1 = CommandExecutionInterface_Invoke_1_GetPtr<IMPL>(true);
		CommandExecutionInterface_Interact = CommandExecutionInterface_Interact_GetPtr<IMPL>(true);
	}
};

struct CommandExecutionInterface::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
		using Implementation = C;
		static Result<COMMANDRESULT> CommandExecutionInterface_Invoke(const CommandClass& command, CommandDataRef& data, Bool interactive) { return C::Invoke(command, data, interactive); }
		static Result<COMMANDRESULT> CommandExecutionInterface_Invoke_1(const CommandClass& command, CommandDataRef& data, Bool interactive, const CommandDataInterface::SetParameters& setParameters) { return C::Invoke(command, data, interactive, setParameters); }
		static Result<COMMANDRESULT> CommandExecutionInterface_Interact(CommandDataRef& data, INTERACTIONTYPE interactionType) { return C::Interact(data, interactionType); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto CommandExecutionInterface::Invoke(const CommandClass& command, CommandDataRef& data, Bool interactive) -> Result<COMMANDRESULT>
{
	return MTable::_instance.CommandExecutionInterface_Invoke(command, data, interactive);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CommandExecutionInterface::Invoke(const CommandClass& command, CommandDataRef& data, Bool interactive, const CommandDataInterface::SetParameters& setParameters) -> Result<COMMANDRESULT>
{
	return MTable::_instance.CommandExecutionInterface_Invoke_1(command, data, interactive, setParameters);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CommandExecutionInterface::Interact(CommandDataRef& data, INTERACTIONTYPE interactionType) -> Result<COMMANDRESULT>
{
	return MTable::_instance.CommandExecutionInterface_Interact(data, interactionType);
}

#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_commandbase)
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


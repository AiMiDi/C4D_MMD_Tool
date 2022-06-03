
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1

struct DescriptionProcessorInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Process);
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	Result<GenericData> (*DescriptionProcessorInterface_Process) (const maxon::GenericComponent* this_, const Id& descriptionId, const DataDescription& dataDescription);
	maxon::Int DescriptionProcessorInterface_Process_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DescriptionProcessorInterface, Process))
	{
		DescriptionProcessorInterface_Process = &W::DescriptionProcessorInterface_Process;
		DescriptionProcessorInterface_Process_Offset = offset;
	}
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<DescriptionProcessorInterface, typename ObjectInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<DescriptionProcessorInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct DescriptionProcessorInterface::Hxx2
{
	template <typename S> class CWrapper : public ObjectInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Process);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename ObjectInterface::Hxx2::template CWrapper<S>;
			if (!S::Implementation::PROXY && !(Super0::InitMTablesWithBases(info, offset))) return false;
			auto* vt = (DescriptionProcessorInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, DescriptionProcessorInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		static Result<GenericData> DescriptionProcessorInterface_Process(const maxon::GenericComponent* this_, const Id& descriptionId, const DataDescription& dataDescription) { return ((const typename S::Implementation*) this_)->Process(descriptionId, dataDescription); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto DescriptionProcessorInterface::Process(const Id& descriptionId, const DataDescription& dataDescription) const -> Result<GenericData>
{
	const DescriptionProcessorInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DescriptionProcessorInterface, this); return mt_.DescriptionProcessorInterface_Process((const maxon::GenericComponent*) this + mt_.DescriptionProcessorInterface_Process_Offset, descriptionId, dataDescription);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DescriptionProcessorInterface::Hxx1::ConstFn<S>::Process(const Id& descriptionId, const DataDescription& dataDescription) const -> Result<GenericData>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<GenericData>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DescriptionProcessorInterface* o_ = (const DescriptionProcessorInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DescriptionProcessorInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DescriptionProcessorInterface, o_, DescriptionProcessorInterface_Process) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DescriptionProcessorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DescriptionProcessorInterface>() : PRIVATE_MAXON_VTABLE(DescriptionProcessorInterface, o_); 
	return (mt_.DescriptionProcessorInterface_Process(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.DescriptionProcessorInterface_Process_Offset, descriptionId, dataDescription));
}
auto DescriptionProcessorInterface::GetPtr() -> Ptr { return Ptr(this); }
auto DescriptionProcessorInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_descriptionprocessor)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_DescriptionProcessorInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_DescriptionProcessorInterface() { new (s_ui_maxon_DescriptionProcessorInterface) maxon::EntityUse(DescriptionProcessorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/descriptionprocessor.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_DescriptionProcessorInterface(DescriptionProcessorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/descriptionprocessor.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif


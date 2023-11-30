
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
	PRIVATE_MAXON_MF_POINTER(DescriptionProcessorInterface_Process, Process, true, maxon::GenericComponent, const, (Result<GenericData>), const Id& descriptionId, const DataDescriptionDefinition& dataDescriptionDef, const DataDescription& dataDescription);
	maxon::Int DescriptionProcessorInterface_Process_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DescriptionProcessorInterface, Process))
	{
		maxon::Tie(DescriptionProcessorInterface_Process, DescriptionProcessorInterface_Process_Offset) = DescriptionProcessorInterface_Process_GetPtr<W>(offset, true);
	}
	}
	template <typename S> using CombinedMTable = maxon::PrivateCombinedMTable<DescriptionProcessorInterface, typename ObjectInterface::MTable::template CombinedMTable<S>>;
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
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (DescriptionProcessorInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, DescriptionProcessorInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		PRIVATE_MAXON_MF_WRAPPER(DescriptionProcessorInterface_Process, maxon::GenericComponent, const, (Result<GenericData>), const Id& descriptionId, const DataDescriptionDefinition& dataDescriptionDef, const DataDescription& dataDescription) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->Process(descriptionId, dataDescriptionDef, dataDescription); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto DescriptionProcessorInterface::Process(const Id& descriptionId, const DataDescriptionDefinition& dataDescriptionDef, const DataDescription& dataDescription) const -> Result<GenericData>
{
	const DescriptionProcessorInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DescriptionProcessorInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.DescriptionProcessorInterface_Process_Offset), mt_.DescriptionProcessorInterface_Process, descriptionId, dataDescriptionDef, dataDescription);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DescriptionProcessorInterface::Hxx1::ConstFn<S>::Process(const Id& descriptionId, const DataDescriptionDefinition& dataDescriptionDef, const DataDescription& dataDescription) const -> Result<GenericData>
{
	HXXRETURN0(Result<GenericData>); HXXRES; HXXCONST(HXXRET1(NULLPTR)) HXXTABLE(DescriptionProcessorInterface_Process); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.DescriptionProcessorInterface_Process_Offset), mt_.DescriptionProcessorInterface_Process, descriptionId, dataDescriptionDef, dataDescription));
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


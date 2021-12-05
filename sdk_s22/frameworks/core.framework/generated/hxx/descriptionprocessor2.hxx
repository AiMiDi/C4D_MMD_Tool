
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
	static const maxon::Bool HAS_NONSTATIC = false;
	Result<GenericData> (*_DescriptionProcessorInterface_Process) (const maxon::GenericComponent* this_, const Id& descriptionId, const DataDescription& dataDescription);
	maxon::Int _DescriptionProcessorInterface_Process_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DescriptionProcessorInterface, Process))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DescriptionProcessorInterface, Process), W, MTable>::type::_DescriptionProcessorInterface_Process;
			_DescriptionProcessorInterface_Process = reinterpret_cast<const decltype(_DescriptionProcessorInterface_Process)&>(ptr);
			_DescriptionProcessorInterface_Process_Offset = offset;
		}
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!ObjectInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<DescriptionProcessorInterface, typename ObjectInterface::MTable::template CombinedMTable<S>>;
	PRIVATE_MAXON_COMPBASE(DescriptionProcessorInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct DescriptionProcessorInterface::Hxx2
{
	template <typename S> class Wrapper : public ObjectInterface::Hxx2::template Wrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Process);
	static Result<GenericData> _DescriptionProcessorInterface_Process(const maxon::GenericComponent* this_, const Id& descriptionId, const DataDescription& dataDescription) { return ((const typename S::Implementation*) this_)->Process(descriptionId, dataDescription); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto DescriptionProcessorInterface::Process(const Id& descriptionId, const DataDescription& dataDescription) const -> Result<GenericData>
{
	const DescriptionProcessorInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DescriptionProcessorInterface, this); return mt_._DescriptionProcessorInterface_Process((const maxon::GenericComponent*) this + mt_._DescriptionProcessorInterface_Process_Offset, descriptionId, dataDescription);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DescriptionProcessorInterface::Hxx1::ConstReferenceFunctionsImpl<S>::Process(const Id& descriptionId, const DataDescription& dataDescription) const -> Result<GenericData>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<GenericData>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DescriptionProcessorInterface* o_ = (const DescriptionProcessorInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DescriptionProcessorInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DescriptionProcessorInterface, o_, DescriptionProcessorInterface_Process) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<DescriptionProcessorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DescriptionProcessorInterface>() : PRIVATE_MAXON_VTABLE(DescriptionProcessorInterface, o_); 
	return (mt_._DescriptionProcessorInterface_Process(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._DescriptionProcessorInterface_Process_Offset, descriptionId, dataDescription));
}
auto DescriptionProcessorInterface::GetPtr() -> Ptr { return Ptr(this); }
auto DescriptionProcessorInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
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


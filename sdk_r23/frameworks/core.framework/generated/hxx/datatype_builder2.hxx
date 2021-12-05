
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1

struct DataTypeBuilderInterface::MTable
{
	static const maxon::Char* const _ids;
	static const maxon::Bool HAS_NONSTATIC = false;
	template <typename W> void Init(maxon::Int offset)
	{
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!Object::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<DataTypeBuilderInterface, typename Object::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<DataTypeBuilderInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct DataTypeBuilderInterface::Hxx2
{
	class Unresolved;
	struct StaticMTable
	{
		static StaticMTable _instance;
		static StaticMTable _unresolvedInstance;
		static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, StaticMTable* tbl);
		static const maxon::Char* const _ids;
		static const maxon::NULL_RETURN_TYPE _returnTypes[];
	Result<String> (*_DataTypeBuilderInterface_GetDataTypeName) (const DataType& dt, DATATYPEBUILDERNAME category);
	Result<Tuple<String, Bool>> (*_DataTypeBuilderInterface_RecurseDataType) (DATATYPEBUILDERNAME category, const Member& dt, const ParametricTypeInterface* parentTypeId, Int& globalIdentifier, BaseArray<DataTypeComponent>& components);
		StaticMTable() = default;
		template <typename IMPL> static void Init(StaticMTable* tbl)
		{
		tbl->_DataTypeBuilderInterface_GetDataTypeName = &IMPL::_DataTypeBuilderInterface_GetDataTypeName;
		tbl->_DataTypeBuilderInterface_RecurseDataType = &IMPL::_DataTypeBuilderInterface_RecurseDataType;
		}
	};
	template <typename S> class CWrapper : public Object::Hxx2::template CWrapper<S>
	{
	public:
		static Result<String> _DataTypeBuilderInterface_GetDataTypeName(const DataType& dt, DATATYPEBUILDERNAME category) { return S::Implementation::GetDataTypeName(dt, category); }
		static Result<Tuple<String, Bool>> _DataTypeBuilderInterface_RecurseDataType(DATATYPEBUILDERNAME category, const Member& dt, const ParametricTypeInterface* parentTypeId, Int& globalIdentifier, BaseArray<DataTypeComponent>& components) { return S::Implementation::RecurseDataType(category, dt, parentTypeId, globalIdentifier, components); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeBuilderInterface::GetDataTypeName(const DataType& dt, DATATYPEBUILDERNAME category) -> Result<String>
{
	return Hxx2::StaticMTable::_instance._DataTypeBuilderInterface_GetDataTypeName(dt, category);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeBuilderInterface::RecurseDataType(DATATYPEBUILDERNAME category, const Member& dt, const ParametricTypeInterface* parentTypeId, Int& globalIdentifier, BaseArray<DataTypeComponent>& components) -> Result<Tuple<String, Bool>>
{
	return Hxx2::StaticMTable::_instance._DataTypeBuilderInterface_RecurseDataType(category, dt, parentTypeId, globalIdentifier, components);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeBuilderInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetDataTypeName(const DataType& dt, DATATYPEBUILDERNAME category) -> Result<String> { return (Hxx2::StaticMTable::_instance._DataTypeBuilderInterface_GetDataTypeName(dt, category)); }
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeBuilderInterface::Hxx1::ConstReferenceFunctionsImpl<S>::RecurseDataType(DATATYPEBUILDERNAME category, const Member& dt, const ParametricTypeInterface* parentTypeId, Int& globalIdentifier, BaseArray<DataTypeComponent>& components) -> Result<Tuple<String, Bool>> { return (Hxx2::StaticMTable::_instance._DataTypeBuilderInterface_RecurseDataType(category, dt, parentTypeId, globalIdentifier, components)); }
auto DataTypeBuilderInterface::GetPtr() -> Ptr { return Ptr(this); }
auto DataTypeBuilderInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_DataTypeBuilderInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_DataTypeBuilderInterface() { new (s_ui_maxon_DataTypeBuilderInterface) maxon::EntityUse(DataTypeBuilderInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/datatype_builder.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_DataTypeBuilderInterface(DataTypeBuilderInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/datatype_builder.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_usi_maxon_DataTypeBuilderInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_usi_maxon_DataTypeBuilderInterface() { new (s_usi_maxon_DataTypeBuilderInterface) maxon::EntityUse(DataTypeBuilderInterface::_staticInterface.GetReference(), &maxon::g_translationUnit, "maxon/datatype_builder.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_usi_maxon_DataTypeBuilderInterface(DataTypeBuilderInterface::_staticInterface.GetReference(), &maxon::g_translationUnit, "maxon/datatype_builder.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif


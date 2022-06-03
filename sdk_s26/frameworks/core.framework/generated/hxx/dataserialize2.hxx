
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1
#ifndef MAXON_COMPILER_CLANG
#endif
#ifndef MAXON_COMPILER_CLANG
#endif

struct DataSerializeInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(DescribeElement);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(PrepareHelperClass);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(RegisterDefaults);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(RegisterObjectSubstitution);
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	Result<void> (*DataSerializeInterface_DescribeElement) (const maxon::GenericComponent* this_, const Char* name, const DataType& dt, Int objectOffset, KeyValueConversionFunc* func, DESCRIBEFLAGS flags, UInt64 mask, UInt64 value);
	maxon::Int DataSerializeInterface_DescribeElement_Offset;
	Result<void> (*DataSerializeInterface_PrepareHelperClass) (const maxon::GenericComponent* this_, CreateIoHelperFunc* createFunc, DeleteIoHelperFunc* deleteFunc, ReadIoHelperFunc* readFunc, WriteIoHelperFunc* writeFunc, PREPAREHELPERFLAGS flags);
	maxon::Int DataSerializeInterface_PrepareHelperClass_Offset;
	Result<void> (*DataSerializeInterface_RegisterObjectSubstitution) (maxon::GenericComponent* this_, ReferenceSubstitutionFunction&& func);
	maxon::Int DataSerializeInterface_RegisterObjectSubstitution_Offset;
	Result<void*> (*DataSerializeInterface_RegisterDefaults) (const maxon::GenericComponent* this_, CreateIoHelperFunc* createFunc, DeleteIoHelperFunc* deleteFunc);
	maxon::Int DataSerializeInterface_RegisterDefaults_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataSerializeInterface, DescribeElement))
	{
		DataSerializeInterface_DescribeElement = &W::DataSerializeInterface_DescribeElement;
		DataSerializeInterface_DescribeElement_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataSerializeInterface, PrepareHelperClass))
	{
		DataSerializeInterface_PrepareHelperClass = &W::DataSerializeInterface_PrepareHelperClass;
		DataSerializeInterface_PrepareHelperClass_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataSerializeInterface, RegisterObjectSubstitution))
	{
		DataSerializeInterface_RegisterObjectSubstitution = &W::DataSerializeInterface_RegisterObjectSubstitution;
		DataSerializeInterface_RegisterObjectSubstitution_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataSerializeInterface, RegisterDefaults))
	{
		DataSerializeInterface_RegisterDefaults = &W::DataSerializeInterface_RegisterDefaults;
		DataSerializeInterface_RegisterDefaults_Offset = offset;
	}
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<DataSerializeInterface, typename ObjectInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<DataSerializeInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct DataSerializeInterface::Hxx2
{
	template <typename S> class CWrapper : public ObjectInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(DescribeElement);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(PrepareHelperClass);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(RegisterDefaults);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(RegisterObjectSubstitution);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename ObjectInterface::Hxx2::template CWrapper<S>;
			if (!S::Implementation::PROXY && !(Super0::InitMTablesWithBases(info, offset))) return false;
			auto* vt = (DataSerializeInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, DataSerializeInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		static Result<void> DataSerializeInterface_DescribeElement(const maxon::GenericComponent* this_, const Char* name, const DataType& dt, Int objectOffset, KeyValueConversionFunc* func, DESCRIBEFLAGS flags, UInt64 mask, UInt64 value) { return ((const typename S::Implementation*) this_)->DescribeElement(name, dt, objectOffset, func, flags, mask, value); }
		static Result<void> DataSerializeInterface_PrepareHelperClass(const maxon::GenericComponent* this_, CreateIoHelperFunc* createFunc, DeleteIoHelperFunc* deleteFunc, ReadIoHelperFunc* readFunc, WriteIoHelperFunc* writeFunc, PREPAREHELPERFLAGS flags) { return ((const typename S::Implementation*) this_)->PrepareHelperClass(createFunc, deleteFunc, readFunc, writeFunc, flags); }
		static Result<void> DataSerializeInterface_RegisterObjectSubstitution(maxon::GenericComponent* this_, ReferenceSubstitutionFunction&& func) { return ((typename S::Implementation*) this_)->RegisterObjectSubstitution(std::forward<ReferenceSubstitutionFunction>(func)); }
		static Result<void*> DataSerializeInterface_RegisterDefaults(const maxon::GenericComponent* this_, CreateIoHelperFunc* createFunc, DeleteIoHelperFunc* deleteFunc) { return ((const typename S::Implementation*) this_)->RegisterDefaults(createFunc, deleteFunc); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto DataSerializeInterface::DescribeElement(const Char* name, const DataType& dt, Int objectOffset, KeyValueConversionFunc* func, DESCRIBEFLAGS flags, UInt64 mask, UInt64 value) const -> Result<void>
{
	const DataSerializeInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataSerializeInterface, this); return mt_.DataSerializeInterface_DescribeElement((const maxon::GenericComponent*) this + mt_.DataSerializeInterface_DescribeElement_Offset, name, dt, objectOffset, func, flags, mask, value);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataSerializeInterface::PrepareHelperClass(CreateIoHelperFunc* createFunc, DeleteIoHelperFunc* deleteFunc, ReadIoHelperFunc* readFunc, WriteIoHelperFunc* writeFunc, PREPAREHELPERFLAGS flags) const -> Result<void>
{
	const DataSerializeInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataSerializeInterface, this); return mt_.DataSerializeInterface_PrepareHelperClass((const maxon::GenericComponent*) this + mt_.DataSerializeInterface_PrepareHelperClass_Offset, createFunc, deleteFunc, readFunc, writeFunc, flags);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataSerializeInterface::RegisterObjectSubstitution(ReferenceSubstitutionFunction&& func) -> Result<void>
{
	const DataSerializeInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataSerializeInterface, this); return mt_.DataSerializeInterface_RegisterObjectSubstitution((maxon::GenericComponent*) this + mt_.DataSerializeInterface_RegisterObjectSubstitution_Offset, std::forward<ReferenceSubstitutionFunction>(func));
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataSerializeInterface::RegisterDefaults(CreateIoHelperFunc* createFunc, DeleteIoHelperFunc* deleteFunc) const -> Result<void*>
{
	const DataSerializeInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataSerializeInterface, this); return mt_.DataSerializeInterface_RegisterDefaults((const maxon::GenericComponent*) this + mt_.DataSerializeInterface_RegisterDefaults_Offset, createFunc, deleteFunc);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataSerializeInterface::Hxx1::ConstFn<S>::DescribeElement(const Char* name, const DataType& dt, Int objectOffset, KeyValueConversionFunc* func, DESCRIBEFLAGS flags, UInt64 mask, UInt64 value) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DataSerializeInterface* o_ = (const DataSerializeInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DataSerializeInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataSerializeInterface, o_, DataSerializeInterface_DescribeElement) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DataSerializeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataSerializeInterface>() : PRIVATE_MAXON_VTABLE(DataSerializeInterface, o_); 
	return (mt_.DataSerializeInterface_DescribeElement(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.DataSerializeInterface_DescribeElement_Offset, name, dt, objectOffset, func, flags, mask, value));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataSerializeInterface::Hxx1::ConstFn<S>::PrepareHelperClass(CreateIoHelperFunc* createFunc, DeleteIoHelperFunc* deleteFunc, ReadIoHelperFunc* readFunc, WriteIoHelperFunc* writeFunc, PREPAREHELPERFLAGS flags) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DataSerializeInterface* o_ = (const DataSerializeInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DataSerializeInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataSerializeInterface, o_, DataSerializeInterface_PrepareHelperClass) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DataSerializeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataSerializeInterface>() : PRIVATE_MAXON_VTABLE(DataSerializeInterface, o_); 
	return (mt_.DataSerializeInterface_PrepareHelperClass(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.DataSerializeInterface_PrepareHelperClass_Offset, createFunc, deleteFunc, readFunc, writeFunc, flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataSerializeInterface::Hxx1::Fn<S>::RegisterObjectSubstitution(ReferenceSubstitutionFunction&& func) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataSerializeInterface* o_ = (DataSerializeInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataSerializeInterface, o_, DataSerializeInterface_RegisterObjectSubstitution) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DataSerializeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataSerializeInterface>() : PRIVATE_MAXON_VTABLE(DataSerializeInterface, o_); 
	return (mt_.DataSerializeInterface_RegisterObjectSubstitution(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataSerializeInterface_RegisterObjectSubstitution_Offset, std::forward<ReferenceSubstitutionFunction>(func)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataSerializeInterface::Hxx1::COWFn<S>::RegisterObjectSubstitution(ReferenceSubstitutionFunction&& func) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataSerializeInterface* o_ = (DataSerializeInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataSerializeInterface, o_, DataSerializeInterface_RegisterObjectSubstitution) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DataSerializeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataSerializeInterface>() : PRIVATE_MAXON_VTABLE(DataSerializeInterface, o_); 
	return (mt_.DataSerializeInterface_RegisterObjectSubstitution(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataSerializeInterface_RegisterObjectSubstitution_Offset, std::forward<ReferenceSubstitutionFunction>(func)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataSerializeInterface::Hxx1::ConstFn<S>::RegisterDefaults(CreateIoHelperFunc* createFunc, DeleteIoHelperFunc* deleteFunc) const -> Result<void*>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void*>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DataSerializeInterface* o_ = (const DataSerializeInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DataSerializeInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataSerializeInterface, o_, DataSerializeInterface_RegisterDefaults) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DataSerializeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataSerializeInterface>() : PRIVATE_MAXON_VTABLE(DataSerializeInterface, o_); 
	return (mt_.DataSerializeInterface_RegisterDefaults(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.DataSerializeInterface_RegisterDefaults_Offset, createFunc, deleteFunc));
}
auto DataSerializeInterface::GetPtr() -> Ptr { return Ptr(this); }
auto DataSerializeInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_dataserialize)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_DataSerializeInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_DataSerializeInterface() { new (s_ui_maxon_DataSerializeInterface) maxon::EntityUse(DataSerializeInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/dataserialize.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_DataSerializeInterface(DataSerializeInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/dataserialize.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif

struct DataSerializeWriterInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(WriteDocument);
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	Result<void> (*DataSerializeWriterInterface_WriteDocument) (maxon::GenericComponent* this_, const Id& id, const ConstDataPtr& data);
	maxon::Int DataSerializeWriterInterface_WriteDocument_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataSerializeWriterInterface, WriteDocument))
	{
		DataSerializeWriterInterface_WriteDocument = &W::DataSerializeWriterInterface_WriteDocument;
		DataSerializeWriterInterface_WriteDocument_Offset = offset;
	}
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<DataSerializeWriterInterface, typename DataSerializeInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<DataSerializeWriterInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct DataSerializeWriterInterface::Hxx2
{
	template <typename S> class CWrapper : public DataSerializeInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(WriteDocument);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename DataSerializeInterface::Hxx2::template CWrapper<S>;
			if (!S::Implementation::PROXY && !(Super0::InitMTablesWithBases(info, offset))) return false;
			auto* vt = (DataSerializeWriterInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, DataSerializeWriterInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		static Result<void> DataSerializeWriterInterface_WriteDocument(maxon::GenericComponent* this_, const Id& id, const ConstDataPtr& data) { return ((typename S::Implementation*) this_)->WriteDocument(id, data); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto DataSerializeWriterInterface::WriteDocument(const Id& id, const ConstDataPtr& data) -> Result<void>
{
	const DataSerializeWriterInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataSerializeWriterInterface, this); return mt_.DataSerializeWriterInterface_WriteDocument((maxon::GenericComponent*) this + mt_.DataSerializeWriterInterface_WriteDocument_Offset, id, data);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataSerializeWriterInterface::Hxx1::Fn<S>::WriteDocument(const Id& id, const ConstDataPtr& data) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataSerializeWriterInterface* o_ = (DataSerializeWriterInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataSerializeWriterInterface, o_, DataSerializeWriterInterface_WriteDocument) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DataSerializeWriterInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataSerializeWriterInterface>() : PRIVATE_MAXON_VTABLE(DataSerializeWriterInterface, o_); 
	return (mt_.DataSerializeWriterInterface_WriteDocument(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataSerializeWriterInterface_WriteDocument_Offset, id, data));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataSerializeWriterInterface::Hxx1::COWFn<S>::WriteDocument(const Id& id, const ConstDataPtr& data) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataSerializeWriterInterface* o_ = (DataSerializeWriterInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataSerializeWriterInterface, o_, DataSerializeWriterInterface_WriteDocument) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DataSerializeWriterInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataSerializeWriterInterface>() : PRIVATE_MAXON_VTABLE(DataSerializeWriterInterface, o_); 
	return (mt_.DataSerializeWriterInterface_WriteDocument(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataSerializeWriterInterface_WriteDocument_Offset, id, data));
}
auto DataSerializeWriterInterface::GetPtr() -> Ptr { return Ptr(this); }
auto DataSerializeWriterInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_dataserialize)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_DataSerializeWriterInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_DataSerializeWriterInterface() { new (s_ui_maxon_DataSerializeWriterInterface) maxon::EntityUse(DataSerializeWriterInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/dataserialize.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_DataSerializeWriterInterface(DataSerializeWriterInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/dataserialize.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif

struct DataSerializeReaderInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(ReadDocument);
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	Result<void> (*DataSerializeReaderInterface_ReadDocument) (maxon::GenericComponent* this_, const Id& id, const DataPtr& data);
	maxon::Int DataSerializeReaderInterface_ReadDocument_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataSerializeReaderInterface, ReadDocument))
	{
		DataSerializeReaderInterface_ReadDocument = &W::DataSerializeReaderInterface_ReadDocument;
		DataSerializeReaderInterface_ReadDocument_Offset = offset;
	}
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<DataSerializeReaderInterface, typename DataSerializeInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<DataSerializeReaderInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct DataSerializeReaderInterface::Hxx2
{
	template <typename S> class CWrapper : public DataSerializeInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(ReadDocument);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename DataSerializeInterface::Hxx2::template CWrapper<S>;
			if (!S::Implementation::PROXY && !(Super0::InitMTablesWithBases(info, offset))) return false;
			auto* vt = (DataSerializeReaderInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, DataSerializeReaderInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		static Result<void> DataSerializeReaderInterface_ReadDocument(maxon::GenericComponent* this_, const Id& id, const DataPtr& data) { return ((typename S::Implementation*) this_)->ReadDocument(id, data); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto DataSerializeReaderInterface::ReadDocument(const Id& id, const DataPtr& data) -> Result<void>
{
	const DataSerializeReaderInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataSerializeReaderInterface, this); return mt_.DataSerializeReaderInterface_ReadDocument((maxon::GenericComponent*) this + mt_.DataSerializeReaderInterface_ReadDocument_Offset, id, data);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataSerializeReaderInterface::Hxx1::Fn<S>::ReadDocument(const Id& id, const DataPtr& data) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataSerializeReaderInterface* o_ = (DataSerializeReaderInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataSerializeReaderInterface, o_, DataSerializeReaderInterface_ReadDocument) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DataSerializeReaderInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataSerializeReaderInterface>() : PRIVATE_MAXON_VTABLE(DataSerializeReaderInterface, o_); 
	return (mt_.DataSerializeReaderInterface_ReadDocument(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataSerializeReaderInterface_ReadDocument_Offset, id, data));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataSerializeReaderInterface::Hxx1::COWFn<S>::ReadDocument(const Id& id, const DataPtr& data) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataSerializeReaderInterface* o_ = (DataSerializeReaderInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataSerializeReaderInterface, o_, DataSerializeReaderInterface_ReadDocument) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DataSerializeReaderInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataSerializeReaderInterface>() : PRIVATE_MAXON_VTABLE(DataSerializeReaderInterface, o_); 
	return (mt_.DataSerializeReaderInterface_ReadDocument(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataSerializeReaderInterface_ReadDocument_Offset, id, data));
}
auto DataSerializeReaderInterface::GetPtr() -> Ptr { return Ptr(this); }
auto DataSerializeReaderInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_dataserialize)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_DataSerializeReaderInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_DataSerializeReaderInterface() { new (s_ui_maxon_DataSerializeReaderInterface) maxon::EntityUse(DataSerializeReaderInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/dataserialize.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_DataSerializeReaderInterface(DataSerializeReaderInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/dataserialize.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif



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
	static const maxon::Bool HAS_NONSTATIC = false;
	Result<void> (*_DataSerializeInterface_DescribeElement) (const maxon::GenericComponent* this_, const Char* name, const DataType& dt, Int objectOffset, KeyValueConversionFunc* func, DESCRIBEFLAGS flags, UInt64 mask, UInt64 value);
	maxon::Int _DataSerializeInterface_DescribeElement_Offset;
	Result<void> (*_DataSerializeInterface_PrepareHelperClass) (const maxon::GenericComponent* this_, CreateIoHelperFunc* createFunc, DeleteIoHelperFunc* deleteFunc, ReadIoHelperFunc* readFunc, WriteIoHelperFunc* writeFunc, PREPAREHELPERFLAGS flags);
	maxon::Int _DataSerializeInterface_PrepareHelperClass_Offset;
	Result<void> (*_DataSerializeInterface_RegisterObjectSubstitution) (maxon::GenericComponent* this_, ReferenceSubstitutionFunction&& func);
	maxon::Int _DataSerializeInterface_RegisterObjectSubstitution_Offset;
	Result<void*> (*_DataSerializeInterface_RegisterDefaults) (const maxon::GenericComponent* this_, CreateIoHelperFunc* createFunc, DeleteIoHelperFunc* deleteFunc);
	maxon::Int _DataSerializeInterface_RegisterDefaults_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataSerializeInterface, DescribeElement))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataSerializeInterface, DescribeElement), W, MTable>::type::_DataSerializeInterface_DescribeElement;
			_DataSerializeInterface_DescribeElement = reinterpret_cast<const decltype(_DataSerializeInterface_DescribeElement)&>(ptr);
			_DataSerializeInterface_DescribeElement_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataSerializeInterface, PrepareHelperClass))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataSerializeInterface, PrepareHelperClass), W, MTable>::type::_DataSerializeInterface_PrepareHelperClass;
			_DataSerializeInterface_PrepareHelperClass = reinterpret_cast<const decltype(_DataSerializeInterface_PrepareHelperClass)&>(ptr);
			_DataSerializeInterface_PrepareHelperClass_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataSerializeInterface, RegisterObjectSubstitution))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataSerializeInterface, RegisterObjectSubstitution), W, MTable>::type::_DataSerializeInterface_RegisterObjectSubstitution;
			_DataSerializeInterface_RegisterObjectSubstitution = reinterpret_cast<const decltype(_DataSerializeInterface_RegisterObjectSubstitution)&>(ptr);
			_DataSerializeInterface_RegisterObjectSubstitution_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataSerializeInterface, RegisterDefaults))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataSerializeInterface, RegisterDefaults), W, MTable>::type::_DataSerializeInterface_RegisterDefaults;
			_DataSerializeInterface_RegisterDefaults = reinterpret_cast<const decltype(_DataSerializeInterface_RegisterDefaults)&>(ptr);
			_DataSerializeInterface_RegisterDefaults_Offset = offset;
		}
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!ObjectInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<DataSerializeInterface, typename ObjectInterface::MTable::template CombinedMTable<S>>;
	PRIVATE_MAXON_COMPBASE(DataSerializeInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct DataSerializeInterface::Hxx2
{
	template <typename S> class Wrapper : public ObjectInterface::Hxx2::template Wrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(DescribeElement);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(PrepareHelperClass);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(RegisterDefaults);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(RegisterObjectSubstitution);
	static Result<void> _DataSerializeInterface_DescribeElement(const maxon::GenericComponent* this_, const Char* name, const DataType& dt, Int objectOffset, KeyValueConversionFunc* func, DESCRIBEFLAGS flags, UInt64 mask, UInt64 value) { return ((const typename S::Implementation*) this_)->DescribeElement(name, dt, objectOffset, func, flags, mask, value); }
	static Result<void> _DataSerializeInterface_PrepareHelperClass(const maxon::GenericComponent* this_, CreateIoHelperFunc* createFunc, DeleteIoHelperFunc* deleteFunc, ReadIoHelperFunc* readFunc, WriteIoHelperFunc* writeFunc, PREPAREHELPERFLAGS flags) { return ((const typename S::Implementation*) this_)->PrepareHelperClass(createFunc, deleteFunc, readFunc, writeFunc, flags); }
	static Result<void> _DataSerializeInterface_RegisterObjectSubstitution(maxon::GenericComponent* this_, ReferenceSubstitutionFunction&& func) { return ((typename S::Implementation*) this_)->RegisterObjectSubstitution(std::forward<ReferenceSubstitutionFunction>(func)); }
	static Result<void*> _DataSerializeInterface_RegisterDefaults(const maxon::GenericComponent* this_, CreateIoHelperFunc* createFunc, DeleteIoHelperFunc* deleteFunc) { return ((const typename S::Implementation*) this_)->RegisterDefaults(createFunc, deleteFunc); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto DataSerializeInterface::DescribeElement(const Char* name, const DataType& dt, Int objectOffset, KeyValueConversionFunc* func, DESCRIBEFLAGS flags, UInt64 mask, UInt64 value) const -> Result<void>
{
	const DataSerializeInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataSerializeInterface, this); return mt_._DataSerializeInterface_DescribeElement((const maxon::GenericComponent*) this + mt_._DataSerializeInterface_DescribeElement_Offset, name, dt, objectOffset, func, flags, mask, value);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataSerializeInterface::PrepareHelperClass(CreateIoHelperFunc* createFunc, DeleteIoHelperFunc* deleteFunc, ReadIoHelperFunc* readFunc, WriteIoHelperFunc* writeFunc, PREPAREHELPERFLAGS flags) const -> Result<void>
{
	const DataSerializeInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataSerializeInterface, this); return mt_._DataSerializeInterface_PrepareHelperClass((const maxon::GenericComponent*) this + mt_._DataSerializeInterface_PrepareHelperClass_Offset, createFunc, deleteFunc, readFunc, writeFunc, flags);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataSerializeInterface::RegisterObjectSubstitution(ReferenceSubstitutionFunction&& func) -> Result<void>
{
	const DataSerializeInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataSerializeInterface, this); return mt_._DataSerializeInterface_RegisterObjectSubstitution((maxon::GenericComponent*) this + mt_._DataSerializeInterface_RegisterObjectSubstitution_Offset, std::forward<ReferenceSubstitutionFunction>(func));
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataSerializeInterface::RegisterDefaults(CreateIoHelperFunc* createFunc, DeleteIoHelperFunc* deleteFunc) const -> Result<void*>
{
	const DataSerializeInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataSerializeInterface, this); return mt_._DataSerializeInterface_RegisterDefaults((const maxon::GenericComponent*) this + mt_._DataSerializeInterface_RegisterDefaults_Offset, createFunc, deleteFunc);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataSerializeInterface::Hxx1::ConstReferenceFunctionsImpl<S>::DescribeElement(const Char* name, const DataType& dt, Int objectOffset, KeyValueConversionFunc* func, DESCRIBEFLAGS flags, UInt64 mask, UInt64 value) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DataSerializeInterface* o_ = (const DataSerializeInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DataSerializeInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataSerializeInterface, o_, DataSerializeInterface_DescribeElement) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<DataSerializeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataSerializeInterface>() : PRIVATE_MAXON_VTABLE(DataSerializeInterface, o_); 
	return (mt_._DataSerializeInterface_DescribeElement(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._DataSerializeInterface_DescribeElement_Offset, name, dt, objectOffset, func, flags, mask, value));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataSerializeInterface::Hxx1::ConstReferenceFunctionsImpl<S>::PrepareHelperClass(CreateIoHelperFunc* createFunc, DeleteIoHelperFunc* deleteFunc, ReadIoHelperFunc* readFunc, WriteIoHelperFunc* writeFunc, PREPAREHELPERFLAGS flags) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DataSerializeInterface* o_ = (const DataSerializeInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DataSerializeInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataSerializeInterface, o_, DataSerializeInterface_PrepareHelperClass) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<DataSerializeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataSerializeInterface>() : PRIVATE_MAXON_VTABLE(DataSerializeInterface, o_); 
	return (mt_._DataSerializeInterface_PrepareHelperClass(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._DataSerializeInterface_PrepareHelperClass_Offset, createFunc, deleteFunc, readFunc, writeFunc, flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataSerializeInterface::Hxx1::ReferenceFunctionsImpl<S>::RegisterObjectSubstitution(ReferenceSubstitutionFunction&& func) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataSerializeInterface* o_ = (DataSerializeInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataSerializeInterface, o_, DataSerializeInterface_RegisterObjectSubstitution) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<DataSerializeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataSerializeInterface>() : PRIVATE_MAXON_VTABLE(DataSerializeInterface, o_); 
	return (mt_._DataSerializeInterface_RegisterObjectSubstitution(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._DataSerializeInterface_RegisterObjectSubstitution_Offset, std::forward<ReferenceSubstitutionFunction>(func)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataSerializeInterface::Hxx1::COWReferenceFunctionsImpl<S>::RegisterObjectSubstitution(ReferenceSubstitutionFunction&& func) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataSerializeInterface* o_ = (DataSerializeInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataSerializeInterface, o_, DataSerializeInterface_RegisterObjectSubstitution) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<DataSerializeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataSerializeInterface>() : PRIVATE_MAXON_VTABLE(DataSerializeInterface, o_); 
	return (mt_._DataSerializeInterface_RegisterObjectSubstitution(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._DataSerializeInterface_RegisterObjectSubstitution_Offset, std::forward<ReferenceSubstitutionFunction>(func)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataSerializeInterface::Hxx1::ConstReferenceFunctionsImpl<S>::RegisterDefaults(CreateIoHelperFunc* createFunc, DeleteIoHelperFunc* deleteFunc) const -> Result<void*>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void*>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const DataSerializeInterface* o_ = (const DataSerializeInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = DataSerializeInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataSerializeInterface, o_, DataSerializeInterface_RegisterDefaults) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<DataSerializeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataSerializeInterface>() : PRIVATE_MAXON_VTABLE(DataSerializeInterface, o_); 
	return (mt_._DataSerializeInterface_RegisterDefaults(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._DataSerializeInterface_RegisterDefaults_Offset, createFunc, deleteFunc));
}
auto DataSerializeInterface::GetPtr() -> Ptr { return Ptr(this); }
auto DataSerializeInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
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
	static const maxon::Bool HAS_NONSTATIC = false;
	Result<void> (*_DataSerializeWriterInterface_WriteDocument) (maxon::GenericComponent* this_, const Id& id, const ConstDataPtr& data);
	maxon::Int _DataSerializeWriterInterface_WriteDocument_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataSerializeWriterInterface, WriteDocument))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataSerializeWriterInterface, WriteDocument), W, MTable>::type::_DataSerializeWriterInterface_WriteDocument;
			_DataSerializeWriterInterface_WriteDocument = reinterpret_cast<const decltype(_DataSerializeWriterInterface_WriteDocument)&>(ptr);
			_DataSerializeWriterInterface_WriteDocument_Offset = offset;
		}
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!DataSerializeInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<DataSerializeWriterInterface, typename DataSerializeInterface::MTable::template CombinedMTable<S>>;
	PRIVATE_MAXON_COMPBASE(DataSerializeWriterInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct DataSerializeWriterInterface::Hxx2
{
	template <typename S> class Wrapper : public DataSerializeInterface::Hxx2::template Wrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(WriteDocument);
	static Result<void> _DataSerializeWriterInterface_WriteDocument(maxon::GenericComponent* this_, const Id& id, const ConstDataPtr& data) { return ((typename S::Implementation*) this_)->WriteDocument(id, data); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto DataSerializeWriterInterface::WriteDocument(const Id& id, const ConstDataPtr& data) -> Result<void>
{
	const DataSerializeWriterInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataSerializeWriterInterface, this); return mt_._DataSerializeWriterInterface_WriteDocument((maxon::GenericComponent*) this + mt_._DataSerializeWriterInterface_WriteDocument_Offset, id, data);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataSerializeWriterInterface::Hxx1::ReferenceFunctionsImpl<S>::WriteDocument(const Id& id, const ConstDataPtr& data) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataSerializeWriterInterface* o_ = (DataSerializeWriterInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataSerializeWriterInterface, o_, DataSerializeWriterInterface_WriteDocument) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<DataSerializeWriterInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataSerializeWriterInterface>() : PRIVATE_MAXON_VTABLE(DataSerializeWriterInterface, o_); 
	return (mt_._DataSerializeWriterInterface_WriteDocument(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._DataSerializeWriterInterface_WriteDocument_Offset, id, data));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataSerializeWriterInterface::Hxx1::COWReferenceFunctionsImpl<S>::WriteDocument(const Id& id, const ConstDataPtr& data) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataSerializeWriterInterface* o_ = (DataSerializeWriterInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataSerializeWriterInterface, o_, DataSerializeWriterInterface_WriteDocument) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<DataSerializeWriterInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataSerializeWriterInterface>() : PRIVATE_MAXON_VTABLE(DataSerializeWriterInterface, o_); 
	return (mt_._DataSerializeWriterInterface_WriteDocument(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._DataSerializeWriterInterface_WriteDocument_Offset, id, data));
}
auto DataSerializeWriterInterface::GetPtr() -> Ptr { return Ptr(this); }
auto DataSerializeWriterInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
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
	static const maxon::Bool HAS_NONSTATIC = false;
	Result<void> (*_DataSerializeReaderInterface_ReadDocument) (maxon::GenericComponent* this_, const Id& id, const DataPtr& data);
	maxon::Int _DataSerializeReaderInterface_ReadDocument_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataSerializeReaderInterface, ReadDocument))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataSerializeReaderInterface, ReadDocument), W, MTable>::type::_DataSerializeReaderInterface_ReadDocument;
			_DataSerializeReaderInterface_ReadDocument = reinterpret_cast<const decltype(_DataSerializeReaderInterface_ReadDocument)&>(ptr);
			_DataSerializeReaderInterface_ReadDocument_Offset = offset;
		}
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!DataSerializeInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<DataSerializeReaderInterface, typename DataSerializeInterface::MTable::template CombinedMTable<S>>;
	PRIVATE_MAXON_COMPBASE(DataSerializeReaderInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct DataSerializeReaderInterface::Hxx2
{
	template <typename S> class Wrapper : public DataSerializeInterface::Hxx2::template Wrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(ReadDocument);
	static Result<void> _DataSerializeReaderInterface_ReadDocument(maxon::GenericComponent* this_, const Id& id, const DataPtr& data) { return ((typename S::Implementation*) this_)->ReadDocument(id, data); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto DataSerializeReaderInterface::ReadDocument(const Id& id, const DataPtr& data) -> Result<void>
{
	const DataSerializeReaderInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataSerializeReaderInterface, this); return mt_._DataSerializeReaderInterface_ReadDocument((maxon::GenericComponent*) this + mt_._DataSerializeReaderInterface_ReadDocument_Offset, id, data);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataSerializeReaderInterface::Hxx1::ReferenceFunctionsImpl<S>::ReadDocument(const Id& id, const DataPtr& data) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataSerializeReaderInterface* o_ = (DataSerializeReaderInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataSerializeReaderInterface, o_, DataSerializeReaderInterface_ReadDocument) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<DataSerializeReaderInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataSerializeReaderInterface>() : PRIVATE_MAXON_VTABLE(DataSerializeReaderInterface, o_); 
	return (mt_._DataSerializeReaderInterface_ReadDocument(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._DataSerializeReaderInterface_ReadDocument_Offset, id, data));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataSerializeReaderInterface::Hxx1::COWReferenceFunctionsImpl<S>::ReadDocument(const Id& id, const DataPtr& data) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataSerializeReaderInterface* o_ = (DataSerializeReaderInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataSerializeReaderInterface, o_, DataSerializeReaderInterface_ReadDocument) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<DataSerializeReaderInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataSerializeReaderInterface>() : PRIVATE_MAXON_VTABLE(DataSerializeReaderInterface, o_); 
	return (mt_._DataSerializeReaderInterface_ReadDocument(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._DataSerializeReaderInterface_ReadDocument_Offset, id, data));
}
auto DataSerializeReaderInterface::GetPtr() -> Ptr { return Ptr(this); }
auto DataSerializeReaderInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
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



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
	PRIVATE_MAXON_MF_POINTER(DataSerializeInterface_DescribeElement, DescribeElement, true, maxon::GenericComponent, const, (Result<void>), const Char* name, const DataType& dt, Int objectOffset, KeyValueConversionFunc* func, DESCRIBEFLAGS flags, UInt64 mask, UInt64 value);
	maxon::Int DataSerializeInterface_DescribeElement_Offset;
	PRIVATE_MAXON_MF_POINTER(DataSerializeInterface_PrepareHelperClass, PrepareHelperClass, true, maxon::GenericComponent, const, (Result<void>), CreateIoHelperFunc* createFunc, DeleteIoHelperFunc* deleteFunc, ReadIoHelperFunc* readFunc, WriteIoHelperFunc* writeFunc, PREPAREHELPERFLAGS flags);
	maxon::Int DataSerializeInterface_PrepareHelperClass_Offset;
	PRIVATE_MAXON_MF_POINTER(DataSerializeInterface_RegisterObjectSubstitution, RegisterObjectSubstitution, true, maxon::GenericComponent,, (Result<void>), ReferenceSubstitutionFunction&& func);
	maxon::Int DataSerializeInterface_RegisterObjectSubstitution_Offset;
	PRIVATE_MAXON_MF_POINTER(DataSerializeInterface_RegisterDefaults, RegisterDefaults, true, maxon::GenericComponent, const, (Result<void*>), CreateIoHelperFunc* createFunc, DeleteIoHelperFunc* deleteFunc);
	maxon::Int DataSerializeInterface_RegisterDefaults_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataSerializeInterface, DescribeElement))
	{
		maxon::Tie(DataSerializeInterface_DescribeElement, DataSerializeInterface_DescribeElement_Offset) = DataSerializeInterface_DescribeElement_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataSerializeInterface, PrepareHelperClass))
	{
		maxon::Tie(DataSerializeInterface_PrepareHelperClass, DataSerializeInterface_PrepareHelperClass_Offset) = DataSerializeInterface_PrepareHelperClass_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataSerializeInterface, RegisterObjectSubstitution))
	{
		maxon::Tie(DataSerializeInterface_RegisterObjectSubstitution, DataSerializeInterface_RegisterObjectSubstitution_Offset) = DataSerializeInterface_RegisterObjectSubstitution_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataSerializeInterface, RegisterDefaults))
	{
		maxon::Tie(DataSerializeInterface_RegisterDefaults, DataSerializeInterface_RegisterDefaults_Offset) = DataSerializeInterface_RegisterDefaults_GetPtr<W>(offset, true);
	}
	}
	template <typename S> using CombinedMTable = maxon::PrivateCombinedMTable<DataSerializeInterface, typename ObjectInterface::MTable::template CombinedMTable<S>>;
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
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (DataSerializeInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, DataSerializeInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		PRIVATE_MAXON_MF_WRAPPER(DataSerializeInterface_DescribeElement, maxon::GenericComponent, const, (Result<void>), const Char* name, const DataType& dt, Int objectOffset, KeyValueConversionFunc* func, DESCRIBEFLAGS flags, UInt64 mask, UInt64 value) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->DescribeElement(name, dt, objectOffset, func, flags, mask, value); }
		PRIVATE_MAXON_MF_WRAPPER(DataSerializeInterface_PrepareHelperClass, maxon::GenericComponent, const, (Result<void>), CreateIoHelperFunc* createFunc, DeleteIoHelperFunc* deleteFunc, ReadIoHelperFunc* readFunc, WriteIoHelperFunc* writeFunc, PREPAREHELPERFLAGS flags) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->PrepareHelperClass(createFunc, deleteFunc, readFunc, writeFunc, flags); }
		PRIVATE_MAXON_MF_WRAPPER(DataSerializeInterface_RegisterObjectSubstitution, maxon::GenericComponent,, (Result<void>), ReferenceSubstitutionFunction&& func) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->RegisterObjectSubstitution(std::forward<ReferenceSubstitutionFunction>(func)); }
		PRIVATE_MAXON_MF_WRAPPER(DataSerializeInterface_RegisterDefaults, maxon::GenericComponent, const, (Result<void*>), CreateIoHelperFunc* createFunc, DeleteIoHelperFunc* deleteFunc) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->RegisterDefaults(createFunc, deleteFunc); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto DataSerializeInterface::DescribeElement(const Char* name, const DataType& dt, Int objectOffset, KeyValueConversionFunc* func, DESCRIBEFLAGS flags, UInt64 mask, UInt64 value) const -> Result<void>
{
	const DataSerializeInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataSerializeInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.DataSerializeInterface_DescribeElement_Offset), mt_.DataSerializeInterface_DescribeElement, name, dt, objectOffset, func, flags, mask, value);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataSerializeInterface::PrepareHelperClass(CreateIoHelperFunc* createFunc, DeleteIoHelperFunc* deleteFunc, ReadIoHelperFunc* readFunc, WriteIoHelperFunc* writeFunc, PREPAREHELPERFLAGS flags) const -> Result<void>
{
	const DataSerializeInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataSerializeInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.DataSerializeInterface_PrepareHelperClass_Offset), mt_.DataSerializeInterface_PrepareHelperClass, createFunc, deleteFunc, readFunc, writeFunc, flags);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataSerializeInterface::RegisterObjectSubstitution(ReferenceSubstitutionFunction&& func) -> Result<void>
{
	const DataSerializeInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataSerializeInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.DataSerializeInterface_RegisterObjectSubstitution_Offset), mt_.DataSerializeInterface_RegisterObjectSubstitution, std::forward<ReferenceSubstitutionFunction>(func));
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataSerializeInterface::RegisterDefaults(CreateIoHelperFunc* createFunc, DeleteIoHelperFunc* deleteFunc) const -> Result<void*>
{
	const DataSerializeInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataSerializeInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.DataSerializeInterface_RegisterDefaults_Offset), mt_.DataSerializeInterface_RegisterDefaults, createFunc, deleteFunc);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataSerializeInterface::Hxx1::ConstFn<S>::DescribeElement(const Char* name, const DataType& dt, Int objectOffset, KeyValueConversionFunc* func, DESCRIBEFLAGS flags, UInt64 mask, UInt64 value) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXCONST(HXXRET1(NULLPTR)) HXXTABLE(DataSerializeInterface_DescribeElement); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.DataSerializeInterface_DescribeElement_Offset), mt_.DataSerializeInterface_DescribeElement, name, dt, objectOffset, func, flags, mask, value));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataSerializeInterface::Hxx1::ConstFn<S>::PrepareHelperClass(CreateIoHelperFunc* createFunc, DeleteIoHelperFunc* deleteFunc, ReadIoHelperFunc* readFunc, WriteIoHelperFunc* writeFunc, PREPAREHELPERFLAGS flags) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXCONST(HXXRET1(NULLPTR)) HXXTABLE(DataSerializeInterface_PrepareHelperClass); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.DataSerializeInterface_PrepareHelperClass_Offset), mt_.DataSerializeInterface_PrepareHelperClass, createFunc, deleteFunc, readFunc, writeFunc, flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataSerializeInterface::Hxx1::Fn<S>::RegisterObjectSubstitution(ReferenceSubstitutionFunction&& func) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(DataSerializeInterface_RegisterObjectSubstitution); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataSerializeInterface_RegisterObjectSubstitution_Offset), mt_.DataSerializeInterface_RegisterObjectSubstitution, std::forward<ReferenceSubstitutionFunction>(func)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataSerializeInterface::Hxx1::COWFn<S>::RegisterObjectSubstitution(ReferenceSubstitutionFunction&& func) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(DataSerializeInterface_RegisterObjectSubstitution); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataSerializeInterface_RegisterObjectSubstitution_Offset), mt_.DataSerializeInterface_RegisterObjectSubstitution, std::forward<ReferenceSubstitutionFunction>(func)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataSerializeInterface::Hxx1::ConstFn<S>::RegisterDefaults(CreateIoHelperFunc* createFunc, DeleteIoHelperFunc* deleteFunc) const -> Result<void*>
{
	HXXRETURN0(Result<void*>); HXXRES; HXXCONST(HXXRET1(NULLPTR)) HXXTABLE(DataSerializeInterface_RegisterDefaults); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.DataSerializeInterface_RegisterDefaults_Offset), mt_.DataSerializeInterface_RegisterDefaults, createFunc, deleteFunc));
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
	PRIVATE_MAXON_MF_POINTER(DataSerializeWriterInterface_WriteDocument, WriteDocument, true, maxon::GenericComponent,, (Result<void>), const Id& id, const ConstDataPtr& data);
	maxon::Int DataSerializeWriterInterface_WriteDocument_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataSerializeWriterInterface, WriteDocument))
	{
		maxon::Tie(DataSerializeWriterInterface_WriteDocument, DataSerializeWriterInterface_WriteDocument_Offset) = DataSerializeWriterInterface_WriteDocument_GetPtr<W>(offset, true);
	}
	}
	template <typename S> using CombinedMTable = maxon::PrivateCombinedMTable<DataSerializeWriterInterface, typename DataSerializeInterface::MTable::template CombinedMTable<S>>;
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
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (DataSerializeWriterInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, DataSerializeWriterInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		PRIVATE_MAXON_MF_WRAPPER(DataSerializeWriterInterface_WriteDocument, maxon::GenericComponent,, (Result<void>), const Id& id, const ConstDataPtr& data) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->WriteDocument(id, data); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto DataSerializeWriterInterface::WriteDocument(const Id& id, const ConstDataPtr& data) -> Result<void>
{
	const DataSerializeWriterInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataSerializeWriterInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.DataSerializeWriterInterface_WriteDocument_Offset), mt_.DataSerializeWriterInterface_WriteDocument, id, data);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataSerializeWriterInterface::Hxx1::Fn<S>::WriteDocument(const Id& id, const ConstDataPtr& data) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(DataSerializeWriterInterface_WriteDocument); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataSerializeWriterInterface_WriteDocument_Offset), mt_.DataSerializeWriterInterface_WriteDocument, id, data));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataSerializeWriterInterface::Hxx1::COWFn<S>::WriteDocument(const Id& id, const ConstDataPtr& data) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(DataSerializeWriterInterface_WriteDocument); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataSerializeWriterInterface_WriteDocument_Offset), mt_.DataSerializeWriterInterface_WriteDocument, id, data));
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
	PRIVATE_MAXON_MF_POINTER(DataSerializeReaderInterface_ReadDocument, ReadDocument, true, maxon::GenericComponent,, (Result<void>), const Id& id, const DataPtr& data);
	maxon::Int DataSerializeReaderInterface_ReadDocument_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataSerializeReaderInterface, ReadDocument))
	{
		maxon::Tie(DataSerializeReaderInterface_ReadDocument, DataSerializeReaderInterface_ReadDocument_Offset) = DataSerializeReaderInterface_ReadDocument_GetPtr<W>(offset, true);
	}
	}
	template <typename S> using CombinedMTable = maxon::PrivateCombinedMTable<DataSerializeReaderInterface, typename DataSerializeInterface::MTable::template CombinedMTable<S>>;
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
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (DataSerializeReaderInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, DataSerializeReaderInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		PRIVATE_MAXON_MF_WRAPPER(DataSerializeReaderInterface_ReadDocument, maxon::GenericComponent,, (Result<void>), const Id& id, const DataPtr& data) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->ReadDocument(id, data); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto DataSerializeReaderInterface::ReadDocument(const Id& id, const DataPtr& data) -> Result<void>
{
	const DataSerializeReaderInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataSerializeReaderInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.DataSerializeReaderInterface_ReadDocument_Offset), mt_.DataSerializeReaderInterface_ReadDocument, id, data);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataSerializeReaderInterface::Hxx1::Fn<S>::ReadDocument(const Id& id, const DataPtr& data) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(DataSerializeReaderInterface_ReadDocument); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataSerializeReaderInterface_ReadDocument_Offset), mt_.DataSerializeReaderInterface_ReadDocument, id, data));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataSerializeReaderInterface::Hxx1::COWFn<S>::ReadDocument(const Id& id, const DataPtr& data) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(DataSerializeReaderInterface_ReadDocument); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataSerializeReaderInterface_ReadDocument_Offset), mt_.DataSerializeReaderInterface_ReadDocument, id, data));
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


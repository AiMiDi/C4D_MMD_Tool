
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1

struct DataFormatBaseReaderInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(CloseInput);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(ReadDataEOS);
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	PRIVATE_MAXON_MF_POINTER(DataFormatBaseReaderInterface_CloseInput, CloseInput, true, maxon::GenericComponent,, (Result<void>));
	maxon::Int DataFormatBaseReaderInterface_CloseInput_Offset;
	PRIVATE_MAXON_MF_POINTER(DataFormatBaseReaderInterface_ReadDataEOS, ReadDataEOS, true, maxon::GenericComponent,, (Result<Int>), void* data, Int dataSize, Int elementCount);
	maxon::Int DataFormatBaseReaderInterface_ReadDataEOS_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataFormatBaseReaderInterface, CloseInput))
	{
		maxon::Tie(DataFormatBaseReaderInterface_CloseInput, DataFormatBaseReaderInterface_CloseInput_Offset) = DataFormatBaseReaderInterface_CloseInput_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataFormatBaseReaderInterface, ReadDataEOS))
	{
		maxon::Tie(DataFormatBaseReaderInterface_ReadDataEOS, DataFormatBaseReaderInterface_ReadDataEOS_Offset) = DataFormatBaseReaderInterface_ReadDataEOS_GetPtr<W>(offset, true);
	}
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<DataFormatBaseReaderInterface, typename DataDictionaryObjectInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<DataFormatBaseReaderInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct DataFormatBaseReaderInterface::Hxx2
{
	template <typename S> class CWrapper : public DataDictionaryObjectInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(CloseInput);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(ReadDataEOS);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename DataDictionaryObjectInterface::Hxx2::template CWrapper<S>;
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (DataFormatBaseReaderInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, DataFormatBaseReaderInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		PRIVATE_MAXON_MF_WRAPPER(DataFormatBaseReaderInterface_CloseInput, maxon::GenericComponent,, (Result<void>)) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->CloseInput(); }
		PRIVATE_MAXON_MF_WRAPPER(DataFormatBaseReaderInterface_ReadDataEOS, maxon::GenericComponent,, (Result<Int>), void* data, Int dataSize, Int elementCount) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->ReadDataEOS(data, dataSize, elementCount); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto DataFormatBaseReaderInterface::CloseInput() -> Result<void>
{
	const DataFormatBaseReaderInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataFormatBaseReaderInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.DataFormatBaseReaderInterface_CloseInput_Offset), mt_.DataFormatBaseReaderInterface_CloseInput);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataFormatBaseReaderInterface::ReadDataEOS(void* data, Int dataSize, Int elementCount) -> Result<Int>
{
	const DataFormatBaseReaderInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataFormatBaseReaderInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.DataFormatBaseReaderInterface_ReadDataEOS_Offset), mt_.DataFormatBaseReaderInterface_ReadDataEOS, data, dataSize, elementCount);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataFormatBaseReaderInterface::Hxx1::Fn<S>::CloseInput() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); DataFormatBaseReaderInterface* o_ = (DataFormatBaseReaderInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataFormatBaseReaderInterface, o_, DataFormatBaseReaderInterface_CloseInput) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DataFormatBaseReaderInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataFormatBaseReaderInterface>() : PRIVATE_MAXON_VTABLE(DataFormatBaseReaderInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataFormatBaseReaderInterface_CloseInput_Offset), mt_.DataFormatBaseReaderInterface_CloseInput));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataFormatBaseReaderInterface::Hxx1::COWFn<S>::CloseInput() -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); DataFormatBaseReaderInterface* o_ = (DataFormatBaseReaderInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataFormatBaseReaderInterface, o_, DataFormatBaseReaderInterface_CloseInput) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DataFormatBaseReaderInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataFormatBaseReaderInterface>() : PRIVATE_MAXON_VTABLE(DataFormatBaseReaderInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataFormatBaseReaderInterface_CloseInput_Offset), mt_.DataFormatBaseReaderInterface_CloseInput));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataFormatBaseReaderInterface::Hxx1::Fn<S>::ReadData(void* data, Int dataSize, Int elementCount) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); DataFormatBaseReaderInterface* o_ = (DataFormatBaseReaderInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->ReadData(data, dataSize, elementCount));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataFormatBaseReaderInterface::Hxx1::COWFn<S>::ReadData(void* data, Int dataSize, Int elementCount) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION DataFormatBaseReaderInterface::ReadData on super."); if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); DataFormatBaseReaderInterface* o_ = (DataFormatBaseReaderInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (o_->ReadData(data, dataSize, elementCount));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataFormatBaseReaderInterface::Hxx1::Fn<S>::ReadDataEOS(void* data, Int dataSize, Int elementCount) const -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); DataFormatBaseReaderInterface* o_ = (DataFormatBaseReaderInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataFormatBaseReaderInterface, o_, DataFormatBaseReaderInterface_ReadDataEOS) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DataFormatBaseReaderInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataFormatBaseReaderInterface>() : PRIVATE_MAXON_VTABLE(DataFormatBaseReaderInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataFormatBaseReaderInterface_ReadDataEOS_Offset), mt_.DataFormatBaseReaderInterface_ReadDataEOS, data, dataSize, elementCount));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataFormatBaseReaderInterface::Hxx1::COWFn<S>::ReadDataEOS(void* data, Int dataSize, Int elementCount) -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); DataFormatBaseReaderInterface* o_ = (DataFormatBaseReaderInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataFormatBaseReaderInterface, o_, DataFormatBaseReaderInterface_ReadDataEOS) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DataFormatBaseReaderInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataFormatBaseReaderInterface>() : PRIVATE_MAXON_VTABLE(DataFormatBaseReaderInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataFormatBaseReaderInterface_ReadDataEOS_Offset), mt_.DataFormatBaseReaderInterface_ReadDataEOS, data, dataSize, elementCount));
}
auto DataFormatBaseReaderInterface::GetPtr() -> Ptr { return Ptr(this); }
auto DataFormatBaseReaderInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_dataformat_base)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_DataFormatBaseReaderInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_DataFormatBaseReaderInterface() { new (s_ui_maxon_DataFormatBaseReaderInterface) maxon::EntityUse(DataFormatBaseReaderInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/dataformat_base.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_DataFormatBaseReaderInterface(DataFormatBaseReaderInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/dataformat_base.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif

struct DataFormatBaseWriterInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(CloseOutput);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Flush);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(WriteData);
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	PRIVATE_MAXON_MF_POINTER(DataFormatBaseWriterInterface_CloseOutput, CloseOutput, true, maxon::GenericComponent,, (Result<void>));
	maxon::Int DataFormatBaseWriterInterface_CloseOutput_Offset;
	PRIVATE_MAXON_MF_POINTER(DataFormatBaseWriterInterface_WriteData, WriteData, true, maxon::GenericComponent,, (Result<void>), const void* data, Int dataSize, Int elementCount);
	maxon::Int DataFormatBaseWriterInterface_WriteData_Offset;
	PRIVATE_MAXON_MF_POINTER(DataFormatBaseWriterInterface_Flush, Flush, true, maxon::GenericComponent,, (Result<void>));
	maxon::Int DataFormatBaseWriterInterface_Flush_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataFormatBaseWriterInterface, CloseOutput))
	{
		maxon::Tie(DataFormatBaseWriterInterface_CloseOutput, DataFormatBaseWriterInterface_CloseOutput_Offset) = DataFormatBaseWriterInterface_CloseOutput_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataFormatBaseWriterInterface, WriteData))
	{
		maxon::Tie(DataFormatBaseWriterInterface_WriteData, DataFormatBaseWriterInterface_WriteData_Offset) = DataFormatBaseWriterInterface_WriteData_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataFormatBaseWriterInterface, Flush))
	{
		maxon::Tie(DataFormatBaseWriterInterface_Flush, DataFormatBaseWriterInterface_Flush_Offset) = DataFormatBaseWriterInterface_Flush_GetPtr<W>(offset, true);
	}
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<DataFormatBaseWriterInterface, typename DataDictionaryObjectInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<DataFormatBaseWriterInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct DataFormatBaseWriterInterface::Hxx2
{
	template <typename S> class CWrapper : public DataDictionaryObjectInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(CloseOutput);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Flush);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(WriteData);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename DataDictionaryObjectInterface::Hxx2::template CWrapper<S>;
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (DataFormatBaseWriterInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, DataFormatBaseWriterInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		PRIVATE_MAXON_MF_WRAPPER(DataFormatBaseWriterInterface_CloseOutput, maxon::GenericComponent,, (Result<void>)) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->CloseOutput(); }
		PRIVATE_MAXON_MF_WRAPPER(DataFormatBaseWriterInterface_WriteData, maxon::GenericComponent,, (Result<void>), const void* data, Int dataSize, Int elementCount) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->WriteData(data, dataSize, elementCount); }
		PRIVATE_MAXON_MF_WRAPPER(DataFormatBaseWriterInterface_Flush, maxon::GenericComponent,, (Result<void>)) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->Flush(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto DataFormatBaseWriterInterface::CloseOutput() -> Result<void>
{
	const DataFormatBaseWriterInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataFormatBaseWriterInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.DataFormatBaseWriterInterface_CloseOutput_Offset), mt_.DataFormatBaseWriterInterface_CloseOutput);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataFormatBaseWriterInterface::WriteData(const void* data, Int dataSize, Int elementCount) -> Result<void>
{
	const DataFormatBaseWriterInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataFormatBaseWriterInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.DataFormatBaseWriterInterface_WriteData_Offset), mt_.DataFormatBaseWriterInterface_WriteData, data, dataSize, elementCount);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataFormatBaseWriterInterface::Flush() -> Result<void>
{
	const DataFormatBaseWriterInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataFormatBaseWriterInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.DataFormatBaseWriterInterface_Flush_Offset), mt_.DataFormatBaseWriterInterface_Flush);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataFormatBaseWriterInterface::Hxx1::Fn<S>::CloseOutput() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); DataFormatBaseWriterInterface* o_ = (DataFormatBaseWriterInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataFormatBaseWriterInterface, o_, DataFormatBaseWriterInterface_CloseOutput) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DataFormatBaseWriterInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataFormatBaseWriterInterface>() : PRIVATE_MAXON_VTABLE(DataFormatBaseWriterInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataFormatBaseWriterInterface_CloseOutput_Offset), mt_.DataFormatBaseWriterInterface_CloseOutput));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataFormatBaseWriterInterface::Hxx1::COWFn<S>::CloseOutput() -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); DataFormatBaseWriterInterface* o_ = (DataFormatBaseWriterInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataFormatBaseWriterInterface, o_, DataFormatBaseWriterInterface_CloseOutput) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DataFormatBaseWriterInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataFormatBaseWriterInterface>() : PRIVATE_MAXON_VTABLE(DataFormatBaseWriterInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataFormatBaseWriterInterface_CloseOutput_Offset), mt_.DataFormatBaseWriterInterface_CloseOutput));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataFormatBaseWriterInterface::Hxx1::Fn<S>::WriteData(const void* data, Int dataSize, Int elementCount) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); DataFormatBaseWriterInterface* o_ = (DataFormatBaseWriterInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataFormatBaseWriterInterface, o_, DataFormatBaseWriterInterface_WriteData) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DataFormatBaseWriterInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataFormatBaseWriterInterface>() : PRIVATE_MAXON_VTABLE(DataFormatBaseWriterInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataFormatBaseWriterInterface_WriteData_Offset), mt_.DataFormatBaseWriterInterface_WriteData, data, dataSize, elementCount));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataFormatBaseWriterInterface::Hxx1::COWFn<S>::WriteData(const void* data, Int dataSize, Int elementCount) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); DataFormatBaseWriterInterface* o_ = (DataFormatBaseWriterInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataFormatBaseWriterInterface, o_, DataFormatBaseWriterInterface_WriteData) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DataFormatBaseWriterInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataFormatBaseWriterInterface>() : PRIVATE_MAXON_VTABLE(DataFormatBaseWriterInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataFormatBaseWriterInterface_WriteData_Offset), mt_.DataFormatBaseWriterInterface_WriteData, data, dataSize, elementCount));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataFormatBaseWriterInterface::Hxx1::Fn<S>::Flush() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); DataFormatBaseWriterInterface* o_ = (DataFormatBaseWriterInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataFormatBaseWriterInterface, o_, DataFormatBaseWriterInterface_Flush) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DataFormatBaseWriterInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataFormatBaseWriterInterface>() : PRIVATE_MAXON_VTABLE(DataFormatBaseWriterInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataFormatBaseWriterInterface_Flush_Offset), mt_.DataFormatBaseWriterInterface_Flush));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataFormatBaseWriterInterface::Hxx1::COWFn<S>::Flush() -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); DataFormatBaseWriterInterface* o_ = (DataFormatBaseWriterInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataFormatBaseWriterInterface, o_, DataFormatBaseWriterInterface_Flush) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DataFormatBaseWriterInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataFormatBaseWriterInterface>() : PRIVATE_MAXON_VTABLE(DataFormatBaseWriterInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DataFormatBaseWriterInterface_Flush_Offset), mt_.DataFormatBaseWriterInterface_Flush));
}
template <typename S> template <typename T> MAXON_ATTRIBUTE_FORCE_INLINE auto DataFormatBaseWriterInterface::Hxx1::Fn<S>::Write(const Block<const T>& data) const -> maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), true, maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); DataFormatBaseWriterInterface* o_ = (DataFormatBaseWriterInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR)); } 
	auto res_ = o_->Write<T>(data);
	return ReturnHelper::Return(this, res_.GetErrorStorage());
}
template <typename S> template <typename T> MAXON_ATTRIBUTE_FORCE_INLINE auto DataFormatBaseWriterInterface::Hxx1::COWFn<S>::Write(const Block<const T>& data) -> maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), true, maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)>>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION DataFormatBaseWriterInterface::Write on super."); if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); DataFormatBaseWriterInterface* o_ = (DataFormatBaseWriterInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	auto res_ = o_->Write<T>(data);
	return ReturnHelper::Return(this, res_.GetErrorStorage());
}
auto DataFormatBaseWriterInterface::GetPtr() -> Ptr { return Ptr(this); }
auto DataFormatBaseWriterInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_dataformat_base)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_DataFormatBaseWriterInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_DataFormatBaseWriterInterface() { new (s_ui_maxon_DataFormatBaseWriterInterface) maxon::EntityUse(DataFormatBaseWriterInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/dataformat_base.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_DataFormatBaseWriterInterface(DataFormatBaseWriterInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/dataformat_base.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif


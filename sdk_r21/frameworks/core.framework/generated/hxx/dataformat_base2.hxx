
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1
namespace DATAFORMATBASEIDS
{
	struct STREAM_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0xf222d890c2265342LL), maxon::UInt(31))> { };
}

struct DataFormatBaseReaderInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(CloseInput);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(ReadDataEOS);
	static const maxon::Char* const _ids;
	static const maxon::Bool HAS_NONSTATIC = false;
	Result<void> (*_DataFormatBaseReaderInterface_CloseInput) (maxon::GenericComponent* this_);
	maxon::Int _DataFormatBaseReaderInterface_CloseInput_Offset;
	Result<Int> (*_DataFormatBaseReaderInterface_ReadDataEOS) (maxon::GenericComponent* this_, void* data, Int dataSize, Int elementCount);
	maxon::Int _DataFormatBaseReaderInterface_ReadDataEOS_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataFormatBaseReaderInterface, CloseInput))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataFormatBaseReaderInterface, CloseInput), W, MTable>::type::_DataFormatBaseReaderInterface_CloseInput;
			_DataFormatBaseReaderInterface_CloseInput = reinterpret_cast<const decltype(_DataFormatBaseReaderInterface_CloseInput)&>(ptr);
			_DataFormatBaseReaderInterface_CloseInput_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataFormatBaseReaderInterface, ReadDataEOS))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataFormatBaseReaderInterface, ReadDataEOS), W, MTable>::type::_DataFormatBaseReaderInterface_ReadDataEOS;
			_DataFormatBaseReaderInterface_ReadDataEOS = reinterpret_cast<const decltype(_DataFormatBaseReaderInterface_ReadDataEOS)&>(ptr);
			_DataFormatBaseReaderInterface_ReadDataEOS_Offset = offset;
		}
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!DataDictionaryObjectInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<DataFormatBaseReaderInterface, typename DataDictionaryObjectInterface::MTable::template CombinedMTable<S>>;
	PRIVATE_MAXON_COMPBASE(DataFormatBaseReaderInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct DataFormatBaseReaderInterface::Hxx2
{
	template <typename S> class Wrapper : public DataDictionaryObjectInterface::Hxx2::template Wrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(CloseInput);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(ReadDataEOS);
	static Result<void> _DataFormatBaseReaderInterface_CloseInput(maxon::GenericComponent* this_) { return ((typename S::Implementation*) this_)->CloseInput(); }
	static Result<Int> _DataFormatBaseReaderInterface_ReadDataEOS(maxon::GenericComponent* this_, void* data, Int dataSize, Int elementCount) { return ((typename S::Implementation*) this_)->ReadDataEOS(data, dataSize, elementCount); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto DataFormatBaseReaderInterface::CloseInput() -> Result<void>
{
	const DataFormatBaseReaderInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataFormatBaseReaderInterface, this); return mt_._DataFormatBaseReaderInterface_CloseInput((maxon::GenericComponent*) this + mt_._DataFormatBaseReaderInterface_CloseInput_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataFormatBaseReaderInterface::ReadDataEOS(void* data, Int dataSize, Int elementCount) -> Result<Int>
{
	const DataFormatBaseReaderInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataFormatBaseReaderInterface, this); return mt_._DataFormatBaseReaderInterface_ReadDataEOS((maxon::GenericComponent*) this + mt_._DataFormatBaseReaderInterface_ReadDataEOS_Offset, data, dataSize, elementCount);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataFormatBaseReaderInterface::Hxx1::ReferenceFunctionsImpl<S>::CloseInput() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataFormatBaseReaderInterface* o_ = (DataFormatBaseReaderInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataFormatBaseReaderInterface, o_, DataFormatBaseReaderInterface_CloseInput) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<DataFormatBaseReaderInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataFormatBaseReaderInterface>() : PRIVATE_MAXON_VTABLE(DataFormatBaseReaderInterface, o_); 
	return (mt_._DataFormatBaseReaderInterface_CloseInput(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._DataFormatBaseReaderInterface_CloseInput_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataFormatBaseReaderInterface::Hxx1::COWReferenceFunctionsImpl<S>::CloseInput() -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataFormatBaseReaderInterface* o_ = (DataFormatBaseReaderInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataFormatBaseReaderInterface, o_, DataFormatBaseReaderInterface_CloseInput) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<DataFormatBaseReaderInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataFormatBaseReaderInterface>() : PRIVATE_MAXON_VTABLE(DataFormatBaseReaderInterface, o_); 
	return (mt_._DataFormatBaseReaderInterface_CloseInput(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._DataFormatBaseReaderInterface_CloseInput_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataFormatBaseReaderInterface::Hxx1::ReferenceFunctionsImpl<S>::ReadData(void* data, Int dataSize, Int elementCount) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataFormatBaseReaderInterface* o_ = (DataFormatBaseReaderInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (o_->ReadData(data, dataSize, elementCount));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataFormatBaseReaderInterface::Hxx1::COWReferenceFunctionsImpl<S>::ReadData(void* data, Int dataSize, Int elementCount) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION DataFormatBaseReaderInterface::ReadData on super."); if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataFormatBaseReaderInterface* o_ = (DataFormatBaseReaderInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (o_->ReadData(data, dataSize, elementCount));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataFormatBaseReaderInterface::Hxx1::ReferenceFunctionsImpl<S>::ReadDataEOS(void* data, Int dataSize, Int elementCount) const -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataFormatBaseReaderInterface* o_ = (DataFormatBaseReaderInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataFormatBaseReaderInterface, o_, DataFormatBaseReaderInterface_ReadDataEOS) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<DataFormatBaseReaderInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataFormatBaseReaderInterface>() : PRIVATE_MAXON_VTABLE(DataFormatBaseReaderInterface, o_); 
	return (mt_._DataFormatBaseReaderInterface_ReadDataEOS(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._DataFormatBaseReaderInterface_ReadDataEOS_Offset, data, dataSize, elementCount));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataFormatBaseReaderInterface::Hxx1::COWReferenceFunctionsImpl<S>::ReadDataEOS(void* data, Int dataSize, Int elementCount) -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataFormatBaseReaderInterface* o_ = (DataFormatBaseReaderInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataFormatBaseReaderInterface, o_, DataFormatBaseReaderInterface_ReadDataEOS) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<DataFormatBaseReaderInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataFormatBaseReaderInterface>() : PRIVATE_MAXON_VTABLE(DataFormatBaseReaderInterface, o_); 
	return (mt_._DataFormatBaseReaderInterface_ReadDataEOS(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._DataFormatBaseReaderInterface_ReadDataEOS_Offset, data, dataSize, elementCount));
}
auto DataFormatBaseReaderInterface::GetPtr() -> Ptr { return Ptr(this); }
auto DataFormatBaseReaderInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
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
	static const maxon::Bool HAS_NONSTATIC = false;
	Result<void> (*_DataFormatBaseWriterInterface_CloseOutput) (maxon::GenericComponent* this_);
	maxon::Int _DataFormatBaseWriterInterface_CloseOutput_Offset;
	Result<void> (*_DataFormatBaseWriterInterface_WriteData) (maxon::GenericComponent* this_, const void* data, Int dataSize, Int elementCount);
	maxon::Int _DataFormatBaseWriterInterface_WriteData_Offset;
	Result<void> (*_DataFormatBaseWriterInterface_Flush) (maxon::GenericComponent* this_);
	maxon::Int _DataFormatBaseWriterInterface_Flush_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataFormatBaseWriterInterface, CloseOutput))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataFormatBaseWriterInterface, CloseOutput), W, MTable>::type::_DataFormatBaseWriterInterface_CloseOutput;
			_DataFormatBaseWriterInterface_CloseOutput = reinterpret_cast<const decltype(_DataFormatBaseWriterInterface_CloseOutput)&>(ptr);
			_DataFormatBaseWriterInterface_CloseOutput_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataFormatBaseWriterInterface, WriteData))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataFormatBaseWriterInterface, WriteData), W, MTable>::type::_DataFormatBaseWriterInterface_WriteData;
			_DataFormatBaseWriterInterface_WriteData = reinterpret_cast<const decltype(_DataFormatBaseWriterInterface_WriteData)&>(ptr);
			_DataFormatBaseWriterInterface_WriteData_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataFormatBaseWriterInterface, Flush))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DataFormatBaseWriterInterface, Flush), W, MTable>::type::_DataFormatBaseWriterInterface_Flush;
			_DataFormatBaseWriterInterface_Flush = reinterpret_cast<const decltype(_DataFormatBaseWriterInterface_Flush)&>(ptr);
			_DataFormatBaseWriterInterface_Flush_Offset = offset;
		}
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!DataDictionaryObjectInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<DataFormatBaseWriterInterface, typename DataDictionaryObjectInterface::MTable::template CombinedMTable<S>>;
	PRIVATE_MAXON_COMPBASE(DataFormatBaseWriterInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct DataFormatBaseWriterInterface::Hxx2
{
	template <typename S> class Wrapper : public DataDictionaryObjectInterface::Hxx2::template Wrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(CloseOutput);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Flush);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(WriteData);
	static Result<void> _DataFormatBaseWriterInterface_CloseOutput(maxon::GenericComponent* this_) { return ((typename S::Implementation*) this_)->CloseOutput(); }
	static Result<void> _DataFormatBaseWriterInterface_WriteData(maxon::GenericComponent* this_, const void* data, Int dataSize, Int elementCount) { return ((typename S::Implementation*) this_)->WriteData(data, dataSize, elementCount); }
	static Result<void> _DataFormatBaseWriterInterface_Flush(maxon::GenericComponent* this_) { return ((typename S::Implementation*) this_)->Flush(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto DataFormatBaseWriterInterface::CloseOutput() -> Result<void>
{
	const DataFormatBaseWriterInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataFormatBaseWriterInterface, this); return mt_._DataFormatBaseWriterInterface_CloseOutput((maxon::GenericComponent*) this + mt_._DataFormatBaseWriterInterface_CloseOutput_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataFormatBaseWriterInterface::WriteData(const void* data, Int dataSize, Int elementCount) -> Result<void>
{
	const DataFormatBaseWriterInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataFormatBaseWriterInterface, this); return mt_._DataFormatBaseWriterInterface_WriteData((maxon::GenericComponent*) this + mt_._DataFormatBaseWriterInterface_WriteData_Offset, data, dataSize, elementCount);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataFormatBaseWriterInterface::Flush() -> Result<void>
{
	const DataFormatBaseWriterInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DataFormatBaseWriterInterface, this); return mt_._DataFormatBaseWriterInterface_Flush((maxon::GenericComponent*) this + mt_._DataFormatBaseWriterInterface_Flush_Offset);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataFormatBaseWriterInterface::Hxx1::ReferenceFunctionsImpl<S>::CloseOutput() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataFormatBaseWriterInterface* o_ = (DataFormatBaseWriterInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataFormatBaseWriterInterface, o_, DataFormatBaseWriterInterface_CloseOutput) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<DataFormatBaseWriterInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataFormatBaseWriterInterface>() : PRIVATE_MAXON_VTABLE(DataFormatBaseWriterInterface, o_); 
	return (mt_._DataFormatBaseWriterInterface_CloseOutput(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._DataFormatBaseWriterInterface_CloseOutput_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataFormatBaseWriterInterface::Hxx1::COWReferenceFunctionsImpl<S>::CloseOutput() -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataFormatBaseWriterInterface* o_ = (DataFormatBaseWriterInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataFormatBaseWriterInterface, o_, DataFormatBaseWriterInterface_CloseOutput) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<DataFormatBaseWriterInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataFormatBaseWriterInterface>() : PRIVATE_MAXON_VTABLE(DataFormatBaseWriterInterface, o_); 
	return (mt_._DataFormatBaseWriterInterface_CloseOutput(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._DataFormatBaseWriterInterface_CloseOutput_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataFormatBaseWriterInterface::Hxx1::ReferenceFunctionsImpl<S>::WriteData(const void* data, Int dataSize, Int elementCount) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataFormatBaseWriterInterface* o_ = (DataFormatBaseWriterInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataFormatBaseWriterInterface, o_, DataFormatBaseWriterInterface_WriteData) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<DataFormatBaseWriterInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataFormatBaseWriterInterface>() : PRIVATE_MAXON_VTABLE(DataFormatBaseWriterInterface, o_); 
	return (mt_._DataFormatBaseWriterInterface_WriteData(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._DataFormatBaseWriterInterface_WriteData_Offset, data, dataSize, elementCount));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataFormatBaseWriterInterface::Hxx1::COWReferenceFunctionsImpl<S>::WriteData(const void* data, Int dataSize, Int elementCount) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataFormatBaseWriterInterface* o_ = (DataFormatBaseWriterInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataFormatBaseWriterInterface, o_, DataFormatBaseWriterInterface_WriteData) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<DataFormatBaseWriterInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataFormatBaseWriterInterface>() : PRIVATE_MAXON_VTABLE(DataFormatBaseWriterInterface, o_); 
	return (mt_._DataFormatBaseWriterInterface_WriteData(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._DataFormatBaseWriterInterface_WriteData_Offset, data, dataSize, elementCount));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataFormatBaseWriterInterface::Hxx1::ReferenceFunctionsImpl<S>::Flush() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataFormatBaseWriterInterface* o_ = (DataFormatBaseWriterInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataFormatBaseWriterInterface, o_, DataFormatBaseWriterInterface_Flush) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<DataFormatBaseWriterInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataFormatBaseWriterInterface>() : PRIVATE_MAXON_VTABLE(DataFormatBaseWriterInterface, o_); 
	return (mt_._DataFormatBaseWriterInterface_Flush(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._DataFormatBaseWriterInterface_Flush_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DataFormatBaseWriterInterface::Hxx1::COWReferenceFunctionsImpl<S>::Flush() -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataFormatBaseWriterInterface* o_ = (DataFormatBaseWriterInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DataFormatBaseWriterInterface, o_, DataFormatBaseWriterInterface_Flush) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<DataFormatBaseWriterInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DataFormatBaseWriterInterface>() : PRIVATE_MAXON_VTABLE(DataFormatBaseWriterInterface, o_); 
	return (mt_._DataFormatBaseWriterInterface_Flush(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._DataFormatBaseWriterInterface_Flush_Offset));
}
template <typename S> template <typename T> MAXON_ATTRIBUTE_FORCE_INLINE auto DataFormatBaseWriterInterface::Hxx1::ReferenceFunctionsImpl<S>::Write(const Block<const T>& data) const -> maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), true, maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataFormatBaseWriterInterface* o_ = (DataFormatBaseWriterInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR)); 
	auto res_ = o_->Write<T>(data);
	return ReturnHelper::Return(this, res_.GetErrorStorage());
}
template <typename S> template <typename T> MAXON_ATTRIBUTE_FORCE_INLINE auto DataFormatBaseWriterInterface::Hxx1::COWReferenceFunctionsImpl<S>::Write(const Block<const T>& data) -> maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), true, maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)>>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION DataFormatBaseWriterInterface::Write on super."); if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DataFormatBaseWriterInterface* o_ = (DataFormatBaseWriterInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	auto res_ = o_->Write<T>(data);
	return ReturnHelper::Return(this, res_.GetErrorStorage());
}
auto DataFormatBaseWriterInterface::GetPtr() -> Ptr { return Ptr(this); }
auto DataFormatBaseWriterInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
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


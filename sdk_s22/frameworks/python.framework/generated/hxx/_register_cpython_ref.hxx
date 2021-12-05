#if 1
namespace maxon
{
	namespace py
	{
		namespace enum36 { enum class REFTYPE
		{
			DECREF = 1,										///< The NativePyObject is new and just needs to be decrefed after the CPyRef instance is destructed.
			BORROWED = 2,									///< The NativePyObject is borrowed and the CPyRef needs to incref it internally, and decref it after the CPyRef instance is destructed.
			PRIVATE_SHORTTERM_BORROWED = 3,					///< No refcount handling is performed on the passed NativePyObject.
			PRIVATE_MUST_NOT_BE_USED_ANYMORE = 4			///< Indicates that the CPyRef is not supposed to be used anymore and should be destructed as soon as possible.
		} ; }
		maxon::String PrivateToString_REFTYPE36(std::underlying_type<enum36::REFTYPE>::type x, const maxon::FormatStatement* fmt)
		{
			const maxon::UInt64 values[] = {(maxon::UInt64) enum36::REFTYPE::DECREF, (maxon::UInt64) enum36::REFTYPE::BORROWED, (maxon::UInt64) enum36::REFTYPE::PRIVATE_SHORTTERM_BORROWED, (maxon::UInt64) enum36::REFTYPE::PRIVATE_MUST_NOT_BE_USED_ANYMORE};
			return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "REFTYPE", SIZEOF(x), false, values, "DECREF\0BORROWED\0PRIVATE_SHORTTERM_BORROWED\0PRIVATE_MUST_NOT_BE_USED_ANYMORE\0", fmt);
		}
		const maxon::Char* const CPyInterface::MTable::_ids = 
		"Init@93ae16f30041d8b9\0" // void Init(const CPythonLibraryInterface* lib, REFTYPE refType, NativePyObject* pyObject)
		"Incref@6b2e10f\0" // void Incref()
		"Decref@6b2e10f\0" // void Decref()
		"GetRefCount@82d56af6\0" // Int64 GetRefCount()
		"GetLibrary@5b0d60b0c47e8401\0" // const CPythonLibraryInterface* GetLibrary() const
		"GetTypeRef@18949c5e975594e4\0" // CPyTypeRef GetTypeRef() const
		"GetPyObject@eec8a73e7dbc01c2\0" // NativePyObject* GetPyObject() const
		"Disconnect@bd614fb7b179ad78\0" // NativePyObject* Disconnect()
		"";
		PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(CPyInterface, , "net.maxon.python.interface.cpyref", "maxon.py.CPyInterface", (&ObjectInterface::_interface));
		template <typename DUMMY> maxon::Int CPyInterface::PrivateInstantiateNullValueHelper()
		{
			return 0
			| maxon::details::InstantiateNullReturnValue<CPyConstRef>(OVERLOAD_MAX_RANK)
			| maxon::details::InstantiateNullReturnValue<CPyRef>(OVERLOAD_MAX_RANK)
			| maxon::details::InstantiateNullReturnValue<CPyTempRef>(OVERLOAD_MAX_RANK)
			| maxon::details::InstantiateNullReturnValue<CPyTypeRef>(OVERLOAD_MAX_RANK)
			;
		}
		const maxon::Char* const CPyTypeInterface::MTable::_ids = 
		"";
		PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(CPyTypeInterface, , "net.maxon.python.interface.cpytype", "maxon.py.CPyTypeInterface", (&CPyInterface::_interface));
		template <typename DUMMY> maxon::Int CPyTypeInterface::PrivateInstantiateNullValueHelper()
		{
			return 0
			| maxon::details::InstantiateNullReturnValue<CPyTypeConstRef>(OVERLOAD_MAX_RANK)
			| maxon::details::InstantiateNullReturnValue<CPyTypeRef>(OVERLOAD_MAX_RANK)
			;
		}
		const maxon::Char* const CPyFrameInterface::MTable::_ids = 
		"GetBack@f9fd990099dae1a9\0" // CPyFrameRef GetBack() const
		"GetCode@18948eec3533ae11\0" // CPyCodeRef GetCode() const
		"GetLastInstruction@fd7d68f65\0" // Int32 GetLastInstruction() const
		"";
		PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(CPyFrameInterface, , "net.maxon.python.interface.cpyframe", "maxon.py.CPyFrameInterface", (&CPyInterface::_interface));
		template <typename DUMMY> maxon::Int CPyFrameInterface::PrivateInstantiateNullValueHelper()
		{
			return 0
			| maxon::details::InstantiateNullReturnValue<CPyCodeRef>(OVERLOAD_MAX_RANK)
			| maxon::details::InstantiateNullReturnValue<CPyFrameRef>(OVERLOAD_MAX_RANK)
			;
		}
		const maxon::Char* const CPyTracebackInterface::MTable::_ids = 
		"GetNext@a78434c2947008ca\0" // CPyTracebackRef GetNext() const
		"GetLineNumber@fd7d68f65\0" // Int32 GetLineNumber() const
		"GetFrameRef@f9fd990099dae1a9\0" // CPyFrameRef GetFrameRef() const
		"";
		PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(CPyTracebackInterface, , "net.maxon.python.interface.cpytraceback", "maxon.py.CPyTracebackInterface", (&CPyInterface::_interface));
		template <typename DUMMY> maxon::Int CPyTracebackInterface::PrivateInstantiateNullValueHelper()
		{
			return 0
			| maxon::details::InstantiateNullReturnValue<CPyFrameRef>(OVERLOAD_MAX_RANK)
			| maxon::details::InstantiateNullReturnValue<CPyTracebackRef>(OVERLOAD_MAX_RANK)
			;
		}
		const maxon::Char* const CPyCodeInterface::MTable::_ids = 
		"GetFilename@1be8b0e99fe\0" // CPyRef GetFilename() const
		"GetName@1be8b0e99fe\0" // CPyRef GetName() const
		"";
		PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(CPyCodeInterface, , "net.maxon.python.interface.cpycode", "maxon.py.CPyCodeInterface", (&CPyInterface::_interface));
		template <typename DUMMY> maxon::Int CPyCodeInterface::PrivateInstantiateNullValueHelper()
		{
			return 0
			| maxon::details::InstantiateNullReturnValue<CPyCodeRef>(OVERLOAD_MAX_RANK)
			| maxon::details::InstantiateNullReturnValue<CPyRef>(OVERLOAD_MAX_RANK)
			;
		}
		const maxon::Char* const MPyClassInterface::MTable::_ids = 
		"";
		PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(MPyClassInterface, , "net.maxon.python.interface.mpyclass", "maxon.py.MPyClassInterface", (&CPyInterface::_interface));
		template <typename DUMMY> maxon::Int MPyClassInterface::PrivateInstantiateNullValueHelper()
		{
			return 0
			| maxon::details::InstantiateNullReturnValue<MPyClassRef>(OVERLOAD_MAX_RANK)
			;
		}
		const maxon::Char* const MPyMemberInterface::MTable::_ids = 
		"";
		PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(MPyMemberInterface, , "net.maxon.python.interface.mpymember", "maxon.py.MPyMemberInterface", (&CPyInterface::_interface));
		template <typename DUMMY> maxon::Int MPyMemberInterface::PrivateInstantiateNullValueHelper()
		{
			return 0
			| maxon::details::InstantiateNullReturnValue<MPyMemberRef>(OVERLOAD_MAX_RANK)
			;
		}
		const maxon::Char* const MPyFunctionInterface::MTable::_ids = 
		"GetFunction@546a834ab62c0b79\0" // const reflection::Function* GetFunction()
		"";
		PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(MPyFunctionInterface, , "net.maxon.python.interface.mpyfunction", "maxon.py.MPyFunctionInterface", (&CPyInterface::_interface));
		template <typename DUMMY> maxon::Int MPyFunctionInterface::PrivateInstantiateNullValueHelper()
		{
			return 0
			| maxon::details::InstantiateNullReturnValue<MPyFunctionRef>(OVERLOAD_MAX_RANK)
			;
		}
		const maxon::Char* const MPyDataTypeInterface::MTable::_ids = 
		"GetType@f6200306f4b3253c\0" // const DataType& GetType() const
		"";
		PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(MPyDataTypeInterface, , "net.maxon.python.interface.mpydatatype", "maxon.py.MPyDataTypeInterface", (&CPyInterface::_interface));
		template <typename DUMMY> maxon::Int MPyDataTypeInterface::PrivateInstantiateNullValueHelper()
		{
			return 0
			| maxon::details::InstantiateNullReturnValue<MPyDataTypeRef>(OVERLOAD_MAX_RANK)
			| maxon::details::InstantiateNullReturnValue<const DataType&>(OVERLOAD_MAX_RANK)
			;
		}
		const maxon::Char* const MPyDataInterface::MTable::_ids = 
		"GetType@f6200306f4b3253c\0" // const DataType& GetType() const
		"GetMappingType@f6200306f4b3253c\0" // const DataType& GetMappingType() const
		"GetData@79969e83\0" // Data* GetData()
		"GetData@629b06512e59f25a\0" // const Data* GetData() const
		"PrivateGetPtr@d6646c3a063c45e7\0" // const Generic* PrivateGetPtr() const
		"PrivateGetPtr@39b188901530\0" // Generic* PrivateGetPtr()
		"";
		PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(MPyDataInterface, , "net.maxon.python.interface.mpydata", "maxon.py.MPyDataInterface", (&CPyInterface::_interface));
		template <typename DUMMY> maxon::Int MPyDataInterface::PrivateInstantiateNullValueHelper()
		{
			return 0
			| maxon::details::InstantiateNullReturnValue<MPyDataRef>(OVERLOAD_MAX_RANK)
			| maxon::details::InstantiateNullReturnValue<const DataType&>(OVERLOAD_MAX_RANK)
			;
		}
		const maxon::Char* const MPyCallerContextInterface::MTable::_ids = 
		"";
		PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(MPyCallerContextInterface, , "net.maxon.python.interface.mpycallercontext", "maxon.py.MPyCallerContextInterface", (&CPyInterface::_interface));
		template <typename DUMMY> maxon::Int MPyCallerContextInterface::PrivateInstantiateNullValueHelper()
		{
			return 0
			| maxon::details::InstantiateNullReturnValue<MPyCallerContextRef>(OVERLOAD_MAX_RANK)
			;
		}
#ifdef MAXON_COMPILER_INTEL
#endif
#ifdef MAXON_COMPILER_INTEL
#endif
		MAXON_REGISTRY_REGISTER(CPyReferences27);
		namespace CPyReferences27
		{
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(CPy, , "net.maxon.python.pyreference27.cpy");
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(CPyType, , "net.maxon.python.pyreference27.cpytype");
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(CPyFrame, , "net.maxon.python.pyreference27.cpyframe");
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(CPyTraceback, , "net.maxon.python.pyreference27.cpytraceback");
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(CPyCode, , "net.maxon.python.pyreference27.cpycode");
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(MPyClass, , "net.maxon.python.pyreference27.mpyclass");
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(MPyMember, , "net.maxon.python.pyreference27.mpymember");
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(MPyFunction, , "net.maxon.python.pyreference27.mpyfunction");
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(MPyDataType, , "net.maxon.python.pyreference27.mpydatatype");
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(MPyData, , "net.maxon.python.pyreference27.mpydata");
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(MPyCallerContext, , "net.maxon.python.pyreference27.mpycallercontext");
		}
	}
}
#endif
static maxon::details::ForceEvaluation s_forceEval_cpython_ref(0
	| maxon::py::CPyInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
	| maxon::py::CPyTypeInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
	| maxon::py::CPyFrameInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
	| maxon::py::CPyTracebackInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
	| maxon::py::CPyCodeInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
	| maxon::py::MPyClassInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
	| maxon::py::MPyMemberInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
	| maxon::py::MPyFunctionInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
	| maxon::py::MPyDataTypeInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
	| maxon::py::MPyDataInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
	| maxon::py::MPyCallerContextInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
);

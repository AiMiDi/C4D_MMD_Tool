#if 1
namespace maxon
{
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(DT_IDENT_VOID,, "net.maxon.ident_void");
#ifndef MAXON_COMPILER_CLANG
#endif
#ifndef MAXON_COMPILER_CLANG
#endif
	namespace enum190
	{
		enum class PREPAREHELPERFLAGS
		{
			NONE								= 0,
		
			INITIALIZE_READ			= (1 << 0),	///< The helper's ReadAction will get a call with INITIALIZEHASH before the class has been read.
			INITIALIZE_WRITE		= (1 << 1),	///< The helper's WriteAction will get a call with INITIALIZEHASH before the class has been written.
		
			FINALIZE_READ				= (1 << 2),	///< The helper's ReadAction will get a call with FINALIZEHASH after the class has been read.
			FINALIZE_WRITE			= (1 << 3),	///< The helper's WriteAction will get a call with FINALIZEHASH after the class has been written.
		
			VALIDATE_STATE			= (1 << 4)	///< The helper's ReadAction will get a call after all input operations are finished. Objects that interact with others can then update necessary information.
		} ;
		static const maxon::UInt64 PREPAREHELPERFLAGS_values[] = {maxon::UInt64(enum190::PREPAREHELPERFLAGS::NONE), maxon::UInt64(enum190::PREPAREHELPERFLAGS::INITIALIZE_READ), maxon::UInt64(enum190::PREPAREHELPERFLAGS::INITIALIZE_WRITE), maxon::UInt64(enum190::PREPAREHELPERFLAGS::FINALIZE_READ), maxon::UInt64(enum190::PREPAREHELPERFLAGS::FINALIZE_WRITE), maxon::UInt64(enum190::PREPAREHELPERFLAGS::VALIDATE_STATE)};
		static const maxon::EnumInfo PREPAREHELPERFLAGS_info{"PREPAREHELPERFLAGS", SIZEOF(PREPAREHELPERFLAGS), true, "NONE\0INITIALIZE_READ\0INITIALIZE_WRITE\0FINALIZE_READ\0FINALIZE_WRITE\0VALIDATE_STATE\0", PREPAREHELPERFLAGS_values, std::extent<decltype(PREPAREHELPERFLAGS_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_PREPAREHELPERFLAGS190(){ return enum190::PREPAREHELPERFLAGS_info; }
	const maxon::Char* const DataSerializeInterface::MTable::_ids = 
		"DescribeElement@abe746afd1ef0220\0" // Result<void> DescribeElement(const Char* name, const DataType& dt, Int objectOffset, KeyValueConversionFunc* func, DESCRIBEFLAGS flags, UInt64 mask, UInt64 value) const
		"PrepareHelperClass@b0fd11c275448f5f\0" // Result<void> PrepareHelperClass(CreateIoHelperFunc* createFunc, DeleteIoHelperFunc* deleteFunc, ReadIoHelperFunc* readFunc, WriteIoHelperFunc* writeFunc, PREPAREHELPERFLAGS flags) const
		"RegisterObjectSubstitution@b7e36fe40c2afe2f\0" // Result<void> RegisterObjectSubstitution(ReferenceSubstitutionFunction&& func)
		"RegisterDefaults@7b9cffd89ba51026\0" // Result<void*> RegisterDefaults(CreateIoHelperFunc* createFunc, DeleteIoHelperFunc* deleteFunc) const
	"";
	const maxon::METHOD_FLAGS DataSerializeInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(DataSerializeInterface, , "net.maxon.interface.dataserialize", "maxon.DataSerializeInterface", (ObjectInterface::PrivateGetInterface()));
	const maxon::Char* const DataSerializeWriterInterface::MTable::_ids = 
		"WriteDocument@4384c3f494e3b621\0" // Result<void> WriteDocument(const Id& id, const ConstDataPtr& data)
	"";
	const maxon::METHOD_FLAGS DataSerializeWriterInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(DataSerializeWriterInterface, , "net.maxon.interface.dataserializewriter", "maxon.DataSerializeWriterInterface", (DataSerializeInterface::PrivateGetInterface()));
	const maxon::Char* const DataSerializeReaderInterface::MTable::_ids = 
		"ReadDocument@bdd1e641f15ecb4e\0" // Result<void> ReadDocument(const Id& id, const DataPtr& data)
	"";
	const maxon::METHOD_FLAGS DataSerializeReaderInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(DataSerializeReaderInterface, , "net.maxon.interface.dataserializereader", "maxon.DataSerializeReaderInterface", (DataSerializeInterface::PrivateGetInterface()));
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(DataSerializeBaseClass, , "net.maxon.class.dataserializebase");
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(DataSerializeReaderClass, , "net.maxon.class.dataserializereader");
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(DataSerializeWriterClass, , "net.maxon.class.dataserializewriter");
}
#endif

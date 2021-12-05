#if 1
namespace maxon
{
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(DT_IDENT_VOID,, "net.maxon.ident_void");
#ifndef MAXON_COMPILER_CLANG
#endif
#ifndef MAXON_COMPILER_CLANG
#endif
	namespace enum189 { enum class PREPAREHELPERFLAGS
	{
		NONE								= 0,
	
		INITIALIZE_READ			= (1 << 0),	///< The helper's ReadAction will get a call with INITIALIZEHASH before the class has been read.
		INITIALIZE_WRITE		= (1 << 1),	///< The helper's WriteAction will get a call with INITIALIZEHASH before the class has been written.
	
		FINALIZE_READ				= (1 << 2),	///< The helper's ReadAction will get a call with FINALIZEHASH after the class has been read.
		FINALIZE_WRITE			= (1 << 3),	///< The helper's WriteAction will get a call with FINALIZEHASH after the class has been written.
	
		VALIDATE_STATE			= (1 << 4)	///< The helper's ReadAction will get a call after all input operations are finished. Objects that interact with others can then update necessary information.
	} ; }
	maxon::String PrivateToString_PREPAREHELPERFLAGS189(std::underlying_type<enum189::PREPAREHELPERFLAGS>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum189::PREPAREHELPERFLAGS::NONE, (maxon::UInt64) enum189::PREPAREHELPERFLAGS::INITIALIZE_READ, (maxon::UInt64) enum189::PREPAREHELPERFLAGS::INITIALIZE_WRITE, (maxon::UInt64) enum189::PREPAREHELPERFLAGS::FINALIZE_READ, (maxon::UInt64) enum189::PREPAREHELPERFLAGS::FINALIZE_WRITE, (maxon::UInt64) enum189::PREPAREHELPERFLAGS::VALIDATE_STATE};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "PREPAREHELPERFLAGS", SIZEOF(x), true, values, "NONE\0INITIALIZE_READ\0INITIALIZE_WRITE\0FINALIZE_READ\0FINALIZE_WRITE\0VALIDATE_STATE\0", fmt);
	}
	const maxon::Char* const DataSerializeInterface::MTable::_ids = 
		"DescribeElement@df490387a922b5bd\0" // Result<void> DescribeElement(const Char* name, const DataType& dt, Int objectOffset, KeyValueConversionFunc* func, DESCRIBEFLAGS flags, UInt64 mask, UInt64 value) const
		"PrepareHelperClass@7e3c15422a34f012\0" // Result<void> PrepareHelperClass(CreateIoHelperFunc* createFunc, DeleteIoHelperFunc* deleteFunc, ReadIoHelperFunc* readFunc, WriteIoHelperFunc* writeFunc, PREPAREHELPERFLAGS flags) const
		"RegisterObjectSubstitution@d2f84113c1d53ae8\0" // Result<void> RegisterObjectSubstitution(ReferenceSubstitutionFunction&& func)
		"RegisterDefaults@588529f357742be5\0" // Result<void*> RegisterDefaults(CreateIoHelperFunc* createFunc, DeleteIoHelperFunc* deleteFunc) const
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(DataSerializeInterface, , "net.maxon.interface.dataserialize", "maxon.DataSerializeInterface", (&ObjectInterface::_interface));
	const maxon::Char* const DataSerializeWriterInterface::MTable::_ids = 
		"WriteDocument@8379acb55f0fa3f2\0" // Result<void> WriteDocument(const Id& id, const ConstDataPtr& data)
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(DataSerializeWriterInterface, , "net.maxon.interface.dataserializewriter", "maxon.DataSerializeWriterInterface", (&DataSerializeInterface::_interface));
	const maxon::Char* const DataSerializeReaderInterface::MTable::_ids = 
		"ReadDocument@018a3d9dc2151ff5\0" // Result<void> ReadDocument(const Id& id, const DataPtr& data)
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(DataSerializeReaderInterface, , "net.maxon.interface.dataserializereader", "maxon.DataSerializeReaderInterface", (&DataSerializeInterface::_interface));
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(DataSerializeBaseClass, , "net.maxon.class.dataserializebase");
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(DataSerializeReaderClass, , "net.maxon.class.dataserializereader");
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(DataSerializeWriterClass, , "net.maxon.class.dataserializewriter");
}
#endif

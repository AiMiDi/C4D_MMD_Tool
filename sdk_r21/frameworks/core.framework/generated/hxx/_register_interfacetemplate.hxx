#if 1
namespace maxon
{
	const maxon::Char* const NumberBaseInterface::MTable::_ids = 
		"GenericMul@75fc83a16bf00d4a\0" // NumberBaseRef<> GenericMul(const NumberBaseRef<>& x) const
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(NumberBaseInterface, , "net.maxon.interface.numberbase", "maxon.NumberBaseInterface", (&ObjectInterface::_interface));
	constexpr inline const maxon::Char* PrivateGetInstantiationId(NumberInterface<Int,4>*) { return "net.maxon.interface.number.int"; }
	constexpr inline const maxon::Char* PrivateGetInstantiationSourceName(NumberInterface<Int,4>*) { return "maxon.NumberInterface<Int,4>"; }
	template maxon::InterfaceReference NumberInterface<Int,4>::_interface;
	template maxon::NonvirtualMTableReference NumberInterface<Int,4>::_nonvirtualMTable;
	template NumberInterface<Int,4>::MTable::NVMTable NumberInterface<Int,4>::MTable::NVMTable::_instance;
	template maxon::NonvirtualInterfaceReference NumberInterface<Int,4>::_staticInterface;
	template NumberInterface<Int,4>::Hxx2::StaticMTable NumberInterface<Int,4>::Hxx2::StaticMTable::_instance;
	constexpr inline const maxon::Char* PrivateGetInstantiationId(Number2Interface<Int>*) { return "net.maxon.interface.number2.int"; }
	constexpr inline const maxon::Char* PrivateGetInstantiationSourceName(Number2Interface<Int>*) { return "maxon.Number2Interface<Int>"; }
	template maxon::InterfaceReference Number2Interface<Int>::_interface;
	template maxon::NonvirtualMTableReference Number2Interface<Int>::_nonvirtualMTable;
	template Number2Interface<Int>::MTable::NVMTable Number2Interface<Int>::MTable::NVMTable::_instance;
	template maxon::NonvirtualInterfaceReference Number2Interface<Int>::_staticInterface;
	template Number2Interface<Int>::Hxx2::StaticMTable Number2Interface<Int>::Hxx2::StaticMTable::_instance;
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(IntNumberClass, , "net.maxon.class.number.int");
}
#endif

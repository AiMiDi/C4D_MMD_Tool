#if 1
namespace maxon
{
	constexpr inline const maxon::Char* PrivateGetInstantiationId(NumberInterface<Float,8>*) { return "net.maxon.interface.number.float"; }
	constexpr inline const maxon::Char* PrivateGetInstantiationSourceName(NumberInterface<Float,8>*) { return "maxon.NumberInterface<Float,8>"; }
	template maxon::InterfaceReference NumberInterface<Float,8>::_interface;
	template maxon::NonvirtualMTableReference NumberInterface<Float,8>::_nonvirtualMTable;
	template NumberInterface<Float,8>::MTable::NVMTable NumberInterface<Float,8>::MTable::NVMTable::_instance;
	template maxon::NonvirtualInterfaceReference NumberInterface<Float,8>::_staticInterface;
	template NumberInterface<Float,8>::Hxx2::StaticMTable NumberInterface<Float,8>::Hxx2::StaticMTable::_instance;
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(FloatNumberClass, , "net.maxon.class.number.float");
}
#endif

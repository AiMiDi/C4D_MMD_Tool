
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_NumberInterfaceNumberInterface_Float_8_); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_NumberInterfaceNumberInterface_Float_8_() { new (s_ui_maxon_NumberInterfaceNumberInterface_Float_8_) maxon::EntityUse(NumberInterface<Float,8>::_interface.GetReference(), &maxon::g_translationUnit, "maxon/interfacetemplate_instantiation.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_NumberInterfaceNumberInterface_Float_8_(NumberInterface<Float,8>::_interface.GetReference(), &maxon::g_translationUnit, "maxon/interfacetemplate_instantiation.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui1_maxon_NumberInterfaceNumberInterface_Float_8_); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui1_maxon_NumberInterfaceNumberInterface_Float_8_() { new (s_ui1_maxon_NumberInterfaceNumberInterface_Float_8_) maxon::EntityUse(NumberInterface<Float,8>::_nonvirtualMTable.GetReference(), &maxon::g_translationUnit, "maxon/interfacetemplate_instantiation.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui1_maxon_NumberInterfaceNumberInterface_Float_8_(NumberInterface<Float,8>::_nonvirtualMTable.GetReference(), &maxon::g_translationUnit, "maxon/interfacetemplate_instantiation.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_usi_maxon_NumberInterfaceNumberInterface_Float_8_); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_usi_maxon_NumberInterfaceNumberInterface_Float_8_() { new (s_usi_maxon_NumberInterfaceNumberInterface_Float_8_) maxon::EntityUse(NumberInterface<Float,8>::_staticInterface.GetReference(), &maxon::g_translationUnit, "maxon/interfacetemplate_instantiation.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_usi_maxon_NumberInterfaceNumberInterface_Float_8_(NumberInterface<Float,8>::_staticInterface.GetReference(), &maxon::g_translationUnit, "maxon/interfacetemplate_instantiation.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
extern template NumberInterface<Float,8>::MTable::NVMTable NumberInterface<Float,8>::MTable::NVMTable::_instance;
extern template NumberInterface<Float,8>::Hxx2::StaticMTable NumberInterface<Float,8>::Hxx2::StaticMTable::_instance;
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif


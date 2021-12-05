
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1
#ifdef MAXON_TARGET_ANDROID
#endif
#ifdef MAXON_TARGET_ANDROID

struct Java::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = false;
	JNIEnv* (*_Java_GetMainThreadJavaEnv) ();
	JNIEnv* (*_Java_GetJavaEnv) ();
	JavaVM* (*_Java_GetJavaVM) ();
	jobject (*_Java_GetNativeActivityObject) ();
	AAssetManager* (*_Java_GetAssetManager) ();
	jobject (*_Java_AllcoObject) (JNIEnv* env, jclass javaClass);
	jclass (*_Java_MakeGlobalRef) (JNIEnv* env, const char* className);
	void (*_Java_DeleteGlobalRef) (JNIEnv* env, jclass& javaClass);
	jfieldID (*_Java_GetFieldID) (JNIEnv* env, jclass javaClass, const char* memberName, const char* signature);
	jlong (*_Java_GetLongField) (JNIEnv* env, jobject obj, jfieldID field);
	void (*_Java_SetLongField) (JNIEnv* env, jobject obj, jfieldID field, jlong value);
	String (*_Java_ConvertString) (JNIEnv* env, jstring str);
	jstring (*_Java_ConvertString_1) (JNIEnv* env, const String& str);
	jobject (*_Java_IntGetStaticObjectField) (JNIEnv* env, const Char* className, const Char* memberName, const Char* signature);
	jobject (*_Java_IntCallStaticMethodObject) (JNIEnv* env, const Char* className, const Char* memberName, const Char* signature, va_list list);
	void (*_Java_IntCallStaticMethodVoid) (JNIEnv* env, const Char* className, const Char* memberName, const Char* signature, va_list list);
	jlong (*_Java_IntCallStaticMethodLong) (JNIEnv* env, const Char* className, const Char* memberName, const Char* signature, va_list list);
	jobject (*_Java_IntCallMethodObject) (JNIEnv* env, jobject object, const Char* className, const Char* memberName, const Char* signature, va_list list);
	jlong (*_Java_IntCallMethodLong) (JNIEnv* env, jobject object, const Char* className, const Char* memberName, const Char* signature, va_list list);
	template <typename IMPL> void Init()
	{
		_Java_GetMainThreadJavaEnv = &IMPL::_Java_GetMainThreadJavaEnv;
		_Java_GetJavaEnv = &IMPL::_Java_GetJavaEnv;
		_Java_GetJavaVM = &IMPL::_Java_GetJavaVM;
		_Java_GetNativeActivityObject = &IMPL::_Java_GetNativeActivityObject;
		_Java_GetAssetManager = &IMPL::_Java_GetAssetManager;
		_Java_AllcoObject = &IMPL::_Java_AllcoObject;
		_Java_MakeGlobalRef = &IMPL::_Java_MakeGlobalRef;
		_Java_DeleteGlobalRef = &IMPL::_Java_DeleteGlobalRef;
		_Java_GetFieldID = &IMPL::_Java_GetFieldID;
		_Java_GetLongField = &IMPL::_Java_GetLongField;
		_Java_SetLongField = &IMPL::_Java_SetLongField;
		_Java_ConvertString = &IMPL::_Java_ConvertString;
		_Java_ConvertString_1 = &IMPL::_Java_ConvertString_1;
		_Java_IntGetStaticObjectField = &IMPL::_Java_IntGetStaticObjectField;
		_Java_IntCallStaticMethodObject = &IMPL::_Java_IntCallStaticMethodObject;
		_Java_IntCallStaticMethodVoid = &IMPL::_Java_IntCallStaticMethodVoid;
		_Java_IntCallStaticMethodLong = &IMPL::_Java_IntCallStaticMethodLong;
		_Java_IntCallMethodObject = &IMPL::_Java_IntCallMethodObject;
		_Java_IntCallMethodLong = &IMPL::_Java_IntCallMethodLong;
	}
};

struct Java::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
	static JNIEnv* _Java_GetMainThreadJavaEnv() { return C::GetMainThreadJavaEnv(); }
	static JNIEnv* _Java_GetJavaEnv() { return C::GetJavaEnv(); }
	static JavaVM* _Java_GetJavaVM() { return C::GetJavaVM(); }
	static jobject _Java_GetNativeActivityObject() { return C::GetNativeActivityObject(); }
	static AAssetManager* _Java_GetAssetManager() { return C::GetAssetManager(); }
	static jobject _Java_AllcoObject(JNIEnv* env, jclass javaClass) { return C::AllcoObject(env, std::forward<jclass>(javaClass)); }
	static jclass _Java_MakeGlobalRef(JNIEnv* env, const char* className) { return C::MakeGlobalRef(env, className); }
	static void _Java_DeleteGlobalRef(JNIEnv* env, jclass& javaClass) { return C::DeleteGlobalRef(env, javaClass); }
	static jfieldID _Java_GetFieldID(JNIEnv* env, jclass javaClass, const char* memberName, const char* signature) { return C::GetFieldID(env, std::forward<jclass>(javaClass), memberName, signature); }
	static jlong _Java_GetLongField(JNIEnv* env, jobject obj, jfieldID field) { return C::GetLongField(env, std::forward<jobject>(obj), std::forward<jfieldID>(field)); }
	static void _Java_SetLongField(JNIEnv* env, jobject obj, jfieldID field, jlong value) { return C::SetLongField(env, std::forward<jobject>(obj), std::forward<jfieldID>(field), std::forward<jlong>(value)); }
	static String _Java_ConvertString(JNIEnv* env, jstring str) { return C::ConvertString(env, std::forward<jstring>(str)); }
	static jstring _Java_ConvertString_1(JNIEnv* env, const String& str) { return C::ConvertString(env, str); }
	static jobject _Java_IntGetStaticObjectField(JNIEnv* env, const Char* className, const Char* memberName, const Char* signature) { return C::IntGetStaticObjectField(env, className, memberName, signature); }
	static jobject _Java_IntCallStaticMethodObject(JNIEnv* env, const Char* className, const Char* memberName, const Char* signature, va_list list) { return C::IntCallStaticMethodObject(env, className, memberName, signature, list); }
	static void _Java_IntCallStaticMethodVoid(JNIEnv* env, const Char* className, const Char* memberName, const Char* signature, va_list list) { return C::IntCallStaticMethodVoid(env, className, memberName, signature, list); }
	static jlong _Java_IntCallStaticMethodLong(JNIEnv* env, const Char* className, const Char* memberName, const Char* signature, va_list list) { return C::IntCallStaticMethodLong(env, className, memberName, signature, list); }
	static jobject _Java_IntCallMethodObject(JNIEnv* env, jobject object, const Char* className, const Char* memberName, const Char* signature, va_list list) { return C::IntCallMethodObject(env, std::forward<jobject>(object), className, memberName, signature, list); }
	static jlong _Java_IntCallMethodLong(JNIEnv* env, jobject object, const Char* className, const Char* memberName, const Char* signature, va_list list) { return C::IntCallMethodLong(env, std::forward<jobject>(object), className, memberName, signature, list); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto Java::GetMainThreadJavaEnv() -> JNIEnv*
{
	return MTable::_instance._Java_GetMainThreadJavaEnv();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Java::GetJavaEnv() -> JNIEnv*
{
	return MTable::_instance._Java_GetJavaEnv();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Java::GetJavaVM() -> JavaVM*
{
	return MTable::_instance._Java_GetJavaVM();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Java::GetNativeActivityObject() -> jobject
{
	return MTable::_instance._Java_GetNativeActivityObject();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Java::GetAssetManager() -> AAssetManager*
{
	return MTable::_instance._Java_GetAssetManager();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Java::AllcoObject(JNIEnv* env, jclass javaClass) -> jobject
{
	return MTable::_instance._Java_AllcoObject(env, std::forward<jclass>(javaClass));
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Java::MakeGlobalRef(JNIEnv* env, const char* className) -> jclass
{
	return MTable::_instance._Java_MakeGlobalRef(env, className);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Java::DeleteGlobalRef(JNIEnv* env, jclass& javaClass) -> void
{
	return MTable::_instance._Java_DeleteGlobalRef(env, javaClass);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Java::GetFieldID(JNIEnv* env, jclass javaClass, const char* memberName, const char* signature) -> jfieldID
{
	return MTable::_instance._Java_GetFieldID(env, std::forward<jclass>(javaClass), memberName, signature);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Java::GetLongField(JNIEnv* env, jobject obj, jfieldID field) -> jlong
{
	return MTable::_instance._Java_GetLongField(env, std::forward<jobject>(obj), std::forward<jfieldID>(field));
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Java::SetLongField(JNIEnv* env, jobject obj, jfieldID field, jlong value) -> void
{
	return MTable::_instance._Java_SetLongField(env, std::forward<jobject>(obj), std::forward<jfieldID>(field), std::forward<jlong>(value));
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Java::ConvertString(JNIEnv* env, jstring str) -> String
{
	return MTable::_instance._Java_ConvertString(env, std::forward<jstring>(str));
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Java::ConvertString(JNIEnv* env, const String& str) -> jstring
{
	return MTable::_instance._Java_ConvertString_1(env, str);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Java::IntGetStaticObjectField(JNIEnv* env, const Char* className, const Char* memberName, const Char* signature) -> jobject
{
	return MTable::_instance._Java_IntGetStaticObjectField(env, className, memberName, signature);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Java::IntCallStaticMethodObject(JNIEnv* env, const Char* className, const Char* memberName, const Char* signature, va_list list) -> jobject
{
	return MTable::_instance._Java_IntCallStaticMethodObject(env, className, memberName, signature, list);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Java::IntCallStaticMethodVoid(JNIEnv* env, const Char* className, const Char* memberName, const Char* signature, va_list list) -> void
{
	return MTable::_instance._Java_IntCallStaticMethodVoid(env, className, memberName, signature, list);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Java::IntCallStaticMethodLong(JNIEnv* env, const Char* className, const Char* memberName, const Char* signature, va_list list) -> jlong
{
	return MTable::_instance._Java_IntCallStaticMethodLong(env, className, memberName, signature, list);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Java::IntCallMethodObject(JNIEnv* env, jobject object, const Char* className, const Char* memberName, const Char* signature, va_list list) -> jobject
{
	return MTable::_instance._Java_IntCallMethodObject(env, std::forward<jobject>(object), className, memberName, signature, list);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Java::IntCallMethodLong(JNIEnv* env, jobject object, const Char* className, const Char* memberName, const Char* signature, va_list list) -> jlong
{
	return MTable::_instance._Java_IntCallMethodLong(env, std::forward<jobject>(object), className, memberName, signature, list);
}

#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_Java); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_Java() { new (s_ui_maxon_Java) maxon::EntityUse(Java::_interface.GetReference(), &maxon::g_translationUnit, "maxon/java.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_Java(Java::_interface.GetReference(), &maxon::g_translationUnit, "maxon/java.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif


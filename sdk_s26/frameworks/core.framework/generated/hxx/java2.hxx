
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
constexpr const maxon::Char* Java::PrivateGetCppName() { return nullptr; }

struct Java::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = false;
	JNIEnv* (*Java_GetMainThreadJavaEnv) ();
	JNIEnv* (*Java_GetJavaEnv) ();
	JavaVM* (*Java_GetJavaVM) ();
	jobject (*Java_GetNativeActivityObject) ();
	AAssetManager* (*Java_GetAssetManager) ();
	jobject (*Java_AllcoObject) (JNIEnv* env, jclass javaClass);
	jclass (*Java_MakeGlobalRef) (JNIEnv* env, const char* className);
	void (*Java_DeleteGlobalRef) (JNIEnv* env, jclass& javaClass);
	jfieldID (*Java_GetFieldID) (JNIEnv* env, jclass javaClass, const char* memberName, const char* signature);
	jlong (*Java_GetLongField) (JNIEnv* env, jobject obj, jfieldID field);
	void (*Java_SetLongField) (JNIEnv* env, jobject obj, jfieldID field, jlong value);
	String (*Java_ConvertString) (JNIEnv* env, jstring str);
	jstring (*Java_ConvertString_1) (JNIEnv* env, const String& str);
	jobject (*Java_IntGetStaticObjectField) (JNIEnv* env, const Char* className, const Char* memberName, const Char* signature);
	jobject (*Java_IntCallStaticMethodObject) (JNIEnv* env, const Char* className, const Char* memberName, const Char* signature, va_list list);
	void (*Java_IntCallStaticMethodVoid) (JNIEnv* env, const Char* className, const Char* memberName, const Char* signature, va_list list);
	jlong (*Java_IntCallStaticMethodLong) (JNIEnv* env, const Char* className, const Char* memberName, const Char* signature, va_list list);
	jobject (*Java_IntCallMethodObject) (JNIEnv* env, jobject object, const Char* className, const Char* memberName, const Char* signature, va_list list);
	jlong (*Java_IntCallMethodLong) (JNIEnv* env, jobject object, const Char* className, const Char* memberName, const Char* signature, va_list list);
	template <typename IMPL> void Init()
	{
		Java_GetMainThreadJavaEnv = &IMPL::Java_GetMainThreadJavaEnv;
		Java_GetJavaEnv = &IMPL::Java_GetJavaEnv;
		Java_GetJavaVM = &IMPL::Java_GetJavaVM;
		Java_GetNativeActivityObject = &IMPL::Java_GetNativeActivityObject;
		Java_GetAssetManager = &IMPL::Java_GetAssetManager;
		Java_AllcoObject = &IMPL::Java_AllcoObject;
		Java_MakeGlobalRef = &IMPL::Java_MakeGlobalRef;
		Java_DeleteGlobalRef = &IMPL::Java_DeleteGlobalRef;
		Java_GetFieldID = &IMPL::Java_GetFieldID;
		Java_GetLongField = &IMPL::Java_GetLongField;
		Java_SetLongField = &IMPL::Java_SetLongField;
		Java_ConvertString = &IMPL::Java_ConvertString;
		Java_ConvertString_1 = &IMPL::Java_ConvertString_1;
		Java_IntGetStaticObjectField = &IMPL::Java_IntGetStaticObjectField;
		Java_IntCallStaticMethodObject = &IMPL::Java_IntCallStaticMethodObject;
		Java_IntCallStaticMethodVoid = &IMPL::Java_IntCallStaticMethodVoid;
		Java_IntCallStaticMethodLong = &IMPL::Java_IntCallStaticMethodLong;
		Java_IntCallMethodObject = &IMPL::Java_IntCallMethodObject;
		Java_IntCallMethodLong = &IMPL::Java_IntCallMethodLong;
	}
};

struct Java::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
		static JNIEnv* Java_GetMainThreadJavaEnv() { return C::GetMainThreadJavaEnv(); }
		static JNIEnv* Java_GetJavaEnv() { return C::GetJavaEnv(); }
		static JavaVM* Java_GetJavaVM() { return C::GetJavaVM(); }
		static jobject Java_GetNativeActivityObject() { return C::GetNativeActivityObject(); }
		static AAssetManager* Java_GetAssetManager() { return C::GetAssetManager(); }
		static jobject Java_AllcoObject(JNIEnv* env, jclass javaClass) { return C::AllcoObject(env, std::forward<jclass>(javaClass)); }
		static jclass Java_MakeGlobalRef(JNIEnv* env, const char* className) { return C::MakeGlobalRef(env, className); }
		static void Java_DeleteGlobalRef(JNIEnv* env, jclass& javaClass) { return C::DeleteGlobalRef(env, javaClass); }
		static jfieldID Java_GetFieldID(JNIEnv* env, jclass javaClass, const char* memberName, const char* signature) { return C::GetFieldID(env, std::forward<jclass>(javaClass), memberName, signature); }
		static jlong Java_GetLongField(JNIEnv* env, jobject obj, jfieldID field) { return C::GetLongField(env, std::forward<jobject>(obj), std::forward<jfieldID>(field)); }
		static void Java_SetLongField(JNIEnv* env, jobject obj, jfieldID field, jlong value) { return C::SetLongField(env, std::forward<jobject>(obj), std::forward<jfieldID>(field), std::forward<jlong>(value)); }
		static String Java_ConvertString(JNIEnv* env, jstring str) { return C::ConvertString(env, std::forward<jstring>(str)); }
		static jstring Java_ConvertString_1(JNIEnv* env, const String& str) { return C::ConvertString(env, str); }
		static jobject Java_IntGetStaticObjectField(JNIEnv* env, const Char* className, const Char* memberName, const Char* signature) { return C::IntGetStaticObjectField(env, className, memberName, signature); }
		static jobject Java_IntCallStaticMethodObject(JNIEnv* env, const Char* className, const Char* memberName, const Char* signature, va_list list) { return C::IntCallStaticMethodObject(env, className, memberName, signature, list); }
		static void Java_IntCallStaticMethodVoid(JNIEnv* env, const Char* className, const Char* memberName, const Char* signature, va_list list) { return C::IntCallStaticMethodVoid(env, className, memberName, signature, list); }
		static jlong Java_IntCallStaticMethodLong(JNIEnv* env, const Char* className, const Char* memberName, const Char* signature, va_list list) { return C::IntCallStaticMethodLong(env, className, memberName, signature, list); }
		static jobject Java_IntCallMethodObject(JNIEnv* env, jobject object, const Char* className, const Char* memberName, const Char* signature, va_list list) { return C::IntCallMethodObject(env, std::forward<jobject>(object), className, memberName, signature, list); }
		static jlong Java_IntCallMethodLong(JNIEnv* env, jobject object, const Char* className, const Char* memberName, const Char* signature, va_list list) { return C::IntCallMethodLong(env, std::forward<jobject>(object), className, memberName, signature, list); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto Java::GetMainThreadJavaEnv() -> JNIEnv*
{
	return MTable::_instance.Java_GetMainThreadJavaEnv();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Java::GetJavaEnv() -> JNIEnv*
{
	return MTable::_instance.Java_GetJavaEnv();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Java::GetJavaVM() -> JavaVM*
{
	return MTable::_instance.Java_GetJavaVM();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Java::GetNativeActivityObject() -> jobject
{
	return MTable::_instance.Java_GetNativeActivityObject();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Java::GetAssetManager() -> AAssetManager*
{
	return MTable::_instance.Java_GetAssetManager();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Java::AllcoObject(JNIEnv* env, jclass javaClass) -> jobject
{
	return MTable::_instance.Java_AllcoObject(env, std::forward<jclass>(javaClass));
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Java::MakeGlobalRef(JNIEnv* env, const char* className) -> jclass
{
	return MTable::_instance.Java_MakeGlobalRef(env, className);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Java::DeleteGlobalRef(JNIEnv* env, jclass& javaClass) -> void
{
	return MTable::_instance.Java_DeleteGlobalRef(env, javaClass);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Java::GetFieldID(JNIEnv* env, jclass javaClass, const char* memberName, const char* signature) -> jfieldID
{
	return MTable::_instance.Java_GetFieldID(env, std::forward<jclass>(javaClass), memberName, signature);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Java::GetLongField(JNIEnv* env, jobject obj, jfieldID field) -> jlong
{
	return MTable::_instance.Java_GetLongField(env, std::forward<jobject>(obj), std::forward<jfieldID>(field));
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Java::SetLongField(JNIEnv* env, jobject obj, jfieldID field, jlong value) -> void
{
	return MTable::_instance.Java_SetLongField(env, std::forward<jobject>(obj), std::forward<jfieldID>(field), std::forward<jlong>(value));
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Java::ConvertString(JNIEnv* env, jstring str) -> String
{
	return MTable::_instance.Java_ConvertString(env, std::forward<jstring>(str));
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Java::ConvertString(JNIEnv* env, const String& str) -> jstring
{
	return MTable::_instance.Java_ConvertString_1(env, str);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Java::IntGetStaticObjectField(JNIEnv* env, const Char* className, const Char* memberName, const Char* signature) -> jobject
{
	return MTable::_instance.Java_IntGetStaticObjectField(env, className, memberName, signature);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Java::IntCallStaticMethodObject(JNIEnv* env, const Char* className, const Char* memberName, const Char* signature, va_list list) -> jobject
{
	return MTable::_instance.Java_IntCallStaticMethodObject(env, className, memberName, signature, list);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Java::IntCallStaticMethodVoid(JNIEnv* env, const Char* className, const Char* memberName, const Char* signature, va_list list) -> void
{
	return MTable::_instance.Java_IntCallStaticMethodVoid(env, className, memberName, signature, list);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Java::IntCallStaticMethodLong(JNIEnv* env, const Char* className, const Char* memberName, const Char* signature, va_list list) -> jlong
{
	return MTable::_instance.Java_IntCallStaticMethodLong(env, className, memberName, signature, list);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Java::IntCallMethodObject(JNIEnv* env, jobject object, const Char* className, const Char* memberName, const Char* signature, va_list list) -> jobject
{
	return MTable::_instance.Java_IntCallMethodObject(env, std::forward<jobject>(object), className, memberName, signature, list);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Java::IntCallMethodLong(JNIEnv* env, jobject object, const Char* className, const Char* memberName, const Char* signature, va_list list) -> jlong
{
	return MTable::_instance.Java_IntCallMethodLong(env, std::forward<jobject>(object), className, memberName, signature, list);
}

#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_java)
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


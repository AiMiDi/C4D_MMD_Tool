
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
	static const maxon::UNRESOLVED_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = false;
	PRIVATE_MAXON_SF_POINTER(Java_GetMainThreadJavaEnv, GetMainThreadJavaEnv, MAXON_EXPAND_VA_ARGS, (JNIEnv*));
	PRIVATE_MAXON_SF_POINTER(Java_GetJavaEnv, GetJavaEnv, MAXON_EXPAND_VA_ARGS, (JNIEnv*));
	PRIVATE_MAXON_SF_POINTER(Java_GetJavaVM, GetJavaVM, MAXON_EXPAND_VA_ARGS, (JavaVM*));
	PRIVATE_MAXON_SF_POINTER(Java_GetNativeActivityObject, GetNativeActivityObject, MAXON_EXPAND_VA_ARGS, (jobject));
	PRIVATE_MAXON_SF_POINTER(Java_GetAssetManager, GetAssetManager, MAXON_EXPAND_VA_ARGS, (AAssetManager*));
	PRIVATE_MAXON_SF_POINTER(Java_AllcoObject, AllcoObject, MAXON_EXPAND_VA_ARGS, (jobject), JNIEnv* env, jclass javaClass);
	PRIVATE_MAXON_SF_POINTER(Java_MakeGlobalRef, MakeGlobalRef, MAXON_EXPAND_VA_ARGS, (jclass), JNIEnv* env, const char* className);
	PRIVATE_MAXON_SF_POINTER(Java_DeleteGlobalRef, DeleteGlobalRef, MAXON_EXPAND_VA_ARGS, (void), JNIEnv* env, jclass& javaClass);
	PRIVATE_MAXON_SF_POINTER(Java_GetFieldID, GetFieldID, MAXON_EXPAND_VA_ARGS, (jfieldID), JNIEnv* env, jclass javaClass, const char* memberName, const char* signature);
	PRIVATE_MAXON_SF_POINTER(Java_GetLongField, GetLongField, MAXON_EXPAND_VA_ARGS, (jlong), JNIEnv* env, jobject obj, jfieldID field);
	PRIVATE_MAXON_SF_POINTER(Java_SetLongField, SetLongField, MAXON_EXPAND_VA_ARGS, (void), JNIEnv* env, jobject obj, jfieldID field, jlong value);
	PRIVATE_MAXON_SF_POINTER(Java_ConvertString, ConvertString, MAXON_EXPAND_VA_ARGS, (String), JNIEnv* env, jstring str);
	PRIVATE_MAXON_SF_POINTER(Java_ConvertString_1, ConvertString, MAXON_EXPAND_VA_ARGS, (jstring), JNIEnv* env, const String& str);
	PRIVATE_MAXON_SF_POINTER(Java_IntGetStaticObjectField, IntGetStaticObjectField, MAXON_EXPAND_VA_ARGS, (jobject), JNIEnv* env, const Char* className, const Char* memberName, const Char* signature);
	PRIVATE_MAXON_SF_POINTER(Java_IntCallStaticMethodObject, IntCallStaticMethodObject, MAXON_EXPAND_VA_ARGS, (jobject), JNIEnv* env, const Char* className, const Char* memberName, const Char* signature, va_list list);
	PRIVATE_MAXON_SF_POINTER(Java_IntCallStaticMethodVoid, IntCallStaticMethodVoid, MAXON_EXPAND_VA_ARGS, (void), JNIEnv* env, const Char* className, const Char* memberName, const Char* signature, va_list list);
	PRIVATE_MAXON_SF_POINTER(Java_IntCallStaticMethodLong, IntCallStaticMethodLong, MAXON_EXPAND_VA_ARGS, (jlong), JNIEnv* env, const Char* className, const Char* memberName, const Char* signature, va_list list);
	PRIVATE_MAXON_SF_POINTER(Java_IntCallMethodObject, IntCallMethodObject, MAXON_EXPAND_VA_ARGS, (jobject), JNIEnv* env, jobject object, const Char* className, const Char* memberName, const Char* signature, va_list list);
	PRIVATE_MAXON_SF_POINTER(Java_IntCallMethodLong, IntCallMethodLong, MAXON_EXPAND_VA_ARGS, (jlong), JNIEnv* env, jobject object, const Char* className, const Char* memberName, const Char* signature, va_list list);
	template <typename IMPL> void Init()
	{
		Java_GetMainThreadJavaEnv = Java_GetMainThreadJavaEnv_GetPtr<IMPL>(true);
		Java_GetJavaEnv = Java_GetJavaEnv_GetPtr<IMPL>(true);
		Java_GetJavaVM = Java_GetJavaVM_GetPtr<IMPL>(true);
		Java_GetNativeActivityObject = Java_GetNativeActivityObject_GetPtr<IMPL>(true);
		Java_GetAssetManager = Java_GetAssetManager_GetPtr<IMPL>(true);
		Java_AllcoObject = Java_AllcoObject_GetPtr<IMPL>(true);
		Java_MakeGlobalRef = Java_MakeGlobalRef_GetPtr<IMPL>(true);
		Java_DeleteGlobalRef = Java_DeleteGlobalRef_GetPtr<IMPL>(true);
		Java_GetFieldID = Java_GetFieldID_GetPtr<IMPL>(true);
		Java_GetLongField = Java_GetLongField_GetPtr<IMPL>(true);
		Java_SetLongField = Java_SetLongField_GetPtr<IMPL>(true);
		Java_ConvertString = Java_ConvertString_GetPtr<IMPL>(true);
		Java_ConvertString_1 = Java_ConvertString_1_GetPtr<IMPL>(true);
		Java_IntGetStaticObjectField = Java_IntGetStaticObjectField_GetPtr<IMPL>(true);
		Java_IntCallStaticMethodObject = Java_IntCallStaticMethodObject_GetPtr<IMPL>(true);
		Java_IntCallStaticMethodVoid = Java_IntCallStaticMethodVoid_GetPtr<IMPL>(true);
		Java_IntCallStaticMethodLong = Java_IntCallStaticMethodLong_GetPtr<IMPL>(true);
		Java_IntCallMethodObject = Java_IntCallMethodObject_GetPtr<IMPL>(true);
		Java_IntCallMethodLong = Java_IntCallMethodLong_GetPtr<IMPL>(true);
	}
};

struct Java::Hxx2
{
	class Unresolved;
	template <typename S> class Wrapper
	{
	public:
		using Implementation = S;
		static JNIEnv* Java_GetMainThreadJavaEnv() { return S::GetMainThreadJavaEnv(); }
		static JNIEnv* Java_GetJavaEnv() { return S::GetJavaEnv(); }
		static JavaVM* Java_GetJavaVM() { return S::GetJavaVM(); }
		static jobject Java_GetNativeActivityObject() { return S::GetNativeActivityObject(); }
		static AAssetManager* Java_GetAssetManager() { return S::GetAssetManager(); }
		static jobject Java_AllcoObject(JNIEnv* env, jclass javaClass) { return S::AllcoObject(env, std::forward<jclass>(javaClass)); }
		static jclass Java_MakeGlobalRef(JNIEnv* env, const char* className) { return S::MakeGlobalRef(env, className); }
		static void Java_DeleteGlobalRef(JNIEnv* env, jclass& javaClass) { return S::DeleteGlobalRef(env, javaClass); }
		static jfieldID Java_GetFieldID(JNIEnv* env, jclass javaClass, const char* memberName, const char* signature) { return S::GetFieldID(env, std::forward<jclass>(javaClass), memberName, signature); }
		static jlong Java_GetLongField(JNIEnv* env, jobject obj, jfieldID field) { return S::GetLongField(env, std::forward<jobject>(obj), std::forward<jfieldID>(field)); }
		static void Java_SetLongField(JNIEnv* env, jobject obj, jfieldID field, jlong value) { return S::SetLongField(env, std::forward<jobject>(obj), std::forward<jfieldID>(field), std::forward<jlong>(value)); }
		static String Java_ConvertString(JNIEnv* env, jstring str) { return S::ConvertString(env, std::forward<jstring>(str)); }
		static jstring Java_ConvertString_1(JNIEnv* env, const String& str) { return S::ConvertString(env, str); }
		static jobject Java_IntGetStaticObjectField(JNIEnv* env, const Char* className, const Char* memberName, const Char* signature) { return S::IntGetStaticObjectField(env, className, memberName, signature); }
		static jobject Java_IntCallStaticMethodObject(JNIEnv* env, const Char* className, const Char* memberName, const Char* signature, va_list list) { return S::IntCallStaticMethodObject(env, className, memberName, signature, list); }
		static void Java_IntCallStaticMethodVoid(JNIEnv* env, const Char* className, const Char* memberName, const Char* signature, va_list list) { return S::IntCallStaticMethodVoid(env, className, memberName, signature, list); }
		static jlong Java_IntCallStaticMethodLong(JNIEnv* env, const Char* className, const Char* memberName, const Char* signature, va_list list) { return S::IntCallStaticMethodLong(env, className, memberName, signature, list); }
		static jobject Java_IntCallMethodObject(JNIEnv* env, jobject object, const Char* className, const Char* memberName, const Char* signature, va_list list) { return S::IntCallMethodObject(env, std::forward<jobject>(object), className, memberName, signature, list); }
		static jlong Java_IntCallMethodLong(JNIEnv* env, jobject object, const Char* className, const Char* memberName, const Char* signature, va_list list) { return S::IntCallMethodLong(env, std::forward<jobject>(object), className, memberName, signature, list); }
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


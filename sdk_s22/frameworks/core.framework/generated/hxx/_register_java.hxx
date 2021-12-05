#if defined(MAXON_TARGET_ANDROID)
#if 1
#ifdef MAXON_TARGET_ANDROID
#endif
namespace maxon
{
#ifdef MAXON_TARGET_ANDROID
	const maxon::Char* const Java::MTable::_ids = 
		"GetMainThreadJavaEnv@3b6a140d69e2\0" // JNIEnv* GetMainThreadJavaEnv()
		"GetJavaEnv@3b6a140d69e2\0" // JNIEnv* GetJavaEnv()
		"GetJavaVM@3bed449f02f1\0" // JavaVM* GetJavaVM()
		"GetNativeActivityObject@551569baca49\0" // jobject GetNativeActivityObject()
		"GetAssetManager@065246193e7dbfcc\0" // AAssetManager* GetAssetManager()
		"AllcoObject@439d5b498e529091\0" // jobject AllcoObject(JNIEnv* env, jclass javaClass)
		"MakeGlobalRef@a681cb4576744beb\0" // jclass MakeGlobalRef(JNIEnv* env, const char* className)
		"DeleteGlobalRef@8e89a96b65058004\0" // void DeleteGlobalRef(JNIEnv* env, jclass& javaClass)
		"GetFieldID@30b1175d8614b9bd\0" // jfieldID GetFieldID(JNIEnv* env, jclass javaClass, const char* memberName, const char* signature)
		"GetLongField@39f8c4a99801fe4e\0" // jlong GetLongField(JNIEnv* env, jobject obj, jfieldID field)
		"SetLongField@ae139821b325f3c2\0" // void SetLongField(JNIEnv* env, jobject obj, jfieldID field, jlong value)
		"ConvertString@ef7481d07682e504\0" // String ConvertString(JNIEnv* env, jstring str)
		"ConvertString@71048b007ec8d23d\0" // jstring ConvertString(JNIEnv* env, const String& str)
		"IntGetStaticObjectField@e133138cd252c0ba\0" // jobject IntGetStaticObjectField(JNIEnv* env, const Char* className, const Char* memberName, const Char* signature)
		"IntCallStaticMethodObject@4dadf20538fa3674\0" // jobject IntCallStaticMethodObject(JNIEnv* env, const Char* className, const Char* memberName, const Char* signature, va_list list)
		"IntCallStaticMethodVoid@b21b0e13af231de9\0" // void IntCallStaticMethodVoid(JNIEnv* env, const Char* className, const Char* memberName, const Char* signature, va_list list)
		"IntCallStaticMethodLong@a5c699d0ae7e7cd7\0" // jlong IntCallStaticMethodLong(JNIEnv* env, const Char* className, const Char* memberName, const Char* signature, va_list list)
		"IntCallMethodObject@589827c518b1e317\0" // jobject IntCallMethodObject(JNIEnv* env, jobject object, const Char* className, const Char* memberName, const Char* signature, va_list list)
		"IntCallMethodLong@77bc27ead707167a\0" // jlong IntCallMethodLong(JNIEnv* env, jobject object, const Char* className, const Char* memberName, const Char* signature, va_list list)
	"";
	MAXON_WARNING_PUSH
	MAXON_WARNING_DISABLE_DEPRECATED
	class Java::Hxx2::Unresolved : public Java
	{
	public:
		static const Unresolved* Get(const Java* o) { return (const Unresolved*) o; }
		static Unresolved* Get(Java* o) { return (Unresolved*) o; }
		static JNIEnv* GetMainThreadJavaEnv() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return Java::GetMainThreadJavaEnv(); return nullptr;}
		static JNIEnv* GetJavaEnv() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return Java::GetJavaEnv(); return nullptr;}
		static JavaVM* GetJavaVM() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return Java::GetJavaVM(); return nullptr;}
		static jobject GetNativeActivityObject() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return Java::GetNativeActivityObject(); return maxon::PrivateIncompleteNullReturnValue<jobject>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		static AAssetManager* GetAssetManager() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return Java::GetAssetManager(); return nullptr;}
		static jobject AllcoObject(JNIEnv* env, jclass javaClass) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return Java::AllcoObject(env, std::forward<jclass>(javaClass)); return maxon::PrivateIncompleteNullReturnValue<jobject>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		static jclass MakeGlobalRef(JNIEnv* env, const char* className) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return Java::MakeGlobalRef(env, className); return maxon::PrivateIncompleteNullReturnValue<jclass>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		static void DeleteGlobalRef(JNIEnv* env, jclass& javaClass) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return Java::DeleteGlobalRef(env, javaClass); return maxon::PrivateLogNullptrError();}
		static jfieldID GetFieldID(JNIEnv* env, jclass javaClass, const char* memberName, const char* signature) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return Java::GetFieldID(env, std::forward<jclass>(javaClass), memberName, signature); return maxon::PrivateIncompleteNullReturnValue<jfieldID>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		static jlong GetLongField(JNIEnv* env, jobject obj, jfieldID field) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return Java::GetLongField(env, std::forward<jobject>(obj), std::forward<jfieldID>(field)); return maxon::PrivateIncompleteNullReturnValue<jlong>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		static void SetLongField(JNIEnv* env, jobject obj, jfieldID field, jlong value) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return Java::SetLongField(env, std::forward<jobject>(obj), std::forward<jfieldID>(field), std::forward<jlong>(value)); return maxon::PrivateLogNullptrError();}
		static String ConvertString(JNIEnv* env, jstring str) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return Java::ConvertString(env, std::forward<jstring>(str)); return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		static jstring ConvertString(JNIEnv* env, const String& str) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return Java::ConvertString(env, str); return maxon::PrivateIncompleteNullReturnValue<jstring>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		static jobject IntGetStaticObjectField(JNIEnv* env, const Char* className, const Char* memberName, const Char* signature) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return Java::IntGetStaticObjectField(env, className, memberName, signature); return maxon::PrivateIncompleteNullReturnValue<jobject>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		static jobject IntCallStaticMethodObject(JNIEnv* env, const Char* className, const Char* memberName, const Char* signature, va_list list) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return Java::IntCallStaticMethodObject(env, className, memberName, signature, list); return maxon::PrivateIncompleteNullReturnValue<jobject>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		static void IntCallStaticMethodVoid(JNIEnv* env, const Char* className, const Char* memberName, const Char* signature, va_list list) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return Java::IntCallStaticMethodVoid(env, className, memberName, signature, list); return maxon::PrivateLogNullptrError();}
		static jlong IntCallStaticMethodLong(JNIEnv* env, const Char* className, const Char* memberName, const Char* signature, va_list list) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return Java::IntCallStaticMethodLong(env, className, memberName, signature, list); return maxon::PrivateIncompleteNullReturnValue<jlong>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		static jobject IntCallMethodObject(JNIEnv* env, jobject object, const Char* className, const Char* memberName, const Char* signature, va_list list) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return Java::IntCallMethodObject(env, std::forward<jobject>(object), className, memberName, signature, list); return maxon::PrivateIncompleteNullReturnValue<jobject>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		static jlong IntCallMethodLong(JNIEnv* env, jobject object, const Char* className, const Char* memberName, const Char* signature, va_list list) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return Java::IntCallMethodLong(env, std::forward<jobject>(object), className, memberName, signature, list); return maxon::PrivateIncompleteNullReturnValue<jlong>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
	};
	MAXON_WARNING_POP
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::NULL_RETURN_TYPE Java::MTable::_returnTypes[] = 
	{
		maxon::details::NullReturnType<JNIEnv*>::value,
		maxon::details::NullReturnType<JNIEnv*>::value,
		maxon::details::NullReturnType<JavaVM*>::value,
		maxon::details::NullReturnType<jobject>::value,
		maxon::details::NullReturnType<AAssetManager*>::value,
		maxon::details::NullReturnType<jobject>::value,
		maxon::details::NullReturnType<jclass>::value,
		maxon::details::NullReturnType<void>::value,
		maxon::details::NullReturnType<jfieldID>::value,
		maxon::details::NullReturnType<jlong>::value,
		maxon::details::NullReturnType<void>::value,
		maxon::details::NullReturnType<String>::value,
		maxon::details::NullReturnType<jstring>::value,
		maxon::details::NullReturnType<jobject>::value,
		maxon::details::NullReturnType<jobject>::value,
		maxon::details::NullReturnType<void>::value,
		maxon::details::NullReturnType<jlong>::value,
		maxon::details::NullReturnType<jobject>::value,
		maxon::details::NullReturnType<jlong>::value,
		maxon::NULL_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool Java::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_Java_GetMainThreadJavaEnv = &Hxx2::Wrapper<Hxx2::Unresolved>::_Java_GetMainThreadJavaEnv;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_Java_GetJavaEnv = &Hxx2::Wrapper<Hxx2::Unresolved>::_Java_GetJavaEnv;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_Java_GetJavaVM = &Hxx2::Wrapper<Hxx2::Unresolved>::_Java_GetJavaVM;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<jobject>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_Java_GetNativeActivityObject = &Hxx2::Wrapper<Hxx2::Unresolved>::_Java_GetNativeActivityObject;
		#else
		tbl->_Java_GetNativeActivityObject = &Hxx2::Wrapper<Hxx2::Unresolved>::_Java_GetNativeActivityObject;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_Java_GetAssetManager = &Hxx2::Wrapper<Hxx2::Unresolved>::_Java_GetAssetManager;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<jobject>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_Java_AllcoObject = &Hxx2::Wrapper<Hxx2::Unresolved>::_Java_AllcoObject;
		#else
		tbl->_Java_AllcoObject = &Hxx2::Wrapper<Hxx2::Unresolved>::_Java_AllcoObject;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<jclass>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_Java_MakeGlobalRef = &Hxx2::Wrapper<Hxx2::Unresolved>::_Java_MakeGlobalRef;
		#else
		tbl->_Java_MakeGlobalRef = &Hxx2::Wrapper<Hxx2::Unresolved>::_Java_MakeGlobalRef;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_Java_DeleteGlobalRef = &Hxx2::Wrapper<Hxx2::Unresolved>::_Java_DeleteGlobalRef;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<jfieldID>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_Java_GetFieldID = &Hxx2::Wrapper<Hxx2::Unresolved>::_Java_GetFieldID;
		#else
		tbl->_Java_GetFieldID = &Hxx2::Wrapper<Hxx2::Unresolved>::_Java_GetFieldID;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<jlong>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_Java_GetLongField = &Hxx2::Wrapper<Hxx2::Unresolved>::_Java_GetLongField;
		#else
		tbl->_Java_GetLongField = &Hxx2::Wrapper<Hxx2::Unresolved>::_Java_GetLongField;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_Java_SetLongField = &Hxx2::Wrapper<Hxx2::Unresolved>::_Java_SetLongField;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<String>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_Java_ConvertString = &Hxx2::Wrapper<Hxx2::Unresolved>::_Java_ConvertString;
		#else
		tbl->_Java_ConvertString = &Hxx2::Wrapper<Hxx2::Unresolved>::_Java_ConvertString;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<jstring>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_Java_ConvertString_1 = &Hxx2::Wrapper<Hxx2::Unresolved>::_Java_ConvertString_1;
		#else
		tbl->_Java_ConvertString_1 = &Hxx2::Wrapper<Hxx2::Unresolved>::_Java_ConvertString_1;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<jobject>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_Java_IntGetStaticObjectField = &Hxx2::Wrapper<Hxx2::Unresolved>::_Java_IntGetStaticObjectField;
		#else
		tbl->_Java_IntGetStaticObjectField = &Hxx2::Wrapper<Hxx2::Unresolved>::_Java_IntGetStaticObjectField;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<jobject>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_Java_IntCallStaticMethodObject = &Hxx2::Wrapper<Hxx2::Unresolved>::_Java_IntCallStaticMethodObject;
		#else
		tbl->_Java_IntCallStaticMethodObject = &Hxx2::Wrapper<Hxx2::Unresolved>::_Java_IntCallStaticMethodObject;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_Java_IntCallStaticMethodVoid = &Hxx2::Wrapper<Hxx2::Unresolved>::_Java_IntCallStaticMethodVoid;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<jlong>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_Java_IntCallStaticMethodLong = &Hxx2::Wrapper<Hxx2::Unresolved>::_Java_IntCallStaticMethodLong;
		#else
		tbl->_Java_IntCallStaticMethodLong = &Hxx2::Wrapper<Hxx2::Unresolved>::_Java_IntCallStaticMethodLong;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<jobject>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_Java_IntCallMethodObject = &Hxx2::Wrapper<Hxx2::Unresolved>::_Java_IntCallMethodObject;
		#else
		tbl->_Java_IntCallMethodObject = &Hxx2::Wrapper<Hxx2::Unresolved>::_Java_IntCallMethodObject;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<jlong>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_Java_IntCallMethodLong = &Hxx2::Wrapper<Hxx2::Unresolved>::_Java_IntCallMethodLong;
		#else
		tbl->_Java_IntCallMethodLong = &Hxx2::Wrapper<Hxx2::Unresolved>::_Java_IntCallMethodLong;
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (maxon::Char*) tbl, _returnTypes, SIZEOF(MTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(Java, "net.maxon.interface.java", nullptr);
	template <typename DUMMY> maxon::Int Java::PrivateInstantiateNullValueHelper()
	{
		return 0
		| maxon::details::InstantiateNullReturnValue<String>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<jclass>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<jfieldID>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<jlong>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<jobject>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<jstring>(OVERLOAD_MAX_RANK)
		;
	}
#endif
}
#endif
static maxon::details::ForceEvaluation s_forceEval_java(0
	| maxon::Java::PrivateInstantiateNullValueHelper<maxon::Int>()
);
#endif

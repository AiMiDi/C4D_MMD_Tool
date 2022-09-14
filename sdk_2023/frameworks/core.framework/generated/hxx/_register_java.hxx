#if defined(MAXON_TARGET_ANDROID)
#if 1
#ifdef MAXON_TARGET_ANDROID
#endif
namespace maxon
{
#ifdef MAXON_TARGET_ANDROID
	const maxon::Char* const Java::MTable::_ids = 
		"GetMainThreadJavaEnv@6975e3dbd8bbacf5\0" // JNIEnv* GetMainThreadJavaEnv()
		"GetJavaEnv@6975e3dbd8bbacf5\0" // JNIEnv* GetJavaEnv()
		"GetJavaVM@fc925e19850d5ba0\0" // JavaVM* GetJavaVM()
		"GetNativeActivityObject@b9b0facd340db20\0" // jobject GetNativeActivityObject()
		"GetAssetManager@95bf8233390bda19\0" // AAssetManager* GetAssetManager()
		"AllcoObject@e4e8f5cda7c451a\0" // jobject AllcoObject(JNIEnv* env, jclass javaClass)
		"MakeGlobalRef@e5844441d8e02502\0" // jclass MakeGlobalRef(JNIEnv* env, const char* className)
		"DeleteGlobalRef@c8fd5e28f4a7ea1d\0" // void DeleteGlobalRef(JNIEnv* env, jclass& javaClass)
		"GetFieldID@2ed321f436cf8c16\0" // jfieldID GetFieldID(JNIEnv* env, jclass javaClass, const char* memberName, const char* signature)
		"GetLongField@dce16d2bbd4951\0" // jlong GetLongField(JNIEnv* env, jobject obj, jfieldID field)
		"SetLongField@b352930c2f6f3f39\0" // void SetLongField(JNIEnv* env, jobject obj, jfieldID field, jlong value)
		"ConvertString@2df024354732c881\0" // String ConvertString(JNIEnv* env, jstring str)
		"ConvertString@eb0dd67c8035ed96\0" // jstring ConvertString(JNIEnv* env, const String& str)
		"IntGetStaticObjectField@8555aba2de5fc99\0" // jobject IntGetStaticObjectField(JNIEnv* env, const Char* className, const Char* memberName, const Char* signature)
		"IntCallStaticMethodObject@ef50cb1d930857ab\0" // jobject IntCallStaticMethodObject(JNIEnv* env, const Char* className, const Char* memberName, const Char* signature, va_list list)
		"IntCallStaticMethodVoid@cbb2bd83946e0cf0\0" // void IntCallStaticMethodVoid(JNIEnv* env, const Char* className, const Char* memberName, const Char* signature, va_list list)
		"IntCallStaticMethodLong@32cdaf9988dbdfcc\0" // jlong IntCallStaticMethodLong(JNIEnv* env, const Char* className, const Char* memberName, const Char* signature, va_list list)
		"IntCallMethodObject@d12d8fa5aee56fe8\0" // jobject IntCallMethodObject(JNIEnv* env, jobject object, const Char* className, const Char* memberName, const Char* signature, va_list list)
		"IntCallMethodLong@51ca9ac1e9c6e623\0" // jlong IntCallMethodLong(JNIEnv* env, jobject object, const Char* className, const Char* memberName, const Char* signature, va_list list)
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
		tbl->Java_GetMainThreadJavaEnv = PRIVATE_MAXON_MF_CAST(decltype(Java_GetMainThreadJavaEnv), &Hxx2::Wrapper<Hxx2::Unresolved>::Java_GetMainThreadJavaEnv);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->Java_GetJavaEnv = PRIVATE_MAXON_MF_CAST(decltype(Java_GetJavaEnv), &Hxx2::Wrapper<Hxx2::Unresolved>::Java_GetJavaEnv);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->Java_GetJavaVM = PRIVATE_MAXON_MF_CAST(decltype(Java_GetJavaVM), &Hxx2::Wrapper<Hxx2::Unresolved>::Java_GetJavaVM);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<jobject>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->Java_GetNativeActivityObject = PRIVATE_MAXON_MF_CAST(decltype(Java_GetNativeActivityObject), &Hxx2::Wrapper<Hxx2::Unresolved>::Java_GetNativeActivityObject);
		#else
		tbl->Java_GetNativeActivityObject = PRIVATE_MAXON_MF_CAST(decltype(Java_GetNativeActivityObject), &Hxx2::Wrapper<Hxx2::Unresolved>::Java_GetNativeActivityObject);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->Java_GetAssetManager = PRIVATE_MAXON_MF_CAST(decltype(Java_GetAssetManager), &Hxx2::Wrapper<Hxx2::Unresolved>::Java_GetAssetManager);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<jobject>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->Java_AllcoObject = PRIVATE_MAXON_MF_CAST(decltype(Java_AllcoObject), &Hxx2::Wrapper<Hxx2::Unresolved>::Java_AllcoObject);
		#else
		tbl->Java_AllcoObject = PRIVATE_MAXON_MF_CAST(decltype(Java_AllcoObject), &Hxx2::Wrapper<Hxx2::Unresolved>::Java_AllcoObject);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<jclass>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->Java_MakeGlobalRef = PRIVATE_MAXON_MF_CAST(decltype(Java_MakeGlobalRef), &Hxx2::Wrapper<Hxx2::Unresolved>::Java_MakeGlobalRef);
		#else
		tbl->Java_MakeGlobalRef = PRIVATE_MAXON_MF_CAST(decltype(Java_MakeGlobalRef), &Hxx2::Wrapper<Hxx2::Unresolved>::Java_MakeGlobalRef);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->Java_DeleteGlobalRef = PRIVATE_MAXON_MF_CAST(decltype(Java_DeleteGlobalRef), &Hxx2::Wrapper<Hxx2::Unresolved>::Java_DeleteGlobalRef);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<jfieldID>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->Java_GetFieldID = PRIVATE_MAXON_MF_CAST(decltype(Java_GetFieldID), &Hxx2::Wrapper<Hxx2::Unresolved>::Java_GetFieldID);
		#else
		tbl->Java_GetFieldID = PRIVATE_MAXON_MF_CAST(decltype(Java_GetFieldID), &Hxx2::Wrapper<Hxx2::Unresolved>::Java_GetFieldID);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<jlong>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->Java_GetLongField = PRIVATE_MAXON_MF_CAST(decltype(Java_GetLongField), &Hxx2::Wrapper<Hxx2::Unresolved>::Java_GetLongField);
		#else
		tbl->Java_GetLongField = PRIVATE_MAXON_MF_CAST(decltype(Java_GetLongField), &Hxx2::Wrapper<Hxx2::Unresolved>::Java_GetLongField);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->Java_SetLongField = PRIVATE_MAXON_MF_CAST(decltype(Java_SetLongField), &Hxx2::Wrapper<Hxx2::Unresolved>::Java_SetLongField);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<String>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->Java_ConvertString = PRIVATE_MAXON_MF_CAST(decltype(Java_ConvertString), &Hxx2::Wrapper<Hxx2::Unresolved>::Java_ConvertString);
		#else
		tbl->Java_ConvertString = PRIVATE_MAXON_MF_CAST(decltype(Java_ConvertString), &Hxx2::Wrapper<Hxx2::Unresolved>::Java_ConvertString);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<jstring>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->Java_ConvertString_1 = PRIVATE_MAXON_MF_CAST(decltype(Java_ConvertString_1), &Hxx2::Wrapper<Hxx2::Unresolved>::Java_ConvertString_1);
		#else
		tbl->Java_ConvertString_1 = PRIVATE_MAXON_MF_CAST(decltype(Java_ConvertString_1), &Hxx2::Wrapper<Hxx2::Unresolved>::Java_ConvertString_1);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<jobject>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->Java_IntGetStaticObjectField = PRIVATE_MAXON_MF_CAST(decltype(Java_IntGetStaticObjectField), &Hxx2::Wrapper<Hxx2::Unresolved>::Java_IntGetStaticObjectField);
		#else
		tbl->Java_IntGetStaticObjectField = PRIVATE_MAXON_MF_CAST(decltype(Java_IntGetStaticObjectField), &Hxx2::Wrapper<Hxx2::Unresolved>::Java_IntGetStaticObjectField);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<jobject>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->Java_IntCallStaticMethodObject = PRIVATE_MAXON_MF_CAST(decltype(Java_IntCallStaticMethodObject), &Hxx2::Wrapper<Hxx2::Unresolved>::Java_IntCallStaticMethodObject);
		#else
		tbl->Java_IntCallStaticMethodObject = PRIVATE_MAXON_MF_CAST(decltype(Java_IntCallStaticMethodObject), &Hxx2::Wrapper<Hxx2::Unresolved>::Java_IntCallStaticMethodObject);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->Java_IntCallStaticMethodVoid = PRIVATE_MAXON_MF_CAST(decltype(Java_IntCallStaticMethodVoid), &Hxx2::Wrapper<Hxx2::Unresolved>::Java_IntCallStaticMethodVoid);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<jlong>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->Java_IntCallStaticMethodLong = PRIVATE_MAXON_MF_CAST(decltype(Java_IntCallStaticMethodLong), &Hxx2::Wrapper<Hxx2::Unresolved>::Java_IntCallStaticMethodLong);
		#else
		tbl->Java_IntCallStaticMethodLong = PRIVATE_MAXON_MF_CAST(decltype(Java_IntCallStaticMethodLong), &Hxx2::Wrapper<Hxx2::Unresolved>::Java_IntCallStaticMethodLong);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<jobject>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->Java_IntCallMethodObject = PRIVATE_MAXON_MF_CAST(decltype(Java_IntCallMethodObject), &Hxx2::Wrapper<Hxx2::Unresolved>::Java_IntCallMethodObject);
		#else
		tbl->Java_IntCallMethodObject = PRIVATE_MAXON_MF_CAST(decltype(Java_IntCallMethodObject), &Hxx2::Wrapper<Hxx2::Unresolved>::Java_IntCallMethodObject);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<jlong>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->Java_IntCallMethodLong = PRIVATE_MAXON_MF_CAST(decltype(Java_IntCallMethodLong), &Hxx2::Wrapper<Hxx2::Unresolved>::Java_IntCallMethodLong);
		#else
		tbl->Java_IntCallMethodLong = PRIVATE_MAXON_MF_CAST(decltype(Java_IntCallMethodLong), &Hxx2::Wrapper<Hxx2::Unresolved>::Java_IntCallMethodLong);
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

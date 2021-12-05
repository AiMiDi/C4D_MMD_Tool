#ifndef JAVA_HELPER_H__
#define JAVA_HELPER_H__

#include "maxon/apibase.h"
#include "maxon/sortedarray.h"
#include "maxon/string.h"
#include "maxon/cstdliballocator.h"
#include "maxon/hashmap.h"
#include "maxon/spinlock.h"

#ifdef MAXON_TARGET_ANDROID
	#include <ctype.h>
	#include <jni.h>
	#include <android/log.h>
	#include <android/asset_manager.h>
	#include <android/asset_manager_jni.h>
#else
	using JNIEnv = void;
	using jvalue = void*;
	using jmethodID = void*;
	using jclass = void*;
	using jfieldID = void*;
	using jobject = void*;
	using jstring = void*;
	using AAssetManager = void;
#endif

namespace maxon
{

#ifdef MAXON_TARGET_ANDROID

Bool InitJava(JavaVM* vm, jobject nativeActivity, AAssetManager* assetManager);
JNIEnv* GetMainThreadJavaEnv();
JNIEnv* GetJavaEnv();
JavaVM* GetJavaVM();
jobject GetNativeActivityObject();
AAssetManager* GetAssetManager();

#endif

struct JavaCall
{
	const Char*		_memberName;
	const Char*		_sig;
	Bool					_static;

	JavaCall() : _memberName(nullptr), _sig(nullptr), _static(false)
	{
	}

	JavaCall(const Char* memberName, const Char* sig, Bool staticCall) : _memberName(memberName), _sig(sig), _static(staticCall)
	{
	}
};

struct JavaMember
{
	JavaCall			_call;
	union
	{
		jmethodID			_memberPointer;
		jfieldID			_fieldPointer;
	};

	JavaMember() : _memberPointer(nullptr)
	{

	}

	static inline Bool IsEqual(const JavaMember& a, const JavaMember& b)
	{
		COMPARERESULT r = DefaultCompare::Compare(a._call._memberName, b._call._memberName);
		if (r == COMPARERESULT::EQUAL)
			return true;
		r = DefaultCompare::Compare(a._call._sig, b._call._sig);
		return r == COMPARERESULT::EQUAL;
	}

	static inline Bool IsEqual(const JavaCall& a, const JavaMember& b)
	{
		COMPARERESULT r = DefaultCompare::Compare(a._memberName, b._call._memberName);
		if (r == COMPARERESULT::EQUAL)
			return true;
		r = DefaultCompare::Compare(a._sig, b._call._sig);
		return r == COMPARERESULT::EQUAL;
	}

	static inline Bool LessThan(const JavaMember& a, const JavaMember& b)
	{
		COMPARERESULT r = DefaultCompare::Compare(a._call._memberName, b._call._memberName);
		if (r != COMPARERESULT::EQUAL)
			return r == COMPARERESULT::LESS;
		r = DefaultCompare::Compare(a._call._sig, b._call._sig);
		return r == COMPARERESULT::LESS;
	}

	static inline Bool LessThan(const JavaCall& a, const JavaMember& b)
	{
		COMPARERESULT r = DefaultCompare::Compare(a._memberName, b._call._memberName);
		if (r != COMPARERESULT::EQUAL)
			return r == COMPARERESULT::LESS;
		r = DefaultCompare::Compare(a._sig, b._call._sig);
		return r == COMPARERESULT::LESS;
	}
};

struct JavaClass
{
	using JavaMemberArray = SortedArray<JavaMember, BaseArray<JavaMember, 16, BASEARRAYFLAGS::NONE, CStdLibAllocator>>;

	const Char*					_className;
	JavaMemberArray*		_members;
	jclass							_javaClass;

	JavaClass() : _className(nullptr), _members(nullptr), _javaClass(nullptr)
	{

	}

	static inline Bool IsEqual(const JavaClass& a, const JavaClass& b)
	{
		return DefaultCompare::Compare(a._className, b._className) == COMPARERESULT::EQUAL;
	}

	static inline Bool IsEqual(const Char* cl, const JavaClass& b)
	{
		return DefaultCompare::Compare(cl, b._className) == COMPARERESULT::EQUAL;
	}

	static inline Bool LessThan(const JavaClass& a, const JavaClass& b)
	{
		return DefaultCompare::Compare(a._className, b._className) == COMPARERESULT::LESS;
	}

	static inline Bool LessThan(const Char* cl, const JavaClass& b)
	{
		return DefaultCompare::Compare(cl, b._className) == COMPARERESULT::LESS;
	}

	static void InitInsertData(JavaClass& initme, const Char* className)
	{
		initme._className = className;
		initme._javaClass = nullptr;
	}

	template<typename T> T CallStaticMember(JNIEnv* env, const Char* memberName, const Char* sig, va_list list)
	{
		Bool newElement;
		JavaCall call(memberName, sig, true);
		if (!_members)
		{
			iferr (_members = NewObj(JavaMemberArray))
			{
#ifdef MAXON_TARGET_ANDROID
				__android_log_print(ANDROID_LOG_ERROR, "Maxon Andoid App", "Error allocating memory for CallStaticMember");
#endif
				return T();
			}
		}
		iferr (JavaMember& member = _members->InsertValue(call, newElement))
		{
#ifdef MAXON_TARGET_ANDROID
			__android_log_print(ANDROID_LOG_ERROR, "Maxon Andoid App", "Error allocating memory for CallStaticMember");
#endif
			return T();
		}
		if (newElement)
		{
			member._call = call;
			member._memberPointer = env->GetStaticMethodID(_javaClass, memberName, sig);
		}

		if (!member._memberPointer)
		{
			CriticalOutput("Member not found @ -> @ @", _className, member._call._memberName, member._call._sig);
			return T();
		}
		T res = (T)env->CallStaticObjectMethodV(_javaClass, member._memberPointer, list);
#ifdef MAXON_TARGET_ANDROID
		// __android_log_print(ANDROID_LOG_DEBUG, "Maxon Andoid App", "CallStaticMemberA %s %s %p -> %p", memberName, sig, list, res);
#endif
		return res;
	}

	void CallStaticMemberVoid(JNIEnv* env, const Char* memberName, const Char* sig, va_list list)
	{
		Bool newElement;
		JavaCall call(memberName, sig, true);
		if (!_members)
		{
			iferr (_members = NewObj(JavaMemberArray))
			{
#ifdef MAXON_TARGET_ANDROID
				__android_log_print(ANDROID_LOG_DEBUG, "Maxon Andoid App", "Error allocating memory for CallStaticMember");
#endif
				return;
			}
		}
		iferr (JavaMember& member = _members->InsertValue(call, newElement))
		{
			return;
		}
		if (newElement)
		{
			member._call = call;
			member._memberPointer = env->GetStaticMethodID(_javaClass, memberName, sig);
		}

		if (!member._memberPointer)
		{
			CriticalOutput("Member not found @ -> @ @", _className, member._call._memberName, member._call._sig);
			return;
		}
		env->CallStaticVoidMethod(_javaClass, member._memberPointer, list);
#ifdef MAXON_TARGET_ANDROID
		// __android_log_print(ANDROID_LOG_DEBUG, "Maxon Andoid App", "CallStaticMemberA %s %s %p -> %p", memberName, sig, list, res);
#endif
	}

	template<typename T> T CallMember(JNIEnv* env, jobject object, const Char* memberName, const Char* sig, va_list list)
	{
		if (!object)
		{
#ifdef MAXON_TARGET_ANDROID
			__android_log_print(ANDROID_LOG_DEBUG, "Maxon Andoid App", "CallMember %s: object is nullptr", memberName);
#endif
			return T();
		}
		Bool newElement;
		JavaCall call(memberName, sig, false);
		if (!_members)
		{
			iferr (_members = NewObj(JavaMemberArray))
			{
#ifdef MAXON_TARGET_ANDROID
				__android_log_print(ANDROID_LOG_ERROR, "Maxon Andoid App", "Error allocating memory for CallMember");
#endif
				return T();
			}
		}
		iferr (JavaMember& member = _members->InsertValue(call, newElement))
		{
#ifdef MAXON_TARGET_ANDROID
			__android_log_print(ANDROID_LOG_ERROR, "Maxon Andoid App", "Error allocating memory for CallMember");
#endif
			return T();
		}
		if (newElement)
		{
			member._call = call;
			member._memberPointer = env->GetMethodID(_javaClass, memberName, sig);
		}
		if (!member._memberPointer)
		{
			CriticalOutput("Member not found @ -> @ @", _className, member._call._memberName, member._call._sig);
			return T();
		}
		T res = (T)env->CallObjectMethodV(object, member._memberPointer, list);
#ifdef MAXON_TARGET_ANDROID
		// __android_log_print(ANDROID_LOG_DEBUG, "Maxon Andoid App", "CallMemberA %s %s %p -> %p", memberName, sig, list, res);
#endif
		return res;
	}

	template<typename T> T GetStaticObjectField(JNIEnv* env, const Char* memberName, const Char* sig)
	{
		Bool newElement;
		JavaCall call(memberName, sig, true);
		if (!_members)
		{
			iferr (_members = NewObj(JavaMemberArray))
			{
				__android_log_print(ANDROID_LOG_ERROR, "Maxon Andoid App", "Error allocating memory for CallStaticMember");
				return T();
			}
		}
		iferr (JavaMember& member = _members->InsertValue(call, newElement))
		{
#ifdef MAXON_TARGET_ANDROID
			__android_log_print(ANDROID_LOG_ERROR, "Maxon Andoid App", "Error allocating memory for CallMember");
#endif
			return T();
		}
		if (newElement)
		{
			member._call = call;
			member._fieldPointer = env->GetStaticFieldID(_javaClass, memberName, sig);
		}

		if (!member._fieldPointer)
		{
			CriticalOutput("Field not found @ -> @ @", _className, member._call._memberName, member._call._sig);
			return T();
		}
		T res = (T)env->GetStaticObjectField(_javaClass, member._fieldPointer);
#ifdef MAXON_TARGET_ANDROID
		// __android_log_print(ANDROID_LOG_DEBUG, "Maxon Andoid App", "CallStaticMemberA %s %s -> %p", memberName, sig, res);
#endif
		return res;
	}
};


class JavaClassArray : private SortedArray<JavaClass, BaseArray<JavaClass, 16, BASEARRAYFLAGS::NONE, CStdLibAllocator>>
{
public:
	void SetEnv(JNIEnv* env)
	{
		_env = env;
	}

	JavaClass* InsertClass(const Char *className)
	{
		iferr (JavaClass* cl = &InsertValue(className))
			return nullptr;

#ifdef MAXON_TARGET_ANDROID
		if (!cl->_javaClass)
		{
			cl->_javaClass = _env->FindClass(className);
#ifdef MAXON_TARGET_DEBUG
			if (_env->ExceptionCheck())
			{
				_env->ExceptionDescribe();
				_env->ExceptionClear();
			}
#endif
		}
#endif
		return cl;
	}

private:
	JNIEnv* _env;
};

class JavaClassHash : public HashMap<JNIEnv*, JavaClassArray>
{
public:
	JavaClassArray* GetClassArray(JNIEnv* env)
	{
		Bool created = false;

		_lock.Lock();
		finally
		{
			_lock.Unlock();
		};

		iferr (JavaClassArray* classArray = &InsertKey(env, created))
			return nullptr;

		if (created)
			classArray->SetEnv(env);

		return classArray;
	}

private:
	Spinlock _lock;
};

class JavaHelper
{
public:

	template<typename T> T CallStaticMember(JNIEnv* env, const Char *className, const Char* memberName, const Char* sig, ...)
	{
		va_list list;
		va_start(list, sig);

		JavaClassArray* classArray = _classes.GetClassArray(env);
		if (!classArray)
		{
			CriticalOutput("Error allocating memory for @", className);
			return T();
		}
		JavaClass* cl = classArray->InsertClass(className);
		if (!cl)
		{
			CriticalOutput("Error allocating memory for @", className);
			return T();
		}
		if (!cl->_javaClass)
		{
			CriticalOutput("Java Class not found @", className);
			return T();
		}
		T res = cl->CallStaticMember<T>(env, memberName, sig, list);
#ifdef MAXON_TARGET_ANDROID
//		__android_log_print(ANDROID_LOG_DEBUG, "Maxon Andoid App", "CallStaticMember %s %s %p",className,memberName,res);
#endif
		va_end(list);
		return res;
	}

	void CallStaticMemberVoid(JNIEnv* env, const Char *className, const Char* memberName, const Char* sig, ...)
	{
		va_list list;
		va_start(list, sig);

		JavaClassArray* classArray = _classes.GetClassArray(env);
		if (!classArray)
		{
			CriticalOutput("Error allocating memory for @", className);
			return;
		}
		JavaClass* cl = classArray->InsertClass(className);
		if (!cl)
		{
			CriticalOutput("Error allocating memory for @", className);
			return;
		}
		if (!cl->_javaClass)
		{
			CriticalOutput("Java Class not found @", className);
			return;
		}
		cl->CallStaticMemberVoid(env, memberName, sig, list);
#ifdef MAXON_TARGET_ANDROID
//		__android_log_print(ANDROID_LOG_DEBUG, "Maxon Andoid App", "CallStaticMember %s %s %p",className,memberName,res);
#endif
		va_end(list);
	}

	template<typename T> T CallMember(JNIEnv* env, jobject object, const Char *className, const Char* memberName, const Char* sig, ...)
	{
		va_list list;
		va_start(list, sig);

		JavaClassArray* classArray = _classes.GetClassArray(env);
		if (!classArray)
		{
			CriticalOutput("Error allocating memory for @", className);
			return T();
		}
		JavaClass* cl = classArray->InsertClass(className);
		if (!cl)
		{
			CriticalOutput("Error allocating memory for @", className);
			return T();
		}
		if (!cl->_javaClass)
		{
			CriticalOutput("Java Class not found @", className);
			return T();
		}
		T res = cl->CallMember<T>(env, object, memberName, sig, list);
#ifdef MAXON_TARGET_ANDROID
		// __android_log_print(ANDROID_LOG_DEBUG, "Maxon Andoid App", "CallMember %s %s %p", className, memberName, res);
#endif
		va_end(list);
		return res;
	}

	template<typename T> T GetStaticObjectField(JNIEnv* env, const Char *className, const Char* memberName, const Char* sig)
	{
		JavaClassArray* classArray = _classes.GetClassArray(env);
		if (!classArray)
		{
			CriticalOutput("Error allocating memory for @", className);
			return T();
		}
		JavaClass* cl = classArray->InsertClass(className);
		if (!cl)
		{
			CriticalOutput("Error allocating memory for @", className);
			return T();
		}
		if (!cl->_javaClass)
		{
			CriticalOutput("Java Class not found @", className);
			return T();
		}
		T res = cl->GetStaticObjectField<T>(env, memberName, sig);
#ifdef MAXON_TARGET_ANDROID
		// __android_log_print(ANDROID_LOG_DEBUG, "Maxon Andoid App", "CallMember %s %s %p", className, memberName, res);
#endif
		return res;
	}

private:
	JavaClassHash _classes;
};

extern JavaHelper g_javaHelper;

inline String GetPrintableString(JNIEnv* env, const jstring& val)
{
	if (!val)
		return String::NullValue();
#ifdef MAXON_TARGET_ANDROID
	int stringLength = env->GetStringLength(val);
	jboolean iscopy = false;

	const jchar* stringUni = env->GetStringChars(val, &iscopy);
	if (!stringUni)
		return String::NullValue();

	// jchar is 16 bit unsigned integer, see http://docs.oracle.com/javase/1.5.0/docs/guide/jni/spec/types.html
	String s((Utf16Char*)stringUni, stringLength);
	if (iscopy)
		env->ReleaseStringChars(val, stringUni);
	return s;
#else
	return String::NullValue();
#endif
}

static inline String ToString(JNIEnv* env, const jstring& str)
{
	return GetPrintableString(env, str);
}

} // namespace maxon

#endif // JAVA_HELPER_H__

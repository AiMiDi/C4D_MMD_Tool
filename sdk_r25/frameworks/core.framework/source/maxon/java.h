#ifndef JAVA_H__
#define JAVA_H__

#include "apibase.h"
#include "module.h"
#include "interfacebase.h"
#include "string.h"

#ifdef MAXON_TARGET_ANDROID
	#include <ctype.h>
	#include <jni.h>
	#include <android/log.h>
	#include <android/asset_manager.h>
	#include <android/asset_manager_jni.h>
#endif

namespace maxon
{

MAXON_PREPROCESSOR_CONDITION(defined(MAXON_TARGET_ANDROID));

#ifdef MAXON_TARGET_ANDROID

class JavaClass;

class Java
{
	MAXON_INTERFACE_NONVIRTUAL(Java, MAXON_REFERENCE_NONE, "net.maxon.interface.java");

public:
	//----------------------------------------------------------------------------------------
	/// Gets the JNIEnv object for the main thread.
	/// @return												The JNIEnv object for the main thread.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD JNIEnv* GetMainThreadJavaEnv();

	//----------------------------------------------------------------------------------------
	/// Gets the JNIEnv object for the current thread.
	/// @return												The JNIEnv object for the current thread.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD JNIEnv* GetJavaEnv();

	//----------------------------------------------------------------------------------------
	/// Gets the Java VMobject.
	/// @return												The Java VMobject.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD JavaVM* GetJavaVM();

	//----------------------------------------------------------------------------------------
	/// Gets the native activity object.
	/// @return												The native activity object.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD jobject GetNativeActivityObject();

	//----------------------------------------------------------------------------------------
	/// Gets the asset managegr.
	/// @return												The asset managegr.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD AAssetManager* GetAssetManager();

	//----------------------------------------------------------------------------------------
	/// Allocates a new Java object.
	/// @param[in] env								JNIEnv for the current thread.
	/// @param[in] javaClass					Class of the new object.
	/// @return												New object.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD jobject AllcoObject(JNIEnv* env, jclass javaClass);

	//----------------------------------------------------------------------------------------
	/// Creates a jclass object for a given class name.
	/// @param[in] env								JNIEnv for the current thread.
	/// @param[in] className					The class name.
	/// @return												Java class for the given class name.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD jclass MakeGlobalRef(JNIEnv* env, const char* className);

	//----------------------------------------------------------------------------------------
	/// Deletes a java class object.
	/// @param[in] env								JNIEnv for the current thread.
	/// @param[in,out] javaClass			Class to delete. The object will get nullptr assigned.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD void DeleteGlobalRef(JNIEnv* env, jclass& javaClass);

	//----------------------------------------------------------------------------------------
	/// Gets the field ID for a certain field of a class.
	/// @param[in] env								JNIEnv for the current thread.
	/// @param[in] javaClass					The class.
	/// @param[in] name								Member name.
	/// @param[in] signature					Signature of the member.
	/// @return												The field ID.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD jfieldID GetFieldID(JNIEnv* env, jclass javaClass, const char* memberName, const char* signature);

	//----------------------------------------------------------------------------------------
	/// Gets a member from the class.
	/// @param[in] env								JNIEnv for the current thread.
	/// @param[in] obj								The Java object.
	/// @param[in] field							Field which value should be retrieved.
	/// @return												The value of the field.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD jlong GetLongField(JNIEnv* env, jobject obj, jfieldID field);

	//----------------------------------------------------------------------------------------
	/// Gets a member from the class.
	/// @param[in] env								JNIEnv for the current thread.
	/// @param[in] obj								The Java object.
	/// @param[in] field							Field which value should be retrieved.
	/// @param[in] value							New value for the field.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD void SetLongField(JNIEnv* env, jobject obj, jfieldID field, jlong value);

	//----------------------------------------------------------------------------------------
	/// Calls a method of a Java object.
	/// @param[in] env								JNIEnv for the current thread.
	/// @param[in] className					Class name.
	/// @param[in] memberName					Member name.
	/// @param[in] signature					Function signature.
	/// @return												Return value of the call. This is a jobject or a derived function of it.
	//----------------------------------------------------------------------------------------
	template<typename T> static T CallStaticMethodObject(JNIEnv* env, const Char *className, const Char* memberName, const Char* signature, ...)
	{
		va_list list;
		va_start(list, signature);

		jobject ret = IntCallStaticMethodObject(env, className, memberName, signature, list);

		va_end(list);

		return static_cast<T>(ret);
	}

	//----------------------------------------------------------------------------------------
	/// Calls a method of a Java object.
	/// @param[in] env								JNIEnv for the current thread.
	/// @param[in] className					Class name.
	/// @param[in] memberName					Member name.
	/// @param[in] signature					Function signature.
	//----------------------------------------------------------------------------------------
	static void CallStaticMethodVoid(JNIEnv* env, const Char *className, const Char* memberName, const Char* signature, ...)
	{
		va_list list;
		va_start(list, signature);

		IntCallStaticMethodVoid(env, className, memberName, signature, list);

		va_end(list);
	}

	//----------------------------------------------------------------------------------------
	/// Calls a method of a Java object.
	/// @param[in] env								JNIEnv for the current thread.
	/// @param[in] className					Class name.
	/// @param[in] memberName					Member name.
	/// @param[in] signature					Function signature.
	/// @return												Return value of the call.
	//----------------------------------------------------------------------------------------
	static jlong CallStaticMethodLong(JNIEnv* env, const Char *className, const Char* memberName, const Char* signature, ...)
	{
		va_list list;
		va_start(list, signature);

		jlong ret = IntCallStaticMethodLong(env, className, memberName, signature, list);

		va_end(list);

		return ret;
	}

	//----------------------------------------------------------------------------------------
	/// Calls a method of a Java object.
	/// @param[in] env								JNIEnv for the current thread.
	/// @param[in] obj								The Java object.
	/// @param[in] className					Class name.
	/// @param[in] memberName					Member name.
	/// @param[in] signature					Function signature.
	/// @return												Return value of the call. This is a jobject or a derived function of it.
	//----------------------------------------------------------------------------------------
	template<typename T> static T CallMethodObject(JNIEnv* env, jobject object, const Char *className, const Char* memberName, const Char* signature, ...)
	{
		va_list list;
		va_start(list, signature);

		jobject ret = IntCallMethodObject(env, object, className, memberName, signature, list);

		va_end(list);

		return static_cast<T>(ret);
	}

	//----------------------------------------------------------------------------------------
	/// Calls a method of a Java object.
	/// @param[in] env								JNIEnv for the current thread.
	/// @param[in] obj								The Java object.
	/// @param[in] className					Class name.
	/// @param[in] memberName					Member name.
	/// @param[in] signature					Function signature.
	/// @return												Return value of the call. This is a jobject or a derived function of it.
	//----------------------------------------------------------------------------------------
	static jlong CallMethodLong(JNIEnv* env, jobject object, const Char *className, const Char* memberName, const Char* signature, ...)
	{
		va_list list;
		va_start(list, signature);

		jlong ret = IntCallMethodLong(env, object, className, memberName, signature, list);

		va_end(list);

		return ret;
	}

	//----------------------------------------------------------------------------------------
	/// Gets the field of a static object.
	/// @param[in] env								JNIEnv for the current thread.
	/// @param[in] className					Class name.
	/// @param[in] name								Member name.
	/// @param[in] signature					Signature of the member.
	/// @return												The field value.
	//----------------------------------------------------------------------------------------
	template<typename T> static T GetStaticObjectField(JNIEnv* env, const Char *className, const Char* memberName, const Char* signature)
	{
		return static_cast<T>(IntGetStaticObjectField(env, className, memberName, signature));
	}

	//----------------------------------------------------------------------------------------
	/// Converts a Java string to a String.
	/// @param[in] env								JNIEnv for the current thread.
	/// @param[in] str								Java string to convert.
	/// @return												The converted string.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD String ConvertString(JNIEnv* env, jstring str);

	//----------------------------------------------------------------------------------------
	/// Converts a string to a Java string.
	/// @param[in] env								JNIEnv for the current thread.
	/// @param[in] str								String to convert.
	/// @return												The converted Java string.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD jstring ConvertString(JNIEnv* env, const String& str);

protected:
	static MAXON_METHOD jobject IntGetStaticObjectField(JNIEnv* env, const Char *className, const Char* memberName, const Char* signature);

	static MAXON_METHOD jobject IntCallStaticMethodObject(JNIEnv* env, const Char *className, const Char* memberName, const Char* signature, va_list list);
	static MAXON_METHOD void IntCallStaticMethodVoid(JNIEnv* env, const Char *className, const Char* memberName, const Char* signature, va_list list);
	static MAXON_METHOD jlong IntCallStaticMethodLong(JNIEnv* env, const Char *className, const Char* memberName, const Char* signature, va_list list);

	static MAXON_METHOD jobject IntCallMethodObject(JNIEnv* env, jobject object, const Char* className, const Char* memberName, const Char* signature, va_list list);
	static MAXON_METHOD jlong IntCallMethodLong(JNIEnv* env, jobject object, const Char* className, const Char* memberName, const Char* signature, va_list list);
};

#endif

#include "java1.hxx"
#include "java2.hxx"

} // namespace maxon

#endif // JAVA_H__

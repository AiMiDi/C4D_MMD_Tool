#ifndef CPYTHON_REF_H__
#define CPYTHON_REF_H__

#include "maxon/objectbase.h"
#include "maxon/weakref.h"
#include "maxon/cpython_raw.h"

namespace maxon
{

namespace py
{

// forward declare references
class CPyRef;
class CPyConstRef;
class CPyTempRef;
class CPyTypeRef;
class CPyTypeConstRef;
class CPyFrameRef;
class CPyTracebackRef;
class CPyCodeRef;
class MPyClassRef;
class MPyMemberRef;
class MPyFunctionRef;
class MPyDataTypeRef;
class MPyCallerContextRef;
class MPyDataRef;

enum class REFTYPE
{
	DECREF = 1,										///< The NativePyObject is new and just needs to be decrefed after the CPyRef instance is destructed.
	BORROWED = 2,									///< The NativePyObject is borrowed and the CPyRef needs to incref it internally, and decref it after the CPyRef instance is destructed.
	PRIVATE_SHORTTERM_BORROWED = 3,					///< No refcount handling is performed on the passed NativePyObject.
	PRIVATE_MUST_NOT_BE_USED_ANYMORE = 4			///< Indicates that the CPyRef is not supposed to be used anymore and should be destructed as soon as possible.
} MAXON_ENUM_LIST(REFTYPE);

// forward declare lib
class CPythonLibraryInterface;

//----------------------------------------------------------------------------------------
/// Interface class for CPyRefs which removes the need for manual reference counting. The internally stored
/// PyObject can be disconnected from this wrapper class by calling CPyInterface::Disconnect.
///
/// @MAXON_ANNOTATION{refclass=false}
//----------------------------------------------------------------------------------------
class CPyInterface : MAXON_INTERFACE_BASES(ObjectInterface)
{
	MAXON_INTERFACE(CPyInterface, MAXON_REFERENCE_NORMAL, "net.maxon.python.interface.cpyref");
public:
	//----------------------------------------------------------------------------------------
	/// Creates a CPyRef reference by a given NativePyObject from a Python 2.7 virtual machine. GIL must be held. 
	/// @param[in] lib								The NativePyObject's library origin.
	/// @param[in] refType						Ref count handler information.
	/// @return												Returns a new wrapper reference.
	//----------------------------------------------------------------------------------------
	static MAXON_FUNCTION CPyRef CreateRef27(const CPythonLibraryInterface* lib, REFTYPE refType, NativePyObject* pyObject);

	//----------------------------------------------------------------------------------------
	/// Creates a CPyRef reference by a given NativePyObject from a Python 3.6 virtual machine. GIL must be held. 
	/// @param[in] lib								The NativePyObject's library origin.
	/// @param[in] refType						Ref count handler information.
	/// @return												Returns a new wrapper reference.
	//----------------------------------------------------------------------------------------
	static MAXON_FUNCTION CPyRef CreateRef36(const CPythonLibraryInterface* lib, REFTYPE refType, NativePyObject* pyObject);

	//----------------------------------------------------------------------------------------
	/// Creates a CPyRef reference by a given NativePyObject. GIL must be held. The library version is detected by using the library, is slightly slower than CreateRef27 or CreateRef36.
	/// @param[in] lib								The NativePyObject's library origin.
	/// @param[in] refType						Ref count handler information.
	/// @return												Returns a new wrapper reference.
	//----------------------------------------------------------------------------------------
	static MAXON_FUNCTION CPyRef CreateRef(const CPythonLibraryInterface* lib, REFTYPE refType, NativePyObject* pyObject);

	//----------------------------------------------------------------------------------------
	/// Creates a immutable CPyConstRef reference by a given NativePyObject. GIL must be held.
	/// @param[in] lib								The NativePyObject's library origin.
	/// @param[in] refType						Ref count handler information.
	/// @return												Returns a new wrapper reference.
	//----------------------------------------------------------------------------------------
	static MAXON_FUNCTION CPyConstRef CreateConstRef(const CPythonLibraryInterface* lib, REFTYPE refType, NativePyObject* pyObject);

	//----------------------------------------------------------------------------------------
	/// Creates a temporary CPyTempRef reference by a given NativePyObject. GIL must be held.
	/// @param[in] lib								The NativePyObject's library origin.
	/// @return												Returns a new wrapper reference.
	//----------------------------------------------------------------------------------------
	static MAXON_FUNCTION CPyTempRef CreateTempRef(const CPythonLibraryInterface* lib, NativePyObject* pyObject);

	//----------------------------------------------------------------------------------------
	/// Initializes the wrapper reference. GIL must be held.
	/// @param[in] lib								The NativePyObject's library origin.
	/// @param[in] refType						Ref count handler information.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void Init(const CPythonLibraryInterface* lib, REFTYPE refType, NativePyObject* pyObject);

	//----------------------------------------------------------------------------------------
	/// Increments the reference count. Instance must be already initialized. GIL must be held.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void Incref();
	
	//----------------------------------------------------------------------------------------
	/// Decrements the reference count. Instance must be already initialized. GIL must be held.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void Decref();

	//----------------------------------------------------------------------------------------
	/// Decrements the reference count. Instance must be already initialized. GIL must be held.
	/// @return												Reference count.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Int64 GetRefCount();

	//----------------------------------------------------------------------------------------
	/// Returns the library pointer with which the instance got initialized.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const CPythonLibraryInterface* GetLibrary() const;

	//----------------------------------------------------------------------------------------
	/// Returns the type object of the wrapped NativePyObject. GIL must be held.
	/// @return												Type reference.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD CPyTypeRef GetTypeRef() const;

	//----------------------------------------------------------------------------------------
	/// Returns the internal NativePyObject with which the instance got initialized. No reference
	/// count change is performed.
	/// @return												Internal NativePyObject
	//----------------------------------------------------------------------------------------
	MAXON_METHOD NativePyObject* GetPyObject() const;
	
	//----------------------------------------------------------------------------------------
	/// Returns the internal NativePyObject with which the instance got initialized. Objects reference count
	/// needs to be decremented if not used anymore. The wrapper reference becomes invalid, no
	/// other function should be called, and it should be deleted soon as possible. GIL must be held.
	/// @return												Internal NativePyObject
	//----------------------------------------------------------------------------------------
	MAXON_METHOD NativePyObject* Disconnect();

	//----------------------------------------------------------------------------------------
	/// Returns the internal NativePyObject cast to a target type. GIL must be held. No check is performed if the cast
	/// is valid or not. No reference count change is performed.
	/// @return												Internal NativePyObject casted.
	//----------------------------------------------------------------------------------------
	template <typename T = NativePyObject>
	MAXON_FUNCTION T* Get() const
	{
		return reinterpret_cast<T*>(GetPyObject());
	}

	//----------------------------------------------------------------------------------------
	/// Returns the internal NativePyObject cast to a target type. No check is performed if the cast
	/// is valid or not. Reference count is incremented before function returns. The wrapper reference
	/// stays valid. GIL must be held.
	/// @return												Internal NativePyObject casted.
	//----------------------------------------------------------------------------------------
	template <typename T = NativePyObject>
	MAXON_FUNCTION T* GetAndIncref()
	{
		Incref();
		return reinterpret_cast<T*>(GetPyObject());
	}


};

//----------------------------------------------------------------------------------------
/// Interface class for CPyRefs.
///
/// @MAXON_ANNOTATION{refclass=false}
//----------------------------------------------------------------------------------------
class CPyTypeInterface : MAXON_INTERFACE_BASES(CPyInterface)
{
	MAXON_INTERFACE(CPyTypeInterface, MAXON_REFERENCE_NORMAL, "net.maxon.python.interface.cpytype");
public:
	//----------------------------------------------------------------------------------------
	/// Creates a type reference by a given NativePyObject. GIL must be held.
	/// @param[in] lib								The NativePyObject's library origin.
	/// @param[in] refType						Ref count handler information.
	/// @return												Returns a new wrapper reference.
	//----------------------------------------------------------------------------------------
	static MAXON_FUNCTION CPyTypeRef CreateTypeRef(const CPythonLibraryInterface* lib, REFTYPE refType, NativePyObject* pyObject);
	
	//----------------------------------------------------------------------------------------
	/// Creates a immutable type reference by a given NativePyObject. GIL must be held.
	/// @param[in] lib								The NativePyObject's library origin.
	/// @param[in] refType						Ref count handler information.
	/// @return												Returns a new wrapper reference.
	//----------------------------------------------------------------------------------------
	static MAXON_FUNCTION CPyTypeConstRef CreateTypeConstRef(const CPythonLibraryInterface* lib, REFTYPE refType, NativePyObject* pyObject);
};

//----------------------------------------------------------------------------------------
/// Interface class for CPyRefs.
///
/// @MAXON_ANNOTATION{refclass=false}
//----------------------------------------------------------------------------------------
class CPyFrameInterface : MAXON_INTERFACE_BASES(CPyInterface)
{
	MAXON_INTERFACE(CPyFrameInterface, MAXON_REFERENCE_NORMAL, "net.maxon.python.interface.cpyframe");
public:
	//----------------------------------------------------------------------------------------
	/// Creates a frame reference by a given NativePyObject. GIL must be held.
	/// @param[in] lib								The NativePyObject's library origin.
	/// @param[in] refType						Ref count handler information.
	/// @return												Returns a new wrapper reference.
	//----------------------------------------------------------------------------------------
	static MAXON_FUNCTION CPyFrameRef CreateFrameRef(const CPythonLibraryInterface* lib, REFTYPE refType, NativePyObject* pyObject);

	MAXON_METHOD CPyFrameRef GetBack() const;
	MAXON_METHOD CPyCodeRef GetCode() const;
	MAXON_METHOD Int32 GetLastInstruction() const;
};

//----------------------------------------------------------------------------------------
/// Interface class for CPyRefs.
///
/// @MAXON_ANNOTATION{refclass=false}
//----------------------------------------------------------------------------------------
class CPyTracebackInterface : MAXON_INTERFACE_BASES(CPyInterface)
{
	MAXON_INTERFACE(CPyTracebackInterface, MAXON_REFERENCE_NORMAL, "net.maxon.python.interface.cpytraceback");
public:
	static MAXON_FUNCTION CPyTracebackRef CreateTracebackRef(const CPythonLibraryInterface* lib, REFTYPE refType, NativePyObject* pyObject);

	MAXON_METHOD CPyTracebackRef GetNext() const;
	MAXON_METHOD Int32 GetLineNumber() const;
	MAXON_METHOD CPyFrameRef GetFrameRef() const;
};

//----------------------------------------------------------------------------------------
/// Interface class for CPyRefs.
///
/// @MAXON_ANNOTATION{refclass=false}
//----------------------------------------------------------------------------------------
class CPyCodeInterface : MAXON_INTERFACE_BASES(CPyInterface)
{
	MAXON_INTERFACE(CPyCodeInterface, MAXON_REFERENCE_NORMAL, "net.maxon.python.interface.cpycode");
public:
	static MAXON_FUNCTION CPyCodeRef CreateCodeRef(const CPythonLibraryInterface* lib, REFTYPE refType, NativePyObject* pyObject);

	MAXON_METHOD CPyRef GetFilename() const;
	MAXON_METHOD CPyRef GetName() const;
};

//----------------------------------------------------------------------------------------
/// Interface class for CPyRefs.
///
/// @MAXON_ANNOTATION{refclass=false}
//----------------------------------------------------------------------------------------
class MPyClassInterface : MAXON_INTERFACE_BASES(CPyInterface)
{
	MAXON_INTERFACE(MPyClassInterface, MAXON_REFERENCE_NORMAL, "net.maxon.python.interface.mpyclass");
public:
	static MAXON_FUNCTION MPyClassRef CreateClassRef(const CPythonLibraryInterface* lib, REFTYPE refType, NativePyObject* pyObject);
};

//----------------------------------------------------------------------------------------
/// Interface class for CPyRefs.
///
/// @MAXON_ANNOTATION{refclass=false}
//----------------------------------------------------------------------------------------
class MPyMemberInterface : MAXON_INTERFACE_BASES(CPyInterface)
{
	MAXON_INTERFACE(MPyMemberInterface, MAXON_REFERENCE_NORMAL, "net.maxon.python.interface.mpymember");
public:
	static MAXON_FUNCTION MPyMemberRef CreateMemberRef(const CPythonLibraryInterface* lib, REFTYPE refType, NativePyObject* pyObject);
};

//----------------------------------------------------------------------------------------
/// Interface class for CPyRefs.
///
/// @MAXON_ANNOTATION{refclass=false}
//----------------------------------------------------------------------------------------
class MPyFunctionInterface : MAXON_INTERFACE_BASES(CPyInterface)
{
	MAXON_INTERFACE(MPyFunctionInterface, MAXON_REFERENCE_NORMAL, "net.maxon.python.interface.mpyfunction");
public:
	static MAXON_FUNCTION MPyFunctionRef CreateFunctionRef(const CPythonLibraryInterface* lib, REFTYPE refType, NativePyObject* pyObject);

	MAXON_METHOD const reflection::Function* GetFunction();
};

//----------------------------------------------------------------------------------------
/// Interface class for CPyRefs.
///
/// @MAXON_ANNOTATION{refclass=false}
//----------------------------------------------------------------------------------------
class MPyDataTypeInterface : MAXON_INTERFACE_BASES(CPyInterface)
{
	MAXON_INTERFACE(MPyDataTypeInterface, MAXON_REFERENCE_NORMAL, "net.maxon.python.interface.mpydatatype");
public:
	static MAXON_FUNCTION MPyDataTypeRef CreateDataTypeRef(const CPythonLibraryInterface* lib, REFTYPE refType, NativePyObject* pyObject);

	MAXON_METHOD const DataType& GetType() const;
};

//----------------------------------------------------------------------------------------
/// Interface class for CPyRefs.
///
/// @MAXON_ANNOTATION{refclass=false}
//----------------------------------------------------------------------------------------
class MPyDataInterface : MAXON_INTERFACE_BASES(CPyInterface)
{
	MAXON_INTERFACE(MPyDataInterface, MAXON_REFERENCE_NORMAL, "net.maxon.python.interface.mpydata");
public:
	static MAXON_FUNCTION MPyDataRef CreateDataRef(const CPythonLibraryInterface* lib, REFTYPE refType, NativePyObject* pyObject);

	MAXON_METHOD const DataType& GetType() const;
	MAXON_METHOD const DataType& GetMappingType() const;

	MAXON_METHOD Data* GetData();
	MAXON_METHOD const Data* GetData() const;
	MAXON_METHOD const Generic* PrivateGetPtr() const;
	MAXON_METHOD Generic* PrivateGetPtr();
};

//----------------------------------------------------------------------------------------
/// Interface class for CPyRefs.
///
/// @MAXON_ANNOTATION{refclass=false}
//----------------------------------------------------------------------------------------
class MPyCallerContextInterface : MAXON_INTERFACE_BASES(CPyInterface)
{
	MAXON_INTERFACE(MPyCallerContextInterface, MAXON_REFERENCE_NORMAL, "net.maxon.python.interface.mpycallercontext");
public:
	static MAXON_FUNCTION MPyCallerContextRef CreateCallerContextRef(const CPythonLibraryInterface* lib, REFTYPE refType, NativePyObject* pyObject);
};

#include "cpython_ref1.hxx"

template <typename T>
class CPyCompare : public T
{
private:
	using Super = T;
public:
	using Super::Super;
	using Super::operator =;

	Bool operator ==(std::nullptr_t) const
	{
		if (Super::operator ==(nullptr))
			return true;

		// TODO: (Seb) A reference should not exist in the first place if its nullptr
		if (this->template Get<void>() == nullptr)
			return true;

		return false;
	}

	Bool operator !=(std::nullptr_t) const
	{
		if (Super::operator ==(nullptr))
			return false;

		// TODO: (Seb) A reference should not exist in the first place if its nullptr
		if (this->template Get<void>() == nullptr)
			return false;

		return true;
	}

	Bool operator ==(Super& o)
	{
		if (Super::operator ==(o))
			return true;

		if (this->template Get<void>() == o.template Get<void>())
			return true;

		return false;
	}

	Bool operator !=(Super& o)
	{
		if (Super::operator ==(o))
			return false;

		if (this->template Get<void>() == o.template Get<void>())
			return false;

		return true;
	}

	Bool operator ==(const Super& o) const
	{
		if (Super::operator ==(o))
			return true;

		if (this->template Get<void>() == o.template Get<void>())
			return true;

		return false;
	}

	Bool operator !=(const Super& o) const
	{
		if (Super::operator ==(o))
			return false;

		if (this->template Get<void>() == o.template Get<void>())
			return false;

		return true;
	}
};

class CPyRef : public CPyCompare<CPyInterface::Reference>
{
private:
	using Super = CPyCompare<CPyInterface::Reference>;
public:
	using Super::Super;
	using Super::operator =;

	CPyRef() = default;
	MAXON_IMPLICIT CPyRef(std::nullptr_t) { }
};

#ifdef MAXON_COMPILER_INTEL
#pragma warning(push)
#pragma warning(disable:1418) // external function definition with no prior declaration
#endif


template <typename T>
typename std::enable_if<std::is_same<T, py::CPyRef>::value, T>::type CPyCast(const CPyRef& o) // no real cast, but needed for Cast<T> where T can be CPyRef or another Python ref type
{
	return o;
}

template <typename T>
typename std::enable_if<std::is_same<T, py::CPyTypeRef>::value, T>::type CPyCast(const CPyRef& o);

template <typename T>
typename std::enable_if<std::is_same<T, py::CPyFrameRef>::value, T>::type CPyCast(const CPyRef& o);

template <typename T>
typename std::enable_if<std::is_same<T, py::CPyTracebackRef>::value, T>::type CPyCast(const CPyRef& o);

template <typename T>
typename std::enable_if<std::is_same<T, py::CPyCodeRef>::value, T>::type CPyCast(const CPyRef& o);

template <typename T>
typename std::enable_if<std::is_same<T, py::MPyClassRef>::value, T>::type CPyCast(const CPyRef& o);

template <typename T>
typename std::enable_if<std::is_same<T, py::MPyMemberRef>::value, T>::type CPyCast(const CPyRef& o);

template <typename T>
typename std::enable_if<std::is_same<T, py::MPyFunctionRef>::value, T>::type CPyCast(const CPyRef& o);

template <typename T>
typename std::enable_if<std::is_same<T, py::MPyDataTypeRef>::value, T>::type CPyCast(const CPyRef& o);

template <typename T>
typename std::enable_if<std::is_same<T, py::MPyDataRef>::value, T>::type CPyCast(const CPyRef& o);

template <typename T>
typename std::enable_if<std::is_same<T, py::MPyCallerContextRef>::value, T>::type CPyCast(const CPyRef& o);


#ifdef MAXON_COMPILER_INTEL
#pragma warning(pop)
#endif

class CPyTypeRef : public CPyCompare<CPyTypeInterface::Reference>
{
private:
	using Super = CPyCompare<CPyTypeInterface::Reference>;
public:
	using Super::Super;
	using Super::operator =;
};

class CPyFrameRef : public CPyCompare<CPyFrameInterface::Reference>
{
private:
	using Super = CPyCompare<CPyFrameInterface::Reference>;
public:
	using Super::Super;
	using Super::operator =;
};

class CPyTracebackRef : public CPyCompare<CPyTracebackInterface::Reference>
{
private:
	using Super = CPyCompare<CPyTracebackInterface::Reference>;
public:
	using Super::Super;
	using Super::operator =;
};

class CPyCodeRef : public CPyCompare<CPyCodeInterface::Reference>
{
private:
	using Super = CPyCompare<CPyCodeInterface::Reference>;
public:
	using Super::Super;
	using Super::operator =;
};

class MPyClassRef : public CPyCompare<MPyClassInterface::Reference>
{
private:
	using Super = CPyCompare<MPyClassInterface::Reference>;
public:
	using Super::Super;
	using Super::operator =;
};

class MPyMemberRef : public CPyCompare<MPyMemberInterface::Reference>
{
private:
	using Super = CPyCompare<MPyMemberInterface::Reference>;
public:
	using Super::Super;
	using Super::operator =;
};

class MPyFunctionRef : public CPyCompare<MPyFunctionInterface::Reference>
{
private:
	using Super = CPyCompare<MPyFunctionInterface::Reference>;
public:
	using Super::Super;
	using Super::operator =;
};

class MPyDataTypeRef : public CPyCompare<MPyDataTypeInterface::Reference>
{
private:
	using Super = CPyCompare<MPyDataTypeInterface::Reference>;
public:
	using Super::Super;
	using Super::operator =;
};

class MPyDataRef : public CPyCompare<MPyDataInterface::Reference>
{
private:
	using Super = CPyCompare<MPyDataInterface::Reference>;
public:
	using Super::Super;
	using Super::operator =;
};

class MPyCallerContextRef : public CPyCompare<MPyCallerContextInterface::Reference>
{
private:
	using Super = CPyCompare<MPyCallerContextInterface::Reference>;
public:
	using Super::Super;
	using Super::operator =;
};

class CPyConstRef : public CPyCompare<CPyRef>
{
private:
	using Super = CPyCompare<CPyRef>;
public:
	CPyConstRef() { }
	using Super::Super;
	using Super::operator =;

	NativePyObject * Disconnect() = delete;
};

class CPyTypeConstRef : public CPyCompare<CPyTypeRef>
{
private:
	using Super = CPyCompare<CPyTypeRef>;
public:
	using Super::Super;
	using Super::operator =;

	NativePyObject * Disconnect() = delete;
};

class CPyTempRef
{
public:
	CPyTempRef() = default;
	explicit CPyTempRef(const CPyRef&&) = delete;
	explicit CPyTempRef(const CPyRef& o) : _ref(o) { }
	CPyTempRef operator =(const CPyRef&) = delete;
	CPyTempRef operator =(const CPyTempRef&) = delete;

	operator CPyRef&()
	{
		return _ref;
	}

	operator const CPyRef&() const
	{
		return _ref;
	}

private:
	CPyRef _ref;
};

MAXON_REGISTRY(Class<CPyRef>, CPyReferences27, "net.maxon.python.registry.pyreferences27");
namespace CPyReferences27
{
	MAXON_DECLARATION(Class<CPyRef>, CPy, "net.maxon.python.pyreference27.cpy");
	MAXON_DECLARATION(Class<CPyTypeRef>, CPyType, "net.maxon.python.pyreference27.cpytype");
	MAXON_DECLARATION(Class<CPyFrameRef>, CPyFrame, "net.maxon.python.pyreference27.cpyframe");
	MAXON_DECLARATION(Class<CPyTracebackRef>, CPyTraceback, "net.maxon.python.pyreference27.cpytraceback");
	MAXON_DECLARATION(Class<CPyCodeRef>, CPyCode, "net.maxon.python.pyreference27.cpycode");
	MAXON_DECLARATION(Class<MPyClassRef>, MPyClass, "net.maxon.python.pyreference27.mpyclass");
	MAXON_DECLARATION(Class<MPyMemberRef>, MPyMember, "net.maxon.python.pyreference27.mpymember");
	MAXON_DECLARATION(Class<MPyFunctionRef>, MPyFunction, "net.maxon.python.pyreference27.mpyfunction");
	MAXON_DECLARATION(Class<MPyDataTypeRef>, MPyDataType, "net.maxon.python.pyreference27.mpydatatype");
	MAXON_DECLARATION(Class<MPyDataRef>, MPyData, "net.maxon.python.pyreference27.mpydata");
	MAXON_DECLARATION(Class<MPyCallerContextRef>, MPyCallerContext, "net.maxon.python.pyreference27.mpycallercontext");
}

#include "cpython_ref2.hxx"

} // namespace py

} // namespace maxon

#endif // CPYTHON_REF_H__

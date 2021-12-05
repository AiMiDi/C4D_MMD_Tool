#ifndef CPYTHON27_RAW_H__
#define CPYTHON27_RAW_H__

#include "cpython_raw.h"
MAXON_DEPENDENCY_WEAK("cpython_raw.h");

#include "maxon/apibase.h"
#include "maxon/url.h"
#include "maxon/blockarray.h"
#include "maxon/reflectionbase.h"
#include "maxon/dll.h"
#include "maxon/string.h"

namespace maxon
{

namespace py
{
class CPythonLibraryRef;
} // namespace py

namespace py27
{

struct TpFlags
{
	static const Int64 NONE = 0;
	static const Int64 INT_SUBCLASS = (1L << 23);
	static const Int64 LONG_SUBCLASS = (1L << 24);
	static const Int64 LIST_SUBCLASS = (1L << 25);
	static const Int64 TUPLE_SUBCLASS = (1L << 26);
	static const Int64 STRING_SUBCLASS = (1L << 27);
	static const Int64 UNICODE_SUBCLASS = (1L << 28);
	static const Int64 DICT_SUBCLASS = (1L << 29);
	static const Int64 BASE_EXC_SUBCLASS = (1L << 30);
	static const Int64 TYPE_SUBCLASS = (1L << 31);
};

struct NativePyObjectHead_Debug : public py::NativePyObject
{
	NativePyObjectHead_Debug* _ob_next = nullptr;
	NativePyObjectHead_Debug* _ob_prev = nullptr;

	Int ob_refcnt = 0;
	struct NativePyTypeObject* ob_type = nullptr;

	_typeobject* GetTypeObject()
	{
		return reinterpret_cast<_typeobject*>(this->ob_type);
	}
};

struct NativePyObjectHead_Release : public py::NativePyObject
{
	Int ob_refcnt = 0;
	struct NativePyTypeObject* ob_type = nullptr;

	_typeobject* GetTypeObject()
	{
		return reinterpret_cast<_typeobject*>(this->ob_type);
	}
};

#ifdef MAXON_TARGET_DEBUG
	using NativePyObject = NativePyObjectHead_Debug;
#else
	using NativePyObject = NativePyObjectHead_Release;
#endif

struct NativePyModuleDefBase : public NativePyObject
{
};

struct NativePyModuleDef : public NativePyModuleDefBase
{
	NativePyModuleDef() = default;
	NativePyModuleDef(const Char* name, py::NativePyMethodDef* methods, const Char* doc) : m_name(name), m_doc(doc), m_methods(methods) { }

	const Char* m_name = nullptr;
	const Char* m_doc = "";
	Int64 m_size = -1;
	py::NativePyMethodDef* m_methods = nullptr;
	void* slots = nullptr;
	void* m_traverse = nullptr;
	void* m_clear = nullptr;
	void* m_free = nullptr;
};

struct NativePyVarObject : public NativePyObject
{
	Int ob_size = 0;
};

struct NativePyCodeObject : public NativePyObject
{
		Int32 co_argcount;								// #arguments, except *args
		Int32 co_nlocals;									// #local variables
		Int32 co_stacksize;								// #entries needed for evaluation stack
		Int32 co_flags;										// CO_..., see below
		NativePyObject *co_code;					// instruction opcodes
		NativePyObject *co_consts;				// list (constants used)
		NativePyObject *co_names;					// list of strings (names used)
		NativePyObject *co_varnames;			// tuple of strings (local variable names)
		NativePyObject *co_freevars;			// tuple of strings (free variable names)
		NativePyObject *co_cellvars;      // tuple of strings (cell variable names)
																			// The rest doesn't count for hash/cmp
		NativePyObject *co_filename;			// string (where it was loaded from)
		NativePyObject *co_name;					// string (name, for reference)
		Int32 co_firstlineno;							// first source line number
		NativePyObject *co_lnotab;				// string (encoding addr<->lineno mapping) See Objects/lnotab_notes.txt for details.
		void *co_zombieframe;							// for optimization only (see frameobject.c)
		NativePyObject *co_weakreflist;   // to support weakrefs to code objects
};

struct PyInterpreterState;

struct NativePyThreadState
{
	_ts* Get()
	{
		return reinterpret_cast<_ts*>(this);
	}

	struct _ts *next = nullptr;
	PyInterpreterState *interp = nullptr;

	struct NativePyFrameObject *frame = nullptr;
	Int32 recursion_depth;

	// tracing' keeps track of the execution depth when tracing/profiling.
	// This is to prevent the actual trace/profile code from being recorded in
	// the trace/profile.
	Int32 tracing;
	Int32 use_tracing;

	void* c_profilefunc; // Py_tracefunc
	void* c_tracefunc;
	NativePyObject *c_profileobj;
	NativePyObject *c_traceobj;

	NativePyObject *curexc_type;
	NativePyObject *curexc_value;
	NativePyObject *curexc_traceback;

	NativePyObject *exc_type;
	NativePyObject *exc_value;
	NativePyObject *exc_traceback;

	NativePyObject *dict;  //  Stores per-thread state 

	// tick_counter is incremented whenever the check_interval ticker
	// reaches zero. The purpose is to give a useful measure of the number
	// of interpreted bytecode instructions in a given thread.  This
	// extremely lightweight statistic collector may be of interest to
	// profilers (like psyco.jit()), although nothing in the core uses it.
	Int32 tick_counter;

	Int32 gilstate_counter;

	NativePyObject *async_exc; //  Asynchronous exception to raise 
	long thread_id; //  Thread id where this tstate was created 

	Int32 trash_delete_nesting;
	NativePyObject *trash_delete_later;
};

struct NativePyFrameObject : public NativePyVarObject
{
	NativePyFrameObject* f_back = nullptr;

	NativePyCodeObject* f_code;	//  code segment 
	NativePyObject*			f_builtins;	//  builtin symbol table (PyDictObject) 
	NativePyObject*			f_globals;	//  global symbol table (PyDictObject) 
	NativePyObject*			f_locals;		//  local symbol table (any mapping) 
	NativePyObject**		f_valuestack;	//  points after the last local 
														// Next free slot in f_valuestack.  Frame creation sets to f_valuestack.
														// Frame evaluation usually NULLs it, but a frame that yields sets it
														// to the current stack top.
	NativePyObject**		f_stacktop;
	NativePyObject*			f_trace;		//  Trace function 

												// If an exception is raised in this frame, the next three are used to
												// record the exception info (if any) originally in the thread state.  See
												// comments before set_exc_info() -- it's not obvious.
												// Invariant:  if _type is NULL, then so are _value and _traceback.
												// Desired invariant:  all three are NULL, or all three are non-NULL.  That
												// one isn't currently true, but "should be".
	NativePyObject *f_exc_type, *f_exc_value, *f_exc_traceback;

	NativePyThreadState *f_tstate;
	Int32 f_lasti = 0;		// Last instruction if called
												// Call PyFrame_GetLineNumber() instead of reading this field
												// directly.  As of 2.3 f_lineno is only valid when tracing is
												// active (i.e. when f_trace is set).  At other times we use
												// PyCode_Addr2Line to calculate the line from the current
												// bytecode index.
	Int32 f_lineno = 0;		// Current line number */
	Int32 f_iblock = 0;		// index in f_blockstack

	struct NativePyTryBlock
	{
		Int32 b_type = 0;
		Int32 b_handler = 0;
		Int32 b_level = 0;
	};
	
	NativePyTryBlock f_blockstack[NATIVE_CO_MAXBLOCKS];			// for try and loop blocks */

	NativePyObject* f_localsplus[1];	// locals+stack, dynamically sized */
};

struct NativePyMemoryViewBuffer
{
	UChar* buf = nullptr;
	NativePyObject* obj = nullptr;	//  owned reference 
	Int len = 0;
	Int itemsize = 0;								// This is Py_ssize_t so it can be
																	// pointed to by strides in simple case.
	Int32 readonly = 0;
	Int32 ndim = 0;
	Char* format = nullptr;
	Int* shape = nullptr;
	Int* strides = nullptr;
	Int* suboffsets = nullptr;
	Int smalltable[2];							// static store for shape and strides of
																	// mono-dimensional buffers. 
	void* internal = nullptr;
};

struct NativePyMemoryView : public NativePyObject
{
	NativePyObject* base = nullptr; // unknown
	NativePyMemoryViewBuffer view;
};

struct NativePyMember : public NativePyObject
{
	const reflection::Member* _member = nullptr;
};

using NativePyReflectionFunction_Entry = Tuple<DataType, Bool>;

struct NativePyReflectionFunction : public NativePyObject
{
	const reflection::Function* _func = nullptr;

	// in cases a parameter in reflection::Function is not registered
	// as a DataType, this array helps to convert it
	BaseArray<NativePyReflectionFunction_Entry> _parameters;
  DataType _returnType;
};

struct NativePyDelegate : public NativePyObject
{
	DelegateBase _delegate;
};

struct NativePyClassCapsule : public NativePyObject
{
	const reflection::Class* _cls = nullptr;
};

struct NativePyTracebackObject : public NativePyObject
{
	struct NativePyTracebackObject* tb_next = nullptr;
	struct NativePyFrameObject*			tb_frame = nullptr;
	Int32 tb_lasti = 0;
	Int32 tb_lineno = 0;
};

struct NativePyList : public NativePyObject
{
};

struct NativeCPyCallerContext_Debug : public NativePyObjectHead_Debug
{
	py::CPythonLibraryInterface* pylib = nullptr;
};

struct NativeCPyCallerContext_Release : public NativePyObjectHead_Release
{
	py::CPythonLibraryInterface* pylib = nullptr;
};

struct NativePyDataType : public NativePyObject
{
	DataTypePtr _dt;
};

struct NativePyData : public NativePyObject
{
	py::CPythonLibraryInterface* pylib = nullptr;
	Bool _owner = false;
	DataTypePtr _mappingType; // reserved for later use
																					// can also contain a BaseContainer pointer, additional workaround in DataType_Create(..)
	Data _data;

	BlockArray<Data> _helperStack; // used only in case this object is actually a BaseArray

	Data& GetData()
	{
		return _data;
	}

	const Data& GetData() const
	{
		return _data;
	}

	Generic* GetPtr()
	{
		return const_cast<Generic*>(GetData().PrivateGetPtr());
	}

	const DataType& GetType() const
	{
		return GetData().GetType();
	}
};

using NativePyCapsule_Destructor = void(struct NativePyCapsule*);

struct NativePyCapsule : public NativePyObject
{
	void* pointer = nullptr;
	const Char* name = nullptr;
	void *context = nullptr;
	NativePyCapsule_Destructor* destructor = nullptr;
};

struct NativePyTypeObject : public NativePyObject
{
	Int ob_size = 0;
	const Char* tp_name = nullptr;

	Int tp_basicsize = 0;
	Int tp_itemsize = 0;

	py::destruct* tp_dealloc = nullptr;
	void* tp_print = nullptr;
	void* tp_getattr = nullptr;
	void* tp_setattr = nullptr;
	void* tp_as_async = nullptr;

	py::reprfunc* tp_repr = nullptr;

	void* tp_as_number = nullptr;
	void* tp_as_sequence = nullptr;
	void* tp_as_mapping = nullptr;

	void* tp_hash = nullptr;
	void* tp_call = nullptr;
	py::reprfunc* tp_str = nullptr;
	void* tp_getattro = nullptr;
	void* tp_setattro = nullptr;

	void* tp_as_buffer = nullptr;

	Int64 tp_flags = TpFlags::NONE;

	const Char* tp_doc = nullptr;

	void* tp_traverse = nullptr;

	// delete references to contained objects
	void* tp_clear = nullptr;

	// rich comparisons
	void* tp_richcompare = nullptr;

	// weak reference enabler
	Int64 tp_weaklistoffset = 0;

	// Iterators
	void* tp_iter = nullptr;
	void* tp_iternext = nullptr;

	// Attribute descriptor and subclassing stuff
	void *tp_methods = nullptr;
	void *tp_members = nullptr;
	void *tp_getset = nullptr;
	void *tp_base = nullptr;

	NativePyObject *tp_dict = nullptr;
	void* tp_descr_get = nullptr;
	void* tp_descr_set = nullptr;
	Int64 tp_dictoffset = 0;
	void* tp_init = nullptr;
	py::allocfunc* tp_alloc = nullptr;

	py::newfunc* tp_new = nullptr;
	void* tp_free = nullptr;; // Low-level free-memory routine
	void* tp_is_gc = nullptr;; // For PyObject_IS_GC
	NativePyObject* tp_bases = nullptr;
	NativePyObject* tp_mro = nullptr; // method resolution order
	NativePyObject* tp_cache = nullptr;
	NativePyObject* tp_subclasses = nullptr;
	NativePyObject* tp_weaklist = nullptr;
	void* tp_del = nullptr;

	//  Type attribute cache version tag. Added in version 2.6 
	UInt32 tp_version_tag = 0;

#ifdef COUNT_ALLOCS
	//  these must be last and never explicitly initialized 
	Int tp_allocs = 0;
	Int tp_frees = 0;
	Int tp_maxalloc = 0;
	struct NativePyTypeObject* tp_prev = nullptr;
	struct NativePyTypeObject* tp_next = nullptr;
#endif

	_typeobject* Get()
	{
		return reinterpret_cast<_typeobject*>(this);
	}
};

MAXON_ATTRIBUTE_FORCE_INLINE NativePyTypeObject* Py_Type(NativePyObject* ob)
{
	return ob->ob_type;
}

struct NativePyIntObject : public NativePyObject
{
	_object* Get()
	{
		return reinterpret_cast<_object*>(this);
	}
};

struct NativePyLongObject : public NativePyObject
{
	NativePyLongObject* Get()
	{
		return reinterpret_cast<NativePyLongObject*>(this);
	}
};

} // namespace py

} // namespace maxon

#endif // CPYTHON27_RAW_H__

/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef LIB_PY_H__
#define LIB_PY_H__

#include <stdarg.h>

#include "c4d_library.h"
#include "c4d_resource.h"
#include "ge_math.h"

#ifdef __API_INTERN__

#include "pluginobject.h"
#include "plugintag.h"

#else

#include "c4d_baseobject.h"
#include "c4d_basetag.h"

#endif

struct PyLibrary;
class PythonBase;
class PythonGIL;
struct _PyObject;
class CPyDict_Wrapper;
class CPyTuple_Wrapper;
class CPyList_Wrapper;

#define C4DPL_PYINITTYPES 1027123				// message when Python library was loaded successfully and third-party plugins can add their own Python types
#define C4DPL_PYINITIALIZE 1026661			// message when Python is fully loaded and all types (including third-party plugins) are available
#define C4DPL_PYENDPLUGINS 300002146		// message send before Python is about to stop all Python Threads and unload all Python Plugins
#define C4DPL_PYFINALIZE 1026662				// message send when all Python objects must be freed and no Python function must be used anymore

#define PYTHON_GET_CODE_FROM_EDITOR	1023729

enum class SCRIPTMETA : int
{
	DOCUMENTATION = 0,
	NAME
} MAXON_ENUM_LIST(SCRIPTMETA);

enum class PYFN_FLAGS
{
	VARARGS		= 0x0001,
	KEYWORDS	= 0x0002,
	NOARGS		= 0x0004,
	STATIC		= 0x0020,
	//////////////////////////////////////////////////////////////
	NONE = 0,

	ARGS_KEYWORDS = VARARGS | KEYWORDS
} MAXON_ENUM_FLAGS(PYFN_FLAGS);

enum class XPYCOMPILERINPUT
{
	SINGLE	= 256, // Py_single_input
	FILE 		= 257, // Py_file_input
	EVAL 		= 258, // Py_eval_input
} MAXON_ENUM_LIST(XPYCOMPILERINPUT);

typedef _PyObject *(*PyFn)(_PyObject *, _PyObject *);
typedef _PyObject *(*PyFnKeywords)(_PyObject *, _PyObject *, _PyObject *);
typedef _PyObject *(*PyFnNoArgs)(_PyObject *);

class PythonMethodData
{
public:
	PythonMethodData() { m_Flags = PYFN_FLAGS::NONE; m_pName = nullptr; m_pHelp = nullptr; }
	~PythonMethodData() { DeleteMem(m_pName); DeleteMem(m_pHelp); }

	void Init(const String &name, PyFn fn, PYFN_FLAGS flags, const String &help);

	PYFN_FLAGS m_Flags;
	PyFn m_pFunction;
	Char *m_pName;
	Char *m_pHelp;
};

class PythonTypeBase	// !! do not use any virtual members !!
{
protected:

	typedef PythonTypeBase *(PythonTypeBase::*PyTyAlloc)();
	typedef void (PythonTypeBase::*PyTyFree)(PythonTypeBase *&tybase);
	typedef Bool (PythonTypeBase::*PyTySetData)(const GeData &data);
	typedef Bool (PythonTypeBase::*PyTyGetData)(GeData &data);

	PyTyAlloc _Alloc;
	PyTyFree _Free;
	PyTySetData _SetData;
	PyTyGetData _GetData;

public:

	PythonTypeBase *Alloc() { return (_Alloc)?(this->*_Alloc)():nullptr; }
	void Free(PythonTypeBase *&tybase) { if (_Free) (this->*_Free)(tybase); }
	Bool SetData(const GeData &data) { return (_SetData)?(this->*_SetData)(data):false; }
	Bool GetData(GeData &data) { return (_GetData)?(this->*_GetData)(data):false; }

};

class PythonLibrary
{
public:
	Bool Execute(const String &code);

	//////////////////////////////////////////////////////////////////////////

	PythonBase *Alloc();
	void Free(PythonBase *&base);

	PythonTypeBase *AllocType();
	void FreeType(PythonTypeBase *&base);

	Bool Run(const String &code, PythonBase *base, const String &name_handler, XPYCOMPILERINPUT flag);

	Bool Initiated(PythonBase *base);

	Bool SetGeData(PythonBase *base, const String &name, const GeData &dat);
	Bool SetBaseThread(PythonBase *base, const String &name, BaseThread *bt);
	Bool SetGeResource(PythonBase *base, const String &name, GeResource *res, Bool owner);
	Bool SetGeListNode(PythonBase *base, const String &name, GeListNode *obj, Bool owner);
	Bool SetPyObject(PythonBase *base, const String &name, _PyObject *op);
	Bool SetNone(PythonBase *base, const String &name);
	Bool SetString(PythonBase *base, const String &name, const String &value);
	Bool SetInt32(PythonBase *base, const String &name, const Int32 value);
	Bool SetVector(PythonBase *base, const String &name, const Vector &value);
	Bool SetMatrix(PythonBase *base, const String &name, const Matrix &value);
	Bool SetInt64(PythonBase *base, const String &name, const Int64 value);
	Bool SetFloat(PythonBase *base, const String &name, const Float value);
	Bool SetContainer(PythonBase *base, const String &name, const BaseContainer &value);
	Bool SetCustom(PythonBase *base, const String &name, const String &type, const GeData &value);

	Bool FindRef(PythonBase *base, const String &name);
	_PyObject *GetObject(PythonBase *base, const String &name);
	Bool GetName(_PyObject *op, String &name);

	Bool GetGeData(PythonBase *base, _PyObject *op, GeData &dat);
	Bool GetBaseThread(PythonBase *base, _PyObject *op, BaseThread *&bt);
	Bool GetGeResource(PythonBase *base, _PyObject *op, GeResource *&res);
	Bool GetGeListNode(PythonBase *base, _PyObject *op, GeListNode *&obj);
	Bool GetString(PythonBase *base, _PyObject *op, String &value);
	Bool GetLONG(PythonBase *base, _PyObject *op, Int32 &value);
	Bool GetInt32(PythonBase *base, _PyObject *op, Int32 &value);
	Bool GetVector(PythonBase *base, _PyObject *op, Vector &value);
	Bool GetMatrix(PythonBase *base, _PyObject *op, Matrix &value);
	Bool GetLLONG(PythonBase *base, _PyObject *op, Int64 &value);
	Bool GetInt64(PythonBase *base, _PyObject *op, Int64 &value);
	Bool GetFloat(PythonBase *base, _PyObject *op, Float &value);
	Bool GetContainer(PythonBase *base, _PyObject *op, BaseContainer &value);
	Bool GetCustom(PythonBase *base, _PyObject *op, const String &type, GeData &value);

	Bool FunctionCheck(_PyObject *op);
	void ErrSetString(_PyObject *err, const String &msg);
	void ErrPrint();
	Bool pyExecuteFile(const Filename &fn);
	void pyGetLastError(Bool restore, Int32 *line, Int32 *cols, String *err);
	void DecRef(_PyObject *op);
	void IncRef(_PyObject *op);
	PythonGIL *AllocGIL();
	void FreeGIL(PythonGIL *&gil);
	_PyObject *CallFunction(_PyObject *op);
	_PyObject *ObjectNew(_PyObject *type);
	void ObjectDel(_PyObject *&op);
	_PyObject *GetModule(const String &name);
	Bool CheckSyntax(const String &code, Int32 *line = nullptr, Int32 *cols = nullptr, String *err = nullptr);

	Bool InitType(const String &name, PythonTypeBase *tybase, PythonMethodData *methods, const String &help);
	Bool InitModule(const String &name, PythonMethodData *methods, const String &help);
	Bool InitConstant(_PyObject *op, const String &name, Int32 value);
	Bool InitStringConstant(_PyObject *op, const String &name, const String &value);
	PythonTypeBase *GetTypeBase(_PyObject *op);

	_PyObject *ReturnPyInt32(Int32 value);
	_PyObject *ReturnPyInt(Int value);
	_PyObject *ReturnPyUInt(UInt value);
	_PyObject *ReturnPyInt64(Int64 value);
	_PyObject *ReturnPyBool(Bool value);
	_PyObject *ReturnPyFloat(Float value);
	_PyObject *ReturnPyString(const String &value);
	_PyObject *ReturnPyContainer(const BaseContainer &value);
	_PyObject *ReturnPyTime(const BaseTime &value);
	_PyObject *ReturnPyVector(const Vector &value);
	_PyObject *ReturnPyMatrix(const Matrix &value);
	_PyObject *ReturnPyGeData(const GeData &value);
	_PyObject *ReturnPyVoidPtr(void *value);
	_PyObject *ReturnPyRangeErr(const String &str);
	_PyObject *ReturnPyNone();
	_PyObject *ReturnPyTRUE();
	_PyObject *ReturnPyFALSE();
	_PyObject *ReturnPyNOTIMPLEMENTED();
	_PyObject *ReturnPyCustom(const String &type, const GeData &value);
	_PyObject *ReturnGeListNode(const GeListNode *op, Bool owner);

	Bool ParseTupleAndKeywords(_PyObject *args, _PyObject *keywords, const Char *format, const Char *kwlist[], ...);
	Bool ParseTupleAndKeywords(_PyObject *args, _PyObject *keywords, const Char *format, const Char *kwlist[], va_list *p_va);

	String GetDocString(const String &code);
	String GetDocStringMeta(const String &doc, SCRIPTMETA info, Bool english);

	Bool ImportModule(PythonBase *base, const String &name);
	Bool PluginMessage(_PyObject* func, Int32 id, void* data);
	_PyObject *CallFunctionWithArguments(_PyObject *op, GeData *arg1 = nullptr, GeData *arg2 = nullptr, GeData *arg3 = nullptr, GeData *arg4 = nullptr);
	Bool Message(_PyObject* func, Int32 id, void* data);
};

class PyList;
class PyDict;
class PyTuple;

class PyTuple
{
public:
	Bool AppendBool(Bool p);
	Bool AppendInt32(Int32 p);
	Bool AppendFloat(Float p);
	Bool AppendChar(Char p);
	Bool AppendNone();
	Bool AppendVector(const Vector &p);
	Bool AppendMatrix(const Matrix &p);
	Bool AppendString(const String &p);
	Bool AppendGeData(const GeData &p);
	Bool AppendDescID(const DescID &id);
	Bool AppendPyObject(_PyObject *op);
	Bool AppendBaseTime(const BaseTime &p);
	Bool AppendBitmap(BaseBitmap *p, Bool owner);
	Bool AppendObject(GeListNode *p, Bool owner);
	Bool AppendBaseContainer(const BaseContainer &p);

	static PyTuple* Alloc(Int32 s);
	static void Free(PyTuple*& p);

private:
	C4D_RESERVE_PRIVATE_TYPE(void*, obj);

	PyTuple() { }
	~PyTuple() { }
};

class PyDict
{
public:
	Bool AppendBool(const Char* name, Bool p);
	Bool AppendInt32(const Char* name, Int32 p);
	Bool AppendFloat(const Char* name, Float p);
	Bool AppendChar(const Char* name, Char p);
	Bool AppendNone(const Char* name);
	Bool AppendVector(const Char* name, const Vector &p);
	Bool AppendMatrix(const Char* name, const Matrix &p);
	Bool AppendString(const Char* name, const String &p);
	Bool AppendGeData(const Char* name, const GeData &p);
	Bool AppendDescID(const Char* name, const DescID &id);
	Bool AppendPyObject(const Char* name, _PyObject *op);
	Bool AppendBaseTime(const Char* name, const BaseTime &p);
	Bool AppendBitmap(const Char* name, BaseBitmap *p, Bool owner);
	Bool AppendObject(const Char* name, GeListNode *p, Bool owner);
	Bool AppendBaseContainer(const Char* name, const BaseContainer &p);
	Bool AppendList(const Char* name, PyList& list);

	static PyDict* Alloc();
	static void Free(PyDict*& p);

private:
	C4D_RESERVE_PRIVATE_TYPE(void*, obj);

	PyDict() { }
	~PyDict() { }
};

class PyList
{
public:
	Bool AppendBool(Bool p);
	Bool AppendInt32(Int32 p);
	Bool AppendFloat(Float p);
	Bool AppendChar(Char p);
	Bool AppendNone();
	Bool AppendVector(const Vector &p);
	Bool AppendMatrix(const Matrix &p);
	Bool AppendString(const String &p);
	Bool AppendGeData(const GeData &p);
	Bool AppendDescID(const DescID &id);
	Bool AppendPyObject(_PyObject *op);
	Bool AppendBaseTime(const BaseTime &p);
	Bool AppendBitmap(BaseBitmap *p, Bool owner);
	Bool AppendObject(GeListNode *p, Bool owner);
	Bool AppendBaseContainer(const BaseContainer &p);
	Bool AppendDict(PyDict &p);

	static PyList* Alloc();
	static void Free(PyList*& p);

private:
	C4D_RESERVE_PRIVATE_TYPE(void*, obj);

	PyList() { }
	~PyList() { }
};


class Python
{
	PythonBase *m_pBase;

private:

	Python() { m_pBase = m_PyLib.Alloc(); }
	~Python() { m_PyLib.Free(m_pBase); }

	PythonLibrary m_PyLib;
};

//////////////////////////////////////////////////////////////////////////

class GePythonGIL
{
public:
	explicit GePythonGIL(PythonGIL *gil = nullptr)
	{
		m_pGIL = gil?gil:m_PyLib.AllocGIL();
		owner = (gil == nullptr);
	}
	~GePythonGIL()
	{
		if (m_pGIL && owner) m_PyLib.FreeGIL(m_pGIL);
	}

	Bool HasGIL() { return m_pGIL != nullptr; }

private:

	Bool owner;
	PythonGIL *m_pGIL;
	PythonLibrary m_PyLib;
};

class GePython
{
public:

	GePython(); // no GIL
	~GePython(); // no GIL

	Bool Init(const String &handler = String()); // no GIL
	void Free(); // no GIL

	Bool Run(const String& code);

	Bool ImportModule(const String &mod_name); // no GIL

	Bool HasCode() { return _code.IsPopulated(); } // no GIL

	Bool CallFunction(const String &name, GeData *ret = nullptr); // GIL
	Bool HasFunction(const String &name);// GIL

	Bool SetString(const String &name, const String &str);// GIL
	Bool SetMatrix(const String &name, const Matrix &m);// GIL
	Bool SetVector(const String &name, const Vector &v);// GIL
	Bool SetFloat(const String &name, Float v);// GIL
	Bool SetNode(const String &name, const GeListNode *node);// GIL
	Bool SetContainer(const String &name, const BaseContainer &bc);// GIL
	Bool SetCustom(const String &name, const String &type, const GeData &v);// GIL
	Bool SetInt32(const String &name, Int32 v);// GIL

	Bool GetContainer(const String &name, BaseContainer &bc);// GIL
	Bool GetInt32(const String &name, Int32 &v);// GIL
	Bool GetMatrix(const String &name, Matrix &m);// GIL

	Bool PluginMessage(Int32 id, void* data);// GIL

private:
	PythonLibrary m_PyLib;
	PythonBase *m_pPyBase;

	String _code;
	String _handler;

public:
	Bool SetThread(const String &name, BaseThread *bt);// GIL

	_PyObject *GetFunction(const String &name);

	Bool CallFunction(_PyObject *functionObject, GeData *ret = nullptr);
	Bool CallFunctionWithArguments(const String &name, GeData *arg1 = nullptr, GeData *arg2 = nullptr, GeData *arg3 = nullptr, GeData *arg4 = nullptr, GeData *ret = nullptr); // GIL
	Bool CallFunctionWithArguments(_PyObject *functionObject, GeData *arg1 = nullptr, GeData *arg2 = nullptr, GeData *arg3 = nullptr, GeData *arg4 = nullptr, GeData *ret = nullptr);

	Bool Message(Int32 id, void* data);// GIL

	Bool GetNode(const String &name, GeListNode *&n);// GIL
};

//////////////////////////////////////////////////////////////////////////

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

//////////////////////////////////////////////////////////////////////////
#define LIBRARY_PY		1025707
//////////////////////////////////////////////////////////////////////////

struct PyLibrary : public C4DLibrary
{
	Bool (*pyExecute)(const String &code);

	PythonBase *(*pyAlloc)();
	void (*pyFree)(PythonBase *&base);

	//////////////////////////////////////////////////////////////////////////

	Bool (*pyRun)(const String &code, PythonBase *base, const String &name_handler, XPYCOMPILERINPUT flag);

	Bool (*pyInitiated)(PythonBase *base);

	Bool (*pySetGeData)(PythonBase *base, const String &name, const GeData &dat);
	Bool (*pySetBaseThread)(PythonBase *base, const String &name, BaseThread *bt);
	Bool (*pySetGeResource)(PythonBase *base, const String &name, GeResource *res, Bool owner);
	Bool (*pySetGeListNode)(PythonBase *base, const String &name, GeListNode *obj, Bool owner);
	Bool (*pySetPyObject)(PythonBase *base, const String &name, _PyObject *op);
	Bool (*pySetNone)(PythonBase *base, const String &name);
	Bool (*pySetString)(PythonBase *base, const String &name, const String &value);
	Bool (*pySetInt32)(PythonBase *base, const String &name, const Int32 value);
	Bool (*pySetVector)(PythonBase *base, const String &name, const Vector &value);
	Bool (*pySetMatrix)(PythonBase *base, const String &name, const Matrix &value);
	Bool (*pySetInt64)(PythonBase *base, const String &name, const Int64 value);
	Bool (*pySetFloat)(PythonBase *base, const String &name, const Float value);
	Bool (*pySetContainer)(PythonBase *base, const String &name, const BaseContainer &value);
	Bool (*pySetCustom)(PythonBase *base, const String &name, const String &type, const GeData &value);

	Bool (*pyImportModule)(PythonBase *base, const String &name);
	Bool (*pyFindRef)(PythonBase *base, const String &name);
	_PyObject *(*pyGetObject)(PythonBase *base, const String &name);
	Bool (*pyGetName)(_PyObject *op, String &name);

	Bool (*pyGetGeData)(PythonBase *base, _PyObject *op, GeData &dat);
	Bool (*pyGetBaseThread)(PythonBase *base, _PyObject *op, BaseThread *&bt);
	Bool (*pyGetGeResource)(PythonBase *base, _PyObject *op, GeResource *&res);
	Bool (*pyGetGeListNode)(PythonBase *base, _PyObject *op, GeListNode *&obj);
	Bool (*pyGetString)(PythonBase *base, _PyObject *op, String &value);
	Bool (*pyGetInt32)(PythonBase *base, _PyObject *op, Int32 &value);
	Bool (*pyGetVector)(PythonBase *base, _PyObject *op, Vector &value);
	Bool (*pyGetMatrix)(PythonBase *base, _PyObject *op, Matrix &value);
	Bool (*pyGetInt64)(PythonBase *base, _PyObject *op, Int64 &value);
	Bool (*pyGetFloat)(PythonBase *base, _PyObject *op, Float &value);
	Bool (*pyGetContainer)(PythonBase *base, _PyObject *op, BaseContainer &value);
	Bool (*pyGetCustom)(PythonBase *base, _PyObject *op, const String &type, GeData &value);

	Bool (*pyFunctionCheck)(_PyObject *op);
	void (*pyErrSetString)(_PyObject *err, const String &msg);
	void (*pyErrPrint)();
	void (*pyGetLastError)(Bool restore, Int32 *line, Int32 *cols, String *err);
	Bool (*pyExecuteFile)(const Filename &fn);
	void (*pyDecRef)(_PyObject *op);
	void (*pyIncRef)(_PyObject *op);
	PythonGIL *(*pyAllocGIL)();
	void (*pyFreeGIL)(PythonGIL *&gil);
	_PyObject *(*pyCallFunction)(_PyObject *op);
	_PyObject *(*pyObjectNew)(_PyObject *type);
	void (*pyObjectDel)(_PyObject *&op);
	_PyObject *(*pyGetModule)(const String &name);
	Bool (*pyCheckSyntax)(const String &code, Int32 *line, Int32 *cols, String *err);

	Bool (*pyInitType)(const String &name, PythonTypeBase *tybase, PythonMethodData *methods, const String &help);
	Bool (*pyInitModule)(const String &name, PythonMethodData *methods, const String &help);
	Bool (*pyInitConstant)(_PyObject *op, const String &name, Int32 value);
	Bool (*pyInitStringConstant)(_PyObject *op, const String &name, const String &value);
	PythonTypeBase *(*pyGetTypeBase)(_PyObject *op);

	_PyObject *(*pyReturnPyInt32)(Int32 value);
	_PyObject *(*pyReturnPyInt)(Int value);
	_PyObject *(*pyReturnPyUInt)(UInt value);
	_PyObject *(*pyReturnPyInt64)(Int64 value);
	_PyObject *(*pyReturnPyBool)(Bool value);
	_PyObject *(*pyReturnPyFloat)(Float value);
	_PyObject *(*pyReturnPyString)(const String &value);
	_PyObject *(*pyReturnPyContainer)(const BaseContainer &value);
	_PyObject *(*pyReturnPyTime)(const BaseTime &value);
	_PyObject *(*pyReturnPyVector)(const Vector &value);
	_PyObject *(*pyReturnPyMatrix)(const Matrix &value);
	_PyObject *(*pyReturnPyGeData)(const GeData &value);
	_PyObject *(*pyReturnPyVoidPtr)(void *value);
	_PyObject *(*pyReturnPyRangeErr)(const String &str);
	_PyObject *(*pyReturnPyNone)();
	_PyObject *(*pyReturnPyTRUE)();
	_PyObject *(*pyReturnPyFALSE)();
	_PyObject *(*pyReturnPyNOTIMPLEMENTED)();
	_PyObject *(*pyReturnGeListNode)(const GeListNode *op, Bool owner);
	_PyObject *(*pyReturnPyCustom)(const String &type, const GeData &value);

	Bool (*pyParseTupleAndKeywords)(_PyObject *args, _PyObject *keywords, const Char *format, const Char *kwlist[], va_list *p_va);

	String (*pyDocString)(const String &code);
	String (*pyDocStringMeta)(const String &doc, SCRIPTMETA info, Bool english);

	PyTuple* (*pyAllocTuple)(Int32 s);
	void (*pyFreeTuple)(PyTuple *&op);
	Bool (CPyTuple_Wrapper::*pyTupleAppendBool)(Bool p);
	Bool (CPyTuple_Wrapper::*pyTupleAppendInt32)(Int32 p);
	Bool (CPyTuple_Wrapper::*pyTupleAppendFloat)(Float p);
	Bool (CPyTuple_Wrapper::*pyTupleAppendChar)(Char p);
	Bool (CPyTuple_Wrapper::*pyTupleAppendNone)();
	Bool (CPyTuple_Wrapper::*pyTupleAppendVector)(const Vector &p);
	Bool (CPyTuple_Wrapper::*pyTupleAppendMatrix)(const Matrix &p);
	Bool (CPyTuple_Wrapper::*pyTupleAppendString)(const String &p);
	Bool (CPyTuple_Wrapper::*pyTupleAppendGeData)(const GeData &p);
	Bool (CPyTuple_Wrapper::*pyTupleAppendDescID)(const DescID &id);
	Bool (CPyTuple_Wrapper::*pyTupleAppendBaseTime)(const BaseTime &p);
	Bool (CPyTuple_Wrapper::*pyTupleAppendBitmap)(BaseBitmap *p, Bool owner);
	Bool (CPyTuple_Wrapper::*pyTupleAppendObject)(GeListNode *p, Bool owner);
	Bool (CPyTuple_Wrapper::*pyTupleAppendBaseContainer)(const BaseContainer &p);
	Bool (*pyTupleAppendPyObject)(PyTuple* t, _PyObject *op);

	PyList* (*pyAllocList)();
	void (*pyFreeList)(PyList*& op);
	Bool (CPyList_Wrapper::*pyListAppendBool)(Bool p);
	Bool (CPyList_Wrapper::*pyListAppendInt32)(Int32 p);
	Bool (CPyList_Wrapper::*pyListAppendFloat)(Float p);
	Bool (CPyList_Wrapper::*pyListAppendChar)(Char p);
	Bool (CPyList_Wrapper::*pyListAppendNone)();
	Bool (CPyList_Wrapper::*pyListAppendVector)(const Vector &p);
	Bool (CPyList_Wrapper::*pyListAppendMatrix)(const Matrix &p);
	Bool (CPyList_Wrapper::*pyListAppendString)(const String &p);
	Bool (CPyList_Wrapper::*pyListAppendGeData)(const GeData &p);
	Bool (CPyList_Wrapper::*pyListAppendDescID)(const DescID &id);
	Bool (CPyList_Wrapper::*pyListAppendBaseTime)(const BaseTime &p);
	Bool (CPyList_Wrapper::*pyListAppendBitmap)(BaseBitmap *p, Bool owner);
	Bool (CPyList_Wrapper::*pyListAppendObject)(GeListNode *p, Bool owner);
	Bool (CPyList_Wrapper::*pyListAppendBaseContainer)(const BaseContainer &p);
	Bool (*pyListAppendDict)(PyList* l, PyDict& dict);
	Bool (*pyListAppendPyObject)(PyList* l, _PyObject *op);

	PyDict* (*pyAllocDict)();
	void (*pyFreeDict)(PyDict*& op);
	Bool (CPyDict_Wrapper::*pyDictAppendBool)(const Char* name, Bool p);
	Bool (CPyDict_Wrapper::*pyDictAppendInt32)(const Char* name, Int32 p);
	Bool (CPyDict_Wrapper::*pyDictAppendFloat)(const Char* name, Float p);
	Bool (CPyDict_Wrapper::*pyDictAppendChar)(const Char* name, Char p);
	Bool (CPyDict_Wrapper::*pyDictAppendNone)(const Char* name);
	Bool (CPyDict_Wrapper::*pyDictAppendVector)(const Char* name, const Vector &p);
	Bool (CPyDict_Wrapper::*pyDictAppendMatrix)(const Char* name, const Matrix &p);
	Bool (CPyDict_Wrapper::*pyDictAppendString)(const Char* name, const String &p);
	Bool (CPyDict_Wrapper::*pyDictAppendGeData)(const Char* name, const GeData &p);
	Bool (CPyDict_Wrapper::*pyDictAppendDescID)(const Char* name, const DescID &id);
	Bool (CPyDict_Wrapper::*pyDictAppendBaseTime)(const Char* name, const BaseTime &p);
	Bool (CPyDict_Wrapper::*pyDictAppendBitmap)(const Char* name, BaseBitmap *p, Bool owner);
	Bool (CPyDict_Wrapper::*pyDictAppendObject)(const Char* name, GeListNode *p, Bool owner);
	Bool (CPyDict_Wrapper::*pyDictAppendBaseContainer)(const Char* name, const BaseContainer &p);
	Bool (*pyDictAppendPyObject)(PyDict* d, const Char* name, _PyObject *op);
	Bool (*pyDictAppendList)(PyDict* l, const Char* name, PyList& list);
	Bool (*pyPluginMessage)(_PyObject* func, Int32 id, void* data);
	_PyObject *(*pyCallFunctionArgs)(_PyObject *op, GeData *arg1, GeData *arg2, GeData *arg3, GeData *arg4);
	Bool (*pyMessage)(_PyObject* func, Int32 id, void* data);
};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

#endif // LIB_PY_H__

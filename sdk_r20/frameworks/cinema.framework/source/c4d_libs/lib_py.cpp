#include <stdarg.h>
#include "lib_py.h"

//////////////////////////////////////////////////////////////////////////

PyLibrary *lib_py = nullptr;

static PyLibrary *CheckPyLib(Int32 offset)
{
	return (PyLibrary*)CheckLib(LIBRARY_PY, offset, (C4DLibrary**)&lib_py);
}

#define PyLibCall(b) 		PyLibrary *lib = CheckPyLib(LIBOFFSET(PyLibrary, b)); \
															if (!lib || !lib->b) return; \
															(lib->b)

#define PyLibCallR(a, b)  PyLibrary *lib = CheckPyLib(LIBOFFSET(PyLibrary, b)); \
															if (!lib || !lib->b) return a; \
															return (lib->b)

#define PyPyRCall(a, b, c)	PyLibrary *lib = CheckPyLib(LIBOFFSET(PyLibrary, a)); \
														if (!lib || !lib->a) return c; \
														return (((b*)this)->*(lib->a))

#define PyPyCall(a, b)	PyLibrary *lib = CheckPyLib(LIBOFFSET(PyLibrary, a)); \
												if (!lib || !lib->a) return; \
												return (((b*)this)->*(lib->a))

//////////////////////////////////////////////////////////////////////////

GePython::GePython()
{
	m_pPyBase = nullptr;
}

GePython::~GePython()
{
	Free();
}

void GePython::Free()
{
	if (m_pPyBase)
	{
		GePythonGIL gil_state;
		m_PyLib.Free(m_pPyBase);
	}
	_code = String();
}

Bool GePython::Init(const String &handler)
{
	Free();

	GePythonGIL gil_state;

	m_pPyBase = m_PyLib.Alloc();
	if (!m_pPyBase)
		return false;

	_handler = handler;

	if (!m_PyLib.Initiated(m_pPyBase))
	{
		Free();
		return false;
	}

	return true;
}

Bool GePython::Run(const String& code)
{
	if (!code.IsPopulated())
		return false;

	_code = code;

	GePythonGIL gil_state;

	if (!m_PyLib.Run(_code, m_pPyBase, (_handler.IsPopulated()) ? _handler : "GePython", XPYCOMPILERINPUT::FILE))
	{
		m_PyLib.ErrPrint();
		return false;
	}

	return true;
}

Bool GePython::ImportModule(const String &name)
{
	GePythonGIL gil_state;
	return m_PyLib.ImportModule(m_pPyBase, name);
}

Bool GePython::HasFunction(const String &name)
{
	if (!m_pPyBase || !m_PyLib.Initiated(m_pPyBase)) return false;

	_PyObject *fn = m_PyLib.GetObject(m_pPyBase, name);
	if (!fn) return false;

	return m_PyLib.FunctionCheck(fn);
}

_PyObject *GePython::GetFunction(const String &name)
{
	if (!m_pPyBase || !m_PyLib.Initiated(m_pPyBase))
		return nullptr;

	_PyObject *fn = m_PyLib.GetObject(m_pPyBase, name);
	if (!fn)
		return nullptr;

	if (!m_PyLib.FunctionCheck(fn))
		return nullptr;

	return fn;
}

Bool GePython::PluginMessage(Int32 id, void* data)
{
	if (!m_pPyBase || !m_PyLib.Initiated(m_pPyBase)) return false;

	_PyObject *fn = m_PyLib.GetObject(m_pPyBase, "PluginMessage");
	if (!fn) return false;

	m_PyLib.PluginMessage(fn, id, data);

	return true;
}

Bool GePython::Message(Int32 id, void* data)
{
	if (!m_pPyBase || !m_PyLib.Initiated(m_pPyBase)) return false;

	_PyObject *fn = m_PyLib.GetObject(m_pPyBase, "message");
	if (!fn) return false;

	m_PyLib.Message(fn, id, data);

	return true;
}

Bool GePython::CallFunction(const String &name, GeData *ret)
{
	if (!m_pPyBase || !m_PyLib.Initiated(m_pPyBase)) return false;

	_PyObject *fn = m_PyLib.GetObject(m_pPyBase, name);
	if (!fn) return false;

	_PyObject *retval = m_PyLib.CallFunction(fn);
	if (!retval)
	{
		m_PyLib.ErrPrint();
		return false;
	}

	if (ret)
	{
		if (!m_PyLib.GetGeData(m_pPyBase, retval, *ret)) return false;
	}

	m_PyLib.DecRef(retval);

	return true;
}

Bool GePython::CallFunction(_PyObject *functionObject, GeData *ret)
{
	if (!m_pPyBase || !m_PyLib.Initiated(m_pPyBase) || !functionObject) return false;

	_PyObject *retval = m_PyLib.CallFunction(functionObject);
	if (!retval)
	{
		m_PyLib.ErrPrint();
		return false;
	}

	if (ret)
	{
		if (!m_PyLib.GetGeData(m_pPyBase, retval, *ret)) return false;
	}

	m_PyLib.DecRef(retval);

	return true;
}

Bool GePython::CallFunctionWithArguments(const String &name, GeData *arg1, GeData *arg2, GeData *arg3, GeData *arg4, GeData *ret)
{
	if (!m_pPyBase || !m_PyLib.Initiated(m_pPyBase)) return false;

	_PyObject *fn = m_PyLib.GetObject(m_pPyBase, name);
	if (!fn) return false;

	_PyObject *retval = m_PyLib.CallFunctionWithArguments(fn, arg1, arg2, arg3, arg4);
	if (!retval)
	{
		m_PyLib.ErrPrint();
		return false;
	}

	if (ret)
	{
		if (!m_PyLib.GetGeData(m_pPyBase, retval, *ret)) return false;
	}

	m_PyLib.DecRef(retval);

	return true;
}

Bool GePython::CallFunctionWithArguments(_PyObject *functionObject, GeData *arg1, GeData *arg2, GeData *arg3, GeData *arg4, GeData *ret)
{
	if (!m_pPyBase || !m_PyLib.Initiated(m_pPyBase)) return false;

	_PyObject *retval = m_PyLib.CallFunctionWithArguments(functionObject, arg1, arg2, arg3, arg4);
	if (!retval)
	{
		m_PyLib.ErrPrint();
		return false;
	}

	if (ret)
	{
		if (!m_PyLib.GetGeData(m_pPyBase, retval, *ret)) return false;
	}

	m_PyLib.DecRef(retval);

	return true;
}


Bool GePython::SetString(const String &name, const String &str)
{
	if (!m_pPyBase || !m_PyLib.Initiated(m_pPyBase)) return false;

	return m_PyLib.SetString(m_pPyBase, name, str);
}

Bool GePython::SetMatrix(const String &name, const Matrix &m)
{
	if (!m_pPyBase || !m_PyLib.Initiated(m_pPyBase)) return false;

	return m_PyLib.SetMatrix(m_pPyBase, name, m);
}

Bool GePython::SetVector(const String &name, const Vector &v)
{
	if (!m_pPyBase || !m_PyLib.Initiated(m_pPyBase)) return false;

	return m_PyLib.SetVector(m_pPyBase, name, v);
}

Bool GePython::SetFloat(const String &name, Float v)
{
	if (!m_pPyBase || !m_PyLib.Initiated(m_pPyBase)) return false;

	return m_PyLib.SetFloat(m_pPyBase, name, v);
}

Bool GePython::SetNode(const String &name, const GeListNode *node)
{
	if (!m_pPyBase || !m_PyLib.Initiated(m_pPyBase)) return false;

	return m_PyLib.SetGeListNode(m_pPyBase, name, (GeListNode*)node, false);
}

Bool GePython::SetContainer(const String &name, const BaseContainer &bc)
{
	if (!m_pPyBase || !m_PyLib.Initiated(m_pPyBase)) return false;

	return m_PyLib.SetContainer(m_pPyBase, name, bc);
}

Bool GePython::SetCustom(const String &name, const String &type, const GeData &v)
{
	if (!m_pPyBase || !m_PyLib.Initiated(m_pPyBase)) return false;

	return m_PyLib.SetCustom(m_pPyBase, name, type, v);
}

Bool GePython::SetInt32(const String &name, Int32 v)
{
	if (!m_pPyBase || !m_PyLib.Initiated(m_pPyBase)) return false;

	return m_PyLib.SetInt32(m_pPyBase, name, v);
}

Bool GePython::SetThread(const String &name, BaseThread *bt)
{
	if (!m_pPyBase || !m_PyLib.Initiated(m_pPyBase)) return false;

	return m_PyLib.SetBaseThread(m_pPyBase, name, bt);
}


Bool GePython::GetContainer(const String &name, BaseContainer &bc)
{
	if (!m_pPyBase || !m_PyLib.Initiated(m_pPyBase)) return false;

	_PyObject *op = m_PyLib.GetObject(m_pPyBase, name);
	if (!op) return false;

	return m_PyLib.GetContainer(m_pPyBase, op, bc);
}

Bool GePython::GetInt32(const String &name, Int32 &v)
{
	if (!m_pPyBase || !m_PyLib.Initiated(m_pPyBase)) return false;

	_PyObject *op = m_PyLib.GetObject(m_pPyBase, name);
	if (!op) return false;

	return m_PyLib.GetInt32(m_pPyBase, op, v);
}

Bool GePython::GetMatrix(const String &name, Matrix &m)
{
	if (!m_pPyBase || !m_PyLib.Initiated(m_pPyBase)) return false;

	_PyObject *op = m_PyLib.GetObject(m_pPyBase, name);
	if (!op) return false;

	return m_PyLib.GetMatrix(m_pPyBase, op, m);
}

Bool GePython::GetNode(const String &name, GeListNode *&n)
{
	if (!m_pPyBase || !m_PyLib.Initiated(m_pPyBase)) return false;

	_PyObject *op = m_PyLib.GetObject(m_pPyBase, name);
	if (!op) return false;

	return m_PyLib.GetGeListNode(m_pPyBase, op, n);
}

//////////////////////////////////////////////////////////////////////////

Bool PythonLibrary::Execute(const String &code) { PyLibCallR(false, pyExecute)(code); }
PythonBase *PythonLibrary::Alloc() { PyLibCallR(nullptr, pyAlloc)(); }
void PythonLibrary::Free(PythonBase *&base) { PyLibCall(pyFree)(base); }

//////////////////////////////////////////////////////////////////////////

Bool PythonLibrary::Run(const String &code, PythonBase *base, const String &name_handler, XPYCOMPILERINPUT flag) { PyLibCallR(false, pyRun)(code, base, name_handler, flag); }

Bool PythonLibrary::Initiated(PythonBase *base) { PyLibCallR(false, pyInitiated)(base); }

Bool PythonLibrary::SetGeData(PythonBase *base, const String &name, const GeData &dat) { PyLibCallR(false, pySetGeData)(base, name, dat); }
Bool PythonLibrary::SetBaseThread(PythonBase *base, const String &name, BaseThread *bt) { PyLibCallR(false, pySetBaseThread)(base, name, bt); }
Bool PythonLibrary::SetGeResource(PythonBase *base, const String &name, GeResource *res, Bool owner) { PyLibCallR(false, pySetGeResource)(base, name, res, owner); }
Bool PythonLibrary::SetGeListNode(PythonBase *base, const String &name, GeListNode *obj, Bool owner) { PyLibCallR(false, pySetGeListNode)(base, name, obj, owner); }
Bool PythonLibrary::SetPyObject(PythonBase *base, const String &name, _PyObject *op) { PyLibCallR(false, pySetPyObject)(base, name, op); }
Bool PythonLibrary::SetNone(PythonBase *base, const String &name) { PyLibCallR(false, pySetNone)(base, name); }
Bool PythonLibrary::SetString(PythonBase *base, const String &name, const String &value) { PyLibCallR(false, pySetString)(base, name, value); }
Bool PythonLibrary::SetInt32(PythonBase *base, const String &name, const Int32 value) { PyLibCallR(false, pySetInt32)(base, name, value); }
Bool PythonLibrary::SetVector(PythonBase *base, const String &name, const Vector &value) { PyLibCallR(false, pySetVector)(base, name, value); }
Bool PythonLibrary::SetMatrix(PythonBase *base, const String &name, const Matrix &value) { PyLibCallR(false, pySetMatrix)(base, name, value); }
Bool PythonLibrary::SetInt64(PythonBase *base, const String &name, Int64 value) { PyLibCallR(false, pySetInt64)(base, name, value); }
Bool PythonLibrary::SetFloat(PythonBase *base, const String &name, Float value) { PyLibCallR(false, pySetFloat)(base, name, value); }
Bool PythonLibrary::SetContainer(PythonBase *base, const String &name, const BaseContainer &value) { PyLibCallR(false, pySetContainer)(base, name, value); }
Bool PythonLibrary::SetCustom(PythonBase *base, const String &name, const String &type, const GeData &value) { PyLibCallR(false, pySetCustom)(base, name, type, value); }

Bool PythonLibrary::FindRef(PythonBase *base, const String &name) { PyLibCallR(false, pyFindRef)(base, name); }
_PyObject *PythonLibrary::GetObject(PythonBase *base, const String &name) { PyLibCallR(nullptr, pyGetObject)(base, name); }
Bool PythonLibrary::GetName(_PyObject *op, String &name) { PyLibCallR(false, pyGetName)(op, name); }

Bool PythonLibrary::GetGeData(PythonBase *base, _PyObject *op, GeData &dat) { PyLibCallR(false, pyGetGeData)(base, op, dat); }
Bool PythonLibrary::GetBaseThread(PythonBase *base, _PyObject *op, BaseThread *&bt) { PyLibCallR(false, pyGetBaseThread)(base, op, bt); }
Bool PythonLibrary::GetGeResource(PythonBase *base, _PyObject *op, GeResource *&res) { PyLibCallR(false, pyGetGeResource)(base, op, res); }
Bool PythonLibrary::GetGeListNode(PythonBase *base, _PyObject *op, GeListNode *&obj) { PyLibCallR(false, pyGetGeListNode)(base, op, obj); }
Bool PythonLibrary::GetString(PythonBase *base, _PyObject *op, String &value) { PyLibCallR(false, pyGetString)(base, op, value); }
Bool PythonLibrary::GetInt32(PythonBase *base, _PyObject *op, Int32 &value) { PyLibCallR(false, pyGetInt32)(base, op, value); }
Bool PythonLibrary::GetVector(PythonBase *base, _PyObject *op, Vector &value) { PyLibCallR(false, pyGetVector)(base, op, value); }
Bool PythonLibrary::GetMatrix(PythonBase *base, _PyObject *op, Matrix &value) { PyLibCallR(false, pyGetMatrix)(base, op, value); }
Bool PythonLibrary::GetInt64(PythonBase *base, _PyObject *op, Int64 &value) { PyLibCallR(false, pyGetInt64)(base, op, value); }
Bool PythonLibrary::GetFloat(PythonBase *base, _PyObject *op, Float &value) { PyLibCallR(false, pyGetFloat)(base, op, value); }
Bool PythonLibrary::GetContainer(PythonBase *base, _PyObject *op, BaseContainer &value) { PyLibCallR(false, pyGetContainer)(base, op, value); }
Bool PythonLibrary::GetCustom(PythonBase *base, _PyObject *op, const String &type, GeData &value) { PyLibCallR(false, pyGetCustom)(base, op, type, value); }
Bool PythonLibrary::ImportModule(PythonBase *base, const String &name) { PyLibCallR(false, pyImportModule)(base, name); }

Bool PythonLibrary::FunctionCheck(_PyObject *op) { PyLibCallR(false, pyFunctionCheck)(op); }
void PythonLibrary::ErrSetString(_PyObject *err, const String &msg) { PyLibCall(pyErrSetString)(err, msg); }
void PythonLibrary::ErrPrint() { PyLibCall(pyErrPrint)(); }
Bool PythonLibrary::pyExecuteFile(const Filename &fn) { PyLibCallR(false, pyExecuteFile)(fn); }
void PythonLibrary::pyGetLastError(Bool restore, Int32 *line, Int32 *cols, String *err) { PyLibCall(pyGetLastError)(restore, line, cols, err); }
void PythonLibrary::DecRef(_PyObject *op) { PyLibCall(pyDecRef)(op); }
void PythonLibrary::IncRef(_PyObject *op) { PyLibCall(pyIncRef)(op); }
PythonGIL *PythonLibrary::AllocGIL() { PyLibCallR(nullptr, pyAllocGIL)(); }
void PythonLibrary::FreeGIL(PythonGIL *&gil) { PyLibCall(pyFreeGIL)(gil); }
_PyObject *PythonLibrary::CallFunction(_PyObject *op) { PyLibCallR(nullptr, pyCallFunction)(op); }
_PyObject *PythonLibrary::CallFunctionWithArguments(_PyObject *op, GeData *arg1, GeData *arg2, GeData *arg3, GeData *arg4) { PyLibCallR(nullptr, pyCallFunctionArgs)(op, arg1, arg2, arg3, arg4); }
Bool PythonLibrary::PluginMessage(_PyObject* func, Int32 id, void* data) { PyLibCallR(false, pyPluginMessage)(func, id, data); }
Bool PythonLibrary::Message(_PyObject* func, Int32 id, void* data) { PyLibCallR(false, pyMessage)(func, id, data); }
_PyObject *PythonLibrary::ObjectNew(_PyObject *type) { PyLibCallR(nullptr, pyObjectNew)(type); }
void PythonLibrary::ObjectDel(_PyObject *&op) { PyLibCall(pyObjectDel)(op); }
_PyObject *PythonLibrary::GetModule(const String &name) { PyLibCallR(nullptr, pyGetModule)(name); }
Bool PythonLibrary::CheckSyntax(const String &code, Int32 *line, Int32 *cols, String *err) { PyLibCallR(false, pyCheckSyntax)(code, line, cols, err); }

Bool PythonLibrary::InitType(const String &name, PythonTypeBase *tybase, PythonMethodData *methods, const String &help) { PyLibCallR(false, pyInitType)(name, tybase, methods, help); }
Bool PythonLibrary::InitModule(const String &name, PythonMethodData *methods, const String &help) { PyLibCallR(false, pyInitModule)(name, methods, help); }
Bool PythonLibrary::InitConstant(_PyObject *op, const String &name, Int32 value) { PyLibCallR(false, pyInitConstant)(op, name, value); }
Bool PythonLibrary::InitStringConstant(_PyObject *op, const String &name, const String &value) { PyLibCallR(false, pyInitStringConstant)(op, name, value); }
PythonTypeBase *PythonLibrary::GetTypeBase(_PyObject *op) { PyLibCallR(nullptr, pyGetTypeBase)(op); }

_PyObject *PythonLibrary::ReturnPyInt32(Int32 value) { PyLibCallR(nullptr, pyReturnPyInt32)(value); }
_PyObject *PythonLibrary::ReturnPyInt(Int value) { PyLibCallR(nullptr, pyReturnPyInt)(value); }
_PyObject *PythonLibrary::ReturnPyUInt(UInt value) { PyLibCallR(nullptr, pyReturnPyUInt)(value); }
_PyObject *PythonLibrary::ReturnPyInt64(Int64 value) { PyLibCallR(nullptr, pyReturnPyInt64)(value); }
_PyObject *PythonLibrary::ReturnPyBool(Bool value) { PyLibCallR(nullptr, pyReturnPyBool)(value); }
_PyObject *PythonLibrary::ReturnPyFloat(Float value) { PyLibCallR(nullptr, pyReturnPyFloat)(value); }
_PyObject *PythonLibrary::ReturnPyString(const String &value) { PyLibCallR(nullptr, pyReturnPyString)(value); }
_PyObject *PythonLibrary::ReturnPyContainer(const BaseContainer &value) { PyLibCallR(nullptr, pyReturnPyContainer)(value); }
_PyObject *PythonLibrary::ReturnPyTime(const BaseTime &value) { PyLibCallR(nullptr, pyReturnPyTime)(value); }
_PyObject *PythonLibrary::ReturnPyVector(const Vector &value) { PyLibCallR(nullptr, pyReturnPyVector)(value); }
_PyObject *PythonLibrary::ReturnPyMatrix(const Matrix &value) { PyLibCallR(nullptr, pyReturnPyMatrix)(value); }
_PyObject *PythonLibrary::ReturnPyGeData(const GeData &value) { PyLibCallR(nullptr, pyReturnPyGeData)(value); }
_PyObject *PythonLibrary::ReturnPyVoidPtr(void *value) { PyLibCallR(nullptr, pyReturnPyVoidPtr)(value); }
_PyObject *PythonLibrary::ReturnPyRangeErr(const String &str) { PyLibCallR(nullptr, pyReturnPyRangeErr)(str); }
_PyObject *PythonLibrary::ReturnPyNone() { PyLibCallR(nullptr, pyReturnPyNone)(); }
_PyObject *PythonLibrary::ReturnPyTRUE() { PyLibCallR(nullptr, pyReturnPyTRUE)(); }
_PyObject *PythonLibrary::ReturnPyFALSE() { PyLibCallR(nullptr, pyReturnPyFALSE)(); }
_PyObject *PythonLibrary::ReturnPyNOTIMPLEMENTED() { PyLibCallR(nullptr, pyReturnPyNOTIMPLEMENTED)(); }
_PyObject *PythonLibrary::ReturnGeListNode(const GeListNode *op, Bool owner) { PyLibCallR(nullptr, pyReturnGeListNode)(op, owner); }
_PyObject *PythonLibrary::ReturnPyCustom(const String &type, const GeData &value) { PyLibCallR(nullptr, pyReturnPyCustom)(type, value); }

Bool PythonLibrary::ParseTupleAndKeywords(_PyObject *args, _PyObject *keywords, const Char *format, const Char *kwlist[], ...)
{
	va_list va;

	PyLibrary *lib = CheckPyLib(LIBOFFSET(PyLibrary, pyParseTupleAndKeywords));
	if (!lib || !lib->pyParseTupleAndKeywords) return false;

	va_start(va, kwlist);

	Bool ret = lib->pyParseTupleAndKeywords(args, keywords, format, kwlist, &va);

	va_end(va);

	return ret;
}

Bool PythonLibrary::ParseTupleAndKeywords(_PyObject *args, _PyObject *keywords, const Char *format, const Char *kwlist[], va_list *p_va) { PyLibCallR(false, pyParseTupleAndKeywords)(args, keywords, format, kwlist, p_va); }
String PythonLibrary::GetDocString(const String &code) { PyLibCallR(String(), pyDocString)(code); }
String PythonLibrary::GetDocStringMeta(const String &doc, SCRIPTMETA info, Bool english) { PyLibCallR(String(), pyDocStringMeta)(doc, info, english); }
//////////////////////////////////////////////////////////////////////////

PyTuple* PyTuple::Alloc(Int32 s)
{
	PyLibrary *lib = CheckPyLib(LIBOFFSET(PyLibrary, pyAllocTuple));
	if (!lib || !lib->pyAllocTuple) return nullptr;

	return lib->pyAllocTuple(s);
}

void PyTuple::Free(PyTuple*& p)
{
	PyLibCall(pyFreeTuple)(p);
}

Bool PyTuple::AppendBool(Bool p) { PyPyRCall(pyTupleAppendBool, CPyTuple_Wrapper, false)(p); }
Bool PyTuple::AppendInt32(Int32 p) { PyPyRCall(pyTupleAppendInt32, CPyTuple_Wrapper, false)(p); }
Bool PyTuple::AppendFloat(Float p) { PyPyRCall(pyTupleAppendFloat, CPyTuple_Wrapper, false)(p); }
Bool PyTuple::AppendChar(Char p) { PyPyRCall(pyTupleAppendChar, CPyTuple_Wrapper, false)(p); }
Bool PyTuple::AppendNone() { PyPyRCall(pyTupleAppendNone, CPyTuple_Wrapper, false)(); }
Bool PyTuple::AppendVector(const Vector &p) { PyPyRCall(pyTupleAppendVector, CPyTuple_Wrapper, false)(p); }
Bool PyTuple::AppendMatrix(const Matrix &p) { PyPyRCall(pyTupleAppendMatrix, CPyTuple_Wrapper, false)(p); }
Bool PyTuple::AppendString(const String &p) { PyPyRCall(pyTupleAppendString, CPyTuple_Wrapper, false)(p); }
Bool PyTuple::AppendGeData(const GeData &p) { PyPyRCall(pyTupleAppendGeData, CPyTuple_Wrapper, false)(p); }
Bool PyTuple::AppendDescID(const DescID &id) { PyPyRCall(pyTupleAppendDescID, CPyTuple_Wrapper, false)(id); }
Bool PyTuple::AppendPyObject(_PyObject *op) { PyLibCallR(false, pyTupleAppendPyObject)(this, op); }
Bool PyTuple::AppendBaseTime(const BaseTime &p) { PyPyRCall(pyTupleAppendBaseTime, CPyTuple_Wrapper, false)(p); }
Bool PyTuple::AppendBitmap(BaseBitmap *p, Bool owner) { PyPyRCall(pyTupleAppendBitmap, CPyTuple_Wrapper, false)(p, owner); }
Bool PyTuple::AppendObject(GeListNode *p, Bool owner) {  PyPyRCall(pyTupleAppendObject, CPyTuple_Wrapper, false)(p, owner); }
Bool PyTuple::AppendBaseContainer(const BaseContainer &p) { PyPyRCall(pyTupleAppendBaseContainer, CPyTuple_Wrapper, false)(p); }

PyList* PyList::Alloc()
{
	PyLibrary *lib = CheckPyLib(LIBOFFSET(PyLibrary, pyAllocList));
	if (!lib || !lib->pyAllocList) return nullptr;

	return lib->pyAllocList();
}

void PyList::Free(PyList*& p)
{
	PyLibCall(pyFreeList)(p);
}

Bool PyList::AppendBool(Bool p) { PyPyRCall(pyListAppendBool, CPyList_Wrapper, false)(p); }
Bool PyList::AppendInt32(Int32 p) { PyPyRCall(pyListAppendInt32, CPyList_Wrapper, false)(p); }
Bool PyList::AppendFloat(Float p) { PyPyRCall(pyListAppendFloat, CPyList_Wrapper, false)(p); }
Bool PyList::AppendChar(Char p) { PyPyRCall(pyListAppendChar, CPyList_Wrapper, false)(p); }
Bool PyList::AppendNone() { PyPyRCall(pyListAppendNone, CPyList_Wrapper, false)(); }
Bool PyList::AppendVector(const Vector &p) { PyPyRCall(pyListAppendVector, CPyList_Wrapper, false)(p); }
Bool PyList::AppendMatrix(const Matrix &p) { PyPyRCall(pyListAppendMatrix, CPyList_Wrapper, false)(p); }
Bool PyList::AppendString(const String &p) { PyPyRCall(pyListAppendString, CPyList_Wrapper, false)(p); }
Bool PyList::AppendGeData(const GeData &p) { PyPyRCall(pyListAppendGeData, CPyList_Wrapper, false)(p); }
Bool PyList::AppendDescID(const DescID &id) { PyPyRCall(pyListAppendDescID, CPyList_Wrapper, false)(id); }
Bool PyList::AppendPyObject(_PyObject *op) { PyLibCallR(false, pyListAppendPyObject)(this, op); }
Bool PyList::AppendBaseTime(const BaseTime &p) { PyPyRCall(pyListAppendBaseTime, CPyList_Wrapper, false)(p); }
Bool PyList::AppendBitmap(BaseBitmap *p, Bool owner) { PyPyRCall(pyListAppendBitmap, CPyList_Wrapper, false)(p, owner); }
Bool PyList::AppendObject(GeListNode *p, Bool owner) {  PyPyRCall(pyListAppendObject, CPyList_Wrapper, false)(p, owner); }
Bool PyList::AppendBaseContainer(const BaseContainer &p) { PyPyRCall(pyListAppendBaseContainer, CPyList_Wrapper, false)(p); }
Bool PyList::AppendDict(PyDict& dict) { PyLibCallR(false, pyListAppendDict)(this, dict); }

PyDict* PyDict::Alloc()
{
	PyLibrary *lib = CheckPyLib(LIBOFFSET(PyLibrary, pyAllocDict));
	if (!lib || !lib->pyAllocDict) return nullptr;

	return lib->pyAllocDict();
}

void PyDict::Free(PyDict*& p)
{
	PyLibCall(pyFreeDict)(p);
}

Bool PyDict::AppendBool(const Char* name, Bool p) { PyPyRCall(pyDictAppendBool, CPyDict_Wrapper, false)(name, p); }
Bool PyDict::AppendInt32(const Char* name, Int32 p) { PyPyRCall(pyDictAppendInt32, CPyDict_Wrapper, false)(name, p); }
Bool PyDict::AppendFloat(const Char* name, Float p) { PyPyRCall(pyDictAppendFloat, CPyDict_Wrapper, false)(name, p); }
Bool PyDict::AppendChar(const Char* name, Char p) { PyPyRCall(pyDictAppendChar, CPyDict_Wrapper, false)(name, p); }
Bool PyDict::AppendNone(const Char* name) { PyPyRCall(pyDictAppendNone, CPyDict_Wrapper, false)(name); }
Bool PyDict::AppendVector(const Char* name, const Vector &p) { PyPyRCall(pyDictAppendVector, CPyDict_Wrapper, false)(name, p); }
Bool PyDict::AppendMatrix(const Char* name, const Matrix &p) { PyPyRCall(pyDictAppendMatrix, CPyDict_Wrapper, false)(name, p); }
Bool PyDict::AppendString(const Char* name, const String &p) { PyPyRCall(pyDictAppendString, CPyDict_Wrapper, false)(name, p); }
Bool PyDict::AppendGeData(const Char* name, const GeData &p) { PyPyRCall(pyDictAppendGeData, CPyDict_Wrapper, false)(name, p); }
Bool PyDict::AppendDescID(const Char* name, const DescID &id) { PyPyRCall(pyDictAppendDescID, CPyDict_Wrapper, false)(name, id); }
Bool PyDict::AppendPyObject(const Char* name, _PyObject *op) { PyLibCallR(false, pyDictAppendPyObject)(this, name, op); }
Bool PyDict::AppendBaseTime(const Char* name, const BaseTime &p) { PyPyRCall(pyDictAppendBaseTime, CPyDict_Wrapper, false)(name, p); }
Bool PyDict::AppendBitmap(const Char* name, BaseBitmap *p, Bool owner) { PyPyRCall(pyDictAppendBitmap, CPyDict_Wrapper, false)(name, p, owner); }
Bool PyDict::AppendObject(const Char* name, GeListNode *p, Bool owner) {  PyPyRCall(pyDictAppendObject, CPyDict_Wrapper, false)(name, p, owner); }
Bool PyDict::AppendBaseContainer(const Char* name, const BaseContainer &p) { PyPyRCall(pyDictAppendBaseContainer, CPyDict_Wrapper, false)(name, p); }
Bool PyDict::AppendList(const Char* name, PyList& list) { PyLibCallR(false, pyDictAppendList)(this, name, list); }

//////////////////////////////////////////////////////////////////////////

void PythonMethodData::Init(const String &name, PyFn fn, PYFN_FLAGS flags, const String &help)
{
	DeleteMem(m_pName);
	DeleteMem(m_pHelp);

	m_pFunction = fn;
	m_Flags = flags;

	if (name.IsPopulated())
	{
		Int32 l = name.GetCStringLen(STRINGENCODING::UTF8)+1;
		if (l > 1)
		{
			iferr (m_pName = NewMemClear(Char, l))
				return;
			name.GetCString(m_pName, l, STRINGENCODING::UTF8);
		}
	}

	if (help.IsPopulated())
	{
		Int32 l = help.GetCStringLen(STRINGENCODING::UTF8)+1;
		if (l > 1)
		{
			iferr (m_pHelp = NewMemClear(Char, l))
				return;
			help.GetCString(m_pHelp, l, STRINGENCODING::UTF8);
		}
	}
}

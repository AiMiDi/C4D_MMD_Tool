#include "cpython_ref.h"
#include "cpython.h"

MAXON_DEPENDENCY_WEAK("cpython_ref.h");
MAXON_DEPENDENCY_WEAK("cpython.h");

namespace maxon
{
namespace py
{

CPyRef CPyInterface::CreateRef(const CPythonLibraryInterface* lib, REFTYPE refType, NativePyObject* pyObject)
{
	iferr (auto res = lib->GetCPyRefClass().Create())
		return {};
	res.Init(lib, refType, pyObject);
	return res;
}

CPyConstRef CPyInterface::CreateConstRef(const CPythonLibraryInterface* lib, REFTYPE refType, NativePyObject* pyObject)
{
	iferr (auto res = lib->GetCPyRefClass().Create())
		return {};
	res.Init(lib, refType, pyObject);
	return Cast<CPyConstRef>(res);
}

CPyTempRef CPyInterface::CreateTempRef(const CPythonLibraryInterface* lib, NativePyObject* pyObject)
{
	iferr (auto res = lib->GetCPyRefClass().Create())
		return {};
	res.Init(lib, REFTYPE::PRIVATE_SHORTTERM_BORROWED, pyObject);
	return CPyTempRef(res);
}

CPyTypeRef CPyTypeInterface::CreateTypeRef(const CPythonLibraryInterface* lib, REFTYPE refType, NativePyObject* pyObject)
{
	iferr (auto res = lib->GetCPyTypeRefClass().Create())
		return {};
	res.Init(lib, refType, pyObject);
	return res;
}

CPyTypeConstRef CPyTypeInterface::CreateTypeConstRef(const CPythonLibraryInterface* lib, REFTYPE refType, NativePyObject* pyObject)
{
	iferr (auto res = lib->GetCPyTypeRefClass().Create())
		return {};
	res.Init(lib, refType, pyObject);
	return CPyTypeConstRef(res);
}

CPyFrameRef CPyFrameInterface::CreateFrameRef(const CPythonLibraryInterface* lib, REFTYPE refType, NativePyObject* pyObject)
{
	iferr (auto res = lib->GetCPyFrameRefClass().Create())
		return {};
	res.Init(lib, refType, pyObject);
	return res;
}

CPyTracebackRef CPyTracebackInterface::CreateTracebackRef(const CPythonLibraryInterface* lib, REFTYPE refType, NativePyObject* pyObject)
{
	iferr (auto res = lib->GetCPyTracebackRefClass().Create())
		return {};
	res.Init(lib, refType, pyObject);
	return res;
}

CPyCodeRef CPyCodeInterface::CreateCodeRef(const CPythonLibraryInterface* lib, REFTYPE refType, NativePyObject* pyObject)
{
	iferr (auto res = lib->GetCPyCodeRefClass().Create())
		return {};
	res.Init(lib, refType, pyObject);
	return res;
}

MPyClassRef MPyClassInterface::CreateClassRef(const CPythonLibraryInterface* lib, REFTYPE refType, NativePyObject* pyObject)
{
	iferr (auto res = lib->GetMPyClassRefClass().Create())
		return {};
	res.Init(lib, refType, pyObject);
	return res;
}

MPyMemberRef MPyMemberInterface::CreateMemberRef(const CPythonLibraryInterface* lib, REFTYPE refType, NativePyObject* pyObject)
{
	iferr (auto res = lib->GetMPyMemberRefClass().Create())
		return {};
	res.Init(lib, refType, pyObject);
	return res;
}

MPyDataTypeRef MPyDataTypeInterface::CreateDataTypeRef(const CPythonLibraryInterface* lib, REFTYPE refType, NativePyObject* pyObject)
{
	iferr (auto res = lib->GetMPyDataTypeRefClass().Create())
		return {};
	res.Init(lib, refType, pyObject);
	return res;
}

MPyFunctionRef MPyFunctionInterface::CreateFunctionRef(const CPythonLibraryInterface* lib, REFTYPE refType, NativePyObject* pyObject)
{
	iferr (auto res = lib->GetMPyFunctionRefClass().Create())
		return {};
	res.Init(lib, refType, pyObject);
	return res;
}

MPyDataRef MPyDataInterface::CreateDataRef(const CPythonLibraryInterface* lib, REFTYPE refType, NativePyObject* pyObject)
{
	iferr (auto res = lib->GetMPyDataRefClass().Create())
		return {};

	res.Init(lib, refType, pyObject);
	return res;
}

MPyCallerContextRef MPyCallerContextInterface::CreateCallerContextRef(const CPythonLibraryInterface* lib, REFTYPE refType, NativePyObject* pyObject)
{
	iferr (auto res = lib->GetMPyCallerContextRefClass().Create())
		return {};
	res.Init(lib, refType, pyObject);
	return res;
}


} // namespace py

} // namespace maxon

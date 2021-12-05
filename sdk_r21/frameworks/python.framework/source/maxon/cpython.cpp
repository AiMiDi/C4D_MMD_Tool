#define MAXON_DEPENDENCY_ENABLE

#include "cpython.h"
#include "cpython27_raw.h"

MAXON_DEPENDENCY_WEAK("cpython.h");
MAXON_DEPENDENCY_WEAK("cpython27_raw.h");

namespace maxon
{

const Id ID_LOGGER_PYTHON = Id("net.maxon.logger.python");

void PrivateCPyRefDiagnosticOutput(MAXON_SOURCE_LOCATION_DECLARATION, const Char* refName, const py::CPyRef& ref)
{
	String output;
	auto* lib = const_cast<py::CPythonLibraryInterface*>(ref.GetLibrary());
	if (lib == nullptr)
	{
		output = "lib is nullptr"_s;
	}
	else
	{
		auto str = lib->CPyObject_Str(ref);
		if (str == nullptr)
		{
			lib->CPyErr_Print();
			return;
		}

		iferr (output = lib->CPyString_AsString(str))
		{
			lib->CPyErr_Print();
			return;
		}

		iferr (auto typeStr = lib->CPyType_GetName(ref.GetTypeRef()))
		{
			lib->CPyErr_Print();
			return;
		}

		output = FormatString("@ (@)", output, typeStr);
	}

	_ConsoleOutput(maxon::OUTPUT::DIAGNOSTIC, FormatString("Ref info (varname=@): @"_s, refName, output), allocLocation.GetLine(), allocLocation.GetFile());
}

void _Python27Output(maxon::TARGETAUDIENCE audience, const Char* str, Int line, const Char* file, maxon::WRITEMETA meta)
{
    MAXON_WARN_MUTE_UNUSED maxon::Loggers::Get(maxon::ID_LOGGER_PYTHON).Write(audience, String(str), maxon::SourceLocation(file, line), meta);
}

void _Python27Output(maxon::TARGETAUDIENCE audience, const maxon::String& str, Int line, const Char* file)
{
	maxon::BaseArray<Char> buf;

	iferr (str.GetCStringAppendArray(buf, maxon::GetUtf8DefaultEncoder()))
	{
		DebugStop();
		return;
	}
	iferr (buf.Append(0))
	{
		DebugStop();
		return;
	}
	_Python27Output(audience, buf.GetFirst(), line, file);
}

void _Python27Output(maxon::TARGETAUDIENCE audience, maxon::StringProxy* proxy, Int line, const Char* file)
{
	if (proxy)
	{
		_Python27Output(audience, proxy->str, line, file);
		DeleteObj(proxy);
	}
	else
	{
		_Python27Output(maxon::TARGETAUDIENCE::ALL, "Console output failed", line, file, maxon::WRITEMETA::CRITICAL);
	}
}


static py::CPythonLibraryRef g_lib; 

// stub function is used to avoid a circular reference dependency
maxon::py::CPythonLibraryRef PrivateExtractCPythonLibrary27(py::NativePyObject* self)
{
	// g_lib is protected by the GIL if called within the Python context
	// TODO: (Seb) Extract library reference from self pointer instead
	if (!g_lib)
	{
		auto vm = MAXON_CPYTHONVM();
		g_lib = Cast<py::CPythonLibraryRef>(vm.GetLibraryRef());
	}
	return g_lib;
}

maxon::Error PrivateRegisterCPythonFunc(const maxon::Char* name, maxon::py::NativePyCFunctionWithKeywords underlyingFunc27, maxon::BaseArray<maxon::NativePyCFunctionTable>& functions27)
{
	iferr (functions27.Append({ name, underlyingFunc27 }))
		return maxon::UnknownError(MAXON_SOURCE_LOCATION, FormatString("failed to register c-function @", name));

	return {};
}

namespace py
{

} // namespace py

static void FreePythonLibRef()
{
	g_lib = nullptr;
}

MAXON_INITIALIZATION(nullptr, FreePythonLibRef);

} // namespace maxon 

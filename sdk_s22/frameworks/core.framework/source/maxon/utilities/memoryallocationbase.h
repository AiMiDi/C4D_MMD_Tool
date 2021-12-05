#ifndef MEMORYALLOCATIONBASE_H__
#define MEMORYALLOCATIONBASE_H__

#ifndef APIBASE_H__
	#error "Do not include this file directly"
#endif

/// @file
/// Source locations

namespace maxon
{

/// @addtogroup SYSTEM
/// @{

class SourceLocation
{
public:
	const Char*	file = nullptr;
	Int	lineAndFlags = 0;
	const Char*	name = nullptr;

	SourceLocation() = default;
	
	// Using a constexpr constructor here allows the compiler to omit boilerplate code for templates which are never used.
	constexpr SourceLocation(const Char* f, Int l, const Char* objectName = nullptr) : file(f), lineAndFlags(l), name(objectName)
	{
	}
	
	/// Returns the source file as C string (or a nullptr).
	const Char*	GetFile() const { return file; }
	/// Returns the source file line number (or 0).
	Int	GetLine() const { return lineAndFlags & LINE_NUMBER_MASK; }
	Bool	HasFrameInfo() const { return (lineAndFlags & FRAME_INFO_FLAG) != 0; }

	static const Int FRAME_INFO_FLAG = 0x1000000;
	static const Int LINE_NUMBER_MASK = 0xffffff;	// struct carries extended debug info if FRAME_INFO_FLAG is set

	using SourceLocationMarker = Int; // TODO: (Ole) remove this when possible (currently used for a SFINAE hack that should be obsolete when variadic templates are supported)

	static const SourceLocation& NullValue()
	{
		return GetZeroRef<SourceLocation>();
	}

	inline Bool operator ==(const SourceLocation& b) const { return file == b.file && lineAndFlags == b.lineAndFlags; }
	inline Bool operator < (const SourceLocation& b) const { return file < b.file && lineAndFlags < b.lineAndFlags; }
	MAXON_OPERATOR_COMPARISON(SourceLocation);

	UInt GetHashCode() const
	{
		DebugStop();
		return 0;
	}
};

//----------------------------------------------------------------------------------------
/// MAXON_SOURCE_LOCATION creates a SourceLocation object for the current file location that can be
/// passed to a memory allocation function (or something similar). This will later be used to track the
/// origin of memory leaks.
/// You could as well write SourceLocation(__FILE__, __LINE__) in your code, but the purpose of this
/// macro is to be able to easily modify the inner workings of the memory leak detector without having to
/// modify all callers.
//----------------------------------------------------------------------------------------
#define	MAXON_SOURCE_LOCATION							maxon::SourceLocation(__FILE__, __LINE__)

//----------------------------------------------------------------------------------------
/// MAXON_SOURCE_LOCATION_DECLARATION is a helper macro for function declarations that expect information
/// about the origin of a memory allocation. Again the purpose of the macro is to be able to easily modify
/// the inner workings of memory the leak detector without having to modify  all callers.
//----------------------------------------------------------------------------------------
#define	MAXON_SOURCE_LOCATION_DECLARATION	const maxon::SourceLocation& allocLocation

//----------------------------------------------------------------------------------------
/// MAXON_SOURCE_LOCATION_FORWARD is used to forward information about the origin of a memory allocation
/// to other functions with a MAXON_SOURCE_LOCATION_DECLARATION.  The purpose of the macro is to be able
/// to easily modify the inner workings of memory the leak detector without having to modify  all callers.
//----------------------------------------------------------------------------------------
#define MAXON_SOURCE_LOCATION_FORWARD			allocLocation

//----------------------------------------------------------------------------------------
// All compilers implement __PRETTY_FUNCTION__ differently, but we can use it to deduct the type of T:
// See http://clang-developers.42468.n3.nabble.com/clang-and-gcc-implement-PRETTY-FUNCTION-differently-td3550386.html
//----------------------------------------------------------------------------------------
template <typename T> static MAXON_ATTRIBUTE_FORCE_INLINE const Char* PrivateGetClassName()
{
#ifdef MAXON_TARGET_DEBUG
	#ifdef MAXON_TARGET_WINDOWS
		// __FUNCSIG__ should return something like const Char* maxon::PrivateGetClassName<WhatEverTypename>()
		return __FUNCSIG__;
	#else
		// __PRETTY_FUNCTION__ should return something like const Char* maxon::PrivateGetClassName() [T = WhatEverTypename]
		return __PRETTY_FUNCTION__;
	#endif
#else
	return nullptr;
#endif
}

/// MAXON_SOURCE_LOCATION_NAME adds the allocated object name to the SourceLocation object
#define	MAXON_SOURCE_LOCATION_NAME(x)						maxon::SourceLocation(__FILE__, __LINE__, maxon::PrivateGetClassName<x>())



// Release optimization for SourceLocation (VS 2015 produces a compile error).
#if defined(MAXON_TARGET_RELEASE)

#undef MAXON_SOURCE_LOCATION
#undef MAXON_SOURCE_LOCATION_NAME

template <typename T, Int LN> struct SourceLocationOnly
{
	static const SourceLocation value;
};

template <typename T, Int LN> const SourceLocation SourceLocationOnly<T, LN>::value
{
	T{}.value,
	LN,
	nullptr
};

// Use a lambda to return the SourceLocation. In release the lambda will be removed by the compiler
// and the instantiated SourceLocation is built at compile time. Therefore only a pointer
// has to be loaded into a register.
#define MAXON_SOURCE_LOCATION \
	[]() -> const maxon::SourceLocation& \
	{ \
		struct SourceLocationFile \
		{ \
			const char* value = __FILE__; \
		}; \
		return maxon::SourceLocationOnly<SourceLocationFile, __LINE__>::value; \
	}()

#define MAXON_SOURCE_LOCATION_NAME(NAME) MAXON_SOURCE_LOCATION

#endif

/// @}

} // namespace maxon

#endif // MEMORYALLOCATIONBASE_H__

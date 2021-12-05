#ifndef UNITTEST_H__
#define UNITTEST_H__

#include "maxon/object.h"
#include "maxon/timer.h"
#include "maxon/datetime.h"

namespace maxon
{

/// @addtogroup SYSTEM
/// @{

//----------------------------------------------------------------------------------------
/// UnitTest error.
//----------------------------------------------------------------------------------------
class UnitTestErrorInterface : MAXON_INTERFACE_BASES(ErrorInterface)
{
	MAXON_INTERFACE(UnitTestErrorInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.interface.unittesterror");
};

//----------------------------------------------------------------------------------------
/// Class for Unit tests.
/// All available interfaces and implementations should get a unit test to verify the correct function of the interface.
/// A unit test should check the positive and negative return values. E.g. also if giving wrong arguments to functions return the expected error code.
/// There are 3 different categories of tests right now. They can be registered with MAXON_COMPONENT_CLASS_REGISTER.
/// - Pure functional unit tests registered using the UnitTestClasses identifier. This kind of test should pass within seconds and test only if all functions operates correctly.
///   Those unit tests will be executed and checked for every build on the build server.
/// - Speed tests registered using the SpeedTestClasses identifier. This kind of test should pass within seconds.
/// - Long run Tests registered using the LongRunTestClasses identifier.
///
/// Here is an example how this class should be used:
/// @code
/// class UnitTestExample : public UnitTestComponent<UnitTestExample>
/// {
/// 	MAXON_COMPONENT();
///
/// public:
/// 	Result<void> Run()
/// 	{
/// 		Bool res;
///			// Do some operations here.
/// 		res = (5 == 5);
///			// Add the result to the database.
/// 		self.AddResult("Test 1"_s, res ? OK : UnitTestError(MAXON_SOURCE_LOCATION, "5 == 5"_s));
///			// Do more Tests.
///			return OK;
/// 	}
/// };
///
/// MAXON_COMPONENT_CLASS_REGISTER(UnitTestExample, UnitTestClasses, "net.maxon.unittest.example");
/// @endcode
//----------------------------------------------------------------------------------------
class UnitTestInterface : MAXON_INTERFACE_BASES(ObjectInterface)
{
	MAXON_INTERFACE(UnitTestInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.unittest");

public:
	//----------------------------------------------------------------------------------------
	/// This functions needs to be overridden with the implementation of the test code (see example).
	/// @return												OK on success. The result has no effect on other unit tests.
	/// 															If an error is returned it will be output (and added to the SQL database if enabled).
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Run();

	//----------------------------------------------------------------------------------------
	/// Checks if the Test has been cancelled from outside.
	/// @return												In case of true the test should exit immediately.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool IsCancelled() const;

	//----------------------------------------------------------------------------------------
	/// Cancel all UnitTestClasses.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void Cancel();

	//----------------------------------------------------------------------------------------
	/// Outputs the result to the console in a standard format. This format can be analyzed by tools.
	/// The output may be added to an SQL database.
	/// The example above prints these lines:
	/// @code
	///	Running unit test 9/16: net.maxon.unittest.example
	///	Unittest "net.maxon.unittest.example" OK: Test1
	/// @endcode
	/// @param[in] testName						A unique name within your test class. This is the identifier for later comparisons with previous builds.
	/// @param[in] state							The result of the test.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void AddResult(const String& testName, Result<void> state);

	//----------------------------------------------------------------------------------------
	/// Outputs the result with timing to the console in a standard format. Same AddResult() but with timing added.
	/// @param[in] testName						A unique name within your test class. This is the identifier for later comparisons with previous builds.
	/// @param[in] state							The result of the test.
	/// @param[in] duration						Duration of the test.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void AddTimingResult(const String& testName, Result<void> state, TimeValue duration);

	//----------------------------------------------------------------------------------------
	/// @cond INTERNAL
	/// This function is called when a test for a new buildid is started.
	/// This value is taken to enter the results into the mysql database.
	/// @param[in] buildId						New build id to simulate a new test with a different build (e.g. "Build12345").
	/// @param[in] dateTime						The date and time of the changelist for this build.
	/// @return												OK on success.
	/// @endcond
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool ReInitializeBuildId(const String& buildId, const UniversalDateTime& dateTime);
};

// include autogenerated headerfile here
#include "unittest1.hxx"

MAXON_REGISTRY(Class<UnitTestRef>, UnitTestClasses, "net.maxon.registry.unittestclasses");
MAXON_REGISTRY(Class<UnitTestRef>, SpeedTestClasses, "net.maxon.registry.speedtestclasses");
MAXON_REGISTRY(Class<UnitTestRef>, LongRunTestClasses, "net.maxon.registry.longruntestclasses");

MAXON_DECLARATION(Class<UnitTestRef>, UnitTestBaseClass, "net.maxon.class.unittestbase");

// include autogenerated headerfile here
#include "unittest2.hxx"


template <typename C, typename... INTERFACES> class UnitTestComponent : public Component<C, UnitTestInterface, INTERFACES...>
{
public:
	static Result<void> ConfigureClass(ClassInterface& cls)
	{
		return cls.AddComponents(UnitTestBaseClass());
	}
};

/// @}

#define MAXON_TEST_ASSERT_EQ(expected, ...) \
	for (auto testAssertValue = __VA_ARGS__; !(testAssertValue == expected);) \
		return UnitTestError(MAXON_SOURCE_LOCATION, FormatString("Test assertion failed. \"" #__VA_ARGS__  "\" was @, expected @."_s, testAssertValue, expected))

#define MAXON_TEST_ASSERT_LT(expected, ...) \
	for (auto testAssertValue = __VA_ARGS__; !(testAssertValue < expected);) \
		return UnitTestError(MAXON_SOURCE_LOCATION, FormatString("Test assertion failed. \"" #__VA_ARGS__  "\" was @, expected < @."_s, testAssertValue, expected))

#define MAXON_TEST_ASSERT_LE(expected, ...) \
	for (auto testAssertValue = __VA_ARGS__; !(testAssertValue <= expected);) \
		return UnitTestError(MAXON_SOURCE_LOCATION, FormatString("Test assertion failed. \"" #__VA_ARGS__  "\" was @, expected <= @."_s, testAssertValue, expected))

#define MAXON_TEST_ASSERT_GT(expected, ...) \
	for (auto testAssertValue = __VA_ARGS__; !(testAssertValue > expected);) \
		return UnitTestError(MAXON_SOURCE_LOCATION, FormatString("Test assertion failed. \"" #__VA_ARGS__  "\" was @, expected > @."_s, testAssertValue, expected))

#define MAXON_TEST_ASSERT_GE(expected, ...) \
	for (auto testAssertValue = __VA_ARGS__; !(testAssertValue >= expected);) \
		return UnitTestError(MAXON_SOURCE_LOCATION, FormatString("Test assertion failed. \"" #__VA_ARGS__  "\" was @, expected >= @."_s, testAssertValue, expected))

#define MAXON_TEST_ASSERT_TRUE(...) \
	if (! (__VA_ARGS__)) \
		return UnitTestError(MAXON_SOURCE_LOCATION, "Test assertion failed. \"" #__VA_ARGS__  "\" should be true."_s)

#define MAXON_TEST_ASSERT_FALSE(...) \
	if (__VA_ARGS__) \
		return UnitTestError(MAXON_SOURCE_LOCATION, "Test assertion failed. \"" #__VA_ARGS__  "\" should be false."_s)

#define MAXON_TEST_ASSERT_NO_ERROR(...) \
	iferr (__VA_ARGS__) \
		return UnitTestError(MAXON_SOURCE_LOCATION, "Test assertion failed. \"" #__VA_ARGS__  "\" should return no error."_s)

#define MAXON_TEST_ASSERT_ERROR(...) \
	ifnoerr (__VA_ARGS__) \
		return UnitTestError(MAXON_SOURCE_LOCATION, "Test assertion failed. \"" #__VA_ARGS__  "\" should return an error."_s)

}


#endif // UNITTEST_H__

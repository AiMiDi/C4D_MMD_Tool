#ifdef PRIVATE_MAXON_REGISTRATION_UNIT
#endif
#if 1
#if 1
#endif
namespace maxon
{
/// @cond IGNORE

	namespace enum24 { enum class JOBCANCELLATION
	{
		AUTOMATIC,						///< If a lambda does not return anything early cancellation is not an error, if it has a return value it is considered an error.
		ISOK,									///< If a lambda returns nothing or Result<void> early cancellation is not an error.
		ISERROR,							///< Early cancellation is always an error.
		KEEP_RUNNING_ON_EXIT	///< The job has to run on program exit and the containing module takes care of waiting/cancelling it before the module is unloaded. Early cancellation of the job will return an error.
	} ; }
	maxon::String PrivateToString_JOBCANCELLATION24(std::underlying_type<enum24::JOBCANCELLATION>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum24::JOBCANCELLATION::AUTOMATIC, (maxon::UInt64) enum24::JOBCANCELLATION::ISOK, (maxon::UInt64) enum24::JOBCANCELLATION::ISERROR, (maxon::UInt64) enum24::JOBCANCELLATION::KEEP_RUNNING_ON_EXIT};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "JOBCANCELLATION", SIZEOF(x), false, values, "AUTOMATIC\0ISOK\0ISERROR\0KEEP_RUNNING_ON_EXIT\0", fmt);
	}
/// @endcond

}
#endif

#if 1
namespace maxon
{
/// @cond INTERNAL

	namespace enum109
	{
		enum class JOBCANCELLATION
		{
			AUTOMATIC,						///< If a lambda does not return anything early cancellation is not an error, if it has a return value it is considered an error.
			ISOK,									///< If a lambda returns nothing or Result<void> early cancellation is not an error.
			ISERROR,							///< Early cancellation is always an error.
			KEEP_RUNNING_ON_EXIT	///< The job has to run on program exit and the containing module takes care of waiting/cancelling it before the module is unloaded. Early cancellation of the job will return an error.
		} ;
		static const maxon::UInt64 JOBCANCELLATION_values[] = {maxon::UInt64(enum109::JOBCANCELLATION::AUTOMATIC), maxon::UInt64(enum109::JOBCANCELLATION::ISOK), maxon::UInt64(enum109::JOBCANCELLATION::ISERROR), maxon::UInt64(enum109::JOBCANCELLATION::KEEP_RUNNING_ON_EXIT)};
		static const maxon::EnumInfo JOBCANCELLATION_info{"JOBCANCELLATION", SIZEOF(JOBCANCELLATION), false, "AUTOMATIC\0ISOK\0ISERROR\0KEEP_RUNNING_ON_EXIT\0", JOBCANCELLATION_values, std::extent<decltype(JOBCANCELLATION_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_JOBCANCELLATION109(){ return enum109::JOBCANCELLATION_info; }
/// @endcond

/// @cond INTERNAL

/// @endcond

/// @cond INTERNAL

/// @endcond

/// @cond INTERNAL

/// @endcond

/// @cond INTERNAL

/// @endcond

/// @cond INTERNAL

/// @endcond

/// @cond INTERNAL

/// @endcond

/// @cond INTERNAL

/// @endcond

/// @cond INTERNAL

/// @endcond

	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(DT_JobRef,, "net.maxon.datatype.job");
}
#endif

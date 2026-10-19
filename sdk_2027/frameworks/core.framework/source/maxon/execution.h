#ifndef EXECUTION_H__
#define EXECUTION_H__

#include "maxon/registry.h"
#include "maxon/job.h"

namespace maxon
{

/// @addtogroup SYSTEM
/// @{

//----------------------------------------------------------------------------------------
/// Class for code that needs to be executed once the whole system including modules is up and running.
/// To register code write:
/// @code
/// class ExecutionExample : public ExecutionInterface<ExecutionExample>
/// {
/// public:
/// 	Result<void> operator ()()
/// 	{
///     ..do something..
///			return OK;
/// 	}
/// };
///
/// MAXON_DECLARATION_REGISTER(ExecutionJobs, "net.maxon.execution.example")
/// {
/// 	return NewObj(ExecutionExample);
/// }
/// @endcode
//----------------------------------------------------------------------------------------
template <typename EXECUTION> using ExecutionInterface = JobInterfaceTemplate<EXECUTION>;


MAXON_REGISTRY(JobRef, ExecutionJobs, "net.maxon.registry.executionjobs");

}

#endif // EXECUTION_H__

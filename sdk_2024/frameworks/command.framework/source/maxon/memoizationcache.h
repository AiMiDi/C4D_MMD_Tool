#ifndef MEMOIZATIONCACHE_H__
#define MEMOIZATIONCACHE_H__

#include "maxon/datatypebase.h"
#include "maxon/hashmap.h"
#include "maxon/interfacebase.h"
#include "maxon/optional.h"
#include "maxon/registrybase.h"

namespace maxon
{

//----------------------------------------------------------------------------------------
/// Allows to store objects for possible reuse within a global cache.
/// All functions are thread safe.
//----------------------------------------------------------------------------------------
class MemoizationCacheInterface
{
	MAXON_INTERFACE_NONVIRTUAL(MemoizationCacheInterface, MAXON_REFERENCE_STATIC, "net.maxon.command.interface.memoizationcache");

public:
	//----------------------------------------------------------------------------------------
	/// Gets or creates a object. If the object is not cached the lambda is called to create a new object.
	/// The caller is responsible to clone the data from the GenericData of the result.
	/// @param[in] type								Category of the cache. See MemoizationTypes::...
	/// @param[in] documentRelated		Pointer to an object (e.g. BaseDocument) to which the object belongs to.
	/// @param[in] runId							Timestamp of the cache object. In cc4d you can use BaseDocument::GetCacheRunId() to pass the value.
	/// @param[in] hash								Unique hash of the cache object.
	/// @param[in] lambda							Delegate which is called to create an object if no cache was found for the given hash.
	/// @param[out] created						Returns True if no cache was found and the object was created.
	/// @return                       GenericData on success. This points to the original data. The caller is responsible to clone the data.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<GenericDataRef> Get(LiteralId&& type, const void* documentRelated, Int runId, UniqueHash hash, const Delegate<Result<GenericDataRef>()>& lambda, Bool& created = BoolLValue());

	//----------------------------------------------------------------------------------------
	/// Flushes the caches. The caller can flush all by giving default parameters of selective by id or pointer.
	/// @param[in] type								If type.IsPopulated() the Flush function selects only the given types.
	/// @param[in] documentRelated		If documentRelated != nullptr the function deletes only caches belonging to this pointer.
	/// @param[in] removeRunId				If removeRunId != NOTOK all values older or equal to this runId are deleted.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD void FlushAll(LiteralId&& type, const void* documentRelated, Int removeRunId);

	//----------------------------------------------------------------------------------------
	/// Returns the current cache usage by type, count etc.
	/// @param[out] result						The given HashMap is filled in the function call. 
	///																LiteralId - the MemoizationTypes::...,
	///																Int cnt - the number of entries of the cache,
	///																Int mem - memory usage by this entry.
	/// @return                       OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> GetStatistics(HashMap<Id, Tuple<Int /*cnt*/, Int /*mem*/>>& result);
};

MAXON_REGISTRY(NO_VALUE_TYPE, MemoizationTypes, "net.maxon.registry.memoization");

#include "memoizationcache1.hxx"

namespace MemoizationTypes
{
	MAXON_DECLARATION(NO_VALUE_TYPE, BaseDeformObject, "net.maxon.memoization.basedeform");
	MAXON_DECLARATION(NO_VALUE_TYPE, CommandExecution, "net.maxon.memoization.commandexecution");
	MAXON_DECLARATION(NO_VALUE_TYPE, TextOutlines, "net.maxon.memoization.textoutlines");	
	MAXON_DECLARATION(NO_VALUE_TYPE, Caps, "net.maxon.memoization.caps");
	MAXON_DECLARATION(NO_VALUE_TYPE, CapsClose, "net.maxon.memoization.capsclose");
	MAXON_DECLARATION(NO_VALUE_TYPE, GetFieldDirAndUvwDataUVs, "net.maxon.memoization.getfielddiranduvw.uwv");
	MAXON_DECLARATION(NO_VALUE_TYPE, GetFieldDirAndUvwDataNormals, "net.maxon.memoization.getfielddiranduvw.normals");
}

#include "memoizationcache2.hxx"

}

#endif // MEMOIZATIONCACHE_H__

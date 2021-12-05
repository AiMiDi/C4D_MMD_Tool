#ifndef SOURCECONTROL_H__
#define SOURCECONTROL_H__

#include "maxon/apibase.h"
#include "maxon/object.h"
#include "maxon/url.h"
#include "maxon/datetime.h"
#include "maxon/datadictionary.h"
#include "maxon/hashmap.h"
#include "maxon/progressmonitor.h"

namespace maxon
{

/// @addtogroup IO
/// @{

using SCConversionFunction = Delegate<Result<Data>(const CString& val)>;
using SCTypeConversion = HashMap<CString, SCConversionFunction>;

//----------------------------------------------------------------------------------------
/// Return value of GetChanges() and GetMissingIntegrations().
//----------------------------------------------------------------------------------------
class SourceControlChangeEntry
{
public:
	SourceControlChangeEntry() : _changeList(0)
	{
	}

	Int				_changeList;			///< Change list number of this entry.
	UniversalDateTime	_dateTime;				///< Date and time when the changelist has been submitted.
	String		_userName;				///< User name which submitted the change list.
	String		_workspaceName;		///< Client workspace that submitted the change list.
	String		_status;					///< Status of the changelist. Should be "submitted".
	String		_description;			///< The description text of the change list.
	String		_changeType;			///< public or private change
	Url				_path;						///< common path

	//----------------------------------------------------------------------------------------
	/// Describe all elements of this class for I/O operations.
	/// @param[in] stream							The stream that is used to register the class members.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static Result<void> DescribeIO(const DataSerializeInterface& stream);

	UInt GetHashCode() const
	{
		CriticalStop();
		return 0;
	}
};

class SourceControlInterface
{
	MAXON_INTERFACE_NONVIRTUAL(SourceControlInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.sourcecontrol");

public:
	//----------------------------------------------------------------------------------------
	/// Allocator for common use.
	/// @param[in] allocLocation			Pass MAXON_SOURCE_LOCATION(_NAME) to add the current source line and file.
	/// @param[in] portName						Perforce ip address and port. E.g. "127.0.0.1:1666". If the string is empty the value from the perforce credentials is taken.
	/// @param[in] clientName					Client workspace name. If the string is empty the value from the perforce credentials is taken.
	/// @param[in] userName						Perforce user name to login. If the string is empty the value from the perforce credentials is taken.
	/// @param[in] passWord						Perforce user password. If the string is empty the value from perforce credentials is taken.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<SourceControlInterface*> Alloc(MAXON_SOURCE_LOCATION_DECLARATION, const String& portName = String(), const String& clientName = String(), const String& userName = String(), const String& passWord = String());

	//----------------------------------------------------------------------------------------
	/// Checks out a file from the source code control depot for editing.
	/// @param[in] path								Path pointing to a file in the source code control depot, e.g. perforce:///depot/... or pointing to a local file.
	/// @return												Path where the checked out file locally resides.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Url> CheckoutFile(const Url& path);

	//----------------------------------------------------------------------------------------
	/// Gets the latest revision of a file from the source code control depot.
	/// @param[in] path								Path pointing to a file in the source code control depot, e.g. perforce:///depot/... or pointing to a local file.
	/// @param[in] changeList					Change list to sync. -1 syncs to the latest change list.
	/// @param[out] monitor						Optional handler to watch status throughout the time span of the sync operation.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> SyncFile(const Url& path, Int changeList = -1, ProgressMonitorRef monitor = ProgressMonitorRef());

	//----------------------------------------------------------------------------------------
	/// Gets the a revision of a file from the source code control depot.
	/// @param[in] path								Path pointing to a file in the source code control depot, e.g. perforce:///depot/... or pointing to a local file.
	/// @param[in] revision						The revision number to sync. -1 syncs to the latest revision.
	/// @param[out] monitor						Optional handler to watch status throughout the time span of the sync operation.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> SyncFileRevision(const Url& path, Int revision = -1, ProgressMonitorRef monitor = ProgressMonitorRef());

	//----------------------------------------------------------------------------------------
	/// Gets the local revision number of files on depot.
	/// @param[in] path								Path pointing to a file in the source code control depot, e.g. perforce:///depot/..., could be a file or a folder. Passing a folder is faster then call the fucntion on any file in it.
	/// @return												A map composed by the filname as key and local revision number as value.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<HashMap<Url, Int>> GetRevisionOnDrive(const Url& path);

	//----------------------------------------------------------------------------------------
	/// Reverts a (checked out) file to the latest revision from the source code control depot.
	/// @param[in] path								Path pointing to a file in the source code control depot, e.g. perforce:///depot/... or pointing to a local file.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> RevertFile(const Url& path);

	//----------------------------------------------------------------------------------------
	/// Gets the local file name of a depot file.
	/// @param[in] path								Path pointing to a file in the source code control depot, e.g. perforce:///depot/...
	/// @return												Path where the file locally resides.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Url> GetNameOnDrive(const Url& path);

	//----------------------------------------------------------------------------------------
	/// Submits the current default changelist.
	/// @param[in] description				The description for the changelist.
	/// @return												Returns the newly created changelist number on success. The changelist number is 0 if no files has been submitted because there were no changes to the files or there were no files.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Int> SubmitChangelist(const String& description);

	//----------------------------------------------------------------------------------------
	/// Adds a file to the current changelist.
	/// @param[in] path								Path of a local file that needs to be checked in.
	/// @return												Returns the perforce depot name as the result.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Url> AddFile(const Url& path);

	//----------------------------------------------------------------------------------------
	/// Deletes a file and adds this operation to the current changelist.
	/// @param[in] path								Path of a local file that needs to be deleted.
	/// @return												Returns the perforce depot name as the result.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Url> DeleteFile(const Url& path);

	//----------------------------------------------------------------------------------------
	/// Retrieves the last changelist of a given file.
	/// @param[in] path								Path of a local file or depot path.
	/// @return												Returns the changelist or an error.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Int> GetLastChange(const Url& path);

	//----------------------------------------------------------------------------------------
	/// Checks whether a file is under source control or not.
	/// @param[in] path								Path of a local file or depot path.
	/// @return												Receives true if the file is under source control, only valid if the operation succeeded.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Bool> IsUnderSourceControl(const Url& path);

	//----------------------------------------------------------------------------------------
	/// Checks whether multiple files are under source control or not. This is much faster than calling it for individual files.
	/// @param[in] paths							Array of paths of local files or depot paths.
	/// @param[out] result						Array of boolean values. True indicates a file is under source control and the operation succeeded.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> IsUnderSourceControl(const BaseArray<Url>& paths, BaseArray<Bool>& result);

	//----------------------------------------------------------------------------------------
	/// Queries the list of available branch mappings.
	/// @param[out] branches					The list that will be filled.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> GetBranchMappings(BaseArray<String>& branches);

	//----------------------------------------------------------------------------------------
	/// Retrieves data for an existing branch mapping.
	/// @param[in] name								The name of the branch mapping.
	/// @param[in] view								The branch mapping's view entries.
	/// @param[in] description				The branch mapping's description.
	/// @param[in] owner							The branch mapping's owner.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> GetBranchMapping(const String& name, BaseArray<String>& view, String& description, String& owner);

	//----------------------------------------------------------------------------------------
	/// Creates a new branch mapping or edits an existing one.
	/// @param[in] name								The name of the branch mapping.
	/// @param[in] view								The branch mapping's view.
	/// @param[in] description				The branch mapping's description.
	/// @param[in] owner							The branch mapping's owner.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> CreateBranchMapping(const String& name, const BaseArray<String>& view, const String& description, const String& owner);

	//----------------------------------------------------------------------------------------
	/// Deletes an existing branch mapping.
	/// @param[in] name								The name of the branch mapping.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> DeleteBranchMapping(const String& name);

	//----------------------------------------------------------------------------------------
	/// Gets all of the changes of a given depotPath (file or directory).
	/// @param[in] path								Path of a local file/directory.
	/// @param[in] longDescription		If true the functions returns the long description. Otherwise the shortened description.
	/// @param[in] limitUser					Limit the output to a specific user. An empty string for no filtering.
	/// @param[in] limitChanges				Limit the output to this number of changelists. 0 for no limits.
	/// @param[out] changes						Receives the change lists in this variable.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> GetChanges(const Url& path, Bool longDescription, const String& limitUser, Int limitChanges, BaseArray<SourceControlChangeEntry>& changes);

	//----------------------------------------------------------------------------------------
	/// Retrieves the missing integrations from one branch to another using the given branch mapping.
	/// @param[in] branchMapping			Branch Mapping to check.
	/// @param[in] checkChangelist		Up to this changelist the check will be evaluated. This parameter can be 0 to get the missing integrations for the latest changelist.
	/// @param[in] reverseMapping			If False the direction of the mapping is used. If true the opposite direction is calculated.
	/// @param[in] longDescription		If true the functions returns the long description. Otherwise the shortened description.
	/// @param[out] changes						Receives the change lists in this variable.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> GetMissingIntegrations(const String& branchMapping, Int checkChangelist, Bool reverseMapping, Bool longDescription, BaseArray<SourceControlChangeEntry>& changes);

	//----------------------------------------------------------------------------------------
	/// Return value of DescribeChangelist().
	//----------------------------------------------------------------------------------------
	struct ChangeFiles
	{
		Url		file;						///< File name.
		String		action;					///< Submit action: "edit", "add" ...
		String		type;						///< File type: "text" or "binary" ...
		Int				revision;				///< File revision.
		Int64			fileSize;				///< File size in bytes.
		String		digest;					///< Digest of the file.

		ChangeFiles() : revision(0), fileSize(0)
		{
		}
	};
	//----------------------------------------------------------------------------------------
	/// Gets all of the changes of a given depotPath (file or directory).
	/// @param[in] changelist					Changelist to describe.
	/// @param[out] change						Optional parameter to get the description of the changelist.
	/// @param[out] files							Optional parameter to get the affected files and the differences.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> DescribeChangelist(Int changelist, SourceControlChangeEntry* change, BaseArray<ChangeFiles>* files);

	//----------------------------------------------------------------------------------------
	/// Return value of DiffFiles().
	//----------------------------------------------------------------------------------------
	struct FileDiff
	{
		Int				chunksChanged;	///< Chunks changed.
		Int				linesChanged;		///< Lines changed.

		Int				chunksAdded;		///< Chunks added.
		Int				linesAdded;			///< Lines added.

		Int				chunksRemoved;	///< Chunks removed.
		Int				linesRemoved;		///< Lines removed.

		FileDiff() : chunksChanged(0), linesChanged(0), chunksAdded(0), linesAdded(0), chunksRemoved(0), linesRemoved(0)
		{
		}
	};
	//----------------------------------------------------------------------------------------
	/// Compares 2 files of the depot against each other. Its also possible to compare 2 revisions of the same file.
	/// @param[in] file1							File 1 to compare against file 2.
	/// @param[in] file2							File 2 to compare against file 1.
	/// @param[out] diff							FileDiff structure filled if the operation was successful.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> DiffFiles(const Url& file1, const Url& file2, FileDiff& diff);

	//----------------------------------------------------------------------------------------
	/// Copies the content of the file into the given buffer.
	/// @param[in] file								File to read.
	/// @param[out] content						Buffer that receives the content of the file.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> ReadFile(const Url& file, WritableArrayInterface<UChar>& content);

	//----------------------------------------------------------------------------------------
	/// Runs a native perforce command, the result is placed within a DataDictionary.
	/// @param[in] command						Command to execute.
	/// @param[in] arguments					Arguments passed to this command.
	/// @param[out] result						Result array with the answer.
	/// @param[out] monitor						Optional handler to watch status throughout the time span of the SCC command.
	/// @param[in] typeConversion			Optional HashSet with conversion from perforce types to Data.
	/// @param[in] input							Optional string that feeds the SCC command with input data.
	/// @return												OK on success. Returns the message string in any case (which can be empty).
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<String> RunNativeCommand(const String& command, const ArrayInterface<String>& arguments, WritableArrayInterface<DataDictionary>& result, ProgressMonitorRef monitor = ProgressMonitorRef(), const SCTypeConversion& typeConversion = SCTypeConversion(), const String& input = String());

	static MAXON_METHOD Result<Data> SCConvertSkip(const CString& val);
	static MAXON_METHOD Result<Data> SCConvertInt(const CString& val);
	static MAXON_METHOD Result<Data> SCConvertInt32(const CString& val);
	static MAXON_METHOD Result<Data> SCConvertInt64(const CString& val);
	static MAXON_METHOD Result<Data> SCConvertFloat(const CString& val);
	static MAXON_METHOD Result<Data> SCConvertFloat32(const CString& val);
	static MAXON_METHOD Result<Data> SCConvertFloat64(const CString& val);
	static MAXON_METHOD Result<Data> SCConvertDateTime(const CString& val);
	static MAXON_METHOD Result<Data> SCConvertUrl(const CString& val);
	static MAXON_METHOD Result<Data> SCConvertString(const CString& val);
};

MAXON_DATATYPE(SourceControlChangeEntry, "net.maxon.sourcecontrolchangeentry");

#include "sourcecontrol1.hxx"
#include "sourcecontrol2.hxx"

/// @}

} // namespace maxon

#endif // SOURCECONTROL_H__

#ifndef SQLDATABASE_H__
#define SQLDATABASE_H__

#include "maxon/basearray.h"
#include "maxon/object.h"
#include "maxon/timevalue.h"

namespace maxon
{
/// @addtogroup SqlDatabase
/// @{


//----------------------------------------------------------------------------------------
/// A NetworkError indicates that a network function failed.
//----------------------------------------------------------------------------------------
// class MySQLErrorInterface : MAXON_INTERFACE_BASES(ErrorInterface)
// {
// 	MAXON_INTERFACE(MySQLErrorInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.interface.mysqlerror");
// public:
// 	typedef ErrorInterface::AllocFunctions<MySQLErrorInterface> AllocClass;
// };

// TODO: (Tilo+Ole) the error class creates a circular dependency
using SQLDatabaseError = IllegalStateError;

//----------------------------------------------------------------------------------------
/// This class provides SQL database functionality.
/// With it it's possible to query sql databases.
/// E.g. Result<SqlDatabaseRef> mySql = SqlDatabaseClasses::MySql().Create(); provides access to mysql databases.
//----------------------------------------------------------------------------------------
class SqlDatabaseInterface : MAXON_INTERFACE_BASES(ObjectInterface)
{
	MAXON_INTERFACE(SqlDatabaseInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.sqldatabase");

public:
	//----------------------------------------------------------------------------------------
	/// Opens the connection to a.
	/// @param[in] sqlServer					IP address of the sql server.
	/// @param[in] sqlServerPort			Port of the sql server.
	/// @param[in] sqlUserName				User name at the given sql server.
	/// @param[in] sqlPasswd					Password of the user.
	/// @param[in] sqlDatabase				Opens this database within the sql database on the server. This parameter is optional.
	/// @return												Returns true if opening the database was successful.
	/// @MAXON_ANNOTATION{returnsThis}
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Init(const String& sqlServer, Int sqlServerPort, const String& sqlUserName, const String& sqlPasswd, const String& sqlDatabase);

	//----------------------------------------------------------------------------------------
	/// Opens a connection to a database file.
	/// @param[in] sqlFile						File to open.
	/// @param[in] sqlDatabase				Opens this database within the sql database on the server. This parameter is optional.
	/// @return												Returns true if opening the database was successful.
	/// @MAXON_ANNOTATION{returnsThis}
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Init(const Url& sqlFile, const String& sqlDatabase);

	//----------------------------------------------------------------------------------------
	/// Determines if the connection to the database has been established.
	/// @return												Returns true if the connection is open, otherwise false.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool IsConnected() const;

	//----------------------------------------------------------------------------------------
	/// Sends a query to the database.
	/// @param[in] query							The sql request string. E.g. "SELECT * from mydatabase".
	/// @param[out] insertId					If the query inserted data into the database, this pointer returns the insert id in the database. This parameter is optional.
	/// @param[out] result						If the query returns data it will be filled into this array. This parameter is optional.
	/// 															The outer array contains the number of lines returned by this query. The first line contains the field header names.
	/// 															The inner array the fields per line returned by this query.
	/// @return												Returns true if the query was successful, otherwise false.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> QuerySQL(const String& query, Int64* insertId = nullptr, const ValueReceiver<const BaseArray<String>&>& result = {});

	//----------------------------------------------------------------------------------------
	/// ExecuteSQLQuery description.
	/// @param[in] query							The sql request string. E.g. "SELECT * from mydatabase".
	/// @param[in] arguments					If the select statement contains "?" the arguments will be populated from the arguments array. e.g. "SELECT * from table WHERE col1 = ?"
	/// @param[out] insertId					If the query inserted data into the database, this pointer returns the insert id in the database. This parameter is optional.
	/// @param[out] result						If the query returns data it will be filled into this array. This parameter is optional.
	/// 															The outer array contains the number of lines returned by this query.
	/// 															The inner array the fields per line returned by this query.
	/// @param[out] columnTitles			Delegate to receive the column titles. This is called once.
	/// @return                       OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> ExecuteSQLQuery(const String& query, const Block<ConstDataPtr>& arguments = {}, Int64* insertId = nullptr, const ValueReceiver<BaseArray<Data>&&>& result = {}, const ValueReceiver<const String&>& columnTitles = {});

	//----------------------------------------------------------------------------------------
	/// This functions returns a quoted string usable for sql queries. This function calls internally ReplaceString() to make the given text sql conform.
	/// @param[in] text								The given text the has to be converted.
	/// @return												The converted string.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<String> QuotedString(const String& text) const;

	//----------------------------------------------------------------------------------------
	/// This functions converts a string into usable style for sql queries.
	/// @param[in] text								The given text the has to be converted.
	/// @return												The converted string.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<String> ReplaceString(const String& text) const;

	//----------------------------------------------------------------------------------------
	/// StartTransactions calls "BEGIN TRANSACTION" to collect the next calls. After the given time the commit is done.
	/// @param[in] delayCommitTime		Time after which the commit should be called. Disabled if value == TIMEVALUE_INFINITE
	/// @param[in] maxExecutes				Maximum Number of executes after commit should be called. Disabled if maxExecutes == NOTOK
	/// @return                       OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> StartTransactions(const TimeValue& delayCommitTime, Int maxExecutes);

	//----------------------------------------------------------------------------------------
	/// CommitTransactions force to commit the changes since the last start of StartTransactions(). Does nothing if not in transaction mode
	/// @return                       OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> CommitTransactions();
};


// include autogenerated headerfile here
#include "sqldatabase1.hxx"


MAXON_REGISTRY(Class<SqlDatabaseRef>, SqlDatabaseClasses, "net.maxon.registry.sqldatabaseclasses");

namespace SqlDatabaseClasses
{
	MAXON_DECLARATION(SqlDatabaseClasses::EntryType, MySql, "net.maxon.sqldatabaseclass.mysql");
	MAXON_DECLARATION(SqlDatabaseClasses::EntryType, SQLite, "net.maxon.sqldatabaseclass.sqlite");
}

// include autogenerated headerfile here
#include "sqldatabase2.hxx"

/// @}
}

#endif // SQLDATABASE_H__

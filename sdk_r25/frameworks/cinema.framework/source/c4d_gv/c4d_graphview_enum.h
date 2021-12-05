/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef C4D_GRAPHVIEW_ENUM_H__
#define C4D_GRAPHVIEW_ENUM_H__

//----------------------------------------------------------------------------------------
/// XPresso error codes.
//----------------------------------------------------------------------------------------
enum GvError
{
	GV_IO_ERR_NONE = 0,										///< No I/O error.
	GV_CALC_ERR_NONE = 0,									///< No calculation error.

	GV_CALC_ERR_NO_MEMORY,								///< Out of memory error.
	GV_CALC_ERR_UNDEFINED,								///< Undefined error.
	GV_CALC_ERR_UNKNOWN_TYPE,							///< Unknown type error.
	GV_CALC_ERR_NOT_IMPLEMENTED,					///< Not implemented error.
	GV_CALC_ERR_NOT_INITIALIZED,					///< Not initialized error.
	GV_CALC_ERR_NOT_VALID,								///< Not valid error.
	GV_CALC_ERR_NO_OUTPORT,								///< No output error.
	GV_CALC_ERR_NOT_CONNECTED,						///< Not connected error.
	GV_CALC_ERR_NO_PORT,									///< No port error.
	GV_CALC_ERR_DIVISION_BY_ZERO,					///< Division by zero error.
	GV_CALC_ERR_TYPE_MISMATCH,						///< Type mismatch error.
	GV_CALC_ERR_INIT_FAILED,							///< Init failed error.
	GV_CALC_ERR_QUERY_FAILED,							///< Query failed error.
	GV_CALC_ERR_CALCULATION_FAILED,				///< Calculation failed error.
	GV_CALC_ERR_PARAMETER,								///< Bad parameter error.

	GV_IO_ERR_NO_MEMORY,									///< No memory I/O error.
	GV_IO_ERR_FILE_NOT_FOUND,							///< File not found I/O error.
	GV_IO_ERR_READ,												///< Read I/O error.
	GV_IO_ERR_WRITE,											///< Write I/O error.
	GV_IO_ERR_NOT_A_GROUPNODE,						///< Not a group node I/O error.

	GV_NR_OF_SYSTEM_ERRORS,								///< Number of system errors.
	GV_CALC_ERR_USER_DEFINED = 10000			///< All user defined errors must be above this ID.
};

/// Typedef for calculation errors.
typedef GvError GvCalcError;

/// Typedef for I/O errors.
typedef GvError GvIoError;

//----------------------------------------------------------------------------------------
/// XPresso calculation flags.
//----------------------------------------------------------------------------------------
enum GvValueFlags
{
	GV_CALC_NOP			= (0),						///< No calculation.
	GV_CALC_CLR			= (1 <<  0),			///< Clear:						<tt>((TYPE*)dest)[cpu_id] = 0</tt>
	GV_CALC_SET			= (1 <<  1),			///< Set:							<tt>((TYPE*)dest)[cpu_id] = source1[cpu_id]</tt>
	GV_CALC_ADD			= (1 <<  2),			///< Add:							<tt>((TYPE*)dest)[cpu_id] = source1[cpu_id] + source2[cpu_id]</tt>
	GV_CALC_SUB			= (1 <<  3),			///< Subtract:				<tt>((TYPE*)dest)[cpu_id] = source1[cpu_id] - source2[cpu_id]</tt>
	GV_CALC_MUL			= (1 <<  4),			///< Multiply:				<tt>((TYPE*)dest)[cpu_id] = source1[cpu_id] * source2[cpu_id]</tt>
	GV_CALC_DIV			= (1 <<  5),			///< Divide:					<tt>((TYPE*)dest)[cpu_id] = source1[cpu_id] / source2[cpu_id]</tt>
	GV_CALC_MOD			= (1 <<  6),			///< Modulo:					<tt>((TYPE*)dest)[cpu_id] = source1[cpu_id] % source2[cpu_id]</tt>
	GV_CALC_CRS			= (1 <<  7),			///< Cross product:		<tt>((TYPE*)dest)[cpu_id] = source1[cpu_id] x source2[cpu_id]</tt>
	GV_CALC_INV			= (1 <<  8),			///< Invert:					<tt>((TYPE*)dest)[cpu_id] = 1 / source1[cpu_id]</tt>
	GV_CALC_NEG			= (1 <<  9),			///< Negate:					<tt>((TYPE*)dest)[cpu_id] = -source1[cpu_id]</tt>
	GV_CALC_CMP			= (1 << 10),			///< Compare:					<tt>((Int32*)dest)[cpu_id] = source1[cpu_id] <, ==, > source2[cpu_id] => -1, 0, 1</tt>
	GV_CALC_EQU			= (1 << 12),			///< Equal:						<tt>((Bool*)dest)[cpu_id] = source1[cpu_id] == source2[cpu_id]</tt>
	GV_CALC_NIL			= (1 << 13),			///< Is null:					<tt>((Bool*)dest)[cpu_id] = source1[cpu_id] == 0</tt>
	GV_CALC_STR			= (1 << 14),			///< Print:						<tt>*((String*)dest) = String(source1[cpu_id])</tt>
	GV_CALC_MIX			= (1 << 15),			///< Mix:							<tt>((TYPE*)dest)[cpu_id] = source1[cpu_id] * parm1 + source2[cpu] * (1 - parm1)</tt>
	GV_CALC_ABS			= (1 << 16),			///< Absolute value:	<tt>((TYPE*)dest)[cpu_id] = Abs(source1[cpu_id])</tt>
	GV_CALC_ADR			= (1 << 17),			///< Add real:				<tt>((TYPE*)dest)[cpu_id] = source1[cpu_id] + parm1</tt>
	GV_CALC_SUR			= (1 << 18),			///< Subtract real:		<tt>((TYPE*)dest)[cpu_id] = source1[cpu_id] - parm1</tt>
	GV_CALC_MUR			= (1 << 19),			///< Multiply real:		<tt>((TYPE*)dest)[cpu_id] = source1[cpu_id] * parm1</tt>
	GV_CALC_DIR			= (1 << 20),			///< Divide real:			<tt>((TYPE*)dest)[cpu_id] = source1[cpu_id] / parm1</tt>
	GV_CALC_DEF			= (1 << 21),			///< Set real:				<tt>((TYPE*)dest)[cpu_id] = (TYPE)parm1</tt>
	GV_CALC_DOT			= (1 << 22),			///< Dot product:			<tt>((Float*)dest)[cpu_id] = source1[cpu_id] * source2[cpu_id]</tt>

	GV_CALC_STD			= (GV_CALC_CLR | GV_CALC_SET)			///< A combination of @ref GV_CALC_CLR and @ref GV_CALC_SET. Must be implemented.
};

//----------------------------------------------------------------------------------------
/// XPresso data types filtering options.
/// @see GvWorld::GetDataTypes
//----------------------------------------------------------------------------------------
enum GvDataOptions
{
	GV_DATA_OPTIONS_NONE								= (0),					///< No flags.
	GV_DATA_OPTIONS_SHOW_UNDEFINED			= (1 << 0),			///< Show undefined.
	GV_DATA_OPTIONS_HIDE_NOT_EDITABLE		= (1 << 1)			///< Hide not editable.
};

#endif // C4D_GRAPHVIEW_ENUM_H__

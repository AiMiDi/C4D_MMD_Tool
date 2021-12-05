/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef C4D_FIELDDATA_H__
#define C4D_FIELDDATA_H__

#include "ge_math.h"
#include "ge_prepass.h"
#include "c4d_memory.h"
#include "maxon/blockarray.h"
#ifdef __API_INTERN__
	#include "basecontainer.h"
	#include "ge_container.h"
#else
	#include "c4d_basecontainer.h"
	#include "c4d_gedata.h"
#endif
#include "maxon/algorithms.h"
#include "maxon/crc32c.h"
#include "maxon/collection.h"

class BaseThread;
class BaseDocument;
struct FieldOutputBlock;

#define FLCall(fnc) (this->*C4DOS.FL->fnc)

static const Int32 FIELD_EXECUTION_BLOCK_SIZE	 = 400;			///< / The size of a block that's executed in an MP environment. For single depth execution a value closer to 1200 is actually more optimal, with one group 600 and from then on for each group depth you can expect a drop of a third. For general usage on current architectures this gives the best balance.
static const Float FIELD_EXECUTION_BLOCK_SIZEf = 400.0_f;	///< / The size of a block that's executed in an MP environment. For single depth execution a value closer to 1200 is actually more optimal, with one group 600 and from then on for each group depth you can expect a drop of a third. For general usage on current architectures this gives the best balance.

/// @addtogroup Fieldbase
/// @ingroup group_enumeration
/// @{

// UPDATE SYMBOLS_OLD.H for new ids!

// Part of objects modules
static const Int32 Fspherical = 440000243;				///< Sphere shaped field
static const Int32 Flinear = 440000266;						///< Linear shaped field
static const Int32 Fbox = 440000267;							///< Box shaped field
static const Int32 Fcylinder = 440000268;					///< Cylinder shaped field
static const Int32 Fcone = 440000269;							///< Cone shape field
static const Int32 Ftorus = 440000272;						///< Torus shaped field
static const Int32 Fobject_DEPRECATED = 440000273;
static const Int32 Fcapsule = 440000274;					///< Capsule shaped field

// Part of mograph module
static const Int32 Fstep_DEPRECATED = 440000275;
static const Int32 Ftime_DEPRECATED = 440000278;
static const Int32 Fvolume_DEPRECATED = 440000279;
static const Int32 Fformula = 440000280;					///< Formula field
static const Int32 Frandom	= 440000281;					///< Random/noise field
static const Int32 Fshader	= 440000282;					///< Shader field
static const Int32 Fsound = 440000283;						///< Sound field
static const Int32 Fdelay_DEPRECATED = 440000284;
static const Int32 Fdecay_DEPRECATED = 440000285;
static const Int32 Fradial = 1040448;							///< Radial field
static const Int32 Fgroup = 1040449;							///< Group field

// Part of python module
static const Int32 Fpython = 440000277;

/// @}


/// @addtogroup FLbase
/// @ingroup group_enumeration
/// @{

// UPDATE SYMBOLS_OLD.H for new ids!

static const Int32 FLbase = 440000249;						///< FieldLayer base.
static const Int32 FLplugin = 440000259;					///< FieldLayer plugin.
																										 
// Part of xtensions module
static const Int32 FLfolder	= 440000250;					///< FieldLayer Folder layer.
static const Int32 FLfield	= 440000251;					///< FieldLayer Field object based layer.
static const Int32 FLsolid	= 440000252;					///< FieldLayer Solid value/color layer.
static const Int32 FLdescid = 440000253;					///< FieldLayer DescID based layer.
static const Int32 FLclamp	= 440000295;					///< FieldLayer Clamping remapping layer
static const Int32 FLremap	= 440000296;					///< FieldLayer between values remapping layer
static const Int32 FLcurve	= 440000297;					///< FieldLayer curve remapping layer
static const Int32 FLgradient = 440000298;				///< FieldLayer gradient remapping layer
static const Int32 FLquantize = 440000299;				///< FieldLayer quantize remapping layer
static const Int32 FLinvert = 440000300;					///< FieldLayer invert remapping layer
static const Int32 FLcolorize = 440000301;				///< FieldLayer colorize remapping layer
static const Int32 FLrangemap = 440000302;				///< FieldLayer rangemap remapping layer
static const Int32 FLchannelmix = 440000338;			///< Fieldlayer channel mixer remapping layer

// Part of mograph module
static const Int32 FLnoise	= 440000290;					///< Fieldlayer Noise remapping layer.
static const Int32 FLspline = 440000276;					///< Spline FieldLayer
static const Int32 FLdelay	= 440000291;					///< Delay FieldLayer
static const Int32 FLdecay = 440000292;						///< Decay FieldLayer
static const Int32 FLstep = 440000293;						///< Step FieldLayer
static const Int32 FLweight = 440000294;					///< Weight FieldLayer
static const Int32 FLproximity = 1040379;					///< Proximity FieldLayer
static const Int32 FLformula = 1040450;						///< Formula FieldLayer
static const Int32 FLtime = 1040451;							///< Time FieldLayer
static const Int32 FLpython = 1040420;						///< Python FieldLayer
static const Int32 FLmograph = 440000325;					///< MoGraph FieldLayer
static const Int32 FLpolygonobject = 440000327;		///< Polygon Object FieldLayer
static const Int32 FLvolumeobject = 440000328;		///< Volume Object FieldLayer
static const Int32 FLparticleobject = 440000330;	///< Particle Object FieldLayer
/// @}

//----------------------------------------------------------------------------------------
/// The full result from sampling a field. Struct own the sampled data if
/// it is not a sub block of the full sample.
/// FieldOutput used as subblock don't own the memory and don't carry a ref count on the
/// allocated memory, hence the real block must stay valid during the use of a subblock.
//----------------------------------------------------------------------------------------
struct FieldOutput
{
	//----------------------------------------------------------------------------------------
	/// Creates and empty sample.
	//----------------------------------------------------------------------------------------
	FieldOutput() = default;

	//----------------------------------------------------------------------------------------
	/// Move construction. Takes ownership of the sample memory.
	/// @param[in] moveRef						The source sample.
	//----------------------------------------------------------------------------------------
	FieldOutput(FieldOutput&& moveRef);

	//----------------------------------------------------------------------------------------
	/// Frees sample memory if not a sub block.
	//----------------------------------------------------------------------------------------
	~FieldOutput();

	MAXON_OPERATOR_MOVE_ASSIGNMENT(FieldOutput);

	//----------------------------------------------------------------------------------------
	/// Casting operator, equivalent to GetBlock().
	/// @return												A sub block for the whole FieldOutput.
	//----------------------------------------------------------------------------------------
	operator FieldOutputBlock() const;

	//----------------------------------------------------------------------------------------
	/// Gets the total arrays in a FieldOutputBlock.
	/// @return												A sub block for the whole FieldOutput.
	//----------------------------------------------------------------------------------------
	FieldOutputBlock GetBlock() const;

	//----------------------------------------------------------------------------------------
	/// Gets a sub-section of the total arrays.
	/// @param[in] offset							The offset index to retrieve a sub-block starting at.
	/// @param[in] blockSize					Suggested size of the block, will be clamped against the maximum number of entries.
	/// @return												The sub block.
	//----------------------------------------------------------------------------------------
	maxon::Result<FieldOutputBlock> GetSubBlock(Int offset, Int blockSize = FIELD_EXECUTION_BLOCK_SIZE) const;

	//----------------------------------------------------------------------------------------
	/// Resets the FieldOutput to an empty state. All memory will be deallocated.
	//----------------------------------------------------------------------------------------
	void Reset();

	//----------------------------------------------------------------------------------------
	/// Flush the FieldOutput content, keeping the arrays allocated for future resize.
	//----------------------------------------------------------------------------------------
	void Flush();

	//----------------------------------------------------------------------------------------
	/// Gets the number of elements in the FieldOutput
	/// @return												The count.
	//----------------------------------------------------------------------------------------
	inline Int GetCount() const { return _count; }

	//----------------------------------------------------------------------------------------
	/// Checks if the FieldOutput allocations and sizes are valid (empty FieldOutput is considered valid).
	//----------------------------------------------------------------------------------------
	Bool IsValid() const;

	//----------------------------------------------------------------------------------------
	/// Checks if the FieldOutput is valid and non-empty.
	//----------------------------------------------------------------------------------------
	Bool IsPopulated() const;

	//----------------------------------------------------------------------------------------
	/// Compares the content of both FieldOutput. Count and array content must be the same.
	/// @param[in] comp								Source for the comparison.
	/// @return												True if equal.
	//----------------------------------------------------------------------------------------
	Bool IsEqual(const FieldOutput &comp) const;

	//----------------------------------------------------------------------------------------
	/// Copies from the FieldOutput described by src. Performs a deep copy.
	/// @param[in] src								Source for the duplication.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	maxon::Result<void> CopyFrom(const FieldOutput& src);

	//----------------------------------------------------------------------------------------
	/// Copies from the FieldOutput array content from src.
	/// Size and flags will not be affected by this action.
	/// Source data content will be copied into target up to current size.
	/// If target is bigger than source, the remaining items are cleared.
	/// @param[in] src								Source for the duplication.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	maxon::Result<void> CopyArrayContentFrom(const FieldOutput& src);

	//----------------------------------------------------------------------------------------
	/// Copies from the FieldOutput array content from src.
	/// Size and flags will not be affected by this action.
	/// Source data content will be copied into target up to current size.
	/// If target is bigger than source, the remaining items are cleared.
	/// @param[in] src								Source for the duplication.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	maxon::Result<void> CopyArrayContentFrom(const FieldOutputBlock& src);

	//----------------------------------------------------------------------------------------
	/// Resizes the arrays held in the FieldOutput.
	/// Unspecified channel arrays will be resized to 0 length (according to resizeFlags).
	/// @param[in] newSize						The size that the arrays should become.
	/// @param[in] sampleFlags				The channels to sample.
	/// @param[in] resizeFlags				The flags for which channels should be resized.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	maxon::Result<void> Resize(Int newSize, FIELDSAMPLE_FLAG sampleFlags = FIELDSAMPLE_FLAG::ALL, maxon::COLLECTION_RESIZE_FLAGS resizeFlags = maxon::COLLECTION_RESIZE_FLAGS::DEFAULT);

	//----------------------------------------------------------------------------------------
	/// Reset the sample's data to default values, optionally only the deactivated content too. Values are
	/// reset to 0, colors to 1.0, direction to 0, deactivated to 0.
	/// @param[in] deactivatedOnly		True to deactivated only.
	/// @param[in] deactivatedState		(Optional) The state the deactivated should be cleared to
	//----------------------------------------------------------------------------------------
	void ClearMemory(Bool deactivatedOnly = true, Bool deactivatedState = false);

	//----------------------------------------------------------------------------------------
	/// Reset the sample's data to default values, optionally only the deactivated content too. Values are
	/// reset to 0, colors to 1.0, direction to 0, deactivated to 0.
	/// @param[in] startIdx						Array clear start index.
	/// @param[in] count							Number of array items to reset to default value.
	/// @param[in] deactivatedOnly		True to deactivated only.
	/// @param[in] deactivatedState		(Optional) The state the deactivated should be cleared to
	//----------------------------------------------------------------------------------------
	void ClearMemory(Int startIdx, Int count, Bool deactivatedOnly, Bool deactivatedState);

	/// Clears the deactivated array
	void ClearDeactivated(Bool state = false)
	{
		if (_deactivated.IsPopulated())
		{
			maxon::Fill(_deactivated.GetFirst(), _deactivated.GetFirst() + _count, state);
		}
	}

	//----------------------------------------------------------------------------------------
	/// Calculates a crc on all internal data using maxon::Crc32C.
	/// Crc is not kept internally and will be calculated from scratch on
	/// each CalculateCrc call.
	/// @return												The crc.
	//----------------------------------------------------------------------------------------
	maxon::Crc32C CalculateCrc() const;

	//----------------------------------------------------------------------------------------
	/// Allocate a heap FieldOutput with all specified sampling arrays.
	/// Equivalent of calling empty constructor followed by Resize.
	/// Use FieldOutputRef to have a scoped or auto deleted FieldOutput.
	/// @param[in] size								The size.
	/// @param[in] flags							The flags.
	/// @return												A MemoryError if it fails, else a FieldOutput*.
	//----------------------------------------------------------------------------------------
	static maxon::Result<FieldOutput*> Alloc(Int size, FIELDSAMPLE_FLAG flags = FIELDSAMPLE_FLAG::ALL);

	//----------------------------------------------------------------------------------------
	/// Frees the given FieldOutput and all internal allocations.
	/// @param[in] p									The FieldOutput to free.
	//----------------------------------------------------------------------------------------
	static void Free(FieldOutput*& p);

	//----------------------------------------------------------------------------------------
	/// Create a FieldOutput with all specified sampling arrays.
	/// Same as Alloc, but on the stack.
	/// Equivalent of calling empty constructor followed by Resize.
	/// @param[in] size								The size.
	/// @param[in] flags							The flags.
	/// @return												The resulting FieldOutput.
	//----------------------------------------------------------------------------------------
	static maxon::Result<FieldOutput> Create(Int size, FIELDSAMPLE_FLAG flags = FIELDSAMPLE_FLAG::ALL);

	//----------------------------------------------------------------------------------------
	/// Create a FieldOutput with all specified sampling arrays.
	/// Size will be fetched from the source FieldOutput. Array content will be copied from source FieldOutput.
	/// Equivalent of calling empty constructor followed by CopyFrom.
	/// @param[in] src								The source FieldOutput.
	/// @return												The resulting FieldOutput.
	//----------------------------------------------------------------------------------------
	static maxon::Result<FieldOutput> Create(FieldOutputBlock& src);

private:
	MAXON_DISALLOW_COPY_AND_ASSIGN(FieldOutput);

public:
	maxon::BaseArray<Float> _value;					/// The weight value at this point in space
	maxon::BaseArray<Float> _alpha;					/// The alpha value for color and direction at this point in space, only available when color or direction are allocated.
	maxon::BaseArray<Vector> _color;				/// The color at this point in space
	maxon::BaseArray<Vector> _direction;		/// The direction at this point in space
	maxon::BaseArray<Vector> _rotation;			/// The rotational velocity (axle + magnitude)
	maxon::BaseArray<Vector> _pivot;				/// The rotational pivot point in space
	maxon::BaseArray<Bool> _deactivated;		/// The deactivated state for this point (i.e. cut from interior shape will be true) this skips remapping

private:
	Int _count = 0;													/// The number of elements in the sample arrays
};

using FieldOutputRef = maxon::StrongRef<FieldOutput>;

//----------------------------------------------------------------------------------------
/// Read the sample flags from the array content of a FieldOutputBlock.
/// @param[in] block							The outputs to extract flags from.
/// @return												The flags.
//----------------------------------------------------------------------------------------
FIELDSAMPLE_FLAG ExtractSampleFlags(const FieldOutputBlock& block);

//----------------------------------------------------------------------------------------
/// Validate the content of a block making sure that the block itself is valid
/// and array allocation respect the specified flags. "block" flags must be a
/// perfect 1 to 1 match with the specified flags for the function to succeed.
/// if "block" is missing a flag or has an unneeded flag, validation will fail.
/// @param[in] block							The block to validate.
/// @param[in] flags							The flags to compare the block against..
/// @return												True if the block is valid.
//----------------------------------------------------------------------------------------
Bool ValidateFieldOutputBlockWithFlags(const FieldOutputBlock &block, FIELDSAMPLE_FLAG flags);

//----------------------------------------------------------------------------------------
/// FieldOutput sub block class. FieldOutputBlock never own the memory of the sampling arrays,
/// it is owned by the FieldOutput structure.
/// Lifetime of a block is the same as its owner. Resizing, resetting the owner, or any
/// other operation that will have the owner reallocate or deallocate memory will invalidate 
/// the blocks.
//----------------------------------------------------------------------------------------
struct FieldOutputBlock
{
	//----------------------------------------------------------------------------------------
	/// Creates and empty sampling block, with not data.
	//----------------------------------------------------------------------------------------
	FieldOutputBlock() = default;

	//----------------------------------------------------------------------------------------
	/// Move construction. Does not actually steal anything as FieldOutputBlock never owns the 
	/// memory.
	/// @param[in] moveRef						The source sample.
	//----------------------------------------------------------------------------------------
	FieldOutputBlock(FieldOutputBlock&& moveRef) = default;

	MAXON_OPERATOR_MOVE_ASSIGNMENT(FieldOutputBlock);

	//----------------------------------------------------------------------------------------
	/// Gets a sub-section of "this" which can be indexed from 0 to "blockSize".
	/// @param[in] offset							The offset index to retrieve a sub-block starting at.
	/// @param[in] blockSize					Suggested size of the block, will be clamped against the maximum number of entries.
	/// @return												The sub block.
	//----------------------------------------------------------------------------------------
	maxon::Result<FieldOutputBlock> GetSubBlock(Int offset, Int blockSize = FIELD_EXECUTION_BLOCK_SIZE) const;

	//----------------------------------------------------------------------------------------
	/// Resets the FieldOutputBlock to default state (i.e. null count, no owner, no data, empty).
	//----------------------------------------------------------------------------------------
	void Reset();

	//----------------------------------------------------------------------------------------
	/// Gets the number of elements in the sub block.
	/// @return												The count.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE Int GetCount() const { return _count; }

	//----------------------------------------------------------------------------------------
	/// Gets the number of elements used in the owning FieldOutput.
	/// @return												The count.
	//----------------------------------------------------------------------------------------
	Int GetFullCount() const { return _owner ? _owner->GetCount() : 0; }

	//----------------------------------------------------------------------------------------
	/// Gets the offset of the sub block in the FieldOutput.
	/// @return												The offset.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE Int GetOffset() const { return _offset; }

	/// Returns the owner FieldOutput.
	MAXON_ATTRIBUTE_FORCE_INLINE const FieldOutput* GetOwner() const { return _owner; }

	//----------------------------------------------------------------------------------------
	/// Copies from the FieldOutputBlock described by src. 
	/// Note that FieldOutputBlock never owns the arrays, so the copy only copies the raw pointers.
	/// @param[in] src								Source for the duplication.
	//----------------------------------------------------------------------------------------
	void CopyFrom(const FieldOutputBlock& src);

	//----------------------------------------------------------------------------------------
	/// Copies from the FieldOutput array content from src.
	/// Block size and flags will not be affected by this action.
	/// The destination allocated size must be big enough to accept the full content of the src block.
	/// Destination block will own memory if it is a normal block or not own it if it is a subblock.
	/// @param[in] src								Source for the duplication.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	maxon::Result<void> CopyArrayContentFrom(const FieldOutputBlock& src);

	//----------------------------------------------------------------------------------------
	/// Reset the sample's data to default values, optionally only the deactivated content too. Values are
	/// reset to 0, colors to 1.0, direction to 0, deactivated to 0.
	/// @param[in] deactivatedOnly		True to deactivated only.
	/// @param[in] deactivatedState		(Optional) The state the deactivated should be cleared to
	//----------------------------------------------------------------------------------------
	void ClearMemory(Bool deactivatedOnly = true, Bool deactivatedState = false);

	//----------------------------------------------------------------------------------------
	/// Reset the sample's data to default values, optionally only the deactivated content too. Values are
	/// reset to 0, colors to 1.0, direction to 0, deactivated to 0.
	/// @param[in] startIdx						Array clear start index.
	/// @param[in] count							Number of array items to reset to default value.
	/// @param[in] deactivatedOnly		True to deactivated only.
	/// @param[in] deactivatedState		(Optional) The state the deactivated should be cleared to
	//----------------------------------------------------------------------------------------
	void ClearMemory(Int startIdx, Int count, Bool deactivatedOnly, Bool deactivatedState);

	/// Clears the deactivated array
	void ClearDeactivated(Bool state = false)
	{
		if (_deactivated.IsPopulated())
		{
			maxon::Fill(_deactivated.GetFirst(), _deactivated.GetFirst() + _count, state);
		}
	}

	//----------------------------------------------------------------------------------------
	/// Calculates a crc on all internal data using maxon::Crc32C.
	/// Crc is not kept internally and will be calculated from scratch on
	/// each CalculateCrc call.
	/// @return												The crc.
	//----------------------------------------------------------------------------------------
	maxon::Crc32C CalculateCrc() const;

	//----------------------------------------------------------------------------------------
	/// Checks if the FieldOutputBlock allocations and sizes are valid (empty is considered valid).
	//----------------------------------------------------------------------------------------
	Bool IsValid() const;

	//----------------------------------------------------------------------------------------
	/// Checks if the FieldOutputBlock is valid and non-empty.
	//----------------------------------------------------------------------------------------
	Bool IsPopulated() const;

private:
	friend FieldOutputBlock FieldOutput::GetBlock() const;
	friend maxon::Result<FieldOutputBlock> FieldOutput::GetSubBlock(Int offset, Int blockSize) const;

	MAXON_DISALLOW_COPY_AND_ASSIGN(FieldOutputBlock);

public:
	maxon::Block<Float>		_value;					/// The weight value at this point in space
	maxon::Block<Float>		_alpha;					/// The alpha value for color and direction at this point in space, only available when color or direction are allocated.
	maxon::Block<Vector>	_color;					/// The color at this point in space
	maxon::Block<Vector>	_direction;			/// The slope at this point in space
	maxon::Block<Vector>	_rotation;			/// The rotational velocity (axle + magnitude)
	maxon::Block<Vector>	_pivot;					/// The rotational pivot point in space
	maxon::Block<Bool>		_deactivated;		/// The deactivated state for this point (i.e. cut from interior shape will be true) this skips remapping

private:
	Int _count = 0;												/// The number of elements in the sample arrays
	Int _offset = 0;											/// Data offset in the original arrays (owner).
	const FieldOutput* _owner = nullptr;	/// Sampling array memory owner.
};

/// Input-output structure used to share some data between fields.
/// NOTE: to avoid multi-threading issues, it is not allowed to write to it during
/// Sampling (Sample method) calls. Most uses should write to it during FreeSampling.
struct FieldShared
{
public:
	//----------------------------------------------------------------------------------------
	/// Empty constructor
	//----------------------------------------------------------------------------------------
	FieldShared() = default;

	//----------------------------------------------------------------------------------------
	/// Destructor
	//----------------------------------------------------------------------------------------
	~FieldShared() = default;

	//----------------------------------------------------------------------------------------
	/// Move constructor
	/// @param[in] src								Move source.
	//----------------------------------------------------------------------------------------
	FieldShared(FieldShared&& src);

	MAXON_OPERATOR_MOVE_ASSIGNMENT(FieldShared);

	//----------------------------------------------------------------------------------------
	/// Resets the shared data and deallocates the memory.
	//----------------------------------------------------------------------------------------
	void Flush();

	//----------------------------------------------------------------------------------------
	/// Copies from the FieldShared described by src.
	/// @param[in] src								Source for the duplication.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	maxon::Result<void> CopyFrom(const FieldShared& src);

	//----------------------------------------------------------------------------------------
	/// Resets the dirty counts/flags to non dirty. Should be done before shared data is used
	/// for any sampling to allow layers to update data within correctly.
	//----------------------------------------------------------------------------------------
	void ResetDirty();

private:
	MAXON_DISALLOW_COPY_AND_ASSIGN(FieldShared);

public:
	typedef maxon::StrongRef<maxon::BlockArray<Float>> ValueArrayRef;
	ValueArrayRef _finalOutput;		/// Used for saving a field list's final output. Can be reused on next eval.
	UInt32 _finalOutputDirty = 0;

	//----------------------------------------------------------------------------------------
	/// Used for sharing very specific data that most fields won't use.
	/// The BaseContainer allows sharing more complex data types.
	//----------------------------------------------------------------------------------------
	typedef maxon::StrongRef<BaseContainer> CustomDataRef;
	CustomDataRef _customData;
	UInt32 _customDataDirty = 0;
};

/// The structure holding the arrays of points and optionally their directions to be sampled.
/// Caller owns the pointed data and must ensure they are valid. FieldInput will not deallocate the data under
/// any circumstance.
struct FieldInput
{
public:
	FieldInput() = default;

	//----------------------------------------------------------------------------------------
	/// Constructor with single position value
	/// @param[in] pos								The position.
	/// @param[in] transform					(Optional) The transform matrix required to convert the position and direction inputs to global space.
	//----------------------------------------------------------------------------------------
	FieldInput(const Vector& pos, Matrix transform = Matrix())
		: _position(&pos, 1), _blockCount(1), _fullArraySize(1), _transform(transform), _allocatedArraySize(1) { }

	//----------------------------------------------------------------------------------------
	/// Constructor with position data only.
	/// @param[in] pos								The position array to sample.
	/// @param[in] allocatedCount			The allocated length of the pos array.
	/// @param[in] transform					The transform matrix required to convert the position and direction inputs to global space.
	/// @param[in] fullCount					The full position count if count was to big to allocate in pos. Will be
	/// 															allocatedCount unless specified otherwise.
	//----------------------------------------------------------------------------------------
	FieldInput(const Vector* pos, Int allocatedCount, Matrix transform = Matrix(), Int fullCount = 0)
		: _position(pos, allocatedCount), _blockCount(allocatedCount), _fullArraySize(Max(allocatedCount, fullCount)), _transform(transform), _allocatedArraySize(allocatedCount)
	{
		DebugAssert(IsValid());
	}

	//----------------------------------------------------------------------------------------
	/// Constructor with single position and direction
	/// @param[in] pos								The position.
	/// @param[in] dir								The direction that the sample is facing in space.
	/// @param[in] transform					(Optional) The transform matrix required to convert the position and direction inputs to global space.
	//----------------------------------------------------------------------------------------
	FieldInput(const Vector& pos, const Vector& dir, Matrix transform = Matrix())
		: _position(&pos, 1), _direction(&dir, 1), _blockCount(1), _fullArraySize(1), _transform(transform), _allocatedArraySize(1) { }

	//----------------------------------------------------------------------------------------
	/// Constructor with position and direction data.
	/// @param[in] pos								The position array to sample.
	/// @param[in] dir								The direction array to sample.
	/// @param[in] allocatedCount			The allocated length of the pos and dir arrays.
	/// @param[in] transform					The transform matrix required to convert the position and direction inputs to global space.
	/// @param[in] fullCount					The full position count if count was to big to allocate in pos. Will be
	/// 															allocatedCount unless specified otherwise.
	//----------------------------------------------------------------------------------------
	FieldInput(const Vector* pos, const Vector* dir, Int allocatedCount, Matrix transform = Matrix(), Int fullCount = 0)
		: _position(pos, allocatedCount), _direction(dir, dir ? allocatedCount : 0), _blockCount(allocatedCount), _fullArraySize(Max(allocatedCount, fullCount)), _transform(transform), _allocatedArraySize(allocatedCount)
	{
		DebugAssert(IsValid());
	}

	//----------------------------------------------------------------------------------------
	/// Constructor with single position, direction and UVW entry
	/// @param[in] pos								The position array to sample.
	/// @param[in] dir								The direction array to sample.
	/// @param[in] uvw								The uvw array to sample.
	/// @param[in] transform					The transform matrix required to convert the position and direction inputs to global space.
	//----------------------------------------------------------------------------------------
	FieldInput(const Vector& pos, const Vector& dir, const Vector& uvw, Matrix transform = Matrix())
		: _position(&pos, 1), _direction(&dir, 1), _uvw(&uvw, 1), _blockCount(1), _fullArraySize(1), _transform(transform), _allocatedArraySize(1) { }

	//----------------------------------------------------------------------------------------
	/// Constructor with position, direction and uvw data.
	/// @param[in] pos								The position array to sample.
	/// @param[in] dir								The direction array to sample.
	/// @param[in] uvw								The uvw array to sample.
	/// @param[in] allocatedCount			The allocated length of the pos and dir arrays.
	/// @param[in] transform					The transform matrix required to convert the position and direction inputs to global space.
	/// @param[in] fullCount					(optional) The full position count if count was to big to allocate in pos. Will be
	/// 															allocatedCount unless specified otherwise.
	//----------------------------------------------------------------------------------------
	FieldInput(const Vector* pos, const Vector* dir, const Vector* uvw, Int allocatedCount, Matrix transform = Matrix(), Int fullCount = 0)
		: _position(pos, allocatedCount), _direction(dir, dir ? allocatedCount : 0), _uvw(uvw, uvw ? allocatedCount : 0), _blockCount(allocatedCount), _fullArraySize(Max(allocatedCount, fullCount)), _transform(transform), _allocatedArraySize(allocatedCount)
	{
		DebugAssert(IsValid());
	}

//----------------------------------------------------------------------------------------
/// Constructor with position, direction and uvw data.
/// @param[in] pos								The position array to sample.
/// @param[in] dir								The direction array to sample.
/// @param[in] uvw								The uvw array to sample.
/// @param[in] allocatedCount			The allocated length of the pos and dir arrays.
/// @param[in] transform					The transform matrix required to convert the position and direction inputs to global space.
/// @param[in] fullCount					(optional) The full position count if count was to big to allocate in pos. Will be
/// 															allocatedCount unless specified otherwise.
//----------------------------------------------------------------------------------------
	FieldInput(const Vector* pos, const maxon::Block<const Vector>& dir, const maxon::Block<const Vector>& uvw, Int allocatedCount, Matrix transform = Matrix(), Int fullCount = 0)
		: _position(pos, allocatedCount), _direction(dir), _uvw(uvw), _blockCount(allocatedCount), _fullArraySize(Max(allocatedCount, fullCount)), _transform(transform), _allocatedArraySize(allocatedCount)
	{
		DebugAssert(IsValid());
	}

	//----------------------------------------------------------------------------------------
	/// Constructor with position, direction and uvw data.
	/// @param[in] pos								The position array to sample.
	/// @param[in] dir								The direction array to sample.
	/// @param[in] uvw								The uvw array to sample.
	/// @param[in] allocatedCount			The allocated length of the pos and dir arrays.
	/// @param[in] transform					The transform matrix required to convert the position and direction inputs to global space.
	/// @param[in] fullCount					(optional) The full position count if count was to big to allocate in pos. Will be
	/// 															allocatedCount unless specified otherwise.
	//----------------------------------------------------------------------------------------
	FieldInput(const maxon::Block<const Vector>& pos, const maxon::Block<const Vector>& dir, const maxon::Block<const Vector>& uvw, Int allocatedCount, Matrix transform = Matrix(), Int fullCount = 0)
		: _position(pos), _direction(dir), _uvw(uvw), _blockCount(allocatedCount), _fullArraySize(Max(allocatedCount, fullCount)), _transform(transform), _allocatedArraySize(allocatedCount)
	{
		DebugAssert(IsValid());
	}

	/// Destructor. FieldInput owns no memory.
	~FieldInput() = default;

	//----------------------------------------------------------------------------------------
	/// Copy constructor
	/// NOTE: This performs a dumb raw copy of the FieldInput instance.
	/// I.e. internal pointers will be copied and point to the content of the original owner.
	/// Field point never owns the data, this is why a standard CopyFrom is not part of this class.
	/// @param[in] src								Copy source.
	//----------------------------------------------------------------------------------------
	FieldInput(const FieldInput& src) : MAXON_COPY_MEMBERS(_position, _direction, _uvw, _blockCount, _blockOffset, _fullArraySize, _transform, _allocatedArraySize) { }

	//----------------------------------------------------------------------------------------
	/// Move constructor
	/// @param[in] src								Move source.
	//----------------------------------------------------------------------------------------
	FieldInput(FieldInput&& src) : MAXON_MOVE_MEMBERS(_position, _direction, _uvw, _blockCount, _blockOffset, _fullArraySize, _transform, _allocatedArraySize) { }

	MAXON_OPERATOR_MOVE_ASSIGNMENT(FieldInput);
	MAXON_OPERATOR_COPY_ASSIGNMENT(FieldInput);

	//----------------------------------------------------------------------------------------
	/// Performs a raw copy of the the FieldInput described by src. Equivalent to copy construction.
	/// NOTE: this is not a CopyFrom, see copy constructor note above.
	/// @param[in] src								Source for the duplication.
	//----------------------------------------------------------------------------------------
	void CopyFromRaw(const FieldInput& src);

	//----------------------------------------------------------------------------------------
	/// Return a FieldInput struct for a subset of the original array. This can be used
	/// to pass smaller blocks to the field processing threads.
	/// @param[in] offset							The subblock start offset in the full array (0 based).
	/// @param[in] blockSize					The size of the desired subblock.
	/// @return												The sub FieldInput structure. Will be empty if request is out of bounds.
	//----------------------------------------------------------------------------------------
	FieldInput GetSubBlock(Int offset, Int blockSize = FIELD_EXECUTION_BLOCK_SIZE) const;

	//----------------------------------------------------------------------------------------
	/// Gets the number of elements in the FieldInput
	/// @return												The count.
	//----------------------------------------------------------------------------------------
	inline Int GetCount() const { return _blockCount; }

	//----------------------------------------------------------------------------------------
	/// Gets the offset of the first element in the full arrays.
	/// @return												The offset.
	//----------------------------------------------------------------------------------------
	inline Int GetOffset() const { return _blockOffset; }

	//----------------------------------------------------------------------------------------
	/// Checks if the FieldInput allocations and sizes are valid. Empty FieldInput is considered valid.
	//----------------------------------------------------------------------------------------
	Bool IsValid() const;

	//----------------------------------------------------------------------------------------
	/// Checks if the FieldInput is valid and non-empty.
	//----------------------------------------------------------------------------------------
	Bool IsPopulated() const;

public:
	maxon::Block<const Vector> _position;		///< The position values for the array of points, if this is a sub-block then element 0 is at _blockOffset within the larger array, caller owns this array, size must match or be greater than count value @required
	maxon::Block<const Vector> _direction;	///< The (optional) direction values for the array of points, if this is a sub-block then element 0 is at _blockOffset within the larger array, caller owns this array, size must match or be greater than count value.
	maxon::Block<const Vector> _uvw;				///< The (optional) uvw values for the array of points, if this is a sub-block then element 0 is at _blockOffset within the larger array, caller owns this array, size must match or be greater than count value.
	Int						_blockCount = 0;					///< The number of elements in the array to be processed (for this processing block, this should be treated as the count to use when iterating over elements in FieldObject and FieldLayer.
	Int						_blockOffset = 0;					///< The offset (starting point) of the elements if a portion of a larger array, used e.g. to get the actual index in the array actualIndex = index - points._blockOffset;
	Int						_fullArraySize = 0;				///< The full size of the source data, this may be larger than blockCount, also might be larger then the size of the allocated pointers within the FieldInput class. Do no use this size to browse the arrays!
	Matrix				_transform;								///< The transform matrix for the points in the input block, use this to bring the _position and _direction arrays into world space or the local space of your FieldObject

private:
	Int						_allocatedArraySize = 0;	///< The allocated size of the vector arrays. Use this with _blockOffset to browse all the input vectors safely. Might be larger than blockCount.
};

//----------------------------------------------------------------------------------------
/// Structure for passing the linked object information within a FieldLayer if it uses another
/// object within the scene, e.g. standard FieldObject layers.
//----------------------------------------------------------------------------------------
struct FieldLayerLink
{
	FieldLayerLink() { }
	FieldLayerLink(BaseList2D* op) : _object(op) { }
	FieldLayerLink(BaseList2D* op, GeData data) : _object(op), _secondaryData(data) { }

	BaseList2D* _object = nullptr;	///< The linked object
	GeData			_secondaryData;			///< secondary data such as e.g. a DescID or other useful information relevant to the FieldLayer
};

//----------------------------------------------------------------------------------------
/// A list of all of the "callers" i.e. objects that invoked the sampling function.
/// Additionally contains an identifier one way hash created to generate a unique ID based on the objects invoking the
/// sampling, you can append additional addresses/objects using the operator + and += functions in
/// order to continue the chain and ensure that the caller ID remains unique within the FieldInfo
/// for each call chain.
//----------------------------------------------------------------------------------------
class FieldCallerStack
{
	MAXON_DISALLOW_COPY_AND_ASSIGN(FieldCallerStack);

public:
	FieldCallerStack() = default;
	explicit FieldCallerStack(UInt value)
	{
		_value = value;
	}
	FieldCallerStack(FieldCallerStack&& src)
		: MAXON_MOVE_MEMBERS(_value, _callers)
	{
		src._value = 0;
	}
	~FieldCallerStack() = default;

	MAXON_OPERATOR_MOVE_ASSIGNMENT(FieldCallerStack);

	//----------------------------------------------------------------------------------------
	/// Creates an empty FieldCallerStack. Cannot fail. Same as using default constructor.
	/// @return												A maxon::Result<FieldCallerStack>.
	//----------------------------------------------------------------------------------------
	static FieldCallerStack Create()
	{
		FieldCallerStack stack;
		return stack;
	}

	//----------------------------------------------------------------------------------------
	/// Creates a FieldCallerStack while relaying potential allocation errors.
	/// On error, the result will contain a default FieldCallerStack structure.
	/// @param[in] caller							The first caller for the stack.
	/// @return												A maxon::Result<FieldCallerStack>.
	//----------------------------------------------------------------------------------------
	static maxon::Result<FieldCallerStack> Create(const BaseList2D* caller)
	{
		iferr_scope;
		FieldCallerStack stack;
		stack.Add(caller) iferr_return;
		return std::move(stack);
	}

	//----------------------------------------------------------------------------------------
	/// Creates a FieldCallerStack while relaying potential allocation errors.
	/// On error, the result will contain a default FieldCallerStack structure.
	/// @param[in] callers						An initializer list to build the stack, first item is base of stack.
	/// @return												A maxon::Result<FieldCallerStack>.
	//----------------------------------------------------------------------------------------
	static maxon::Result<FieldCallerStack> Create(const std::initializer_list<const BaseList2D*>& callers)
	{
		iferr_scope;
		FieldCallerStack stack;
		for (auto caller : callers)
		{
			stack.Add(caller) iferr_return;
		}
		return std::move(stack);
	}

	//----------------------------------------------------------------------------------------
	/// Copies from the supplied FieldCallerStack.
	/// @param[in] src								The source.
	/// @return												A maxon::Result.
	//----------------------------------------------------------------------------------------
	maxon::Result<void> CopyFrom(const FieldCallerStack& src);

	//----------------------------------------------------------------------------------------
	/// Returns an element of the stack.
	/// @param[in] index							The caller index.
	/// @return												The element.
	//----------------------------------------------------------------------------------------
	const BaseList2D* operator[](Int index) const
	{
		DebugAssert(_callers.GetCount() > 0);
		index = index % _callers.GetCount();
		return _callers[index];
	}

	//----------------------------------------------------------------------------------------
	/// Cast to UInt, return the value of the stack.
	/// @return												The stack value.
	//----------------------------------------------------------------------------------------
	operator const UInt&() const { return _value; }

	//----------------------------------------------------------------------------------------
	/// Calculates the id of the caller stack from scratch. Does not update stored id value.
	/// @return												The new id.
	//----------------------------------------------------------------------------------------
	UInt RecalcValue() const;

	//----------------------------------------------------------------------------------------
	/// Recalculates the id of the caller stack from scratch.
	/// Will update the internal stack id value.
	//----------------------------------------------------------------------------------------
	void UpdateValue();

	//----------------------------------------------------------------------------------------
	/// Calculates a new stack id from the current id and the added caller.
	/// Can be used to calculate a stack id without carrying the actual BaseList2d stack.
	/// @param[in] caller							The new caller, assuming already added to stack.
	//----------------------------------------------------------------------------------------
	void UpdateValue(const BaseList2D* caller);

	//----------------------------------------------------------------------------------------
	/// Adds a caller to the caller stack and updates the stack id.
	/// @param[in] caller							The caller object to add to the stack.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	maxon::Result<void> Add(const BaseList2D* caller);

	//----------------------------------------------------------------------------------------
	/// Adds a caller to the caller stack and returns a modified stack.
	/// This function hides the memory management iferr statement by returning
	/// an empty FieldCallerStack if an error occurs. It can be used within a field sampling call directly.
	/// But it is recommended to use the non static version and avoid any field sampling call if a prior memory
	/// error occurred.
	/// @param[in] src								The original stack.
	/// @param[in] newCaller					The caller object to add to the stack.
	/// @return												A new stack passed by move constructor. Stack will be empty if internal error occurred.
	//----------------------------------------------------------------------------------------
	static FieldCallerStack Add(const FieldCallerStack& src, const BaseList2D* newCaller);

	//----------------------------------------------------------------------------------------
	/// Returns the number of callers involved in this chain.
	/// @return												The number of callers.
	//----------------------------------------------------------------------------------------
	inline Int GetCount() const { return _callers.GetCount(); }

	//----------------------------------------------------------------------------------------
	/// Returns the caller stack id.
	/// @return												The id.
	//----------------------------------------------------------------------------------------
	inline UInt GetValue() const { return _value; }

	//----------------------------------------------------------------------------------------
	/// Check for valid stack content.
	/// Empty stack is valid.
	/// Stack with null pointers is not valid.
	/// Non empty stack with no stack id value is not valid.
	/// @return												True if valid.
	//----------------------------------------------------------------------------------------
	Bool IsValid() const;

public:
	UInt																_value = 0;	///< Caller stack id.
	maxon::BaseArray<const BaseList2D*> _callers;		///< Detailed stack for id _value.
};

//----------------------------------------------------------------------------------------
/// Thread local information for this field sample invocation.
//----------------------------------------------------------------------------------------
struct FieldInfo
{
public:
	FieldInfo() = default;
	FieldInfo(FieldInfo&& src)
		: MAXON_MOVE_MEMBERS(_flags, _threadIndex, _totalThreadCount, _callerThread, _doc, _inputData, _callerStack)
	{
		src._flags = FIELDSAMPLE_FLAG::VALUE;
		src._doc = nullptr;
		src._callerThread = nullptr;
	}
	~FieldInfo() = default;

	MAXON_OPERATOR_MOVE_ASSIGNMENT(FieldInfo);

	//----------------------------------------------------------------------------------------
	/// Checks if the FieldInfo data is valid. Default (empty) FieldInfo is considered valid.
	//----------------------------------------------------------------------------------------
	Bool IsValid() const;

	//----------------------------------------------------------------------------------------
	/// Checks if the FieldInfo is valid and non-empty (all content should be set and ready for sampling)
	//----------------------------------------------------------------------------------------
	Bool IsPopulated() const;

	//----------------------------------------------------------------------------------------
	/// Copies content from the supplied FieldInfo.
	/// @param[in] src								The source info.
	/// @return												A maxon::Result.
	//----------------------------------------------------------------------------------------
	maxon::Result<void> CopyFrom(const FieldInfo& src);

	//----------------------------------------------------------------------------------------
	/// Creates a FieldInfo while relaying potential allocation errors. On error, the result will
	/// contain a default FieldInfo structure.
	/// @param[in] caller							The caller object, should belong to the document being used.
	/// @param[in] callingFlags				(Optional) The channel sampling flags expected to be used for sampling.
	/// @return												A maxon::Result containing the resulting FieldInfo, _inputData will not be populated,
	/// 				if you use this with the "Direct" sampling methods of the FieldList without populating
	/// 				_inputData you will encounter problematic behavior that could lead to crashes.
	//----------------------------------------------------------------------------------------
	static maxon::Result<FieldInfo> Create(BaseList2D* caller, FIELDSAMPLE_FLAG callingFlags = FIELDSAMPLE_FLAG::VALUE);

	//----------------------------------------------------------------------------------------
	/// Creates a FieldInfo while relaying potential allocation errors. On error, the result will contain a
	/// default FieldInfo structure.
	/// @param[in] caller							The caller object, should belong to the document being used.
	/// @param[in] inputs							The inputs that will be sampled.
	/// @param[in] callingFlags				(Optional) The channel sampling flags expected to be used for sampling.
	/// @param[in] threadIndex				(Optional) Zero-based index of the thread within the current MP loop
	/// 															alternatively just 0 for the initial thread.
	/// @param[in] threadCount				(Optional) Number of threads to be used, 0 or lower to automatically calculate
	/// 															for MP invocation.
	/// @return												A maxon::Result containing the resulting FieldInfo.
	//----------------------------------------------------------------------------------------
	static maxon::Result<FieldInfo> Create(BaseList2D* caller, const FieldInput& inputs, FIELDSAMPLE_FLAG callingFlags = FIELDSAMPLE_FLAG::VALUE, Int threadIndex = 0, Int threadCount = 0);

	//----------------------------------------------------------------------------------------
	/// Creates a FieldInfo while relaying potential allocation errors. On error, the result will contain a
	/// default FieldInfo structure.
	/// @param[in] caller							The caller object, should belong to the document being used.
	/// @param[in] doc								The document to sample.
	/// @param[in] callingFlags				The channel sampling flags expected to be used for sampling.
	/// @param[in] inputs							The inputs that will be sampled.
	/// @return												A maxon::Result containing the resulting FieldInfo.
	//----------------------------------------------------------------------------------------
	static maxon::Result<FieldInfo> Create(BaseList2D* caller, BaseDocument* doc, FIELDSAMPLE_FLAG callingFlags, const FieldInput& inputs);

	//----------------------------------------------------------------------------------------
	/// Creates a FieldInfo while relaying potential allocation errors. On error, the result will contain a
	/// default FieldInfo structure.
	/// @param[in] caller							The caller stack object.
	/// @param[in] doc								The document to sample.
	/// @param[in] callingFlags				The channel sampling flags expected to be used for sampling.
	/// @param[in] inputs							The inputs that will be sampled.
	/// @return												A maxon::Result containing the resulting FieldInfo.
	//----------------------------------------------------------------------------------------
	static maxon::Result<FieldInfo> Create(const FieldCallerStack& caller, BaseDocument* doc, FIELDSAMPLE_FLAG callingFlags, const FieldInput& inputs);

	//----------------------------------------------------------------------------------------
	/// Creates an incomplete FieldInfo that the user has to fill in with a FieldCallerStack.
	/// This overload cannot fail.
	/// @param[in] callingFlags				The channels to sample.
	/// @param[in] thread							The caller thread.
	/// @param[in] document						The document to sample.
	/// @param[in] currentThreadIndex	The thread index that will sample those points.
	/// @param[in] threadCount				The total thread count.
	/// @param[in] inputs							The full point list.
	/// @return												The created FieldInfo.
	//----------------------------------------------------------------------------------------
	static FieldInfo Create(FIELDSAMPLE_FLAG callingFlags, BaseThread* thread, BaseDocument* document, Int currentThreadIndex, Int threadCount, const FieldInput& inputs = FieldInput())
	{
		FieldInfo newInfo;
		newInfo._flags = callingFlags;
		newInfo._callerThread = thread;
		newInfo._doc = document;
		newInfo._threadIndex = currentThreadIndex;
		newInfo._totalThreadCount = threadCount;
		newInfo._inputData = inputs;
		return newInfo;
	}

	//----------------------------------------------------------------------------------------
	/// Creates a FieldInfo while relaying potential allocation errors.
	/// On error, the result will contain a default FieldInfo structure.
	/// @param[in] callingFlags				The channels to sample.
	/// @param[in] thread							The caller thread.
	/// @param[in] doc								The document to sample.
	/// @param[in] currentThreadIndex	The thread index that will sample those points.
	/// @param[in] threadCount				The total thread count.
	/// @param[in] inputs							The full point list.
	/// @param[in] caller							The caller stack.
	/// @return												A maxon::Result containing the resulting FieldInfo.
	//----------------------------------------------------------------------------------------
	static maxon::Result<FieldInfo> Create(FIELDSAMPLE_FLAG callingFlags, BaseThread* thread, BaseDocument* doc, Int currentThreadIndex, Int threadCount, const FieldInput& inputs, const FieldCallerStack& caller)
	{
		iferr_scope;

		FieldInfo newInfo(Create(callingFlags, thread, doc, currentThreadIndex, threadCount, inputs));
		newInfo._callerStack.CopyFrom(caller) iferr_return;
		return std::move(newInfo);
	}

//----------------------------------------------------------------------------------------
/// Creates a FieldInfo while relaying potential allocation errors.
/// On error, the result will contain a default FieldInfo structure.
/// @param[in] callingFlags				The channels to sample.
/// @param[in] thread							The caller thread.
/// @param[in] doc								The document to sample.
/// @param[in] currentThreadIndex	The thread index that will sample those points.
/// @param[in] threadCount				The total thread count.
/// @param[in] inputs							The full point list.
/// @param[in] callers						An initializer list to build the stack, first item is base of stack.
/// @return												A maxon::Result containing the resulting FieldInfo.
//----------------------------------------------------------------------------------------
	static maxon::Result<FieldInfo> Create(FIELDSAMPLE_FLAG callingFlags, BaseThread* thread, BaseDocument* doc, Int currentThreadIndex, Int threadCount, const FieldInput& inputs, const std::initializer_list<BaseList2D*>& callers)
	{
		iferr_scope;

		FieldCallerStack stack = FieldCallerStack::Create();
		for (auto caller : callers)
		{
			stack.Add(caller) iferr_return;
		}
		FieldInfo newInfo(Create(callingFlags, thread, doc, currentThreadIndex, threadCount, inputs));
		newInfo._callerStack = std::move(stack);
		return std::move(newInfo);
	}

private:
	MAXON_DISALLOW_COPY_AND_ASSIGN(FieldInfo);

public:
	FIELDSAMPLE_FLAG _flags = FIELDSAMPLE_FLAG::ALL;	///< The current flags represent which channels are available and should be sampled
	Int							 _threadIndex = 0;								///< The current thread index
	Int							 _totalThreadCount = 1;						///< The number of threads active for this execution
	BaseThread*			 _callerThread = nullptr;					///< The calling thread @required
	BaseDocument*		 _doc = nullptr;									///< The calling document @required
	FieldInput			 _inputData;											///< The input data to be sampled, caller owns this object @required
	FieldCallerStack _callerStack;										///< A list of objects that called this calculation as well as an ID for the invocation chain, useful if you need to hash data to a specific caller, this uses the memory addresses of the callers so the value could change on undo/redo and will change on document load @required
};

#ifdef __API_INTERN__
class BaseObject;
class FieldObject;
#else

	#include "c4d_baseobject.h"
	#include "c4d_basetag.h"

	#define LIB_FIELD	440000199

class FieldObject : public BaseObject
{
	MAXON_DISALLOW_COPY_AND_ASSIGN(FieldObject);

	FieldObject();
	~FieldObject();

public:
	//----------------------------------------------------------------------------------------
	/// @allocatesA{Field object}
	/// @param[in] type								The field type.
	/// @return												@allocReturn{Field object}
	//----------------------------------------------------------------------------------------
	static FieldObject* Alloc(Int32 type)
	{
		return static_cast<FieldObject*>(C4DOS.Bo->Alloc(type));
	}

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{Field object}
	/// @param[in,out] field					@theToDestruct{Field object}
	//----------------------------------------------------------------------------------------
	static void Free(FieldObject*& field)
	{
		C4DOS.Bl->Free(field);
		field = nullptr;
	}

	//----------------------------------------------------------------------------------------
	/// Initializes Field Sampling, this must be called before Sample is invoked on any field object.
	/// FreeSampling must be called afterwards.
	/// @param[in] info								The FieldInfo structure to initialize with.
	/// @param[in,out] shared					Data shared between fields/layers.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	maxon::Result<void> InitSampling(const FieldInfo& info, FieldShared& shared) { return BoCall (FiInitSampling)(info, shared); }

	//----------------------------------------------------------------------------------------
	/// Frees any memory allocated in InitSampling. This must be called after InitSampling has been
	/// invoked.
	/// @param[in] info								The FieldInfo structure used for initialization and sampling.
	/// @param[in,out] shared					Data shared between fields/layers.
	//----------------------------------------------------------------------------------------
	void FreeSampling(const FieldInfo& info, FieldShared& shared) { BoCall (FiFreeSampling)(info, shared); }

	//----------------------------------------------------------------------------------------
	/// Samples an array of points within the field. InitSampling must be called before invocation, and FreeSampling must can called once all sampling
	/// is complete. NOTE: Sample does not receive the SharedData. If a field needs access to it, it can keep a reference on it or copy parts of it in
	/// InitSampling.
	/// @param[in] inputs							The points to sample in global space.
	/// @param[out] outputs						The output result values, should be allocated prior to usage.
	/// @param[in] info								The FieldInfo structure, containing useful information for sampling, this should match the structure used in InitSampling.
	/// @param[in] objectSampleFlags	The object sample flags.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	maxon::Result<void> Sample(const FieldInput& inputs, FieldOutputBlock& outputs, const FieldInfo& info, const FIELDOBJECTSAMPLE_FLAG& objectSampleFlags = FIELDOBJECTSAMPLE_FLAG::NONE) const { return BoCall (FiSample)(inputs, outputs, info, objectSampleFlags); }

	//----------------------------------------------------------------------------------------
	/// Gets the FIELDOBJECT_FLAG flags for this object.
	/// @param[in] doc								If non-null, the document.
	/// @return												The field flags.
	//----------------------------------------------------------------------------------------
	FIELDOBJECT_FLAG GetFieldFlags(BaseDocument* doc) const { return BoCall (FiGetFlags)(doc); }
};

class FieldLayer : public BaseList2D
{
	MAXON_DISALLOW_COPY_AND_ASSIGN(FieldLayer);

	FieldLayer();
	~FieldLayer();

public:
	//----------------------------------------------------------------------------------------
	/// Gets the parent FieldLayer in the FieldList
	/// @return												nullptr if there is no parent, else the parent.
	//----------------------------------------------------------------------------------------
	FieldLayer* GetUp() const { return FLCall (GetUp)(); }

	//----------------------------------------------------------------------------------------
	/// Gets the first child of the FieldLayer in the FieldList
	/// @return												nullptr if there are no children, else the first child.
	//----------------------------------------------------------------------------------------
	FieldLayer* GetDown() const { return FLCall (GetDown)(); }

	//----------------------------------------------------------------------------------------
	/// Gets the next FieldLayer in the FieldList
	/// @return												nullptr if this is the final FieldLayer at the current level, otherwise the next sibling.
	//----------------------------------------------------------------------------------------
	FieldLayer* GetNext() const { return FLCall (GetNext)(); }

	//----------------------------------------------------------------------------------------
	/// Gets the previous FieldLayer in the FieldList
	/// @return												nullptr if this is the first FieldLayer at the current level, otherwise the previous sibling.
	//----------------------------------------------------------------------------------------
	FieldLayer* GetPred() const { return FLCall (GetPred)(); }

	//----------------------------------------------------------------------------------------
	/// Gets the last child of the FieldLayer in the FieldList
	/// @return												nullptr if there are no children, else the last child.
	//----------------------------------------------------------------------------------------
	FieldLayer* GetDownLast() const { return FLCall (GetDownLast)(); }

	//----------------------------------------------------------------------------------------
	/// Gets the FieldLayer's strength in the FieldList
	/// @return												The strength in percent.
	//----------------------------------------------------------------------------------------
	Float GetStrength() const { return FLCall (GetStrength)(); }

	//----------------------------------------------------------------------------------------
	/// Sets a the FieldLayer's blending strength.
	/// @param[in] strength						The strength to set in percent.
	//----------------------------------------------------------------------------------------
	void SetStrength(Float strength) { FLCall (SetStrength)(strength); }

	//----------------------------------------------------------------------------------------
	/// Gets the FieldLayers blending mode in the FieldList
	/// @return												The blending mode, see Flbase.h/res.
	//----------------------------------------------------------------------------------------
	Int32 GetBlendingMode() const { return FLCall (GetBlendingMode)(); }

	//----------------------------------------------------------------------------------------
	/// Sets FieldLayer's blending mode
	/// @param[in] blendingMode				The blending mode, see FLbase.h/res.
	//----------------------------------------------------------------------------------------
	void SetBlendingMode(Int32 blendingMode) { FLCall (SetBlendingMode)(blendingMode); }

	//----------------------------------------------------------------------------------------
	/// @markprivate
	//----------------------------------------------------------------------------------------
	Int32 GetUniqueID() const { return FLCall (GetUniqueID)(); }

	//----------------------------------------------------------------------------------------
	/// @markprivate
	//----------------------------------------------------------------------------------------
	void SetUniqueID(Int32 id) { FLCall (SetUniqueID)(id); }

	//----------------------------------------------------------------------------------------
	/// Gets the enable state flags for the layers channel, e.g. the overall on/off (enable) or value, color
	/// and slope states
	/// @return												The channel flags for the layer see FIELDLAYER_CHANNELFLAG.
	//----------------------------------------------------------------------------------------
	FIELDLAYER_CHANNELFLAG GetChannelFlags() const { return FLCall (GetChannelFlags)(); }

	//----------------------------------------------------------------------------------------
	/// Sets channel flags to the passed FIELDLAYER_CHANNELFLAG value
	/// @param[in] flags							The flags state to be set for this layer.
	//----------------------------------------------------------------------------------------
	void SetChannelFlags(FIELDLAYER_CHANNELFLAG flags) { FLCall (SetChannelFlags)(flags); }

	//----------------------------------------------------------------------------------------
	/// Gets a specific channel enabling state flag for the layer. e.g. the enable, value, color or slope states
	/// @param[in] flag								The flag to retrieve.
	/// @return												True if the flag is set, False if it is clear.
	//----------------------------------------------------------------------------------------
	Bool GetChannelFlag(FIELDLAYER_CHANNELFLAG flag) const { return FLCall (GetChannelFlag)(flag); }

	//----------------------------------------------------------------------------------------
	/// Sets a specific channel flag state for the layer, e.g. the overall enabling, value, color or slope
	/// states
	/// @param[in] flag								The flag to set or clear.
	/// @param[in] state							(Optional) True to set the state to on, False to disable (clear) the flag for the layer.
	//----------------------------------------------------------------------------------------
	void SetChannelFlag(FIELDLAYER_CHANNELFLAG flag, Bool state = true) { FLCall (SetChannelFlag)(flag, state); }

	//----------------------------------------------------------------------------------------
	/// Initializes the Field Sampling, Must be called prior to invoking the Sample function. FreeSampling must
	/// be called to free any memory allocated during InitSampling after this.
	/// @param[in] info								A fully populated FieldInfo structure.
	/// @param[in,out] shared					Data shared between fields/layers.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	maxon::Result<void> InitSampling(const FieldInfo& info, FieldShared& shared) { return FLCall (InitSampling)(info, shared); }

	//----------------------------------------------------------------------------------------
	/// Samples the FieldLayer. InitSampling must be called prior to use, and FreeSampling must be called after use.
	/// NOTE: Sample does not receive the SharedData. If a layer needs access to it,
	/// it can keep a reference on it or copy parts of it in InitSampling.
	/// @param[in] inputs							The points to sample in global space.
	/// @param[in,out] outputs				The output arrays, must be allocated prior to use.
	/// @param[in] info								A fully populated FieldInfo structure.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	maxon::Result<void> Sample(const FieldInput& inputs, FieldOutputBlock& outputs, const FieldInfo& info) const { return FLCall (Sample)(inputs, outputs, info); }

	//----------------------------------------------------------------------------------------
	/// @MarkPrivate
	/// @param[in] inputs							The inputs.
	/// @param[in] outputs						The outputs.
	/// @param[in] info								The information.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	maxon::Result<void> Aggregate(const FieldInput& inputs, const FieldOutputBlock& outputs, const FieldInfo& info) { return FLCall(Aggregate)(inputs, outputs, info); }

	//----------------------------------------------------------------------------------------
	/// Free's the Field Sampling. Releases any memory allocated during InitSampling.
	/// @param[in] info								A fully populated FieldInfo structure.
	/// @param[in,out] shared					Data shared between fields/layers.
	//----------------------------------------------------------------------------------------
	void FreeSampling(const FieldInfo& info, FieldShared& shared) { FLCall (FreeSampling)(info, shared); }

	//----------------------------------------------------------------------------------------
	/// Query if this layer is equal to another. Used by the undo system and to update dirtiness as required.
	/// @param[in] comp								The FieldLayer to compare to.
	/// @return												True if equal, false if not.
	//----------------------------------------------------------------------------------------
	Bool IsEqual(FieldLayer* comp) const { return FLCall (IsEqual)(comp); }

	//----------------------------------------------------------------------------------------
	/// Sets the layer display and execution flags, see FIELDLAYER_FLAG.
	/// @param[in] flags							The flags to set, see FIELDLAYER_FLAG.
	/// @param[in] state							(Optional) true to set, false to clear.
	//----------------------------------------------------------------------------------------
	void SetLayerFlags(FIELDLAYER_FLAG flags, Bool state = true) { FLCall (SetLayerFlags)(flags, state); }

	//----------------------------------------------------------------------------------------
	/// Gets the layer execution and display flags, see FIELDLAYER_FLAG.
	/// @return												The layer flags.
	//----------------------------------------------------------------------------------------
	FIELDLAYER_FLAG GetLayerFlags() const { return FLCall (GetLayerFlags)(); }

	//----------------------------------------------------------------------------------------
	/// If the FieldLayer links to another object in scene this function should return that object.
	/// This is used for it's GUI and to check dirtiness within the FieldList
	/// @param[in] doc								The document the FieldLayer belongs to.
	/// @return												The linked object and potentially secondary data in a FieldLayerLink structure.
	//----------------------------------------------------------------------------------------
	FieldLayerLink GetLinkedObject(BaseDocument* doc) const { return FLCall (GetLinkedObject)(doc); }

	//----------------------------------------------------------------------------------------
	/// If the FieldLayer accepts a linked object then this function sets that object. This is used
	/// for it's GUI and to check the dirtiness within the FieldList
	/// @param[in] link								A populated FieldLayerLink.
	/// @return												True if it succeeds, false if it fails.
	//----------------------------------------------------------------------------------------
	Bool SetLinkedObject(const FieldLayerLink& link) { return FLCall (SetLinkedObject)(link); }

	//----------------------------------------------------------------------------------------
	/// @allocatesA{Field layer}
	/// @param[in] type								The layer type.
	/// @return												@allocReturn{Field layer}
	//----------------------------------------------------------------------------------------
	static FieldLayer* Alloc(Int32 type)
	{
		return C4DOS.FL->Alloc(type);
	}

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{Field layer}
	/// @param[in,out] layer					@theToDestruct{Field layer}
	//----------------------------------------------------------------------------------------
	static void Free(FieldLayer*& layer)
	{
		C4DOS.Bl->Free(layer);
		layer = nullptr;
	}
	
	//----------------------------------------------------------------------------------------
	/// If the FieldLayer has a mask then this retrieve the listhead containing the mask layers.
	/// @return												The GeListHead containing the mask layers, nullptr if masks aren't active on this layer.
	//----------------------------------------------------------------------------------------
	GeListHead* GetMaskHead() const { return FLCall (GetMaskHead)(); }
	
	//----------------------------------------------------------------------------------------
	/// Adds a mask to the FieldLayer, if a mask already exists then this will do nothing.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	maxon::Result<void> AddMask() { return FLCall (AddMask)(); }
	
	//----------------------------------------------------------------------------------------
	/// Removes the mask on the FieldLayer, if no mask exists then this will do nothing.
	/// @param[in]	deleteLayers			true to delete the layers in the mask, false to retain them so that when enabled again via AddMask the layers will reappear.
	//----------------------------------------------------------------------------------------
	void RemoveMask(Bool deleteLayers = true) { FLCall (RemoveMask)(deleteLayers); }
};

// Message send if an individual function call of a processing function is incoming. This gives the opportunity to prepare any possible Fields sampling in that function for batch sampling.
// An example for this is dynamics force sampling. The Force sampling calls are individual calls for each object, but this gives a start and end message to simulate batch sampling.
static const Int32 MSG_PRESAMPLE_FIELD_SINGLE = 1050040; ///< Message to signal an impending invidual calls of an object list @correspondingData{PresampleFieldSingleData}
static const Int32 MSG_POSTSAMPLE_FIELD_SINGLE = 1050041; ///< Message to signal the end of individual calls of an object list

//----------------------------------------------------------------------------------------
/// Message struct for ::MSG_PRESAMPLE_FIELD_SINGLE.
//----------------------------------------------------------------------------------------
struct PresampleFieldSingleData
{
	maxon::BaseArray<Vector>* _samplePositions = nullptr;			///< Positions of impending object calls.
	BaseObject* _fieldsOwner = nullptr; ///< The object that will be registered as owner of the Fields sampling
};

#endif	// #ifdef __API_INTERN__
#endif // C4D_FIELDDATA_H__

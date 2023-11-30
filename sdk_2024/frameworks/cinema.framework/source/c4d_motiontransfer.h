/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef C4D_MOTIONTRANSFER_H__
#define C4D_MOTIONTRANSFER_H__

#ifdef __API_INTERN__
#error "Not in the kernel"
#endif

#include "c4d_basetag.h"
#include "operatingsystem.h"
#include "c4d_library.h"

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_BEGIN
#endif

class BaseObject;

enum class MTBODYPARTTRANSFERATTRIBUTEMODE : Int32
{
	BYID = 0,								///< Transfer using the ID.
	BYNAME,									///< Transfer using the Name.
	BOTH										///< Transfer using both technique.
} MAXON_ENUM_LIST(MTBODYPARTTRANSFERATTRIBUTEMODE);

struct MTBodyPartParameters
{
	maxon::Result<void> CopyFrom(const MTBodyPartParameters& src);

	// Body Part Identification
	maxon::InternedId							_identifier; // need to stay unique in hierarchy
	maxon::String									_name;

	// Skeleton and Controllers object
	maxon::BaseArray<BaseObject*>	_skeletonNodes;
	maxon::BaseArray<BaseObject*>	_controllerNodes;

	// automatic skeleton extraction keywords
	maxon::BaseArray<maxon::String> _skeletonKeywords;
	maxon::BaseArray<maxon::String> _skeletonDiscardKeywords;

	// Settings
	Bool _transferPosition = false;
	Bool _transferRotation = true;
	Bool _transferScale = false;
	Bool _exposeInSolver = false;
	Bool _transferUserData = false;
	MTBODYPARTTRANSFERATTRIBUTEMODE _transferUserDataMode = MTBODYPARTTRANSFERATTRIBUTEMODE::BYNAME;
};

class MTCharacterBodyPart
{
	MAXON_DISALLOW_COPY_AND_ASSIGN(MTCharacterBodyPart);
	MTCharacterBodyPart() = default;

public:
	MTCharacterBodyPart(MTCharacterBodyPart&& src) : MAXON_MOVE_MEMBERS(_parameters, _parent, _children) {}
	~MTCharacterBodyPart();

	/// @name Alloc/Free
	/// @{

	//----------------------------------------------------------------------------------------
	/// @allocatesA{MTCharacterBodyPart}
	/// @return												@allocReturn{MTCharacterBodyPart}
	//----------------------------------------------------------------------------------------
	static MTCharacterBodyPart* Alloc();

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{MTCharacterBodyPart}
	/// All the children will be freed.
	/// @param[in,out] ptr							@theToDestruct{MTCharacterBodyPart}
	//----------------------------------------------------------------------------------------
	static void Free(MTCharacterBodyPart*& ptr);

	/// @}

	/// @name Hierarchy helper
	/// @{

	//----------------------------------------------------------------------------------------
	/// Inserts the given child.
	/// @param[in] child							Child to insert.
	/// @return												OK on success
	//----------------------------------------------------------------------------------------
	maxon::Result<void> InsertChild(MTCharacterBodyPart* child);

	//----------------------------------------------------------------------------------------
	/// Deletes the child at the given index.
	/// @param[in] index							Child index.
	/// @return												OK on success
	//----------------------------------------------------------------------------------------
	maxon::Result<void> DeleteChild(Int index);

	//----------------------------------------------------------------------------------------
	/// Gets the child at the given index.
	/// @param[in] index							Child index.
	/// @return												the child body part pointer on success.
	//----------------------------------------------------------------------------------------
	maxon::Result<MTCharacterBodyPart*> GetChild(Int index) const { return _children[index]; }

	//----------------------------------------------------------------------------------------
	/// Gets the child count.
	/// @return												the child count.
	//----------------------------------------------------------------------------------------
	Int GetChildCount() const { return _children.GetCount(); }

	//----------------------------------------------------------------------------------------
	/// Gets the parent pointer if any.
	/// @return												parent pointer.
	//----------------------------------------------------------------------------------------
	MTCharacterBodyPart* GetParent() const { return _parent; }

	/// @}

	/// @name Parameters helper
	/// @{

	//----------------------------------------------------------------------------------------
	/// Sets the parameter for the body part.
	/// @param[in] param							parameters.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	maxon::Result<void> SetParameters(const MTBodyPartParameters& param) { return _parameters.CopyFrom(param); }

	//----------------------------------------------------------------------------------------
	/// Gets the parameters structure.
	/// @return												the body part parameters.
	//----------------------------------------------------------------------------------------
	MTBodyPartParameters& GetParameters() { return _parameters; }

	/// @}

private:
	// various Body Part parameters
	MTBodyPartParameters _parameters;

	// hierarchy data
	MTCharacterBodyPart* _parent = nullptr;
	maxon::BaseArray<MTCharacterBodyPart*> _children;
};

//----------------------------------------------------------------------------------------
/// Represents the Character Definition tag.
//----------------------------------------------------------------------------------------
class MTCharacterDefinitionTag : public BaseTag
{
private:
	MTCharacterDefinitionTag();
	~MTCharacterDefinitionTag();

public:
	/// @name Alloc/Free
	/// @{

	//----------------------------------------------------------------------------------------
	/// @allocatesA{MTCharacterDefinition tag}
	/// @return												@allocReturn{MTCharacterDefinition tag}
	//----------------------------------------------------------------------------------------
	static MTCharacterDefinitionTag* Alloc() { return (MTCharacterDefinitionTag*)BaseTag::Alloc(Tchardefinition); }

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{MTCharacterDefinition tag}
	/// @param[in,out] tag							@theToDestruct{MTCharacterDefinition tag}
	//----------------------------------------------------------------------------------------
	static void Free(MTCharacterDefinitionTag*& tag);

	/// @}


	/// @name Commands
	/// @{

	//----------------------------------------------------------------------------------------
	/// Automatic body part extraction for the skeleton.
	/// This should be called only in the main thread.
	/// @param[in] undo								Add Character definition to the undo stack before any changes.
	/// @return												OK on success
	//----------------------------------------------------------------------------------------
	maxon::Result<void> ExtractSkeleton(Bool undo);

	//----------------------------------------------------------------------------------------
	/// Gets current skeleton pose and set it as rest pose.
	/// This should be called only in the main thread.
	/// @param[in] undo								Add Character definition to the undo stack before any changes.
	/// @return												OK on success
	//----------------------------------------------------------------------------------------
	maxon::Result<void> ExtractRestPose(Bool undo);

	//----------------------------------------------------------------------------------------
	/// Applies the current rest pose.
	/// This should be called only in the main thread.
	/// @param[in] undo								Add Character definition to the undo stack before any changes.
	/// @return												OK on success
	//----------------------------------------------------------------------------------------
	maxon::Result<void> ApplyRestPose(Bool undo);

	//----------------------------------------------------------------------------------------
	/// Clears the current rest pose.
	/// This should be called only in the main thread.
	/// @param[in] undo								Add Character definition to the undo stack before any changes.
	/// @return												OK on success
	//----------------------------------------------------------------------------------------
	maxon::Result<void> ClearRestPose(Bool undo);

	//----------------------------------------------------------------------------------------
	/// Creates a solver and assign to the object owner.
	/// This should be called only in the main thread.
	/// @param[in] undo								Add Character definition to the undo stack before any changes.
	/// @return												new created MTCharacterMotionTransferTag on success
	//----------------------------------------------------------------------------------------
	maxon::Result<BaseTag*> CreateSolver(Bool undo);
	/// @}

	/// @name Helpers
	/// @{

	//----------------------------------------------------------------------------------------
	/// Returns a copy of the body part hierarchy.
	/// Memory management is on the client side, use MTCharacterBodyPart::Free() to avoid Leaks
	/// @return												MTCharacterBodyPart on success
	//----------------------------------------------------------------------------------------
	maxon::Result<MTCharacterBodyPart*> GetRootBodyPart();

	//----------------------------------------------------------------------------------------
	/// Sets the body part hierarchy.
	/// rootBodyPart is not kept, memory management is on the client side, use MTCharacterBodyPart::Free() to avoid Leaks.
	/// @param[in] rootBodyPart				MTCharacterBodyPart representing the BodyPart hierarchy.
	/// @return												OK on success
	//----------------------------------------------------------------------------------------
	maxon::Result<void> SetRootBodyPart(MTCharacterBodyPart& rootBodyPart);

	/// @}
};

class MTCharacterMotionTransferTag : public BaseTag
{
private:
	~MTCharacterMotionTransferTag() = delete;

public:
	/// @name Alloc/Free
	/// @{

	//----------------------------------------------------------------------------------------
	/// @allocatesA{MTCharacterDefinition tag}
	/// @return												@allocReturn{MTCharacterDefinition tag}
	//----------------------------------------------------------------------------------------
	static MTCharacterMotionTransferTag* Alloc() { return (MTCharacterMotionTransferTag*)BaseTag::Alloc(Tcharmotiontransfer); }

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{MTCharacterDefinition tags}
	/// @param[in,out] tag							@theToDestruct{MTCharacterDefinition tag}
	//----------------------------------------------------------------------------------------
	static void Free(MTCharacterMotionTransferTag*& tag);

	/// @}

	/// @name Body Part Settings 
	/// @{

	//----------------------------------------------------------------------------------------
	/// Returns BaseContainer containing the solver settings for the given identifier.
	/// use IDs starting with CS_BPSS_ in the returned container.
	/// @param[in] bodyPartIdentifier	Identifier used to get the body part settings.
	/// @return												BaseContainer containing solvers setting for the given part. nullptr if not exposed.
	//----------------------------------------------------------------------------------------
	maxon::Result<BaseContainer*> GetExposedBodyPartSettings(maxon::InternedId bodyPartIdentifier);

	//----------------------------------------------------------------------------------------
	/// Sets body part solver settings for an exposed body part.
	/// use IDs starting with CS_BPSS_ to configure the container.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	maxon::Result<void>	SetExposedBodyPartSettings(const BaseContainer& bodyPartSettings);

	/// @}

};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// Mocca library ID.
#define LIBRARY_MOCCA 1056374

struct MoccaLibrary : public C4DLibrary
{
	maxon::Result<void> (*ExtractSkeleton)(MTCharacterDefinitionTag* tag, Bool undo);
	maxon::Result<void> (*ExtractRestPose)(MTCharacterDefinitionTag* tag, Bool undo);
	maxon::Result<void> (*ApplyRestPose)(MTCharacterDefinitionTag* tag, Bool undo);
	maxon::Result<void> (*ClearRestPose)(MTCharacterDefinitionTag* tag, Bool undo);
	maxon::Result<BaseTag*> (*CreateSolver)(MTCharacterDefinitionTag* tag, Bool undo);
	maxon::Result<MTCharacterBodyPart*> (*GetRootBodyPart)(MTCharacterDefinitionTag* tag);
	maxon::Result<void> (*SetRootBodyPart)(MTCharacterDefinitionTag* tag, MTCharacterBodyPart& rootBodyPart);

	maxon::Result<BaseContainer*> (*GetExposedBodyPartSettings)(MTCharacterMotionTransferTag* tag, maxon::InternedId bodyPartIdentifier);
	maxon::Result<void>						(*SetExposedBodyPartSettings)(MTCharacterMotionTransferTag* tag, const BaseContainer& bodyPartSettings);
};

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_END
#endif

#endif // C4D_MOTIONTRANSFER_H__

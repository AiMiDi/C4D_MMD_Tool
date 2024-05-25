#include "c4d_memory.h"
#include "c4d_motiontransfer.h"
#include "maxon/errortypes.h"

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_BEGIN
#endif

//#define MTCall(fnc) (C4DOS_MT->fnc)

MoccaLibrary* g_mocca_library = nullptr;

#define MoccaCall(b) MoccaLibrary* lib = CheckMoccaLib(LIBOFFSET(MoccaLibrary, b)); \
	if (!lib || !lib->b) return maxon::UnknownError(MAXON_SOURCE_LOCATION, "Implementation not found"_s); \
	return (*lib->b)

#define MoccaCallR(a, b) MoccaLibrary* lib = CheckMoccaLib(LIBOFFSET(MoccaLibrary, b)); \
	if (!lib || !lib->b) return a; \
	return (*lib->b)

static MoccaLibrary* CheckMoccaLib(Int32 offset)
{
	return CheckLib<MoccaLibrary>(LIBRARY_MOCCA, offset, g_mocca_library);
}

maxon::Result<void> MTBodyPartParameters::CopyFrom(const MTBodyPartParameters& src)
{
	iferr_scope;

	_identifier = src._identifier;
	_name = src._name;
	_skeletonNodes.CopyFrom(src._skeletonNodes) iferr_return;
	_controllerNodes.CopyFrom(src._controllerNodes) iferr_return;
	_skeletonKeywords.CopyFrom(src._skeletonKeywords) iferr_return;
	_skeletonDiscardKeywords.CopyFrom(src._skeletonDiscardKeywords) iferr_return;

	_transferPosition = src._transferPosition;
	_transferRotation = src._transferRotation;
	_transferScale = src._transferScale;
	_exposeInSolver = src._exposeInSolver;
	_transferUserData = src._transferUserData;
	_transferUserDataMode = src._transferUserDataMode;
	return maxon::OK;
}

MTCharacterBodyPart* MTCharacterBodyPart::Alloc() { return new MTCharacterBodyPart; }
void MTCharacterBodyPart::Free(MTCharacterBodyPart*& ptr) { delete ptr; ptr = nullptr; }

maxon::Result<void> MTCharacterBodyPart::InsertChild(MTCharacterBodyPart* child)
{
	iferr_scope;
	CheckArgument(child);
	_children.Append(child) iferr_return;
	child->_parent = this;
	return maxon::OK;
}

maxon::Result<void> MTCharacterBodyPart::DeleteChild(Int index)
{
	MTCharacterBodyPart* child = _children[index];
	Free(child);
	return maxon::OK;
}

MTCharacterBodyPart::~MTCharacterBodyPart()
{
	if (_parent)
	{
		Int foundIndex = _parent->_children.FindIndex(this);
		if (foundIndex >= 0)
		{
			iferr (_parent->_children.Erase(foundIndex))
			{
				// never supposed to happen
			}
		}
	}
	for (MTCharacterBodyPart* child : _children)
	{
		child->_parent = nullptr;
		Free(child);
	}
}

void MTCharacterDefinitionTag::Free(MTCharacterDefinitionTag*& tag) 
{ 
	BaseTag* bTag = tag;
	BaseTag::Free(bTag); 
	tag = static_cast<MTCharacterDefinitionTag*>(bTag);
}

maxon::Result<void> MTCharacterDefinitionTag::ExtractSkeleton(Bool undo) { MoccaCall(ExtractSkeleton)(this, undo); }
maxon::Result<void> MTCharacterDefinitionTag::ExtractRestPose(Bool undo) { MoccaCall(ExtractRestPose)(this, undo); }
maxon::Result<void> MTCharacterDefinitionTag::ApplyRestPose(Bool undo) { MoccaCall(ApplyRestPose)(this, undo); }
maxon::Result<void> MTCharacterDefinitionTag::ClearRestPose(Bool undo) { MoccaCall(ClearRestPose)(this, undo); }
maxon::Result<BaseTag*> MTCharacterDefinitionTag::CreateSolver(Bool undo) { MoccaCall(CreateSolver)(this, undo); }
maxon::Result<MTCharacterBodyPart*> MTCharacterDefinitionTag::GetRootBodyPart() { MoccaCall(GetRootBodyPart)(this); }
maxon::Result<void> MTCharacterDefinitionTag::SetRootBodyPart(MTCharacterBodyPart& rootBodyPart) { MoccaCall(SetRootBodyPart)(this, rootBodyPart); }

void MTCharacterMotionTransferTag::Free(MTCharacterMotionTransferTag*& tag)
{
	BaseTag* bTag = tag;
	BaseTag::Free(bTag);
	tag = static_cast<MTCharacterMotionTransferTag*>(bTag);
}

maxon::Result<BaseContainer*> MTCharacterMotionTransferTag::GetExposedBodyPartSettings(maxon::InternedId bodyPartIdentifier)
{
	MoccaCall(GetExposedBodyPartSettings)(this, bodyPartIdentifier);
}

maxon::Result<void>	MTCharacterMotionTransferTag::SetExposedBodyPartSettings(const BaseContainer& bodyPartSettings)
{
	MoccaCall(SetExposedBodyPartSettings)(this, bodyPartSettings);
}


#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_END
#endif

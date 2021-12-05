#ifndef AUTOWEIGHT_H__
#define AUTOWEIGHT_H__

#include "maxon/apibase.h"
#include "maxon/objectbase.h"
#include "maxon/interfacebase.h"
#include "maxon/datadictionaryobject.h"
#include "maxon/datadescriptionobject.h"
#include "maxon/basebitset.h"

class BaseDocument;
class PolygonObject;
class SkinJoint;
namespace maxon
{
	
struct Bone
{
	Vector _position;							/// The position of the start of the bone
	Vector _direction;						/// The direction of the bone
	Float _oLen = 0.0_f;					/// The length of the bone.
	Int32 _jointIndex = NOTOK;		/// The joint index associated with the bone.
};

struct AutoWeightPointJointSelections
{
	MAXON_DISALLOW_COPY_AND_ASSIGN(AutoWeightPointJointSelections);
	BaseBitSet<> _pointSelection;		/// The point selection.
	BaseBitSet<> _jointSelection;		/// The joint selection.
	BaseBitSet<> _lockSelection;			/// The lock joint selection.
	Int32 _pointCount = 0;						/// The amount of points in the mesh.
	Int32 _jointCount = 0;						/// The amount of joints.
	AutoWeightPointJointSelections()
	{
	}
};

class AutoWeightInterface : MAXON_INTERFACE_BASES(DataDictionaryObjectInterface, DataDescriptionObjectInterface)
{
	MAXON_INTERFACE(AutoWeightInterface, MAXON_REFERENCE_NORMAL, "net.maxon.animation.interface.autoweight");

public:
	MAXON_FUNCTION Result<void> RunAutoWeight(BaseArray<BaseArray<Float>>& weights, BaseArray<BaseArray<Float>>& oldWeights, AutoWeightPointJointSelections& autoWeightPointJointSelections, const BaseArray<Bone>& bones, BaseDocument* doc, PolygonObject* op);

	//----------------------------------------------------------------------------------------
	/// Give the raw weight of the weighting algo.
	/// @param[out] weights				The resulting autoweight array.
	/// @param[in] doc						The base document.
	/// @param[in] op							The polygon object.
	/// @param[in] bones					A array of bone structure.
	/// @param[in] autoWeightPointJointSelections		The point joint lock selection
	/// @return										Error code if fail else OK.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> CalculateWeights(BaseArray<BaseArray<Float>>& weights, BaseDocument* doc, PolygonObject* op, const BaseArray<Bone>& bones, AutoWeightPointJointSelections &autoWeightPointJointSelections);
	
	//----------------------------------------------------------------------------------------
	/// Normalize the weights.
	/// @param[out] weights													The resulting autoweight array.
	/// @param[in] oldWeights												The previous weight array.
	/// @param[in] autoWeightPointJointSelections		The point joint lock selection
	/// @return																			Error code if fail else OK.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> NormalizeWeights(BaseArray<BaseArray<Float>>& weights, const BaseArray<BaseArray<Float>>& oldWeights, AutoWeightPointJointSelections &autoWeightPointJointSelections);
	
	//----------------------------------------------------------------------------------------
	/// Run the smooth algorithm on the weights.
	/// @param[out] weights														The resulting autoweight array.
	/// @param[in] op																	The polygon object.
	/// @param[in] oldWeights													The previous weight array.
	/// @param[in] autoWeightPointJointSelections			The point joint lock selection.
	/// @return																				Error code if fail else OK.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> SmoothWeights(BaseArray<BaseArray<Float>>& weights, PolygonObject* op, const BaseArray<BaseArray<Float>>& oldWeights, AutoWeightPointJointSelections &autoWeightPointJointSelections);
};

#include "autoweight1.hxx"

//----------------------------------------------------------------------------------------
// ABSTRACT CLASSES
//----------------------------------------------------------------------------------------

namespace AutoWeightComponents
{
	// Default normalization component class
	MAXON_DECLARATION(Class<AutoWeightRef>, NormalizeClass, "net.maxon.animation.autoweight.normalize");
	// Default smooth component class
	MAXON_DECLARATION(Class<AutoWeightRef>, SmoothClass, "net.maxon.animation.autoweight.smooth");

	// BASE CLASSES

	// Default base class for all autoweight implementations. Adds support for data and UI.
	MAXON_DECLARATION(Class<AutoWeightRef>, DictionaryClass, "net.maxon.animation.autoweight.dictionary");
	// Default base class for all autoweight implementations using supplied smooth and normalize components.
	MAXON_DECLARATION(Class<AutoWeightRef>, BaseClass, "net.maxon.animation.autoweight.base");
}

//----------------------------------------------------------------------------------------
// USABLE CLASSES
//----------------------------------------------------------------------------------------

// Register all fully implemented autoweight interface classes in this registry to have them visible in
// Weight Manager.
MAXON_REGISTRY(Class<AutoWeightRef>, AutoWeightAlgos, "net.maxon.animation.registry.autoweights");

namespace AutoWeightAlgos
{
	// Heatmap algo with default AutoWeightNormalizeClass and AutoWeightSmoothClass;
	MAXON_DECLARATION(AutoWeightAlgos::EntryType, HeatmapClass, "net.maxon.animation.autoweight.heatmap");
	// Bone glow algo with default AutoWeightNormalizeClass and AutoWeightSmoothClass;
	MAXON_DECLARATION(AutoWeightAlgos::EntryType, BoneglowClass, "net.maxon.animation.autoweight.boneglow");
	// Bone glow voxels algo with default AutoWeightNormalizeClass and AutoWeightSmoothClass;
	MAXON_DECLARATION(AutoWeightAlgos::EntryType, VoxelBoneglowClass, "net.maxon.animation.autoweight.voxelboneglow");
}

#include "autoweight2.hxx"
} // namespace maxon


#endif // Autoweight_H__

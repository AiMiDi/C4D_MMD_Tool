#ifndef VOLUMECOMMANDS_H__
#define VOLUMECOMMANDS_H__

#include "ge_prepass.h"
#include "maxon/commandbase.h"
#include "maxon/basearray.h"
#include "maxon/datadictionaryobject.h"
#include "maxon/volumetools.h"

class BaseObject;
class BaseList2D;
class BaseThread;
class BaseDocument;
class SplineData;

namespace maxon
{

struct VolumeCommandData
{
	Result<void> CopyFrom(const VolumeCommandData& other)
	{
		iferr_scope;
		op = other.op;
		reference = other.reference;
		doc = other.doc;
		bt = other.bt;
		masks = other.masks;
		result.CopyFrom(other.result) iferr_return;
		fieldMask = other.fieldMask;
		targetGridMatrix = other.targetGridMatrix;
		splineData = other.splineData;
		return OK;
	}

	BaseArray<::BaseObject*>* op = nullptr;						// The objects to perform the operation on.
	BaseArray<::BaseObject*>* reference = nullptr;		// Reference volumes for field conversion and MoSpline reference for spline conversion.
	::BaseDocument* doc = nullptr;										// The current document.
	::BaseThread* bt = nullptr;												// A thread reference to test for cancellation.
	BaseArray<::BaseObject*>* masks = nullptr;				// Optional mask volumes for some operations like filters.
	BaseArray<::BaseObject*> result;									// The output lists for the command.
	FieldSampleData* fieldMask = nullptr;							// Data for Fieldsampling as mask or field conversion.
	Matrix* targetGridMatrix = nullptr;								// The target grid matrix for creation volume commands. This will be the grid matrix of the created volume.
	SplineData* splineData = nullptr;									// A spline data pointer used for scaling of spline radii
};

namespace LegacyCommandDataClasses
{
	MAXON_DECLARATION(LegacyCommandDataClasses::EntryType, VOLUMEDATA, "net.maxon.legacycommanddata.volumes");
}

namespace CommandClasses
{
	MAXON_DECLARATION(CommandClasses::EntryType, VOLUMETOMESH, "net.maxon.command.volumes.volumetomesh");
	MAXON_DECLARATION(CommandClasses::EntryType, MESHTOVOLUME, "net.maxon.command.volumes.meshtovolume");
	MAXON_DECLARATION(CommandClasses::EntryType, PARTICLESTOVOLUME, "net.maxon.command.volumes.particlestovolume");
	MAXON_DECLARATION(CommandClasses::EntryType, SPLINETOVOLUME, "net.maxon.command.volumes.splinetovolume");
	MAXON_DECLARATION(CommandClasses::EntryType, FILTER, "net.maxon.command.volumes.filter");
	MAXON_DECLARATION(CommandClasses::EntryType, SDFFILTER, "net.maxon.command.volumes.sdffilter");
	MAXON_DECLARATION(CommandClasses::EntryType, BOOLE, "net.maxon.command.volumes.boole");
	MAXON_DECLARATION(CommandClasses::EntryType, SDFTOFOG, "net.maxon.command.volumes.sdftofog");
	MAXON_DECLARATION(CommandClasses::EntryType, FOGTOSDF, "net.maxon.command.volumes.fogtosdf");
	MAXON_DECLARATION(CommandClasses::EntryType, RESAMPLE, "net.maxon.command.volumes.resample");
	MAXON_DECLARATION(CommandClasses::EntryType, MIX, "net.maxon.command.volumes.mix");
	MAXON_DECLARATION(CommandClasses::EntryType, FIELDTOVOLUME, "net.maxon.command.volumes.fieldtovolume");
	MAXON_DECLARATION(CommandClasses::EntryType, CREATESPHEREVOLUME, "net.maxon.command.volumes.createspherevolume");
	MAXON_DECLARATION(CommandClasses::EntryType, CREATEPLATONICVOLUME, "net.maxon.command.volumes.createplatonicvolume");
}

} // namespace maxon

#endif // VOLUMECOMMANDS_H__

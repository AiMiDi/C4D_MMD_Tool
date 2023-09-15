#ifndef _GOZ_POLYGROUP_TAG_H__
#define _GOZ_POLYGROUP_TAG_H__

#include "maxon/lib_math.h"
// #include "lib_customdatatag.h"
#include "maxon/mesh_attribute_base.h"

static const maxon::Int32 ID_POLYGROUPTAG = 1054295;



namespace maxon
{
//----------------------------------------------------------------------------------------
/// PolygroupInformation
/// This class is used to store the polygroup ID.
/// It have been created because of a bug in the customdatatag and because the data size must be 64bits
//----------------------------------------------------------------------------------------
class PolygroupInformation
{
public:
	PolygroupInformation() = default;

	MAXON_IMPLICIT PolygroupInformation(Int32 index) : _privateBuffer(0), _polygroupIndex(index) { }
	
	PolygroupInformation& operator =(const PolygroupInformation& src)
	{
		_polygroupIndex = src._polygroupIndex;
		_privateBuffer = src._privateBuffer;
		return *this;
	}

	inline Bool operator ==(const PolygroupInformation& other) const
	{
		return _polygroupIndex == other._polygroupIndex;
	}

	inline Bool operator <(const PolygroupInformation& other) const
	{
		return _polygroupIndex < other._polygroupIndex;
	}

	MAXON_OPERATOR_COMPARISON(PolygroupInformation);

	inline String ToString(const FormatStatement* formatStatement = nullptr) const
	{
		return FormatString("polygon Polygroup : @", _polygroupIndex);
	}

	HashInt GetHashCode() const
	{
		return MAXON_HASHCODE(_privateBuffer, _polygroupIndex);
	}

	Int32 _privateBuffer = 0; /// not used just here for the size of the class
	Int32 _polygroupIndex = NOTOK;

};


//----------------------------------------------------------------------------------------
/// Declaration of a new DataType.
/// This will be store inside the new mesh attribute
//----------------------------------------------------------------------------------------
MAXON_DATATYPE(PolygroupInformation, "net.maxon.meshattribute.gozpolyinformation");
//----------------------------------------------------------------------------------------
/// Declaration of the new MeshAttribute
//----------------------------------------------------------------------------------------
MAXON_MESHATTRIBUTE(PolygroupInformation, POLYGROUP);
//----------------------------------------------------------------------------------------
/// Declaration of the new DataTape for the mesh attribute
//----------------------------------------------------------------------------------------
MAXON_DATATYPE(POLYGROUP_MESHATTRIBUTE, "net.maxon.meshattribute.gozpolygroup");


namespace CustomDataTagClasses
{
	//----------------------------------------------------------------------------------------
	/// Declaration of the CustomDataTag class for the polygroup itself
	//----------------------------------------------------------------------------------------
	MAXON_DECLARATION(maxon::CustomDataTagClasses::EntryType, POLYGROUP, "net.maxon.mesh_misc.customdatatagclass.gozpolygroup");
} // namespace CustomDataTagClasses

namespace CustomDataTagDisplayClasses
{
	//----------------------------------------------------------------------------------------
	/// Declaration of the polygroup display class for the polygroup tag
	//----------------------------------------------------------------------------------------
	MAXON_DECLARATION(CustomDataTagDisplayClasses::EntryType, POLYGROUPDISPLAY, "net.maxon.mesh_misc.customdatatagdisplay.gozpolygroup");
	
} // namespace CustomDataTagDisplayClasses


#include "polygroup_tag1.hxx"
#include "polygroup_tag2.hxx"

} // namespace maxon


#endif // _GOZ_POLYGROUP_TAG_H__

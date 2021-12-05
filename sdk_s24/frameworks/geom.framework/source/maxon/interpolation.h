#ifndef INTERPOLATION_H__
#define INTERPOLATION_H__

#include "maxon/apibase.h"
#include "maxon/interface.h"
#include "maxon/basearray.h"
namespace maxon
{

template <typename VALUETYPE, typename FLOATTYPE> class GenericInterpolate
{
public:
	static void Linear(void* data1, const void* data2, Float blendValue)
	{
		if (!data1 || !data2)
			return;
		
		VALUETYPE* v1 = static_cast<VALUETYPE*>(data1);
		const VALUETYPE* v2 = static_cast<const VALUETYPE*>(data2);
		*v1 = Blend(*v1, *v2, (FLOATTYPE)blendValue);
	}

	static void InOutline(void* data, const Block<void*>& outline, const Block<Float>& weights)
	{
		if (!data)
			return;
		
		if (outline.GetCount() != weights.GetCount())
			return;
		
		VALUETYPE* 	v = static_cast<VALUETYPE*>(data);
		
		if (outline.GetCount() == 3)
		{
			InterpolateBarycentricInternal(v, reinterpret_cast<VALUETYPE**>(outline.GetFirst()), weights);
		}
		else
		{
			InterpolateInOutlineInternal(v, outline, weights);
		}
	}
	
	static void Average(void* data, const Block<const void*>& dataSet)
	{
		if (!data)
			return;
		
		if (dataSet.GetCount() == 0)
			return;
		
		VALUETYPE* v = static_cast<VALUETYPE*>(data);
		*v = VALUETYPE();
		
		for (const void* entry : dataSet)
		{
			*v += *(static_cast<const VALUETYPE*>(entry));
		}
		
		*v /= static_cast<FLOATTYPE>(dataSet.GetCount());
	}
	
private:
	
	static inline void InterpolateInOutlineInternal(VALUETYPE* v, const Block<void*>& outline, const Block<Float>& weights)
	{
		VALUETYPE* 	currentValue = nullptr;
		VALUETYPE 	numerator = VALUETYPE();
		
		for (auto it = Iterable::IndexIterator(outline); it; ++it)
		{
			currentValue = static_cast<VALUETYPE*>(*it);
			if (MAXON_UNLIKELY(!currentValue))
				continue;
			
			numerator += ((*currentValue) * (FLOATTYPE)weights[it.GetIndex()]);
		}
		
		*v = numerator;
	}
	
	// this case only works if outline and weights are 3. no checks on that for performance reasons
	static inline void InterpolateBarycentricInternal(VALUETYPE* v, VALUETYPE* const * outline, const Block<Float>& weights)
	{
		// count is checked outside of the only function that is allowed to call this
		if (MAXON_UNLIKELY(!outline[0] || !outline[1] || !outline[2]))
			return;
		
		*v = *outline[0] * (FLOATTYPE)weights[0];
		*v += *outline[1] * (FLOATTYPE)weights[1];
		*v += *outline[2] * (FLOATTYPE)weights[2];
	}
};

class InterpolateType;
 
class InterpolateTypeInterface : MAXON_INTERFACE_BASES(ObjectInterface)
{
	MAXON_INTERFACE(InterpolateTypeInterface, MAXON_REFERENCE_CONST, "net.maxon.geometry.interface.interpolate");
	
public:
	
	//----------------------------------------------------------------------------------------
	/// Returns the datatype this class manages, e.g. Vector2d32
	/// @return												The datatype.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const DataType& GetInterpolateDataType() const;

	//----------------------------------------------------------------------------------------
	/// Interpolates linearly between two data values. Both addresses must be cast to the appropriate datatype.
	/// @param[in,out] data1					The address of the first value. The value will be overwritten with the result.
	/// @param[in] data2							The address of the second value.
	/// @param[in] blend							The blend percentage [0.0..blend..1.0]
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void InterpolateLinear(void* data1, const void* data2, Float blend) const;
	
	//----------------------------------------------------------------------------------------
	/// Interpolates a value in the polygon outline using given weights. The addresses in data and outline need to be cast to the appropriate datatype.
	/// @param[in,out] data						The address of the value. The value will be overwritten with the result.
	/// @param[in] outline						The outline data used to perform the interpolation.
	/// @param[in] weights						Weights to use for the interpolation; represent the interpolation distance from each outline edge.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void InterpolateInOutline(void* data, const Block<void*>& outline, const Block<Float>& weights) const;
	
	//----------------------------------------------------------------------------------------
	/// Averages values in dataSet and stores the result under the specified data pointer.
	/// @param[in,out] data						The resulting data pointer to be filled. The caller owns the memory.
	/// @param[in] dataSet						The data set to average.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void Average(void* data, const Block<const void*>& dataSet) const;
	
	//----------------------------------------------------------------------------------------
	/// Interpolates bilinearly between four data values. All addresses must be cast to the appropriate datatype.
	/// @param[in,out] data1					The address of the first value. The value will be overwritten with the result.
	/// @param[in] data2							The address of the second value.
	/// @param[in] data3							The address of the third value.
	/// @param[in] data4							The address of the fourth value.
	/// @param[in] blendS							The first blend percentage [0.0..blend..1.0]. Interpolation Scheme [data1 .. blendS .. data2] and [data4 .. blendS .. data3].
	/// @param[in] blendT							The second blend percentage [0.0..blend..1.0]. Interpolation Scheme [blendS1 .. blendT .. blendS2]
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION void InterpolateBilinear(const DataTypePtr dataType, void* data1, const void* data2, const void* data3, const void* data4, Float blendS, Float blendT) const;
	
	//----------------------------------------------------------------------------------------
	/// Return the interpolation class for the passed data type if exist.
	/// @param[in] datatype						The DataType.
	/// @return												The interpolation class or an empty class if do not exist.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD InterpolateType GetInterpolationClass(const DataType& datatype);
};

#include "interpolation1.hxx"

/// Registration of registry for different types of MeshMapClass
MAXON_REGISTRY(InterpolateType, InterpolateTypes, "net.maxon.geometry.registry.interpolation.types");

namespace InterpolateTypes
{
	MAXON_DECLARATION(InterpolateTypes::EntryType, VECTOR, "net.maxon.geometry.interpolation.types.vector");
	MAXON_DECLARATION(InterpolateTypes::EntryType, VECTOR32, "net.maxon.geometry.interpolation.types.vector32");
	MAXON_DECLARATION(InterpolateTypes::EntryType, VECTOR2D, "net.maxon.geometry.interpolation.types.vector2d");
	MAXON_DECLARATION(InterpolateTypes::EntryType, VECTOR2D32, "net.maxon.geometry.interpolation.types.vector2d32");
	MAXON_DECLARATION(InterpolateTypes::EntryType, FLOAT, "net.maxon.geometry.interpolation.types.float");
	MAXON_DECLARATION(InterpolateTypes::EntryType, FLOAT32, "net.maxon.geometry.interpolation.types.float32");
	MAXON_DECLARATION(InterpolateTypes::EntryType, COLOR, "net.maxon.geometry.interpolation.types.color");
	MAXON_DECLARATION(InterpolateTypes::EntryType, COLOR32, "net.maxon.geometry.interpolation.types.color32");
	MAXON_DECLARATION(InterpolateTypes::EntryType, COLORA, "net.maxon.geometry.interpolation.types.colora");
	MAXON_DECLARATION(InterpolateTypes::EntryType, COLORA32, "net.maxon.geometry.interpolation.types.colora32");
}

#include "interpolation2.hxx"

} // namepsace maxon

#endif // INTERPOLATION_H__

#ifndef GEOMCONSTANTS_H__
#define GEOMCONSTANTS_H__

namespace maxon
{

//----------------------------------------------------------------------------------------
/// Class containing frequently used constants in the geom library.
//----------------------------------------------------------------------------------------
class GeomConstants
{
public:

	static constexpr Float EPSILON1 = 1e-1;
	static constexpr Float EPSILON2 = 1e-2;
	static constexpr Float EPSILON3 = 1e-3;
	static constexpr Float EPSILON4 = 1e-4;
	static constexpr Float EPSILON5 = 1e-5;
	static constexpr Float EPSILON6 = 1e-6;
	static constexpr Float EPSILON7 = 1e-7;
	static constexpr Float EPSILON8 = 1e-8;
	static constexpr Float EPSILON10 = 1e-10;
	static constexpr Float EPSILON12 = 1e-12;
	static constexpr Float EPSILON14 = 1e-14;
	static constexpr Float EPSILON16 = 1e-16;
	template <typename FLOATTYPE> static constexpr FLOATTYPE EPSILON_FLOAT = sizeof(FLOATTYPE) == sizeof(double) ? 2.2204460492503131e-016 : 1.192092896e-07F;
};

} // namespace maxon


#endif // GEOMCONSTANTS_H__

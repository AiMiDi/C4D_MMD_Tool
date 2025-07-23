#ifndef DATADESCRIPTION_NODE_BUNDLES_H__
#define DATADESCRIPTION_NODE_BUNDLES_H__

#include "maxon/fid.h"
#include "maxon/vector.h"
#include "maxon/vector4d.h"
#include "maxon/idandversion.h"
#include "maxon/range.h"
#include "maxon/gradient.h"
//----------------------------------------------------------------------------------------
// BEGIN - auto generated code, do not edit
//----------------------------------------------------------------------------------------
namespace maxon
{
namespace NODESPACE
{
	namespace EXCHANGE
	{
		namespace BUNDLE
		{
			//----------------------------------------------------------------------------------------
			/// This is a simple material description to offer viewport and export support for node materials.
			//----------------------------------------------------------------------------------------
			namespace VIEWPORTMATERIAL
			{
				MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.nodespace.exchange.bundle.viewportmaterial");

				/// Defines the type of material in the viewport:
				/// - Constant: a dielectric material with specular layer on top and diffuse base.
				/// - Metal: a metal / conductor with GGX layer.
				/// - Dielectric: a dielectric material with specular layer on top and diffuse base.
				/// Note that we do not support dynamic metalness.
				MAXON_ATTRIBUTE(InternedId, TYPE, "type");
				MAXON_ATTRIBUTE(void, TYPE_ENUM_CONSTANT, "constant");
				MAXON_ATTRIBUTE(void, TYPE_ENUM_METAL, "metal");
				MAXON_ATTRIBUTE(void, TYPE_ENUM_DIELECTRIC, "dielectric");
				MAXON_ATTRIBUTE(void, TYPE_ENUM_VOLUMETRIC, "volumetric");

				/// Defines the transparency of dielectric materials in the range [0.0, 1.0] from not transparent to fully transparent.
				MAXON_ATTRIBUTE(Float, TRANSMISSIVITY, "transmissivity ");

				/// Defines the alpha of the material in the range [0.0, 1.0] from invisible to opaque.
				MAXON_ATTRIBUTE(Float, ALPHA, "alpha");

				MAXON_ATTRIBUTE(Color, BASE_COLOR, "base.color");

				MAXON_ATTRIBUTE(Float, BASE_COLOR_WEIGHT, "base.color_weight");

				/// Data is expected to be in [0,1] range with the geometric normal = [0.5, 0.5, 1.0].
				/// The tangent frame is oriented in accordance with OpenGL and Unity.
				MAXON_ATTRIBUTE(Vector, BASE_NORMAL, "base.normal");

				MAXON_ATTRIBUTE(Float, BASE_NORMAL_WEIGHT, "base.normal_weight");

				MAXON_ATTRIBUTE(Color, SPECULAR_COLOR, "specular.color");

				MAXON_ATTRIBUTE(Float, SPECULAR_COLOR_WEIGHT, "specular.color_weight");

				/// Data is expected to be in [0,1] range with the geometric normal = [0.5, 0.5, 1.0].
				/// The tangent frame is oriented in accordance with OpenGL and Unity.
				MAXON_ATTRIBUTE(Vector, SPECULAR_NORMAL, "specular.normal");

				MAXON_ATTRIBUTE(Float, SPECULAR_NORMAL_WEIGHT, "specular.normal_weight");

				MAXON_ATTRIBUTE(Float, SPECULAR_ROUGHNESS, "specular.roughness");

				MAXON_ATTRIBUTE(Float, SPECULAR_IOR, "specular.ior");

				MAXON_ATTRIBUTE(Color, EMISSION_COLOR, "emission.color");

				MAXON_ATTRIBUTE(Float, EMISSION_COLOR_WEIGHT, "emission.color_weight");

				MAXON_ATTRIBUTE(Float, SCATTERING_COEFFICIENT, "scattering.coefficient");

				MAXON_ATTRIBUTE(Float, ABSORPTION_COEFFICIENT, "absorption.coefficient");

				MAXON_ATTRIBUTE(Float, EMISSION_COEFFICIENT, "emission.coefficient");

				MAXON_ATTRIBUTE(Float, EMISSION_TEMPERATURE, "emission.temperature");

				MAXON_ATTRIBUTE(Gradient, SCATTERING_GRADIENT, "scattering.gradient");

				MAXON_ATTRIBUTE(Gradient, ABSORPTION_GRADIENT, "absorption.gradient");

				/// Defines the type of volume emission in the viewport:
				/// - None: default - no emission
				/// - Ramp: requires an emission gradient
				/// - Blackbody: uses the temperature for blackbody radiation
				MAXON_ATTRIBUTE(InternedId, EMISSION_TYPE, "emission.type");
				MAXON_ATTRIBUTE(void, EMISSION_TYPE_ENUM_NONE, "none");
				MAXON_ATTRIBUTE(void, EMISSION_TYPE_ENUM_RAMP, "ramp");
				MAXON_ATTRIBUTE(void, EMISSION_TYPE_ENUM_BLACKBODY, "blackbody");

				MAXON_ATTRIBUTE(Gradient, EMISSION_GRADIENT, "emission.gradient");

				MAXON_ATTRIBUTE(Float, DENSITY_SHADOW_SCALE, "density.shadow_scale");

				MAXON_ATTRIBUTE(Range<Float>, DENSITY_RANGE_OLD, "density.range_old");

				MAXON_ATTRIBUTE(Range<Float>, DENSITY_RANGE_NEW, "density.range_new");

				MAXON_ATTRIBUTE(Range<Float>, EMISSION_RANGE_OLD, "emission.range_old");

				MAXON_ATTRIBUTE(Range<Float>, EMISSION_RANGE_NEW, "emission.range_new");

				MAXON_ATTRIBUTE(Group, GROUP_GENERAL, "group.general");

				MAXON_ATTRIBUTE(Group, GROUP_BASE, "group.base");

				MAXON_ATTRIBUTE(Group, GROUP_SPECULAR, "group.specular");

				MAXON_ATTRIBUTE(Group, GROUP_EMISSION, "group.emission");

				MAXON_ATTRIBUTE(Group, GROUP_VOLUME, "group.volume");
			}
		}
	}
}
}
//----------------------------------------------------------------------------------------
// END - auto generated code, do not edit
//----------------------------------------------------------------------------------------

namespace maxon
{

#include "datadescription_node_bundles1.hxx"
#include "datadescription_node_bundles2.hxx"

} // namespace maxon

#endif // DATADESCRIPTION_NODE_BUNDLES_H__

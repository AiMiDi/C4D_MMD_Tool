#ifndef DATADESCRIPTION_MATERIAL_FORGER_H__
#define DATADESCRIPTION_MATERIAL_FORGER_H__

#include "maxon/fid.h"
#include "maxon/vector.h"
#include "maxon/vector4d.h"


//----------------------------------------------------------------------------------------
// BEGIN - auto generated code, do not edit
//----------------------------------------------------------------------------------------
namespace maxon
{
namespace MATERIAL
{
	namespace PORTBUNDLE
	{
		namespace FORGER
		{
			//----------------------------------------------------------------------------------------
			/// Forger Blinn Material
			//----------------------------------------------------------------------------------------
			namespace BLINN
			{
				MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.material.portbundle.forger.blinn");

				MAXON_ATTRIBUTE(ColorA, DIFFUSE, "Diffuse");

				MAXON_ATTRIBUTE(ColorA, SPECULAR, "Specular");

				MAXON_ATTRIBUTE(Float, SHININESS, "Shininess");

				MAXON_ATTRIBUTE(Group, GROUP_BASIC, "group.basic");

				MAXON_ATTRIBUTE(String, OBJECT_BASE_NAME, "net.maxon.object.base.name");

				MAXON_ATTRIBUTE(String, OBJECT_BASE_TAGS, "net.maxon.object.base.tags");

				MAXON_ATTRIBUTE(String, OBJECT_BASE_ANNOTATIONS, "net.maxon.object.base.annotations");
			}

			//----------------------------------------------------------------------------------------
			/// Forger LitSphere Material
			//----------------------------------------------------------------------------------------
			namespace LITSPHERE
			{
				MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.material.portbundle.forger.litsphere");

				MAXON_ATTRIBUTE(ColorA, LITSPHEREMAP, "litspheremap");

				MAXON_ATTRIBUTE(ColorA, CONSTANTCOLOR, "constantcolor");

				MAXON_ATTRIBUTE(ColorA, OVERRIDECONSTANTCOLOR, "overrideConstantColor");

				MAXON_ATTRIBUTE(Bool, IGNORELIGHTDIRECTION, "ignoreLightDirection");

				MAXON_ATTRIBUTE(ColorA, NORMALMAP, "normalMap");

				MAXON_ATTRIBUTE(String, OBJECT_BASE_NAME, "net.maxon.object.base.name");

				MAXON_ATTRIBUTE(String, OBJECT_BASE_TAGS, "net.maxon.object.base.tags");

				MAXON_ATTRIBUTE(String, OBJECT_BASE_ANNOTATIONS, "net.maxon.object.base.annotations");
			}

			//----------------------------------------------------------------------------------------
			/// Forger Standard Material
			//----------------------------------------------------------------------------------------
			namespace STANDARD
			{
				MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.material.portbundle.forger.standard");

				MAXON_ATTRIBUTE(Color, BASECOLOR, "BaseColor");

				MAXON_ATTRIBUTE(Float, SPECULAR, "Specular");

				MAXON_ATTRIBUTE(Float, SPECULARTINT, "SpecularTint");

				MAXON_ATTRIBUTE(Color, ROUGHNESS, "roughness");

				MAXON_ATTRIBUTE(Color, METALNESS, "metalness");

				MAXON_ATTRIBUTE(ColorA, EMITCOLOR, "EmitColor");

				MAXON_ATTRIBUTE(Bool, NORMALMAP_VISIBLE, "normalmap.visible");

				MAXON_ATTRIBUTE(Color, NORMAMAP_COLOR, "NormaMap.Color");

				MAXON_ATTRIBUTE(Group, GROUP_BASE, "group.base");

				MAXON_ATTRIBUTE(Group, GROUP_SPEC, "group.spec");

				MAXON_ATTRIBUTE(Group, GROUP_REFLECTION, "group.reflection");

				MAXON_ATTRIBUTE(Group, EMISSION, "Emission");

				MAXON_ATTRIBUTE(Group, GROUP_SURFACE, "group.surface");

				MAXON_ATTRIBUTE(String, OBJECT_BASE_NAME, "net.maxon.object.base.name");

				MAXON_ATTRIBUTE(String, OBJECT_BASE_TAGS, "net.maxon.object.base.tags");

				MAXON_ATTRIBUTE(String, OBJECT_BASE_ANNOTATIONS, "net.maxon.object.base.annotations");
			}
		}
	}
}
}
//----------------------------------------------------------------------------------------
// END - auto generated code, do not edit
//----------------------------------------------------------------------------------------

#include "datadescription_material_forger1.hxx"
#include "datadescription_material_forger2.hxx"

#endif // !DATADESCRIPTION_MATERIAL_FORGER_H__
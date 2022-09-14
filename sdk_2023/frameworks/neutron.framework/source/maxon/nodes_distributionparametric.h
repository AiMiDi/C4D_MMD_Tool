#ifndef NODES_DISTRIBUTIONPARAMETRIC_H__
#define NODES_DISTRIBUTIONPARAMETRIC_H__

#include "maxon/fid.h"

//----------------------------------------------------------------------------------------
// BEGIN - auto generated code, do not edit
//----------------------------------------------------------------------------------------
namespace maxon
{
namespace NEUTRON
{
	namespace NODE
	{
		namespace DISTRIBUTION
		{
			namespace PARAMETRIC
			{
				namespace GRID
				{
					MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.neutron.node.distribution.parametric.grid");

					// supports MAXON::NODE::BASE::NODEPREVIEWIMAGE
					// supports MAXON::NODE::BASE::MATERIALPREVIEWIMAGE
					// supports MAXON::NODE::BASE::NAME
					// supports MAXON::NODE::BASE::ASSETVERSION
					// supports MAXON::NODE::BASE::COLOR
					// supports MAXON::NODE::BASE::PORTDISPLAY
					// supports MAXON::NODE::BASE::DISPLAYPREVIEW
					// supports MAXON::NODE::BASE::DISPLAYCOMMENT
					// supports MAXON::NODE::BASE::COMMENT
					// supports MAXON::NODE::BASE::FILTERTAGS
					// supports MAXON::NODE::BASE::CATEGORY
					// supports MAXON::NODE::BASE::ICON
					// supports MAXON::NODE::BASE::UPDATEPOLICY
					// supports MAXON::ASSET::BASE::PROTECTED

					MAXON_ATTRIBUTE(void, DISTDATAOUT, "distdataout");

					MAXON_ATTRIBUTE(Vector, SIZEIN, "sizein");

					MAXON_ATTRIBUTE(Vector, POINTOFFSETIN, "pointoffsetin");
				}

				namespace GRIDOFFSET
				{
					MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.neutron.node.distribution.parametric.gridoffset");

					// supports MAXON::NODE::BASE::NODEPREVIEWIMAGE
					// supports MAXON::NODE::BASE::MATERIALPREVIEWIMAGE
					// supports MAXON::NODE::BASE::NAME
					// supports MAXON::NODE::BASE::ASSETVERSION
					// supports MAXON::NODE::BASE::COLOR
					// supports MAXON::NODE::BASE::PORTDISPLAY
					// supports MAXON::NODE::BASE::DISPLAYPREVIEW
					// supports MAXON::NODE::BASE::DISPLAYCOMMENT
					// supports MAXON::NODE::BASE::COMMENT
					// supports MAXON::NODE::BASE::FILTERTAGS
					// supports MAXON::NODE::BASE::CATEGORY
					// supports MAXON::NODE::BASE::ICON
					// supports MAXON::NODE::BASE::UPDATEPOLICY
					// supports MAXON::ASSET::BASE::PROTECTED

					MAXON_ATTRIBUTE(Vector, SIZEIN, "sizein");

					MAXON_ATTRIBUTE(Vector, POINTOFFSETIN, "pointoffsetin");

					MAXON_ATTRIBUTE(Vector2d, ROWOFFSETIN, "rowoffsetin");

					MAXON_ATTRIBUTE(Vector2d, COLUMNOFFSETIN, "columnoffsetin");

					MAXON_ATTRIBUTE(Int, ROWPERIODIN, "rowperiodin");

					MAXON_ATTRIBUTE(Int, COLUMNPERIODIN, "columnperiodin");

					MAXON_ATTRIBUTE(void, DISTDATAOUT, "distdataout");
				}

				namespace LINEAR
				{
					MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.neutron.node.distribution.parametric.linear");

					// supports MAXON::NODE::BASE::NODEPREVIEWIMAGE
					// supports MAXON::NODE::BASE::MATERIALPREVIEWIMAGE
					// supports MAXON::NODE::BASE::NAME
					// supports MAXON::NODE::BASE::ASSETVERSION
					// supports MAXON::NODE::BASE::COLOR
					// supports MAXON::NODE::BASE::PORTDISPLAY
					// supports MAXON::NODE::BASE::DISPLAYPREVIEW
					// supports MAXON::NODE::BASE::DISPLAYCOMMENT
					// supports MAXON::NODE::BASE::COMMENT
					// supports MAXON::NODE::BASE::FILTERTAGS
					// supports MAXON::NODE::BASE::CATEGORY
					// supports MAXON::NODE::BASE::ICON
					// supports MAXON::NODE::BASE::UPDATEPOLICY
					// supports MAXON::ASSET::BASE::PROTECTED

					MAXON_ATTRIBUTE(Int, COUNTIN, "countin");

					MAXON_ATTRIBUTE(Int, OFFSETIN, "offsetin");

					MAXON_ATTRIBUTE(Int, ROTATIONORDERIN, "rotationorderin",
						RESOURCE_DEFINE(ENUM_YXZGLOBAL, 0)
						RESOURCE_DEFINE(ENUM_YZXGLOBAL, 1)
						RESOURCE_DEFINE(ENUM_ZYXGLOBAL, 2)
						RESOURCE_DEFINE(ENUM_ZXYGLOBAL, 3)
						RESOURCE_DEFINE(ENUM_XZYGLOBAL, 4)
						RESOURCE_DEFINE(ENUM_XYZGLOBAL, 5)
						RESOURCE_DEFINE(ENUM_YXZLOCAL, 3)
						RESOURCE_DEFINE(ENUM_YZXLOCAL, 4)
						RESOURCE_DEFINE(ENUM_ZYXLOCAL, 5)
						RESOURCE_DEFINE(ENUM_ZXYLOCAL, 0)
						RESOURCE_DEFINE(ENUM_XZYLOCAL, 1)
						RESOURCE_DEFINE(ENUM_XYZLOCAL, 2));

					MAXON_ATTRIBUTE(Float, STEPSIZEIN, "stepsizein");

					MAXON_ATTRIBUTE(Vector, POSITIONSTEPIN, "positionstepin");

					MAXON_ATTRIBUTE(Vector, SCALESTEPIN, "scalestepin");

					MAXON_ATTRIBUTE(Vector, ROTATIONSTEPIN, "rotationstepin");

					MAXON_ATTRIBUTE(void, DISTDATAOUT, "distdataout");
				}

				namespace LINEARTRANSFORMED
				{
					MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.neutron.node.distribution.parametric.lineartransformed");

					// supports MAXON::NODE::BASE::NODEPREVIEWIMAGE
					// supports MAXON::NODE::BASE::MATERIALPREVIEWIMAGE
					// supports MAXON::NODE::BASE::NAME
					// supports MAXON::NODE::BASE::ASSETVERSION
					// supports MAXON::NODE::BASE::COLOR
					// supports MAXON::NODE::BASE::PORTDISPLAY
					// supports MAXON::NODE::BASE::DISPLAYPREVIEW
					// supports MAXON::NODE::BASE::DISPLAYCOMMENT
					// supports MAXON::NODE::BASE::COMMENT
					// supports MAXON::NODE::BASE::FILTERTAGS
					// supports MAXON::NODE::BASE::CATEGORY
					// supports MAXON::NODE::BASE::ICON
					// supports MAXON::NODE::BASE::UPDATEPOLICY
					// supports MAXON::ASSET::BASE::PROTECTED

					MAXON_ATTRIBUTE(Int, COUNTIN, "countin");

					MAXON_ATTRIBUTE(Int, OFFSETIN, "offsetin");

					MAXON_ATTRIBUTE(Int, ROTATIONORDERIN, "rotationorderin",
						RESOURCE_DEFINE(ENUM_YXZGLOBAL, 0)
						RESOURCE_DEFINE(ENUM_YZXGLOBAL, 1)
						RESOURCE_DEFINE(ENUM_ZYXGLOBAL, 2)
						RESOURCE_DEFINE(ENUM_ZXYGLOBAL, 3)
						RESOURCE_DEFINE(ENUM_XZYGLOBAL, 4)
						RESOURCE_DEFINE(ENUM_XYZGLOBAL, 5)
						RESOURCE_DEFINE(ENUM_YXZLOCAL, 3)
						RESOURCE_DEFINE(ENUM_YZXLOCAL, 4)
						RESOURCE_DEFINE(ENUM_ZYXLOCAL, 5)
						RESOURCE_DEFINE(ENUM_ZXYLOCAL, 0)
						RESOURCE_DEFINE(ENUM_XZYLOCAL, 1)
						RESOURCE_DEFINE(ENUM_XYZLOCAL, 2));

					MAXON_ATTRIBUTE(Float, STEPSIZEIN, "stepsizein");

					MAXON_ATTRIBUTE(Vector, POSITIONSTEPIN, "positionstepin");

					MAXON_ATTRIBUTE(Vector, SCALESTEPIN, "scalestepin");

					MAXON_ATTRIBUTE(Vector, ROTATIONSTEPIN, "rotationstepin");

					MAXON_ATTRIBUTE(Id, CUMULSTEPMODEIN, "cumulstepmodein",
						RESOURCE_DEFINE(ENUM_SINGLEVALUE, Id("singlevalue"))
						RESOURCE_DEFINE(ENUM_CUMULATIVE, Id("cumulative")));

					MAXON_ATTRIBUTE(Float, CUMULSTEPSIZEIN, "cumulstepsizein");

					MAXON_ATTRIBUTE(Vector, CUMULROTATIONSTEPIN, "cumulrotationstepin");

					MAXON_ATTRIBUTE(void, DISTDATAOUT, "distdataout");
				}

				namespace MANDELBROT
				{
					MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.neutron.node.distribution.parametric.mandelbrot");

					// supports MAXON::NODE::BASE::NODEPREVIEWIMAGE
					// supports MAXON::NODE::BASE::MATERIALPREVIEWIMAGE
					// supports MAXON::NODE::BASE::NAME
					// supports MAXON::NODE::BASE::ASSETVERSION
					// supports MAXON::NODE::BASE::COLOR
					// supports MAXON::NODE::BASE::PORTDISPLAY
					// supports MAXON::NODE::BASE::DISPLAYPREVIEW
					// supports MAXON::NODE::BASE::DISPLAYCOMMENT
					// supports MAXON::NODE::BASE::COMMENT
					// supports MAXON::NODE::BASE::FILTERTAGS
					// supports MAXON::NODE::BASE::CATEGORY
					// supports MAXON::NODE::BASE::ICON
					// supports MAXON::NODE::BASE::UPDATEPOLICY
					// supports MAXON::ASSET::BASE::PROTECTED

					MAXON_ATTRIBUTE(Vector2d, SAMPLECOUNTIN, "samplecountin");

					MAXON_ATTRIBUTE(Vector2d, SAMPLEOFFSETIN, "sampleoffsetin");

					MAXON_ATTRIBUTE(Bool, SCALEIN, "scalein");

					MAXON_ATTRIBUTE(Int, MINITERATIONIN, "miniterationin");

					MAXON_ATTRIBUTE(Int, MAXITERATIONIN, "maxiterationin");

					MAXON_ATTRIBUTE(Float, STOPTHRESHOLDIN, "stopthresholdin");

					MAXON_ATTRIBUTE(void, DISTDATAOUT, "distdataout");
				}

				namespace MANDELBULB
				{
					MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.neutron.node.distribution.parametric.mandelbulb");

					// supports MAXON::NODE::BASE::NODEPREVIEWIMAGE
					// supports MAXON::NODE::BASE::MATERIALPREVIEWIMAGE
					// supports MAXON::NODE::BASE::NAME
					// supports MAXON::NODE::BASE::ASSETVERSION
					// supports MAXON::NODE::BASE::COLOR
					// supports MAXON::NODE::BASE::PORTDISPLAY
					// supports MAXON::NODE::BASE::DISPLAYPREVIEW
					// supports MAXON::NODE::BASE::DISPLAYCOMMENT
					// supports MAXON::NODE::BASE::COMMENT
					// supports MAXON::NODE::BASE::FILTERTAGS
					// supports MAXON::NODE::BASE::CATEGORY
					// supports MAXON::NODE::BASE::ICON
					// supports MAXON::NODE::BASE::UPDATEPOLICY
					// supports MAXON::ASSET::BASE::PROTECTED

					MAXON_ATTRIBUTE(Vector, SAMPLECOUNTIN, "samplecountin");

					MAXON_ATTRIBUTE(Vector, SAMPLEOFFSETIN, "sampleoffsetin");

					MAXON_ATTRIBUTE(Bool, SCALEIN, "scalein");

					MAXON_ATTRIBUTE(Float, POWERIN, "powerin");

					MAXON_ATTRIBUTE(Int, MINITERATIONIN, "miniterationin");

					MAXON_ATTRIBUTE(Int, MAXITERATIONIN, "maxiterationin");

					MAXON_ATTRIBUTE(Float, STOPTHRESHOLDIN, "stopthresholdin");

					MAXON_ATTRIBUTE(void, DISTDATAOUT, "distdataout");
				}

				namespace PUSHAPART
				{
					MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.neutron.node.distribution.parametric.pushapart");

					// supports MAXON::NODE::BASE::NODEPREVIEWIMAGE
					// supports MAXON::NODE::BASE::MATERIALPREVIEWIMAGE
					// supports MAXON::NODE::BASE::NAME
					// supports MAXON::NODE::BASE::ASSETVERSION
					// supports MAXON::NODE::BASE::COLOR
					// supports MAXON::NODE::BASE::PORTDISPLAY
					// supports MAXON::NODE::BASE::DISPLAYPREVIEW
					// supports MAXON::NODE::BASE::DISPLAYCOMMENT
					// supports MAXON::NODE::BASE::COMMENT
					// supports MAXON::NODE::BASE::FILTERTAGS
					// supports MAXON::NODE::BASE::CATEGORY
					// supports MAXON::NODE::BASE::ICON
					// supports MAXON::NODE::BASE::UPDATEPOLICY
					// supports MAXON::ASSET::BASE::PROTECTED

					MAXON_ATTRIBUTE(void, POINTSIN, "pointsin");

					MAXON_ATTRIBUTE(Float, MINSEPARATIONIN, "minseparationin");

					MAXON_ATTRIBUTE(Float, STRENGTHIN, "strengthin");

					MAXON_ATTRIBUTE(Int, MAXITERATIONS, "maxiterations");

					MAXON_ATTRIBUTE(Bool, JIGGLEIN, "jigglein");

					MAXON_ATTRIBUTE(Bool, AXISENABLEXIN, "axisenablexin");

					MAXON_ATTRIBUTE(Bool, AXISENABLEYIN, "axisenableyin");

					MAXON_ATTRIBUTE(Bool, AXISENABLEZIN, "axisenablezin");

					MAXON_ATTRIBUTE(void, POINTSOUT, "pointsout");

					MAXON_ATTRIBUTE(Group, AXISENABLEGROUP, "axisenablegroup");
				}

				namespace RADIAL
				{
					MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.neutron.node.distribution.parametric.radial");

					// supports MAXON::NODE::BASE::NODEPREVIEWIMAGE
					// supports MAXON::NODE::BASE::MATERIALPREVIEWIMAGE
					// supports MAXON::NODE::BASE::NAME
					// supports MAXON::NODE::BASE::ASSETVERSION
					// supports MAXON::NODE::BASE::COLOR
					// supports MAXON::NODE::BASE::PORTDISPLAY
					// supports MAXON::NODE::BASE::DISPLAYPREVIEW
					// supports MAXON::NODE::BASE::DISPLAYCOMMENT
					// supports MAXON::NODE::BASE::COMMENT
					// supports MAXON::NODE::BASE::FILTERTAGS
					// supports MAXON::NODE::BASE::CATEGORY
					// supports MAXON::NODE::BASE::ICON
					// supports MAXON::NODE::BASE::UPDATEPOLICY
					// supports MAXON::ASSET::BASE::PROTECTED

					MAXON_ATTRIBUTE(Int, COUNTIN, "countin");

					MAXON_ATTRIBUTE(Float, RADIUSIN, "radiusin");

					MAXON_ATTRIBUTE(Bool, ALIGNIN, "alignin");

					MAXON_ATTRIBUTE(Bool, USEFULLRANGEIN, "usefullrangein");

					MAXON_ATTRIBUTE(Float, STARTANGLEIN, "startanglein");

					MAXON_ATTRIBUTE(Float, ENDANGLEIN, "endanglein");

					MAXON_ATTRIBUTE(Float, OFFSETIN, "offsetin");

					MAXON_ATTRIBUTE(Float, RANDOMVARIATIONIN, "randomvariationin");

					MAXON_ATTRIBUTE(Int, OFFSETSEEDIN, "offsetseedin");

					MAXON_ATTRIBUTE(void, DISTDATAOUT, "distdataout");
				}

				namespace SPIRAL
				{
					MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.neutron.node.distribution.parametric.spiral");

					// supports MAXON::NODE::BASE::NODEPREVIEWIMAGE
					// supports MAXON::NODE::BASE::MATERIALPREVIEWIMAGE
					// supports MAXON::NODE::BASE::NAME
					// supports MAXON::NODE::BASE::ASSETVERSION
					// supports MAXON::NODE::BASE::COLOR
					// supports MAXON::NODE::BASE::PORTDISPLAY
					// supports MAXON::NODE::BASE::DISPLAYPREVIEW
					// supports MAXON::NODE::BASE::DISPLAYCOMMENT
					// supports MAXON::NODE::BASE::COMMENT
					// supports MAXON::NODE::BASE::FILTERTAGS
					// supports MAXON::NODE::BASE::CATEGORY
					// supports MAXON::NODE::BASE::ICON
					// supports MAXON::NODE::BASE::UPDATEPOLICY
					// supports MAXON::ASSET::BASE::PROTECTED

					MAXON_ATTRIBUTE(Int, COUNTIN, "countin");

					MAXON_ATTRIBUTE(Int, COLORCOUNTIN, "colorcountin");

					MAXON_ATTRIBUTE(Float, ANGLEIN, "anglein");

					MAXON_ATTRIBUTE(Float, ROTATIONMULTIN, "rotationmultin");

					MAXON_ATTRIBUTE(Bool, SCALEIN, "scalein");

					MAXON_ATTRIBUTE(Vector, HALFDIAGONALIN, "halfdiagonalin");

					MAXON_ATTRIBUTE(void, DISTDATAOUT, "distdataout");
				}
			}
		}
	}
}
}
//----------------------------------------------------------------------------------------
// END - auto generated code, do not edit
//----------------------------------------------------------------------------------------


#include "nodes_distributionparametric1.hxx"
#include "nodes_distributionparametric2.hxx"

#endif // NODES_DISTRIBUTIONPARAMETRIC_H__

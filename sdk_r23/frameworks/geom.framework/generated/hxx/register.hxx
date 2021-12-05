/*
	DON'T EDIT THIS FILE!
	It has been created and is updated automatically by the interface processor.
	It has to be included by the register.cpp file of the project in order for the automatic registration to work.
*/
#define PRIVATE_MAXON_REGISTRATION_UNIT


#ifndef PRIVATE_MAXON_REGISTRATION_FRAMEWORK
#define PRIVATE_MAXON_DEFINE_MODULE_INFO_FLAGS | EntityBase::FLAGS::PUBLIC
#include "maxon/register.h"
#endif

#include "_include_convexhull.hxx"
#include "_include_delaunay3d.hxx"
#include "_include_exactpredicates2d.hxx"
#include "_include_geometryutils.hxx"
#include "_include_graphbase.hxx"
#include "_include_simplemesh.hxx"
#include "_include_voronoi3d.hxx"

#ifdef PRIVATE_MAXON_REGISTRATION_FRAMEWORK

#include "_reflection_convexhull.hxx"
#include "_reflection_delaunay3d.hxx"
#include "_reflection_exactpredicates2d.hxx"
#include "_reflection_geometryutils.hxx"
#include "_reflection_graphbase.hxx"
#include "_reflection_simplemesh.hxx"
#include "_reflection_voronoi3d.hxx"

#else

MAXON_NULL_VALUE_INCOMPLETE_GET_DEFINITION;

#include "_register_convexhull.hxx"
#include "_register_delaunay3d.hxx"
#include "_register_exactpredicates2d.hxx"
#include "_register_geometryutils.hxx"
#include "_register_graphbase.hxx"
#include "_register_simplemesh.hxx"
#include "_register_voronoi3d.hxx"

static maxon::Id g_usedFrameworks[] = {maxon::Id("net.maxon.core.framework")};
static maxon::SetUsedFrameworks g_setUsedFrameworks(PRIVATE_MAXON_MODULE, g_usedFrameworks);

#endif

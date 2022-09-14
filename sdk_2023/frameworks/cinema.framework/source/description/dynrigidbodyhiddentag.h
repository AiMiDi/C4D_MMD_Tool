#ifndef DYNRIGIDBODYHIDDENTAG_H__
#define DYNRIGIDBODYHIDDENTAG_H__

//
//	This file is only necessary to remove a run-time warning in modules/dynamics/source/rigid_body_tag.cpp
//	"DynRigidBodyTag"_s generates a warning because it's already passed in the previous line and should be unique.
//

enum
{
	RIGID_BODY_DUMMY
};

#endif // DYNRIGIDBODYHIDDENTAG_H__

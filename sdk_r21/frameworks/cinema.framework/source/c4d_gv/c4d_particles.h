/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef C4D_PARTICLES_H__
#define C4D_PARTICLES_H__

#define ID_THINKINGPARTICLES			1001428			///< Thinking Particles scene hook ID.
#define ID_TP_PGROUP							1001381			///< Thinking Particles particle group plugin ID.
#define ID_TP_PARTICLEGEOMETRY		1001414			///< Thinking Particles particle geometry plugin ID.

#define ID_TP_VALUE_TYPE_PARTICLE	1001394			///< %Particle value type ID.
#define ID_TP_DATA_TYPE_PARTICLE	1001395			///< %Particle data type ID.
#define ID_TP_VALUE_TYPE_SHAPE		1001396			///< Shape value type ID.
#define ID_TP_DATA_TYPE_SHAPE			1001397			///< Shape data type ID.
#define ID_TP_VALUE_TYPE_GROUP		1001398			///< Group value type ID.
#define ID_TP_DATA_TYPE_GROUP			1001399			///< Group data type ID.
#define ID_TP_VALUE_TYPE_SPIN			1001433			///< Spin value type ID.
#define ID_TP_DATA_TYPE_SPIN			1001434			///< Spin data type ID.


#define ID_TP_OPCLASS							1001385			///< Thinking Particles class ID.
#define ID_TP_OPGROUP_CONDITION		1001386			///< Thinking Particles condition group ID.
#define ID_TP_OPGROUP_HELPER			1001387			///< Thinking Particles helper group ID.
#define ID_TP_OPGROUP_INITIATOR		1001388			///< Thinking Particles initiator group ID.
#define ID_TP_OPGROUP_GENERATOR		1001389			///< Thinking Particles generator group ID.
#define ID_TP_OPGROUP_STANDARD		1001390			///< Thinking Particles standard group ID.
#define ID_TP_OPGROUP_DYNAMIC			1001391			///< Thinking Particles dynamic group ID.


#define ID_TP_OP_STORM						1001382			///< %Particle storm ID.
#define ID_TP_IN_SELFDYNAMIC			1001435			///< PPass ID.
#define ID_TP_HP_PARTICLEDATA			1001403			///< PGetData ID.
#define ID_TP_OP_PARTICLEDATA			1001404			///< PSetData ID.
#define ID_TP_IN_INTERACT					1001405			///< PPass AB ID.
#define ID_TP_IF_PARTICLEAGE			1001406			///< PAge ID.
#define ID_TP_HP_SPINCONVERT			1001408			///< PSpinConvert ID.
#define ID_TP_HP_PGROUP						1001409			///< PGroup ID (under TP Helper).
#define ID_TP_HP_VELOCITYCONVERT	1001410			///< PVelocityConvert ID.
#define ID_TP_OP_DEFLECTOR				1001411			///< PDeflector ID.
#define ID_TP_OP_POSFOLLOW				1001412			///< PPosition Follow ID.
#define ID_TP_OP_OBJECTSHAPE			1001413			///< PShape ID.
#define ID_TP_OP_SPIN							1001415			///< PSpin ID.
#define ID_TP_OP_ALIGNMENT				1001416			///< PAlignment ID.
#define ID_TP_OP_PGROUP						1001417			///< PGroup ID (under TP Standard).
#define ID_TP_OP_MASS							1001418			///< PMass ID.
#define ID_TP_OP_SIZE							1001419			///< PSize ID.
#define ID_TP_OP_SCALE						1001420			///< PScale ID.
#define ID_TP_OP_FRICTION					1001421			///< PFriction ID.
#define ID_TP_OP_VELOCITY					1001422			///< PVelocity ID.
#define ID_TP_OP_MOTIONINHERI			1001423			///< PMotionInheritance ID.
#define ID_TP_OP_BUBBLE						1001424			///< PBubble ID.
#define ID_TP_OP_DIE							1001425			///< PDie ID.
#define ID_TP_OP_GRAVITY					1001426			///< PGravity ID.
#define ID_TP_OP_WIND							1001427			///< PWind ID.
#define ID_TP_HP_TIMER						1001429			///< PTimer ID.
#define ID_TP_HP_CHRONOMETER			1001430			///< PChronometer ID.
#define ID_TP_OP_FRAGMENT					1001431			///< PFragment ID.
#define ID_TP_OP_FREEZE						1001432			///< PFreeze ID.
#define ID_TP_OP_REPULSEBOUNCE		1001436			///< PRepulse and Bounce ID.
#define ID_TP_OP_ROLLING					1001437			///< PRolling ID.
#define ID_TP_IF_LIGHT						1001438			///< PLight ID.
#define ID_THINKINGCOMMAND				1001439			///< Thinking Particles Settings command ID.
#define ID_TP_HP_SURFACEPOSITION	1001440			///< PSurfacePosition ID.
#define ID_TP_HP_VOLUMEPOSITION		1001441			///< PVolumePosition ID.
#define ID_TP_OP_BORN							1001442			///< PBorn ID.
#define TP_SN_HOOK								1001443			///< Thinking Particles serial ID.
#define ID_TP_OP_BLURP						1001444			///< PBlurp ID.
#define ID_TP_OP_PARTICLEDRAW			1001445			///< PDraw ID.
#define ID_TP_OP_PARTICLEDRAWTOOL	1001446			///< %Particle Draw tool ID.
#define ID_TP_OP_MATTERWAVES			1001447			///< PMatterWaves ID.
#define ID_TP_OP_FORCEOBJECT			1050000			///< PForceObject ID.

#include "ge_math.h"
#include "maxon/basearray.h"
#include "c4d_library.h"
#include "c4d_string.h"
#include "c4d_baselist.h"
#include "c4d_nodedata.h"
#include "c4d_objectdata.h"
#include "c4d_graphview.h"
#include "c4d_baseobject.h"
#include "c4d_basedocument.h"
#include "lib_collider.h"

#ifdef MAXON_TARGET_MACOS
	_Pragma("clang diagnostic push")
	_Pragma("clang diagnostic ignored \"-Wdocumentation\"")
#endif

#define THINKINGPARTICLES_VERSION			1																	///< Thinking Particles library version.
#define THINKINGPARTICLES_PRIORITY		GRAPHVIEW_HOOK_PRIORITY - 100			///< Thinking Particles priority.


class TP_PGroup;
class TP_ParticleNode;
class TP_MasterSystem;


#define TP_PGroupInfo					BaseContainer			///< Container with information about a group. The container IDs are private.

#define TP_DataChannelInfo		BaseContainer			///< Container with information about a channel. The container IDs are: @enumerateEnum{DATACHANNEL_INFO}
/// @addtogroup DATACHANNEL_INFO
/// @ingroup group_containerid
/// @{
#define DATACHANNEL_INFO_CHAN	100			///< ::Int32 Channel ID.
#define DATACHANNEL_INFO_NAME	101			///< ::Int32 Channel name.
#define DATACHANNEL_INFO_TYPE	102			///< ::Int32 Channel data type.
/// @}

//----------------------------------------------------------------------------------------
/// Array of TP_PGroup.
/// @see TP_MasterSystem::GetParticleGroups
//----------------------------------------------------------------------------------------
class TP_PGroupArray : public maxon::BaseArray<TP_PGroup*>
{
public:
	TP_PGroupArray() {}

	// In the move constructor you can use std::move() to initialize class members. Extra care must be taken if you want to call
	// the move constructor of your base class. Instead of BaseClass(std::move(src)) you should call C4D_MISC_MOVE_BASE_CLASS(src, BaseClass).
	// For compiler with C++11 rvalue reference this is equivalent to BaseClass(std::move(src)), but for older compilers it makes
	// sure that std::move() is called with a reference to src's base class (otherwise the compiler would try to call the copy constructor).
	TP_PGroupArray(TP_PGroupArray&& src) : maxon::BaseArray<TP_PGroup*>(std::move(src))
	{
	}

	//----------------------------------------------------------------------------------------
	/// Copies the TP_PGroupArray to another TP_PGroupArray.
	/// @param[out] dest							The destination TP_PGroupArray. @callerOwnsPointed{TP_PGroupArray}
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool CopyTo(TP_PGroupArray *dest) const
	{
		return dest->CopyFrom(*this, maxon::COLLECTION_RESIZE_FLAGS::DEFAULT) == maxon::OK;
	}

	//----------------------------------------------------------------------------------------
	/// Retrieves a TP_PGroup by index.
	/// @param[in] i									The index.
	/// @return												The TP_PGroup, or @formatConstant{nullptr} if i is out of range.
	//----------------------------------------------------------------------------------------
	TP_PGroup* GetIndex(Int i) const
	{
		if (i < 0 || i >= GetCount())
			return nullptr; // unfortunately this case was allowed in old GeTempDynArrays and is heavily used

		return maxon::BaseArray<TP_PGroup*>::operator[](i);
	}
};

struct TP_Spin
{
	Vector	axis;				///< Rotation axis.
	Float		speed;			///< Rotation speed.
};

/// @addtogroup TP_InsertMode
/// @ingroup group_enumeration
/// @{
enum TP_InsertMode
{
	TP_INSERT_NONE = 0,				///< Not used.
	TP_INSERT_UNDERFIRST,			///< Insert group as first child of parent.
	TP_INSERT_UNDERLAST,			///< Insert group as last child of parent.
	TP_INSERT_BEFORE,					///< Insert group before parent.
	TP_INSERT_AFTER						///< Insert group after parent.
};
/// @}

/// @addtogroup TP_GetPGroupMode
/// @ingroup group_enumeration
/// @{
enum TP_GetPGroupMode
{
	TP_GETPGROUP_ALL = 0,						///< All groups.
	TP_GETPGROUP_WITHPARTICLES,			///< Groups with particles.
	TP_GETPGROUP_SELECTED						///< Selected groups.
};
/// @}


/// Collision ID.
#define TP_Collision	Int32

//----------------------------------------------------------------------------------------
/// Implements this forward declaration to support collision callbacks.
/// @see TP_CollisionInterface
//----------------------------------------------------------------------------------------
class TP_BaseCollision {};

//----------------------------------------------------------------------------------------
/// Callback interface for nodes that register collisions.\n
/// The easiest way to create this is to implement the TP_BaseCollision class:\n
/// This class is only forward-declared in c4d_particles.h, so as long as the linker approves this is fine.\n
/// @b Example:
/// @code
/// class TP_BaseCollision
/// {
/// public:
/// 	TP_CollisionInterface ci;
/// 	TP_BaseCollision() { ci.base = this; }
///
/// 	Bool CheckCollision(TP_Collision, TP_MasterSystem *msys, Int32 pid, Float t,
/// 											Vector &pos, Vector &vel, TP_Spin &spin, Float dt, Float &ct)
/// 	{
/// 		// ...
/// 	}
/// };
/// @endcode
/// In the @ref TP_MSG_GET_COLLISIONINTERFACE message then simply set the passed TP_CollisionInterface pointer to @c &basecol.ci, for a global TP_BaseCollision @c basecol object that was previously created.\n
/// Thinking Particles will then call CheckCollision() as needed.
//----------------------------------------------------------------------------------------
struct TP_CollisionInterface
{
	TP_BaseCollision *base;			///< Base class pointer.

	//----------------------------------------------------------------------------------------
	/// Called by Thinking Particles when a collision handle is registered with TP_MasterSystem::SetCollision(), and provided Thinking Particles with a TP_CollisionInterface in the @ref TP_MSG_GET_COLLISIONINTERFACE message.\n
	/// Evaluate the passed collision parameters and set the output parameters. Thinking Particles will then update the particle values.
	/// @param[in] collision					The collision ID. This is GvNode::GetOperatorID() for the node responsible for the collision.
	/// @param[in] msys								The master system. @callerOwnsPointed{TP_MasterSystem}
	/// @param[in] pid								The particle ID: @em 0 <= @formatParam{pid} < @formatParam{msys}->@link TP_MasterSystem::NumParticles NumParticles()@endlink
	/// @param[in] t									The time to evaluate the collision at. Collisions are detected between @formatParam{t} - @formatParam{dt} and @formatParam{t}t.
	/// @param[out] pos								Assign the new position of the object if there is a collision.
	/// @param[out] vel								Assign the new velocity of the object if there is a collision.
	/// @param[out] spin							Assign the new spin of the object if there is a collision.
	/// @param[in] dt									The time since the last evaluation, i.e. the time to look backwards for collisions.
	/// @param[in] ct									Assign the collision time, if there was a collision. This will generally be less than @formatParam{t}.
	/// @return												@trueIfOtherwiseFalse{there was a collision}
	//----------------------------------------------------------------------------------------
	Bool (TP_BaseCollision::*CheckCollision)(TP_Collision collision, TP_MasterSystem *msys, Int32 pid, Float t, Vector &pos, Vector &vel, TP_Spin &spin, Float dt, Float &ct);
};

#include <string.h>

//----------------------------------------------------------------------------------------
/// PShape datatype.
//----------------------------------------------------------------------------------------
struct TP_PShapeI
{
	Int32	owner_id;			///< Owner ID of the shape. This is TP_MasterSystem::GetOperatorID() for the node responsible for the shape.
	Int32	refcnt;				///< The reference count of the shape.

	//----------------------------------------------------------------------------------------
	/// Default constructor.
	//----------------------------------------------------------------------------------------
	TP_PShapeI() : owner_id(NOTOK), refcnt(0) { }

	//----------------------------------------------------------------------------------------
	/// Destructor.
	//----------------------------------------------------------------------------------------
	virtual ~TP_PShapeI()
	{
	}
};

//----------------------------------------------------------------------------------------
/// Wrapper around a TP_PShapeI pointer.
//----------------------------------------------------------------------------------------
class TP_PShapePtr
{
		TP_PShapeI *ptr;
	public:
		//----------------------------------------------------------------------------------------
		/// Default constructor.
		//----------------------------------------------------------------------------------------
		TP_PShapePtr() { ptr = nullptr; }

		//----------------------------------------------------------------------------------------
		/// Copy constructor.
		/// @param[in] p									The TP_PShapePtr to copy.
		//----------------------------------------------------------------------------------------
		TP_PShapePtr(const TP_PShapePtr &p)
		{
			ptr = p.ptr;
			if (ptr)
			{
				ptr->refcnt++;
			}
		}

		//----------------------------------------------------------------------------------------
		/// Creates a TP_PShapePtr from a TP_PShapeI pointer.
		/// @param[in] p									The TP_PShapeI pointer.
		//----------------------------------------------------------------------------------------
		MAXON_IMPLICIT TP_PShapePtr(TP_PShapeI *p)
		{
			ptr = p;
			if (ptr)
			{
				ptr->refcnt++;
			}
		}

		//----------------------------------------------------------------------------------------
		/// Equality operator.
		/// @param[in] p									The TP_PShapePtr to compare with.
		/// @return												@trueIfOtherwiseFalse{the internal TP_PShapeI pointers are equal}
		//----------------------------------------------------------------------------------------
		Bool operator == (const TP_PShapePtr &p)
		{
			return ptr == p.ptr;
		}

		//----------------------------------------------------------------------------------------
		/// Inequality operator.
		/// @param[in] p									The TP_PShapePtr to compare with.
		/// @return												@trueIfOtherwiseFalse{the internal TP_PShapeI pointers are not equal}
		//----------------------------------------------------------------------------------------
		Bool operator != (const TP_PShapePtr &p)
		{
			return ptr != p.ptr;
		}

		//----------------------------------------------------------------------------------------
		/// Assignment operator.
		/// @param[in] p									The TP_PShapePtr to assign.
		/// @return												*this.
		//----------------------------------------------------------------------------------------
		const TP_PShapePtr& operator = (const TP_PShapePtr &p)
		{
			if (ptr)
			{
				ptr->refcnt--;
				if (ptr->refcnt == 0)
				{
					DeleteObj(ptr);
				}
			}
			ptr = p.ptr;
			if (ptr)
			{
				ptr->refcnt++;
			}
			return *this;
		}

		//----------------------------------------------------------------------------------------
		/// Assignment operator.
		/// @param[in] p									The TP_PShapeI to assign to the internal pointer.
		/// @return												*this.
		//----------------------------------------------------------------------------------------
		const TP_PShapePtr& operator = (TP_PShapeI *p)
		{
			*this = TP_PShapePtr(p);
			return *this;
		}

		//----------------------------------------------------------------------------------------
		/// Checks if the internal TP_PShapeI pointer has been set.
		/// @return												@trueIfOtherwiseFalse{the internal TP_PShapeI pointer is not @formatConstant{nullptr}}
		//----------------------------------------------------------------------------------------
		Bool IsPopulated() const
		{
			return ptr != nullptr;
		}

		//----------------------------------------------------------------------------------------
		/// Retrieves the internal TP_PShapeI pointer.
		/// @return												The internal TP_PShapeI pointer.
		//----------------------------------------------------------------------------------------
		TP_PShapeI *Get() const
		{
			return ptr;
		}

		//----------------------------------------------------------------------------------------
		/// Destructor
		//----------------------------------------------------------------------------------------
		~TP_PShapePtr()
		{
			if (ptr)
			{
				ptr->refcnt--;
				if (ptr->refcnt == 0)
				{
					DeleteObj(ptr);
				}
			}
		}
};

//----------------------------------------------------------------------------------------
/// Implements this forward declaration to support PShape callbacks.
/// @see TP_PShapeInterface
//----------------------------------------------------------------------------------------
class TP_BaseShape {};

//----------------------------------------------------------------------------------------
/// Callback interface for nodes that register shapes.\n
/// The easiest way to create this is to implement the TP_BaseShape class:\n
/// This class is only forward-declared in c4d_particles.h, so as long as the linker approves this is fine.\n
/// @b Example:
/// @code
/// class TP_BaseShape
/// {
/// public:
/// 	TP_PShapeInterface si;
/// 	TP_BaseShape() { si.base = this; }
///
/// 	TP_PShape* GetShapeClone(TP_PShapePtr &shape , TP_MasterSystem *msys, Int32 pid, Int32 flags, AliasTrans *trn)
/// 	{
/// 		// ...
/// 	}
///
/// 	TP_PShape* GetShape(TP_PShapePtr &shape , TP_MasterSystem *msys, Int32 pid, Int32 owner_id)
/// 	{
/// 		// ...
/// 	}
///
/// 	BaseObject* GetShapeVirtualObjects(TP_PShapePtr &shape , TP_MasterSystem *msys, Int32 pid, BaseDocument *doc, HierarchyHelp *hh)
/// 	{
/// 		// ...
/// 	}
///
/// 	Float GetShapeScale(TP_PShapePtr &shape , TP_MasterSystem *msys, Int32 pid)
/// 	{
/// 		// ...
/// 	}
///
/// 	void FreeShape(TP_PShapePtr &shape, TP_MasterSystem *msys, Int32 pid)
/// 	{
/// 		// ...
/// 	}
/// };
/// @endcode
/// In the @ref TP_MSG_GET_PSHAPEINTERFACE message then simply set the passed pointer TP_PShapeInterface to @c &baseshape.si, for a global TP_BaseShape @c baseshape object that was previously created.\n
/// Thinking Particles will then call the shape functions as needed.
//----------------------------------------------------------------------------------------
struct TP_PShapeInterface
{
	TP_BaseShape* base;			///< Base class pointer.

	//----------------------------------------------------------------------------------------
	/// Return a clone of @formatParam{shape}.
	/// @param[in] shape							The particle shape pointer structure of the particle shape handle.
	/// @param[in] msys								The master system. @callerOwnsPointed{TP_MasterSystem}
	/// @param[in] pid								The particle ID: @em 0 <= @formatParam{pid} < @formatParam{msys}->@link TP_MasterSystem::NumParticles NumParticles()@endlink
	/// @param[in] flags							The flags: @enumerateEnum{COPYFLAGS}
	/// @param[in] trn								An alias translator for the operation. Can be @formatConstant{nullptr}. @callerOwnsPointed{AliasTrans}
	/// @return												The particle shape pointer structure of the cloned particle shape. @callerOwnsPointed{TP_PShapePtr}
	//----------------------------------------------------------------------------------------
	TP_PShapePtr (TP_BaseShape::*GetShapeClone)(const TP_PShapePtr &shape, TP_MasterSystem *msys, Int32 pid, COPYFLAGS flags, AliasTrans *trn);

	//----------------------------------------------------------------------------------------
	/// Return the shape associated with @formatParam{shape}.
	/// Normally this is the same object, so a typical implementation would be:
	/// @code
	/// TP_PShapePtr GetShape(TP_PShapePtr &shape , TP_MasterSystem *msys, Int32 pid, Int32 owner_id)
	/// {
	/// 	if (shape->Get()->owner_id == owner_id)
	/// 		return TP_ShapePtr(shape);
	/// 	return nullptr;
	/// }
	/// @endcode
	/// @param[in] shape							The particle shape pointer structure of the particle shape handle.
	/// @param[in] msys								The master system. @callerOwnsPointed{TP_MasterSystem}
	/// @param[in] pid								The particle ID: @em 0 <= @formatParam{pid} < @formatParam{msys}->@link TP_MasterSystem::NumParticles NumParticles()@endlink
	/// @param[in] owner_id						The owner ID.
	/// @return												The particle shape pointer structure. @theOwnsPointed{shape handler,shape}
	//----------------------------------------------------------------------------------------
	TP_PShapePtr (TP_BaseShape::*GetShape)(const TP_PShapePtr &shape, TP_MasterSystem *msys, Int32 pid, Int32 owner_id);

	//----------------------------------------------------------------------------------------
	/// Return a real BaseObject for @formatParam{shape}.
	/// @param[in] shape							The particle shape pointer structure of the particle shape handle.
	/// @param[in] msys								The master system. @callerOwnsPointed{TP_MasterSystem}
	/// @param[in] pid								The particle ID: @em 0 <= @formatParam{pid} < @formatParam{msys}->@link TP_MasterSystem::NumParticles NumParticles()@endlink
	/// @param[in] doc								The current document. @callerOwnsPointed{BaseDocument}
	/// @param[in] hh									A hierarchy helper for the operation. @callerOwnsPointed{HierarchyHelp}
	/// @return												The particle shape object. @theOwnsPointed{particle shape handler,object}
	//----------------------------------------------------------------------------------------
	BaseObject* (TP_BaseShape::*GetShapeVirtualObjects)(const TP_PShapePtr &shape, TP_MasterSystem *msys, Int32 pid, BaseDocument *doc, HierarchyHelp *hh);

	//----------------------------------------------------------------------------------------
	/// Return the scale of the particle shape.
	/// @param[in] shape							The particle shape pointer structure of the particle shape handle.
	/// @param[in] msys								The master system. @callerOwnsPointed{TP_MasterSystem}
	/// @param[in] pid								The particle ID: @em 0 <= @formatParam{pid} < @formatParam{msys}->@link TP_MasterSystem::NumParticles NumParticles()@endlink
	/// @return												The particle shape scale.
	//----------------------------------------------------------------------------------------
	Float (TP_BaseShape::*GetShapeScale)(const TP_PShapePtr &shape, TP_MasterSystem *msys, Int32 pid);

	//----------------------------------------------------------------------------------------
	/// Free the particle shape.
	/// @param[in] shape							The particle shape pointer structure of the particle shape handle.
	/// @param[in] msys								The master system. @callerOwnsPointed{TP_MasterSystem}
	/// @param[in] pid								The particle ID: @em 0 <= @formatParam{pid} < @formatParam{msys}->@link TP_MasterSystem::NumParticles NumParticles()@endlink
	//----------------------------------------------------------------------------------------
	void (TP_BaseShape::*FreeShape)(TP_PShapePtr &shape , TP_MasterSystem *msys, Int32 pid);
};

//----------------------------------------------------------------------------------------
/// Callback interface for the free-particle event.\n
/// Use TP_MasterSystem::Reg_FreeParticle_CB() and TP_MasterSystem::UReg_FreeParticle_CB() to register and remove the callback.
//----------------------------------------------------------------------------------------
struct TP_FreeParticle_CB
{

	//----------------------------------------------------------------------------------------
	/// Called when particle @formatParam{pid} is freed.
	/// @param[in] cb									The TP_FreeParticle_CB callback object.
	/// @param[in] pid								The particle ID: @em 0 <= @formatParam{pid} < @formatParam{msys}->@link TP_MasterSystem::NumParticles NumParticles()@endlink
	//----------------------------------------------------------------------------------------
	void (*FreeParticle)(TP_FreeParticle_CB *cb, Int32 pid);
};

//----------------------------------------------------------------------------------------
/// Callback interface for the free-pshape event.\n
/// Use TP_MasterSystem::Reg_DeletePShape_CB() and TP_MasterSystem::UReg_DeletePShape_CB() to register and remove the callback.
//----------------------------------------------------------------------------------------
struct TP_FreePShape_CB
{
	//----------------------------------------------------------------------------------------
	/// Called when @formatParam{shape} of particle @formatParam{pid} is freed.
	/// @param[in] cb									The TP_FreeParticle_CB callback object.
	/// @param[in] pid								The particle ID: @em 0 <= @formatParam{pid} < @formatParam{msys}->@link TP_MasterSystem::NumParticles NumParticles()@endlink
	/// @param[in] shape							The particle shape pointer structure of the particle shape handle.
	//----------------------------------------------------------------------------------------
	void (*FreePShape)(TP_FreePShape_CB *cb, Int32 pid, const TP_PShapePtr &shape);
};

/// @addtogroup TP_MSG
/// @ingroup group_enumeration
/// @{
enum
{
	TP_MSG_PGROUP_PREREMOVE = 1000000,			///< Sent before a PGroup is removed in the Thinking Particles settings. @c data points to a TP_PGroupPreRemove.
	TP_MSG_PGROUP_TREECHANGED,							///< Sent when the PGroup structure is changed, for example by renaming, adding or reordering the groups. @c data is @formatConstant{nullptr}.
	TP_MSG_DCHANNEL_PREREMOVE,							///< Sent before a data channel is removed. @c data is the channel number, cast it to ::Int32.
	TP_MSG_DCHANNEL_CHANGED,								///< Sent when the data channel list is changed. @c data is @formatConstant{nullptr}.
	TP_MSG_GET_PSHAPEINTERFACE,							///< Sent to get the PShape interface. @c data points to a TP_PShapeInterface pointer. Set this pointer to points to your own PShape interface.\n
																					///< The sender owns the pointed pointer. The receiver owns the pointed interface.
	TP_MSG_GET_COLLISIONINTERFACE,					///< Sent to get the collision interface. @c data points to a TP_CollisionInterface pointer. Set this pointer to points to your own collision interface.\n
																					///< The sender owns the pointed pointer. The receiver owns the pointed interface.
	TP_MSG_OBJECT_GETPARTICLES							///< Can be sent by anyone to the ParticleGeometry object to get its particles. Used for example by the PyroCluster material.\n
																					///< @c data points to a TP_PGroupArray that is filled with particles. The sender owns the pointed array.
};
/// @}

//----------------------------------------------------------------------------------------
/// Message structure for Thinking Particles messages.
/// Sent to NodeData::Message() with @c type set to @ref ID_THINKINGPARTICLES and @c data pointing to this structure.
//----------------------------------------------------------------------------------------
struct TP_Msg
{
	Int32							msg;			///< The message type: @enumerateEnum{TP_MSG}
	TP_MasterSystem*	msys;			///< The master system. The sender owns the pointed TP_MasterSystem.
	void*							data;			///< The message data. Depends on the message type @ref msg.
};

//----------------------------------------------------------------------------------------
/// Data structure for @ref TP_MSG_PGROUP_PREREMOVE message.
//----------------------------------------------------------------------------------------
struct TP_PGroupPreRemove
{
	TP_PGroup*	pgroup;			///< The group to remove.
	Bool				used;				///< @formatConstant{true} if the group is used.
};


/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

struct C4D_TP_MASTERSYSTEM
{
	Int32		(TP_MasterSystem::*AllocParticle				)(void);
	Int32		(TP_MasterSystem::*AllocParticles				)(Int32 num, Int32 *ids);
	void		(TP_MasterSystem::*FreeParticle					)(Int32 pid);
	void		(TP_MasterSystem::*FreeAllParticles			)(void);

	TP_PGroup*				(TP_MasterSystem::*AllocParticleGroup					)(void);
	void							(TP_MasterSystem::*FreeParticleGroup					)(TP_PGroup *&group);
	Bool							(TP_MasterSystem::*SetPGroupHierarchy					)(TP_PGroup *parent , TP_PGroup *group, TP_InsertMode mode);
	Int32							(TP_MasterSystem::*GetGroupParticleCount			)(TP_PGroup *ingroup, Bool subgroups);
	BaseObject*				(TP_MasterSystem::*GetVirtualObjects					)(TP_PGroup *ingroup, Bool inRender, Bool subgroups, HierarchyHelp *hh);
	TP_PGroupInfo*		(TP_MasterSystem::*GetGroupInfo								)(TP_PGroup *group);
	TP_PGroup*				(TP_MasterSystem::*GetGroupFromInfo						)(TP_PGroupInfo *info);

	Int32						(TP_MasterSystem::*NumParticles			)(void);
	Bool						(TP_MasterSystem::*Alive						)(Int32 pid);
	Bool						(TP_MasterSystem::*IsBorn						)(Int32 pid);
	Bool						(TP_MasterSystem::*IsDie						)(Int32 pid);
	Bool						(TP_MasterSystem::*EntersGroup			)(Int32 pid);
	TP_PGroup*			(TP_MasterSystem::*Group						)(Int32 pid);
	Vector					(TP_MasterSystem::*Position					)(Int32 pid);
	Vector					(TP_MasterSystem::*Velocity					)(Int32 pid);
	Float						(TP_MasterSystem::*Mass							)(Int32 pid);
	TP_Spin					(TP_MasterSystem::*Spin							)(Int32 pid);
	Float						(TP_MasterSystem::*Size							)(Int32 pid);
	Vector					(TP_MasterSystem::*Scale						)(Int32 pid);
	BaseTime				(TP_MasterSystem::*Age							)(Int32 pid);
	BaseTime				(TP_MasterSystem::*Life							)(Int32 pid);
	Matrix					(TP_MasterSystem::*Alignment				)(Int32 pid);
	Int32						(TP_MasterSystem::*Randomseed				)(Int32 pid);
	TP_PShapePtr		(TP_MasterSystem::*Shape						)(Int32 pid);
	Matrix					(TP_MasterSystem::*Transform				)(Int32 pid);
	UInt16					(TP_MasterSystem::*Flags						)(Int32 pid);
	Float						(TP_MasterSystem::*DTFactor					)(Int32 pid);

	void		(TP_MasterSystem::*SetPosition				)(Int32 pid, const Vector &p);
	void		(TP_MasterSystem::*SetVelocity				)(Int32 pid, const Vector &p);
	void		(TP_MasterSystem::*SetMass						)(Int32 pid, Float mass);
	void		(TP_MasterSystem::*SetSpin						)(Int32 pid, const TP_Spin &spin);
	void		(TP_MasterSystem::*SetAge							)(Int32 pid, const BaseTime &age);
	void		(TP_MasterSystem::*SetLife						)(Int32 pid, const BaseTime &life);
	void		(TP_MasterSystem::*SetGroup						)(Int32 pid, TP_PGroup *group);
	void		(TP_MasterSystem::*SetSize						)(Int32 pid, Float size);
	void		(TP_MasterSystem::*SetScale						)(Int32 pid, const Vector &scale);
	void		(TP_MasterSystem::*SetAlignment				)(Int32 pid, const Matrix &align);
	void		(TP_MasterSystem::*SetRandomseed			)(Int32 pid, Int32 seed);
	void		(TP_MasterSystem::*SetShape						)(Int32 pid, const TP_PShapePtr &shape, Bool deleteold);
	void		(TP_MasterSystem::*SetCollision				)(Int32 pid, TP_Collision collision);
	void		(TP_MasterSystem::*SetDTFactor				)(Int32 pid, Float dt);


	Bool				(TP_MasterSystem::*AddDataChannel						)(GvDataID type, const maxon::String& str);
	Bool				(TP_MasterSystem::*RemoveDataChannel				)(Int32 chan);
	Int32				(TP_MasterSystem::*NumDataChannels					)(void);
	GvDataID		(TP_MasterSystem::*DataChannelType					)(Int32 chan);
	String			(TP_MasterSystem::*DataChannelName					)(Int32 chan);
	Int32				(TP_MasterSystem::*DataChannelUniqueID			)(Int32 chan);
	Int32				(TP_MasterSystem::*DataChannelID						)(Int32 unique_id);

	Bool		(TP_MasterSystem::*SetData							)(Int32 pid, Int32 chan, void *data, GvValueID type);
	Bool		(TP_MasterSystem::*GetData							)(Int32 pid, Int32 chan, void *data, GvValueID type);
	Bool		(TP_MasterSystem::*SetDataFromPort			)(Int32 pid, Int32 chan, GvPort *p, GvRun *r);
	Bool		(TP_MasterSystem::*SetDataToPort				)(Int32 pid, Int32 chan, GvPort *p, GvRun *r);

	TP_DataChannelInfo*		(TP_MasterSystem::*GetDataChannelInfo					)(Int32 chan);
	Int32									(TP_MasterSystem::*GetDataChannelFromInfo			)(TP_DataChannelInfo *info);

	void		(TP_MasterSystem::*Reg_FreeParticle_CB			)(TP_FreeParticle_CB *cb);
	void		(TP_MasterSystem::*UReg_FreeParticle_CB			)(TP_FreeParticle_CB *cb);
	void		(TP_MasterSystem::*Reg_FreePShape_CB				)(TP_FreePShape_CB *cb);
	void		(TP_MasterSystem::*UReg_FreePShape_CB				)(TP_FreePShape_CB *cb);

	Int32							(TP_MasterSystem::*GetOperatorID			)(GvNode *op);
	GvOperatorData*		(TP_MasterSystem::*GetOperator				)(Int32 id);

	UInt32		(TP_MasterSystem::*GetDirty			)(void) const;
	void			(TP_MasterSystem::*SetDirty			)(void);

	Bool		(TP_MasterSystem::*CheckCollision			)(TP_Collision collision, Int32 pid, Float t, Vector &pos, Vector &vel, TP_Spin &spin, Float dt, Float &ct);

	TP_PShapePtr		(TP_MasterSystem::*GetShapeClone							)(const TP_PShapePtr &shape , Int32 pid, COPYFLAGS flags, AliasTrans *trn);
	TP_PShapePtr		(TP_MasterSystem::*GetShape										)(const TP_PShapePtr &shape , Int32 pid, Int32 owner_id);
	BaseObject*			(TP_MasterSystem::*GetShapeVirtualObjects			)(const TP_PShapePtr &shape , Int32 pid, BaseDocument *doc, HierarchyHelp *hh);
	Float						(TP_MasterSystem::*GetShapeScale							)(const TP_PShapePtr &shape , Int32 pid);
	void						(TP_MasterSystem::*FreeShape									)(TP_PShapePtr &shape, Int32 pid);

	GeColliderCache*			(TP_MasterSystem::*ColliderCache			)(Int32 pid);

	Int32		(TP_MasterSystem::*GetParticleGroups			)(TP_PGroup *ingroup, TP_PGroupArray *gtab, TP_GetPGroupMode mode, Bool subgroups);

	Vector32	(TP_MasterSystem::*Color				)(Int32 pid);
	void			(TP_MasterSystem::*SetColor			)(Int32 pid, const Vector32& color);

	Bool			(TP_MasterSystem::*UpdateGroup)(TP_PGroup* group, const BaseTime& timeDelta);
};

struct C4D_TP_PGROUP
{
	Int32								(TP_PGroup::*GetLevel						)(void);
	TP_ParticleNode*		(TP_PGroup::*GetFirstNode				)(void);
	TP_ParticleNode*		(TP_PGroup::*GetLastNode				)(void);
	Int32								(TP_PGroup::*NumParticles				)(void);
	Bool								(TP_PGroup::*IsSubGroup					)(TP_PGroup *group);
	Int32								(TP_PGroup::*GetGroupID					)(void);
	const String				(TP_PGroup::*GetTitle						)(void);
	void								(TP_PGroup::*SetTitle						)(const maxon::String &title);
	void								(TP_PGroup::*SetViewType				)(Int32 type);
	Int32								(TP_PGroup::*GetViewType				)(void);
	void								(TP_PGroup::*SetShowObjects			)(Bool show);
	Bool								(TP_PGroup::*GetShowObjects			)(void);
	void								(TP_PGroup::*SetColor						)(Vector &col);
	Vector							(TP_PGroup::*GetColor						)(void);
	Bool								(TP_PGroup::*EditSettings				)(void);
	Bool								(TP_PGroup::*IsSelected					)(void);
	Bool								(TP_PGroup::*IsOpened						)(void);
	void								(TP_PGroup::*Select							)(Int32 mode);
	void								(TP_PGroup::*Open								)(Bool onoff);
	void								(TP_PGroup::*SetUseColor				)(Bool useCol);
	Bool								(TP_PGroup::*GetUseColor				)(void);
	void								(TP_PGroup::*Cache							)(Bool onoff);
	Bool								(TP_PGroup::*IsCache						)(void);
};

struct C4D_TP_PARTICLENODE
{
	Int32								(TP_ParticleNode::*GetParticleID			)(void);
	TP_ParticleNode*		(TP_ParticleNode::*GetNext						)(void);
	TP_ParticleNode*		(TP_ParticleNode::*GetPrev						)(void);
};

struct C4DLibrary_TPOS : public C4DLibrary
{
	C4D_TP_MASTERSYSTEM	*MSYS;
	C4D_TP_PGROUP				*GROUP;
	C4D_TP_PARTICLENODE	*PART;
};

extern C4DLibrary_TPOS *TPOS;

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

#define TpCall(fnc) (this->*TPOS->MSYS->fnc)

//----------------------------------------------------------------------------------------
/// The master system is the main Thinking Particles engine class. There can only be one master system per document. This is the easiest way to get it:
/// @code
/// TP_MasterSystem* GetTpMasterSystem(BaseDocument* doc)
/// {
/// 	if (!doc)
/// 		return nullptr;
///
/// 	BaseSceneHook* hook = doc->FindSceneHook(ID_THINKINGPARTICLES);
/// 	if (!hook || hook->GetType() != ID_THINKINGPARTICLES)
/// 		return nullptr;
///
/// 	return static_cast<TP_MasterSystem*>(hook);
/// }
/// @endcode
//----------------------------------------------------------------------------------------
class TP_MasterSystem : public BaseSceneHook
{
private:
	TP_MasterSystem();
	~TP_MasterSystem();
public:
	/// @name Particle/Particles
	/// @{

	//----------------------------------------------------------------------------------------
	/// Allocates a particle.
	/// @return												The particle ID of the allocated particle, or @ref NOTOK if the allocation failed.
	//----------------------------------------------------------------------------------------
	Int32 AllocParticle(void) { return TpCall(AllocParticle)(); }

	//----------------------------------------------------------------------------------------
	/// Allocates @formatParam{num} particles and stores their particles IDs in the @formatParam{ids} array.
	/// @param[in] num								The number of particles to allocate.
	/// @param[out] ids								An array of @formatParam{num} ::Int32 elements. Filled with the allocated particle IDs. @callerOwnsPointed{array}
	/// @return												The number of particles allocated, or @ref NOTOK if the allocation failed.
	//----------------------------------------------------------------------------------------
	Int32 AllocParticles(Int32 num, Int32 *ids) { return TpCall(AllocParticles)(num, ids); }

	//----------------------------------------------------------------------------------------
	/// Frees a particle.
	/// @note Normally this should not be used. Instead SetLife() should be uses with a negative time, so that the particle in question dies immediately.
	/// @param[in] pid								The particle ID of the particle to free: @em 0 <= @formatParam{pid} < NumParticles()
	//----------------------------------------------------------------------------------------
	void FreeParticle(Int32 pid) { TpCall(FreeParticle)(pid); }

	//----------------------------------------------------------------------------------------
	/// Frees all particles.
	/// @note Normally this should not be used. Instead SetLife() should be uses with a negative time, so that the particles dies immediately.
	//----------------------------------------------------------------------------------------
	void FreeAllParticles(void) { TpCall(FreeAllParticles)(); }

	//----------------------------------------------------------------------------------------
	/// Retrieves the number of allocated particles. All particles IDs are less than this value.
	/// @return												The number of particles.
	//----------------------------------------------------------------------------------------
	Int32 NumParticles(void) { return TpCall(NumParticles)(); }

	/// @}

	/// @name Particle Group
	/// @{

	//----------------------------------------------------------------------------------------
	/// Allocates a new particle group. Must be freed with FreeParticleGroup(), or inserted into the list with SetPGroupHierarchy().
	/// @return												The allocate particle group. @callerOwnsPointed{TP_PGroup}
	//----------------------------------------------------------------------------------------
	TP_PGroup* AllocParticleGroup(void) { return TpCall(AllocParticleGroup)(); }

	//----------------------------------------------------------------------------------------
	/// Frees a particle group, removing it from the list.
	/// @param[in,out] group					The group to free. Set to @formatConstant{nullptr} afterwards.
	//----------------------------------------------------------------------------------------
	void FreeParticleGroup(TP_PGroup *&group) { TpCall(FreeParticleGroup)(group); }

	//----------------------------------------------------------------------------------------
	/// Performs a hierarchy action on a particle group.
	/// @param[in] parent							The parent parameter. @callerOwnsPointed{TP_PGroup}
	/// @param[in] group							The group to act on. @callerOwnsPointed{TP_PGroup}
	/// @param[in] mode								The hierarchy action: @enumerateEnum{TP_InsertMode}
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool SetPGroupHierarchy(TP_PGroup *parent , TP_PGroup *group, TP_InsertMode mode) { return TpCall(SetPGroupHierarchy)(parent, group, mode); }

	//----------------------------------------------------------------------------------------
	/// Returns the particle groups in @formatParam{ingroup}, specified by @formatParam{mode}, into the @formatParam{gtab} list.\n
	/// @b Example:
	/// @code
	/// PluginSceneHook* hook = doc->FindSceneHook(ID_THINKINGPARTICLES);
	/// if (hook && hook->GetType() == ID_THINKINGPARTICLES)
	/// {
	/// 	TP_MasterSystem *tpm = (TP_MasterSystem*)hook;
	/// 	TP_PGroupArray groups;
	/// 	Int32 gcnt = tpm->GetParticleGroups(nullptr, &groups, TP_GETPGROUP_ALL, false);
	/// 	// For subgroups
	/// 	//Int32 gcnt = tpm->GetParticleGroups(nullptr,&groups, TP_GETPGROUP_ALL, true);
	///
	/// 	TP_PGroup *grp = (TP_PGroup*)groups.GetIndex(0); // grp is the "All" group
	///
	/// 	//To iterate
	/// 	//for (Int32 i=0; i<gcnt; i++)
	/// 	//{
	/// 	//	TP_PGroup *grp = (TP_PGroup*)groups.GetIndex(i);
	/// 	//}
	/// }
	/// @endcode
	/// @param[in] ingroup						The in-group parameter. @callerOwnsPointed{TP_PGroup}
	/// @param[out] gtab							The specified groups are added to this list. @callerOwnsPointed{TP_PGroup}
	/// @param[in] mode								The mode: @enumerateEnum{TP_GetPGroupMode}
	/// @param[in] subgroups					If @formatConstant{true} sub-groups are included.
	/// @return												The number of groups added to @formatParam{gtab}.
	//----------------------------------------------------------------------------------------
	Int32 GetParticleGroups(TP_PGroup *ingroup, TP_PGroupArray *gtab, TP_GetPGroupMode mode, Bool subgroups = true) { return TpCall(GetParticleGroups)(ingroup, gtab, mode, subgroups); }

	//----------------------------------------------------------------------------------------
	/// Calculates the number of particles in @formatParam{ingroup}.
	/// @param[in] ingroup						The in-group parameter. @callerOwnsPointed{TP_PGroup}
	/// @param[in] subgroups					If @formatConstant{true} sub-groups are included.
	/// @return												The number of particles in the specified group.
	//----------------------------------------------------------------------------------------
	Int32 GetGroupParticleCount(TP_PGroup *ingroup, Bool subgroups = true) { return TpCall(GetGroupParticleCount)(ingroup, subgroups); }

	//----------------------------------------------------------------------------------------
	/// Creates the virtual object hierarchy for a particle group, i.e. an object group containing all particles. Used by the ParticleGeometry object.
	/// @param[in] ingroup						The in-group parameter. @callerOwnsPointed{TP_PGroup}
	/// @param[in] inRender						@formatConstant{true} if this is for rendering, otherwise the objects are built for the editor view.
	/// @param[in] subgroups					If @formatConstant{true} sub-groups are included.
	/// @param[in] hh									The hierarchy helper for the virtual object generation. @callerOwnsPointed{HierarchyHelp}
	/// @return												The virtual object, or @formatConstant{nullptr} if there was an error.
	//----------------------------------------------------------------------------------------
	BaseObject* GetVirtualObjects(TP_PGroup *ingroup, Bool inRender = true, Bool subgroups = true, HierarchyHelp *hh = nullptr) { return TpCall(GetVirtualObjects)(ingroup, inRender, subgroups, hh); }

	//----------------------------------------------------------------------------------------
	/// Retrieves the group information for a @formatParam{group}.
	/// @param[in] group							The group to get the information for. @callerOwnsPointed{TP_PGroup}
	/// @return												The group information for group. @callerOwnsPointed{@ref TP_PGroupInfo}
	//----------------------------------------------------------------------------------------
	TP_PGroupInfo* GetGroupInfo(TP_PGroup *group) { return TpCall(GetGroupInfo)(group); }

	//----------------------------------------------------------------------------------------
	/// Retrieves a group from the information in @formatParam{info}.
	/// @param[in] info								The group information to search for. @callerOwnsPointed{@ref TP_PGroupInfo}
	/// @return												The retrieved group, or @formatConstant{nullptr} if no group matched. @theOwnsPointed{master system,TP_PGroup}
	//----------------------------------------------------------------------------------------
	TP_PGroup* GetGroupFromInfo(TP_PGroupInfo *info) { return TpCall(GetGroupFromInfo)(info); }

	//----------------------------------------------------------------------------------------
	/// Updates a group at a given time difference since the last update. Use a default @formatParam{timeDelta} of @em 0 to update at the current time.
	/// @since R16.050
	/// @param[in] group							The group to update. @callerOwnsPointed{TP_PGroup}
	/// @param[in] timeDelta					The time difference since the last update.
	/// @return												@trueIfOtherwiseFalse{the update was done successfully}
	//----------------------------------------------------------------------------------------
	Bool UpdateGroup(TP_PGroup* group, const BaseTime& timeDelta) { return TpCall(UpdateGroup)(group, timeDelta); }

	/// @}

	/// @name Particle Information/Bits
	/// @{

	//----------------------------------------------------------------------------------------
	/// Retrieves the alive bit of a particle.
	/// @param[in] pid								The particle ID: @em 0 <= @formatParam{pid} < NumParticles()
	/// @return												@trueIfOtherwiseFalse{the particle is alive}
	//----------------------------------------------------------------------------------------
	Bool Alive(Int32 pid) { return TpCall(Alive)(pid); }

	//----------------------------------------------------------------------------------------
	/// Retrieves the is-born bit of a particle.
	/// @param[in] pid								The particle ID: @em 0 <= @formatParam{pid} < NumParticles()
	/// @return												@trueIfOtherwiseFalse{the particle was just born}
	//----------------------------------------------------------------------------------------
	Bool IsBorn(Int32 pid) { return TpCall(IsBorn)(pid); }

	//----------------------------------------------------------------------------------------
	/// Retrieves the is-die bit of a particle.
	/// @param[in] pid								The particle ID: @em 0 <= @formatParam{pid} < NumParticles()
	/// @return												@trueIfOtherwiseFalse{the particle just died}
	//----------------------------------------------------------------------------------------
	Bool IsDie(Int32 pid) { return TpCall(IsDie)(pid); }

	//----------------------------------------------------------------------------------------
	/// Retrieves the enters-group bit of a particle.
	/// @param[in] pid								The particle ID: @em 0 <= @formatParam{pid} < NumParticles()
	/// @return												@trueIfOtherwiseFalse{the particle just entered a group}
	//----------------------------------------------------------------------------------------
	Bool EntersGroup(Int32 pid) { return TpCall(EntersGroup)(pid); }

	//----------------------------------------------------------------------------------------
	/// Retrieves the group of a particle.
	/// @param[in] pid								The particle ID: @em 0 <= @formatParam{pid} < NumParticles()
	/// @return												The group that the particle currently is in. @theOwnsPointed{master system,TP_PGroup}
	//----------------------------------------------------------------------------------------
	TP_PGroup* Group(Int32 pid) { return TpCall(Group)(pid); }

	//----------------------------------------------------------------------------------------
	/// Retrieves the position of a particle.
	/// @param[in] pid								The particle ID: @em 0 <= @formatParam{pid} < NumParticles()
	/// @return												The particle position.
	//----------------------------------------------------------------------------------------
	Vector Position(Int32 pid) { return TpCall(Position)(pid); }

	//----------------------------------------------------------------------------------------
	/// Retrieves the velocity of a particle.
	/// @param[in] pid								The particle ID: @em 0 <= @formatParam{pid} < NumParticles()
	/// @return												The particle velocity.
	//----------------------------------------------------------------------------------------
	Vector Velocity(Int32 pid) { return TpCall(Velocity)(pid); }

	//----------------------------------------------------------------------------------------
	/// Retrieves the mass of a particle.
	/// @param[in] pid								The particle ID: @em 0 <= @formatParam{pid} < NumParticles()
	/// @return												The particle mass.
	//----------------------------------------------------------------------------------------
	Float Mass(Int32 pid) { return TpCall(Mass)(pid); }

	//----------------------------------------------------------------------------------------
	/// Retrieves the spin of a particle.
	/// @param[in] pid								The particle ID: @em 0 <= @formatParam{pid} < NumParticles()
	/// @return												The particle spin.
	//----------------------------------------------------------------------------------------
	TP_Spin Spin(Int32 pid) { return TpCall(Spin)(pid); }

	//----------------------------------------------------------------------------------------
	/// Retrieves the size of a particle.
	/// @param[in] pid								The particle ID: @em 0 <= @formatParam{pid} < NumParticles()
	/// @return												The particle size.
	//----------------------------------------------------------------------------------------
	Float Size(Int32 pid) { return TpCall(Size)(pid); }

	//----------------------------------------------------------------------------------------
	/// Retrieves the scale of a particle.
	/// @param[in] pid								The particle ID: @em 0 <= @formatParam{pid} < NumParticles()
	/// @return												The particle scale.
	//----------------------------------------------------------------------------------------
	Vector Scale(Int32 pid) { return TpCall(Scale)(pid); }

	//----------------------------------------------------------------------------------------
	/// Retrieves the age of a particle.
	/// @param[in] pid								The particle ID: @em 0 <= @formatParam{pid} < NumParticles()
	/// @return												The particle age.
	//----------------------------------------------------------------------------------------
	BaseTime Age(Int32 pid) { return TpCall(Age)(pid); }

	//----------------------------------------------------------------------------------------
	/// Retrieves the lifetime of a particle.
	/// @param[in] pid								The particle ID: @em 0 <= @formatParam{pid} < NumParticles()
	/// @return												The particle lifetime.
	//----------------------------------------------------------------------------------------
	BaseTime Life(Int32 pid) { return TpCall(Life)(pid); }

	//----------------------------------------------------------------------------------------
	/// Retrieves the alignment matrix of a particle.
	/// @param[in] pid								The particle ID: @em 0 <= @formatParam{pid} < NumParticles()
	/// @return												The particle alignment matrix.
	//----------------------------------------------------------------------------------------
	Matrix Alignment(Int32 pid) { return TpCall(Alignment)(pid); }

	//----------------------------------------------------------------------------------------
	/// Retrieves the random seed of a particle.
	/// @param[in] pid								The particle ID: @em 0 <= @formatParam{pid} < NumParticles()
	/// @return												The particle random seed.
	//----------------------------------------------------------------------------------------
	Int32 Randomseed(Int32 pid) { return TpCall(Randomseed)(pid); }

	//----------------------------------------------------------------------------------------
	/// Retrieves the shape of a particle.
	/// @param[in] pid								The particle ID: @em 0 <= @formatParam{pid} < NumParticles()
	/// @return												The particle shape. @theOwnsPointed{master system,TP_PShapePtr}
	//----------------------------------------------------------------------------------------
	TP_PShapePtr Shape(Int32 pid) { return TpCall(Shape)(pid); }

	//----------------------------------------------------------------------------------------
	/// Retrieves the transformation matrix of a particle.
	/// @param[in] pid								The particle ID: @em 0 <= @formatParam{pid} < NumParticles()
	/// @return												The particle transformation matrix.
	//----------------------------------------------------------------------------------------
	Matrix Transform(Int32 pid) { return TpCall(Transform)(pid); }

	//----------------------------------------------------------------------------------------
	/// Retrieves the flags of a particle.
	/// @note These returned flags are private. Use the functions like Alive() instead.
	/// @param[in] pid								The particle ID: @em 0 <= @formatParam{pid} < NumParticles()
	/// @return												The particle flags.
	//----------------------------------------------------------------------------------------
	UInt16 Flags(Int32 pid) { return TpCall(Flags)(pid); }

	//----------------------------------------------------------------------------------------
	/// Retrieves the delta time factor of a particle.
	/// @param[in] pid								The particle ID: @em 0 <= @formatParam{pid} < NumParticles()
	/// @return												The particle delta time factor.
	//----------------------------------------------------------------------------------------
	Float DTFactor(Int32 pid) { return TpCall(DTFactor)(pid); }

	/// @}

	/// @name Set Particle Information/Bits
	/// @{

	//----------------------------------------------------------------------------------------
	/// Sets the position for a particle.
	/// @param[in] pid								The particle ID: @em 0 <= @formatParam{pid} < NumParticles()
	/// @param[in] p									The new particle position.
	//----------------------------------------------------------------------------------------
	void SetPosition(Int32 pid, const Vector &p) { TpCall(SetPosition)(pid, p); }

	//----------------------------------------------------------------------------------------
	/// Sets the velocity for a particle.
	/// @param[in] pid								The particle ID: @em 0 <= @formatParam{pid} < NumParticles()
	/// @param[in] p									The new particle velocity.
	//----------------------------------------------------------------------------------------
	void SetVelocity(Int32 pid, const Vector &p) { TpCall(SetVelocity)(pid, p); }

	//----------------------------------------------------------------------------------------
	/// Sets the mass for a particle.
	/// @param[in] pid								The particle ID: @em 0 <= @formatParam{pid} < NumParticles()
	/// @param[in] mass								The new particle mass.
	//----------------------------------------------------------------------------------------
	void SetMass(Int32 pid, Float mass) { TpCall(SetMass)(pid, mass); }

	//----------------------------------------------------------------------------------------
	/// Sets the spin for a particle.
	/// @param[in] pid								The particle ID: @em 0 <= @formatParam{pid} < NumParticles()
	/// @param[in] spin								The new particle spin.
	//----------------------------------------------------------------------------------------
	void SetSpin(Int32 pid, const TP_Spin &spin) { TpCall(SetSpin)(pid, spin); }

	//----------------------------------------------------------------------------------------
	/// Sets the age for a particle.
	/// @param[in] pid								The particle ID: @em 0 <= @formatParam{pid} < NumParticles()
	/// @param[in] age								The new particle age.
	//----------------------------------------------------------------------------------------
	void SetAge(Int32 pid, const BaseTime &age) { TpCall(SetAge)(pid, age); }

	//----------------------------------------------------------------------------------------
	/// Sets the lifetime for a particle.
	/// @param[in] pid								The particle ID: @em 0 <= @formatParam{pid} < NumParticles()
	/// @param[in] life								The new particle lifetime.
	//----------------------------------------------------------------------------------------
	void SetLife(Int32 pid, const BaseTime &life) { TpCall(SetLife)(pid, life); }

	//----------------------------------------------------------------------------------------
	/// Inserts a particle into another group.
	/// @param[in] pid								The particle ID: @em 0 <= @formatParam{pid} < NumParticles()
	/// @param[in] group							The group to place the particle in. The pointed group must belong to this master system.
	//----------------------------------------------------------------------------------------
	void SetGroup(Int32 pid, TP_PGroup *group) { TpCall(SetGroup)(pid, group); }

	//----------------------------------------------------------------------------------------
	/// Sets the size for a particle.
	/// @param[in] pid								The particle ID: @em 0 <= @formatParam{pid} < NumParticles()
	/// @param[in] size								The new particle size.
	//----------------------------------------------------------------------------------------
	void SetSize(Int32 pid, Float size) { TpCall(SetSize)(pid, size); }

	//----------------------------------------------------------------------------------------
	/// Sets the scale for a particle.
	/// @param[in] pid								The particle ID: @em 0 <= @formatParam{pid} < NumParticles()
	/// @param[in] scale							The new particle scale.
	//----------------------------------------------------------------------------------------
	void SetScale(Int32 pid, const Vector &scale) { TpCall(SetScale)(pid, scale); }

	//----------------------------------------------------------------------------------------
	/// Sets the alignment matrix for a particle.
	/// @param[in] pid								The particle ID: @em 0 <= @formatParam{pid} < NumParticles()
	/// @param[in] align							The new particle alignment matrix.
	//----------------------------------------------------------------------------------------
	void SetAlignment(Int32 pid, const Matrix &align) { TpCall(SetAlignment)(pid, align); }

	//----------------------------------------------------------------------------------------
	/// Sets the random seed for a particle.
	/// @param[in] pid								The particle ID: @em 0 <= @formatParam{pid} < NumParticles()
	/// @param[in] seed								The new particle random seed.
	//----------------------------------------------------------------------------------------
	void SetRandomseed(Int32 pid, Int32 seed) { TpCall(SetRandomseed)(pid, seed); }

	//----------------------------------------------------------------------------------------
	/// Sets the shape for a particle.
	/// @param[in] pid								The particle ID: @em 0 <= @formatParam{pid} < NumParticles()
	/// @param[in] shape							The new particle shape.\n
	/// 															TP_PShapeI::owner_id should be set to GetOperatorID() for the node responsible for the shape handling.\n
	/// 															This node should be prepared to provide a TP_PShapeInterface via the @ref TP_MSG_GET_PSHAPEINTERFACE message.
	/// @param[in] deleteold					If @formatConstant{true} the old shape is deleted.
	//----------------------------------------------------------------------------------------
	void SetShape(Int32 pid, const TP_PShapePtr &shape, Bool deleteold = true) { TpCall(SetShape)(pid, shape, deleteold); }

	//----------------------------------------------------------------------------------------
	/// Sets the collision handling information for a particle.
	/// @param[in] pid								The particle ID: @em 0 <= @formatParam{pid} < NumParticles()
	/// @param[in] collision					The collision ID.\n
	/// 															This is the GetOperatorID() for the node responsible for the collision handling.\n
	/// 															This node should be prepared to provide a TP_CollisionInterface via the @ref TP_MSG_GET_COLLISIONINTERFACE message.
	//----------------------------------------------------------------------------------------
	void SetCollision(Int32 pid, TP_Collision collision){ TpCall(SetCollision)(pid, collision); }

	//----------------------------------------------------------------------------------------
	/// Sets the delta time factor for a particle.
	/// @param[in] pid								The particle ID: @em 0 <= @formatParam{pid} < NumParticles()
	/// @param[in] dt									The new particle delta time factor.
	//----------------------------------------------------------------------------------------
	void SetDTFactor(Int32 pid, Float dt) { TpCall(SetDTFactor)(pid, dt); }

	/// @}

	/// @name Particle Data Channels
	/// @{

	//----------------------------------------------------------------------------------------
	/// Adds a data channel.
	/// @param[in] type								The channel data type: @enumerateEnum{GvDataID}
	/// @param[in] str								The channel name.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool AddDataChannel(GvDataID type, const maxon::String& str) { return TpCall(AddDataChannel)(type, str); }

	//----------------------------------------------------------------------------------------
	/// Removes a data channel.
	/// @param[in] chan								The channel index: @em 0 <= @formatParam{chan} < NumDataChannels()
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool RemoveDataChannel(Int32 chan) { return TpCall(RemoveDataChannel)(chan); }

	//----------------------------------------------------------------------------------------
	/// Retrieves the data channel count.
	/// @return												The number of data channels.
	//----------------------------------------------------------------------------------------
	Int32 NumDataChannels(void) { return TpCall(NumDataChannels)(); }

	//----------------------------------------------------------------------------------------
	/// Retrieves the data type of a data channel.
	/// @param[in] chan								The channel index: @em 0 <= @formatParam{chan} < NumDataChannels()
	/// @return												The data type of channel @formatParam{chan}.
	//----------------------------------------------------------------------------------------
	GvDataID DataChannelType(Int32 chan) { return TpCall(DataChannelType)(chan); }

	//----------------------------------------------------------------------------------------
	/// Retrieves the name of a data channel.
	/// @param[in] chan								The channel index: @em 0 <= @formatParam{chan} < NumDataChannels()
	/// @return												The data channel name.
	//----------------------------------------------------------------------------------------
	String DataChannelName(Int32 chan) { return TpCall(DataChannelName)(chan); }

	//----------------------------------------------------------------------------------------
	/// Retrieves a unique ID for a data channel that is independent of its index.
	/// @param[in] chan								The channel index: @em 0 <= @formatParam{chan} < NumDataChannels()
	/// @return												A unique ID for channel @formatParam{chan}.
	//----------------------------------------------------------------------------------------
	Int32 DataChannelUniqueID(Int32 chan) { return TpCall(DataChannelUniqueID)(chan); }

	//----------------------------------------------------------------------------------------
	/// Retrieves the index of a data channel from its unique ID.
	/// @param[in] unique_id					The unique channel ID.
	/// @return												The data channel index.
	//----------------------------------------------------------------------------------------
	Int32 DataChannelID(Int32 unique_id) { return TpCall(DataChannelID)(unique_id); }

	//----------------------------------------------------------------------------------------
	/// Sets the data channel for a particle.
	/// @param[in] pid								The particle ID: @em 0 <= @formatParam{pid} < NumParticles()
	/// @param[in] chan								The channel index: @em 0 <= @formatParam{chan} < NumDataChannels()
	/// @param[in] data								The data to set. Points to GV data. The layout of the pointed data is determined by @formatParam{type}.
	/// @param[in] type								Determines the type of @formatParam{data}.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool SetData(Int32 pid, Int32 chan, void *data, GvValueID type) { return TpCall(SetData)(pid, chan, data, type); }

	//----------------------------------------------------------------------------------------
	/// Retrieves the data channel for a particle.
	/// @param[in] pid								The particle ID: @em 0 <= @formatParam{pid} < NumParticles()
	/// @param[in] chan								The channel index: @em 0 <= @formatParam{chan} < NumDataChannels()
	/// @param[out] data							Filled with the retrieved data. Points to GV data. The layout of the pointed data is determined by @formatParam{type}.
	/// @param[in] type								Determines the type of @formatParam{data}.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool GetData(Int32 pid, Int32 chan, void *data, GvValueID type) { return TpCall(GetData)(pid, chan, data, type); }

	//----------------------------------------------------------------------------------------
	/// Sets the data channel for a particle, getting the data from a GV port.
	/// @param[in] pid								The particle ID: @em 0 <= @formatParam{pid} < NumParticles()
	/// @param[in] chan								The channel index: @em 0 <= @formatParam{chan} < NumDataChannels()
	/// @param[in] p									The port with the data to set. @callerOwnsPointed{GvPort}
	/// @param[in] r									The run helper. @callerOwnsPointed{GvRun}
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool SetDataFromPort(Int32 pid, Int32 chan, GvPort *p, GvRun *r) { return TpCall(SetDataFromPort)(pid, chan, p, r); }

	//----------------------------------------------------------------------------------------
	/// Retrieves the data channel for a particle, storing the data in a GV port.
	/// @param[in] pid								The particle ID: @em 0 <= @formatParam{pid} < NumParticles()
	/// @param[in] chan								The channel index: @em 0 <= @formatParam{chan} < NumDataChannels()
	/// @param[out] p									The retrieved data is set in this port. @callerOwnsPointed{GvPort}
	/// @param[in] r									The run helper. @callerOwnsPointed{GvRun}
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool SetDataToPort(Int32 pid, Int32 chan, GvPort *p, GvRun *r) { return TpCall(SetDataToPort)(pid, chan, p, r); }

	//----------------------------------------------------------------------------------------
	/// Retrieves the channel information for a data channel.
	/// @warning The returned object needs to be free with @link DeleteObj@endlink(info) afterwards.
	/// @param[in] chan								The channel index: @em 0 <= @formatParam{chan} < NumDataChannels()
	/// @return												The channel information for chan. @callerOwnsPointed{@ref TP_DataChannelInfo}
	//----------------------------------------------------------------------------------------
	TP_DataChannelInfo* GetDataChannelInfo(Int32 chan) { return TpCall(GetDataChannelInfo)(chan); }

	//----------------------------------------------------------------------------------------
	/// Retrieves a data channel index from the information in @formatParam{info}.
	/// @param[in] info								The information to search for. @callerOwnsPointed{@ref TP_DataChannelInfo}
	/// @return												The retrieved channel index, or @ref NOTOK if no channel matched.
	//----------------------------------------------------------------------------------------
	Int32 GetDataChannelFromInfo(TP_DataChannelInfo *info) { return TpCall(GetDataChannelFromInfo)(info); }

	/// @}

	/// @name Callbacks
	/// @{

	//----------------------------------------------------------------------------------------
	/// Registers a free-particle callback.
	/// @param[in] cb									The callback to register.
	//----------------------------------------------------------------------------------------
	void Reg_FreeParticle_CB (TP_FreeParticle_CB *cb) { TpCall(Reg_FreeParticle_CB)(cb); }

	//----------------------------------------------------------------------------------------
	/// Unregisters a free-particle callback.
	/// @param[in] cb									The callback to unregister.
	//----------------------------------------------------------------------------------------
	void UReg_FreeParticle_CB(TP_FreeParticle_CB *cb) { TpCall(UReg_FreeParticle_CB)(cb); }

	//----------------------------------------------------------------------------------------
	/// Registers a delete-shape callback.
	/// @param[in] cb									The callback to register.
	//----------------------------------------------------------------------------------------
	void Reg_DeletePShape_CB(TP_FreePShape_CB *cb) { TpCall(Reg_FreePShape_CB)(cb); }

	//----------------------------------------------------------------------------------------
	/// Unregisters a delete-shape callback.
	/// @param[in] cb									The callback to unregister.
	//----------------------------------------------------------------------------------------
	void UReg_DeletePShape_CB(TP_FreePShape_CB *cb) { TpCall(UReg_FreePShape_CB)(cb); }

	/// @}

	/// @name Operator Link Table
	/// @{

	//----------------------------------------------------------------------------------------
	/// Retrieves an ID for @formatParam{op} that can later be used with GetOperator() to get @formatParam{op} back.
	/// @warning The ID is only valid during a limited time.
	/// @param[in] op									A node. @callerOwnsPointed{node}
	/// @return												An operator ID for @formatParam{op}.
	//----------------------------------------------------------------------------------------
	Int32 GetOperatorID(GvNode *op) { return TpCall(GetOperatorID)(op); }

	//----------------------------------------------------------------------------------------
	/// Retrieves the operator for an ID previously acquired with GetOperatorID().
	/// @param[in] id									The operator ID, as returned by GetOperatorID().
	/// @return												The retrieved operator, or @formatConstant{nullptr}. The GV world owns the pointed object.
	//----------------------------------------------------------------------------------------
	GvOperatorData* GetOperator(Int32 id) { return TpCall(GetOperator)(id); }

	/// @}

	/// @name Dirty
	/// @{

	//----------------------------------------------------------------------------------------
	/// A dirty counter for the master system. This can be used to see if anything has changed. Use SetDirty() to increment the counter.
	/// @return												The dirty counter, incremented when something changes in the system.
	//----------------------------------------------------------------------------------------
	UInt32 GetDirty(void) const { return TpCall(GetDirty)(); }

	//----------------------------------------------------------------------------------------
	/// Increments the dirty counter, i.e. tells anyone using GetDirty() that something has changed.
	/// @note This has to be used whenever an operator affects particle shapes, like the ObjectShape operator does.
	//----------------------------------------------------------------------------------------
	void SetDirty(void) { TpCall(SetDirty)(); }

	/// @}

	/// @name Collision
	/// @{

	//----------------------------------------------------------------------------------------
	/// Finds the node responsible for @formatParam{collision}, the one that called SetCollision(), and tells it to evaluate the passed collision parameters.
	/// @note Normally Thinking Particles evaluates this function automatically for registered collisions.
	/// @param[in] collision					The collision ID. This is GetOperatorID() for the node responsible for the collision.
	/// @param[in] pid								The particle ID: @em 0 <= @formatParam{pid} < NumParticles()
	/// @param[in] t									Time to evaluate the collision at. Collisions are detected between @formatParam{t} - @formatParam{dt} and @formatParam{t}.
	/// @param[in] pos								Assigned the new position of the object if there is a collision.
	/// @param[out] vel								Assigned the new velocity of the object if there is a collision.
	/// @param[out] spin							Assigned the new spin of the object if there is a collision.
	/// @param[in] dt									The time since the last evaluation, i.e. the time to look backwards for collisions.
	/// @param[in] ct									The collision time, if there was a collision. This is generally less than @formatParam{t}.
	/// @return												@trueIfOtherwiseFalse{there was a collision}
	//----------------------------------------------------------------------------------------
	Bool CheckCollision(TP_Collision collision, Int32 pid, Float t, Vector &pos, Vector &vel, TP_Spin &spin, Float dt, Float &ct){ return TpCall(CheckCollision)(collision, pid, t, pos, vel, spin, dt, ct); }

	/// @}

	/// @name Particle Shape
	/// @{

	//----------------------------------------------------------------------------------------
	/// Finds the node responsible for @formatParam{shape}, as specified by TP_PShapeI::owner_id, and tells it to return a clone of @formatParam{shape}.
	/// @note Normally Thinking Particles evaluates this function automatically for registered shapes.
	/// @warning The returned shape must be free with FreeShape() afterwards.
	/// @param[in] shape							The particle shape. @callerOwnsPointed{shape}
	/// @param[in] pid								The particle ID: @em 0 <= @formatParam{pid} < NumParticles()
	/// @param[in] flags							The flags: @enumerateEnum{COPYFLAGS}
	/// @param[in] trn								An alias translator for the operation. Can be @formatConstant{nullptr}. @callerOwnsPointed{AliasTrans}
	/// @return												The particle shape pointer structure of the cloned particle shape. @callerOwnsPointed{shape}
	//----------------------------------------------------------------------------------------
	TP_PShapePtr GetShapeClone(const TP_PShapePtr &shape , Int32 pid, COPYFLAGS flags, AliasTrans *trn) { return TpCall(GetShapeClone)(shape, pid, flags, trn); }

	//----------------------------------------------------------------------------------------
	/// Finds the node responsible for @formatParam{shape}, as specified by TP_PShapeI::owner_id, and tells it to return the shape associated with @formatParam{shape}. (Normally this is the same object.)
	/// @note Normally Thinking Particles evaluates this function automatically for registered shapes.
	/// @param[in] shape							The particle shape. @callerOwnsPointed{shape}
	/// @param[in] pid								The particle ID: @em 0 <= @formatParam{pid} < NumParticles()
	/// @param[in] owner_id						The owner ID.
	/// @return												The shape. @theOwnsPointed{shape handler,shape}
	//----------------------------------------------------------------------------------------
	TP_PShapePtr GetShape(const TP_PShapePtr &shape , Int32 pid, Int32 owner_id) { return TpCall(GetShape)(shape, pid, owner_id); }

	//----------------------------------------------------------------------------------------
	/// Finds the node responsible for @formatParam{shape}, as specified by TP_PShapeI::owner_id, and tells it to return a BaseObject shape for @formatParam{shape}.
	/// @note Normally Thinking Particles evaluates this function automatically for registered shapes.
	/// @param[in] shape							The particle shape. @callerOwnsPointed{shape}
	/// @param[in] pid								The particle ID: @em 0 <= @formatParam{pid} < NumParticles()
	/// @param[in] doc								The current document. @callerOwnsPointed{BaseDocument}
	/// @param[in] hh									A hierarchy helper for the operation. @callerOwnsPointed{HierarchyHelp}
	/// @return												The particle shape object. @theOwnsPointed{particle shape handler,object}
	//----------------------------------------------------------------------------------------
	BaseObject* GetShapeVirtualObjects(const TP_PShapePtr &shape , Int32 pid, BaseDocument *doc, HierarchyHelp *hh) { return TpCall(GetShapeVirtualObjects)(shape, pid, doc, hh); }

	//----------------------------------------------------------------------------------------
	/// Finds the node responsible for @formatParam{shape}, as specified by TP_PShapeI::owner_id, and tells it to return the scale of @formatParam{shape}.
	/// @note Normally Thinking Particles evaluates this function automatically for registered shapes.
	/// @param[in] shape							The particle shape. @callerOwnsPointed{shape}
	/// @param[in] pid								The particle ID: @em 0 <= @formatParam{pid} < NumParticles()
	/// @return												The shape scale.
	//----------------------------------------------------------------------------------------
	Float GetShapeScale(const TP_PShapePtr &shape , Int32 pid) { return TpCall(GetShapeScale)(shape, pid); }

	//----------------------------------------------------------------------------------------
	/// Finds the node responsible for @formatParam{shape}, as specified by TP_PShapeI::owner_id, and tells it to free @formatParam{shape}.
	/// @note Normally Thinking Particles evaluates this function automatically for registered shapes.
	/// @param[in] shape							The particle shape. @callerOwnsPointed{shape}
	/// @param[in] pid								The particle ID: @em 0 <= @formatParam{pid} < NumParticles()
	//----------------------------------------------------------------------------------------
	void FreeShape(TP_PShapePtr &shape, Int32 pid) { TpCall(FreeShape)(shape, pid); }

	/// @}

	/// @name Collider Cache
	/// @{

	//----------------------------------------------------------------------------------------
	/// Retrieves a collider cache for the shape associated with a particle.
	/// @param[in] pid								The particle ID: @em 0 <= @formatParam{pid} < NumParticles()
	/// @return												The collider cache, or @formatConstant{nullptr}. @theOwnsPointed{system,collider cache}
	//----------------------------------------------------------------------------------------
	GeColliderCache* ColliderCache(Int32 pid){ return TpCall(ColliderCache)(pid); }

	/// @}

	/// @name Color Property
	/// @{

	//----------------------------------------------------------------------------------------
	/// Retrieves the color for a particle.
	/// @since R16.038
	/// @param[in] pid								The particle ID: @em 0 <= @formatParam{pid} < NumParticles()
	/// @return												The particle color.
	//----------------------------------------------------------------------------------------
	Vector32 Color(Int32 pid){ return TpCall(Color)(pid); }

	//----------------------------------------------------------------------------------------
	/// Sets the color for a particle.
	/// @since R16.038
	/// @param[in] pid								The particle ID: @em 0 <= @formatParam{pid} < NumParticles()
	/// @param[in] color							The particle color.
	//----------------------------------------------------------------------------------------
	void SetColor(Int32 pid, const Vector32& color){ TpCall(SetColor)(pid, color); }

	/// @}
};


#define PartCall(fnc) (this->*TPOS->PART->fnc)

//----------------------------------------------------------------------------------------
/// Represents a particle in a TP_PGroup list.
//----------------------------------------------------------------------------------------
class TP_ParticleNode
{
public:
	//----------------------------------------------------------------------------------------
	/// Retrieves the particle ID.
	/// @return												The particle ID.
	//----------------------------------------------------------------------------------------
	Int32 GetParticleID(void){ return PartCall(GetParticleID)(); }

	//----------------------------------------------------------------------------------------
	/// Retrieves the next particle node in the list.
	/// @return												The next particle node in the list. @theOwnsPointed{list,TP_ParticleNode}
	//----------------------------------------------------------------------------------------
	TP_ParticleNode *GetNext(void){ return PartCall(GetNext)(); }

	//----------------------------------------------------------------------------------------
	/// Retrieves the previous particle node in the list.
	/// @return												The previous particle node in the list. @theOwnsPointed{list,TP_ParticleNode}
	//----------------------------------------------------------------------------------------
	TP_ParticleNode *GetPrev(void){ return PartCall(GetPrev)(); }
};


#define PGroupCall(fnc) (this->*TPOS->GROUP->fnc)

//----------------------------------------------------------------------------------------
/// Represents a particle group.
//----------------------------------------------------------------------------------------
class TP_PGroup : public BaseList2D
{
private:
	TP_PGroup();
	~TP_PGroup();
public:

	//----------------------------------------------------------------------------------------
	/// Calculates the level of the group. This is the number of parents that the group has.
	/// @return												The group level.
	//----------------------------------------------------------------------------------------
	Int32 GetLevel(void) { return PGroupCall(GetLevel)(); }

	//----------------------------------------------------------------------------------------
	/// Gets the first node in the particle list of the group.
	/// @return												The first node. @theOwnsPointed{list,TP_ParticleNode}
	//----------------------------------------------------------------------------------------
	TP_ParticleNode* GetFirstNode(void) { return PGroupCall(GetFirstNode)(); }

	//----------------------------------------------------------------------------------------
	/// Gets the last node in the particle list of the group.
	/// @return												The last node. @theOwnsPointed{list,TP_ParticleNode}
	//----------------------------------------------------------------------------------------
	TP_ParticleNode* GetLastNode(void) { return PGroupCall(GetLastNode)(); }

	//----------------------------------------------------------------------------------------
	/// Calculates the number of particles in the group.
	/// @return												The particle count.
	//----------------------------------------------------------------------------------------
	Int32 NumParticles(void) { return PGroupCall(NumParticles)(); }

	//----------------------------------------------------------------------------------------
	/// Checks if @formatParam{group} is a subgroup of the group.
	/// @param[in] group							A group. @callerOwnsPointed{TP_PGroup}
	/// @return												@trueIfOtherwiseFalse{group is a subgroup of the group}
	//----------------------------------------------------------------------------------------
	Bool IsSubGroup(TP_PGroup *group) { return PGroupCall(IsSubGroup)(group); }

	//----------------------------------------------------------------------------------------
	/// Gets the ID of the group. This is only based on the order in the group list, so it can change when the user reorders the groups.
	/// @return												The group ID.
	//----------------------------------------------------------------------------------------
	Int32 GetGroupID(void) { return PGroupCall(GetGroupID)(); }

	//----------------------------------------------------------------------------------------
	/// Gets the group title.
	/// @return												The group title.
	//----------------------------------------------------------------------------------------
	const String GetTitle(void) { return PGroupCall(GetTitle)(); }

	//----------------------------------------------------------------------------------------
	/// Sets the group title.
	/// @param[in] title							The new group title.
	//----------------------------------------------------------------------------------------
	void SetTitle(const maxon::String &title) { PGroupCall(SetTitle)(title); }

	//----------------------------------------------------------------------------------------
	/// Gets the group view type.
	/// @return												The view type. See @ref PGROUP_VIEWTYPE in description/tp_group.h.
	//----------------------------------------------------------------------------------------
	Int32 GetViewType(void) { return PGroupCall(GetViewType)(); }

	//----------------------------------------------------------------------------------------
	/// Sets the group view type.
	/// @param[in] type								The new view type. See @ref PGROUP_VIEWTYPE in description/tp_group.h.
	//----------------------------------------------------------------------------------------
	void SetViewType(Int32 type) { PGroupCall(SetViewType)(type); }

	//----------------------------------------------------------------------------------------
	/// Gets the show-objects flag of the group.
	/// @return												The show-objects flag.
	//----------------------------------------------------------------------------------------
	Bool GetShowObjects(void) { return PGroupCall(GetShowObjects)(); }

	//----------------------------------------------------------------------------------------
	/// Sets the show-objects flag of the group.
	/// @param[in] show								The new show-objects flag.
	//----------------------------------------------------------------------------------------
	void SetShowObjects(Bool show) { PGroupCall(SetShowObjects)(show); }

	//----------------------------------------------------------------------------------------
	/// Gets the color of the group.
	/// @return												The group color.
	//----------------------------------------------------------------------------------------
	Vector GetColor(void) { return PGroupCall(GetColor)(); }

	//----------------------------------------------------------------------------------------
	/// Sets the color of the group.
	/// @param[in] col								The new group color.
	//----------------------------------------------------------------------------------------
	void SetColor(Vector &col) { PGroupCall(SetColor)(col); }

	//----------------------------------------------------------------------------------------
	/// Opens the edit dialog for the group.
	/// @return												@trueIfOtherwiseFalse{the user clicked @em OK}
	//----------------------------------------------------------------------------------------
	Bool EditSettings(void) { return PGroupCall(EditSettings)(); }

	//----------------------------------------------------------------------------------------
	/// Checks if the group is selected in the group list.
	/// @return												@trueIfOtherwiseFalse{the group is selected}
	//----------------------------------------------------------------------------------------
	Bool IsSelected(void) { return PGroupCall(IsSelected)(); }

	//----------------------------------------------------------------------------------------
	/// Checks if the group is opened in the group list.
	/// @return												@trueIfOtherwiseFalse{the group is opened}
	//----------------------------------------------------------------------------------------
	Bool IsOpened(void) { return PGroupCall(IsOpened)(); }

	//----------------------------------------------------------------------------------------
	/// Sets the selection mode of the group in the group list.
	/// @param[in] mode								The selection mode: @enumerateEnum{SELECTION}
	//----------------------------------------------------------------------------------------
	void Select(Int32 mode) { PGroupCall(Select)(mode); }

	//----------------------------------------------------------------------------------------
	/// Opens or closes the group in the group list.
	/// @param[in] onoff							@trueIfOtherwiseFalse{the group should be opened}
	//----------------------------------------------------------------------------------------
	void Open(Bool onoff) { PGroupCall(Open)(onoff); }

	//----------------------------------------------------------------------------------------
	/// Sets the use color state of the group.
	/// @since R16.038
	/// @param[in] useCol							@trueIfOtherwiseFalse{use color should be enabled}
	//----------------------------------------------------------------------------------------
	void SetUseColor(Bool useCol) { PGroupCall(SetUseColor)(useCol); }

	//----------------------------------------------------------------------------------------
	/// Gets the use color state of the group.
	/// @since R16.038
	/// @return												@trueIfOtherwiseFalse{use color is enabled}
	//----------------------------------------------------------------------------------------
	Bool GetUseColor() { return PGroupCall(GetUseColor)(); }

	//----------------------------------------------------------------------------------------
	/// Sets the group to contain only cached data. This will prevent the particle system from doing simulation calculations for the group.
	/// @since R16.050
	/// @param[in] onoff							@trueIfOtherwiseFalse{cached data is used}
	//----------------------------------------------------------------------------------------
	void Cache(Bool onoff) { PGroupCall(Cache)(onoff); }

	//----------------------------------------------------------------------------------------
	/// Checks if the group is used to represent cached particle data only.
	/// @since R16.050
	/// @return												@trueIfOtherwiseFalse{the group represents cached data}
	//----------------------------------------------------------------------------------------
	Bool IsCache() { return PGroupCall(IsCache)(); }
};


//----------------------------------------------------------------------------------------
/// Must be called before Thinking Particles is used. The best way is to call it in PluginMessage():
/// @code
/// Bool PluginMessage(Int32 id, void *data)
/// {
/// 	switch (id)
/// 	{
/// 		case C4DPL_STARTACTIVITY:
/// 		{
/// 			InitThinkingParticles(void);
/// 		}
/// 		break;
///
/// 		// ...
/// 	}
/// 	return true;
/// }
/// @endcode
/// @return												@trueIfOtherwiseFalse{Thinking Particles initialization was successful}
//----------------------------------------------------------------------------------------
inline Bool InitThinkingParticles(void)
{
	return nullptr != CheckLib(ID_THINKINGPARTICLES, 0, (C4DLibrary**)&TPOS);
}

#ifdef MAXON_TARGET_MACOS
	_Pragma("clang diagnostic pop")
#endif

#endif // C4D_PARTICLES_H__

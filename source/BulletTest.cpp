#include "BulletTest.h"
#include <vector>
static maxon::ThreadRefTemplate<tool::BulletThread> g_bulletThread;

namespace tool
{
	Matrix4d InvZ(const Matrix4d& m)
	{
		const Matrix4d invZ = MatToGLMat(MatrixScale(Vector(1, 1, -1)));
		return(invZ * m * invZ);
	}
	struct MMDFilterCallback : public btOverlapFilterCallback
	{
		std::vector<btBroadphaseProxy*> nonFilterProxy;
		Bool needBroadphaseCollision(btBroadphaseProxy* proxy0, btBroadphaseProxy* proxy1) const override
		{
			auto findIt = std::find_if(
				nonFilterProxy.begin(),
				nonFilterProxy.end(),
				[proxy0, proxy1](const auto& x) { return(x == proxy0 || x == proxy1); }
			);
			if (findIt != nonFilterProxy.end())
			{
				return(true);
			}
			Bool collides = (proxy0->m_collisionFilterGroup & proxy1->m_collisionFilterMask) != 0;
			collides = collides && (proxy1->m_collisionFilterGroup & proxy0->m_collisionFilterMask);
			return(collides);
		}
	};
	Bool BulletThread::PhysicsCreate()
	{
		broadphase = std::make_unique<btDbvtBroadphase>();

		collisionConfig = std::make_unique<btDefaultCollisionConfiguration>();

		dispatcher = std::make_unique<btCollisionDispatcher>(collisionConfig.get());

		solver = std::make_unique<btSequentialImpulseConstraintSolver>();

		dynamicsWorld = std::make_unique<btDiscreteDynamicsWorld>(dispatcher.get(), broadphase.get(), solver.get(), collisionConfig.get());
		dynamicsWorld->setGravity(btVector3(0, -9.8f, 0));

		groundShape = std::make_unique<btStaticPlaneShape>(btVector3(0, 1, 0), 0.0f);

		btTransform groundTransform;
		groundTransform.setIdentity();

		groundMS = std::make_unique<btDefaultMotionState>(groundTransform);

		btRigidBody::btRigidBodyConstructionInfo groundInfo(0, groundMS.get(), groundShape.get(), btVector3(0, 0, 0));
		groundRB = std::make_unique<btRigidBody>(groundInfo);

		dynamicsWorld->addRigidBody(groundRB.get());

		auto filterCB = std::make_unique<MMDFilterCallback>();
		filterCB->nonFilterProxy.push_back(groundRB->getBroadphaseProxy());
		dynamicsWorld->getPairCache()->setOverlapFilterCallback(filterCB.get());
		filterCB = std::move(filterCB);
		return(true);
	}
	void BulletThread::PhysicsDestroy()
	{
		if (dynamicsWorld != nullptr && groundRB != nullptr)
		{
			dynamicsWorld->removeRigidBody(groundRB.get());
		}

		broadphase = nullptr;
		collisionConfig = nullptr;
		dispatcher = nullptr;
		solver = nullptr;
		dynamicsWorld = nullptr;
		groundShape = nullptr;
		groundMS = nullptr;
		groundRB = nullptr;
	}
	void BulletThread::SetFPS(Int32 fps)
	{
		fps = fps;
	}
	Int32 BulletThread::GetFPS() const
	{
		return(fps);
	}
	void BulletThread::SetMaxSubStepCount(Int32 numSteps)
	{
		maxSubStepCount = numSteps;
	}
	Int32 BulletThread::GetMaxSubStepCount() const
	{
		return(maxSubStepCount);
	}
	btDiscreteDynamicsWorld* BulletThread::GetDynamicsWorld() const
	{
		return(dynamicsWorld.get());
	}

	/*
	 * *******************
	 * MMDRigidBody
	 * *******************
	 */

	MMDRigidBody::MMDRigidBody()
		: m_rigidBodyType(TRACK_BONES)
		, m_group(0)
		, m_groupMask(0)
		, m_node(0)
		, m_offsetMat(Matrix4d())
	{
	}
	MMDRigidBody::~MMDRigidBody()
	{
	}
	Bool MMDRigidBody::Create(OMMDRigid* pmxRigidBody)
	{
		Destroy();
		BaseContainer* bc = static_cast<BaseList2D*>(pmxRigidBody->Get())->GetDataInstance();
		if (bc == nullptr)
		{
			return(false);
		}
		m_rigidBodyType = bc->GetInt32(RIGID_PHYSICS_MODE);

		switch (bc->GetInt32(RIGID_SHAPE_TYPE))
		{
		case SPHERICAL:
			m_shape = std::make_unique<btSphereShape>(bc->GetFloat(RIGID_SHAPE_SIZE_X));
			break;
		case BOX:
			m_shape = std::make_unique<btBoxShape>(btVector3(
				bc->GetFloat(RIGID_SHAPE_SIZE_X),
				bc->GetFloat(RIGID_SHAPE_SIZE_Y),
				bc->GetFloat(RIGID_SHAPE_SIZE_Z)
			));
			break;
		case CAPLETS:
			m_shape = std::make_unique<btCapsuleShape>(
				bc->GetFloat(RIGID_SHAPE_SIZE_X),
				bc->GetFloat(RIGID_SHAPE_SIZE_Y)
				);
			break;
		default:
			break;
		}
		if (m_shape == nullptr)
		{
			return(false);
		}

		btScalar	mass(0.0f);
		btVector3	localInteria(0, 0, 0);
		if (m_rigidBodyType != TRACK_BONES)
		{
			mass = bc->GetFloat(RIGID_MASS);
		}
		if (mass != 0)
		{
			m_shape->calculateLocalInertia(mass, localInteria);
		}
		Matrix m = HPBToMatrix(Vector(
			bc->GetInt32(RIGID_SHAPE_ROTATION_X),
			bc->GetInt32(RIGID_SHAPE_ROTATION_Y),
			bc->GetInt32(RIGID_SHAPE_ROTATION_Z)), ROTATIONORDER::HPB)
			* MatrixMove(Vector(
				bc->GetInt32(RIGID_SHAPE_POSITION_X),
				bc->GetInt32(RIGID_SHAPE_POSITION_Y),
				bc->GetInt32(RIGID_SHAPE_POSITION_Z)));
		Matrix4d rbMat = InvZ(MatToGLMat(m));

		BaseObject* kinematicObject = nullptr;
		bool		overrideNode = true;
		BaseObject* node = nullptr;
		if (node != nullptr)
		{
			m_offsetMat = ~MatToGLMat(node->GetMl()) * rbMat;
			kinematicObject = node;
		}
		else {
			kinematicObject = pmxRigidBody->GetRootObject();
			m_offsetMat = ~MatToGLMat(kinematicObject->GetMl()) * rbMat;
			overrideNode = false;
		}

		btMotionState* MMDMotionState = nullptr;
		if (m_rigidBodyType == TRACK_BONES)
		{
			m_kinematicMotionState = std::make_unique<KinematicMotionState>(kinematicObject, m_offsetMat);
			MMDMotionState = m_kinematicMotionState.get();
		}
		else {
			if (node != nullptr)
			{
				if (m_rigidBodyType == PHYSICAL_CALCULUS)
				{
					m_activeMotionState = std::make_unique<DynamicMotionState>(kinematicObject, m_offsetMat);
					m_kinematicMotionState = std::make_unique<KinematicMotionState>(kinematicObject, m_offsetMat);
					MMDMotionState = m_activeMotionState.get();
				}
				else if (m_rigidBodyType == PHYSICS_AND_BONES)
				{
					m_activeMotionState = std::make_unique<DynamicAndBoneMergeMotionState>(kinematicObject, m_offsetMat);
					m_kinematicMotionState = std::make_unique<KinematicMotionState>(kinematicObject, m_offsetMat);
					MMDMotionState = m_activeMotionState.get();
				}
			}
			else {
				m_activeMotionState = std::make_unique<DefaultMotionState>(m_offsetMat);
				m_kinematicMotionState = std::make_unique<KinematicMotionState>(kinematicObject, m_offsetMat);
				MMDMotionState = m_activeMotionState.get();
			}
		}

		btRigidBody::btRigidBodyConstructionInfo rbInfo(mass, MMDMotionState, m_shape.get(), localInteria);
		rbInfo.m_linearDamping = bc->GetFloat(RIGID_MOVE_ATTENUATION);
		rbInfo.m_angularDamping = bc->GetFloat(RIGID_ROTATION_DAMPING);
		rbInfo.m_restitution = bc->GetFloat(RIGID_REPULSION);
		rbInfo.m_friction = bc->GetFloat(RIGID_FRICTION_FORCE);
		rbInfo.m_additionalDamping = true;

		m_rigidBody = std::make_unique<btRigidBody>(rbInfo);
		m_rigidBody->setUserPointer(this);
		m_rigidBody->setSleepingThresholds(0.01f, maxon::DegToRad(0.1f));
		m_rigidBody->setActivationState(DISABLE_DEACTIVATION);
		if (m_rigidBodyType == TRACK_BONES)
		{
			m_rigidBody->setCollisionFlags(m_rigidBody->getCollisionFlags() | btCollisionObject::CF_KINEMATIC_OBJECT);
		}

		m_group = bc->GetInt32(RIGID_GROUP_ID);
		mmd::PMXRigidBodyNonCollisionGroup groupMask(
			bc->GetBool(RIGID_NON_COLLISION_GROUP_0),
			bc->GetBool(RIGID_NON_COLLISION_GROUP_1),
			bc->GetBool(RIGID_NON_COLLISION_GROUP_2),
			bc->GetBool(RIGID_NON_COLLISION_GROUP_3),
			bc->GetBool(RIGID_NON_COLLISION_GROUP_4),
			bc->GetBool(RIGID_NON_COLLISION_GROUP_5),
			bc->GetBool(RIGID_NON_COLLISION_GROUP_6),
			bc->GetBool(RIGID_NON_COLLISION_GROUP_7),
			bc->GetBool(RIGID_NON_COLLISION_GROUP_8),
			bc->GetBool(RIGID_NON_COLLISION_GROUP_9),
			bc->GetBool(RIGID_NON_COLLISION_GROUP_10),
			bc->GetBool(RIGID_NON_COLLISION_GROUP_11),
			bc->GetBool(RIGID_NON_COLLISION_GROUP_12),
			bc->GetBool(RIGID_NON_COLLISION_GROUP_13),
			bc->GetBool(RIGID_NON_COLLISION_GROUP_14),
			bc->GetBool(RIGID_NON_COLLISION_GROUP_15));
		m_groupMask = *reinterpret_cast<uint16_t*>(&groupMask);
		m_node = node;
		m_name = bc->GetString(RIGID_NAME_LOCAL);
		return(true);
	}
	void MMDRigidBody::Destroy()
	{
		m_shape = nullptr;
	}
	btRigidBody* MMDRigidBody::GetRigidBody() const
	{
		return(m_rigidBody.get());
	}
	uint16_t MMDRigidBody::GetGroup() const
	{
		return(m_group);
	}
	uint16_t MMDRigidBody::GetGroupMask() const
	{
		return(m_groupMask);
	}
	void MMDRigidBody::SetActivation(bool activation)
	{
		if (m_rigidBodyType != TRACK_BONES)
		{
			if (activation)
			{
				m_rigidBody->setCollisionFlags(m_rigidBody->getCollisionFlags() & ~btCollisionObject::CF_KINEMATIC_OBJECT);
				m_rigidBody->setMotionState(m_activeMotionState.get());
			}
			else {
				m_rigidBody->setCollisionFlags(m_rigidBody->getCollisionFlags() | btCollisionObject::CF_KINEMATIC_OBJECT);
				m_rigidBody->setMotionState(m_kinematicMotionState.get());
			}
		}
		else {
			m_rigidBody->setMotionState(m_kinematicMotionState.get());
		}
	}
	void MMDRigidBody::ResetTransform()
	{
		if (m_activeMotionState != nullptr)
		{
			m_activeMotionState->Reset();
		}
	}
	void MMDRigidBody::Reset(BulletThread* physics)
	{
		auto cache = physics->GetDynamicsWorld()->getPairCache();
		if (cache != nullptr)
		{
			auto dispatcher = physics->GetDynamicsWorld()->getDispatcher();
			cache->cleanProxyFromPairs(m_rigidBody->getBroadphaseHandle(), dispatcher);
		}
		m_rigidBody->setAngularVelocity(btVector3(0, 0, 0));
		m_rigidBody->setLinearVelocity(btVector3(0, 0, 0));
		m_rigidBody->clearForces();
	}
	void MMDRigidBody::ReflectGlobalTransform()
	{
		if (m_activeMotionState != nullptr)
		{
			m_activeMotionState->ReflectGlobalTransform();
		}
		if (m_kinematicMotionState != nullptr)
		{
			m_kinematicMotionState->ReflectGlobalTransform();
		}
	}
	void MMDRigidBody::CalcLocalTransform()
	{
		if (m_node != nullptr)
		{
			auto parent = m_node->GetPred();
			if (parent != nullptr)
			{
				auto local = ~MatToGLMat(parent->GetMl()) * MatToGLMat(m_node->GetMl());
				m_node->SetMl(GLMatToMat(local));
			}
			else {
				m_node->SetMl(m_node->GetMl());
			}
		}
	}
	Matrix4d MMDRigidBody::GetTransform()
	{
		btTransform transform = m_rigidBody->getCenterOfMassTransform();
		alignas(16) Matrix4d mat;
		transform.getOpenGLMatrix(&mat[0][0]);
		return(InvZ(mat));
	}


	/*
	 * *******************
	 * MMDJoint
	 * *******************
	 */
	MMDJoint::MMDJoint()
	{
	}


	MMDJoint::~MMDJoint()
	{
	}


	Bool MMDJoint::CreateJoint(OMMDJoint* pmxJoint, MMDRigidBody* rigidBodyA, MMDRigidBody* rigidBodyB)
	{
		Destroy();
		BaseContainer* bc = static_cast<BaseList2D*>(pmxJoint->Get())->GetDataInstance();
		btMatrix3x3	rotMat;
		rotMat.setEulerZYX(
			bc->GetFloat(JOINT_ATTITUDE_ROTATION_X),
			bc->GetFloat(JOINT_ATTITUDE_ROTATION_Y),
			bc->GetFloat(JOINT_ATTITUDE_ROTATION_Z));
		btTransform transform;
		transform.setIdentity();
		transform.setOrigin(btVector3(
			bc->GetFloat(JOINT_ATTITUDE_POSITION_X),
			bc->GetFloat(JOINT_ATTITUDE_POSITION_Y),
			bc->GetFloat(JOINT_ATTITUDE_POSITION_Z)
		));
		transform.setBasis(rotMat);

		btTransform	invA = rigidBodyA->GetRigidBody()->getWorldTransform().inverse();
		btTransform	invB = rigidBodyB->GetRigidBody()->getWorldTransform().inverse();
		invA = invA * transform;
		invB = invB * transform;
		switch (bc->GetInt32(JOINT_TYPE))
		{
		case DOF6:
		{
			auto constraint = std::make_unique<btGeneric6DofConstraint>(
				*rigidBodyA->GetRigidBody(),
				*rigidBodyB->GetRigidBody(),
				invA,
				invB,
				true);
			constraint->setLinearLowerLimit(btVector3(
				bc->GetFloat(JOINT_PARAMETER_POSITION_X_MIN),
				bc->GetFloat(JOINT_PARAMETER_POSITION_Y_MIN),
				bc->GetFloat(JOINT_PARAMETER_POSITION_Z_MIN)
			));
			constraint->setLinearUpperLimit(btVector3(
				bc->GetFloat(JOINT_PARAMETER_POSITION_X_MAX),
				bc->GetFloat(JOINT_PARAMETER_POSITION_Y_MAX),
				bc->GetFloat(JOINT_PARAMETER_POSITION_Z_MAX)
			));

			constraint->setAngularLowerLimit(btVector3(
				bc->GetFloat(JOINT_PARAMETER_ROTATION_X_MIN),
				bc->GetFloat(JOINT_PARAMETER_ROTATION_Y_MIN),
				bc->GetFloat(JOINT_PARAMETER_ROTATION_Z_MIN)
			));
			constraint->setAngularUpperLimit(btVector3(
				bc->GetFloat(JOINT_PARAMETER_ROTATION_X_MAX),
				bc->GetFloat(JOINT_PARAMETER_ROTATION_Y_MAX),
				bc->GetFloat(JOINT_PARAMETER_ROTATION_Z_MAX)
			));
			m_constraint = std::move(constraint);
			break;
		}
		case P2P:
		{
			Matrix4d transformA= rigidBodyA->GetTransform();
			Matrix4d transformB = rigidBodyB->GetTransform();
			auto constraint = std::make_unique<btPoint2PointConstraint>(
				*rigidBodyA->GetRigidBody(),
				*rigidBodyB->GetRigidBody(),
				btVector3(
					transformA.v4.x,
					transformA.v4.y,
					transformA.v4.z),
				btVector3(
					transformB.v4.x,
					transformB.v4.y,
					transformB.v4.z));
			m_constraint = std::move(constraint);
			break;
		}
		case ConeTwist:
		{
			auto constraint = std::make_unique<btConeTwistConstraint>(
				*rigidBodyA->GetRigidBody(),
				*rigidBodyB->GetRigidBody(),
				invA,
				invB);
			constraint->setDamping(bc->GetFloat(JOINT_PARAMETER_POSITION_X_MIN));
			constraint->setFixThresh(bc->GetFloat(JOINT_PARAMETER_POSITION_X_MAX));
			constraint->enableMotor(bc->GetFloat(JOINT_PARAMETER_POSITION_Z_MIN));
			constraint->setMaxMotorImpulse(bc->GetFloat(JOINT_PARAMETER_POSITION_Z_MAX));
			constraint->setLimit(
				bc->GetFloat(JOINT_PARAMETER_ROTATION_Y_MIN),
				bc->GetFloat(JOINT_PARAMETER_ROTATION_Z_MIN),
				bc->GetFloat(JOINT_PARAMETER_ROTATION_X_MIN),
				bc->GetFloat(JOINT_SPRING_POSITION_X),
				bc->GetFloat(JOINT_SPRING_POSITION_Y),
				bc->GetFloat(JOINT_SPRING_POSITION_Z)
			);
			constraint->setMotorTarget(btQuaternion(
				bc->GetFloat(JOINT_SPRING_ROTATION_X),
				bc->GetFloat(JOINT_SPRING_ROTATION_Y),
				bc->GetFloat(JOINT_SPRING_ROTATION_Z)));
			m_constraint = std::move(constraint);
			break;
		}
		case Slider:
		{
			auto constraint = std::make_unique<btSliderConstraint>(
				*rigidBodyA->GetRigidBody(),
				*rigidBodyB->GetRigidBody(),
				invA,
				invB,
				true);
			constraint->setLowerLinLimit(bc->GetFloat(JOINT_PARAMETER_POSITION_X_MIN));
			constraint->setUpperLinLimit(bc->GetFloat(JOINT_PARAMETER_POSITION_X_MAX));
			constraint->setLowerAngLimit(bc->GetFloat(JOINT_PARAMETER_ROTATION_X_MIN));
			constraint->setUpperAngLimit(bc->GetFloat(JOINT_PARAMETER_ROTATION_X_MAX));
			constraint->setPoweredLinMotor(bc->GetFloat(JOINT_SPRING_POSITION_X));
			constraint->setTargetLinMotorVelocity(bc->GetFloat(JOINT_SPRING_POSITION_Y));
			constraint->setMaxLinMotorForce(bc->GetFloat(JOINT_SPRING_POSITION_Z));
			constraint->setPoweredAngMotor(bc->GetFloat(JOINT_SPRING_ROTATION_X));
			constraint->setTargetAngMotorVelocity(bc->GetFloat(JOINT_SPRING_ROTATION_Y));
			constraint->setMaxAngMotorForce(bc->GetFloat(JOINT_SPRING_ROTATION_Z));
			m_constraint = std::move(constraint);
			break;
		}
		case Hinge:
		{
			auto constraint = std::make_unique<btHingeConstraint>(
				*rigidBodyA->GetRigidBody(),
				*rigidBodyB->GetRigidBody(),
				invA,
				invB,
				true);
			constraint->setLimit(
				bc->GetFloat(JOINT_PARAMETER_ROTATION_X_MIN),
				bc->GetFloat(JOINT_PARAMETER_ROTATION_X_MAX),
				bc->GetFloat(JOINT_SPRING_POSITION_X),
				bc->GetFloat(JOINT_SPRING_POSITION_Y),
				bc->GetFloat(JOINT_SPRING_POSITION_Z));
			constraint->enableAngularMotor(bc->GetFloat(JOINT_SPRING_ROTATION_X), bc->GetFloat(JOINT_SPRING_ROTATION_Y), bc->GetFloat(JOINT_SPRING_ROTATION_Z));
			m_constraint = std::move(constraint);
			break;
		}
		default: /* SpringDOF6 */
		{
			auto constraint = std::make_unique<btGeneric6DofSpringConstraint>(
				*rigidBodyA->GetRigidBody(),
				*rigidBodyB->GetRigidBody(),
				invA,
				invB,
				true);
			constraint->setLinearLowerLimit(btVector3(
				bc->GetFloat(JOINT_PARAMETER_POSITION_X_MIN),
				bc->GetFloat(JOINT_PARAMETER_POSITION_Y_MIN),
				bc->GetFloat(JOINT_PARAMETER_POSITION_Z_MIN)
			));
			constraint->setLinearUpperLimit(btVector3(
				bc->GetFloat(JOINT_PARAMETER_POSITION_X_MAX),
				bc->GetFloat(JOINT_PARAMETER_POSITION_Y_MAX),
				bc->GetFloat(JOINT_PARAMETER_POSITION_Z_MAX)
			));

			constraint->setAngularLowerLimit(btVector3(
				bc->GetFloat(JOINT_PARAMETER_ROTATION_X_MIN),
				bc->GetFloat(JOINT_PARAMETER_ROTATION_Y_MIN),
				bc->GetFloat(JOINT_PARAMETER_ROTATION_Z_MIN)
			));
			constraint->setAngularUpperLimit(btVector3(
				bc->GetFloat(JOINT_PARAMETER_ROTATION_X_MAX),
				bc->GetFloat(JOINT_PARAMETER_ROTATION_Y_MAX),
				bc->GetFloat(JOINT_PARAMETER_ROTATION_Z_MAX)
			));

			if (bc->GetFloat(JOINT_SPRING_POSITION_X) != 0)
			{
				constraint->enableSpring(0, true);
				constraint->setStiffness(0, bc->GetFloat(JOINT_SPRING_POSITION_X));
			}
			if (bc->GetFloat(JOINT_SPRING_POSITION_Y) != 0)
			{
				constraint->enableSpring(1, true);
				constraint->setStiffness(1, bc->GetFloat(JOINT_SPRING_POSITION_Y));
			}
			if (bc->GetFloat(JOINT_SPRING_POSITION_Z) != 0)
			{
				constraint->enableSpring(2, true);
				constraint->setStiffness(2, bc->GetFloat(JOINT_SPRING_POSITION_Z));
			}
			if (bc->GetFloat(JOINT_SPRING_ROTATION_X) != 0)
			{
				constraint->enableSpring(3, true);
				constraint->setStiffness(3, bc->GetFloat(JOINT_SPRING_ROTATION_X));
			}
			if (bc->GetFloat(JOINT_SPRING_ROTATION_Y) != 0)
			{
				constraint->enableSpring(4, true);
				constraint->setStiffness(4, bc->GetFloat(JOINT_SPRING_ROTATION_Y));
			}
			if (bc->GetFloat(JOINT_SPRING_ROTATION_Z) != 0)
			{
				constraint->enableSpring(5, true);
				constraint->setStiffness(5, bc->GetFloat(JOINT_SPRING_ROTATION_Z));
			}

			m_constraint = std::move(constraint);
			break;
		}
		}
		return(true);
	}


	void MMDJoint::Destroy()
	{
		m_constraint = nullptr;
	}


	btTypedConstraint* MMDJoint::GetConstraint() const
	{
		return(m_constraint.get());
	}
}

#if API_VERSION >= 21000
Bool C4DBulletTest::Execute(BaseDocument* doc, GeDialog* parentManager)
{
	if (op)
	{
		if (!g_bulletThread)
		{
			/* create and start thread */
			g_bulletThread = tool::BulletThread::Create().GetValue();
			iferr(g_bulletThread.Start())
				return(false);
		}

		op = false;
	}
	else {
		g_bulletThread->CancelAndWait();
		g_bulletThread = nullptr;
		op = true;
	}
	return(true);
}
#else
Bool C4DBulletTest::Execute(BaseDocument* doc)
{
	if (op)
	{
		if (!g_bulletThread)
		{
			/* create and start thread */
			g_bulletThread = tool::BulletThread::Create().GetValue();
			iferr(g_bulletThread.Start())
				return(false);
		}

		op = false;
	}
	else {
		g_bulletThread->CancelAndWait();
		g_bulletThread = nullptr;
		op = true;
	}
	return(true);
}
#endif


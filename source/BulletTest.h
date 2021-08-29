#ifndef __C4DBULLETTEST__H__
#include "main.h"
#include "MMD_PMX_Control.h"
#include "btBulletDynamicsCommon.h"

#define MatToGLMat( m ) Matrix4d( Vector4d( m.sqmat.v1 ), Vector4d( m.sqmat.v2 ), Vector4d( m.sqmat.v3 ), Vector4d( m.off ) )
#define GLMatToMat( m ) Matrix( Vector( m.v4 ), Vector( m.v1 ), Vector( m.v2 ), Vector( m.v3 ) )

namespace mmd
{

	Matrix4d InvZ(const Matrix4d& m);

	class BulletThread : public maxon::ThreadInterfaceTemplate<BulletThread>
	{
	private:
		std::unique_ptr<btDefaultCollisionConfiguration>	collisionConfig;        /* 碰撞配置 */
		std::unique_ptr<btCollisionDispatcher>			dispatcher;             /* 碰撞调度器 */
		std::unique_ptr<btBroadphaseInterface>			broadphase;             /* Broadphase */
		std::unique_ptr<btSequentialImpulseConstraintSolver>	solver;                 /* 约束求解器 */
		std::unique_ptr<btDiscreteDynamicsWorld>		dynamicsWorld;
		std::unique_ptr<btOverlapFilterCallback>		filterCB;
		std::unique_ptr<btCollisionShape>			groundShape;
		std::unique_ptr<btMotionState>				groundMS;
		std::unique_ptr<btRigidBody>				groundRB;
		Int32							fps = 60;
		Int32							maxSubStepCount = 10;
		BaseTime						nextUpdataTime = BaseTime();
	public:

		BulletThread()
		{
		}


		~BulletThread()
		{
			PhysicsDestroy();
		}


		Bool PhysicsCreate();


		void PhysicsDestroy();


		void SetFPS(Int32 fps);


		Int32 GetFPS() const;


		void SetMaxSubStepCount(int numSteps);


		int GetMaxSubStepCount() const;


		btDiscreteDynamicsWorld* GetDynamicsWorld() const;


		maxon::Result<void> operator ()()
		{
			while (!IsCancelled())
			{
				BaseDocument* doc = GetActiveDocument();
				if (doc == nullptr)
				{
					return(maxon::OK);
				}
				BaseTime time = doc->GetTime();
				if (nextUpdataTime < time)
				{
					dynamicsWorld->stepSimulation(1.f / (float)doc->GetFps());

					/* 打印所有对象的位置 */
					for (int j = dynamicsWorld->getNumCollisionObjects() - 1; j >= 0; j--)
					{
						btCollisionObject* obj = dynamicsWorld->getCollisionObjectArray()[j];
						btRigidBody* body = btRigidBody::upcast(obj);
						btTransform		trans;

						if (body && body->getMotionState())
						{
							body->getMotionState()->getWorldTransform(trans);
						}
						else {
							trans = obj->getWorldTransform();
						}
						GePrint("world pos object " + String::IntToString(j) + " = " + String::FloatToString(float(trans.getOrigin().getX())) + " ," + String::FloatToString(float(trans.getOrigin().getY())) + " ," + String::FloatToString(float(trans.getOrigin().getZ())) + "\n");
					}
					GePrint(" "_s);

					nextUpdataTime = time;
				}
			}
			return(maxon::OK);
		}


		const maxon::Char* GetName() const
		{
			return("BulletThread");
		}
	};

	class MMDMotionState : public btMotionState
	{
	public:
		virtual void Reset() = 0;


		virtual void ReflectGlobalTransform() = 0;
	};

	class DefaultMotionState : public MMDMotionState
	{
	public:
		DefaultMotionState(const Matrix4d& transform)
		{
			Matrix4d trans = ~transform;
			m_transform.setFromOpenGLMatrix(&trans[0][0]);
			m_initialTransform = m_transform;
		}


		void getWorldTransform(btTransform& worldTransform) const override
		{
			worldTransform = m_transform;
		}


		void setWorldTransform(const btTransform& worldTransform) override
		{
			m_transform = worldTransform;
		}


		virtual void Reset() override
		{
			m_transform = m_initialTransform;
		}


		virtual void ReflectGlobalTransform() override
		{
		}


	private:
		btTransform	m_initialTransform;
		btTransform	m_transform;
	};

	class DynamicMotionState : public MMDMotionState
	{
	public:
		DynamicMotionState(BaseObject* object, const Matrix4d& offset, bool override = true)
			: m_object(object)
			, m_offset(offset)
			, m_override(override)
		{
			m_invOffset = ~offset;
			Reset();
		}


		void getWorldTransform(btTransform& worldTransform) const override
		{
			worldTransform = m_transform;
		}


		void setWorldTransform(const btTransform& worldTransform) override
		{
			m_transform = worldTransform;
		}


		void Reset() override
		{
			Matrix4d global = InvZ(MatToGLMat(m_object->GetMl()) * m_offset);
			m_transform.setFromOpenGLMatrix(&global[0][0]);
		}


		void ReflectGlobalTransform() override
		{
			alignas(16) Matrix4d world;
			m_transform.getOpenGLMatrix(&world[0][0]);
			Matrix4d btGlobal = InvZ(world) * m_invOffset;

			if (m_override)
			{
				m_object->SetMl(GLMatToMat(btGlobal));
			}
		}


	private:
		BaseObject* m_object;
		Matrix4d	m_offset;
		Matrix4d	m_invOffset;
		btTransform	m_transform;
		bool		m_override;
	};

	class DynamicAndBoneMergeMotionState : public MMDMotionState
	{
	public:
		DynamicAndBoneMergeMotionState(BaseObject* object, const Matrix4d& offset, bool override = true)
			: m_object(object)
			, m_offset(offset)
			, m_override(override)
		{
			m_invOffset = ~offset;
			Reset();
		}


		void getWorldTransform(btTransform& worldTransform) const override
		{
			worldTransform = m_transform;
		}


		void setWorldTransform(const btTransform& worldTransform) override
		{
			m_transform = worldTransform;
		}


		void Reset() override
		{
			Matrix4d global = InvZ(MatToGLMat(m_object->GetMl()) * m_offset);
			m_transform.setFromOpenGLMatrix(&global[0][0]);
		}


		void ReflectGlobalTransform() override
		{
			alignas(16) Matrix4d world;
			m_transform.getOpenGLMatrix(&world[0][0]);
			Matrix4d	btGlobal = InvZ(world) * m_invOffset;
			Matrix4d	global = MatToGLMat(m_object->GetMl());
			btGlobal[3] = global[3];

			if (m_override)
			{
				m_object->SetMl(GLMatToMat(btGlobal));
			}
		}


	private:
		BaseObject* m_object;
		Matrix4d	m_offset;
		Matrix4d	m_invOffset;
		btTransform	m_transform;
		bool		m_override;
	};

	class KinematicMotionState : public MMDMotionState
	{
	public:
		KinematicMotionState(BaseObject* object, const Matrix4d& offset)
			: m_object(object)
			, m_offset(offset)
		{
		}


		void getWorldTransform(btTransform& worldTransform) const override
		{
			Matrix4d m;
			if (m_object != nullptr)
			{
				m = MatToGLMat(m_object->GetMl()) * m_offset;
			}
			else {
				m = m_offset;
			}
			m = InvZ(m);
			worldTransform.setFromOpenGLMatrix(&m[0][0]);
		}


		void setWorldTransform(const btTransform& worldTransform) override
		{
		}


		void Reset() override
		{
		}


		void ReflectGlobalTransform() override
		{
		}


	private:
		BaseObject* m_object;
		Matrix4d	m_offset;
	};

	class MMDRigidBody
	{
	public:
		MMDRigidBody();
		~MMDRigidBody();
		MMDRigidBody(const MMDRigidBody& rhs) = delete;
		MMDRigidBody& operator =(const MMDRigidBody& rhs) = delete;


		Bool Create(OMMDRigid* pmxRigidBody);


		void Destroy();


		btRigidBody* GetRigidBody() const;


		uint16_t GetGroup() const;


		uint16_t GetGroupMask() const;


		void SetActivation(bool activation);


		void ResetTransform();


		void Reset(BulletThread* physics);


		void ReflectGlobalTransform();


		void CalcLocalTransform();


		Matrix4d GetTransform();


	private:
		std::unique_ptr<btCollisionShape>	m_shape;
		std::unique_ptr<MMDMotionState>		m_activeMotionState;
		std::unique_ptr<MMDMotionState>		m_kinematicMotionState;
		std::unique_ptr<btRigidBody>		m_rigidBody;

		Int32		m_rigidBodyType;
		uint16_t	m_group;
		uint16_t	m_groupMask;

		BaseObject* m_node;
		Matrix4d	m_offsetMat;
		String		m_name;
	};

	class MMDJoint
	{
	public:
		MMDJoint();
		~MMDJoint();
		MMDJoint(const MMDJoint& rhs) = delete;
		MMDJoint& operator =(const MMDJoint& rhs) = delete;


		Bool CreateJoint(OMMDJoint* pmxJoint, MMDRigidBody* rigidBodyA, MMDRigidBody* rigidBodyB);


		void Destroy();


		btTypedConstraint* GetConstraint() const;


	private:
		std::unique_ptr<btTypedConstraint> m_constraint;
	};
}

class C4DBulletTest : public CommandData
{
	Bool op = true;
public:
#if API_VERSION >= 21000
	virtual Bool Execute(BaseDocument* doc, GeDialog* parentManager);
#else
	virtual Bool Execute(BaseDocument* doc);
#endif
};

Bool RegisterC4DBulletTest()
{
	return(RegisterCommandPlugin(999999, "BulletTest"_s, 0, AutoBitmap("MMDIcon.png"_s), "BulletTest"_s, NewObjClear(C4DBulletTest)));
}


#endif /* !__C4DBULLETTEST__H__ */

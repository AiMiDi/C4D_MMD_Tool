#include "BulletTest.h"

static  maxon::ThreadRefTemplate<BulletThread> g_bulletThread;

void BulletThread::Init_Bullet() {
	if (collisionConfiguration != nullptr) {
		delete collisionConfiguration;
	}
	collisionConfiguration = new btDefaultCollisionConfiguration();//碰撞配置包含内存的默认设置，碰撞设置。 高级用户可以创建自己的配置。		
	if (dispatcher != nullptr) {
		delete dispatcher;
	}
	dispatcher = new btCollisionDispatcher(collisionConfiguration);//使用默认的碰撞调度器。 对于并行处理，您可以使用不同的调度程序（请参阅 Extras/BulletMultiThreaded）	
	if (overlappingPairCache != nullptr) {
		delete overlappingPairCache;
	}
	overlappingPairCache = new btDbvtBroadphase();//btDbvtBroadphase 是一个很好的通用 Broadphase。 您也可以尝试 btAxis3Sweep。	
	if (solver != nullptr) {
		delete solver;
	}
	solver = new btSequentialImpulseConstraintSolver;//默认约束求解器。 对于并行处理，您可以使用不同的求解器（参见 Extras/BulletMultiThreaded）
	if (dynamicsWorld != nullptr) {
		delete dynamicsWorld;
	}
	dynamicsWorld = new btDiscreteDynamicsWorld(dispatcher, overlappingPairCache, solver, collisionConfiguration);
	dynamicsWorld->setGravity(btVector3(0, -9.8, 0));
}

Bool C4DBulletTest::Execute(BaseDocument* doc) {
	
	if (op) {
		if (!g_bulletThread)
		{
			// create and start thread
			g_bulletThread = BulletThread::Create().GetValue();
			iferr(g_bulletThread.Start())return false;
		}
		///创建一些基本的刚体

		//地面是位置 y = -56 处 100 边的立方体。
		//球体将在 y = -6 处撞击它，中心在 -5
		{
			btCollisionShape* groundShape = new btBoxShape(btVector3(btScalar(50.), btScalar(50.), btScalar(50.)));

			g_bulletThread->collisionShapes.push_back(groundShape);

			btTransform groundTransform;
			groundTransform.setIdentity();
			groundTransform.setOrigin(btVector3(0, -56, 0));

			btScalar mass(0.);

			//当且仅当质量不为零时刚体是动态的，否则是静态的
			bool isDynamic = (mass != 0.f);

			btVector3 localInertia(0, 0, 0);
			if (isDynamic)
				groundShape->calculateLocalInertia(mass, localInertia);

			//使用 motionstate 是可选的，它提供插值功能，并且只同步“活动”对象
			btDefaultMotionState* myMotionState = new btDefaultMotionState(groundTransform);
			btRigidBody::btRigidBodyConstructionInfo rbInfo(mass, myMotionState, groundShape, localInertia);
			btRigidBody* body = new btRigidBody(rbInfo);
			//将刚体添加到动力学世界
			g_bulletThread->dynamicsWorld->addRigidBody(body);
		}

		{
			//创建动态刚体

			//btCollisionShape* colShape = new btBoxShape(btVector3(1,1,1));
			btCollisionShape* colShape = new btSphereShape(btScalar(1.));
			g_bulletThread->collisionShapes.push_back(colShape);

			/// 创建动力学对象
			btTransform startTransform;
			startTransform.setIdentity();

			btScalar mass(1.f);

			//当且仅当质量不为零时刚体是动态的，否则是静态的
			bool isDynamic = (mass != 0.f);

			btVector3 localInertia(0, 0, 0);
			if (isDynamic)
				colShape->calculateLocalInertia(mass, localInertia);

			startTransform.setOrigin(btVector3(2, 10, 0));

			//推荐使用motionstate，它提供插值功能，并且只同步“活动”对象
			btDefaultMotionState* myMotionState = new btDefaultMotionState(startTransform);
			btRigidBody::btRigidBodyConstructionInfo rbInfo(mass, myMotionState, colShape, localInertia);
			btRigidBody* body = new btRigidBody(rbInfo);

			g_bulletThread->dynamicsWorld->addRigidBody(body);
		}
		op = false;
	}
	else {
		g_bulletThread->CancelAndWait();
		g_bulletThread = nullptr;
		op = true;
	}

	return true;
}


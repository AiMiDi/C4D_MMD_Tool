#ifndef __C4DBULLETTEST__H__
#include "main.h"
#include "btBulletDynamicsCommon.h"

class C4DBulletTest : public CommandData
{
	Bool op = true;
public:
	virtual Bool Execute(BaseDocument* doc, GeDialog* parentManager);
};


class BulletThread : public maxon::ThreadInterfaceTemplate<BulletThread>
{
private:
	btDefaultCollisionConfiguration* collisionConfiguration = new btDefaultCollisionConfiguration();//碰撞配置
	btCollisionDispatcher* dispatcher = new btCollisionDispatcher(collisionConfiguration);//碰撞调度器
	btBroadphaseInterface* overlappingPairCache = new btDbvtBroadphase();//Broadphase
	btSequentialImpulseConstraintSolver* solver = new btSequentialImpulseConstraintSolver;//约束求解器
	BaseTime nextUpdataTime = BaseTime();
public:	
	btAlignedObjectArray<btCollisionShape*> collisionShapes;
	btDiscreteDynamicsWorld* dynamicsWorld = new btDiscreteDynamicsWorld(dispatcher, overlappingPairCache, solver, collisionConfiguration);
	BulletThread() {
		dynamicsWorld->setGravity(btVector3(0, -9.8, 0));
	}
	~BulletThread() {
		for (Int32 i = dynamicsWorld->getNumCollisionObjects() - 1; i >= 0; i--)
		{
			btCollisionObject* obj = dynamicsWorld->getCollisionObjectArray()[i];
			btRigidBody* body = btRigidBody::upcast(obj);
			if (body && body->getMotionState())
			{
				delete body->getMotionState();
			}
			dynamicsWorld->removeCollisionObject(obj);
			delete obj;
		}
		//删除碰撞形状
		for (Int32 j = 0; j < collisionShapes.size(); j++)
		{
			btCollisionShape* shape = collisionShapes[j];
			collisionShapes[j] = 0;
			delete shape;
		}
		collisionShapes.clear();
		delete dynamicsWorld;
		delete solver;
		delete overlappingPairCache;
		delete dispatcher;
		delete collisionConfiguration;
	}	
	void Init_Bullet();
	maxon::Result<void> operator ()()
	{
		while (!IsCancelled())
		{
			BaseDocument* doc = GetActiveDocument();
			if (doc == nullptr) {
				return maxon::OK;
			}
			BaseTime& time = doc->GetTime();
			if (nextUpdataTime < time) {
				dynamicsWorld->stepSimulation(1.f / (float)doc->GetFps());

				//打印所有对象的位置
				for (int j = dynamicsWorld->getNumCollisionObjects() - 1; j >= 0; j--)
				{
					btCollisionObject* obj = dynamicsWorld->getCollisionObjectArray()[j];
					btRigidBody* body = btRigidBody::upcast(obj);
					btTransform trans;

					if (body && body->getMotionState())
					{
						body->getMotionState()->getWorldTransform(trans);
					}
					else
					{
						trans = obj->getWorldTransform();
					}
					GePrint("world pos object " + String::IntToString(j) + " = " + String::FloatToString(float(trans.getOrigin().getX())) + " ," + String::FloatToString(float(trans.getOrigin().getY())) + " ," + String::FloatToString(float(trans.getOrigin().getZ())) + "\n");
				}
				GePrint(" "_s);

				nextUpdataTime = time;
			}
		}
		return maxon::OK;
	}
	const maxon::Char* GetName() const { return "BulletThread"; }
};

Bool RegisterC4DBulletTest() {
	return RegisterCommandPlugin(999999, "BulletTest"_s, 0, AutoBitmap("MMDIcon.png"_s), "BulletTest"_s, NewObjClear(C4DBulletTest));
}
#endif // !__C4DBULLETTEST__H__


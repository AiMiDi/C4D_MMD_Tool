#ifndef DYNMOTOROBJECT_H__
#define DYNMOTOROBJECT_H__

enum
{
	MOTOR_FORCE = 12101,
	MOTOR_LINEAR_SPEED = 12102,
	MOTOR_TORQUE = 12111,
	MOTOR_ANGULAR_SPEED = 12112,

	MOTOR_MODE = 12121,
	MOTOR_MODE_REGULATE_SPEED = 0,
	MOTOR_MODE_APPLY_FORCE = 1,

	MOTOR_DUMMY
};

#endif // DYNMOTOROBJECT_H__

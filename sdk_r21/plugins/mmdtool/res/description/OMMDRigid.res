CONTAINER OMMDRigid {
	NAME OMMDRigid;
	INCLUDE Obase;

	GROUP PMX_RIGID_OBJ_GRP {
		DEFAULT 1;

		STATICTEXT RIGID_INDEX {
		}

		STRING RIGID_NAME_LOCAL {
			ANIM OFF;
		}

		STRING RIGID_NAME_UNIVERSAL {
			ANIM OFF;
		}

		LONG RIGID_NAME_IS {
			ANIM OFF;
			MIN 0;
			MAX 1;

			CYCLE {
				RIGID_NAME_IS_LOCAL;
				RIGID_NAME_IS_UNIVERSAL;
			}
		}

		LONG RIGID_GROUP_ID {
			ANIM OFF;
			MIN 0;
			MAX 15;

			CYCLE {
				RIGID_GROUP_0;
				RIGID_GROUP_1;
				RIGID_GROUP_2;
				RIGID_GROUP_3;
				RIGID_GROUP_4;
				RIGID_GROUP_5;
				RIGID_GROUP_6;
				RIGID_GROUP_7;
				RIGID_GROUP_8;
				RIGID_GROUP_9;
				RIGID_GROUP_10;
				RIGID_GROUP_11;
				RIGID_GROUP_12;
				RIGID_GROUP_13;
				RIGID_GROUP_14;
				RIGID_GROUP_15;
			}
		}

		LONG RIGID_PHYSICS_MODE {
			ANIM OFF;

			CYCLE {
				TRACK_BONES;
				PHYSICAL_CALCULUS;
				PHYSICS_AND_BONES;
			}
		}

		LONG RIGID_SHAPE_TYPE {
			ANIM OFF;

			CYCLE {
				SPHERICAL;
				BOX;
				CAPLETS;
			}
		}


		LONG RIGID_RELATED_BONE_INDEX {
			ANIM OFF;
			CYCLE {
				RIGID_BONE_NONE;
			}
		}

		GROUP RIGID_SIZE_POSTURE_GRP {
			DEFAULT 1;

			STATICTEXT RIGID_SHAPE_SIZE {
			}

			GROUP {
				DEFAULT 1;
				COLUMNS 3;

				REAL RIGID_SHAPE_SIZE_X {
					FIT_H;
					SCALE_H;
					STEP 0.1;
					MIN 0;
					ANIM OFF;
				}

				REAL RIGID_SHAPE_SIZE_Y {
					FIT_H;
					SCALE_H;
					STEP 0.1;
					MIN 0;
					ANIM OFF;
				}

				REAL RIGID_SHAPE_SIZE_Z {
					FIT_H;
					SCALE_H;
					STEP 0.1;
					MIN 0;
					ANIM OFF;
				}
			}

			STATICTEXT RIGID_SHAPE_POSITION {
			}

			GROUP {
				DEFAULT 1;
				COLUMNS 3;

				REAL RIGID_SHAPE_POSITION_X {
					FIT_H;
					SCALE_H;
					STEP 0.1;
					ANIM OFF;
				}

				REAL RIGID_SHAPE_POSITION_Y {
					FIT_H;
					SCALE_H;
					STEP 0.1;
					ANIM OFF;
				}

				REAL RIGID_SHAPE_POSITION_Z {
					FIT_H;
					SCALE_H;
					STEP 0.1;
					ANIM OFF;
				}
			}

			STATICTEXT RIGID_SHAPE_ROTATION {
			}

			GROUP {
				DEFAULT 1;
				COLUMNS 3;

				REAL RIGID_SHAPE_ROTATION_X {
					FIT_H;
					SCALE_H;
					STEP 0.1;
					ANIM OFF;
				}

				REAL RIGID_SHAPE_ROTATION_Y {
					FIT_H;
					SCALE_H;
					STEP 0.1;
					ANIM OFF;
				}

				REAL RIGID_SHAPE_ROTATION_Z {
					FIT_H;
					SCALE_H;
					STEP 0.1;
					ANIM OFF;
				}
			}
		}

		GROUP RIGID_NON_COLLISION_GROUP_GRP {
			DEFAULT 1;
			COLUMNS 8;

			BOOL RIGID_NON_COLLISION_GROUP_0 {
				ANIM OFF;
			}

			BOOL RIGID_NON_COLLISION_GROUP_1 {
				ANIM OFF;
			}

			BOOL RIGID_NON_COLLISION_GROUP_2 {
				ANIM OFF;
			}

			BOOL RIGID_NON_COLLISION_GROUP_3 {
				ANIM OFF;
			}

			BOOL RIGID_NON_COLLISION_GROUP_4 {
				ANIM OFF;
			}

			BOOL RIGID_NON_COLLISION_GROUP_5 {
				ANIM OFF;
			}

			BOOL RIGID_NON_COLLISION_GROUP_6 {
				ANIM OFF;
			}

			BOOL RIGID_NON_COLLISION_GROUP_7 {
				ANIM OFF;
			}

			BOOL RIGID_NON_COLLISION_GROUP_8 {
				ANIM OFF;
			}

			BOOL RIGID_NON_COLLISION_GROUP_9 {
				ANIM OFF;
			}

			BOOL RIGID_NON_COLLISION_GROUP_10 {
				ANIM OFF;
			}

			BOOL RIGID_NON_COLLISION_GROUP_11 {
				ANIM OFF;
			}

			BOOL RIGID_NON_COLLISION_GROUP_12 {
				ANIM OFF;
			}

			BOOL RIGID_NON_COLLISION_GROUP_13 {
				ANIM OFF;
			}

			BOOL RIGID_NON_COLLISION_GROUP_14 {
				ANIM OFF;
			}

			BOOL RIGID_NON_COLLISION_GROUP_15 {
				ANIM OFF;
			}
		}

		GROUP RIGID_PHYSICAL_PARAMETER_GRP {
			DEFAULT 1;

			REAL RIGID_MASS {
				FIT_H;
				SCALE_H;
				MIN 0;
				STEP 0.01;
				ANIM OFF;
			}

			REAL RIGID_REPULSION {
				FIT_H;
				SCALE_H;
				MIN 0;
				STEP 0.01;
				ANIM OFF;
			}

			REAL RIGID_FRICTION_FORCE {
				FIT_H;
				SCALE_H;
				MIN 0;
				STEP 0.01;
				ANIM OFF;
			}

			REAL RIGID_MOVE_ATTENUATION {
				FIT_H;
				SCALE_H;
				MIN 0;
				STEP 0.01;
				ANIM OFF;
			}

			REAL RIGID_ROTATION_DAMPING {
				FIT_H;
				SCALE_H;
				MIN 0;
				STEP 0.01;
				ANIM OFF;
			}
		}
	}
}

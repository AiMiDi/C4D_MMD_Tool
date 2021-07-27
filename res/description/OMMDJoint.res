CONTAINER OMMDJoint {
	NAME OMMDJoint;
	INCLUDE Obase;

	GROUP OMMDJoint_GRP {
		DEFAULT 1;

		STATICTEXT JOINT_INDEX {
		}

		STRING JOINT_NAME_LOCAL {
			ANIM OFF;
		}

		STRING JOINT_NAME_UNIVERSAL {
			ANIM OFF;
		}

		LONG JOINT_NAME_IS {
			ANIM OFF;
			MIN 0;
			MAX 1;

			CYCLE {
				JOINT_NAME_IS_LOCAL;
				JOINT_NAME_IS_UNIVERSAL;
			}
		}

		LONG JOINT_TYPE {
			ANIM OFF;
			MIN 0;
			MAX 5;

			CYCLE {
				SpringDOF6;
				DOF6;
				P2P;
				ConeTwist;
				Slider;
				Hinge;
			}
		}

		GROUP JOINT_LINK_RIGID_GRP {
			DEFAULT 1;
			FIT_H;
			SCALE_H;

			LONG JOINT_LINK_RIGID_A_INDEX {
				FIT_H;
				SCALE_H;
				ANIM OFF;
				MIN -1;

				CYCLE {
					JOINT_RIGID_NONE;
				}
			}

			LONG JOINT_LINK_RIGID_B_INDEX {
				FIT_H;
				SCALE_H;
				ANIM OFF;
				MIN -1;

				CYCLE {
					JOINT_RIGID_NONE;
				}
			}
		}

		GROUP JOINT_ATTITUDE_GRP {
			DEFAULT 1;

			STATICTEXT JOINT_ATTITUDE_POSITION {
			}

			GROUP {
				DEFAULT 1;
				COLUMNS 3;

				REAL JOINT_ATTITUDE_POSITION_X {
					FIT_H;
					SCALE_H;
					STEP 0.1;
					ANIM OFF;
				}

				REAL JOINT_ATTITUDE_POSITION_Y {
					FIT_H;
					SCALE_H;
					STEP 0.1;
					ANIM OFF;
				}

				REAL JOINT_ATTITUDE_POSITION_Z {
					FIT_H;
					SCALE_H;
					STEP 0.1;
					ANIM OFF;
				}
			}

			STATICTEXT JOINT_ATTITUDE_ROTATION {
			}

			GROUP {
				DEFAULT 1;
				COLUMNS 3;

				REAL JOINT_ATTITUDE_ROTATION_X {
					FIT_H;
					SCALE_H;
					STEP 0.1;
					ANIM OFF;
				}

				REAL JOINT_ATTITUDE_ROTATION_Y {
					FIT_H;
					SCALE_H;
					STEP 0.1;
					ANIM OFF;
				}

				REAL JOINT_ATTITUDE_ROTATION_Z {
					FIT_H;
					SCALE_H;
					STEP 0.1;
					ANIM OFF;
				}
			}

			LONG JOINT_ATTITUDE_USE_BONE_INDEX {
				ANIM OFF;
				MIN -1;
				FIT_H;
				SCALE_H;

				CYCLE {
					JOINT_BONE_NONE;
				}
			}

			BUTTON JOINT_ATTITUDE_USE_BONE_BUTTON {
				FIT_H;
				SCALE_H;
			}
		}

		GROUP JOINT_PARAMETER_GRP {
			DEFAULT 1;

			STATICTEXT JOINT_PARAMETER_POSITION {
			}

			GROUP {
				DEFAULT 1;
				COLUMNS 2;

				REAL JOINT_PARAMETER_POSITION_X_MIN {
					FIT_H;
					SCALE_H;
					STEP 0.1;
					ANIM OFF;
				}

				REAL JOINT_PARAMETER_POSITION_X_MAX {
					FIT_H;
					SCALE_H;
					STEP 0.1;
					ANIM OFF;
				}
			}

			GROUP {
				DEFAULT 1;
				COLUMNS 2;

				REAL JOINT_PARAMETER_POSITION_Y_MIN {
					FIT_H;
					SCALE_H;
					STEP 0.1;
					ANIM OFF;
				}

				REAL JOINT_PARAMETER_POSITION_Y_MAX {
					FIT_H;
					SCALE_H;
					STEP 0.1;
					ANIM OFF;
				}
			}

			GROUP {
				DEFAULT 1;
				COLUMNS 2;

				REAL JOINT_PARAMETER_POSITION_Z_MIN {
					FIT_H;
					SCALE_H;
					STEP 0.1;
					ANIM OFF;
				}

				REAL JOINT_PARAMETER_POSITION_Z_MAX {
					FIT_H;
					SCALE_H;
					STEP 0.1;
					ANIM OFF;
				}
			}


			STATICTEXT JOINT_PARAMETER_ROTATION {
			}

			GROUP {
				DEFAULT 1;
				COLUMNS 2;

				REAL JOINT_PARAMETER_ROTATION_X_MIN {
					FIT_H;
					SCALE_H;
					STEP 0.1;
					ANIM OFF;
				}

				REAL JOINT_PARAMETER_ROTATION_X_MAX {
					FIT_H;
					SCALE_H;
					STEP 0.1;
					ANIM OFF;
				}
			}

			GROUP {
				DEFAULT 1;
				COLUMNS 2;

				REAL JOINT_PARAMETER_ROTATION_Y_MIN {
					FIT_H;
					SCALE_H;
					STEP 0.1;
					ANIM OFF;
				}

				REAL JOINT_PARAMETER_ROTATION_Y_MAX {
					FIT_H;
					SCALE_H;
					STEP 0.1;
					ANIM OFF;
				}
			}

			GROUP {
				DEFAULT 1;
				COLUMNS 2;

				REAL JOINT_PARAMETER_ROTATION_Z_MIN {
					FIT_H;
					SCALE_H;
					STEP 0.1;
					ANIM OFF;
				}

				REAL JOINT_PARAMETER_ROTATION_Z_MAX {
					FIT_H;
					SCALE_H;
					STEP 0.1;
					ANIM OFF;
				}
			}

			BUTTON JOINT_PARAMETER_RESET_BUTTON {
				FIT_H;
				SCALE_H;
			}
		}

		GROUP JOINT_SPRING_GRP {
			DEFAULT 1;

			STATICTEXT JOINT_SPRING_POSITION {
			}

			GROUP {
				DEFAULT 1;
				COLUMNS 3;

				REAL JOINT_SPRING_POSITION_X {
					FIT_H;
					SCALE_H;
					STEP 0.1;
					ANIM OFF;
				}

				REAL JOINT_SPRING_POSITION_Y {
					FIT_H;
					SCALE_H;
					STEP 0.1;
					ANIM OFF;
				}

				REAL JOINT_SPRING_POSITION_Z {
					FIT_H;
					SCALE_H;
					STEP 0.1;
					ANIM OFF;
				}
			}

			STATICTEXT JOINT_SPRING_ROTATION {
			}

			GROUP {
				DEFAULT 1;
				COLUMNS 3;

				REAL JOINT_SPRING_ROTATION_X {
					FIT_H;
					SCALE_H;
					STEP 0.1;
					ANIM OFF;
				}

				REAL JOINT_SPRING_ROTATION_Y {
					FIT_H;
					SCALE_H;
					STEP 0.1;
					ANIM OFF;
				}

				REAL JOINT_SPRING_ROTATION_Z {
					FIT_H;
					SCALE_H;
					STEP 0.1;
					ANIM OFF;
				}
			}

			BUTTON JOINT_SPRING_RESET_BUTTON {
				FIT_H;
				SCALE_H;
			}
		}
	}
}
}

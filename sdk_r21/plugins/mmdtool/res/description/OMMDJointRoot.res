CONTAINER OMMDJointRoot {
	NAME OMMDJointRoot;

	GROUP JOINT_ROOT_GRP {
		DEFAULT 1;


		LONG JOINT_DISPLAY_TYPE {
			CUSTOMGUI QUICKTABRADIO;
			ANIM OFF;
			FIT_H;
			SCALE_H;

			CYCLE {
				JOINT_DISPLAY_TYPE_OFF;
				JOINT_DISPLAY_TYPE_ON;
				JOINT_DISPLAY_TYPE_WIRE;
			}
		}

		LONG JOINT_MODE {
			CUSTOMGUI QUICKTABRADIO;
			ANIM OFF;
			FIT_H;
			SCALE_H;

			CYCLE {
				JOINT_MODE_EDIT;
				JOINT_MODE_ANIM;
			}
		}

		BUTTON ADD_JOINT_BUTTON {
			FIT_H;
			SCALE_H;
		}
	}
}

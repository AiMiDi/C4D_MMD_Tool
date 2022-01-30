CONTAINER TMMDBone {
	NAME TMMDBone;
	INCLUDE Texpression;

	GROUP PMX_BONE_INFO_GRP {
		DEFAULT 1;

		GROUP {
			DEFAULT 1;
			COLUMNS 2;

			STATICTEXT PMX_BONE_INDEX_TEXT {
			}

			STATICTEXT PMX_BONE_INDEX {
			}
		}

		GROUP {
			DEFAULT 1;
			COLUMNS 3;

			STATICTEXT PMX_BONE_PARENT_BONE_TEXT {
			}

			STATICTEXT PMX_BONE_PARENT_BONE_INDEX {
			}

			STATICTEXT PMX_BONE_PARENT_BONE_NAME {
			}
		}

		STRING PMX_BONE_NAME_LOCAL {
			ANIM OFF;
		}

		STRING PMX_BONE_NAME_UNIVERSAL {
			ANIM OFF;
		}

		LONG PMX_BONE_NAME_IS {
			ANIM OFF;
			MIN 0;
			MAX 1;

			CYCLE {
				PMX_BONE_NAME_IS_LOCAL;
				PMX_BONE_NAME_IS_UNIVERSAL;
			}
		}

		VECTOR PMX_BONE_POSITION {
			ANIM OFF;
		}

		GROUP PMX_BONE_FLAG_GRP {
			DEFAULT 1;
			COLUMNS 5;

			BOOL PMX_BONE_ROTATABLE {
				ANIM OFF;
			}

			BOOL PMX_BONE_TRANSLATABLE {
				ANIM OFF;
			}

			BOOL PMX_BONE_VISIBLE {
				ANIM OFF;
			}

			BOOL PMX_BONE_ENABLED {
				ANIM OFF;
			}

			BOOL PMX_BONE_IS_IK {
				ANIM OFF;
			}
		}

		GROUP PMX_BONE_DEFORM_LAYER_GRP {
			DEFAULT 1;
			COLUMNS 2;

			LONG PMX_BONE_LAYER {
				ANIM OFF;
			}

			BOOL PMX_BONE_PHYSICS_AFTER_DEFORM {
				ANIM OFF;
			}
		}

		GROUP PMX_BONE_END_OF_BONE_GRP {
			DEFAULT 1;

			LONG PMX_BONE_INDEXED_TAIL_POSITION {
				ANIM OFF;
				MIN 0;
				MAX 1;

				CYCLE {
					PMX_BONE_TAIL_IS_INDEX;
					PMX_BONE_TAIL_IS_POSITION;
				}
			}

			LONG PMX_BONE_TAIL_INDEX {
				FIT_H;
				SCALE_H;
				ANIM OFF;
				MIN -1;
			}

			VECTOR PMX_BONE_TAIL_POSITION {
				ANIM OFF;
			}
		}

		GROUP PMX_BONE_INHERIT_GRP {
			GROUP {
				COLUMNS 2;

				BOOL PMX_BONE_INHERIT_ROTATION {
					FIT_H;
					SCALE_H;
					ANIM OFF;
				}

				BOOL PMX_BONE_INHERIT_TRANSLATION {
					FIT_H;
					SCALE_H;
					ANIM OFF;
				}
			}

			GROUP {
				COLUMNS 2;

				LONG PMX_BONE_INHERIT_BONE_PARENT_INDEX {
					ANIM OFF;
					MIN -1;
				}

				LINK PMX_BONE_INHERIT_BONE_PARENT_LINK {
					ANIM OFF;
				}
			}

			REAL PMX_BONE_INHERIT_BONE_PARENT_INFLUENCE {
				ANIM OFF;
				STEP 0.01;
				FIT_H;
				SCALE_H;
				UNIT REAL;
			}
		}

		GROUP PMX_BONE_FIXED_AXIS_GRP {
			BOOL PMX_BONE_IS_FIXED_AXIS {
				ANIM OFF;
			}

			VECTOR PMX_BONE_FIXED_AXIS {
				ANIM OFF;
			}
		}

		GROUP PMX_BONE_LOCAL_COORDINATE_GRP {
			BOOL PMX_BONE_LOCAL_IS_COORDINATE {
				ANIM OFF;
			}

			VECTOR PMX_BONE_LOCAL_X {
				ANIM OFF;
			}

			VECTOR PMX_BONE_LOCAL_Z {
				ANIM OFF;
			}
		}
	}

	GROUP PMX_BONE_TAG_ANIMATION_GRP {

		LONG PMX_BONE_TAG_FRAME_ON {
			FIT_H;
			SCALE_H;
		}

		LONG PMX_BONE_TAG_CURVE_TYPE {
			ANIM OFF;
			MIN 0;
			MAX 5;
			FIT_H;
			SCALE_H;


			CYCLE {
				PMX_BONE_TAG_XCURVE;
				PMX_BONE_TAG_YCURVE;
				PMX_BONE_TAG_ZCURVE;
				PMX_BONE_TAG_RCURVE;
				PMX_BONE_TAG_ACURVE;
			}
		}

		GROUP {
			SPLINE PMX_BONE_TAG_SPLINE {
				ANIM OFF;
				SHOWGRID_H;
				SHOWGRID_V;
				MINSIZE_H 350;
				MINSIZE_V 350;
				FIT_H;
				SCALE_H;
				SQUARE;
			}

			GROUP {
				COLUMNS 5;

				BUTTON PMX_BONE_TAG_INIT_CURVE_BUTTON {
					FIT_H;
					SCALE_H;
				}

				BUTTON PMX_BONE_TAG_REGISTER_CURVE_BUTTON {
					FIT_H;
					SCALE_H;
				}

				BUTTON PMX_BONE_TAG_UPDATE_CURVE_BUTTON {
					FIT_H;
					SCALE_H;
				}

				BUTTON PMX_BONE_TAG_DELETE_CURVE_BUTTON {
					FIT_H;
					SCALE_H;
				}

				BUTTON PMX_BONE_TAG_DELETE_ALL_CURVE_BUTTON {
					FIT_H;
					SCALE_H;
				}
			}
		}
	}

	GROUP PMX_BONE_MORPH_GRP {
		STRING PMX_BONE_MORPH_ADD_NAME {
			FIT_H;
			SCALE_H;
			ANIM OFF;
		}

		BUTTON PMX_BONE_MORPH_ADD_BUTTON {
			FIT_H;
			SCALE_H;
		}
	}
}

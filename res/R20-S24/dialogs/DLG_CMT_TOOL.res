DIALOG DLG_CMT_TOOL {
    NAME IDS_CMT_TOOL_TITLE;
    CENTER_V;
    CENTER_H;

    USERAREA DLG_CMT_TOOL_IMG {
        SIZE 214, 68;
        SCALE_H;
    }

    TAB DLG_CMT_TOOL_TAB_GRP {
        FIT_V;
        FIT_H;
        SCALE_H;
        SCALE_V;

        GROUP DLG_CMT_TOOL_CAMERA_GRP {
            NAME IDS_CMT_TOOL_CAMERA_GRP;
            BORDERSIZE 0, 0, 0, 0;
            SPACE 0, 0;
            BORDERSTYLE BORDER_NONE;

            SCROLLGROUP DLG_CMT_TOOL_CAMERA_SCROLL_GRP {
                SIZE 0, 210;
                FIT_V;
                FIT_H;
                SCALE_H;
                SCALE_V;
                SCROLL_V;
                SCROLL_STATUSBAR;

                GROUP {
                    SIZE 350, 0;
                    CENTER_H;
                    COLUMNS 1;
                    ROWS 3;
                    BORDERSIZE 0, 0, 0, 0;
                    SPACE 0, 0;
                    BORDERSTYLE BORDER_NONE;

                    GROUP DLG_CMT_TOOL_CAMERA_IMPORT_GRP {
                        NAME IDS_CMT_TOOL_CAMERA_IMPORT_GRP;
                        SIZE 0, 0;
                        CENTER_H;
                        COLUMNS 1;
                        ROWS 2;
                        BORDERSIZE 10, 5, 10, 10;
                        SPACE 2, 5;
                        BORDERSTYLE BORDER_IN;

                        GROUP DLG_CMT_TOOL_CAMERA_IMPORT_SIZE_GRP {
                            SIZE 350, 10;
                            CENTER_H;
                            COLUMNS 2;
                            ROWS 1;

                            STATICTEXT DLG_CMT_TOOL_CAMERA_IMPORT_SIZE_NAME {
                                NAME IDS_CMT_TOOL_SIZE;
                                SIZE 100, 10;
                                ALIGN_LEFT;
                            }

                            EDITNUMBERARROWS DLG_CMT_TOOL_CAMERA_IMPORT_SIZE {
                                SIZE 250, 10;
                                ALIGN_LEFT;
                            }
                        }

                        GROUP DLG_CMT_TOOL_CAMERA_IMPORT_OFFSET_GRP {
                            SIZE 350, 10;
                            CENTER_H;
                            COLUMNS 2;
                            ROWS 1;

                            STATICTEXT DLG_CMT_TOOL_CAMERA_IMPORT_OFFSET_NAME {
                                NAME IDS_CMT_TOOL_OFFSET;
                                SIZE 100, 10;
                                ALIGN_LEFT;
                            }

                            EDITNUMBERARROWS DLG_CMT_TOOL_CAMERA_IMPORT_OFFSET {
                                SIZE 250, 10;
                                ALIGN_LEFT;
                            }
                        }

                        BUTTON DLG_CMT_TOOL_CAMERA_IMPORT_BUTTON {
                            NAME IDS_CMT_TOOL_IMPORT_BUTTON;
                            SIZE 300, 30;
                            CENTER_H;
                        }
                    }

                    GROUP DLG_CMT_TOOL_CAMERA_EXPORT_GRP {
                        NAME IDS_CMT_TOOL_CAMERA_EXPORT_GRP;
                        SIZE 0, 0;
                        CENTER_H;
                        COLUMNS 1;
                        ROWS 2;
                        BORDERSIZE 10, 5, 10, 10;
                        SPACE 2, 5;
                        BORDERSTYLE BORDER_IN;

                        GROUP DLG_CMT_TOOL_CAMERA_EXPORT_SIZE_GRP {
                            SIZE 350, 10;
                            CENTER_H;
                            COLUMNS 2;
                            ROWS 1;

                            STATICTEXT DLG_CMT_TOOL_CAMERA_EXPORT_SIZE_NAME {
                                NAME IDS_CMT_TOOL_SIZE;
                                SIZE 100, 10;
                                ALIGN_LEFT;
                            }

                            EDITNUMBERARROWS DLG_CMT_TOOL_CAMERA_EXPORT_SIZE {
                                SIZE 250, 10;
                                ALIGN_LEFT;
                            }
                        }

                        GROUP DLG_CMT_TOOL_CAMERA_EXPORT_OFFSET_GRP {
                            SIZE 350, 10;
                            CENTER_H;
                            COLUMNS 2;
                            ROWS 1;

                            STATICTEXT DLG_CMT_TOOL_CAMERA_EXPORT_OFFSET_NAME {
                                NAME IDS_CMT_TOOL_OFFSET;
                                SIZE 100, 10;
                                ALIGN_LEFT;
                            }

                            EDITNUMBERARROWS DLG_CMT_TOOL_CAMERA_EXPORT_OFFSET {
                                SIZE 250, 10;
                                ALIGN_LEFT;
                            }
                        }

                        GROUP DLG_CMT_TOOL_CAMERA_EXPORT_ROTATION_TWEEN_GRP {
                            SIZE 350, 10;
                            CENTER_H;
                            COLUMNS 2;
                            ROWS 1;

                            STATICTEXT DLG_CMT_TOOL_CAMERA_EXPORT_ROTATION_TWEEN_NAME {
                                NAME IDS_CMT_TOOL_ROTATION_TWEEN;
                                SIZE 100, 10;
                                ALIGN_LEFT;
                            }

                            COMBOBOX DLG_CMT_TOOL_CAMERA_EXPORT_ROTATION_TWEEN {
                                SIZE 242, 10;
                                ALIGN_LEFT;

                                CHILDS {
                                    DLG_CMT_ROTATION_TWEEN_X, IDS_CMT_ROTATION_TWEEN_X;
                                    DLG_CMT_ROTATION_TWEEN_Y, IDS_CMT_ROTATION_TWEEN_Y;
                                    DLG_CMT_ROTATION_TWEEN_Z, IDS_CMT_ROTATION_TWEEN_Z;
                                }
                            }
                        }

                        CHECKBOX DLG_CMT_TOOL_CAMERA_EXPORT_USE_BAKE {
                            NAME IDS_CMT_TOOL_EXPORT_USE_BAKE;
                            SIZE 350, 13;
                            ALIGN_LEFT;
                        }

                        BUTTON DLG_CMT_TOOL_CAMERA_EXPORT_BUTTON {
                            NAME IDS_CMT_TOOL_EXPORT_BUTTON;
                            SIZE 300, 30;
                            CENTER_H;
                        }
                    }

                    GROUP DLG_CMT_TOOL_CAMERA_CONV_GRP {
                        NAME IDS_CMT_TOOL_CAMERA_CONV_GRP;
                        SIZE 0, 0;
                        CENTER_H;
                        COLUMNS 1;
                        ROWS 2;
                        BORDERSIZE 10, 5, 10, 10;
                        SPACE 2, 5;
                        BORDERSTYLE BORDER_IN;

                        GROUP DLG_CMT_TOOL_CAMERA_CONV_DIS_GRP {
                            SIZE 350, 10;
                            CENTER_H;
                            COLUMNS 2;
                            ROWS 1;

                            STATICTEXT DLG_CMT_TOOL_CAMERA_CONV_DIS_NAME {
                                NAME IDS_CMT_TOOL_CONV_DIS;
                                SIZE 100, 10;
                                ALIGN_LEFT;
                            }

                            EDITNUMBERARROWS DLG_CMT_TOOL_CAMERA_CONV_DIS {
                                SIZE 250, 10;
                                ALIGN_LEFT;
                            }
                        }

                        GROUP DLG_CMT_TOOL_CAMERA_CONV_ROTATION_TWEEN_GRP {
                            SIZE 350, 10;
                            CENTER_H;
                            COLUMNS 2;
                            ROWS 1;

                            STATICTEXT DLG_CMT_TOOL_CAMERA_CONV_ROTATION_TWEEN_NAME {
                                NAME IDS_CMT_TOOL_ROTATION_TWEEN;
                                SIZE 100, 10;
                                ALIGN_LEFT;
                            }

                            COMBOBOX DLG_CMT_TOOL_CAMERA_CONV_ROTATION_TWEEN {
                                SIZE 242, 10;
                                ALIGN_LEFT;

                                CHILDS {
                                    DLG_CMT_ROTATION_TWEEN_X, IDS_CMT_ROTATION_TWEEN_X;
                                    DLG_CMT_ROTATION_TWEEN_Y, IDS_CMT_ROTATION_TWEEN_Y;
                                    DLG_CMT_ROTATION_TWEEN_Z, IDS_CMT_ROTATION_TWEEN_Z;
                                }
                            }
                        }

                        BUTTON DLG_CMT_TOOL_CAMERA_CONV_BUTTON {
                            NAME IDS_CMT_TOOL_CAMERA_CONV_BUTTON;
                            SIZE 300, 30;
                            CENTER_H;
                        }
                    }
                }
            }
        }

        GROUP DLG_CMT_TOOL_MOTION_GRP {
            NAME IDS_CMT_TOOL_MOTION_GRP;
            BORDERSIZE 0, 0, 0, 0;
            SPACE 0, 0;
            BORDERSTYLE BORDER_NONE;

            SCROLLGROUP DLG_CMT_TOOL_MOTION_SCROLL_GRP {
                SIZE 0, 210;
                FIT_V;
                FIT_H;
                SCALE_H;
                SCALE_V;
                SCROLL_V;
                SCROLL_STATUSBAR;

                GROUP {
                    SIZE 350, 0;
                    CENTER_H;
                    COLUMNS 1;
                    ROWS 3;
                    BORDERSIZE 0, 0, 0, 0;
                    SPACE 0, 0;
                    BORDERSTYLE BORDER_NONE;

                    GROUP DLG_CMT_TOOL_MOTION_IMPORT_GRP {
                        NAME IDS_CMT_TOOL_MOTION_IMPORT_GRP;
                        SIZE 0, 0;
                        CENTER_H;
                        COLUMNS 1;
                        ROWS 2;
                        BORDERSIZE 10, 5, 10, 10;
                        SPACE 2, 5;
                        BORDERSTYLE BORDER_IN;

                        GROUP DLG_CMT_TOOL_MOTION_IMPORT_SIZE_GRP {
                            SIZE 350, 10;
                            CENTER_H;
                            COLUMNS 2;
                            ROWS 1;

                            STATICTEXT DLG_CMT_TOOL_MOTION_IMPORT_SIZE_NAME {
                                NAME IDS_CMT_TOOL_SIZE;
                                SIZE 100, 10;
                                ALIGN_LEFT;
                            }

                            EDITNUMBERARROWS DLG_CMT_TOOL_MOTION_IMPORT_SIZE {
                                SIZE 250, 10;
                                ALIGN_LEFT;
                            }
                        }

                        GROUP DLG_CMT_TOOL_MOTION_IMPORT_OFFSET_GRP {
                            SIZE 350, 10;
                            CENTER_H;
                            COLUMNS 2;
                            ROWS 1;

                            STATICTEXT DLG_CMT_TOOL_MOTION_IMPORT_OFFSET_NAME {
                                NAME IDS_CMT_TOOL_OFFSET;
                                SIZE 100, 10;
                                ALIGN_LEFT;
                            }

                            EDITNUMBERARROWS DLG_CMT_TOOL_MOTION_IMPORT_OFFSET {
                                SIZE 250, 10;
                                ALIGN_LEFT;
                            }
                        }

                        GROUP DLG_CMT_TOOL_MOTION_IMPORT_SETTING_GRP {
                            NAME IDS_CMT_TOOL_IMPORT_SETTING_GRP;
                            SIZE 350, 0;
                            CENTER_H;
                            COLUMNS 2;
                            ROWS 3;
                            BORDERSIZE 10, 5, 10, 10;
                            BORDERSTYLE BORDER_IN;

                            CHECKBOX DLG_CMT_TOOL_MOTION_IMPORT_MOTION {
                                NAME IDS_CMT_TOOL_MOTION_IMPORT_MOTION;
                                SIZE 180, 13;
                                ALIGN_LEFT;
                            }

                            CHECKBOX DLG_CMT_TOOL_MOTION_IMPORT_MORPH {
                                NAME IDS_CMT_TOOL_MOTION_IMPORT_MORPH;
                                SIZE 180, 13;
                                ALIGN_LEFT;
                            }

                            CHECKBOX DLG_CMT_TOOL_MOTION_IMPORT_MODEL_INFO {
                                NAME IDS_CMT_TOOL_MOTION_IMPORT_MODEL_INFO;
                                SIZE 180, 13;
                                ALIGN_LEFT;
                            }

                            CHECKBOX DLG_CMT_TOOL_MOTION_IMPORT_IGNORE_PHYSICAL {
                                NAME IDS_CMT_TOOL_MOTION_IMPORT_IGNORE_PHYSICAL;
                                SIZE 180, 13;
                                ALIGN_LEFT;
                            }

                            CHECKBOX DLG_CMT_TOOL_MOTION_IMPORT_DELETE_PREVIOUS_ANIMATION {
                                NAME IDS_CMT_TOOL_MOTION_IMPORT_DELETE_PREVIOUS_ANIMATION;
                                SIZE 180, 13;
                                ALIGN_LEFT;
                            }

                            CHECKBOX DLG_CMT_TOOL_MOTION_IMPORT_DETAIL {
                                NAME IDS_CMT_TOOL_MOTION_IMPORT_DETAIL;
                                SIZE 180, 13;
                                ALIGN_LEFT;
                            }
                        }

                        BUTTON DLG_CMT_TOOL_MOTION_IMPORT_BUTTON {
                            NAME IDS_CMT_TOOL_IMPORT_BUTTON;
                            SIZE 300, 30;
                            CENTER_H;
                        }
                    }

                    GROUP DLG_CMT_TOOL_MOTION_EXPORT_GRP {
                        NAME IDS_CMT_TOOL_MOTION_EXPORT_GRP;
                        SIZE 0, 0;
                        CENTER_H;
                        COLUMNS 1;
                        ROWS 2;
                        BORDERSIZE 10, 5, 10, 10;
                        SPACE 2, 5;
                        BORDERSTYLE BORDER_IN;

                        GROUP DLG_CMT_TOOL_MOTION_EXPORT_SIZE_GRP {
                            SIZE 350, 10;
                            CENTER_H;
                            COLUMNS 2;
                            ROWS 1;

                            STATICTEXT DLG_CMT_TOOL_MOTION_EXPORT_SIZE_NAME {
                                NAME IDS_CMT_TOOL_SIZE;
                                SIZE 100, 10;
                                ALIGN_LEFT;
                            }

                            EDITNUMBERARROWS DLG_CMT_TOOL_MOTION_EXPORT_SIZE {
                                SIZE 250, 10;
                                ALIGN_LEFT;
                            }
                        }

                        GROUP DLG_CMT_TOOL_MOTION_EXPORT_OFFSET_GRP {
                            SIZE 350, 10;
                            CENTER_H;
                            COLUMNS 2;
                            ROWS 1;

                            STATICTEXT DLG_CMT_TOOL_MOTION_EXPORT_OFFSET_NAME {
                                NAME IDS_CMT_TOOL_OFFSET;
                                SIZE 100, 10;
                                ALIGN_LEFT;
                            }

                            EDITNUMBERARROWS DLG_CMT_TOOL_MOTION_EXPORT_OFFSET {
                                SIZE 250, 10;
                                ALIGN_LEFT;
                            }
                        }

                        GROUP DLG_CMT_TOOL_MOTION_EXPORT_ROTATION_TWEEN_GRP {
                            SIZE 350, 10;
                            CENTER_H;
                            COLUMNS 2;
                            ROWS 1;

                            STATICTEXT DLG_CMT_TOOL_MOTION_EXPORT_ROTATION_TWEEN_NAME {
                                NAME IDS_CMT_TOOL_ROTATION_TWEEN;
                                SIZE 100, 10;
                                ALIGN_LEFT;
                            }

                            COMBOBOX DLG_CMT_TOOL_MOTION_EXPORT_ROTATION_TWEEN {
                                SIZE 242, 10;
                                ALIGN_LEFT;

                                CHILDS {
                                    DLG_CMT_ROTATION_TWEEN_X, IDS_CMT_ROTATION_TWEEN_X;
                                    DLG_CMT_ROTATION_TWEEN_Y, IDS_CMT_ROTATION_TWEEN_Y;
                                    DLG_CMT_ROTATION_TWEEN_Z, IDS_CMT_ROTATION_TWEEN_Z;
                                }
                            }
                        }

                        GROUP DLG_CMT_TOOL_MOTION_EXPORT_SETTING_GRP {
                            NAME IDS_CMT_TOOL_EXPORT_SETTING_GRP;
                            SIZE 350, 0;
                            CENTER_H;
                            COLUMNS 2;
                            ROWS 2;
                            BORDERSIZE 10, 5, 10, 10;
                            BORDERSTYLE BORDER_IN;

                            CHECKBOX DLG_CMT_TOOL_MOTION_EXPORT_MOTION {
                                NAME IDS_CMT_TOOL_MOTION_EXPORT_MOTION;
                                SIZE 180, 13;
                                ALIGN_LEFT;
                            }

                            CHECKBOX DLG_CMT_TOOL_MOTION_EXPORT_MORPH {
                                NAME IDS_CMT_TOOL_MOTION_EXPORT_MORPH;
                                SIZE 180, 13;
                                ALIGN_LEFT;
                            }

                            CHECKBOX DLG_CMT_TOOL_MOTION_EXPORT_MODEL_INFO {
                                NAME IDS_CMT_TOOL_MOTION_EXPORT_MODEL_INFO;
                                SIZE 180, 13;
                                ALIGN_LEFT;
                            }

                            CHECKBOX DLG_CMT_TOOL_MOTION_EXPORT_USE_BAKE {
                                NAME IDS_CMT_TOOL_EXPORT_USE_BAKE;
                                SIZE 180, 13;
                                ALIGN_LEFT;
                            }
                        }

                        BUTTON DLG_CMT_TOOL_MOTION_EXPORT_BUTTON {
                            NAME IDS_CMT_TOOL_EXPORT_BUTTON;
                            SIZE 300, 30;
                            CENTER_H;
                        }
                    }

                    GROUP DLG_CMT_TOOL_POST_IMPORT_GRP {
                        NAME IDS_CMT_TOOL_POST_IMPORT_GRP;
                        SIZE 0, 0;
                        CENTER_H;
                        COLUMNS 1;
                        ROWS 2;
                        BORDERSIZE 28, 5, 28, 10;
                        SPACE 2, 5;
                        BORDERSTYLE BORDER_IN;

                        BUTTON DLG_CMT_TOOL_POSE_IMPORT_BUTTON {
                            NAME IDS_CMT_TOOL_IMPORT_BUTTON;
                            SIZE 300, 30;
                            CENTER_H;
                        }
                    }
                }
            }
        }

        GROUP DLG_CMT_TOOL_MODEL_GRP {
            NAME IDS_CMT_TOOL_MODEL_GRP;
            BORDERSIZE 0, 0, 0, 0;
            SPACE 0, 0;
            BORDERSTYLE BORDER_NONE;

            SCROLLGROUP DLG_CMT_TOOL_MODEL_SCROLL_GRP {
                SIZE 0, 210;
                FIT_V;
                FIT_H;
                SCALE_H;
                SCALE_V;
                SCROLL_V;
                SCROLL_STATUSBAR;

                GROUP {
                    SIZE 350, 0;
                    CENTER_H;
                    COLUMNS 1;
                    ROWS 1;
                    BORDERSIZE 0, 0, 0, 0;
                    SPACE 0, 0;
                    BORDERSTYLE BORDER_NONE;

                    GROUP DLG_CMT_TOOL_MODEL_IMPORT_GRP {
                        NAME IDS_CMT_TOOL_MODEL_IMPORT_GRP;
                        SIZE 0, 0;
                        CENTER_H;
                        COLUMNS 1;
                        ROWS 2;
                        BORDERSIZE 10, 5, 10, 10;
                        SPACE 2, 5;
                        BORDERSTYLE BORDER_IN;

                        GROUP DLG_CMT_TOOL_MODEL_IMPORT_SIZE_GRP {
                            SIZE 350, 10;
                            CENTER_H;
                            COLUMNS 2;
                            ROWS 1;

                            STATICTEXT DLG_CMT_TOOL_MODEL_IMPORT_SIZE_NAME {
                                NAME IDS_CMT_TOOL_SIZE;
                                SIZE 100, 10;
                                ALIGN_LEFT;
                            }

                            EDITNUMBERARROWS DLG_CMT_TOOL_MODEL_IMPORT_SIZE {
                                SIZE 250, 10;
                                ALIGN_LEFT;
                            }
                        }

                        GROUP DLG_CMT_TOOL_MODEL_IMPORT_SETTING_GRP {
                            NAME IDS_CMT_TOOL_IMPORT_SETTING_GRP;
                            SIZE 350, 0;
                            CENTER_H;
                            COLUMNS 2;
                            ROWS 6;
                            BORDERSIZE 10, 5, 10, 10;
                            BORDERSTYLE BORDER_IN;

                            CHECKBOX DLG_CMT_TOOL_MODEL_IMPORT_POLYGON {
                                NAME IDS_CMT_TOOL_MODEL_IMPORT_POLYGON;
                                SIZE 180, 13;
                                ALIGN_LEFT;
                            }

                            CHECKBOX DLG_CMT_TOOL_MODEL_IMPORT_NORMAL {
                                NAME IDS_CMT_TOOL_MODEL_IMPORT_NORMAL;
                                SIZE 180, 13;
                                ALIGN_LEFT;
                            }

                            CHECKBOX DLG_CMT_TOOL_MODEL_IMPORT_UV {
                                NAME IDS_CMT_TOOL_MODEL_IMPORT_UV;
                                SIZE 180, 13;
                                ALIGN_LEFT;
                            }

                            CHECKBOX DLG_CMT_TOOL_MODEL_IMPORT_MATERIAL {
                                NAME IDS_CMT_TOOL_MODEL_IMPORT_MATERIAL;
                                SIZE 180, 13;
                                ALIGN_LEFT;
                            }

                            CHECKBOX DLG_CMT_TOOL_MODEL_IMPORT_BONE {
                                NAME IDS_CMT_TOOL_MODEL_IMPORT_BONE;
                                SIZE 180, 13;
                                ALIGN_LEFT;
                            }

                            CHECKBOX DLG_CMT_TOOL_MODEL_IMPORT_WEIGHTS {
                                NAME IDS_CMT_TOOL_MODEL_IMPORT_WEIGHTS;
                                SIZE 180, 13;
                                ALIGN_LEFT;
                            }

                            CHECKBOX DLG_CMT_TOOL_MODEL_IMPORT_IK {
                                NAME IDS_CMT_TOOL_MODEL_IMPORT_IK;
                                SIZE 180, 13;
                                ALIGN_LEFT;
                            }

                            CHECKBOX DLG_CMT_TOOL_MODEL_IMPORT_INHERIT {
                                NAME IDS_CMT_TOOL_MODEL_IMPORT_INHERIT;
                                SIZE 180, 13;
                                ALIGN_LEFT;
                            }

                            CHECKBOX DLG_CMT_TOOL_MODEL_IMPORT_EXPRESSION {
                                NAME IDS_CMT_TOOL_MODEL_IMPORT_EXPRESSION;
                                SIZE 180, 13;
                                ALIGN_LEFT;
                            }

                            CHECKBOX DLG_CMT_TOOL_MODEL_IMPORT_MULTIPART {
                                NAME IDS_CMT_TOOL_MODEL_IMPORT_MULTIPART;
                                SIZE 180, 13;
                                ALIGN_LEFT;
                            }

                            CHECKBOX DLG_CMT_TOOL_MODEL_IMPORT_ENGLISH {
                                NAME IDS_CMT_TOOL_MODEL_IMPORT_ENGLISH;
                                SIZE 180, 13;
                                ALIGN_LEFT;
                            }

                            CHECKBOX DLG_CMT_TOOL_MODEL_IMPORT_ENGLISH_CHECK {
                                NAME IDS_CMT_TOOL_MODEL_IMPORT_ENGLISH_CHECK;
                                SIZE 180, 13;
                                ALIGN_LEFT;
                            }
                        }

                        BUTTON DLG_CMT_TOOL_MODEL_IMPORT_BUTTON {
                            NAME IDS_CMT_TOOL_IMPORT_BUTTON;
                            SIZE 300, 30;
                            CENTER_H;
                        }
                    }
                }
            }
        }
    }
}

DIALOG DLG_CMT_VMD_IMPORT {
    NAME IDS_CMT_TOOL_TITLE;
    CENTER_V;
    CENTER_H;

    USERAREA DLG_CMT_TOOL_IMG {
        SIZE 214, 68;
        SCALE_H;
    }
    
    GROUP DLG_CMT_TOOL_CAMERA_IMPORT_GRP {
        NAME IDS_CMT_TOOL_CAMERA_IMPORT_GRP;
        BORDERSIZE 5, 5, 5, 10;
        SPACE 2, 5;
        COLUMNS 1;
        ROWS 2;
        BORDERSTYLE BORDER_IN;

        GROUP {
            SIZE 350, 10;
            CENTER_H;
            COLUMNS 2;
            ROWS 1;

            STATICTEXT DLG_CMT_TOOL_CAMERA_IMPORT_SIZE_NAME {
                NAME IDS_CMT_TOOL_CAMERA_IMPORT_SIZE_NAME;
                SIZE 100, 10;
                ALIGN_LEFT;
            }

            EDITNUMBERARROWS DLG_CMT_TOOL_CAMERA_IMPORT_SIZE {
                SIZE 250, 10;
                ALIGN_LEFT;
            }
        }

        GROUP {
            SIZE 350, 10;
            CENTER_H;
            COLUMNS 2;
            ROWS 1;

            STATICTEXT DLG_CMT_TOOL_CAMERA_IMPORT_OFFSET_NAME {
                NAME IDS_CMT_TOOL_CAMERA_IMPORT_OFFSET_NAME;
                SIZE 100, 10;
                ALIGN_LEFT;
            }

            EDITNUMBERARROWS DLG_CMT_TOOL_CAMERA_IMPORT_OFFSET {
                SIZE 250, 10;
                ALIGN_LEFT;
            }
        }

        GROUP {
            SIZE 350, 10;
            CENTER_H;
            COLUMNS 2;
            ROWS 1;

            BUTTON DLG_CMT_TOOL_CAMERA_IMPORT_BUTTON {
                NAME IDS_CMT_TOOL_CAMERA_IMPORT_BUTTON;
                SIZE 150, 30;
                CENTER_H;
            }

            BUTTON DLG_CMT_TOOL_CAMERA_CANCEL_BUTTON {
                NAME IDS_CMT_TOOL_CAMERA_CANCEL_BUTTON;
                SIZE 150, 30;
                CENTER_H;
            }
        }
    }
}
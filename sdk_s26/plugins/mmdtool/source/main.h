#ifndef MAIN_H_
#define MAIN_H_

/*
 * #define ID_VMD_MOTION_TAG 1056979
 * #define ID_PMX_BONE_INHERIT 1057256
 */
#define ID_MMD_TOOL 1056563

#define ID_O_MMD_MODEL		1056724
#define ID_T_MMD_MATERIAL	1056725
#define ID_T_MMD_DISPLAY	1056721
#define ID_T_MMD_BONE		1056720

#define ID_O_MMD_RIGID		1056722
#define ID_O_MMD_JOINT		1056723
#define ID_O_MMD_CAMERA		1056978
#define ID_O_MMD_MESH_ROOT	1057943
#define ID_O_MMD_BONE_ROOT	1057944
#define ID_O_MMD_RIGID_ROOT	1057945
#define ID_O_MMD_JOINT_ROOT	1057946

#define ID_S_MMD_CAM_DRAW	1057017
#define ID_L_MMD_VMD_IMPORT	1057489
#define ID_E_MMD_VMD_EXPORT	1057490


#include <fstream>
#include <memory>
#include "c4d.h"
#include "c4d_baseobject.h"
#include "c4d_objectdata.h"
#include "c4d_plugin.h"
#include "c4d_scenehookdata.h"
#include "c4d_symbols.h"
#include "c4d_tagdata.h"
#include "ckvalue.h"
#include "customgui_priority.h"
#include "customgui_splinecontrol.h"
#include "customgui_splinecontrol.h"
#include "ge_prepass.h"
#include "ImagesGUI.h"
#include "lib_ca.h"
#include "lib_ca.h"
#include "lib_description.h"
#include "lib_modeling.h"
#include "lib_ngon.h"
#include "ocajoint.h"
#include "operatingsystem.h"
#include "tcaconstraint.h"
#include "tcaik.h"
#include "tcaposemorph.h"
#include "tcaweight.h"
#include "tprotection.h"
#include "xcolor.h"
#include "maxon/apibase.h"
#include "maxon/baselist.h"
#include "maxon/pointerarray.h"
#include "maxon/quaternion.h"
#include "maxon/queue.h"
#include "maxon/sortedarray.h"
#include "maxon/synchronized.h"
#include "maxon/timevalue.h"

#if API_VERSION >= 21000
#include "customgui_iconchooser.h"
#endif

#if API_VERSION < 23000
namespace maxon {
    using HashInt = UInt;
}
#endif

class MMDTool;
class MMDToolDialog;

class MyBaseTime : public BaseTime {
public:
    maxon::HashInt GetHashCode() const
    {
       return MAXON_HASHCODE(this->GetNumerator(), this->GetDenominator());
    }

   MyBaseTime(const BaseTime& time){
       this->SetDenominator(time.GetDenominator());
       this->SetNumerator(time.GetNumerator());
   }
};

Bool RegisterOMMDModelObject();


Bool RegisterTMMDBone();


Bool RegisterOMMDCamera();


Bool RegisterOMMDRigid();


/*Bool RegisterPMXMaterialTag();
 * Bool RegisterPMXDisplayTag();*/
Bool RegisterOMMDJoint();


Bool RegisterVMDCamDrawSceneHook();


Bool RegisterMMDTool();


Bool RegisterC4DBulletTest();


Bool RegisterVMDImport();


Bool RegisterOMMDMeshRoot();


Bool RegisterOMMDBoneRoot();


Bool RegisterOMMDRigidRoot();


Bool RegisterOMMDJointRoot();


static maxon::Spinlock g_spinlock;

#endif /* MAIN_H_ */

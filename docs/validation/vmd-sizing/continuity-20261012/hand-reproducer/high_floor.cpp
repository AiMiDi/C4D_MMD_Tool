#define main ExistingAdvancedMain
#include "Advanced-baseline.cpp"
#undef main
#include <iomanip>
int main() {
 libmmd::PMXFile source;
 Check(libmmd::ReadPMXFile(&source,"C:/code/C4D_MMD_Tool/dependency/libMMD/tests/fixtures/vmd-sizing/source.pmx"),"source");
 for(const std::string side:{"左","右"})AddFinger(source,side,1,1);
 for(const std::string side:{"左","右"})for(const auto*part:{"腕","ひじ","手首"})source.m_bones[Find(source,side+part)].m_position.y()=13;
 auto target=source;
 for(auto&bone:target.m_bones)if(bone.m_name.find("腕")!=std::string::npos||bone.m_name.find("ひじ")!=std::string::npos||bone.m_name.find("手首")!=std::string::npos||bone.m_name.find("指")!=std::string::npos)bone.m_position.x()+=bone.m_name.substr(0,3)=="左"?.8f:-.8f;
 for(auto&bone:target.m_bones)if(bone.m_name.find("腕")!=std::string::npos||bone.m_name.find("ひじ")!=std::string::npos||bone.m_name.find("手首")!=std::string::npos)bone.m_position.y()+=1;
 auto motion=ContactTransitionMotion(3);motion.m_motions.erase(motion.m_motions.begin());
 for(uint32_t f=0;f<=60;++f){auto key=Key("センター",f);key.m_translate.y()=float(.2+.004*(f<=30?f:60-f));motion.m_motions.push_back(key);}
 auto options=BaseOptions();options.floorContact=true;options.floorHeight=15;
 auto result=Run(source,target,motion,options);RequireResult(result);
 const Rig sourceRig(source);const Motion sourceMotion(motion);const Rig rig(target);const Motion input(result.stages[5]),output(result.stages[6]);int wrist=rig.Find("左手首"),arm=rig.Find("左腕"),elbow=rig.Find("左ひじ");
 Vector prior=Vector::Zero();std::cout<<std::setprecision(12)<<"frame,x,y,z,step,arm_rad,elbow_rad,wrist_rad,palm_rad,confidence,weighted_error,input_weighted_error\n";
 for(uint32_t f=0;f<=60;++f){const Pose before(rig,input,f),after(rig,output,f);auto p=after.positions[wrist];const Pose sourcePose(sourceRig,sourceMotion,f);double u=std::clamp(5.*(1.-std::abs(sourcePose.positions[sourceRig.Find("左手首")].y()-options.floorHeight)/options.contactDistance),0.,1.);const double confidence=u*u*(3.-2.*u);Vector goal=before.positions[wrist];goal.y()+=confidence*(options.floorHeight-goal.y());std::cout<<f<<','<<p.x()<<','<<p.y()<<','<<p.z()<<','<<(f?(p-prior).norm():0)<<','<<before.local[arm].rotation.angularDistance(after.local[arm].rotation)<<','<<before.local[elbow].rotation.angularDistance(after.local[elbow].rotation)<<','<<before.local[wrist].rotation.angularDistance(after.local[wrist].rotation)<<','<<before.rotations[wrist].angularDistance(after.rotations[wrist])<<','<<confidence<<','<<confidence*(p-goal).squaredNorm()<<','<<confidence*(before.positions[wrist]-goal).squaredNorm()<<'\n';prior=p;}
}

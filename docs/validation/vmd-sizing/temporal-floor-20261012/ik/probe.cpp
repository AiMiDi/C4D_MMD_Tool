#include "Constraints-frozen.cpp"
#include <iostream>
#include <iomanip>
using namespace libmmd::sizing;
using namespace libmmd::sizing::detail;
bool floorIKTrace=false;
#include "fixture.h"
int main(){
 auto model=Model();Rig rig(model);Options options;options.tolerance=.002;options.iterations=100;options.floorContact=true;options.centerOffsets=options.legOffsets=false;
 libmmd::VMDFile original;original.m_motions.push_back(Key("センター",0));
 for(uint32_t f=0;f<=100;++f)for(const std::string side:{"左","右"}){auto k=Key(side+"足ＩＫ",f);k.m_translate.y()=float(.15+.002*f);original.m_motions.push_back(k);}
 auto output=original;Analysis analysis;Contact(rig,rig,original,output,Effectors(rig,rig,options,analysis),options,analysis,nullptr,{});
 Motion input(original),adjusted(output);int foot=rig.Find("左足ＩＫ"),ankle=rig.Find("左足首"),knee=rig.Find("左ひざ");
 std::cout<<std::setprecision(12)<<"kind,frame,goal_y,ankle_y,ankle_z,knee_y,knee_z,error\n";
 auto print=[&](const char*kind,uint32_t frame,Pose& p){std::cout<<kind<<','<<frame<<','<<p.positions[foot].y()<<','<<p.positions[ankle].y()<<','<<p.positions[ankle].z()<<','<<p.positions[knee].y()<<','<<p.positions[knee].z()<<','<<(p.positions[ankle]-p.positions[foot]).norm()<<'\n';};
 for(uint32_t f:{46u,47u,48u,49u}){Pose incoming(rig,input,f),result(rig,adjusted,f);print("input",f,incoming);print("output",f,result);double height=incoming.positions[foot].y(),conf=ContactConfidence(height,.3);for(double weight:{1.,.5,.25}){auto candidate=incoming;candidate.local[foot].translation.y()-=weight*conf*height;floorIKTrace=f==47||f==48;candidate.Update();floorIKTrace=false;print("candidate",f,candidate);}}
 for(int n=0;n<=1000;++n){Pose p(rig,input,48);p.local[foot].translation.y()=double(n)*.00025;p.Update();print("sweep",48,p);}
 for(double height:{.006888,.244,.003108745,.246,.006888}){Pose p(rig,input,48);p.local[foot].translation.y()=height;p.Update();print("repeat",48,p);Rig independent(model);Pose fresh(independent,input,48);fresh.local[foot].translation.y()=height;fresh.Update();print("fresh",48,fresh);}
 for(double scale:{1.,8.5}){
  auto scaled=model;for(auto&bone:scaled.m_bones)bone.m_position*=float(scale);Rig scaledRig(scaled);Motion zero{libmmd::VMDFile()};
  for(double height:{.00310874493836,.00688801523424,.174546614289,.244,.246}){Pose p(scaledRig,zero,0);p.local[foot].translation.y()=scale*height;p.Update();std::cerr<<"scale,"<<scale<<','<<height<<','<<p.positions[ankle].y()/scale<<','<<p.positions[ankle].z()/scale<<','<<(p.positions[ankle]-p.positions[foot]).norm()/scale<<'\n';}
 }

}

#include "MMDMotionPose.h"
#include "MMDMotionLegs.h"
#include <fstream>
#include <filesystem>
#include <iostream>
#include <iomanip>
#include <random>
using namespace libmmd::sizing;
using namespace libmmd::sizing::detail;
std::vector<uint8_t> Read(const std::string& p) {std::ifstream s(std::filesystem::u8path(p),std::ios::binary);Require(s.good(),p);return {std::istreambuf_iterator<char>(s),{}};}
int main(){
std::ifstream manifest("S:/tmp/cmt-sizing-migration-assets.txt");std::string src,target;std::getline(manifest,src);std::getline(manifest,target);if(target.back()=='\r')target.pop_back();
libmmd::PMXFile model;auto bytes=Read(target);Require(libmmd::ReadPMXFile(&model,bytes.data(),bytes.size()),"model");
std::vector<libmmd::VMDFile> files(3);for(int i=0;i<3;++i){bytes=Read("S:/tmp/cmt-sizing-review-20261012/real-after/all-leg/stage-"+std::to_string(i+4)+".vmd");Require(libmmd::ReadVMDFile(&files[i],bytes.data(),bytes.size()),"vmd");}
Rig rig(model);Motion input(files[0]),avoided(files[1]),contact(files[2]);Options options;const auto pairs=LegCollisionPairs(rig);std::vector<int> controls{rig.Find("左足ＩＫ"),rig.Find("右足ＩＫ")};double length=0;
for(std::string side:{"左","右"}){int h=rig.Find(side+"足"),k=rig.Find(side+"ひざ"),a=rig.Find(side+"足首");length+=(model.m_bones[h].m_position-model.m_bones[k].m_position).norm()+(model.m_bones[k].m_position-model.m_bones[a].m_position).norm();}
double budget=length*.04;
std::ofstream out("S:/tmp/cmt-sizing-continuity-20261012/legs/selected.tsv");out<<std::setprecision(12)<<"frame\tcase\tmax_depth\tdepth0\tdepth1\tdepth2\tdepth3\tleft_ik\tright_ik\tleft_x\tleft_z\tright_x\tright_z\tsafe_max\tsafe_pairs\n";
for(int frame:{254,255,258,282,291,544,545,586,587,588,589,590,591,592,593,594,595,596,597,1197,1198,1199,1204,1242,1243,1244,1245,1246}){
Pose p(rig,input,frame),previous(rig,input,frame-1),priorAdjusted(rig,avoided,frame-1);auto original=p.local;auto baselineDepth=LegPenetrations(p,pairs,options.collisionMargin);std::vector<double> baselineIK;std::vector<Rotation> rotations;Eigen::Vector4d previousOffset;
for(int i=0;i<2;++i){int c=controls[i],parent=model.m_bones[c].m_parentBoneIndex;rotations.push_back(parent<0?Rotation::Identity():p.rotations[parent]);baselineIK.push_back((p.positions[model.m_bones[c].m_ikTargetBoneIndex]-p.positions[c]).norm());Vector v=priorAdjusted.positions[c]-previous.positions[c];previousOffset.segment<2>(i*2)=Eigen::Vector2d(v.x(),v.z());}
auto emit=[&](const std::string& name){auto d=LegPenetrations(p,pairs,options.collisionMargin);bool safe=true,perPair=true;out<<frame<<'\t'<<name<<'\t'<<*std::max_element(d.begin(),d.end());for(size_t i=0;i<d.size();++i){out<<'\t'<<d[i];perPair&=d[i]<=std::max(baselineDepth[i],options.tolerance)+1e-8;}
for(int i=0;i<2;++i){int c=controls[i];double e=(p.positions[model.m_bones[c].m_ikTargetBoneIndex]-p.positions[c]).norm();out<<'\t'<<e;safe&=e<=baselineIK[i]+options.tolerance;}
for(int i=0;i<2;++i){Vector v=rotations[i]*(p.local[controls[i]].translation-original[controls[i]].translation);out<<'\t'<<v.x()<<'\t'<<v.z();safe&=v.norm()<=budget+1e-7 && std::abs(v.y())<1e-6;}
out<<'\t'<<(safe&&*std::max_element(d.begin(),d.end())<=*std::max_element(baselineDepth.begin(),baselineDepth.end())+1e-6)<<'\t'<<(safe&&perPair)<<'\n';};
auto set=[&](Eigen::Vector4d offset){p.local=original;for(int i=0;i<2;++i)p.local[controls[i]].translation+=rotations[i].conjugate()*Vector(offset[2*i],0,offset[2*i+1]);p.Update();};
emit("input");p.local=Pose(rig,avoided,frame).local;p.Update();emit("stage5");p.local=Pose(rig,contact,frame).local;p.Update();emit("stage6");
for(int step=0;step<9;++step){set(previousOffset*std::ldexp(1.,-step));emit("previous_"+std::to_string(step));}
if(frame==589||frame==590||frame==592){std::mt19937 random(2000+frame);std::uniform_real_distribution<double> u(-1,1);double best=*std::max_element(baselineDepth.begin(),baselineDepth.end());Eigen::Vector4d bestOffset=Eigen::Vector4d::Zero();for(int trial=0;trial<2000;++trial){Eigen::Vector4d o;for(int f=0;f<2;++f){double x,z;do{x=u(random);z=u(random);}while(x*x+z*z>1.);o[2*f]=x*budget;o[2*f+1]=z*budget;}set(o);auto d=LegPenetrations(p,pairs,options.collisionMargin);bool safe=true;for(int i=0;i<2;++i){int c=controls[i];safe&=(p.positions[model.m_bones[c].m_ikTargetBoneIndex]-p.positions[c]).norm()<=baselineIK[i]+options.tolerance;}for(size_t i=0;i<d.size();++i)safe&=d[i]<=std::max(baselineDepth[i],options.tolerance)+1e-8;double mx=*std::max_element(d.begin(),d.end());if(safe&&mx<best){best=mx;bestOffset=o;}}set(bestOffset);emit("safe_random_best");}
if(frame==589||frame==590||frame==592){double best=*std::max_element(baselineDepth.begin(),baselineDepth.end());Eigen::Vector4d bestOffset=Eigen::Vector4d::Zero();for(int code=1;code<81;++code)for(double radius:{.25,.5,.75,1.}){int bits=code;Eigen::Vector4d o;for(int k=0;k<4;++k){o[k]=(bits%3)-1;bits/=3;}for(int f=0;f<2;++f){double norm=o.segment<2>(2*f).norm();if(norm>0)o.segment<2>(2*f)*=budget*radius/norm;}set(o);auto d=LegPenetrations(p,pairs,options.collisionMargin);bool safe=true;for(int i=0;i<2;++i){int c=controls[i];safe&=(p.positions[model.m_bones[c].m_ikTargetBoneIndex]-p.positions[c]).norm()<=baselineIK[i]+options.tolerance;}for(size_t i=0;i<d.size();++i)safe&=d[i]<=std::max(baselineDepth[i],options.tolerance)+1e-8;double mx=*std::max_element(d.begin(),d.end());if(safe&&mx<best){best=mx;bestOffset=o;}}set(bestOffset);emit("safe_grid_best");}

}
std::cout<<"budget="<<budget<<" pairs="<<pairs.size()<<"\n";
}

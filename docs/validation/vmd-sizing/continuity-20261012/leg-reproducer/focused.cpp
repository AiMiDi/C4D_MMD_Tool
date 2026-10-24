#include "MMDMotionPose.h"
#include "MMDMotionLegs.h"
#include <fstream>
#include <filesystem>
#include <iostream>
#include <iomanip>
using namespace libmmd::sizing;
using namespace libmmd::sizing::detail;
std::vector<uint8_t> Read(const std::string& p){std::ifstream s(std::filesystem::u8path(p),std::ios::binary);Require(s.good(),p);return {std::istreambuf_iterator<char>(s),{}};}
int main(int argc,char**argv){Require(argc==2,"output");std::ifstream manifest("S:/tmp/cmt-sizing-migration-assets.txt");std::string src,target;std::getline(manifest,src);std::getline(manifest,target);if(target.back()=='\r')target.pop_back();
libmmd::PMXFile model;auto bytes=Read(target);Require(libmmd::ReadPMXFile(&model,bytes.data(),bytes.size()),"model");libmmd::VMDFile file;bytes=Read("S:/tmp/cmt-sizing-review-20261012/real-after/all-leg/stage-4.vmd");Require(libmmd::ReadVMDFile(&file,bytes.data(),bytes.size()),"motion");Rig rig(model);Motion full(file);Options options;options.maxDiagnostics=100000;std::vector<int> controls{rig.Find("左足ＩＫ"),rig.Find("右足ＩＫ")};auto pairs=LegCollisionPairs(rig);double length=0;for(std::string side:{"左","右"}){int h=rig.Find(side+"足"),k=rig.Find(side+"ひざ"),a=rig.Find(side+"足首");length+=(model.m_bones[h].m_position-model.m_bones[k].m_position).norm()+(model.m_bones[k].m_position-model.m_bones[a].m_position).norm();}double budget=length*.04;std::map<std::string,libmmd::VMDMotion> templates;for(auto&k:file.m_motions)templates.emplace(k.m_boneName.ToUtf8String(),k);
std::ofstream out(argv[1]);out<<std::setprecision(12)<<"case\tframe\tbefore_max\tafter_max\tmax_pair_increase\tleft_ik_delta\tright_ik_delta\tleft_offset\tright_offset\tleft_step\tright_step\tsafe\n";int failures=0;
for(int scenario=0;scenario<4;++scenario){int start=scenario==3?0:(scenario==1?1230:575),end=scenario==3?int(full.LastFrame()):(scenario==1?1260:607);libmmd::VMDFile clip;for(int f=start;f<=end;++f){for(const auto&entry:templates){auto k=entry.second;auto v=full.Sample(entry.first,f);k.m_frame=f-start;k.m_translate=v.translation.cast<float>();k.m_quaternion=v.rotation.cast<float>();clip.m_motions.push_back(k);}libmmd::VMDIk ik;ik.m_frame=f-start;ik.m_show=1;for(int c:rig.ikControllers){std::u16string name;libmmd::ConvU8ToU16(model.m_bones[c].m_name,name);libmmd::VMDIkInfo info;info.m_name.Set(libmmd::ConvertU16ToSjisString(name).c_str());info.m_enable=full.IKEnabled(model.m_bones[c].m_name,f);if(scenario==2&&f>=588&&f<=593)info.m_enable=0;ik.m_ikInfos.push_back(info);}clip.m_iks.push_back(ik);}
Motion input(clip);auto result=clip;Analysis analysis;ApplyLegAvoidance(rig,result,options,analysis,nullptr,{});Motion output(result);Eigen::Vector4d previous=Eigen::Vector4d::Zero();for(int f=start;f<=end;++f){Pose a(rig,input,f-start),b(rig,output,f-start);auto da=LegPenetrations(a,pairs,options.collisionMargin),db=LegPenetrations(b,pairs,options.collisionMargin);double pairIncrease=-1e30;bool safe=true;for(size_t i=0;i<da.size();++i){pairIncrease=std::max(pairIncrease,db[i]-std::max(da[i],options.tolerance));safe&=db[i]<=std::max(da[i],options.tolerance)+1e-5;}out<<scenario<<'\t'<<f<<'\t'<<*std::max_element(da.begin(),da.end())<<'\t'<<*std::max_element(db.begin(),db.end())<<'\t'<<pairIncrease;Eigen::Vector4d correction;double sizes[2],steps[2];for(int i=0;i<2;++i){int c=controls[i],ankle=model.m_bones[c].m_ikTargetBoneIndex;double delta=(b.positions[c]-b.positions[ankle]).norm()-(a.positions[c]-a.positions[ankle]).norm();out<<'\t'<<delta;if(a.ikEnabled[c])safe&=delta<=options.tolerance+1e-5;Vector v=b.positions[c]-a.positions[c];sizes[i]=v.norm();correction.segment<2>(2*i)=Eigen::Vector2d(v.x(),v.z());steps[i]=(correction.segment<2>(2*i)-previous.segment<2>(2*i)).norm();safe&=sizes[i]<=budget+1e-5&&std::abs(v.y())<1e-5;if(!a.ikEnabled[c])safe&=sizes[i]<1e-6;}
out<<'\t'<<sizes[0]<<'\t'<<sizes[1]<<'\t'<<steps[0]<<'\t'<<steps[1]<<'\t'<<safe<<'\n';if(!safe)++failures;
if(scenario!=2 && f>start && std::max(steps[0],steps[1])>budget*.25+1.e-5)++failures;
const double maximum=*std::max_element(db.begin(),db.end());
if(scenario==0 && f==590 && maximum>=1.04)++failures;
if(scenario==0 && f==592 && maximum>=.95)++failures;
if(scenario==1 && f==1244 && (maximum>=.3 || std::max(steps[0],steps[1])>=.1))++failures;
previous=correction;}}
std::cout<<"regression_failures="<<failures<<"\n";return failures ? 1 : 0;
}

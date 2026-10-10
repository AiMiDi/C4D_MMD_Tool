#include "libMMD/Model/MMD/MMDMotionSizing.h"
#include <iostream>

int main(int argc, char** argv)
{
    if (argc != 2) return 1;
    const std::string root = argv[1];
    libmmd::PMXFile source, target;
    libmmd::VMDFile input;
    if (!libmmd::ReadPMXFile(&source, (root + "/source.pmx").c_str()) ||
        !libmmd::ReadPMXFile(&target, (root + "/target.pmx").c_str()) ||
        !libmmd::ReadVMDFile(&input, (root + "/motion.vmd").c_str())) return 2;
    const auto result = libmmd::sizing::Run(source, target, input);
    const auto batch = libmmd::sizing::RunBatch({{source, target, input, {}}});
    if (!result.success || !batch.success || batch.characters.size() != 1) return 3;
    std::cout << "Installed public API: Run and RunBatch passed\n";
    return 0;
}

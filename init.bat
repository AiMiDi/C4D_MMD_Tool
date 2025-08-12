git submodule update --init --recursive
for /f "delims=" %%i in ('"%ProgramFiles(x86)%\Microsoft Visual Studio\Installer\vswhere.exe" -products * -requires Microsoft.Component.MSBuild -property installationPath -latest') do set VSPath=%%i
call "%VSPath%\VC\Auxiliary\Build\vcvars64.bat" x64
rmdir /S /Q "./dependency/install"
cd ./dependency/bullet3 
mkdir build 
cd build
cmake ..  -G "Ninja Multi-Config" ^
-D INSTALL_LIBS=ON  ^
-D CMAKE_DEBUG_POSTFIX="_Debug" ^
-D CMAKE_INSTALL_PREFIX="../../install" ^
-D USE_MSVC_RUNTIME_LIBRARY_DLL=On ^
-D BUILD_CPU_DEMOS=Off ^
-D BUILD_OPENGL3_DEMOS=Off ^
-D BUILD_BULLET2_DEMOS=Off ^
-D BUILD_UNIT_TESTS=Off ^
-D BUILD_BULLET3=Off ^
-D BUILD_EXTRAS=Off ^
-D USE_GRAPHICAL_BENCHMARK=Off ^
-D BUILD_PYBULLET=Off ^
-D BULLET2_MULTITHREADING=ON ^
-D BULLET2_USE_PPL_MULTITHREADING=ON
cmake --build . --config Debug -j
cmake --install . --config Debug --prefix ../../install
cmake --build . --config Release -j
cmake --install . --config Release --prefix ../../install
cd ../..
cd ./yaml-cpp 
mkdir build
cd build
cmake ..  -G "Ninja Multi-Config" ^
-D CMAKE_DEBUG_POSTFIX="_Debug" ^
-D CMAKE_INSTALL_PREFIX="../../install" ^
-D YAML_CPP_BUILD_TESTS=Off ^
-D YAML_CPP_BUILD_TOOLS=Off
cmake --build . --config Debug -j
cmake --install . --config Debug --prefix ../../install
cmake --build . --config Release -j
cmake --install . --config Release --prefix ../../install
cd ../..
cd ./libMMD
mkdir build 
cd build
cmake ..  -G "Ninja Multi-Config" -D CMAKE_DEBUG_POSTFIX="_Debug" -D CMAKE_INSTALL_PREFIX="../../install" -D LIBMMD_BULLET_ROOT="../../install" -D LIBMMD_ENABLE_TEST=off -D LIBMMD_INSTALL=on
cmake --build . --config Debug -j
cmake --install . --config Debug --prefix ../../install
cmake --build . --config Release -j
cmake --install . --config Release --prefix ../../install
cd ../..
pause

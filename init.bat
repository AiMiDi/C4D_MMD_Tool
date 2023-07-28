git submodule update --init --recursive
for /f "delims=" %%i in ('"C:\Program Files (x86)\Microsoft Visual Studio\Installer\vswhere.exe" -products * -requires Microsoft.Component.MSBuild -property installationPath -latest') do set VSPath=%%i
call "%VSPath%\VC\Auxiliary\Build\vcvars64.bat" x64
cd ./dependency/bullet3 
mkdir build 
cd build
cmake ..  -G "Ninja Multi-Config" -D INSTALL_LIBS=ON -D USE_DOUBLE_PRECISION=ON -D CMAKE_DEBUG_POSTFIX="_Debug" -D CMAKE_INSTALL_PREFIX="../../install"
cmake --build . --config Debug -j
cmake --install . --config Debug --prefix ../../install
cmake --build . --config Release -j
cmake --install . --config Release --prefix ../../install
cd ../..
cd ./yaml-cpp 
mkdir build
cd build
cmake ..  -G "Ninja Multi-Config" -D CMAKE_DEBUG_POSTFIX="_Debug" -D CMAKE_INSTALL_PREFIX="../../install"
cmake --build . --config Debug -j
cmake --install . --config Debug --prefix ../../install
cmake --build . --config Release -j
cmake --install . --config Release --prefix ../../install
cd ../..
cd ./libMMD
mkdir build 
cd build
cmake ..  -G "Ninja Multi-Config" -D CMAKE_DEBUG_POSTFIX="_Debug" -D CMAKE_INSTALL_PREFIX="../../install"
cmake --build . --config Debug -j
cmake --install . --config Debug --prefix ../../install
cmake --build . --config Release -j
cmake --install . --config Release --prefix ../../install
cd ../..
Xcopy "span\include\tcb\*" "install\include\" /y
pause
git submodule update --init --recursive
call "C:\Program Files\Microsoft Visual Studio\2022\Enterprise\VC\Auxiliary\Build\vcvars64.bat" x64
cd ./dependency/bullet3 
mkdir build 
cd build
cmake ..  -G "Ninja Multi-Config" -D INSTALL_LIBS=ON -D USE_DOUBLE_PRECISION=ON
cmake --build . --config Debug -j
cmake --install . --config Debug --prefix ../../install
cmake --build . --config Release -j
cmake --install . --config Release --prefix ../../install
cd ../..
cd ./yaml-cpp 
mkdir build
cd build
cmake ..  -G "Ninja Multi-Config" -D CMAKE_DEBUG_POSTFIX="_Debug"
cmake --build . --config Debug -j
cmake --install . --config Debug --prefix ../../install
cmake --build . --config Release -j
cmake --install . --config Release --prefix ../../install
cd ../..
cd ./libiconv
mkdir build 
cd build
cmake ..  -G "Ninja Multi-Config"
cmake --build . --config Debug -j
cmake --install . --config Debug --prefix ../../install
cmake --build . --config Release -j
cmake --install . --config Release --prefix ../../install
cd ../..
Xcopy "span\include\tcb\*" "install\include\" /y
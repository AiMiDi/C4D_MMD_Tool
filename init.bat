git submodule update --init --recursive
cd ./dependency/bullet3 
mkdir build 
cd build
cmake ..  -D INSTALL_LIBS=ON -D USE_DOUBLE_PRECISION=ON
cmake --build . --config Debug -j
cmake --install . --config Debug --prefix ../../install
cmake --build . --config Release -j
cmake --install . --config Release --prefix ../../install
cd ../..
cd ./yaml-cpp 
mkdir build
cd build
cmake .. -D CMAKE_DEBUG_POSTFIX="_Debug"
cmake --build . --config Debug -j
cmake --install . --config Debug --prefix ../../install
cmake --build . --config Release -j
cmake --install . --config Release --prefix ../../install
cd ../..
cd ./libiconv
mkdir build 
cd build
cmake .. 
cmake --build . --config Debug -j
cmake --install . --config Debug --prefix ../../install
cmake --build . --config Release -j
cmake --install . --config Release --prefix ../../install
cd ../../..
pause
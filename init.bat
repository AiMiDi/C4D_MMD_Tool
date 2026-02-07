@echo off
setlocal enabledelayedexpansion

:: Parse command line arguments
set "BUILD_CONFIG=%1"
if "%BUILD_CONFIG%"=="" (
    echo No build configuration specified, will build both Debug and Release versions
    set "BUILD_DEBUG=1"
    set "BUILD_RELEASE=1"
) else if /i "%BUILD_CONFIG%"=="Debug" (
    echo Build configuration: Debug
    set "BUILD_DEBUG=1"
    set "BUILD_RELEASE=0"
) else if /i "%BUILD_CONFIG%"=="Release" (
    echo Build configuration: Release
    set "BUILD_DEBUG=0"
    set "BUILD_RELEASE=1"
) else (
    echo Error: Invalid build configuration "%BUILD_CONFIG%"
    echo Usage: init.bat [Debug^|Release]
    echo   No arguments: Build both Debug and Release versions
    echo   Debug: Build Debug version only
    echo   Release: Build Release version only
    pause
    exit /b 1
)

git submodule update --init --recursive
for /f "delims=" %%i in ('"%ProgramFiles(x86)%\Microsoft Visual Studio\Installer\vswhere.exe" -products * -requires Microsoft.Component.MSBuild -property installationPath -latest') do set VSPath=%%i
call "%VSPath%\VC\Auxiliary\Build\vcvars64.bat" x64
echo MSVC Toolset Version: %VCToolsVersion%
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

if "%BUILD_DEBUG%"=="1" (
    echo Building bullet3 Debug version...
    cmake --build . --config Debug -j
    cmake --install . --config Debug --prefix ../../install
)

if "%BUILD_RELEASE%"=="1" (
    echo Building bullet3 Release version...
    cmake --build . --config Release -j
    cmake --install . --config Release --prefix ../../install
)

cd ../..
cd ./yaml-cpp 
mkdir build
cd build
cmake ..  -G "Ninja Multi-Config" ^
-D CMAKE_DEBUG_POSTFIX="_Debug" ^
-D CMAKE_INSTALL_PREFIX="../../install" ^
-D YAML_CPP_BUILD_TESTS=Off ^
-D YAML_CPP_BUILD_TOOLS=Off

if "%BUILD_DEBUG%"=="1" (
    echo Building yaml-cpp Debug version...
    cmake --build . --config Debug -j
    cmake --install . --config Debug --prefix ../../install
)

if "%BUILD_RELEASE%"=="1" (
    echo Building yaml-cpp Release version...
    cmake --build . --config Release -j
    cmake --install . --config Release --prefix ../../install
)

cd ../..
cd ./libMMD
mkdir build 
cd build
cmake ..  -G "Ninja Multi-Config" -D CMAKE_DEBUG_POSTFIX="_Debug" -D CMAKE_INSTALL_PREFIX="../../install" -D LIBMMD_BULLET_ROOT="../../install" -D LIBMMD_ENABLE_TEST=off -D LIBMMD_INSTALL=on

if "%BUILD_DEBUG%"=="1" (
    echo Building libMMD Debug version...
    cmake --build . --config Debug -j
    cmake --install . --config Debug --prefix ../../install
)

if "%BUILD_RELEASE%"=="1" (
    echo Building libMMD Release version...
    cmake --build . --config Release -j
    cmake --install . --config Release --prefix ../../install
)

cd ../..
pause

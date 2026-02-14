@echo off
setlocal enabledelayedexpansion

:: Parse command line arguments
set "BUILD_DEBUG=0"
set "BUILD_RELEASE=0"
set "TOOLSET="

:parse_args
if "%~1"=="" goto :done_args
if /i "%~1"=="Debug" (
    set "BUILD_DEBUG=1"
    shift
    goto :parse_args
) else if /i "%~1"=="Release" (
    set "BUILD_RELEASE=1"
    shift
    goto :parse_args
) else if /i "%~1"=="v143" (
    set "TOOLSET=v143"
    shift
    goto :parse_args
) else if /i "%~1"=="v145" (
    set "TOOLSET=v145"
    shift
    goto :parse_args
) else (
    echo Error: Invalid argument "%~1"
    echo Usage: init.bat [Debug^|Release] [v143^|v145]
    echo   Build config: Debug, Release, or both if omitted
    echo   Toolset: v143 ^(VS 2022^), v145 ^(VS 2026^), or auto-detect if omitted
    pause
    exit /b 1
)
:done_args

:: Default: build both if no config specified
if "%BUILD_DEBUG%"=="0" if "%BUILD_RELEASE%"=="0" (
    set "BUILD_DEBUG=1"
    set "BUILD_RELEASE=1"
)

echo Build config: Debug=%BUILD_DEBUG% Release=%BUILD_RELEASE% Toolset=%TOOLSET%

git submodule update --init --recursive
:: Find latest Visual Studio installation
for /f "delims=" %%i in ('"%ProgramFiles(x86)%\Microsoft Visual Studio\Installer\vswhere.exe" -products * -requires Microsoft.Component.MSBuild -property installationPath -latest') do set VSPath=%%i
if not defined VSPath (
    echo Error: Could not find any Visual Studio installation
    pause
    exit /b 1
)
echo Using Visual Studio: %VSPath%

:: Select MSVC toolset version via vcvarsall
if "%TOOLSET%"=="v143" (
    echo Selecting MSVC toolset v143 ^(14.4x^)...
    call "%VSPath%\VC\Auxiliary\Build\vcvarsall.bat" x64 -vcvars_ver=14.4
) else if "%TOOLSET%"=="v145" (
    echo Selecting MSVC toolset v145 ^(14.5x^)...
    call "%VSPath%\VC\Auxiliary\Build\vcvarsall.bat" x64 -vcvars_ver=14.5
) else (
    call "%VSPath%\VC\Auxiliary\Build\vcvars64.bat" x64
)
if errorlevel 1 (
    echo Error: Failed to initialize MSVC toolset "%TOOLSET%"
    echo Make sure the corresponding toolset component is installed in Visual Studio Installer.
    pause
    exit /b 1
)
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
cmake ..  -G "Ninja Multi-Config" -D CMAKE_DEBUG_POSTFIX="_Debug" -D CMAKE_INSTALL_PREFIX="../../install" -D LIBMMD_BULLET_ROOT="../../install" -D LIBMMD_ENABLE_TEST=on -D LIBMMD_INSTALL=on

if "%BUILD_DEBUG%"=="1" (
    echo Building libMMD Debug version...
    cmake --build . --config Debug -j
    echo Running libMMD tests ^(Debug^)...
    ctest -C Debug --output-on-failure
    if errorlevel 1 (
        echo [ERROR] libMMD Debug tests failed!
        cd ../..
        pause
        exit /b 1
    )
    cmake --install . --config Debug --prefix ../../install
)

if "%BUILD_RELEASE%"=="1" (
    echo Building libMMD Release version...
    cmake --build . --config Release -j
    echo Running libMMD tests ^(Release^)...
    ctest -C Release --output-on-failure
    if errorlevel 1 (
        echo [ERROR] libMMD Release tests failed!
        cd ../..
        pause
        exit /b 1
    )
    cmake --install . --config Release --prefix ../../install
)

cd ../..
pause

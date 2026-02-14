@echo off
echo Cleaning dependency build caches...

if exist "dependency\bullet3\build" (
    echo Removing bullet3\build...
    rmdir /S /Q "dependency\bullet3\build"
)

if exist "dependency\yaml-cpp\build" (
    echo Removing yaml-cpp\build...
    rmdir /S /Q "dependency\yaml-cpp\build"
)

if exist "dependency\libMMD\build" (
    echo Removing libMMD\build...
    rmdir /S /Q "dependency\libMMD\build"
)

if exist "dependency\install" (
    echo Removing install output...
    rmdir /S /Q "dependency\install"
)

echo Done.
pause

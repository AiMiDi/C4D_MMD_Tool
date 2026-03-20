@echo off
setlocal EnableExtensions

rem =============================================================================
rem Run cmake --preset in a given sdk_* directory to generate the IDE/project files.
rem
rem Usage:
rem   configure_sdk.bat <sdk_dir> [preset]
rem
rem Examples:
rem   configure_sdk.bat sdk_2026 windows_vs2022_v143
rem   configure_sdk.bat sdk_r25 windows_vs2022_v143
rem   configure_sdk.bat sdk_2026 linux_ninja
rem
rem If preset is omitted, windows_vs2022_v143 is used.
rem For more options, run cmake --preset <name> ... directly in that sdk_* directory.
rem =============================================================================

set "ROOT=%~dp0"
set "SDK=%~1"
set "PRESET=%~2"

if "%SDK%"=="" (
  echo.
  echo Usage: %~nx0 ^<sdk_dir^> [preset]
  echo   Example: %~nx0 sdk_2026 windows_vs2022_v143
  echo.
  exit /b 1
)

if "%PRESET%"=="" set "PRESET=windows_vs2022_v143"

set "SDKPATH=%ROOT%%SDK%"
if not exist "%SDKPATH%\CMakePresets.json" (
  echo Error: "%SDKPATH%\CMakePresets.json" not found.
  exit /b 1
)

pushd "%SDKPATH%" || exit /b 1
echo [configure_sdk] cmake --preset "%PRESET%"
echo [configure_sdk] cwd: %CD%
cmake --preset "%PRESET%"
set "ERR=%ERRORLEVEL%"
popd
exit /b %ERR%

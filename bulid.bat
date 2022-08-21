./init.bat
"C:\Program Files\Microsoft Visual Studio\2022\Enterprise\Common7\IDE\devenv.com" sdk_r20\plugins\project\plugins.sln /Build "Release"
"C:\Program Files\Microsoft Visual Studio\2022\Enterprise\Common7\IDE\devenv.com" sdk_r21\plugins\project\plugins.sln /Build "Release"
"C:\Program Files\Microsoft Visual Studio\2022\Enterprise\Common7\IDE\devenv.com" sdk_s22\plugins\project\plugins.sln /Build "Release"
"C:\Program Files\Microsoft Visual Studio\2022\Enterprise\Common7\IDE\devenv.com" sdk_r23\plugins\project\plugins.sln /Build "Release"
"C:\Program Files\Microsoft Visual Studio\2022\Enterprise\Common7\IDE\devenv.com" sdk_S24\plugins\project\plugins.sln /Build "Release"
"C:\Program Files\Microsoft Visual Studio\2022\Enterprise\Common7\IDE\devenv.com" sdk_R25\plugins\project\plugins.sln /Build "Release"
"C:\Program Files\Microsoft Visual Studio\2022\Enterprise\Common7\IDE\devenv.com" sdk_S26\plugins\project\plugins.sln /Build "Release"
cd "D:\Program Files (x86)\Inno Setup 6\"
ISCC.exe 
iscc /DMyAppVersion="0.5.0" "%~dp0setup\c4d_plugin.iss"
pause
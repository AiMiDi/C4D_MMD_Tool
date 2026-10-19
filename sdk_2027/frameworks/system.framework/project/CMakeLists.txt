set(target_base_name system.framework)
set(target_platforms windows macos linux ios)

# Section: Source Processor (in json format)
set(target_settings [=[
{
  "apis" : [ "core.framework" ],
  "maxon" : true,
  "publicationlevel" : "public",
  "type" : "Lib"
}
]=])

# Section: General
set(enable_rtti OFF)
set(enable_exception_handling OFF)
set(source_directories source)

# Section: Windows
set(exclude_from_build.WINDOWS /sys_mac/ /sys_linux/ /cahosttimebase /macos /corethread_pthread.cpp)

# Section: macOS
set(exclude_from_build.MACOS /sys_windows/ /sys_linux/)

# Section: iOS
set(exclude_from_build.IOS /sys_windows/ /sys_linux/)

# Section: Linux
set(exclude.LINUX /sys_windows/ /sys_mac/ debugging/mac network/IPHlpApi corethread_win)

MaxonTargets_ProcessCinemaTargetVars()

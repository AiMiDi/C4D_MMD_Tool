set(target_base_name core.framework)
set(target_platforms windows macos linux ios)

# Section: Source Processor (in json format)
set(target_settings [=[
{
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
set(exclude_from_build.WINDOWS java_helper.cpp)

# Section: macOS
set(exclude_from_build.MACOS /win)
set(prebuild_event.MACOS.DEBUG "mkdir -p ~/Library/Application\\\\ Support/MAXON ; cp -f ${CMAKE_CURRENT_SOURCE_DIR}/typeviewer/xcode/maxon.py ~/Library/Application\\\\ Support/MAXON/maxon.py ; perl -w ${CMAKE_CURRENT_SOURCE_DIR}/typeviewer/xcode/copytypeviewer.pl maxon.py ~/Library/Application\\\\ Support/MAXON/maxon.py")
set(prebuild_event.MACOS.RELEASE "mkdir -p ~/Library/Application\\\\ Support/MAXON ; cp -f ${CMAKE_CURRENT_SOURCE_DIR}/typeviewer/xcode/maxon.py ~/Library/Application\\\\ Support/MAXON/maxon.py ; perl -w ${CMAKE_CURRENT_SOURCE_DIR}/typeviewer/xcode/copytypeviewer.pl maxon.py ~/Library/Application\\\\ Support/MAXON/maxon.py")

# Section: iOS
set(exclude_from_build.IOS /win)
set(prebuild_event.IOS.DEBUG "mkdir -p ~/Library/Application\\\\ Support/MAXON ; cp -f ${CMAKE_CURRENT_SOURCE_DIR}/typeviewer/xcode/maxon.py ~/Library/Application\\\\ Support/MAXON/maxon.py ; perl -w ${CMAKE_CURRENT_SOURCE_DIR}/typeviewer/xcode/copytypeviewer.pl maxon.py ~/Library/Application\\\\ Support/MAXON/maxon.py")
set(prebuild_event.IOS.RELEASE "mkdir -p ~/Library/Application\\\\ Support/MAXON ; cp -f ${CMAKE_CURRENT_SOURCE_DIR}/typeviewer/xcode/maxon.py ~/Library/Application\\\\ Support/MAXON/maxon.py ; perl -w ${CMAKE_CURRENT_SOURCE_DIR}/typeviewer/xcode/copytypeviewer.pl maxon.py ~/Library/Application\\\\ Support/MAXON/maxon.py")

# Section: Linux
set(exclude.LINUX /win)

MaxonTargets_ProcessCinemaTargetVars()

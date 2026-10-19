set(target_base_name cinema.framework)
set(target_platforms windows macos linux ios)

# Section: Source Processor (in json format)
set(target_settings [=[
{
  "apis" : [ "mesh_misc.framework", "core.framework", "math.framework" ],
  "c4d" : true,
  "dontuncrustify" : [ "/description/" ],
  "maxon" : true,
  "publicationlevel" : "public",
  "stylecheck.level" : 1,
  "type" : "Lib"
}
]=])

# Section: General
set(enable_rtti OFF)
set(enable_exception_handling OFF)
set(source_directories source)

# Section: macOS
set(prebuild_event.MACOS.DEBUG "mkdir -p ~/Library/Application\\\\ Support/MAXON ; cp -f ${CMAKE_CURRENT_SOURCE_DIR}/typeviewer/xcode/c4dapi.py ~/Library/Application\\\\ Support/MAXON/c4dapi.py ; perl -w ${CMAKE_CURRENT_SOURCE_DIR}/typeviewer/xcode/copytypeviewer.pl c4dapi.py ~/Library/Application\\\\ Support/MAXON/c4dapi.py")
set(prebuild_event.MACOS.RELEASE "mkdir -p ~/Library/Application\\\\ Support/MAXON ; cp -f ${CMAKE_CURRENT_SOURCE_DIR}/typeviewer/xcode/c4dapi.py ~/Library/Application\\\\ Support/MAXON/c4dapi.py ; perl -w ${CMAKE_CURRENT_SOURCE_DIR}/typeviewer/xcode/copytypeviewer.pl c4dapi.py ~/Library/Application\\\\ Support/MAXON/c4dapi.py")

# Section: iOS
set(prebuild_event.IOS.DEBUG "mkdir -p ~/Library/Application\\\\ Support/MAXON ; cp -f ${CMAKE_CURRENT_SOURCE_DIR}/typeviewer/xcode/c4dapi.py ~/Library/Application\\\\ Support/MAXON/c4dapi.py ; perl -w ${CMAKE_CURRENT_SOURCE_DIR}/typeviewer/xcode/copytypeviewer.pl c4dapi.py ~/Library/Application\\\\ Support/MAXON/c4dapi.py")
set(prebuild_event.IOS.RELEASE "mkdir -p ~/Library/Application\\\\ Support/MAXON ; cp -f ${CMAKE_CURRENT_SOURCE_DIR}/typeviewer/xcode/c4dapi.py ~/Library/Application\\\\ Support/MAXON/c4dapi.py ; perl -w ${CMAKE_CURRENT_SOURCE_DIR}/typeviewer/xcode/copytypeviewer.pl c4dapi.py ~/Library/Application\\\\ Support/MAXON/c4dapi.py")

MaxonTargets_ProcessCinemaTargetVars()

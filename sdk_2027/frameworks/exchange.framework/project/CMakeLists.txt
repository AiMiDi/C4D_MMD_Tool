set(target_base_name exchange.framework)
set(target_platforms windows macos linux ios)

# Section: Source Processor (in json format)
set(target_settings [=[
{
  "apis" : [ "core.framework", "image.framework", "math.framework" ],
  "maxon" : true,
  "publicationlevel" : "public",
  "type" : "Lib"
}
]=])

# Section: General
set(enable_rtti OFF)
set(enable_exception_handling OFF)
set(source_directories source)

MaxonTargets_ProcessCinemaTargetVars()

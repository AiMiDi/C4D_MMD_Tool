set(CMAKE_CURRENT_SOURCE_DIR <<CMAKE_CURRENT_SOURCE_DIR>>)
set(target_base_name <<target_base_name>>)
set(target_platforms <<target_platforms>>)

# Section: Source Processor (in json format)
set(target_settings <<target_settings>>)

# Section: General
set(enable_rtti <<enable_rtti>>)
set(enable_exception_handling <<enable_exception_handling>>)
set(type_viewer_files <<type_viewer_files>>)
set(source_directories <<source_directories>>)
set(additional_definitions <<additional_definitions>>)
set(output_directory <<output_directory>>)

# Section: Windows
set(exclude_from_build.WINDOWS <<exclude_from_build.WINDOWS>>)
set(exclude.WINDOWS <<exclude.WINDOWS>>)
set(additional_definitions.WINDOWS <<additional_definitions.WINDOWS>>)
set(link_libraries.WINDOWS.DEBUG <<link_libraries.WINDOWS.DEBUG>>)
set(link_libraries.WINDOWS.RELEASE <<link_libraries.WINDOWS.RELEASE>>)
set(link_libraries.WINDOWS.ARM.DEBUG <<link_libraries.WINDOWS.ARM.DEBUG>>)
set(link_libraries.WINDOWS.ARM.RELEASE <<link_libraries.WINDOWS.ARM.RELEASE>>)
set(additional_include_directories.WINDOWS <<additional_include_directories.WINDOWS>>)
set(additional_include_directories.WINDOWS.ARM <<additional_include_directories.WINDOWS.ARM>>)
set(additional_link_directories.WINDOWS <<additional_link_directories.WINDOWS>>)
set(additional_link_directories.WINDOWS.DEBUG <<additional_link_directories.WINDOWS.DEBUG>>)
set(additional_link_directories.WINDOWS.RELEASE <<additional_link_directories.WINDOWS.RELEASE>>)
set(additional_link_directories.WINDOWS.ARM <<additional_link_directories.WINDOWS.ARM>>)
set(additional_source_files.WINDOWS <<additional_source_files.WINDOWS>>)
set(prebuild_event.WINDOWS.DEBUG <<prebuild_event.WINDOWS.DEBUG>>)
set(prebuild_event.WINDOWS.RELEASE <<prebuild_event.WINDOWS.RELEASE>>)
set(subsystem.WINDOWS <<subsystem.WINDOWS>>)
set(additional_solution_files.WINDOWS <<additional_solution_files.WINDOWS>>)

# Section: macOS
set(exclude_from_build.MACOS <<exclude_from_build.MACOS>>)
set(exclude.MACOS <<exclude.MACOS>>)
set(additional_definitions.MACOS <<additional_definitions.MACOS>>)
set(swift_bridging_header.MACOS <<swift_bridging_header.MACOS>>)
set(xib_file.MACOS <<xib_file.MACOS>>)
set(plist_file.MACOS <<plist_file.MACOS>>)
set(icon_files.MACOS <<icon_files.MACOS>>)
set(link_libraries.MACOS.DEBUG <<link_libraries.MACOS.DEBUG>>)
set(link_libraries.MACOS.RELEASE <<link_libraries.MACOS.RELEASE>>)
set(additional_include_directories.MACOS <<additional_include_directories.MACOS>>)
set(link_frameworks.MACOS <<link_frameworks.MACOS>>)
set(additional_source_files.MACOS <<additional_source_files.MACOS>>)
set(prebuild_event.MACOS.DEBUG <<prebuild_event.MACOS.DEBUG>>)
set(prebuild_event.MACOS.RELEASE <<prebuild_event.MACOS.RELEASE>>)

# Section: Linux
set(exclude_from_build.LINUX <<exclude_from_build.LINUX>>)
set(exclude.LINUX <<exclude.LINUX>>)
set(additional_definitions.LINUX <<additional_definitions.LINUX>>)
set(link_libraries.LINUX.DEBUG <<link_libraries.LINUX.DEBUG>>)
set(link_libraries.LINUX.RELEASE <<link_libraries.LINUX.RELEASE>>)
set(additional_source_files.LINUX <<additional_source_files.LINUX>>)
set(system_include_paths <<system_include_paths>>)
set(additional_link_directories.LINUX.DEBUG <<additional_link_directories.LINUX.DEBUG>>)
set(additional_link_directories.LINUX.RELEASE <<additional_link_directories.LINUX.RELEASE>>)
set(additional_include_directories.LINUX <<additional_include_directories.LINUX>>)
set(prebuild_event.LINUX.DEBUG <<prebuild_event.LINUX.DEBUG>>)
set(prebuild_event.LINUX.RELEASE <<prebuild_event.LINUX.RELEASE>>)

# Section: Compiler

# Subsection: MSVC
set(additional_compile_options.MSVC.CPP <<additional_compile_options.MSVC.CPP>>)
set(additional_compile_options.MSVC.C <<additional_compile_options.MSVC.C>>)

# Subsection: GCC
set(additional_compile_options.GNU.CPP <<additional_compile_options.GNU.CPP>>)
set(additional_compile_options.GNU.C <<additional_compile_options.GNU.C>>)

# Subsection: Clang
set(additional_compile_options.CLANG.CPP <<additional_compile_options.CLANG.CPP>>)
set(additional_compile_options.CLANG.C <<additional_compile_options.CLANG.C>>)

# Section: Linker
set(additional_linker_options.MSVC.DEBUG <<additional_linker_options.MSVC.DEBUG>>)
set(additional_linker_options.MSVC.RELEASE <<additional_linker_options.MSVC.RELEASE>>)
set(additional_linker_options.CLANG.DEBUG <<additional_linker_options.CLANG.DEBUG>>)
set(additional_linker_options.CLANG.RELEASE <<additional_linker_options.CLANG.RELEASE>>)

MaxonTargets_ProcessCinemaTargetVars()

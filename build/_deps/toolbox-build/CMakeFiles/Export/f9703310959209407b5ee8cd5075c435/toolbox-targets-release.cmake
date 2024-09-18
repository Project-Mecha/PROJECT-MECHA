#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "toolbox::toolbox" for configuration "Release"
set_property(TARGET toolbox::toolbox APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(toolbox::toolbox PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/toolbox.lib"
  )

list(APPEND _cmake_import_check_targets toolbox::toolbox )
list(APPEND _cmake_import_check_files_for_toolbox::toolbox "${_IMPORT_PREFIX}/lib/toolbox.lib" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)

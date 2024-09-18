#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "bip3x::bip3x" for configuration "Release"
set_property(TARGET bip3x::bip3x APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(bip3x::bip3x PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/bip3x.lib"
  )

list(APPEND _cmake_import_check_targets bip3x::bip3x )
list(APPEND _cmake_import_check_files_for_bip3x::bip3x "${_IMPORT_PREFIX}/lib/bip3x.lib" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)

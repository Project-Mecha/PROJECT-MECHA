########### AGGREGATED COMPONENTS AND DEPENDENCIES FOR THE MULTI CONFIG #####################
#############################################################################################

set(cmake_COMPONENT_NAMES "")
if(DEFINED cmake_FIND_DEPENDENCY_NAMES)
  list(APPEND cmake_FIND_DEPENDENCY_NAMES )
  list(REMOVE_DUPLICATES cmake_FIND_DEPENDENCY_NAMES)
else()
  set(cmake_FIND_DEPENDENCY_NAMES )
endif()

########### VARIABLES #######################################################################
#############################################################################################
set(cmake_PACKAGE_FOLDER_RELEASE "C:/Users/Beyioku/.conan2/p/cmake98309fcbb52ab/p")
set(cmake_BUILD_MODULES_PATHS_RELEASE )


set(cmake_INCLUDE_DIRS_RELEASE )
set(cmake_RES_DIRS_RELEASE )
set(cmake_DEFINITIONS_RELEASE )
set(cmake_SHARED_LINK_FLAGS_RELEASE )
set(cmake_EXE_LINK_FLAGS_RELEASE )
set(cmake_OBJECTS_RELEASE )
set(cmake_COMPILE_DEFINITIONS_RELEASE )
set(cmake_COMPILE_OPTIONS_C_RELEASE )
set(cmake_COMPILE_OPTIONS_CXX_RELEASE )
set(cmake_LIB_DIRS_RELEASE )
set(cmake_BIN_DIRS_RELEASE "${cmake_PACKAGE_FOLDER_RELEASE}/bin")
set(cmake_LIBRARY_TYPE_RELEASE UNKNOWN)
set(cmake_IS_HOST_WINDOWS_RELEASE 1)
set(cmake_LIBS_RELEASE )
set(cmake_SYSTEM_LIBS_RELEASE )
set(cmake_FRAMEWORK_DIRS_RELEASE )
set(cmake_FRAMEWORKS_RELEASE )
set(cmake_BUILD_DIRS_RELEASE )
set(cmake_NO_SONAME_MODE_RELEASE FALSE)


# COMPOUND VARIABLES
set(cmake_COMPILE_OPTIONS_RELEASE
    "$<$<COMPILE_LANGUAGE:CXX>:${cmake_COMPILE_OPTIONS_CXX_RELEASE}>"
    "$<$<COMPILE_LANGUAGE:C>:${cmake_COMPILE_OPTIONS_C_RELEASE}>")
set(cmake_LINKER_FLAGS_RELEASE
    "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,SHARED_LIBRARY>:${cmake_SHARED_LINK_FLAGS_RELEASE}>"
    "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,MODULE_LIBRARY>:${cmake_SHARED_LINK_FLAGS_RELEASE}>"
    "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,EXECUTABLE>:${cmake_EXE_LINK_FLAGS_RELEASE}>")


set(cmake_COMPONENTS_RELEASE )
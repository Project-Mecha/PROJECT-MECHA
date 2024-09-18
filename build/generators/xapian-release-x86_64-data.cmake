########### AGGREGATED COMPONENTS AND DEPENDENCIES FOR THE MULTI CONFIG #####################
#############################################################################################

set(xapian-core_COMPONENT_NAMES "")
if(DEFINED xapian-core_FIND_DEPENDENCY_NAMES)
  list(APPEND xapian-core_FIND_DEPENDENCY_NAMES ZLIB)
  list(REMOVE_DUPLICATES xapian-core_FIND_DEPENDENCY_NAMES)
else()
  set(xapian-core_FIND_DEPENDENCY_NAMES ZLIB)
endif()
set(ZLIB_FIND_MODE "NO_MODULE")

########### VARIABLES #######################################################################
#############################################################################################
set(xapian-core_PACKAGE_FOLDER_RELEASE "C:/Users/Beyioku/.conan2/p/xapiab284ff9fc5d22/p")
set(xapian-core_BUILD_MODULES_PATHS_RELEASE "${xapian-core_PACKAGE_FOLDER_RELEASE}/lib/cmake/conan-official-xapian-core-variables.cmake")


set(xapian-core_INCLUDE_DIRS_RELEASE )
set(xapian-core_RES_DIRS_RELEASE "${xapian-core_PACKAGE_FOLDER_RELEASE}/res")
set(xapian-core_DEFINITIONS_RELEASE )
set(xapian-core_SHARED_LINK_FLAGS_RELEASE )
set(xapian-core_EXE_LINK_FLAGS_RELEASE )
set(xapian-core_OBJECTS_RELEASE )
set(xapian-core_COMPILE_DEFINITIONS_RELEASE )
set(xapian-core_COMPILE_OPTIONS_C_RELEASE )
set(xapian-core_COMPILE_OPTIONS_CXX_RELEASE )
set(xapian-core_LIB_DIRS_RELEASE "${xapian-core_PACKAGE_FOLDER_RELEASE}/lib")
set(xapian-core_BIN_DIRS_RELEASE )
set(xapian-core_LIBRARY_TYPE_RELEASE STATIC)
set(xapian-core_IS_HOST_WINDOWS_RELEASE 1)
set(xapian-core_LIBS_RELEASE )
set(xapian-core_SYSTEM_LIBS_RELEASE rpcrt4 ws2_32)
set(xapian-core_FRAMEWORK_DIRS_RELEASE )
set(xapian-core_FRAMEWORKS_RELEASE )
set(xapian-core_BUILD_DIRS_RELEASE )
set(xapian-core_NO_SONAME_MODE_RELEASE FALSE)


# COMPOUND VARIABLES
set(xapian-core_COMPILE_OPTIONS_RELEASE
    "$<$<COMPILE_LANGUAGE:CXX>:${xapian-core_COMPILE_OPTIONS_CXX_RELEASE}>"
    "$<$<COMPILE_LANGUAGE:C>:${xapian-core_COMPILE_OPTIONS_C_RELEASE}>")
set(xapian-core_LINKER_FLAGS_RELEASE
    "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,SHARED_LIBRARY>:${xapian-core_SHARED_LINK_FLAGS_RELEASE}>"
    "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,MODULE_LIBRARY>:${xapian-core_SHARED_LINK_FLAGS_RELEASE}>"
    "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,EXECUTABLE>:${xapian-core_EXE_LINK_FLAGS_RELEASE}>")


set(xapian-core_COMPONENTS_RELEASE )
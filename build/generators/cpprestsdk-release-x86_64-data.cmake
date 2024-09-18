########### AGGREGATED COMPONENTS AND DEPENDENCIES FOR THE MULTI CONFIG #####################
#############################################################################################

list(APPEND cpprestsdk_COMPONENT_NAMES cpprestsdk::cpprestsdk_boost_internal cpprestsdk::cpprestsdk_openssl_internal cpprestsdk::cpprestsdk_zlib_internal cpprestsdk::cpprestsdk_websocketpp_internal cpprestsdk::cpprest)
list(REMOVE_DUPLICATES cpprestsdk_COMPONENT_NAMES)
if(DEFINED cpprestsdk_FIND_DEPENDENCY_NAMES)
  list(APPEND cpprestsdk_FIND_DEPENDENCY_NAMES websocketpp Boost OpenSSL ZLIB)
  list(REMOVE_DUPLICATES cpprestsdk_FIND_DEPENDENCY_NAMES)
else()
  set(cpprestsdk_FIND_DEPENDENCY_NAMES websocketpp Boost OpenSSL ZLIB)
endif()
set(websocketpp_FIND_MODE "NO_MODULE")
set(Boost_FIND_MODE "NO_MODULE")
set(OpenSSL_FIND_MODE "NO_MODULE")
set(ZLIB_FIND_MODE "NO_MODULE")

########### VARIABLES #######################################################################
#############################################################################################
set(cpprestsdk_PACKAGE_FOLDER_RELEASE "C:/Users/Beyioku/.conan2/p/cppre69c94d4f4dab5/p")
set(cpprestsdk_BUILD_MODULES_PATHS_RELEASE )


set(cpprestsdk_INCLUDE_DIRS_RELEASE "${cpprestsdk_PACKAGE_FOLDER_RELEASE}/include")
set(cpprestsdk_RES_DIRS_RELEASE )
set(cpprestsdk_DEFINITIONS_RELEASE "-D_NO_ASYNCRTIMP"
			"-D_NO_PPLXIMP")
set(cpprestsdk_SHARED_LINK_FLAGS_RELEASE )
set(cpprestsdk_EXE_LINK_FLAGS_RELEASE )
set(cpprestsdk_OBJECTS_RELEASE )
set(cpprestsdk_COMPILE_DEFINITIONS_RELEASE "_NO_ASYNCRTIMP"
			"_NO_PPLXIMP")
set(cpprestsdk_COMPILE_OPTIONS_C_RELEASE )
set(cpprestsdk_COMPILE_OPTIONS_CXX_RELEASE )
set(cpprestsdk_LIB_DIRS_RELEASE "${cpprestsdk_PACKAGE_FOLDER_RELEASE}/lib")
set(cpprestsdk_BIN_DIRS_RELEASE )
set(cpprestsdk_LIBRARY_TYPE_RELEASE STATIC)
set(cpprestsdk_IS_HOST_WINDOWS_RELEASE 1)
set(cpprestsdk_LIBS_RELEASE cpprest143_2_10)
set(cpprestsdk_SYSTEM_LIBS_RELEASE winhttp httpapi bcrypt)
set(cpprestsdk_FRAMEWORK_DIRS_RELEASE )
set(cpprestsdk_FRAMEWORKS_RELEASE )
set(cpprestsdk_BUILD_DIRS_RELEASE )
set(cpprestsdk_NO_SONAME_MODE_RELEASE FALSE)


# COMPOUND VARIABLES
set(cpprestsdk_COMPILE_OPTIONS_RELEASE
    "$<$<COMPILE_LANGUAGE:CXX>:${cpprestsdk_COMPILE_OPTIONS_CXX_RELEASE}>"
    "$<$<COMPILE_LANGUAGE:C>:${cpprestsdk_COMPILE_OPTIONS_C_RELEASE}>")
set(cpprestsdk_LINKER_FLAGS_RELEASE
    "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,SHARED_LIBRARY>:${cpprestsdk_SHARED_LINK_FLAGS_RELEASE}>"
    "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,MODULE_LIBRARY>:${cpprestsdk_SHARED_LINK_FLAGS_RELEASE}>"
    "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,EXECUTABLE>:${cpprestsdk_EXE_LINK_FLAGS_RELEASE}>")


set(cpprestsdk_COMPONENTS_RELEASE cpprestsdk::cpprestsdk_boost_internal cpprestsdk::cpprestsdk_openssl_internal cpprestsdk::cpprestsdk_zlib_internal cpprestsdk::cpprestsdk_websocketpp_internal cpprestsdk::cpprest)
########### COMPONENT cpprestsdk::cpprest VARIABLES ############################################

set(cpprestsdk_cpprestsdk_cpprest_INCLUDE_DIRS_RELEASE "${cpprestsdk_PACKAGE_FOLDER_RELEASE}/include")
set(cpprestsdk_cpprestsdk_cpprest_LIB_DIRS_RELEASE "${cpprestsdk_PACKAGE_FOLDER_RELEASE}/lib")
set(cpprestsdk_cpprestsdk_cpprest_BIN_DIRS_RELEASE )
set(cpprestsdk_cpprestsdk_cpprest_LIBRARY_TYPE_RELEASE STATIC)
set(cpprestsdk_cpprestsdk_cpprest_IS_HOST_WINDOWS_RELEASE 1)
set(cpprestsdk_cpprestsdk_cpprest_RES_DIRS_RELEASE )
set(cpprestsdk_cpprestsdk_cpprest_DEFINITIONS_RELEASE "-D_NO_ASYNCRTIMP"
			"-D_NO_PPLXIMP")
set(cpprestsdk_cpprestsdk_cpprest_OBJECTS_RELEASE )
set(cpprestsdk_cpprestsdk_cpprest_COMPILE_DEFINITIONS_RELEASE "_NO_ASYNCRTIMP"
			"_NO_PPLXIMP")
set(cpprestsdk_cpprestsdk_cpprest_COMPILE_OPTIONS_C_RELEASE "")
set(cpprestsdk_cpprestsdk_cpprest_COMPILE_OPTIONS_CXX_RELEASE "")
set(cpprestsdk_cpprestsdk_cpprest_LIBS_RELEASE cpprest143_2_10)
set(cpprestsdk_cpprestsdk_cpprest_SYSTEM_LIBS_RELEASE winhttp httpapi bcrypt)
set(cpprestsdk_cpprestsdk_cpprest_FRAMEWORK_DIRS_RELEASE )
set(cpprestsdk_cpprestsdk_cpprest_FRAMEWORKS_RELEASE )
set(cpprestsdk_cpprestsdk_cpprest_DEPENDENCIES_RELEASE cpprestsdk::cpprestsdk_boost_internal cpprestsdk::cpprestsdk_openssl_internal cpprestsdk::cpprestsdk_zlib_internal cpprestsdk::cpprestsdk_websocketpp_internal)
set(cpprestsdk_cpprestsdk_cpprest_SHARED_LINK_FLAGS_RELEASE )
set(cpprestsdk_cpprestsdk_cpprest_EXE_LINK_FLAGS_RELEASE )
set(cpprestsdk_cpprestsdk_cpprest_NO_SONAME_MODE_RELEASE FALSE)

# COMPOUND VARIABLES
set(cpprestsdk_cpprestsdk_cpprest_LINKER_FLAGS_RELEASE
        $<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,SHARED_LIBRARY>:${cpprestsdk_cpprestsdk_cpprest_SHARED_LINK_FLAGS_RELEASE}>
        $<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,MODULE_LIBRARY>:${cpprestsdk_cpprestsdk_cpprest_SHARED_LINK_FLAGS_RELEASE}>
        $<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,EXECUTABLE>:${cpprestsdk_cpprestsdk_cpprest_EXE_LINK_FLAGS_RELEASE}>
)
set(cpprestsdk_cpprestsdk_cpprest_COMPILE_OPTIONS_RELEASE
    "$<$<COMPILE_LANGUAGE:CXX>:${cpprestsdk_cpprestsdk_cpprest_COMPILE_OPTIONS_CXX_RELEASE}>"
    "$<$<COMPILE_LANGUAGE:C>:${cpprestsdk_cpprestsdk_cpprest_COMPILE_OPTIONS_C_RELEASE}>")
########### COMPONENT cpprestsdk::cpprestsdk_websocketpp_internal VARIABLES ############################################

set(cpprestsdk_cpprestsdk_cpprestsdk_websocketpp_internal_INCLUDE_DIRS_RELEASE )
set(cpprestsdk_cpprestsdk_cpprestsdk_websocketpp_internal_LIB_DIRS_RELEASE "${cpprestsdk_PACKAGE_FOLDER_RELEASE}/lib")
set(cpprestsdk_cpprestsdk_cpprestsdk_websocketpp_internal_BIN_DIRS_RELEASE )
set(cpprestsdk_cpprestsdk_cpprestsdk_websocketpp_internal_LIBRARY_TYPE_RELEASE STATIC)
set(cpprestsdk_cpprestsdk_cpprestsdk_websocketpp_internal_IS_HOST_WINDOWS_RELEASE 1)
set(cpprestsdk_cpprestsdk_cpprestsdk_websocketpp_internal_RES_DIRS_RELEASE )
set(cpprestsdk_cpprestsdk_cpprestsdk_websocketpp_internal_DEFINITIONS_RELEASE )
set(cpprestsdk_cpprestsdk_cpprestsdk_websocketpp_internal_OBJECTS_RELEASE )
set(cpprestsdk_cpprestsdk_cpprestsdk_websocketpp_internal_COMPILE_DEFINITIONS_RELEASE )
set(cpprestsdk_cpprestsdk_cpprestsdk_websocketpp_internal_COMPILE_OPTIONS_C_RELEASE "")
set(cpprestsdk_cpprestsdk_cpprestsdk_websocketpp_internal_COMPILE_OPTIONS_CXX_RELEASE "")
set(cpprestsdk_cpprestsdk_cpprestsdk_websocketpp_internal_LIBS_RELEASE )
set(cpprestsdk_cpprestsdk_cpprestsdk_websocketpp_internal_SYSTEM_LIBS_RELEASE )
set(cpprestsdk_cpprestsdk_cpprestsdk_websocketpp_internal_FRAMEWORK_DIRS_RELEASE )
set(cpprestsdk_cpprestsdk_cpprestsdk_websocketpp_internal_FRAMEWORKS_RELEASE )
set(cpprestsdk_cpprestsdk_cpprestsdk_websocketpp_internal_DEPENDENCIES_RELEASE websocketpp::websocketpp)
set(cpprestsdk_cpprestsdk_cpprestsdk_websocketpp_internal_SHARED_LINK_FLAGS_RELEASE )
set(cpprestsdk_cpprestsdk_cpprestsdk_websocketpp_internal_EXE_LINK_FLAGS_RELEASE )
set(cpprestsdk_cpprestsdk_cpprestsdk_websocketpp_internal_NO_SONAME_MODE_RELEASE FALSE)

# COMPOUND VARIABLES
set(cpprestsdk_cpprestsdk_cpprestsdk_websocketpp_internal_LINKER_FLAGS_RELEASE
        $<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,SHARED_LIBRARY>:${cpprestsdk_cpprestsdk_cpprestsdk_websocketpp_internal_SHARED_LINK_FLAGS_RELEASE}>
        $<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,MODULE_LIBRARY>:${cpprestsdk_cpprestsdk_cpprestsdk_websocketpp_internal_SHARED_LINK_FLAGS_RELEASE}>
        $<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,EXECUTABLE>:${cpprestsdk_cpprestsdk_cpprestsdk_websocketpp_internal_EXE_LINK_FLAGS_RELEASE}>
)
set(cpprestsdk_cpprestsdk_cpprestsdk_websocketpp_internal_COMPILE_OPTIONS_RELEASE
    "$<$<COMPILE_LANGUAGE:CXX>:${cpprestsdk_cpprestsdk_cpprestsdk_websocketpp_internal_COMPILE_OPTIONS_CXX_RELEASE}>"
    "$<$<COMPILE_LANGUAGE:C>:${cpprestsdk_cpprestsdk_cpprestsdk_websocketpp_internal_COMPILE_OPTIONS_C_RELEASE}>")
########### COMPONENT cpprestsdk::cpprestsdk_zlib_internal VARIABLES ############################################

set(cpprestsdk_cpprestsdk_cpprestsdk_zlib_internal_INCLUDE_DIRS_RELEASE )
set(cpprestsdk_cpprestsdk_cpprestsdk_zlib_internal_LIB_DIRS_RELEASE "${cpprestsdk_PACKAGE_FOLDER_RELEASE}/lib")
set(cpprestsdk_cpprestsdk_cpprestsdk_zlib_internal_BIN_DIRS_RELEASE )
set(cpprestsdk_cpprestsdk_cpprestsdk_zlib_internal_LIBRARY_TYPE_RELEASE STATIC)
set(cpprestsdk_cpprestsdk_cpprestsdk_zlib_internal_IS_HOST_WINDOWS_RELEASE 1)
set(cpprestsdk_cpprestsdk_cpprestsdk_zlib_internal_RES_DIRS_RELEASE )
set(cpprestsdk_cpprestsdk_cpprestsdk_zlib_internal_DEFINITIONS_RELEASE )
set(cpprestsdk_cpprestsdk_cpprestsdk_zlib_internal_OBJECTS_RELEASE )
set(cpprestsdk_cpprestsdk_cpprestsdk_zlib_internal_COMPILE_DEFINITIONS_RELEASE )
set(cpprestsdk_cpprestsdk_cpprestsdk_zlib_internal_COMPILE_OPTIONS_C_RELEASE "")
set(cpprestsdk_cpprestsdk_cpprestsdk_zlib_internal_COMPILE_OPTIONS_CXX_RELEASE "")
set(cpprestsdk_cpprestsdk_cpprestsdk_zlib_internal_LIBS_RELEASE )
set(cpprestsdk_cpprestsdk_cpprestsdk_zlib_internal_SYSTEM_LIBS_RELEASE )
set(cpprestsdk_cpprestsdk_cpprestsdk_zlib_internal_FRAMEWORK_DIRS_RELEASE )
set(cpprestsdk_cpprestsdk_cpprestsdk_zlib_internal_FRAMEWORKS_RELEASE )
set(cpprestsdk_cpprestsdk_cpprestsdk_zlib_internal_DEPENDENCIES_RELEASE ZLIB::ZLIB)
set(cpprestsdk_cpprestsdk_cpprestsdk_zlib_internal_SHARED_LINK_FLAGS_RELEASE )
set(cpprestsdk_cpprestsdk_cpprestsdk_zlib_internal_EXE_LINK_FLAGS_RELEASE )
set(cpprestsdk_cpprestsdk_cpprestsdk_zlib_internal_NO_SONAME_MODE_RELEASE FALSE)

# COMPOUND VARIABLES
set(cpprestsdk_cpprestsdk_cpprestsdk_zlib_internal_LINKER_FLAGS_RELEASE
        $<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,SHARED_LIBRARY>:${cpprestsdk_cpprestsdk_cpprestsdk_zlib_internal_SHARED_LINK_FLAGS_RELEASE}>
        $<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,MODULE_LIBRARY>:${cpprestsdk_cpprestsdk_cpprestsdk_zlib_internal_SHARED_LINK_FLAGS_RELEASE}>
        $<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,EXECUTABLE>:${cpprestsdk_cpprestsdk_cpprestsdk_zlib_internal_EXE_LINK_FLAGS_RELEASE}>
)
set(cpprestsdk_cpprestsdk_cpprestsdk_zlib_internal_COMPILE_OPTIONS_RELEASE
    "$<$<COMPILE_LANGUAGE:CXX>:${cpprestsdk_cpprestsdk_cpprestsdk_zlib_internal_COMPILE_OPTIONS_CXX_RELEASE}>"
    "$<$<COMPILE_LANGUAGE:C>:${cpprestsdk_cpprestsdk_cpprestsdk_zlib_internal_COMPILE_OPTIONS_C_RELEASE}>")
########### COMPONENT cpprestsdk::cpprestsdk_openssl_internal VARIABLES ############################################

set(cpprestsdk_cpprestsdk_cpprestsdk_openssl_internal_INCLUDE_DIRS_RELEASE )
set(cpprestsdk_cpprestsdk_cpprestsdk_openssl_internal_LIB_DIRS_RELEASE "${cpprestsdk_PACKAGE_FOLDER_RELEASE}/lib")
set(cpprestsdk_cpprestsdk_cpprestsdk_openssl_internal_BIN_DIRS_RELEASE )
set(cpprestsdk_cpprestsdk_cpprestsdk_openssl_internal_LIBRARY_TYPE_RELEASE STATIC)
set(cpprestsdk_cpprestsdk_cpprestsdk_openssl_internal_IS_HOST_WINDOWS_RELEASE 1)
set(cpprestsdk_cpprestsdk_cpprestsdk_openssl_internal_RES_DIRS_RELEASE )
set(cpprestsdk_cpprestsdk_cpprestsdk_openssl_internal_DEFINITIONS_RELEASE )
set(cpprestsdk_cpprestsdk_cpprestsdk_openssl_internal_OBJECTS_RELEASE )
set(cpprestsdk_cpprestsdk_cpprestsdk_openssl_internal_COMPILE_DEFINITIONS_RELEASE )
set(cpprestsdk_cpprestsdk_cpprestsdk_openssl_internal_COMPILE_OPTIONS_C_RELEASE "")
set(cpprestsdk_cpprestsdk_cpprestsdk_openssl_internal_COMPILE_OPTIONS_CXX_RELEASE "")
set(cpprestsdk_cpprestsdk_cpprestsdk_openssl_internal_LIBS_RELEASE )
set(cpprestsdk_cpprestsdk_cpprestsdk_openssl_internal_SYSTEM_LIBS_RELEASE )
set(cpprestsdk_cpprestsdk_cpprestsdk_openssl_internal_FRAMEWORK_DIRS_RELEASE )
set(cpprestsdk_cpprestsdk_cpprestsdk_openssl_internal_FRAMEWORKS_RELEASE )
set(cpprestsdk_cpprestsdk_cpprestsdk_openssl_internal_DEPENDENCIES_RELEASE openssl::openssl)
set(cpprestsdk_cpprestsdk_cpprestsdk_openssl_internal_SHARED_LINK_FLAGS_RELEASE )
set(cpprestsdk_cpprestsdk_cpprestsdk_openssl_internal_EXE_LINK_FLAGS_RELEASE )
set(cpprestsdk_cpprestsdk_cpprestsdk_openssl_internal_NO_SONAME_MODE_RELEASE FALSE)

# COMPOUND VARIABLES
set(cpprestsdk_cpprestsdk_cpprestsdk_openssl_internal_LINKER_FLAGS_RELEASE
        $<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,SHARED_LIBRARY>:${cpprestsdk_cpprestsdk_cpprestsdk_openssl_internal_SHARED_LINK_FLAGS_RELEASE}>
        $<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,MODULE_LIBRARY>:${cpprestsdk_cpprestsdk_cpprestsdk_openssl_internal_SHARED_LINK_FLAGS_RELEASE}>
        $<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,EXECUTABLE>:${cpprestsdk_cpprestsdk_cpprestsdk_openssl_internal_EXE_LINK_FLAGS_RELEASE}>
)
set(cpprestsdk_cpprestsdk_cpprestsdk_openssl_internal_COMPILE_OPTIONS_RELEASE
    "$<$<COMPILE_LANGUAGE:CXX>:${cpprestsdk_cpprestsdk_cpprestsdk_openssl_internal_COMPILE_OPTIONS_CXX_RELEASE}>"
    "$<$<COMPILE_LANGUAGE:C>:${cpprestsdk_cpprestsdk_cpprestsdk_openssl_internal_COMPILE_OPTIONS_C_RELEASE}>")
########### COMPONENT cpprestsdk::cpprestsdk_boost_internal VARIABLES ############################################

set(cpprestsdk_cpprestsdk_cpprestsdk_boost_internal_INCLUDE_DIRS_RELEASE )
set(cpprestsdk_cpprestsdk_cpprestsdk_boost_internal_LIB_DIRS_RELEASE "${cpprestsdk_PACKAGE_FOLDER_RELEASE}/lib")
set(cpprestsdk_cpprestsdk_cpprestsdk_boost_internal_BIN_DIRS_RELEASE )
set(cpprestsdk_cpprestsdk_cpprestsdk_boost_internal_LIBRARY_TYPE_RELEASE STATIC)
set(cpprestsdk_cpprestsdk_cpprestsdk_boost_internal_IS_HOST_WINDOWS_RELEASE 1)
set(cpprestsdk_cpprestsdk_cpprestsdk_boost_internal_RES_DIRS_RELEASE )
set(cpprestsdk_cpprestsdk_cpprestsdk_boost_internal_DEFINITIONS_RELEASE )
set(cpprestsdk_cpprestsdk_cpprestsdk_boost_internal_OBJECTS_RELEASE )
set(cpprestsdk_cpprestsdk_cpprestsdk_boost_internal_COMPILE_DEFINITIONS_RELEASE )
set(cpprestsdk_cpprestsdk_cpprestsdk_boost_internal_COMPILE_OPTIONS_C_RELEASE "")
set(cpprestsdk_cpprestsdk_cpprestsdk_boost_internal_COMPILE_OPTIONS_CXX_RELEASE "")
set(cpprestsdk_cpprestsdk_cpprestsdk_boost_internal_LIBS_RELEASE )
set(cpprestsdk_cpprestsdk_cpprestsdk_boost_internal_SYSTEM_LIBS_RELEASE )
set(cpprestsdk_cpprestsdk_cpprestsdk_boost_internal_FRAMEWORK_DIRS_RELEASE )
set(cpprestsdk_cpprestsdk_cpprestsdk_boost_internal_FRAMEWORKS_RELEASE )
set(cpprestsdk_cpprestsdk_cpprestsdk_boost_internal_DEPENDENCIES_RELEASE Boost::headers Boost::system Boost::date_time Boost::regex)
set(cpprestsdk_cpprestsdk_cpprestsdk_boost_internal_SHARED_LINK_FLAGS_RELEASE )
set(cpprestsdk_cpprestsdk_cpprestsdk_boost_internal_EXE_LINK_FLAGS_RELEASE )
set(cpprestsdk_cpprestsdk_cpprestsdk_boost_internal_NO_SONAME_MODE_RELEASE FALSE)

# COMPOUND VARIABLES
set(cpprestsdk_cpprestsdk_cpprestsdk_boost_internal_LINKER_FLAGS_RELEASE
        $<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,SHARED_LIBRARY>:${cpprestsdk_cpprestsdk_cpprestsdk_boost_internal_SHARED_LINK_FLAGS_RELEASE}>
        $<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,MODULE_LIBRARY>:${cpprestsdk_cpprestsdk_cpprestsdk_boost_internal_SHARED_LINK_FLAGS_RELEASE}>
        $<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,EXECUTABLE>:${cpprestsdk_cpprestsdk_cpprestsdk_boost_internal_EXE_LINK_FLAGS_RELEASE}>
)
set(cpprestsdk_cpprestsdk_cpprestsdk_boost_internal_COMPILE_OPTIONS_RELEASE
    "$<$<COMPILE_LANGUAGE:CXX>:${cpprestsdk_cpprestsdk_cpprestsdk_boost_internal_COMPILE_OPTIONS_CXX_RELEASE}>"
    "$<$<COMPILE_LANGUAGE:C>:${cpprestsdk_cpprestsdk_cpprestsdk_boost_internal_COMPILE_OPTIONS_C_RELEASE}>")
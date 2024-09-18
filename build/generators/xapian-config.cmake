########## MACROS ###########################################################################
#############################################################################################

# Requires CMake > 3.15
if(${CMAKE_VERSION} VERSION_LESS "3.15")
    message(FATAL_ERROR "The 'CMakeDeps' generator only works with CMake >= 3.15")
endif()

if(xapian_FIND_QUIETLY)
    set(xapian_MESSAGE_MODE VERBOSE)
else()
    set(xapian_MESSAGE_MODE STATUS)
endif()

include(${CMAKE_CURRENT_LIST_DIR}/cmakedeps_macros.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/xapianTargets.cmake)
include(CMakeFindDependencyMacro)

check_build_type_defined()

foreach(_DEPENDENCY ${xapian-core_FIND_DEPENDENCY_NAMES} )
    # Check that we have not already called a find_package with the transitive dependency
    if(NOT ${_DEPENDENCY}_FOUND)
        find_dependency(${_DEPENDENCY} REQUIRED ${${_DEPENDENCY}_FIND_MODE})
    endif()
endforeach()

set(xapian_VERSION_STRING "1.4.19")
set(xapian_INCLUDE_DIRS ${xapian-core_INCLUDE_DIRS_RELEASE} )
set(xapian_INCLUDE_DIR ${xapian-core_INCLUDE_DIRS_RELEASE} )
set(xapian_LIBRARIES ${xapian-core_LIBRARIES_RELEASE} )
set(xapian_DEFINITIONS ${xapian-core_DEFINITIONS_RELEASE} )


# Only the last installed configuration BUILD_MODULES are included to avoid the collision
foreach(_BUILD_MODULE ${xapian-core_BUILD_MODULES_PATHS_RELEASE} )
    message(${xapian_MESSAGE_MODE} "Conan: Including build module from '${_BUILD_MODULE}'")
    include(${_BUILD_MODULE})
endforeach()



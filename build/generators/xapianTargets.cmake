# Load the debug and release variables
file(GLOB DATA_FILES "${CMAKE_CURRENT_LIST_DIR}/xapian-*-data.cmake")

foreach(f ${DATA_FILES})
    include(${f})
endforeach()

# Create the targets for all the components
foreach(_COMPONENT ${xapian-core_COMPONENT_NAMES} )
    if(NOT TARGET ${_COMPONENT})
        add_library(${_COMPONENT} INTERFACE IMPORTED)
        message(${xapian_MESSAGE_MODE} "Conan: Component target declared '${_COMPONENT}'")
    endif()
endforeach()

if(NOT TARGET xapian-core::xapian-core)
    add_library(xapian-core::xapian-core INTERFACE IMPORTED)
    message(${xapian_MESSAGE_MODE} "Conan: Target declared 'xapian-core::xapian-core'")
endif()
# Load the debug and release library finders
file(GLOB CONFIG_FILES "${CMAKE_CURRENT_LIST_DIR}/xapian-Target-*.cmake")

foreach(f ${CONFIG_FILES})
    include(${f})
endforeach()
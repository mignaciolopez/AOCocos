cmake_minimum_required(VERSION 3.6)

set(lib_name SLikeNet-v.0.1.3)
set(target_name ext_${lib_name})

project(${lib_name})

include(../cmake/CocosExternalConfig.cmake)

add_library(${target_name} STATIC IMPORTED GLOBAL)

set_target_properties(${target_name} PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_CURRENT_SOURCE_DIR}/include"
)
if(WINDOWS)
  set_target_properties(${target_name} PROPERTIES
    IMPORTED_LOCATION_DEBUG "${platform_spec_path}/debug/${lib_name}.lib"
    IMPORTED_LOCATION_RELEASE "${platform_spec_path}/release/${lib_name}.lib"
  )
else()
  set_target_properties(${target_name} PROPERTIES
    IMPORTED_LOCATION "${platform_spec_path}/${lib_name}.a"
  )
endif()
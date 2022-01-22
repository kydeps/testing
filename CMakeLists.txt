cmake_minimum_required(VERSION 3.20)
project(external_package_experiment)

# execute_process(COMMAND ${CMAKE_CXX_COMPILER} -dumpmachine
#                 OUTPUT_VARIABLE KYDEPS_TRIPLET)

# message(STATUS ">>> " ${CMAKE_SYSTEM})
# message(STATUS ">>> " ${KYDEPS_TRIPLET})
# message(STATUS ">>> " ${CMAKE_SYSTEM_NAME})
# message(STATUS ">>> " ${CMAKE_SIZEOF_VOID_P})

# message(STATUS "print_all_variables------------------------------------------{")
# get_cmake_property(_variableNames VARIABLES)
# foreach (_variableName ${_variableNames})
#     message(STATUS "${_variableName}=${${_variableName}}")
# endforeach()
# message(STATUS "print_all_variables------------------------------------------}")

# set(KYDEPS_CACHE_BUCKET "https://kydeps.nyc3.digitaloceanspaces.com")
# include(FetchContent) FetchContent_Declare(packages URL
# ${KYDEPS_CACHE_BUCKET}/packages.zip URL_HASH
# SHA256=9e91a6d3ddc99c8a87ec25fbc2e6d36d200ce23de85da866ff176bd6e7076177 )
# FetchContent_MakeAvailable(packages) set(KYDEPS_CACHE_REGISTRY_DIR
# "${packages_SOURCE_DIR}")

set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

set(KYDEPS_TARGETS gflags glog GTest)

# modes: - mode-inline - mode-fetch
#
if("${KYDEPS_MODE}" STREQUAL "")
    set(KYDEPS_MODE "mode-inline")
endif()

add_subdirectory(${KYDEPS_MODE})

find_package(gflags REQUIRED CONFIG)
find_package(glog REQUIRED CONFIG)
find_package(GTest REQUIRED CONFIG)

add_executable(tests test.cc)
target_link_libraries(
    tests
    PRIVATE gflags
    PRIVATE glog::glog
    PRIVATE GTest::gtest
    PRIVATE GTest::gtest_main)

include(CTest)
include(GoogleTest)
gtest_discover_tests(tests)

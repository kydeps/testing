cmake_minimum_required(VERSION 3.20)
project(external_package_experiment)

set(KYDEPS_TARGETS gflags glog GTest)

# modes:
# - mode-inline
# - mode-fetch
#
if("${KYDEPS_MODE}" STREQUAL "")
    set(KYDEPS_MODE "mode-inline")    
endif()

add_subdirectory(${KYDEPS_MODE})

find_package(gflags REQUIRED CONFIG)
find_package(glog REQUIRED CONFIG)
find_package(GTest REQUIRED CONFIG)

add_executable(tests test.cc)
target_link_libraries(tests
    PRIVATE gflags
    PRIVATE glog::glog
    PRIVATE GTest::gtest
    PRIVATE GTest::gtest_main
)

include(CTest)
include(GoogleTest)
gtest_discover_tests(tests)

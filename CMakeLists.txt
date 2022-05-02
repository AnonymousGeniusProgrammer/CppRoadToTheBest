CMAKE_MINIMUM_REQUIRED(VERSION 3.15 FATAL_ERROR)

Project("CppRoadToTheBest")

include(CMakePrintHelpers)

SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin" CACHE PATH "Runtime directory" FORCE)

set(RW_BUILD_WITH_LIBRARIES "yaobi;pqp;fcl;sdurw_qhull;sdurw_csgjs;sdurw_assimp;sdurw_zlib;sdurw_unzip;sdurw_algorithms;sdurw_pathplanners;sdurw_pathoptimization;sdurw_simulation;sdurw_opengl;sdurw_assembly;sdurw_task;sdurw_calibration;sdurw_csg;sdurw_control;sdurw_proximitystrategies;sdurw;sdurw_core;sdurw_common;sdurw_math")

set(RW_BUILD_WITH_LIB_DEPEND "opengl32;glu32;C:/Dev/Framework/RobWork/Install/RW/Debug/lib/xerces-c_3D.lib;optimized;C:/Dev/Libs/boost_1_74_0/lib64-msvc-14.2/libboost_filesystem-vc142-mt-x64-1_74.lib;debug;C:/Dev/Libs/boost_1_74_0/lib64-msvc-14.2/libboost_filesystem-vc142-mt-gd-x64-1_74.lib;optimized;C:/Dev/Libs/boost_1_74_0/lib64-msvc-14.2/libboost_regex-vc142-mt-x64-1_74.lib;debug;C:/Dev/Libs/boost_1_74_0/lib64-msvc-14.2/libboost_regex-vc142-mt-gd-x64-1_74.lib;optimized;C:/Dev/Libs/boost_1_74_0/lib64-msvc-14.2/libboost_serialization-vc142-mt-x64-1_74.lib;debug;C:/Dev/Libs/boost_1_74_0/lib64-msvc-14.2/libboost_serialization-vc142-mt-gd-x64-1_74.lib;optimized;C:/Dev/Libs/boost_1_74_0/lib64-msvc-14.2/libboost_system-vc142-mt-x64-1_74.lib;debug;C:/Dev/Libs/boost_1_74_0/lib64-msvc-14.2/libboost_system-vc142-mt-gd-x64-1_74.lib;optimized;C:/Dev/Libs/boost_1_74_0/lib64-msvc-14.2/libboost_thread-vc142-mt-x64-1_74.lib;debug;C:/Dev/Libs/boost_1_74_0/lib64-msvc-14.2/libboost_thread-vc142-mt-gd-x64-1_74.lib;optimized;C:/Dev/Libs/boost_1_74_0/lib64-msvc-14.2/libboost_program_options-vc142-mt-x64-1_74.lib;debug;C:/Dev/Libs/boost_1_74_0/lib64-msvc-14.2/libboost_program_options-vc142-mt-gd-x64-1_74.lib;optimized;C:/Dev/Libs/boost_1_74_0/lib64-msvc-14.2/libboost_chrono-vc142-mt-x64-1_74.lib;debug;C:/Dev/Libs/boost_1_74_0/lib64-msvc-14.2/libboost_chrono-vc142-mt-gd-x64-1_74.lib;optimized;C:/Dev/Libs/boost_1_74_0/lib64-msvc-14.2/libboost_date_time-vc142-mt-x64-1_74.lib;debug;C:/Dev/Libs/boost_1_74_0/lib64-msvc-14.2/libboost_date_time-vc142-mt-gd-x64-1_74.lib;optimized;C:/Dev/Libs/boost_1_74_0/lib64-msvc-14.2/libboost_atomic-vc142-mt-x64-1_74.lib;debug;C:/Dev/Libs/boost_1_74_0/lib64-msvc-14.2/libboost_atomic-vc142-mt-gd-x64-1_74.lib;optimized;C:/Dev/Libs/boost_1_74_0/lib64-msvc-14.2/libboost_test_exec_monitor-vc142-mt-x64-1_74.lib;debug;C:/Dev/Libs/boost_1_74_0/lib64-msvc-14.2/libboost_test_exec_monitor-vc142-mt-gd-x64-1_74.lib;optimized;C:/Dev/Libs/boost_1_74_0/lib64-msvc-14.2/libboost_unit_test_framework-vc142-mt-x64-1_74.lib;debug;C:/Dev/Libs/boost_1_74_0/lib64-msvc-14.2/libboost_unit_test_framework-vc142-mt-gd-x64-1_74.lib;optimized;C:/Dev/Libs/boost_1_74_0/lib64-msvc-14.2/libboost_test_exec_monitor-vc142-mt-x64-1_74.lib;debug;C:/Dev/Libs/boost_1_74_0/lib64-msvc-14.2/libboost_test_exec_monitor-vc142-mt-gd-x64-1_74.lib;optimized;C:/Dev/Libs/boost_1_74_0/lib64-msvc-14.2/libboost_unit_test_framework-vc142-mt-x64-1_74.lib;debug;C:/Dev/Libs/boost_1_74_0/lib64-msvc-14.2/libboost_unit_test_framework-vc142-mt-gd-x64-1_74.lib")

# Parse RW_BUILD_WITH_LIBRARIES
string(REGEX MATCHALL "([^\ ]+\ |[^\ ]+$)" RW_LIBRARIES_LIST "${RW_BUILD_WITH_LIBRARIES}")
string(REGEX MATCHALL "([^\ ]+\ |[^\ ]+$)" RW_DEPEND_LIBRARIES_LIST "${RW_BUILD_WITH_LIB_DEPEND}")

set(RW_LIB_ROOT "C/Dev/Robwork/Robwork/libs/Debug")

set(ROBWORK_LIBRARIES)
foreach(lib ${RW_LIBRARIES_LIST})
    set(l "${RW_LIB_ROOT}/${lib}.lib")    
    list(APPEND ROBWORK_LIBRARIES ${l})
    # cmake_print_variables(l)
endforeach()

foreach(lib ${RW_DEPEND_LIBRARIES_LIST})
    list(APPEND ROBWORK_LIBRARIES ${lib})    
    # cmake_print_variables(lib)
endforeach()

message(STATUS ${ROBWORK_LIBRARIES})

add_subdirectory(src)
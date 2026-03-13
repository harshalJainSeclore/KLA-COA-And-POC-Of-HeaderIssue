cmake_minimum_required(VERSION 3.20)

project(SetupHelper LANGUAGES CXX)

add_executable(SetupHelper SetupHelper.cpp)

target_compile_features(SetupHelper PRIVATE cxx_std_17)

set_target_properties(
    SetupHelper
    PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/build"
        RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_SOURCE_DIR}/build"
        RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_SOURCE_DIR}/build"
        RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO "${CMAKE_SOURCE_DIR}/build"
        RUNTIME_OUTPUT_DIRECTORY_MINSIZEREL "${CMAKE_SOURCE_DIR}/build"
)

set_target_properties(
    SetupHelper
    PROPERTIES
        CXX_EXTENSIONS OFF
)

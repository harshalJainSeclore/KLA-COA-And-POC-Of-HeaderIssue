cmake_minimum_required(VERSION 3.20)

project(SetupHelper LANGUAGES CXX)

add_executable(SetupHelper SetupHelper.cpp)

if(WIN32)
    target_link_libraries(SetupHelper PRIVATE user32)
endif()

# MSVC: emit a Program Database (.pdb). The VS generator usually writes the linker PDB
# under the CMake binary dir (e.g. out/Release/) while the exe is staged to source/build/;
# copy the PDB to build/ so CI and packaging see build/SetupHelper.exe + SetupHelper.pdb.
if(MSVC)
    target_compile_options(SetupHelper PRIVATE /Zi)
    target_link_options(SetupHelper PRIVATE /DEBUG:FULL)
    set(_setuphelper_stage_dir "${CMAKE_SOURCE_DIR}/build")
    add_custom_command(
        TARGET SetupHelper
        POST_BUILD
        COMMAND "${CMAKE_COMMAND}" -E copy_if_different
                "$<TARGET_PDB_FILE:SetupHelper>"
                "${_setuphelper_stage_dir}/SetupHelper.pdb"
        COMMENT "Staging SetupHelper.pdb next to staged exe (build/)"
    )
endif()

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

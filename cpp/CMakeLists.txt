cmake_minimum_required (VERSION 3.16)
set(CMAKE_CXX_STANDARD 17)

project(design_pattern)

set(EXECUTABLE_OUTPUT_PATH .)
set(MY_LIBS pthread)

include_directories(creational_patterns)
include_directories(structural_patterns)
include_directories(behavioral_patterns)

aux_source_directory(. DIR_SRCS)
add_executable(${PROJECT_NAME} ${DIR_SRCS})
target_link_libraries(${PROJECT_NAME}  ${MY_LIBS})
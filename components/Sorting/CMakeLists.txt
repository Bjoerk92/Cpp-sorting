cmake_minimum_required(VERSION 3.20)


add_library(Sorting INTERFACE)

target_include_directories(Sorting
INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}
)
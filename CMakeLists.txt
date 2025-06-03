cmake_minimum_required(VERSION 3.10)

project(Banksystem)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE SOURCE_FILES "${CMAKE_SOURCE_DIR}/source/*.cpp")
list(REMOVE_ITEM SOURCE_FILES "${CMAKE_SOURCE_DIR}/source/main.cpp")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

add_subdirectory(external/json)
add_subdirectory(test)
add_subdirectory(source)


set(DATA_PATH "${CMAKE_SOURCE_DIR}/data/data.json")

target_compile_definitions(Banksystem PRIVATE DATA_PATH=\"${DATA_PATH}\")
target_compile_definitions(Test PRIVATE DATA_PATH=\"${DATA_PATH}\")

cmake_minimum_required(VERSION 3.10)

project(Banksystem)

set(CMAKE_CXX_STANDARD 17)

file(GLOB SOURCE_FILES "${CMAKE_SOURCE_DIR}/source/*.cpp")

include_directories(include external/json/include)

add_executable(Banksystem ${SOURCE_FILES})


set(DATA_PATH "${CMAKE_SOURCE_DIR}/data/data.json")

target_compile_definitions(Banksystem PRIVATE DATA_PATH=\"${DATA_PATH}\")

install(TARGETS Banksystem DESTINATION ${CMAKE_SOURCE_DIR}/bin)


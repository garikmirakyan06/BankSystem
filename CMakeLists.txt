cmake_minimum_required(VERSION 3.10)

project(Banksystem)

set(CMAKE_CXX_STANDARD 17)

include_directories(include external/json/include)

add_executable(Banksystem src/main.cpp src/Account.cpp src/Bank.cpp src/Menu.cpp src/file_functions.cpp)


set(DATA_PATH "${CMAKE_SOURCE_DIR}/data/data.json")
target_compile_definitions(Banksystem PRIVATE DATA_PATH=\"${DATA_PATH}\")

install(TARGETS Banksystem DESTINATION ${CMAKE_SOURCE_DIR}/bin)


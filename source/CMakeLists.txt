cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)

add_executable(Banksystem main.cpp ${SOURCE_FILES})


target_include_directories(Banksystem PUBLIC ${CMAKE_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/include/Screens)
target_include_directories(Banksystem PUBLIC ${CMAKE_SOURCE_DIR}/external/json/include)




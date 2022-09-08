cmake_minimum_required(VERSION 3.0.0)

project(tv_demos)

find_package(tvision CONFIG)

add_executable(demo TFileContent.cpp TInterior.cpp TDemoWindow.cpp main.cpp)

target_include_directories(demo PUBLIC include)
target_link_libraries(demo tvision::tvision)


cmake_minimum_required(VERSION 2.8.9)
project(directory_test)

include_directories(include)

set(SOURCES src/main.cpp)

file(GLOB SOURCES "src/*.cpp")

add_executable(app ${SOURCES})

TARGET_LINK_LIBRARIES( app
pthread
)

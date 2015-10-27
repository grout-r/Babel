cmake_minimum_required(VERSION 2.8.11)

project(BabelServer)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

file(GLOB SOURCES src/*.cpp)

include_directories(includes)

add_executable(BabelServer WIN32 ${SOURCES} ${moc_sources})

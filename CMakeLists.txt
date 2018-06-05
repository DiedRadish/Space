cmake_minimum_required(VERSION 3.10)

project(Space)

set(SpaceDir ${PROJECT_SOURCE_DIR})
set(SpaceSrcDir ${SpaceDir}/src)

include_directories(${SpaceSrcDir})

include(src/Space/CMakeLists.txt)
include(src/Console/CMakeLists.txt)
include(src/Platform/CMakeLists.txt)
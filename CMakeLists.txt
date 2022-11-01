cmake_minimum_required(VERSION 3.10)

project(XenoMC LANGUAGES C VERSION 0.2)

set(XenoMCRootDir ${CMAKE_CURRENT_LIST_DIR})
set(XenoMCSourceDir ${XenoMCRootDir}/src)

include(src/CMakeLists.txt)

cmake_minimum_required(VERSION 3.21)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
if ("${CMAKE_SYSTEM_NAME}" STREQUAL "iOS" OR IOS)
    set(CMAKE_OSX_ARCHITECTURES "arm64")
else()
    set(CMAKE_OSX_ARCHITECTURES "arm64;x86_64")
endif()
set(CMAKE_CXX_VISIBILITY_PRESET hidden)

project(GeodeLuaTemplate VERSION 1.0.0)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS src/*.cpp)
add_library(${PROJECT_NAME} SHARED ${SOURCES})

if (NOT DEFINED ENV{GEODE_SDK})
    message(FATAL_ERROR "Unable to find Geode SDK! Please define GEODE_SDK environment variable to point to Geode")
else()
    message(STATUS "Found Geode: $ENV{GEODE_SDK}")
endif()

add_subdirectory($ENV{GEODE_SDK} ${CMAKE_CURRENT_BINARY_DIR}/geode)

setup_geode_mod(${PROJECT_NAME})



set(SOL2_BUILD_LUA OFF CACHE BOOL "Always build Lua, do not search for it in the system")
SET(BUILD_LUA_AS_DLL OFF)
SET(SOL2_TESTS OFF)
SET(SOL2_ENABLE_INSTALL OFF)

CPMAddPackage(
  NAME lua
  GITHUB_REPOSITORY lua/lua
  GIT_TAG v5.4.8
  DOWNLOAD_ONLY TRUE
)

# Add the Lua amalgamated file to your target
target_sources(${PROJECT_NAME} PRIVATE ${CPM_PACKAGE_lua_SOURCE_DIR}/onelua.c)

# Optionally include the Lua headers
target_include_directories(${PROJECT_NAME} PRIVATE ${CPM_PACKAGE_lua_SOURCE_DIR})

CPMAddPackage("gh:ThePhD/sol2#c1f95a7")
target_compile_definitions(${PROJECT_NAME} PRIVATE MOD_ROOT="${CMAKE_SOURCE_DIR}")

target_link_libraries(${PROJECT_NAME} sol2)
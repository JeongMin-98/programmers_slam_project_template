################################################################################
# Project Name: imageProject
#
# Components:
#    - ImageProject
#
################################################################################

# Project information
cmake_minimum_required(VERSION 3.10)
set(PACKAGE_NAME ImageProjector)
project(${PACKAGE_NAME} LANGUAGES CXX)

# Export aliases
set(ImageProjector_PATH ${CMAKE_CURRENT_SOURCE_DIR} CACHE PATH "ImageProject_PATH")
set(ImageProjector_INCLUDE_PATH
        "${ImageProjector_PATH}/include" CACHE PATH "ImageProjector_INCLUDE_PATH")
set(ImageProjector_RESOURCES_PATH
        "${ImageProjector_PATH}/resources" CACHE PATH "ImageProjector_RESOURCES_PATH")
set(ImageProjector_TEST_PATH
        "${ImageProjector_PATH}/test" CACHE PATH "ImageProjector_TEST_PATH")

# Paths
add_definitions(-DImageProjector_SOURCE_DIR="${ImageProjector_PATH}")
add_definitions(-DImageProjector_RESOURCES_DIR="${ImageProjector_RESOURCES_PATH}")

# Source files
set(ImageProjector_SOURCE_FILES
        src/ImageProjector.cpp
        )
add_library(${PACKAGE_NAME}
        ${ImageProjector_SOURCE_FILES}
        )

# Header files, including 3rdParty
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_MODULE_PATH})

target_include_directories(${PACKAGE_NAME} PRIVATE
        ${ImageProjector_INCLUDE_PATH}
        )
target_link_libraries(${PACKAGE_NAME} PRIVATE
        ${EASY_PROFILER_LIBS}
        ${SPDLOG_LIBS}
        stdc++fs
        )

# Compile options
target_compile_options(${PACKAGE_NAME} PRIVATE
        -Wall -Wextra -Wpedantic -Werror
        )
set_target_properties(${PACKAGE_NAME} PROPERTIES
        CXX_STANDARD 11
        CXX_STANDARD_REQUIRED ON
        CXX_EXTENSIONS OFF
        )

# Unit tests
add_subdirectory(test)

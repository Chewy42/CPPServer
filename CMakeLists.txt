# Copyright (c) 2024 by Matthew Favela
# Protected under the MIT License
# Refer to LICENSE for more information


cmake_minimum_required(VERSION 3.15)
project(CPPServer VERSION 0.1 LANGUAGES CXX)

cmake_policy(SET CMP0167 OLD)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set build output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Specify paths to Boost (adjust paths according to your installation)
set(BOOST_ROOT "$ENV{HOME}/.conan/data/boost/1.85.0/_/_/package/<package_id>")
set(BOOST_INCLUDEDIR "$ENV{HOME}/.conan/data/boost/1.85.0/_/_/package/<package_id>/include")
set(BOOST_LIBRARYDIR "$ENV{HOME}/.conan/data/boost/1.85.0/_/_/package/<package_id}/lib")

# Find Boost package
find_package(Boost 1.85 REQUIRED COMPONENTS system filesystem)

# Add the source files
add_executable(CPPServer src/main.cpp)

# Link Boost libraries
target_link_libraries(CPPServer PRIVATE Boost::system Boost::filesystem)

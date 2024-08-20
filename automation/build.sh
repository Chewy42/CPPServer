#!/bin/bash

# Install dependencies
conan install . --output-folder=build --build=missing

# Configure the project
cd build
cmake ..

# Build the project
cmake --build .

# Go back a dir
cd ..
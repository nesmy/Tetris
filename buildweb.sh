#!/bin/bash

#$VULKAN_SDK/bin/glslc Resources/Shader/shader.vert -o Resources/Shader/vert.spv
#$VULKAN_SDK/bin/glslc Resources/Shader/shader.frag -o Resources/Shader/frag.spv
cd vendor/emsdk
./emsdk install latest
./emsdk activate latest

cd ../..

cmake -B build -S . -DCMAKE_BUILD_TYPE=Debug -DCMAKE_TOOLCHAIN_FILE=vendor/emsdk/upstream/emscripten/cmake/Modules/Platform/Emscripten.cmake -DPLATFORM=Web

cp -r Resources build
cmake --build build


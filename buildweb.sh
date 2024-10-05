#!/bin/bash

#$VULKAN_SDK/bin/glslc Resources/Shader/shader.vert -o Resources/Shader/vert.spv
#$VULKAN_SDK/bin/glslc Resources/Shader/shader.frag -o Resources/Shader/frag.spv

cmake -B build -S . -DCMAKE_BUILD_TYPE=Debug -DCMAKE_TOOLCHAIN_FILE=/home/nesmy/opt/emsdk-main/upstream/emscripten/cmake/Modules/Platform/Emscripten.cmake -DPLATFORM=Web
cmake --build build


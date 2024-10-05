#!/bin/bash

#$VULKAN_SDK/bin/glslc Resources/Shader/shader.vert -o Resources/Shader/vert.spv
#$VULKAN_SDK/bin/glslc Resources/Shader/shader.frag -o Resources/Shader/frag.spv

cmake -B out -S . -DCMAKE_BUILD_TYPE=Debug
cmake --build out


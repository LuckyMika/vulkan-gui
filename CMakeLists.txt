cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(Vulkan-GUI VERSION 1.0)

include_directories($ENV{VULKAN_SDK}/Include)

add_executable(Vulkan-GUI src/main.cpp "src/window.cpp" "src/window.h")

target_link_libraries(Vulkan-GUI PRIVATE $ENV{VULKAN_SDK}/Lib/vulkan-1.lib)

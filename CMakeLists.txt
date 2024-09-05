cmake_minimum_required(VERSION 3.30)
project(MyProject LANGUAGES CXX)

# Enable C++23
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add vcpkg toolchain
# set(CMAKE_TOOLCHAIN_FILE "C:/Users/gabri/scoop/apps/vcpkg/current/scripts/toolchains/windows.cmake")

set(CMAKE_PREFIX_PATH "C:/Users/gabri/scoop/persist/vcpkg/packages")

message("CMAKE_CXX_COMPILER: ${CMAKE_CXX_COMPILER}")
message("CMAKE_MODULE_PATH: ${CMAKE_MODULE_PATH}")
message("CMAKE_SOURCE_DIR: ${CMAKE_SOURCE_DIR}")
message("CMAKE_PREFIX_PATH: ${CMAKE_PREFIX_PATH}")

# Find packages
# find_package(Vulkan REQUIRED)
find_package(spdlog REQUIRED)
find_package(EnTT REQUIRED)
find_package(GLFW3 REQUIRED)
find_package(glm REQUIRED)

# Add executable
add_executable(${PROJECT_NAME} src/main.cpp)

# Link libraries
target_link_libraries(${PROJECT_NAME} PRIVATE 
  # Vulkan::Vulkan
  spdlog::spdlog
  EnTT::EnTT
  glfw 
  glm
)

add_subdirectory(EngineCore)
add_subdirectory(EngineApp)
add_dependencies(EngineApp EngineCore) # Ensure EngineApp depends on EngineCore

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    $<TARGET_FILE:EngineCore>
    ${CMAKE_BINARY_DIR}/$<CONFIGURATION>

    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    $<TARGET_FILE:EngineApp>
    ${CMAKE_BINARY_DIR}/$<CONFIGURATION>
)

# Add examples
# add_subdirectory(examples/example1)
# add_subdirectory(examples/example2)

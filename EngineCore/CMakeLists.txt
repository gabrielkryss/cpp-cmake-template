# # Enable position-independent code for shared libraries
# set(CMAKE_POSITION_INDEPENDENT_CODE ON)
#
# # Enable exports for shared libraries
# set(CMAKE_ENABLE_EXPORTS ON)

# Add EngineCore shared library
add_library(EngineCore SHARED
    src/engine.cpp
    src/EngineCoreModule.cpp
    # include/EngineCoreModule.cppm
)

# Specify the module interface file
target_sources(EngineCore PRIVATE
    FILE_SET cxx_modules TYPE CXX_MODULES FILES include/EngineCoreModule.cppm
)

target_include_directories(EngineCore PUBLIC
    include
)

target_compile_definitions(EngineCore PRIVATE ENGINE_EXPORTS)

# Link libraries to EngineCore
target_link_libraries(EngineCore PRIVATE 
    # Vulkan::Vulkan
    spdlog::spdlog
    EnTT::EnTT
    glm
)

# # Set output directories for DLL and LIB files
# set_target_properties(EngineCore PROPERTIES
#     RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/$<CONFIGURATION>
#     ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/$<CONFIGURATION>
#     LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/$<CONFIGURATION>
# )

# # Set MSVC-specific properties for module files
# if (MSVC)
#     set_target_properties(EngineCore PROPERTIES
#         CXX_STANDARD 23
#         CXX_EXTENSIONS OFF
#         CXX_MODULES ON
#     )
# endif()

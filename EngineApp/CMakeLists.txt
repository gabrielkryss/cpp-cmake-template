# Add EngineApp executable
add_executable(EngineApp
    src/main.cpp
    src/MyModule.cpp
    include/MyModule.cppm
)

target_include_directories(EngineApp PRIVATE
    ../EngineCore/include
)

# Link libraries
target_link_libraries(EngineApp PRIVATE 
    EngineCore
    spdlog::spdlog
    EnTT::EnTT
    glfw
    glm
)

# set_target_properties(EngineApp PROPERTIES
#     RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/$<CONFIGURATION>
# )

add_custom_command(TARGET EngineApp POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    $<TARGET_FILE:EngineCore>
    $<TARGET_FILE_DIR:EngineApp>
)

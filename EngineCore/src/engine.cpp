#include "engine.h"

import std;

namespace MY_ENGINE {

// Constructor
Engine::Engine() noexcept {
    std::print("Engine created.\n");
}

// Destructor
Engine::~Engine() noexcept {
    std::print("Engine destroyed.\n");
}

// Initialize the engine
void Engine::initialize() noexcept {
    std::print("Engine initialized.\n");
}

// Run the engine
void Engine::run() noexcept {
    /*while (isRunningFlag) {*/
    /*    // Placeholder for main loop logic*/
    /*    // Example usage of constexpr function*/
    /*    std::print("Max FPS: {}\n", getMaxFPS());*/
    /*}*/

    std::print("Engine running.\n");
}

// Stop the engine
void Engine::stop() noexcept {
    isRunningFlag = false;
    std::print("Engine stopped.\n");
}

// Check if the engine is running
[[nodiscard]] bool Engine::isRunning() const noexcept {
    return isRunningFlag;
}

} // namespace MY_ENGINE

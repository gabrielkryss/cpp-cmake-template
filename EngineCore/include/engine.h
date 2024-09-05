#pragma once

#ifdef ENGINE_EXPORTS
#define ENGINE_API __declspec(dllexport)
#else
#define ENGINE_API __declspec(dllimport)
#endif

namespace MY_ENGINE {

class ENGINE_API Engine {
public:
    // Constructor
    Engine() noexcept;

    // Destructor
    ~Engine() noexcept;

    // Initialize the engine
    void initialize() noexcept;

    // Run the engine
    void run() noexcept;

    // Stop the engine
    void stop() noexcept;

    // Check if the engine is running
    [[nodiscard]] bool isRunning() const noexcept;

    // Constexpr function to get the maximum FPS
    constexpr int getMaxFPS() const noexcept {
        return maxFPS;
    }

private:
    bool isRunningFlag = true;
    int maxFPS = 60; // Example member variable
};

} // namespace MY_ENGINE

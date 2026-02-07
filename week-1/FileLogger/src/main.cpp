#include "../include/Logger.hpp"
#include <thread>
#include <vector>

int main() {
    // 1. Basic Initialization Test
    // Notice we pass "info" in lowercase to test your Uppercase Logic
    Logger logger("app.log", "info");

    std::cout << "--- Starting Logger Tests ---" << std::endl;

    // 2. Sequential Writing Test
    logger.writeMessage("Starting the application...");
    logger.writeMessage("Performing a simple calculation: 2 + 2 = 4");

    // 3. Concurrency Test (Stress Test)
    // We create 10 threads, each writing 50 messages simultaneously.
    // If the Mutex logic is wrong, the file will be a mess.
    const int num_threads = 10;
    const int messages_per_thread = 50;
    std::vector<std::thread> threads;

    std::cout << "Spawning " << num_threads << " threads to test Mutex logic..." << std::endl;

    for (int i = 0; i < num_threads; ++i) {
        threads.emplace_back([&logger, i]() {
            for (int j = 0; j < messages_per_thread; ++j) {
                logger.writeMessage("Message from thread " + std::to_string(i) + " count: " + std::to_string(j));
            }
        });
    }

    // Wait for all threads to finish
    for (auto& t : threads) {
        t.join();
    }

    logger.writeMessage("All tests completed successfully.");
    std::cout << "--- Tests Finished. Check 'app.log' for results. ---" << std::endl;

    return 0;
}

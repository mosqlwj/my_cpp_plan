//
// Created by lwj on 22-8-22.
//
#include <iostream>
#include <thread>
#include <vector>


int main() {
    std::vector<std::thread> threads;
    for (size_t i = 0; i < 5; i++) {
        threads.emplace_back([i]() {
            std::this_thread::sleep_for(std::chrono::milliseconds(10 * i));
            std::cout << "Hello Thread: " << i << std::endl;
        });
    }

    std::cout << "Hello Main1" << std::endl;
    for (auto& t : threads) {
        t.join();
    }
    std::cout << "Hello Main2" << std::endl;
    return 0;
}
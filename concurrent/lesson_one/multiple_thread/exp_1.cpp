//
// Created by lwj on 22-8-22.
//
#include <iostream>
#include <thread>
#include <vector>

void PrintHello() {
    std::cout << "Hello Thread:"
              << std::this_thread::get_id()
              << std::endl;
}

int main() {
    std::vector<std::thread> threads;
    for (size_t i = 0; i < 5; i++) {
        // thread not support copy
//        std::thread t(PrintHello);
//        threads.push_back(t);

        // thread move
        threads.push_back(std::thread(PrintHello));
    }

    for (auto& t : threads) {
        t.join();
    }

    std::cout << "Hello Main:"
              << std::this_thread::get_id()
              << std::endl;
    return 0;
}
//
// Created by lwj on 22-8-31.
//
#include <cmath>
#include <future>
#include <iostream>
#include <memory>
#include <thread>
#include <vector>

void WorkFunction(int n) {

    std::cout << "Work thread id = " << std::this_thread::get_id() << std::endl;

    for (int i = 0; i < n; i++) {
        sqrt(12345.6789);
    }
}

int main() {
    std::cout << "Work thread id = " << std::this_thread::get_id() << std::endl;

    std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();

    std::vector<std::future<void>> futures;
    int n_loops = 10;
    int n_thread = 5;

    for (int i = 0; i < n_thread; i++) {
        futures.emplace_back(std::async(std::launch::async, WorkFunction, n_loops));
    }

    for(auto& ftr : futures) {
        ftr.wait();
    }
    std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
    std::cout << "Duration = " << duration << "ms" << std::endl;
    return  0;
}
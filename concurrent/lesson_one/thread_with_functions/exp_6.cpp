//
// Created by lwj on 22-8-29.
//
#include <iostream>
#include <thread>

int main() {

    int id = 0;
    auto f0 = [&id]() {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        std::cout << "Call by Ref ID = " << id << "\n";
    };

    std::thread t1(f0);

    auto f1 = [id]() mutable {
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        std::cout << "Call by Val ID = " << id << "\n";
    };

    std::thread t2(f1);

    ++id;
    std::cout << "Main ID = " << id << "\n";

    t1.join();
    t2.join();
    return 0;
}
//
// Created by lwj on 22-8-30.
//
#include <iostream>
#include <thread>

void PrintMessage(std::string message) {
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    std::cout << "Thread 1:" << message << std::endl;
}

int main() {
    std::string message = "My Message";
    std::thread t1(PrintMessage, message);

    std::thread t2([message]() {
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        std::cout << "Thread 2:" << message << std::endl;
    });
    t1.join();
    t2.join();
    return 0;
}
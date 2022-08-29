//
// Created by lwj on 22-8-22.
//
#include <iostream>
#include <thread>
void  ThreadFunctionEven() {
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    std::cout << "Even thread" << std::endl;
}

void  ThreadFunctionOdd() {
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    std::cout << "Odd thread" << std::endl;
}

int main() {
    // create thread
    for (size_t i = 0; i < 6; i++) {
        if (i % 2 == 0) {
            std::thread t(ThreadFunctionEven);
            t.join();
        } else {
            std::thread t(ThreadFunctionOdd);
            t.join();
        }
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    std::cout << "Thread main" << std::endl;

    return 0;
}
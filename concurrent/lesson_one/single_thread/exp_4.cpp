//
// Created by lwj on 22-8-22.
//
#include <iostream>
#include <thread>

void  ThreadFunction() {
//    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::cout << "Finish work1 ThreadFunction" << std::endl;

//    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::cout << "Finish work2 ThreadFunction" << std::endl;
}

int main() {
    // create thread
    std::thread t(ThreadFunction);

//    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    std::cout << "Finish work1 in main" << std::endl;

//    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    std::cout << "Finish work2 in main" << std::endl;

    t.join();
    return 0;
}
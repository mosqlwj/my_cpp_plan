//
// Created by lwj on 22-8-22.
//
#include <iostream>
#include <thread>

void  ThreadFunction() {
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::cout << "Finish work ThreadFunction:" << std::this_thread::get_id() << std::endl;
}

int main() {
    // create thread
    std::thread t(ThreadFunction);

    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    std::cout << "Finish work main:" << std::this_thread::get_id() << std::endl;

    t.join();
    return 0;
}
//
// Created by lwj on 22-8-29.
//
#include <iostream>
#include <thread>
#include <string>

void PrintName(std::string name, int wait_time) {
    std::this_thread::sleep_for(std::chrono::milliseconds(wait_time));
    std::cout << "Name(from thread) = " << name << std::endl;
}



int main() {
    std::string name1 = "MyThread1";
    std::string name2 = "MyThread2";
    // copy by val and move semantic
    std::thread t1(PrintName, name1, 50);
    std::thread t2(PrintName, std::move(name2), 50);

    t1.join();
    t2.join();

    std::cout << "Name1(from main) = " << name1 << std::endl;
    std::cout << "Name2(from main) = " << name2 << std::endl;

    return 0;
}
//
// Created by lwj on 22-8-29.
//
#include <iostream>
#include <thread>
#include <string>

void PrintName(std::string& name, int wait_time) {
    std::this_thread::sleep_for(std::chrono::milliseconds(wait_time));
    name += " (from thread)";
    std::cout << name << std::endl;
}



int main() {
    std::string name = "MyThread";

    std::thread t1(PrintName, std::ref(name), 50);

    t1.join();

    name += " (from main)";
    std::cout << name << std::endl;

    return 0;
}
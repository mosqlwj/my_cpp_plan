//
// Created by lwj on 22-8-29.
//
#include <iostream>
#include <thread>
#include <string>

void PrintID(int id) {
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::cout << "ID = " << id << std::endl;
}

void PrintIDAndName(int id, std::string name) {
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::cout << "ID = " << id << ", Name = " << name << std::endl;
}

int main() {
    int id = 1;
    std::thread t1(PrintID, id);
    std::thread t2(PrintIDAndName, id, "my srting");

    t1.join();
    t2.join();


    return 0;
}
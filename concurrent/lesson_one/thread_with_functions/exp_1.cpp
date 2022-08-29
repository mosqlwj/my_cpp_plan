//
// Created by lwj on 22-8-29.
//
#include <iostream>
#include <thread>

class Vehicle {
public:
    void operator()() {
        std::cout << "Vehicle object has been create \n";
    }
};

int main() {
    std::thread t((Vehicle()));

    std::cout << "Finished work in main \n";
    t.join();
    return 0;
}
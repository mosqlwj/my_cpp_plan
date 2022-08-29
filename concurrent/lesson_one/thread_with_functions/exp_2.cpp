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
    std::thread t1((Vehicle()));
    std::thread t2 = std::thread(Vehicle());
    std::thread t3{Vehicle()};

    t1.join();
    t2.join();
    t3.join();
    std::cout << "Finished work in main \n";
    return 0;
}
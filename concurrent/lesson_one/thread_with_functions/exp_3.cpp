//
// Created by lwj on 22-8-29.
//
#include <iostream>
#include <thread>

class Vehicle {
public:
    Vehicle(int id) {
        _id = id;
    }
    void operator()() {
        std::cout << "Vehicle #" << _id << " has been created \n";
    }

private:
    int _id;
};

int main() {
//    std::thread t((Vehicle(1)));
    std::thread t(Vehicle(1));
    std::cout << "Finished work in main \n";
    t.join();
    return 0;
}
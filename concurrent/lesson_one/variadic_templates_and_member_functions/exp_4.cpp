//
// Created by lwj on 22-8-29.
//
#include <iostream>
#include <thread>

class Vehicle {
public:
    Vehicle() {
        _id = 0;
    }

    void AddID(int id) {
        _id = id;
    }

    void PrintID() {
        std::cout << "ID = " << _id << std::endl;
    }
private:
    int _id;
};

int main() {
    Vehicle v1, v2;
    std::thread t1(&Vehicle::AddID, v1, 1);
    std::thread t2(&Vehicle::AddID, &v2, 2);

    t1.join();
    t2.join();

    v1.PrintID();
    v2.PrintID();
    return 0;
}
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

    std::shared_ptr<Vehicle> v(new Vehicle);
    std::thread t(&Vehicle::AddID, v, 1);
    t.join();
    v->PrintID();

    return 0;
}
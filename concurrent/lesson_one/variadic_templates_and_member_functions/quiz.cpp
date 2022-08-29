//
// Created by lwj on 22-8-29.
//
#include <iostream>
#include <thread>
#include <string>

class Vehicle {
public:
    Vehicle() {
        _id = 0;
        _name = "";
    }

    void AddID(int id) {
        _id = id;
    }

    void SetName(std::string name) {
        _name = name;
    }

    void PrintID() {
        std::cout << "ID = " << _id << std::endl;
    }

    void PrintName() {
        std::cout << "Name = " << _name << std::endl;
    }

private:
    int _id;
    std::string _name;
};

int main() {

    std::shared_ptr<Vehicle> v(new Vehicle);
    std::thread t1(&Vehicle::AddID, v, 1);
    std::thread t2(&Vehicle::SetName, v, "Vehicle");

    t1.join();
    t2.join();

    v->PrintID();
    v->PrintName();
    return 0;
}
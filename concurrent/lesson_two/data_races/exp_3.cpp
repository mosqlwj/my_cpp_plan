//
// Created by lwj on 22-8-31.
//
#include <future>
#include <iostream>
#include <thread>
#include <string>

class Vehicle {
public:
    Vehicle() : _id(0), _name(new std::string("Default name")) {
        std::cout << "V#" << _id
                  << " Default constructor called" << std::endl;
    }
    Vehicle(int id, std::string name) : _id(id), _name(new std::string(name)) {
        std::cout << "V#" << _id
                  << " Init constructor called" << std::endl;
    }

    Vehicle(const Vehicle& src) {
        std::cout << "V#" << _id
                  << " Copy constructor called" << std::endl;
    }
    // move
    Vehicle(Vehicle&& src) {
        _id = src.GetId();
        _name = new std::string(src.GetName());

        src.SetId(0);
        src.SetName("Default name");
        std::cout << "V#" << _id
                  << " Move constructor called" << std::endl;
    }

    void SetId(int id) {
        _id = id;
    }
    int GetId() {
        return _id;
    }

    void SetName(std::string name) {
        *_name = name;
    }

    std::string GetName() {
        return *_name;
    }
private:
    int _id;
    std::string* _name;
};

int main() {
    Vehicle v0;
    Vehicle v1(1, "V#1");

    std::future<void> ftr = std::async(
            [](Vehicle v) {
                    v.SetName("V 2");
                },
                std::move(v0));

    ftr.wait();
    std::cout << "V #" << v0.GetName() << std::endl;
    return 0;
}
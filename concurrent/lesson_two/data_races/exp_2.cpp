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
    Vehicle v1(1, "V 1");

    std::future<void> ftr = std::async(
            [](Vehicle v) {
                    std::this_thread::sleep_for(std::chrono::milliseconds(100));
                    v.SetName("V 2");
                },
                v0);
    // data race
    v0.SetName("V 3");

    ftr.wait();
    std::cout << "V #" << v0.GetName() << std::endl;
    return 0;
}
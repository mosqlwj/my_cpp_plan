//
// Created by lwj on 22-8-31.
//
#include <future>
#include <iostream>
#include <thread>

class Vehicle {
public:
    Vehicle() : _id(0) {
        std::cout << "V#" << _id
                  << " Default constructor called" << std::endl;
    }
    Vehicle(int id) : _id(id) {
        std::cout << "V#" << _id
                  << " Init constructor called" << std::endl;
    }

    void SetId(int id) {
        _id = id;
    }
    int GetId() {
        return _id;
    }
private:
    int _id;
};

int main() {
    Vehicle v0;
    Vehicle v1(1);

    std::future<void> ftr = std::async(
            [](Vehicle& v) {
                    std::this_thread::sleep_for(std::chrono::milliseconds(100));
                    v.SetId(2);
                },
                std::ref(v0));
    // data race
//    v0.SetId(3);

    ftr.wait();
    std::cout << "V #" << v0.GetId() << std::endl;
    return 0;
}
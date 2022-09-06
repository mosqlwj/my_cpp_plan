//
// Created by lwj on 22-9-1.
//
#include <future>
#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

class Vehicle {
public:
    Vehicle(int id) : _id(id) {}
    int GetID() { return  _id; }
private:
    int _id;
};

class WaitingVehicles {
public:
    WaitingVehicles() {}

    void PrintSize() {
        _mutex.lock();
        std::cout << "#vehicles = " << _vehicles.size() << std::endl;
        _mutex.unlock();
    }

    void PushBack(Vehicle&& v) {
        for (size_t i = 0; i < 3; i++) {
            if (_mutex.try_lock_for(std::chrono::milliseconds(100))) {
                _vehicles.emplace_back(std::move(v));
                std::this_thread::sleep_for(std::chrono::milliseconds(10));
                _mutex.unlock();
                break;
            } else {
                _mutex.lock();
                std::cout << "Error: V#" << v.GetID() << " cannot be added to vec" << std::endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(100));
                _mutex.unlock();
            }
        }
    }
private:
    std::vector<Vehicle> _vehicles;
    std::timed_mutex _mutex;
};

int main() {

    std::shared_ptr<WaitingVehicles> queue(new WaitingVehicles);
    std::vector<std::future<void>> futures;

    for (int i = 0; i < 100; i++) {
        Vehicle v(i);
        futures.emplace_back(std::async(
                std::launch::async, &WaitingVehicles::PushBack, queue, std::move(v)));
    }

    for (auto& ftr : futures) {
        ftr.wait();
    }
    queue->PrintSize();

    return 0;
}
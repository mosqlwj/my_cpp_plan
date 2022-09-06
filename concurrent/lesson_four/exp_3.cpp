//
// Created by lwj on 22-9-3.
//
#include <future>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

class Vehicle {
public:
    Vehicle(int id) : _id(id) {}

    int GetID() {
        return _id;
    }
private:
    int _id;
};

class WaitingVehicles {
public:
    WaitingVehicles() {}

    Vehicle PopBack() {
        std::unique_lock<std::mutex> lock(_mutex);

//        _cond.wait(lock, [this] {
//            return !_vehicles.empty();
//        });
        _cond.wait(lock, [this] {
            return !_vehicles.empty();
        });

        auto v = std::move(_vehicles.back());
        _vehicles.pop_back();
        return v;
    }

    void PushBack(Vehicle&& v) {
        std::lock_guard<std::mutex> lock(_mutex);
        std::cout << "V#" << v.GetID() << " will be added to vector" << std::endl;
        _vehicles.emplace_back(std::move(v));

        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        _cond.notify_one();
    }

    void PrintIDs() {
//        std::lock_guard<std::mutex> lock(_mutex);
        for (auto& v: _vehicles) {
            std::cout << "V#" << v.GetID() << " is waiting in the vector" << std::endl;
        }
    }

private:
    std::vector<Vehicle> _vehicles;
    std::mutex _mutex;
    std::condition_variable _cond;
};

int main() {
    std::shared_ptr<WaitingVehicles> queue(new WaitingVehicles);
    std::cout << "Spawning thread.." << std::endl;
    std::vector<std::future<void>> futures;

    for (int i = 0; i < 10; i++) {
        Vehicle v(i);
        futures.emplace_back(std::async(
                std::launch::async,
                &WaitingVehicles::PushBack,
                queue,
                std::move(v)));
    }

    std::cout << "Collecting results.." << std::endl;

    while (true) {
        Vehicle v = queue->PopBack();
        std::cout << "V#" << v.GetID() << " has been removed from queue." << std::endl;
    }


    for (auto& ftr : futures) {
        ftr.wait();
    }

    std::cout << "Finish processing.." << std::endl;
    return 0;
}
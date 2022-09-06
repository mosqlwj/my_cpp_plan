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
private:
    int _id;
};

class WaitingVehicles {
public:
    WaitingVehicles() : _tmp_vehicles(0) {}

    void PrintSize() {
        _mutex.lock();
        std::cout << "#vehicles = " << _tmp_vehicles << std::endl;
        _mutex.unlock();
    }

    void PushBack(Vehicle&& v) {
        _mutex.lock();
        _vehicles.push_back(std::move(v));
        int old_num = _tmp_vehicles;
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
        _tmp_vehicles = old_num + 1;
        _mutex.unlock();
    }
private:
    std::vector<Vehicle> _vehicles;
    int _tmp_vehicles;
    std::mutex _mutex;
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
//
// Created by lwj on 22-9-1.
//
#include <future>
#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

double result = 0.0;

std::mutex mutex;
void PrintResult(int denom) {
    std::cout << "for denom = "
        << denom << ", the result is "
        << result << std::endl;
}

void DivideByNumber(double num, double denom) {
    mutex.lock();
    try {
        if (denom != 0) {

            result = num / denom;
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
            PrintResult(denom);

        } else {
            throw std::invalid_argument("Exception:Division by zero!");
        }
    } catch (const std::invalid_argument& e) {
        e.what();
    }
    mutex.unlock();
}

int main() {

    std::vector<std::future<void>> futures;

    for (double i = -5; i <= 5; i++) {
        futures.emplace_back(std::async(std::launch::async, DivideByNumber, 50.0, i));
    }

    for (auto& ftr : futures) {
        ftr.wait();
    }

    return 0;
}
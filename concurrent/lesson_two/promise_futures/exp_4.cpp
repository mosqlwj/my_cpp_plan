//
// Created by lwj on 22-8-30.
//
#include <iostream>
#include <thread>
#include <future>
#include <cmath>
#include <memory>

void DivideNumber(std::promise<double>&& prms, double num, double denom) {
    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    try {
        if (denom == 0) {
            throw std::runtime_error("Division by zero!");
        } else {
            prms.set_value(num / denom);
        }
    } catch (...) {
        prms.set_exception(std::current_exception());
    }
}

int main() {
    std::promise<double> prms;
    std::future<double> ftr = prms.get_future();

    double num = 42.0, denom = 0.0;
    std::thread t(DivideNumber, std::move(prms), num, denom);
    try {
        double res = ftr.get();
        std::cout << res << std::endl;
    } catch (std::runtime_error e) {
        std::cout << e.what() << std::endl;
    }
    t.join();
    return 0;
}
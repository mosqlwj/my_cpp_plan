//
// Created by lwj on 22-8-31.
//
#include <cmath>
#include <future>
#include <iostream>
#include <memory>
#include <thread>

double DivideByNumber(double num, double denom) {
    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    if (denom == 0) {
        throw std::runtime_error("Divide by zero!");
    }

    return num / denom;
}

int main() {
    double num = 42.0, denom = 2.0;
    std::future<double> ftr = std::async(DivideByNumber, num, denom);

    try {
        double res = ftr.get();
        std::cout << "Res = " << res << std::endl;
    } catch (std::runtime_error e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
//
// Created by lwj on 22-8-30.
//
#include <iostream>
#include <thread>
#include <cmath>
#include <future>

void ComputeSqrt(std::promise<double>&& prms, double input) {
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    double output = sqrt(input);
    prms.set_value(output);
}

int main() {
    double input = 2.0;
    std::promise<double> prms;
    std::future<double> ftr = prms.get_future();

    std::thread t(ComputeSqrt, std::move(prms), input);

    auto status = ftr.wait_for(std::chrono::milliseconds(1000));
    if (status == std::future_status::ready) {
        std::cout << "Res = " << ftr.get() << std::endl;
    } else if (status == std::future_status::timeout ||
               status == std::future_status::deferred) {
        std::cout << "Res Unavailable " << std::endl;
    }

    t.join();
    return 0;
}
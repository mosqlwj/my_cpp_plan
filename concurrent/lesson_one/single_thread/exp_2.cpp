//
// Created by lwj on 22-8-22.
//
#include <iostream>
#include <thread>

int main() {
    unsigned int n_cores = std::thread::hardware_concurrency();
    std::cout << "this machine has " << n_cores << " cores available" << std::endl;
    return 0;
}
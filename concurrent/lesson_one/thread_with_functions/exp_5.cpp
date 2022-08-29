//
// Created by lwj on 22-8-29.
//
#include <iostream>
#include <thread>

int main() {
    int id = 0;

    auto f = [](const int id) {
        std::cout << "ID = " << id << "\n";
    };

    f(id);

    return 0;
}
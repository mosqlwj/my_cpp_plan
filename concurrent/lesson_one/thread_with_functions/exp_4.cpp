//
// Created by lwj on 22-8-29.
//
#include <iostream>
#include <thread>

int main() {
    int id = 0;
    id++;

//    auto f0 = []() {
//        std::cout << "ID = " << id << "\n";
//    };

    auto f1 = [id]() {
        // id captured by value
        std::cout << "ID = " << id << "\n";
    };

    id++;
    auto f2 = [&id]() {
        // id captured by ref
        std::cout << "ID = " << id << "\n";
    };

//    auto f3 = [id]() {
//        std::cout << "ID = " << ++id << "\n";
//    };

    auto f4 = [id]() mutable {
        std::cout << "ID = " << ++id << "\n";
    };
    f1();
    f2();
    f4();
    std::cout << "ID = " << id << "\n";


    return 0;
}
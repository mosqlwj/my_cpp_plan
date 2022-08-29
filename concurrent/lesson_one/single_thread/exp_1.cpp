//
// Created by lwj on 22-8-22.
//
#include <iostream>
#include <thread>

int main() {
    // 获取当前main thread id
    std::cout << "Thread id = " << std::this_thread::get_id() << std::endl;
    return 0;
}
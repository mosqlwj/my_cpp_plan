//
// Created by lwj on 22-8-30.
//
#include <iostream>
#include <thread>
#include <future>


void ModifyMessage(std::promise<std::string>&& prms, std::string message) {
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    std::string modified_message = message + "has been modified";
    prms.set_value(modified_message);
}


int main() {
    std::string message_to_thread = "My Message";

    std::promise<std::string> prms;
    std::future<std::string> ftr = prms.get_future();

    std::thread t(ModifyMessage, std::move(prms), message_to_thread);

    std::cout << "Main Message:" << message_to_thread << std::endl;

    std::string message_from_thread = ftr.get();
    std::cout << "Thread Meesage:" << message_from_thread;

    t.join();
    return 0;
}
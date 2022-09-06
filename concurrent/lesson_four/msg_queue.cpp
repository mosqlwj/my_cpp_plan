//
// Created by lwj on 22-9-6.
//
#include <future>
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>

template <class T>
class MessageQueue {
public:
    T Receive() {
        std::unique_lock<std::mutex> lock(_mtx);
        _cond.wait(lock, [this] {
            return !_messages.empty();
        });
        T msg = std::move(_messages.back());
        _messages.pop_back();
        return msg;
    }

    void Send(T&& msg) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        std::lock_guard<std::mutex> lock(_mtx);
        std::cout << " msg:" << msg << " has been sent to the queue!" << std::endl;
        _messages.template emplace_back(std::move(msg));
        _cond.notify_one();
    }
private:
    std::deque<T> _messages;
    std::mutex _mtx;
    std::condition_variable _cond;
};

int main() {
    std::shared_ptr<MessageQueue<int>> queue(new MessageQueue<int>);
    std::cout << "Spawning thread.." << std::endl;
    std::vector<std::future<void>> futures;

    for (int i = 0; i < 10; i++) {
        int msg = i;
        futures.emplace_back(std::async(
                std::launch::async,
                &MessageQueue<int>::Send,
                queue,
                std::move(msg)));
    }

    std::cout << "Collecting results.." << std::endl;

    while (true) {
        int msg = queue->Receive();
        std::cout << " msg:" << msg << " has been removed from queue." << std::endl;
    }


    for (auto& ftr : futures) {
        ftr.wait();
    }

    std::cout << "Finish processing.." << std::endl;
    return 0;

    return 0;
}
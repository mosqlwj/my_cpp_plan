//
// Created by LWJ on 2021/8/13.
//

#ifndef MY_LEETCODE_PLAN_MESSAGE_H
#define MY_LEETCODE_PLAN_MESSAGE_H
#include "folders.h"
#include <string>
#include <set>
#include <iostream>

class Folder;
class MyMessage {
    friend class Folder;
    friend void swap(MyMessage&, MyMessage&);
public:
    explicit MyMessage(const std::string& str = "") :
        contents(str) {}
    MyMessage(const MyMessage&);
    MyMessage& operator=(const MyMessage&);
    ~MyMessage();

    void save(Folder&);
    void remove(Folder&);

    void print_debug();
private:
    std::string contents;
    std::set<Folder*> folders;

    void add_to_folders(const MyMessage&);
    void remove_from_folders();

    void addFlder(Folder* f) {
        folders.insert(f);
    }
    void remFlder(Folder* f) {
        folders.erase(f);
    }
};

void swap(MyMessage&, MyMessage&);
#endif //MY_LEETCODE_PLAN_MESSAGE_H

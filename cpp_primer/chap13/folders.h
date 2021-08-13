//
// Created by LWJ on 2021/8/13.
//

#ifndef MY_LEETCODE_PLAN_FOLDERS_H
#define MY_LEETCODE_PLAN_FOLDERS_H
#include "message.h"
#include <set>
#include <string>
#include <iostream>
class MyMessage;
class Folder {
    friend class MyMessage;
    friend void swap(Folder&, Folder&);
public:
    Folder() {};
    Folder(const Folder&);
    Folder& operator=(const Folder&);
    ~Folder();
    void print_debug();

private:
    std::set<MyMessage*> msgs;
    void add_to_message(const Folder&);
    void remove_from_message();
    void addMsg(MyMessage* m) {
        msgs.insert(m);
    }
    void remMsg(MyMessage* m) {
        msgs.erase(m);
    }
};
void swap(Folder&, Folder&);
#endif //MY_LEETCODE_PLAN_FOLDERS_H

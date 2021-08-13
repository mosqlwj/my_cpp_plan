//
// Created by LWJ on 2021/8/13.
//
#include "message.h"

void MyMessage::save(Folder& f) {
    folders.insert(&f);
    f.addMsg(this);
}

void MyMessage::remove(Folder& f) {
    folders.erase(&f);
    f.remMsg(this);
}

void MyMessage::add_to_folders(const MyMessage& m) {
    for (auto f : m.folders) {
        f->addMsg(this);
    }
}

MyMessage::MyMessage(const MyMessage& m):
    contents(m.contents), folders(m.folders){
    add_to_folders(m);
}

void MyMessage::remove_from_folders() {
    for (auto f : folders) {
        f->remMsg(this);
    }
}

MyMessage::~MyMessage() {
    remove_from_folders();
}

MyMessage & MyMessage::operator=(const MyMessage& rhs) {
    remove_from_folders();
    contents = rhs.contents;
    folders = rhs.folders;
    add_to_folders(rhs);
    return *this;
}

void MyMessage::print_debug() {
    std::cout << contents << std::endl;
}

void swap(MyMessage& lhs, MyMessage& rhs) {
    using std::swap;
    lhs.remove_from_folders();
    rhs.remove_from_folders();
    swap(lhs.folders, rhs.folders);
    swap(lhs.contents, rhs.contents);
    lhs.add_to_folders(lhs);
    rhs.add_to_folders(rhs);
}


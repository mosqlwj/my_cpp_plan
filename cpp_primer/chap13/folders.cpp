//
// Created by LWJ on 2021/8/13.
//
#include "folders.h"

void Folder::add_to_message(const Folder& f) {
    for (auto m : f.msgs) {
        m->addFlder(this);
    }
}

Folder::Folder(const Folder& f): msgs(f.msgs) {
    add_to_message(f);
}

void Folder::remove_from_message() {
    for (auto m : msgs) {
        m->remFlder(this);
    }
}

Folder::~Folder() {
    remove_from_message();
}

Folder & Folder::operator=(const Folder& f) {
    remove_from_message();
    msgs = f.msgs;
    add_to_message(f);
    return *this;
}

void Folder::print_debug() {
    for (auto m : msgs) {
        std::cout << m->contents << " ";
    }
    std::cout << std::endl;
}

void swap(Folder& lhs, Folder& rhs) {
    using std::swap;
    lhs.remove_from_message();
    rhs.remove_from_message();

    swap(lhs.msgs, rhs.msgs);

    lhs.add_to_message(lhs);
    rhs.add_to_message(rhs);
}
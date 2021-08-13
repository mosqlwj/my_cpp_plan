//
// Created by LWJ on 2021/8/13.
//

#include "message.h"
#include "folders.h"
#include <iostream>
using namespace std;

int main() {
    MyMessage m1("msg0-1");
    MyMessage m2("msg0-2");
    m1.print_debug();
    m2.print_debug();
    MyMessage m3(m1);
    m3.print_debug();
    m3 = m2;
    m3.print_debug();
    Folder f1;
    m1.save(f1);
    m2.save(f1);
    m3.save(f1);
    f1.print_debug();
    m2.remove(f1);
    f1.print_debug();
    swap(m1, m2);
    m1.print_debug();
    m2.print_debug();
    return 0;
}
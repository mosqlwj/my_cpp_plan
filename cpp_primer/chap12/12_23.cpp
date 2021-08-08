//
// Created by LWJ on 2021/8/8.
//

#include <iostream>
#include <string>
#include <cstring>
#include <memory>
using namespace std;
int main() {
    const char* c1 = "hello";
    const char* c2 = "world";
    unsigned len = strlen(c1) + strlen(c2) + 1;
    char* r = new char[len]();
    strcat_s(r, len, c1);
    strcat_s(r, len, c2);
    std::cout << r << std::endl;

    string s1 = "hello";
    string s2 = "world";
    strcpy_s(r, len, (s1 + s2).c_str());
    cout << r << endl;
    delete [] r;
    return 0;
}
//
// Created by LWJ on 2021/7/15.
//

#include <iostream>
#include <vector>
#include <initializer_list>
using namespace std;

class X {
public:
    X() { cout << "X()" <<endl; }
    X(const X&) { cout << "X(const X&)" <<endl; }
    X& operator=(const X&) { cout << "X& operator=(const X&)" << endl; return *this; }
    ~X() { cout << "~X()" << endl; }
private:

};
void f(const X& rx, X x) {
    vector<X> vec;
    vec.reserve(2);
    vec.push_back(rx);
    vec.push_back(x);
}
int main() {
    X *px = new X;
    f(*px, *px);
    delete px;
    return 0;
}
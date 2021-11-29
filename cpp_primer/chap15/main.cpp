#include "StrBlob.h"
#include <iostream>

using namespace std;

void Test_StrBlob() {

    StrBlob sb{"hello", "nihao"};
    // sb.push_back("nihao");
    string res = sb.front();
    cout << sb.front() << endl;
    for (auto it = sb.begin(); neq(it, sb.end()); it.incr()) {
        cout << it.deref() << endl;
    }

}


int main() {

    cout << "hello world" << endl;
    Test_StrBlob();
    return 0;
}
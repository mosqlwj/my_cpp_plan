//
// Created by LWJ on 2021/8/13.
//

#ifndef MY_LEETCODE_PLAN_STRVEC_H
#define MY_LEETCODE_PLAN_STRVEC_H
#include <string>
#include <utility>
using namespace std;

class StrVec {

public:
    StrVec() : elements(nullptr),
               first_free(nullptr),
               cap(nullptr){}
    StrVec(const StrVec&);
    StrVec& operator=(const StrVec&);
    ~StrVec();
    void push_back(const string&);
    std::size_t size() {
        return first_free - elements;
    }
    std::size_t capacity() {
        return cap - elements;
    }
    string* begin() const {
        return elements;
    }
    string* end() const {
        return first_free;
    }
private:
    static allocator<string> alloc;
    void chk_n_alloc() {
        if (size() == capacity()) {
            reallocate();
        }
    }
    pair<string*, string*> alloc_n_copy(const string*, const string*);
    void free();
    void reallocate();

    string* elements;
    string* first_free;
    string* cap;
};
#endif //MY_LEETCODE_PLAN_STRVEC_H

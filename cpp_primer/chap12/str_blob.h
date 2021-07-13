//
// Created by LWJ on 2021/7/13.
//

#ifndef MY_LEETCODE_PLAN_STR_BLOB_H
#define MY_LEETCODE_PLAN_STR_BLOB_H
#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

class StrBlob {
public:
    typedef vector<string>::size_type size_type;
    StrBlob();
    StrBlob(initializer_list<string> il);
    size_type size() const { return _data->size(); }
    bool empty() const { return _data->empty(); }
    void push_back(const string& t) { _data->push_back(t); }
    void pop_back();
    string& front();
    string& back();
    const string& front() const;
    const string& back() const;
private:
    shared_ptr<vector<string>> _data;
    void check(size_type i, const  string& msg) const;
};
#endif //MY_LEETCODE_PLAN_STR_BLOB_H

//
// Created by LWJ on 2021/7/13.
//

#include "str_blob.h"

StrBlob::StrBlob() : _data(make_shared<vector<string>>()) {}

StrBlob::StrBlob(initializer_list<string> il) :
                _data(make_shared<vector<string>>(il)) {}

void StrBlob::check(size_type i, const string &msg) const {
    if (i >= _data->size())
        throw out_of_range(msg);
}

string & StrBlob::front() {
    check(0, "front on empty StrBlob");
    return _data->front();
}

string & StrBlob::back() {
    check(0, "back on empty StrBlob");
    return _data->back();
}

const string & StrBlob::front() const {
    check(0, "front on empty StrBlob");
    return _data->front();
}

const string & StrBlob::back() const {
    check(0, "back on empty StrBlob");
    return _data->back();
}

void StrBlob::pop_back() {
    check(0, "pop_back on empty StrBlob");
    _data->pop_back();
}




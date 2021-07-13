//
// Created by LWJ on 2021/7/13.
//

#ifndef MY_LEETCODE_PLAN_TEXT_QUERY_H
#define MY_LEETCODE_PLAN_TEXT_QUERY_H
#include <iostream>
#include <memory>
#include <fstream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

class QueryResult;

class TextQuery {
public:
    using line_no = vector<string>::size_type;
    TextQuery(ifstream&);
    QueryResult query(const string& ) const;
private:
    shared_ptr<vector<string>> _file;
    map<string, shared_ptr<set<line_no>>> _wm;
};

class QueryResult {
    friend ostream& print(ostream&, const QueryResult&);
public:
    QueryResult(string s,
                shared_ptr<set<TextQuery::line_no>> p,
                shared_ptr<vector<string>> f) :
                _sought(s), _lines(p), _files(f) {}
private:
    string _sought;
    shared_ptr<set<TextQuery::line_no>> _lines;
    shared_ptr<vector<string>> _files;
};

ostream& print(ostream& os, const QueryResult& qr);
#endif //MY_LEETCODE_PLAN_TEXT_QUERY_H

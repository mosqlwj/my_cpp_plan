//
// Created by LWJ on 2021/7/13.
//
#include "text_query.h"

void run_queries(ifstream& is) {
    TextQuery tq(is);
    while(true) {
        cout << "enter word to query, or q to quit:" ;
        string s;
        if (!(cin >> s) || s == "q") break;
        print(cout, tq.query(s));
    }
}

int main() {
    ifstream is("D:\\workspace\\my_leetcode_plan\\cpp_primer\\chap12\\stordata.txt");
    if (!is.is_open()) {
        cerr << "file not open." << endl;
        exit(0);
    }
    run_queries(is);
    return 0;
}

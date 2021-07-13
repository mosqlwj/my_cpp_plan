//
// Created by LWJ on 2021/7/13.
//
#include "text_query.h"

TextQuery::TextQuery(ifstream& is) : _file(new vector<string>) {
    string text;
    while (getline(is ,text)) {
        _file->push_back(text);
        int n = _file->size() - 1;
        istringstream line(text);
        string word;
        while (line >> word) {
            auto& lines =_wm[word];
            if (!lines) {
                lines.reset(new set<TextQuery::line_no>);
            }
            lines->insert(n);
        }
    }
}

QueryResult TextQuery::query(const string& sought) const {
    static shared_ptr<set<TextQuery::line_no>> nodata(new set<TextQuery::line_no>);
    // return map iterator
    auto loc = _wm.find(sought);
    if (loc == _wm.end()) {
        return QueryResult(sought, nodata, _file);
    } else {
        return QueryResult(sought, loc->second, _file);
    }
}

ostream& print(ostream& os, const QueryResult& qr) {
    os << qr._sought << " occurs " << qr._lines->size() << " times." << endl;
    for (auto num : *qr._lines) {
        os << "\t(line" << num + 1 << ") " << *(qr._files->begin() + num) << endl;
    }
    return os;
}
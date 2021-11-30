#include "TextQuery.h"

TextQuery::TextQuery(std::ifstream& ifs) {
    std::string line;
    while (std::getline(ifs, line)) {
        _file.push_back(line);
        int line_num = _file.size() - 1;

        std::stringstream line_stream(line);
        std::string word;
        while (line_stream >> word) {
            std::shared_ptr<std::set<line_no>>& lines = _word_map[word];
            // lines is null
            if (!lines) {
                lines.reset(new std::set<line_no>);
            } 
            lines->insert(line_num);
        }
    }
}

QueryResult
TextQuery::Query(const std::string& sought) const {
    static std::shared_ptr<std::set<line_no>> no_data{std::make_shared<std::set<line_no>>()};
    auto iter = _word_map.find(sought);
    if (iter == _word_map.end()) {
        return QueryResult(sought, no_data, _file);
    } else {
        return QueryResult(sought, iter->second, _file);
    }
}
#ifndef TEXTQUERY_H
#define TEXTQUERY_H

#include "StrBlob.h"

#include <map>
#include <set>
#include <string>
#include <memory>
#include <fstream>
#include <sstream>

class QueryResult;

class TextQuery {
public:
    using line_no = StrBlob::size_type;
    
    TextQuery(std::ifstream& ifs);
    
    QueryResult Query(const std::string& ) const;

private:
    StrBlob _file;
    std::map<std::string, std::shared_ptr<std::set<line_no>>> _word_map;

};

#endif
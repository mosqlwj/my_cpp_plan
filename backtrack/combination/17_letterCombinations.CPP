#include "../../leetcode.h"

class Solution {
public:
    // hashmap
    const string letter_map_[10] = {
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz",
    };

    vector<string> letterCombinations(string digits) {
        string path;
        vector<string> res;
        if (digits.empty() || digits.size() == 0)
            return res;
        backtrack(digits, 0, path, res);
        return res;
    }
    // 注意start_index表示digits数量，也控制了递归深度。
    // 刚开始对digit进行了循环，后来才发现其实是不对的
    void backtrack(string& digits, int start_index, string& path, vector<string>& res) {
        if (path.size() == digits.size()) {
            res.push_back(path);
            return;
        }
        
        int num = digits[start_index] - '0';
        const string tmp = letter_map_[num];
        for (auto elem : tmp) {
            // string 可以调用push_back和pop_back
            path.push_back(elem);
            backtrack(digits, start_index + 1, path, res);
            path.pop_back();
        }
    }
};
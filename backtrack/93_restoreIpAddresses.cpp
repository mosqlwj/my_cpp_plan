//
// Created by liwenjie on 2021/5/23.
//

#include "../leetcode.h"

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        vector<int> ip;
        backtrack(s, 4, ip, res);
        return res;
    }

    void backtrack(string s, int index, vector<int>& ip, vector<string>& res) {
        if (index == 0 && s.empty()) {
            res.push_back(get_string(ip));
            return;
        }
        for (int i = 1; i < 4; i++) {
            string tmp = s.substr(0, i);
            if (s.size() >= i && is_valid(tmp)) {
                ip.push_back(stoi(tmp));
                backtrack(s.substr(i), index - 1, ip, res);
                ip.pop_back();
            }
        }
    }

    bool is_valid(string s) {
        if (s.empty() || s.size() > 3 || (s.size() > 1 && s[0] == '0'))
            return false;
        int res = stoi(s);
        return res <= 255 && res >= 0;
    }

    string get_string(const vector<int>& ip) {
        string res = to_string(ip[0]);
        for (int i = 1; i < ip.size(); i++) {
            res += "." + to_string(ip[i]);
        }
        return res;
    }
};

int main() {
    string s = "101023";
    vector<string> res = Solution().restoreIpAddresses(s);
    for (auto elem : res) {
        cout << elem << ", ";
    }
    return 0;
}
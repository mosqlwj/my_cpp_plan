//
// Created by liwenjie on 2021/5/19.
//

#include "../leetcode.h"

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> path;
        vector<vector<int>> result;
        backtrack(n, k, 1, path, result);
        return result;
    }

    void backtrack(int n, int k, int index, vector<int>& path, vector<vector<int>>& result) {
        if (path.size() == k) {
            result.push_back(path);
            return;
        }

        for (int i = index; i <= n; i++) {
            path.push_back(i);
            backtrack(n, k, i+1, path, result);
            path.pop_back();
        }
    }
};

int main() {
    vector<vector<int>> res = Solution().combine(4, 2);
    for (auto elems : res) {
        for (auto e : elems) {
            cout << e << ",";
        }
        cout << endl;
    }
    return 0;
}
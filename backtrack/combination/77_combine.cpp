#include "../../leetcode.h"

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> path;
        vector<vector<int>> res;
        backtrack(n, k, 1, path, res);
        return res;
    }

    void backtrack(int n, int k, int start_index, vector<int>& path, vector<vector<int>>& res) {
        if (path.size() == k) {
            res.push_back(path);
            return;
        }
        // 循环：控制树的横向遍历，此处设置start_index，是因为当前的组合，不考虑顺序
        // 
        for (int i = start_index; i <= n; i++) {
            path.push_back(i);
            // 递归：控制树的纵向遍历，下一层的搜索从i+1开始
            backtrack(n, k, i + 1, path, res);
            path.pop_back();
        }
        return;
    }
};
//
// Created by liwenjie on 2021/5/17.
//
#include "../leetcode.h"

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> path;
        int len = candidates.size();
        if (len == 0) return result;
        // 排序剪枝
//        sort(candidates.begin(), candidates.end());
        backtrack(candidates, 0, len, target, path, result);
        return result;
    }

    void backtrack(vector<int>& candidates, int begin, int end, int target, vector<int>& path, vector<vector<int>>& result) {
        if (target < 0)
            return;
        if (target == 0) {
            result.push_back(path);
            return;
        }
        // 注意这里的begin用于去掉重复的序列
        for (int i = begin; i < end; ++i) {
            path.push_back(candidates[i]);

            backtrack(candidates, i, end, target - candidates[i], path, result);
            path.pop_back();
        }
    }
};

int main() {
    vector<int> candidates {2, 3, 6, 7};
    vector<vector<int>> result;
    result = Solution().combinationSum(candidates, 7);
    for (auto elems : result) {
        for (auto e : elems) {
            cout << e << ",";
        }
        cout << endl;
    }
    return 0;
}
//
// Created by liwenjie on 2021/5/18.
//
#include "../leetcode.h"

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> path;
        int len = candidates.size();
        if (len == 0) return result;
        // 排序剪枝
        sort(candidates.begin(), candidates.end());
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

        for (int i = begin; i < end; i++) {
            // 保证同一层次，相同的数字不再使用。
            if (i > begin && candidates[i] == candidates[i-1]) {
                continue;
            }
            path.push_back(candidates[i]);
            // 这里从i+1开始，类似visited的效果，保证已使用的数字，在下一层次递归时不再使用。
            backtrack(candidates, i+1, end, target - candidates[i], path, result);
            path.pop_back();
        }
    }
};

int main() {
    vector<int> candidates {10, 1, 2, 7, 6, 1, 5};
    vector<vector<int>> result;
    result = Solution().combinationSum2(candidates, 8);
    for (auto elems : result) {
        for (auto e : elems) {
            cout << e << ",";
        }
        cout << endl;
    }
    return 0;
}
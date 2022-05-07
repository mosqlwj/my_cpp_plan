#include "../include/leetcode.h"

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> path;
        vector<vector<int>> res;
        if (candidates.empty())
            return res;
        
        sort(candidates.begin(), candidates.end());
        int sum = 0;
        backtrack(candidates, target, 0, sum, path, res);
        return res;
    }

    void backtrack(vector<int>& candidates, 
                   int target, 
                   int start_index, 
                   int& sum,
                   vector<int>& path,
                   vector<vector<int>>& res) {
        
        if (sum > target) {
            return;
        }
        if (sum == target) {
            res.push_back(path);
            return;
        }

        for (int i = start_index; i < candidates.size(); i++) {
            // 去重
            if (i > start_index && candidates[i] == candidates[i - 1]) {
                continue;
            }
            sum += candidates[i];
            path.push_back(candidates[i]);
            backtrack(candidates, target, i + 1, sum, path, res);
            path.pop_back();
            sum -= candidates[i];
        }


    }
};
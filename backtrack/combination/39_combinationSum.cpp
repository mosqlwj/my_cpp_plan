#include "../../leetcode.h"

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> path;
        vector<vector<int>> res;
        if (candidates.empty())
            return res;
        int sum = 0;
        backtrack(candidates, target, 0, sum, path, res);
        return res;
    }

    void backtrack(vector<int>& candidate, 
                   int target, 
                   int start_index,
                   int &sum, 
                   vector<int>& path, 
                   vector<vector<int>>& res) {
                       
        if (sum == target) {
            res.push_back(path);
            return;
        }

        if (sum > target) {
            return;
        }
        // 注意这里的i用于防止结果重复
        for (int i = start_index; i < candidate.size(); i++) {
            sum += candidate[i];
            path.push_back(candidate[i]);
            backtrack(candidate, target, i, sum, path, res);
            sum -= candidate[i];
            path.pop_back();
        }
    }
};
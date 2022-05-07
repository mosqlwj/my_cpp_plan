#include "../include/leetcode.h"

class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> path;
        vector<vector<int>> res;
        if (nums.empty())
            return res;
        
        backtrack(nums, 0, path, res);
        return res;
    }

    void backtrack(vector<int>& nums, 
                   int start_index, 
                   vector<int>& path, 
                   vector<vector<int>>& res) {
        if (path.size() >= 2) {
            res.push_back(path);
        }

        if (start_index >= nums.size())
            return;
        // 是个局部变量，只在当前层起作用
        unordered_set<int> used;
        for (int i = start_index; i < nums.size(); i++) {
            // 树枝剪枝
            if (!path.empty() && nums[i] < path.back())
                continue;
            // 同一层去重
            if (used.find(nums[i]) != used.end())
                continue;

            used.insert(nums[i]);
            path.push_back(nums[i]);
            backtrack(nums, i + 1, path, res);
            path.pop_back();   
        }
        

    }
};
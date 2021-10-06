#include "../../leetcode.h"

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> path;
        vector<vector<int>> res;
        vector<bool> used(nums.size(), false);
        if (nums.empty())
            return res;
        sort(nums.begin(), nums.end());
        backtrack(nums, 0, used, path, res);
        return res;
    }

    void backtrack(vector<int>& nums, 
                   int start_index, 
                   vector<bool>& used, 
                   vector<int>& path, 
                   vector<vector<int>>& res) {

        res.push_back(path);

        if (start_index >= nums.size())
            return;
        
        for (int i = start_index; i < nums.size(); i++) {
            // 使用used表示同一树层去重，但是树枝不需要去重
            if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) {
                continue;
            }

            path.push_back(nums[i]);
            used[i] = true;
            backtrack(nums, i + 1, used, path, res);
            path.pop_back();
            used[i] = false;

        }
    }
};
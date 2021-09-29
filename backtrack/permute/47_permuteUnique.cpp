#include "../../leetcode.h"
// 47
// 对于有重复元素的数组，先进行排序，在去重处理
// 
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> path;
        vector<vector<int>> res;
        if (nums.empty())
            return res;
        sort(nums.begin(), nums.end());
        vector<bool> used(nums.size(), false);
        backtrack(nums, used, path, res);
        return res;
    }

    void backtrack(vector<int>& nums, 
                   vector<bool>& used, 
                   vector<int>& path, 
                   vector<vector<int>>& res) {
        
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            // 同一层上存在重复值，
            if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false)
                continue;
            if (used[i] == true)
                continue;
            
            used[i] = true;
            path.push_back(nums[i]);
            backtrack(nums, used, path, res);
            path.pop_back();
            used[i] = false;
        }
    
    }
};
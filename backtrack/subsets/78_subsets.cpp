#include "../../leetcode.h"

// 自己也是不考虑顺序的，所以类似组合问题，需要使用start_index来去重。
// 只不过组合是在叶子节点收集结果，而子集在整棵树的节点收集结果
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
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
        res.push_back(path);               
        // base case: 到叶子节点，也就是集合为空的时候
        if (start_index >= nums.size())
            return;

        for (int i = start_index; i < nums.size(); i++) {
            path.push_back(nums[i]);

            backtrack(nums, i + 1, path, res);
            path.pop_back();
        }
    }
};
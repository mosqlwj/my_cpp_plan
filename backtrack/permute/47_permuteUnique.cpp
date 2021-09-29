#include "../../leetcode.h"
// 47
// 对于有重复元素的数组，先进行排序，在去重处理
// 
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {

        sort(nums.begin(), nums.end());
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
            
        }
    
    }
};
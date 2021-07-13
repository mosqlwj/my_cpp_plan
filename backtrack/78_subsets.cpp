#include "../leetcode.h"

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        if (nums.size() == 0) return {{}};

        int back_val = nums.back();
        nums.pop_back();
        vector<vector<int>> res = subsets(nums);

        // for (auto& x : res) {
        //     res.push_back(x);
        //     res.back().push_back(back_val);
        // }
        int size = res.size();
        for (int i = 0; i < size; i++) {
            res.push_back(res[i]);
            res.back().push_back(back_val);
        }
        return res;
    }

    // 
    vector<vector<int>> res;
    vector<vector<int>> subsets2(vector<int>& nums) {
       vector<int> track;
       backtrack(nums, 0, track);
       return res;
    }

    void backtrack(vector<int>& nums, int start, vector<int>& track) {
        res.push_back(track);
        for (int i = start; i < nums.size(); i++) {
            track.push_back(nums[i]);
            backtrack(nums, i+1, track);
            track.pop_back();
        }

    }
};
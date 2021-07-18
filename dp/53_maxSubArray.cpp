//
// Created by LWJ on 2021/7/18.
//
#include "../leetcode.h"

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        vector<int> dp(size, 0);
        // base case
        dp[0] = nums[0];
        // dp state
        for (int i = 1; i < size; i++) {
            dp[i] = max(nums[i], dp[i - 1] + nums[i]);
        }
        // return
        int res = INT_MIN;
        for (int i = 0; i < size; i++) {
            res = max(res, dp[i]);
        }
        return res;
    }
};

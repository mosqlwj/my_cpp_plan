//
// Created by LWJ on 2021/7/14.
//
#include "../include/leetcode.h"

class Solution {
public:
    // nums: [10, 9, 2, 5, 3, 7, 101, 18]
    //   dp: [1,  1, 1, 2, 2, 3, 4,    4]
    // dp state
    // for (int j = 0; j < i; j++) {
    //     if (nums[i] > nums[j]) {
    //         dp[i] = max(dp[i], dp[j] + 1);
    //     }
    // }
    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size();
        // base case: init all value as 1
        vector<int> dp(size, 1);
        // dp state transfer
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        // get max res
        int res = 0;
        for (const auto& count : dp) {
            res = max(res, count);
        }
        return res;
    }
};
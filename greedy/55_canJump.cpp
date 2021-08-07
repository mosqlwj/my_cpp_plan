//
// Created by liwenjie on 2021/8/7.
//

#include "../leetcode.h"

class Solution {
public:
    // greedy O(n)
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int farthest = 0;
        for (int i = 0; i < n; i++) {
            farthest = max(farthest, i + nums[i]);
            if (farthest == n - 1)
                return true;
            if (farthest <= i)
                return false;
        }
        return true;
    }
};

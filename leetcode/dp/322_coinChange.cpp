//
// Created by LWJ on 2021/7/12.
//

#include "../include/leetcode.h"
class Solution {
public:
    // 1. recursion
    // exceed time limit
//    int coinChange(vector<int>& coins, int amount) {
//        if (amount == 0) return 0;
//        if (amount < 0) return -1;
//        int res = INT_MAX;
//        for (auto coin : coins) {
//            int tmp = coinChange(coins, amount - coin);
//            if (tmp == -1) continue;
//            res = min(res, 1 + tmp);
//        }
//        return res != INT_MAX ? res : -1;
//    }
    // 2 .dp
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        // base case
        dp[0] = 0;
        for (int i = 1; i < dp.size(); i++) {
            for (auto coin : coins) {
                // i 小于面额值[1,2,5]
                if (i - coin < 0) continue;
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
        // 当前amount的个数小于等于amount
        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
};
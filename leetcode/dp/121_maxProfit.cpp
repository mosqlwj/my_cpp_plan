//
// Created by LWJ on 2021/8/19.
//

#include "../include/leetcode.h"
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp(n, 0);
        int min_price = prices[0];
        // 状态转移
        for (int i = 1; i < n; i++) {
            min_price = min(min_price, prices[i]);
            dp[i] = max(dp[i - 1], prices[i] - min_price);
        }
        return dp[n - 1];
    }
};
//
// Created by liwenjie on 2021/8/18.
//
#include "../include/leetcode.h"

class Solution {
public:
    bool isMatch(string s, string p) {
        if (s.empty() || p.empty())
            return false;
        int m = s.size();
        int n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        // s 为空 且 p为空
        dp[0][0] = true;
        // s 为空， p不为空
        for (int i = 1; i < n + 1; i++) {
            if (p[i - 1] == '*') {
                dp[0][i] = dp[0][i - 2];
            }
        }
    }
};
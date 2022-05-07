//
// Created by liwenjie on 2021/7/15.
//
#include "../include/leetcode.h"

class Solution {
public:
    // 转换成最长递增字序列
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if (envelopes.empty()) {
            return 0;
        }
        // sort
        // width: from little to big, if width is same, height: from big to little
        sort(envelopes.begin(), envelopes.end(), [](const vector<int>& e1, const vector<int>& e2){
            return e1[0] < e2[0] || (e1[0] == e2[0] && e1[1] > e2[1]);
        });

        int n = envelopes.size();
        // base case
        vector<int> dp(n, 1);
        //
        vector<int> height(n , 0);
        for (int i = 0; i < n; i++) {
            height[i] = envelopes[i][1];
        }
        // dp state
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (height[j] < height[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        // return max
        int res = 0;
        for (int i = 0; i < dp.size(); i++) {
            res = max(res, dp[i]);
        }
        return res;
    }
};
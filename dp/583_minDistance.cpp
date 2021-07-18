//
// Created by liwenjie on 2021/7/18.
//
#include "../leetcode.h"

class Solution {
public:
    // 和1143相关，先找lcs，然后将两个字符串的长度家去lcs的长度
    int minDistance(string word1, string word2) {
        int lcs = longestCommonSubsequence(word1, word2);
        return word1.size() + word2.size() - 2 * lcs;
    }

    int longestCommonSubsequence(string text1, string text2) {
        int s1 = text1.size(), s2 = text2.size();
        vector<vector<int>> dp(s1 + 1, vector<int>(s2 + 1, -1));
        // base case
        for (int i = 0; i <= s1; i++) {
            dp[i][0] = 0;
        }
        for (int j = 0; j <= s2; j++) {
            dp[0][j] = 0;
        }
        // dp state
        for (int i = 1; i <= s1; i++) {
            for (int j = 1; j <= s2; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(max(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]);
                }
            }
        }
        return dp[s1][s2];
    }

};
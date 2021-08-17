//
// Created by LWJ on 2021/8/17.
//
#include "../leetcode.h"

class Solution {
public:
    /*
    // 1. mem + recursion (暴力搜索，回溯)
    // https://leetcode-cn.com/problems/dungeon-game/solution/cong-hui-su-dao-ji-yi-hua-sou-suo-dao-dong-tai-gui/
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        vector<vector<int>> mem(m, vector<int>(n, -1));
        return dp(dungeon, 0, 0, mem, m, n) + 1;
    }

    int dp(vector<vector<int>>& dungeon, int i, int j,
           vector<vector<int>>& mem, int m, int n) {
        // base case
        if (i == m - 1 && j == n - 1) {
            return dungeon[i][j] >= 0 ? 0 : -dungeon[i][j];
        }

        if (i == m || j == n) {
            return INT_MAX;
        }

        if(mem[i][j] != -1) {
            return mem[i][j];
        }

        int res = min(dp(dungeon, i, j + 1, mem, m, n),
                      dp(dungeon, i + 1, j, mem, m, n)) + (-dungeon[i][j]);
        // 这里为什么在res <= 0时为0， 因为方格中的值可能为正值，也即加血。
        // 对于正值，意味着最小为0就行。
        mem[i][j] = res <= 0 ? 0 : res;
        return mem[i][j];
    }
     */
    // 2. dp
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));
        dp[m - 1][n - 1] = max(0, -dungeon[m - 1][n - 1]);
        // row
        for (int r = m - 2; r >= 0; r--) {
            int min_val = dp[r + 1][n - 1] - dungeon[r][n - 1];
            dp[r][n - 1] = max(0, min_val);
        }
        // col
        for (int c = n - 2; c >= 0; c--) {
            int min_val = dp[m - 1][c + 1] - dungeon[m - 1][c];
            dp[m - 1][c] = max(0, min_val);
        }
        // state transfer
        for (int i = m - 2; i >= 0; i--) {
            for (int j = n - 2; j >= 0; j--) {
                int min_val = min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j];
                dp[i][j] = max(0, min_val);
            }
        }

        return dp[0][0] + 1;
    }
};
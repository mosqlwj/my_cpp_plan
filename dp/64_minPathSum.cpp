//
// Created by liwenjie on 2021/8/16.
//
#include "../leetcode.h"

class Solution {
public:
    /*
    int dp(vector<vector<int>>& grid, int i, int j) {
        if (i == 0 && j == 0) {
            return grid[i][j];
        }
        if (i < 0 || j < 0) {
            return INT_MAX;
        }

        return min(dp(grid, i - 1, j),
                   dp(grid, i, j - 1)) +
                   grid[i][j];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        return dp(grid, m - 1, n - 1);
    }
     */
    /*
    int dp(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& mem) {
        if (i == 0 && j == 0) {
            return grid[i][j];
        }
        if (i < 0 || j < 0) {
            return INT_MAX;
        }
        if (mem[i][j] != -1)
            return mem[i][j];
        mem[i][j] =  min(dp(grid, i - 1, j, mem), dp(grid, i, j - 1, mem)) + grid[i][j];

        return mem[i][j];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> mem(m, vector<int>(n, -1));

        return dp(grid, m - 1, n - 1, mem);
    }
     */
    // dp
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if (m == 0 || n == 0)
            return 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = grid[0][0];

        for (int i = 1; i < m; i++) {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }

        for (int j = 1; j < n; j++) {
            dp[0][j] = dp[0][j - 1] + grid[0][j];
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }

        return dp[m - 1][n - 1];
    }

};
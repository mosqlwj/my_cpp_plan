#include "../../leetcode.h"

class Solution {
public:
    vector<vector<int>> dir = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < n; i++) {
            dfs(grid, 0, i);
            dfs(grid, m - 1, i);
        }
        for (int i = 0; i < m; i++) {
            dfs(grid, i, 0);
            dfs(grid, i, n - 1);
        }

        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    count++;
                    dfs(grid, i, j);
                }
            }
        }
        return count;

    }

    void dfs(vector<vector<int>>& grid, 
             int i,
             int j) {
        int m = grid.size();
        int n = grid[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n) {
            return;
        }
        if (grid[i][j] == 1) {
            return;
        }
        grid[i][j] = 1;
        
        for (const auto& d : dir) {
            dfs(grid, i + d[0], j + d[1]);
        }
        
    }
};
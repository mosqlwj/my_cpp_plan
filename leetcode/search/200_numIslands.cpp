#include "../include/leetcode.h"

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    count++;
                    dfs(grid, i, j, visited);
                }
            }
        }

        return count;
    }
    void dfs(vector<vector<char>>& grid, 
                    int i, 
                    int j, 
                    vector<vector<bool>>& visited) {
        
        // base case 
        int m = grid.size();
        int n = grid[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n) {
            return;
        }
        if (grid[i][j] == '0') {
            return;
        }
        if (visited[i][j] == true) {
            return;
        }

        visited[i][j] = true;
        // 可以使用for循环替代，建立方向数组{{0, 1}, {0, -1}, {-1, 0}, {1, 0}}
        dfs(grid, i - 1, j, visited);
        dfs(grid, i + 1, j, visited);
        dfs(grid, i, j - 1, visited);
        dfs(grid, i, j + 1, visited);
    }
};
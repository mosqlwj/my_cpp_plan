#include "../include/leetcode.h"

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                bool is_edge = i == 0 || j == 0 || i == m - 1 || j == n - 1;
                if (is_edge && board[i][j] == 'O') {
                    dfs(board, i, j);
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } 
                if (board[i][j] == '#') {
                    board[i][j] = 'O';
                }
            }
        }
        
    }

    // 先将边界上的'O'替换为'#'
    void dfs(vector<vector<char>>& board, int i, int j) {
        // base case
        // 越界
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) {
            return;
        }
        // 不是'O'
        if (board[i][j] == 'X' || board[i][j] == '#')
            return;

        board[i][j] = '#';
        dfs(board, i - 1, j);
        dfs(board, i + 1, j);
        dfs(board, i, j - 1);
        dfs(board, i, j + 1);
    }
};